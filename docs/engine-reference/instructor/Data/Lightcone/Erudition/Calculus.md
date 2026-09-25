# `src/Defination/Data/Lightcone/Erudition/Calculus.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Calculus"` · base stats `SetAllyBaseStats(1058, 529, 397)`

| ท่อน | โค้ด |
|---|---|
| ATK% `7 + S` | `Reset_List` |
| ATK% เพิ่มตามจำนวนเป้าของ action (`เป้า × 3 + S`) | `BeforeAttackAction_List` |
| ถ้า ATK ที่ได้ ≥ 24 → SPD `6 + 2S` 1 เทิร์น | เงื่อนไขในบล็อกเดียวกัน |
| ถอน SPD | `After_turn_List` |

## รากฐาน: ถอนของเก่า-ตั้งค่าใหม่-ใส่ของใหม่

```cpp
ptr->Stats_type[ATK_P][None] -= ptr->buffNote["Calculus_Atk_buff"];
ptr->buffNote["Calculus_Atk_buff"] = act->targetList.size() * 3 + superimpose;
ptr->Stats_type[ATK_P][None] += ptr->buffNote["Calculus_Atk_buff"];
```
ค่าเปลี่ยนเป็นค่าใหม่ทั้งก้อน (ไม่ใช่เพิ่มทีละนิด) → ต้องถอนของเดิมออกก่อน · สำนวนเดียวกับ `../../Relic/Grand_Duke.md`

## จุดที่ควรระวัง

- **`BeforeAttackAction_List` ไม่ guard ผู้โจมตี** → ATK ของผู้สวมเปลี่ยนตามจำนวนเป้าของ action ของ **ทุกคนในทีม** รวม DoT และ additional · เป็นบั๊กที่ชัดเจนถ้า kit ระบุเฉพาะ action ของผู้สวม
- **ATK ที่ค้างอยู่จาก action สุดท้ายไม่ถูกถอน** — ค้างจนกว่าจะมี action ถัดไปมาเขียนทับ
