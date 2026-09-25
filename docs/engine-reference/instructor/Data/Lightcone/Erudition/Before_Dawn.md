# `src/Defination/Data/Lightcone/Erudition/Before_Dawn.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Before_Dawn"` · base stats `SetAllyBaseStats(1058, 582, 463)`

| ท่อน | โค้ด |
|---|---|
| CD `30 + 6S` · Skill DMG `15 + 3S` · Ult DMG `15 + 3S` | `Reset_List` |
| ใช้ Skill/Ult → ตั้ง `stack["Somnus_Corpus"] = 1` | `AfterAttackActionList` |
| FuA ครั้งถัดไป → DMG[Fua] `40 + 8S` เฉพาะ action นั้น | `BeforeAttackAction_List` ลง / `AfterAttackActionList` ถอน |

## รากฐาน: บัฟที่ครอบ action เดียวโดยเขียน `Stats_type` ตรง ๆ

```cpp
Before: if (ผู้สวม && stack["Somnus_Corpus"] == 1 && มี AType::Fua ใน actionTypeList)
            ptr->Stats_type[DMG][AType::Fua] += 40 + 8*S;
After:  ... ตรวจเงื่อนไขเดิม -> -= 40 + 8*S;  stack["Somnus_Corpus"] = 0;
```
**ไม่ใช้ `buffSingle` เพราะไม่ต้องการให้มีชื่อบัฟและอายุ** — เป็นบัฟที่มีผลกับ action เดียวเท่านั้น · สำนวนเดียวกับ `../Nihility/Fermata.md` แต่ทำกับฝั่งตัวเอง

**วน `act->actionTypeList` หา `AType::Fua`** แทนการเทียบ `AType` ตัวเดียว เพราะ action หนึ่งมีได้หลายประเภท (เหมือน `../../Relic/Grand_Duke.md`)

## จุดที่ควรระวัง

**บล็อก `AfterAttackActionList` ตั้ง flag ก่อนแล้วค่อยเช็คถอนในฟังก์ชันเดียวกัน** — ถ้า action เดียวมีทั้ง `AType::SKILL` และ `AType::Fua` (เป็นไปได้ถ้าใส่หลายประเภท) จะตั้ง flag แล้วถอนทันทีในรอบเดียว
