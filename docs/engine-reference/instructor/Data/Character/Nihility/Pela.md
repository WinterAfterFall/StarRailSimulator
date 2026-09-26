# `src/Defination/Data/Character/Nihility/Pela.h`

kit อ้างอิง: `docs/kit-reference/Character/Nihility/pela.md` · **ไฟล์นี้ยัง implement ไม่ครบ kit** — ดูหัวข้อ "ส่วนที่ยังไม่มีในโค้ด" ก่อนใช้เป็นตัวอย่าง

โครงต่างจาก `Tingyun.h` ตรงที่แยก `Basic_Atk` ออกเป็นฟังก์ชันระดับ namespace (forward-declare บรรทัด 4-5) แทนที่จะเป็น lambda ใน `Setup` — รับ `CharUnit *ptr` เข้ามา ใช้ได้เมื่อ action นั้นไม่ต้อง capture state อื่นของ `Setup`

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(105, 110, 110, E, ElementType::Ice, Path::Nihility, "Pela", UnitType::Standard)` | 8 |
| Base HP/ATK/DEF | `SetAllyBaseStats(1087, 660, 509)` | 9 |
| build ที่ใช้จำลอง | `pushSubstats` ×3 · `setTotalSubstats` · `setSpeedRequire(160)` · `setRelicMainStats` | 12-18 |
| **ความแม่นของ debuff** | `ptr->setApplyBaseChance(100)` — ไม่มีใน Tingyun เพราะ Tingyun ไม่ลง debuff | 17 |
| **Basic ATK** — Frost Shot | `Pela::Basic_Atk(ptr)` — `genSkillPoint(+1)` + `Increase_energy(20)` + `addDamageIns` 2 ก้อน (55%/5 ×2) | 111-126 |
| **Skill** — Frostbite | **ไม่มี** | — |
| **Ultimate** — Zone Suppression | `Ultimate_List` + `AllyAttackAction(AType::Ult, ..., TraceType::Aoe, ...)` · debuff ลงใน callback ก่อน `Attack(act)` | 36-50 |
| Exposed (DEF −40%) | `debuffAllEnemyApply(ptr, {{Stats::DEF_SHRED, AType::None, 42}}, "Zone_Suppression", 2)` | 40 |
| **Talent** — Data Collecting (energy เมื่อศัตรูติด debuff) | `AfterAttackActionList` → วน `act->targetList` เจอ `Total_debuff != 0` ตัวแรกแล้ว `break` (1 ครั้ง/การโจมตี) | 89-96 |
| **Technique** — Preemptive Strike | `Start_game_List` + `if (ptr->Technique == 1)` → DEF shred 20% + energy 20 | 63-68 |
| **A4** — EHR ทีม +10% ขณะอยู่ในสนาม | `WhenOnField_List` → `buffAllAlly({{Stats::EHR, ..., 10}})` | 70-72 |
| **Minor traces** | `Reset_List` → `Stats_each_element` / `Stats_type` | 52-64 |
| **A2** — Bash (+20% DMG ใส่ศัตรูที่ติด debuff) | `Reset_List` → `Stats_type[Stats::DMG][AType::None] += 20` — ใส่ตรง ๆ ไม่ผูกเงื่อนไข | 60 |
| **E6** — additional DMG ใส่ศัตรูที่ติด debuff | `AfterAttackActionList` ก้อนเดียวกับ talent → `AllyAttackAction(AType::Addtional, ...)` | 98-105 |
| AI: เทิร์นนี้กดอะไร | `ptr->Turn_func` → เรียก `Basic_Atk` **เสมอ** | 25-27 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → มีศัตรูตัวใดยังไม่ติด `Zone_Suppression` = กด | 29-34 |
| หมดอายุ debuff → ถอน stat | `After_turn_List` + `debuffEnd[...] == turnCnt` → ลบค่าออกจาก `Stats_type` และ `--Total_debuff` เอง | 74-87 |

## รากฐานที่เพิ่มจาก Tingyun

**1. debuff ฝั่งศัตรูใช้คนละชุดกับบัฟฝั่งเพื่อน**
บัฟ ally = `buffSingle` / `Buff_check` / `isBuffEnd` · debuff ศัตรู = `debuffAllEnemyApply(ผู้ลง, {{stat, AType, value}}, ชื่อ, เทิร์น)` เขียนลง `enemyUnit[i]->debuffCheck` / `debuffEnd` / `Stats_type` และมีตัวนับ `Total_debuff` แยก — ตัวถอนที่ควรใช้คือ `isDebuffEnd(enemy, ชื่อ)` (`Function/Combat/Debuff_Stats.h:54`) คู่กับ `debuffSingle(enemy, {{stat, ..., -value}})` — แบบที่ `Black Swan.h:117-125` ทำ · **แต่ `Pela.h` ไม่ได้ใช้** กลับไปเทียบ `debuffEnd[ชื่อ]` กับ turn counter เองแล้วถอนทั้ง 3 อย่าง (stat, `debuffCheck`, `Total_debuff`) ด้วยมือ (74-87) — เป็นโค้ดเก่าที่ควรรีแฟกเตอร์ ไม่ใช่รูปแบบที่ควรลอก

**2. `AfterAttackActionList` = "หลังการโจมตีจบ" ใช้ทำ energy gain และ additional DMG ตามเงื่อนไขของเป้าหมาย**
ต่างจาก `When_attack_List` ของ Tingyun ที่ยิง *ระหว่าง* การโจมตี · ต้อง guard ผู้โจมตีเองเสมอ (`act->Attacker->Atv_stats->Name != "Pela"` → return, บรรทัด 90) เพราะ list เป็นของกลางทั้งเกม

**3. additional DMG ที่ยิงหลายเป้า = หนึ่ง action หลาย `addDamageIns` โดยระบุเป้าต่อก้อน**
`addDmg->addDamageIns(DmgSrc(...), e)` — พารามิเตอร์ตัวที่ 2 คือเป้าหมายเฉพาะก้อนนั้น (บรรทัด 102) ต่างจากแบบไม่ระบุเป้าที่ใช้ `TraceType` ตัดสิน

**4. `addDamageIns`: จำนวน argument = การกระจายเป้า / จำนวนครั้งที่เรียก = จำนวนจังหวะ**
(`Class/ActionData/AllyAttackAction.h:217-270`) 1 arg = เป้าเดียว · 2 args = main + adjacent (blast) · 3 args = main + adjacent + other (AoE) — engine วน `Total_enemy` แล้วแจกตาม `Target_type` ให้เอง ดังนั้น Ult ของ Pela ที่ใส่ 3 ก้อนในการเรียก **ครั้งเดียว** (43-47) คือ AoE 108% ทุกตัว ไม่ใช่ 3 จังหวะ — ต่างจาก Basic ATK ที่ **เรียก 2 ครั้ง** (119-124) = ตี 2 จังหวะ จังหวะละ 55%

**5. `WhenOnField_List` = aura ที่มีผลตลอดขณะตัวละครอยู่ในทีม** ใช้กับ trace แบบ A4 ที่ไม่ผูกกับ action

## ส่วนที่ยังไม่มีในโค้ด (เทียบ kit)

- **Skill — Frostbite ทั้งอัน — TODO ไม่ใช่การข้ามโดยเจตนา** (user ยืนยัน 2026-09-22) ไม่มี `AType::SKILL` ในไฟล์เลย และ `Turn_func` เรียก `Basic_Atk` ทุกเทิร์น → Pela ในซิมนี้**สร้าง skill point ทุกเทิร์นและไม่เคยใช้** · ผลพวงคือของที่ผูกกับ Skill หายตามทั้งหมด: **A6** (Wipe Out, +20% DMG ครั้งถัดไป), **E2** (SPD +10%), **E4** (Ice RES −12%) รวมถึงกลไกลบ buff
  > เหตุผลที่ยังไม่ทำ: ในการเล่นจริง Pela จะกด Skill ก็ต่อเมื่ออยู่ทีมน้ำแข็ง แต่ยังไม่เคยมีเคสที่ต้องคำนวณทีมน้ำแข็งในซิมนี้เลย → **ถ้าวันไหนต้องรันทีมน้ำแข็ง ต้องทำ Skill ก่อนเป็นอันดับแรก** ไม่งั้นผลที่ได้จะต่ำกว่าจริงมาก
- **E1** (ศัตรูตาย → energy 5) ไม่มี — engine ยังไม่ยิงเหตุการณ์ศัตรูตาย และยังไม่ได้ตัดสินใจว่าจะ trigger ตรงไหน ดู `README.md` หัวข้อ "`Enemy_Death_List` — ยังไม่มีทางเข้า"

## แก้เมื่อ 2026-09-22 (user สั่ง)

- **A2 — Bash** เดิมไม่มีในโค้ดเลย · เพิ่มเป็น `Stats_type[Stats::DMG][AType::None] += 20` ใน `Reset_List` (บรรทัด 60) **แบบไม่ผูกเงื่อนไข "ศัตรูต้องติด debuff"**
  > เหตุผล (user ตัดสินใจ): Pela ไม่ใช่ตัวดาเมจ และในทางปฏิบัติศัตรูติด debuff อยู่แล้วแทบตลอดเวลา — ต้นทุนของการเขียนเงื่อนไขไม่คุ้มกับความแม่นที่ได้เพิ่ม · เป็นแนวเดียวกับ A6 ของ `Black Swan.h` ที่ใส่ค่า cap ตรง ๆ แทนการคำนวณจาก EHR จริง

## ตัวเลขที่ไม่ตรง kit (ปรับแล้ว ไม่ใช่บั๊ก)

kit เป็นเลข Lv.6/Lv.10 แต่โค้ดใช้เลขที่ level สูงกว่า เหมือน `Tingyun.h`
| | kit | โค้ด |
|---|---|---|
| Basic ATK | 100% | 55+55 = 110% (toughness 5+5 = 10) |
| Exposed DEF shred | 40% | 42 |
| Talent energy | +10 | +11 (บรรทัด 94) |

## จุดที่ควรระวัง

- **การถอน debuff ใช้ turn counter คนละตัวใน 2 บล็อกที่อยู่ติดกัน** — `Zone_Suppression` เทียบกับ `enemyUnit[turn->num]->Atv_stats->turnCnt` (บรรทัด 76) ส่วน `Pela_Technique` เทียบกับ `turn->turnCnt` (บรรทัด 81)
- `Basic_Atk` เพิ่ม energy ผ่าน `charUnit[ptr->Atv_stats->num].get()` แทนที่จะใช้ `ptr` ตรง ๆ (บรรทัด 116)
