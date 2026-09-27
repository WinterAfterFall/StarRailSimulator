# `src/Defination/Data/Lightcone/Abundance/Multiplication.h`

`namespace Abundance_Lightcone` · `lightCone.name` = `"Multiplication"` · base stats `setAllyBaseStats(953, 318, 198)`

**ใบเดียวของโฟลเดอร์** · 3★ base stats ต่ำ

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 318, 198)` | `Multiplication.h:5` |
| ผู้สวมใช้ Basic ATK → action ถัดไป advance `10 + 2S`% | `afterAllyActionList` (หลัง action จบ ไม่ถูก turn reset ลบทิ้ง) → `isSameAction(ptr, AType::BA)` → `actionForward` | `:8-12` (advance `:10`) |

**ไม่มีสแตตติดตัว**

## รากฐาน: advance ต้องเกิดหลัง turn reset

ลำดับใน `Function/Combat/Combat.h`: `allEventBeforeAllyAction` (`beforeAllyActionList`) → `allyAction()` → `attack()` ซึ่งจบด้วย `if(act->turnReset) resetTurn(turn)` (บรรทัด 218; BA ตั้ง `turnReset = true` ใน `Class/ActionData/AllyAttackAction.h:83`) → `allEventAfterAllyAction` (`afterAllyActionList`)

**advance ที่สั่งก่อน `resetTurn` จะถูกลบทิ้ง** · kit: "their **next** action will be Advanced Forward" จึงต้องสั่งใน `afterAllyActionList` (event ที่แยก Before/After เมื่อ 2026-09-26 — ดู `../../../Function/Event/Event.md`)

> **แก้ 2026-09-26**: เดิมอยู่ใน `beforeAllyActionList` + `actionForward(turn, ...)` → advance ถูก `resetTurn` ลบทุกครั้ง **ใบนี้ไม่เคยมีผล** และ `turn` อาจเป็นคนอื่นถ้าโจมตีนอกเทิร์นตัวเอง · ตอนนี้ advance ตัวผู้สวมตรง ๆ หลัง `allyAction()` จบ (รอบแรกใช้ `afterAttackActionList` แล้ว user สั่งย้ายมา `afterAllyActionList`) · guard เปลี่ยนจาก `isSameOwnerAction` (รวม memosprite) เป็น `isSameAction(ptr, AType::BA)` ตาม kit "the wearer uses their Basic ATK"
