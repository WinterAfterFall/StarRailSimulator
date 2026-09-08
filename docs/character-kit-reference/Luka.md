# Luka — ลูก้า

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Luka.h` |
| ธาตุ | **Physical** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.5 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 917 · ATK 582 · DEF 485 · SPD 103

> Nihility single-target DPS สาย Bleed + "Fighting Will" + DMG vulnerability

---

## Basic ATK — Direct Punch (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Sky-Shatter Fist (โจมตีเดี่ยว, Lv.6)
- กิน **Fighting Will 2 stacks**
- Direct Punch **3 hit × 20% ATK** + Rising Uppercut **1 hit × 80% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 20

## Skill — Lacerating Fist (โจมตีเดี่ยว, Lv.10)
- Physical DMG = **120% ATK** ใส่ศัตรู 1 ตัว
- 100% base chance ติด **Bleed** นาน 3 เทิร์น
- Bleed: Physical DoT ต้นทุกเทิร์น = **24% ของ Max HP ศัตรู** แต่ไม่เกิน **338% ATK ของ Luka**
- Energy +30 · Toughness 20

## Ultimate — Coup de Grâce (โจมตีเดี่ยว, 130 energy, Lv.10)
- ได้ **Fighting Will 2 stacks**
- 100% base chance ศัตรูเป้าหมายรับดาเมจเพิ่ม **+20%** นาน 3 เทิร์น
- Physical DMG = **330% ATK** ใส่เป้าหมาย
- Energy +5 · Toughness 30

## Talent — Flying Sparks (Lv.10)
- หลังใช้ Direct Punch หรือ Lacerating Fist → Fighting Will **+1** (สูงสุด 4)
- มี Fighting Will ≥ 2 → Direct Punch enhanced เป็น "Sky-Shatter Fist"
- หลัง Rising Uppercut ของ Enhanced BA โดนศัตรู Bleeding → Bleed ลงดาเมจทันที 1 ครั้ง = **85% ของดาเมจเดิม**
- ต้นการต่อสู้ → มี Fighting Will 1 stack

## Technique — Anticipator
- เข้าฉากโจมตี: Physical DMG = **50% ATK** ใส่ศัตรูสุ่ม + 100% base chance ติด Bleed (แบบ Skill) + Fighting Will **+1**
- Toughness 20

---

## Major Traces
- **A2 — Kinetic Overload**: ใช้ Skill → ลบ buff 1 อันจากเป้าหมาย
- **A4 — Cycle Braking**: ทุก Fighting Will ที่ได้ → คืน Energy **3**
- **A6 — Crush Fighting Will**: ใช้ Enhanced BA ทุก hit ของ Direct Punch → 50% fixed chance ตีเพิ่มอีก 1 hit (ไม่ apply กับ hit ที่เกิดจาก effect นี้)

## Minor Traces (รวมทั้งหมด)
ATK +28% · Effect HIT Rate +18% · DEF +12.5%

## Eidolons
- **E1**: เมื่อ Luka action ถ้าเป้าหมาย Bleeding → Luka +DMG **+15%** นาน 2 เทิร์น
- **E2**: ถ้า Skill โดนศัตรูที่มี Physical Weakness → Fighting Will **+1**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ทุก Fighting Will ที่ได้ → ATK **+5%** stack 4 ครั้ง
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: หลัง Rising Uppercut โดนศัตรู Bleeding → Bleed ลงดาเมจทันที = **8% ของดาเมจเดิม ต่อ hit ของ Direct Punch ที่ปล่อยไปแล้วใน Enhanced BA ครั้งนั้น**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Fighting Will** (0–4): +1 ต่อ Direct Punch/Skill, +2 Ult, +1 Technique, start 1 (E2 +1 conditional); ≥ 2 → BA enhanced, กิน 2/Enhanced BA
- **Bleed**: min(24% enemy Max HP, 338% ATK)/turn — HP-scaling DoT capped by ATK
- **Bleed detonation**: Talent 85% ของดาเมจเดิม หลัง Uppercut โดน bleeding (E6 +8%/Direct Punch hit)
- **A6**: 50% chance extra Direct Punch hit ต่อ hit (variance สูง)
- **Ult vulnerability +20%** (3t) — Luka มักเป็น trigger enabler ให้ Black Swan/Kafka
- **A4 energy**: +3 ต่อ Fighting Will → energy generation สูง
- โค้ด: `Start_game_List` (`Luka.h:140`, `lk`, `FW`) — start Fighting Will + technique

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/luka — kit tab (review patch 2.5, calc patch 3.4, profile 01/Jun/2026)
