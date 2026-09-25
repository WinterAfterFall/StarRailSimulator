# `src/Defination/Data/Lightcone/Remembrance/Hyacnine_LC.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Hyacnine_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ Hyacine** (ชื่อไฟล์สะกด `Hyacnine` ต่างจากชื่อตัวละคร `Hyacine`) · ดู `../../Character/Remembrance/Hyacine.md`

| ท่อน | โค้ด |
|---|---|
| SPD% `15 + 3S` | `Reset_List` |
| memosprite ของผู้สวมใช้ Skill → ศัตรูทุกตัวติด VUL `13.5 + 4.5S` 2 เทิร์น | `BeforeAction_List` |
| ผู้สวมใช้ BA/Skill/Ult → สะสม 1% ของ HP ปัจจุบันของทุกคน + เสีย HP `0.75 + 0.25S` | `BeforeAction_List` ท่อนที่สอง |
| memosprite ใช้ Skill → ปล่อยยอดสะสมเป็น Additional DMG | `AfterAttackActionList` |
| ถอน VUL | `After_turn_List` |

## รากฐาน: `act->castToAllyActionData()`

```cpp
AllyActionData *allyaction = act->castToAllyActionData();
if (!allyaction) return;
```
`BeforeAction_List` เห็น action ของ **ทั้งฝ่ายเราและศัตรู** → ต้อง cast ลงมาเป็น `AllyActionData` ก่อนใช้ · คู่กับ `castToEnemyActionData()` ที่ `../../Character/Remembrance/Hyacine.md` และ `../../Character/Destruction/Phainon.md` ใช้

## บั๊ก: ใส่ดาเมจผิด action

```cpp
shared_ptr<AllyAttackAction> addtionaldmg =
    make_shared<AllyAttackAction>(AType::Addtional, act->Attacker, TraceType::Single, "Hyc LC AddDmg");
act->addDamageIns(DmgSrc(DmgSrcType::CONST, ptr->buffNote["Hyacnine_LC Note"] * (1.875 + 0.625*S), 0));
Attack(addtionaldmg);
```
**`act->addDamageIns(...)` ใส่ดาเมจเข้า `act`** ซึ่งเป็น action ที่ **เพิ่งยิงจบไปแล้ว** (อยู่ใน `AfterAttackActionList`) แทนที่จะเป็น `addtionaldmg` ที่เพิ่งสร้าง

**ผล**: `Attack(addtionaldmg)` ยิง action ที่ไม่มีก้อนดาเมจเลย → **Additional DMG ของ LC ใบนี้ไม่ออกดาเมจ** · ส่วนดาเมจที่ใส่เข้า `act` อาจถูกคำนวณซ้ำถ้ามี trigger อื่นใช้ `act` ต่อ

ควรเป็น `addtionaldmg->addDamageIns(...)`

## จุดที่ควรระวังเพิ่ม

- **`DecreaseHP(ptr, 0, 0, (0.75 + 0.25*S))`** ส่ง arg ตัวที่ 2 เป็น `0` (ควรเป็น `Unit*`) — ต้องตรวจ overload ว่ารับแบบนี้ได้จริงไหม
- **วน `allyList` บวก `currentHP * 0.01` ของทุกคน** ทุกครั้งที่ผู้สวมทำ action — ไม่มี cap
