# `src/Defination/Data/Lightcone/Nihility/HertaShop.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Solitary Healing"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `HertaShop` แต่ `Light_cone.Name` เป็น `"Solitary Healing"`** — ชื่อไฟล์บอกแหล่งที่มา (ร้าน Herta) ไม่ใช่ชื่อใบ

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 529, 397)` | `HertaShop.h:5` |
| Break Effect `15 + 5S` | บวกถาวร | `:8` |
| ผู้สวมกด Ult → DoT DMG `18 + 6S` นาน 2 เทิร์น | `WhenUseUlt_List` + `isSameOwner` → `buffSingle(…, "Solitary Healing", 2)` | `:10-12` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์น ally `isBuffEnd` | `:14-21` |

## จุดที่ควรระวัง

**`After_turn_List` เช็ค `isBuffEnd(ally, "Solitary Healing")` กับ ally ที่เพิ่งจบเทิร์น แต่ถอนจาก `ptr`** (ผู้สวม) — ถ้า ally คนอื่นมีบัฟชื่อเดียวกัน (เช่นสวมใบเดียวกัน) จะถอนผิดจังหวะ · อาการเดียวกับ `ShowTime.md`

> มีไฟล์ชื่อ `HertaShop.h` ใน `../Destruction/` ด้วย — คนละใบ คนละ namespace
