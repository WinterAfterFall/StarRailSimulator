# `src/Defination/Data/Lightcone/Harmony/The Forever Victual.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"The Forever Victual"` · base stats `SetAllyBaseStats(953, 476, 331)`

**free** · ฟังก์ชันชื่อ `ForeverVictual` (ไม่มี `The`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 476, 331)` | `The Forever Victual.h:5` |
| ATK% `12 + 4S` | บวกถาวร | `:9` |
| ผู้สวมใช้ Skill → ATK `6 + 2S`% ต่อชั้น (สูงสุด 3) | `BeforeAllyActionList` → `buffStackSingle(…, 1, 3, "The Forever Victual")` · ไม่มีอายุ | `:12-15` |

## จุดที่น่าสังเกต

**stack ไม่มี duration โดยตั้งใจ** — kit: "After the wearer uses Skill, increases ATK by ... stacking up to 3 times" ไม่ระบุระยะเวลา จึงสะสมถาวรจนเต็ม 3 ถูกต้อง

ใช้ `BeforeAllyActionList` + `act->isSameAction(ptr, AType::SKILL)` เพื่อจับ Skill ที่เป็นได้ทั้ง attack และ buff action
