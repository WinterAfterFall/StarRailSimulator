# `src/Defination/Data/Lightcone/Nihility/ShowTime.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"ShowTime"` · base stats `SetAllyBaseStats(1058, 476, 265)`

บังคับ `newEhrRequire(80)`

| ท่อน | โค้ด |
|---|---|
| ATK% `16 + 4S` | `Reset_List` |
| ลง debuff สำเร็จ → DMG stack `5 + S` (cap 3, 1 เทิร์น) | `AfterApplyDebuff` → `buffStackSingle(ptr, ..., 1, 3, "ShowTime Trick", 1)` |
| ถอน | `After_turn_List` → `isBuffEnd` → `buffResetStack` |

## จุดที่ควรระวัง

- **`After_turn_List` เช็ค `isBuffEnd(ally, ...)` กับ ally ที่เพิ่งจบเทิร์น แล้วถอนจาก `ally` คนนั้น** — แต่บัฟลงที่ `ptr` (ผู้สวม) เสมอ · ถ้า ally คนอื่นบังเอิญมีบัฟชื่อเดียวกันจะถูกถอนผิดคน · ที่ถูกควรเช็คและถอนที่ `ptr` ตรง ๆ
- **ชื่อบัฟไม่ prefix ด้วยชื่อเจ้าของ** ทั้งที่บัฟลงกับผู้สวมเท่านั้น (ยังไม่เป็นปัญหาเพราะลงคนเดียว)
