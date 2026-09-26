# `src/Defination/Data/Lightcone/Harmony/For_Tomorrow_Journey.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"For_Tomorrow_Journey"` · base stats `SetAllyBaseStats(953, 476, 331)`

**free**

| ท่อน | โค้ด |
|---|---|
| ATK% `12 + 4S` | `Reset_List` |
| กด ult → ตัวเอง DMG `15 + 3S` 1 เทิร์น | `WhenUseUlt_List` → `buffSingle(..., "For_Tomorrow_Journey_Buff", 1)` |
| ถอน | `After_turn_List` |

## แก้แล้ว 2026-09-26: ถอนบัฟด้วยชื่อผิด

```cpp
WhenUseUlt_List:  buffSingle(ptr, {{DMG, 15.0 + 3*S}}, "For_Tomorrow_Journey_Buff", 1);
After_turn_List:  if (isBuffEnd(ptr, "For_Tomorrow_Journey_Buff")) { ... }   // เดิมเป็น "Himeko_LC_buff"
```
เดิมบล็อกถอนเช็คชื่อ `"Himeko_LC_buff"` ที่ copy มาจาก `../Erudition/Himeko_LC.h` → `isBuffEnd` ไม่มีวันเป็นจริง **DMG `15 + 3S` ค้างถาวรตั้งแต่ ult ครั้งแรก** (ไม่ซ้อนเพิ่ม เพราะ `buffSingle` แบบมีชื่อเช็ค `buffCheck` ก่อนบวก)

เป็นบั๊กชนิดเดียวกับที่แก้ไปแล้วใน `../../Character/Nihility/Kafka.md` (`"kafka E1"` vs `"Kafka E1"`) และ `../../Character/Abundance/Luocha.md` (`"Cycle _of_Life"`)
