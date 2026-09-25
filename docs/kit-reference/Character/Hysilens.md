# Hysilens (Helektra) — ไฮไซเลนส์

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Hysilens.h` |
| ธาตุ | **Physical** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 3.5) |

## Base Stats (Lv.80, ascended)
HP 1205 · ATK 601 · DEF 485 · SPD 102

> Nihility DoT support/sub-DPS สาย multi-DoT + Zone + vulnerability

---

## Basic ATK — Aeolian Mode: Echoes in Still Waters (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Overtone Hum: Chorus After Dark Tides (AoE, Lv.10)
- 100% base chance ศัตรูทุกตัวรับดาเมจเพิ่ม **+20%** นาน 3 เทิร์น
- Physical DMG = **140% ATK** AoE
- Energy +30 · Toughness 10

## Ultimate — Maelstrom Rhapsody (AoE, 110 energy, Lv.10)
- กาง **Zone**: ศัตรู ATK **−15%**, DEF **−25%**
- Physical DMG = **200% ATK** AoE
- ต่อ 1 instance ของ DoT ที่ศัตรูใน Zone รับ → Hysilens สร้าง Physical DoT = **80% ATK** ใส่ตัวนั้น
  - trigger ต้นทุกเทิร์น หรือหลังเพื่อนโจมตี 1 ครั้ง สูงสุด **8 ครั้ง** (ไม่ trigger ซ้ำ)
- Zone นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Hysilens); Hysilens ถูกน็อค → Zone หาย
- Energy +5 · Toughness 20

## Talent — Sirenic Serenade (Lv.10)
- เมื่อเพื่อนโจมตี → 100% base chance Hysilens ยัดสถานะ 1 อย่าง: **Wind Shear / Bleed / Burn / Shock** (เลือกที่ยังไม่มีก่อน)
- Wind Shear/Burn/Shock: DoT ต้นทุกเทิร์น = **25% ATK** (Wind/Fire/Lightning) นาน 2 เทิร์น
- Bleed: Physical DoT ต้นทุกเทิร์น = **20% ของ Max HP ศัตรู** แต่ไม่เกิน **25% ATK ของ Hysilens** นาน 2 เทิร์น

## Technique — At Ocean's Abode
- สร้าง Special Dimension 20 วิ (ศัตรู "Soulstruck" ไม่โจมตีเพื่อน)
- เข้าฉากกับศัตรู Soulstruck → 100% base chance ยัด 2 สถานะจาก Wind Shear/Bleed/Burn/Shock (แบบเดียวกับ Talent)

---

## Major Traces
- **A2 — The Gladius of Conquest**: ต้นการต่อสู้ → Hysilens กาง Zone (แบบ Ult) นาน 3 เทิร์น. ทุกครั้งที่กาง Zone → คืน Skill Point **1**
- **A4 — The Bubble of Banquets**: ใช้ Ult ถ้าเป้าหมายติด DoT → DoT ทั้งหมดบนเป้าหมายสร้างความเสียหายทันที = **150% ของดาเมจเดิม**
- **A6 — The Fiddle of Pearls**: ทุก 10% ของ Effect Hit Rate ที่เกิน **60%** → Hysilens +DMG **+15%** สูงสุด **+90%**

## Minor Traces (รวมทั้งหมด)
ATK +18% · SPD +14 · Effect HIT Rate +10%

## Eidolons
- **E1**: ขณะ Hysilens อยู่ในสนาม → เพื่อนทุกคนสร้าง DoT = **116%** ของเดิม. เมื่อ Talent ยัด Wind Shear/Bleed/Burn/Shock → 100% base chance ยัดเพิ่มอีก 1 instance (เหมือนเดิม, coexist ได้)
- **E2**: ขณะ Zone active → A6 DMG Boost apply ให้เพื่อนทุกคน
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ขณะ Zone active → ศัตรูทุกตัว All-Type RES **−20%**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ขณะ Zone active → cap ของ Physical DoT effect เพิ่มเป็น **12** + multiplier **+20%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Multi-DoT**: Talent ยัด 4 ชนิด (E1 ×2), แต่ละชนิด DoT 25% ATK/2t; Bleed = min(20% enemy Max HP, 25% ATK)
- **Zone reactive DoT**: 80% ATK ต่อ DoT instance ที่ศัตรูรับ, cap 8/turn (E6 12, +20%), trigger ต้นเทิร์น/หลัง ally attack
- **A4**: Ult → detonate DoT 150%
- **Vulnerability**: Skill +20% DMG taken (3t) + Ult Zone ATK/DEF shred
- **A6**: DMG scaling จาก EHR เกิน 60% (cap 90%, E2 → ทีม)
- โค้ด: `Start_game_List` (`Hysilens.h:191`, `hys`, `Talent`, `E1`) — A2 Zone ต้นการต่อสู้ + SP

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/hysilens — kit tab (review/calc patch 3.5, profile 01/Jun/2026)
