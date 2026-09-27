# `src/Defination/Data/Character/Nihility/Black Swan.h`

kit อ้างอิง: `docs/kit-reference/Character/Nihility/black-swan.md` · **ไฟล์อ้างอิงหลักของระบบ DoT** — ใครจะทำตัวละคร DoT ให้เริ่มอ่านที่นี่ (`Black SwanV1.h` เป็นเวอร์ชันเก่า ข้าม)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(102, 120, 120, E, ElementType::WIND, Path::NIHILITY, "Black Swan", UnitType::STANDARD)` | 9 |
| Base HP/ATK/DEF | `setAllyBaseStats(1087, 660, 485)` | 10 |
| build — **EHR เป็น stat หลัก** | `setEhrRequire(120)` + main stat ช่องแรกเป็น `Stats::EHR` (ไม่ใช่ CR แบบ DPS ปกติ) | 15-16 |
| **Basic ATK** | lambda `BA` — `genSkillPoint(+1)` + energy 20 + `addDamageInsByDebuff(..., "BS DefShred")` | 30-42 |
| **Skill** — Blast + DEF shred 20.8% | lambda `skill` — `addDamageIns(90/20, 90/10)` (2 args = blast) + `debuffSingleApply` วน `targetList` | 44-60 |
| **Ultimate** — Epiphany + AoE | `ultimateList` → `addDamageIns` 3 args (AoE 120%) · `debuffAllEnemyApply("Epiphany", 2)` · ยัด Arcana เพิ่มครึ่งหนึ่งของ stack ปัจจุบัน + ตั้ง `Arcana Ignore` | 77-98 |
| **Talent** — Arcana tick ต้นเทิร์น | `dotList.push_back(TriggerDotFunc(PRIORITY_LAST, ...))` | 158-187 |
| Arcana multiplier 240% + 12%/stack | `DmgSrc(DmgSrcType::ATK, 240 + getStack("Arcana")*12)` | 163 |
| Arcana ลาม adjacent 180% ตอน tick ต้นเทิร์น | `act->traceType = TraceType::BLAST` + `addDamageHit(..., target->nextToLeft/nextToRight)` | 165-173 |
| Arcana เพิกเฉย DEF 20% | `buffSingle(ptr, DEF_SHRED +20)` → `attack(act)` → `buffSingle(ptr, DEF_SHRED -20)` | 176-178 |
| cap Arcana 50 (E6 80) | ตัวแปร `maxArcana` + `setStack("Arcana", min(maxArcana, ...))` **หลัง** ยิงดาเมจ | 27-28, 180 |
| Arcana หาร 2 หลัง tick | `arcanaStacksAfterTick()` เฉพาะตอน `PhaseStatus::DOT_BEFORE_TURN` และไม่มี `Arcana Ignore` | 4-6, 182-185 |
| **A2** — BS โจมตี → Arcana 5 stack | `whenAttackList` สาขา `act->isSameName(ptr)` | 128-133 |
| **A4** — เติม DEF shred หลัง BA/Ult | `whenAttackList` สาขาเดียวกัน → `debuffEnemyTargetsApply` | 130 |
| **A6** — DMG ทีมจาก EHR (cap 72%) | `whenOnFieldList` → `buffAllAlly({{Stats::DMG, ..., 72}})` — **ใส่ค่า cap ตรง ๆ ไม่ได้คำนวณจาก EHR จริง** | 141-142 |
| **Minor traces** | `resetList` | 100-104 |
| **Technique** | `startGameList` → `if (ptr->technique)` Arcana 2 stack | 151-152 |
| **E1** — ลด RES 4 ธาตุ | `whenOnFieldList` → `debuffAllEnemyApply` หลาย `Stats::RESPEN` ในก้อนเดียว (ไม่ใส่ duration = ถาวร) | 143-148 |
| **E2** — เข้าฉาก Arcana 30 | `startGameList` → `if (ptr->eidolon >= 2)` | 155 |
| **E4** — Epiphany vulnerability 25→45 | `if (ptr->eidolon >= 4)` ที่จุดลง Epiphany และจุดถอน | 82-83, 122-123 |
| **E6** — เพื่อนโจมตี → Arcana | `whenAttackList` สาขา `else if (ptr->eidolon >= 6)` | 134-138 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — มีศัตรู (สูงสุด 3 ตัว) ที่ยังไม่ติด `BS DEF_SHRED` → Skill, ไม่งั้น BA | 63-71 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `return true` (กดทันทีที่พอ) | 73-75 |
| หมดอายุ debuff → ถอน stat | `afterTurnList` + `turn->canCastToEnemy()` + `isDebuffEnd` | 113-126 |

## รากฐานระบบ DoT (ของใหม่จากไฟล์นี้)

**1. DoT เป็น stack บนศัตรู + ชุด `DotType` ที่ถือพร้อมกัน**
`dotSingleStack(ผู้ลง, เป้า, {DotType::WIND_SHEAR, BLEED, BURN, SHOCK}, จำนวน stack, ratio, ชื่อ)` · Arcana ของ kit ที่ "ถือว่าติด 4 DoT พร้อมกัน" แปลตรงตัวเป็น list 4 ตัวนี้ · เวอร์ชัน AoE คือ `dotAllEnemyStack` · อ่าน/เขียน stack ด้วย `target->getStack(ชื่อ)` / `setStack(ชื่อ, ค่า)`

**2. ดาเมจ DoT ไม่ได้เกิดเองจากการลง stack — ต้องลงทะเบียน `dotList` แยก**
`dotList.push_back(TriggerDotFunc(PRIORITY_LAST, [..](Enemy* target, double dotRatio, DotType dotType){...}))` คือที่ที่ **คำนวณดาเมจ DoT จริง** · ข้างในสร้าง `AllyAttackAction` ตามปกติแล้ว `act->multiplyDmg(dotRatio)` · `phaseStatus == PhaseStatus::DOT_BEFORE_TURN` = tick ต้นเทิร์นศัตรู (ต่างจาก tick ที่เกิดจากเหตุอื่น) ใช้แยกพฤติกรรม

**3. `Arcana Ignore` = flag แบบ debuff ที่ใช้เป็น "ตั๋วใช้ครั้งเดียว"**
`setDebuff(ชื่อ, 1)` ตอน ult → tick ถัดไปเห็นแล้ว **ไม่หาร stack และล้าง flag ทิ้งเอง** (`setDebuff(ชื่อ, 0)`) · เป็นวิธีข้ามกฎชั่วคราวโดยไม่ต้องเพิ่มฟิลด์ใน class

**4. ผลแบบ "เพิกเฉย DEF เฉพาะดาเมจก้อนนี้" ทำโดยบัฟตัวเองก่อนยิงแล้วถอนทันที**
`buffSingle(ptr, DEF_SHRED +20)` → `attack(act)` → `buffSingle(ptr, DEF_SHRED -20)` (176-178) · ใช้ได้เพราะ `attack()` คำนวณจบในบรรทัดเดียว ไม่ใช่ deferred

**5. `addDamageInsByDebuff(dmgsrc, ชื่อ debuff)` = ตัวเลือกเป้า ไม่ใช่เงื่อนไขดาเมจ**
(`AllyAttackAction.h:272`) เลือกศัตรู **ตัวแรกที่ยังไม่ติด** debuff นั้น ถ้าติดครบทุกตัวค่อย fallback เป็นเป้าปกติ — BA ของ BS จึงเล็งตัวที่ DEF shred หลุดโดยอัตโนมัติ

**6. `turn->canCastToEnemy()` = สำนวนมาตรฐานของ `afterTurnList` ฝั่ง debuff**
คืน `Enemy*` ถ้าเทิร์นที่เพิ่งจบเป็นของศัตรู ไม่งั้น `nullptr` — สะอาดกว่าการเช็ค `turn->side == Side::ENEMY` แล้ว index `enemyUnit[turn->num]` เองแบบ `Pela.h`

## ความน่าจะเป็นถูกตัดทิ้งทั้งระบบ

kit ของ BS เต็มไปด้วย base chance (65% ติด Arcana, 50% double stack ตอน Epiphany, technique แบบ cascade 150%→50%→…) แต่**โค้ดลง stack แบบการันตีทุกจุด** ไม่มีการสุ่มเลย ชดเชยด้วยการบังคับ build ให้ EHR ถึงเกณฑ์ (`setEhrRequire(120)`) แทน · เวลาเทียบตัวเลขกับ kit ต้องเข้าใจว่านี่คือ **ค่าคาดหวังแบบ best case ไม่ใช่ค่าเฉลี่ย** — และของที่ kit เขียนว่า "50% เพิ่ม stack อีก 1" ถูกแปลเป็น "เพิ่มครึ่งหนึ่งของ stack ปัจจุบัน" ตอน ult (บรรทัด 85) แทน

## กฎการลด Arcana หลัง tick

หลัง Arcana สร้างความเสียหายตอน `DOT_BEFORE_TURN` ถ้าไม่มี `Arcana Ignore` จะลด stack ลงครึ่งหนึ่งแบบหารจำนวนเต็ม แต่คงขั้นต่ำ 1 stack (user ยืนยัน 2026-09-21) ผ่าน `arcanaStacksAfterTick()` เช่น 1 → 1, 2 → 1, 4 → 2 จึงไม่ทำให้ Arcana กลายเป็นสถานะ 0 stack โดยการลดตามรอบนี้; ถ้ามี `Arcana Ignore` จะไม่ลด stack และล้าง flag ดังกล่าวแทน

`Black SwanV1.h` ที่ยังอยู่ใน repo ใช้หลักคงขั้นต่ำ 1 stack แบบตรง ๆ เช่นกัน แต่มีวิธีลด stack ต่างจาก implementation ปัจจุบัน

## แก้เมื่อ 2026-09-23 (user สั่ง)

- **Skill และ Ult ถูกสร้างด้วย `AType::BA`** (บรรทัด 47, 79) ทั้งที่ชื่อ action เป็น "BS Skill" / "BS Ult" → บัฟหรือ trace ที่ผูกกับ `AType::SKILL` / `AType::ULT` ไม่เข้ากับ 2 ท่านี้ และเพราะ `genSkillPoint(-1)` ไม่ได้ผูกกับ AType จึงไม่เห็นอาการทันที · แก้เป็น `AType::SKILL` / `AType::ULT` (อาการเดียวกับที่แก้ใน `Luka.md`)
  > แก้ `TraceType` ให้ตรงกับก้อนดาเมจไปด้วย: Skill `SINGLE` → `BLAST` (มี 2 args) และ Ult `SINGLE` → `AOE` (มี 3 args) · **ไม่กระทบการเลือกเป้าหรือตัวเลข** เพราะ `targetType` ของศัตรูถูกตั้งครั้งเดียวตอนสร้าง (`Function/Setup/SetEnemy.h:11`) และ `traceType` ถูกใช้แค่ส่งต่อให้ action SPB (`Function/Combat/Combat.h:238`) — เป็นการแก้ให้อ่านแล้วไม่หลงเท่านั้น

## จุดที่ควรระวัง

- **A6 ใส่ค่า cap 72% ตรง ๆ** ไม่ได้คำนวณจาก EHR จริงของ BS → ถ้า build EHR ต่ำกว่า 120% ตัวเลขนี้จะสูงเกินจริง
- **E1 ลง `debuffAllEnemyApply` โดยไม่ใส่ duration** (143-148) ต่างจาก debuff อื่นในไฟล์ที่ใส่เทิร์นเสมอ — ตั้งใจให้ถาวรขณะอยู่ในสนาม แต่ก็ไม่มีโค้ดถอนเมื่อ BS ออกจากสนาม
- **`turnFunc` วนแค่ `i <= 3`** (บรรทัด 64) ขณะที่ `dotList` และ `debuffAllEnemyApply` วนตาม `totalEnemy` จริง
