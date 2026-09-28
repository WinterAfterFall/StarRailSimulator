# `src/Defination/Function/Event/Event.h`

ไฟล์นี้เป็น dispatcher ของ trigger lists: ฟังก์ชัน `allEvent*` ส่วนใหญ่เพียงวนลิสต์ที่ตรงกับเหตุการณ์แล้วเรียก `call()` พร้อมข้อมูลที่ trigger ต้องใช้ ชนิด callback และความหมายพารามิเตอร์บันทึกไว้ใน [Trigger_Function.md](../../Class/Trigger/Trigger_Function.md)

`allEventBeforeTurn()` ตั้ง `phaseStatus = BEFORE_TURN`; ถ้าเป็นเทิร์นศัตรูจะ trigger DoT, ทำดาเมจ Entanglement และจัดการ Freeze ก่อนวน `beforeTurnList`

`allEventAfterTurn()` จัดการหมดอายุของ Break DoT/Entanglement/Imprisonment และ weakness ที่เพิ่มชั่วคราวในเทิร์นศัตรู จากนั้นวน `afterTurnList`; ถ้าเป็นเทิร์นฝ่ายเรา ยังจัดการรายการ `cbCheck` หลัง event ด้วย

`allEventWhenAttack()` เพิ่มสแต็ก Entanglement ของศัตรูใน `targetList` (สูงสุด 5) ก่อนวน `whenAttackList`; `allEventAdjustStats()` เปิด `adjustCheck` ระหว่าง dispatch แล้วปิดเมื่อจบ

## Before / After ของ ally action

ใน 3 ลูปของ `Function/Combat/Combat.h` (Aha Instant, `dealDamage`, คิวแอ็กชัน) แอ็กชันฝ่ายเราถูกครอบแบบนี้:

```cpp
allEventBeforeAllyAction(allyActionData);   // beforeAllyActionList
allyActionData->allyAction();               // attack()/buff + resetTurn ถ้า turnReset
allEventAfterAllyAction(allyActionData);    // afterAllyActionList
```

- **`beforeAllyActionList`** — เดิมชื่อ `AllyActionList` / `allEventWhenAllyAction` · user สั่งเปลี่ยนชื่อ 2026-09-26 ผู้ใช้เดิมทั้งหมดย้ายมาเป็น Before (พฤติกรรมเท่าเดิม)
- **`afterAllyActionList`** — เพิ่ม 2026-09-26 · ยิงหลัง `allyAction()` จบ คือหลัง `resetTurn` แล้ว · ใช้กับเอฟเฟกต์ประเภท "หลังใช้ X → advance action ถัดไป" ที่ถ้าสั่งก่อนจะถูก reset ลบ (ดู `../../Data/Lightcone/Abundance/Multiplication.md`)

## When use Elation Skill

`allEventWhenUseElationSkill(CharUnit *ptr)` วน `whenUseElationSkillList` (`TriggerByAllyFunc` · ประกาศ `Setting.h:109` · sort `Function/Setup/SetCombat.h:18`) โดยส่งตัวละครที่เพิ่งใช้ Elation Skill · เพิ่ม 2026-09-28 (user สั่ง) ในรูปแบบเดียวกับ `whenUseUltList`

- **ผู้เรียกมีที่เดียว** — `callElationSkill(e)` ใน `Function/Combat/AhaCombat.h:5-8` เรียก Elation Skill ของเจ้าของ แล้วยิง event นี้ต่อทันที · ทั้ง `ahaTurn` / `ahaInstant(PL)` / `elationSkillTrigger` ใช้ `callElationSkill`
- **ยิงแยกทุกตัวละคร** ต่างจาก `beforeAllyActionList` / `afterAllyActionList` ที่ใน Aha Instant ยิงครั้งเดียวด้วย action ตัวแรกเป็นตัวแทน → ใช้ event นี้เมื่อต้องการรู้ว่า "ตัวละคร X ใช้ Elation Skill" จริง ๆ
- **จังหวะ**: action ของ Elation Skill ถูกใส่ลงคิว `ahaInstantBar` แล้วแต่**ยังไม่ตี** (ตีตอน `runAhaInstantBar`) · callback อ่าน `ahaInstantBar.back()` เพื่อดูว่าตัวละครเพิ่งใส่ action อะไรได้ · บัฟ/ดีบัฟที่ลงตรงนี้มีผลกับดาเมจของ Aha Instant รอบเดียวกัน
- Elation Skill ที่ไม่สร้าง action (Pearl, SW999 Pro-Gamer Move) ก็ยิง event นี้เหมือนกัน
- ผู้ใช้ตอนนี้ (ทั้งหมดใน `Data/Lightcone/Elation/`): `Pearl_LC.h`, `Evanescia_LC.h`, `AventurineWaveflair_LC.h`, `Today's Good Luck.h`, `Mushy Shroomy's Adventures.h`

## Break DoT หมดอายุ

แก้ 2026-09-21: ก่อน `erase()` เก็บ `type` ของ Break DoT ที่หมดอายุไว้ใน `expiredType` แล้วใช้ค่านี้เลือกตัวนับ Burn/Shock/Wind Shear/Bleed ที่จะลด เพราะ iterator ที่ `erase()` คืนมาชี้รายการถัดไปหรือ `end()` ไม่ใช่รายการที่เพิ่งลบ มี regression test สำหรับ DoT หมดอายุขณะอีกชนิดยังอยู่ และกรณีลบรายการสุดท้าย (BUGS #21)
