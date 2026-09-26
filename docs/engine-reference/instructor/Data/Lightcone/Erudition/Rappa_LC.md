# `src/Defination/Data/Lightcone/Erudition/Rappa_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Rappa_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Rappa** (ดู `../../Character/Erudition/Rappa.md`)

| ท่อน | โค้ด |
|---|---|
| Break Effect `50 + 10S` | `Reset_List` |
| ต้นเกม → energy `27.5 + 2.5S` | `Start_game_List` |
| กด ult → เปิดสถานะ `Ration` | `WhenUseUlt_List` + `isSameOwner` |
| ใช้ BA ครบ 2 ครั้งหลัง ult → advance `45 + 5S` | `AfterAttackActionList` + `stack["Ration"]` |

## จุดที่น่าสนใจ

**ใช้ `buffCheck` เป็นสวิตช์และ `stack` เป็นตัวนับคู่กัน** — `buffCheck["Ration"]` บอกว่าสถานะเปิดอยู่ไหม, `stack["Ration"]` นับว่าใช้ BA ไปกี่ครั้งแล้ว · พอครบ 2 ก็ปิดสวิตช์ · สำนวนเดียวกับ Ult state ของ `../../Character/Erudition/Rappa.md`

`isSameAction(ptr, AType::BA)` guard ทั้งผู้กระทำและชนิด action ในบรรทัดเดียว

> advance เคยเป็น `40 + 5S` (S1 = 45%) kit ให้ 50/55/60/65/70 · แก้เป็น `45 + 5S` แล้ว
