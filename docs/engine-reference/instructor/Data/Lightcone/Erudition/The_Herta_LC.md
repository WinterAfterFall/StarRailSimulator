# `src/Defination/Data/Lightcone/Erudition/The_Herta_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"The_Herta_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ The Herta** (ดู `../../Character/Erudition/The_Herta.md`)

| ท่อน | โค้ด |
|---|---|
| CR `10 + 2S` | `Reset_List` |
| ใช้ Ult → Skill/Ult DMG `50 + 10S` 3 เทิร์น | `BeforeAllyActionList` → `act->isSameAction(ptr, AType::Ult)` |
| ถ้า `Ult_cost >= 140` → คืน SP 1 | เงื่อนไขในบล็อกเดียวกัน |
| ถอน | `After_turn_List` → `isBuffEnd` |

## จุดที่น่าสนใจ

**`ptr->Ult_cost >= 140` เป็นการเช็คว่าผู้สวมเป็นตัว energy สูงหรือไม่** — สำนวนเดียวกับ `../Destruction/Saber_LC.md` ที่ใช้ `Max_energy >= 300` แทนการเช็คชื่อตัวละคร

ใช้ `BeforeAllyActionList` (เห็นทั้ง attack และ buff action) แทน `WhenUseUlt_List` — ต่างจาก LC ส่วนใหญ่ · ได้ผลเหมือนกันสำหรับ ult ที่เป็น action แต่ `WhenUseUlt_List` ตรงกว่า
