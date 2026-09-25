# `src/Defination/Data/Lightcone/Destruction/Jingliu_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Jingliu_LC"` · base stats `SetAllyBaseStats(1164, 582, 397)`

**signature ของ Jingliu** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

| ท่อน | โค้ด |
|---|---|
| CD `17 + 3S` | `Reset_List` |
| ถูกตี → DMG stack `11.5 + 2.5S` (cap 3) | `Enemy_hit_List` |
| เสีย HP → DMG stack เหมือนกัน | `HPDecrease_List` |
| ครบ 3 stack → DEF_SHRED `10 + 2S` | `isHaveToAddBuff(ptr, "Jingliu_LC Def Shred")` |
| ผู้สวมโจมตี → ล้างทั้งหมด | `AfterAttackActionList` |

## จุดที่ควรระวัง

- **`Enemy_hit_List` วน `target` แล้ว `buffStackSingle` ทุกรอบโดยไม่เช็คว่าเป็นผู้สวม** — ตัวแปร `e` ไม่ได้ถูกใช้เลย → **ศัตรูตีโดน 3 คน = ได้ 3 stack ในครั้งเดียว** แม้ไม่ได้โดนเอง · เทียบกับ `Blade_LC.h` และ `Clara_LC.h` ที่เช็ค `e->isSameName(ptr)` ถูกต้อง
- **`HPDecrease_List` ก็ไม่ guard `target`** → ได้ stack ทุกครั้งที่ใครในทีมเสีย HP
- **บล็อกเช็คครบ 3 stack ถูก copy 2 ที่**
- ถอนด้วย `buffCharResetStack` (ตระกูล `...Char`) ทั้งที่ลงด้วย `buffStackSingle` — คนละตระกูล
