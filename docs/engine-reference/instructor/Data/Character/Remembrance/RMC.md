# `src/Defination/Data/Character/Remembrance/RMC.h`

kit อ้างอิง: `docs/character-kit-reference/RMC.md` · **ไฟล์อ้างอิงหลักของระบบ memosprite** — ใครจะทำตัวละคร Remembrance ให้เริ่มที่นี่ · มี `//temp` (บรรทัด 5)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult (160) | `SetCharBasicStats(103, 160, 160, E, ElementType::Ice, Path::Remembrance, "RMC", UnitType::Standard)` | 14 |
| Base HP/ATK/DEF ของตัวละคร | `SetAllyBaseStats(1048, 543, 631)` | 15 |
| **สร้าง memosprite "Mem"** | `SetMemoStats(ptr, 688, 68, 130, 0, ElementType::Ice, "Mem", UnitType::Standard)` | 19 |
| **Basic ATK** | `Basic_Atk(ptr)` — single 100%/10 | 193-202 |
| **Skill** — เรียก Mem ออกมา | `Skill(ptr)` — `AllyBuffAction` + `addActionType(AType::Summon)` → `summon(100)` + `resetATV(130)` + charge 90 | 203-219 |
| **Memosprite Skill** | `Memo_Skill(ptr)` — `TraceType::Bounce` + `addEnemyBounce(39.6/5, 4)` + AoE 99% | 223-239 |
| **Memosprite Enhanced Skill** (Mem_Charge เต็ม) | `Memo_Echance_Skill(ptr)` — `AllyBuffAction` ลง `Mem_Support` + CR +10 + advance เป้า 100% | 240-265 |
| **Ultimate** | `Ultimate_List` — AoE 264%×3 args ยิงในนามของ **memosprite** | 55-75 |
| Ult — CR 100% ชั่วคราว | `buffSingle(Memptr, CR +100)` → `Attack` → `-100` | 61-66 |
| **Talent** — CD ทีมตาม CD ของ Mem | `WhenOnField_List` ตั้งครั้งแรก + `Stats_Adjust_List` คำนวณใหม่เมื่อ CD ของ Mem เปลี่ยน | 87-96, 119-124 |
| ระบบ **Mem_Charge** | `Increase_Charge(ptr, charge)` — ครบ 100 → เคลียร์เป็น 0, ตั้ง flag, advance Mem 100% | 181-190 |
| charge จากการได้ energy ของทีม | `When_Energy_Increase_List` | 154-166 |
| **Technique** | `Start_game_List` — ลด action ศัตรูทุกตัว 50% + AoE 50% + advance ตัวเอง 30% | 98-117 |
| **Minor traces** | `Reset_List` | 77-85 |
| **E2** — memosprite ตัวอื่นโจมตี → energy 8 | `Before_turn_List` ตั้ง flag + `AfterAttackActionList` ใช้ flag | 133-135, 167-173 |
| True DMG จาก `Mem_Support` | `AfterDealingDamage_List` → `Cal_DamageNote` | 136-152 |
| AI: เทิร์นของตัวละคร | `Turn_func` — เทิร์นแรก Skill (เรียก Mem) ที่เหลือ BA | 34-40 |
| AI: เทิร์นของ memosprite | `ptr->memosprite->Turn_func` — มี charge → Enhanced Skill ไม่งั้น Skill | 41-48 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — charge ≥ 60 และเป้าที่บัฟใกล้ได้เล่น → รอ | 50-53 |

## รากฐาน: memosprite

**1. memosprite เป็น unit เต็มตัวที่มีเทิร์นของตัวเอง**
`SetMemoStats(ตัวละคร, HP, ATK, DEF, SPD, element, ชื่อ, UnitType)` สร้างแล้วผูกไว้ใน `ptr->memosprite` · เข้าถึงได้ 2 ทาง: `ptr->getMemosprite()` (คืน `CharUnit*`-like) และ `ptr->memosprite` (คืน `unique_ptr`) — ไฟล์นี้ใช้ทั้งสองแบบสลับกัน · **มี `Turn_func` แยกของตัวเอง** (41) ซึ่งคือ AI ว่า memosprite จะทำอะไรในเทิร์นของมัน

**2. วงจรชีวิต: `isDeath()` → `summon(HP%)` → `resetATV(SPD)`**
Skill ของ RMC เช็ค `isDeath()` ก่อน ถ้าตายอยู่จึงเรียกออกมาใหม่ (208-213) · `summon(100)` = เรียกด้วย HP เต็ม 100% · `resetATV(130)` = ตั้ง action value เริ่มต้นด้วย SPD 130 · ถ้า Mem ยังอยู่ Skill จะไม่ทำอะไรเลยนอกจากกิน SP และให้ energy

**3. `chooseAllyBuff(unit)` / `chooseCharacterBuff(unit)` — ตัวแปลงเป้าหมายบัฟ**
เมื่อบัฟอาจต้องลงที่ "ตัวละคร" หรือ "memosprite" ขึ้นกับสถานการณ์ · `chooseCharacterBuff` คืน **ตัวละครเจ้าของ** เสมอ ส่วน `chooseAllyBuff` คืนตัวที่ควรได้บัฟตอนนี้ · ดูระบบ index ของ `chooseAllyBuff` ที่ `../../README.md` และ `future-improvements.md`

**4. `Side::Memosprite` แยกจาก `Side::Ally`**
`AfterAttackActionList` ของ E2 กรองด้วย `act->Attacker->Atv_stats->side == Side::Memosprite` **และ** ชื่อไม่ใช่ `"Mem"` (168) = "memosprite ของคนอื่นโจมตี"

**5. `buffSingleChar` vs `buffSingle`** — `buffSingleChar` ลงให้ทั้งตัวละครและ memosprite ของเขา (ดู `../../Relic/Hero_Wreath.md`)

## รากฐาน: trigger ใหม่ 2 ตัว

**`When_Energy_Increase_List`** (`TriggerEnergy_Increase_Func`) — ยิงทุกครั้งที่ **ใครก็ตามในทีมได้ energy** callback รับ `(CharUnit *target, double Energy)`
```cpp
if (Energy == 0) { Increase_Charge(ptr, 3); return; }                   // energy ที่ไม่ผ่าน ER
if (Energy + target->Current_energy > target->Max_energy)               // clamp ส่วนที่ล้น
    Energy = target->Max_energy - target->Current_energy;
buffNote["Mem_Energy_cnt"] += Energy;
Increase_Charge(ptr, floor(buffNote["Mem_Energy_cnt"] / 10));           // ทุก 10 energy = 1 charge
buffNote["Mem_Energy_cnt"] -= floor(...) * 10;                          // เก็บเศษไว้
```
**สำนวนเก็บเศษ** นี้จำเป็นเพราะ charge เป็นจำนวนเต็มแต่ energy ไม่ใช่ — เศษที่ไม่ถึง 10 ต้องสะสมข้ามครั้ง

**`AfterDealingDamage_List`** (`TriggerAfterDealDamage`) — callback รับ `(act, target, damage)` คือ **ดาเมจที่ออกไปจริงแล้ว** ใช้ทำผลที่สเกลกับดาเมจก้อนนั้น · RMC ใช้คู่กับ `Cal_DamageNote(...)` เพื่อเพิ่ม True DMG ตาม `Mem_Support`

## รากฐาน: `AType::TEMP` กับการกันลูปของ `Stats_Adjust_List`

Talent ของ RMC คือ "CD ทีม = สัดส่วนของ CD ของ Mem" ซึ่งเป็นสูตรที่ **ผลของมันเองก็เป็น CD** → ถ้าปล่อยไว้จะวนไม่จบ

```cpp
double buffValue = calculateCritdamForBuff(Mem, 13.2) + 26.4;
buffAllAlly({{Stats::CD, AType::TEMP, buffValue - buffNote["Mem_Talent_Buff"]}});
buffAllAlly({{Stats::CD, AType::None, buffValue - buffNote["Mem_Talent_Buff"]}});
buffNote["Mem_Talent_Buff"] = buffValue;
```

**ลงค่าเดียวกัน 2 ครั้ง ที่ `AType::TEMP` และ `AType::None`** — เพราะ `calculateXForBuff` **ลบช่อง `TEMP` ออกก่อนคำนวณ** (`CalStats.h:86`) ช่อง `TEMP` จึงเป็น "บันทึกว่าส่วนนี้มาจากบัฟที่คำนวณเอง อย่าเอามาคิดซ้ำ" ส่วนช่อง `None` คือค่าที่ใช้จริงตอนตีดาเมจ · **นี่คือกลไกกันลูปของสูตรที่อ้างอิงตัวเอง** ใช้คู่กับสำนวน delta + `buffNote` เดียวกับ `../Abundance/Gallagher.md`

## รากฐาน: action ของ memosprite

- สร้าง action โดยส่ง `ptr->getMemosprite()` เป็นผู้กระทำ ไม่ใช่ `ptr` (58, 225, 244)
- **`addActionType` / `addAttackType` / `addDamageType` ต่างกัน** (`Class/ActionData/AllyActionData.h:199-212`): `addActionType` เพิ่มเฉพาะประเภท action, `addDamageType` เฉพาะประเภทดาเมจ, `addAttackType` เพิ่มทั้งคู่ · ท่าของ memosprite ใส่ `AType::Summon` เพิ่มเข้าไปเพื่อให้บัฟที่เจาะจง Summon เข้าถึง
- **`TraceType::Bounce` + `addEnemyBounce(DmgSrc, จำนวนครั้ง)`** = โจมตีเด้งสุ่มเป้าหลายครั้ง เป็น trace type ที่นอกเหนือจาก Single/Blast/Aoe

## จุดที่ควรระวัง

- **`goto jump` ใน `AfterDealingDamage_List`** (136-152) ใช้ข้ามออกจากลูปซ้อน — ทำงานได้แต่เป็นรูปแบบเดียวในโปรเจกต์ · ตัวแปร `ally` ประกาศแล้วไม่ init ถ้าเส้นทางไหนหลุดไปถึง `jump` โดยไม่ผ่านการ assign จะเป็น undefined (ตอนนี้ทุกเส้นทางที่ไปถึงมีการ assign แล้ว)
- **`Before_turn_List` ตั้ง `RMC_E2` = 1 ทุกต้นเทิร์นของทุก unit** (133-135) ไม่ได้ guard ว่าเป็นเทิร์นใคร → โควตา E2 รีเซ็ตถี่กว่าที่ kit ตั้งใจ (อาการเดียวกับ `../../Planar/Tengoku@Livestream.md`)
- **Ult ยิงในนามของ memosprite แต่ `Ultimate_List` ผูกกับ `ptr`** (55-58) — ถ้า Mem ตายอยู่ตอนกด ult ยังไม่มีโค้ดกันไว้
- **`Increase_Charge` เช็ค `isDeath()` แล้ว return** (182) แต่ `When_Energy_Increase_List` เรียกทุกครั้งที่ทีมได้ energy → charge ที่ควรสะสมระหว่าง Mem ตายจะหายไปทั้งหมด รวมถึงเศษใน `Mem_Energy_cnt` ที่ยังถูกสะสมต่อ
- **charge ล้นถูกตัดทิ้ง** — ครบ 100 ตั้งเป็น 0 ตรง ๆ (185) ไม่ได้เก็บส่วนเกิน
