# `src/Defination/Data/Lightcone/Harmony/Sunday_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Sunday_LC"` · base stats `SetAllyBaseStats(1164, 476, 529)`

**signature ของ Sunday** (ดู `../../Character/Harmony/Sunday.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1164, 476, 529)` | `Sunday_LC.h:5` |
| บัฟเพื่อนเป้าเดี่ยว → ผู้สวมได้ energy `5.5 + 0.5S` · เป้าได้ "Hymn" DMG `12.75 + 2.25S` ต่อชั้น (สูงสุด 3, นาน 3 เทิร์น) | `Buff_List` เฉพาะผู้สวม + `TraceType::Single` · `buffStackSingle(…, 1, 3, hymn, 3)` ชื่อผูกเจ้าของ (`:7`) | `:20-25` |
| ทุก 2 ครั้ง → SP +1 | นับ `stack["Hymn_cnt"]` ถึง 2 แล้วรีเซ็ต | `:26-30` |
| ถอน Hymn เมื่อหมดอายุ / เป้าตาย | ท้ายเทิร์นผู้ถือ `isBuffEnd` → `buffResetStack` · `AllyDeath_List` ถอนทั้งกอง | `:8-14` · `:16-18` |

ชื่อบัฟ prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " Hymn"`) เหมือน `Cerydra LC.md`

## จุดที่ควรระวัง

- **`AllyDeath_List` เรียก `buffResetStack` โดยไม่เช็คว่ามีบัฟไหม** — ไม่เป็นปัญหา: `buffResetStack` ลบ `value × stack ปัจจุบัน` ถ้าไม่เคยมี stack ก็ลบ 0 · ใช้ `isBuffGoneByDeath` ไม่ได้ด้วย เพราะ `buffStackSingle` ไม่ตั้ง `buffCheck`
- **`stack["Hymn_cnt"]` ไม่รีเซ็ตข้ามการต่อสู้** ถ้าไม่มีใครล้าง

> **แก้ 2026-09-26**: `After_turn_List` เดิม guard ด้วย `turn->num != ptr->currentCharNum` (เลขลำดับคิว ATV เทียบกับเลขช่องเป้าหมายของ Sunday — คนละระบบ) → ถอน stack ได้เฉพาะเป้าปัจจุบัน ถ้า Sunday เปลี่ยนเป้า stack บนตัวเดิมค้าง · ตอนนี้ใช้ `turn->canCastToAllyUnit()` แล้วเช็ค `isBuffEnd` กับทุกคน
