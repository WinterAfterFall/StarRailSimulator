# Yao Guang — เหยาก่วง

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Elation/YaoGuang.h` (โค้ดเรียก `"Yao Guang"`) |
| ธาตุ | **Physical** |
| Path | **Elation** |
| ระดับ | 5★ |
| Energy Ultimate | 180 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1242 · ATK 465 · DEF 654 · SPD 101

> Elation support/amplifier — Zone + Punchline + "Great Boon" follow-up

---

## Basic ATK — Whistlebolt Sings Joy (Blast, Lv.6)
- Physical DMG หลัก = **90% ATK**, ข้างเคียง = **30% ATK**
- Energy จาก Basic ATK เพิ่มเป็น **30**
- Toughness 10 (+5)

## Skill — Decalight Unveils All (Support, Lv.10)
- กาง **Zone** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Yao Guang)
- ขณะ Zone active: เพื่อนทุกคน Elation **+เท่ากับ 20% ของ Elation ของ Yao Guang**
- หลัง Yao Guang ใช้ BA/Skill → Punchline **+3**
- Energy +30

## Ultimate — Hexagram of Feathered Fortune (Support, 180 energy, Lv.10)
- Punchline **+5**
- Aha ได้เทิร์นพิเศษทันที 1 ครั้ง โดยนับ Punchline คงที่ **20** (E1 → 40) — เทิร์นนี้ไม่กิน Punchline
- เพื่อนทุกคน All-Type RES PEN **+20%** นาน 3 เทิร์น
- Energy +5

## Talent — Behold Wherever Light Unfolds (Support, Lv.10)
- ขณะถือ **"Certified Banger"**:
  - หลังเพื่อนโจมตี → trigger **"Great Boon"**: +1 instance ของ **20% Elation DMG** (Type ตามผู้โจมตี) ใส่เป้าหมายที่โดนสุ่ม 1 ตัว
  - ถ้าการโจมตีนั้นกิน Skill Point → trigger "Great Boon" เพิ่มอีก 1 ครั้ง
  - ถ้า Elation ของผู้โจมตี < Elation ของ Yao Guang → instance นี้ใช้ Elation ของ Yao Guang คำนวณ
- "Great Boon" ไม่นับเป็น 1 การโจมตี

## Technique — Untethered Glimmer Sails Far
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป trigger Skill อัตโนมัติ 1 ครั้ง โดยไม่กิน Skill Point

## Elation Skill — Let Thy Fortune Burst in Flames (AoE, Lv.10)
- ติด **"Woe's Whisper"** ศัตรูทุกตัว นาน 3 เทิร์น → รับดาเมจเพิ่ม **16%**
- **100% Physical Elation DMG** AoE + **5 instance × 20% Physical Elation DMG** ใส่ศัตรูสุ่ม
- Energy +5 · Toughness 5 (+20)

---

## Major Traces
- **A2 — Amaze-In Grace**: SPD ≥ 120 → Elation **+30%**; ทุก 1 SPD ที่เกิน → Elation **+1%** (นับ SPD ส่วนเกินสูงสุด 200)
- **A4 — Poised and Sated**: CRIT DMG **+60%**. หลังใช้ Elation Skill → คืน Skill Point **1** ให้ทีม
- **A6 — Felicity Ensemble**: เมื่อ Yao Guang ได้ "Certified Banger" → duration **+1 เทิร์น**

## Minor Traces (รวมทั้งหมด)
CRIT Rate +18.7% · SPD +9 · Elation +10%

## Eidolons
- **E1**: Aha extra turn จาก Ult → Punchline คงที่เพิ่มเป็น **40**. เมื่อสร้าง Elation DMG → เพื่อนทุกคนเพิกเฉย DEF **20%**
- **E2**: ขณะ Zone active → เพื่อนทุกคน SPD **+12%** + Elation **+16%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Elation Skill Lv. +1
- **E4**: ใน Aha extra turn จาก Ult ของ Yao Guang → ดาเมจ Elation Skill ของเพื่อนทุกคน = **150%** ของเดิม
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Elation Skill Lv. +1
- **E6**: เพื่อนทุกคน Elation DMG **+25%**. multiplier ของ Elation Skill ของ Yao Guang **+100%** ของเดิม

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Elation share**: Zone ให้เพื่อน +20% ของ Elation ของ Yao Guang (E2 +16% เพิ่ม); "Great Boon" ใช้ Elation ที่สูงกว่าคำนวณ
- **A2**: Elation scaling จาก SPD (≥120 → +30%, +1%/SPD เกิน, cap 200)
- **Punchline**: Skill BA/Skill +3, Ult +5; Aha extra turn นับ Punchline คงที่ 20/40
- **Great Boon**: follow-up 20% Elation DMG ต่อการโจมตีของเพื่อน + ซ้ำถ้ากิน SP — เข้ากับ `When_attack_List` / `AfterAhaInstant_List` ในโค้ด
- โค้ด `Start_game_List`: ถ้า `Technique` → สร้าง AllyBuffAction "YG Skill" (genPunchLine 3, energy 30, E2 buff SPD 12/Elation 16, Elation buff คำนวณ `calculateElationForBuff`), `addToActionBar` + `Deal_damage()` (self-flush)
- Elation Skill: Woe's Whisper (+16% vul) + A4 คืน SP 1

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/yao-guang — kit tab (review/calc patch 4.0, profile 15/Jun/2026)
