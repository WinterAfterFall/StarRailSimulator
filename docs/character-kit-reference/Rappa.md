# Rappa — รัปปะ

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Rappa.h` |
| ธาตุ | **Imaginary** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.8) |

## Base Stats (Lv.80, ascended)
HP 1087 · ATK 717 · DEF 460 · SPD 96

> Erudition Break DPS สาย Super Break / Sealform

---

## Basic ATK — Ninjutsu: Rise Above Tumbles (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Ningu: Demonbane Petalblade (Blast, Lv.6)
- hit 1–2: Imaginary DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- hit 3: Imaginary DMG = **100% ATK** ใส่ศัตรูทุกตัว
- ไม่คืน Skill Point
- ตีศัตรูที่ไม่มี Imaginary Weakness ยังลด Toughness ได้ = **50% ของปกติ**; เมื่อ Break → trigger Imaginary Weakness Break effect
- Energy +20 · Toughness 25 (+15 ข้างเคียง)

## Skill — Ninja Strike: Rooted Resolute (AoE, Lv.10)
- Imaginary DMG = **120% ATK** AoE
- Energy +30 · Toughness 10

## Ultimate — Nindō Supreme: Aishiteru (Enhance, 140 energy, Lv.10)
- เข้าสถานะ **"Sealform"**, ได้เทิร์นพิเศษทันที, ได้ **"Chroma Ink" 3 แต้ม**, Weakness Break Efficiency **+50%**, Break Effect **+30%**
- ขณะ Sealform: Basic ATK enhanced, ใช้ Skill/Ult ไม่ได้; หลัง Enhanced BA → กิน Chroma Ink 1 แต้ม; Chroma Ink หมด → ออกจาก Sealform
- Energy +5

## Talent — Ninja Tech: Endurance Gauge (Lv.10)
- ทุกครั้งศัตรู Weakness Broken → Rappa Charge **+1** (สูงสุด 10)
- hit ที่ 3 ของ Ningu: Demonbane Petalblade ครั้งถัดไป → เพิ่ม Break DMG = **60% ของ Imaginary Break DMG ของ Rappa** AoE
  - ดาเมจนี้ลด Toughness ได้โดยไม่สน Weakness type = 2; กิน Charge ทั้งหมด
  - ต่อ 1 Charge → Break DMG multiplier **+50%** + ignore-weakness Toughness Reduction **+1**
- Toughness 2

## Technique — Wisps of Aurora
- เข้าฉากโดยตีศัตรู: ลด Toughness 30 โดยไม่สน Weakness type + Break DMG = **200% ของ Imaginary Break DMG** ต่อศัตรู, ข้างเคียง = **180%**
- คืน Energy **10**
- Toughness 10

---

## Major Traces
- **A2 — Sky High**: ศัตรู elite+ ถูก Weakness Broken → Rappa Charge **+1** + คืน Energy **10**
- **A4 — Sea Echo**: ขณะ Sealform หลัง Enhanced BA ตีศัตรู Weakness Broken → แปลง Toughness Reduction ของ instance นั้นเป็น **Super Break DMG 60%** 1 instance
- **A6 — Withered Leaf**: ศัตรู Weakness Broken → รับ Break DMG **+2%**; ถ้า ATK > 2400 ต่อ 100 ส่วนเกิน → **+1%** สูงสุด **+8%** (นาน 2 เทิร์น)

## Minor Traces (รวมทั้งหมด)
ATK +28% · SPD +9 · Break Effect +13.3%

## Eidolons
- **E1**: ขณะ Sealform จาก Ult → ดาเมจเพิกเฉย DEF **15%**. ออกจาก Sealform → คืน Energy **20**
- **E2**: Enhanced BA hit 1–2 → Toughness Reduction ใส่เป้าหมายหลัก **+50%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Sealform → เพื่อนทุกคน SPD **+12%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: ต้นการต่อสู้ → Charge **+5** + cap **+5**. หลัง hit ที่ 3 ของ Ningu → Charge **+5**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Imaginary Break DMG** เป็นฐานคำนวณ Talent/Technique (ต้องมี break dmg model)
- **Sealform**: Chroma Ink 3 (E ไม่เพิ่ม), Enhanced BA กิน 1/ครั้ง, extra turn ตอนเข้า, +50% WBE +30% BE
- **Charge** (0–10, E6 15): +1 ต่อ enemy break + A2 (elite +1) + E6; ปลดที่ hit 3 → Break DMG 60% × (1 + 0.5×Charge) AoE + ignore-weakness toughness
- **A4 Super Break** ตอน Sealform ตี broken target
- Enhanced BA ไม่คืน SP, break weakness ได้แม้ไม่มี Imaginary weakness (50% toughness)
- โค้ด: `Start_game_List` priority `PRIORITY_ACTTACK` (`Rappa.h:140`) + `Rappa_LC.h` มี Start_game entry ด้วย

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/rappa — kit tab (review patch 3.0, calc patch 3.8, profile 01/Jun/2026)
