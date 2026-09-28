# `src/Defination/Data/Character/Elation/Evanescia.h`

kit อ้างอิง: [`docs/kit-reference/Character/Elation/evanescia.md`](../../../../../kit-reference/Character/Elation/evanescia.md) (ข้อมูลเกม 4.5.54 จาก nanoka) · ชื่อ unit `"Evanescia"` · เลือกใน `SettingFunction.h` ด้วยชื่อ `Evanescia`
คำศัพท์ของ path Elation อยู่ใน [Hibana.md](Hibana.md) — อ่านก่อน

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**
> Participant ID ของ Elation Skill = **146** (ไม่อยู่ในไฟล์ kit ดูจาก nanoka) — ใช้เป็น priority ของ `elationSkillList` และเป็นเกณฑ์ของ A2

## ภาพรวมแบบสั้น

Evanescia เป็น DPS สาย Physical ที่ **Energy กับ Certified Banger (CB) ไหลเข้าหากัน**

- ได้ Energy เท่าไหร่ → ได้ CB เท่านั้น · ได้ CB เท่าไหร่ → ได้ Energy เท่านั้น (ครั้งละไม่เกิน 100)
- Energy ที่ได้สะสมครบ 240 → **Master Fox** ออกมาตี Follow-Up ทุกตัว
- Max Energy 480 = ต้องหา Energy เยอะมากกว่าจะกด Ult · ดังนั้น CB จากทีม (A2, A6) คือตัวเร่ง Ult และ Master Fox

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 104, Physical, Elation · HP/ATK/DEF 1048/737/461 · Max Energy 480 · Ult ใช้ 240 | `setCharBasicStats(104,480,240,...)` — maxEnergy 480, ultCost 240 (user สั่ง 2026-09-29) | 13-14 |
| build | CR / SPD / ATK% / ERR ตาม nanoka | `setRelicMainStats(...)` | 17-20 |
| นับเข้า Elation ในทีม | — | `elationCount++` | 22 |
| **Basic ATK** | 100% ATK เดี่ยว · toughness 10 · SP +1 · Energy 20 | lambda `ba` | 60-72 |
| **Skill** | Blast 300% / 150% · toughness 20/10 · SP −1 · Energy 30 · Punchline +10 | lambda `skill` | 74-96 |
| ↳ ถือ CB | Skill ตีเพิ่ม 16% Physical Elation ใส่เป้าที่โดน | action `ELATION_DMG` แยกก้อนหลังตี | 82-89 |
| **Ultimate** | 160% ATK ทุกตัว (toughness 20) แล้ว bounce 5 ครั้ง × 120% (toughness 5) | `ultimateList` · `addEnemyBounce(...,bounce)` | 141-185 |
| ↳ ถือ CB | Elation 24% ทุกตัว + 28% ใส่ศัตรูแต่ละตัวที่โดน bounce · นับ CB อย่างน้อยเท่า Max Energy | เก็บเป้าที่โดน bounce จากแถว `damageSplit` ตั้งแต่แถว 1 (แถว 0 = AoE) · ยกค่า CB ใต้ `AType::ELATION_DMG` ขึ้นชั่วคราวให้รวมได้ ≥ 480 แล้วคืนค่า | 146-153, 159-174 |
| เงื่อนไขกด Ult | Energy ครบ 240 (ใช้ Ult หัก 240 · เก็บได้สูงสุด 480) | ไม่มีเงื่อนไขเพิ่ม (`return true`) | 135-137 |
| AI เลือกท่า | — | `sp > spSafety` → Skill ไม่งั้น BA | 130-133 |
| **Talent: Elation = 20% ของ CD** | — | `statsAdjustList` เมื่อ CD เปลี่ยน ใส่ส่วนต่างเทียบ `buffNote["Evanescia Talent"]` · `whenOnFieldList` ปลุกครั้งแรกด้วย `statsAdjust(ptr,CD)` | 308-313, 293-295 |
| **Talent: Energy → CB** | ได้ Energy → ได้ CB เท่ากัน (≤ 100) | `whenEnergyIncreaseList` → `gainCB(min(100,energy), false)` — `false` = CB ก้อนนี้ไม่แปลงกลับเป็น Energy | 205-215 |
| **Talent: CB → Energy** | ได้ CB → ได้ Energy เท่ากัน (≤ 100) | `gainCB(x, true)` เพิ่ม CB แล้ว `increaseEnergy(ptr,min(100,x))` (**คูณ ERR** — kit ไม่ได้บอกว่า fixed) โดยตั้งธง `"Evanescia Energy From CB"` กันไม่ให้ Energy ก้อนนี้วนกลับเป็น CB อีก | 39-49 |
| ↳ CB จาก Aha Instant | ทุก Aha เธอได้ CB = Punchline ของ Aha นั้น | `afterAhaInstantList` อ่าน Punchline จาก `cbCheck.back()` แล้วแปลงเป็น Energy (CB ตัวนี้ engine ใส่ให้เองแล้ว) | 218-227 |
| **Talent: Master Fox** | Energy ที่ได้สะสมครบ 240 → Follow-Up 100% ATK ทุกตัว (toughness 10) + Energy 10 · ครั้งเดียวนับสะสมได้ไม่เกิน 240 | สะสมใน `buffNote["Evanescia Fox Acc"]` **เฉพาะ Energy ที่ได้จริง** (ส่วนที่ล้นเพดาน 480 ไม่นับ — event ยิงก่อนบวก จึงคิด `min(energy, maxEnergy − currentEnergy)`) · Energy 10 ท้าย Master Fox คูณ ERR · ครบเมื่อไหร่เรียก `masterFox()` ซึ่ง `addToActionBar` + `dealDamage` (ถ้าอยู่กลาง action จะต่อคิว) | 205-215, 99-126 |
| ↳ ถือ CB | Master Fox ตีเพิ่ม 25% Elation ทุกตัว | action `ELATION_DMG` แยกก้อน | 105-114 |
| **Elation Skill** | 110% Elation ทุกตัว · toughness 20 · Energy 5 · CB +5 | `elationSkillList` priority 146 · `addToAhaInstant()` · `gainCB(5,true)` | 188-202 |
| **Technique** | เข้าต่อสู้: 100% ATK ทุกตัว (toughness 20) + CB 20 | `startGameList` · `turnReset = 0` (ไม่ใช่เทิร์นใคร) | 263-279 |
| **Minor traces** | CR +18.7 · Elation +18 · SPD +5 | `resetList` | 281-285 |
| **A2** | CR +30% · bounce Ult +1/+2/+4 เมื่อศัตรู ≥3/2/1 ตัว · เพื่อนที่ ID ต่ำกว่าได้ CB → เธอได้ 50% ของนั้น | CR ใน `resetList` · `int bounce = 5 + ...` · ใน `afterAhaInstantList` นับเพื่อน Elation ที่ priority < 146 แล้ว `gainCB(PL × 0.5)` ต่อคน | 287, 181, 228-235 |
| **A4** | Master Fox แปะ Vulnerability 12% 3 เทิร์น | `debuffAllEnemyApply(...,"Evanescia A4",3)` · ถอนใน `afterTurnList` ตอนเทิร์นศัตรู | 103, 241-243 |
| **A6** | CB ของเพื่อนหมดอายุ → เธอได้ 50% ของนั้น | `afterTurnList` เทิร์นของเพื่อน Elation: หา CB ใน `cbCheck` ที่จะหมดเทิร์นนี้ (เช็คก่อน engine ถอน) แล้ว `gainCB(PL × 0.5)` | 253-259 |
| CB ของตัวเธอเองหมดอายุ | CB แต่ละก้อนนับเวลาแยกกัน | CB ที่ `gainCB` สร้างชื่อ `"Evanescia CB <n>"` อายุ `cbDuration` (E6 +1) เก็บคู่ {ชื่อ, ค่า} ใน `ownCB` · เทิร์นเธอจบ ก้อนไหน `isBuffEnd` ก็ถอนค่าออก | 30, 34-36, 245-251 |
| **E1** | RES PEN +20% · Master Fox ตีแล้ว → ใช้ Elation Skill อีก 1 ครั้ง · Elation Skill ให้ CB เพิ่มอีก 10 | `resetList` · `elationSkillTrigger(punchline,{"Evanescia"})` ท้าย Master Fox · `gainCB(15)` แทน 5 | 288, 116, 194 |
| **E2** | CD +36% · CB จาก A2 / A6 เพิ่มอีก 50% / 100% ของที่ได้ | `resetList` · ตัวคูณ ×1.5 ใน A2 และ ×2 ใน A6 | 289, 234, 258 |
| **E4** | ดาเมจเธอเจาะ DEF 15% | `DEF_SHRED` +15 ใน `resetList` | 290 |
| **E6** | CB ของเธออยู่นานขึ้น 1 เทิร์น · Elation merrymake 15% + 2% ต่อ CB ที่ถือทุก 100 (นับสูงสุด 1000) · Ult ครั้งแรก, 5, 9, … ได้ Energy 120 | `cbTurns()` +1 และยืด CB จาก Aha ของเธอ (`extendBuffTime`) · `beforeAttackList` ตั้ง `MERRYMAKE` ใหม่ทุกครั้งก่อนเธอตี · `Ult Count % 4 == 1` → `increaseEnergy(ptr,0,120)` | 34-36, 221, 298-305, 156-157 |

## Energy ⇄ CB ไม่วนไม่รู้จบได้ยังไง

kit บอกสองทิศทาง ถ้าทำตรง ๆ จะวนไม่รู้จบ (Energy → CB → Energy → …) โค้ดเลยให้ **ของที่ได้จากการแปลง ไม่แปลงกลับ**:

| ต้นทาง | ได้อะไรเพิ่ม | ได้แล้วแปลงต่อไหม |
|---|---|---|
| Energy ปกติ (BA, Skill, Elation Skill, Ult, Master Fox +10, E6 +120) | CB เท่ากัน (≤ 100) ของค่าที่ส่งเข้า event (หลังคูณ ERR) | ไม่ — `gainCB(..., false)` |
| CB (Aha, Elation Skill, Technique, A2, A6) | Energy = min(100, CB) × ERR | ไม่ — ตั้งธง `Evanescia Energy From CB` ทำให้ตัวดัก Energy ข้ามการสร้าง CB |

แต่ Energy ที่ได้ **ทุกแบบ** (รวมที่แปลงมาจาก CB) นับสะสมเข้า Master Fox เพราะ kit บอกว่านับ Energy ที่ได้ — **นับเฉพาะส่วนที่เข้าหลอดจริง** ส่วนที่ล้นไม่นับ

## จุดที่ตีความเอง

- **ultCost = 240** (user สั่ง 2026-09-29 · เดิม 480 เท่า Max Energy) — kit ไม่ได้บอกค่าใช้ Ult ตรง ๆ · Max Energy ยังเป็น 480 → เก็บ Energy ได้เกินค่าใช้ 1 ครั้ง
- **กติกา Energy (user 2026-09-28)**: Energy ที่ kit ไม่ได้เขียนว่า *fixed* ต้องคูณ ERR เสมอ (CB → Energy, Master Fox +10) · ที่เขียนว่า fixed ไม่คูณ (E6 +120) · Master Fox นับเฉพาะ Energy ที่เข้าหลอดจริง · ส่วน **Energy → CB ใช้ค่าเต็ม** แม้ Energy จะล้นหลอด (user ยืนยัน ไม่ต้องแก้)
- **อายุของ CB ที่เธอได้เอง** (A2, A6, Elation Skill, Technique, Energy → CB) = เท่ากับ CB จาก Aha Instant (`cbDuration`, E6 +1) — user ยืนยัน 2026-09-28
- **A2 "เพื่อนได้ CB"** นับเฉพาะ CB จาก Aha Instant (user ยืนยัน) (engine ให้ CB ทุกตัว Elation เท่ากัน = Punchline) · ทีมปัจจุบัน Hibana (144) กับ Yao Guang (114) ID ต่ำกว่า → นับ, SW999 (999) → ไม่นับ
- **A6** นับเฉพาะ CB จาก Aha ที่อยู่ใน `cbCheck` (user ยืนยัน) · CB ตั้งต้น 20 ตอนเริ่มรัน (`SetCombat.h`) ไม่ได้อยู่ใน `cbCheck` จึงไม่นับ
- **ค่าคงที่ 88 ในตาราง Ult** kit ไม่ได้อธิบาย → ไม่ได้ใช้
- **E6 merrymake นับ CB ที่ถือจริง** (`CB[NONE]`) ไม่รวมค่าที่ Ult ยกขึ้นชั่วคราว (อยู่ใต้ `ELATION_DMG`)

## จุดที่ควรระวัง

- **CB ของเธอมีสองแหล่งที่ถอนคนละที่** — CB จาก Aha ถูก engine ถอนผ่าน `cbCheck` ([Event.h](../../../Function/Event/Event.md)) ส่วน CB ที่ `gainCB` สร้างถอนเองใน `afterTurnList` ถ้าวันหลัง engine เปลี่ยนวิธีเก็บ CB ต้องแก้ทั้งคู่
- **A6 ต้องทำก่อน engine ถอน CB** — `afterTurnList` รันก่อนลูป `cbCheck` ใน `allEventAfterTurn` ถ้าลำดับนี้เปลี่ยน A6 จะไม่ทำงานเงียบ ๆ
- **Master Fox ซ้อนกันได้** — Energy +10 ท้าย Master Fox (และ E1 Elation Skill → CB → Energy) อาจครบ 240 อีกรอบ แต่จะต่อคิวหลัง ไม่ซ้อนกลางท่า
- **ยังไม่ได้รัน sim** — ควรดู Elation (จาก CD) และ CB/Energy ที่ ATV 1000–5000 ว่าไม่ไหลขึ้นหรือลงเรื่อย ๆ
