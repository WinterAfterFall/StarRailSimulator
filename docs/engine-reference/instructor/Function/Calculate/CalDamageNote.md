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
