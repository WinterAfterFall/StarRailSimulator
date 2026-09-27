# `src/Defination/Data/Lightcone/Destruction/Ninja_Record.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Ninja Record"` · base stats `SetAllyBaseStats(1058, 476, 265)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 476, 265)` | `Ninja_Record.h:5` |
| HP% `9 + 3S` | บวกถาวร | `:8` |
| ผู้สวมถูกฮีล → CD `13.5 + 4.5S` นาน 2 เทิร์น | `Healing_List` guard `target` เป็นผู้สวม · `isHaveToAddBuff(…, 2)` กันซ้อน + ตั้งอายุ | `:11-16` |
| ผู้สวมเสีย HP → บัฟเดียวกัน | `HPDecrease_List` guard `target` | `:18-23` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:25-29` |

## จุดที่ทำถูก

- **guard `target->isSameName(ptr)` ทั้งสอง list** — บัฟเกิดเฉพาะตอนผู้สวมถูกฮีล/เสีย HP เอง
- **`isHaveToAddBuff(..., 2)` แบบ 3 args** ทำทั้งกันลงซ้ำและต่ออายุในคราวเดียว (ดู `../../Relic/Goddess of Sun and Thunder.md`)
