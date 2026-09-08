# Firefly (SAM) — ไฟร์ฟลาย

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/FireFly.h` |
| ธาตุ | **Fire** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 240 |
| อ้างอิง | prydwen.gg (review/calc patch 4.2) |

## Base Stats (Lv.80, ascended)
HP 814 · ATK 523 · DEF 776 · SPD 104

---

## Basic ATK — Order: Flare Propulsion (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Basic ATK (Enhanced) — Fyrefly Type-IV: Pyrogenic Decimation (โจมตีเดี่ยว, Lv.6)
- ฮีลตัวเอง = **20% Max HP**
- Fire DMG = **150% ATK** ใส่ศัตรู 1 ตัว
- Energy +0 · Toughness 15

## Skill — Order: Aerial Bombardment (โจมตีเดี่ยว, Lv.10)
- กิน HP = **40% Max HP** (ถ้าไม่พอ → HP เหลือ 1) และคืน Energy = **60% ของ Max Energy** (ค่าคงที่)
- Fire DMG = **200% ATK** ใส่ศัตรู 1 ตัว
- Advance action ครั้งถัดไป **25%**
- Energy +0 · Toughness 20

## Skill (Enhanced) — Fyrefly Type-IV: Deathstar Overload (Blast, Lv.10)
- ฮีลตัวเอง = **25% Max HP**
- เพิ่ม Fire Weakness ให้เป้าหมาย + ศัตรูข้างเคียง นาน 2 เทิร์น
- Fire DMG เป้าหมายหลัก = **(0.2 × Break Effect + 200%) ATK**
- Fire DMG ข้างเคียง = **(0.1 × Break Effect + 100%) ATK**
- **Break Effect ที่ใช้คำนวณ cap ที่ 360%**
- Energy +0 · Toughness 30 (+15 ข้างเคียง)

## Ultimate — Fyrefly Type-IV: Complete Combustion (Enhance, 240 energy, Lv.10)
- เข้าสถานะ **Complete Combustion**, advance action **100%**, ได้ Enhanced BA + Enhanced Skill
- ขณะ Complete Combustion: **SPD +60**; เมื่อใช้ Enhanced BA/Skill → Weakness Break Efficiency **+50%** และ Break DMG ที่ SAM ทำ **+20%** (จนจบการโจมตีนั้น)
- มี countdown timer ใน action order (SPD คงที่ **70**) เมื่อถึงตาของ timer → ออกจากสถานะ
- ใช้ Ultimate ไม่ได้ขณะอยู่ในสถานะ
- Energy +5

## Talent — Chrysalid Pyronexus (Lv.10)
- HP ยิ่งต่ำ → รับดาเมจน้อยลง; HP ≤ 20% → DMG Reduction สูงสุด **40%**
- ขณะ Complete Combustion: DMG Reduction คงที่ max + Effect RES **+30%**
- เริ่มการต่อสู้ ถ้า Energy < 50% → เติมเป็น 50%; เมื่อ Energy เต็ม → ล้าง debuff ทั้งหมดบนตัวเอง

## Technique — Δ Order: Meteoric Incineration
- ต้นแต่ละ wave: ติด Fire Weakness ศัตรูทุกตัวนาน 2 เทิร์น + Fire DMG = **200% ATK** AoE
- Toughness 20

---

## Major Traces
- **A2 — Module α: Antilag Outburst**: ขณะ Complete Combustion → Break Effect **+25%**. เมื่อใช้ Enhanced BA/Skill ทำ Weakness Break → หน่วง countdown **10%** (สูงสุด 3 ครั้ง/รอบสถานะ)
- **A4 — Module β: Autoreactive Armor**: ขณะ Complete Combustion และ Break Effect ≥ **150%/300%** → ตีศัตรูที่ Weakness-Broken จะแปลง Toughness Reduction ของการโจมตีนั้นเป็น **Super Break DMG 100%/150%** 1 instance
- **A6 — Module γ: Core Overload**: ทุก 10 ATK ที่เกิน **1800** → Break Effect **+0.8%**

## Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · SPD +5 · Effect RES +18%

## Eidolons
- **E1**: Enhanced Skill เพิกเฉย DEF **15%** และ**ไม่กิน Skill Point**
- **E2**: ขณะ Complete Combustion ใช้ Enhanced BA/Skill ฆ่าหรือ Break Weakness → ได้เทิร์นพิเศษทันที (1 ครั้ง/เทิร์น, รีเซ็ตตอนเริ่มเทิร์น SAM)
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ขณะ Complete Combustion → Effect RES **+50%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: ขณะ Complete Combustion → Fire RES PEN **+20%**; เมื่อใช้ Enhanced BA/Skill → Weakness Break Efficiency **+50%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ทุกอย่างหมุนรอบ Break Effect** — Enhanced Skill multiplier = f(BE) cap BE 360%; A6 แปลง ATK เกิน 1800 → BE
- **Enhanced Skill DMG** = `(0.2×BE + 2.0)×ATK` main, `(0.1×BE + 1.0)×ATK` blast
- **A4 Super Break**: threshold BE 150% → 100%, BE 300% → 150%; ต้องตี broken enemy ขณะ Combustion
- **Complete Combustion**: countdown unit SPD 70, มี A2 หน่วง 10%×3; SPD +60 ระหว่างสถานะ; Talent DMG-reduction locked max
- **Skill self-damage** 40% Max HP (floor ที่ HP=1) + energy refund 60% Max Energy คงที่
- **Technique** (`Start_wave_List`, `ptr->Technique == 1`) ทำต้นทุก wave: weakness + 200% AoE + self-flush `Deal_damage()`
- Talent energy top-up ถึง 50% ตอนเริ่มต่อสู้ + debuff cleanse ตอน energy เต็ม
- E1: Enhanced Skill ไม่กิน SP (สำคัญต่อ SP economy sim)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/firefly — kit tab (review/calc patch 4.2, profile 01/Jun/2026)
