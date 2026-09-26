# `src/Defination/Data/Lightcone/Nihility/HertaShop.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Solitary Healing"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `HertaShop` แต่ `Light_cone.Name` เป็น `"Solitary Healing"`** — ชื่อไฟล์บอกแหล่งที่มา (ร้าน Herta) ไม่ใช่ชื่อใบ

| ท่อน | โค้ด |
|---|---|
| Break Effect `15 + 5S` | `Reset_List` |
| กด ult → DoT DMG `18 + 6S` 2 เทิร์น | `WhenUseUlt_List` + `isSameOwner` |
| ถอน | `After_turn_List` → `isBuffEnd` |

## จุดที่ควรระวัง

**`After_turn_List` เช็ค `isBuffEnd(ally, "Solitary Healing")` กับ ally ที่เพิ่งจบเทิร์น แต่ถอนจาก `ptr`** (ผู้สวม) — ถ้า ally คนอื่นมีบัฟชื่อเดียวกัน (เช่นสวมใบเดียวกัน) จะถอนผิดจังหวะ · อาการเดียวกับ `ShowTime.md`

> มีไฟล์ชื่อ `HertaShop.h` ใน `../Destruction/` ด้วย — คนละใบ คนละ namespace
