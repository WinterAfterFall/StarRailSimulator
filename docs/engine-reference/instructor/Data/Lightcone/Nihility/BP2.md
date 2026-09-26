# `src/Defination/Data/Lightcone/Nihility/BP2.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Holiday"` · base stats `SetAllyBaseStats(1058, 529, 331)`

**ฟังก์ชันชื่อ `BP2` แต่ `Light_cone.Name` เป็น `"Holiday"`** — ชื่อไฟล์บอกว่ามาจาก Battle Pass · บังคับ `newApplyBaseChanceRequire(100)`

| ท่อน | โค้ด |
|---|---|
| DMG `12 + 4S` | `Reset_List` |
| โจมตี → เป้าติด VUL `8.5 + 1.5S` 2 เทิร์น | `AfterAttackActionList` → `debuffEnemyTargetsApply` |
| ถอน | `After_turn_List` → `isDebuffEnd(enemy, "Holiday Vul")` |

guard ผู้โจมตีด้วย `isSameOwnerName(ptr)` ถูกต้อง

## จุดที่ควรระวัง

**ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ** → ถ้ามีสองคนสวมใบนี้ ค่าจะชนกัน

> มีไฟล์ชื่อ `BP2.h` ใน `../Destruction/` ด้วย — คนละใบ คนละ namespace
