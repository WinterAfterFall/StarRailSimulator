# Luocha — โลชา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Luocha.h` |
| ธาตุ | **Imaginary** |
| Path | **Abundance** |
| ระดับ | 5★ |
| Energy Ultimate | 100 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1280 · ATK 756 · DEF 363 · SPD 101

---

## Basic ATK — Thorns of the Abyss (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Prayer of Abyss Flower (ฮีล, Lv.10)
- ฮีลเพื่อนเป้าหมาย = **60% ATK + 800** ทันที + Luocha ได้ **Abyss Flower 1 stack**
- เมื่อเพื่อนคนใด HP% ≤ 50% → trigger เอฟเฟกต์เทียบเท่า Skill ใส่ตัวนั้นทันที 1 ครั้ง (ไม่กิน Skill Point) — ทำซ้ำได้อีกหลัง **2 เทิร์น**
- Energy +30 · ไม่มี Toughness

## Ultimate — Death Wish (AoE, 100 energy, Lv.10)
- ลบ buff 1 อันจากศัตรูทุกตัว + Imaginary DMG = **200% ATK** AoE
- Luocha ได้ **Abyss Flower 1 stack**
- Energy +5 · Toughness 20

## Talent — Cycle of Life (Lv.10)
- เมื่อ Abyss Flower ครบ **2 stacks** → กินทั้งหมด กาง **Field** ใส่ศัตรู
- ขณะ Field: เพื่อนโจมตีศัตรูใน Field → ผู้โจมตีถูกฮีล = **18% ATK + 240** ทันที
- Field อยู่ **2 เทิร์น** ถ้า Luocha ถูกน็อค Field หาย

## Technique — Mercy of a Fool
- หลังใช้ Technique → trigger Talent ทันทีเมื่อเริ่มการต่อสู้ถัดไป (กาง Field ตั้งแต่ต้น)

---

## Major Traces
- **A2 — Cleansing Revival**: เมื่อเอฟเฟกต์ Skill trigger → ลบ debuff 1 อันจากเพื่อนเป้าหมาย
- **A4 — Sanctified**: เพื่อนโจมตีศัตรูใน Field → เพื่อนทุกคน (ยกเว้นผู้โจมตี) ฮีล = **7% ATK + 93**
- **A6 — Through the Valley**: +70% ต้านทาน Crowd Control

## Minor Traces (รวมทั้งหมด)
ATK +28% · DEF +12.5% · HP +18%

## Eidolons
- **E1 — Ablution of the Quick**: ขณะ Field active → เพื่อนทุกคน ATK **+20%**
- **E2 — Bestowal From the Pure**: เมื่อ Skill trigger ถ้าเป้าหมาย HP < 50% → Luocha Outgoing Healing **+30%**; ถ้า HP ≥ 50% → เป้าหมายได้ **Shield = 18% ATK + 240** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Heavy Lies the Crown**: ขณะ Field active → ศัตรู Weakened, สร้าง DMG น้อยลง **12%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — Reunion With the Dust**: ใช้ Ultimate → 100% fixed chance ลด All-Type RES ศัตรูทุกตัว **20%** นาน 2 เทิร์น

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Abyss Flower**: ได้ +1 จาก Skill และ Ult; ครบ 2 → auto กาง Field + reset stack เป็น 0 (โค้ด `Stack["Abyss_Flower"]`, ฟังก์ชัน `Abyss_Flower(ptr)`)
- **Auto-Skill on HP ≤ 50%**: passive heal โดยไม่กิน SP, cooldown 2 เทิร์น (ต่อ ally? ต่อ global? — เกมคือ per-trigger, cooldown ก่อน trigger ได้อีก)
- **Field heal-on-hit**: 18% ATK + 240 ให้ผู้โจมตี + A4 7% ATK + 93 ให้เพื่อนที่เหลือ
- ทุกค่าฮีล/shield สเกลกับ **ATK ของ Luocha**
- Technique (`ptr->Technique == 1`) → set `Stack = 2` + กาง Field ทันทีใน `Start_game_List`
- E1 (+20% ATK ทีม) / E4 (enemy -12% DMG) ผูกกับ Field active
- E6 RES shred 20% เป็น debuff จาก Ult

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/luocha — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)
