# Jade — เจด

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Jade.h` |
| ธาตุ | **Quantum** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

## Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 509 · SPD 103

> Erudition FUA DPS สาย Charge/Pawned Asset + "Debt Collector"

---

## Basic ATK — Lash of Riches (Blast, Lv.6)
- Quantum DMG หลัก = **90% ATK**, ข้างเคียง = **30% ATK**
- Energy +20 · Toughness 10 (+5)

## Skill — Acquisition Surety (Support, Lv.10)
- ทำให้เพื่อน 1 ตัวเป็น **Debt Collector** + SPD **+30** นาน 3 เทิร์น
- หลัง Debt Collector โจมตี → Jade สร้าง Additional Quantum DMG = **25% ATK** ต่อศัตรูที่โดน 1 instance + กิน HP ของ Debt Collector = **2% Max HP** (ไม่พอ → HP = 1)
- ถ้า Jade เป็น Debt Collector เอง → ไม่ได้ SPD boost และการโจมตีไม่กิน HP
- ขณะมี Debt Collector ในสนาม Jade ใช้ Skill ไม่ได้; ต้นเทิร์นของ Jade → duration ลด 1
- Energy +30

## Ultimate — Vow of the Deep (AoE, 140 energy, Lv.10)
- Quantum DMG = **240% ATK** AoE
- เสริม follow-up attack จาก Talent: +multiplier **80%** (activate ได้ 2 ครั้ง)
- Energy +5 · Toughness 20

## Talent — Fang of Flare Flaying (AoE, Lv.10)
- หลัง Jade หรือเพื่อนที่เป็น/เคยเป็น Debt Collector โจมตี → Jade ได้ **Charge +1 ต่อศัตรูที่โดน**
- Charge ถึง **8** → กิน 8, ยิง follow-up: Quantum DMG = **120% ATK** AoE (follow-up นี้ไม่สร้าง Charge)
- เมื่อยิง follow-up → Jade ได้ **Pawned Asset +5 stack** (ต่อ stack: CRIT DMG **+2.4%**, สูงสุด 50 stack)
- Energy +10 · Toughness 10

## Technique — Visionary Predation
- ติด Blind Fealty ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Blind Fealty → ศัตรูที่ติดทั้งหมดเข้าฉากพร้อมกัน + Quantum DMG = **50% ATK** AoE + Jade ได้ **Pawned Asset +15 stack** ทันที

---

## Major Traces
- **A2 — Reverse Repo**: ศัตรูเข้าฉาก → Jade Pawned Asset +1. ต้นเทิร์นของเพื่อน Debt Collector → Jade Pawned Asset **+3**
- **A4 — Collateral Ticket**: ต้นการต่อสู้ → Jade action advance **50%**
- **A6 — Asset Forfeiture**: ทุก stack ของ Pawned Asset → Jade ATK **+0.5%**

## Minor Traces (รวมทั้งหมด)
ATK +18% · Quantum DMG +22.4% · Effect RES +10%

## Eidolons
- **E1**: Talent follow-up DMG **+32%**. หลัง Debt Collector โจมตีโดน 2/1 ตัว → Jade Charge **+1/+2**
- **E2**: เมื่อมี Pawned Asset 15 stack → Jade CRIT Rate **+18%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ใช้ Ult → Jade ดาเมจเพิกเฉย DEF **12%** นาน 3 เทิร์น
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: เมื่อมีเพื่อน Debt Collector ในสนาม → Jade Quantum RES PEN **+20%** และ Jade ได้สถานะ Debt Collector ด้วย

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Charge** (0–8): +1 ต่อศัตรูที่โดน หลัง Debt Collector attack (+E1); ครบ 8 → FUA 120% + reset
- **Pawned Asset** (0–50): +5/FUA, +15 Technique, A2 (+1 enter, +3 Debt Collector turn) → CRIT DMG 2.4%/stack, A6 ATK 0.5%/stack, E2 CRIT Rate
- **Debt Collector**: SPD +30 buff (ไม่ได้ถ้าเป็น Jade), heal-tax 2% Max HP/attack, Jade Additional DMG 25% ต่อ hit
- **Ult enhance**: next 2 FUA +80% multiplier
- **A4**: action advance 50% ต้นการต่อสู้ (`Start_game_List`)
- โค้ด: `Start_game_List` (`Jade.h:70`) มี addToActionBar + self-flush `Deal_damage()` — น่าจะเป็น technique DMG

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/jade — kit tab (review/calc patch 3.0, profile 01/Jun/2026)
