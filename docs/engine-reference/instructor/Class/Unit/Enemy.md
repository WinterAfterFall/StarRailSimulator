# `src/Defination/Class/Unit/Enemy.h`

## การตรวจสถานะ debuff — `debuffCheck`

user เปลี่ยนชื่อ field จาก `Debuff` เป็น `debuffCheck` แล้ว (ตรวจ `Enemy.h` ยืนยัน 2026-09-15)

- `debuffCheck` (`unordered_map<string,int>`) — ใช้เช็กว่า debuff ตามชื่อนั้นยังอยู่หรือไม่ (user ยืนยัน)
- `stack` (`unordered_map<string,int>`) — เก็บจำนวนสแต็กแยกตามชื่อ (user ยืนยัน 2026-09-15)
- `debuffEnd` — เก็บเลขเทิร์นหมดอายุตามชื่อ debuff: `extendDebuff` ตั้งเป็น `turnCnt + Turn_extend`; `isDebuffEnd` ตรวจเลขเทิร์นตรงกันและเป็นเทิร์นของศัตรูตัวนั้น (ตรวจ `Debuff_Stats.h` 2026-09-15)
- ยังไม่ได้ยืนยันความหมายของค่า `int` แต่ละค่าของ `debuffCheck` หรือรายละเอียดของ `Total_debuff`

### `debuffNote` — ปริมาณเอฟเฟกต์เดิมของ debuff

user อธิบาย (2026-09-15): debuff บางอย่างต้องบันทึกปริมาณเอฟเฟกต์ที่ลงไว้ เพื่อใช้คำนวณส่วนต่างเมื่ออัปเดตเอฟเฟกต์

ตัวอย่างเชิงแนวคิด: debuff ลด DEF ตาม ATK ของผู้ร่าย เมื่อ ATK ผู้ร่ายเปลี่ยน ต้องดูปริมาณลด DEF เดิมจาก `debuffNote` แล้วเทียบกับปริมาณใหม่ เพื่อทราบว่าต้องปรับเพิ่มอีกเท่าไร ตัวอย่างนี้อธิบายหลักการ ยังไม่ได้ระบุว่าเป็นสกิลของตัวละครใดในโค้ด

## `BreakSideEffect`

- `ptr` (`AllyUnit*`) — ชี้ไปยังยูนิตที่เป็นคนทำ Break (user ยืนยัน 2026-09-15)

- `countdown` — เก็บเลขเทิร์นของศัตรูที่สถานะจะหมดอายุ เช่น `turnCnt + 2` คือหมดอายุอีก 2 เทิร์น ไม่ใช่ค่าที่ลดถอยหลัง (user ยืนยัน 2026-09-15)

- `stack` — เก็บจำนวนชั้นของสถานะจาก Break เช่น Wind Shear และ Entanglement (user ยืนยัน 2026-09-15)

- `type` — ระบุชนิดสถานะจาก Break ได้แก่ Bleed, Burn, Freeze, Shock, Wind Shear, Entanglement และ Imprisonment (user ยืนยัน 2026-09-15)

อธิบายความหมายของ field ทั้ง 4 ตัวแล้ว ยังไม่ได้ไล่รายละเอียดการทำงานของคลาสครบ

## Damage Record

ตรวจโค้ดตามคำขอ user (2026-09-15): ระหว่างต่อสู้บันทึกดาเมจไว้ฝั่ง `CharUnit` ส่วน field ทั้งสามของ `Enemy` ถูกสะสมตอน `printSummaryResult()` ใน `Function/Print/Print.h`:

- `avgDmgRecord` — รวม `AvgDmgRecord[j].maxDmgRecord` ของตัวละครทุกตัวสำหรับศัตรูตัวนี้
- `totalDmgRecord` — รวมยอดจาก `maxRealTimeDmg` และ `maxNonRealTimeDmg` ตามศัตรูผู้รับ (`recv`)
- `dmgRecordEachType` — รวมยอดแยกตามชื่อที่ใช้บันทึกดาเมจ จากสมุดสองชุดเดียวกัน

### ที่มาของค่าเฉลี่ย

กลไกอยู่ใน [CalDamageNote.md](../../Function/Calculate/CalDamageNote.md) และโค้ด `Function/Calculate/CalDamageNote.h`:

1. `Cal_DamageNote` สะสมดาเมจในสมุดของตัวละคร
2. หลัง attack action ที่เปิด `damageNote`, `Combat.h` เรียก `Cal_AverageDamage` โดยเริ่มเก็บเมื่อ `Current_atv >= 300`
3. สำหรับเป้าหมายในรายการ คำนวณดาเมจสะสม ณ ตอนนั้น (`rec`) โดยปรับส่วน non-real-time ด้วยตัวคูณ toughness เฉลี่ยของ `src` แล้วเก็บ `rec / Current_atv`
4. ถ้ายังไม่ถึง 20 ATV จากจุดเพิ่มตัวอย่างล่าสุด จะเขียนทับตัวอย่างล่าสุด; เมื่อถึงแล้วจึงเพิ่มตัวอย่างใหม่ ไม่ใช่เก็บทุก hit เป็นตัวอย่างแยก
5. ตอนจบ run, `Cal_DamageSummary` เฉลี่ยตัวอย่างเหล่านี้เป็น `currentDmgRecord`; `changeMaxDamage` เก็บค่าของ run ที่ดีกว่าเป็น `maxDmgRecord`

ดังนั้น `avgDmgRecord` ฝั่งศัตรูเป็นผลรวมค่าเฉลี่ยของตัวอย่างดาเมจสะสมต่อ ATV จากผลที่เก็บไว้ของตัวละคร ไม่ใช่ดาเมจเฉลี่ยต่อจำนวนครั้งที่โจมตี
