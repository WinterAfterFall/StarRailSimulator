# Serval — เซอร์วัล

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Serval.h` |
| ธาตุ | **Lightning** |
| Path | **Erudition** |
| ระดับ | 4★ |
| Energy Ultimate | 100 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 917 · ATK 652 · DEF 374 · SPD 104

> Erudition DoT/DPS สาย Shock

---

## Basic ATK — Roaring Thunderclap (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Lightning Flash (Blast, Lv.10)
- Lightning DMG หลัก = **140% ATK**, ข้างเคียง = **60% ATK**
- 80% base chance → ศัตรูที่โดนติด **Shocked** นาน 2 เทิร์น
- Shocked: Lightning DoT = **104% ATK** ต้นทุกเทิร์น
- Energy +30 · Toughness 20 (+10)

## Ultimate — Here Comes the Mechanical Fever (AoE, 100 energy, Lv.10)
- Lightning DMG = **180% ATK** AoE
- ศัตรูที่ Shocked อยู่แล้ว → ยืด Shock **+2 เทิร์น**
- Energy +5 · Toughness 20

## Talent — Galvanic Chords (Lv.10)
- หลัง Serval โจมตี → Additional Lightning DMG = **72% ATK** ใส่ศัตรู Shocked ทุกตัว

## Technique — Good Night, Belobog
- เข้าฉากโจมตีทันที: Lightning DMG = **50% ATK** ใส่ศัตรูสุ่ม + 100% base chance ศัตรูทุกตัวติด **Shocked** นาน 3 เทิร์น
- Shock (จาก Technique): Lightning DoT = **50% ATK** ต้นทุกเทิร์น
- Toughness 20

---

## Major Traces
- **A2 — Rock 'n' Roll**: Skill มี base chance ติด Shock **+20%**
- **A4 — String Vibration**: ต้นการต่อสู้ → คืน Energy **15** ทันที
- **A6 — Mania**: ฆ่าศัตรู → ATK **+20%** นาน 2 เทิร์น

## Minor Traces (รวมทั้งหมด)
Effect HIT Rate +18% · CRIT Rate +18.7% · Effect RES +10%

## Eidolons
- **E1 — Echo Chamber**: Basic ATK → Lightning DMG = **60% ของดาเมจ Basic ATK** ใส่ศัตรูข้างเคียงสุ่ม 1 ตัว
- **E2 — Encore!**: ทุกครั้งที่ Talent trigger Additional DMG → คืน Energy **4**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4 — Make Some Noise!**: Ultimate มี 100% base chance ติด Shock ให้ศัตรูที่ยังไม่ Shocked (effect เหมือน Skill)
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Serval สร้างดาเมจกับศัตรู Shocked **+30%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Shock** = DoT debuff: Skill 104% ATK/2t (E4 Ult ก็ติด), Technique 50% ATK/3t; Ult ยืด +2t
- **Talent**: post-attack Additional 72% ATK ใส่ Shocked ทุกตัว — trigger บ่อย (`When_attack_List`)
- E1: BA splash 60% ของดาเมจ BA (ไม่ใช่ % ATK) ใส่ข้างเคียง
- E2: energy +4 ต่อ Talent trigger
- E6 / A6: DMG amp vs Shocked / on-kill ATK
- โค้ด: `Start_game_List` priority `PRIORITY_ACTTACK` (`Serval.h:90`) — น่าจะ technique attack + self-flush

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/serval — kit tab (review patch 2.6, calc patch 4.0, profile 01/Jun/2026)
