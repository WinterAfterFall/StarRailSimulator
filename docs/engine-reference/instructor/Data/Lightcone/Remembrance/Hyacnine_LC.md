# `src/Defination/Data/Lightcone/Remembrance/Hyacnine_LC.h`

`namespace Remembrance_Lightcone` · `lightCone.name` = `"Hyacnine_LC"` · base stats `setAllyBaseStats(1164, 476, 529)`

**signature ของ Hyacine** (ชื่อไฟล์สะกด `Hyacnine` ต่างจากชื่อตัวละคร `Hyacine`) · ดู `../../Character/Remembrance/Hyacine.md`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 476, 529)` | `Hyacnine_LC.h:5` |
| SPD `15 + 3S`% | บวก `speedPercent` ถาวร | `:8` |
| memosprite ของผู้สวมใช้ Skill → ศัตรูทุกตัว VUL `13.5 + 4.5S`% นาน 2 เทิร์น | `beforeActionList` เช็ค `side == Memosprite` + `num` + Skill → `debuffAllEnemyApply` | `:14-18` |
| ผู้สวมใช้ BA/Skill/Ult → หัก HP ทุกคน `0.75 + 0.25S`% ของ HP ปัจจุบัน แล้วจดยอดรวมไว้ | ในบล็อกเดียวกัน วน `allyList` รวมยอดลง `buffNote["Hyacnine_LC Note"]` แล้ว `decreaseHP` | `:19-31` |
| การโจมตีครั้งถัดไปของ memosprite → Additional DMG = ยอด HP ที่จด × `(1.875 + 0.625S)` | `afterAttackActionList` · รีเซ็ตยอดก่อนยิง (กันยิงซ้ำ) แล้ว `attack` action `AType::ADDTIONAL` ค่า `CONST` | `:34-46` |
| ถอน VUL | ท้ายเทิร์นศัตรู `isDebuffEnd` | `:48-54` |

## รากฐาน: `act->castToAllyActionData()`

```cpp
AllyActionData *allyaction = act->castToAllyActionData();
if (!allyaction) return;
```
`beforeActionList` เห็น action ของ **ทั้งฝ่ายเราและศัตรู** → ต้อง cast ลงมาเป็น `AllyActionData` ก่อนใช้ · คู่กับ `castToEnemyActionData()` ที่ `../../Character/Remembrance/Hyacine.md` และ `../../Character/Destruction/Phainon.md` ใช้

## รูปแบบปัจจุบันของ Additional DMG

```cpp
double consumed = ptr->buffNote["Hyacnine_LC Note"];
if (consumed <= 0) return;
ptr->setBuffNote("Hyacnine_LC Note", 0);           // ล้างก่อน — Additional DMG ก็เป็นการโจมตีของ memosprite จะยิง list นี้ซ้ำ
addtionaldmg->addDamageIns(DmgSrc(DmgSrcType::CONST, consumed * (1.875 + 0.625*S), 0));
attack(addtionaldmg);
```

ชื่อ debuff `"Hyacnine_LC Debuff"` ไม่มี prefix โดยตั้งใจ — kit "The same types of effects cannot stack"

> **แก้ 2026-09-26 ตาม kit**: (1) เดิม `act->addDamageIns(...)` ใส่ดาเมจเข้า action ที่ยิงจบแล้ว ส่วน `addtionaldmg` ว่างเปล่า → **Additional DMG ไม่เคยออก** (2) เดิมสะสม 1% ของ HP ทุกคนตายตัว แต่หักจริง `0.75 + 0.25S`% → ตอนนี้สะสมเท่าที่หัก (นับเฉพาะคนที่ `isTargetable()` เหมือน `decreaseHP`) (3) เดิมปล่อยเฉพาะตอน memosprite ใช้ Skill → kit "after the next attack launched by the wearer's memosprite" จึงปล่อยกับการโจมตีท่าไหนก็ได้ · `decreaseHP(ptr, 0, 0, x)` ที่เคยสงสัย เป็น overload `(Unit *trigger, value, %TotalHP, %CurrentHP)` ลดทั้งทีม ถูกต้อง
