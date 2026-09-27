# `src/Defination/Data/Lightcone/Erudition/The_Herta_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"The_Herta_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ The Herta** (ดู `../../Character/Erudition/The_Herta.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 635, 463)` | `The_Herta_LC.h:5` |
| CR `10 + 2S` | บวกถาวร | `:9` |
| ผู้สวมใช้ Ult → Skill DMG และ Ult DMG `50 + 10S` นาน 3 เทิร์น | `BeforeAllyActionList` เฉพาะ Ult → `buffSingle(…, "The_Herta_LC_buff", 3)` | `:21-26` |
| ถ้า Ult cost ≥ 140 → SP +1 | ในบล็อกเดียวกัน | `:27-29` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:12-19` |

## จุดที่น่าสนใจ

**`ptr->Ult_cost >= 140` เป็นการเช็คว่าผู้สวมเป็นตัว energy สูงหรือไม่** — สำนวนเดียวกับ `../Destruction/Saber_LC.md` ที่ใช้ `Max_energy >= 300` แทนการเช็คชื่อตัวละคร

ใช้ `BeforeAllyActionList` (เห็นทั้ง attack และ buff action) แทน `WhenUseUlt_List` — ต่างจาก LC ส่วนใหญ่ · ได้ผลเหมือนกันสำหรับ ult ที่เป็น action แต่ `WhenUseUlt_List` ตรงกว่า
