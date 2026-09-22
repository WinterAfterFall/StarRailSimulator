# Star Rail 系统 & โปรเจกต์นี้ — ภาพรวม

เอกสารนี้สรุปกติกาที่ simulator ใช้จริงจากโค้ด สำหรับลำดับ event และสูตรย่อยให้ตามลิงก์ไปคู่มือ engine; วิธีเริ่มโปรแกรมอยู่ใน [build-run-and-test.md](build-run-and-test.md) และข้อมูล kit ของตัวละครอยู่ใน [character-kit-reference](character-kit-reference/README.md)

## 1. จุดประสงค์ของโปรแกรม (Project purpose)

โปรแกรมนี้เป็น **battle damage simulator** สำหรับ Honkai: Star Rail — จุดประสงค์หลักคือจำลอง
สถานการณ์การต่อสู้เพื่อคำนวณดาเมจ ไม่ใช่การจำลองเกมให้ตรงกับข้อจำกัดของเกมจริงทุกกระเบียดนิ้ว

**ผลที่ตามมาสำคัญต่อการออกแบบเอนจิน**: เพราะเป้าหมายคือคำนวณดาเมจ ไม่ใช่ทำเกมจำลองที่ตรงกฎ 100%
ผู้ใช้ตั้งใจให้ระบบ **รองรับการใส่ตัวละคร/ศัตรูเกินขีดจำกัดของเกมจริงได้**:

- ทีมผู้เล่นเกมจริงจำกัดที่ 4 ตัว (+ memosprite) — แต่ในซิมนี้อาจใส่เกินกว่านั้นได้ถ้าต้องการทดสอบสถานการณ์สมมติ
- ศัตรูเกมจริงจำกัดที่ 5 ตัวต่อเวฟ — แต่ในซิมนี้อาจ spawn ศัตรูเกิน 5 ตัวได้เช่นกัน

ดังนั้นเวลาออกแบบ/รีวิวโค้ด engine อย่ายึดค่าคงที่ "4 ตัวละคร" หรือ "5 ศัตรู" เป็น hard cap ทางเทคนิค
เว้นแต่ผู้ใช้จะระบุไว้อย่างชัดเจนว่าต้องการจำกัดในกรณีนั้น ๆ

ข้อนี้เป็น **เป้าหมายการออกแบบ** ของ engine: ทางเข้า `Application.cpp` และ `ManualBuilder.cpp` ปัจจุบันยังผูก `Char1`–`Char4` กับสี่ช่องแรกโดยตรง และ `Application.cpp` มีตัวเลือกศัตรูที่ยังไม่ implement ครบ ดูข้อจำกัดการรันจริงใน [build-run-and-test.md](build-run-and-test.md)

### 1.1 หลักการออกแบบ: Determinism > Realism เวลาเจอ RNG

ผู้ใช้ให้ความสำคัญกับผลลัพธ์ที่ **ใช้อ้างอิงได้** ตัวเลขที่คำนวณต้องมีแนวโน้มเกิดขึ้นจริงและมีโอกาสเกิดสูง
แฟร์กับทุกตัวละคร และ **รันซ้ำกี่ครั้งต้องได้ผลลัพธ์เหมือนเดิมทุกครั้ง (deterministic)**

หลักปฏิบัติ: ทุกจุดในเกมจริงที่เป็น RNG หรือมีความยุ่งยากในการจำลอง (เช่นศัตรูสุ่มเลือกเป้าที่จะโจมตี)
ให้ **แปลงเป็นสถานการณ์ที่การันตีผลลัพธ์แทนการสุ่มจริง** โดยยอมเสียความสมจริงเชิงกลไกดิบเพื่อแลกกับ
ความสม่ำเสมอที่ตรวจสอบซ้ำได้

ตัวอย่างที่ผู้ใช้ยกมา: แทนที่จะสุ่มว่าศัตรูจะตีใครในทีมแบบสุ่มจริงในเกม ให้วัดเป็น **"โอกาสโดนตี" สะสม
ไปเรื่อย ๆ ตามเวลา** พอสะสมครบ 100% ให้ถือว่า "ในช่วงเวลาที่ผ่านมา ตัวละครนี้ควรโดนตี 1 ครั้งแล้ว"
แล้วให้โดนตี ณ ตอนนั้นทันที แม้ผลจะออกมาเป็นว่าหลายตัวโดนตีพร้อมกันในจังหวะเดียวกันก็ตาม
(ต่างจากเกมจริงที่สุ่มเลือกเป้าครั้งละ 1 คน) — นี่คือการแลกความสมจริงเพื่อความ deterministic

**ผลต่อการออกแบบ/รีวิวโค้ด engine**: เวลาเจอโค้ดที่ต้องตัดสินใจว่า "เหตุการณ์นี้ควรเกิดหรือยัง" ให้มองหา
รูปแบบ accumulate-until-threshold (สะสมโอกาส/ค่าไปเรื่อย ๆ จนถึงเกณฑ์แล้วการันตีว่าเกิด) แทนการเรียก
random number generator ตรง ๆ ถ้าเจอจุดที่ยังใช้ RNG ตรง ๆ อยู่ในโค้ด ควรตั้งคำถามว่าตรงกับหลักการนี้
หรือไม่ (อาจเป็นจุดที่ต้อง refactor ในอนาคต)

## 2. ระบบพื้นฐานของเกม (Core game systems)

### 2.1 Action Value / ลำดับการเล่น (turn order)

แต่ละยูนิตมี `atv` เป็นเวลาที่เหลือก่อนถึงเทิร์นและ `Max_atv = 10000 / effectiveSpeed` เป็นเวลาต่อรอบ โดย `effectiveSpeed = baseSpeed × (1 + speedPercent/100) + flatSpeed` `Find_turn()` เลือกยูนิตที่ `atv` ต่ำสุด; เมื่อเสมอกันใช้ `priority` ที่สูงกว่า `Atv_fix()` ลด `atv` ของยูนิตที่เดินเวลาได้ทุกตัวและเพิ่ม `Current_atv` แล้วจึงประมวลผลเทิร์น ถ้าเวลารวมเกิน `Wave[i]` จะจบ wave โดยไม่ให้ยูนิตนั้นออกท่า

`Action_forward()` ลด `atv` ตามเปอร์เซ็นต์ของ `Max_atv`; ถ้าถึงศูนย์จะกำหนด priority ใหม่ แอ็กชันที่ตั้ง `Turn_reset` และการโจมตีของศัตรูเรียก `resetTurn()` เพื่อตั้ง `atv` กลับเป็น `Max_atv` รายละเอียดการเปลี่ยน speed, การแทรกเทิร์น และ Aha ดู [Action_value.md](engine-reference/instructor/Function/Combat/Action_value.md) และ [Combat.md](engine-reference/instructor/Function/Combat/Combat.md)

### 2.2 Energy / Ultimate

พลังงานจากแอ็กชันใช้ `Increase_energy(ptr, E)` ซึ่งคูณ Energy Recharge; พลังงานคงที่หรือเปอร์เซ็นต์ของหลอดใช้ overload `(ptr, percent, flat)` ซึ่งไม่คูณ Energy Recharge ทั้งสองแบบ clamp ผลให้อยู่ในช่วง `0..Max_energy` และส่ง event ก่อนเปลี่ยนค่าหลอด

`ultUseCheck()` ตรวจว่ายูนิตยังอยู่ มีพลังงานถึง `Ult_cost` และผ่าน `ultCondition` ทุกข้อ **ก่อน** หัก cost จากนั้นคืนพลังงาน 5 ผ่าน overload ที่คูณ Energy Recharge แล้วส่ง `WhenUseUlt_List` จุดที่ engine เรียกตรวจอัลติอยู่ใน [Combat.md](engine-reference/instructor/Function/Combat/Combat.md); ความหมายของสอง overload และลำดับเต็มอยู่ใน [Energy.md](engine-reference/instructor/Function/Combat/Energy.md)

### 2.3 Damage formula

`Attack()` วน `damageSplit`: หนึ่งรายการมีเป้าหมาย, สเกล ATK/HP/DEF, ดาเมจฐานคงที่, สเกล Elation และค่าลด Toughness `calDamage()` รวมดาเมจฐานกับสเกล ATK/HP/DEF แล้วคูณ Crit, DMG%, DEF shred, RES PEN, Vulnerability, Mitigation, Multiplier increase และตัวคูณสถานะ Break ตามลำดับ ส่วน Elation, Break, DoT และ Super Break มีสูตรและ event ของตัวเอง ดู [CalDamage.md](engine-reference/instructor/Function/Calculate/CalDamage.md)

ดาเมจที่คำนวณแล้วถูกบันทึกแยกเป็นแบบใช้สถานะ Break ณ ตอนโจมตี กับแบบคูณสัดส่วนเวลาที่ศัตรูอยู่ในสถานะ Break ตอนสรุปผล เพื่อให้ดาเมจที่ไวต่อจังหวะมีค่าประมาณที่ใช้เทียบบิลด์ได้ ดู [CalDamageNote.md](engine-reference/instructor/Function/Calculate/CalDamageNote.md)

### 2.4 Buff / Debuff — กฎ duration ที่ sim ใช้

- กลไก (Buff_Stats.h): `extendBuffTime` ตั้ง `buffEnd[buff] = holder.turnCnt + duration`;
  `isBuffEnd` ยิงเมื่อ `holder.turnCnt == buffEnd` **และ** เป็นเทิร์นของ holder
  (เช็คใน After_turn)
- ผล: บัฟ **ลด duration ทุกครั้งที่จบเทิร์นของ holder** และบัฟที่ลงในเทิร์นของ holder เอง
  จะได้ครบ duration พอดี (เทิร์นที่กำลังดำเนินอยู่ไม่ถูกนับ) — นี่คือกติกามาตรฐาน
- สูตร: **`buffEnd = holder.turnCnt + duration`**
- **ข้อยกเว้น 2 ตัว — Ultimate ของ Bronya / Tingyun**: ult ถูกกดใน**เทิร์นของเป้าหมาย** (holder)
  ช่วง `PhaseStatus::BeforeTurn` — บัฟลงก่อน After_turn expiry ของเทิร์นนั้น ถ้าส่ง duration ตรง ๆ
  เทิร์นที่กำลังดำเนินอยู่จะถูกนับด้วย → over-count 1 เทิร์น
  fix: เมื่อ `onTargetTurn` ให้ส่ง `duration − 1` (Tingyun Rejoicing ส่ง 1 แทน 2)
  *เฉพาะการปรับ duration ตอนกดในเทิร์นเป้าหมายเท่านั้น — กฎ "ลด duration ทุกจบเทิร์น" ทำงานปกติ*
- ใช้เฉพาะบัฟที่ระบุระยะเป็น **"X เทิร์น"**
- บัฟอีกประเภทที่ระบุเป็น **stack / "ลด 1 เทิร์นตอนเริ่มเทิร์นของ <caster>"** (ไม่บอกเทิร์นจบตรง ๆ) →
  ใช้สูตรเดียวกัน `buffEnd = holder.turnCnt + duration` ต่างกันแค่ tick ตอน `Before_turn` แทน
  `After_turn` แต่ isBuffEnd เทียบ turnCnt เท่ากัน + ยิงเฉพาะเทิร์นเจ้าของ → หมดอายุเทิร์นเดียวกัน
  ตัวอย่าง: Ruan Mei Skill/Ult, Robin Skill, Tribbie Skill/Ult/A2
  (ยืนยันในโค้ด Ruan_Mei.h: `isHaveToAddBuff(ptr,"Mei_Skill",3)` + `Before_turn_List` isBuffEnd)
- buff/debuff ทั้งหมดในเอนจินเก็บเป็น raw +/- stat delta (ดู memory: buff drift debugging)

### 2.5 SP & Energy — จุดที่ไม่ fix

- ค่า default: Basic ATK +1 SP, Skill −1 SP — แต่ **ไม่ใช่ทุกตัว** (บางตัว Basic ไม่ให้ SP,
  Skill ไม่กิน SP, หรือให้/กินมากกว่า 1)
- Energy ต่อ action **ไม่ fix** — กำหนดต่อท่าต่อตัวละคร
- **Fixed Energy**: Energy บางก้อนจากความสามารถเฉพาะเป็นค่าคงที่ **คูณ ERR ไม่ได้** —
  ต่างจาก Energy ปกติที่คูณ ERR; sim ต้องแยกสองประเภท

### 2.6 Path & Element (สองแกนของตัวละคร)

- ตัวละครทุกตัวมี Path 1 อัน (บทบาท) + Combat Type/Element 1 อัน (ชนิดดาเมจ) เป็นอิสระต่อกัน
- รายละเอียดเต็มดู docs/hsr-system-reference.md §6 (Path), §7 (Element)

### 2.7 Relic ในซิม (Head/Hands + substats)

- **Head = flat HP, Hands = flat ATK** (main stat ตายตัวในเกมจริง) → ในโค้ดใส่ไว้ใน Reset stats
  ของตัวละคร ไม่ใช่ระบบ relic แยก
- **Substats**: sim ไม่สุ่ม 4 substat แบบเกมจริง แต่ให้ **baseline อย่างละ 2 roll ทุกประเภท**
  แล้วมี **roll อิสระอีก x จำนวน** ที่ตัว reroll-optimizer เลือกกระจายลงประเภทไหนก็ได้เพื่อหา max damage
  (โค้ด: `Substats` = vector ของ `pair<Stats,int>` โดย `.second` = จำนวน roll; `Substats_Reset.h` `Set_Stats()`)
- ค่าต่อ roll ที่ sim ใช้ = **ค่า mid roll** ของ 5★: CR 2.9, CD 5.8, ATK%/HP% 3.888, DEF% 4.86,
  Break Effect 5.8, SPD 2.3
- deterministic: ผู้ใช้/optimizer กำหนดการกระจาย roll เอง ไม่มีการสุ่มจริง

## 3. ขอบเขต & ข้อจำกัดของการจำลอง (Scope / assumptions)

- **ไม่บังคับ Light Cone ให้ตรง Path** — sim เป็นเครื่องมือคำนวณ/เทียบ/ทดสอบ ใส่ LC ข้าม Path ได้
  (ในเกมจริง LC ที่ไม่ตรง Path จะได้แค่ค่าสแตตพื้นฐาน ไม่ได้ passive — sim ไม่ต้อง enforce ตรงนี้
  เว้นแต่ผู้ใช้ระบุ)
- **การจัดทีมเป็นหน้าที่ของผู้ใช้ทั้งหมด** — sim ไม่ต้องแนะนำ/สร้าง/ตรวจสอบทีม ผู้ใช้เลือกเอง
