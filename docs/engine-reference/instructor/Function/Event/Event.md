# `src/Defination/Function/Event/Event.h`

ไฟล์นี้เป็น dispatcher ของ trigger lists: ฟังก์ชัน `allEvent*` ส่วนใหญ่เพียงวนลิสต์ที่ตรงกับเหตุการณ์แล้วเรียก `Call()` พร้อมข้อมูลที่ trigger ต้องใช้ ชนิด callback และความหมายพารามิเตอร์บันทึกไว้ใน [Trigger_Function.md](../../Class/Trigger/Trigger_Function.md)

`allEventBeforeTurn()` ตั้ง `phaseStatus = BeforeTurn`; ถ้าเป็นเทิร์นศัตรูจะ trigger DoT, ทำดาเมจ Entanglement และจัดการ Freeze ก่อนวน `Before_turn_List`

`allEventAfterTurn()` จัดการหมดอายุของ Break DoT/Entanglement/Imprisonment และ weakness ที่เพิ่มชั่วคราวในเทิร์นศัตรู จากนั้นวน `After_turn_List`; ถ้าเป็นเทิร์นฝ่ายเรา ยังจัดการรายการ `CBcheck` หลัง event ด้วย

`allEventWhenAttack()` เพิ่มสแต็ก Entanglement ของศัตรูใน `targetList` (สูงสุด 5) ก่อนวน `When_attack_List`; `allEventAdjustStats()` เปิด `AdjustCheck` ระหว่าง dispatch แล้วปิดเมื่อจบ

## Before / After ของ ally action

ใน 3 ลูปของ `Function/Combat/Combat.h` (Aha Instant, `Deal_damage`, คิวแอ็กชัน) แอ็กชันฝ่ายเราถูกครอบแบบนี้:

```cpp
allEventBeforeAllyAction(allyActionData);   // BeforeAllyActionList
allyActionData->AllyAction();               // Attack()/buff + resetTurn ถ้า Turn_reset
allEventAfterAllyAction(allyActionData);    // AfterAllyActionList
```

- **`BeforeAllyActionList`** — เดิมชื่อ `AllyActionList` / `allEventWhenAllyAction` · user สั่งเปลี่ยนชื่อ 2026-09-26 ผู้ใช้เดิมทั้งหมดย้ายมาเป็น Before (พฤติกรรมเท่าเดิม)
- **`AfterAllyActionList`** — เพิ่ม 2026-09-26 · ยิงหลัง `AllyAction()` จบ คือหลัง `resetTurn` แล้ว · ใช้กับเอฟเฟกต์ประเภท "หลังใช้ X → advance action ถัดไป" ที่ถ้าสั่งก่อนจะถูก reset ลบ (ดู `../../Data/Lightcone/Abundance/Multiplication.md`)

## Break DoT หมดอายุ

แก้ 2026-09-21: ก่อน `erase()` เก็บ `type` ของ Break DoT ที่หมดอายุไว้ใน `expiredType` แล้วใช้ค่านี้เลือกตัวนับ Burn/Shock/Wind Shear/Bleed ที่จะลด เพราะ iterator ที่ `erase()` คืนมาชี้รายการถัดไปหรือ `end()` ไม่ใช่รายการที่เพิ่งลบ มี regression test สำหรับ DoT หมดอายุขณะอีกชนิดยังอยู่ และกรณีลบรายการสุดท้าย (BUGS #21)
