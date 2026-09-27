# `src/Defination/Data/Character/Destruction/Mydei.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/mydei.md` · **ไฟล์อ้างอิงของ taunt และการแลก HP เป็นทรัพยากร** · ดาเมจสเกลกับ HP ทั้งหมด

> **แก้ 2026-09-27** (รีวิวเทียบ kit): Skill / Kingslayer energy `increaseEnergy(ptr, 30, 0)` = 30% ของ Max Energy (48 แต้ม ไม่ผ่าน ER) → `increaseEnergy(ptr, 30)` ตาม kit · เข้า Vendetta นอกเทิร์นตัวเอง (เช่นโดนศัตรูตี) advance ทันที เดิมรอจนมีคนโจมตีเสร็จ · Charge cap 200 + GodSlayer ต้องอยู่ใน Vendetta · ATK 426 · เขียน `basicAtk` ให้เสร็จ · ลบ `buffNote["count"]`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | บรรทัดใน `Mydei.h` |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(95, 160, 160, E, IMAGINARY, DESTRUCTION, "Mydei", STANDARD)` | 17 |
| build — HP เป็นแกน | main stat `HP_P` 2 ช่อง + `setSpeedRequire(135)` | 26-27 |
| **Basic ATK** | `basicAtk(ptr)` — 50% Max HP, toughness 10, energy 20 (AI ไม่ได้เรียก) | 203-212 |
| **Skill** | `skill(ptr)` — blast 90/50 + `decreaseHP(ptr, ptr, 0, 0, 50)` + energy 30 | 214-227 |
| **Enhanced Skill** — Kingslayer (ขณะ Vendetta) | `enchanceSkill(ptr)` — blast 110/66 + เสีย HP 35% + energy 30 | 229-242 |
| **GodSlayer** — ท่าพิเศษจาก charge | `godSlayer(ptr)` — blast 2 ชุด (E1 → AoE 3 args) | 244-276 |
| **Ultimate** | `ultimateList` — blast 160/100 + taunt + ฮีลตัวเอง 20% Max HP + charge 20 | 45-69 |
| **Talent** — Vendetta: Max HP +50% | `statsAdjustList` → `calculateHpForBuff(ptr, 50)` + สำนวน delta `TEMP`/`NONE` | 128-139 |
| เข้าสถานะ Vendetta | `chargePoint()` — charge (cap 200) ครบ 100 → ตั้ง flag, advance 100% (ถ้ากำลังเป็นเทิร์น Mydei รอหลัง action), ฮีล 25%, `FLAT_DEF -= 10000` | 298-316 |
| **charge จากการเสีย HP** | `hpDecreaseList` → `calculateChargePoint()` = `value / totalHP * 100` | 141-148 |
| **A6** — โบนัสตาม Max HP ที่เกิน 4000 (cap 40) | `startGameList` — CR ×1.2 และ Healing ×0.75 ต่อหน่วย (Incoming Healing ใส่เป็น `HEALING_OUT` เพราะ engine ไม่มีสแตต incoming — ผลเท่ากันกับการฮีลตัวเอง) | 83-91 |
| **Technique** | `startGameList` — AoE 80% + taunt ทุกตัว 1 เทิร์น | 107-125 |
| **Minor traces** | `resetList` | 71-80 |
| **E1** — GodSlayer เป็น AoE และแรงขึ้น (280 + 30 = 310%) | `if (ptr->eidolon >= 1)` ใน `godSlayer` | 253-264 |
| **E2** — DEF_SHRED +15 · ฮีลแปลงเป็น charge | `chargePoint` · `healingList` | 314, 150-156 |
| **E4** — CD +30 · ถูกตี → ฮีล 10% | `chargePoint` · `enemyHitList` | 315, 158-166 |
| **E6** — เริ่มเกมใน Vendetta · GodSlayer ถูกกว่า | `startGameList` · `chargePoint` ใช้เกณฑ์ 100 แทน 150 (ต้องอยู่ใน Vendetta) | 92-104, 318-330 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — ไม่อยู่ใน Vendetta → Skill · อยู่ → Enhanced Skill | 37-43 |
| Taunt หมดอายุ | `afterTurnList` → `isDebuffEnd(e,"Mydei_Taunt")` → `e->removeTaunt(ptr)` | 189-193 |

## รากฐาน: taunt

```cpp
debuffApply(ptr, e, "Mydei_Taunt", 2);   // นับอายุ 2 เทิร์นบนศัตรูตัวนั้น
e->addTaunt(ptr);                        // ลงทะเบียนตัวเองใน tauntList ของศัตรู
...
if (isDebuffEnd(e, "Mydei_Taunt")) e->removeTaunt(ptr);
```
**taunt เป็นสองส่วนที่ต้องขยับคู่กันเสมอ** — `debuffApply` ดูแลอายุ ส่วน `addTaunt` / `removeTaunt` ดูแลรายชื่อบนศัตรู · คอมเมนต์ในไฟล์ระบุว่า `addTaunt` มี dedup ในตัว และ `debuffApply` 4 args refresh countdown เสมอ (50-53) · **อายุแยกอิสระต่อศัตรูแต่ละตัว** จึงต้องถอนใน `afterTurnList` ที่ผูกกับเทิร์นของศัตรูตัวนั้น

## รากฐาน: HP เป็นทรัพยากรสองทาง

```cpp
double calculateChargePoint(AllyUnit *ptr, double value) { return value / ptr->totalHP * 100.0; }
```
**แปลง HP ที่เสียเป็นเปอร์เซ็นต์ของ Max HP** แล้วเอาไปเป็น charge · `hpDecreaseList` แยกสองกรณี (140-147):
- ศัตรูเป็นคนทำให้เสีย (`trigger->canCastToEnemy()`) → คูณโบนัสจาก A6
- ตัวเองจ่าย (Skill/Enhanced Skill) → ได้ตามตรง

`decreaseHP(ptr, ptr, 0, 0, 50)` = จ่าย 50% ของ HP เป็นต้นทุนของ Skill

## รากฐาน: flag กัน charge ซ้อนระหว่าง action

```cpp
beforeAttackActionList: if (act->actionName == "GodSlayer") buffCheck["Mydei_cannot_charge"] = 1;
chargePoint():           if (ptr->buffCheck["Mydei_cannot_charge"]) return;
afterAttackActionList:   buffCheck["Mydei_cannot_charge"] = 0;
```
GodSlayer ถูกยิงจากข้างใน `chargePoint()` เอง → ถ้าดาเมจของมันทำให้ได้ charge ต่อจะเกิด recursion · flag นี้คือตัวตัดวง

## รากฐาน: `enemyHitList`

`TriggerByEnemyHit` — callback รับ `(Enemy *attacker, vector<AllyUnit*> target)` = **ศัตรูโจมตีฝ่ายเรา** · เป็น list เดียวที่มองจากฝั่งศัตรูเป็นผู้กระทำ · E4 ของ Mydei ใช้เช็คว่าตัวเองอยู่ในรายชื่อเป้าหมายไหม

## จุดที่ควรระวัง

- **`FLAT_DEF -= 10000`** เป็นวิธีทำ "DEF = 0 ขณะ Vendetta" ด้วยการลบค่ามหาศาล — ไม่มีโค้ดคืนค่าเพราะ sim ไม่มีทางออกจาก Vendetta (ศัตรูไม่ได้ทำดาเมจถึงตาย)
- **โค้ดเข้า Vendetta มี 2 ที่** — `startGameList` สำหรับ E6 (92-104, advance ตรง ๆ) และ `chargePoint` (302-316)
- **advance ตอนเข้า Vendetta** — ถ้า `turn` เป็นของ Mydei (กำลังใช้ Skill) ตั้ง `buffCheck["Mydei_action"]` แล้ว advance ใน `afterAttackActionList` (หลัง `resetTurn` ที่อยู่ใน `attack()`) · นอกนั้น advance ทันที
- **`goto jump` ใน `enemyHitList`** (158-166) รูปแบบเดียวกับ `../Remembrance/RMC.md`
- **A6 เขียน `statsType` ตรง ๆ ทั้ง `NONE` และ `TEMP`** ไม่ผ่าน `buffSingle` → ไม่ยิง `statsAdjust` · ต้องเรียก `allEventAdjustStats(ptr, Stats::HP_P)` เองที่บรรทัด 106
- **`increaseEnergy(CharUnit*, a, b)` แบบ 3 args: `a` = % ของ Max Energy, `b` = energy คงที่ — ทั้งคู่ไม่ผ่าน ER** (`Function/Combat/Energy.h:17`) · ใช้กับ energy ที่ kit ระบุเป็น "fixed" เท่านั้น · energy ปกติของ Skill/BA ใช้ 2 args (ผ่าน ER) — แก้ 2026-09-27: คู่มือเดิมบอกแค่ว่า arg 3 ไม่ผ่าน ER
