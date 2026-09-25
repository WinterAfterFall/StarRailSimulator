# `src/Defination/Data/Character/Destruction/Mydei.h`

kit อ้างอิง: `docs/character-kit-reference/Mydei.md` · **ไฟล์อ้างอิงของ taunt และการแลก HP เป็นทรัพยากร** · ดาเมจสเกลกับ HP ทั้งหมด

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(95, 160, 160, E, Imaginary, Destruction, "Mydei", Standard)` | 17 |
| build — HP เป็นแกน | main stat `HP_P` 2 ช่อง + `setSpeedRequire(135)` | 26-27 |
| **Basic ATK** | `Basic_Atk(ptr)` — **ยังไม่เสร็จ** (`//none complete` บรรทัด 207) | 202-209 |
| **Skill** | `Skill(ptr)` — blast 90/50 + `DecreaseHP(ptr, ptr, 0, 0, 50)` | 210-224 |
| **Enhanced Skill** — Kingslayer (ขณะ Vendetta) | `Enchance_Skill(ptr)` — blast 110/66 + เสีย HP 35% | 225-239 |
| **GodSlayer** — ท่าพิเศษจาก charge | `GodSlayer(ptr)` — blast 2 ชุด (E1 → AoE 3 args) | 240-273 |
| **Ultimate** | `Ultimate_List` — blast 160/100 + taunt + ฮีลตัวเอง 20% Max HP + charge 20 | 45-69 |
| **Talent** — Vendetta: Max HP +50% | `Stats_Adjust_List` → `calculateHpForBuff(ptr, 50)` + สำนวน delta `TEMP`/`None` | 127-138 |
| เข้าสถานะ Vendetta | `ChargePoint()` — charge ครบ 100 → ตั้ง flag, ฮีล 25%, `FLAT_DEF -= 10000` | 294-310 |
| **charge จากการเสีย HP** | `HPDecrease_List` → `CalculateChargePoint()` = `Value / totalHP * 100` | 140-147 |
| **A6** — โบนัสตาม Max HP ที่เกิน 4000 (cap 40) | `Start_game_List` — CR ×1.2 และ Healing Out ×0.75 ต่อหน่วย | 83-90 |
| **Technique** | `Start_game_List` — AoE 80% + taunt ทุกตัว 1 เทิร์น | 106-124 |
| **Minor traces** | `Reset_List` | 71-80 |
| **E1** — GodSlayer เป็น AoE และแรงขึ้น | `if (ptr->Eidolon >= 1)` ใน `GodSlayer` | 249-260 |
| **E2** — DEF_SHRED +15 · ฮีลแปลงเป็น charge | `ChargePoint` · `Healing_List` | 307, 149-155 |
| **E4** — CD +30 · ถูกตี → ฮีล 10% | `ChargePoint` · `Enemy_hit_List` | 308, 157-165 |
| **E6** — เริ่มเกมใน Vendetta · GodSlayer ถูกกว่า | `Start_game_List` · `ChargePoint` ใช้เกณฑ์ 100 แทน 150 | 91-103, 311-322 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — ไม่อยู่ใน Vendetta → Skill · อยู่ → Enhanced Skill | 37-43 |
| Taunt หมดอายุ | `After_turn_List` → `isDebuffEnd(e,"Mydei_Taunt")` → `e->removeTaunt(ptr)` | 188-192 |

## รากฐาน: taunt

```cpp
debuffApply(ptr, e, "Mydei_Taunt", 2);   // นับอายุ 2 เทิร์นบนศัตรูตัวนั้น
e->addTaunt(ptr);                        // ลงทะเบียนตัวเองใน tauntList ของศัตรู
...
if (isDebuffEnd(e, "Mydei_Taunt")) e->removeTaunt(ptr);
```
**taunt เป็นสองส่วนที่ต้องขยับคู่กันเสมอ** — `debuffApply` ดูแลอายุ ส่วน `addTaunt` / `removeTaunt` ดูแลรายชื่อบนศัตรู · คอมเมนต์ในไฟล์ระบุว่า `addTaunt` มี dedup ในตัว และ `debuffApply` 4 args refresh countdown เสมอ (50-53) · **อายุแยกอิสระต่อศัตรูแต่ละตัว** จึงต้องถอนใน `After_turn_List` ที่ผูกกับเทิร์นของศัตรูตัวนั้น

## รากฐาน: HP เป็นทรัพยากรสองทาง

```cpp
double CalculateChargePoint(AllyUnit *ptr, double Value) { return Value / ptr->totalHP * 100.0; }
```
**แปลง HP ที่เสียเป็นเปอร์เซ็นต์ของ Max HP** แล้วเอาไปเป็น charge · `HPDecrease_List` แยกสองกรณี (140-147):
- ศัตรูเป็นคนทำให้เสีย (`Trigger->canCastToEnemy()`) → คูณโบนัสจาก A6
- ตัวเองจ่าย (Skill/Enhanced Skill) → ได้ตามตรง

`DecreaseHP(ptr, ptr, 0, 0, 50)` = จ่าย 50% ของ HP เป็นต้นทุนของ Skill

## รากฐาน: flag กัน charge ซ้อนระหว่าง action

```cpp
BeforeAttackAction_List: if (act->actionName == "GodSlayer") buffCheck["Mydei_cannot_charge"] = 1;
ChargePoint():           if (ptr->buffCheck["Mydei_cannot_charge"]) return;
AfterAttackActionList:   buffCheck["Mydei_cannot_charge"] = 0;
```
GodSlayer ถูกยิงจากข้างใน `ChargePoint()` เอง → ถ้าดาเมจของมันทำให้ได้ charge ต่อจะเกิด recursion · flag นี้คือตัวตัดวง

## รากฐาน: `Enemy_hit_List`

`TriggerByEnemyHit` — callback รับ `(Enemy *Attacker, vector<AllyUnit*> target)` = **ศัตรูโจมตีฝ่ายเรา** · เป็น list เดียวที่มองจากฝั่งศัตรูเป็นผู้กระทำ · E4 ของ Mydei ใช้เช็คว่าตัวเองอยู่ในรายชื่อเป้าหมายไหม

## จุดที่ควรระวัง

- **`Basic_Atk` ยังไม่ได้ implement** (202-209) — สร้าง `AllyActionData` เปล่าแล้ว push เข้า `Action_bar` พร้อมคอมเมนต์ `//none complete` · แต่ `Turn_func` ไม่เคยเรียกมัน (มีแค่ Skill / Enhanced Skill) จึงยังไม่เห็นอาการ
- **`FLAT_DEF -= 10000`** (98-99, 305-306) เป็นวิธีทำ "DEF = 0 ขณะ Vendetta" ของ kit ด้วยการลบค่ามหาศาล แทนที่จะตั้งเป็น 0 — **ไม่มีโค้ดคืนค่าเมื่อออกจาก Vendetta** (ซึ่ง kit ไม่มีทางออกอยู่แล้ว) แต่ถ้ามีวันนั้นจะรั่ว
- **โค้ดเข้า Vendetta ถูก copy 2 ที่** — ใน `Start_game_List` สำหรับ E6 (91-103) และใน `ChargePoint` (297-310) ต่างกันเล็กน้อย (ตัวแรกเรียก `Action_forward` ตัวหลังตั้ง `buffCheck["Mydei_action"]`)
- **`goto jump` ใน `Enemy_hit_List`** (157-165) รูปแบบเดียวกับ `../Remembrance/RMC.md`
- **A6 เขียน `Stats_type` ตรง ๆ ทั้ง `None` และ `TEMP`** (87-90) ไม่ผ่าน `buffSingle` → ไม่ยิง `StatsAdjust` · ต้องเรียก `allEventAdjustStats(ptr, Stats::HP_P)` เองที่บรรทัด 105
- **`buffNote["count"]`** (319) เพิ่มขึ้นแต่ไม่มีใครอ่าน — น่าจะเป็นตัวนับดีบัก
- **`Increase_energy(ptr, 30, 0)`** ใช้ overload 3 args ที่ Skill/Enhanced Skill (215, 230) ต่างจาก `Increase_energy(ptr, 10)` ใน GodSlayer (245) — arg ที่ 3 คือ energy ที่ไม่ผ่าน ER
