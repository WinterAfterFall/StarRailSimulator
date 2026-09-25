# `src/Defination/Data/Character/Remembrance/Castorice.h`

kit อ้างอิง: `docs/kit-reference/Character/Remembrance/castorice.md` · **ไฟล์ที่ซับซ้อนที่สุดในโปรเจกต์ (397 บรรทัด)** · อ่าน `RMC.md` (พื้นฐาน memosprite) และ `Aglaea.md` (joint attack) ก่อน

## สิ่งที่ทำให้ไฟล์นี้ต่างจากทุกตัว

| ประเด็น | รายละเอียด |
|---|---|
| **energy ult = 0** | `SetCharBasicStats(95, 0, 0, ...)` — ไม่ใช้ระบบ energy เลย เงื่อนไขกด ult คือทรัพยากร `Newbud` แทน |
| **ดาเมจสเกลกับ HP** | ทุกท่าใช้ `DmgSrcType::HP` ไม่ใช่ `ATK` · main stat 3 ใน 4 ช่องเป็น `HP_P` |
| **memosprite เป็น `UnitType::Backup`** | `SetMemoStats(ptr, 34000, 0, 165, 0, Quantum, "Netherwing", UnitType::Backup)` |
| **เสีย HP = ทรัพยากร** | `HPDecrease_List` แปลง HP ที่ทีมเสียเป็น `Newbud` หรือ HP ของ Netherwing |
| **มีฟังก์ชันตั้งเงื่อนไขให้ตัวละคร "อื่น"** | `DriverCondition` / `HealerCondition` / `CastoriceWithDriver` (373-393) |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| **Basic ATK** | `BasicAttack(ptr)` — `DmgSrc(DmgSrcType::HP, 50, 10)` | 286-296 |
| **Skill** | `Skill(ptr)` — blast 50/30 + `DecreaseHP(ptr,"Netherwing",0,0,30)` | 297-310 |
| **Enhanced Skill** (Netherwing อยู่) | `Enchance_Skill(ptr)` — AoE 2 ชุด + `setJoint()` + `switchAttacker` | 311-339 |
| **Memosprite Skill** | `memosprite->Turn_func` — ลูป `while (currentHP > 8500)` ยิงซ้ำจนเลือดหมด | 45-117 |
| **Kamikaze** (จบอายุ Netherwing) | `Kamikaze(ptr)` — `TraceType::Bounce` + `addEnemyBounce(HP 40/5, 6 หรือ 9)` แล้ว `death()` | 340-372 |
| **Ultimate** — เรียก Netherwing | `Ultimate_List` — `AllyBuffAction` · `summon(100)` · `extendBuffTime("NetherwingLifeSpan", Adjust)` · `debuffAllEnemyMark` RESPEN 20 | 141-161 |
| Ult ให้ทีม DMG +10% 3 เทิร์น | `buffAllAlly({{DMG, 10}}, "Roar Rumbles the Realm", 3)` | 152 |
| **เงื่อนไขกด ult (2 ชั้น)** | `addUltCondition` — `Newbud >= 34000` **และ** memosprite ตายอยู่ | 132-139 |
| **Newbud** — ทรัพยากรจาก HP ที่เสีย | `HPDecrease_List` + `Healing_List` | 199-238 |
| **Talent** — เสีย HP → DMG +20% (3 ชั้น) | `HPDecrease_List` → `buffStackChar(..., 1, 3, "CastoriceTalentBuff", 3)` | 227-230 |
| **Inverted Torch** — HP ≥ 50% → SPD +40% | ตั้งใน `Start_game_List` / `Healing_List` และถอนใน `HPDecrease_List` | 194-197, 213-218, 231-236 |
| **Technique** | `Start_game_List` — `summon(50)` + ตั้ง `turn` เอง + `DecreaseHP` 40% | 173-193 |
| **Minor traces** | `Reset_List` | 119-130 |
| **E1** — ดาเมจ ×1.239 | คูณ `dmgSrc.HP` ใน Enhanced Skill / Memo Skill / Kamikaze | 68-72, 100-104, 317-323, 362-368 |
| **E2** — Netherwing อยู่ 1 เทิร์นแทน 3 + Ardent Will 2 | `ptr->Adjust["NetherwingLifeSpan"]` + `setStack("Ardent Will", 2)` | 33-35, 154-158 |
| **E4** — ทีม Healing Received +20% | `WhenOnField_List` | 165-167 |
| **E6** — RESPEN +20 + เพิกเฉย weakness + bounce 9 ครั้ง | `WhenOnField_List` · `act->Dont_care_weakness = 100` · `addEnemyBounce(..., 9)` | 168-170, 110, 355-359 |
| AI: เทิร์นตัวละคร | `Turn_func` — memosprite ตาย → Skill ไม่งั้น Enhanced Skill | 36-43 |
| หมดอายุ Netherwing → Kamikaze | `After_turn_List` → `isBuffEnd(Polluxptr,"NetherwingLifeSpan")` | 240-243 |

## รากฐาน: HP เป็นทั้งทรัพยากรและ stat ของดาเมจ

**`DecreaseHP(ptr, ชื่อแหล่ง, ?, ?, เปอร์เซ็นต์)`** — ลด HP ของฝ่ายเราแบบตั้งใจ (ไม่ใช่โดนตี) ใช้เป็นต้นทุนของท่า · ทุกการลด HP ไปโผล่ที่ **`HPDecrease_List`** (`TriggerDecreaseHP`, callback รับ `(Unit *Trigger, AllyUnit *target, double Value)`)

```cpp
if (memosprite ตาย)  ptr->buffNote["Newbud"] += Value;          // สะสมรอเรียก
else                 memosprite->RestoreHP(..., CONST, Value);   // เติมเลือดมังกร
```

**`Healing_List` ก็ถูกดักเหมือนกัน** — การฮีลที่ตกใส่ทีมถูกแปลงเป็น Newbud/เลือดมังกรด้วย พร้อม **เพดานต่อ action ที่ 4080** ผ่าน `buffNote["NetherwingHealLimit"]` ซึ่งถูกล้างที่ `Buff_List` และ `BeforeAttackAction_List` (261-272) = **หน้าต่างการนับคือ "ต่อหนึ่ง action"** ไม่ใช่ต่อเทิร์น

## รากฐาน: ลูปโจมตีจนทรัพยากรหมดใน callback เดียว

`Turn_func` ของ Netherwing มี `while (currentHP > 8500)` (52) ที่ยิง `Attack(act)` ซ้ำ ๆ โดย **แก้ multiplier ของ action เดิมก่อนยิงแต่ละรอบ**:

```cpp
for (auto &each : act->damageSplit[0]) each.dmgSrc.HP = 24;   // หรือ 28 / 34 ตาม stack
...
Attack(act);
if (getStack("Ardent Will") > 0) stack--;  else  currentHP -= 8500;
```

**เป็นที่เดียวในโปรเจกต์ที่แก้ `act->damageSplit` โดยตรงหลังประกอบ action แล้ว** — ปกติจะ `addDamageIns` ให้ครบก่อน `addToActionBar()` · ทำแบบนี้ได้เพราะ `Attack()` คำนวณจบทันทีในบรรทัดนั้น

## รากฐาน: `Stats_Adjust_List` แบบ "ตรึงค่าไว้ที่ตัวเลขคงที่"

```cpp
if (!Target->isSameName("Netherwing")) return;
if (StatsType != Stats::FLAT_HP && StatsType != Stats::HP_P) return;
double temp = 34000 - calculateHpOnStats(ptr->getMemosprite());
buffSingle(Polluxptr, {{Stats::FLAT_HP, AType::None, temp}});
```
ทุกครั้งที่ HP ของ Netherwing ถูกบัฟ จะถูกดึงกลับมาให้รวมเป็น **34000 พอดีเสมอ** — ต่างจากการใช้ `Stats_Adjust_List` แบบอื่นที่คำนวณค่าตาม stat ต้นทาง

## รากฐาน: ตัวละครที่ไปตั้งเงื่อนไข ult ให้ตัวอื่น

```cpp
void DriverCondition(CharUnit *ptr, CharUnit *target)   // driver จะไม่กด ult ถ้า Netherwing ตาย
void HealerCondition(CharUnit *ptr, CharUnit *target)   // healer จะไม่กด ult ถ้า Newbud เต็มแล้ว
void CastoriceWithDriver(CharUnit *ptr, CharUnit *target) // Castorice รอจังหวะ driver
```
push เข้า `target->ultCondition` โดยตรง — **ไม่ได้ถูกเรียกจากใน `Setup`** ต้องเรียกจากข้างนอก (ManualBuilder / ไฟล์ประกอบทีม) เหมือน `Kafka::useKafkaA2` (ดู `../Nihility/Kafka.md`)

## จุดที่ควรระวัง

- **`Start_game_List` เขียน global `turn` โดยตรง** (`turn = ptr->getMemosprite()->Atv_stats.get();` บรรทัด 181) เพื่อให้ `DecreaseHP` ที่ตามมาถูกนับให้ถูกตัว — เป็นการแตะตัวแปรลำดับเทิร์นของ engine จากไฟล์ตัวละคร ซึ่งไม่มีที่อื่นทำ
- **โค้ดเลือก multiplier 24/28/34 ถูก copy 2 รอบในฟังก์ชันเดียว** (53-66 และ 80-97) ต่างกันแค่บริบท ถ้าแก้ตัวเลขต้องแก้ทั้งสองที่
- **`while (currentHP > 8500)`** ไม่มีตัวกันวนไม่จบถ้า `Ardent Will` ถูกเติมระหว่างลูป — ตอนนี้ไม่มีโค้ดเติม จึงปลอดภัยโดยบังเอิญ
- **`Kamikaze` ถอน `Lost Netherland` ด้วยมือทั้ง `debuffRemove` และ `debuffSingle(-20)`** (348-351) แทนที่จะใช้ `isDebuffEnd` — ถูกต้องเพราะ debuff นี้ลงด้วย `debuffAllEnemyMark` (ไม่มีอายุ) แต่แปลว่าถ้ามีทางจบสถานะทางอื่นต้องไล่ถอนเองทุกทาง
- **`Buff_List` และ `BeforeAttackAction_List` ล้าง `NetherwingHealLimit` ของ ally ทุกคนทุก action** (261-272) — เป็น O(ally) ต่อ action และไม่ได้ guard ว่า action นั้นเกี่ยวกับ Castorice ไหม
- **`HealerCondition` เทียบ `currentHP == 34000`** ด้วย `==` กับ `double` (388)
