# `src/Defination/Function/Calculate/CalDamage.h`

## `calDamage(act, target, abilityRatio)`

เริ่มจาก `abilityRatio.constDmg` แล้วบวกดาเมจที่สเกลจาก ATK, HP และ DEF ของ `act->source` ตาม ratio ใน `DmgSrc` จากนั้นคูณตัวคูณตามลำดับนี้:

```text
Crit
→ DMG%
→ DEF shred
→ RES PEN
→ Vulnerability
→ Mitigation
→ Multiplier increase
→ Toughness multiplier
```

User ยืนยัน 2026-09-20 ว่า `constDmg` เป็นดาเมจฐานค่าคงที่ของแอ็กชัน แต่ยังอยู่ในผลรวมก่อน multiplier จึงรับตัวคูณชุดเดียวกับดาเมจจาก ATK/HP/DEF ไม่ใช่ true/fixed damage ที่ข้าม multiplier

หลังคำนวณจะบันทึกผ่าน `Cal_DamageNote()` และส่ง `allEventAfterDealingDamage()`

ลำดับที่แสดงข้างต้นเป็นลำดับการเรียกในโค้ดเพื่ออ่าน flow ได้ง่าย แต่ multiplier เหล่านี้คูณต่อกันทั้งหมด จึงสลับลำดับกันได้ตามสมบัติการคูณสลับที่โดยไม่เปลี่ยนผลลัพธ์ (ตราบใดที่แต่ละฟังก์ชันยังคำนวณจาก state เดิม)

## `calElationDamage(act, target, abilityRatio)`

`Attack()` เรียกต่อจาก `calDamage()` สำหรับแต่ละรายการใน `damageSplit` ถ้า `abilityRatio.Elation <= 0` จะกลับทันทีโดยไม่บันทึกดาเมจ ฐานดาเมจเมื่อมีค่า Elation คือ `Level_multiplier × 2 × abilityRatio.Elation / 100` แล้วคูณ `calElationMultiplier` → Punchline/Certified Banger → Merrymake → Crit → DEF shred → RES PEN → Vulnerability → Mitigation → Multiplier increase → Toughness multiplier ตามลำดับ ไม่ใช้สเกล ATK/HP/DEF หรือ DMG% ของ `calDamage()`

ผลที่ได้ลง `Cal_DamageNote()` ในชื่อ `act->actionName` แล้วเรียก `allEventAfterDealingDamage()` อีกครั้งสำหรับดาเมจส่วน Elation ดังนั้นหนึ่งรายการโจมตีที่มีทั้งดาเมจปกติและ Elation จะมีการบันทึกและ event หลังสร้างดาเมจแยกสองครั้ง ดูสูตรตัวคูณ Elation, Punchline และ Merrymake ใน [CalStats.md](CalStats.md)

## `Cal_Break_damage(act, target, Constant)`

เริ่มจาก `Constant × Level_multiplier` เรียก `allEventBeforeAttack(act)` แล้วคูณ `(0.5 + target->Max_toughness / 40)` × Break Effect × DEF shred × RES PEN × Vulnerability × Mitigation × Multiplier increase × Toughness multiplier ไม่ใช้ Crit หรือ DMG% หลังคำนวณจะบันทึกผ่าน `Cal_DamageNote()` ยิง `allEventAfterDealingDamage()` แล้ว `allEventAfterAttack(act)` ตามลำดับ ส่วน event ก่อนโจมตีและหลังโจมตีของฟังก์ชันนี้แยกจากลูปโจมตีปกติใน `Attack()`

## `Cal_Total_Toughness_Reduce()`

รวม `TOUGH_REDUCE` และ `BREAK_EFF` จาก `Attacker` กับ `target` ใน `AType::None` และใน `act->actionTypeList` แล้วนำไปคูณกับ `Base_Toughness_reduce`:

```text
base toughness reduction
× (100 + TOUGH_REDUCE) / 100
× (100 + BREAK_EFF) / 100
```

User ยืนยัน 2026-09-20 ว่าการคำนวณสองค่านี้อิง `actionTypeList` โดยตรง เพราะเป็นคุณสมบัติของ action แม้ `damageTypeList` ของดาเมจที่เกิดขึ้นจะต่างกัน

หมายเหตุเรื่องค่าติดลบ: จุดที่เห็น `BREAK_EFF = -50` ในชุดตัวละครเป็นการถอนบัฟ `+50` ที่เคยใส่ไว้ ไม่ได้หมายถึงระบบมี debuff Break Efficiency ติดลบเป็นความหมายถาวร

## `Cal_Toughness_reduction()` และ `Dont_care_weakness`

ถ้าเป้าไม่มี Weakness ของธาตุโจมตีและ `Dont_care_weakness == 0` จะไม่ลด Toughness ตราบใดที่ Toughness ยังมากกว่า 0

ถ้า action ตั้ง `Dont_care_weakness` เป็นเปอร์เซ็นต์ จะลด Toughness ได้ตามสัดส่วนนั้นแม้ไม่ตรง Weakness เช่น `50` = ลดได้ 50% ของ Toughness reduction ปกติ หากการคำนวณทำให้ค่า Toughness ติดลบ โค้ดจะคูณส่วนที่ติดลบกลับด้วย `100 / Dont_care_weakness` เพื่อให้การทะลุศูนย์ยังสะท้อนสัดส่วนที่อนุญาต (User ยืนยัน 2026-09-20)

## `Cal_Freeze_damage()`

ใช้ `Level_multiplier` เป็นฐาน แล้วคูณ Break Effect, DEF shred, RES PEN, Vulnerability, Mitigation, Multiplier increase และ Toughness multiplier ตามลำดับในโค้ด โดยไม่ผ่าน Crit หรือ DMG% User ยืนยัน 2026-09-20 ว่าเป็นชุด multiplier ตามสูตรเกม

## `Cal_Dot_Toughness_break_damage()`

ใช้ `Level_multiplier × Dot_ratio / 100` เป็นฐาน แล้วใช้ชุด multiplier เดียวกับ Freeze damage ได้แก่ Break Effect, DEF shred, RES PEN, Vulnerability, Mitigation, Multiplier increase และ Toughness multiplier โดยไม่ผ่าน Crit หรือ DMG% (User ยืนยัน 2026-09-20)

## `Cal_Superbreak_damage()`

ใช้ `Level_multiplier × Superbreak_ratio / 100` เป็นฐาน แล้วคูณ Break Effect, `SPB_inc`, DEF shred, RES PEN, Vulnerability, Multiplier increase และ Mitigation โดยไม่ผ่าน Crit, DMG% หรือ Toughness multiplier User ยืนยัน 2026-09-20 ว่าเป็นชุด multiplier ตามสูตรเกม
