# `src/Defination/Data/Lightcone/Harmony/The Forever Victual.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"The Forever Victual"` · base stats `SetAllyBaseStats(953, 476, 331)`

**free** · ฟังก์ชันชื่อ `ForeverVictual` (ไม่มี `The`)

| ท่อน | โค้ด |
|---|---|
| ATK% `12 + 4S` | `Reset_List` |
| ใช้ Skill → ATK stack `6 + 2S` (cap 3) | `AllyActionList` → `buffStackSingle(ptr, ..., 1, 3, "The Forever Victual")` |

## จุดที่น่าสังเกต

**stack ไม่มีวันถูกถอน** — `buffStackSingle` ถูกเรียกโดยไม่ส่ง duration และไม่มี `After_turn_List` รองรับ · ถ้า kit ระบุว่าเป็นบัฟถาวรที่สะสมจนเต็มก็ถูก แต่ควรยืนยันกับ kit

ใช้ `AllyActionList` + `act->isSameAction(ptr, AType::SKILL)` เพื่อจับ Skill ที่เป็นได้ทั้ง attack และ buff action
