# Anaxa (Anaxagoras) — อนาซา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Anaxa.h` |
| ธาตุ | **Wind** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 4.3) |

## Base Stats (Lv.80, ascended)
HP 970 · ATK 756 · DEF 557 · SPD 97

> Erudition DPS สาย weakness-implant — ยัด weakness ทุก type แล้วเก็บ bonus

---

## Basic ATK — Pain, Brews Truth (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Fractal, Exiles Fallacy (Bounce, Lv.10)
- Wind DMG = **70% ATK** ใส่เป้าหมาย + เพิ่ม **4 instance × 70% ATK** ใส่ศัตรูสุ่ม (bounce เลี่ยงตัวที่โดนแล้วในรอบนี้)
- เมื่อใช้: ต่อจำนวนศัตรูที่ตีได้ในสนาม → Skill นี้ +DMG dealt **20%** ต่อตัว
- Energy +6 · Toughness 10 (ทุก instance)

## Ultimate — Sprouting Life Sculpts Earth (AoE, 140 energy, Lv.10)
- ติด **"Sublimation"** ศัตรูทุกตัว → Wind DMG = **160% ATK** AoE
- Sublimation: ติด Weakness ทั้ง 7 type (Physical/Fire/Ice/Lightning/Wind/Quantum/Imaginary) จนถึงต้นเทิร์นของเป้าหมาย; ถ้าไม่มี Control RES → ทำ action ไม่ได้ระหว่าง Sublimation
- Energy +5 · Toughness 20

## Talent — Tetrad Wisdom Reigns Thrice (Lv.10)
- ทุกครั้งที่ Anaxa ตีโดน 1 hit → ยัด Weakness type สุ่ม 1 อัน นาน 3 เทิร์น (เลือก type ที่เป้าหมายยังไม่มีก่อน)
- ขณะ Anaxa อยู่ในสนาม: ศัตรูที่มี Weakness ≥ 5 type → ติด **"Qualitative Disclosure"**
  - Anaxa สร้างดาเมจกับตัวที่ติด **+30%**
  - หลังใช้ BA/Skill ใส่ตัวนั้น → ปล่อย Skill เพิ่ม 1 instance (ไม่กิน SP, ไม่ re-trigger effect; ถ้าเป้าตายก่อน → ยิงใส่ศัตรูสุ่ม)

## Technique — Prism of the Pupil
- ติด Terrified ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Terrified → ถือว่าเข้าฉากแบบตี Weakness เสมอ + Anaxa ยัด Weakness type ของผู้โจมตี 1 อันให้ศัตรูทุกตัว นาน 3 เทิร์น

---

## Major Traces
- **A2 — Roaming Signifier**: ใช้ BA → คืน Energy **10**. ต้นเทิร์น ถ้าไม่มีศัตรูติด "Qualitative Disclosure" → คืน Energy **30** ทันที
- **A4 — Imperative Hiatus**: ตามจำนวนตัวละคร Erudition ในทีม — 1 ตัว: Anaxa CRIT DMG **+140%**; ≥ 2 ตัว: เพื่อนทุกคน +DMG dealt **50%**
- **A6 — Qualitative Shift**: ต่อ Weakness type ที่เป้าหมายมี → Anaxa ดาเมจเพิกเฉย DEF **4%** (สูงสุด 7 type = 28%)

## Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · HP +10% · Wind DMG +22.4%

## Eidolons
- **E1**: ใช้ Skill ครั้งแรก → คืน Skill Point **1**. ใช้ Skill โดนศัตรู → ลด DEF เป้าหมาย **16%** นาน 2 เทิร์น
- **E2**: ศัตรูเข้าสนาม → trigger Talent weakness implant 1 ครั้ง + ลด All-Type RES **20%**
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ใช้ Skill → ATK **+30%** นาน 2 เทิร์น stack 2 ครั้ง
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ดาเมจของ Anaxa = **130%** ของเดิม. A4 ทั้ง 2 effect trigger ทันทีโดยไม่สนจำนวน Erudition

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Weakness implant ทุก hit** (Talent) — ทุก instance ของ Skill bounce ก็ยัด weakness — โค้ดมี `weaknessApply` / `Weakness Aplly function` (มี fix commit ล่าสุด)
- **Qualitative Disclosure** = threshold 5 weakness types → +30% DMG + follow-up Skill (ไม่กิน SP, ไม่ recursion)
- **Skill DMG scaling**: base 70% + (20% × จำนวนศัตรู) DMG-dealt bonus
- **A6 DEF ignore**: 4% × weakness type count (cap 7)
- **A2 energy**: BA +10, +30 conditional ต้นเทิร์น
- **Ult Sublimation**: 7-type weakness + soft CC (ถ้าไม่มี Control RES)
- **A4** ผูกกับ Erudition count → E6 unlock ทั้งคู่; โค้ด `Start_game_List` (`Anaxaptr`, allEventAdjustStats)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/anaxa — kit tab (review patch 3.2, calc patch 4.3, profile 01/Jun/2026)
