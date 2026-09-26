# `src/Defination/Data/Lightcone/Remembrance/Victory_In_Blink.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Victory_In_Blink"` · base stats `SetAllyBaseStats(847, 476, 397)`

| ท่อน | โค้ด |
|---|---|
| CD `9 + 3S` | `Reset_List` |
| memosprite ของผู้สวมใช้ buff action → ทีม DMG `6 + 2S` 3 เทิร์น | `Buff_List` |
| ถอน | `After_turn_List` + `AllyDeath_List` |

ชื่อบัฟ prefix ด้วยชื่อเจ้าของ

## จุดที่ทำถูก

**guard memosprite ด้วยการเทียบชื่อเจ้าของ** — `act->Attacker->owner->Atv_stats->Name == ptr->Atv_stats->Name` · ปลอดภัยกว่าการเทียบเลขช่องที่ `Aglaea_LC.h` / `Castorice_LC.h` / `Hyacnine_LC.h` ใช้

**ถอนครบทั้ง 2 ทาง** — `isBuffEnd` และ `isBuffGoneByDeath`

> **แก้ 2026-09-26**: เดิมถอนด้วยการเขียน `Stats_type[DMG] -= ...` ตรง ๆ → เปลี่ยนเป็น `buffSingle` ค่าติดลบให้คู่กับตอนลง · `dynamic_cast` → `turn->canCastToAllyUnit()`
