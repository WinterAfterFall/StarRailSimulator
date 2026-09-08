# Saber (Artoria) — เซเบอร์ (Fate/stay night collab)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Saber.h` |
| ธาตุ | **Wind** |
| Path | **Destruction** |
| ระดับ | 5★ (collab) |
| Energy Ultimate | 360 |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1241 · ATK 601 · DEF 654 · SPD 101

---

## Basic ATK — Invisible Air: Barrier of the Wind King (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Release, the Golden Scepter (AoE, Lv.6)
- ได้ **Core Resonance +2**
- Wind DMG = **150% ATK** ใส่ศัตรูทุกตัว
- ถ้าจำนวนศัตรู = 2/1 → เพิ่ม Wind DMG **150%/220% ATK** ใส่ศัตรูทุกตัว
- Energy +30 · Toughness 20

## Skill — Strike Air: Hammer of the Wind King (Blast, Lv.10)
- Wind DMG หลัก = **150% ATK**, ข้างเคียง = **75% ATK**
- ถ้ามี "Core Resonance" และการกิน Core Resonance หลัง Skill นี้จะเติม Energy เต็มพอดี → เพิ่ม multiplier ของ Skill ครั้งนี้ **+14% ต่อ stack** ของ Core Resonance และกิน Core Resonance ทั้งหมดเพื่อคืน Energy
- มิฉะนั้น → ได้ **Core Resonance +3**
- Energy +30 · Toughness 20 (+10)

## Ultimate — Excalibur (AoE, 360 energy, Lv.10)
- Wind DMG = **280% ATK** ใส่ศัตรูทุกตัว
- เพิ่ม **10 instance × 110% ATK** Wind DMG ใส่ศัตรูสุ่ม
- หลังใช้ Ult → Basic ATK ถัดไปเปลี่ยนเป็น "Release, the Golden Scepter" และใช้ได้แต่ท่านั้น
- Energy +5 · Toughness 20 (+40 ข้างเคียง)

## Talent — Dragon Reactor Core (Lv.10)
- เข้าฉาก → Core Resonance **+1**
- เมื่อเพื่อนคนใดใช้ Ultimate → Saber +DMG dealt **60%** นาน 2 เทิร์น + Core Resonance **+3**
- กิน Core Resonance 1 แต้ม → คืน Energy คงที่ **8**
- Energy +5

## Technique — Behold, the King of Knights
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป Saber ATK **+35%** นาน 2 เทิร์น + Core Resonance **+2**

---

## Major Traces
- **A2 — Knight of the Dragon**: CRIT Rate **+20%**. เข้าฉาก / ใช้ Enhanced BA → ได้ **'Mana Burst'**. ขณะมี Mana Burst ถ้ามี Core Resonance และ Skill+กิน Core Resonance จะเติม Energy เต็มพอดี → กิน Mana Burst คืน **Skill Point 1** ให้ทีม + Saber action ทันที
- **A4 — Blessing of the Lake**: สะสม excess Energy ได้สูงสุด **120**. หลังใช้ Ult → ล้าง excess แล้วคืนตามจำนวนนั้น. ต้นการต่อสู้ ถ้า Energy < 60% → เติมเป็น 60%
- **A6 — Crown of the Star**: ใช้ Skill → CRIT DMG **+50%** นาน 2 เทิร์น. ตลอดการต่อสู้ ทุก Core Resonance ที่ได้ → CRIT DMG **+4%** stack 8 ครั้ง

## Minor Traces (รวมทั้งหมด)
Wind DMG +22.4% · CRIT Rate +12% · HP +10%

## Eidolons
- **E1**: Ultimate DMG **+60%**. หลังใช้ BA/Skill → Core Resonance +1
- **E2**: ทุก Core Resonance ที่ได้ → ดาเมจเพิกเฉย DEF **1%** stack 15 ครั้ง. เมื่อ trigger Skill-multiplier effect → ทุก Core Resonance เพิ่ม multiplier ครั้งนั้น **+7%**
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: Wind RES PEN **+8%**. หลังใช้ Ult → Wind RES PEN **+4%** stack 3 ครั้ง
- **E5**: Skill Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: Ultimate DMG ได้ Wind RES PEN **+20%**. A4 overflow cap เพิ่มเป็น **200**. Ult ครั้งแรกหลังเข้าฉาก → คืน Energy คงที่ **300** (trigger ได้อีกทุก ๆ 3 Ult)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Energy = ทรัพยากรหลัก** (Ult cost 360). Talent: กิน Core Resonance 1 → +8 energy. A4/E6: overflow energy 120/200/300
- **Core Resonance**: ได้จาก Enhanced BA(+2), Skill(+3 ถ้าไม่ trigger), Talent (เข้าฉาก +1, เพื่อน Ult +3), Technique(+2), E1(+1 หลัง BA/Skill)
- **Skill conditional**: "ถ้ากิน Core Resonance หลัง Skill แล้ว energy เต็มพอดี" → Skill multiplier +14%/stack (+E2 7%/stack), กิน Core Resonance หมด; ไม่งั้น +3 Core Resonance — เงื่อนไข energy-math สำคัญมาก
- **Ult** → next BA locked เป็น Enhanced (AoE)
- **A6 CRIT DMG**: +4% ต่อ Core Resonance ที่เคยได้ (สะสมทั้งเกม stack 8)
- โค้ด: `Start_game_List` (energy 10, `Mana Flow` buff check, `CoreResonance(1)`; Technique → `CoreResonance(2)` + ATK% 35 buff)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/saber — kit tab (review/calc patch 3.4, profile 01/Jun/2026)
