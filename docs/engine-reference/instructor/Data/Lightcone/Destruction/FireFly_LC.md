# `src/Defination/Data/Lightcone/Destruction/FireFly_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"FireFly_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ FireFly** (ดู `../../Character/Destruction/FireFly.md`)

| ท่อน | โค้ด |
|---|---|
| Break Effect `50 + 10S` | `Reset_List` |
| โจมตี → เป้าติด Break VUL `20 + 4S` + SPD −20 (2 เทิร์น) | `AfterAttackActionList` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ

## guard ผู้โจมตี (แก้แล้ว 2026-09-26)

เดิมเขียน `num != ptr->num && side != Side::Ally` ซึ่งเป็นเท็จเสมอสำหรับ ally → Routed ติดทุกครั้งที่ใครในทีมโจมตี · ตอนนี้เป็น `if (!act->isSameOwnerName(ptr)) return;` → เฉพาะผู้สวม

kit บอกว่าติดเมื่อ "สร้าง Break DMG" แต่โค้ดติดทุกการโจมตีของผู้สวม — ผลต่างน้อยเพราะ Firefly สร้าง Break DMG เกือบทุกครั้ง

## จุดที่ควรระวังเพิ่ม

- **`After_turn_List` เช็ค `turn != nullptr`** — เป็นที่เดียวในโปรเจกต์ที่ระวังกรณีนี้
- ลด SPD ศัตรู −20 เป็นค่าคงที่ ไม่ขึ้นกับ superimpose
