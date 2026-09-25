# The Herta — เดอะ เฮอร์ทา

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/The_Herta.h` |
| ธาตุ | **Ice** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 220 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

## Base Stats (Lv.80, ascended)
HP 1164 · ATK 679 · DEF 485 · SPD 99

> Erudition hypercarry สาย "Interpretation" stack

---

## Basic ATK — Did You Get It (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Big Brain Energy (Blast, Lv.10)
- Ice DMG = **70% ATK** ใส่เป้าหมาย + ติด **"Interpretation" 1 stack**
- Ice DMG = **70% ATK** ใส่เป้าหมายที่โดน + ข้างเคียง — **ทำซ้ำ 2 ครั้ง**
- Energy +30 · Toughness 15 (+5)

## Skill (Enhanced) — Hear Me Out (Blast, Lv.10)
- กิน **"Inspiration" 1 stack**
- Ice DMG = **80% ATK** ใส่เป้าหมาย + ติด "Interpretation" 1 stack
- Ice DMG = **80% ATK** ใส่เป้าหมาย + ข้างเคียง — ทำซ้ำ 2 ครั้ง
- สุดท้าย Ice DMG = **40% ATK** ใส่ศัตรูทุกตัว
- Energy +30 · Toughness 20 (+5)

## Ultimate — Told Ya! Magic Happens (AoE, 220 energy, Lv.10)
- จัดเรียง "Interpretation" stack ใหม่ ย้ายไปกอง Elite+ ก่อน
- Ice DMG = **200% ATK** AoE
- The Herta ATK **+80%** นาน 3 เทิร์น
- หลังใช้ → action ทันที + ได้ **"Inspiration" 1 stack** (สูงสุด 4) — ขณะมี Inspiration → Skill เป็น "Hear Me Out"
- Energy +5 · Toughness 20

## Talent — Hand Them Over (Lv.10)
- ศัตรูเข้าฉาก → ติด "Interpretation" 1 stack
- ต้นแต่ละ wave → ติด **"Interpretation" 25 stack** ใส่ศัตรูสุ่ม (Elite+ ก่อน)
- เมื่อ Enhanced Skill เป้าหมายหลักมี "Interpretation" → multiplier เพิ่ม ต่อ stack **+8%/+4%** (หลัก/รอง)
  - ถ้าในทีมมี Erudition ≥ 2 → ต่อ stack เพิ่มอีก **+8%/+4%**
- "Interpretation" สูงสุด **42 stack**
- ใช้ Enhanced Skill → reset "Interpretation" ของเป้าหมายหลักเป็น **1** (E1 → 15)
- ศัตรูออก/ตาย → "Interpretation" ย้าย (Elite+ ก่อน)
- Energy +5

## Technique — Vibe Checker
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป ATK **+60%** นาน 2 เทิร์น

---

## Major Traces
- **A2 — Aloofly Honest**: เพื่อนโจมตี → ติด "Interpretation" 1 stack ให้ศัตรูที่โดน. หลังโจมตี ต่อเป้าหมายที่โดน → คืน Energy คงที่ **3** (นับสูงสุด 5 เป้า). ใช้ Enhanced Skill ถ้าเป้าหมายหลักมี Interpretation ครบ 42 → The Herta Ice DMG **+50%** จนจบการโจมตี
- **A4 — Message From Beyond the Veil**: เข้าฉาก ถ้าทีมมี Erudition ≥ 2 → เพื่อนทุกคน CRIT DMG **+80%**, A2 นับเป้าอย่างน้อย 3, หลังโจมตี → ติด Interpretation 1 stack ให้ศัตรูที่มี stack สูงสุด (+2 stack ถ้าผู้โจมตีเป็น Erudition)
- **A6 — Starved Landscape of Vacua**: ต่อ 1 Interpretation ที่ยัดให้ศัตรู → The Herta ได้ **"Answer" 1 stack** (สูงสุด 99). ใช้ Ult → ต่อ Answer → Ult multiplier **+1%**

## Minor Traces (รวมทั้งหมด)
Ice DMG +22.4% · ATK +18% · SPD +5

## Eidolons
- **E1**: Enhanced Skill นับ Interpretation → นับ **50%** ของ stack บนตัวที่ stack สูงสุด (ในกลุ่มเป้าหมายหลัก+ข้างเคียง) เพิ่ม. reset เป็น **15** แทน 1
- **E2**: หลังเข้าฉากและใช้ Ult → Inspiration +1 stack. หลังใช้ Enhanced Skill → action advance **35%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ตัวละคร Erudition ในทีม SPD **+12%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: Ice RES PEN **+20%**. ศัตรู 3+/2/1 ตัว → Ult multiplier **+140%/+250%/+400%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Interpretation** (0–42): แหล่ง — enemy enter (+1), wave start (+25 random Elite), A2 (ally attack +1), Talent ทุก stack, reset เป็น 1/15 หลัง Enhanced Skill
- **Enhanced Skill multiplier**: +8%/stack (หลัก), +4%/stack (รอง); ×2 ถ้า Erudition ≥ 2 — ผูกกับ team composition
- **Inspiration** (0–4): +1/Ult; เปลี่ยน Skill → Hear Me Out; กิน 1/Enhanced Skill
- **Answer** (0–99, A6): +1 ต่อ Interpretation ที่ยัด → Ult multiplier +1%/stack
- **Ult**: rearrange stacks + ATK +80%/3t + instant action + Inspiration
- โค้ด: `Start_game_List` (`The_Herta.h:97`, `Hertaptr`)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/the-herta — kit tab (review/calc patch 3.0, profile 01/Jun/2026)
