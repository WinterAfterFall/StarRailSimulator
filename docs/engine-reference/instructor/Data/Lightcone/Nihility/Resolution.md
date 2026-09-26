# `src/Defination/Data/Lightcone/Nihility/Resolution.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Resolution"` · base stats `SetAllyBaseStats(953, 476, 331)`

บังคับ `newApplyBaseChanceRequire(50 + S*10)` — เป็นใบเดียวที่เกณฑ์ขึ้นกับ superimpose

| ท่อน | โค้ด |
|---|---|
| โจมตี → เป้าติด `Ensnared` DEF_SHRED `11 + S` | `AfterAttackActionList` |
| ถอน | `After_turn_List` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ

## รูปแบบปัจจุบัน

```cpp
ลง:   debuffSingleApply(ptr, e, {{DEF_SHRED, None, 11 + S}}, ensnared, 1);
ถอน:  if (isDebuffEnd(enemy, ensnared)) debuffSingle(enemy, {{DEF_SHRED, None, -(11 + S)}});
```
guard ผู้โจมตีด้วย `isSameOwnerName(ptr)`

> **แก้ 2026-09-26**: เดิมจัดการ debuff ด้วยมือทั้งหมด (เขียน `Stats_type` / `debuffEnd` / `debuffCheck` / `Total_debuff` เอง และใช้ `enemyUnit[turn->num]`) แบบโค้ดเก่าของ `../../Character/Nihility/Pela.md` · เปลี่ยนเป็น `debuffSingleApply` + `isDebuffEnd` ผลเท่าเดิม (ยังเช็คลงซ้ำผ่าน `debuffApply` ภายใน จึงไม่รั่วแบบ Nectar Blitz ใน `../../Character/Abundance/Gallagher.md`) · guard เดิมเทียบชื่อ → memosprite ของผู้สวมไม่นับ แก้เป็น `isSameOwnerName`
