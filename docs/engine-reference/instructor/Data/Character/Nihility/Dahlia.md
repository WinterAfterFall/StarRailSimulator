# `src/Defination/Data/Character/Nihility/Dahlia.h`

kit อ้างอิง: `docs/kit-reference/Character/Nihility/the-dahlia.md` · **ซัพพอร์ต Super Break ที่แก้ toughness reduction ของ action คนอื่นโดยตรง** · เป็นที่เดียวที่ใช้ `weaknessApplyList` และตั้ง global `dahliaCheck`

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(96, 130, 130, E, FIRE, NIHILITY, "Dahlia", STANDARD)` | 5 |
| **ตั้ง flag global** | `dahliaCheck = 1;` | 20 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 23-35 |
| **Skill** — ทีม Break Effect +50 / BE ตาม BE ตัวเอง | lambda `skill` — `isHaveToAddBuff("Dahlia Skill", 3)` + `calculateBreakEffectForBuff(ptr,24) + 50` | 37-56 |
| **Follow-up ATK** | lambda `FUA` — `TraceType::BOUNCE` + `addEnemyBounce(30/3, 5)` (E4 → 10) | 58-78 |
| **Ultimate** — Wilt + แปะ weakness ธาตุของเป้าที่บัฟ | `ultimateList` — AoE 300%×3 | 91-108 |
| **A2** — BE ทีมตาม BE ของ Dahlia | `buffNote["Dahlia A2"]` + คู่ `TEMP`/`NONE` | 44-47 |
| **A6** — แปะ weakness → SPD +30% · toughness reduce +20 | `weaknessApplyList` · `beforeAttackList` | 216-224, 155-167 |
| **Super Break ให้ทีม** | `afterAttackActionList` → `superbreakTrigger(act, 60 หรือ 100, "Dahlia")` | 184-196 |
| **Talent** — เป้าที่บัฟโจมตี → Dahlia ยิง FuA | `afterAttackActionList` → `fua()` | 194-196 |
| **Technique** | `startGameList` — ทำ Skill buff ซ้ำทั้งก้อน | 198-215 |
| **Minor traces** | `resetList` | 110-114 |
| **E1** — toughness reduce ตาม Max toughness · Super Break 100 | `beforeAttackList` · `afterAttackActionList` | 167-176, 185-187 |
| **E2** — ศัตรู RESPEN +20 · แปะ weakness ต้นเกม | `whenOnFieldList` · `startGameList` | 116, 208-213 |
| **E4** — FuA bounce 10 ครั้ง · VUL +12 | `addEnemyBounce(..., 10)` · `debuffSingleApply(..., "Dahlia E4", 2)` | 74, 66 |
| **E6** — BE +150 ทั้งคู่ · FuA advance | `whenOnFieldList` · `actionForward(..., 20)` ×2 | 117-120, 69-72 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — มีบัฟ Skill → BA ไม่งั้น Skill | 81-85 |

## รากฐาน: แก้ `toughnessReduce` ของ action คนอื่นก่อนยิง

```cpp
beforeAttackList:
for (auto &each1 : act->damageSplit)
    for (auto &each : each1) {
        if (each.target->getDebuff("Dahlia A6")) continue;      // ตัวละหนึ่งครั้ง
        each.dmgSrc.toughnessReduce += 20;
        each.target->setDebuff("Dahlia A6", 1);
    }
for (auto &each : act->targetList) each->setDebuff("Dahlia A6", 0);   // ล้างทันทีหลังวน
```
- **เข้าไปแก้ `damageSplit` ของ action ที่คนอื่นสร้าง** ก่อนที่ดาเมจจะถูกคำนวณ — เป็นวิธีเพิ่ม toughness reduction ให้ทั้งทีม (ซึ่งเป็นแกนของ Super Break)
- **ใช้ `setDebuff` เป็น flag ชั่วคราวภายในลูป** เพื่อกันการบวกซ้ำให้ศัตรูตัวเดียวกันหลายก้อนดาเมจ แล้วล้างทันที · เป็นการใช้ช่อง debuff เป็นตัวแปรชั่วคราว
- E1 ใช้รูปแบบเดียวกันแต่คิดจาก `maxToughness * 0.25` (clamp 10-300) และ **ไม่ล้าง flag `Dahlia E1`** → ดูจุดที่ควรระวัง

## รากฐาน: `weaknessApplyList`

```cpp
weaknessApplyList.push_back(TriggerByWeaknessApplyFunc(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *trigger, Enemy *target, vector<ElementType> elementList) { ... }));
```
ยิงทุกครั้งที่มีการ **แปะธาตุอ่อนแอ** (`weaknessApply` / `weaknessApplyChoose` จาก `../Erudition/Anaxa.md`, `../Destruction/FireFly.md`, `Silver Wolf.md`) · callback ได้ทั้งผู้แปะ เป้าหมาย และรายการธาตุ · Dahlia ใช้เป็น trigger ของ A6

## จุดที่ควรระวัง

- **`beforeTurnList` เรียก `isBuffEnd(ally, ...)` โดยไม่เช็ค null** (128) — `turn->canCastToAllyUnit()` คืน `nullptr` ได้เมื่อเป็นเทิร์นศัตรู · บล็อกนี้ไม่มี `if (!ally) return;` ต่างจาก `afterTurnList` ข้างล่างที่เช็ค → **เสี่ยง null dereference**
- **`afterActionList` วน `allyList` แต่ตั้ง flag ของ `ptr` เสมอ** (179-183): `for (auto &each : allyList) ptr->setBuffCheck("Dahlia A6", 0);` — ตัวแปรลูป `each` ไม่ได้ถูกใช้ · ตั้งค่าเดิมซ้ำ N ครั้ง
- **flag `Dahlia E1` ไม่เคยถูกล้าง** (170-172) ต่างจาก `Dahlia A6` ที่ล้างท้ายลูป → **E1 ให้ toughness reduce กับศัตรูแต่ละตัวได้ครั้งเดียวตลอดเกม**
- **Ult สร้างด้วย `AType::SKILL`** (93) ทั้งที่ชื่อ `"Dahlia Ult"` — อาการเดียวกับ `Black Swan.h` / `Luka.h` ที่แก้แล้ว **ไฟล์นี้ยังไม่ได้แก้**
- **Technique copy โค้ด Skill buff ทั้งก้อน** (201-207)
- **`whenOnFieldList` ของ E2 ลง `debuffAllEnemyApply` โดยไม่ใส่ duration** (116) → ถาวร ไม่มีโค้ดถอน (อาการเดียวกับ E1 ของ `Black Swan.md`)
- **`afterAttackActionList` เรียก `fua()` เมื่อเป้าที่บัฟโจมตี** (194-196) โดยไม่มีตัวจำกัดจำนวนครั้งต่อเทิร์น
- **`FUA` มี flag `Dahlia FUA SP` ที่ไม่มีใครตั้งเป็น 1** (62-63) → `genSkillPoint(ptr, 1)` ทำงานทุกครั้ง
