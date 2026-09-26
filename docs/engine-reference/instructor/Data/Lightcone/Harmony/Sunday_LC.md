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

- **`AllyDeath_List` เรียก `buffResetStack` โดยไม่เช็ค `isBuffGoneByDeath` ก่อน** → ถอน stack กับทุกคนที่ตายแม้ไม่เคยมีบัฟ · อาการเดียวกับ E6 ใน `../../Character/Harmony/Sunday.md`
- **`After_turn_List` guard ด้วย `turn->num != ptr->currentCharNum`** แล้วใช้ `dynamic_cast` — ผูกกับเลขช่องซึ่งเปลี่ยนได้เมื่อมี memosprite
- **`stack["Hymn_cnt"]` ไม่รีเซ็ตข้ามการต่อสู้** ถ้าไม่มีใครล้าง
