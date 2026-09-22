# `src/Defination/Function/Calculate/CalDamageNote.h`

## วิธี implement True DMG ในเอนจิน

**ไม่มี `AType` / `DmgSrcType` สำหรับ True DMG** (`Vocab/04-AttackType.md:43` — "ยังไม่มี") · จำลองเป็น **รายการบันทึกดาเมจล้วน ๆ** ผ่าน `Cal_DamageNote()` (`CalDamageNote.h:68-80`):

```cpp
void Cal_DamageNote(act, Enemy* src, Enemy* recv, double damage, double ratio, string name){
    // ไม่มีสูตร — เอา damage ที่คำนวณเสร็จแล้ว × ratio/100 ยัดเข้าสมุดตรง ๆ
    // เข้า pool ไหนตาม act->toughnessAvgCalculate
}
```

ตัวอย่าง Tribbie E1 (`Tribbie.h:206-210`) — hook `AfterDealingDamage_List` รับ `damage` ของฮิตที่เพิ่งเกิด → `Cal_DamageNote(act, src, enemyUnit[Main_Enemy_num], damage, 24, "TB True " + act->actionName)`

ผลพลอยได้ที่ **ตรงกับเกมพอดี** เพราะ path นี้ไม่แตะ `CalDamage`/`Attack()` เลย:
- ไม่ผ่าน DEF / RES / CRIT / Vuln / Broken mult ✔
- ไม่ลด toughness · ไม่สร้าง energy · ไม่ยิง `AfterDealingDamage_List` ซ้ำ (ไม่ recursion) ✔
- ทั้งหมดนี้สรุปได้ด้วยประโยคเดียวของ wiki: True DMG **"ไม่ถือเป็นการโจมตี" (not considered an attack)**

> ⚠️ True DMG งอกได้จากดาเมจ **ทุกชนิด** — non-crit, crit, **DoT, Break, Super Break** (Game8) · note ก้อนนั้นตกลงสมุดเล่มไหนก็ตาม `act->toughnessAvgCalculate` ของการโจมตีแม่ → ดูในไฟล์นี้ และ [🐞 #16](../../BUGS.md)

**แหล่งอ้างอิงนอก:** [Fandom — True DMG](https://honkai-star-rail.fandom.com/wiki/True_DMG) · [Game8 — Remembrance Trailblazer](https://game8.co/games/Honkai-Star-Rail/archives/486082)
_(หมายเหตุ: Game8 เขียน RMC Mem's Support = 30%, เรโปเขียน 28% — คนละเลเวล talent ไม่ขัดกัน ดู `character-implementation-notes.md` คอนเวนชันเลเวล)_

## สมุดดาเมจ 2 เล่ม — real-time vs non-real-time

### กฎเกมที่เป็นต้นเหตุ

ศัตรูที่ยัง**ไม่** broken กินดาเมจแค่ **90%** พอ broken แล้วกิน **100%** — คือ **Broken Multiplier** ใน[สูตรดาเมจ](../../../../hsr-system-reference.md) §10.1 · ในโค้ดคือ `calToughnessMultiplier` คืน `0.9` หรือ `1` (`CalStats.h:392-398`)

### ปัญหาสำหรับ sim

sim วัด "ดาเมจเฉลี่ยต่อ ATV" ถ้าใส่ 0.9/1.0 ตามสถานะจริง ณ วินาทีที่ตี ผลจะ**แกว่งตามจังหวะ** — อัลติก้อนใหญ่ที่บังเอิญตกหลัง break พอดีได้ ×1.0 แต่เลื่อนนิดเดียวไปตกก่อน break ได้ ×0.9 ทั้งก้อน ดาเมจรวมทั้งรันเด้งทั้งที่บิลด์เหมือนเดิมเป๊ะ = ไม่ใช่ตัวเลขที่เป็นตัวแทนของบิลด์

### วิธีแก้ — แยกสมุด 2 เล่ม

| สมุด | ทำอะไรตอนตี | ทำอะไรตอนจบ |
|---|---|---|
| **`currentNonRealTimeDmg`** ("เดี๋ยวค่อยเฉลี่ย") | **ไม่ใส่** 0.9/1.0 เลย — `calToughnessMultiplier` คืน `1` เก็บดาเมจดิบ | คูณทั้งเล่มด้วยตัวคูณเฉลี่ยตัวเดียว = สัดส่วนเวลาที่ศัตรู broken ตลอดรัน (`Cal_AvgToughnessMultiplier`, `CalDamageNote.h:59-67`) · เช่น broken 30% ของเวลา → `0.3×1.0 + 0.7×0.9 = 0.93` |
| **`currentRealTimeDmg`** ("จบตรงนั้น") | ใส่ 0.9/1.0 **จริง** ตามสถานะ ณ วินาทีนั้น | ไม่แตะอีก — บวกดิบ ๆ (`CalDamageNote.h:40-43`) |

### `toughnessAvgCalculate` — สวิตช์ที่ตัดสิน

ชื่อบอกตรงตัว: **"ดาเมจก้อนนี้จะคิดตัวคูณ toughness แบบเฉลี่ยไหม"**

- `= 1` → **เฉลี่ย** → ลง `currentNonRealTimeDmg`
- `= 0` → **คิดสด** → ลง `currentRealTimeDmg`

ค่าเริ่มต้น `= 1` (`AllyAttackAction.h:31`) · ถูกกดเป็น `0` เฉพาะ **5 ชนิด**: `Break` · `SPB` · `Technique` · `Freeze` · `Entanglement` (`AllyAttackAction.h:106,114,134,139,145`)

**เหตุผลที่ 5 ชนิดนี้คิดสด (ยืนยัน 2026-09-13):** เวลาของมัน**แน่นอนอยู่แล้ว** ไม่มีความไม่แน่นอนให้เฉลี่ย — Break DMG เกิดตอน break พอดี · Super Break ปกติเกิดบนเป้าที่ broken ไปแล้ว (Broken mult ล็อค 1.0) · Technique/Freeze/Entanglement เกิดในจังหวะที่ระบุชัด

| ชนิดดาเมจ | `toughnessAvgCalculate` | สมุด |
|---|---|---|
| BA · Skill · Ult · FuA · **DoT** · Additional · Elation · Memosprite | `1` (default) | non-real-time (เฉลี่ย) |
| **Break · Super Break** · Technique · Freeze · Entanglement | `0` | real-time (คิดสด) |

> ⚠️ **อย่าสับสน** — DoT อยู่เล่ม**เฉลี่ย** (ไม่ได้ถูกกดเป็น 0) ส่วน Break/SPB อยู่เล่ม**คิดสด**

### ข้อยกเว้น: Dahlia pre-break SPB

สถานะ 2026-09-16: commit แล้วที่ `e65743d` ตรวจ syntax ของ `Application.cpp` ผ่าน แต่ยังไม่ได้ตรวจผล simulation เต็ม

ประเด็นที่ต้องการปรับคือ Super Break ตั้งต้นใช้สมุดคิดสดทั้งหมด การแก้ส่วนนี้เลือกให้ Super Break ในทีมที่มี Dahlia ใช้ตัวคูณ toughness เฉลี่ยตามเวลา เป็นทางเลือกการคำนวณของ simulator ไม่ใช่ข้อสรุปว่าการคิดสดผิดเสมอ

`Superbreak_trigger` (`Combat.h:254-256`) เขียนทับค่าก่อนคำนวณแต่ละเป้า:
```cpp
// SPB ปกติเกิดบนเป้าที่ broken แล้ว (Broken mult ล็อค 1.0) → เก็บ real-time ไม่เฉลี่ย
// SPB ผ่าน Dahlia บนเป้าที่ยังไม่ broken → Broken mult ไม่แน่นอน → เก็บใน pool ที่เฉลี่ย toughness/weaken
data_2->toughnessAvgCalculate = DahliaCheck ? 1 : 0;
```

⚠️ **เงื่อนไขคือ `DahliaCheck` ไม่ใช่ `Toughness_status` ของเป้า** — `DahliaCheck` เป็น global (`Setting.h:22`) ที่ตั้ง `1` ครั้งเดียวตอน build ตัว Dahlia (`Dahlia.h:20`) และไม่เคยถูกเคลียร์ จึงมีความหมายว่า "ทีมนี้มี Dahlia" ไม่ใช่ "เป้านี้ยังไม่ broken"

ผลที่ตามมา:
- ทีม**ไม่มี** Dahlia → `0` ทุกกรณี → SPB ทั้งหมดลงสมุดคิดสดเหมือนเดิม
- ทีม**มี** Dahlia → `1` ทุกกรณี → SPB ทั้งหมดลงสมุดเฉลี่ย **รวมถึง SPB บนเป้าที่ broken ไปแล้ว** ซึ่งตัวคูณล็อค 1.0 อยู่แล้ว จุดนี้เป็นการประมาณแบบหยาบ ถ้าต้องการแยกรายเป้าจริง ๆ ต้องอ่าน `enemyUnit[i]->Toughness_status` เพิ่ม
- `DahliaCheck` ยังคุมอีก 2 จุดในฟังก์ชันเดียวกัน: `Combat.h:250` (ไม่ข้ามเป้าที่ยังไม่ broken) และ `Combat.h:258` (ใช้ toughness ที่ลดจริงแทนการ clamp ที่ toughness ที่เหลือ)

## ปิดรอบการวัดผล — `Cal_AverageDamage()` · `Cal_DamageSummary()` · `changeMaxDamage()`

สามฟังก์ชันนี้คือวงจร "วัดผลบิลด์" ที่ทำงานไล่กันเป็นทอด ๆ โดย `Cal_DamageNote()` เป็นคนลงสมุด ส่วนสามตัวนี้เป็นคนสรุปสมุด

### `Cal_AverageDamage(ptr, enemyList)` (บรรทัด 34–61) — เก็บ sample ระหว่างรัน

ถูกเรียกเป็นระยะระหว่างการต่อสู้เพื่อบันทึก "ดาเมจเฉลี่ยต่อ ATV ณ ขณะนี้" ของตัวละครหนึ่งตัวต่อศัตรูแต่ละตัว

1. `if (Current_atv < 300) return;` — **ช่วงต้นรบไม่เก็บ sample** เพราะดาเมจต่อ ATV ช่วงแรกแกว่งจัด (ตัวหารยังน้อย)
2. รีเฟรช `toughnessAvgMultiplier` ของศัตรู **ทุกตัว** ไม่ใช่แค่เป้าที่เพิ่งโดนตี — คอมเมนต์ในโค้ดระบุเหตุผลไว้ว่า note ก้อนหนึ่งอาจมี `src` เป็นศัตรูที่ไม่ได้ถูกตีรอบนี้ (True DMG ย้ายเป้าได้)
3. รวมดาเมจของศัตรูตัวนั้นจากสองสมุด: `currentRealTimeDmg` บวกดิบ · `currentNonRealTimeDmg` **คูณ `src->toughnessAvgMultiplier` ก่อน** แล้วหารด้วย `Current_atv` ได้ "ดาเมจต่อ ATV"
4. เขียนลง `AvgDmgRecord[enemyNum].avgDmgInstance` โดยมีกติกา **กันเก็บถี่เกิน 20 ATV**: ถ้าห่างจาก `lastNote` ไม่ถึง 20 ATV จะ **เขียนทับ sample ตัวสุดท้าย** แทนการ `push_back` ตัวใหม่

⚠️ การหารด้วย `Current_atv` ทุกครั้งแปลว่าแต่ละ sample คือ "ค่าเฉลี่ยสะสมตั้งแต่ต้นรบถึงตอนนี้" ไม่ใช่ค่าเฉลี่ยของช่วงเวลานั้น ๆ

### `Cal_AvgToughnessMultiplier(target, Total_atv)` (บรรทัด 62–70)

คืนตัวคูณ Broken เฉลี่ยตามเวลา = `(เวลาที่ broken × 1.0 + เวลาที่ไม่ broken × 0.9) / เวลาทั้งหมด` โดยกรณีที่ศัตรู **กำลัง broken อยู่ ณ ตอนนี้** (`Toughness_status == 0`) จะบวกช่วงที่ยัง break ค้างอยู่ (`Total_atv − when_toughness_broken`) เข้าไปในเวลาที่ broken ด้วย

### `Cal_DamageSummary()` (บรรทัด 84–113) — ปิดบัญชีตอนจบรัน

วนทุกตัวละคร × ทุกศัตรู:

1. รีเฟรช `toughnessAvgMultiplier` ของศัตรูทุกตัวอีกครั้งด้วยค่า `Current_atv` สุดท้าย
2. เฉลี่ย `avgDmgInstance` ทั้งหมดเป็น `AvgDmgRecord[j].currentDmgRecord` ต่อศัตรูหนึ่งตัว แล้ว**บวกสะสม**ลง `AvgDmgRecord[0].currentDmgRecord` ซึ่งทำหน้าที่เป็นช่อง "รวมทุกศัตรู" (ช่อง index 0 = ผลรวม ไม่ใช่ศัตรูตัวที่ 0)
3. `if (sum == 0) continue;` — ศัตรูที่ไม่เคยโดนตัวละครนี้ตีจะถูกข้าม ไม่ถูกนับเป็น 0 มาถ่วงค่าเฉลี่ย
4. รวม `currentTotalDmg` จากสองสมุด โดยเล่ม non-real-time **คูณ `toughnessAvgMultiplier` ลงไปในตัวมันเอง** ทั้ง `.total` และรายท่าใน `.type` — เป็นจุดเดียวที่ตัวคูณเฉลี่ยถูก "ปั๊ม" ลงสมุดจริง

⚠️ ขั้นที่ 4 **แก้ค่าในสมุดโดยตรง (in-place)** เรียก `Cal_DamageSummary()` ซ้ำสองครั้งโดยไม่รีเซ็ตจะคูณตัวคูณซ้ำสองรอบ และ `AvgDmgRecord[0].currentDmgRecord` ก็เป็น `+=` สะสมเช่นกัน — การรีเซ็ตเป็นหน้าที่ของ [Stats_Reset.md](../Setup/Stats_Reset.md)

### `changeMaxDamage(ptr)` (บรรทัด 3–33) — เก็บบิลด์ที่ดีที่สุด

ใช้ตอนไล่สุ่ม/ไล่ปรับ substats: ถ้ารันล่าสุดให้ค่าเฉลี่ยรวม (`AvgDmgRecord[0]`) **ดีกว่า**ของเดิม จะ snapshot ทุกอย่างของรันนี้ทับของเดิมแล้วคืน `true`

สิ่งที่ถูก snapshot: `maxTotalDmg` · `maxDmgRecord` ของทุกศัตรู · `maxRealTimeDmg` และ `maxNonRealTimeDmg` (ทั้ง `.total` และรายท่าใน `.type`) · และ `bestSubstats` ซึ่งคัดลอกจาก `Substats[i].second`

⚠️ เกณฑ์ตัดสินคือ **ดาเมจเฉลี่ยรวมทุกศัตรู** (`AvgDmgRecord[0].currentDmgRecord`) ไม่ใช่ `currentTotalDmg` — บิลด์ที่ดาเมจรวมสูงแต่ใช้เวลานานกว่าจึงแพ้บิลด์ที่ดาเมจต่อ ATV ดีกว่า ซึ่งตรงกับเจตนาของ sim ที่วัด "ดาเมจต่อเวลา"

⚠️ ต้องเรียก **หลัง** `Cal_DamageSummary()` เสมอ เพราะค่าที่ใช้เทียบถูกคำนวณในขั้นตอนนั้น

### ลำดับจริงในลูปหลัก

```text
Take_action() … (ระหว่างรบ)
    └─ Combat.h:149  Cal_AverageDamage()   ← เก็บ sample เมื่อ act->damageNote เปิด
Main.h:59   Cal_DamageSummary()            ← ปิดบัญชีรันนี้
Main.h:60   printRoundResult()
Main.h:61   Reroll_substats()
    └─ Substats_Reset.h:76,126,159  changeMaxDamage()  ← เทียบกับบิลด์ที่ดีที่สุด
```

ผู้เรียก `Cal_DamageSummary()` มีแค่ 2 จุดคือ `Main.h:59` (ลูปหลัก) กับ `ManualBuilder.cpp:168` · ส่วน `Cal_AverageDamage()` ถูกเรียกจุดเดียวที่ `Combat.h:149` และยิงเฉพาะ action ที่ตั้ง `damageNote` ไว้
