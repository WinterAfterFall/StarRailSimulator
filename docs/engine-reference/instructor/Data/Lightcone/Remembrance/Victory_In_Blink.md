# `src/Defination/Data/Lightcone/Remembrance/Victory_In_Blink.h`

`namespace Remembrance_Lightcone` · `lightCone.name` = `"Victory_In_Blink"` · base stats `setAllyBaseStats(847, 476, 397)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(847, 476, 397)` | `Victory_In_Blink.h:5` |
| CD `9 + 3S` | บวกถาวร | `:10` |
| memosprite ของผู้สวมใช้ท่าบัฟ → ทั้งทีม DMG `6 + 2S` นาน 3 เทิร์น | `buffList` เช็คผู้กระทำเป็น memosprite ของผู้สวม → `buffAllAlly(…, victoryBlink, 3)` ชื่อผูกเจ้าของ (`:7`) | `:13-18` |
| ถอนเมื่อหมดอายุ / ตาย | ท้ายเทิร์นผู้ถือ `isBuffEnd` · `allyDeathList` + `isBuffGoneByDeath` | `:20-26` · `:28-32` |

ชื่อบัฟ prefix ด้วยชื่อเจ้าของ

## จุดที่ทำถูก

**guard memosprite ด้วยการเทียบชื่อเจ้าของ** — `act->attacker->owner->atvStats->name == ptr->atvStats->name` · ปลอดภัยกว่าการเทียบเลขช่องที่ `Aglaea_LC.h` / `Castorice_LC.h` / `Hyacnine_LC.h` ใช้

**ถอนครบทั้ง 2 ทาง** — `isBuffEnd` และ `isBuffGoneByDeath`

> **แก้ 2026-09-26**: เดิมถอนด้วยการเขียน `statsType[DMG] -= ...` ตรง ๆ → เปลี่ยนเป็น `buffSingle` ค่าติดลบให้คู่กับตอนลง · `dynamic_cast` → `turn->canCastToAllyUnit()`
