# Black Swan — แบล็คสวอน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Black Swan.h` (เวอร์ชันเก่า `Black SwanV1.h` — ข้าม) |
| ธาตุ | **Wind** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 485 · SPD 102

> Nihility DoT DPS สาย "Arcana" stack

---

## Basic ATK — Percipience, Silent Dawn (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Decadence, False Twilight (Blast, Lv.10)
- Wind DMG = **90% ATK** ใส่เป้าหมาย + ข้างเคียง
- 100% base chance ลด DEF เป้าหมาย + ข้างเคียง **20.8%** นาน 3 เทิร์น
- Energy +30 · Toughness 20 (+10)

## Ultimate — Bliss of Otherworld's Embrace (AoE, 120 energy, Lv.10)
- ติด **"Epiphany"** ศัตรูทุกตัว นาน 2 เทิร์น → Wind DMG = **120% ATK** AoE
- ขณะ Epiphany: ศัตรูรับดาเมจเพิ่ม **+25%**; ต่อ 1 stack ของ Arcana ที่ยัด → 50% fixed chance เพิ่มจำนวน stack อีก 1; Arcana ไม่ถูกหาร 2 หลังลงดาเมจต้นเทิร์น
- Energy +5 · Toughness 20

## Talent — Loom of Fate's Caprice (Lv.10)
- ทุกครั้งศัตรูรับ 1 instance ของ DoT → 65% base chance ติด **"Arcana" 1 stack**
- ขณะติด Arcana: ถือว่าติด Wind Shear + Bleed + Burn + Shock พร้อมกัน
- ต้นทุกเทิร์น: Wind DoT = **240% ATK** จากนั้น stack ถูกหาร 2; ต่อ 1 stack ของ Arcana → multiplier **+12%**
- Arcana stack ได้ **50** (เกินได้ ส่วนเกินหายหลังลงดาเมจ)
- ดาเมจ Arcana เพิกเฉย DEF **20%**; เมื่อ Arcana ลงดาเมจต้นเทิร์นของศัตรู → ข้างเคียงรับ Wind DoT เพิ่ม **180% ATK** 1 instance
- Energy +5

## Technique — From Façade to Vérité
- หลังใช้ Technique → 150% base chance ติด Arcana 1 stack ให้ศัตรูแต่ละตัวต้นการต่อสู้; ยัดซ้ำเรื่อย ๆ จนล้มเหลว (base chance ครั้งถัดไป = 50% ของครั้งก่อนที่สำเร็จ)

---

## Major Traces
- **A2 — Viscera's Disquiet**: เมื่อ Black Swan โจมตีศัตรู → 65% base chance ติด Arcana **5 stack**
- **A4 — Goblet's Dredges**: ศัตรูเข้าฉาก → 65% base chance ติด Arcana 1 stack + 100% base chance ติด DEF reduction จาก Skill 3 เทิร์น. หลัง BA/Ult → 100% base chance ติด DEF reduction จาก Skill
- **A6 — Candleflame's Portent**: เพื่อนทุกคน +DMG = **60% ของ Effect Hit Rate ของ Black Swan** สูงสุด **+72%**

## Minor Traces (รวมทั้งหมด)
ATK +28% · Wind DMG +14.4% · Effect HIT Rate +10%

## Eidolons
- **E1**: ขณะ Black Swan active → ศัตรูที่ติด Wind Shear/Bleed/Burn/Shock → ลด Wind/Physical/Fire/Lightning RES ตามลำดับ **25%**
- **E2**: ศัตรูเข้าฉาก → 100% base chance ติด Arcana **30 stack**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Epiphany → ศัตรูรับดาเมจเพิ่ม **+20%** เพิ่ม. ต้นทุกเทิร์น/เมื่อศัตรูตาย → คืน Energy **8**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: cap Arcana **+30**. เมื่อเพื่อนโจมตีศัตรู → 65% base chance ติด Arcana 1 stack. ทุก 1 stack ของ Arcana ที่ Black Swan ยัด → เพิ่มจำนวน stack ครั้งนั้นอีก 1

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Arcana** = DoT stack แกน: DoT = 240% ATK × (1 + 0.12×stack) ต้นเทิร์น, หาร 2 หลังลง (ยกเว้น Epiphany); cap 50 (E6 80); เพิกเฉย DEF 20%
- **แหล่ง Arcana**: DoT tick (65%), A2 (BS attack 65% → 5 stack), A4 (enter 65%), E2 (enter 30), E6 (ally attack 65%), Technique (cascade), Ult (50% double)
- **Epiphany (Ult)**: vulnerability +25% (E4 +20%) + Arcana ไม่หาร 2 + double-chance
- **Talent adjacent**: 180% ATK DoT ให้ข้างเคียงตอน Arcana tick ต้นเทิร์นศัตรู
- **A6**: DMG amp ทีมจาก EHR ของ BS (cap 72%) — EHR เป็น stat สำคัญ
- โค้ด: `Start_game_List` (`Black Swan.h:147`, `bs`)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/black-swan — kit tab (review/calc patch 4.0, profile 01/Jun/2026)
