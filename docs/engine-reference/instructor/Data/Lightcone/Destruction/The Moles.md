# `src/Defination/Data/Lightcone/Destruction/The Moles.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"The Moles"` · base stats `SetAllyBaseStats(1058, 476, 265)`

ฟังก์ชันชื่อ `The_Moles`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 476, 265)` | `The Moles.h:5` |
| ใช้ BA / Skill / Ult ครั้งแรกของแต่ละชนิด → ATK `9 + 3S`% (รวมได้ 3 ก้อน ถาวร) | `BeforeAttackAction_List` guard `isSameOwnerName` · ใช้ `isHaveToAddBuff` ชื่อแยกต่อชนิดท่าเป็นตัวจำว่าเคยใช้แล้ว | `:7-15` (BA `:9-10` · Skill `:11-12` · Ult `:13-14`) |

**ไม่มีสแตตติดตัว** และ **ไม่มีการถอน** — สะสมได้สูงสุด 3 ก้อนแล้วอยู่ถาวร

## รากฐาน: ใช้ `isHaveToAddBuff` แบบ 2 args เป็น "เคยทำหรือยัง"

3 ชื่อบัฟแยกตามชนิด action — `isHaveToAddBuff` คืน `true` ครั้งเดียวต่อชื่อ จึงใช้จำว่า "เคยใช้ท่าชนิดนี้แล้ว" ได้โดยไม่ต้องมีตัวแปรแยก · สำนวนเดียวกับ `../Nihility/BlackSwan_LC.md`

guard ผู้กระทำด้วย `isSameOwnerName(ptr)` ถูกต้อง
