# `src/Defination/Data/Character/Harmony/Bronya.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/bronya.md` · **ตัวที่นิยาม `driverNum` ของทั้งเกม** · มี `//temp` (บรรทัด 7)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(99, 120, 120, E, WIND, HARMONY, "Bronya", STANDARD)` | 11 |
| **ตั้งตัวเองเป็น driver ของทีม** | `driverNum = bronyaPtr->atvStats->num;` | 20 |
| **Skill** — advance เป้า 100% + DMG +66% | `skill(ptr)` — `AllyBuffAction` + `actionForward(..., 100)` | 136-168 |
| **Ultimate** — ATK +55% + CD ทีม | `ultimateList` — `buffAllAlly` + สำนวน delta รายคน | 30-55 |
| Ult — CD = 16% ของ CD Bronya + 20 | `calculateCritdamForBuff(ptr, 16) + 20` | 38 |
| **A4** — ทีม DEF +20% 2 เทิร์น | `startGameList` → `buffAllAlly(..., "Bronya_A4", 2)` | 67 |
| **Talent** — BA คริติคอลเสมอ + advance ตัวเอง | `statsType[Stats::CR][AType::BA] = 100` · `afterAttackActionList` → `actionForward(30)` | 62, 113-115 |
| **Technique** | `startGameList` → `buffAllAlly(ATK +15, "Bronya_Technique", 2)` | 66 |
| ทีม DMG +10% ขณะอยู่ในสนาม | `whenOnFieldList` | 108-110 |
| **Minor traces** | `resetList` | 57-63 |
| **E1** — Skill คืน SP ทุก 2 ครั้ง | `stack["Bronya_Skill_E1"]` + `isHaveToAddBuff(..., 1)` | 140-146 |
| **E2** — Skill ให้ SPD +30% | `buffSingle(..., "Bronya_Skill_E2", 1)` | 161-162 |
| **E4** — เพื่อนใช้ BA → Bronya ยิง FuA | `afterAttackActionList` + flag `Bronya_E4` (รีเซ็ตต้นเทิร์น) | 116-126, 101-104 |
| **E6** — Skill buff อยู่ 2 เทิร์น | `if (ptr->eidolon >= 6)` เลือก duration | 153-156 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` → `skill(ptr)` เสมอ | 26-28 |
| ถอนบัฟทุกตัว | `afterTurnList` — 6 บล็อก `isBuffEnd` | 70-99 |

## รากฐาน: `driverNum` — ตัวละครที่ทีมหมุนรอบ

`driverNum` เป็น global ที่บอกว่าใครเป็น "driver" (ตัวที่ทีมเร่งให้ได้เล่นถี่) · Bronya ตั้งค่านี้ตอน `setup` (20) · ตัวละครอื่นอ่านไปใช้: `../Erudition/The_Herta.md` เทียบ `charUnit[driverNum]->atvStats` ในสาขา `DriverType::DOUBLE_TURN` และ `Castorice.h` มีฟังก์ชัน `castoriceWithDriver`

> **มีที่เดียวในโปรเจกต์ที่เขียนค่านี้** — ถ้าทีมไม่มี Bronya `driverNum` จะค้างที่ค่าเดิม/ค่าตั้งต้น

## รากฐาน: บัฟทีมที่ค่าต่างกันรายคนต้องเก็บ `buffNote` รายคน

```cpp
double temp = calculateCritdamForBuff(ptr,16) + 20;
for (auto &e : act->buffTargetList) {
    buffSingle(e, {{CD, AType::NONE, temp - e->buffNote["Bronya_Ult"]}});
    buffSingle(e, {{CD, AType::TEMP,  temp - e->buffNote["Bronya_Ult"]}});
    e->buffNote["Bronya_Ult"] = temp;                 // <- เก็บที่ "เป้าหมาย" ไม่ใช่ที่ Bronya
}
```
ต่างจาก `../Abundance/Gallagher.md` ที่เก็บ `buffNote` บนตัวเอง เพราะที่นี่ค่าเดียวกันแต่ **ต้องถอนทีละคนตามเทิร์นของคนนั้น** (89-91) จึงต้องให้แต่ละคนจำค่าของตัวเอง

## รากฐาน: การกันบัฟ ult นับเทิร์นเกิน

```cpp
if (phaseStatus == PhaseStatus::BEFORE_TURN && (turn->side == Side::MEMOSPRITE || turn->side == Side::ALLY)) {
    AllyUnit *temp = dynamic_cast<AllyUnit*>(turn->charptr);
    extendBuffTime(temp, "Bronya_Ult", 1);
}
```
ถ้ากด ult ตอน `BEFORE_TURN` ของเพื่อน บัฟจะถูกนับหายไป 1 เทิร์น → ต่ออายุให้คนนั้นอีก 1 · **เป็นบั๊กร่วมของ Bronya กับ Tingyun** (ดู `Tingyun.md` ที่แก้ด้วยการลด duration แทน) — สองไฟล์แก้คนละวิธีกับปัญหาเดียวกัน

## จุดที่ควรระวัง

- **`statsType[Stats::CR][AType::BA] = 100`** ใช้ `=` ไม่ใช่ `+=` (62) — เขียนทับค่าที่ relic/LC อาจใส่ไว้ในช่องเดียวกัน · ถ้า `resetList` ของ relic รันก่อน ค่านั้นจะหาย
- **`beforeTurnList` มีบรรทัดที่ไม่ทำอะไร** (105): `if(ptr->atvStats->num != driverNum) return;` เป็นบรรทัดสุดท้ายของ lambda → `return` หรือไม่ก็ได้ผลเท่ากัน
- **`afterTurnList` ใช้ `dynamic_cast<AllyUnit*>(turn->charptr)`** (71) แทน `turn->canCastToAllyUnit()` ที่มีอยู่ — โค้ดเก่า (อาการเดียวกับ `../Erudition/Serval.md`)
- **E1 ใช้ `stack` เป็นตัวนับที่ไม่เคยรีเซ็ตนอก `isBuffEnd`** (141-145) — `stack["Bronya_Skill_E1"]++` ทุกครั้งที่ใช้ Skill แต่เช็ค `== 1` เท่านั้น → หลังจากเลย 1 ไปแล้วจะไม่คืน SP อีกจนกว่า `isBuffEnd` จะรีเซ็ตเป็น 0
- **E4 ไม่ guard `act->attacker` ว่าเป็นฝ่ายเรา** (116) ใช้ `isSameAction(AType::BA)` อย่างเดียว
- **`skill` ใช้ `chooseAllyBuff(ptr)` สด 4 ครั้ง** (154-162) — ถ้าเป้าหมายเปลี่ยนระหว่างนั้นจะไม่ตรงกัน · และ `afterTurnList` ถอนด้วย `tempstats` (คนที่เพิ่งจบเทิร์น) ซึ่งถูกต้องกว่า แต่ก็แปลว่าบัฟลงกับถอนใช้คนละกลไก · เทียบกับ `Tingyun.md` ที่แก้ปัญหานี้ด้วย `buffSubUnitTarget`
