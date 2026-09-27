# `src/Defination/Data/Character/Erudition/Serval.h`

kit อ้างอิง: `docs/kit-reference/Character/Erudition/serval.md` · **ไฟล์นี้มีคอมเมนต์ `//temp` (บรรทัด 11) และยังไม่เสร็จ — อย่าใช้เป็นแม่แบบ** ใช้ `Kafka.md` / `Black Swan.md` แทน ที่นี่ให้อ่านเพื่อรู้ว่ามีอะไรค้างอยู่

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(104, 100, 100, E, ElementType::LIGHTNING, Path::ERUDITION, "Serval", UnitType::STANDARD)` | 13 |
| Base HP/ATK/DEF | `setAllyBaseStats(917, 653, 375)` | 15 |
| build | substats CD/CR/ATK% + `setSpeedRequire(160)` + `setApplyBaseChance(100)` + main stat ช่องแรก `Stats::EHR` | 17-23 |
| **Basic ATK** | `Serval::basicAtk(ptr)` — `addDamageIns(110/10, chooseEnemyTarget(ptr))` | 132-149 |
| **Skill** — Blast + Shock | `Serval::skill(ptr)` — `addDamageIns(154/20, 66/10)` + วน `enemyList` `debuffApply` → `changeShock(1)` → `extendDebuffAll("Serval_Shock", 2)` | 150-170 |
| **Ultimate** — AoE 194% | `ultimateList` (**`PRIORITY_ACTTACK`** ไม่ใช่ `PRIORITY_BUFF` แบบตัวอื่น) + `addDamageIns` 3 args | 51-72 |
| **Talent** — Additional DMG ใส่ศัตรู Shocked | `whenAttackList` → มีศัตรูติด Shock สักตัว → `AType::ADDTIONAL` / `TraceType::AOE` 79% ใส่ทุกตัว ยิงครั้งเดียว | 104-127 |
| Shock DoT 114% | `dotList` + guard `getDebuff("Serval_Shock")` และ `dotType` (General/Shock) | 97-105 |
| **A4** — energy 15 ต้นเกม | `startGameList` → `increaseEnergy(ptr, 15)` | 90-91 |
| **A6** — ฆ่าศัตรู → ATK +20% 2 เทิร์น | `enemyDeathList` → `buffSingle(..., "Serval_A6", 2)` — **list นี้ไม่เคยถูกยิง** | 122-124 |
| **Minor traces** | `resetList` | 41-49 |
| **E1** — BA ลามข้างเคียง 60% | `addDamageHit(DmgSrc(..., 60, 0), enemyUnit[...])` ใน `basicAtk` | 141-147 |
| **E2** — energy 4 ต่อ Additional DMG | `if (ptr->eidolon >= 2) increaseEnergy(ptr, 4)` — 1 ครั้งต่อการ trigger talent | 124-126 |
| **E4** — Ult ติด Shock ด้วย | `if (ptr->eidolon >= 4)` ใน callback ของ Ult (ก้อนเดียวกับ Skill) | 56-63 |
| **E6** — DMG +30% ใส่ศัตรู Shocked | `startGameList` → `statsType[Stats::DMG][AType::NONE] += 30` | 92-94 |
| **A2 / Technique** | **ไม่มี** | — |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — `turnCnt % 3 != 1` → BA, ไม่งั้น Skill (กด Skill 1 ครั้งทุก 3 เทิร์น) | 30-36 |
| หมด Shock → ลดตัวนับ | `afterTurnList` → `dynamic_cast<Enemy*>(turn->charptr)` + `isDebuffEnd` → `changeShock(-1)` | 74-88 |

## รากฐานที่เพิ่ม

**1. Shock ที่หลายตัวละครลงร่วมกันมีตัวนับกลางบนศัตรู: `changeShock(±1)`**
ต่างจาก Shock เฉพาะตัวของ Kafka ที่จัดการผ่าน `dotSingleApply` / `dotRemove` — ของ Serval ใช้คู่ `debuffApply(ผู้ลง, เป้า, ชื่อ)` (คืน `bool` ว่าลงติดไหม) แล้วค่อย `changeShock(1)` เอง และตอนหมดอายุต้อง `changeShock(-1)` คืน · **ตัวนับกับ debuff เป็นคนละอย่าง ต้องขยับให้ครบคู่ทุกทาง** ไม่งั้นสถานะ Shock ของศัตรูค้าง

**2. `extendDebuffAll(ชื่อ, เทิร์น)` = ต่ออายุ debuff ให้ศัตรูทุกตัวในคราวเดียว**
ใช้แทนการวนลงใหม่ทีละตัว — ตรงกับ kit ที่ Ult "ยืด Shock +2 เทิร์น" กับศัตรูที่ติดอยู่แล้ว

**3. `addDamageHit(DmgSrc, เป้า)` = เพิ่มก้อนดาเมจใส่เป้าที่ระบุเข้า action ที่มีอยู่**
ต่างจาก `addDamageIns` ที่ engine แจกเป้าให้ตาม `targetType` — ใช้ตอนต้องยิงเป้าที่เลือกเอง เช่น E1 ที่ลามไปตัวข้างเคียง (และ Arcana ของ BS ที่ลาม `nextToLeft` / `nextToRight`)

**4. `chooseEnemyTarget(ptr)` = เป้าหมายที่ AI เลือกอยู่ตอนนี้** ส่งเข้า `addDamageIns` เป็น arg ที่ 2 เมื่ออยากยิงเป้านั้นตรง ๆ

## ส่วนที่ยังไม่เสร็จ / ต้องแก้

- ~~Talent ยิงดาเมจซ้ำซ้อน~~ **แก้แล้ว 2026-09-23 (user สั่ง)** — เดิม `data2` ถูกสร้างนอกลูป แต่ในลูปทั้ง `addDamageIns` **และ** `attack(data2)` ทุกรอบ → ศัตรู Shocked ตัวที่ 2 ยิง action ที่มี 2 ก้อนสะสม ตัวที่ 3 ยิง 3 ก้อน (ดาเมจทบต้น)
  > รูปแบบใหม่ตามที่ user สั่ง: **เช็คว่ามีศัตรูติด Shock สักตัวไหม ถ้ามี ยิง additional DMG ใส่ศัตรูทุกตัว ครั้งเดียว** (`TraceType::AOE` + `addDamageIns` 3 args) — ต่างจาก kit ที่ระบุ "ใส่ศัตรู Shocked ทุกตัว" แต่ในทางปฏิบัติ Skill ของ Serval ลง Shock ทั้งสนามอยู่แล้ว
  > **E2 เปลี่ยนจาก energy 4 ต่อศัตรู Shocked เป็น 4 ต่อการ trigger 1 ครั้ง** ซึ่งตรงกับ kit ("ทุกครั้งที่ Talent trigger Additional DMG") มากกว่าของเดิม
- ~~`turnFunc` ตายตั้งแต่บรรทัดแรก~~ **แก้แล้ว 2026-09-22 (user สั่ง)** — เดิมมี `basicAtk(ptr); return;` คาหัว lambda ทำให้ตรรกะ "3 เทิร์นกด Skill 1 ครั้ง" ข้างล่างเป็น dead code และ Serval กด Basic ATK ตลอดเกม ไม่เคยลง Shock จาก Skill · ลบ 2 บรรทัดนั้นออกแล้ว ตรรกะ `turnCnt % 3` ทำงานจริง → **Shock / Talent / DoT / E2 / E6 เริ่มทำงานตามที่ออกแบบไว้ ตัวเลขผลลัพธ์ของ Serval จะเปลี่ยนไปมาก**
- **A6 แขวนอยู่บน `enemyDeathList` ที่ไม่เคยทำงาน** — โค้ดเขียนครบแล้ว (119-121) แต่ยังไม่ได้ตัดสินใจว่า engine ควรยิงเหตุการณ์ศัตรูตายตรงไหน ดู `README.md` หัวข้อ "`enemyDeathList` — ยังไม่มีทางเข้า"
- **E6 ไม่ผูกเงื่อนไข Shocked — จงใจ** (user ยืนยัน 2026-09-23) kit บอก "+30% เฉพาะศัตรูที่ Shocked" แต่โค้ดบวก `Stats::DMG` แบบไม่มีเงื่อนไขตอนต้นเกม · เลือกทางนี้เพราะเขียนเงื่อนไขไม่คุ้ม — แนวเดียวกับ A2 ของ `Pela.md` และ A6 ของ `Black Swan.md`
- **A2 (base chance Shock +20%) และ Technique ทั้งอัน** ยังไม่มี · A2 หายไปได้เพราะระบบความน่าจะเป็นถูกตัดทิ้งอยู่แล้ว (ดู `Black Swan.md`) แต่ Technique เป็นดาเมจ + Shock ต้นเกมที่หายจริง

## จุดที่ควรระวัง

- **ถอน debuff ด้วย `dynamic_cast<Enemy*>(turn->charptr)`** (81) ทั้งที่มี `turn->canCastToEnemy()` ให้ใช้อยู่แล้ว (`Black Swan.h:114`, `Kafka.h:159`) — โค้ดเก่า ควรรีแฟกเตอร์ให้ตรงกัน
- **Ult ใช้ `PRIORITY_ACTTACK`** ขณะที่ตัวอื่นใช้ `PRIORITY_BUFF` — ลำดับการยิง ult เทียบกับ trigger อื่นจึงต่างจากตัวอื่นในเกม
- **main stat ช่องแรกเป็น `Stats::EHR` แต่ substats เป็น CD/CR/ATK%** (17-23) ขัดกันในตัวเอง และ Serval ในโค้ดแทบไม่ได้ใช้ EHR เพราะ `setApplyBaseChance(100)` การันตีลง debuff อยู่แล้ว
