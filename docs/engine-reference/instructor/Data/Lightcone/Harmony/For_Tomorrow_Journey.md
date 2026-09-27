# `src/Defination/Data/Lightcone/Harmony/For_Tomorrow_Journey.h`

`namespace Harmony_Lightcone` · `lightCone.name` = `"For_Tomorrow_Journey"` · base stats `setAllyBaseStats(953, 476, 331)`

**free**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `For_Tomorrow_Journey.h:5` |
| ATK% `12 + 4S` | บวกถาวร | `:9` |
| ผู้สวมกด Ult → DMG `15 + 3S` นาน 1 เทิร์น | `whenUseUltList` + `isSameOwner` → `buffSingle(…, "For_Tomorrow_Journey_Buff", 1)` | `:12-18` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:20-26` |

## แก้แล้ว 2026-09-26: ถอนบัฟด้วยชื่อผิด

```cpp
whenUseUltList:  buffSingle(ptr, {{DMG, 15.0 + 3*S}}, "For_Tomorrow_Journey_Buff", 1);
afterTurnList:  if (isBuffEnd(ptr, "For_Tomorrow_Journey_Buff")) { ... }   // เดิมเป็น "Himeko_LC_buff"
```
เดิมบล็อกถอนเช็คชื่อ `"Himeko_LC_buff"` ที่ copy มาจาก `../Erudition/Himeko_LC.h` → `isBuffEnd` ไม่มีวันเป็นจริง **DMG `15 + 3S` ค้างถาวรตั้งแต่ ult ครั้งแรก** (ไม่ซ้อนเพิ่ม เพราะ `buffSingle` แบบมีชื่อเช็ค `buffCheck` ก่อนบวก)

เป็นบั๊กชนิดเดียวกับที่แก้ไปแล้วใน `../../Character/Nihility/Kafka.md` (`"kafka E1"` vs `"Kafka E1"`) และ `../../Character/Abundance/Luocha.md` (`"Cycle _of_Life"`)
