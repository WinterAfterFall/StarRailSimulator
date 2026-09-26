# `src/Defination/Data/Lightcone/Harmony/Sunday_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Sunday_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ Sunday** (ดู `../../Character/Harmony/Sunday.md`)

| ท่อน | โค้ด |
|---|---|
| Skill เป้าเดียว → energy `5.5 + 0.5S` | `Buff_List` |
| Skill เป้าเดียว → เป้าได้ DMG `12.75 + 2.25S` stack (cap 3, 3 เทิร์น) | `buffStackSingle(each, ..., 1, 3, hymn, 3)` |
| ทุก 2 ครั้งที่ใช้ Skill → คืน SP 1 | `ptr->stack["Hymn_cnt"]` |
| ถอน | `After_turn_List` + `AllyDeath_List` → `buffResetStack` |

ชื่อบัฟ prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " Hymn"`) เหมือน `Cerydra LC.md`

## จุดที่ควรระวัง

- **`AllyDeath_List` เรียก `buffResetStack` โดยไม่เช็คว่ามีบัฟไหม** — ไม่เป็นปัญหา: `buffResetStack` ลบ `value × stack ปัจจุบัน` ถ้าไม่เคยมี stack ก็ลบ 0 · ใช้ `isBuffGoneByDeath` ไม่ได้ด้วย เพราะ `buffStackSingle` ไม่ตั้ง `buffCheck`
- **`stack["Hymn_cnt"]` ไม่รีเซ็ตข้ามการต่อสู้** ถ้าไม่มีใครล้าง

> **แก้ 2026-09-26**: `After_turn_List` เดิม guard ด้วย `turn->num != ptr->currentCharNum` (เลขลำดับคิว ATV เทียบกับเลขช่องเป้าหมายของ Sunday — คนละระบบ) → ถอน stack ได้เฉพาะเป้าปัจจุบัน ถ้า Sunday เปลี่ยนเป้า stack บนตัวเดิมค้าง · ตอนนี้ใช้ `turn->canCastToAllyUnit()` แล้วเช็ค `isBuffEnd` กับทุกคน
