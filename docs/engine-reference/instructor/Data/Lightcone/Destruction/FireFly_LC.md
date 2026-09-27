# `src/Defination/Data/Lightcone/Destruction/FireFly_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"FireFly_LC"` · base stats `setAllyBaseStats(1164, 476, 529)`

**signature ของ FireFly** (ดู `../../Character/Destruction/FireFly.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 476, 529)` | `FireFly_LC.h:5` |
| Break Effect `50 + 10S` | บวกถาวร | `:9` |
| ผู้สวมโจมตี → เป้าติด "Routed": Break DMG ที่รับ +`20 + 4S`% และ SPD −20% นาน 2 เทิร์น | `afterAttackActionList` guard `isSameOwnerName(ptr)` · `debuffSingleApply` ทุกเป้าใน `targetList` · ชื่อ debuff ขึ้นต้นด้วยชื่อผู้สวม (`:7`) | `:13-21` |
| หมดอายุ → ถอน | ท้ายเทิร์นศัตรู `isDebuffEnd` → คืน VUL และ SPD | `:23-32` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ

## guard ผู้โจมตี (แก้แล้ว 2026-09-26)

เดิมเขียน `num != ptr->num && side != Side::ALLY` ซึ่งเป็นเท็จเสมอสำหรับ ally → Routed ติดทุกครั้งที่ใครในทีมโจมตี · ตอนนี้เป็น `if (!act->isSameOwnerName(ptr)) return;` → เฉพาะผู้สวม

kit บอกว่าติดเมื่อ "สร้าง Break DMG" แต่โค้ดติดทุกการโจมตีของผู้สวม — ผลต่างน้อยเพราะ Firefly สร้าง Break DMG เกือบทุกครั้ง

## จุดที่ควรระวังเพิ่ม

- **`afterTurnList` เช็ค `turn != nullptr`** — เป็นที่เดียวในโปรเจกต์ที่ระวังกรณีนี้
- ลด SPD ศัตรู −20 เป็นค่าคงที่ ไม่ขึ้นกับ superimpose
