# `src/Defination/Function/Calculate/CalRequireStats.h`

ไฟล์นี้กัน substat rolls ส่วนหนึ่งไว้เพื่อให้ตัวละครถึงค่า requirement ก่อนนำ rolls ที่เหลือไป reroll หา damage สูงสุด การเรียกใน `SetCombat()` เรียงเป็น ATK → HP → DEF → SPD → EHR ซึ่งเป็นลำดับ priority เมื่อ rolls มีไม่พอ

ทุกสูตรคำนวณ stat ที่ยังขาด ปัดจำนวน rolls ขึ้นด้วย `ceil` แล้วส่งจำนวนที่ต้องการให้ `changeTotalSubStats(-rolls)` ฟังก์ชันนั้นจำกัดจำนวนตาม rolls ที่เหลือและคืนจำนวนที่จัดสรรได้จริง

## ค่าเฉลี่ยต่อหนึ่ง roll

- SPD: `2.3`
- ATK%, HP% และ EHR: `3.888`
- DEF%: `4.86`

User ยืนยัน 2026-09-18 ว่าค่าคงที่เหล่านี้คือค่าเฉลี่ยของ substat หนึ่ง roll

## `AtkRequirment()` / `HpRequirment()` / `DefRequirment()`

คำนวณ stat ปัจจุบันจาก base stat, stat% ใน `AType::None` และ flat stat หากยังต่ำกว่า `*Require` จะคำนวณจำนวน rolls ที่ต้องใช้ เพิ่มเปอร์เซ็นต์ที่จัดสรรจริงเข้า `Extra*` และ `Stats_type` ของตัวละคร รวมถึง memosprite ทุกตัว

HP% ของ memosprite ได้ค่าเปอร์เซ็นต์ `x` เต็มจำนวนเช่นเดียวกับ ATK%/DEF% เพราะ base HP ของ memosprite ถูกสเกลด้วย `Unit_Hp_Ratio` อยู่แล้ว

## `SpeedRequirment()`

คำนวณ SPD ปัจจุบันจาก base SPD + SPD% + flat SPD แล้วเติมส่วนที่ขาดด้วย flat SPD rolls ค่า `ExtraSpeed` เก็บ SPD ที่จัดสรรจริง ส่วน memosprite ได้ flat SPD ตาม `x × Unit_Speed_Ratio / 100`

## `EhrRequirment()`

หากมี `ApplyBaseChance` จะคำนวณ EHR ที่ต้องใช้เพื่อให้โอกาสติดสถานะหลังหัก `Enemy_effect_res` เท่ากับ 100% แล้วเปรียบเทียบกับ `EhrRequire` โดยเลือกเป้าหมายที่สูงกว่า จากนั้นหัก EHR ที่มีใน `AType::None` และเติมส่วนที่ขาดด้วย rolls

`Enemy_effect_res` เป็นค่า Effect RES กลางของศัตรูทั้งหมด ค่าเริ่มต้น `40`; Guinaifen E1 ลด global นี้ลง `10` โดยตั้งใจให้การลด Effect RES ส่งผลต่อ requirement EHR ของสมาชิกทั้งทีม (User ยืนยัน 2026-09-20)

เมื่อหลายเอฟเฟกต์กำหนด base chance ผ่าน `newApplyBaseChanceRequire(amount)` ระบบเก็บ base chance ที่ต่ำที่สุด เพราะเป็นเอฟเฟกต์ที่ต้องใช้ EHR สูงที่สุด การกัน EHR ตามค่านี้จึงครอบคลุมเอฟเฟกต์ที่มี base chance สูงกว่าด้วย (User ยืนยัน 2026-09-20)

แก้บั๊กวันที่ 2026-09-20: ค่าเริ่มต้น `ApplyBaseChance == 0` เคยทำให้ `newApplyBaseChanceRequire(amount)` ไม่สามารถกำหนดค่าครั้งแรกได้ เงื่อนไขปัจจุบันจึงรับ `amount` เมื่อค่ายังเป็น `0` หรือเมื่อ `amount` ต่ำกว่าค่าที่มีอยู่

EHR ที่จัดสรรจริงในครั้งนั้นถูกเพิ่มเข้า `ExtraEhr`, ตัวละคร และ memosprite ทุกตัว รายละเอียด field และประวัติการแก้สูตรดู [CharUnit.md](../../Class/Unit/CharUnit.md#requirement-stats--speedrequire--extraspeed)
