# `src/Defination/Data/Character/Abundance/Gallagher.h`

kit อ้างอิง: `docs/kit-reference/Character/Abundance/gallagher.md` · **ไฟล์อ้างอิงของ "stat ที่คำนวณจาก stat อื่นแบบ live"** (A2: Outgoing Healing = 50% ของ Break Effect) — กลไกนี้ไม่มีในตัวละครอื่นที่สำรวจมา · คู่กับ `Luocha.md` สำหรับระบบฮีลพื้นฐาน

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | บรรทัดใน `Gallagher.h` |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(98, 110, 110, E, ElementType::FIRE, Path::ABUNDANCE, "Gallagher", UnitType::STANDARD)` | 14 |
| Base HP/ATK/DEF | `setAllyBaseStats(1305, 529, 441)` | 15 |
| build — **substat เป็น `BE`** (Break Effect) | `pushSubstats(Stats::BE)` + main stat หมวก `HEALING_OUT` + `setSpeedRequire(150)` | 18-21 |
| **Basic ATK** — Corkage Fee | `basicAtk(ptr)` — `addDamageIns` 2 ครั้ง (55/5) | 166-178 |
| **Enhanced BA** — Nectar Blitz | `enchanceBasicAtk(ptr)` — 3 จังหวะ (68.75/7.5, 41.25/4.5, 165/18) = 275% (Lv7 ตาม E3 เหมือน BA ปกติ 110%) + ลด ATK เป้า | 179-197 |
| Nectar Blitz ลด ATK เป้า 16% | `target->atkPercent -= 16` + `debuffApply` + `extendDebuff(..., "Nectar_Blitz", 2)` | 186-188 |
| **Skill** — Special Brew (ฮีลล้วน) | `skillFunc(ptr)` — **`AllyBuffAction`** ไม่ใช่ `AllyAttackAction` เพราะไม่มีดาเมจ | 198-209 |
| **Ultimate** — Champagne Etiquette | `ultimateList` (`PRIORITY_DEBUFF`) — AoE 165%×3 args | 44-67 |
| Ult → ติด Besotted | `debuffAllEnemyApply(charPtr, {{Stats::VUL, AType::BREAK, 13.2}}, "Besotted")` แล้ว `extendDebuffAll` แยก | 50-55 |
| Ult → BA ครั้งถัดไปเป็น Nectar Blitz | `ptr->buffCheck["Gallagher_enchance_basic_atk"] = 1` | 49 |
| **A4** — หลัง Ult advance 100% | `actionForward(ptr->atvStats.get(), 100)` ใน callback ของ Ult | 48 |
| **Talent** — Besotted ให้ Break DMG taken +12% | อยู่ในตัว debuff เอง: `Stats::VUL` ที่ `AType::BREAK` | 50 |
| **Talent** — ตี Besotted → ผู้โจมตีถูกฮีล | `whenAttackList` (`PRIORITY_HEAL`) → นับเป้าที่ติด Besotted แล้ว `restoreHP(act->attacker, ...)` | 138-146 |
| **A6** — Nectar Blitz → ฮีลทั้งทีม | สาขา `isSameAction("Gallagher", AType::BA) && buffCheck[...] == 1` → `restoreHP(HealSrc)` **overload 1 arg = ฮีลทุกคน** | 126-137 |
| **A2** — Outgoing Healing = 50% ของ Break Effect (cap 75) | `whenOnFieldList` ตั้งค่าครั้งแรก + `statsAdjustList` คำนวณใหม่ทุกครั้งที่ `BE` เปลี่ยน | 104-108, 148-155 |
| **Technique** | อยู่ใน `whenOnFieldList` (**ไม่ใช่ `startGameList`** แบบตัวอื่น) | 109-123 |
| **Minor traces** | `resetList` | 69-84 |
| **E1** — ต้นเกม energy 20 | `startGameList` → `if (ptr->eidolon >= 1) increaseEnergy(ptr, 20)` + `resetList` → Effect RES +50% | 77-79, 98-102 |
| **E4** — Besotted จาก Ult ยืดอีก 1 เทิร์น | `extendDebuffAll("Besotted", 3)` แทน 2 | 51-55 |
| **E6** — Break Effect / Break Efficiency +20% | `resetList` → `Stats::BREAK_EFF += 20` และ `Stats::BE += 20` | 80-83 |
| **E2** | **ไม่มี** | — |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — `turnCnt % 8 == 1` → Skill · ไม่งั้นดู flag ว่าเป็น EBA หรือ BA | 29-39 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `phaseStatus != BEFORE_TURN && atv != 0` | 40-42 |
| หมด Besotted / Nectar_Blitz → ถอน | `afterTurnList` + `canCastToEnemy()` + `isDebuffEnd` | 86-95 |

## รากฐานที่เพิ่ม

**1. `statsAdjustList` — stat ที่ต้องคำนวณใหม่เมื่อ stat ต้นทางเปลี่ยน**
`statsAdjustList.push_back(TriggerByStats(PRIORITY_HEAL, [](AllyUnit* target, Stats statsType){...}))` · ถูกยิงจาก `statsAdjust(ptr, statsType)` ซึ่ง `buffSingle` เรียกให้เองทุกครั้งที่ลงบัฟแบบ `AType::NONE` (`Function/Combat/Buff_Stats.h:91,102`) · handler ต้อง guard 2 ชั้นเสมอ: **stat ที่เปลี่ยนใช่ตัวที่เราสนใจไหม** และ **เจ้าของ stat ใช่เราไหม** (146) เพราะ list เป็นของกลาง · `allEventAdjustStats` ตั้ง `adjustCheck = 1` ระหว่างวน (`Function/Event/Event.h:203`) เป็นตัวกันลูปซ้อน

**2. สำนวน "เก็บค่าที่ลงไปล่าสุด" สำหรับ stat ที่คำนวณต่อเนื่อง**

```cpp
double temp = calculateBreakEffectForBuff(ptr, 50);
if (temp > 75) temp = 75;
buffSingle(ptr, {{Stats::HEALING_OUT, AType::NONE, temp - ptr->buffNote["Novel Concoction"]}});
ptr->buffNote["Novel Concoction"] = temp;
```

`buffSingle` บวกค่าดิบเสมอ ไม่มีการ "ตั้งค่าเป็น" → ต้องลงเฉพาะ **ส่วนต่าง** จากค่าที่เคยลงไว้ แล้วจำค่าใหม่ไว้ใน `buffNote` · **รูปแบบนี้ใช้ได้กับทุก trace ที่เป็น "stat A = สัดส่วนของ stat B"** และโค้ดต้องอยู่ 2 ที่เสมอ: ตอนเริ่ม (`whenOnFieldList`) และตอน B เปลี่ยน (`statsAdjustList`)

**3. `calculateXForBuff(ptr, ratio)` = อ่านค่า stat ปัจจุบันเป็นสัดส่วน**
`calculateBreakEffectForBuff(ptr, 50)` = 50% ของ Break Effect · สังเกตว่ามันลบ `statsType[BE][AType::TEMP]` ออกก่อน (`CalStats.h:86`) คือ **ไม่นับส่วนที่เป็นบัฟชั่วคราว** และ clamp ไม่ให้ติดลบ · มีชุดเดียวกันสำหรับ ATK (`calculateAtkForBuff`) และ EHR (`calculateEhrForBuff`)

**4. `restoreHP(HealSrc)` overload เดียว = ฮีลทุกคนในทีม**
(`Function/Combat/ChangeHP.h:65`) วน `allyList` ทั้งหมด — ต่างจาก `restoreHP(target, HealSrc)` ที่ฮีลคนเดียว · A6 ของ Gallagher ใช้ความต่างนี้ตรง ๆ: Nectar Blitz → overload ฮีลทั้งทีม, BA ปกติ → overload ฮีลผู้โจมตี (125-143)

**5. `AllyBuffAction` ใช้กับ action ที่ไม่มีดาเมจเลย**
Skill ของ Gallagher เป็นการฮีลล้วน จึงไม่ใช้ `AllyAttackAction` · ประกอบด้วย `addBuffSingleTarget(chooseAllyBuff(ptr))` + `addToActionBar()` เหมือน Skill/Ult ของ Tingyun

**6. debuff ที่ลดค่าของศัตรูโดยตรงเขียนที่ฟิลด์ของศัตรู ไม่ใช่ `statsType`**
`target->atkPercent -= 16` (184) และคืนด้วย `focusUnit->atkPercent += 16` (90) — ใช้เมื่อผลไม่ได้เข้าสูตรดาเมจของฝ่ายเรา

**7. `act->isSameAction(ชื่อ, AType)` = ตัวกรองมาตรฐานใน `whenAttackList`**
(`Class/ActionData/AllyActionData.h:56-58`) มี 3 overload: ตาม `AType` อย่างเดียว, ตาม `AllyUnit*`, ตามชื่อ string

**8. `if(!actionBarUse) dealDamage();`**
`actionBarUse` เป็น flag กลาง (`Setting.h:69`) ที่ `Combat.h:108-125` ตั้งระหว่างประมวลผล action bar อยู่ — กันการเรียก `dealDamage()` ซ้อนตอนที่ระบบกำลังไล่คิวอยู่แล้ว · ตัวละครอื่นเรียก `dealDamage()` ตรง ๆ

## ตัวเลขที่ไม่ตรง kit (ปรับ level แล้ว ไม่ใช่บั๊ก)

| | kit (Lv.10) | โค้ด |
|---|---|---|
| Besotted — Break DMG taken | 12% | 13.2 |
| Nectar Blitz — ลด ATK | 15% | 16 |
| Skill heal | 1600 | 1768 |
| Talent heal ต่อเป้าที่ Besotted | 640 | 707 |
| Ult DMG | 150% | 165% |
| Nectar Blitz DMG | 250% (Lv6) | 275% (Lv7) |

> **แก้ 2026-09-26**: Nectar Blitz เดิม 250% (Lv6) ไม่ตรงกับ BA ปกติ 110% / ลด ATK 16% ที่เป็น Lv7 → ปรับเป็น 275% (user เลือก Lv7) · Effect RES จาก minor trace 18 → 28 ตาม kit · เพิ่ม E1 Effect RES +50% · อัปเดตเลขบรรทัดทั้งตาราง

## ส่วนที่ยังไม่มีในโค้ด

- **E2 — Lion’s Tail** (Skill ลบ debuff 1 อัน + Effect RES +30% 2 เทิร์น) ไม่มีทั้งอัน · ส่วนลบ debuff ไม่มีระบบ cleanse รองรับ (เหมือน A2 ของ `Luocha.md`)

## จุดที่ควรระวัง

- ~~**Nectar Blitz ลด ATK ซ้ำซ้อนได้**~~ **แก้ 2026-09-26**: เดิมไม่เช็คค่าที่ `debuffApply` คืน → ลบ 16 ทุกครั้งแต่คืนครั้งเดียว ค่ารั่วถาวร · ตอนนี้ `if(debuffApply(...)) atkPercent -= 16` ลบเฉพาะตอนติดใหม่ (ต่ออายุด้วย `extendDebuff` เหมือนเดิม)
- **`turnFunc` กด Skill ทุก 8 เทิร์นแบบตายตัว** (30) — kit ไม่มีกฎนี้ Gallagher ควรกด Skill เมื่อทีมต้องการฮีล · เป็นการประมาณรอบที่ไม่ได้อิงสถานะจริง ต่างจาก `The_Herta.h` ที่อ่าน `sp` / `spSafety` ของเกม
- **Ult ลง Besotted โดยไม่ระบุ duration แล้วค่อย `extendDebuffAll` ทีหลัง** (50-55) — ต่างจาก Technique ที่ส่ง `2` ไปกับ `debuffAllEnemyApply` เลย (110) · ผลเหมือนกันแต่เป็นสองสำนวนในไฟล์เดียว
- **`skillFunc` รับ lambda ที่ประกาศ `shared_ptr<AllyBuffAction> act` แบบ by-value** (200) ขณะที่ทุกไฟล์อื่นใช้ `&` — ยังทำงานได้ แต่คัดลอก shared_ptr ทุกครั้งที่เรียก
- **A2 ถูกคำนวณใหม่เฉพาะตอน `BE` เปลี่ยนผ่าน `buffSingle` แบบ `AType::NONE`** — ถ้ามีโค้ดไหนเขียน `statsType[Stats::BE]` ตรง ๆ (เช่น `resetList` ของ E6 ที่บรรทัด 79) `statsAdjust` จะไม่ถูกยิง · กรณี E6 ไม่มีปัญหาเพราะ `resetList` รันก่อน `whenOnFieldList` แต่ถ้ามี trace/LC ตัวไหนบวก BE ทีหลังแบบเขียนตรง ๆ ค่า Outgoing Healing จะไม่ตามไปด้วย
