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

`Superbreak_trigger` (`Combat.h:254-256`) เขียนทับค่าเป็นราย ๆ ไป:
```cpp
data_2->toughnessAvgCalculate = (enemyUnit[i]->Toughness_status==1) ? 1 : 0;
```
(`Toughness_status == 1` = **ยัง**ไม่ broken · `== 0` = broken แล้ว)

SPB ปกติยิงบนเป้าที่ broken แล้ว → `0` → คิดสด · แต่ SPB ผ่าน Dahlia ยิงบนเป้าที่**ยังไม่** broken → Broken mult ไม่แน่นอน → `1` → เข้าเล่มเฉลี่ย
