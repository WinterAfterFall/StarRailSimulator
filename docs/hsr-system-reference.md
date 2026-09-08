# Honkai: Star Rail — คู่มืออ้างอิงระบบเกมเชิงลึก

เอกสารอ้างอิงรวมกลไกหลักของ Honkai: Star Rail (HSR) สำหรับใช้เป็น context ให้ LLM หรือใช้อ้างอิงในการวางแผนทีม
ข้อมูล ณ กันยายน 2026 (เกมอยู่ที่ Version 4.5 "To Roll the Stars in Astropolis")
รายการแหล่งที่มาทั้งหมดอยู่ในภาคผนวกท้ายเอกสาร

---

## 1. ระบบเกมพื้นฐาน

HSR เป็นเกม turn-based RPG แบบ gacha ของ HoYoverse ระบบต่อสู้วางบนสามเสาหลัก: Skill Point (SP) economy, Weakness Break / Toughness และ Action Value (AV) turn order [S17][S13]

### 1.1 โครงสร้างการต่อสู้

- ทีมสูงสุด 4 ตัวละคร (+ memosprite ได้อีก 1 ช่อง)
- การกระทำหลัก: Basic ATK, Skill, Ultimate
- Ultimate ไม่กินเทิร์น แต่ให้ "Extra Turn" ทันทีเมื่อกดใช้ [S1]
- Ultimate คืน Energy 5 หน่วยหลังใช้ [S1]

### 1.2 Skill Point (SP)

- SP เป็นทรัพยากรที่ใช้ร่วมกันทั้งทีม เพดานปกติ 5 แต้ม
- ค่า default: Basic ATK +1 SP, Skill -1 SP
- **ไม่ใช่ทุกตัว**: มีตัวละครที่ Basic ไม่ให้ SP / Skill ไม่กิน SP / ให้-กินมากกว่า 1 ตาม kit
- การบริหาร SP คือครึ่งหนึ่งของการเล่น HSR [S17][S16]

### 1.3 Energy (พลังงาน Ultimate)

| การกระทำ | Energy โดยประมาณ (ค่าอ้างอิงคร่าว ๆ) |
|---|---|
| Basic ATK | ~20 |
| Skill | ~30 |
| Ultimate (คืนหลังใช้) | 5 |
| Follow-up ATK | 5–10 |
| ถูกโจมตี / สังหารศัตรู | มีค่าตามกรณี |

- ค่า Energy ต่อ action **ไม่ fix** — กำหนดต่อท่าต่อตัวละคร ตารางข้างบนเป็นค่าอ้างอิงเท่านั้น
- Energy ปกติ **คูณด้วย Energy Regeneration Rate** (ฐาน 100%) [S3]
- **Fixed Energy**: Energy บางก้อนจากความสามารถเฉพาะเป็นค่าคงที่ที่ **คูณ ERR ไม่ได้** — sim ต้องแยกสองประเภทนี้
- ค่าใช้ Ultimate ปกติเท่ากับ Max Energy ยกเว้น Argenti และ Yunli ที่ใช้ครึ่งหนึ่งได้ [S1]

### 1.4 การพัฒนาตัวละคร

- ตัวละครขึ้นได้ถึง Lv. 80 ผ่าน Ascension 6 ครั้ง
- แต่ละขั้น Ascension ต้องมี Equilibrium Level ตามกำหนด (EL 0 ถึง EL 5)
- ปลดล็อก Bonus Ability 1/2/3 ที่ Ascension 2/4/6

### 1.5 Eidolon (E1–E6)

ระบบเปิดพลังจากการได้ตัวละครซ้ำ มี 6 ระดับ [S2][S4]

- E1, E2, E4, E6 = เอฟเฟกต์ใหม่เฉพาะตัว
- E3 = เพิ่มเลเวลสกิลตายตัว (Skill +2, Basic ATK +1)
- E5 = เพิ่มเลเวลสกิลตายตัว (Ultimate +2, Talent +2)
- Eidolon ผูกกับตัวละครถาวร ไม่สามารถโยกหรือรีเซ็ตได้ ต้องปลดตามลำดับจาก E1 [S2]
- ในทางปฏิบัติ E0 ที่ปั้นดีทำผลงานดีกว่า E2 ที่ปั้นแย่ และไม่มีคอนเทนต์ endgame ใดบังคับให้มี Eidolon สูง [S2]

### 1.6 โหมดเนื้อหาและแหล่งของ

- Cavern of Corrosion — แหล่งฟาร์ม Cavern Relics ที่ 40 Trailblaze Power ต่อรอบ แต่ละถ้ำให้ 2 เซ็ตเฉพาะ [S5]
- Simulated Universe / Divergent Universe — แหล่ง Planar Ornaments ผ่าน Immersion Rewards ใช้ Immersifier หรือ 40 Trailblaze Power [S5][S6]
- Endgame หมุนเวียน — Memory of Chaos (Forgotten Hall), Pure Fiction, Apocalyptic Shadow, Anomaly Arbitration [S17]

### 1.7 ระบบ Cycle ใน endgame

- Cycle แรกของแต่ละ wave กินเวลา 150 AV
- Cycle ถัด ๆ ไปกินเวลา 100 AV ต่อ cycle
- นี่คือที่มาของ SPD breakpoint ยอดนิยม (ดูหัวข้อ 9)

---

## 2. ข้อมูลตัวละครพื้นฐาน

### 2.1 โครงสร้างชุดสกิล

ตัวละครทุกตัวมีชุดความสามารถมาตรฐาน:

- Basic ATK — สร้าง SP
- Skill — ใช้ SP
- Ultimate — ใช้ Energy, ให้ Extra Turn [S1]
- Talent — passive / เงื่อนไขในสนาม
- Technique — ใช้บนแผนที่ก่อนเข้าสู้
- Bonus Abilities 3 ตัว จาก Ascension
- (เฉพาะ Remembrance) Memosprite Skill + Memosprite Talent เป็นสองโนดพิเศษในผังเทรซ

### 2.2 สแตตในเกม

ATK, DEF, HP, SPD, CRIT Rate, CRIT DMG, Break Effect, Outgoing Healing Boost,
Energy Regeneration Rate, Effect Hit Rate, Effect RES, DMG Boost, Vulnerability,
DMG Mitigation, Aggro และสแตตฝ่ายศัตรูอย่าง Toughness

### 2.3 ภาพรวมโรสเตอร์

- ตัวละครที่เล่นได้ทะลุ 80 ตัว กระจายอยู่ใน 7 Type และ 9 Path
- กลุ่มที่มีตัวละครมากสุด: Physical (14 ตัว) และ Fire (13 ตัว)
- Elation ซึ่งเป็นเส้นทางใหม่สุดเริ่มจาก Yao Guang (Physical) และ Sparxie (Fire)

---

## 3. Light Cone

Light Cone คืออุปกรณ์ที่เพิ่ม Base HP, Base ATK, Base DEF ให้ตัวละคร และให้ passive ability
เฉพาะเมื่อ Path ของ Light Cone ตรงกับ Path ของผู้สวมใส่ — หากไม่ตรง Path จะได้เฉพาะค่าสแตตพื้นฐาน

### 3.1 กลไกค่าสแตต

ค่าสแตตรวมของ Light Cone ในระดับความหายากเดียวกันถูกทำให้สมดุลด้วยสูตรผลรวมถ่วงน้ำหนัก
ที่ Lv. 1 กำหนด x = Base HP / 4.8, y = Base ATK / 2.4, z = Base DEF / 3 แล้ว:

    x + y + z = 18   (3-star)
    x + y + z = 23   (4-star)
    x + y + z = 28   (5-star ส่วนใหญ่)
    x + y + z = 26   (5-star จาก Herta's Store)

### 3.2 การอัปเกรด

- อัปเลเวลได้ถึง Lv. 80 ผ่าน Ascension 6 ขั้น
- ต้องมี Equilibrium Level ตามกำหนด
- เสียเครดิตรวม 385,000 สำหรับ 5-star

### 3.3 Superimposition (S1–S5)

- ยกระดับ passive โดยกินสำเนาเดียวกัน
- แรงก์บวกกันได้ (S2 + S2 = S4) แต่ไม่เกิน S5
- วัสดุที่ลงทุนไปในสำเนาที่ถูกกินไม่คืน
- ในทางปฏิบัติ 4-star มักผลัก S5 ได้ง่าย ขณะที่ 5-star แบบ limited มักอยู่ที่ S1 [S13]

---

## 4. Main Stat และ Substat ของ Relic

### 4.1 ตำแหน่งชิ้น

Relic มี 6 ชิ้น แยกเป็น Cavern Relics 4 ชิ้น (Head, Hands, Body, Feet)
และ Planar Ornaments 2 ชิ้น (Planar Sphere, Link Rope) [S5][S7]

| ชิ้น | Main Stat ที่เป็นไปได้ | หมายเหตุ |
|---|---|---|
| Head | HP (flat) | ตายตัว 100% |
| Hands | ATK (flat) | ตายตัว 100% |
| Body | HP%, ATK%, DEF%, Effect Hit Rate, Outgoing Healing, CRIT Rate, CRIT DMG | CRIT Rate/DMG โอกาสละ 10% |
| Feet | HP%, ATK%, DEF%, SPD | SPD โอกาส 12% |
| Planar Sphere | HP%, ATK%, DEF%, Type DMG Boost 7 ชนิด | แต่ละ Type โอกาสละ 9% |
| Link Rope | HP%, ATK%, DEF%, Break Effect, Energy Regen Rate | Break Effect 16%, ERR 5% |

### 4.2 ค่าสูงสุดของ Main Stat (5-star ที่ +15)

| Main Stat | ค่าสูงสุด |
|---|---|
| ATK% / HP% / Effect Hit Rate | 43.2% |
| DEF% | 54% |
| CRIT Rate | 32.4% |
| CRIT DMG | 64.8% |
| Break Effect | 64.8% |
| SPD | 25.032 |
| Type DMG Boost | 38.8803% |
| Energy Regen Rate | 19.4394% |
| Outgoing Healing | 34.5606% |
| flat HP | 705.6 |
| flat ATK | 352.8 |

### 4.3 กลไก Substat

- Relic 5-star มีเลเวลสูงสุด +15 และเริ่มด้วย substat 3–4 ตัว
- ระบบเพิ่ม substat ใหม่ทุก ๆ 3 เลเวลจนครบ 4 ตัว
- หลังครบ 4 ตัว ทุก 3 เลเวลจะไปเสริมค่า substat เดิมแบบสุ่ม
- 5-star ที่เกิดมาพร้อม 4 substat จะได้ roll เสริมทั้งหมด 5 ครั้ง
- Substat ไม่ซ้ำกันเอง และไม่ซ้ำกับ Main Stat ของชิ้นนั้น (เช่น Head ที่มี flat HP เป็น main จะไม่มี flat HP เป็น substat แต่มี HP% ได้)

### 4.4 น้ำหนักการสุ่ม Substat

รวม 100 ก่อนตัดตัวที่ถูกใช้ไปแล้ว:

| Substat | น้ำหนัก |
|---|---|
| HP / ATK / DEF (flat) | 10 ต่อตัว |
| HP% / ATK% / DEF% | 10 ต่อตัว |
| Effect Hit Rate / Effect RES / Break Effect | 8 ต่อตัว |
| CRIT Rate / CRIT DMG | 6 ต่อตัว |
| SPD | 4 (ต่ำสุด) |

SPD มีน้ำหนักต่ำสุด จึงเป็นเหตุที่ SPD substat หาได้ยากที่สุด

### 4.5 ค่าต่อ roll ของ 5-star (Low / Med / High)

| Substat | Low | Med | High |
|---|---|---|---|
| CRIT Rate | 2.592% | 2.916% | 3.24% |
| CRIT DMG | 5.184% | 5.832% | 6.48% |
| ATK% / HP% | 3.456% | 3.888% | 4.32% |
| DEF% | 4.32% | 4.86% | 5.4% |
| Break Effect | 5.184% | 5.832% | 6.48% |
| SPD | 2 | 2.3 | 2.6 |

---

## 5. Relic Set และ Planar Set

### 5.1 ความต่างเชิงโครงสร้าง

| ประเด็น | Cavern Relics | Planar Ornaments |
|---|---|---|
| จำนวนช่อง | 4 (Head, Hands, Body, Feet) [S5] | 2 (Sphere, Link Rope) [S5] |
| โบนัสเซ็ต | มีทั้ง 2-piece และ 4-piece [S5] | มีเฉพาะ 2-piece [S5][S9] |
| ลักษณะโบนัส | 2-pc เป็นสแตตดิบ (12% ATK, 16% Break Effect, 10% Type DMG, 6% SPD); 4-pc เป็นเอฟเฟกต์มีเงื่อนไข [S5] | เซ็ตเดียว เอฟเฟกต์เดียว ต้องตรงกันทั้งสองชิ้นถึงได้ผล [S5] |
| แหล่งฟาร์ม | Cavern of Corrosion [S5] | Simulated / Divergent Universe [S5][S6] |

จุดสำคัญ: Planar ไม่มีโบนัส 1 ชิ้น ต้องให้ครบคู่เสมอ — Sphere กับ Rope ที่ไม่เข้าคู่จะให้เพียง
main stat และ substat เท่านั้น [S5][S9] ค่าโดยประมาณของ Planar เซ็ตที่ดีอยู่ราว 10% ของดาเมจ
เทียบกับไม่มีโบนัสเซ็ต [S9]

### 5.2 Cavern Set ที่สำคัญ (จาก 28 เซ็ตในเกม)

| เซ็ต | 2-Piece | 4-Piece |
|---|---|---|
| Iron Cavalry Against the Scourge | Break Effect +16% | Break Effect >=150% -> Break DMG ignore DEF 10%; >=250% -> Super Break ignore DEF เพิ่ม 15% |
| Hunter of Glacial Forest | Ice DMG +10% | หลังใช้ Ultimate: CRIT DMG +25% เป็นเวลา 2 เทิร์น |
| Genius of Brilliant Stars | Quantum DMG +10% | ignore DEF 10% และเพิ่มอีก 10% ถ้าเป้าอ่อนแอ Quantum |
| Scholar Lost in Erudition | CRIT Rate +8% | Skill/Ultimate DMG +20%; หลัง Ultimate เพิ่ม Skill ถัดไปอีก 25% |
| Pioneer Diver of Dead Waters | DMG ต่อศัตรูที่ติด debuff +12% | CRIT Rate +4%; CRIT DMG +8%/12% ต่อศัตรูที่ติด 2/3 debuff (คูณสองหลังผู้ใส่ลง debuff) |
| The Ashblazing Grand Duke | Follow-up ATK DMG +20% | ATK +6% ต่อครั้งที่ follow-up ลงดาเมจ สูงสุด 8 ชั้น |
| Hero of Triumphant Song | ATK +12% | ขณะ memosprite อยู่สนาม: SPD +6%; เมื่อ memosprite โจมตี CRIT DMG ทั้งคู่ +30% 2 เทิร์น |
| Poet of Mourning Collapse | Quantum DMG +10% | SPD -8%; ถ้า SPD < 110/95 -> CRIT Rate +20%/32% (ผลถึง memosprite ด้วย) |
| Watchmaker, Master of Dream Machinations | Break Effect +16% | ใช้ Ultimate กับพวก: Break Effect ทั้งทีม +30% 2 เทิร์น (ไม่ stack) |
| Messenger Traversing Hackerspace | SPD +6% | ใช้ Ultimate กับพวก: SPD ทั้งทีม +12% 1 เทิร์น (ไม่ stack) [S8] |

### 5.3 Planar Set ที่สำคัญ (จาก 24 เซ็ต)

| เซ็ต | 2-Piece Effect |
|---|---|
| Space Sealing Station | ATK +12%; ถ้า SPD >=120 -> ATK เพิ่มอีก 12% |
| Firmament Frontline: Glamoth | ATK +12%; ถ้า SPD >=135/160 -> DMG +12%/18% |
| Talia: Kingdom of Banditry | Break Effect +16%; ถ้า SPD >=145 -> Break Effect เพิ่มอีก 20% |
| Rutilant Arena | CRIT Rate +8%; ถ้า CRIT Rate >=70% -> Basic ATK และ Skill DMG +20% |
| Inert Salsotto | CRIT Rate +8%; ถ้า CRIT Rate >=50% -> Ultimate และ follow-up DMG +15% |
| Broken Keel | Effect RES +10%; ถ้า Effect RES >=30% -> CRIT DMG ทั้งทีม +10% [S6] |
| Sprightly Vonwacq | ERR +5%; ถ้า SPD >=120 -> advance action 40% เมื่อเข้าสู้ [S10] |
| Penacony, Land of the Dreams | ERR +5%; พวกที่ Type เดียวกับผู้ใส่ได้ DMG +10% |
| The Wondrous BananAmusement Park | CRIT DMG +16%; ถ้ามี summon ของผู้ใส่อยู่สนาม -> CRIT DMG เพิ่มอีก 32% |
| Bone Collection's Serene Demesne | Max HP +12%; ถ้า Max HP >=5,000 -> CRIT DMG ของผู้ใส่และ memosprite +28% [S11] |
| Lushaka, the Sunken Seas | ERR +5%; ถ้าผู้ใส่ไม่ใช่ตัวแรกในทีม -> ATK ของตัวแรก +12% [S12] |
| Pan-Cosmic Commercial Enterprise | Effect Hit Rate +10%; ATK +25% ของ EHR ปัจจุบัน (เพดาน 25%) [S10] |
| Tengoku Livestream | CRIT DMG +16%; ถ้าใช้ SP >=3 แต้มในเทิร์นเดียว -> CRIT DMG เพิ่ม 32% เป็นเวลา 3 เทิร์น |

---

## 6. Path

Path คือ "บทบาท" ในเกม เชื่อมโยงกับ Aeon แต่ละองค์ ปัจจุบันมี 9 Path ที่เล่นได้
และอีก 9 Path ที่ปรากฏเฉพาะในเนื้อเรื่อง/Blessing

| Path | Aeon | บทบาทในเกม |
|---|---|---|
| Destruction | Nanook | ดาเมจสูงพร้อมความอึด ใช้ได้หลายสถานการณ์ |
| The Hunt | Lan | ดาเมจเป้าเดี่ยวสูงสุด เหมาะกับ Elite |
| Erudition | Nous | ดาเมจหลายเป้า เหมาะกับศัตรูเป็นกลุ่ม |
| Harmony | Xipe | บัฟพวกพ้อง |
| Nihility | IX | ลง debuff ลดขีดความสามารถศัตรู |
| Preservation | Qlipoth | เกราะ / ป้องกันทีม |
| Abundance | Yaoshi | ฮีลและฟื้น HP |
| Remembrance | Fuli | เรียก memosprite ร่วมรบ |
| Elation | Aha | กลไก Punchline / Aha Instant (เพิ่มใน 4.0) |

Path ที่ไม่ได้เล่นได้แต่มีบทบาทในเนื้อเรื่อง: Trailblaze (Akivili), Voracity, Beauty,
Permanence, Propagation, Enigmata, Equilibrium, Finality และ Order

ใน Simulated / Divergent Universe คำว่า Path ใช้จัดหมวด Blessing ตามสไตล์การเล่น
เช่น Harmony = Break DMG, Nihility = DoT/debuff, Elation = Follow-up และ Additional DMG,
Erudition = Ultimate

---

## 7. Element Type

มี 7 Type: Physical, Fire, Ice, Lightning, Wind, Quantum, Imaginary

จุดสำคัญ: HSR ไม่มีระบบ elemental reaction แบบ Genshin — Type กำหนดเพียงชนิดดาเมจ
และ debuff ที่ได้จาก Weakness Break ส่วน "ความอ่อนแอ" เป็นคุณสมบัติของศัตรูรายตัว
ไม่ใช่ตารางธาตุตายตัว [S13]

- ศัตรูแต่ละตัวมีจุดอ่อน 2–4 Type [S13]
- การลด Toughness แบ่งเป็น 3 กรณี:
  1. ตีตรงจุดอ่อน → ลด Toughness ตามค่าท่า
  2. ตีไม่ตรงจุดอ่อน → ลด Toughness = 0
  3. ท่า/เอฟเฟกต์ที่ระบุว่า "ลด Toughness โดยไม่สนจุดอ่อน" → ลดได้แม้ศัตรูไม่อ่อนธาตุนั้น เช่น แถบ Exo-Toughness (Type ไหนก็ได้), ท่าของ Fugue ที่เปิดให้เพื่อนลด Toughness ศัตรูที่ไม่มีจุดอ่อนตรงกัน
- Weakness Implant — บางตัวแปะจุดอ่อนชั่วคราวให้ศัตรูได้เอง: Silver Wolf (ธาตุของเพื่อนในทีม + Quantum), Boothill (Physical ตอน Standoff) พอแปะแล้วลด Toughness ด้วยธาตุนั้นได้เหมือนจุดอ่อนปกติ
- ตัวละครผู้เล่นไม่มี Toughness และไม่ถูก Weakness Break แต่ยังรับ debuff ธาตุจากการโจมตีของศัตรูบางประเภทได้
- Version 4.0 เพิ่ม Elation DMG ซึ่งเป็นดาเมจชนิดใหม่ที่ไม่ทำงานเหมือนธาตุคลาสสิก แต่คริติคอลได้และสเกลตามสแตต Elation [S14]

---

## 8. Toughness, Break และ Super Break

### 8.1 กลไก Toughness

Toughness เป็นสแตตของศัตรูเท่านั้น แสดงเป็นเกจเหนือแถบ HP ลดได้ด้วยการโจมตี Type ที่ศัตรูอ่อนแอ
เมื่อหมดเกจจะเกิด Weakness Break ซึ่งให้ผลสี่อย่าง:

1. ลง Break DMG หนึ่งครั้ง
2. หน่วงการกระทำของศัตรู 25%
3. ลง debuff ตาม Type ที่ทำ Break ด้วย base chance 150%
4. เข้าสถานะ Weakness Broken จนถึงเทิร์นถัดไปของศัตรูซึ่งจะฟื้นเกจเต็ม

ขณะที่ศัตรูยังไม่ถูก Break ดาเมจทุกชนิดที่เข้าจะถูกคูณ 0.9 (Broken Multiplier)
รวมถึง Break DMG ที่เกิดจากการทำเกจแตกด้วย

### 8.2 ค่า Toughness และการลด

- ค่า Toughness ฐานของศัตรูส่วนใหญ่เป็นพหุคูณของ 10 (10 หน่วยแสดงผล = 1 Toughness Unit)
- ลำดับปริมาณ: Normal < Elite < Boss/Echo of War
- สกิลตัวละครลด Toughness ได้ที่ค่า 2, 2.5, 3.333..., 5, 10, 15, 20, 30 หรือ 40
- การโจมตีศัตรูบนแผนที่ก่อนเข้าสู้ลด Toughness 10 หน่วย (Technique บางตัวลด 20)

### 8.3 Exo-Toughness

- แถบเสริมสีม่วงที่อยู่หลังแถบปกติ (เข้ามาใน 2.5 และเปิดให้ผู้เล่นใช้ผ่าน Talent ของ Fugue ใน 2.7)
- ต้องทุบแถบแรกให้แตกก่อน
- แถบ Exo ลดได้ด้วย Type ใดก็ได้โดยไม่สนจุดอ่อน
- เมื่อหมดจะทริกเกอร์ Weakness Break อีกครั้งเต็มรูปแบบ
- Talent ของ Fugue ("Cloudflame Luster") ให้ Exo-Toughness เท่ากับ 40% ของ Max Toughness ของศัตรู

### 8.4 สูตรลด Toughness

    Toughness Reduction = (Base + Additive)
                        x (1 + %Toughness Reduction Increase)
                        x (1 + %Weakness Break Efficiency + %Toughness Vulnerability)
                        x Ability Multiplier

Weakness Break Efficiency มีเพดานที่ 300% (เพิ่มมา patch 2.7, ธ.ค. 2024)

หมายเหตุ sim:
- Additive term ไม่ implement แยก — ผู้ใช้บวกเข้า Base ก่อนเรียก `Cal_Total_Toughness_Reduce`
- `Cal_Total_Toughness_Reduce` (CalDamage.h): `Base x (1 + ΣTOUGH_REDUCE%) x (1 + ΣBREAK_EFF%)`
  โดย BREAK_EFF bucket = Weakness Break Efficiency (คนละ stat กับ `Stats::BE` ที่เพิ่ม Break DMG)
- cap 300%: cap ค่าโบนัส (`Weakness_Break_Efficiency_bonus`) ที่ 300 ก่อนบวก base 100% (2026-09-08)
  — bucket `Stats::BREAK_EFF` เก็บโบนัสล้วน (baseline 0); base 100% มาจาก literal ในฟังก์ชันคำนวณ

### 8.5 Break DMG

Break DMG ไม่คริติคอล และไม่ได้รับผลจาก DMG Boost แต่สเกลตาม Break Effect,
Max Toughness ของเป้า และเลเวลผู้โจมตี

    Max Toughness Multiplier = 0.5 + (Max Toughness ของเป้า / 40)

| Type | Break Base DMG | Debuff |
|---|---|---|
| Physical | 2 x Level Mult x MaxToughMult | Bleed |
| Fire | 2 x Level Mult x MaxToughMult | Burn |
| Wind | 1.5 x Level Mult x MaxToughMult | Wind Shear |
| Ice | 1 x Level Mult x MaxToughMult | Freeze |
| Lightning | 1 x Level Mult x MaxToughMult | Shock |
| Quantum | 0.5 x Level Mult x MaxToughMult | Entanglement |
| Imaginary | 0.5 x Level Mult x MaxToughMult | Imprisonment |

สูตรดาเมจฝ่าย Break (รวม DoT และ delayed DMG จาก Break):

    DMG = Base DMG
        x Ability Mult
        x (1 + Break Effect)
        x (1 + Break DMG Increase)
        x DEF Mult
        x RES Mult
        x Vulnerability Mult
        x DMG Mitigation Mult
        x Broken Mult

### 8.6 รายละเอียด Debuff จาก Break

| Debuff | Base DMG | เทิร์น | ผลเพิ่มเติม | เป็น DoT |
|---|---|---|---|---|
| Bleed | 16% Max HP (Normal) / 7% (Elite/Boss) | 2 | เพดานที่ 2 x Level Mult x MaxToughMult | ใช่ |
| Burn | 1 x Level Mult | 2 | — | ใช่ |
| Shock | 2 x Level Mult | 2 | — | ใช่ |
| Wind Shear | 1 x stack x Level Mult | 2 | 1 stack กับ Normal, 3 stack กับ Elite/Boss (เพดาน 5) | ใช่ |
| Freeze | 1 x Level Mult | 1 | ข้ามเทิร์นแต่ advance เทิร์นถัดไป 50% | ไม่ |
| Entanglement | 0.6 x stack x Level Mult x MaxToughMult | 1 | หน่วง action 20% x (1 + Break Effect); เพดาน 5 stack | ไม่ |
| Imprisonment | — | 1 | หน่วง 30% x (1 + Break Effect) และลด SPD 10% | — |

หมายเหตุ:
- Bleed มีเพดานสองชั้น: (1) 16%/7% ของ Max HP ศัตรูต่อเทิร์น (2) hard cap ที่ 2 x Level Mult x MaxToughMult — ค่าที่ใช้จริงคือค่าที่ต่ำกว่า
- ตัวคูณ Base DMG ในตาราง = (ตัวคูณ) x Level Mult [x MaxToughMult ตามที่ระบุ] แล้วเข้าสูตร Break DMG (§8.5): x (1+Break Effect) x (1+Break DMG Increase) x DEF x RES x Vuln x Mitigation x Broken
- DoT/delayed DMG จาก Break ทั้งหมด: ไม่คริ, ไม่รับ DMG Boost, ไม่รับ Weaken; สเกลตาม Break Effect ของผู้ทำ Break (snapshot ตอนลง debuff)
- Shock (Lightning) แรงเป็น 2 เท่าของ Burn (Fire); Wind Shear คิดต่อ stack

### 8.7 Super Break DMG

Super Break เป็นรูปแบบพิเศษของ Break DMG ที่แปลง Toughness Reduction ของการโจมตี
เป็นดาเมจ 1 ครั้งต่อเป้า โดยปกติต้องให้เป้าอยู่ในสถานะ Weakness Broken ก่อน
(ข้อยกเว้นคือ Skill ของ The Dahlia ที่เปิดให้ทีมลง Super Break ได้แม้เป้ายังไม่ Break)

**Overflow toughness บนฮิตที่ทำ Break เอง**: ถ้าโจมตีศัตรูที่ยังไม่ Break แล้วฮิตนั้นเป็นตัว
ทำให้ Toughness ถึง 0 พอดี ส่วนของ Toughness Reduction ที่ "ลดเกิน 0" (overflow) จะถูกนำมา
คำนวณ Super Break ทันทีในฮิตเดียวกันนั้น ไม่ต้องรอฮิตถัดไป
(เช่น เหลือ Toughness 2, ฮิตลด 5 → 2 ใช้ทุบเกจ, 3 ที่เหลือเข้าสูตร Super Break)
เงื่อนไข "ต้อง Weakness Broken ก่อน" จึงหมายถึง "Toughness ต้องถึง 0" ซึ่งรวมกรณีฮิตนั้นทำเอง

    Super Break DMG = (Toughness Reduction / 10)
                    x Level Mult
                    x Ability Mult
                    x (1 + Break Effect)
                    x (1 + Break DMG Increase)
                    x (1 + Super Break DMG Increase)
                    x DEF Mult
                    x RES Mult
                    x Vulnerability Mult
                    x DMG Mitigation Mult
                    x Broken Mult

Super Break ไม่คริติคอลและไม่รับ DMG Boost และนับเป็น Break DMG ประเภทหนึ่ง
Break-related DMG ไม่ได้รับผลจาก Weaken ต่างจากดาเมจปกติ

### 8.8 Level Multiplier (ค่าอ้างอิงสำคัญ)

Level Multiplier ขึ้นกับเลเวลผู้โจมตี

| Level | Level Multiplier |
|---|---|
| 1 | 54.0000 |
| 20 | 139.7703 |
| 40 | 363.6658 |
| 50 | 774.9041 |
| 60 | 1640.3068 |
| 70 | 2659.6406 |
| 75 | 3239.9758 |
| 80 | 3767.5533 |
| 90 | 6020.8836 |
| 95 | 7494.3713 |

Lv. 81–95 (สูงสุด 7494.3713) เป็นค่าเฉพาะฝ่ายศัตรูเมื่อ Weakness ถูก Break จาก non-character effects

---

## 9. ระบบ AV และการคำนวณเทิร์น

### 9.1 สูตรพื้นฐาน

    SPD = Base SPD x (1 + SPD%) + Flat SPD

    Base Action Value = 10000 / SPD

### 9.2 ลำดับการทำงานของ turn order

1. เริ่มการต่อสู้ ทุกยูนิตตั้ง AV เท่ากับ Base AV ของตัวเอง
2. เอฟเฟกต์ที่ทำงาน "เมื่อเข้าสู้" รวมถึงเอฟเฟกต์แก้ SPD/AV ทริกเกอร์จากตัวละครซ้ายไปขวา
3. ยูนิตที่มี AV ต่ำสุดถูกเลือกเป็นผู้กระทำถัดไป
4. ทุกยูนิตลบค่า AV ต่ำสุดนั้นออกจาก AV ของตน (แทนเวลาที่เดินไป)
5. ยูนิตเริ่มเทิร์น DoT ทั้งหมดบนตัวมันลงดาเมจ
6. ผู้เล่นกด Ultimate ก่อนกระทำได้ แต่ Ultimate ก่อนกระทำไม่สามารถ advance ตัวที่กำลังจะเล่นได้ เพราะ AV เป็น 0 อยู่แล้ว
7. ยูนิตกระทำ แล้วรีเซ็ต AV กลับเป็น Base AV; Ultimate ที่คิวหลังกระทำสามารถ advance เทิร์นถัดไปของตัวเองได้ เพราะ AV ถูกรีเซ็ตแล้ว
8. จบเทิร์น สถานะต่าง ๆ นับถอยหลัง แล้ววนกลับข้อ 3

### 9.3 การปรับ AV สองแบบ

การแก้ SPD จะปรับ AV ที่เหลือแบบสัดส่วน:

    AV_new = AV_old x (SPD_old / SPD_new)

การ advance / delay จะหักเป็นเปอร์เซ็นต์ของ Base AV เต็มเทิร์น:

    AV_new = max(0, AV_old - Base AV x (Advance% - Delay%))

ข้อแตกต่างสำคัญ: เอฟเฟกต์ "immediately take action" ตั้ง AV เป็น 0 โดยตรง ซึ่งต่างจาก
"advance forward by 100%" — ดังนั้นถ้ายูนิตถูก delay จนมี AV มากกว่า Base AV
เอฟเฟกต์ "immediately" ยังดึงมาสุดได้ แต่ advance 100% ทำไม่ได้
อย่างไรก็ดี หากสั่งกลางเทิร์นของตัวอื่น ตัวที่กำลังเล่นต้องจบเทิร์นก่อน

### 9.4 SPD Breakpoints ที่มีค่าจริง

| SPD | ผลที่ได้ |
|---|---|
| 114.3 | 4 actions ใน 3 cycle แรก |
| 120 | 3 actions ใน 2 cycle แรก + ปลด Space Sealing Station, Fleet of the Ageless, Sprightly Vonwacq |
| 133.4 | 2 actions ใน cycle แรก |
| 135 | Firmament Frontline: Glamoth ขั้นแรก / Giant Tree ขั้นแรก |
| 142.9 | 5 actions ใน 3 cycle แรก |
| 145 | Talia: Kingdom of Banditry |
| 160 | 4 actions ใน 2 cycle แรก + Glamoth ขั้นสอง |
| 171.5 | 6 actions ใน 3 cycle แรก |
| 180 | Giant Tree of Rapt Brooding ขั้นสอง |

### 9.5 หมายเหตุการเล่นจริง

- สถานะที่แก้ SPD จะนับถอยหลังเฉพาะเมื่อมันติดอยู่ตั้งแต่ต้นเทิร์น
- การปล่อยบัฟ SPD กลางเทิร์นของเป้าหมายจะได้ประโยชน์สูงสุด
- การปล่อยก่อนเทิร์นของเป้าหมายเป็นการเสียเปล่าที่สุด
- ศัตรูมีตัวคูณ Base SPD ตามเลเวล: x1 ที่ Lv. 1–64, x1.1 ที่ 65–77, x1.2 ที่ 78–85 และ x1.32 ที่ 86 ขึ้นไป

---

## 10. ระบบการคำนวณดาเมจ

### 10.1 สูตรทั่วไป

    DMG = Base DMG
        x CRIT Mult
        x DMG Boost Mult
        x Weaken Mult
        x DEF Mult
        x RES Mult
        x Vulnerability Mult
        x DMG Mitigation Mult
        x Broken Mult

### 10.2 องค์ประกอบแต่ละตัว

    Base DMG = Ability Multiplier x Stat + Extra DMG

    CRIT Mult = 1 + CRIT DMG   (เมื่อคริติคอล)
              = 1              (เมื่อไม่คริติคอล และ DoT ของตัวละครเสมอ)

    DMG Boost Mult = 1 + Elemental DMG Boost + All DMG Boost + DoT Boost

    Weaken Mult = 1 - Weaken

    DEF Mult = (Lv_atk + 20) /
               ( (Lv_enemy + 20) x max(0, 1 + %DEF Bonus - %DEF Reduction - %DEF Ignore)
                 + Lv_atk + 20 )

    RES Mult = 1 - (RES ของเป้า - RES PEN ของผู้โจมตี)

    Vulnerability Mult = 1 + Elemental Vuln + All Type Vuln + DoT Vuln

    DMG Mitigation Mult = (1 - m1) x (1 - m2) x (1 - m3) x ...

DEF ของศัตรูคำนวณจาก DEF = 200 + 10 x Level
ซึ่งเป็นเหตุที่ DEF Reduction / DEF Ignore มีผลคุ้มค่าสูงในทางปฏิบัติ

### 10.3 ข้อสังเกตเชิงปฏิบัติ

- ตัวคูณเป็นแบบคูณกันระหว่างหมวด แต่บวกกันภายในหมวด (เช่น DMG Boost ทุกชนิดบวกรวมก่อน) ดังนั้นการกระจายลงทุนข้ามหมวด (ATK / CRIT / DMG Boost / Vulnerability / DEF Ignore) ให้ผลทวีคูณ
- DMG Mitigation เท่านั้นที่ซ้อนแบบคูณกันภายในหมวดตัวเอง ทำให้การซ้อนลดดาเมจหลายชั้นไม่กลายเป็นภูมิคุ้มกัน 100%
- Break-related DMG ไม่ได้รับผลจาก Weaken ต่างจากดาเมจปกติ

### 10.4 Hit Split และ Bounce

- การโจมตีหลายฮิตจะแบ่งดาเมจ, Toughness Reduction และการสร้าง Energy เป็นสัดส่วนตายตัว
- แต่ละฮิตทอยคริติคอลแยกกัน
- จำนวนฮิตกระทบเอฟเฟกต์เช่น Super Break DMG, Light Cone Swordplay และ Talent ของ Dan Heng • Imbibitor Lunae
- ตัวอย่างการแบ่ง: Skill ของ Acheron แบ่ง 10/10/10/70% ขณะที่ Skill ของ Topaz แบ่งเท่ากัน 1/7 เจ็ดฮิต
- การโจมตีแบบ Bounce กระจายฮิตนอกเป้าหลักไปยังเป้าสุ่ม และถ้าท่านั้นสร้าง Energy การเพิ่ม Hits Per Action ก็เพิ่ม Energy ตามด้วย

---

## 11. Aha Instant และ Path of Elation

Elation กลายเป็น Path ที่เล่นได้ใน Version 3.8 / 4.0 พร้อมกลไกที่แตกต่างจากทุก Path ก่อนหน้า [S14]

### 11.0 สูตร Elation DMG (ยืนยันจาก wiki [W16])

    Elation DMG = Base DMG
                x Original Elation DMG Multiplier   (default 1; Yao Guang E4 x1.5, E6)
                x CRIT Multiplier
                x Elation Multiplier      = 1 + Elation
                x Punchline Multiplier    = 1 + (Punchline x 5)/(Punchline + 240)
                                            (ใช้ Certified Banger แทน Punchline ถ้ามาจากสถานะนั้น)
                x Merrymake Multiplier    = 1 + Merrymake
                x DEF Mult x RES Mult x Vulnerability Mult x DMG Mitigation Mult
                x Broken Mult

    Base DMG = Level Multiplier(Elation) x Ability Multiplier
    Ability Multiplier = Base Ability Multiplier + Elation DMG Multiplier Increase

- **Elation Level Multiplier มีตารางแยก** และ = ~2 เท่าของ Break DMG Level Multiplier พอดี
  (Lv.1 = 108.0, Lv.80 = 7535.107 = 3767.5533 x 2)
- **ไม่รับ DMG Boost และ Weaken** (ต่างจากดาเมจปกติ) — เหมือน Break ตรงนี้ แต่ **คริได้** (ต่าง Break)
- ในโค้ด sim: `calElationDamage()` base = `Level_multiplier x 2 x ratio/100` → ตรงกับ wiki
  (ยืนยันแล้ว 2026-09-08 — Punchline/Merrymake/Elation multiplier เป๊ะทุกพจน์)

### 11.1 Punchline

- ทรัพยากรหลักของ Elation สร้างจากการโจมตีและความสามารถของตัวละคร Elation
- แชร์กันทั้งทีม
- เพดานเพิ่มขึ้นตามจำนวนตัวละคร Elation ในทีม [S14]
- ยิ่งสะสม Punchline มาก ยิ่งเพิ่ม Elation DMG [S15]

### 11.2 Aha Instant

Aha ซึ่งเป็น Aeon ของ Elation ปรากฏบนแถบลำดับการกระทำตั้งแต่เริ่มสู้ ในฐานะ entity ที่ทั้งฝ่าย
พันธมิตรและศัตรูไม่สามารถเลือกเป็นเป้าได้ และ SPD ของ Aha ขึ้นกับจำนวนตัวละคร Elation ในทีม [S14]

เมื่อถึงเทิร์นของ Aha จะเกิด Aha Instant ซึ่งให้ผลดังนี้:

- ปลดล็อก Elation Skill ของตัวละคร Elation ทุกตัวโดยไม่สนตำแหน่งบนแถบเทิร์น [S14]
- ยิง Elation Skill ต่อเนื่องเรียงตาม Participant ID — ID ต่ำยิงก่อน (ดูได้ในเทรซของ Elation Skill)
- ล้าง Crowd Control debuff ออกจากตัวละคร Elation ทั้งหมด [S14]
- กิน Punchline ทั้งหมดเพื่อขยายผลของสกิล [S14]
- หากไม่มียูนิตใดใช้ Elation Skill ได้ Aha จะใช้สกิล "Let There Be Laughter" แทน ซึ่งแรงตามจำนวน Punchline ที่สะสม

Yao Guang สามารถบังคับทริกเกอร์ Aha Instant พิเศษผ่าน Ultimate ของเธอ แต่ Punchline ที่นับเข้า
ในกรณีนี้เป็นค่าคงที่ [S15][S18]

### 11.3 Certified Banger

- เมื่อ Aha Instant จบลง ตัวละครที่เข้าร่วมจะได้สถานะ Certified Banger
- สถานะนี้ snapshot จำนวน Punchline ที่ใช้ไปเพื่อเพิ่ม Elation DMG ต่อเนื่อง
- อยู่ 2 เทิร์นและซ้อนทับได้หลายชั้น โดยผลของ Punchline สะสมกัน [S14]

### 11.4 ตัวอย่างการทำงานจริง

- Yao Guang ใช้ "Woe Lots" ระหว่าง Aha Instant ทำให้ศัตรูรับดาเมจเพิ่มพร้อมคืน SP ให้ทีม และ Certified Banger ของเธอทำให้การโจมตีของเพื่อนร่วมทีมลง Additional Elation DMG หนึ่งครั้ง (แรงขึ้นถ้าการโจมตีนั้นกิน SP) [S18]
- Sparxie ใช้กลไกกิน SP ส่ง "Gift" แบบสุ่มเพื่อคืน SP หรือ Punchline ยิ่งกิน SP มากยิ่งได้ Punchline มากและดาเมจตอนเคลียร์บัญชีสูงขึ้น [S18]

### 11.5 ข้อควรระวังเชิงยุทธวิธี

- อย่าทริกเกอร์ Aha Instant เร็วเกินไป ควรสะสม Punchline ให้พีคก่อน [S14]
- การใช้ท่าแรง ๆ นอกบริบท Aha Instant เป็นการเสียศักยภาพเปล่า [S14]
- ทีมที่มีค่า Elation ต่ำจะทำให้ทั้งระบบด้อยประสิทธิภาพลงอย่างมาก [S14]

### 11.6 Elation Trailblazer (ยูนิตฟรี)

- ปลด E1–E6 ได้ครบโดยไม่ต้องหมุนกาชา ผ่านเนื้อเรื่อง 4.2, Heromorpher Wishes จาก 4.0/4.1 และร้าน Furbobo Freebies [S19]
- ร้าน Furbobo Freebies ต้องดัน Planarcadia exploration ถึงระดับ 26 [S19]
- E4 ("Save the World. Just Because.") เด่นสุด เพราะ debuff เพิ่มดาเมจที่ศัตรูรับ 10% รีเฟรชทุกครั้งที่ Elation Skill ทริกเกอร์ [S19]

---

## 12. Memosprite

### 12.1 นิยามและตำแหน่ง

Memosprite คือ entity อิสระที่ตัวละคร Path of Remembrance (เรียกว่า memomaster) เรียกออกมา
วางในช่องขวาของ memomaster และทำตัวเหมือนตัวละครเพิ่มในทีม — มีแถบ HP ของตัวเอง
ถูกศัตรูเล็งได้ และรับบัฟ / ฮีล / เกราะจากพวกได้โดยตรง [S20][S21][S22]

**ไม่จำกัดตัวเดียว**: ทีมมี Remembrance ได้หลายคน แต่ละคนมี memosprite ของตัวเอง — ในซิม
(ที่ทีมเกิน 4 ได้) memosprite จึงเป็นยูนิตตัวที่ 5, 6, 7, 8 ได้ engine ต้องไม่สมมติว่ามีได้ตัวเดียว
หรือ hardcode ช่อง

**Memosprite = summon เสมอ**: ทุกการโจมตีจาก memosprite มี AType::Summon ติดเพิ่มเสมอ
(ดู memory reference_atype_action_damage_rules ข้อ 5 — Joint Attack ก็ push Summon เฉพาะฝั่ง memosprite)

เพราะนับเป็นตัวละครแยก memosprite จึงทริกเกอร์เอฟเฟกต์ที่ต้องการ "ตัวละคร" ได้
และการโจมตีแบบ Blast ที่กระทบ "เป้าข้างเคียง" จะรวม memosprite เข้าไปด้วย
ซึ่งเปลี่ยนรูปแบบการวางทีมอย่างมีนัยสำคัญ [S20]

ตัวอย่าง: Skill ฮีลของ Huohuo ที่ครอบเป้าหลัก + สองตัวข้าง อาจถูก memosprite กินช่องไป
ทำให้ฮีลตัวละครจริงไม่ครบสามตัว [S20]

### 12.2 สแตตและการสืบทอด

สแตตเริ่มต้นของ memosprite มาจากสองทาง: สืบทอดจาก memomaster (ทั้งหมดหรือบางสัดส่วน)
หรือกำหนดค่าตายตัวจาก Talent [S20]

สแตตที่สืบทอดได้ครอบคลุม HP, ATK, DEF, SPD, CRIT Rate/DMG, Break Effect,
Outgoing Healing, Effect Hit Rate, Effect RES, Type DMG Boost และ Type RES [S20]

ตัวอย่าง: Mem ของ Remembrance Trailblazer มี SPD ของตัวเอง แต่ HP และสแตตคริติคอลผูกกับ RMC [S22]

### 12.3 Energy และคุณสมบัติอื่น

- Memosprite ไม่มีเกจ Energy ของตัวเอง แต่สืบทอด Energy Regeneration Rate [S20]
- Memosprite ผลิต Energy ให้ memomaster — จากการใช้ Memosprite Skill, จากการสังหารศัตรู, จากการถูกโจมตี และจากท่าที่ให้ Energy [S20]
- ท่าที่ให้ Energy ทั้งทีม (เช่น Ultimate ของ Huohuo) นับให้ memomaster เพียงครั้งเดียวไม่ว่า memosprite จะอยู่สนามหรือไม่ [S20]
- Memosprite สืบทอด Combat Type และ Path ของ memomaster จึงได้ประโยชน์จากเอฟเฟกต์ที่กำหนดเงื่อนไขเหล่านั้น [S20]
- Memosprite มี Taunt Value เฉพาะตัว (Mem = 200, Garmentmaker = 125) [S23]
- ท่าของ memosprite ไม่กิน SP [S23]

### 12.4 กฎเรื่องเป้าหมายและเอฟเฟกต์ (จุดที่เข้าใจผิดบ่อยสุด)

- Control Effect บน memomaster ไม่ส่งผลถึง memosprite เพราะทั้งสองมีอยู่แยกกัน [S20]
- เอฟเฟกต์ที่ลงบน memomaster ไม่ลงบน memosprite โดยอัตโนมัติ ต้องเล็งแยก และระยะเวลาของเอฟเฟกต์นับถอยหลังตามเทิร์นของ memosprite เอง [S20]
- Passive ของ Light Cone, Relic และ Planar บน memomaster ไม่ส่งผลถึง memosprite ยกเว้นระบุไว้ชัด หรือเป็นการเพิ่มสแตตที่มองเห็นได้นอกการต่อสู้ [S20]

| เอฟเฟกต์ | ส่งผลถึง memosprite? |
|---|---|
| สแตตดิบที่เห็นนอกคอมแบต (CRIT DMG จาก Victory in a Blink, ATK% จาก Glamoth, HP% จาก 2-pc Longevous) | ใช่ [S20] |
| Penacony, Land of the Dreams (All-Type DMG +10%) | ใช่ แม้ memomaster เป็นคนใส่ [S20] |
| Planetary Rendezvous (Type DMG Boost) | ใช่ [S20] |
| บัฟทั้งทีมของ Robin, Zone ของ Luocha, A6 ของ Sparkle | ใช่ ไม่ขึ้นกับจังหวะเรียก [S20] |
| 4-pc Longevous Disciple (CRIT Rate), Forge of the Kalpagni Lantern (Break Effect) | ไม่ — จำกัดเฉพาะผู้สวมใส่ [S20] |
| The Wondrous BananAmusement Park | memosprite ช่วย "เปิด" CRIT DMG +32% ให้ memomaster ได้ แต่ตัวมันเองไม่ได้รับ [S20][S23] |
| Izumo Gensei and Takama Divine Realm | ไม่ — ไม่ช่วยเปิดและไม่ได้รับ CRIT Rate [S20] |
| Aventurine (shield), Ultimate ของ Sparkle, Messenger Traversing Hackerspace (SPD) | ได้เฉพาะเมื่อ memosprite อยู่สนามแล้วตอนลงเอฟเฟกต์ [S20] |

Sunday เป็นข้อยกเว้นเชิงกลไก: Skill และ Ultimate ของเขาลงเอฟเฟกต์ให้ทั้ง memomaster
และ memosprite พร้อมกันได้ถ้าทั้งคู่อยู่สนาม (รวมถึง CRIT Rate จาก Talent,
CRIT DMG จาก Sacerdos' Relived Ordeal และ DMG Boost จาก A Grounded Ascent)
แม้ระยะเวลาจะนับแยกกัน [S20]

### 12.5 Memosprite DMG และ Joint Attack

- ดาเมจที่ memosprite ทำจากท่าตัวเองนับเป็น Memosprite DMG
- รับผลจาก All-Type DMG Boost และ Type DMG Boost ที่ตรงกัน
- ไม่รับ DMG Boost ที่เจาะจง Basic ATK / Skill / Ultimate [S20]
- นี่เป็นเหตุผลที่ Relic แนว "Skill DMG +20%" มักไม่คุ้มบนสาย memosprite

Joint Attack ระหว่าง memomaster กับ memosprite:

- มีตัวคูณแยกกันและใช้สแตตของแต่ละฝ่ายอย่างเป็นอิสระ
- นับเป็นสองการโจมตีแยกกัน (เอฟเฟกต์ที่ทริกเกอร์ตอนโจมตีจะทำงานสองครั้ง)
- แต่นับเป็นหนึ่ง Action เดียว
- สืบทอดชนิดดาเมจตามท่านั้น ๆ [S20]

### 12.6 เทรซและการอัปเกรด

- Memosprite มีโนดเทรซเพิ่มเติมที่ต้องอัปแยกในเมนูเทรซของ memomaster
- Memosprite Skill เพิ่มค่าท่า active
- Memosprite Talent เพิ่มค่าท่า passive [S20][S23]
- Memosprite ใช้ Memosprite Skill หนึ่งท่าในเทิร์นของตัวเอง
- บาง Talent สั่งให้ใช้ท่าอัตโนมัติโดยไม่ต้องกด (เช่น Mem ใช้ "Baddies! Trouble!" เสมอ เว้นแต่ Charge เต็ม 100% จึงเปลี่ยนไปใช้ "Lemme! Help You!") [S20]

### 12.7 กลไก "ตายแล้วได้ประโยชน์"

หลาย memosprite ออกแบบให้การหายไปเป็นส่วนหนึ่งของรอบการเล่น [S23]

- เมื่อ Mem หายไป Trailblazer ได้ advance action 25%
- เมื่อ Garmentmaker หายไป Aglaea ได้ Energy 20 หน่วย
- การใช้ Skill เรียกซ้ำจะฮีล memosprite แทนถ้ามันอยู่แล้ว แต่ Mem จะเสีย Charge ทั้งหมดและ Garmentmaker เสียชั้นบัฟ SPD

### 12.8 หมายเหตุ

- ในเชิงเนื้อเรื่อง คำว่า memosprite เป็นศัพท์เกมเพลย์มากกว่าคำที่ใช้ในโลกของเกม ชุมชนถกเถียงว่ามีเพียง Mem ที่เป็น memetic entity แท้จริง [S24][S25]
- Remembrance เป็น Path เดียวที่มี memosprite
- ไม่ใช่ summon ทุกตัวที่นับเป็น memosprite — Numby ของ Topaz, Lightning-Lord ของ Jing Yuan และ Fuyuan ของ Lingsha เป็น summon ธรรมดา ไม่ใช่ memosprite [S22]

---

## 13. บทวิเคราะห์เชิงปฏิบัติ

### 13.1 สองเศรษฐกิจดาเมจที่แทบไม่คุยกัน

เมื่อรวมทุกระบบเข้าด้วยกัน จะเห็นว่าดาเมจใน HSR แยกเป็นสองสายที่แทบไม่ทับกัน:

| สาย | ตัวแปรหลัก | ไม่แตะ |
|---|---|---|
| สายคริติคอล | ATK x CRIT x DMG Boost x Vulnerability | — |
| สาย Break / Super Break | Break Effect x Level Multiplier x Toughness Reduction x Vulnerability | CRIT และ DMG Boost |

สายที่สองไม่แตะ CRIT และ DMG Boost เลย ทำให้การผสมสองสายบนตัวละครเดียว
มักได้ผลแย่กว่าการทุ่มไปทางเดียว

### 13.2 Toughness เป็นทั้งเกตดาเมจและเครื่องมือควบคุมเทิร์น

Toughness ทำหน้าที่สองอย่างพร้อมกัน: เป็นเกตดาเมจ (ตัวคูณ 0.9 ก่อน Break)
และเป็นเครื่องมือควบคุมเทิร์น (หน่วง 25% เมื่อ Break) ซึ่งเชื่อมตรงเข้ากับระบบ AV
จึงเป็นเหตุที่การจัดทีมตาม Weakness ของเวทีมีผลมากกว่าการอัปดาเมจดิบ [S13]

### 13.3 สองกลไกล่าสุดเพิ่ม throughput ต่อ AV

Memosprite และ Elation ต่างขยาย "จำนวนหน่วยที่กระทำได้ต่อ cycle" ในรูปแบบที่ต่างกัน:

- Memosprite เพิ่มยูนิตจริงที่มีเทิร์นและสแตตของตัวเอง [S21]
- Aha Instant ยิงสกิลของตัวละคร Elation ทั้งกลุ่มออกนอกลำดับเทิร์นปกติ [S14]

ทั้งสองจึงเป็นการเพิ่ม throughput ต่อ AV มากกว่าการเพิ่มดาเมจต่อการโจมตี

---

## ภาคผนวก: แหล่งที่มาทั้งหมด

### A. แหล่งข้อมูลเชิงเทคนิคหลัก (Honkai: Star Rail Wiki — Fandom)

หน้าเหล่านี้เป็นที่มาของสูตร ค่าคงที่ ตารางตัวเลข และรายการเซ็ตทั้งหมดในเอกสารนี้

| รหัส | หน้า | URL |
|---|---|---|
| W1 | Toughness (Break, Super Break, Level Multiplier, Exo-Toughness) | https://honkai-star-rail.fandom.com/wiki/Toughness |
| W2 | Damage (สูตรดาเมจ, DEF/RES/Vulnerability, Hit Split) | https://honkai-star-rail.fandom.com/wiki/Damage |
| W3 | Speed (AV, turn order, SPD breakpoints) | https://honkai-star-rail.fandom.com/wiki/Speed |
| W4 | Relic/Stats (Main Stat, Substat, น้ำหนักการสุ่ม, ค่าต่อ roll) | https://honkai-star-rail.fandom.com/wiki/Relic/Stats |
| W5 | Relic/Sets (รายการ Cavern 28 เซ็ต, Planar 24 เซ็ต) | https://honkai-star-rail.fandom.com/wiki/Relic/Sets |
| W6 | Relic (ภาพรวมระบบ Relic) | https://honkai-star-rail.fandom.com/wiki/Relic |
| W7 | Light Cone (สูตรสแตต, Superimposition, Ascension) | https://honkai-star-rail.fandom.com/wiki/Light_Cone |
| W8 | Type (7 ธาตุ) | https://honkai-star-rail.fandom.com/wiki/Type |
| W9 | Path (9 Path เล่นได้ + Path ในเนื้อเรื่อง) | https://honkai-star-rail.fandom.com/wiki/Path |
| W10 | Character (โครงสร้างตัวละคร, Ascension, โรสเตอร์) | https://honkai-star-rail.fandom.com/wiki/Character |
| W11 | Ultimate (Extra Turn, Energy) | https://honkai-star-rail.fandom.com/wiki/Ultimate |
| W12 | Version (โครงสร้างเวอร์ชัน) | https://honkai-star-rail.fandom.com/wiki/Version |
| W13 | Memosprite | https://honkai-star-rail.fandom.com/wiki/Memosprite |
| W14 | Mem (memosprite ของ Trailblazer) | https://honkai-star-rail.fandom.com/wiki/Mem |
| W15 | Skill Point | https://honkai-star-rail.fandom.com/wiki/Skill_Point |
| W16 | Elation DMG (สูตร + Level Multiplier table) | https://honkai-star-rail.fandom.com/wiki/Elation_DMG |

### B. แหล่งอ้างอิงที่ถูกอ้างในเนื้อหา (รหัส S)

| รหัส | ชื่อแหล่ง | URL |
|---|---|---|
| S1 | Ultimate — Honkai: Star Rail Wiki (Fandom) | https://honkai-star-rail.fandom.com/wiki/Ultimate |
| S2 | HSR Eidolons Explained: How They Work and Which Ones Matter — GameMarket.gg (21 ส.ค. 2026) | https://gamemarket.gg/news/honkai-star-rail/hsr-eidolons-explained-how-they-work-and-which-ones-matter |
| S3 | How to Get MORE Ultimates — Complete Energy Guide (ValkyrjaYT, YouTube) | https://www.youtube.com/watch?v=3JRPfPb-OzQ |
| S4 | Honkai Star Rail Eidolons — What are they? — Pro Game Guides | https://progameguides.com/honkai-star-rail/honkai-star-rail-eidolons-what-are-they/ |
| S5 | Honkai: Star Rail Relics Guide: Sets, Stats & Where to Farm — GameMarket.gg (25 ส.ค. 2026) | https://gamemarket.gg/news/honkai-star-rail/honkai-star-rail-relics-guide-sets-stats-where-to-farm |
| S6 | All Honkai: Star Rail Relics and Planar Ornaments — Talk Android | https://www.talkandroid.com/75889-honkai-star-rail-relics-and-planar-ornaments/ |
| S7 | Relic — Honkai: Star Rail Wiki (Fandom) | https://honkai-star-rail.fandom.com/wiki/Relic |
| S8 | NEW 1.2 RELICS Worth Farming? Relic Set & Planar Ornament Analysis (SevyPlays, YouTube) | https://www.youtube.com/watch?v=mMlZJzLaKtA |
| S9 | Your Account is BETTER Than You Realize! Relic Guide (Guoba Fans, YouTube) | https://www.youtube.com/watch?v=5xQ0fS5XJBw |
| S10 | What are Planar Ornaments in Honkai: Star Rail? — Dot Esports | https://dotesports.com/honkai/news/what-are-planar-ornaments-in-honkai-star-rail |
| S11 | NEW 3.1 Relic Sets — Who Can Use Them & Are They Good (EODGamer, YouTube) | https://www.youtube.com/watch?v=CYTs8WFS1Vk |
| S12 | Every Character Getting A BUFF From The New Planar Ornament Relic Sets in 2.5! (ZDB, YouTube) | https://www.youtube.com/watch?v=6tpIdmNfMoE |
| S13 | Glossary — GameVika (29 ก.ค. 2026) | https://gamevika.com/en/hsr/glossary |
| S14 | Honkai Star Rail Elation Path Explained: How Will It Work? — Beebom (15 ม.ค. 2026) | https://beebom.com/honkai-star-rail-elation-path/ |
| S15 | Why Elation is WAY Better Than You Think (PretenderHSR, YouTube, 8 ม.ค. 2026) | https://www.youtube.com/watch?v=XgruYqJi-4c |
| S16 | Honkai Star Rail combat guide, everything explained (KibblesBits, YouTube) | https://www.youtube.com/watch?v=ihoCZPFFixI |
| S17 | Honkai: Star Rail Strategy Guide — Cosmo Strategy Guides (7 พ.ค. 2026) | https://cosmocheats.com/game-guides/honkai-star-rail/ |
| S18 | Learn More About the Path of Elation and Abilities of Yao Guang & Sparxie — GameSpace (9 ก.พ. 2026) | https://gamespace.com/all-articles/news/hsr-elation-yao-guang-sparxie/ |
| S19 | Honkai Star Rail Guide: How to Get Elation Trailblazer Eidolons — Games.gg (26 เม.ย. 2026) | https://games.gg/honkai-star-rail/guides/honkai-star-rail-how-to-get-elation-trailblazer-eidolons/ |
| S20 | Memosprite Mechanics Guide — KeqingMains (KQM, 8 เม.ย. 2025) | https://hsr.keqingmains.com/misc/memosprite-mechanics/ |
| S21 | Honkai Star Rail: Everything About Remembrance Characters So Far — ScreenRant (20 ธ.ค. 2024) | https://screenrant.com/honkai-star-rail-remembrance-characters-mechanics-memosprites/ |
| S22 | What are Memosprites? — r/StarRailStation (14 ม.ค. 2025) | https://www.reddit.com/r/StarRailStation/comments/1i12n39/what_are_memosprites/ |
| S23 | List of discoveries testing Memosprites (jsternmains) — r/HonkaiStarRail_leaks (7 ธ.ค. 2024) | https://www.reddit.com/r/HonkaiStarRail_leaks/comments/1h8q5gj/list_of_discoveries_testing_memosprites_from_the/ |
| S24 | About Memosprites... — r/HonkaiStarRail (1 ก.พ. 2025) | https://www.reddit.com/r/HonkaiStarRail/comments/1ifi75v/about_memosprites/ |
| S25 | Are memosprites actually a thing or..? — r/HonkaiStarRail (24 ก.พ. 2025) | https://www.reddit.com/r/HonkaiStarRail/comments/1ix8zbr/are_memosprites_actually_a_thing_or/ |
| S26 | Memosprite clarification by ubatcha — r/HonkaiStarRail_leaks (2 ธ.ค. 2024) | https://www.reddit.com/r/HonkaiStarRail_leaks/comments/1h52bs7/memosprite_clarification_by_ubatcha/ |
| S27 | What Is the Path of Remembrance in Honkai: Star Rail? — Icy Veins | https://www.icy-veins.com/honkai-star-rail/remembrance-characters |
| S28 | KQM Relics Overview | https://hsr.keqingmains.com/misc/relics-overview/ |
| S29 | Guide to the new Path (HONKAI: STAR RAIL 4.0) — HoYoLAB | https://www.hoyolab.com/article/43731305 |

### C. แหล่งข้อมูลเวอร์ชันและแพตช์

| รหัส | ชื่อแหล่ง | URL |
|---|---|---|
| V1 | Honkai: Star Rail official site (Version 4.5 "To Roll the Stars in Astropolis") | https://hsr.hoyoverse.com/ |
| V2 | Version 4.3 "The Lethe Below the Living" Update Details — HoYoverse | https://hsr.hoyoverse.com/en-us/news/164415 |
| V3 | Honkai: Star Rail Version 4.3 The Lethe Below the Living — HoYoverse News | https://www.hoyoverse.com/en-us/news/164350 |
| V4 | Version 4.3 Update and Maintenance Notice — HoYoLAB | https://www.hoyolab.com/article/45252090 |
| V5 | Honkai: Star Rail 4.3 Banners, Events, and Release Date — Game8 (13 ก.ค. 2026) | https://game8.co/games/Honkai-Star-Rail/archives/591836 |
| V6 | Patch Timeline — Prydwen.gg | https://www.prydwen.gg/star-rail/patch-timeline |
| V7 | Patch Notes for Honkai: Star Rail — PatchBot | https://patchbot.io/games/honkai-star-rail |
| V8 | Honkai: Star Rail Version 4.3 Officially Revealed — GamesPress | https://www.gamespress.com/it/Honkai-Star-Rail-Version-43-The-Lethe-Below-the-Living-Officially-Reve |

---

## หมายเหตุสำหรับการใช้เป็น context ให้ LLM

1. ตัวเลขและสูตรทั้งหมดในเอกสารนี้เป็นค่า ณ กันยายน 2026 (เกมอยู่ที่ Version 4.5) กลไกใหม่อาจเข้ามาในเวอร์ชันถัดไป
2. ค่า Level Multiplier, ค่า Main Stat สูงสุด, น้ำหนักการสุ่ม substat และค่าต่อ roll เป็นค่าตายตัวที่ตรวจสอบได้จากหน้า wiki ในภาคผนวก A
3. รายการ Relic/Planar set ในเอกสารนี้เป็นการคัดเฉพาะเซ็ตที่ใช้บ่อย ไม่ใช่รายการครบทั้ง 28 + 24 เซ็ต — หากต้องการรายการครบ ให้ดู W5
4. ส่วนที่มาจาก Reddit (S22–S26) เป็นการทดสอบของชุมชน มีความน่าเชื่อถือต่ำกว่าหน้า wiki และ KQM ควรถือเป็นข้อมูลประกอบ
5. หัวข้อ Elation / Aha Instant เป็นกลไกใหม่ที่สุด ข้อมูลบางส่วนมาจากการวิเคราะห์ของ content creator (S15, S18) จึงอาจเปลี่ยนแปลงได้เมื่อ HoYoverse ปรับสมดุล
