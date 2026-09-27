# `src/Defination/Data/Lightcone/Nihility/ShowTime.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"ShowTime"` · base stats `setAllyBaseStats(1058, 476, 265)`

บังคับ `newEhrRequire(80)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 476, 265)` | `ShowTime.h:5` |
| (AI) EHR ขั้นต่ำ 80 | `newEhrRequire(80)` | `:7` |
| ATK% `16 + 4S` | บวกถาวร | `:9` |
| ผู้สวมติด debuff ให้ศัตรู → DMG `5 + S`% ต่อชั้น (สูงสุด 3) นาน 1 เทิร์น | `afterApplyDebuff` → `buffStackSingle(…, 1, 3, "ShowTime Trick", 1)` | `:12-16` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์น ally `isBuffEnd` → `buffResetStack` | `:18-25` |

## จุดที่ควรระวัง

- **`afterTurnList` เช็ค `isBuffEnd(ally, ...)` กับ ally ที่เพิ่งจบเทิร์น แล้วถอนจาก `ally` คนนั้น** — แต่บัฟลงที่ `ptr` (ผู้สวม) เสมอ · ถ้า ally คนอื่นบังเอิญมีบัฟชื่อเดียวกันจะถูกถอนผิดคน · ที่ถูกควรเช็คและถอนที่ `ptr` ตรง ๆ
- **ชื่อบัฟไม่ prefix ด้วยชื่อเจ้าของ** — บัฟลงกับผู้สวมเท่านั้น แต่ละคนมี map บัฟของตัวเอง จึงไม่ชนกัน
