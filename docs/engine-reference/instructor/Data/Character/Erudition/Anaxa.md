# `src/Defination/Data/Character/Erudition/Anaxa.h`

kit อ้างอิง: `docs/character-kit-reference/Anaxa.md` · **ไฟล์อ้างอิงของการแปะธาตุอ่อนแอ (weakness) เป็นกลไกหลัก** · คู่กับ `FireFly.md` ที่ใช้ `weaknessApply` แบบเจาะธาตุเดียว

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(97, 140, 140, E, Wind, Erudition, "Anaxa", Standard)` | 15 |
| **Basic ATK** | `Basic_Atk(ptr)` — single 100%/10 + แปะ weakness + A6 | 186-219 |
| **Skill** | `Skill(ptr)` — `TraceType::Bounce` + `addEnemyFairBounce(70/10, 5)` | 220-269 |
| **Ultimate** | `Ultimate_List` — AoE 160%×3 + แปะ **ทุกธาตุ** 1 เทิร์น | 49-83 |
| **A6** — DEF_SHRED ตามจำนวนธาตุอ่อนแอ | `each->debuffNote["AnaxaA6"] = currentWeaknessElementAmount * 4` ครอบ `Attack` | 58-74, 194-213, 251-266 |
| A6 — ธาตุครบ 5 → DMG +30 | `if (each->currentWeaknessElementAmount >= 5)` | 61-64 |
| **A4** — โบนัสตามจำนวน Erudition ในทีม | `WhenOnField_List` → `Adjust["AnaxaA4"]` = 1 หรือ 2 | 93-113 |
| **Talent** — แปะธาตุอ่อนแอ | `AnaxaDebuff(ptr, enemy)` → `weaknessApplyChoose(ptr, enemy, 1, "AnaxaTalent", 3)` | 274-277 |
| Talent — ทำ Skill ซ้ำถ้าธาตุยังไม่ครบ | `AfterAttackActionList` + flag `AnaxaTalent` | 169-180 |
| **Technique** | `Start_game_List` — DEF_SHRED stack + แปะ weakness ให้ศัตรูทุกตัว | 116-126 |
| **Minor traces** | `Reset_List` (มี `DMG += 30` เพิ่ม) | 85-91 |
| **E1** — Skill ลง DEF_SHRED 16 · ได้ SP คืนเทิร์นแรก | `debuffSingleApply(..., "AnaxaE1", 2)` · `genSkillPoint(ptr, 1)` | 244, 234 |
| **E2** — แปะ weakness 2 รอบ + RESPEN 20 ถาวร | `Start_game_List` → `debuffSingleMark(..., "AnaxaE2")` | 120-123 |
| **E4** — Skill ให้ ATK stack | `buffStackSingle(..., 1, 2, "AnaxaE4", 2)` | 240 |
| **E6** — ดาเมจ ×1.3 · ได้ทั้ง A4 สองท่อน | `BeforeAttackAction_List` แก้ `dmgSrc` ทุกช่อง · `WhenOnField_List` | 153-167, 104-107 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — ตั้ง flag Talent แล้ว SP พอ/เทิร์นแรก → Skill ไม่งั้น BA | 34-41 |

## รากฐาน: weakness เป็นทรัพยากรที่สะสมบนศัตรู

| helper | ทำอะไร |
|---|---|
| `weaknessApply(ptr, enemy, {ธาตุ...}, ชื่อ, เทิร์น)` | แปะธาตุที่ระบุ (Ult ของ Anaxa แปะครบ 7 ธาตุ, `FireFly.h` แปะ Fire) |
| `weaknessApplyChoose(ptr, enemy, จำนวน, ชื่อ, เทิร์น)` | **ให้ engine เลือกธาตุให้** ตามจำนวนที่ขอ — Talent ของ Anaxa ใช้ตัวนี้ |
| `enemy->currentWeaknessElementAmount` | จำนวนธาตุอ่อนแอที่ศัตรูมีอยู่ตอนนี้ |
| `Enemy_weak` (global) | รายการธาตุทั้งหมด ใช้วนถอน: `isDebuffEnd(enemy, "AnaxaTalent " + toString(e.first))` |

**ชื่อ debuff ของ weakness ถูกต่อท้ายด้วยชื่อธาตุ** (140) → ถอนต้องวนทุกธาตุ ไม่ใช่ชื่อเดียว

## รากฐาน: A6 — บัฟที่คำนวณจากสถานะศัตรู ณ เวลายิง

```cpp
for (auto &each : act->targetList) {
    each->debuffNote["AnaxaA6"] = each->currentWeaknessElementAmount * 4;
    debuffSingle(each, {{DEF_SHRED, AnaxaA6}});
    if (each->currentWeaknessElementAmount >= 5) { debuffNote["AnaxaDmgBonus"] = 30; debuffSingle(...); }
}
Attack(act);
for (auto &each : act->targetList) { ถอนทั้งสองอย่างด้วยค่าใน debuffNote แล้วล้างเป็น 0 }
```
**ครอบ `Attack` แบบเดียวกับ `../Nihility/Black Swan.md` แต่ค่าต่างกันรายศัตรู** จึงต้องเก็บค่าที่ลงไปไว้ใน `debuffNote` ของศัตรูแต่ละตัว ไม่ใช่ตัวแปรเดียว · **ก้อนนี้ถูก copy 3 ที่** (Ult, BA, Skill) เหมือนกันทุกบรรทัด

## รากฐาน: `addEnemyFairBounce` vs `addEnemyBounce`

`addEnemyFairBounce(DmgSrc, จำนวน)` (268) — เด้งแบบ**กระจายให้ทั่วถึง** ต่างจาก `addEnemyBounce` ที่สุ่ม · Skill ของ Anaxa ต้องแปะ weakness ให้ทั่วจึงใช้แบบ fair

## รากฐาน: Talent ที่เรียกท่าของตัวเองซ้ำ

```cpp
AfterAttackActionList:
if (actionName == "Anaxa BA" || actionName == "Anaxa Skill") {
    if (getBuffCheck("AnaxaTalent"))
        for (auto &each : act->targetList) {
            Skill(ptr);                                  // <- เรียก Skill ซ้ำ
            if (each->currentWeaknessElementAmount >= 5) { Deal_damage(); setBuffCheck(..., false); break; }
        }
    else setBuffCheck("AnaxaTalent", true);
}
```
flag `AnaxaTalent` ถูกตั้งเป็น `true` ที่ต้นเทิร์น (35) แล้วปิดเมื่อเงื่อนไขครบ — เป็นตัวกัน recursion แบบเดียวกับ `Mydei_cannot_charge` ใน `../Destruction/Mydei.md` แต่**หลวมกว่ามาก** (ดูจุดที่ควรระวัง)

## จุดที่ควรระวัง

- **ลูป Talent ใน `AfterAttackActionList` เสี่ยง recursion ไม่จบ** (171-178) — `Skill(ptr)` ข้างในจะสร้าง action ใหม่ที่ชื่อ `"Anaxa Skill"` ซึ่งเมื่อจบก็เข้า `AfterAttackActionList` ตัวเดิมอีก · ตัวหยุดมีทางเดียวคือธาตุครบ 5 แล้วตั้ง flag เป็น `false` · ถ้าแปะธาตุไม่ถึง 5 (เช่นศัตรูมีธาตุอยู่แล้วเยอะจนแปะเพิ่มไม่ได้) **จะวนไม่จบ**
- **`while(1)` ใน Skill** (245-253) มี `break` เมื่อ `cnt == 0` ทั้งสองชั้น — ถ้า `act->targetList` ว่าง (ไม่มีศัตรู) จะวนไม่จบเช่นกัน
- **`Basic_Atk` และ `Skill` เพิ่ม energy ผ่าน `charUnit[ptr->Atv_stats->num]`** (191, 226) แล้ว Skill ยังเรียก `Increase_energy(ptr, 30)` ซ้ำอีกครั้งในสาขาเทิร์นแรก (233) — รวมเป็น 60 ในเทิร์นแรก
- **`Reset_List` บวก `DMG += 30` ลอย ๆ** (90) ไม่มีคอมเมนต์ว่ามาจาก trace ไหน (อาการเดียวกับ `Saber.h`, `Hibana.h`)
- **`WhenOnField_List` ของ A4 เช็ค `charUnit[i]->path[0]` ช่องแรกช่องเดียว** (97) ต่างจาก `../../Planar/Izumo.md` และ `The_Herta.h` ที่วนทุก path — ตัวที่มีหลาย path จะถูกนับพลาด
- **`AnaxaDebuff` ประกาศตัวแปร `string element;` ที่ไม่ได้ใช้** (275)
- **`addUltCondition` ถูกคอมเมนต์ทิ้งทั้งก้อน** (42-47) → กด ult ทันทีที่ energy เต็มเสมอ
- **E6 คูณ `dmgSrc` ทุกช่องด้วย 1.3 ใน `BeforeAttackAction_List`** (156-162) ซึ่งยิงทุก action ของ Anaxa รวมถึง action ที่ Talent เรียกซ้ำ — ต้องดูว่าคูณซ้อนหรือไม่ เพราะ action ถูกสร้างใหม่ทุกครั้งจึงน่าจะปลอดภัย
