# `src/Defination/Data/Character/Nihility/Fugue.h`

kit อ้างอิง: `docs/kit-reference/Character/Fugue.md` · **ซัพพอร์ต Super Break** — คู่กับ `../Harmony/Harmony_MC.md` · เป็นที่เดียวที่เรียก `Toughness_break()` ด้วยมือ

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(102, 130, 130, E, Fire, Nihility, "Fugue", Standard)` | 5 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 23-35 |
| **Enhanced BA** (หลังใช้ Skill) | lambda `EBA` — blast 100/100 | 37-50 |
| **Skill** — เป้าได้ BE +30 | lambda `Skill` — `AllyBuffAction` + `isHaveToAddBuff("Fugue Skill", 3)` | 52-69 |
| **Ultimate** | `Ultimate_List` — AoE 200%×3 + `Dont_care_weakness = 100` | 82-99 |
| **Talent** — Cloudflame Luster: break ซ้ำได้ | `AfterAttackActionList` → `Toughness_break(act, each)` เมื่อ toughness ติดลบเกิน 40% | 160-168 |
| **Super Break ให้ทั้งทีม** | `AfterAttackActionList` → `Superbreak_trigger(act, 100, "Fugue")` | 160 |
| **A-trace** — เป้าที่บัฟเพิกเฉย weakness 50% + DEF_SHRED | `BeforeAttack_List` | 148-158 |
| **A6** — break แล้วทีมได้ BE stack | `Toughness_break_List` → `buffStackAllAlly(..., 1, 2, "Fugue A6", 2)` | 170-176 |
| break แล้วถอยคิวศัตรู | `Action_forward(target->getAtvStats(), -15)` | 171 |
| **Minor traces** | `Reset_List` (BE `24 + 30`) | 100-106 |
| **E1** — เป้าได้ Break Effect +50 | `if (ptr->Eidolon >= 1)` ใน Skill | 61 |
| **E2** — Ult advance ทีม 24% · break คืน energy | `All_Action_forward(24)` · `Increase_energy(ptr, 3)` | 87, 175 |
| **E4** — เป้าได้ VUL +20 | `if (ptr->Eidolon >= 4)` ใน Skill | 62 |
| **E6** — Skill บัฟทั้งทีม · Break Effect +50 | `act->addBuffAllAllies()` · `Reset_List` | 66, 105 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — มีบัฟ Skill → EBA ไม่งั้น Skill | 72-76 |

## รากฐาน: `Toughness_break()` เรียกด้วยมือ — break ซ้ำ

```cpp
AfterAttackActionList:
for (auto &each : act->targetList) {
    if (each->debuffCheck["Cloudflame Luster"] == 0 && each->Current_toughness * (-1) >= each->Max_toughness * 0.4) {
        Toughness_break(act, each);                       // สั่ง break เอง
        each->debuffCheck["Cloudflame Luster"] = 1;       // กันซ้ำจนกว่าจะ break จริงอีกครั้ง
    }
}
Toughness_break_List:  target->debuffCheck["Cloudflame Luster"] = 0;   // ปลดล็อกเมื่อ break เกิดขึ้น
```
**kit ของ Fugue คือ "ศัตรูที่ broken แล้วยัง break ได้อีก"** — โค้ดตรวจว่า toughness ติดลบเกิน 40% ของค่าเต็มแล้วสั่ง `Toughness_break()` เอง · `Cloudflame Luster` เป็น flag กันการ break ซ้อนในรอบเดียว และถูกปลดใน `Toughness_break_List` ซึ่งยิงหลัง break สำเร็จ

> `Current_toughness * (-1)` — toughness ติดลบหมายถึงเกินจุด break ไปแล้วเท่าไร

## รากฐาน: `Dont_care_weakness` แบบ `max`

```cpp
act->Dont_care_weakness = max(act->Dont_care_weakness, 50.0);
```
(150) — **ไม่เขียนทับของเดิม** เผื่อ action นั้นมีค่าสูงกว่าอยู่แล้ว (เช่น Ult ของ Fugue เองที่ตั้ง 100) · เทียบกับ `../Erudition/Rappa.md` และ `../Remembrance/Castorice.md` ที่ตั้งค่าตรง ๆ

## รากฐาน: `buffStackAllAlly`

`buffStackAllAlly({stat}, เพิ่ม, cap, ชื่อ, เทิร์น)` (174) — เวอร์ชันทั้งทีมของ `buffStackSingle` · ถอนด้วย `buffResetStack` รายคนใน `After_turn_List` (135-137)

## จุดที่ควรระวัง

- **`AllyDeath_List` ใช้ `isBuffEnd` แทน `isBuffGoneByDeath`** (142-146) — `isBuffEnd` เช็คว่าเป็นเทิร์นของ unit นั้นด้วย ซึ่งคนที่เพิ่งตายไม่ได้อยู่ในเทิร์นตัวเอง → **บล็อกนี้แทบไม่มีวันทำงาน** บัฟ `Fugue A6` บนคนที่ตายจะค้าง
- **`Skill` สร้างด้วย `AType::BA`** (54) ทั้งที่เป็น `AllyBuffAction` ชื่อ `"Fugue Skill"` — อาการเดียวกับ `Black Swan.h` / `Luka.h` ที่แก้ไปแล้ว **ไฟล์นี้ยังไม่ได้แก้**
- **การถอนบัฟ Skill ใช้ `chooseAllyBuff(ptr)` สด** (117-120) ไม่ใช่ตัวที่ถือบัฟจริง → ถ้าเป้าหมายเปลี่ยนจะถอนผิดคน (อาการเดียวกับ `../Harmony/Cerydra.md`)
- **`AfterAttackActionList` เรียก `Superbreak_trigger` ทุก action ของทุกคนโดยไม่มีเงื่อนไข** (160) — ต่างจาก `../Harmony/Harmony_MC.md` ที่ต้องมีบัฟ ult ก่อน และ `../Destruction/FireFly.md` ที่ต้องมี BE ถึงเกณฑ์ · ถ้า kit ของ Fugue ให้ Super Break ตลอดเวลาก็ถูก แต่ควรยืนยัน
- **`Reset_List` บวก BE เป็น `24 + 30`** (102) — เขียนเป็นผลบวกให้เห็นสองแหล่งแต่ไม่บอกว่าแหล่งไหน
- **`Turn_func` แจก SP ฟรีในเทิร์นแรก** (73) `if (ptr->getTurnCnt() == 1) genSkillPoint(ptr, 1);` ไม่มีคอมเมนต์อ้างอิง kit
- **`Toughness_break_List` ไม่ guard ว่าใคร break** (170) → ทุกผลทำงานทุกครั้งที่ใครก็ตาม break ซึ่งน่าจะตรงกับ kit
