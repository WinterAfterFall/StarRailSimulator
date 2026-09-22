# `src/Defination/Class/Unit/Enemy.h`

## การตรวจสถานะ debuff — `debuffCheck`

user เปลี่ยนชื่อ field จาก `Debuff` เป็น `debuffCheck` แล้ว (ตรวจ `Enemy.h` ยืนยัน 2026-09-15)

- `debuffCheck` (`unordered_map<string,int>`) — ใช้เช็กว่า debuff ตามชื่อนั้นยังอยู่หรือไม่ (user ยืนยัน)
- `stack` (`unordered_map<string,int>`) — เก็บจำนวนสแต็กแยกตามชื่อ (user ยืนยัน 2026-09-15)
- `debuffEnd` — เก็บเลขเทิร์นหมดอายุตามชื่อ debuff: `extendDebuff` ตั้งเป็น `turnCnt + Turn_extend`; `isDebuffEnd` ตรวจเลขเทิร์นตรงกันและเป็นเทิร์นของศัตรูตัวนั้น (ตรวจ `Debuff_Stats.h` 2026-09-15)
- ค่า `int` ของ `debuffCheck` ใช้เป็น flag `0`/`1` เท่านั้น (ตรวจทุกจุดที่เรียก `setDebuff` ใน `src/` 2026-09-16 — ไม่มีที่ไหนเขียนค่าอื่น) จำนวนสแต็กอยู่ใน `stack` แยกต่างหาก

### `Total_debuff` — จำนวนสถานะ debuff

user ยืนยัน (2026-09-16): นับจำนวนสถานะ debuff บนศัตรู รวมสถานะจาก Break โดยไม่ได้นับตามจำนวนสแต็ก

- ตัวอย่าง: ลด DEF 1 สถานะ + Wind Shear 3 สแต็ก → `Total_debuff = 2`
- หลักการนับนี้เป็นความหมายที่ user ยืนยัน ยังไม่ได้ตรวจความถูกต้องของทุกจุดที่เพิ่ม/ลดตัวนับ

### `debuffNote` — ปริมาณเอฟเฟกต์เดิมของ debuff

user อธิบาย (2026-09-15): debuff บางอย่างต้องบันทึกปริมาณเอฟเฟกต์ที่ลงไว้ เพื่อใช้คำนวณส่วนต่างเมื่ออัปเดตเอฟเฟกต์

ตัวอย่างเชิงแนวคิด: debuff ลด DEF ตาม ATK ของผู้ร่าย เมื่อ ATK ผู้ร่ายเปลี่ยน ต้องดูปริมาณลด DEF เดิมจาก `debuffNote` แล้วเทียบกับปริมาณใหม่ เพื่อทราบว่าต้องปรับเพิ่มอีกเท่าไร ตัวอย่างนี้อธิบายหลักการ ยังไม่ได้ระบุว่าเป็นสกิลของตัวละครใดในโค้ด

## พลังโจมตีและโบนัสดาเมจของศัตรู

user ยืนยัน (2026-09-16):

- `ATK` — พลังโจมตีตั้งต้น ค่าเริ่มต้น `718`
- `atkPercent` — เปอร์เซ็นต์เพิ่ม/ลด ATK ค่าเริ่มต้น `0`; เช่น `-20` คือ ATK ลด 20%
- `dmgPercent` — เปอร์เซ็นต์เพิ่ม/ลดดาเมจที่ศัตรูสร้าง แยกจาก ATK ค่าเริ่มต้น `0`

ตรวจ `Function/Calculate/CalDmgReceive.h`: `calEnemyATK` คำนวณ `ATK * (1 + atkPercent / 100)` และ `calEnemyDMG` คำนวณตัวคูณ `1 + dmgPercent / 100` โดยทั้งสองฟังก์ชันจำกัดผลลัพธ์ต่ำสุดไว้ที่ `0`

## Toughness — ความทนทานของศัตรู

user ยืนยัน (2026-09-16):

- `Max_toughness` — ความทนทานสูงสุดของศัตรู
- `Current_toughness` — ความทนทานที่เหลือปัจจุบัน
- `Toughness_status` — `1` คือยังไม่อยู่ในสถานะ Weakness Break; `0` คืออยู่ในสถานะ Weakness Break

- `toughnessAvgMultiplier` — ตัวคูณดาเมจเฉลี่ยถ่วงตามเวลา ATV: ช่วงยังไม่ Break ใช้ `0.9` และช่วงอยู่ในสถานะ Break ใช้ `1.0` เช่น อยู่แต่ละสถานะอย่างละครึ่งเวลาจะได้ `0.95`; นำไปใช้กับดาเมจในสมุด non-real-time (user ยืนยันว่าตรงกับที่ตั้งใจไว้ 2026-09-16)

กลไกคำนวณดู [CalDamageNote.md](../../Function/Calculate/CalDamageNote.md)

## `Target_type` — ตำแหน่งเทียบกับเป้าหมายหลัก

user ยืนยัน (2026-09-16): ใช้ `EnemyType` แบ่งศัตรูตามตำแหน่งเทียบกับเป้าหมายหลัก

- `Main` — เป้าหมายหลัก
- `Adjacent` — ศัตรูข้างเป้าหมายหลัก
- `Other` — ศัตรูตัวอื่น

## `AttackCoolDown` — โอกาสโดนโจมตีสะสม

user ยืนยัน (2026-09-16): ตั้งใจใช้การสะสมโอกาสโดนโจมตีแทนการสุ่มเป้าหมาย

- เก็บค่าแยกตามชื่อยูนิตฝ่ายเรา (`unordered_map<string,double>`)
- ในการโจมตีปกติของศัตรู เพิ่มค่าจาก `calHitChance` ให้ยูนิตที่พิจารณาเป็นเป้าหมาย
- เมื่อสะสมถึง `100` ยูนิตนั้นจะโดนโจมตี แล้วหักออก `100` โดยเก็บเศษไว้
- ตัวอย่าง: โอกาสโดนตีคงที่ `25%` เริ่มสะสมจาก `0` จะโดนจริงทุก 4 ครั้งที่ศัตรูโจมตีปกติ

ตรวจการทำงานใน `Class/ActionData/EnemyActionData.h` (`setBaAttack`); `Function/Setup/Stats_Reset.h` รีเซ็ตค่าที่สะสมเป็น `0`

## `AoeCharge` — ตัวนับแอ็กชันสำหรับรอบโจมตี AoE

user ยืนยัน (2026-09-16): นับจำนวนแอ็กชันโจมตีของศัตรู โดยเพิ่ม `1` ก่อนเลือกโจมตีปกติหรือ AoE; หากหนึ่งเทิร์นมีหลายแอ็กชัน จะเพิ่มทุกแอ็กชัน

- `SetupEnemy` เลือก AoE เมื่อ `AoeCoolDown != 0`, `AOEskillRatio != 0` และ `AoeCharge % AoeCoolDown == AoeStart`; นอกนั้นเลือกโจมตีปกติ
- ตัวอย่าง: cooldown `3`, start `0` จะใช้ AoE ในแอ็กชันที่ `3, 6, 9, ...` เมื่อเปิดใช้ AoE ไว้
- ค่าเริ่มต้นและค่าหลังรีเซ็ตเป็น `0`

กลไกอยู่ใน `Function/Setup/SetEnemy.h`; การรีเซ็ตอยู่ใน `Function/Setup/Stats_Reset.h`

## `tauntList` — รายการยูนิตที่ยั่วยุศัตรูตัวนี้

user ยืนยัน (2026-09-16): เก็บยูนิตฝ่ายเราที่ใช้ยั่วยุศัตรูตัวนี้เป็น `AllyUnit*`

- ถ้ารายการมีสมาชิก การโจมตีปกติจะพิจารณาเป้าหมายจากรายการนี้ โดยกรองยูนิต Backup และยูนิตที่เป็นเป้าหมายไม่ได้ออก
- หากมีหลายตัว ใช้ `calHitChance` และ `AttackCoolDown` ภายในกลุ่มนั้น
- การโจมตี AoE ยังโจมตีทุกยูนิตที่เป็นเป้าหมายได้ตามเดิม

ตรวจเส้นทางเลือกเป้าหมายใน `Class/ActionData/EnemyActionData.h`

## `toughnessReduceNote` — ค่าลดความทนทานสะสมสำหรับ Super Break

user ยืนยัน (2026-09-16): เป็นที่พักค่าลดความทนทานรวมต่อเป้าหมายสำหรับคำนวณ Super Break

ใน `Superbreak_trigger` (`Function/Combat/Combat.h`) สะสม `toughnessReduce` จากแต่ละส่วนของ `act->damageSplit` แยกตามศัตรู แล้วนำยอดรวมไปปรับด้วย `Cal_Total_Toughness_Reduce` เพื่อคำนวณ Super Break

## `hitCount` — ตัวนับ hit ที่ศัตรูได้รับ

user แก้ไขข้อสรุปเดิม (2026-09-16): `hitCount` มีการใช้งาน ไม่ใช่ dead code

ตรวจ `Attack()` ใน `Function/Combat/Combat.h`: รีเซ็ต `hitCount` ของเป้าหมายเป็น `0` ตอนเริ่มการโจมตี แล้วเพิ่ม `each2.target->hitCount++` ตามรายการเป้าหมายในแต่ละส่วนของ `damageSplit` ส่วนรายละเอียดการนำค่าฝั่ง Enemy ไปอ่านยังไม่ได้ไล่ครบ

## `nextToLeft` / `nextToRight` — ศัตรูข้างเคียง

user ยืนยัน (2026-09-16): ชี้ไปยังศัตรูที่ติดกันทางซ้าย/ขวาของศัตรูตัวนี้; หากไม่มีจะเป็น `nullptr` บางตัวละครมีสกิลที่จำเป็นต้องรู้ศัตรูซ้ายขวา เช่น ดาเมจกระจายของ Black Swan

## รายการสถานะจาก Break

user ยืนยันเจตนาการแยกรายการ (2026-09-16):

- `breakDotList` — Bleed, Burn, Shock และ Wind Shear
- `breakImsList` — Imprisonment
- `breakEngList` — Entanglement
- `breakFrzList` — Freeze

แต่ละรายการเก็บ `BreakSideEffect`; การยืนยันนี้เป็นความหมายของรายการ ยังไม่ได้ตรวจความถูกต้องของเส้นทางเพิ่ม/ลบทั้งหมด

### `addBreakSEList` — เพิ่มหรืออัปเดตสถานะตามผู้ทำ Break

user ยืนยัน (2026-09-16): คนเดิมทำ Break ซ้ำให้อัปเดตสถานะเดิม ส่วนคนละคนให้เก็บแยกกัน

- โค้ดค้นหาในรายการของกลุ่มสถานะนั้น โดยเทียบชื่อผู้ทำ Break ผ่าน `isSameName`
- เมื่อพบรายการเดิม อัปเดต `countdown` เป็นค่าใหม่
- สำหรับกลุ่ม DoT บวก `input.stack` เพิ่มให้รายการเดิมด้วย

**ค่าที่ส่งกลับ** (ตรวจโค้ด 2026-09-16): `true` = เพิ่งเพิ่มรายการใหม่ · `false` = มีรายการของคนทำ Break คนนี้อยู่แล้ว จึงแค่ต่ออายุให้

มีผู้เรียกที่ใช้ค่านี้จริงอยู่จุดเดียวคือแขนง Imaginary ใน `Break_trigger` (`Function/Combat/Combat.h:372`):

```cpp
if(target->addBreakSEList(BreakSideEffect(BreakSEType::Imprisonment,data_2->Attacker,target->Atv_stats->turnCnt + 1)))
target->speedBuff({Stats::SPD_P,AType::None,-10});
```

คือลด SPD 10% **เฉพาะตอน Imprisonment เป็นของใหม่** ถ้าเป็นการ Break ซ้ำโดยคนเดิมที่แค่ต่ออายุจะไม่ลดซ้ำ ซึ่งจำเป็นเพราะบัฟในเอนจินนี้เป็นค่าบวก/ลบดิบ ถ้าลดซ้ำทุกครั้งแต่คืนค่าครั้งเดียวตอนหมดอายุ (`Function/Event/Event.h:69` `debuffSingle(target,{{Stats::SPD_P,AType::None,10}})`) SPD ของศัตรูจะไหลลงเรื่อย ๆ

อีก 6 จุดที่เรียก (`Combat.h:342,347,352,357,362,367` — Bleed/Burn/Freeze/Shock/Wind Shear/Entanglement) ทิ้งค่าที่ส่งกลับไป เพราะไม่มีผลข้างเคียงที่ต้องแปะครั้งแรกครั้งเดียว

ยังไม่ได้ตรวจความถูกต้องของทุกเส้นทางใน method

แก้บั๊กตามคำขอ user (2026-09-16): ย้าย `breakDotList.push_back` และการเพิ่มตัวนับ DoT เข้าแขนง DoT เพื่อไม่ให้ Freeze / Imprisonment / Entanglement ที่เพิ่มใหม่ถูกใส่ในรายการ DoT และเพิ่ม `DotCount` ด้วย โดยยังคงคืน `true` เมื่อเพิ่มใหม่ และ `false` เมื่ออัปเดตรายการเดิม

## กลุ่ม Weakness — ธาตุที่ศัตรูอ่อนแอ

ตรวจโค้ด 2026-09-16 (ยังไม่ได้ให้ user ยืนยันเจตนา)

| field | ชนิด | หน้าที่ |
|---|---|---|
| `Default_Weakness_type` | `map<ElementType,bool>` | ธาตุอ่อนแอ **ติดตัว** ของศัตรู ตั้งครั้งเดียวตอนสร้าง ไม่เปลี่ยนระหว่าง run |
| `Weakness_type` | `map<ElementType,bool>` | ธาตุอ่อนแอ **ปัจจุบัน** = ของติดตัว + ที่ตัวละครยัดเพิ่มเข้าไป |
| `Weakness_typeCountdown` | `map<ElementType,int>` | เลขเทิร์นของศัตรูที่ธาตุอ่อนแอ *ที่ถูกยัดเพิ่ม* จะหมดอายุ (convention เดียวกับ `debuffEnd`) |
| `DefaultElementRes` | `map<ElementType,double>` | ค่า RES ตั้งต้นแยกตามธาตุ |
| `defaultWeaknessElementAmount` | `int` | จำนวนธาตุอ่อนแอติดตัว นับตอนสร้าง |
| `currentWeaknessElementAmount` | `int` | จำนวนธาตุอ่อนแอปัจจุบัน |

### เส้นทางการทำงาน

**ตอนสร้างศัตรู** — `SetupEnemy` (`Function/Setup/SetEnemy.h:58-71`) คัดลอก `Enemy_weak` ลงทั้ง `Weakness_type` และ `Default_Weakness_type` พร้อมนับจำนวนที่เป็น `1` เก็บใน `defaultWeaknessElementAmount` แล้วคัดลอก `Enemy_res` ลง `DefaultElementRes`

**ตอนยัดธาตุอ่อนแอเพิ่ม** — `weaknessApply` (`Function/Combat/Debuff_Stats.h:103,122`): ถ้าธาตุนั้นยังไม่อ่อนแอ จะตั้ง `Weakness_type = 1` และ `currentWeaknessElementAmount++` จากนั้นตั้ง `Weakness_typeCountdown[ธาตุ]` เป็น `turnCnt + extend` โดย**เลือกค่าที่มากกว่า**ของเดิมกับของใหม่ (ต่ออายุได้ แต่ไม่ตัดอายุให้สั้นลง)

`chooseWeakness` (`Debuff_Stats.h:78-101`) เป็นตัวเลือกว่าจะยัดธาตุไหน โดยข้ามธาตุที่อ่อนแออยู่แล้ว แล้วเรียงลำดับความสำคัญตาม Path ของตัวละครในทีม (Harmony > Abundance > Preservation > Nihility > ที่เหลือ) ถ้าไม่มีธาตุไหนให้เลือกเลยจะย้อนไปเลือกจากธาตุที่กำลังจะหมดอายุก่อน

**ตอนหมดอายุ** — `allEventAfterTurn` (`Function/Event/Event.h:72-77`) วน `Weakness_typeCountdown` ทุกธาตุ ถ้าเลขตรงกับ `turnCnt` ของเทิร์นนี้ **และ** `Default_Weakness_type` ของธาตุนั้นเป็น `0` จะคืน `Weakness_type = 0` และ `currentWeaknessElementAmount--`

> เงื่อนไข `Default_Weakness_type == 0` คือสิ่งที่กันไม่ให้ธาตุอ่อนแอติดตัวหลุดหายไปตอนธาตุที่ยัดเพิ่มหมดอายุ

**ตอนรีเซ็ตต่อ run** — `Stats_Reset.h:150-152,181-191` คืน `Weakness_type` กลับเป็น `Default_Weakness_type`, ตั้ง `Weakness_typeCountdown` ทุกช่องเป็น `0`, ตั้ง `currentWeaknessElementAmount = defaultWeaknessElementAmount` และเขียน `DefaultElementRes` กลับเข้า `Stats_each_element[RESPEN]` เป็นค่าติดลบทั้ง 7 ธาตุ

ตรวจแล้วว่า `Weakness_typeCountdown` ที่ถูกรีเซ็ตเป็น `0` ไม่ทำให้เกิดการหมดอายุผิดพลาด เพราะ `turnCnt` ถูก `++` ตั้งแต่ต้นเทิร์น (`Function/Combat/Combat.h:11`) ก่อนที่ `allEventAfterTurn` จะรัน ค่าที่ตรวจจึงเริ่มที่ `1` เสมอ ไม่มีวันตรงกับ `0`

### ใครอ่านค่าเหล่านี้

- `Cal_Toughness_reduction` (`Function/Calculate/CalDamage.h:185-186`) — ถ้าธาตุที่ตีไม่ตรงกับ `Weakness_type` และ toughness ยังไม่หมด จะไม่ลด toughness เลย ยกเว้นแอ็กชันที่ตั้ง `Dont_care_weakness` ไว้ ซึ่งจะลดได้ตามสัดส่วนเปอร์เซ็นต์ที่ระบุ
- `currentWeaknessElementAmount` — Anaxa A6 (`Data/Character/Erudition/Anaxa.h:59,61,174,200,202,251,253`) ใช้คูณ 4 เป็นปริมาณ debuff และเช็กเงื่อนไข `>= 5`
- `Default_Weakness_type` — Silver Wolf (`Data/Character/Nihility/Silver Wolf.h:52`) ใช้ข้ามธาตุที่ศัตรูอ่อนแอติดตัวอยู่แล้ว

## เวลาที่ศัตรูอยู่ในสถานะ Break

ตรวจโค้ด 2026-09-16 (ยังไม่ได้ให้ user ยืนยันเจตนา)

- `when_toughness_broken` — `Current_atv` ณ ตอนที่ศัตรู Break ล่าสุด ตั้งค่าใน `Cal_Toughness_reduction` (`Function/Calculate/CalDamage.h:199`)
- `Total_toughness_broken_time` — เวลา ATV **สะสม** ที่ศัตรูตัวนี้อยู่ในสถานะ Break ตลอด run

ตอนเทิร์นของศัตรูเริ่มและพบว่า `Toughness_status == 0` (`Function/Setup/SetEnemy.h:42-46`) จะฟื้นจาก Break คือคืน `Toughness_status = 1`, เติม `Current_toughness` เต็ม แล้วบวก `Current_atv - when_toughness_broken` เข้า `Total_toughness_broken_time`

สองตัวนี้คือวัตถุดิบของ `toughnessAvgMultiplier` — `CalDamageNote.h:65,67` เฉลี่ยตัวคูณ `1.0` (ช่วง Break) กับ `0.9` (ช่วงยังไม่ Break) ถ่วงตามสัดส่วนเวลาใน `Total_atv` โดยบรรทัด 65 ใช้ตอนศัตรูยัง Break ค้างอยู่ จึงบวกช่วงที่ยังไม่ปิด (`Total_atv - when_toughness_broken`) เข้าไปด้วย ส่วนบรรทัด 67 ใช้ตอนไม่ได้ Break อยู่

รีเซ็ตทั้งคู่เป็น `0` ที่ `Function/Setup/SetCombat.h:132-133` และ `Function/Setup/Stats_Reset.h:168-169`

## ตัวนับ DoT

user ยืนยัน (2026-09-16): นับจำนวนสถานะ DoT จากทั้งสกิลและ Break โดยไม่ได้นับจำนวนสแต็ก

- `ShockCount` / `WindSheerCount` / `BleedCount` / `BurnCount` — จำนวนสถานะ DoT แยกตามประเภท
- `DotCount` — จำนวนสถานะ DoT รวม
- สถานะแบบสะสมสแต็กหนึ่งอันนับเป็น `1` DoT ต่อให้มี `50` สแต็กก็ตาม
- ตัวอย่าง: Wind Shear จากสกิล 5 สแต็ก + Wind Shear จาก Break 3 สแต็ก → `WindSheerCount = 2`

### Methods ปรับตัวนับ DoT

user ยืนยัน (2026-09-16):

- `changeShock` / `changeWindSheer` / `changeBleed` / `changeBurn` เพิ่มหรือลดตัวนับประเภทนั้นและ `DotCount` พร้อมกันตามค่า `amount`
- `changeDotType` เลือกเรียก method ตามประเภท DoT ที่ส่งมา
- ตัวอย่าง: `changeShock(-1)` คือเอาสถานะ Shock ออกหนึ่งอัน ทำให้ `ShockCount` และ `DotCount` ลดลงอย่างละ `1`

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

## get/set/add ของสถานะดีบัฟ (บรรทัด 166–206)

ทุกตัวเป็น one-liner อ่าน/เขียน map หรือ field ตรง ๆ โดยใช้ **ชื่อดีบัฟเป็น key** — โครงเดียวกับฝั่ง ally ใน [CharUnit.md](CharUnit.md)

| get | set | add | ที่เก็บจริง |
|---|---|---|---|
| `getTotalDebuff()` | `setTotalDebuff(v)` | `addTotalDebuff(v)` | `Total_debuff` (int ตัวเดียว) |
| `getDebuff(name)` | `setDebuff(name, v)` | — | `debuffCheck` |
| `getDebuffNote(name)` | `setDebuffNote(name, v)` | — | `debuffNote` |
| `getStack(name)` | `setStack(name, v)` | `addStack(name, v)` | `stack` |
| `getDebuffTimeCount(name)` | `setDebuffTimeCount(name, v)` | — | **`debuffEnd`** |

⚠️ จุดที่ต้องระวัง:

- **`getDebuffTimeCount` / `setDebuffTimeCount` แตะ `debuffEnd`** ซึ่งเก็บ "เทิร์นที่หมดอายุ" = `turnCnt ของศัตรูตัวนี้ + duration` **ไม่ใช่จำนวนเทิร์นที่เหลือ** ทางที่ควรใช้คือ `extendDebuff()` ใน [Debuff_Stats.md](../../Function/Combat/Debuff_Stats.md)
- **`addStack()` มีพื้นที่ 0 ในตัวเอง** (ตัดค่าติดลบทิ้ง) แต่ **ไม่มีเพดาน** — เพดาน `StackLimit` อยู่ที่ `calDebuffStack()` ใน [DebuffStack.md](../../Function/Combat/DebuffStack.md) เรียก `addStack()` ตรง ๆ จึงข้ามทั้งเพดาน ทั้ง event และทั้งการนับ `Total_debuff`
- **`addTotalDebuff()` ไม่มี clamp เลย** ติดลบได้ถ้าถอนเกินจำนวนที่ลง — เป็นเหตุผลว่าทำไมกติกา "นับตอนเปลี่ยนผ่าน 0 ↔ บวก" ถึงต้องรัดกุม (ดู BUGS #22)
- ทุกตัวที่รับ `name` ใช้ `operator[]` → **อ่านชื่อที่ไม่เคยมีจะสร้าง entry ใหม่ค่า 0 ทิ้งไว้** สะกดชื่อผิดจึงเงียบสนิท ไม่พัง
- `getDebuff()` คืน `int` ไม่ใช่ `bool` แม้จะใช้เป็นธงเปิด/ปิด
