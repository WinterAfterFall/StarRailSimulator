# `src/Defination/Data/Lightcone/Remembrance/Geniuses_Greetings.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Geniuses_Greetings"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| ATK% `12 + 4S` | `Reset_List` |
| กด ult → BA DMG `15 + 5S` 3 เทิร์น | `WhenUseUlt_List` + `isSameOwner` → `buffSingleChar` |
| ถอน | `After_turn_List` |

## รากฐาน: ถอนผ่านเจ้าของเทิร์น

```cpp
AllyUnit *tempstats = turn->canCastToAllyUnit();
if (isBuffEnd(tempstats, "Geniuses_Greetings")) buffSingle(tempstats, {{DMG, BA, -(15 + 5S)}});
```
`buffSingleChar(ptr, ..., "Geniuses_Greetings", 3)` ลงบัฟพร้อม `buffEnd` แยกให้ทั้งผู้สวมและ memosprite · ตอนจบเทิร์นของใคร ก็เช็ค `buffEnd` ของคนนั้นแล้วถอนจากคนนั้น → ผู้สวมกับ memosprite หมดอายุตามเทิร์นของตัวเอง

ชื่อบัฟไม่มี prefix เพราะลงเฉพาะผู้สวมและ memosprite ของตัวเอง

> **แก้ 2026-09-26** (user กำหนดวิธี: เช็ค buffEnd ผ่านเจ้าของเทิร์น): เดิมลงด้วย `buffSingleChar` (ผู้สวม + memosprite) แต่ถอนด้วย `buffSingle(ptr, ...)` เฉพาะผู้สวม → **บัฟบน memosprite ค้างถาวร** · ลบ `dynamic_cast` ที่ไม่ได้ใช้
