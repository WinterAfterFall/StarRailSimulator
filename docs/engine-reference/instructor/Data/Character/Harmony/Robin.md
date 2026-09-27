# `src/Defination/Data/Character/Harmony/Robin.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/robin.md` · **ไฟล์ที่มี `addUltCondition` มากที่สุด (4 ก้อน)** และเป็นที่เดียวที่แก้ `baseSpeed` ระหว่างเกม · มี `//temp` (บรรทัด 6)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(102, 160, 160, E, PHYSICAL, HARMONY, "Robin", STANDARD)` | 13 |
| **Basic ATK** | `basicAtk(ptr)` — single 100%/10 | 200-210 |
| **Skill** — ทีม DMG +50% 3 เทิร์น | `skill(ptr)` — `setBuffCheck` + `extendBuffTime("Pinion'sAria", 3)` | 186-198 |
| **Ultimate** — เข้า Concerto state | `ultimateList` — `countdown->summon()` + `baseSpeed = -1` + `allActionForward(100)` | 73-95 |
| Ult — ทีม FLAT_ATK ตาม ATK ของ Robin | `calculateAtkForBuff(ptr, 22.8) + 200` + สำนวน delta `TEMP`/`NONE` | 82-84 |
| Ult — ทีม CD สำหรับ FuA +25 | `buffAllAlly({{Stats::CD, AType::FUA, 25}})` | 86 |
| **Talent** — Additional DMG ทุกครั้งที่ทีมโจมตี (ขณะ Concerto) | `whenAttackList` → `AType::ADDTIONAL` 120% | 127-150 |
| Talent — คริติคอลคงที่ 150% | สลับ `CR`/`CD` ชั่วคราวรอบ `attack` | 137-148 |
| energy จากการโจมตีของทีม | `whenAttackList` → `increaseEnergy(ptr, 2)` | 128 |
| **A-trace** — ทีม CD +20% | `whenOnFieldList` | 117-119 |
| **Technique** | `startWaveList` → energy +5 | 107-111 |
| **Minor traces** | `resetList` (ตั้ง `baseSpeed = 102` กลับด้วย) | 97-105 |
| **E1** — ทีม RESPEN +24 ขณะ Concerto | `if (ptr->eidolon >= 1)` ทั้งตอนเข้าและออก | 87, 175 |
| **E2** — เพื่อน SPD +16% · energy เพิ่ม | `buffAllAllyExcludingBuffer` · `increaseEnergy(ptr, 1)` | 88, 129-131 |
| **จบ Concerto state** | `countdownList[0]->turnFunc` — ถอนบัฟทั้งหมด + คืน `baseSpeed` | 166-180 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — ไม่มี `Pinion'sAria` → Skill ไม่งั้น BA | 28-34 |

## รากฐาน: `addUltCondition` หลายก้อนที่แยกตาม `driverType`

Robin มี 4 ก้อน แต่ละก้อนดูแลสถานการณ์ต่างกัน และ **ทุกก้อนต้องเป็นจริงพร้อมกัน** ถึงจะกด ult:

| ก้อน | บรรทัด | ดูแลอะไร |
|---|---|---|
| 1 | 36-42 | เฉพาะ `DriverType::DOUBLE_TURN` — อย่ากดถ้า driver ใกล้ได้เล่นหรือเป้าที่บัฟ atv = 0 |
| 2 | 44-57 | ถ้า**ไม่ใช่** `ALWAYS_PULL` → เช็คว่าตัวเองกับ memosprite ไม่ได้ atv = 0 · ถ้าใช่ → driver ต้องได้เล่นทีหลัง dps |
| 3 | 59-65 | เฉพาะ `ALWAYS_PULL` — กลับด้านจากก้อน 2 |
| 4 | 67-71 | ต้องไม่อยู่ใน Concerto อยู่แล้ว และต้องมี `Pinion'sAria` ก่อน |

**`driverType` เป็น global ที่บอกรูปแบบทีม** (`DOUBLE_TURN` / `ALWAYS_PULL` / …) — ตัวเดียวกับที่ `../Erudition/The_Herta.md` ใช้ · ก้อน 2 กับ 3 มีเงื่อนไขกลับด้านกันซึ่งอ่านแล้วสับสน (ดูจุดที่ควรระวัง)

## รากฐาน: แก้ `baseSpeed` เพื่อ "หยุดเทิร์น"

```cpp
ULT:              ptr->atvStats->baseSpeed = -1;  updateMaxAtv(...);  resetTurn(...);
countdown จบ:     ptr->atvStats->baseSpeed = 102; updateMaxAtv(...);  resetTurn(...);
```
ตั้ง `baseSpeed` เป็น **-1** ทำให้ Robin ไม่ได้เทิร์นเลยระหว่าง Concerto state (ตรงกับ kit ที่ Robin เข้าสู่สถานะพิเศษ) · **ต้องเรียก `updateMaxAtv` แล้ว `resetTurn` เสมอหลังแก้ `baseSpeed`** ไม่งั้น action value ไม่ถูกคำนวณใหม่

> `resetList` ตั้ง `baseSpeed = 102` ไว้ด้วย (103) เป็นการกันค่าค้างจากรอบก่อน

## รากฐาน: บังคับคริติคอลคงที่ด้วยการสลับ stat ชั่วคราว

```cpp
ptr->statsType[CR][AType::NONE] += 100;                      // คริแน่นอน
x1 = ptr->statsType[CD][AType::NONE];                        // จำค่าเดิม
x2 = enemyUnit[mainEnemyNum]->statsType[CD][AType::NONE];
ptr->statsType[CD][AType::NONE] = 150;                       // ตั้งเป็นค่าคงที่
enemyUnit[mainEnemyNum]->statsType[CD][AType::NONE] = 0;   // ล้างฝั่งศัตรู
attack(newAct);
... คืนค่าทั้งสามอย่าง
```
Additional DMG ของ Robin ตาม kit คริติคอลเสมอที่ 150% **ไม่ขึ้นกับ CD จริง** → ต้องเขียนทับทั้งของตัวเองและ **ของศัตรู** (ซึ่งมีช่อง CD ที่เข้าสูตรด้วย) แล้วคืนให้ครบ · **เป็นการเขียนทับ stat ชั่วคราวที่กว้างที่สุดในโปรเจกต์** — สำนวนพื้นฐานเดียวกับ `../Nihility/Black Swan.md` แต่ที่นี่ต้อง save/restore แทนการบวก/ลบ

## จุดที่ควรระวัง

- **`allActionForward(100)`** (90) — ดัน action bar ของ **ทุกคน** 100% เป็นฟังก์ชันที่มีที่เดียวในโปรเจกต์
- **ก้อน `addUltCondition` ที่ 2 กับ 3 ทับซ้อนกัน** (44-65) — ก้อน 2 มีสาขา `ALWAYS_PULL` ที่เช็ค `driver->getATV() > dps->getATV()` แล้วก้อน 3 เช็ค `driver->getATV() < dps->getATV()` สำหรับ `ALWAYS_PULL` เหมือนกัน → **สองเงื่อนไขนี้ขัดกันเอง** ถ้า `driver` กับ `dps` มี atv ต่างกัน จะมีก้อนหนึ่งเป็นเท็จเสมอ → **กด ult ไม่ได้เลยในโหมด `ALWAYS_PULL`** เว้นแต่ atv เท่ากันพอดี
- **`statsAdjustList` ไม่ guard `adjustCheck`** (152-161) — `buffAllAlly` ข้างในลง `FLAT_ATK` ซึ่งอาจย้อนกลับมายิง `statsAdjust` ของ Robin เองได้ถ้า Robin อยู่ใน `allyList` · ที่รอดเพราะ guard บรรทัด 153 เช็คชื่อ และ `AType::TEMP` ถูกหักออกใน `calculateAtkForBuff`
- **`whenAttackList` ไม่ guard ผู้โจมตี** (127) → ได้ energy และยิง Additional DMG ทุกครั้งที่ **ใครก็ตาม** โจมตี รวมถึง DoT/additional ของตัวเอง — ตรงกับ kit สำหรับ Talent แต่ energy +2 ต่อ action ทุกก้อนอาจมากเกิน
- **`skill` ใช้ `setBuffCheck` + `extendBuffTime` แยกกัน** (193-194) แทน `buffSingle(..., ชื่อ, เทิร์น)` ที่ทำให้ในคราวเดียว — ผลเหมือนกันแต่ไม่ตรงกับสำนวนของไฟล์อื่น
- **`doubleTurn(CharUnit*)` ประกาศไว้แต่ไม่มี definition** (9) — forward declaration ที่ไม่มีตัวจริง
- **`countdownList[0]->turnFunc` เรียก `actionForward(ptr, 100)` นอก `if`** (178) → ดัน Robin 100% แม้ในกรณีที่ countdown ตายอยู่แล้ว
