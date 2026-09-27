# `src/Defination/Class/Trigger/Trigger_Function.h`

## `TriggerFunc::owner`

แก้ 2026-09-27 (user สั่ง): ย้าย `owner` (`CharUnit*`) จาก `TriggerByYourSelfFunc` ขึ้นมาที่ `TriggerFunc` คลาสแม่ · constructor `TriggerFunc(priority)` เดิมยังอยู่ (owner = `nullptr`) ให้ trigger ชนิดอื่นใช้ต่อได้ · ตอนนี้มีแค่ `TriggerByYourSelfFunc` ที่ **บังคับ** ใส่ owner · ใช้เลือก trigger ของคนใดคนหนึ่งได้ เช่น `ultUseCheck(e.owner)` ใน `Energy.h` หรือเรียก Elation Skill ของคนที่ระบุจาก `elationSkillList`

## `TriggerFunc::priority`

User ยืนยัน 2026-09-18: ใช้กำหนดลำดับเอฟเฟกต์ที่เกิดในจังหวะเดียวกัน โดยค่ามากทำงานก่อนภายในลิสต์ event เดียวกัน

จากโค้ด: `triggerCmp` คืน `l.priority > r.priority` และถูกใช้เรียงลิสต์ trigger ใน `SetCombat.h` เช่น priority 100 มาก่อน 50

## `TriggerByYourSelf_Func::call`

**แก้ 2026-09-27** (user สั่ง): เปลี่ยนจาก `function<void()>` เป็น `function<void(CharUnit *ptr)>` · constructor เดียว `TriggerByYourSelfFunc(priority, ptr, [..](CharUnit *ptr){...})` **บังคับใส่ owner** · engine เรียก `e.call(e.owner)` ทุกลิสต์ (`setupList`, `resetList`, `whenOnFieldList`, `tuneStatsList`, `startGameList`, `startWaveList`, `beforeTurnList`, `afterTurnList`, `ultimateList`, `elationSkillList`, `beforeAhaInstantList`, `afterAhaInstantList`) · lambda **ไม่ต้องจับ `[ptr]`** แล้ว ใช้ `ptr` จาก parameter · capture อื่น (`superimpose`, ชื่อบัฟ, lambda ช่วย) ยังจับตามเดิม

```cpp
resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
    ptr->statsType[Stats::CD][AType::NONE] += 40 + superimpose * 8;
}));
```

เดิม (2026-09-18): callback ไม่รับพารามิเตอร์ ใช้ lambda จับ `[ptr]` ไว้ตอนสร้าง และ owner ใส่หรือไม่ใส่ก็ได้ (มีแค่ `ultimateList` ที่ใส่)

## `TriggerByAlly_Func::call`

User ยืนยัน 2026-09-18: รับ `CharUnit*` เพื่อให้ callback รู้ว่าเหตุการณ์ครั้งนี้เกี่ยวกับตัวละครไหน ตัวอย่าง `whenUseUltList` เรียก `e.call(ptr)` โดยส่งตัวละครที่เพิ่งใช้อัลติ

## `TriggerByAction_Func::call`

User ยืนยัน 2026-09-18: รับ `shared_ptr<ActionData>&` เพื่อให้เอฟเฟกต์ตรวจและตอบสนองตามแอ็กชันที่เกิดขึ้นครั้งนั้น เช่น `beforeActionList` ส่งแอ็กชันที่กำลังจะทำให้ callback ตรวจชื่อหรือแปลงเป็นชนิดแอ็กชันที่เฉพาะขึ้น

## Trigger ตามชนิดแอ็กชันฝ่ายเรา

User ยืนยัน 2026-09-18: แยกชนิด trigger เพื่อให้แต่ละ event เข้าถึงข้อมูลที่เกี่ยวข้องโดยตรง

- `TriggerByAllyActionFunc` รับแอ็กชันฝ่ายเราทั้งโจมตีและบัฟ
- `TriggerByAllyAttackActionFunc` รับเฉพาะแอ็กชันโจมตี จึงเข้าถึง `damageSplit`, เป้าหมาย และประเภทดาเมจได้
- `TriggerByAllyBuffActionFunc` รับเฉพาะแอ็กชันบัฟ จึงเข้าถึง `buffTargetList` ได้

## `TriggerByStats`

User ยืนยัน 2026-09-18: รับทั้งยูนิตที่มีค่าสถานะเปลี่ยนและชนิด `Stats` ที่เปลี่ยน เพื่ออัปเดตเอฟเฟกต์ซึ่งคำนวณต่อจากค่าสถานะนั้น โดยไม่ต้องคำนวณใหม่เมื่อ stats ชนิดอื่นเปลี่ยน ตัวอย่าง FireFly คำนวณ Break Effect ใหม่เฉพาะเมื่อ ATK% หรือ Flat ATK เปลี่ยน

จากโค้ด: `allEventAdjustStats(ptr, statsType)` ตั้ง `adjustCheck = 1` ระหว่างวน `statsAdjustList` แล้วคืนเป็น 0 เมื่อจบ

## `TriggerAllyDeath`

User ยืนยัน 2026-09-18: รับ `AllyUnit*` ที่เพิ่งตาย เพื่อรองรับทั้งเอฟเฟกต์ตอบสนองต่อการตายและการทำความสะอาดสถานะที่ผูกกับยูนิตนั้น ตัวอย่าง Huohuo ตรวจและถอนบัฟที่ต้องหายเมื่อตายออกจากเป้าหมายโดยตรง

## `TriggerBySomeAllyFunc`

User ยืนยัน 2026-09-18: เป็น callback กลางสำหรับเหตุการณ์ที่มีความสัมพันธ์ระหว่างศัตรูหนึ่งตัวกับยูนิตฝ่ายเราหนึ่งตัว โดย `Enemy* target` คือศัตรูที่ได้รับเหตุการณ์ ส่วนความหมายของ `AllyUnit* trigger` ขึ้นกับ event เช่น ผู้ทำ Weakness Break, ผู้ลง debuff หรือผู้สังหาร

## `TriggerByWeaknessApplyFunc`

User ยืนยัน 2026-09-18: รับข้อมูลครบสามส่วน ได้แก่ `AllyUnit* trigger` ผู้เพิ่ม Weakness, `Enemy* target` ศัตรูที่ได้รับ Weakness และ `vector<ElementType> elementList` รายการธาตุที่ถูกเพิ่ม ตัวอย่าง Dahlia ตรวจธาตุของผู้เพิ่ม Weakness ส่วน `elementList` รองรับเอฟเฟกต์ที่ต้องตรวจธาตุซึ่งถูกเพิ่มโดยตรง

## `TriggerHealing`

User ยืนยัน 2026-09-18: รับผู้ฮีล เป้าหมาย และ `value` ซึ่งหมายถึงค่าฮีลที่กระทำก่อนหัก overheal

จากโค้ด: `increaseHP()` ตรวจว่าค่าไม่เป็น 0 และเป้าหมายยังอยู่ จากนั้นเพิ่ม HP โดย clamp ที่ `totalHP` แล้วเรียก `allEventHeal(healer, target, value)` ด้วยค่าเดิม ดังนั้น `value` อาจมากกว่า HP ที่เป้าหมายได้รับจริง

## `TriggerDecreaseHP`

User ยืนยัน 2026-09-18: รับต้นเหตุ เป้าหมาย และจำนวน HP ที่ลดจริงหลัง clamp ขั้นต่ำไว้ที่ 1 เช่น HP 100 ถูกสั่งลด 500 จะส่ง `value = 99`

แก้โค้ดให้ `decreaseCurrentHP()` คืนผลต่างระหว่าง HP ก่อนและหลังลด แล้วใช้ค่านี้กับ `allEventChangeHP()` ใน `decreaseHP` ทุก overload และการโจมตีของศัตรูใน `EnemyActionData`

## `TriggerByEnemyHit`

User ยืนยัน 2026-09-18: ใช้กับเอฟเฟกต์เมื่อถูกโจมตีหรือโดนตี ซึ่งไม่ต้องรอจำนวน HP ที่ลดจริง โดยรับศัตรูผู้โจมตีกับรายชื่อยูนิตที่โดนการโจมตีครั้งนั้น ส่วนเอฟเฟกต์ที่ต้องรู้ HP ที่เสียจริงใช้ `TriggerDecreaseHP`

จากโค้ด: AoE ส่งทุกเป้าหมายที่โจมตีได้ ส่วนการโจมตีปกติส่งเฉพาะยูนิตที่ `attackCoolDown` สะสมถึง 100 และโดนตีจริง โดยเรียก event ก่อนคำนวณดาเมจและลด HP

## `TriggerDotFunc`

User ยืนยัน 2026-09-18:

- `Enemy* target` คือศัตรูที่ DoT กำลังทำงาน
- `double dotRatio` คือตัวคูณการ trigger DoT เช่น 100 ทำเต็มค่า
- `DotType dotType` จำกัดชนิด DoT ที่ทำงาน โดย `GENERAL` เปิดทุกชนิดที่เข้าเงื่อนไข

ตัวอย่าง Kafka ตรวจว่าเป้ามี Kafka Shock และชนิดเป็น `GENERAL` หรือ `SHOCK` แล้วคูณดาเมจด้วย `dotRatio`

## `TriggerEnergyIncreaseFunc`

User ยืนยัน 2026-09-18: trigger ทำงานก่อนเขียนค่าใหม่ลง `currentEnergy` เพื่อให้ callback เห็นค่าก่อนหน้าและคำนวณพลังงานที่จะล้นเพดานได้

รับตัวละครเป้าหมายกับจำนวนพลังงานที่จะเพิ่ม สำหรับ overload ที่เป็นพลังงานจากการกระทำ ค่าที่ส่งผ่าน event คูณ ERR แล้ว ตัวอย่าง Saber ใช้ `currentEnergy + energy - maxEnergy` คำนวณพลังงานส่วนเกินก่อนระบบ clamp

## `TriggerSkillPointFunc`

User ยืนยัน 2026-09-18: ใช้รูปแบบเดียวกันสำหรับ `skillPointList` และ `punchLineList` โดยรับยูนิตผู้ก่อเหตุและจำนวนการเปลี่ยนแปลง ค่าบวกคือเพิ่ม ค่าลบคือใช้หรือลด และผู้ก่อเหตุอาจเป็น `nullptr` ใน `genPunchLine(nullptr, ...)`

event ทำงานก่อนเปลี่ยนค่ารวม `sp` หรือ `punchline` callback จึงเห็นค่ารวมเดิมพร้อมจำนวนที่กำลังจะเปลี่ยน

## `TriggerAfterDealDamage`

User ยืนยัน 2026-09-18:

- `act` คือแอ็กชันที่สร้างดาเมจ
- `target` คือศัตรูเป้าหมายที่รับดาเมจ
- `damage` คือดาเมจหลังผ่านตัวคูณทั้งหมดของการคำนวณหนึ่งรายการต่อหนึ่งเป้าหมาย ไม่ใช่ผลรวมทั้งแอ็กชัน

Tribbie และ Cipher ใช้ดาเมจของเป้าหมายนั้นสร้าง True Damage ต่อ เปลี่ยนชื่อพารามิเตอร์เดิม `src` เป็น `target` ใน trigger, event dispatcher และ callback ทุกจุดเพื่อให้ความหมายชัดเจน
