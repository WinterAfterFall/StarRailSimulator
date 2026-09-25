# `src/Defination/Data/Lightcone/Destruction/Clara_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Clara_LC"` · base stats `SetAllyBaseStats(1164, 582, 397)`

**signature ของ Clara** (ตัวละครยังไม่มีในโปรเจกต์)

| ท่อน | โค้ด |
|---|---|
| ATK% `20 + 4S` | `Reset_List` |
| ถูกตี → ฮีลตัวเอง `6 + 2S`% ATK + DMG `20 + 4S` 1 เทิร์น | `Enemy_hit_List` |
| ถอน | `After_turn_List` |

## จุดที่น่าสังเกต

**เป็น LC ใบเดียวในโฟลเดอร์ที่ฮีล** — `e->RestoreHP(e, HealSrc(HealSrcType::ATK, 6.0 + superimpose*2.0))` ใช้ overload `RestoreHP(target, HealSrc)` โดยให้ผู้สวมฮีลตัวเอง

guard ตัวเองด้วย `e->isSameName(ptr)` แล้ว `return` ถูกต้อง
