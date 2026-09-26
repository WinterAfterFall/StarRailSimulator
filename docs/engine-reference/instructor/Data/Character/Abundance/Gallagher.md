# `src/Defination/Data/Character/Abundance/Gallagher.h`

kit อ้างอิง: `docs/kit-reference/Character/Abundance/gallagher.md` · **ไฟล์อ้างอิงของ "stat ที่คำนวณจาก stat อื่นแบบ live"** (A2: Outgoing Healing = 50% ของ Break Effect) — กลไกนี้ไม่มีในตัวละครอื่นที่สำรวจมา · คู่กับ `Luocha.md` สำหรับระบบฮีลพื้นฐาน

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(98, 110, 110, E, ElementType::Fire, Path::Abundance, "Gallagher", UnitType::Standard)` | 14 |
| Base HP/ATK/DEF | `SetAllyBaseStats(1305, 529, 441)` | 15 |
| build — **substat เป็น `BE`** (Break Effect) | `pushSubstats(Stats::BE)` + main stat หมวก `HEALING_OUT` + `setSpeedRequire(150)` | 18-21 |
| **Basic ATK** — Corkage Fee | `Basic_Atk(ptr)` — `addDamageIns` 2 ครั้ง (55/5) | 163-175 |
| **Enhanced BA** — Nectar Blitz | `Enchance_Basic_Atk(ptr)` — 3 จังหวะ (62.5/7.5, 37.5/4.5, 150/18) + ลด ATK เป้า | 176-194 |
| Nectar Blitz ลด ATK เป้า 16% | `target->atkPercent -= 16` + `debuffApply` + `extendDebuff(..., "Nectar_Blitz", 2)` | 182-186 |
| **Skill** — Special Brew (ฮีลล้วน) | `Skill_func(ptr)` — **`AllyBuffAction`** ไม่ใช่ `AllyAttackAction` เพราะไม่มีดาเมจ | 195-206 |
| **Ultimate** — Champagne Etiquette | `Ultimate_List` (`PRIORITY_DEBUFF`) — AoE 165%×3 args | 44-67 |
| Ult → ติด Besotted | `debuffAllEnemyApply(Charptr, {{Stats::VUL, AType::Break, 13.2}}, "Besotted")` แล้ว `extendDebuffAll` แยก | 50-55 |
| Ult → BA ครั้งถัดไปเป็น Nectar Blitz | `ptr->buffCheck["Gallagher_enchance_basic_atk"] = 1` | 49 |
| **A4** — หลัง Ult advance 100% | `Action_forward(ptr->Atv_stats.get(), 100)` ใน callback ของ Ult | 48 |
| **Talent** — Besotted ให้ Break DMG taken +12% | อยู่ในตัว debuff เอง: `Stats::VUL` ที่ `AType::Break` | 50 |
| **Talent** — ตี Besotted → ผู้โจมตีถูกฮีล | `When_attack_List` (`PRIORITY_HEAL`) → นับเป้าที่ติด Besotted แล้ว `RestoreHP(act->Attacker, ...)` | 135-143 |
| **A6** — Nectar Blitz → ฮีลทั้งทีม | สาขา `isSameAction("Gallagher", AType::BA) && buffCheck[...] == 1` → `RestoreHP(HealSrc)` **overload 1 arg = ฮีลทุกคน** | 125-134 |
| **A2** — Outgoing Healing = 50% ของ Break Effect (cap 75) | `WhenOnField_List` ตั้งค่าครั้งแรก + `Stats_Adjust_List` คำนวณใหม่ทุกครั้งที่ `BE` เปลี่ยน | 101-105, 145-152 |
| **Technique** | อยู่ใน `WhenOnField_List` (**ไม่ใช่ `Start_game_List`** แบบตัวอื่น) | 106-120 |
| **Minor traces** | `Reset_List` | 69-81 |
| **E1** — ต้นเกม energy 20 | `Start_game_List` → `if (ptr->Eidolon >= 1) Increase_energy(ptr, 20)` (ส่วน Effect RES +50% **ไม่มี**) | 95-99 |
| **E4** — Besotted จาก Ult ยืดอีก 1 เทิร์น | `extendDebuffAll("Besotted", 3)` แทน 2 | 51-55 |
| **E6** — Break Effect / Break Efficiency +20% | `Reset_List` → `Stats::BREAK_EFF += 20` และ `Stats::BE += 20` | 77-80 |
| **E2** | **ไม่มี** | — |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — `turnCnt % 8 == 1` → Skill · ไม่งั้นดู flag ว่าเป็น EBA หรือ BA | 29-39 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `phaseStatus != BeforeTurn && atv != 0` | 40-42 |
| หมด Besotted / Nectar_Blitz → ถอน | `After_turn_List` + `canCastToEnemy()` + `isDebuffEnd` | 83-92 |

## รากฐานที่เพิ่ม

**1. `Stats_Adjust_List` — stat ที่ต้องคำนวณใหม่เมื่อ stat ต้นทางเปลี่ยน**
`Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [](AllyUnit* Target, Stats StatsType){...}))` · ถูกยิงจาก `StatsAdjust(ptr, statsType)` ซึ่ง `buffSingle` เรียกให้เองทุกครั้งที่ลงบัฟแบบ `AType::None` (`Function/Combat/Buff_Stats.h:91,102`) · handler ต้อง guard 2 ชั้นเสมอ: **stat ที่เปลี่ยนใช่ตัวที่เราสนใจไหม** และ **เจ้าของ stat ใช่เราไหม** (146) เพราะ list เป็นของกลาง · `allEventAdjustStats` ตั้ง `AdjustCheck = 1` ระหว่างวน (`Function/Event/Event.h:203`) เป็นตัวกันลูปซ้อน

**2. สำนวน "เก็บค่าที่ลงไปล่าสุด" สำหรับ stat ที่คำนวณต่อเนื่อง**

```cpp
double temp = calculateBreakEffectForBuff(ptr, 50);
if (temp > 75) temp = 75;
buffSingle(ptr, {{Stats::HEALING_OUT, AType::None, temp - ptr->buffNote["Novel Concoction"]}});
ptr->buffNote["Novel Concoction"] = temp;
```

`buffSingle` บวกค่าดิบเสมอ ไม่มีการ "ตั้งค่าเป็น" → ต้องลงเฉพาะ **ส่วนต่าง** จากค่าที่เคยลงไว้ แล้วจำค่าใหม่ไว้ใน `buffNote` · **รูปแบบนี้ใช้ได้กับทุก trace ที่เป็น "stat A = สัดส่วนของ stat B"** และโค้ดต้องอยู่ 2 ที่เสมอ: ตอนเริ่ม (`WhenOnField_List`) และตอน B เปลี่ยน (`Stats_Adjust_List`)

**3. `calculateXForBuff(ptr, ratio)` = อ่านค่า stat ปัจจุบันเป็นสัดส่วน**
`calculateBreakEffectForBuff(ptr, 50)` = 50% ของ Break Effect · สังเกตว่ามันลบ `Stats_type[BE][AType::TEMP]` ออกก่อน (`CalStats.h:86`) คือ **ไม่นับส่วนที่เป็นบัฟชั่วคราว** และ clamp ไม่ให้ติดลบ · มีชุดเดียวกันสำหรับ ATK (`calculateAtkForBuff`) และ EHR (`calculateEhrForBuff`)

**4. `RestoreHP(HealSrc)` overload เดียว = ฮีลทุกคนในทีม**
(`Function/Combat/ChangeHP.h:65`) วน `allyList` ทั้งหมด — ต่างจาก `RestoreHP(target, HealSrc)` ที่ฮีลคนเดียว · A6 ของ Gallagher ใช้ความต่างนี้ตรง ๆ: Nectar Blitz → overload ฮีลทั้งทีม, BA ปกติ → overload ฮีลผู้โจมตี (125-143)

**5. `AllyBuffAction` ใช้กับ action ที่ไม่มีดาเมจเลย**
Skill ของ Gallagher เป็นการฮีลล้วน จึงไม่ใช้ `AllyAttackAction` · ประกอบด้วย `addBuffSingleTarget(chooseAllyBuff(ptr))` + `addToActionBar()` เหมือน Skill/Ult ของ Tingyun

**6. debuff ที่ลดค่าของศัตรูโดยตรงเขียนที่ฟิลด์ของศัตรู ไม่ใช่ `Stats_type`**
`target->atkPercent -= 16` (184) และคืนด้วย `focusUnit->atkPercent += 16` (90) — ใช้เมื่อผลไม่ได้เข้าสูตรดาเมจของฝ่ายเรา

**7. `act->isSameAction(ชื่อ, AType)` = ตัวกรองมาตรฐานใน `When_attack_List`**
(`Class/ActionData/AllyActionData.h:56-58`) มี 3 overload: ตาม `AType` อย่างเดียว, ตาม `AllyUnit*`, ตามชื่อ string

**8. `if(!actionBarUse) Deal_damage();`**
`actionBarUse` เป็น flag กลาง (`Setting.h:69`) ที่ `Combat.h:108-125` ตั้งระหว่างประมวลผล action bar อยู่ — กันการเรียก `Deal_damage()` ซ้อนตอนที่ระบบกำลังไล่คิวอยู่แล้ว · ตัวละครอื่นเรียก `Deal_damage()` ตรง ๆ

## ตัวเลขที่ไม่ตรง kit (ปรับ level แล้ว ไม่ใช่บั๊ก)

| | kit (Lv.10) | โค้ด |
|---|---|---|
| Besotted — Break DMG taken | 12% | 13.2 |
| Nectar Blitz — ลด ATK | 15% | 16 |
| Skill heal | 1600 | 1768 |
| Talent heal ต่อเป้าที่ Besotted | 640 | 707 |
| Ult DMG | 150% | 165% |

## ส่วนที่ยังไม่มีในโค้ด

- **E2 — Lion’s Tail** (Skill ลบ debuff 1 อัน + Effect RES +30% 2 เทิร์น) ไม่มีทั้งอัน · ส่วนลบ debuff ไม่มีระบบ cleanse รองรับ (เหมือน A2 ของ `Luocha.md`)
- **E1 ทำแค่ครึ่งเดียว** — energy 20 มีแล้ว แต่ **Effect RES +50% ไม่มี**

## จุดที่ควรระวัง

- **Nectar Blitz ลด ATK ซ้ำซ้อนได้** — `debuffApply(act->Attacker, target, "Nectar_Blitz")` คืน `bool` ว่าลงติดใหม่หรือไม่ แต่**โค้ดไม่ได้เช็คค่าที่คืนมา** แล้ว `target->atkPercent -= 16` ทุกครั้ง (183-185) · ถ้า Nectar Blitz ลงซ้ำขณะที่ debuff เดิมยังไม่หมด (ult ถี่ → EBA ถี่) ATK ศัตรูจะถูกลบ 16 หลายรอบ แต่ `After_turn_List` คืนให้แค่ครั้งเดียว → **ค่ารั่วถาวร** · เทียบกับ `debuffSingleApply` ที่ engine เช็คให้เอง (ดู `Kafka.md` หัวข้อ "แก้เมื่อ")
- **`Turn_func` กด Skill ทุก 8 เทิร์นแบบตายตัว** (30) — kit ไม่มีกฎนี้ Gallagher ควรกด Skill เมื่อทีมต้องการฮีล · เป็นการประมาณรอบที่ไม่ได้อิงสถานะจริง ต่างจาก `The_Herta.h` ที่อ่าน `sp` / `Sp_Safety` ของเกม
- **Ult ลง Besotted โดยไม่ระบุ duration แล้วค่อย `extendDebuffAll` ทีหลัง** (50-55) — ต่างจาก Technique ที่ส่ง `2` ไปกับ `debuffAllEnemyApply` เลย (110) · ผลเหมือนกันแต่เป็นสองสำนวนในไฟล์เดียว
- **`Skill_func` รับ lambda ที่ประกาศ `shared_ptr<AllyBuffAction> act` แบบ by-value** (200) ขณะที่ทุกไฟล์อื่นใช้ `&` — ยังทำงานได้ แต่คัดลอก shared_ptr ทุกครั้งที่เรียก
- **A2 ถูกคำนวณใหม่เฉพาะตอน `BE` เปลี่ยนผ่าน `buffSingle` แบบ `AType::None`** — ถ้ามีโค้ดไหนเขียน `Stats_type[Stats::BE]` ตรง ๆ (เช่น `Reset_List` ของ E6 ที่บรรทัด 79) `StatsAdjust` จะไม่ถูกยิง · กรณี E6 ไม่มีปัญหาเพราะ `Reset_List` รันก่อน `WhenOnField_List` แต่ถ้ามี trace/LC ตัวไหนบวก BE ทีหลังแบบเขียนตรง ๆ ค่า Outgoing Healing จะไม่ตามไปด้วย
