# Tingyun • Fugue — ฟิวก์

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Fugue.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1125 · ATK 582 · DEF 557 · SPD 102

> Nihility Break/Super Break support — คนแรกที่บังคับใส่ Exo Toughness ให้ break ได้รอบสอง

---

## Basic ATK — Radiant Streak (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Fiery Caress (Blast, Lv.6)
- Fire DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- Energy +20 · Toughness 10 (+5)

## Skill — Virtue Beckons Bliss (Support, Lv.10)
- มอบ **"Foxian Prayer"** ให้เพื่อน 1 ตัว + เข้าสถานะ **"Torrid Scorch"** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Fugue)
- "Foxian Prayer" มีผลกับเป้าหมาย Skill ล่าสุดเท่านั้น:
  - Break Effect **+30%**
  - ลด Toughness ได้แม้ตีศัตรูที่ไม่มี Weakness type ตรง = **50% ของปกติ** (ไม่ stack กับ ignore-weakness อื่น)
- ขณะ "Torrid Scorch": Fugue enhanced Basic ATK; ทุกครั้งเพื่อนที่มี "Foxian Prayer" โจมตี → 100% base chance ลด DEF ศัตรูที่โดน **18%** นาน 2 เทิร์น
- Energy +30

## Ultimate — Solar Splendor Shines Upon All (AoE, 130 energy, Lv.10)
- Fire DMG = **200% ATK** AoE
- ลด Toughness ศัตรูทุกตัวโดยไม่สน Weakness type; เมื่อ break → trigger Fire Weakness Break effect
- Energy +5 · Toughness 20

## Talent — Fortune Follows Where Virtue Spreads (Lv.10)
- ขณะ Fugue อยู่ในสนาม → ศัตรูถูกใส่ **"Cloudflame Luster"** = **40% ของ Max Toughness**
  - เมื่อ Toughness เริ่มต้นถูกลดเป็น 0 → ลด "Cloudflame Luster" ต่อได้; เมื่อ "Cloudflame Luster" ถึง 0 → ศัตรูรับ Weakness Break DMG อีกครั้ง
- ขณะ Fugue อยู่ในสนาม หลังเพื่อนตีศัตรู Weakness Broken → แปลง Toughness Reduction ของการโจมตีนั้นเป็น **Super Break DMG 100%** 1 instance

## Technique — Percipient Shine
- ติด Daze ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Dazed → Fugue action advance **40%** + 100% base chance ติด DEF Reduction แบบ Skill ให้ศัตรูทุกตัว นาน 2 เทิร์น

---

## Major Traces
- **A2 — Verdantia Renaissance**: หลังเพื่อน break weakness → delay action ศัตรู **+15%**
- **A4 — Sylvan Enigma**: Fugue Break Effect **+30%**. ใช้ Skill ครั้งแรก → คืน Skill Point **1**
- **A6 — Phecda Primordia**: ศัตรูถูก break → เพื่อน (ยกเว้น Fugue) Break Effect **+6%**; ถ้า BE ของ Fugue ≥ 220% → เพิ่มอีก **+12%** นาน 2 เทิร์น stack 2 ครั้ง

## Minor Traces (รวมทั้งหมด)
Break Effect +24% · SPD +14 · HP +10%

## Eidolons
- **E1**: เพื่อนที่มี "Foxian Prayer" → Weakness Break Efficiency **+50%**
- **E2**: ศัตรูถูก break → Fugue คืน Energy **3**. หลังใช้ Ult → advance action เพื่อนทุกคน **24%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: เพื่อนที่มี "Foxian Prayer" → Break DMG dealt **+20%**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Fugue Weakness Break Efficiency **+50%**. ขณะ "Torrid Scorch" → "Foxian Prayer" มีผลกับเพื่อนทุกคน

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Cloudflame Luster (Talent)** = Exo Toughness = 40% Max Toughness → break ได้รอบสอง (กลไก unique ต้องมี second-toughness bar)
- **Super Break conversion 100%** เมื่อเพื่อนตี broken enemy (ขณะ Fugue อยู่ในสนาม)
- **Foxian Prayer (Skill)**: BE +30% + ignore-weakness toughness 50% ให้เพื่อน 1 ตัว (E6 → ทั้งทีมขณะ Torrid Scorch)
- **Ult**: ignore-weakness toughness reduction + Fire weakness break
- **BE breakpoint 220%** (A6) — Fugue เป็น BE-scaling support
- โค้ด: `Fugue.h` — ตรวจ `Start_game_List` / weakness apply

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tingyun-fugue — kit tab (review patch 3.2, calc patch 4.0, profile 01/Jun/2026)
