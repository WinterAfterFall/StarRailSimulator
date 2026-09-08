# Trailblazer • Harmony — เทรลเบลเซอร์ (สาย Harmony)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Harmony_MC.h` |
| ธาตุ | **Imaginary** |
| Path | **Harmony** |
| ระดับ | 5★ (MC) |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1086 · ATK 446 · DEF 679 · SPD 105

> Harmony support สาย Super Break enabler

---

## Basic ATK — Swing Dance Etiquette (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Halftime to Make It Rain (Bounce, Lv.10)
- Imaginary DMG = **50% ATK** ใส่เป้าหมาย + เพิ่ม **4 instance × 50% ATK** ใส่ศัตรูสุ่ม
- Energy +6 · Toughness 10 (ต่อ instance)

## Ultimate — All-Out Footlight Parade (Support, 140 energy, Lv.10)
- มอบ **Backup Dancer** ให้เพื่อนทุกคน นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Trailblazer)
- เพื่อนที่มี Backup Dancer: Break Effect **+30%**
- เมื่อเพื่อนที่มี Backup Dancer โจมตีศัตรูที่ **Weakness Broken** → Toughness Reduction ของการโจมตีนั้นแปลงเป็น **Super Break DMG** 1 instance
- Energy +5

## Talent — Full-on Aerial Dance (Lv.10)
- เมื่อศัตรู Weakness Broken → Trailblazer คืน Energy **10** ทันที

## Technique — Now! I'm the Band!
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป เพื่อนทุกคน Break Effect **+30%** นาน 2 เทิร์น

---

## Major Traces
- **A2 — Dance With the One**: จำนวนศัตรู 5+/4/3/2/1 → Super Break DMG จาก Backup Dancer **+20%/+30%/+40%/+50%/+60%**
- **A4 — Shuffle Along**: ใช้ Skill → Toughness Reduction ของ instance แรก **+100%**
- **A6 — Hat of the Theater**: เมื่อเพื่อน Break Weakness ศัตรู → delay action ศัตรู **+30%**

## Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · Imaginary DMG +14.4% · Effect RES +10%

## Eidolons
- **E1**: ใช้ Skill ครั้งแรก → คืน Skill Point **1**
- **E2**: ต้นการต่อสู้ → Trailblazer Energy Regen Rate **+25%** นาน 3 เทิร์น
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Trailblazer อยู่ในสนาม → เพื่อน (ยกเว้น Trailblazer) Break Effect **+เท่ากับ 15% ของ Break Effect ของ Trailblazer**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: จำนวน additional DMG instance ของ Skill **+2** (รวม 6)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Backup Dancer** = แกนกลไก: BE +30% + Super Break conversion เมื่อตี broken enemy
- **Super Break DMG** = f(Toughness Reduction ของการโจมตี, BE ของผู้โจมตี) × A2 multiplier (ตามจำนวนศัตรู)
- **A4**: Skill instance แรก toughness reduction ×2
- **Talent**: energy +10 ต่อ enemy break (ตัว Trailblazer เอง)
- **E4**: BE share 15% ของ Trailblazer ให้เพื่อน — ผูกกับ BE stat ต้อง re-eval
- โค้ด: `Start_game_List` (`Harmony_MC.h:62`) — technique BE buff

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/trailblazer-harmony — kit tab (review patch 2.6, calc patch 3.4, profile 01/Jun/2026)
