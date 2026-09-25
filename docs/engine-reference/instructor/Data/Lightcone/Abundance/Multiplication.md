# `src/Defination/Data/Lightcone/Abundance/Multiplication.h`

`namespace Abundance_Lightcone` · `Light_cone.Name` = `"Multiplication"` · base stats `SetAllyBaseStats(953, 318, 198)`

**ใบเดียวของโฟลเดอร์** · 3★ base stats ต่ำ

| ท่อน | โค้ด |
|---|---|
| ผู้สวมใช้ BA → advance `10 + 2S` | `AllyActionList` → `act->isSameOwnerAction(ptr, AType::BA)` → `Action_forward(turn, ...)` |

**ไม่มีสแตตติดตัว**

## จุดที่น่าสังเกต

**`Action_forward(turn, ...)` ส่ง `turn` (global ของเทิร์นปัจจุบัน) ไม่ใช่ `ptr->Atv_stats.get()`** — ต่างจากทุกใบอื่นในโปรเจกต์ที่ระบุ unit ตรง ๆ

ผลคือ advance ตกที่ **unit ที่กำลังเล่นอยู่** ซึ่งในกรณีปกติคือผู้สวมเอง (เพราะเพิ่งใช้ BA) แต่ถ้ามี action ซ้อนจากเทิร์นของคนอื่นจะไปถูกคนผิด

**`isSameOwnerAction(ptr, AType::BA)`** เป็น overload ที่เช็คทั้ง owner และชนิด action ในครั้งเดียว — ครอบ memosprite ของเจ้าของด้วย
