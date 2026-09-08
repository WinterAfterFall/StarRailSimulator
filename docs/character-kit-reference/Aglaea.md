# Aglaea — อากลาเอีย

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Aglaea.h` |
| ธาตุ | **Lightning** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 350 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1241 · ATK 698 · DEF 485 · SPD 102

> Remembrance DPS สาย memosprite **Garmentmaker** + SPD scaling + "Seam Stitch"

---

## Basic ATK — Thorned Nectar (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Slash by a Thousandfold Kiss (Blast, Lv.6)
- Joint ATK: Aglaea + Garmentmaker
  - หลัก: Lightning DMG = **200% ATK ของ Aglaea** + **200% ATK ของ Garmentmaker**
  - ข้างเคียง: **90% ATK ของ Aglaea** + **90% ATK ของ Garmentmaker**
- ไม่คืน Skill Point
- Energy +20 · Toughness 20 (+10)

## Skill — Rise, Exalted Renown (Summon, Lv.10)
- ฮีล Garmentmaker **50% Max HP**; ถ้าไม่มี Garmentmaker → เรียก + Aglaea action ทันที
- Energy +20

## Ultimate — Dance, Destined Weaveress (Enhance, 350 energy, Lv.10)
- เรียก Garmentmaker (ถ้ามีอยู่แล้ว → ฮีลเต็ม), Aglaea เข้าสถานะ **"Supreme Stance"** + action ทันที
- ขณะ Supreme Stance: Aglaea ได้ SPD Boost stack จาก Memosprite Talent (ต่อ stack SPD **+15%**), Basic ATK เป็น "Slash by a Thousandfold Kiss", ใช้ Skill ไม่ได้, Garmentmaker ภูมิคุ้มกัน CC
- countdown ใน action order SPD คงที่ **100**; ใช้ Ult ซ้ำ → reset countdown; ถึงตา countdown → Garmentmaker self-destruct → Supreme Stance หาย
- Energy +5

## Talent — Rosy-Fingered (Lv.10)
- Garmentmaker: initial SPD = **35% ของ SPD ของ Aglaea**, Max HP = **66% ของ Max HP ของ Aglaea + 720**
- ขณะ Garmentmaker อยู่ในสนาม → การโจมตีของ Aglaea ติด **"Seam Stitch"**
- ตีศัตรูที่ติด "Seam Stitch" → Lightning Additional DMG = **30% ATK ของ Aglaea**
- "Seam Stitch" มีผลกับเป้าล่าสุดเท่านั้น
- Energy +10

## Technique — Meteoric Sunder
- เรียก Garmentmaker + joint attack; เข้าฉาก → คืน Energy **30** + Lightning DMG = **100% ATK** AoE + ติด "Seam Stitch" ศัตรูสุ่ม
- Toughness 20

## Memosprite: Garmentmaker
### Memosprite Skill — Thorned Snare (Blast, Lv.6)
- Lightning DMG หลัก = **110% ATK**, ข้างเคียง = **66% ATK**
- Energy +10 · Toughness 10 (+5)

### Memosprite Talent
- **A Body Brewed by Tears**: หลังตีศัตรูที่ติด "Seam Stitch" → SPD **+55** stack 6 ครั้ง. เมื่อ Garmentmaker action → ใช้ "Thorned Snare" อัตโนมัติ (เลือกศัตรู Seam Stitch ก่อน)
- **The Speeding Summer**: เมื่อ Garmentmaker ถูกเรียก → action advance **100%**
- **Bloom of Drying Grass**: เมื่อ Garmentmaker หาย → คืน Energy **20** ให้ Aglaea

---

## Major Traces
- **A2 — The Myopic's Doom**: ขณะ Supreme Stance → Aglaea + Garmentmaker ATK **+เท่ากับ 720% ของ SPD ของ Aglaea + 360% ของ SPD ของ Garmentmaker**
- **A4 — Last Thread of Fate**: Garmentmaker หาย → เก็บ SPD Boost stack ได้ 1 stack; เรียกใหม่ → ได้ stack นั้นกลับ
- **A6 — The Speeding Sol**: ต้นการต่อสู้ ถ้า Energy < 50% → เติมเป็น 50%

## Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · Lightning DMG +22.4% · DEF +12.5%

## Eidolons
- **E1**: ศัตรูที่ติด "Seam Stitch" รับดาเมจเพิ่ม **+15%**. หลัง Aglaea/Garmentmaker ตีเป้านี้ → คืน Energy **20**
- **E2**: เมื่อ Aglaea/Garmentmaker action → ดาเมจของ Aglaea + Garmentmaker เพิกเฉย DEF **14%** stack 3 ครั้ง (อยู่จนกว่าหน่วยอื่นใช้ ability)
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Memosprite Talent Lv. +1
- **E4**: SPD Boost cap **+1**. หลัง Aglaea โจมตี → Garmentmaker ก็ได้ SPD Boost stack ด้วย
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Memosprite Skill Lv. +1
- **E6**: ขณะ Supreme Stance → Aglaea + Garmentmaker Lightning RES PEN **+20%**. เมื่อ SPD > 160/240/320 → Joint ATK DMG **+10%/+30%/+60%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Garmentmaker (memosprite)**: SPD = 35% Aglaea SPD, HP = 66% Aglaea HP + 720; auto-cast Thorned Snare ทุกเทิร์น; advance 100% เมื่อเรียก; คืน energy 20 เมื่อหาย
- **SPD scaling**: A2 ATK = 720%×AglaeaSPD + 360%×GMSPD (Supreme Stance); Memosprite Talent SPD +55/stack (cap 6, E4 7); Ult SPD +15%/stack
- **Seam Stitch**: Additional DMG 30% ATK + E1 vuln 15%; single target ล่าสุด
- **Supreme Stance (Ult 350)**: countdown SPD 100, Enhanced BA (Joint ATK 200%+200%), no Skill
- **Joint ATK** = ดาเมจ 2 แหล่ง (Aglaea ATK + Garmentmaker ATK) — sim ต้องแยก ATK stat 2 ตัว
- โค้ด: `Start_game_List` (`Aglaea.h:88`, `AGptr`) + memosprite handling
- **หมายเหตุ**: `elationCount`-style — Remembrance ใช้ `memospriteList`

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/aglaea — kit tab (review patch 3.0, calc patch 3.4, profile 01/Jun/2026)
