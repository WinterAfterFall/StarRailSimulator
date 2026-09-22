# `src/Defination/Data/Character/Nihility/Kafka.h`

kit อ้างอิง: `docs/character-kit-reference/Kafka.md` · **ไฟล์อ้างอิงของ DoT แบบ "จุดระเบิด" (detonate) และ Follow-up ATK** — คู่กับ `Black Swan.md` ที่เป็นฝั่ง DoT แบบสะสม stack

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(100, 120, 120, E, ElementType::Lightning, Path::Nihility, "Kafka", UnitType::Standard)` | 7 |
| Base HP/ATK/DEF | `SetAllyBaseStats(1087, 679, 485)` | 8 |
| build — EHR + SPD | `setSpeedRequire(160)` + `setEhrRequire(75)` + main stat ช่องแรก `Stats::EHR` | 13-15 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 34-46 |
| **Skill** — Blast + จุดระเบิด DoT 75/50% | lambda `Skill` — `addDamageIns(160/20, 60/10)` (2 args = blast) แล้ว **หลัง `Attack(act)`** วน `targetList` เรียก `Dot_trigger(75 หรือ 50, each, DotType::General)` แยกตาม `Target_type` | 48-65 |
| **Ultimate** — AoE + Shock + จุดระเบิด 120% | `Ultimate_List` → `addDamageIns` 3 args (AoE 80%) · `dotSingleApply(..., {DotType::Shock}, "Kafka Shock", 2)` · `Dot_trigger(120, ...)` · `addStack("Kafka Talent", 1)` (= A6) | 95-115 |
| **Talent** — FuA 140% + Shock | lambda `Fua` (`AType::Fua`) + ตัวนับ `"Kafka Talent"` | 67-84 |
| Talent trigger หลังเพื่อนโจมตี | `AfterAttack_List` → `!act->isSameName("Kafka") && getStack("Kafka Talent") > 0` → `addStack(-1)` แล้วเรียก `Fua()` | 165-170 |
| Talent คืน charge ตอนจบเทิร์น Kafka | `After_turn_List` → `if (turn->isSameName("Kafka")) addStack("Kafka Talent", 1)` | 158 |
| Shock DoT 290% ต้นเทิร์น | `Dot_List` → guard `getDebuff("Kafka Shock")` + guard `Dot_type` เป็น `General`/`Shock` เท่านั้น | 172-182 |
| **Technique** | `Start_game_List` → สร้าง `AllyAttackAction(AType::Technique, ...)` AoE 50% + Shock | 136-155 |
| **A2** — ATK +100% ให้เพื่อน EHR ≥ 75% | `setAdjust("Kafka A2 <ชื่อ>", 1)` ตอน setup + `WhenOnField_List` วน `charList` เช็ค `getAdjust` → `buffSingleChar` + `newEhrRequire(75)` | 26-31, 123-129 |
| **A4** — ศัตรูตายขณะ Shock → energy 5 | **ไม่มี** (ดูล่าง) | — |
| **A6** — หลัง Ult ได้ charge เพิ่ม | `addStack("Kafka Talent", 1)` ท้าย callback ของ Ult | 106 |
| **Minor traces** | `Reset_List` | 117-121 |
| **E1** — เป้ารับ DoT +30% | `BeforeAttack_List` (เฉพาะเมื่อ `Eidolon >= 1`) → `debuffSingleApply(..., {{Stats::VUL, AType::Dot, 30}}, ...)` | 184-191 |
| **E2** — DoT ทีม +33% | `WhenOnField_List` → `buffAllAlly({{Stats::DMG, AType::Dot, 33}})` | 131-133 |
| **E4** — energy 2 ต่อ Shock tick | `if (ptr->Eidolon >= 4) Increase_energy(ptr, 2)` ใน `Dot_List` | 180 |
| **E6** — Shock +156% (+1 เทิร์น) | บวก multiplier ใน `Dot_List` + `dotSingleApply(..., 3)` ก่อนบรรทัด 2 เทิร์นปกติ | 74-75, 102-103, 143-144, 177 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` → `Skill()` **เสมอ** (Kafka ไม่มีเหตุผลกด BA) | 87-89 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `return true` | 91-93 |
| หมด Shock → ถอน DoT | `After_turn_List` + `turn->canCastToEnemy()` + `isDebuffEnd` → `dotRemove(enemy, {DotType::Shock})` | 157-163 |

## รากฐานที่เพิ่มจาก Black Swan

**1. DoT มี 2 แบบของ API: แบบ stack และแบบมีอายุ**
`dotSingleStack(...)` (BS/Arcana) สะสมจำนวน stack · `dotSingleApply(ผู้ลง, เป้า, {DotType}, ชื่อ, เทิร์น)` (Kafka/Shock) ลงเป็น debuff มีอายุ แล้วถอนด้วย `dotRemove(enemy, {DotType::Shock})` เมื่อ `isDebuffEnd` — เลือกให้ตรงกับ kit ว่า DoT นั้น "ซ้อนได้" หรือ "มีเทิร์น"

**2. `Dot_trigger(ratio, เป้า, DotType)` = จุดระเบิด DoT ที่ติดอยู่ให้ออกดาเมจทันที**
ไม่ใช่การลง DoT ใหม่ · `ratio` คือ % ของดาเมจ DoT เดิม (Skill 75/50, Ult 120, FuA 80) · `DotType::General` = จุดระเบิด DoT ทุกชนิดบนเป้านั้น · ปลายทางคือ handler ใน `Dot_List` ของทุกตัวละครที่รับ `Dot_ratio` ไปคูณด้วย `act->multiplyDmg(Dot_ratio)` — **นี่คือเหตุผลที่ `Dot_List` handler ต้องรับ `Dot_ratio` เป็นพารามิเตอร์**

**3. `Dot_List` handler ต้อง guard 2 ชั้นเสมอ**
`Dot_List` เป็น list กลางของทั้งเกม — handler ของ Kafka จึงเช็คทั้ง "เป้านี้ติด Shock ของ Kafka ไหม" (`getDebuff("Kafka Shock")`) และ "DoT ที่ถูกเรียกเป็นชนิดที่เกี่ยวกับเราไหม" (`Dot_type != General && != Shock` → return, บรรทัด 173-174) ไม่งั้น Shock จะออกดาเมจตอนมีคนจุดระเบิด DoT ชนิดอื่น

**4. Follow-up ATK ที่มี charge = ตัวนับ stack บนตัวเอง + `AfterAttack_List`**
`kafka->addStack("Kafka Talent", n)` / `getStack(...)` ใช้เป็นตัวนับ charge ตรง ๆ · trigger อยู่ที่ `AfterAttack_List` พร้อม guard ว่าผู้โจมตีไม่ใช่ Kafka เอง (กัน FuA ยิง FuA ซ้อน) · `Fua()` ต้องปิดท้ายด้วย `Deal_damage()` เองเพราะไม่ได้ถูกเรียกผ่าน action bar ปกติ

**5. `setAdjust` / `getAdjust` = ช่องเก็บค่า config ต่อตัวละครแบบ key-string**
ใช้เมื่อผลของ trace ขึ้นกับ "ใครอยู่ในทีม" ซึ่งรู้ไม่ได้ตอน compile — Kafka ตั้ง `"Kafka A2 <ชื่อ>"` ไว้ล่วงหน้าเป็น whitelist (Kafka, Hysilens, Black Swan, Guinaifen, Luka, Robin) แล้ว `WhenOnField_List` ค่อยวน `charList` จับคู่ · `Kafka::useKafkaA2(int num)` (201-206) เป็นทางเพิ่มชื่อจากนอกไฟล์ (เช่นจาก ManualBuilder) พร้อมยก `newApplyBaseChanceRequire(75)` ให้ตัวนั้น

**6. ตัวละครหนึ่งเขียนทับเกณฑ์ build ของ "ตัวอื่น" ได้**
`each->newEhrRequire(75)` / `newApplyBaseChanceRequire(75)` — A2 ของ Kafka บังคับให้เพื่อนที่รับบัฟต้องปั้น EHR ถึง 75% ด้วย เป็น side effect ข้ามตัวละครที่หาไม่เจอถ้าอ่านแต่ไฟล์ของตัวที่ถูกบัฟ

## ส่วนที่ยังไม่มีในโค้ด

- **A4 — Plunder** (ศัตรูตายขณะ Shock → energy 5) ไม่มี · engine ยังไม่ยิงเหตุการณ์ศัตรูตาย และยังไม่ได้ตัดสินใจว่าจะ trigger ตรงไหน ดู `README.md` หัวข้อ "`Enemy_Death_List` — ยังไม่มีทางเข้า"

## จุดที่ควรระวัง

- ~~ชื่อ debuff E1 สะกดไม่ตรงกัน~~ **แก้แล้ว 2026-09-22** — เดิมลงด้วย `"kafka E1"` (k เล็ก, บรรทัด 188) แต่เช็คหมดอายุด้วย `"Kafka E1"` (K ใหญ่, บรรทัด 194) → `isDebuffEnd` ไม่มีวันเป็นจริง DoT vulnerability +30% จึงค้างถาวร · ตอนนี้ใช้ `"Kafka E1"` ทั้งสองจุด E1 หมดอายุใน 2 เทิร์นตาม kit
  > ไม่ต้องกันการลงซ้ำเพิ่ม: `debuffApply(ptr, enemy, ชื่อ, extend)` (`Function/Combat/Debuff_Stats.h:14`) ต่ออายุให้ทุกครั้งแต่คืน `false` ถ้า debuff ติดอยู่แล้ว → `debuffSingleApply` ข้ามการบวก stat ซ้ำเอง · **นี่คือเหตุผลที่ลง debuff ซ้ำ ๆ ทุกการโจมตีได้อย่างปลอดภัย ตราบใดที่ชื่อตรงกัน**
- **ตัวนับ `"Kafka Talent"` ไม่มี cap — จงใจ** (user ยืนยัน 2026-09-23) kit บอก charge สูงสุด 2 · เป็น default ของโปรเจกต์ ดู `README.md` หัวข้อ "cap ของ stack สะสม"
- **ตัวนับ `"Kafka Talent"` เริ่มที่ 0 — จงใจเมิน** (user ยืนยัน 2026-09-23) kit บอกเริ่มเกมมี 2 charge · อันนี้คนละเรื่องกับ cap และรู้อยู่แล้วว่าไม่ตรง → ช่วงต้นเกม Kafka ยิง FuA ช้ากว่าจริง ถ้าจะแก้คือเซ็ตค่าเริ่มต้นใน `Start_game_List`
- **`Dot_trigger` ของ Skill ถูกเรียกหลัง `Attack(act)`** (บรรทัด 54-58) ส่วน Ult ก็เช่นกัน — ลำดับนี้สำคัญเพราะ debuff ที่ action นั้นเพิ่งลงต้องมีผลก่อนจุดระเบิด ถ้าสลับลำดับตัวเลขจะเปลี่ยน
- **E1 ลงทะเบียน trigger ใน `if (ptr->Eidolon >= 1)` นอก callback** (บรรทัด 184) ต่างจาก eidolon อื่นในไฟล์ที่เช็คข้างใน — ทั้งสองแบบใช้ได้ แต่แบบนี้ประหยัดกว่าเพราะไม่ push trigger ที่ไม่มีวันทำงาน
