# `src/Defination/Data/Lightcone/Destruction/FireFly_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"FireFly_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ FireFly** (ดู `../../Character/Destruction/FireFly.md`)

| ท่อน | โค้ด |
|---|---|
| Break Effect `50 + 10S` | `Reset_List` |
| โจมตี → เป้าติด Break VUL `20 + 4S` + SPD −20 (2 เทิร์น) | `AfterAttackActionList` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ

## บั๊ก: guard ผู้โจมตีเขียนกลับด้าน

```cpp
if (act->Attacker->Atv_stats->num != ptr->Atv_stats->num && act->Attacker->Atv_stats->side != Side::Ally) return;
```
เจตนาน่าจะเป็น "ไม่ใช่ผู้สวมและไม่ใช่ฝ่ายเรา ให้ข้าม" แต่ `side != Side::Ally` เป็นเท็จสำหรับ ally ทุกคน → **เงื่อนไขรวมเป็นเท็จเสมอสำหรับ ally** → ไม่เคย `return` → **debuff ถูกลงทุกครั้งที่ใครในทีมโจมตี**

ถ้าตั้งใจให้เฉพาะผู้สวม ควรเป็น `if (!act->isSameOwnerName(ptr)) return;`

## จุดที่ควรระวังเพิ่ม

- **`After_turn_List` เช็ค `turn != nullptr`** — เป็นที่เดียวในโปรเจกต์ที่ระวังกรณีนี้
- ลด SPD ศัตรู −20 เป็นค่าคงที่ ไม่ขึ้นกับ superimpose
