# Cerydra — เซริดรา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Cerydra.h` |
| ธาตุ | **Wind** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.5 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1358 · ATK 620 · DEF 485 · SPD 99

---

## Basic ATK — King's Castling (โจมตีเดี่ยว, Lv.6)
- สร้าง Wind DMG = **100% ATK** ให้ศัตรูเป้าหมาย 1 ตัว
- Energy +20 · Toughness 10

## Skill — Pawn's Promotion (Support, Lv.10)
- มอบ **"Military Merit"** ให้ตัวละครฝ่ายเดียวกัน 1 ตัว และ Cerydra ได้ **Charge +1** (cap 8)
- เมื่อ Charge ถึง **6** → อัปเกรด "Military Merit" ของตัวนั้นเป็น **"Peerage"** อัตโนมัติ + ล้าง debuff Crowd Control ของตัวนั้น
  - ตัวที่มี "Peerage" ถือว่ามี "Military Merit" ไปพร้อมกัน
- ตัวที่มี **"Peerage"**:
  - +72% CRIT DMG เฉพาะดาเมจ Skill ของตัวเอง
  - +10% All-Type RES PEN
  - trigger **Coup de Main** เมื่อใช้ Skill ใส่ศัตรู หลัง Coup de Main จบ → กิน Charge 6 แต้ม, คืน "Peerage" กลับเป็น "Military Merit"
- Energy +30 · ไม่มี Toughness

## Ultimate — Scholar's Mate (AoE, 130 energy, Lv.10)
- ได้ **Charge +2**
- สร้าง Wind DMG = **240% ATK** ให้ศัตรูทุกตัว
- ถ้าในสนามไม่มีใครมี "Military Merit" → มอบให้ตัวละครลำดับแรกของทีมปัจจุบัน
- Energy +5 · Toughness 20

## Talent — Ave Imperator (Support, Lv.10)
- ตัวที่มี "Military Merit": **+ATK เท่ากับ 24% ของ ATK ของ Cerydra**
- เมื่อตัวนั้นใช้ Basic ATK หรือ Skill → Cerydra ได้ **Charge +1** (ยกเว้นช่วง Coup de Main จะไม่ได้ Charge)
- หลังตัวที่มี "Military Merit" โจมตี → Cerydra สร้าง Wind **Additional DMG = 60% ATK** เพิ่ม 1 instance
  - trigger ได้สูงสุด **20 ครั้ง** ตัวนับรีเซ็ตทุกครั้งที่ Cerydra ใช้ Ultimate
- "Military Merit" มีผลกับ **เป้าหมายล่าสุดตัวเดียว** เมื่อเปลี่ยนตัวที่ถือ → **Charge ของ Cerydra รีเซ็ตเป็น 0**

## Technique — First-Move Advantage
- หลังใช้ Technique → ได้ "Military Merit"
- เมื่อสลับตัวละคร active → "Military Merit" ย้ายตามตัว active ปัจจุบัน
- เริ่มการต่อสู้ถัดไป → ใช้ Skill อัตโนมัติ 1 ครั้งใส่ตัวที่ถือ "Military Merit" โดย**ไม่กิน Skill Point**

---

## Major Traces
- **A2 — Veni**: ทุก ๆ 100 ATK ของ Cerydra ที่เกิน 2000 → +18% CRIT DMG สูงสุด **+360%**
- **A4 — Vidi**: +100% CRIT Rate ให้ Cerydra. ขณะ Charge ยังไม่เต็ม ถ้าตัวที่มี "Military Merit" ใช้ Ultimate → Cerydra ได้ Charge +1 (ครั้งเดียว/การต่อสู้)
- **A6 — Vici**: เมื่อใช้ Skill → +20 SPD ให้ Cerydra และเพื่อนที่มี "Military Merit" นาน 3 เทิร์น. เมื่อตัวที่มี "Military Merit" ใช้ Basic ATK/Skill → คืน Energy 5 ให้ Cerydra

## Minor Traces (รวมทั้งหมด)
ATK +18% · Wind DMG +22.4% · HP +10%

## Eidolons
- **E1 — Seize the Crowns of All**: ตัวที่มี "Military Merit" **เพิกเฉย DEF 16%**. ถ้าอัปเป็น "Peerage" → เพิกเฉย DEF เพิ่มอีก **20%** เฉพาะดาเมจ Skill. เมื่อ Cerydra ใช้ Skill → คืน Energy 2 ให้ตัวเป้าหมาย
- **E2 — Forge the Dreams of Many**: ตัวที่มี "Military Merit" **+40% DMG**. ขณะมีเพื่อนถือ "Military Merit" ในสนาม → Cerydra **+160% DMG**
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Remake the Realms of Men**: Ultimate multiplier **+240%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — A Journey Set Starward**: ตัวที่มี "Military Merit" **+20% All-Type RES PEN** และ multiplier ของ Additional DMG จาก Talent **+300%**. ขณะมีเพื่อนถือ "Military Merit" → Cerydra **+20% All-Type RES PEN**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Charge**: cap 8, ได้จาก Skill(+1) / Ult(+2) / Talent เมื่อ target ทำ BA·Skill(+1) / A4(+1) เงื่อนไข. Coup de Main ระงับการได้ Charge จาก Talent
- **Threshold 6** = อัป Peerage อัตโนมัติ; Coup de Main จบ = กิน 6 Charge คืนเป็น Military Merit
- **เปลี่ยนตัวถือ Military Merit ⇒ Charge = 0** (สำคัญมากสำหรับ single-target buff logic)
- Talent ATK buff เป็น % ของ ATK **ของ Cerydra** (snapshot ต้องอัปเดตเมื่อ ATK Cerydra เปลี่ยน — โค้ดใช้ `calculateAtkForBuff` + `Buff_note`)
- Additional DMG counter รีเซ็ตที่ Ultimate ไม่ใช่ต่อเทิร์น
- A2 CRIT DMG scaling ผูกกับ ATK จริง → ต้อง re-evaluate ผ่าน `Stats_Adjust_List`

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/cerydra — kit tab (review patch 3.5, calc patch 4.0, profile 04/Jun/2026)
