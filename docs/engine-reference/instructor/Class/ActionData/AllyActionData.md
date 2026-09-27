# `src/Defination/Class/ActionData/AllyActionData.h`

## `attacker` กับ `source`

User ยืนยัน 2026-09-16:

- `attacker` คือยูนิตที่ทำแอ็กชัน ใช้ตรวจ trigger และจัดการ energy
- `source` คือยูนิตเจ้าของค่าพลังที่ใช้เป็นฐานสเกล ATK/HP/DEF ซึ่งอาจเป็นคนละยูนิตกับผู้โจมตี ส่วน CR/CD, DMG%, การลด DEF และ RES PEN ยังอิง `attacker`
- ตัวอย่าง: Netherwing ซึ่งเป็น memosprite ของ Castorice ใช้ HP ของ Castorice เป็นฐานคำนวณ แต่ใช้ค่าคริติคอลและ stats อื่น ๆ ของ Netherwing เอง

ตอนสร้างแอ็กชัน `attacker` และ `source` เริ่มจากยูนิตเดียวกัน แล้วสกิลที่ต้องใช้ค่าพลังของคนอื่นจึงเปลี่ยน `source`

## `turnReset`

User ยืนยัน 2026-09-16: บ่งบอกว่าหลังจบแอ็กชันนี้ ตัวละครจะรีเซ็ตเทิร์นหรือไม่

- ค่าเริ่มต้นเป็น `false`; Basic Attack และ Skill ตั้งเป็น `true` ใน `setupActionType`
- เมื่อจบแอ็กชัน ถ้าเป็น `true` จะเรียก `resetTurn(turn)` ใน `Combat.h`; Ultimate/FuA ปกติไม่รีเซ็ต
- จังหวะ: attack reset ใน `attack()` (`Combat.h:218`) ก่อน `allEventWhenAttack` / `allEventAfterAttackAction`; buff reset ที่ `Combat.h:153` ก่อน `allEventBuff` — user ยืนยัน 2026-09-19 ว่าตั้งใจ reset ATV ก่อนปล่อย event เพื่อให้ action advance / ปรับ ATV ที่เกิดใน event ทำงานบนค่าที่ reset แล้ว ไม่ถูกทับทีหลัง
- `setTurnReset(bool)` ใช้กำหนดค่า และ `turnResetTrue()` ใช้ตั้งเป็น `true`

## `traceType`

User ยืนยัน 2026-09-16: ระบุรูปแบบเป้าหมายของแอ็กชัน (`TraceType` ใน `src/Enum/Enum.h`)

- `SINGLE`: เป้าเดี่ยว
- `BLAST`: เป้าหลักกับเป้าข้างเคียง
- `AOE`: หมู่
- `BOUNCE`: เด้ง

## `isSameName` กับ `isSameOwnerName`

User ยืนยัน 2026-09-16:

- `isSameName` ตรวจยูนิตผู้โจมตีโดยตรง
- `isSameOwnerName` ตรวจรวมถึงยูนิตของตัวละครนั้นด้วย เช่น Netherwing โจมตี ก็ตรงกับ Castorice เมื่อใช้ `isSameOwnerName`

รายละเอียดจาก `ActionDataDefine.h`: แอ็กชันโจมตีวนตรวจผู้โจมตีใน `attackSetList` และคืน `true` เมื่อพบรายการที่ตรง ส่วนแอ็กชันอื่นตรวจ `attacker` โดยตรง; `isSameOwnerName` ใช้ `isSameOwner` ตรวจความสัมพันธ์กับตัวละคร

## `getChar()`

User ยืนยัน 2026-09-16: ใช้อ้างอิงกลับไปยังตัวละครเจ้าของ เช่น สำหรับรวมผลเข้าตัวละคร

- ถ้า `attacker` เป็น memosprite จะคืนเจ้าของ เช่น Netherwing → Castorice
- ถ้า `attacker` เป็นตัวละคร จะคืนตัวละครนั้นเอง

## `actionTypeList` (หลาย type)

User ยืนยัน 2026-09-19:

- แอ็กชันหนึ่งนับเป็นได้หลาย type (เช่น Skill ที่นับเป็น Summon ด้วยผ่าน `addActionType(AType::SUMMON)` ใน Aglaea / Hyacine / RMC) เพื่อให้สกิลที่ trigger จาก type อื่น ๆ มีโอกาสทำงานกับแอ็กชันนี้ด้วย
- ฝั่งดาเมจ (`damageTypeList` ใน `AllyAttackAction`): มีหลาย type ทำให้ตอนคำนวณดาเมจรวมบัฟของ type อื่นด้วย
- User ยืนยัน 2026-09-19: ลำดับใน list ไม่มีความหมายเชิงกลไก `getActionType()` เป็นแค่ทางลัดของ `getActionType(0)` (เช่น SPB ใส่ `BREAK` ก่อน `SPB` ไม่ได้แปลว่า Break เป็น type หลัก)
- จากโค้ด: `getActionType()` คืนตัวแรก (index 0); `getActionType(index)` คืน `AType::ERROR` เมื่อ index เกิน; `CalDamage.h:211-215` วนรวม Toughness Reduction / Break Efficiency ของทุก type ใน `actionTypeList`

## `allyAction()` (`Combat.h:128`) — ลำดับ event

User ยืนยัน 2026-09-19:

- attack: `allEventBeforeAttackAction` → `actionFunction` (หรือ `attack()` ถ้าไม่มี) → `allEventWhenAttack` **ปล่อยครั้งละตัวใน `attackSetList`** (สลับ `attacker` / `actionTypeList` / `damageTypeList` ตามรายการ) → คืนค่าเป็น `attackSetList[0]` → `allEventAfterAttackAction` → `calAverageDamage` ถ้า `damageNote`
- ตั้งใจให้ `allEventWhenAttack` เป็น event เดียวที่แยกรายผู้โจมตี เพื่อให้ trigger ที่เช็ค "ใครตี" (เช่น memosprite ใน joint attack) ทำงานถูกตัว ส่วน before/after นับเป็นแอ็กชันเดียวของเจ้าของ (index 0)
- buff: `actionFunction` → `resetTurn` ถ้า `turnReset` → `allEventBuff`

## จุดต่อการสำรวจ

- `isSameAction` / `isSameOwnerAction`: ถามไปแล้ว; user เตือนไม่ให้ถามซ้ำ
- `attackSetList` / `switchAttacker` สำรวจแล้ว ดู [AllyAttackAction.md](AllyAttackAction.md); จุดต่อปัจจุบันดู [LOG.md](../../LOG.md)

## accessor และการ cast

`getAttacker()` (บรรทัด 26) คืน `attacker` (`AllyUnit*`) ตรง ๆ — ต่างจาก `getChar()` ที่เด้งไปหา `CharUnit` เจ้าของ ถ้าผู้โจมตีเป็นเมมอสไปรต์ สองตัวนี้จะคืนคนละยูนิต ดูกติกาผู้โจมตี vs เจ้าของใน [AllyAttackAction.md](AllyAttackAction.md)

`castToAllyActionData()` (บรรทัด 79) — `dynamic_cast` จาก `ActionData*` ขึ้นมาเป็น `AllyActionData*` คืน `nullptr` ถ้า action นั้นเป็นของศัตรู · คู่กับ `castToAllyAttackAction()` และ `castToEnemyActionData()` ตามลำดับชั้นใน [ActionData.md](ActionData.md)
