# `src/Defination/Data/Lightcone/Erudition/Rappa_LC.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"Rappa_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Rappa** (ดู `../../Character/Erudition/Rappa.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Rappa_LC.h:5` |
| Break Effect `50 + 10S` | บวกถาวร | `:9` |
| ต้นเกม → energy `27.5 + 2.5S` | `startGameList` | `:12-14` |
| ผู้สวมกด Ult → เข้าสถานะ "Ration" | `whenUseUltList` + `isSameOwner` ตั้ง flag และนับใหม่ | `:17-22` |
| ใช้ Basic ATK ครบ 2 ครั้งหลัง Ult → advance `45 + 5S`% | `afterAttackActionList` นับ `stack["Ration"]` ถึง 2 → `actionForward` และปิดสถานะ | `:24-32` |

## จุดที่น่าสนใจ

**ใช้ `buffCheck` เป็นสวิตช์และ `stack` เป็นตัวนับคู่กัน** — `buffCheck["Ration"]` บอกว่าสถานะเปิดอยู่ไหม, `stack["Ration"]` นับว่าใช้ BA ไปกี่ครั้งแล้ว · พอครบ 2 ก็ปิดสวิตช์ · สำนวนเดียวกับ Ult state ของ `../../Character/Erudition/Rappa.md`

`isSameAction(ptr, AType::BA)` guard ทั้งผู้กระทำและชนิด action ในบรรทัดเดียว

> advance เคยเป็น `40 + 5S` (S1 = 45%) kit ให้ 50/55/60/65/70 · แก้เป็น `45 + 5S` แล้ว
