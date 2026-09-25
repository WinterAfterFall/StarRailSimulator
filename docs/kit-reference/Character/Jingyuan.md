# Jing Yuan — จิ่งหยวน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Jingyuan.h` |
| ธาตุ | **Lightning** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.7 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1164 · ATK 698 · DEF 485 · SPD 99

> Erudition DPS สาย summon "Lightning-Lord" (LL)

---

## Basic ATK — Glistening Light (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Rifting Zenith (AoE, Lv.10)
- Lightning DMG = **100% ATK** AoE
- เพิ่ม **Hits Per Action ของ Lightning-Lord +2** สำหรับเทิร์นถัดไป
- Energy +30 · Toughness 10

## Ultimate — Lightbringer (AoE, 130 energy, Lv.10)
- Lightning DMG = **200% ATK** AoE
- เพิ่ม **Hits Per Action ของ Lightning-Lord +3** สำหรับเทิร์นถัดไป
- Energy +5 · Toughness 20

## Talent — Prana Extirpated (Bounce, Lv.10)
- เรียก **Lightning-Lord** ต้นการต่อสู้: base SPD **60**, base Hits Per Action **3**
- LL action นับเป็น follow-up attack: แต่ละ hit = **66% ATK** Lightning DMG ใส่ศัตรูสุ่ม 1 ตัว + ศัตรูข้างเคียงรับ **25% ของดาเมจที่ทำกับเป้าหมาย**
- Hits Per Action สูงสุด **10**; ทุก +1 hit → LL SPD +10. หลัง LL action จบ → SPD และ Hits Per Action กลับค่า base
- Jing Yuan ถูกน็อค → LL หาย; Jing Yuan ติด CC → LL ทำ action ไม่ได้
- Toughness 5 (ต่อ hit)

## Technique — Spirit Invocation
- หลังใช้ Technique → LL Hits Per Action ในเทิร์นแรกของการต่อสู้ถัดไป **+3**

---

## Major Traces
- **A2 — Battalia Crush**: ถ้า LL Hits Per Action ≥ 6 ในเทิร์นถัดไป → LL CRIT DMG **+25%** สำหรับเทิร์นนั้น
- **A4 — Savant Providence**: ต้นการต่อสู้ → คืน Energy **15** ทันที
- **A6 — War Marshal**: หลังใช้ Skill → CRIT Rate **+10%** นาน 2 เทิร์น

## Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · ATK +28% · DEF +12.5%

## Eidolons
- **E1**: เมื่อ LL โจมตี → multiplier ใส่ศัตรูข้างเคียงเพิ่มอีก **25% ของ multiplier ที่ใส่เป้าหมาย**
- **E2**: หลัง LL action → ดาเมจจาก BA/Skill/Ult ของ Jing Yuan **+20%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ต่อ hit ของ LL → Jing Yuan คืน Energy **2**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ทุก hit ของ LL → เป้าหมาย Vulnerable รับดาเมจเพิ่ม **12%** จนจบเทิร์นของ LL stack 3 ครั้ง

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Lightning-Lord** = summon แยก action bar: base SPD 60, base HPA 3, SPD = 60 + 10×(HPA−3)
- **HPA**: base 3 + Skill(+2) + Ult(+3) + Technique(+3 เทิร์นแรก) สำหรับ **เทิร์นถัดไปเท่านั้น** แล้ว reset — สะสมได้จนถึง cap 10
- LL hit = FUA 66% ATK ต่อ hit ใส่ศัตรูสุ่ม + blast 25% ให้ข้างเคียง (E1: +25% ของ main multiplier)
- **A2**: LL CRIT DMG +25% ถ้า HPA ≥ 6
- โค้ด: `Start_game_List` (`Jingyuan.h:97`, `JYptr`) — summon LL + Technique HPA
- ต้อง track "next turn HPA" แยกจาก current

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/jing-yuan — kit tab (review patch 2.7, calc patch 4.0, profile 01/Jun/2026)
