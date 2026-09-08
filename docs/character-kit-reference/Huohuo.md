# Huohuo — โฮโฮ

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Huohuo.h` |
| ธาตุ | **Wind** |
| Path | **Abundance** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review/calc patch 4.2) |

## Base Stats (Lv.80, ascended)
HP 1358 · ATK 601 · DEF 509 · SPD 98

---

## Basic ATK — Banner: Stormcaller (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **50% Max HP ของ Huohuo** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Talisman: Protection (ฮีล, Lv.10)
- ลบ debuff 1 อันจากเพื่อนเป้าหมาย + ฮีลเป้าหมาย = **24% Max HP + 640**
- ฮีลเพื่อนที่อยู่ติดกับเป้าหมาย = **19.2% Max HP + 512**
- Energy +30 · ไม่มี Toughness

## Ultimate — Tail: Spiritual Domination (Support, 140 energy, Lv.10)
- คืน Energy ให้เพื่อนทุกคน (ยกเว้นตัวเอง) = **20% ของ Max Energy** ของแต่ละคน
- +ATK **40%** ให้เพื่อนทุกคน นาน 2 เทิร์น
- Energy +5 · ไม่มี Toughness

## Talent — Possession: Ethereal Metaflow (Lv.10)
- หลังใช้ Skill/Ultimate → Huohuo ได้ **"Divine Provision"** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Huohuo)
- ขณะมี "Divine Provision" เมื่อเริ่มเทิร์นของเพื่อน หรือเพื่อนใช้ Ultimate:
  - ฮีลเพื่อนคนนั้น + เพื่อนที่ HP% ต่ำสุด = **4.5% Max HP + 120**
  - จากนั้นฮีลเพื่อนทุกคนที่ HP% ≤ 50% = **4.5% Max HP + 120**
- เมื่อ "Divine Provision" trigger ฮีลเพื่อน → ลบ debuff 1 อันจากตัวนั้น
- trigger ได้ **6 ครั้ง** ต่อการได้ "Divine Provision" 1 รอบ (ได้ใหม่ = รีเซ็ตตัวนับ)

## Technique — Fiend: Impeachment of Evil
- ติด Horror-Struck ให้ศัตรูรอบข้าง (หนีจาก Huohuo 10 วิ)
- เข้าการต่อสู้กับศัตรูที่ Horror-Struck → 100% base chance ลด ATK ศัตรูทุกตัว **25%** นาน 2 เทิร์น

---

## Major Traces
- **A2 — Fearful to Act**: เริ่มการต่อสู้ → Huohuo ได้ Energy **30** + "Divine Provision" นาน 2 เทิร์น
- **A4 — The Cursed One**: +35% ต้านทาน Crowd Control. เมื่อใช้ Ultimate ถ้าเพื่อนเป้าหมายมี Max Energy ≥ 160 → +ATK เพิ่มอีก **24%**
- **A6 — Stress Reaction to Horror**: เมื่อ Talent trigger ฮีลเพื่อน → Huohuo คืน Energy **1**

## Minor Traces (รวมทั้งหมด)
HP +28% · Effect RES +18% · SPD +5

## Eidolons
- **E1**: "Divine Provision" +1 เทิร์น. ขณะมี "Divine Provision" → Huohuo Outgoing Healing **+20%**, เพื่อนทุกคน SPD **+12%**
- **E2**: ขณะมี "Divine Provision" ถ้าเพื่อนโดน killing blow → ไม่ล้ม + ฮีลทันที **50% Max HP** ของตัวนั้น, ลด "Divine Provision" 1 เทิร์น. trigger ได้ 2 ครั้ง/การต่อสู้
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E4**: ฮีลผ่าน Skill/Talent → เป้าหมาย HP ยิ่งต่ำยิ่งฮีลมาก สูงสุด **+80%**
- **E5**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E6**: เมื่อฮีลเพื่อน → เป้าหมาย +DMG dealt **50%** นาน 2 เทิร์น

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ทุกอย่างสเกลกับ Max HP ของ Huohuo** (BA 50%, Skill 24%/19.2%, Talent 4.5%)
- **Divine Provision** = สถานะแกน: ให้ทั้ง passive heal (เริ่มเทิร์นเพื่อน / เพื่อนใช้ Ult), debuff cleanse, cap 6 ครั้ง, ลดเวลาตอนเริ่มเทิร์น Huohuo
- **Ultimate** = energy regen เป็น % ของ Max Energy เพื่อน (ไม่ใช่ค่าคงที่) + ATK% buff
- A4: ATK buff แยกเป็น 40% base + 24% conditional (Max Energy ≥ 160)
- A2: pre-combat energy 30 + Divine Provision 2 เทิร์น (โค้ดใน `Start_game_List`)
- E1 SPD +12% ทีม + Huohuo outgoing heal +20% ผูกกับการถือ Divine Provision
- E6 DMG buff 50% ติดตอนฮีล — apply กว้าง (ทุกครั้งที่ heal target)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/huohuo — kit tab (review/calc patch 4.2, profile 01/Jun/2026)
