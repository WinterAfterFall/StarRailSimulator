# `src/Defination/Class/ActionData/AllyAttackAction.h`

## Constructors

User ยืนยัน 2026-09-17: constructor เปล่า `AllyAttackAction(){}` เผื่อสร้างแอ็กชันแล้วค่อยกำหนดข้อมูลเองภายหลัง ไม่เตรียมข้อมูลเหมือน overload ที่รับพารามิเตอร์

จากโค้ด: overload ที่รับพารามิเตอร์ตั้ง `Attacker` และ `source` เป็นยูนิตที่ส่งมา ตั้งชื่อแอ็กชัน รูปแบบเป้าหมาย และธาตุจากผู้โจมตี เรียก `setupActionType()` แล้วเพิ่มผู้โจมตีคนแรกใน `AttackSetList`; overload อีกแบบรับ `actionFunction` เพิ่มด้วย

## `addToActionBar()`

User ยืนยัน 2026-09-17: เตรียมแอ็กชันให้ครบแล้วส่งเข้าคิวกลาง `Action_bar` เพื่อรอประมวลผล ยังไม่ออกท่าทันที

จากโค้ด: ตรวจ `Attacker->isExisted()` ก่อน หากไม่ผ่านจะไม่เข้าคิว จากนั้นรวบรวมเป้าหมายที่ไม่เป็น null จาก `damageSplit` เพิ่มใน `targetList` โดยไม่เพิ่มยูนิตที่มีอยู่แล้ว (ตรวจด้วย `Atv_stats->num`) แล้วใช้ `shared_from_this()` ส่งแอ็กชันเดิมเข้า `Action_bar`

`addEnemyToTargetList()` ทำขั้นรวบรวมเป้าหมายเดียวกันโดยไม่เข้าคิว และถูก `Attack()` เรียกเมื่อ `targetList` ยังว่าง ส่วน `addToAhaInstant()` รวบรวมเป้าหมายแบบเดียวกันแล้วส่งเข้า `AhaInstantBar` แทน `Action_bar`; ลำดับประมวลผล Aha บันทึกไว้ใน [Combat.md](../../Function/Combat/Combat.md)

## `AttackSetList` กับ `switchAttacker`

User ยืนยัน 2026-09-17:

- `AttackSetList` เก็บผู้โจมตีหลายยูนิต พร้อมประเภทแอ็กชันและดาเมจของแต่ละยูนิต เพื่อรองรับการร่วมโจมตีภายในแอ็กชันเดียว
- `switchAttacker` กำหนดว่าจะสลับไปใช้ผู้โจมตีคนไหนในจังหวะใด

รายละเอียดจาก `Attack()` ใน `Combat.h`:

- `changeWhen` เทียบกับ index ของ `damageSplit` (เริ่มที่ 0)
- `changeTo` เป็น index ของ `AttackSetList` ที่จะใช้ โดยเปลี่ยน `Attacker`, `actionTypeList` และ `damageTypeList` ตามรายการนั้น
- หาก `SwitchAtk.source` ถูกกำหนดไว้ ใช้เป็น `source`; หากไม่ได้กำหนด ใช้ผู้โจมตีที่เพิ่งสลับมา

## `damageSplit`

รายละเอียดการเตรียมผู้ร่วมโจมตีดูหัวข้อ `setJoint()` ด้านล่าง

User ยืนยัน 2026-09-17: `DamageSplit` เป็น `vector<vector<Damage>>` โดยชั้นนอกแบ่งจังหวะโจมตี และชั้นในเก็บดาเมจต่อเป้าหมายในจังหวะนั้น เช่น โจมตีหมู่หนึ่งจังหวะมีหลายเป้าหมายอยู่ในชุดเดียวกัน

## `setJoint()`

User ยืนยัน 2026-09-17: ใช้เตรียมแอ็กชันโจมตีร่วมระหว่างตัวละครกับ memosprite โดยเพิ่ม memosprite ของเจ้าของเข้า `AttackSetList` และติดประเภท `Summon` ให้ส่วนของ memosprite

รายละเอียดจากโค้ด: เพิ่ม `Attacking` โดยใช้ `Attacker->owner->getMemosprite()` และประเภทแอ็กชันปัจจุบัน จากนั้นเพิ่ม `Summon` ใน `actionTypeList` และ `damageTypeList` ของ `AttackSetList[1]`

## `targetList`

User ยืนยัน 2026-09-17: เก็บรายชื่อศัตรูที่เป็นเป้าหมายของแอ็กชันโดยไม่ซ้ำ ส่วน `damageSplit` เก็บรายละเอียดว่าแต่ละจังหวะโจมตีโดนใครบ้าง จึงมีเป้าหมายเดิมซ้ำข้ามจังหวะได้

## `Damage_element`

User ยืนยัน 2026-09-17: เป็นธาตุของดาเมจในแอ็กชัน เริ่มจากธาตุของผู้โจมตี และเปลี่ยนผ่าน `setDamageElement()` ได้ เพื่อรองรับการสร้างความเสียหายต่างธาตุจากตัวผู้โจมตี

## การเพิ่ม action type กับ damage type

จากโค้ด:

- `addActionType(type)` เพิ่มเฉพาะ `actionTypeList` ของแอ็กชันปัจจุบันและของผู้โจมตีหลัก `AttackSetList[0]`
- `addDamageType(type)` เพิ่มเฉพาะ `damageTypeList` สองตำแหน่งดังกล่าว
- `addAttackType(type)` เพิ่มทั้ง action type และ damage type สองตำแหน่ง

สามเมธอดนี้แยกกันเพื่อให้ trigger ที่ตรวจชนิดแอ็กชันกับสูตรที่ตรวจชนิดดาเมจเห็นข้อมูลตามที่ต้องการ โดยไม่จำเป็นต้องเพิ่มทั้งคู่เสมอ ความหมายของ list หลายชนิดดู [AllyActionData.md](AllyActionData.md#actiontypelist-หลาย-type)

## `actionFunction`

User อธิบาย 2026-09-17: รายละเอียดของแอ็กชันมีมาก จึงเลือกใช้ `actionFunction` เพื่อให้สามารถ custom รายละเอียดของแต่ละแอ็กชันได้ง่าย

รายละเอียดจาก `AllyActionData::AllyAction()` ใน `Combat.h`: ถ้ากำหนด `actionFunction` จะเรียก callback นี้; ถ้าไม่ได้กำหนดจึงเรียก `Attack()` โดยตรง ระบบไม่ได้เรียก `Attack()` เพิ่มให้อัตโนมัติหลัง callback

## `addDamage(type, value)`


User ยืนยัน 2026-09-17: บวกค่าที่ระบุให้ทุกรายการใน `damageSplit` เช่น เพิ่มสเกล ATK เท่ากันทุกเป้าหมาย ทุกจังหวะของแอ็กชัน

จากโค้ดปัจจุบัน รองรับ `ATK`, `HP`, `DEF` และ `CONST`

## `addDamageInsByDebuff`

User ยืนยัน 2026-09-17: เลือกโจมตีศัตรูตัวแรกที่ยังไม่มีดีบัฟชื่อนั้น เพื่อกระจายดีบัฟให้ครบก่อน หากทุกตัวที่ตรวจมีแล้วจะกลับไปตีเป้าหลัก

รายละเอียดจากโค้ด: overload ที่มี `max` จำกัดการค้นหาไว้ที่ index ศัตรู `1` ถึง `min(Total_enemy, max)`; เมธอดนี้เลือกเป้าหมายและเพิ่มรอบดาเมจ ไม่ได้ใส่ดีบัฟเอง

## `multiplyDmg(value)`

User ยืนยัน 2026-09-17: คูณสเกล ATK/HP/DEF และดาเมจค่าคงที่ทุกรายการใน `damageSplit` ด้วย `value / 100` เช่น `50` คือครึ่งหนึ่ง และ `200` คือสองเท่า โดยไม่เปลี่ยน `toughnessReduce` หรือสเกล `Elation`

## `addEnemyBounce` กับ `addEnemyFairBounce`

User ยืนยัน 2026-09-17: จำลองท่าเด้งโดยวนเป้าหมายแทนการสุ่ม

- `addEnemyBounce` เลือกเป้าหลักกับข้างเคียง; เมื่อเปิด `bestBounce` เลือกเฉพาะเป้าหลัก
- `addEnemyFairBounce` กระจายไปทั่วกลุ่มศัตรู

รายละเอียดจากโค้ด: ทั้งสองเมธอดเลือกจาก index ศัตรู `1` ถึง `min(Total_enemy, amount)` ตามเงื่อนไขข้างต้น แล้วสร้างรอบโจมตี `amount` รอบ วนเลือกจาก `targetList` ด้วย modulo

## `addDamageIns` กับ `addDamageHit`

User ชี้แจงและยืนยัน 2026-09-17 ว่าโค้ดปัจจุบันถูกต้องแล้ว:

- `addDamageIns` เพิ่มจำนวนครั้ง/รอบโจมตี โดยเพิ่มชุดชั้นนอกของ `damageSplit`
- `addDamageHit` เพิ่ม hit ภายในรอบนั้น โดยเพิ่มรายการในชุดสุดท้าย (`damageSplit.back()`)

ตัวอย่าง: มี 4 รอบแล้วเรียก `addDamageHit` จะยังมี 4 รอบ แต่รอบสุดท้ายมี hit เพิ่ม ส่วนการเพิ่มรอบที่ 5 ใช้ `addDamageIns`

ใน `Attack()` event `BeforeAttackPerHit` / `AfterAttackPerHit` ทำงานต่อชุดชั้นนอก จึงไม่ได้เพิ่มรอบ event เมื่อเพิ่ม hit ในชุดเดิม จุดเรียกใช้ `addDamageHit` ใน Serval และ Black Swan ใช้เพิ่มดาเมจให้เป้าข้างเคียง ไม่ต้องแก้โค้ด

## `addDamageIns` แบบส่งคู่ดาเมจ–เป้าหมาย

User ยืนยัน 2026-09-17: overload แบบ variadic ใช้กับท่าที่ต้องกำหนดเป้าหมายและสเกลของแต่ละเป้าเองอย่างอิสระ เช่น `addDamageIns(dmgA, enemyA, dmgB, enemyB)` เพิ่มหนึ่งรอบโจมตีแล้วใส่ทุกคู่ในรอบนั้น ไม่เลือกจาก `Main` / `Adjacent` / `Other`

จากโค้ด: ตรวจจำนวน argument ว่าเป็นคู่ด้วย `static_assert` แล้ว `addPairs()` รับทีละคู่และตรวจชนิดเป็น `DmgSrc` กับ `Enemy*` ก่อนเพิ่มในชุดเดียวกัน

## `critAble` กับ `critGarantee`

User ยืนยัน 2026-09-17:

- `critAble` กำหนดว่าดาเมจติดคริได้หรือไม่
- `critGarantee` เตรียมไว้สำหรับบังคับคริ แต่ยังไม่ได้ทำใช้งาน

ตรวจโค้ด: `critAble` เริ่มเป็น `true` และ `CalStats.h` คืนตัวคูณคริเป็น `1` เมื่อปิด; `critGarantee` เริ่มเป็น `false` และพบเฉพาะจุดประกาศใน `src`
