# `src/Defination/Data/Lightcone/Elation/Today's Good Luck.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Today's Good Luck"` · base stats `SetAllyBaseStats(953, 529, 397)`

ฟังก์ชันชื่อ `TodayGoodLuck`

| ท่อน | โค้ด |
|---|---|
| CR `10 + 2S` | `Reset_List` |
| ใช้ Elation Skill → Elation stack `10 + 2S` (cap 2) | `BeforeAllyActionList` → `buffStackSingle(ptr, ..., 1, 2, "TDGL Stack")` |

## จุดที่ควรระวัง

**stack ไม่มีอายุและไม่มีการถอน** → สะสมจนเต็ม 2 แล้วค้างตลอดการต่อสู้

`act->isSameAction(ptr, AType::ElationSkill)` guard ทั้งผู้กระทำและชนิด action ถูกต้อง
