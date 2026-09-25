# Trailblazer • Remembrance — เทรลเบลเซอร์ (สาย Remembrance)  (โค้ด: **RMC**)

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/RMC.h` |
| ธาตุ | **Ice** |
| Path | **Remembrance** |
| ระดับ | 5★ (MC) |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.6) |

## Base Stats (Lv.80, ascended)
HP 1047 · ATK 543 · DEF 630 · SPD 103

> Remembrance support/sub-DPS สาย memosprite **Mem** + CRIT DMG buff + True DMG ("Mem's Support")

---

## Basic ATK — Leave It to Me! (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — I Choose You! (Summon, Lv.10)
- เรียก **Mem**; ถ้ามี Mem อยู่แล้ว → ฮีล Mem **60% Max HP ของ Mem** + Mem Charge **+10%**
- Energy +30

## Ultimate — Together, Mem! (AoE, 160 energy, Lv.10)
- เรียก Mem, Mem Charge **+40%**, จากนั้น Mem สร้าง Ice DMG = **240% ATK ของ Mem** AoE
- Energy +5 · Toughness 20

## Talent — Almighty Companion (Lv.10)
- Mem: initial SPD **130**, Max HP = **80% ของ Max HP ของ Trailblazer + 640**
- ทุก 10 Energy ที่เพื่อนทุกคนรวมกันคืน → Mem Charge **+1%**

## Technique — Memories Back as Echoes
- สร้าง Special Dimension 10 วิ (ศัตรู Time Stop)
- เข้าฉากกับศัตรู Time Stop → delay action ศัตรูทุกตัว **50%** + Ice DMG = **100% ATK** AoE

## Bonus Trace — Unfinished Epilogue
- หลังใช้ Ult → ได้ "Epic" 1 stack (สูงสุด 2). มี Epic + Mem ในสนาม → Basic ATK enhanced เป็น "Together, We Script Tomorrow!"

## Memosprite: Mem
### Memosprite Skill — Baddies! Trouble! (AoE, Lv.6)
- **4 instance × 36% ATK ของ Mem** ใส่ศัตรูสุ่ม + สุดท้าย **90% ATK ของ Mem** AoE
- Energy +10 · Toughness 5 (+10 ข้างเคียง)

### Memosprite Skill — Lemme! Help You! (Support, Lv.6)
- advance action เพื่อน 1 ตัว **100%** + มอบ **"Mem's Support"** นาน 3 เทิร์น
- ต่อ 1 instance ของดาเมจที่เป้าหมาย "Mem's Support" ทำ → เพิ่ม True DMG = **28% ของดาเมจเดิม** 1 instance
- ใช้ใส่ Trailblazer เอง → ไม่ได้ action advance
- Energy +10

### Memosprite Talent
- **Friends! Together!**: เพื่อนทุกคน CRIT DMG **+เท่ากับ 12% ของ CRIT DMG ของ Mem + 24%**. Charge < 100% → Mem auto "Baddies! Trouble!" ตอน action; Charge ถึง 100% → Mem action ทันที + เลือกเพื่อน 1 คนใช้ "Lemme! Help You!" ในการกระทำถัดไป
- **Go, Mem, Go!**: เรียก Mem → Charge **+50%** ทันที
- **No... Regrets**: Mem หาย → advance action Trailblazer **25%**

---

## Major Traces
- **A2 — Rhapsode's Scepter**: ต้นการต่อสู้ → Trailblazer action advance **30%**. เรียก Mem ครั้งแรก → Mem Charge **+40%**
- **A4 — Petite Parable**: ใช้ "Baddies! Trouble!" → Mem Charge **+5%**
- **A6 — Magnets and Long Chains**: ถ้าเป้าหมาย "Mem's Support" มี Max Energy > 100 → ทุก 10 Energy ส่วนเกิน → multiplier ของ True DMG จาก "Mem's Support" **+2%** สูงสุด **+20%**

## Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · HP +14% · ATK +14%

## Eidolons
- **E1**: เพื่อนที่มี "Mem's Support" CRIT Rate **+10%**. "Mem's Support" มีผลกับ memosprite/memomaster ของเป้าหมายด้วย (ไม่ stack)
- **E2**: เมื่อ memosprite ของเพื่อน (นอกจาก Mem) action → Trailblazer คืน Energy **8** (1 ครั้ง/เทิร์น, reset ต้นเทิร์นของ Trailblazer)
- **E3**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Talent Lv. +1
- **E4**: เมื่อเพื่อนที่มี Max Energy = 0 ใช้ ability → Mem Charge **+3%** + multiplier ของ True DMG จาก "Mem's Support" ของเป้าหมายนี้ **+6%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Skill Lv. +1
- **E6**: Ultimate CRIT Rate = **100%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Mem (memosprite)**: SPD 130, HP = 80% TB HP + 640; Charge 0–100% (Skill +10, Ult +40, Talent 1%/10 energy ทีม, summon +50%, A2 +40, A4 +5)
- **Charge < 100** → auto Baddies!; **Charge 100** → auto action + assign Lemme! Help You!
- **Mem's Support**: True DMG 28% ต่อ instance ของดาเมจเป้าหมาย (A6 +2%/10 energy เกิน 100, cap +20%; E4 +6%)
- **CRIT DMG buff (Friends! Together!)**: 12% × CD ของ Mem + 24% — ผูกกับ CD ของ Mem
- **ดาเมจ Mem สเกลกับ ATK ของ Mem** (แยก stat จาก Trailblazer)
- โค้ด: `Start_game_List` (`RMC.h:98`, `RMCptr`, `Memptr`) มี addToActionBar + `Deal_damage()` + `Action_forward 30` (A2)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/trailblazer-remembrance — kit tab (review patch 3.0, calc patch 3.6, profile 01/Jun/2026)
