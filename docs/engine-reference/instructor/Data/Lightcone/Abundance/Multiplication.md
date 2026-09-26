# `src/Defination/Data/Lightcone/Abundance/Multiplication.h`

`namespace Abundance_Lightcone` · `Light_cone.Name` = `"Multiplication"` · base stats `SetAllyBaseStats(953, 318, 198)`

**ใบเดียวของโฟลเดอร์** · 3★ base stats ต่ำ

| ท่อน | โค้ด |
|---|---|
| ผู้สวมใช้ BA → action ถัดไป advance `10 + 2S` | `AfterAllyActionList` → `act->isSameAction(ptr, AType::BA)` → `Action_forward(ptr->Atv_stats.get(), ...)` |

**ไม่มีสแตตติดตัว**

## รากฐาน: advance ต้องเกิดหลัง turn reset

ลำดับใน `Function/Combat/Combat.h`: `allEventBeforeAllyAction` (`BeforeAllyActionList`) → `AllyAction()` → `Attack()` ซึ่งจบด้วย `if(act->Turn_reset) resetTurn(turn)` (บรรทัด 218; BA ตั้ง `Turn_reset = true` ใน `Class/ActionData/AllyAttackAction.h:83`) → `allEventAfterAllyAction` (`AfterAllyActionList`)

**advance ที่สั่งก่อน `resetTurn` จะถูกลบทิ้ง** · kit: "their **next** action will be Advanced Forward" จึงต้องสั่งใน `AfterAllyActionList` (event ที่แยก Before/After เมื่อ 2026-09-26 — ดู `../../../Function/Event/Event.md`)

> **แก้ 2026-09-26**: เดิมอยู่ใน `BeforeAllyActionList` + `Action_forward(turn, ...)` → advance ถูก `resetTurn` ลบทุกครั้ง **ใบนี้ไม่เคยมีผล** และ `turn` อาจเป็นคนอื่นถ้าโจมตีนอกเทิร์นตัวเอง · ตอนนี้ advance ตัวผู้สวมตรง ๆ หลัง `AllyAction()` จบ (รอบแรกใช้ `AfterAttackActionList` แล้ว user สั่งย้ายมา `AfterAllyActionList`) · guard เปลี่ยนจาก `isSameOwnerAction` (รวม memosprite) เป็น `isSameAction(ptr, AType::BA)` ตาม kit "the wearer uses their Basic ATK"
