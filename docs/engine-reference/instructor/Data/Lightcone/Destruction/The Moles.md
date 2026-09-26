# `src/Defination/Data/Lightcone/Destruction/The Moles.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"The Moles"` · base stats `SetAllyBaseStats(1058, 476, 265)`

ฟังก์ชันชื่อ `The_Moles`

| ท่อน | โค้ด |
|---|---|
| ใช้ BA ครั้งแรก → ATK `9 + 3S` | `isHaveToAddBuff(ptr, "The Moles BA")` |
| ใช้ Skill ครั้งแรก → ATK `9 + 3S` | `isHaveToAddBuff(ptr, "The Moles Skill")` |
| ใช้ Ult ครั้งแรก → ATK `9 + 3S` | `isHaveToAddBuff(ptr, "The Moles Ult")` |

**ไม่มีสแตตติดตัว** และ **ไม่มีการถอน** — สะสมได้สูงสุด 3 ก้อนแล้วอยู่ถาวร

## รากฐาน: ใช้ `isHaveToAddBuff` แบบ 2 args เป็น "เคยทำหรือยัง"

3 ชื่อบัฟแยกตามชนิด action — `isHaveToAddBuff` คืน `true` ครั้งเดียวต่อชื่อ จึงใช้จำว่า "เคยใช้ท่าชนิดนี้แล้ว" ได้โดยไม่ต้องมีตัวแปรแยก · สำนวนเดียวกับ `../Nihility/BlackSwan_LC.md`

guard ผู้กระทำด้วย `isSameOwnerName(ptr)` ถูกต้อง
