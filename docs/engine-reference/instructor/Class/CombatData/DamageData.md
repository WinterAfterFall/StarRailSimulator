# `src/Defination/Class/CombatData/DamageData.h`

## `Damage` และ `DmgSrc`

User ยืนยัน 2026-09-17: แต่ละ `Damage` จับคู่ `target` (เป้าหมาย) กับ `dmgSrc` ซึ่งเก็บตัวคูณสเกลจาก ATK/HP/DEF/Elation, ดาเมจค่าคงที่ (`constDmg`) และค่าลด toughness (`toughnessReduce`) ของการโจมตีเป้าหมายนั้น

โครงสร้าง `DamageSplit` และการแบ่งจังหวะโจมตี ดู [AllyAttackAction.md](../ActionData/AllyAttackAction.md#damagesplit)

## Constructor แบบรับค่าครบของ `Damage`

User ยืนยัน 2026-09-18: ต้องเก็บเป้าหมายที่ส่งมาเป็น `target(target)` เช่นเดียวกับ overload อื่น แก้จาก `target(nullptr)` แล้ว

## หน่วยของค่าใน `DmgSrc`

User ยืนยัน 2026-09-17:

- `ATK` / `HP` / `DEF` / `Elation` เป็นเปอร์เซ็นต์สเกล เช่น `ATK = 150` หมายถึง 150%
- `constDmg` เป็นดาเมจค่าคงที่
- `toughnessReduce` เป็นจำนวนหน่วย toughness ที่ลดโดยตรง
