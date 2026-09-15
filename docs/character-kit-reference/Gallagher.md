# Gallagher — กัลลาเกอร์

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Gallagher.h` |
| ธาตุ | **Fire** |
| Path | **Abundance** |
| ระดับ | 4★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1305 · ATK 529 · DEF 441 · SPD 98

---

## Basic ATK — Corkage Fee (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Nectar Blitz (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **250% ATK** ใส่ศัตรู 1 ตัว
- ลด ATK เป้าหมาย **15%** นาน 2 เทิร์น
- Energy +20 · Toughness 30

## Skill — Special Brew (ฮีล, Lv.10)
- ฮีลเพื่อนเป้าหมายทันที **1600 HP** (ค่า flat, Lv.10)
- Energy +30 · ไม่มี Toughness

## Ultimate — Champagne Etiquette (AoE, 110 energy, Lv.10)
- ติด **Besotted** ให้ศัตรูทุกตัว นาน 2 เทิร์น
- Fire DMG = **150% ATK** ให้ศัตรูทุกตัว
- เปลี่ยน Basic ATK ครั้งถัดไปของ Gallagher เป็น **Nectar Blitz**
- Energy +5 · Toughness 20

## Talent — Tipsy Tussle (Lv.10)
- สถานะ **Besotted** ทำให้เป้าหมายรับ **Break DMG +12%**
- ทุกครั้งที่เป้าหมาย Besotted ถูกเพื่อนโจมตี → ผู้โจมตีถูกฮีล **640 HP**

## Technique — Artisan Elixir
- เข้าฉากแล้วโจมตีศัตรูทันที: ติด Besotted ให้ศัตรูทุกตัวนาน 2 เทิร์น + Fire DMG = **50% ATK** AoE
- Toughness 20

---

## Major Traces
- **A2 — Novel Concoction**: +Outgoing Healing เท่ากับ **50% ของ Break Effect** สูงสุด **+75%**
- **A4 — Organic Yeast**: หลังใช้ Ultimate → **Advance Forward 100%** ทันที
- **A6 — Bottoms Up**: เมื่อ Gallagher ใช้ Nectar Blitz ตีศัตรูที่ Besotted → เอฟเฟกต์ฮีลจาก Talent ครั้งนั้นจะ**ใช้กับเพื่อนคนอื่นด้วย**

## Minor Traces (รวมทั้งหมด)
Effect RES +28% · Break Effect +13.3% · HP +18%

## Eidolons
- **E1 — Salty Dog**: เข้าการต่อสู้ → คืน Energy **20** + Effect RES **+50%**
- **E2 — Lion's Tail**: ใช้ Skill → ลบ debuff 1 อันจากเป้าหมาย + Effect RES **+30%** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Last Word**: ยืดเวลา Besotted จาก Ultimate อีก **1 เทิร์น** (รวม 3)
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — Blood and Sand**: Break Effect **+20%** + Weakness Break Efficiency **+20%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **A2 Healing**: outgoing healing = min(50% × BreakEffect, 75%) — ผูกกับ Break Effect ปัจจุบัน ต้อง re-eval (โค้ดใช้ `calculateBreakEffectForBuff` + cap 75 + `buffNote["Novel Concoction"]`)
- **Skill / Talent heal เป็นค่า flat** (1600 / 640) ไม่สเกลกับ HP → แต่รับผลจาก outgoing healing % ของ Gallagher
- **Besotted** เป็น debuff ที่ให้ทั้ง Break-DMG-taken +12% (Talent) และเป็นทริกเกอร์ heal-on-hit
- **Enhanced BA**: Ult set flag ให้ BA ถัดไปเป็น Nectar Blitz (250%, +Besotted-ATK-down 15%/2t, Toughness 30)
- **A6**: heal-on-hit ของ Talent ครั้งที่ Nectar Blitz ตี Besotted → กระจายเป็น AoE heal (โค้ดเช็ค `buffCheck["Gallagher_enchance_basic_atk"]`)
- **A4**: action advance 100% หลัง Ult
- E1 (+20 energy, +50% RES) trigger ตอนเข้าสนาม — ในโค้ดอยู่ที่ `Start_game_List` (เฉพาะ E1) และ `WhenOnField_List` (Besotted tech + A2 buff)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/gallagher — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)
