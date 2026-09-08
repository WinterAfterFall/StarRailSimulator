# The Dahlia (Constance) — เดอะ ดาห์เลีย  (codename ในโค้ด: **Dahlia**)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Dahlia.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review/calc patch 3.8) |

## Base Stats (Lv.80, ascended)
HP 1087 · ATK 679 · DEF 606 · SPD 96

> Nihility support สาย Super Break enabler + "Dance Partner" + weakness implant

---

## Basic ATK — Fiddle... Fissured Memory (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Lick... Enkindled Betrayal (Blast, Lv.10)
- กาง **Zone** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ The Dahlia)
- Fire DMG = **160% ATK** ใส่เป้าหมาย + ข้างเคียง
- ขณะ Zone: เพื่อนทุกคน Weakness Break Efficiency **+50%**; Toughness Reduction ที่ศัตรู (ยังไม่ broken) รับ → แปลงเป็น **Super Break DMG** ได้
- Energy +30 · Toughness 10 (+10)

## Ultimate — Wallow...Entombed Ash (AoE, 130 energy, Lv.10)
- ติด **"Wilt"** ศัตรูทุกตัว นาน 4 เทิร์น
- Fire DMG = **300% ATK** กระจายเท่ากันทุกศัตรู
- ศัตรูที่ Wilt: DEF **−18%** + ถูกยัด Weakness ตาม Type ของ "Dance Partner" ทุกคน
- Energy +5 · Toughness 20

## Talent — Who's Afraid of Constance? (Lv.10)
- เข้าฉาก → The Dahlia คืน Energy **35** + มอบ **"Dance Partner"** ให้ตัวเอง + เพื่อนที่ trigger การต่อสู้
- เมื่อไม่มี "Dance Partner" คนอื่นในสนาม → มอบให้ตัวเอง + เพื่อนที่ Break Effect สูงสุด
- หลัง "Dance Partner" ตีศัตรู Weakness Broken → Toughness Reduction ของการโจมตีนั้นแปลงเป็น **Super Break DMG 60%** 1 instance
- หลังศัตรูถูก "Dance Partner" คนอื่นโจมตี → The Dahlia ยิง Follow-Up ATK: **5 instance × 30% ATK** Fire DMG ใส่ศัตรูสุ่ม
  - แต่ละ instance ที่โดนศัตรู Weakness Broken → Toughness Reduction แปลงเป็น **Super Break DMG 200%**
  - trigger 1 ครั้ง/เทิร์น
- Energy +2 · Toughness 3

## Technique — The Heart Makes the Finest Tomb
- สร้าง Special Dimension 20 วิ (ศัตรูไม่โจมตีเพื่อน)
- เข้าฉากกับศัตรูใน Dimension → กาง Zone ของ Skill ทันที + แปลง Toughness Reduction จากการเข้าฉากเป็น Super Break DMG 60% กับศัตรู Weakness Broken

---

## Major Traces
- **A2 — Yet Another Funeral**: เข้าฉาก → เพื่อนคนอื่น Break Effect **+เท่ากับ 24% ของ BE ของ The Dahlia + 50%** นาน 1 เทิร์น. trigger อีกครั้ง (นาน 3 เทิร์น) เมื่อ The Dahlia รับ heal/Shield จากเพื่อน (ไม่ซ้ำในเทิร์นเดียว)
- **A4 — Lament, Lost Soul**: ใช้ Talent Follow-Up ATK → คืน Skill Point **1** ให้ทีม (ทุก ๆ 2 Follow-Up ATK)
- **A6 — Outgrow the Old, Espouse the New**: เมื่อเพื่อนยัด Weakness ให้ศัตรู → SPD **+30%** นาน 2 เทิร์น. ถ้าเพื่อน Fire ยัด Weakness ตอนโจมตี → หลังโจมตี ต่อเป้าที่โดนยัด → Fire Toughness Reduction คงที่ **20** + คืน Energy **10% ของ Max Energy** (cap รวม 50% Max Energy)

## Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · SPD +5 · Effect RES +18%

## Eidolons
- **E1**: apply Super Break DMG multiplier ของ Talent ให้เพื่อนทุกคน ("Dance Partner" ได้ **+40%** เพิ่ม). หลัง "Dance Partner" โจมตี → Toughness Reduction คงที่ = **25% ของ Max Toughness** ของศัตรู (min 10, max 300) 1 ครั้ง/ศัตรู (reset เมื่อศัตรูโดน killing blow)
- **E2**: ขณะ The Dahlia อยู่ในสนาม → ศัตรูทุกตัว All-Type RES **−20%**. ศัตรูเข้าฉาก → ติด "Wilt" ทันที นาน 3 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: Talent Follow-Up ATK instance **+5** (รวม 10) + แต่ละ hit → เป้าหมายรับดาเมจเพิ่ม **+12%** นาน 2 เทิร์น
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: "Dance Partner" Break Effect **+150%**. ใช้ Talent Follow-Up ATK → advance action ของ "Dance Partner" ทุกคน **20%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Dance Partner** = แกน: มอบตอนเข้าฉาก (self + trigger ally) หรือ self + BE สูงสุด; ได้ Super Break conversion 60% เมื่อตี broken enemy (E1 → apply ทีม, +40% Dance Partner, E6 BE +150%)
- **Talent FUA**: 5 hit (E4 10) × 30% ATK, ต่อ hit ที่โดน broken → Super Break 200%; trigger เมื่อ Dance Partner คนอื่นตีศัตรู (1/เทิร์น)
- **Super Break** ต้องมี model (f(toughness reduction, BE))
- **Ult "Wilt"**: DEF −18% + weakness implant ตาม Dance Partner types
- **Zone (Skill)**: WBE +50% + Super Break conversion แม้ยังไม่ broken
- **A2**: BE share 24%×BE + 50% ให้เพื่อน
- โค้ด: `Start_game_List` (`Dahlia.h:203`)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/the-dahlia — kit tab (review/calc patch 3.8, profile 01/Jun/2026)
