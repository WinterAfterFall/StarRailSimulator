# `src/Defination/Data/Lightcone/Erudition/Before_Dawn.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Before_Dawn"` · base stats `SetAllyBaseStats(1058, 582, 463)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 582, 463)` | `Before_Dawn.h:5` |
| CD `30 + 6S` · Skill DMG และ Ult DMG `15 + 3S` | บวกถาวร | `:9-11` |
| ใช้ Skill/Ult → ได้ "Somnus Corpus" | `AfterAttackActionList` ตั้ง `stack["Somnus_Corpus"] = 1` | `:29-34` |
| Follow-up ครั้งถัดไป (มี Somnus Corpus) → FuA DMG `40 + 8S` แล้วใช้หมด | ลงก่อน action ใน `BeforeAttackAction_List` · ถอนและล้าง stack หลัง action | ลง `:14-24` · ถอน `:36-45` |

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
