# `src/Defination/Data/Lightcone/Destruction/Phainon LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Phainon_LC"` · base stats `SetAllyBaseStats(953, 687, 397)`

**signature ของ Phainon** (ดู `../../Character/Destruction/Phainon.md`)

| ท่อน | โค้ด |
|---|---|
| **`baseSpeed += 10 + 2S`** | เขียนนอก trigger ใด ๆ ตอน `Setup` |
| DEF_SHRED `13.5 + 4.5S` | `Reset_List` |
| กด ult → DMG `42 + 18S` 1 เทิร์น | `WhenUseUlt_List` + `isSameOwner` |
| ถอน | `Before_turn_List` → `isBuffEnd(ptr, "Blazing Sun")` |

## จุดที่ต่างจากใบอื่น

**เป็น LC ใบเดียวในโปรเจกต์ที่แก้ `baseSpeed`** (บรรทัด 7) — `ptr->Atv_stats->baseSpeed += 10 + superimpose * 2;` เขียนตรงใน lambda ของ LC ก่อน `Reset_List` · **ไม่ได้เรียก `Update_Max_atv`** ต่างจาก `../../Character/Harmony/Robin.md` ที่เรียกเสมอหลังแก้ `baseSpeed` — ที่นี่รอดเพราะทำตอน setup ก่อนการต่อสู้เริ่ม

**ถอนบัฟใน `Before_turn_List` ไม่ใช่ `After_turn_List`** — ต่างจากเกือบทุกใบ · เหมาะกับบัฟอายุ 1 เทิร์นที่ต้องอยู่จนจบเทิร์นของตัวเอง
