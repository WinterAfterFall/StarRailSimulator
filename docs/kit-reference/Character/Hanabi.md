# Sparkle — สปาร์เคิล  (codename ในโค้ด: **Hanabi**, ชื่อ JP: 花火)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Hanabi.h` (มีเวอร์ชันเก่า `HanabiV1.h` — ข้าม) |
| ธาตุ | **Quantum** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1397 · ATK 523 · DEF 485 · SPD 101

> Harmony support สาย Skill Point battery + CRIT DMG + turn advance

---

## Basic ATK — Monodrama (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Dreamdiver (Support, Lv.10)
- เพื่อน 1 ตัว CRIT DMG **+เท่ากับ 24% ของ CRIT DMG ของ Sparkle + 45%** นาน 2 เทิร์น
- advance action เพื่อนคนนั้น **50%**
- ใช้ใส่ตัวเอง → ไม่ได้ Action Advance
- Energy +30

## Ultimate — The Hero with a Thousand Faces (Support, 110 energy, Lv.10)
- คืน **Skill Point 6** ให้ทีม
- ถ้า SP overflow → บันทึกส่วนเกินสูงสุด **10**; เมื่อจบเทิร์นเพื่อน ถ้า SP < max → กินค่าที่บันทึกไว้เติม SP
- มอบ **"Cipher"** ให้เพื่อนทุกคน — เพื่อนที่มี Cipher: ต่อ stack ของ DMG Boost จาก Talent → เพิ่มอีก **+6%/stack** นาน 3 เทิร์น
- Energy +5

## Talent — Red Herring (Lv.10)
- ขณะ Sparkle อยู่ในสนาม → Max Skill Points **+2**
- ทุกครั้งเพื่อนกิน 1 Skill Point → Sparkle ได้ **"Figment" 1 stack** — ต่อ stack: ศัตรูทุกตัวรับดาเมจเพิ่ม **+4%** นาน 2 เทิร์น stack 3 ครั้ง

## Technique — Unreliable Narrator
- มอบ Misdirect ให้เพื่อนทุกคน 20 วิ
- เข้าฉากใน Misdirect → คืน Skill Point **3** ให้ทีม + Sparkle คืน Energy **20**

---

## Major Traces
- **A2 — Almanac**: ใช้ BA → คืน Energy **10**. เมื่อเพื่อนที่ถือ CRIT DMG Boost จาก Skill กิน Skill Point → Sparkle คืน Energy **1**
- **A4 — Artificial Flower**: ถ้าเพื่อนกิน ≥ 3 Skill Point ในเทิร์นเดียว → Skill ครั้งถัดไปของ Sparkle ไม่กิน Skill Point
- **A6 — Nocturne**: เพื่อนทุกคน ATK **+45%**. เพื่อนที่ถือ CRIT DMG Boost จาก Skill → All-Type RES PEN **+10%**

## Minor Traces (รวมทั้งหมด)
HP +28% · CRIT DMG +24% · Effect RES +10%

## Eidolons
- **E1**: เพื่อนที่มี "Cipher" ATK **+40%**. ต้นการต่อสู้ หรือใช้ Skill → Sparkle SPD **+15%** นาน 2 เทิร์น
- **E2**: ทุก stack ของ Talent → ลด DEF ศัตรู **10%** เพิ่ม
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: Ult คืน Skill Point **+1** (รวม 7). Talent → Max Skill Points **+1** เพิ่ม
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: CRIT DMG Boost จาก Skill → เพิ่มอีก **30% ของ CRIT DMG ของ Sparkle**. ใช้ Skill → Boost apply ให้เพื่อนที่มี "Cipher" ทั้งหมด. ใช้ Ult → เพื่อน 1 ตัวที่มี Boost กระจาย Boost ให้เพื่อนที่มี "Cipher"

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill Point economy** เป็นแกน: Max SP +2 (E4 +1), Ult คืน 6 (E4 7) + overflow bank 10, Technique +3
- **Skill CRIT DMG buff**: 0.24 × (CD ของ Sparkle) + 45% (E6 +0.30×CD) — ผูกกับ CD ของ Sparkle
- **Figment/Talent** vulnerability: +4%/stack (cap 3), Cipher → +6%/stack เพิ่ม, E2 → −10% DEF/stack
- **Skill action advance 50%** (ไม่ทำงานตอน self-target)
- โค้ด: `Start_game_List` (`Hanabi.h:141`) — น่าจะ technique SP/energy
- ระวัง: `HanabiV1.h` เป็น implement เก่า อย่าอ้างอิง

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sparkle — kit tab (review/calc patch 4.0, profile 01/Jun/2026)
