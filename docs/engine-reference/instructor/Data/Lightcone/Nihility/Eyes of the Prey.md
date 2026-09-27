# `src/Defination/Data/Lightcone/Nihility/Eyes of the Prey.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"Eyes of the Prey"` · base stats `setAllyBaseStats(953, 476, 331)`

ฟังก์ชันชื่อ `EyesOfThePrey`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `Eyes of the Prey.h:5` |
| EHR `15 + 5S` | บวกถาวร | `:9` |
| DoT DMG `18 + 6S` | บวก DMG ที่ `AType::DOT` ถาวร | `:10` |

**ไม่มี trigger เลย** — มีแต่ `resetList` ก้อนเดียว · เป็นหนึ่งในไฟล์ที่สั้นที่สุดในโฟลเดอร์

## ข้อควรรู้

`Stats::DMG` ที่ `AType::DOT` เข้าเฉพาะ action ที่มี `AType::DOT` อยู่ใน `damageTypeList` · **action ของ DoT ทุกชนิดมี `AType::DOT` อยู่แล้ว** — ตอนสร้าง action ด้วย `AType::SHOCK`/`BLEED`/`BURN`/`WIND_SHEAR` ตัว `setupActionType()` ใส่ `AType::DOT` ลงทั้ง `actionTypeList` และ `damageTypeList` ให้เอง (`Class/ActionData/AllyAttackAction.h:145-160`) โบนัส DoT DMG ของใบนี้จึงมีผลกับ DoT ทุกชนิด
