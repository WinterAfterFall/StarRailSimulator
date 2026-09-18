# `src/Defination/Class/Trigger/Trigger_Function.h`

## `TriggerFunc::priority`

User ยืนยัน 2026-09-18: ใช้กำหนดลำดับเอฟเฟกต์ที่เกิดในจังหวะเดียวกัน โดยค่ามากทำงานก่อนภายในลิสต์ event เดียวกัน

จากโค้ด: `Trigger_cmp` คืน `l.priority > r.priority` และถูกใช้เรียงลิสต์ trigger ใน `SetCombat.h` เช่น priority 100 มาก่อน 50

## `TriggerByYourSelf_Func::Call`

User ยืนยัน 2026-09-18: callback แบบ `function<void()>` ไม่รับพารามิเตอร์ตอนเรียก `e.Call()` ใช้ lambda จับข้อมูลที่ต้องการไว้ตอนสร้าง เช่น `[ptr]` เพื่อจำตัวละคร จึงไม่ต้องส่งตัวละครนั้นเข้าไปอีกตอนเรียก

## `TriggerByAlly_Func::Call`

User ยืนยัน 2026-09-18: รับ `CharUnit*` เพื่อให้ callback รู้ว่าเหตุการณ์ครั้งนี้เกี่ยวกับตัวละครไหน ตัวอย่าง `WhenUseUlt_List` เรียก `e.Call(ptr)` โดยส่งตัวละครที่เพิ่งใช้อัลติ

## `TriggerByAction_Func::Call`

User ยืนยัน 2026-09-18: รับ `shared_ptr<ActionData>&` เพื่อให้เอฟเฟกต์ตรวจและตอบสนองตามแอ็กชันที่เกิดขึ้นครั้งนั้น เช่น `BeforeAction_List` ส่งแอ็กชันที่กำลังจะทำให้ callback ตรวจชื่อหรือแปลงเป็นชนิดแอ็กชันที่เฉพาะขึ้น

## Trigger ตามชนิดแอ็กชันฝ่ายเรา

User ยืนยัน 2026-09-18: แยกชนิด trigger เพื่อให้แต่ละ event เข้าถึงข้อมูลที่เกี่ยวข้องโดยตรง

- `TriggerByAllyAction_Func` รับแอ็กชันฝ่ายเราทั้งโจมตีและบัฟ
- `TriggerByAllyAttackAction_Func` รับเฉพาะแอ็กชันโจมตี จึงเข้าถึง `damageSplit`, เป้าหมาย และประเภทดาเมจได้
- `TriggerByAllyBuffAction_Func` รับเฉพาะแอ็กชันบัฟ จึงเข้าถึง `buffTargetList` ได้

## `TriggerByStats`

User ยืนยัน 2026-09-18: รับทั้งยูนิตที่มีค่าสถานะเปลี่ยนและชนิด `Stats` ที่เปลี่ยน เพื่ออัปเดตเอฟเฟกต์ซึ่งคำนวณต่อจากค่าสถานะนั้น โดยไม่ต้องคำนวณใหม่เมื่อ stats ชนิดอื่นเปลี่ยน ตัวอย่าง FireFly คำนวณ Break Effect ใหม่เฉพาะเมื่อ ATK% หรือ Flat ATK เปลี่ยน

จากโค้ด: `allEventAdjustStats(ptr, statsType)` ตั้ง `AdjustCheck = 1` ระหว่างวน `Stats_Adjust_List` แล้วคืนเป็น 0 เมื่อจบ

## `TriggerAllyDeath`

User ยืนยัน 2026-09-18: รับ `AllyUnit*` ที่เพิ่งตาย เพื่อรองรับทั้งเอฟเฟกต์ตอบสนองต่อการตายและการทำความสะอาดสถานะที่ผูกกับยูนิตนั้น ตัวอย่าง Huohuo ตรวจและถอนบัฟที่ต้องหายเมื่อตายออกจากเป้าหมายโดยตรง

## `TriggerBySomeAlly_Func`

User ยืนยัน 2026-09-18: เป็น callback กลางสำหรับเหตุการณ์ที่มีความสัมพันธ์ระหว่างศัตรูหนึ่งตัวกับยูนิตฝ่ายเราหนึ่งตัว โดย `Enemy* target` คือศัตรูที่ได้รับเหตุการณ์ ส่วนความหมายของ `AllyUnit* Trigger` ขึ้นกับ event เช่น ผู้ทำ Weakness Break, ผู้ลง debuff หรือผู้สังหาร

## `TriggerByWeaknessApply_Func`

User ยืนยัน 2026-09-18: รับข้อมูลครบสามส่วน ได้แก่ `AllyUnit* Trigger` ผู้เพิ่ม Weakness, `Enemy* target` ศัตรูที่ได้รับ Weakness และ `vector<ElementType> elementList` รายการธาตุที่ถูกเพิ่ม ตัวอย่าง Dahlia ตรวจธาตุของผู้เพิ่ม Weakness ส่วน `elementList` รองรับเอฟเฟกต์ที่ต้องตรวจธาตุซึ่งถูกเพิ่มโดยตรง

## `TriggerHealing`

User ยืนยัน 2026-09-18: รับผู้ฮีล เป้าหมาย และ `Value` ซึ่งหมายถึงค่าฮีลที่กระทำก่อนหัก overheal

จากโค้ด: `IncreaseHP()` ตรวจว่าค่าไม่เป็น 0 และเป้าหมายยังอยู่ จากนั้นเพิ่ม HP โดย clamp ที่ `totalHP` แล้วเรียก `allEventHeal(Healer, target, Value)` ด้วยค่าเดิม ดังนั้น `Value` อาจมากกว่า HP ที่เป้าหมายได้รับจริง

## `TriggerDecreaseHP`

User ยืนยัน 2026-09-18: รับต้นเหตุ เป้าหมาย และจำนวน HP ที่ลดจริงหลัง clamp ขั้นต่ำไว้ที่ 1 เช่น HP 100 ถูกสั่งลด 500 จะส่ง `Value = 99`

แก้โค้ดให้ `DecreaseCurrentHP()` คืนผลต่างระหว่าง HP ก่อนและหลังลด แล้วใช้ค่านี้กับ `allEventChangeHP()` ใน `DecreaseHP` ทุก overload และการโจมตีของศัตรูใน `EnemyActionData`

## `TriggerByEnemyHit`

User ยืนยัน 2026-09-18: ใช้กับเอฟเฟกต์เมื่อถูกโจมตีหรือโดนตี ซึ่งไม่ต้องรอจำนวน HP ที่ลดจริง โดยรับศัตรูผู้โจมตีกับรายชื่อยูนิตที่โดนการโจมตีครั้งนั้น ส่วนเอฟเฟกต์ที่ต้องรู้ HP ที่เสียจริงใช้ `TriggerDecreaseHP`

จากโค้ด: AoE ส่งทุกเป้าหมายที่โจมตีได้ ส่วนการโจมตีปกติส่งเฉพาะยูนิตที่ `AttackCoolDown` สะสมถึง 100 และโดนตีจริง โดยเรียก event ก่อนคำนวณดาเมจและลด HP

## `TriggerDot_Func`

User ยืนยัน 2026-09-18:

- `Enemy* target` คือศัตรูที่ DoT กำลังทำงาน
- `double Dot_ratio` คือตัวคูณการ trigger DoT เช่น 100 ทำเต็มค่า
- `DotType Dot_type` จำกัดชนิด DoT ที่ทำงาน โดย `General` เปิดทุกชนิดที่เข้าเงื่อนไข

ตัวอย่าง Kafka ตรวจว่าเป้ามี Kafka Shock และชนิดเป็น `General` หรือ `Shock` แล้วคูณดาเมจด้วย `Dot_ratio`

## `TriggerEnergy_Increase_Func`

User ยืนยัน 2026-09-18: trigger ทำงานก่อนเขียนค่าใหม่ลง `Current_energy` เพื่อให้ callback เห็นค่าก่อนหน้าและคำนวณพลังงานที่จะล้นเพดานได้

รับตัวละครเป้าหมายกับจำนวนพลังงานที่จะเพิ่ม สำหรับ overload ที่เป็นพลังงานจากการกระทำ ค่าที่ส่งผ่าน event คูณ ERR แล้ว ตัวอย่าง Saber ใช้ `Current_energy + Energy - Max_energy` คำนวณพลังงานส่วนเกินก่อนระบบ clamp

## `TriggerSkill_point_func`

User ยืนยัน 2026-09-18: ใช้รูปแบบเดียวกันสำหรับ `Skill_point_List` และ `PunchLine_List` โดยรับยูนิตผู้ก่อเหตุและจำนวนการเปลี่ยนแปลง ค่าบวกคือเพิ่ม ค่าลบคือใช้หรือลด และผู้ก่อเหตุอาจเป็น `nullptr` ใน `genPunchLine(nullptr, ...)`

event ทำงานก่อนเปลี่ยนค่ารวม `sp` หรือ `punchline` callback จึงเห็นค่ารวมเดิมพร้อมจำนวนที่กำลังจะเปลี่ยน

## `TriggerAfterDealDamage`

User ยืนยัน 2026-09-18:

- `act` คือแอ็กชันที่สร้างดาเมจ
- `target` คือศัตรูเป้าหมายที่รับดาเมจ
- `damage` คือดาเมจหลังผ่านตัวคูณทั้งหมดของการคำนวณหนึ่งรายการต่อหนึ่งเป้าหมาย ไม่ใช่ผลรวมทั้งแอ็กชัน

Tribbie และ Cipher ใช้ดาเมจของเป้าหมายนั้นสร้าง True Damage ต่อ เปลี่ยนชื่อพารามิเตอร์เดิม `src` เป็น `target` ใน trigger, event dispatcher และ callback ทุกจุดเพื่อให้ความหมายชัดเจน
