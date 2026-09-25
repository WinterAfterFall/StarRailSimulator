# Sparxie — สปาร์กซี่  (codename ในโค้ด: **Hibana**)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Elation/Hibana.h` (namespace `Hibana`) |
| ธาตุ | **Fire** |
| Path | **Elation** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1051 · ATK 640 · DEF 460 · SPD 107

> Sparxie = "the Mask" คู่กับ Sparkle ("the Fool") — Elation DPS สาย Punchline/Thrill

---

## Basic ATK — Cat Got Your Flametongue? (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Bloom! Winner Takes All (Blast, Lv.6)
- จบ livestream: Fire DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- Energy +40 · Toughness 10 (+5)

## Skill — Boom! Sparxicle's Poppin (Enhance, Lv.10)
- เริ่ม livestream → เปลี่ยน Basic ATK เป็น "Bloom! Winner Takes All" + trigger "Engagement Farming" 1 ครั้ง
- ระหว่างนี้ trigger "Engagement Farming" ซ้ำได้สูงสุด **20 ครั้ง**
- **การใช้ท่านี้ไม่นับเป็นการใช้ Skill**
- Energy +0

## Skill (Enhanced) — Engagement Farming (Enhance, Lv.10)
- ทำให้ "Bloom! Winner Takes All" +multiplier ใส่เป้าหมายหลัก **+20%**, ข้างเคียง **+10%**
- สุ่มได้ของขวัญ 1 อย่าง:
  - **"Straight Fire"**: Punchline +2, Skill Point +2
  - **"Unreal Banger"**: Punchline +1
- ไม่นับเป็นการใช้ Skill

## Ultimate — Party's Wildin' and Camera's Rollin' (AoE, 160 energy, Lv.10)
- Punchline **+2**
- Fire DMG = **(0.6 × Elation + 50%) ATK** ใส่ศัตรูทุกตัว
- Energy +5 · Toughness 20

## Talent — Sleight of Sparx Hand (Lv.10)
- ขณะถือ **"Certified Banger"**:
  - Enhanced BA → **40% Fire Elation DMG** เป้าหมายหลัก + **20%** ข้างเคียง; ต่อ 1 instance ของ "Engagement Farming" ที่ trigger → +1 instance ของ **20% Fire Elation DMG** ใส่ศัตรูสุ่ม
  - Ultimate → **48% Fire Elation DMG** ใส่ศัตรูทุกตัว
- Energy +5

## Technique — The Heart Makes the Finest Tomb
- ติด "Block" ให้ศัตรู 10 วิ
- โจมตีศัตรู Blocked → เข้าฉาก: Fire DMG = **50% ATK** AoE + คืน Skill Point **2** ให้ทีม

## Elation Skill — Signal Overflow: The Great Encore! (AoE, Lv.10)
- **50% Fire Elation DMG** AoE + **20 instance × 25% Fire Elation DMG** ใส่ศัตรูสุ่ม
- Sparxie ได้ **"Thrill" +2** (ใช้หักล้างการกิน Skill Point; การกิน Thrill นับเป็นการกิน Skill Point)
- Energy +5

---

## Major Traces
- **A2 — Sweet! Punchline Signing**: ทุก 100 ATK ที่เกิน **2000** → Elation **+5%** สูงสุด **+80%**
- **A4 — Dazzling! Persona Kaleidoscope**: มีตัวละคร Elation ในทีม 1/2/(3+) → ใช้ Ult ได้ Punchline เพิ่ม **2/4/8** + Thrill **1/1/4**
- **A6 — Frenzy! Palette of Truth and Lies**: ทุก 1 Punchline ที่ถืออยู่ → เพื่อนทุกคน CRIT DMG **+8%** สูงสุด **+80%**

## Minor Traces (รวมทั้งหมด)
Elation +28% · CRIT Rate +12% · CRIT DMG +13.3%

## Eidolons
- **E1**: จบ Aha Instant → Punchline +5. ทุก 1 Punchline → เพื่อนทุกคน All-Type RES PEN **+1.5%** สูงสุด **+15%**
- **E2**: จบ Aha Instant → Sparxie ได้เทิร์นพิเศษ + Thrill +2. ทุก 1 Thrill ที่กิน → Sparxie CRIT DMG **+10%** นาน 2 เทิร์น stack 4 ครั้ง
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Elation Skill Lv. +1
- **E4**: ใช้ Ult → Punchline +5 + Sparxie Elation **+36%** นาน 3 เทิร์น
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Elation Skill Lv. +1
- **E6**: All-Type RES PEN **+20%**. ทุก 1 Punchline ที่ Elation Skill นับ → +1 instance ของ additional DMG สูงสุด **40**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ระบบ Elation (Aha Instant)** — โค้ดมี `elationCount`, `genPunchLine`, `AfterAhaInstant_List` ฯลฯ
- **Punchline** (สะสม): จาก Engagement Farming, Ult(+2), A4, E1/E4 → ป้อน A6 (CRIT DMG ทีม), E1 (RES PEN), E6 (Elation Skill instances)
- **Thrill**: จาก Elation Skill(+2), A4, E2 → ใช้หักล้าง Skill Point consumption
- **Elation stat**: Ult/Talent DMG สเกลกับ Elation (`0.6×Elation + 0.5`); A2 แปลง ATK เกิน 2000 → Elation
- **livestream/Skill** ไม่นับเป็น "การใช้ Skill" (สำคัญต่อ trigger อื่น ๆ ที่นับ skill-use)
- **Engagement Farming** cap 20 ครั้ง/livestream, สุ่ม 2 outcome
- `setAtkRequire(3600)` ในโค้ด — build เป้า ATK

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sparxie — kit tab (review/calc patch 4.0, profile 01/Jun/2026)
