# `src/Defination/Data/Lightcone/Remembrance/Hyacnine_LC.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Hyacnine_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ Hyacine** (ชื่อไฟล์สะกด `Hyacnine` ต่างจากชื่อตัวละคร `Hyacine`) · ดู `../../Character/Remembrance/Hyacine.md`

| ท่อน | โค้ด |
|---|---|
| SPD% `15 + 3S` | `Reset_List` |
| memosprite ของผู้สวมใช้ Skill → ศัตรูทุกตัวติด VUL `13.5 + 4.5S` 2 เทิร์น | `BeforeAction_List` |
| ผู้สวมใช้ BA/Skill/Ult → ทีมเสีย HP ปัจจุบัน `0.75 + 0.25S`% และสะสมยอดที่เสีย | `BeforeAction_List` ท่อนที่สอง → `DecreaseHP(ptr, 0, 0, %)` (overload ลดทั้งทีม) |
| memosprite โจมตีครั้งถัดไป (ท่าไหนก็ได้) → ปล่อยยอดสะสม × `1.875 + 0.625S` เป็น Additional DMG | `AfterAttackActionList` |
| ถอน VUL | `After_turn_List` |

## รากฐาน: `act->castToAllyActionData()`

```cpp
AllyActionData *allyaction = act->castToAllyActionData();
if (!allyaction) return;
```
`BeforeAction_List` เห็น action ของ **ทั้งฝ่ายเราและศัตรู** → ต้อง cast ลงมาเป็น `AllyActionData` ก่อนใช้ · คู่กับ `castToEnemyActionData()` ที่ `../../Character/Remembrance/Hyacine.md` และ `../../Character/Destruction/Phainon.md` ใช้

## รูปแบบปัจจุบันของ Additional DMG

```cpp
double consumed = ptr->buffNote["Hyacnine_LC Note"];
if (consumed <= 0) return;
ptr->setBuffNote("Hyacnine_LC Note", 0);           // ล้างก่อน — Additional DMG ก็เป็นการโจมตีของ memosprite จะยิง list นี้ซ้ำ
addtionaldmg->addDamageIns(DmgSrc(DmgSrcType::CONST, consumed * (1.875 + 0.625*S), 0));
Attack(addtionaldmg);
```

ชื่อ debuff `"Hyacnine_LC Debuff"` ไม่มี prefix โดยตั้งใจ — kit "The same types of effects cannot stack"

> **แก้ 2026-09-26 ตาม kit**: (1) เดิม `act->addDamageIns(...)` ใส่ดาเมจเข้า action ที่ยิงจบแล้ว ส่วน `addtionaldmg` ว่างเปล่า → **Additional DMG ไม่เคยออก** (2) เดิมสะสม 1% ของ HP ทุกคนตายตัว แต่หักจริง `0.75 + 0.25S`% → ตอนนี้สะสมเท่าที่หัก (นับเฉพาะคนที่ `isTargetable()` เหมือน `DecreaseHP`) (3) เดิมปล่อยเฉพาะตอน memosprite ใช้ Skill → kit "after the next attack launched by the wearer's memosprite" จึงปล่อยกับการโจมตีท่าไหนก็ได้ · `DecreaseHP(ptr, 0, 0, x)` ที่เคยสงสัย เป็น overload `(Unit *Trigger, Value, %TotalHP, %CurrentHP)` ลดทั้งทีม ถูกต้อง
