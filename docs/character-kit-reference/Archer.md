# Archer (EMIYA) — อาร์เชอร์ (Fate/stay night collab)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/The Hunt/Archer.h` |
| ธาตุ | **Quantum** |
| Path | **The Hunt** |
| ระดับ | 5★ (collab) |
| Energy Ultimate | 220 |
| อ้างอิง | prydwen.gg (review patch 3.4 / calc patch 4.4) |

## Base Stats (Lv.80, ascended)
HP 1164 · ATK 620 · DEF 485 · SPD 105

> The Hunt single-target DPS สาย Skill-spam ("Circuit Connection") + Skill Point economy + "Charge" FUA

---

## Basic ATK — Kanshou and Bakuya (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Caladbolg II: Fake Spiral Sword (โจมตีเดี่ยว, Lv.10)
- เข้าสถานะ **"Circuit Connection"**
- Quantum DMG = **360% ATK** ใส่เป้าหมาย
- ใช้ Skill ขณะอยู่ในสถานะ → **เทิร์นปัจจุบันไม่จบ** + Skill DMG **+100%** (stack 2 ครั้ง, อยู่จนออกจากสถานะ)
- ใช้ Skill ครบ **5 ครั้ง** หรือ Skill Point ไม่พอ → ใช้ Skill อีกครั้ง = ออกจากสถานะ
- ออกจากสถานะเมื่อฆ่าศัตรูหมดใน wave
- Energy +30 · Toughness 20

## Ultimate — Unlimited Blade Works (โจมตีเดี่ยว, 220 energy, Lv.10)
- Quantum DMG = **1000% ATK** ใส่เป้าหมาย + Charge **+2** (สูงสุด 4)
- Energy +5 · Toughness 30

## Talent — Mind's Eye (True) (Lv.10)
- เมื่อเพื่อนโจมตีศัตรู → Archer กิน **Charge 1** + ยิง Follow-up ATK ใส่เป้าหมายหลัก: Quantum DMG = **200% ATK** + คืน Skill Point **1**
- ถ้าเป้าตายก่อน → ยิงใส่ศัตรูสุ่ม
- Energy +5 · Toughness 10

## Technique — Clairvoyance
- เข้าฉากโจมตี: Quantum DMG = **200% ATK** AoE + Charge **+1**

---

## Major Traces
- **A2 — Projection Magecraft**: ขณะ Archer อยู่ในสนาม → Max Skill Point **+2**
- **A4 — Hero of Justice**: Archer เข้าฉาก → Charge **+1**
- **A6 — Guardian**: หลังเพื่อนได้ Skill Point ถ้ามี Skill Point ≥ 4 → Archer CRIT DMG **+120%** นาน 1 เทิร์น

## Minor Traces (รวมทั้งหมด)
Quantum DMG +22.4% · ATK +18% · CRIT Rate +6.7%

## Eidolons
- **E1 — The Unreached Dream**: ใช้ Skill 3 ครั้งในเทิร์นเดียว → คืน Skill Point **2** ให้ทีม
- **E2 — The Unfulfilled Happiness**: ใช้ Ult → ลด Quantum RES เป้าหมาย **20%** + induce Quantum Weakness นาน 2 เทิร์น
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4 — The Unsung Life**: Ultimate DMG **+150%**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6 — The Endless Pilgrimage**: ต้นเทิร์น → คืน Skill Point **1** ให้ทีม. Skill DMG boost stack cap **+1** (รวม 3). Skill DMG เพิกเฉย DEF **20%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Circuit Connection**: Skill 360% ATK; ใช้ในสถานะ = เทิร์นไม่จบ (spam ได้) + Skill DMG +100%/stack (cap 2, E6 3); ออกเมื่อ Skill 5 ครั้ง / SP หมด / wave clear
- **Skill Point economy** = แกน: A2 Max SP +2, Talent FUA คืน 1, E1 (3 skills/turn → +2), E6 (+1/turn), A6 (CD +120% ถ้า SP ≥ 4)
- **Charge** (0–4): Ult +2, Technique +1, A4 +1; Talent กิน 1 ต่อการโจมตีของเพื่อน → FUA 200% ATK
- **Ult 1000% ATK** single target (E4 +150%, E2 RES −20%)
- โค้ด: `Start_game_List` priority `PRIORITY_IMMEDIATELY` (`Archer.h:130`, `ac`, `Charge`) — `Charge(1)` + Technique attack + self-flush `Deal_damage()`
- **หมายเหตุ**: element/path ในโค้ด (Quantum/Hunt) ตรงกับเกมจริง

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/archer — kit tab (review patch 3.4, calc patch 4.4, profile 01/Jun/2026)
