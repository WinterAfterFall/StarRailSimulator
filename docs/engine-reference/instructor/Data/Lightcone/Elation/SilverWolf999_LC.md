# `src/Defination/Data/Lightcone/Elation/SilverWolf999_LC.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `SilverWolf999_LC` · `lightCone.name` = `"SilverWolf999_LC"` · base stats `setAllyBaseStats(1164, 476, 529)`

ชื่อในเกม: **Welcome to the Cosmic City** · **signature ของ Silver Wolf LV.999** (ดู `../../Character/Elation/SilverWolf999.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 476, 529)` | `SilverWolf999_LC.h:6` |
| SPD 18/21/24/27/30% | `atvStats->speedPercent += 15 + 3S` | `:11` |
| Elation DMG เจาะ DEF 20/24/28/32/36% | `DEF_SHRED` ช่อง `AType::ELATION_DMG` ถาวร `16 + 4S` | `:12` |
| ใช้ Ult ใส่ตัวเอง → Punchline +20/25/30/35/40 | `buffList` + `isSameAction(ptr, AType::ULT)` + ผู้สวมอยู่ใน `buffTargetList` → `genPunchLine(ptr, 15 + 5S)` | `:18-25` |
| ใช้ได้ 1 ครั้ง · รีเซ็ตหลังใช้ Basic ATK ครบ 3 ครั้ง | ธง `"Cosmic City Used"` · `afterAllyActionList` นับ BA ของผู้สวม ครบ 3 → ปลดธง | `:21-23`, `:27-34` |

## จุดที่ควรระวัง

- ช่อง `ELATION_DMG` ครอบดาเมจ Elation ทุกแบบ รวม Elation Skill ด้วย (action ชนิด `ELATION_SKILL` ใส่ `ELATION_DMG` ใน `damageTypeList` ให้เอง — `Class/ActionData/AllyAttackAction.h:117-121`)
- ตรวจ "ใส่ตัวเอง" จาก `buffTargetList` ของ Ult แบบ buff action · Ult ที่เป็น attack action จะไม่ติด (Ult ของ SW999 เป็น buff action ใส่ตัวเอง จึงติดตามที่ตั้งใจ)
- ตัวนับ BA เริ่มนับหลังใช้สิทธิ์ไปแล้วเท่านั้น (BA ก่อนหน้านั้นไม่นับ)
- Punchline ที่ได้ไปป้อน Talent ของ SW999 (ได้ Hidden MMR เท่ากัน) ผ่าน `punchLineList` ตามปกติ
