# `src/Defination/Data/Character/Elation/YaoGuang.h`

kit อ้างอิง: `docs/kit-reference/Character/Elation/yao-guang.md` · `atvStats->name` = `"Yao Guang"` (มีช่องว่าง ต่างจากชื่อ namespace) · **ซัพพอร์ตสาย Elation** — อ่าน `Hibana.md` ก่อนสำหรับคำศัพท์ของ path นี้

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(101, 180, 180, E, PHYSICAL, ELATION, "Yao Guang", STANDARD)` | 5 |
| build — **SPD เป็นแกน** | `setSpeedRequire(320)` (สูงที่สุดในโปรเจกต์) | 12 |
| นับตัวเองเข้าจำนวน Elation ในทีม | `elationCount++` | 15 |
| **Basic ATK** | lambda `BA` — blast 90/30 + `genPunchLine(ptr, 3)` | 24-38 |
| **Skill** — บัฟ Elation ทีม | lambda `skill` — `AllyBuffAction` + `isHaveToAddBuff("YG Skill", 3)` | 40-67 |
| Skill — Elation ทีม = 20% ของ Elation ตัวเอง | `calculateElationForBuff(ptr, 20)` + สำนวน delta `TEMP`/`NONE` | 54-61 |
| **Ultimate** | `ultimateList` — `AllyBuffAction` · RESPEN ทีม +20 3 เทิร์น · `ahaInstant(20)` | 79-109 |
| **Elation Skill** | `elationSkillList` — AoE 100 ×3 + bounce 20 ×5 + `Woe's Whisper` VUL +16 | 111-129 |
| **A2** — Elation ตาม SPD ที่เกิน 120 (cap 200) | `statsAdjustList` → `min(200, max(0, SPD - 120))` | 229-238 |
| **Talent** — เพื่อนโจมตี → Elation DMG แถม | `whenAttackList` + `Stats::CERTIFIED_BANGER` เป็นตัวปลด | 212-227 |
| Talent — คูณสองถ้ามีการใช้ SP ใน action นั้น | `skillPointList` ตั้ง flag + `beforeAttackActionList` ล้าง flag | 204-217 |
| **Technique** | `startGameList` — ทำ Skill ซ้ำทั้งก้อน + `act->turnReset = 0` | 179-203 |
| **Minor traces** | `resetList` | 131-136 |
| **E1** — ทีม ignore DEF สำหรับ Elation DMG · Aha แรงขึ้น | `whenOnFieldList` · `ahaInstant(40)` | 139, 96 |
| **E2** — Skill ให้ SPD/Elation เพิ่ม | `if (ptr->eidolon >= 2)` ใน Skill และตอนถอน | 48-52, 154-158 |
| **E4** — Elation Skill แรงขึ้นชั่วคราวตอน Ult | `buffAllAlly({{Stats::MTPR_INC, AType::ELATION_SKILL, 50}})` ครอบ `ahaInstant` | 91-102 |
| **E6** — Merrymake + MtprInc ถาวร | `whenOnFieldList` | 140-143 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — บัฟ `YG skill` ยังอยู่ → BA ไม่งั้น Skill | 69-73 |

## รากฐาน: `ahaInstant(n)` — สั่งให้ Elation Skill ทำงานทันที

Ult ของ Yao Guang ไม่ได้ตีเอง แต่เรียก `ahaInstant(20)` / `ahaInstant(40)` (96-97) ซึ่งไปกระตุ้นคิว Aha Instant ที่ `elationSkillList` ของ**ทุกตัวละคร Elation ในทีม**ลงทะเบียนไว้ (ดู `Hibana.md`) — เป็นซัพพอร์ตที่ทำงานโดยยิงท่าของคนอื่น

**E4 ใช้สำนวนครอบชั่วคราว**: `buffAllAlly(MTPR_INC +50)` → `ahaInstant(...)` → `buffAllAlly(MTPR_INC -50)` (91-102) เพื่อให้บัฟมีผลเฉพาะ Aha ครั้งนั้น — สำนวนเดียวกับ "เพิกเฉย DEF เฉพาะก้อนนี้" ของ `../Nihility/Black Swan.md`

## รากฐาน: stat ที่เป็น "สวิตช์" มากกว่าตัวคูณ

```cpp
if (ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE] <= 0) return;
```
Talent ของ Yao Guang ทำงานเฉพาะเมื่อมี `Stats::CERTIFIED_BANGER` — เป็น stat ที่ใช้เป็น **เงื่อนไขเปิด/ปิด** ไม่ใช่ตัวเลขที่เอาไปคูณ · `Stats::MERRYMAKE` (E6) ก็อยู่ในตระกูลเดียวกัน ทั้งคู่เป็น stat เฉพาะของ path Elation

## รากฐาน: flag ที่มีอายุ "หนึ่ง action"

```cpp
beforeAttackActionList: ptr->setBuffCheck("YG Talent SP check", 0);   // ล้างก่อนทุก action
skillPointList:        if (SP < 0) setBuffCheck("YG Talent SP check", 1);  // ใช้ SP -> ตั้ง
whenAttackList:        if (getBuffCheck(...)) newAct->addDamageIns(...);   // อ่านตอนโจมตี
```
หน้าต่างของ flag คือ **ระหว่าง `beforeAttackActionList` ถึง `whenAttackList` ของ action เดียวกัน** — เป็นวิธีถามว่า "action นี้กิน SP ไหม" โดยไม่ต้องส่งข้อมูลผ่าน action object

## รากฐาน: `act->source` — เปลี่ยนตัวที่ใช้ stat คำนวณ

```cpp
if (calculateElationOnStats(ptr) > calculateElationOnStats(act->attacker)) act->source = ptr;
```
ดาเมจแถมยิงในนามของ **ผู้โจมตี** แต่ถ้า Elation ของ Yao Guang สูงกว่า ให้ใช้ stat ของ Yao Guang คำนวณแทน · `source` แยกจาก `attacker` — ตัวหนึ่งคือ "ใครตี" อีกตัวคือ "ใช้ stat ของใคร" · `Castorice.h` ก็ตั้ง `act->source = ptr` ให้ท่าของ memosprite ด้วยเหตุผลเดียวกัน

> **สังเกต: บรรทัดนี้ตั้ง `act->source` ของ action เดิม ไม่ใช่ `newAct` ที่เพิ่งสร้าง** (222) — น่าจะตั้งใจเขียน `newAct->source = ptr` ดูหัวข้อจุดที่ควรระวัง

## จุดที่ควรระวัง

- **`act->source = ptr` ใส่ผิดตัว** (บรรทัด 222) — ตั้งให้ `act` (action ของเพื่อนที่กำลังโจมตี) แทนที่จะเป็น `newAct` (ดาเมจแถมที่เพิ่งสร้าง) → ผลคือ **ดาเมจของเพื่อนถูกคำนวณด้วย stat ของ Yao Guang** ส่วนดาเมจแถมยังใช้ stat ของเพื่อนเหมือนเดิม ซึ่งกลับด้านกับเจตนา
- **`elationSkillList` ใช้ตัวเลข priority ดิบ `114`** (111) เหมือน `Hibana.h` ที่ใช้ `144` — ไม่มีค่าคงที่รองรับ
- **Technique copy โค้ด Skill ทั้งก้อน** (179-203) ต่างจาก Skill แค่ไม่มี `genSkillPoint(ptr,-1)` และมี `turnReset = 0` — ถ้าแก้สูตร Skill ต้องแก้สองที่
- **`resetList` บวก `Stats::ELATION` เป็น `10+30`** (134) เขียนเป็นผลบวกไว้ให้เห็นว่ามาจากสองแหล่ง แต่ไม่มีคอมเมนต์ว่าแหล่งไหน
- **`whenOnFieldList` เรียก `statsAdjust(ptr, Stats::SPD_P)` เอง** (144) เพื่อบังคับให้ A2 คำนวณรอบแรก — เป็นการยิง event ด้วยมือ ต่างจากตัวอื่นที่ตั้งค่าเริ่มต้นตรง ๆ ใน `whenOnFieldList`
- **A2 ลงเฉพาะช่อง `AType::NONE` ไม่มีคู่ `TEMP`** (235) ต่างจาก Skill ของตัวเองและจาก `../Remembrance/RMC.md` — ถ้ามีสูตรไหนอ่าน Elation ด้วย `calculateElationForBuff` ค่าจาก A2 จะถูกนับซ้อนเข้าไปด้วย (Skill ของ Yao Guang เองอ่าน `calculateElationForBuff(ptr, 20)` ที่บรรทัด 54 → **A2 ป้อนกลับเข้า Skill ได้**)
