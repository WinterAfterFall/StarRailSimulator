# `src/Defination/Data/Character/Destruction/FireFly.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/firefly.md` · **ไฟล์อ้างอิงของ Super Break และ Break Effect** — ตัวเดียวที่ดาเมจหลักมาจาก `superbreakTrigger` ไม่ใช่ `addDamageIns`

> **แก้ 2026-09-27** (รีวิวเทียบ kit — kit ใน repo เป็นเวอร์ชัน rework patch 4.2): Enhanced Skill hit สุดท้าย `4*` / `2*` → `0.4*` / `0.2*` (เดิมตัวคูณรวม 4.6 เท่า) · Skill 100% → 200% (80/120) · VUL ของ Combustion `AType::NONE` → `AType::BREAK` (ครอบ SPB ด้วยเพราะ SPB มี `BREAK` ใน `damageTypeList`) · A6 เดิมไม่เคยทำงาน (เช็ค `buffNote` แทน `temp`) และหาร 100 → หาร 10 · เพิ่ม A2 (BE +25% + หน่วง countdown 10% สูงสุด 3 ครั้ง) · A4 ตาม kit ใหม่ (BE ≥150%/300% → SPB 100%/150% เฉพาะ Enhanced Skill ขณะ Combustion — ข้อความเต็มไม่มีใน kit ตีความจากสรุปภาษาไทย) · Talent เติม energy เป็น 50% ตอนเริ่ม · E1 DEF ignore เฉพาะ `AType::SKILL` ขณะ Combustion · E2 guard เฉพาะ Enhanced Skill ของ FireFly + ครั้งเดียวต่อเทิร์น (stack เริ่ม 2 = ตั้งใจ: ประมาณว่าฆ่าศัตรูได้ 2 ตัวฟรี) · เพิ่ม E4 (Effect RES +50% ขณะ Combustion) และ E6 · base 814/523 · **แก้เพิ่ม 2026-09-27 (รอบสอง)**: เพิ่ม `addUltCondition` ห้าม ult ขณะ Combustion · Talent Effect RES +30% ใน `combustionBuff` · ชื่อ SPB `"A4"` · **ยังไม่ได้ทำ**: Ult `p3 = 1.2` / `p4 = 3` ใน kit ไม่รู้ความหมาย (user: ข้ามไปก่อน), Enhanced BA

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(104, 240, 240, E, FIRE, DESTRUCTION, "FireFly", STANDARD)` · base `(814, 523, 776)` | `FireFly.h:11-13` |
| build — **BE เป็นแกน** | `pushSubstats(Stats::BE)` + main stat เชือก `BE` | `:21-24` |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — countdown ตาย (ไม่อยู่ใน Combustion) → Skill · ไม่งั้น Enhanced Skill | `:27-33` |
| **Skill** — 200% ATK, คืน energy 60% ของ max, advance ตัวเอง 25% | `skillFunc` — hit 80% + 120% · `increaseEnergy(ptr, 60, 0)` ไม่ผ่าน ER · `actionForward(25)` หลัง `attack` | `:178-192` |
| **Enhanced Skill** (ขณะ Combustion) — `(0.2×BE + 200%)` ATK เป้าหลัก ครึ่งหนึ่งข้างเคียง, BE cap 360% | `enchanceSkillFunc` — ประกอบดาเมจใน callback ตาม BE ตอนนั้น แบ่ง 15/15/15/15/40 · แปะ Fire weakness 2 เทิร์น | `:193-218` (สูตร `:199-203` · weakness `:212-214`) |
| **Ultimate** — เข้า Complete Combustion + advance 100% | `ultimateList` — `buffSingle(combustionBuff(ptr, 1))` · รีเซ็ตตัวนับ A2 · `countdownList[0]->summon()` | `:50-57` |
| **Ult ใช้ไม่ได้ขณะ Combustion** | `addUltCondition` — กด ult ได้เฉพาะตอน countdown ตายแล้ว (กันบัฟซ้อนสองชั้น + countdown รีเซ็ต) | `:59-61` |
| บัฟระหว่าง Combustion | `combustionBuff(ptr, sign)` — SPD +60, Break Eff +50, VUL[Break] +20, **A2** BE +25, **Talent** Effect RES +30, **E1** DEF_SHRED[SKILL] +15, **E4** Effect RES +50, **E6** RESPEN +20 / Break Eff +50 · ลงด้วย `1` ถอนด้วย `-1` | `:161-176` |
| **countdown "Combustion_state"** (SPD 70) — ถึงตาแล้วออกจากสถานะ | `setCountdownStats(ptr, 70, …)` สร้าง `TimerATV` · `turnFunc` ถอน `combustionBuff(ptr, -1)` แล้ว `death()` | `:149-156` |
| **A2** — Break ขณะ Combustion → หน่วง countdown 10% (สูงสุด 3 ครั้งต่อรอบ) | `toughnessBreakList` → `actionForward(countdown, -10)` + stack `"FireFly A2 delay"` | `:80-91` (หน่วง `:86-89`) |
| **A4** — BE ≥ 150% / 300% → Super Break 100% / 150% | `afterAttackActionList` → `superbreakTrigger(act, 100 หรือ 150, "A4")` เฉพาะ Enhanced Skill ขณะ Combustion | `:123-138` (A4 `:132-137`) · engine: `Function/Combat/Combat.h` `superbreakTrigger` |
| **A6** — ทุก 10 ATK ที่เกิน 1800 → BE +0.8% | `statsAdjustList` (guard `ATK_P` / `FLAT_ATK`) · ลงส่วนต่างจาก `buffNote` | `:64-78` |
| **Talent** — energy < 50% ตอนเริ่ม → เติมเป็น 50% | `startGameList` | `:113-117` |
| **Technique** — แปะ Fire weakness + 200% AoE ต้น wave | `startWaveList` → `weaknessApply(…, "FireFly Weakness", 2)` + `dealDamage()` ทันที | `:93-111` |
| **Minor traces** — BE +37.3 · Effect RES +18 · SPD +5 | `resetList` | `:34-37` |
| **E1** — Enhanced Skill ไม่กิน SP + DEF ignore 15% | `if (ptr->eidolon < 1) genSkillPoint(ptr,-1)` · `combustionBuff` | `:194`, `:169` |
| **E2** — Enhanced Skill ฆ่า/Break → เทิร์นพิเศษ ครั้งเดียวต่อเทิร์น | stack เริ่ม 2 (`resetList`) + `toughnessBreakList` เพิ่ม stack · `afterAttackActionList` ใช้ stack → advance 100% · `beforeTurnList` รีเซ็ต `FireFly_E2_used` | `:45-47`, `:82-84`, `:127-131`, `:119-121` |
| weakness หมดอายุ | `afterTurnList` → `isDebuffEnd(enemy, "FireFly Weakness")` | `:140-144` |

## รากฐาน: Super Break

```cpp
if (!act->isSameAction(ptr, AType::SKILL)) return;      // Enhanced skill ของ FireFly
if (ptr->countdownList[0]->isDeath()) return;            // ขณะ Combustion เท่านั้น
if      (ptr->statsType[Stats::BE][AType::NONE] >= 300) superbreakTrigger(act, 150, "A4");
else if (ptr->statsType[Stats::BE][AType::NONE] >= 150) superbreakTrigger(act, 100, "A4");
```
`superbreakTrigger(act, ratio, ชื่อ)` เรียก **หลัง action จบ** (`afterAttackActionList`) เพื่อแปะดาเมจ Super Break ตามจำนวน toughness ที่ action นั้นทำลายไป · ดาเมจกลุ่มนี้ผูกกับ `AType::SPB` ซึ่ง `../../Relic/Iron_Cavalry.md` มีบัฟให้โดยเฉพาะ

**เกณฑ์ BE เป็นขั้นบันไดที่อ่าน `statsType` สด** ไม่ได้ cache → ถ้า BE เปลี่ยนระหว่างเกม (A2 ให้ BE +25 ระหว่าง Combustion) ระดับจะขยับตาม

## รากฐาน: `weaknessApply` — แปะธาตุอ่อนแอให้ศัตรู

```cpp
weaknessApply(ptr, each, {ElementType::FIRE}, "FireFly Weakness", 2);
```
ทำให้ศัตรูที่ไม่มี Fire weakness กลายเป็นมี ชั่วคราว → เปิดทางให้ break ได้ · ปลายทางคือ `weaknessApplyList` (`TriggerByWeaknessApplyFunc`) ที่ตัวละครอื่นดักได้ · ถอนด้วย `isDebuffEnd` ตามปกติ — สังเกตว่า `afterTurnList` เรียก `isDebuffEnd` **โดยไม่ใช้ค่าที่คืนมา** (`:143`) เพราะ helper เคลียร์สถานะให้เองในตัว

## รากฐาน: Module Y — สูตรที่เขียน stat ดิบเอง

```cpp
temp = floor(((ATK_P/100 * baseAtk + baseAtk) + FLAT_ATK - 1800) / 10) * 0.8;
if (temp <= 0) temp = 0;
buffSingle(ffPtr, {{BE, AType::TEMP, temp - buffNote[...]}, {BE, AType::NONE, temp - buffNote[...]}});
```
**คำนวณ ATK รวมด้วยมือแทนที่จะใช้ `calculateAtkForBuff`** ซึ่งมีอยู่แล้ว (`CalStats.h:52`) — ผลอาจต่างกันเพราะ helper ตัวนั้นหักช่อง `TEMP` ออกก่อน ส่วนสูตรนี้ไม่หัก · ใช้สำนวน delta + คู่ `TEMP`/`NONE` ตามปกติ (ดู `../Remembrance/RMC.md`)

## รากฐาน: ดาเมจที่ประกอบข้างใน callback ทั้งก้อน

`enchanceSkillFunc` ไม่มี `addDamageIns` นอก callback เลย — ประกอบทั้งหมดข้างในเพราะ multiplier ขึ้นกับ BE ณ เวลานั้น (`:197-215`) · เป็นรูปแบบเดียวกับ `../Erudition/The_Herta.md` แต่สุดโต่งกว่า (ที่นั่นมีก้อนคงที่นอก callback ด้วย)

## จุดที่ควรระวัง

- **Ult ไม่ได้สร้าง action** (`:50-57`) — บัฟตัวเองแล้ว `summon()` countdown ตรง ๆ ไม่มี `addToActionBar()` · แต่ `whenUseUltList` **ยังถูกยิง** เพราะ `ultUseCheck` เรียกให้ก่อน (`Function/Combat/Energy.h:39`) — คู่มือเดิมเขียนว่าไม่ยิง ซึ่งผิด (แก้ 2026-09-27)
- **`setCountdownStats` ถูกเรียกท้าย `setup`** (`:149`) หลังจากที่ `turnFunc` และ trigger หลายตัวอ้าง `ptr->countdownList[0]` ไปแล้ว — ทำงานได้เพราะ lambda ประเมินตอนรัน
- **`toughnessBreakList` guard ด้วย `atvStats->num`** (`:81`) แทนการเทียบชื่อ
- **E2 stack เริ่มที่ 2 โดยตั้งใจ** — user: ปกติมีศัตรูตายฟรี ~2 ตัวต่อไฟต์ จึงแถมไว้แทนเงื่อนไข "ฆ่าศัตรู"
- **A4 / Ult ของเวอร์ชัน rework ยังไม่ครบ** — kit เก็บแค่ตัวเลข: A4 ตีความเป็นอัตรา SPB ส่วน Ult `p3 = 1.2` / `p4 = 3` ยังไม่รู้ความหมาย
