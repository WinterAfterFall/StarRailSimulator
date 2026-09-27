# `src/Defination/Data/Lightcone/Elation/Today's Good Luck.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Today's Good Luck"` · base stats `SetAllyBaseStats(953, 529, 397)`

ฟังก์ชันชื่อ `TodayGoodLuck`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 529, 397)` | `Today's Good Luck.h:5` |
| CR `10 + 2S` | บวกถาวร | `:9` |
| ผู้สวมใช้ Elation Skill → Elation `10 + 2S` ต่อ stack (สูงสุด 2) | `BeforeAllyActionList` → `buffStackSingle(…, 1, 2, "TDGL Stack")` · ไม่มีอายุ | `:12-16` |

## จุดที่ควรระวัง

**stack ไม่มีอายุและไม่มีการถอน** → สะสมจนเต็ม 2 แล้วค้างตลอดการต่อสู้

`act->isSameAction(ptr, AType::ElationSkill)` guard ทั้งผู้กระทำและชนิด action ถูกต้อง
