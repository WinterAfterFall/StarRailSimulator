# Ruan Mei — หร่วนเหมย

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Ruan_Mei.h` |
| ธาตุ | **Ice** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 485 · SPD 104

> Harmony support สายบัฟรวม + Break/Super Break

---

## Basic ATK — Threading Fragrance (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — String Sings Slow Swirls (Support, Lv.10)
- Ruan Mei ได้ **Overtone** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Ruan Mei)
- ขณะมี Overtone: เพื่อนทุกคน +DMG **32%** + Weakness Break Efficiency **+50%**
- Energy +30

## Ultimate — Petals to Stream, Repose in Dream (Support, 130 energy, Lv.10)
- กาง field นาน 2 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Ruan Mei)
- ขณะอยู่ใน field: เพื่อนทุกคน All-Type RES PEN **+25%** + การโจมตีของเพื่อนติด **Thanatoplum Rebloom** ให้ศัตรูที่โดน
- เมื่อศัตรูนั้นพยายามฟื้นจาก Weakness Break → trigger Thanatoplum Rebloom: ยืด Weakness Break, delay action = **20% ของ Break Effect ของ Ruan Mei + 10%**, Break DMG = **50% ของ Ice Break DMG ของ Ruan Mei**
- ศัตรูจะโดนติดซ้ำไม่ได้จนกว่าจะฟื้นจาก Weakness Break
- Energy +5

## Talent — Somatotypical Helix (Lv.10)
- เพื่อน (ยกเว้น Ruan Mei) SPD **+10%**
- เมื่อเพื่อน Break Weakness ศัตรู → Ruan Mei สร้าง Break DMG = **120% ของ Ice Break DMG ของเธอ** ใส่ศัตรูนั้น

## Technique — Silken Serenade
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป trigger Skill อัตโนมัติ 1 ครั้ง โดยไม่กิน Skill Points

---

## Major Traces
- **A2 — Inert Respiration**: เพื่อนทุกคน Break Effect **+20%**
- **A4 — Days Wane, Thoughts Wax**: Ruan Mei คืน Energy **5** ตอนเริ่มเทิร์น
- **A6 — Candle Lights on Still Waters**: ทุก 10% ของ Break Effect ของ Ruan Mei ที่เกิน **120%** → Skill เพิ่ม +DMG เพื่อน **+6%** สูงสุด **+36%**

## Minor Traces (รวมทั้งหมด)
DEF +22.5% · SPD +5 · Break Effect +37.3%

## Eidolons
- **E1**: ขณะ field ของ Ult กางอยู่ → ดาเมจเพื่อนทุกคนเพิกเฉย DEF **20%**
- **E2**: ขณะ Ruan Mei อยู่ในสนาม → เพื่อนทุกคน ATK **+40%** เมื่อสร้างดาเมจกับศัตรู Weakness Broken
- **E3**: Ultimate Lv. +2 · Talent Lv. +2
- **E4**: ศัตรู Weakness Broken → Ruan Mei Break Effect **+100%** นาน 3 เทิร์น
- **E5**: Skill Lv. +2 · Basic ATK Lv. +1
- **E6**: field ของ Ult **+1 เทิร์น**. Talent Break DMG multiplier **+200%** (รวม 320%)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Overtone (Skill)**: DMG +32% + WBE +50% (A6 → +6%/10% BE เกิน 120% สูงสุด +36% DMG)
- **Talent Break DMG**: 120% Ice Break DMG (E6 320%) ต่อการ break ของเพื่อน — ต้องมี Ice Break DMG model
- **Ult field**: RES PEN +25%, Thanatoplum Rebloom (delay + break-dmg 50% ตอนศัตรูจะฟื้นจาก break)
- **A2 BE +20% ทีม** / E4 BE +100% self
- **Talent SPD +10%** ทีม (ยกเว้นตัวเอง)
- โค้ด: `Start_game_List` priority `PRIORITY_ACTION` (`Ruan_Mei.h:66`) + มี addToActionBar + `Deal_damage()` (technique auto-skill self-flush)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/ruan-mei — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)
