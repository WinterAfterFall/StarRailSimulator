# Tribbie (Tribios) — ทริบบี้

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Tribbie.h` |
| ธาตุ | **Quantum** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 3.1) |

## Base Stats (Lv.80, ascended)
HP 1047 · ATK 523 · DEF 727 · SPD 96

> Harmony support/sub-DPS สาย HP-scaling + RES PEN + vulnerability Zone (ดาเมจสเกลกับ Max HP)

---

## Basic ATK — Hundred Rockets (Blast, Lv.6)
- Quantum DMG หลัก = **30% Max HP**, ข้างเคียง = **15% Max HP**
- Energy +20 · Toughness 10 (+5)

## Skill — Where'd the Gifts Go (Support, Lv.10)
- ได้ **"Numinosity"** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Tribbie)
- ขณะมี Numinosity: เพื่อนทุกคน All-Type RES PEN **+24%**
- Energy +30

## Ultimate — Guess Who Lives Here (AoE, 120 energy, Lv.10)
- กาง **Zone** + Quantum DMG = **30% Max HP** AoE
- ขณะ Zone: ศัตรูรับดาเมจเพิ่ม **+30%**
- หลังเพื่อนโจมตี ต่อศัตรูที่โดน 1 ตัว → Quantum Additional DMG = **12% Max HP** ใส่ศัตรูที่ HP สูงสุดในกลุ่มที่โดน
- Zone นาน 2 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Tribbie)
- Energy +5 · Toughness 20

## Talent — Busy as Tribbie (AoE, Lv.10)
- หลังเพื่อนคนอื่นใช้ Ultimate → Tribbie ยิง Follow-up ATK: Quantum DMG = **18% Max HP** AoE
- trigger ได้ 1 ครั้ง/ตัวละคร; เมื่อ Tribbie ใช้ Ult → รีเซ็ตตัวนับของเพื่อนคนอื่น
- ถ้าเป้าตายก่อนยิง → ยิงใส่ศัตรูใหม่ที่เข้าฉาก
- Energy +5 · Toughness 5

## Technique — If You're Happy and You Know It
- หลังใช้ Technique + เข้าฉาก → ได้ "Numinosity" นาน 3 เทิร์น

---

## Major Traces
- **A2 — Lamb Outside the Wall...**: หลังยิง Talent Follow-up ATK → Tribbie +DMG **72%** stack 3 ครั้ง นาน 3 เทิร์น
- **A4 — Glass Ball with Wings!**: ขณะ Zone → Tribbie Max HP **+เท่ากับ 9% ของผลรวม Max HP ของเพื่อนทุกคน**
- **A6 — Pebble at Crossroads?**: ต้นการต่อสู้ → คืน Energy **30**. หลังเพื่อนโจมตี → คืน Energy **1.5 ต่อศัตรูที่โดน**

## Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · CRIT Rate +12% · HP +10%

## Eidolons
- **E1**: ขณะ Zone หลังเพื่อนโจมตีศัตรู → True DMG = **24% ของดาเมจรวมของการโจมตีนั้น** ใส่เป้าที่โดน Zone Additional DMG
- **E2**: Zone Additional DMG เพิ่มเป็น **120%** ของเดิม + ยิงเพิ่มอีก 1 instance
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ขณะ Numinosity → ดาเมจเพื่อนทุกคนเพิกเฉย DEF **18%**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: หลัง Tribbie ใช้ Ult → ยิง Talent Follow-up ATK ใส่ศัตรูทุกตัว. Talent Follow-up ATK DMG **+729%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ Max HP** (BA 30/15, Ult 30, Zone Add 12, Talent FUA 18 — ทั้งหมด % Max HP)
- **A4**: Max HP ของ Tribbie += 9% × Σ(Max HP เพื่อน) ขณะ Zone — ต้อง re-eval
- **Zone**: vulnerability +30% + Additional DMG 12% Max HP ต่อการโจมตีของเพื่อน (E2 ×1.2 + extra instance)
- **Talent FUA**: trigger ต่อเพื่อน Ult (1/ตัว, reset เมื่อ Tribbie Ult), E6 → Tribbie Ult ก็ยิงเอง +729%
- **Numinosity (Skill)**: RES PEN +24% ทีม (E4 DEF ignore 18%)
- **A6 energy**: +30 start + 1.5/hit จากเพื่อน
- โค้ด: `Start_game_List` (`Tribbie.h:142`, `TBptr`) + `Tribbie_LC.h` มี Start_game entry

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tribbie — kit tab (review/calc patch 3.1, profile 01/Jun/2026)
