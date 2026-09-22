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

### `Cal_Crit_rate_multiplier()` / `Cal_Crit_dam_multiplier()`

**ยุบรวมแล้ว 2026-09-22** ([🐞 #25](../../BUGS.md)) — เดิมสูตรรวม CR/CD ถูกเขียนซ้ำสองที่: ในสองฟังก์ชันนี้ (ซึ่งไม่มีใครเรียกเลย) และซ้ำอีกชุดในตัว `calCritMultiplier()` เอง ทำให้การแก้ครั้งหนึ่งไปโดนแค่ชุดเดียว (เช่นการแก้ป้าย debug 2026-09-20 ข้างบน แก้เฉพาะชุดที่ไม่ทำงาน) ตอนนี้ `calCritMultiplier()` เรียกสองฟังก์ชันนี้แทน เหลือสูตรชุดเดียวในเรโป

โครงของทั้งคู่เหมือนกัน ต่างกันแค่ stat ที่อ่าน (`Stats::CR` กับ `Stats::CD`):

```cpp
mtpr = Attacker->Stats_type[stat][AType::None] + target->Stats_type[stat][AType::None];
for (type : act->damageTypeList)
    mtpr += Attacker->Stats_type[stat][type] + target->Stats_type[stat][type];
return (mtpr < 0) ? 0 : mtpr;      // clamp พื้นที่ 0 — เพดานอยู่ที่ผู้เรียก
```

จุดที่ต้องจำ:

- **รวมค่าจากศัตรูด้วย** ไม่ใช่แค่ผู้โจมตี — ช่อง `Stats_type[CR]` / `[CD]` ของ `target` คือทางที่ดีบัฟประเภท "เป้านี้โดนคริตง่ายขึ้น" ใช้
- **วนตาม `damageTypeList` ไม่ใช่ `actionTypeList`** ตรงตามกติกาใน [AllyAttackAction.md](../../Class/ActionData/AllyAttackAction.md): `damageTypeList` คือแกนที่ใช้ค้นบัฟ
- **คืนค่าเป็นเปอร์เซ็นต์ดิบ ไม่ใช่ตัวคูณ** เช่น CR 85 คืน `85` ไม่ใช่ `0.85` — ตัวหาร 100 และเพดาน CR ที่ `100%` อยู่ใน `calCritMultiplier()` ผู้เรียก
- แต่ละตัวพิมพ์ debug ของตัวเองคุมด้วย `canCheckDmgformulaCritRate()` / `canCheckDmgformulaCritDam()` ([FormulaCheck.md](../AdjustFunction/FormulaCheck.md)) — ตอนยุบได้ปรับความกว้างคอลัมน์ของทั้งสองตัวให้ตรงกับที่ `calCritMultiplier()` เคยพิมพ์ (`setw(7)`) ผลลัพธ์บนจอจึงไม่เปลี่ยน

⚠️ **มีหนึ่งกรณีที่ผลต่างจากเดิม**: ถ้า CR และ CD **ติดลบพร้อมกัน** โค้ดเดิมจะได้ลบ×ลบ = บวก แล้วคืนตัวคูณ **มากกว่า 1** (เช่น CR −50, CD −100 → `1.5`) ส่วนโค้ดใหม่ clamp ทั้งคู่เป็น 0 ก่อน จึงคืน `1.0` ตามเจตนาของ clamp ขั้นต่ำ กรณีอื่น (ติดลบตัวเดียว หรือบวกทั้งคู่) ผลเท่าเดิมทุกประการ

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

## `calToughnessMultiplier()` (บรรทัด 392)

คืน Broken Multiplier แบบคิดสด — `1.0` เมื่อศัตรู broken อยู่ · `0.9` เมื่อยังไม่ broken · และคืน `1` (ไม่ใส่ 0.9) เมื่อ action นั้นตั้ง `toughnessAvgCalculate` ไว้ เพราะตัวคูณจะถูกเฉลี่ยทีหลังแทน

เหตุผลของการมีสองเส้นทางนี้ และวิธีที่ตัวคูณเฉลี่ยถูกปั๊มลงสมุดตอนจบรัน อธิบายไว้ใน [CalDamageNote.md](CalDamageNote.md) หัวข้อ "สมุดดาเมจ 2 เล่ม"
