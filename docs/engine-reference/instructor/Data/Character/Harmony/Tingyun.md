# `src/Defination/Data/Character/Harmony/Tingyun.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/tingyun.md` · ทั้งตัวละครอยู่ในฟังก์ชันเดียว `Tingyun::Setup(E, LC, Relic, Planar)` ไม่มี class ไม่มี virtual — "ความสามารถ" = lambda ที่ push เข้า event list กลางตอน setup

## ตารางหลัก: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / rarity / energy ult | `SetCharBasicStats(SPD, energy, energy, E, ElementType, Path, ชื่อ, UnitType)` | 23 |
| Base HP/ATK/DEF (Lv.80) | `ptr->SetAllyBaseStats(847, 529, 397)` | 25 |
| build ที่ใช้จำลอง (substat / main stat / SPD เป้า) | `pushSubstats` · `setTotalSubstats` · `setSpeedRequire` · `setRelicMainStats` | 27-30 |
| Light Cone / Relic / Planar | รับเป็น `function<void(CharUnit*)>` แล้วเรียกทันที `LC(ptr); Relic(ptr); Planar(ptr);` | 32-34 |
| **Basic ATK** — Dislodged | `AllyAttackAction(AType::BA, ...)` + `genSkillPoint(ptr, 1)` + `Increase_energy(ptr, 20)` + `addDamageIns(...)` + `addToActionBar()` | 55-66 |
| **Skill** — Soothing Melody | `AllyBuffAction(AType::SKILL, ...)` + `genSkillPoint(ptr, -1)` + `Increase_energy(ptr, 30)` + `buffSingle(target, ..., BUFF_BENEDICTION, 3)` | 69-87 |
| **Ultimate** — Amidst the Rejoicing Clouds | `Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, ptr, ...))` ห่อ `AllyBuffAction(AType::Ult, ...)` แล้วปิดท้าย `Deal_damage()` | 112-137 |
| **Talent** — Violet Sparknado + additional ของ Skill | `When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, ...))` สร้าง `AllyAttackAction(AType::Addtional, ...)` แล้ว `Attack(add)` | 177-195 |
| **Technique** — Gentle Breeze | `Start_game_List` + `ptr->Technique` (จำนวนครั้งที่กด technique) | 26, 168-170 |
| **A2** Nourished Joviality (SPD% 1 เทิร์น) | `buffSingle(ptr, ..., BUFF_NOURISHED, 1)` **ข้างใน lambda ของ Skill** | 82-83 |
| **A4** Knell Subdual (BA DMG +40%) | `Reset_List` → `ptr->Stats_type[Stats::DMG][AType::BA] += 40` | 145 |
| **A6** Jubilant Passage (+5 energy ต้นเทิร์น) | `Before_turn_List` + guard `turn->Name != ptr->Atv_stats->Name` | 149-152 |
| **Minor traces** (ATK/DEF/Lightning DMG) | `Reset_List` เขียนลง `Stats_type` / `Stats_each_element` ตรง ๆ | 140-146 |
| **E1 / E4 / E6** | `if (ptr->Eidolon >= n)` คาไว้ในจุดที่เกี่ยวข้อง ไม่แยกบล็อก eidolon | 120, 126, 185, 192 |
| **E2** | **ไม่มี** — ดูหัวข้อล่างสุด | — |
| AI: เทิร์นนี้กดอะไร | `ptr->Turn_func = [...]` | 94-99 |
| AI: กดอัลติเมื่อไหร่ | `ptr->addUltCondition([...] -> bool)` — `false` = ยังไม่กด | 104-109 |
| หมดอายุบัฟ → ถอน stat | `After_turn_List` + `isBuffEnd(holder, name)` → `buffSingle(holder, {{stat, ..., -value}})` | 156-165 |
| เพื่อนตายพร้อมบัฟ → ถอน stat | `AllyDeath_List` + `isBuffGoneByDeath` | 198-203 |

## รากฐานที่อ่านออกจากไฟล์นี้

**1. บัฟ = stat delta ที่ต้องถอนเอง ไม่ใช่สถานะที่ engine คำนวณให้**
`buffSingle(target, {{stat, AType, +value}}, ชื่อบัฟ, จำนวนเทิร์น)` บวกค่าเข้า stat ทันที เมื่อหมดอายุต้อง **เรียก `buffSingle` ด้วยค่าติดลบเอง** ผ่าน `After_turn_List` จึงต้องมี constant คู่เดียว (`BENEDICTION_ATK` ฯลฯ, บรรทัด 15-18) ให้ apply กับ remove อ้างค่าเดียวกัน — ทุกทางที่บัฟหายต้องถอนครบ: หมดอายุ (`isBuffEnd`), ผู้ถือตาย (`isBuffGoneByDeath`), **และย้ายเป้าหมาย**

**2. บัฟ single-target ต้องจำ "ผู้ถือจริง" แยกจาก "เป้าหมายที่อยากบัฟตอนนี้"**
`Buff_check` / `Buff_countdown` เป็น map เดียวทั้งเกม → ชื่อบัฟต้อง prefix ชื่อตัวละคร (บรรทัด 9-12) · `chooseAllyBuff(ptr)` = เป้าหมายที่ "ตั้งใจ" ณ ตอนนี้ (อ่าน `currentCharNum` สด) ส่วน `ptr->getBuffSubUnitTarget(name)` = คนที่ **ถือบัฟอยู่จริง** สองอันนี้ไม่เท่ากันเมื่อเป้าหมายเปลี่ยน → `clearStaleAllyBuffs` (40-50) ถอนของคนเก่าก่อนลงคนใหม่ ส่วนโค้ดที่ต้องหาว่า "ใครถือบัฟอยู่" (additional DMG, expiry, death) ต้องใช้ `getBuffSubUnitTarget` เสมอ ไม่ใช่ `chooseAllyBuff`

**3. Action = object ที่ประกอบแล้วโยนเข้า action bar**
สร้าง `AllyAttackAction` / `AllyBuffAction` → ใส่ payload (`addDamageIns` / `addBuffSingleTarget`) → `addToActionBar()` · callback ที่ส่งเข้า constructor คือสิ่งที่จะรันตอนถึงคิว ไม่ใช่ตอนสร้าง · `addDamageIns(DmgSrc(DmgSrcType::ATK, multiplier, toughness))` — **จำนวน argument ในการเรียกครั้งหนึ่ง = การกระจายเป้า** (1 = เป้าเดียว, 2 = main + adjacent, 3 = main + adjacent + other; `AllyAttackAction.h:217-270`) ส่วน **จำนวนครั้งที่เรียก = จำนวนจังหวะ** → BA ของ Tingyun เรียก 2 ครั้ง ครั้งละ 1 arg = ตีเป้าเดียว 2 จังหวะ 33%+77% (toughness 3+7)

**4. Additional DMG สเกลกับ ATK ของ "ผู้ถือบัฟ" ไม่ใช่เจ้าของสกิล**
จึงสร้าง action โดยส่ง `holder` (หรือ `act->Attacker`) เป็นเจ้าของ ไม่ใช่ `ptr` — บรรทัด 184, 191

**5. ตัวเลขในโค้ดคือเลขที่ปรับให้ตรงกับที่จำลองจริง ไม่ใช่เลขดิบจาก kit**
หัวไฟล์ระบุ "4★ ที่ E6 → Basic Lv.7 / Skill·Ult·Talent Lv.12" · และ cap "ATK bonus ไม่เกิน 25% ของ ATK Tingyun" ถูก **ตัดทิ้งโดยเจตนา** (บรรทัด 77) เพราะ ATK Tingyun สูงพอเสมอในบริบทที่จำลอง — ถ้าจะเทียบกับ kit ต้องอ่านคอมเมนต์ก่อน อย่าคิดว่าเลขไม่ตรงคือบั๊ก

**6. ยังมีช่องโหว่เรื่อง timing ที่ต้อง hack เอง**
ult ที่ลงบัฟตอน `phaseStatus == PhaseStatus::BeforeTurn` ของเป้าหมาย จะถูกนับเทิร์นเกินไป 1 → ต้องลด duration เอง (บรรทัด 129-132) เป็นบั๊กร่วมของ Tingyun/Bronya

## E2 — ไม่ implement โดยเจตนา

E2 ("เพื่อนที่ถือ Benediction คืน Energy 5 หลังฆ่าศัตรู, 1 ครั้ง/เทิร์น") ไม่มีในไฟล์ เพราะ **engine ยังไม่ยิงเหตุการณ์ศัตรูตาย** — `allEventWhenEnemyDeath()` มีทั้ง declaration และ definition แต่ไม่มีจุดไหนเรียก และ **ยังไม่ได้ตัดสินใจว่าควร trigger ตรงไหน** (user ยืนยัน 2026-09-22) ไม่ใช่การลืมต่อสาย

รายละเอียดและรายการความสามารถทั้งหมดที่ติดค้างเพราะเรื่องนี้อยู่ใน `README.md` ของโฟลเดอร์นี้ หัวข้อ "`Enemy_Death_List` — ยังไม่มีทางเข้า"
