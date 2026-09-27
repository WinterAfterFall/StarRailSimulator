# `src/Defination/Data/Lightcone/Erudition/Calculus.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Calculus"` · base stats `SetAllyBaseStats(1058, 529, 397)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 529, 397)` | `Calculus.h:5` |
| ATK% `7 + S` | บวกถาวร | `:9` |
| หลังผู้สวมโจมตี → ATK% `(3 + S)` × จำนวนเป้า (สูงสุด 5) จนกว่าจะโจมตีครั้งถัดไป | `AfterAttackActionList` ถอนค่าเก่าจาก `buffNote` แล้วลงค่าใหม่ | `:19-25` |
| ตีโดน ≥ 3 เป้า → SPD `6 + 2S`% นาน 1 เทิร์น | `buffSingle(…, "Calculus_Speed_buff", 1)` ในบล็อกเดียวกัน | `:26-28` |
| ถอน SPD เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:12-17` |

## รากฐาน: ถอนของเก่า-ตั้งค่าใหม่-ใส่ของใหม่

```cpp
ptr->Stats_type[ATK_P][None] -= ptr->buffNote["Calculus_Atk_buff"];
ptr->buffNote["Calculus_Atk_buff"] = min(act->targetList.size(), 5) * (3 + superimpose);
ptr->Stats_type[ATK_P][None] += ptr->buffNote["Calculus_Atk_buff"];
```
ค่าเปลี่ยนเป็นค่าใหม่ทั้งก้อน (ไม่ใช่เพิ่มทีละนิด) → ต้องถอนของเดิมออกก่อน · สำนวนเดียวกับ `../../Relic/Grand_Duke.md`

## จุดที่ควรระวัง

- **ATK ค้างจนกว่าผู้สวมจะโจมตีครั้งถัดไป** — ตรงกับ kit ("lasts until the next attack")

> สูตรต่อเป้าเคยเป็น `เป้า * 3 + S` (S5 ตี 5 เป้าได้ 20) แก้เป็น `เป้า * (3 + S)` แล้ว (S5 ตี 5 เป้า = 8 × 5 = 40) · เงื่อนไข SPD เคยเช็ค `ATK ที่ได้ >= 24` แก้เป็น `targetList.size() >= 3` ตาม kit

> เคยลงใน `BeforeAttackAction_List` (บัฟเข้าการโจมตีที่นับเป้าเอง ผิดจาก kit ที่ให้ผลกับครั้งถัดไป) และไม่มีเพดาน 5 สแต็ก · ย้ายไป `AfterAttackActionList` + `min(เป้า, 5)` แล้ว
> เคยไม่ guard ผู้โจมตี (action ของทุกคนในทีมเปลี่ยน ATK/เปิด SPD ให้ผู้สวม) · เพิ่ม `if (!act->isSameName(ptr)) return;` แล้ว
