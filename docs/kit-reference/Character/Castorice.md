# Castorice — คาสโตริซ

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Castorice.h` |
| ธาตุ | **Quantum** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 0 (ใช้ "Newbud" เป็นทรัพยากร ไม่มี energy) |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.6) |

## Base Stats (Lv.80, ascended)
HP 1631 · ATK 523 · DEF 485 · SPD 95

> Remembrance DPS สาย HP-consumption + memosprite **Netherwing** (มังกร)

---

## Basic ATK — Lament, Nethersea's Ripple (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +0 · Toughness 10

## Skill — Silence, Wraithfly's Caress (Blast, Lv.10)
- กิน HP **30% ของ HP ปัจจุบัน** ของเพื่อนทุกคน (ไม่พอ → HP = 1)
- Quantum DMG หลัก = **50% Max HP**, ข้างเคียง = **30% Max HP**
- ถ้ามี Netherwing ในสนาม → Skill เป็น "Boneclaw, Doomdrake's Embrace" แทน
- Energy +0 · Toughness 20 (+10)

## Skill (Enhanced) — Boneclaw, Doomdrake's Embrace (AoE, Lv.10)
- กิน HP **40% ของ HP ปัจจุบัน** ของเพื่อนทุกคน (ยกเว้น Netherwing)
- Joint ATK (Castorice + Netherwing): Quantum DMG = **30%** + **50% Max HP ของ Castorice** ใส่ศัตรูทุกตัว
- Energy +0 · Toughness 20

## Ultimate — Doomshriek, Dawn's Chime (Summon, 0 energy, Lv.10)
- เรียก **Netherwing** + advance action **100%**
- สร้าง Territory **"Lost Netherland"**: ศัตรูทุกตัว All-Type RES **−20%**
- ถ้า DMG Boost จาก Talent active → ขยายผลให้ Netherwing ด้วย
- Netherwing: initial SPD **165**, Max HP = **100% ของ max Newbud**
- Netherwing อยู่ 3 เทิร์น หรือ HP = 0 → หาย + Territory หาย

## Talent — Desolation Across Palms (Lv.10)
- max "Newbud" อิงตามเลเวลของตัวละครทุกตัวในสนาม
- ต่อ 1 HP ที่เพื่อนทุกคนเสีย → Castorice ได้ "Newbud" **+1**
- Newbud เต็ม → ใช้ Ultimate ได้
- เมื่อเพื่อนเสีย HP → Castorice + Netherwing +DMG **20%** stack 3 ครั้ง นาน 3 เทิร์น
- ขณะมี Netherwing → ได้ Newbud จาก Talent ไม่ได้ + HP ที่เพื่อน (ยกเว้น Netherwing) เสีย → แปลงเป็น HP ให้ Netherwing เท่ากัน

## Technique — Wail, Death's Herald
- เข้าสถานะ "Netherveil" 20 วิ
- โจมตี → ศัตรูในระยะเข้าฉาก + เรียก Netherwing (advance 100%) + สร้าง Territory
- Netherwing เริ่มด้วย HP = **50% ของ max Newbud**
- เข้าฉาก → กิน HP **40%** ของ HP ปัจจุบันเพื่อน (ยกเว้น Netherwing); ก่อนเรียก Netherwing → Castorice ได้ Newbud = **30% ของ max**

## Unique — Sanctuary of Mooncocoon
- เมื่อเพื่อนโดน killing blow → เข้าสถานะ "Mooncocoon" (เลื่อนการล้ม, ทำ action ได้ปกติ); หลัง action ถ้า HP เพิ่มหรือได้ Shield → หาย, ไม่งั้นล้มทันที. trigger 1 ครั้ง/การต่อสู้

## Memosprite: Netherwing
### Memosprite Skill — Claw Splits the Veil (AoE, Lv.6)
- Quantum DMG = **40% Max HP ของ Castorice** ใส่ศัตรูทุกตัว · Toughness 10

### Memosprite Skill — Breath Scorches the Shadow (AoE, Lv.6)
- กิน **25% Max HP ของ Netherwing** → Quantum DMG = **24% Max HP ของ Castorice** AoE
- ใช้ซ้ำในการโจมตีเดียวได้ multiplier เพิ่มเป็น **28% / 34%** (สูงสุด 34%; boost คงอยู่จนกว่า Netherwing หาย)
- HP Netherwing ≤ 25% → ใช้แล้ว HP เหลือ 1 + trigger effect ของ "Wings Sweep the Ruins"
- Toughness 10

### Memosprite Talent
- **Mooncocoon Shrouds the Form**: Netherwing เป็น backup — เมื่อเพื่อนรับดาเมจ/เสีย HP → HP เพื่อนลดต่ำสุดถึง 1, จากนั้น Netherwing เสีย HP = **500% ของค่าเดิม**
- **Roar Rumbles the Realm**: เรียก Netherwing → เพื่อนทุกคน +DMG **10%** นาน 3 เทิร์น
- **Wings Sweep the Ruins**: Netherwing หาย → **6 instance × 40% Max HP ของ Castorice** Quantum DMG ใส่ศัตรูสุ่ม + ฮีลเพื่อนทุกคน **6% Max HP ของ Castorice + 800**

---

## Major Traces
- **A2 — Contained Dark Tide**: หลังเพื่อน (ยกเว้น Netherwing) รับ heal → แปลง **100% ของ heal** เป็น Newbud (หรือ HP ของ Netherwing ถ้ามีในสนาม); ต่อ ally ไม่เกิน **12% ของ max Newbud**; รีเซ็ตสะสมหลังหน่วยใด action
- **A4 — Inverted Torch**: HP Castorice ≥ 50% Max HP → SPD **+40%**. เมื่อ Breath Scorches the Shadow ทำ fatal ทั้งสนาม → Netherwing SPD **+100%** 1 เทิร์น
- **A6 — Where The West Wind Dwells**: ทุกครั้ง Breath Scorches the Shadow → Netherwing +DMG **30%** stack 6 ครั้ง (จนจบเทิร์น)

## Minor Traces (รวมทั้งหมด)
CRIT Rate +18.7% · CRIT DMG +13.3% · Quantum DMG +14.4%

## Eidolons
- **E1**: HP ศัตรู ≤ 80%/50% ของ Max HP ของ Castorice → ดาเมจของ Boneclaw/Claw Splits/Breath Scorches/Wings Sweep = **120%/140%** ของเดิม
- **E2**: หลังเรียก Netherwing → Castorice ได้ "Ardent Will" 2 stack (cap 2) → ใช้หักล้าง HP consumption ของ Breath Scorches + advance action Castorice 100%. Enhanced Skill ครั้งถัดไป → Castorice ได้ Newbud 30% ของ max
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Talent Lv. +1
- **E4**: ขณะ Castorice อยู่ในสนาม → เพื่อนทุกคน Incoming Healing **+20%** เมื่อได้รับการฮีล
- **E5**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Skill Lv. +1
- **E6**: เมื่อ Castorice/Netherwing สร้างดาเมจ → Quantum RES PEN **+20%**. Netherwing โจมตีได้ ignore weakness toughness + trigger Quantum break. Wings Sweep the Ruins bounce **+3**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ไม่มี energy** — Ult ใช้ "Newbud" (สะสมจาก HP loss ของทีม 1:1, max อิงเลเวล); โค้ด `SetCharBasicStats(...,0,0,...)` (energy 0)
- **ดาเมจทุกท่าสเกลกับ Max HP ของ Castorice** (BA 50%, Skill 50/30, Boneclaw 30+50, Claw 40%, Breath 24-34%, Wings 40%/hit)
- **Netherwing (memosprite)**: SPD 165, HP = 100% max Newbud; อยู่ 3 เทิร์น/HP 0; auto-action; Mooncocoon backup (500% HP drain); Wings Sweep ตอนหาย
- **HP consumption**: Skill 30%, Boneclaw 40%, Technique 40% — ทีมต้องรอด (Mooncocoon / floor HP 1)
- **DMG Boost (Talent)**: +20%/stack เมื่อเพื่อนเสีย HP (cap 3)
- **A2 heal→Newbud/Netherwing HP conversion** 100% (cap 12% max ต่อ ally)
- โค้ด: `Start_game_List` (`Castorice.h:174`, `Casptr`, `Polluxptr`) — "Pollux" = ชื่อภายในของ Netherwing?

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/castorice — kit tab (review patch 3.2, calc patch 3.6, profile 01/Jun/2026)
