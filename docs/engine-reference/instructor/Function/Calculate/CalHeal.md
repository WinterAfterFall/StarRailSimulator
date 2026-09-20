# `src/Defination/Function/Calculate/CalHeal.h`

## `calculateHeal(healSrc, Healer, target)`

นำองค์ประกอบทั้งหกใน `HealSrc` มารวมเป็นค่าฮีลก่อนนำไปใช้กับ HP:

```text
ATK ของผู้ฮีล × ATK ratio / 100
+ HP ของผู้ฮีล × HP ratio / 100
+ DEF ของผู้ฮีล × DEF ratio / 100
+ เปอร์เซ็นต์ HP ที่เป้าหมายเสียไป
+ เปอร์เซ็นต์ HP สูงสุดของเป้าหมาย
+ ค่าฮีลคงที่
```

ผลรวมทั้งหมดคูณด้วยโบนัสฮีลจาก `calHealBonusMultiplier(Healer, target)` แล้ว clamp ค่าติดลบเป็น `0` รายละเอียดค่าใน `HealSrc` ดู [HealData.md](../../Class/CombatData/HealData.md) และสูตร stat/โบนัสฮีลดู [CalHealStats.md](CalHealStats.md)

User ยืนยัน 2026-09-20 ว่า ratio ทั้งหกชนิดใน `HealSrc` ถูกออกแบบให้เป็น `0` หรือค่าบวก ไม่มีการใช้ ratio ติดลบเพื่อลดองค์ประกอบอื่นของสูตรฮีล

## การตรวจสูตรและผลฮีล

User ยืนยัน 2026-09-20 ว่า flags ฝั่งผู้ฮีลกับผู้รับฮีลใช้เลือกตรวจเป็นคู่:

- แสดงรายละเอียดสูตรเมื่อ `Healer->owner->checkHealFormula` และ `target->owner->checkHealReceiveFormula` เป็นจริงพร้อมกัน
- แสดงผล `Total Heal` เมื่อ `Healer->owner->checkHeal` และ `target->owner->checkHealReceive` เป็นจริงพร้อมกัน
- แสดงหัวข้อ `From <Healer> to <target>` เมื่อเงื่อนไขใดเงื่อนไขหนึ่งข้างต้นเป็นจริง

แก้ข้อความ debug วันที่ 2026-09-20: แถว `Total Hp` เดิมแสดง `healFromLostHP` ทั้งที่ผลด้านขวาคำนวณด้วย `healFromTotalHP`; เปลี่ยนค่าที่แสดงให้ตรงกับสูตรแล้ว การแก้นี้ไม่เปลี่ยนผลฮีลจริง

## `calculateHealFromLostHP(target, percent)`

```text
percent / 100 × (target.totalHP - target.currentHP)
```

คิดจาก HP ที่เป้าหมายเสียไป และคืน `0` หากผลลัพธ์ติดลบ

## `calculateHealFromTotalHP(target, percent)`

```text
percent / 100 × target.totalHP
```

คิดจาก HP สูงสุดของเป้าหมาย และคืน `0` หากผลลัพธ์ติดลบ
