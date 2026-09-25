# `src/Defination/Data/Character/Elation/YaoGuang.h`

kit อ้างอิง: `docs/character-kit-reference/YaoGuang.md` · `Atv_stats->Name` = `"Yao Guang"` (มีช่องว่าง ต่างจากชื่อ namespace) · **ซัพพอร์ตสาย Elation** — อ่าน `Hibana.md` ก่อนสำหรับคำศัพท์ของ path นี้

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(101, 180, 180, E, Physical, Elation, "Yao Guang", Standard)` | 5 |
| build — **SPD เป็นแกน** | `setSpeedRequire(320)` (สูงที่สุดในโปรเจกต์) | 12 |
| นับตัวเองเข้าจำนวน Elation ในทีม | `elationCount++` | 15 |
| **Basic ATK** | lambda `BA` — blast 90/30 + `genPunchLine(ptr, 3)` | 24-38 |
| **Skill** — บัฟ Elation ทีม | lambda `Skill` — `AllyBuffAction` + `isHaveToAddBuff("YG Skill", 3)` | 40-67 |
| Skill — Elation ทีม = 20% ของ Elation ตัวเอง | `calculateElationForBuff(ptr, 20)` + สำนวน delta `TEMP`/`None` | 54-61 |
| **Ultimate** | `Ultimate_List` — `AllyBuffAction` · RESPEN ทีม +20 3 เทิร์น · `AhaInstant(20)` | 79-109 |
| **Elation Skill** | `ElationSkill_List` — AoE 100 ×3 + bounce 20 ×5 + `Woe's Whisper` VUL +16 | 111-129 |
| **A2** — Elation ตาม SPD ที่เกิน 120 (cap 200) | `Stats_Adjust_List` → `min(200, max(0, SPD - 120))` | 229-238 |
| **Talent** — เพื่อนโจมตี → Elation DMG แถม | `When_attack_List` + `Stats::CertifiedBanger` เป็นตัวปลด | 212-227 |
| Talent — คูณสองถ้ามีการใช้ SP ใน action นั้น | `Skill_point_List` ตั้ง flag + `BeforeAttackAction_List` ล้าง flag | 204-217 |
| **Technique** | `Start_game_List` — ทำ Skill ซ้ำทั้งก้อน + `act->Turn_reset = 0` | 179-203 |
| **Minor traces** | `Reset_List` | 131-136 |
| **E1** — ทีม ignore DEF สำหรับ Elation DMG · Aha แรงขึ้น | `WhenOnField_List` · `AhaInstant(40)` | 139, 96 |
| **E2** — Skill ให้ SPD/Elation เพิ่ม | `if (ptr->Eidolon >= 2)` ใน Skill และตอนถอน | 48-52, 154-158 |
| **E4** — Elation Skill แรงขึ้นชั่วคราวตอน Ult | `buffAllAlly({{Stats::MtprInc, AType::ElationSkill, 50}})` ครอบ `AhaInstant` | 91-102 |
| **E6** — Merrymake + MtprInc ถาวร | `WhenOnField_List` | 140-143 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — บัฟ `YG Skill` ยังอยู่ → BA ไม่งั้น Skill | 69-73 |

## รากฐาน: `AhaInstant(n)` — สั่งให้ Elation Skill ทำงานทันที

Ult ของ Yao Guang ไม่ได้ตีเอง แต่เรียก `AhaInstant(20)` / `AhaInstant(40)` (96-97) ซึ่งไปกระตุ้นคิว Aha Instant ที่ `ElationSkill_List` ของ**ทุกตัวละคร Elation ในทีม**ลงทะเบียนไว้ (ดู `Hibana.md`) — เป็นซัพพอร์ตที่ทำงานโดยยิงท่าของคนอื่น

**E4 ใช้สำนวนครอบชั่วคราว**: `buffAllAlly(MtprInc +50)` → `AhaInstant(...)` → `buffAllAlly(MtprInc -50)` (91-102) เพื่อให้บัฟมีผลเฉพาะ Aha ครั้งนั้น — สำนวนเดียวกับ "เพิกเฉย DEF เฉพาะก้อนนี้" ของ `../Nihility/Black Swan.md`

## รากฐาน: stat ที่เป็น "สวิตช์" มากกว่าตัวคูณ

```cpp
if (ptr->Stats_type[Stats::CertifiedBanger][AType::None] <= 0) return;
```
Talent ของ Yao Guang ทำงานเฉพาะเมื่อมี `Stats::CertifiedBanger` — เป็น stat ที่ใช้เป็น **เงื่อนไขเปิด/ปิด** ไม่ใช่ตัวเลขที่เอาไปคูณ · `Stats::Merrymake` (E6) ก็อยู่ในตระกูลเดียวกัน ทั้งคู่เป็น stat เฉพาะของ path Elation

## รากฐาน: flag ที่มีอายุ "หนึ่ง action"

```cpp
BeforeAttackAction_List: ptr->setBuffCheck("YG Talent SP check", 0);   // ล้างก่อนทุก action
Skill_point_List:        if (SP < 0) setBuffCheck("YG Talent SP check", 1);  // ใช้ SP -> ตั้ง
When_attack_List:        if (getBuffCheck(...)) newAct->addDamageIns(...);   // อ่านตอนโจมตี
```
หน้าต่างของ flag คือ **ระหว่าง `BeforeAttackAction_List` ถึง `When_attack_List` ของ action เดียวกัน** — เป็นวิธีถามว่า "action นี้กิน SP ไหม" โดยไม่ต้องส่งข้อมูลผ่าน action object

## รากฐาน: `act->source` — เปลี่ยนตัวที่ใช้ stat คำนวณ

```cpp
if (calculateElationOnStats(ptr) > calculateElationOnStats(act->Attacker)) act->source = ptr;
```
ดาเมจแถมยิงในนามของ **ผู้โจมตี** แต่ถ้า Elation ของ Yao Guang สูงกว่า ให้ใช้ stat ของ Yao Guang คำนวณแทน · `source` แยกจาก `Attacker` — ตัวหนึ่งคือ "ใครตี" อีกตัวคือ "ใช้ stat ของใคร" · `Castorice.h` ก็ตั้ง `act->source = ptr` ให้ท่าของ memosprite ด้วยเหตุผลเดียวกัน

> **สังเกต: บรรทัดนี้ตั้ง `act->source` ของ action เดิม ไม่ใช่ `newAct` ที่เพิ่งสร้าง** (222) — น่าจะตั้งใจเขียน `newAct->source = ptr` ดูหัวข้อจุดที่ควรระวัง

## จุดที่ควรระวัง

- **`act->source = ptr` ใส่ผิดตัว** (บรรทัด 222) — ตั้งให้ `act` (action ของเพื่อนที่กำลังโจมตี) แทนที่จะเป็น `newAct` (ดาเมจแถมที่เพิ่งสร้าง) → ผลคือ **ดาเมจของเพื่อนถูกคำนวณด้วย stat ของ Yao Guang** ส่วนดาเมจแถมยังใช้ stat ของเพื่อนเหมือนเดิม ซึ่งกลับด้านกับเจตนา
- **`ElationSkill_List` ใช้ตัวเลข priority ดิบ `114`** (111) เหมือน `Hibana.h` ที่ใช้ `144` — ไม่มีค่าคงที่รองรับ
- **Technique copy โค้ด Skill ทั้งก้อน** (179-203) ต่างจาก Skill แค่ไม่มี `genSkillPoint(ptr,-1)` และมี `Turn_reset = 0` — ถ้าแก้สูตร Skill ต้องแก้สองที่
- **`Reset_List` บวก `Stats::Elation` เป็น `10+30`** (134) เขียนเป็นผลบวกไว้ให้เห็นว่ามาจากสองแหล่ง แต่ไม่มีคอมเมนต์ว่าแหล่งไหน
- **`WhenOnField_List` เรียก `StatsAdjust(ptr, Stats::SPD_P)` เอง** (144) เพื่อบังคับให้ A2 คำนวณรอบแรก — เป็นการยิง event ด้วยมือ ต่างจากตัวอื่นที่ตั้งค่าเริ่มต้นตรง ๆ ใน `WhenOnField_List`
- **A2 ลงเฉพาะช่อง `AType::None` ไม่มีคู่ `TEMP`** (235) ต่างจาก Skill ของตัวเองและจาก `../Remembrance/RMC.md` — ถ้ามีสูตรไหนอ่าน Elation ด้วย `calculateElationForBuff` ค่าจาก A2 จะถูกนับซ้อนเข้าไปด้วย (Skill ของ Yao Guang เองอ่าน `calculateElationForBuff(ptr, 20)` ที่บรรทัด 54 → **A2 ป้อนกลับเข้า Skill ได้**)
