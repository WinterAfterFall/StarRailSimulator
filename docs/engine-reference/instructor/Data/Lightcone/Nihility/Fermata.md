# `src/Defination/Data/Lightcone/Nihility/Fermata.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Fermata"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| Break Effect `12 + 4S` | `Reset_List` |
| เป้าที่ติด Shock/WindShear รับดาเมจ +`12 + 4S` **เฉพาะก้อนนั้น** | `BeforeAttack_List` ลง / `AfterAttack_List` ถอน |

## รากฐาน: บัฟชั่วคราวครอบ action ด้วยคู่ Before/After + จดรายการ

```cpp
BeforeAttack_List: if (each->ShockCount || each->WindSheerCount) { debuffSingle(each, {{DMG, +(12+4S)}}); buffedTargets->push_back(each); }
AfterAttack_List:  for (each : *buffedTargets) debuffSingle(each, {{DMG, -(12+4S)}});  buffedTargets->clear();
```
`buffedTargets` เป็น `shared_ptr<vector<Enemy*>>` ที่ทั้งสอง lambda capture ร่วมกัน · **ถอนตามรายการที่จดไว้ ไม่เช็คเงื่อนไขซ้ำ** → ถ้าสถานะ DoT ของศัตรูเปลี่ยนระหว่าง Before กับ After (เช่น action นั้นลง Shock ใหม่) ค่าก็ไม่รั่ว

`Stats::DMG` ที่เขียนลงศัตรูถูกนำไปรวมในโบนัสดาเมจของผู้โจมตี (`Function/Calculate/CalStats.h:190-196`) จึงเท่ากับ "ศัตรูรับดาเมจเพิ่ม"

guard ผู้โจมตีด้วย `isSameOwnerName(ptr)` ทั้งสองฝั่ง

> **แก้ 2026-09-26**: เดิมฝั่ง After เช็ค `ShockCount || WindSheerCount` ซ้ำ → ถ้า action ลง Shock/WindShear ใหม่ จะลบโดยไม่เคยบวก ค่าติดลบค้าง
