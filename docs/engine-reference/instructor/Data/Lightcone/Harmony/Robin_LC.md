# `src/Defination/Data/Lightcone/Harmony/Robin_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Robin_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Robin** (ดู `../../Character/Harmony/Robin.md`)

| ท่อน | โค้ด |
|---|---|
| โจมตี → `Energy_recharge += 2.5 + 0.5S` (cap 5 stack) | `When_attack_List` + `stack["Cantillation"]` |
| กด ult → ล้าง stack และคืน ER ที่เพิ่มไปทั้งหมด | `WhenUseUlt_List` |
| กด ult → ทีม DMG `20 + 4S` + ตัวเอง ATK `36 + 12S` (1 เทิร์น) | `isHaveToAddBuff(ptr, "Cadenza", 1)` |
| ถอน | `After_turn_List` → `isBuffEnd(ptr, "Cadenza")` |

## รากฐาน: ER เป็นทรัพยากรที่สะสมแล้วคืน

```cpp
When_attack: if (stack < 5) { stack++; ptr->Energy_recharge += 2.5 + 0.5*S; }
WhenUseUlt:  ptr->Energy_recharge -= stack * (2.5 + 0.5*S);  stack = 0;
```
**เขียน `Energy_recharge` ตรง ๆ ไม่ผ่าน `buffSingle`** — เป็นฟิลด์แยกจาก `Stats_type[Stats::ER]` (ดู `../../Planar/Lushaka.md`) · การถอนคำนวณจาก stack ที่เหลือ ซึ่งถูกต้องตราบใดที่ค่าต่อ stack ไม่เปลี่ยน

## จุดที่ควรระวัง

- **`When_attack_List` ไม่ guard ผู้โจมตี** → ได้ stack จากการโจมตีของ **ทุกคน** รวม DoT/additional · ถ้า kit ระบุเฉพาะเจ้าของจะสะสมเร็วเกินจริง
- **บัฟทีมใช้ `buffAllAlly` แบบไม่มีชื่อ** แล้วคุมอายุด้วยบัฟ `"Cadenza"` บนตัวผู้สวม → ไม่มี `AllyDeath_List` รองรับ
