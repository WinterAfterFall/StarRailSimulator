# `src/Defination/Data/Lightcone/Harmony/DDD.h`

`namespace Harmony_Lightcone` · `lightCone.name` = `"DDD"` · base stats `setAllyBaseStats(953, 423, 397)`

**4★ · ใบที่กระทบ AI ของทั้งทีม**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 423, 397)` | `DDD.h:5` |
| ผู้สวมกด Ult → ทั้งทีม advance `14 + 2S`% | `whenUseUltList` + `isSameOwner` → `allActionForward` | `:8-12` |

ไม่มีสแตตติดตัว มี trigger เดียว — ไฟล์สั้นที่สุดในโฟลเดอร์

## ทำไมใบนี้สำคัญกว่าที่ตาเห็น

`allActionForward(n)` ดัน action bar ของ **ทุกคน** — เป็นฟังก์ชันที่มีผู้เรียก 2 ที่ในโปรเจกต์ (ใบนี้กับ `../../Character/Harmony/Robin.h`)

**ไม่มี `addUltCondition` ในตัว** → ถ้าผู้สวมกด ult ตอนที่ทีมใกล้ได้เล่นอยู่แล้ว advance เสียเปล่า · ต่างจาก `../../Relic/Eagle_Beaked_Helmet.md` ที่ใส่เงื่อนไขของตัวเอง

ประวัติการตัดสินใจ: `Tribbie.h` และ `Hanabi.h` เคยมีบรรทัดเช็ค DDD เพื่อกันการเสียเปล่า แต่ **user สั่งเอาออกทั้งคู่เมื่อ 2026-09-13** เพราะของ Hanabi เขียนผิดจนไม่มีวันกด ult ได้ — ดู `../../README.md`

> เหตุผลที่ย้ายเงื่อนไขเข้ามาไว้ในไฟล์นี้แบบ Eagle ไม่ได้: เงื่อนไขของ Tribbie คือ "กันไม่ให้ advance เสียเปล่า" แต่ของ Hanabi คือ "จับจังหวะให้บัฟ ult เริ่มพอดี" — คนละจุดประสงค์
