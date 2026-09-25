# Silver Wolf — ซิลเวอร์วูล์ฟ

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Silver Wolf.h` (โค้ดเรียก `"SW"`) |
| ธาตุ | **Quantum** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1047 · ATK 640 · DEF 460 · SPD 107

> Nihility debuffer สาย weakness implant + RES/DEF shred + "Bug"

---

## Basic ATK — System Warning (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Allow Changes? (Impair, Lv.10)
- 120% base chance ยัด Weakness type ของเพื่อนในสนาม 1 อัน (เลือกตามเพื่อนลำดับแรก) + ลด RES ต่อ type นั้น **20%** นาน 3 เทิร์น
  - ถ้าศัตรูมี type นั้นอยู่แล้ว → RES reduction ไม่ trigger
  - ศัตรูแต่ละตัวมี Weakness ที่ Silver Wolf ยัดได้ **1 อัน** (ยัดใหม่ = เก็บอันล่าสุด)
- 100% base chance ลด All-Type RES เป้าหมายเพิ่ม **13%** นาน 2 เทิร์น
- Quantum DMG = **196% ATK** ใส่เป้าหมาย
- Energy +30 · Toughness 20

## Ultimate — User Banned (Impair, 110 energy, Lv.10)
- 120% base chance ลด DEF ศัตรูทุกตัว **45%** นาน 3 เทิร์น
- Quantum DMG = **380% ATK** AoE
- Energy +5 · Toughness 30

## Talent — Awaiting System Response... (Lv.10)
- สร้าง "Bug" 3 ชนิด: ATK **−10%**, DEF **−12%**, SPD **−6%**
- หลัง Silver Wolf โจมตีทุกครั้ง → 100% base chance ยัด "Bug" สุ่ม 1 อัน นาน 3 เทิร์น
- ศัตรูตาย → Weakness ที่ Silver Wolf ยัด ย้ายไปศัตรูตัวอื่นที่ยังไม่โดนยัด (Elite+ ก่อน)

## Technique — Force Quit Program
- เข้าฉากโจมตี AoE: Quantum DMG = **80% ATK** + ลด Toughness โดยไม่สน Weakness type; ศัตรูที่ break จากนี้ → trigger Quantum Weakness Break effect
- Toughness 20

---

## Major Traces
- **A2 — Generate**: Bug duration **+1 เทิร์น**. ศัตรู Weakness Broken → 100% base chance ยัด Bug สุ่ม
- **A4 — Inject**: ต้นการต่อสู้ → คืน Energy **20**. ต้นเทิร์นของ Silver Wolf → คืน Energy **5**
- **A6 — Side Note**: ทุก 10% Effect Hit Rate → Silver Wolf ATK **+10%** สูงสุด **+50%**

## Minor Traces (รวมทั้งหมด)
Effect HIT Rate +18% · ATK +28% · Quantum DMG +8%

## Eidolons
- **E1**: หลังใช้ Ult โจมตีศัตรู → คืน Energy **7 ต่อ debuff ที่เป้าหมายมี** (สูงสุด 5 ครั้ง/Ult)
- **E2**: ศัตรูเข้าฉาก → รับดาเมจเพิ่ม **+20%**. เมื่อศัตรูถูกเพื่อนโจมตี → 100% base chance Silver Wolf ยัด Bug สุ่ม
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: หลังใช้ Ult โจมตีศัตรู → Quantum Additional DMG = **20% ATK ต่อ debuff ที่เป้าหมายมี** (สูงสุด 5 ครั้ง/ศัตรู/Ult)
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: ต่อ debuff ที่เป้าหมายมี → Silver Wolf +DMG **+20%** สูงสุด **+100%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Weakness implant (Skill)**: 1 อัน/ศัตรู, type ตามเพื่อนลำดับแรก, + RES −20% ต่อ type + All-Type RES −13%; ย้ายเมื่อศัตรูตาย
- **Bug** (ATK/DEF/SPD down): ยัดสุ่มหลัง SW attack (A2 +1t, +on-break, E2 on-ally-attack)
- **Ult DEF −45%** AoE (3t)
- **debuff count scaling**: E6 (+20%/debuff DMG cap 100%), E4 (Additional DMG 20% ATK/debuff), E1 (energy 7/debuff)
- **A6**: ATK scaling จาก EHR (cap 50%)
- โค้ด: `Start_game_List` (`Silver Wolf.h:164`, `sw`) — technique + implant

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/silver-wolf — kit tab (review/calc patch 3.4, profile 01/Jun/2026)
