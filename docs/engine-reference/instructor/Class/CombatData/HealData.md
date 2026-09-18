# `src/Defination/Class/CombatData/HealData.h`

## `HealSrc` — ค่าที่ใช้กำหนดปริมาณฮีล

User ยืนยัน 2026-09-18:

- `ATK` / `HP` / `DEF` เป็นเปอร์เซ็นต์สเกลจากค่าพลังของผู้ฮีล
- `constHeal` เป็นค่าฮีลคงที่
- `healFromTotalHP` เป็นเปอร์เซ็นต์ HP สูงสุดของผู้รับฮีล
- `healFromLostHP` เป็นเปอร์เซ็นต์ HP ที่ขาดของผู้รับฮีล

ทุกส่วนถูกนำมาบวกกันแล้วคูณโบนัสฮีล ตาม `calculateHeal()` ใน `src/Defination/Function/Calculate/CalHeal.h` ค่าทั้งหกเริ่มต้นเป็น 0

## Constructor แบบคู่ชนิด–ค่า

User ยืนยัน 2026-09-18: เลือกใส่เฉพาะค่าที่ต้องใช้ โดยไม่ต้องเติมศูนย์ตามลำดับพารามิเตอร์ เช่น `HealSrc(HealSrcType::ATK, 60, HealSrcType::CONST, 800)` คือ 60% ATK ของผู้ฮีล + 800 ก่อนคูณโบนัสฮีล ค่าที่ไม่ระบุยังเป็น 0

จากโค้ด: ตรวจจำนวน argument ให้เป็นคู่ด้วย `static_assert` แล้ว `setValues()` ไล่ส่งแต่ละคู่ให้ `setValue()`

## `setValue()`

User ยืนยัน 2026-09-18: กำหนดค่าทับ ไม่บวกสะสม เช่น ATK เดิม 60 แล้วตั้ง 80 จะเป็น 80; หากส่งชนิดเดียวกันซ้ำใน constructor แบบคู่ชนิด–ค่า คู่สุดท้ายจะทับค่าก่อนหน้า

จากโค้ด: ชนิดที่ไม่อยู่ใน `HealSrcType` ที่รองรับจะโยน `std::invalid_argument` ส่วน constructor แบบค่าตามลำดับรับ ATK, HP, DEF, constHeal, healFromTotalHP, healFromLostHP โดยทุกพารามิเตอร์มีค่าเริ่มต้น 0
