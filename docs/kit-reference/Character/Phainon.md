# Phainon / Khaslana — ไฟนอน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Phainon.h` |
| ธาตุ | **Physical** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 12 (ใช้ Coreflame เป็นทรัพยากรหลัก) |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1433 · ATK 582 · DEF 703 · SPD 94

> **หมายเหตุ:** kit ซับซ้อนมาก ข้อความบน prydwen มีสลับชื่อ state ("Soulscorch" / "Soulrending Blaze" / "Scourge") — ตรวจกับ fandom เพิ่มก่อน implement

---

## โหมด Phainon (ปกติ)

### Basic ATK — Stride to Deliverance (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** · Energy +0 · Toughness 10

### Skill — Let There Be Light (Blast, Lv.10)
- ได้ **Coreflame +2**
- Physical DMG หลัก = **300% ATK**, ข้างเคียง = **120% ATK**
- Energy +0 · Toughness 20 (+10)

### Talent (Phainon) — Pyric Corpus
- **Coreflame** ครบ **12** → ใช้ Ultimate ได้ เก็บ overflow ได้อีก 3 แต้ม (คืนหลังจบร่าง)
- เมื่อ Phainon เป็นเป้าของ ability ใด ๆ → Coreflame **+1**; ถ้าผู้ใช้เป็นเพื่อน → Phainon CRIT DMG **+30%** นาน 3 เทิร์น

### Technique — Beginning of the End
- อยู่ในทีม → Max Technique Points **+3**
- ใช้ Technique: กิน 2 TP, โจมตี AoE; เข้าฉาก → คืน Energy **25** ให้ทีม + ได้ Scourge **2** + Skill Point **1**
- ต้นแต่ละ wave: Physical DMG = **200% ATK** AoE

---

## โหมด Khaslana (หลังแปลงร่าง / Ultimate)

### Ultimate — He Who Bears the World Must Burn (AoE, 12 energy, Lv.10)
- แปลงเป็น **Khaslana**, กาง Territory: เพื่อนคนอื่นกลายเป็น **Departed** (ทำอะไรไม่ได้), ศัตรูทุกตัวติด Physical Weakness
- Khaslana ไม่มีเทิร์นของตัวเอง แต่มี **Khaslana's extra turn 8 ครั้ง** SPD คงที่ = **60% ของ base SPD** ของ Khaslana
- ต้นของ extra turn สุดท้าย → **Final Hit**: Physical Ultimate DMG = **960% ATK** กระจายเท่า ๆ กันทุกศัตรู
- Energy +0 · Toughness 20

### Talent (Khaslana) — Fate: Divine Vessel
- ตอนแปลงร่าง: ได้ Scourge **4**; ถ้าเป็นเทิร์นเพื่อน → ยืด buff เพื่อนคนนั้น 1 เทิร์น + จบเทิร์นปัจจุบัน
- Khaslana ภูมิคุ้มกัน CC, มี Enhanced BA 1 + Enhanced Skill 2, ใช้ Ult ไม่ได้
- ขณะแปลงร่าง: **ATK +80%, Max HP +270%**; หลังโจมตี → ฮีล **20% Max HP**
- โดน killing blow → ไม่ล้ม, ฮีล **25% Max HP**, ยิง Final Hit ทันที
- ทุก extra turn ที่เหลือ → Final Hit multiplier ลด **12.5%** ของ multiplier เดิม
- จบการแปลงร่าง → เพื่อนทุกคน SPD **+15%** นาน 1 เทิร์น

### Enhanced Basic ATK — Creation: Bloodthorn Ferry (Blast, Lv.6)
- ได้ **Scourge +2**
- Physical DMG หลัก = **250% ATK**, ข้างเคียง = **75% ATK**
- Toughness 30 (+20)

### Enhanced Skill 1 — Calamity: Soulscorch Edict (Enhance, Lv.10)
- ได้ Scourge = จำนวนศัตรู + **Soulscorch 1 stack**, บังคับศัตรูทุกตัว action ทันที
- ขณะ Soulscorch: Khaslana รับดาเมจ **-75%**; หลังศัตรู attack/action → Soulscorch +1 stack
- หลังศัตรู action → ยิง Counter: Physical DMG = **40% ATK** AoE + เพิ่ม **4 instance × 30% ATK**
- แต่ละ stack เพิ่ม multiplier ของ Counter **+20%** ของ multiplier เดิม
- ดาเมจนับเป็น Skill DMG; ถ้า state ยัง active ตอนต้น extra turn → ยิง Counter ทันที
- Toughness 10 (+5)

### Enhanced Skill 2 — Foundation: Stardeath Verdict (Enhance, Lv.10)
- ล้าง debuff ตัวเอง
- Physical DMG สูงสุด = **1170% ATK**
- ต่อ Scourge ที่กิน: 4 instance × **45% ATK** ใส่ศัตรูสุ่ม
- กิน Scourge ครบ 4 → เพิ่ม Physical DMG **450% ATK** กระจายเท่ากันทุกศัตรู
- Toughness 3 (+20)

---

## Major Traces
- **A2 — March to Oblivion**: ต้นการต่อสู้ → Coreflame +1; จบการแปลงร่าง → Coreflame +3
- **A4 — Bide in Flames**: รับ heal/Shield จากเพื่อน → +DMG dealt **45%** นาน 4 เทิร์น (ไม่ซ้ำในเทิร์นเดียว). รับ Energy regen จากเพื่อน → Coreflame +1
- **A6 — Shine with Valor**: เข้าฉาก หรือจบการแปลงร่าง → ATK **+50%** stack ได้ 2 ครั้ง

## Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · CRIT DMG +37.3% · SPD +5

## Eidolons
- **E1**: SPD inheritance ratio ของ extra turn เพิ่มเป็น **66%** +1.5% ต่อศัตรูที่ฆ่า สูงสุด 84%. ใช้ Ult → CRIT DMG **+50%** นาน 3 เทิร์น
- **E2**: Physical RES PEN **+20%**. กิน Scourge 4 ใช้ "Foundation" → ได้เทิร์นพิเศษ
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ใช้ "Calamity: Soulscorch Edict" → ได้ Soulscorch เพิ่ม **4 stacks**
- **E5**: Skill Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: Coreflame overflow ไม่มี cap. ต้นการต่อสู้ → Coreflame +6. หลัง "Foundation" attack → True DMG = **36% ของดาเมจรวมในการโจมตีนั้น** ใส่ศัตรู HP สูงสุด

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **2 โหมด**: Phainon (Coreflame gen) → transform → Khaslana (8 extra turns, ไม่มีเทิร์นปกติ, teammates Departed)
- **Coreflame** เกน: Skill +2, ถูก target โดย ability +1, A2 (+1 start, +3 end), A4 (energy regen +1), E6 (+6 start). ครบ 12 → Ult
- **Khaslana extra turn** SPD = 60% base (E1 เป็น 66%→84%)
- **Final Hit** multiplier 960% base, ลด 12.5% ต่อ extra turn ที่เหลือ (ยิงเร็ว = แรงกว่า)
- **Scourge** (0–4): ใช้กับ "Foundation" — 4 instance × 45% ต่อ stack + bonus 450% ถ้าครบ 4
- **Khaslana transform buff**: ATK +80%, Max HP +270%, heal 20% หลัง attack
- โค้ด: `Start_game_List` (E→genSkillPoint, Scourge(2), energy 25 ทีม, CoreFlame(3), E6 CoreFlame(6)) + `Start_wave_List` (Technique 200% AoE, self-flush)
- `CoreFlame`, `Scourge` เป็น callback ที่รับ int — sim ต้อง track resource เอง

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/phainon — kit tab (review/calc patch 3.4, profile 01/Jun/2026)
