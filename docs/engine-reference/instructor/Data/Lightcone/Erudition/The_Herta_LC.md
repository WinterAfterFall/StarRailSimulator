# `src/Defination/Data/Lightcone/Erudition/The_Herta_LC.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"The_Herta_LC"` · base stats `setAllyBaseStats(953, 635, 463)`

**signature ของ The Herta** (ดู `../../Character/Erudition/The_Herta.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 635, 463)` | `The_Herta_LC.h:5` |
| CR `10 + 2S` | บวกถาวร | `:9` |
| ผู้สวมใช้ Ult → Skill DMG และ Ult DMG `50 + 10S` นาน 3 เทิร์น | `beforeAllyActionList` เฉพาะ Ult → `buffSingle(…, "The_Herta_LC_buff", 3)` | `:21-26` |
| ถ้า Ult cost ≥ 140 → SP +1 | ในบล็อกเดียวกัน | `:27-29` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:12-19` |

## จุดที่น่าสนใจ

**`ptr->ultCost >= 140` เป็นการเช็คว่าผู้สวมเป็นตัว energy สูงหรือไม่** — สำนวนเดียวกับ `../Destruction/Saber_LC.md` ที่ใช้ `maxEnergy >= 300` แทนการเช็คชื่อตัวละคร

ใช้ `beforeAllyActionList` (เห็นทั้ง attack และ buff action) แทน `whenUseUltList` — ต่างจาก LC ส่วนใหญ่ · ได้ผลเหมือนกันสำหรับ ult ที่เป็น action แต่ `whenUseUltList` ตรงกว่า
