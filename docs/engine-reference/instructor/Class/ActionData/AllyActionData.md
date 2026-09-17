# `src/Defination/Class/ActionData/AllyActionData.h`

## `Attacker` กับ `source`

User ยืนยัน 2026-09-16:

- `Attacker` คือยูนิตที่ทำแอ็กชัน ใช้ตรวจ trigger และจัดการ energy
- `source` คือยูนิตเจ้าของค่าพลังที่ใช้เป็นฐานสเกล ATK/HP/DEF ซึ่งอาจเป็นคนละยูนิตกับผู้โจมตี ส่วน CR/CD, DMG%, การลด DEF และ RES PEN ยังอิง `Attacker`
- ตัวอย่าง: Netherwing ซึ่งเป็น memosprite ของ Castorice ใช้ HP ของ Castorice เป็นฐานคำนวณ แต่ใช้ค่าคริติคอลและ stats อื่น ๆ ของ Netherwing เอง

ตอนสร้างแอ็กชัน `Attacker` และ `source` เริ่มจากยูนิตเดียวกัน แล้วสกิลที่ต้องใช้ค่าพลังของคนอื่นจึงเปลี่ยน `source`

## `Turn_reset`

User ยืนยัน 2026-09-16: บ่งบอกว่าหลังจบแอ็กชันนี้ ตัวละครจะรีเซ็ตเทิร์นหรือไม่

- ค่าเริ่มต้นเป็น `false`; Basic Attack และ Skill ตั้งเป็น `true` ใน `setupActionType`
- เมื่อจบแอ็กชัน ถ้าเป็น `true` จะเรียก `resetTurn(turn)` ใน `Combat.h`; Ultimate/FuA ปกติไม่รีเซ็ต
- `setTurnReset(bool)` ใช้กำหนดค่า และ `turnResetTrue()` ใช้ตั้งเป็น `true`

## `traceType`

User ยืนยัน 2026-09-16: ระบุรูปแบบเป้าหมายของแอ็กชัน (`TraceType` ใน `src/Enum/Enum.h`)

- `Single`: เป้าเดี่ยว
- `Blast`: เป้าหลักกับเป้าข้างเคียง
- `Aoe`: หมู่
- `Bounce`: เด้ง

## `isSameName` กับ `isSameOwnerName`

User ยืนยัน 2026-09-16:

- `isSameName` ตรวจยูนิตผู้โจมตีโดยตรง
- `isSameOwnerName` ตรวจรวมถึงยูนิตของตัวละครนั้นด้วย เช่น Netherwing โจมตี ก็ตรงกับ Castorice เมื่อใช้ `isSameOwnerName`

รายละเอียดจาก `ActionDataDefine.h`: แอ็กชันโจมตีวนตรวจผู้โจมตีใน `AttackSetList` และคืน `true` เมื่อพบรายการที่ตรง ส่วนแอ็กชันอื่นตรวจ `Attacker` โดยตรง; `isSameOwnerName` ใช้ `isSameOwner` ตรวจความสัมพันธ์กับตัวละคร

## `getChar()`

User ยืนยัน 2026-09-16: ใช้อ้างอิงกลับไปยังตัวละครเจ้าของ เช่น สำหรับรวมผลเข้าตัวละคร

- ถ้า `Attacker` เป็น memosprite จะคืนเจ้าของ เช่น Netherwing → Castorice
- ถ้า `Attacker` เป็นตัวละคร จะคืนตัวละครนั้นเอง

## จุดต่อการสำรวจ

- `isSameAction` / `isSameOwnerAction`: ถามไปแล้ว; user เตือนไม่ให้ถามซ้ำ
- `AttackSetList` / `switchAttacker` สำรวจแล้ว ดู [AllyAttackAction.md](AllyAttackAction.md); จุดต่อปัจจุบันดู [LOG.md](../../LOG.md)
