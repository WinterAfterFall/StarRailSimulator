# `src/Defination/Function/Calculate/CalStats.h`

ไฟล์นี้รวม helper คำนวณ stat ปัจจุบัน, ค่า stat ที่ใช้สร้างบัฟ และตัวคูณแต่ละส่วนของสูตรดาเมจ

## Stat ปัจจุบันจาก `AType::None`

- `calculateAtkOnStats`, `calculateHpOnStats`, `calculateDefOnStats`: base stat × (100 + stat%) / 100 + flat stat
- `calculateSpeedOnStats`: base SPD × (100 + SPD%) / 100 + flat SPD
- `calculateCritrateOnStats`, `calculateCritdamOnStats`, `calculateBreakEffectOnStats`, `calculateElationOnStats`, `calculateEhrOnStats`: อ่านค่าชนิดนั้นจาก `AType::None`
- `calculateHPLost`: `totalHP - currentHP`

ทุก helper ในกลุ่มนี้ clamp ผลลัพธ์ติดลบเป็น `0`

## `calculate*ForBuff(ptr, ratio)` และ `AType::TEMP`

helper กลุ่มนี้คำนวณ stat ตาม `ratio` เพื่อนำไปกำหนดปริมาณบัฟ ก่อนคำนวณจะหัก stat ใน `AType::TEMP` ออกจากค่าของผู้แจกบัฟ

User ยืนยัน 2026-09-20 ว่า `TEMP` ไม่ได้กันเพียงบัฟคำนวณจาก stat ของตัวเองวนซ้ำ แต่ครอบคลุมบัฟทุกประเภทที่มีปริมาณอิงจาก stat ของผู้แจกบัฟ: stat ที่ผู้แจกได้รับมาจากบัฟชนิดนี้จะไม่สามารถนำไปเพิ่มปริมาณของบัฟที่คำนวณจาก stat ชนิดอื่นต่อเป็นทอด ๆ ได้

กลุ่มนี้รองรับ ATK, HP, DEF, SPD, CR, CD, Break Effect, EHR และ Elation และ clamp ผลลัพธ์สุดท้ายที่ติดลบเป็น `0`

## `calAtkMultiplier` / `calHpMultiplier` / `calDefMultiplier` ของดาเมจ

เริ่มจาก base stat ของ `act->source` แล้วรวม stat% และ flat stat จาก:

- `AType::None` ของ `source` และศัตรู `target`
- ทุก type ใน `act->damageTypeList` ของ `source` และ `target`

User ยืนยัน 2026-09-20 ว่า stat ฝั่ง `target` ใช้แทน modifier จาก debuff/สถานะบนศัตรู ซึ่งเพิ่มหรือลดค่าสเกลของผู้โจมตีเฉพาะตอนโจมตีเป้าหมายนั้น

สูตรสามตัวนี้ใช้ `source` เป็นเจ้าของ base ATK/HP/DEF ตามกลไกที่อธิบายใน [AllyActionData.md](../../Class/ActionData/AllyActionData.md#attacker-กับ-source) ส่วนตัวคูณดาเมจและคริติคอลส่วนถัดไปใช้ `Attacker`

## `calBonusDmgMultiplier()`

เริ่มจาก `100%` แล้วรวม DMG% ทั่วไปและ DMG% ธาตุจาก `Attacker` กับ `target` ทั้งช่อง `AType::None` และทุก type ใน `damageTypeList` ก่อนหารด้วย `100` เป็นตัวคูณ

User ยืนยัน 2026-09-20 ว่าตัวคูณ DMG ต้องไม่ต่ำกว่า `0` จึงแก้ให้ clamp ที่ศูนย์เมื่อ DMG% รวมต่ำกว่า `-100%` ป้องกันดาเมจติดลบ

## `calCritMultiplier()`

ถ้า action ไม่สามารถคริติคอลได้จะคืน `1` มิฉะนั้นรวม CR และ CD จาก `Attacker` กับ `target` ทั้งช่อง `AType::None` และทุก type ใน `damageTypeList`; CR ถูกจำกัดสูงสุดไว้ที่ `100%` แล้วคำนวณค่าเฉลี่ย `1 + CR × CD`

User ยืนยัน 2026-09-20 ว่าค่าเฉลี่ยคริติคอลต้องไม่ทำให้ดาเมจต่ำกว่า non-crit จึง clamp multiplier สุดท้ายขั้นต่ำที่ `1.0` ครอบคลุมกรณี CR หรือ CD รวมติดลบ

แก้ข้อความ debug ใน `Cal_Crit_dam_multiplier()` วันที่ 2026-09-20: ช่อง `Base Crit dam` เดิมแสดง `Stats::CR`; เปลี่ยนเป็น `Stats::CD` ให้ตรงกับป้ายและสูตร

## `calDefShredMultiplier()`

รวม DEF shred จาก `Attacker` และ `target` ทั้ง `AType::None` กับทุก type ใน `damageTypeList` โดย cap ค่าสูงสุดที่ `100%` แล้วคำนวณ:

```text
100 / (100 + 115 × (1 - DEF_SHRED / 100))
```

User ยืนยัน 2026-09-20 ว่าค่าคงที่ `115` มาจากสมการ DEF ของศัตรูเลเวล 95 (`95 + 20`)

DEF shred ถูก cap เฉพาะค่าสูงสุดที่ `100%` และตั้งใจอนุญาตค่าติดลบ โดยค่าติดลบหมายถึงศัตรูได้รับ DEF เพิ่มขึ้น จึงลด multiplier และดาเมจลง (User ยืนยัน 2026-09-20)

## `Cal_Superbreak_DamageIncrease_multiplier()`

รวม `Stats::SPB_inc` ใน `AType::None` จาก `Attacker` และ `target` เข้ากับฐาน `100%` แล้ว clamp ตัวคูณขั้นต่ำที่ `0` ปัจจุบันยังไม่มีตัวละคร, light cone, relic หรือ planar เพิ่ม stat นี้; User ยืนยัน 2026-09-20 ว่าเตรียมช่องไว้สำหรับเอฟเฟกต์เพิ่ม Super Break DMG ในอนาคต

## `calElationMultiplier()`

รวม Elation จาก `source` และ `target` ทั้ง `AType::None` กับทุก type ใน `damageTypeList` เข้ากับฐาน `100%` และ clamp ตัวคูณขั้นต่ำที่ `0` User ยืนยัน 2026-09-20 ว่าค่า Elation ตั้งใจอิง `source` แบบเดียวกับ ATK/HP/DEF ไม่ใช่ `Attacker`

## `calPunchLineMultiplier()`

ถ้า `damageTypeList` มี `ElationSkill` จะใช้ global `punchline`; กรณีอื่นรวม `CertifiedBanger` จาก `Attacker` และ `target` ทั้ง `AType::None` กับทุก damage type แล้วคำนวณด้วยสูตรเดียวกัน:

```text
1 + (จำนวน × 5) / (240 + จำนวน)
```

ค่าติดลบคืนตัวคูณกลาง `1` User ยืนยัน 2026-09-20 ว่าค่าคงที่ `5` และ `240` มาจากสูตรในเกมโดยตรง ไม่ใช่สูตรประมาณของ simulator

## ตัวคูณเชิงเส้นกลุ่มอื่น

`calRespenMultiplier`, `calVulMultiplier`, `calBreakEffectMultiplier`, `calMerryMakeMultiplier`, `calMitigationMultiplier` และ `calMultiplierIncrease` เริ่มจากฐาน `100%` แล้วรวมค่าจาก `Attacker` กับ `target` ใน `AType::None` และทุก type ใน `damageTypeList` ก่อนแปลงเป็นตัวคูณ โดย clamp ขั้นต่ำที่ `0`

ข้อยกเว้นด้านแหล่งข้อมูล: `calRespenMultiplier` รวมค่าตามธาตุของดาเมจด้วย ส่วน convention RES/RES PEN อธิบายใน [Stats_Reset.md](../Setup/Stats_Reset.md)

User ยืนยัน 2026-09-20 ว่า `Stats::Mitigration` ใช้ค่าติดลบเพื่อแสดงการลดดาเมจ เช่น `-20` → multiplier `0.8`; ค่าบวกเพิ่มดาเมจตามสูตร ปัจจุบันยังไม่มี caller กำหนด stat นี้
