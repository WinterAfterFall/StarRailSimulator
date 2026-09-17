# `src/Defination/Class/ActionData/AllyBuffAction.h`

## `buffTargetList` กับ `actionFunction`

User ยืนยัน 2026-09-17:

- `buffTargetList` เก็บยูนิตฝ่ายเราที่เป็นเป้าหมายรับผลของแอ็กชัน
- `actionFunction` กำหนดรายละเอียดว่าจะให้บัฟหรือทำอะไรกับเป้าหมายเหล่านั้น

## `addBuffChar(ptr)` กับ `addBuffAllAllies()`

User ยืนยัน 2026-09-17:

- `addBuffChar(ptr)` เลือกทั้งตัวละครและ memosprite ของตัวละครนั้น
- `addBuffAllAllies()` เลือกทั้งทีมรวม memosprite
- ทั้งสองเมธอดเว้นยูนิตที่เป็น `UnitType::OutofBounds`

## `addBuffSingleTarget(ptr)`

User ยืนยัน 2026-09-17: แบบระบุเป้าหมายเองเพิ่มยูนิตที่ส่งมาโดยไม่กรอง `OutofBounds` โดยตั้งใจให้ผู้เรียกเลือกและตรวจความเหมาะสมของเป้าหมายเอง

## เมธอดตรวจผู้ให้บัฟ

2026-09-17: user ขอให้เมธอดที่ตรวจ owner มีคำว่า `Owner` ในชื่อ จึงแยกชื่อให้ชัดเจนแทนการใช้ overload ตามชนิด pointer:

- `isSameBufferOwnerName(CharUnit*)` ตรวจผู้ให้บัฟรวมยูนิตของเจ้าของ ผ่าน `isSameOwner`
- `isSameOwnerBuff(CharUnit*, AType)` ตรวจ owner พร้อมประเภทแอ็กชัน
- `isSameBufferName(AllyUnit*)` / `isSameBufferName(string)` ตรวจยูนิตผู้ให้บัฟตรงตัว
- `isSameBuff(AllyUnit*, AType)` / `isSameBuff(string, AType)` ตรวจยูนิตตรงตัวพร้อมประเภทแอ็กชัน ส่วน `isSameBuff(AType)` ตรวจเฉพาะประเภท

ตรวจ `src` ณ ตอนเปลี่ยนชื่อ ไม่พบจุดเรียกใช้เมธอดกลุ่มนี้
