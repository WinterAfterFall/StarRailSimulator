# Pela — เพลา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Pela.h` |
| ธาตุ | **Ice** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.3) |

## Base Stats (Lv.80, ascended)
HP 987 · ATK 546 · DEF 463 · SPD 105

> Nihility debuffer สาย DEF shred (Exposed) + buff strip

---

## Basic ATK — Frost Shot (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Frostbite (Impair, Lv.10)
- ลบ buff 1 อัน + Ice DMG = **210% ATK** ใส่ศัตรู 1 ตัว
- Energy +30 · Toughness 20

## Ultimate — Zone Suppression (Impair, 110 energy, Lv.10)
- Ice DMG = **100% ATK** AoE + 100% base chance ติด **Exposed** ศัตรูทุกตัว
- Exposed: DEF **−40%** นาน 2 เทิร์น
- Energy +5 · Toughness 20

## Talent — Data Collecting (Lv.10)
- ถ้าศัตรูติด debuff หลัง Pela โจมตี → Pela คืน Energy เพิ่ม **10** (1 ครั้ง/การโจมตี)

## Technique — Preemptive Strike
- เข้าฉากโจมตี: Ice DMG = **80% ATK** ใส่ศัตรูสุ่ม + 100% base chance ลด DEF ศัตรูทุกตัว **20%** นาน 2 เทิร์น
- Toughness 20

---

## Major Traces
- **A2 — Bash**: สร้างดาเมจกับศัตรูที่ติด debuff **+20%**
- **A4 — The Secret Strategy**: ขณะ Pela อยู่ในสนาม → เพื่อนทุกคน Effect Hit Rate **+10%**
- **A6 — Wipe Out**: ใช้ Skill ลบ buff → การโจมตีครั้งถัดไปของ Pela **+DMG 20%**

## Minor Traces (รวมทั้งหมด)
Ice DMG +22.4% · ATK +18% · Effect HIT Rate +10%

## Eidolons
- **E1**: ศัตรูตาย → Pela คืน Energy **5**
- **E2**: ใช้ Skill ลบ buff → SPD **+10%** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: ใช้ Skill → 100% base chance ลด Ice RES เป้าหมาย **12%** นาน 2 เทิร์น
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Pela ตีศัตรูที่ติด debuff → Additional Ice DMG = **40% ATK**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Exposed (Ult)**: DEF −40% AoE, 2t — DEF shred หลัก
- **Talent energy**: +10 ถ้าศัตรูมี debuff หลัง Pela attack (1/attack) — energy engine
- **A2 / E6**: DMG amp / Additional DMG vs debuffed enemy
- **A4**: EHR +10% ทีม
- Technique DEF −20% AoE
- โค้ด: `Start_game_List` (`Pela.h:63`) — technique DEF shred

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/pela — kit tab (review patch 2.6, calc patch 3.3, profile 01/Jun/2026)
