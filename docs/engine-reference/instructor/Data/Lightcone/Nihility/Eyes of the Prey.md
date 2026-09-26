# `src/Defination/Data/Lightcone/Nihility/Eyes of the Prey.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Eyes of the Prey"` · base stats `SetAllyBaseStats(953, 476, 331)`

ฟังก์ชันชื่อ `EyesOfThePrey`

| ท่อน | โค้ด |
|---|---|
| EHR `15 + 5S` | `Reset_List` |
| DoT DMG `18 + 6S` | `Stats_type[Stats::DMG][AType::Dot]` |

**ไม่มี trigger เลย** — มีแต่ `Reset_List` ก้อนเดียว · เป็นหนึ่งในไฟล์ที่สั้นที่สุดในโฟลเดอร์

## ข้อควรรู้

`Stats::DMG` ที่ `AType::Dot` เข้าเฉพาะ action ที่มี `AType::Dot` อยู่ใน `damageTypeList` · **action ของ DoT ทุกชนิดมี `AType::Dot` อยู่แล้ว** — ตอนสร้าง action ด้วย `AType::Shock`/`Bleed`/`Burn`/`WindShear` ตัว `setupActionType()` ใส่ `AType::Dot` ลงทั้ง `actionTypeList` และ `damageTypeList` ให้เอง (`Class/ActionData/AllyAttackAction.h:145-160`) โบนัส DoT DMG ของใบนี้จึงมีผลกับ DoT ทุกชนิด
