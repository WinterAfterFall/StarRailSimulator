# `src/Defination/Data/Relic/Dreamlit Actor.h`

`Relic.name` = `"Dreamlit Actor"` · ฟังก์ชัน `Relic::DreamlitActor` · **เซ็ตสาย Elation (ซัพพอร์ต)** · kit: `docs/kit-reference/Relic.md` (nanoka 4.5.54 set 133)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | `atvStats->speedPercent += 6` ใน `resetList` | `Dreamlit Actor.h:12` |
| 4-pc — ใช้ Skill / Ult ใส่เพื่อน **อีกคน** 1 คน → เพื่อนคนนั้น Elation +16% นาน 3 เทิร์น | `buffList` + `isSameAction(ptr, SKILL / ULT)` + `buffTargetList` มี 1 ตัวและไม่ใช่ผู้สวม → `buffSingle(target, …, elationName, 3)` | `:15-20` |
| 4-pc — ถ้าผู้สวมมี Certified Banger ≥ 10 → เพื่อนทุกคน CD +12% นาน 3 เทิร์น | เช็ค `CERTIFIED_BANGER[NONE] >= 10` ตอนเดียวกัน → `buffAllAlly(…, critName, 3)` | `:21-23` |
| บัฟหมดอายุ | `afterTurnList` เทิร์นของเพื่อนแต่ละคน `isBuffEnd` → ลบค่าคืน | `:26-31` |

## จุดที่ควรระวัง

- ใช้ `buffList` จึงติดเฉพาะ Skill / Ult ที่เป็น **buff action** เป้าหมายเดียว · ท่าที่ใส่ทุกคน (เช่น Skill ของ Pearl `addBuffAllAllies`) ไม่ติด ตรงกับ kit "on one other ally target"
- เป้าหมายเป็น memosprite ก็ติด (kit เขียน "ally target" ไม่ได้จำกัดว่าเป็นตัวละคร — ต่างจาก Elation Brimming With Blessings ที่เขียน "ally character")
- **บัฟซ้อนไม่ได้** (user สั่ง 2026-09-29): ชื่อบัฟร่วมกันทุกผู้สวม `"Dreamlit Actor Elation"` / `"Dreamlit Actor CD"` **ไม่ใส่ชื่อเจ้าของนำหน้า** (ข้อยกเว้นของกฎ prefix) → ใส่เซ็ตนี้ 2 คน ได้บัฟก้อนเดียว คนที่สองแค่ต่ออายุ · ใช้ซ้ำตอนบัฟยังอยู่ก็ต่ออายุอย่างเดียว
- ผู้สวมแต่ละคนมี trigger ถอนของตัวเอง แต่ถอนได้ครั้งเดียว: `isBuffEnd` ตัวแรกล้าง `buffEnd` เป็น 0 และ `turnCnt` ≥ 1 เสมอตอนท้ายเทิร์น (`Combat.h:11`) ตัวที่สองจึงไม่เข้าเงื่อนไข
- CD ของทีมนับอายุแยกตามเทิร์นของเพื่อนแต่ละคน
