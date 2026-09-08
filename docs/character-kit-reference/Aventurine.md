# Aventurine — เอเวนจูริน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Preservation/Aventurine.h` |
| ธาตุ | **Imaginary** |
| Path | **Preservation** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1203 · ATK 446 · DEF 654 · SPD 106

> Preservation tank/sub-DPS สาย DEF-scaling + shield + "Blind Bet" FUA

---

## Basic ATK — Straight Bet (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ของ DEF** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Cornerstone Deluxe (Defense, Lv.10)
- มอบ **Fortified Wager** shield ให้เพื่อนทุกคน = **24% ของ DEF + 320** นาน 3 เทิร์น
- ได้ shield ซ้ำ → stack ได้ สูงสุด **200% ของ shield จาก Skill ปัจจุบัน**
- Energy +30

## Ultimate — Roulette Shark (โจมตีเดี่ยว, 110 energy, Lv.10)
- สุ่มได้ **Blind Bet 1–7 แต้ม**
- ติด **Unnerved** เป้าหมาย นาน 3 เทิร์น
- Imaginary DMG = **270% ของ DEF** ใส่เป้าหมาย
- เมื่อเพื่อนตีศัตรู Unnerved → CRIT DMG ที่ทำ **+15%**
- Energy +5 · Toughness 30

## Talent — Shot Loaded Right (Bounce, Lv.10)
- เพื่อน 1 ตัวที่มี Fortified Wager → Effect RES **+50%**; เมื่อเพื่อนคนนั้นถูกโจมตี → Aventurine ได้ Blind Bet **+1** (trigger อีกได้หลัง 2 เทิร์น)
- ขณะ Aventurine มี Fortified Wager → ต้าน CC
- Aventurine ถูกโจมตี → Blind Bet **+1**
- Blind Bet ครบ **7** → กิน 7, ยิง **7-hit follow-up** แต่ละ hit = **25% ของ DEF** Imaginary DMG ใส่ศัตรูสุ่ม
- Blind Bet cap **10**
- Energy +1 · Toughness 3

## Technique — The Red or the Black
- หลังใช้ Technique → ได้ 1 ใน: DEF +24% (chance) / +36% (high chance) / +60% (small chance)
- ใช้ซ้ำ → เก็บค่าสูงสุด
- เริ่มการต่อสู้ถัดไป → เพื่อนทุกคน DEF +ค่านั้น นาน 3 เทิร์น

---

## Major Traces
- **A2 — Leverage**: ทุก 100 DEF ที่เกิน **1600** → Aventurine CRIT Rate **+2%** สูงสุด **+48%**
- **A4 — Hot Hand**: ต้นการต่อสู้ → มอบ Fortified Wager ให้เพื่อนทุกคน = **100% ของ shield จาก Skill** นาน 3 เทิร์น
- **A6 — Bingo!**: หลังเพื่อนที่มี Fortified Wager ยิง follow-up → Aventurine Blind Bet **+1** (สูงสุด 3 ครั้ง, reset ต้นเทิร์นของ Aventurine). หลัง Aventurine ยิง Talent FUA → มอบ Fortified Wager ให้เพื่อนทุกคน = **7.2% ของ DEF + 96** + ให้เพื่อนที่ shield น้อยสุดอีก 1 อัน (7.2% DEF + 96) นาน 3 เทิร์น

## Minor Traces (รวมทั้งหมด)
DEF +35% · Imaginary DMG +14.4% · Effect RES +10%

## Eidolons
- **E1**: เพื่อนที่มี Fortified Wager → CRIT DMG **+20%**. หลังใช้ Ult → มอบ Fortified Wager ให้เพื่อนทุกคน = **100% ของ shield จาก Skill** นาน 3 เทิร์น
- **E2**: ใช้ Basic ATK → ลด All-Type RES เป้าหมาย **12%** นาน 3 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: เมื่อ trigger Talent FUA → Aventurine DEF **+40%** นาน 2 เทิร์น + Hits Per Action ของ Talent FUA **+3** (รวม 10)
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ต่อเพื่อนที่มี Shield → Aventurine +DMG **+50%** สูงสุด **+150%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ DEF** (BA 100%, Ult 270%, Talent FUA 25%/hit)
- **Fortified Wager shield**: 24% DEF + 320 (Skill), stack cap 200% Skill; A4/E1 = 100% Skill ให้ฟรี; A6 = 7.2% DEF + 96
- **Blind Bet** (0–10): Ult (1–7 สุ่ม), ถูกโจมตี (+1), เพื่อน shield ถูกตี (+1), A6 (+1×3); ครบ 7 → 7-hit FUA (E4 10-hit)
- **A2**: CRIT Rate จาก DEF เกิน 1600 (cap 48%)
- **Unnerved (Ult)**: เพื่อนตี → CRIT DMG +15%
- **E6**: DMG amp จากจำนวนเพื่อนที่มี shield (cap 150%)
- โค้ด: `Aventurine.h` — ตรวจ shield model + `Start_game_List` (A4)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/aventurine — kit tab (review/calc patch 4.0, profile 01/Jun/2026)
