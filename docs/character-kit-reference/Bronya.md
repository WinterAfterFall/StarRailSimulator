# Bronya — โบรเนีย

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Bronya.h` |
| ธาตุ | **Wind** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

## Base Stats (Lv.80, ascended)
HP 1241 · ATK 582 · DEF 533 · SPD 99

> Harmony support สาย turn-advance + DMG/ATK/CRIT DMG buff

---

## Basic ATK — Windrider Bullet (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Combat Redeployment (Support, Lv.10)
- ลบ debuff 1 อันจากเพื่อน 1 ตัว, ให้เพื่อนคนนั้น **action ทันที**, +DMG **66%** นาน 1 เทิร์น
- ถ้าใช้ใส่ Bronya เอง → ไม่ได้ action ทันที
- Energy +30

## Ultimate — The Belobog March (Support, 120 energy, Lv.10)
- เพื่อนทุกคน ATK **+55%**
- เพื่อนทุกคน CRIT DMG **+เท่ากับ 16% ของ CRIT DMG ของ Bronya + 20%** นาน 2 เทิร์น
- Energy +5

## Talent — Leading the Way (Lv.10)
- หลังใช้ Basic ATK → action ครั้งถัดไปของ Bronya advance **30%**
- Energy +5 · Toughness 10

## Technique — Banner of Command
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป เพื่อนทุกคน ATK **+15%** นาน 2 เทิร์น

---

## Major Traces
- **A2 — Command**: CRIT Rate ของ Basic ATK เพิ่มเป็น **100%**
- **A4 — Battlefield**: ต้นการต่อสู้ → เพื่อนทุกคน DEF **+20%** นาน 2 เทิร์น
- **A6 — Military Might**: ขณะ Bronya อยู่ในสนาม → เพื่อนทุกคน +DMG **10%**

## Minor Traces (รวมทั้งหมด)
Wind DMG +22.4% · CRIT DMG +24% · Effect RES +10%

## Eidolons
- **E1 — Hone Your Strength**: ใช้ Skill มี 50% fixed chance คืน Skill Point 1 (cooldown 1 เทิร์น)
- **E2 — Quick March**: ใช้ Skill → เป้าหมาย SPD **+30%** หลัง action นาน 1 เทิร์น
- **E3**: Ultimate Lv. +2 · Talent Lv. +2
- **E4 — Take by Surprise**: หลังเพื่อนใช้ Basic ATK ใส่ศัตรูที่มี Wind Weakness → Bronya ยิง follow-up: Wind DMG = **80% ของดาเมจ Basic ATK ของ Bronya** (1 ครั้ง/เทิร์น)
- **E5**: Skill Lv. +2 · Basic ATK Lv. +1
- **E6 — Piercing Rainbow**: DMG Boost จาก Skill → duration **+1 เทิร์น** (รวม 2)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill**: forced action (turn advance 100% effectively) + DMG% buff 66%/1t — ไม่ทำงานตอนใส่ตัวเอง (โค้ดต้อง handle self-target case)
- **Ult CRIT DMG buff**: 0.16 × (CRIT DMG ของ Bronya) + 20% — ผูกกับ CD stat ของ Bronya ต้อง snapshot/re-eval
- **Talent**: BA → self advance 30%
- **A2**: BA CRIT Rate = 100% (มักใช้กับ Bronya-as-DPS niche / E4)
- โค้ด: `Start_game_List` (`Bronya.h:65`, `Bronyaptr`) — A4 DEF buff + technique ATK buff
- driver logic ในโค้ดมี `DriverType` — Bronya skill = pull target ให้ action

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/bronya — kit tab (review/calc patch 3.0, profile 01/Jun/2026)
