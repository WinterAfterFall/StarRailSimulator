# `src/Defination/Data/Lightcone/Remembrance/Geniuses_Greetings.h`

`namespace Remembrance_Lightcone` · `lightCone.name` = `"Geniuses_Greetings"` · base stats `setAllyBaseStats(953, 476, 331)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `Geniuses_Greetings.h:5` |
| ATK% `12 + 4S` | บวกถาวร | `:9` |
| ผู้สวมกด Ult → Basic ATK DMG `15 + 5S` นาน 3 เทิร์น (ผู้สวม + memosprite) | `whenUseUltList` + `isSameOwner` → `buffSingleChar(…, "Geniuses_Greetings", 3)` | `:12-16` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นของแต่ละตัว `isBuffEnd` | `:18-24` |

## รากฐาน: ถอนผ่านเจ้าของเทิร์น

```cpp
AllyUnit *tempstats = turn->canCastToAllyUnit();
if (isBuffEnd(tempstats, "Geniuses_Greetings")) buffSingle(tempstats, {{DMG, BA, -(15 + 5S)}});
```
`buffSingleChar(ptr, ..., "Geniuses_Greetings", 3)` ลงบัฟพร้อม `buffEnd` แยกให้ทั้งผู้สวมและ memosprite · ตอนจบเทิร์นของใคร ก็เช็ค `buffEnd` ของคนนั้นแล้วถอนจากคนนั้น → ผู้สวมกับ memosprite หมดอายุตามเทิร์นของตัวเอง

ชื่อบัฟไม่มี prefix เพราะลงเฉพาะผู้สวมและ memosprite ของตัวเอง

> **แก้ 2026-09-26** (user กำหนดวิธี: เช็ค buffEnd ผ่านเจ้าของเทิร์น): เดิมลงด้วย `buffSingleChar` (ผู้สวม + memosprite) แต่ถอนด้วย `buffSingle(ptr, ...)` เฉพาะผู้สวม → **บัฟบน memosprite ค้างถาวร** · ลบ `dynamic_cast` ที่ไม่ได้ใช้
