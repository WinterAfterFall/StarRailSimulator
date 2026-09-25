# Sunday — ซันเดย์

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Sunday.h` |
| ธาตุ | **Imaginary** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.7 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1241 · ATK 640 · DEF 533 · SPD 96

> Harmony support สาย summon-buffer + CRIT DMG/CRIT Rate + turn advance + energy

---

## Basic ATK — Gleaming Admonition (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Benison of Paper and Rites (Support, Lv.10)
- ให้เพื่อน 1 ตัว + summon ของเขา **action ทันที** + **+DMG dealt 30%**
- ถ้าเป้าหมายมี summon → +DMG dealt เพิ่มอีก **50%** นาน 2 เทิร์น
- ใช้ Skill ใส่ **The Beatified** → คืน Skill Point **1**
- ใช้ใส่ตัวละคร Path Harmony → ไม่ trigger immediate action
- Energy +30

## Ultimate — Ode to Caress and Cicatrix (Support, 130 energy, Lv.10)
- คืน Energy = **20% ของ Max Energy** ให้เพื่อน 1 ตัว
- เปลี่ยนเป้าหมาย + summon เป็น **"The Beatified"** → CRIT DMG **+เท่ากับ 30% ของ CRIT DMG ของ Sunday + 12%**
- ต้นเทิร์นของ Sunday → duration ลด 1, รวม 3 เทิร์น; มีผลกับเป้าหมาย Ult ล่าสุดเท่านั้น (ยกเว้น Sunday); Sunday ถูกน็อค → หาย
- Energy +5

## Talent — The Sorrowing Body (Lv.10)
- ใช้ Skill → เป้าหมาย CRIT Rate **+20%** นาน 3 เทิร์น

## Technique — The Glorious Mysteries
- หลังใช้ Technique → ครั้งแรกที่ Sunday ใช้ ability ใส่เพื่อนในการต่อสู้ถัดไป → เป้าหมาย +DMG dealt **50%** นาน 2 เทิร์น

---

## Major Traces
- **A2 — Rest Day's Longing**: ใช้ Ult ถ้า Energy ที่คืนให้เป้าหมาย < 40 → เพิ่มเป็น **40**
- **A4 — Exalted Sweep**: ต้นการต่อสู้ → Sunday คืน Energy **25**
- **A6 — Haven in Palm**: ใช้ Skill → ลบ debuff 1 อันจากเป้าหมาย

## Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · Effect RES +18% · DEF +12.5%

## Eidolons
- **E1**: ใช้ Skill → เป้าหมายเพิกเฉย DEF **16%**, summon ของเป้าหมายเพิกเฉย DEF **40%** นาน 2 เทิร์น
- **E2**: หลังใช้ Ult ครั้งแรก → คืน Skill Point **2**. ดาเมจของ "The Beatified" **+30%**
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ต้นเทิร์น → คืน Energy **8**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Talent CRIT Rate boost → stack ได้ 3 ครั้ง + duration **+1 เทิร์น**. ใช้ Ult → apply Talent CRIT Rate boost ให้เป้าหมายด้วย. เมื่อ CRIT Rate เป้าหมายเกิน 100% → ทุก 1% ส่วนเกิน → CRIT DMG **+2%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill**: forced action + DMG% (30%, +50% ถ้ามี summon) — ไม่ trigger action ตอนใส่ Harmony char; คืน SP 1 ถ้าเป้าเป็น The Beatified
- **Ult CRIT DMG buff**: 0.30 × (CD ของ Sunday) + 12% — ผูกกับ CD ของ Sunday, single target ล่าสุด, 3 เทิร์น
- **Talent CRIT Rate +20%** (E6: stack 3, +CD conversion เมื่อเกิน 100%)
- **Energy support**: Ult 20% Max Energy (A2 floor 40), A4 +25 start, E4 +8/turn
- summon-centric — ทำงานดีกับ Jing Yuan / Robin / remembrance
- โค้ด: `Start_game_List` (`Sunday.h:179`, `SDptr`)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sunday — kit tab (review patch 2.7, calc patch 4.0, profile 01/Jun/2026)
