# `src/Defination/Class/ActionData/AllyBuffAction.h`

## `addToActionBar()`

User ยืนยัน 2026-09-17: ส่งแอ็กชันที่เตรียมไว้เข้าคิวกลาง ยังไม่ออกท่าทันที เช่นเดียวกับฝั่งโจมตี

จากโค้ด: ตรวจ `Attacker->isExisted()` ก่อน แล้วใช้ `shared_from_this()` ส่งแอ็กชันเดิมเข้า `Action_bar`; ไม่รวบรวมเป้าหมายเพิ่ม เพราะกำหนด `buffTargetList` ไว้ก่อนแล้ว

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

2026-09-17: user อนุมัติให้ใช้เมธอดร่วมจาก `AllyActionData` และลบเมธอดตรวจที่ซ้ำใน `AllyBuffAction`:

- `isSameOwnerName(CharUnit*)` ตรวจผู้ให้บัฟรวมยูนิตของเจ้าของ ผ่าน `isSameOwner`
- `isSameOwnerAction(CharUnit*, AType)` ตรวจ owner พร้อมประเภทแอ็กชัน
- `isSameName(AllyUnit*)` / `isSameName(string)` ตรวจยูนิตผู้ให้บัฟตรงตัว
- `isSameAction(AllyUnit*, AType)` / `isSameAction(string, AType)` ตรวจยูนิตตรงตัวพร้อมประเภทแอ็กชัน ส่วน `isSameAction(AType)` ตรวจเฉพาะประเภท

คลาสแม่ตรวจ `Attacker` และ `actionTypeList` โดยตรงเมื่อเป็น buff; เมื่อเป็น attack จะวน `AttackSetList` พฤติกรรมตรวจเดิมจึงคงอยู่ ตรวจ `src` ก่อนลบไม่พบจุดเรียกใช้เมธอดเฉพาะฝั่ง buff
