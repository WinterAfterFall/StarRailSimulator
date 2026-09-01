# Tingyun — ถิงหยุน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Tingyun.h` |
| ธาตุ | **Lightning** |
| Path | **Harmony** |
| ระดับ | 4★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 846 · ATK 529 · DEF 396 · SPD 112

> Harmony support สาย ATK buff + Additional DMG (single-target "Benediction")

---

## Basic ATK — Dislodged (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Soothing Melody (Support, Lv.10)
- มอบ **Benediction** ให้เพื่อน 1 ตัว → ATK **+50%** แต่ไม่เกิน **25% ของ ATK ปัจจุบันของ Tingyun**
- เพื่อนที่มี Benediction เมื่อโจมตี → สร้าง Additional Lightning DMG = **40% ของ ATK ของเพื่อนคนนั้น** 1 ครั้ง
- Benediction นาน 3 เทิร์น มีผลกับเป้าหมาย Skill ล่าสุดเท่านั้น
- Energy +30

## Ultimate — Amidst the Rejoicing Clouds (Support, 130 energy, Lv.10)
- คืน Energy **50** ให้เพื่อน 1 ตัว + เป้าหมาย +DMG **50%** นาน 2 เทิร์น
- Energy +5

## Talent — Violet Sparknado (Lv.10)
- เมื่อ Tingyun โจมตีศัตรู → เพื่อนที่มี Benediction สร้าง Additional Lightning DMG = **60% ของ ATK ของเพื่อนคนนั้น** ใส่ศัตรูตัวเดียวกันทันที

## Technique — Gentle Breeze
- ใช้ Technique → Tingyun คืน Energy **50** ทันที

---

## Major Traces
- **A2 — Nourished Joviality**: หลังใช้ Skill → Tingyun SPD **+20%** นาน 1 เทิร์น
- **A4 — Knell Subdual**: Basic ATK DMG **+40%**
- **A6 — Jubilant Passage**: ต้นเทิร์นของ Tingyun → คืน Energy **5** ทันที

## Minor Traces (รวมทั้งหมด)
ATK +28% · DEF +22.5% · Lightning DMG +8%

## Eidolons
- **E1**: หลังเพื่อนที่มี Benediction ใช้ Ultimate → SPD **+20%** นาน 1 เทิร์น
- **E2**: เพื่อนที่มี Benediction คืน Energy **5** หลังฆ่าศัตรู (1 ครั้ง/เทิร์น)
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: multiplier ของ Benediction Additional DMG **+20%** (40%→60% skill hit, 60%→80% talent)
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Ultimate คืน Energy ให้เป้าหมายเพิ่ม **+10** (รวม 60)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Benediction**: ATK% buff = min(50%, 25% × ATK ปัจจุบันของ Tingyun / ATK เป้าหมาย?) — จริง ๆ คือ "ATK +50% แต่ค่า flat ที่เพิ่มไม่เกิน 25% ของ ATK ของ Tingyun" → ต้องคิด cap ให้ถูก
- **Additional Lightning DMG**: 40% ATK ของเพื่อน (Skill trigger, ต่อการโจมตี) + 60% ATK ของเพื่อน (Talent trigger เมื่อ Tingyun ตี) — สเกลกับ ATK ของ **เพื่อน** ไม่ใช่ Tingyun (E4 +20%)
- single-target buffer — ผูกกับ target ล่าสุด, 3 เทิร์น
- **Ult** = pure energy battery (50, E6 60) + DMG% 50%
- โค้ด: `Start_game_List` (`Tingyun.h:95`, `TYptr`)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tingyun — kit tab (review patch 2.6, calc patch 3.4, profile 01/Jun/2026)
