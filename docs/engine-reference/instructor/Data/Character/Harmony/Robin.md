# `src/Defination/Data/Character/Harmony/Robin.h`

kit อ้างอิง: `docs/kit-reference/Character/Robin.md` · **ไฟล์ที่มี `addUltCondition` มากที่สุด (4 ก้อน)** และเป็นที่เดียวที่แก้ `baseSpeed` ระหว่างเกม · มี `//temp` (บรรทัด 6)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(102, 160, 160, E, Physical, Harmony, "Robin", Standard)` | 13 |
| **Basic ATK** | `Basic_Atk(ptr)` — single 100%/10 | 200-210 |
| **Skill** — ทีม DMG +50% 3 เทิร์น | `Skill(ptr)` — `setBuffCheck` + `extendBuffTime("Pinion'sAria", 3)` | 186-198 |
| **Ultimate** — เข้า Concerto state | `Ultimate_List` — `countdown->summon()` + `baseSpeed = -1` + `All_Action_forward(100)` | 73-95 |
| Ult — ทีม FLAT_ATK ตาม ATK ของ Robin | `calculateAtkForBuff(ptr, 22.8) + 200` + สำนวน delta `TEMP`/`None` | 82-84 |
| Ult — ทีม CD สำหรับ FuA +25 | `buffAllAlly({{Stats::CD, AType::Fua, 25}})` | 86 |
| **Talent** — Additional DMG ทุกครั้งที่ทีมโจมตี (ขณะ Concerto) | `When_attack_List` → `AType::Addtional` 120% | 127-150 |
| Talent — คริติคอลคงที่ 150% | สลับ `CR`/`CD` ชั่วคราวรอบ `Attack` | 137-148 |
| energy จากการโจมตีของทีม | `When_attack_List` → `Increase_energy(ptr, 2)` | 128 |
| **A-trace** — ทีม CD +20% | `WhenOnField_List` | 117-119 |
| **Technique** | `Start_wave_List` → energy +5 | 107-111 |
| **Minor traces** | `Reset_List` (ตั้ง `baseSpeed = 102` กลับด้วย) | 97-105 |
| **E1** — ทีม RESPEN +24 ขณะ Concerto | `if (ptr->Eidolon >= 1)` ทั้งตอนเข้าและออก | 87, 175 |
| **E2** — เพื่อน SPD +16% · energy เพิ่ม | `buffAllAllyExcludingBuffer` · `Increase_energy(ptr, 1)` | 88, 129-131 |
| **จบ Concerto state** | `countdownList[0]->Turn_func` — ถอนบัฟทั้งหมด + คืน `baseSpeed` | 166-180 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — ไม่มี `Pinion'sAria` → Skill ไม่งั้น BA | 28-34 |

## รากฐาน: `addUltCondition` หลายก้อนที่แยกตาม `driverType`

Robin มี 4 ก้อน แต่ละก้อนดูแลสถานการณ์ต่างกัน และ **ทุกก้อนต้องเป็นจริงพร้อมกัน** ถึงจะกด ult:

| ก้อน | บรรทัด | ดูแลอะไร |
|---|---|---|
| 1 | 36-42 | เฉพาะ `DriverType::DoubleTurn` — อย่ากดถ้า driver ใกล้ได้เล่นหรือเป้าที่บัฟ atv = 0 |
| 2 | 44-57 | ถ้า**ไม่ใช่** `AlwaysPull` → เช็คว่าตัวเองกับ memosprite ไม่ได้ atv = 0 · ถ้าใช่ → driver ต้องได้เล่นทีหลัง dps |
| 3 | 59-65 | เฉพาะ `AlwaysPull` — กลับด้านจากก้อน 2 |
| 4 | 67-71 | ต้องไม่อยู่ใน Concerto อยู่แล้ว และต้องมี `Pinion'sAria` ก่อน |

**`driverType` เป็น global ที่บอกรูปแบบทีม** (`DoubleTurn` / `AlwaysPull` / …) — ตัวเดียวกับที่ `../Erudition/The_Herta.md` ใช้ · ก้อน 2 กับ 3 มีเงื่อนไขกลับด้านกันซึ่งอ่านแล้วสับสน (ดูจุดที่ควรระวัง)

## รากฐาน: แก้ `baseSpeed` เพื่อ "หยุดเทิร์น"

```cpp
Ult:              ptr->Atv_stats->baseSpeed = -1;  Update_Max_atv(...);  resetTurn(...);
countdown จบ:     ptr->Atv_stats->baseSpeed = 102; Update_Max_atv(...);  resetTurn(...);
```
ตั้ง `baseSpeed` เป็น **-1** ทำให้ Robin ไม่ได้เทิร์นเลยระหว่าง Concerto state (ตรงกับ kit ที่ Robin เข้าสู่สถานะพิเศษ) · **ต้องเรียก `Update_Max_atv` แล้ว `resetTurn` เสมอหลังแก้ `baseSpeed`** ไม่งั้น action value ไม่ถูกคำนวณใหม่

> `Reset_List` ตั้ง `baseSpeed = 102` ไว้ด้วย (103) เป็นการกันค่าค้างจากรอบก่อน

## รากฐาน: บังคับคริติคอลคงที่ด้วยการสลับ stat ชั่วคราว

```cpp
ptr->Stats_type[CR][AType::None] += 100;                      // คริแน่นอน
x1 = ptr->Stats_type[CD][AType::None];                        // จำค่าเดิม
x2 = enemyUnit[Main_Enemy_num]->Stats_type[CD][AType::None];
ptr->Stats_type[CD][AType::None] = 150;                       // ตั้งเป็นค่าคงที่
enemyUnit[Main_Enemy_num]->Stats_type[CD][AType::None] = 0;   // ล้างฝั่งศัตรู
Attack(newAct);
... คืนค่าทั้งสามอย่าง
```
Additional DMG ของ Robin ตาม kit คริติคอลเสมอที่ 150% **ไม่ขึ้นกับ CD จริง** → ต้องเขียนทับทั้งของตัวเองและ **ของศัตรู** (ซึ่งมีช่อง CD ที่เข้าสูตรด้วย) แล้วคืนให้ครบ · **เป็นการเขียนทับ stat ชั่วคราวที่กว้างที่สุดในโปรเจกต์** — สำนวนพื้นฐานเดียวกับ `../Nihility/Black Swan.md` แต่ที่นี่ต้อง save/restore แทนการบวก/ลบ

## จุดที่ควรระวัง

- **`All_Action_forward(100)`** (90) — ดัน action bar ของ **ทุกคน** 100% เป็นฟังก์ชันที่มีที่เดียวในโปรเจกต์
- **ก้อน `addUltCondition` ที่ 2 กับ 3 ทับซ้อนกัน** (44-65) — ก้อน 2 มีสาขา `AlwaysPull` ที่เช็ค `driver->getATV() > dps->getATV()` แล้วก้อน 3 เช็ค `driver->getATV() < dps->getATV()` สำหรับ `AlwaysPull` เหมือนกัน → **สองเงื่อนไขนี้ขัดกันเอง** ถ้า `driver` กับ `dps` มี atv ต่างกัน จะมีก้อนหนึ่งเป็นเท็จเสมอ → **กด ult ไม่ได้เลยในโหมด `AlwaysPull`** เว้นแต่ atv เท่ากันพอดี
- **`Stats_Adjust_List` ไม่ guard `AdjustCheck`** (152-161) — `buffAllAlly` ข้างในลง `FLAT_ATK` ซึ่งอาจย้อนกลับมายิง `StatsAdjust` ของ Robin เองได้ถ้า Robin อยู่ใน `allyList` · ที่รอดเพราะ guard บรรทัด 153 เช็คชื่อ และ `AType::TEMP` ถูกหักออกใน `calculateAtkForBuff`
- **`When_attack_List` ไม่ guard ผู้โจมตี** (127) → ได้ energy และยิง Additional DMG ทุกครั้งที่ **ใครก็ตาม** โจมตี รวมถึง DoT/additional ของตัวเอง — ตรงกับ kit สำหรับ Talent แต่ energy +2 ต่อ action ทุกก้อนอาจมากเกิน
- **`Skill` ใช้ `setBuffCheck` + `extendBuffTime` แยกกัน** (193-194) แทน `buffSingle(..., ชื่อ, เทิร์น)` ที่ทำให้ในคราวเดียว — ผลเหมือนกันแต่ไม่ตรงกับสำนวนของไฟล์อื่น
- **`Double_Turn(CharUnit*)` ประกาศไว้แต่ไม่มี definition** (9) — forward declaration ที่ไม่มีตัวจริง
- **`countdownList[0]->Turn_func` เรียก `Action_forward(ptr, 100)` นอก `if`** (178) → ดัน Robin 100% แม้ในกรณีที่ countdown ตายอยู่แล้ว
