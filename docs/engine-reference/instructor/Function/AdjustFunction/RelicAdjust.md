# `src/Defination/Function/AdjustFunction/RelicAdjust.h`

## Requirement setters

- `setSpeed()` กำหนดเป้า SPD โดยตรง
- `newSpeedRequire()` เก็บเป้า SPD ที่สูงกว่าเดิม
- `newApplyBaseChanceRequire()` เก็บ base chance ที่ต่ำที่สุดซึ่งไม่เป็นศูนย์ เพราะ base chance ต่ำต้องใช้ EHR มากกว่า
- `newEhrRequire()` เก็บเป้า EHR ที่สูงกว่าเดิม

## Substat controls

`setTotalSubstats()` กำหนดงบ roll รวมและเก็บไว้ที่ช่องแรกของ `Substats` พร้อมปรับขนาด `bestSubstats`; `pushSubstats()` เพิ่มชนิด stat ที่ optimizer แจก roll ได้; `changeTotalSubStats()` ปรับงบโดย clamp ไม่ให้ต่ำกว่าศูนย์ แล้วคืนค่าตรงข้ามกับจำนวนที่ปรับจริงเพื่อให้ผู้เรียกใช้ย้อนการเปลี่ยนแปลงได้
