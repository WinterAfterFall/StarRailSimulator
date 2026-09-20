# `src/Defination/Function/Calculate/CalHealStats.h`

ไฟล์นี้คำนวณค่าสเตตัสของผู้ฮีลที่ใช้เป็นฐานของสูตรฮีล และคำนวณตัวคูณโบนัสฮีลระหว่างผู้ฮีลกับเป้าหมาย

## `calAtkMultiplier(Healer)` / `calHpMultiplier(Healer)` / `calDefMultiplier(Healer)`

ทั้งสามฟังก์ชันใช้รูปแบบเดียวกัน:

```text
ค่าสเตตัสที่ใช้ฮีล = base stat × (100 + stat%) / 100 + flat stat
```

- ATK ใช้ `baseAtk`, `ATK_P` และ `FLAT_ATK`
- HP ใช้ `baseHp`, `HP_P` และ `FLAT_HP`
- DEF ใช้ `baseDef`, `DEF_P` และ `FLAT_DEF`

ทุกค่าอ่านจาก `Stats_type[...][AType::None]` ของผู้ฮีล และผลลัพธ์ติดลบถูก clamp เป็น `0` User ยืนยัน 2026-09-20 ว่าตั้งใจไม่รวมโบนัส ATK/HP/DEF ที่ผูกกับ action type เช่น Skill หรือ Ultimate เข้าสูตรฮีล

เดิมทั้งสามฟังก์ชันรับ `target` ด้วยแต่ไม่ได้ใช้งาน User ยืนยัน 2026-09-20 ว่าลบได้ จึงเหลือพารามิเตอร์ `Healer` เพียงตัวเดียว

## `calHealBonusMultiplier(Healer, target)`

รวมโบนัสฮีลออกของผู้ฮีลกับโบนัสฮีลเข้าของเป้าหมาย:

```text
(100 + Healer.HEALING_OUT + target.HEALING_IN) / 100
```

User ยืนยัน 2026-09-20 ว่า `HEALING_OUT` กับ `HEALING_IN` ตั้งใจบวกรวมกันก่อนแปลงเป็นตัวคูณ หากตัวคูณติดลบจะคืน `0`
