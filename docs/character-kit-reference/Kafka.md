# Kafka — คาฟกา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Kafka.h` |
| ธาตุ | **Lightning** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review patch 4.0 / calc patch 3.5) |

## Base Stats (Lv.80, ascended)
HP 1086 · ATK 679 · DEF 485 · SPD 100

> Nihility DoT DPS สาย Shock + DoT detonation

---

## Basic ATK — Midnight Tumult (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Caressing Moonlight (Blast, Lv.10)
- Lightning DMG หลัก = **160% ATK**, ข้างเคียง = **60% ATK**
- ถ้าเป้าหมาย/ข้างเคียงติด DoT → DoT ทั้งหมดลงดาเมจทันที = **75% (หลัก) / 50% (ข้างเคียง)** ของดาเมจเดิม
- Energy +30 · Toughness 20 (+10)

## Ultimate — Twilight Trill (AoE, 120 energy, Lv.10)
- Lightning DMG = **80% ATK** AoE
- 100% base chance ศัตรูติด **Shocked** + DoT ปัจจุบันลงดาเมจทันที = **120%** ของดาเมจเดิม
- Shock: Lightning DoT = **290% ATK** ต้นทุกเทิร์น นาน 2 เทิร์น
- Energy +5 · Toughness 20

## Talent — Gentle but Cruel (Lv.10)
- หลังเพื่อนใช้การโจมตีใส่ศัตรู → Kafka ยิง Follow-up ATK: Lightning DMG = **140% ATK** ใส่เป้าหมายหลัก + 100% base chance ติด Shock (แบบ Ult) นาน 2 เทิร์น
- trigger ได้ **2 ครั้ง**, คืน 1 use ตอนจบเทิร์นของ Kafka
- Energy +10 · Toughness 10

## Technique — Mercy Is Not Forgiveness
- เข้าฉากโจมตี AoE: Lightning DMG = **50% ATK** + 100% base chance ติด Shock (แบบ Ult) ศัตรูทุกตัว นาน 2 เทิร์น
- Toughness 20

---

## Major Traces
- **A2 — Torture**: ถ้าเพื่อนมี Effect Hit Rate ≥ 75% → Kafka เพิ่ม ATK ให้เพื่อนคนนั้น **+100%**
- **A4 — Plunder**: ถ้าศัตรูตายขณะ Shocked → Kafka คืน Energy **5**
- **A6 — Thorns**: หลังใช้ Ult → Talent Follow-up ATK trigger ได้ 1 ครั้ง + Follow-up ATK นั้นทำให้ DoT ทั้งหมดบนเป้าลงดาเมจทันที = **80%** ของดาเมจเดิม

## Minor Traces (รวมทั้งหมด)
ATK +28% · Effect HIT Rate +18% · HP +10%

## Eidolons
- **E1**: เมื่อโจมตี → 100% base chance เป้าหมายรับ DoT เพิ่ม **+30%** นาน 2 เทิร์น
- **E2**: ขณะ Kafka อยู่ในสนาม → DoT ของเพื่อนทุกคน **+33%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: เมื่อศัตรูรับดาเมจจาก Shock ของ Kafka → Kafka คืน Energy **2**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Shock DMG multiplier จาก Ult/Technique/Talent-FUA **+156%** + Shock **+1 เทิร์น**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Shock** DoT: 290% ATK/2t (E6 +156% + 1t) — จาก Ult / Technique / Talent FUA
- **DoT detonation**: Skill 75/50%, Ult 120%, A6 FUA 80% — ต้อง track DoT "original DMG" ต่อ instance
- **Talent FUA**: 140% ATK + Shock, 2 charges, +1/turn (A6 +1 หลัง Ult) — trigger ต่อการโจมตีของเพื่อน
- **A2**: ATK +100% ให้เพื่อนที่ EHR ≥ 75% (มักคู่ Black Swan)
- **E2 DoT +33% ทีม** / E1 DoT vulnerability +30%
- **energy**: A4 (+5 kill), E4 (+2 ต่อ Shock tick)
- โค้ด: `Start_game_List` (`Kafka.h:136`, `kafka`) — technique Shock + self-flush

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/kafka — kit tab (review patch 4.0, calc patch 3.5, profile 01/Jun/2026)
