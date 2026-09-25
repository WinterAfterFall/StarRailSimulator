# `src/Defination/Data/Lightcone/Destruction/Ninja_Record.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Ninja Record"` · base stats `SetAllyBaseStats(1058, 476, 265)`

| ท่อน | โค้ด |
|---|---|
| HP% `9 + 3S` | `Reset_List` |
| ถูกฮีล → CD `13.5 + 4.5S` 2 เทิร์น | `Healing_List` + `isHaveToAddBuff(..., 2)` |
| เสีย HP → เหมือนกัน | `HPDecrease_List` |
| ถอน | `After_turn_List` |

## จุดที่ทำถูก

- **guard `target->isSameName(ptr)` ทั้งสอง list** — บัฟเกิดเฉพาะตอนผู้สวมถูกฮีล/เสีย HP เอง
- **`isHaveToAddBuff(..., 2)` แบบ 3 args** ทำทั้งกันลงซ้ำและต่ออายุในคราวเดียว (ดู `../../Relic/Goddess of Sun and Thunder.md`)
