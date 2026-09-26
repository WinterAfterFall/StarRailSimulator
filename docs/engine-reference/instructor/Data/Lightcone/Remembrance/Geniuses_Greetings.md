# `src/Defination/Data/Lightcone/Remembrance/Geniuses_Greetings.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Geniuses_Greetings"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| ATK% `12 + 4S` | `Reset_List` |
| กด ult → BA DMG `15 + 5S` 3 เทิร์น | `WhenUseUlt_List` + `isSameOwner` → `buffSingleChar` |
| ถอน | `After_turn_List` |

## จุดที่ควรระวัง

- **`dynamic_cast` ที่ไม่ได้ใช้** — `tempstats` ถูกใช้แค่เป็นตัวกรองว่าเทิร์นนี้เป็นของ ally แต่บล็อกข้างในอ้าง `ptr` ทั้งหมด · เขียน `if (!turn->canCastToAllyUnit()) return;` ก็ได้ผลเดียวกัน
- **ลงด้วย `buffSingleChar` (ถึง memosprite) แต่ถอนด้วย `buffSingle` (เฉพาะตัวละคร)** → **บัฟบน memosprite ไม่ถูกถอน** ค้างถาวร
