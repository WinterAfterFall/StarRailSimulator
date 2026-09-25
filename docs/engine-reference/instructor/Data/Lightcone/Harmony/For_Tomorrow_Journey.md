# `src/Defination/Data/Lightcone/Harmony/For_Tomorrow_Journey.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"For_Tomorrow_Journey"` · base stats `SetAllyBaseStats(953, 476, 331)`

**free**

| ท่อน | โค้ด |
|---|---|
| ATK% `12 + 4S` | `Reset_List` |
| กด ult → ตัวเอง DMG `15 + 3S` 1 เทิร์น | `WhenUseUlt_List` → `buffSingle(..., "For_Tomorrow_Journey_Buff", 1)` |
| ถอน | `After_turn_List` |

## บั๊ก: ถอนบัฟด้วยชื่อผิด

```cpp
WhenUseUlt_List:  buffSingle(ptr, {{DMG, 15.0 + 3*S}}, "For_Tomorrow_Journey_Buff", 1);   // ลงด้วยชื่อนี้
After_turn_List:  if (isBuffEnd(ptr, "Himeko_LC_buff")) { ... }                            // เช็คด้วยชื่อนี้
```
**`"Himeko_LC_buff"` เป็นชื่อบัฟของ `../Erudition/Himeko_LC.h`** — copy ไฟล์มาแล้วลืมเปลี่ยนชื่อในบล็อกถอน

**ผล**: `isBuffEnd` อ่าน `buffEnd["Himeko_LC_buff"]` ที่ไม่เคยถูกเขียน (default 0) จึงไม่มีวันเป็นจริง → **DMG `15 + 3S` ค้างถาวรและซ้อนทับทุกครั้งที่กด ult**

เป็นบั๊กชนิดเดียวกับที่แก้ไปแล้วใน `../../Character/Nihility/Kafka.md` (`"kafka E1"` vs `"Kafka E1"`) และ `../../Character/Abundance/Luocha.md` (`"Cycle _of_Life"`)
