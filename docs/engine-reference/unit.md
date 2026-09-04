# Engine Reference — `src/Defination/Class/Unit/`

บันทึกความเข้าใจโค้ดโซน **Unit** (คลาสหน่วยในสนามรบ) — ทีละไฟล์ ทุก field / ทุกกลไก
คู่กับ `docs/character-implementation-notes.md` (ฝั่ง "วิธีเขียนตัวละคร") — ไฟล์นี้เน้น "โครงสร้างข้อมูล engine"

สถานะ: 🚧 กำลังทำ
- เสร็จ (ตรวจกับ impl แล้ว): `ActionValueStats.h` · `Unit.h` · `AllyUnit.h`
- บางส่วน (จากการอ่าน `Memosprite_reset` — ยังไม่ไล่ทั้งไฟล์): `Memosprite.h` → ดูหัวข้อ 4.7
- ยังไม่แตะ: `CharUnit.h` · `Enemy.h` · `StatsSet.h`

อัปเดตล่าสุด 2026-09-02 (session ทัวร์โค้ด): แก้ description `extraTurn` / `Type` / `priority` ให้ตรง · เพิ่มหัวข้อ 2.5 (aha) · เติมกลไก freeze ใน 3.5 · เติมหัวข้อ 4.7 (Memosprite) · แก้ `HpAdjust` + rename `Turn_priority` → `nextForwardPriority` ในโค้ด

---

## 0. ภาพรวมโฟลเดอร์

### Include graph
```
Class/Library.h
 └─ Unit/Library.h
     ├─ ActionValueStats.h   ← includes ../include.h → ../../Setting.h (enums, globals)
     ├─ Unit.h               ← includes ActionValueStats.h
     ├─ CharUnit.h           ← includes Memosprite.h
     │   └─ Memosprite.h     ← includes AllyUnit.h
     │       └─ AllyUnit.h   ← includes Unit.h
     ├─ AllyUnit.h
     ├─ Enemy.h              ← includes CharUnit.h  (+ นิยาม DamageSrc::operator<)
     └─ StatsSet.h           ← includes Enemy.h  (+ นิยาม method ที่ประกาศไว้ในคลาส + factory functions)
```
> `Unit/Library.h` `#include "AllyUnit.h"` ซ้ำ 2 บรรทัด (ไม่มีผลเพราะ include guard) — จดไว้ลบทีหลัง

### ลำดับชั้น
```
Unit  ────────────────┬─ AllyUnit ──┬─ CharUnit  (ตัวละครผู้เล่น; owner = this)
 (ถือ ActionValueStats)│             ├─ Memosprite (owner = CharUnit เจ้าของ)
                       │             └─ (summon/countdown ใช้ AllyUnit ดิบ ๆ ผ่าน SetSummonStats/SetCountdownStats)
                       └─ Enemy
```

---

## 1. ระบบ ATV / ลำดับเทิร์น (แนวคิด)

โมเดล "ลู่วิ่งวงกลม": ทุก unit วิ่งบนลู่ ใครเข้าเส้นชัยได้เล่นเทิร์นแล้ววิ่งรอบใหม่ ทุกอย่างเป็น real-time

| ตัวแปร | ความหมาย |
|---|---|
| `atv` (ต่อ unit) | **เวลาที่เหลือ**จนกว่า unit นี้จะได้เทิร์น (นับถอยหลังเข้าใกล้ 0) |
| `Max_atv` (ต่อ unit) | เวลาโดยประมาณต่อ 1 รอบวิ่งของ unit นั้น ณ ความเร็วปัจจุบัน = `10000 / effectiveSpeed` |
| `Current_atv` (global, `Setting.h`) | จำนวน "วินาที" ที่ผ่านไปตั้งแต่เริ่ม simulate (นาฬิกาเดินหน้าอย่างเดียว) |
| `turn` (global `ActionValueStats*`) | unit ที่กำลังเล่นเทิร์นอยู่ตอนนี้ |

`K_const = 10000` (`Trigger_Function.h:10`)
`effectiveSpeed = baseSpeed·(1 + speedPercent/100) + flatSpeed`

> การ debug buff-drift ในหน่วยความจำ ("ดู stats ที่ ATV 1000/2000/…/5000") = ดูตามค่า `Current_atv`

### คำศัพท์: run / wave / game (สำคัญ — โครงลูปใน `Main.h`)

```
Setup()                          // ครั้งเดียว — สร้างตัวละคร + register lambda ทุกตัว
while(1) {                        // ── REROLL LOOP: 1 รอบ = 1 "run" (substats ชุดหนึ่ง) ──
    Reset()                      //   per-run: Basic_reset / Summon_reset / Countdown_reset / Reset_List / Memosprite_reset
    Set_Stats(chars)             //   per-run: ใส่ substats ของ run นี้
    Start_game()                 //   per-run: All_atv_reset + Start_game_List
    for (i = 0; i < Total_wave; i++) {   // ── WAVE LOOP: หลาย wave ต่อ 1 run ──
        Current_atv = 0          //     per-wave
        Start_wave(i)            //     per-wave: (All_atv_reset ถ้า i!=0) + Start_wave_List
        while(1) { Find_turn(); Atv_fix(); Take_action(); }   // turn loop จนกว่า Current_atv > Wave[i]
    }
    Cal_DamageSummary(); printRoundResult();
    if (Reroll_substats()) break;   // ลอง substats ชุดถัดไป หรือหยุด
}
```

| คำ | หมายถึง | อะไร reset ตรงนี้ |
|---|---|---|
| **run** (รอบรัน / iteration ของ reroll loop) | รัน sim ครบ 1 จบ ด้วย substats ชุดหนึ่ง — โปรแกรมทำหลาย run เพื่อวนหา substats ที่ดีสุด | `Reset()` → `Basic_reset` `Memosprite_reset` `Summon_reset` `Countdown_reset` · `nextForwardPriority = 0` |
| **wave** | 1 ยกของศัตรู — 1 run มีได้หลาย wave (`Total_wave`) | `Start_wave` → `All_atv_reset()` (เฉพาะ wave ที่ 2 เป็นต้นไป) + `Start_wave_List` · `Current_atv = 0` |
| **game start** = ต้น run (ก่อน wave 0) | จุดที่ `Reset()` + `Start_game()` รัน | — |

⚠️ **memosprite / summon / countdown reset "ต่อ run" ไม่ใช่ "ต่อ wave"** — ตัวที่ถูก summon ใน wave 0 จะยังอยู่ต่อไป wave 1, 2, … ใน run เดียวกัน

---

## 2. `ActionValueStats.h`

### 2.1 คลาส `ActionValueStats` — ทุก field

| field | ชนิด | ค่าเริ่มต้น | ความหมาย |
|---|---|---|---|
| `baseSpeed` | double | `-1` | ความเร็วฐาน. `<= 0` = **sentinel "ไม่ใช่ตัวเดินเทิร์นเอง"** → `Update_Max_atv` บังคับ `Max_atv = 1e6` → `atv` ค้างใกล้ `1e6` เลยแทบไม่มีทางชนะ `Find_turn` (ตัวที่ไร้เทิร์น / รอเงื่อนไขพิเศษ). `Action_forward` ก็ `return` ทันทีถ้า `baseSpeed <= 0` |
| `flatSpeed` | double | `0` | speed แบน (บวกหลัง %) |
| `speedPercent` | double | `0` | speed % (เก็บเป็นจำนวนเต็ม เช่น `12` = 12%) |
| `atv` | double | `1e6` | เวลาที่เหลือจนได้เทิร์น |
| `Max_atv` | double | `1e6` | เวลา/รอบ ณ ความเร็วปัจจุบัน (คำนวณโดย `Update_Max_atv`) |
| `turnCnt` | int | `0` | **จำนวนเทิร์นที่ unit นี้เล่นไปแล้ว**. `++turn->turnCnt` เกิดใน `take_action` **ก่อน** เช็ค before-turn events. ใช้เป็นฐานเวลาของ buff (`Buff_countdown[name] = turnCnt + duration`) |
| `num` | int | `0` | หมายเลขช่อง **unique เฉพาะในฝั่งตัวเอง** (ally 1..4, enemy 1..5). memosprite/summon/countdown ก๊อป `num` ของเจ้าของ |
| `side` | `Side` | — (⚠️ ไม่ init) | `Ally` `Enemy` `Memosprite` `Summon` `Countdown` — Setup/factory เป็นคนตั้ง |
| `Type` | `UnitType` | — (⚠️ ไม่ init) | `Standard` = ปกติ · `Backup` = อยู่ในสนาม เล่นเทิร์น/บัฟได้ แต่ **enemy ไม่เล็งโจมตี** (`EnemyActionData.h:16,38,62`) เช่น Netherwing (`Castorice.h:15`) · `OutofBounds` = เหมือนนอกสนาม ตี/บัฟไม่ได้ (`isTargetable` + `AllyBuffAction.h:119-130`). เซ็ตครั้งเดียวผ่าน arg สุดท้ายของ `SetCharBasicStats`/`SetMemoStats` — **ยังไม่มีโค้ดเปลี่ยนตอน runtime** (อาจมีในอนาคต) |
| `priority` | int | `0` | ตัวตัดสินเมื่อ `atv` เท่ากัน — สูงชนะ. ถูกเซ็ต `= ++nextForwardPriority` ตอน `Action_forward` ดัน `atv` ของ unit นี้ลงจนแตะ 0 · per-unit `priority` reset ที่ `Basic_reset` (**ต่อ run**) · global counter `nextForwardPriority` reset ที่ `Reset()` (**ต่อ run**) → ภายใน run ที่มีหลาย wave ค่าจะสะสมข้าม wave |
| `Name` | string | `""` | "ชื่อเจ้าของเทิร์น" — **key หลัก**ที่ระบบใช้ค้นทุกที่ (buff map key ด้วยชื่อนี้) |
| `extraTurn` | bool | `false` | **การโจมตีที่ผู้เล่นตัดสินใจเอง (เหมือนเข้าเทิร์น) แต่นับเป็น action แยก** — ไม่ `resetTurn` · ไม่กินเวลาบัฟ (turnCnt ไม่ขยับ) · ไม่แตะ `atv`. เมื่อ `true`: `Take_action` (`Combat.h:10,28`) **ข้าม** `++turnCnt` + before/after-turn events (แต่ `allUltimateCheck` ยังยิง). **ปัจจุบันมีแค่ Phainon ใช้** — set ที่ `Phainon.h:207` (pn) / `:215` (pnCD), เคลียร์เองที่ `Phainon.h:124` · main loop **ไม่เคลียร์ให้** · `Stats_Reset` เคลียร์ทีเดียวตอนต่อ run |
| `charptr` | `Unit*` | `nullptr` | back-pointer กลับไปที่ Unit เจ้าของ (Ally / Enemy / Memosprite / …) เซ็ตใน `Unit()` ctor · **ยกเว้น `aha`** (`Setting.h:80`) สร้างจาก `ActionValueStats` ตรง ๆ ไม่ผ่าน `Unit` → `charptr == nullptr` โดยตั้งใจ = สัญญาณว่าเป็น pseudo-unit (`Take_action` เห็น `!turn->charptr` → เรียก `AhaTurn()`) ดูหัวข้อ 2.5 |

**Constructors:** `()` · `(name)` · `(name, speed)`

**Methods (ในคลาส):** get/set ครบทุก field · `isSameName(str)` `isSameNum(int)` · (นิยามภายนอกใน `Unit.h`) `isSameUnit(Unit*)` `isSameNum(Unit*)` · `canCastToAllyUnit()` `canCastToEnemy()` · `speedBuff(%, flat)` `resetATV()` `resetATV(baseSpeed)` (นิยามใน `Action_value.h`)

### 2.2 ฟังก์ชันระบบ ATV (`src/Defination/Function/Combat/Action_value.h`)

| ฟังก์ชัน | หน้าที่ |
|---|---|
| `Update_Max_atv(ptr)` | `Max_atv = 10000 / effectiveSpeed` · ถ้า `baseSpeed <= 0` → `Max_atv = 1e6` (ไม่วิ่ง) |
| `resetTurn(ptr)` | `atv = Max_atv` (เริ่มวิ่งรอบใหม่เต็ม ๆ) |
| `resetATV()` / `resetATV(baseSpeed)` | `Update_Max_atv` + `resetTurn` (ตั้ง baseSpeed ใหม่ถ้าส่งมา) |
| `All_atv_reset()` | ทำ `Update_Max_atv`+`resetTurn` ให้ทุกตัวใน `atvList` |
| `ActionValueStats::speedBuff(spd%, flatSpd)` | บวก `speedPercent`/`flatSpeed` → `Update_Max_atv` → **rescale `atv` ตามสัดส่วน** `atv = atv/oldMax * newMax` (คง % ความคืบหน้าบนลู่) |
| `Action_forward(ptr, fwd)` | **action advance**: ลด `atv` ลง `Max_atv * fwd/100`. ถ้าเลย 0 → `atv = 0` + `priority = ++nextForwardPriority`. ข้ามถ้า `baseSpeed<=0` หรือ unit ตาย |
| `All_Action_forward(fwd)` | forward ทุก ally — sort จาก `atv` มาก→น้อยก่อน (ตัวใกล้เทิร์นได้ priority ท้ายสุด = สูงสุด = เล่นก่อน) |
| `Atv_fix(reduce)` | **นาฬิกาเดินหน้า**: ทุกตัวใน `atvList` (ที่ `isAtvChangeAble`) ลด `atv` ลง `reduce` · `Current_atv += reduce` |
| `Find_turn()` | หา unit ที่ `atv` ต่ำสุด (ข้าม `!isAtvChangeAble`) → เซ็ต global `turn`. เสมอ → `priority` สูงกว่าชนะ |
| `compareActionValueStats(a,b)` | `a->atv > b->atv` (เรียงมาก→น้อย) |
| `ahaSpeedAdjust(path)` | เฉพาะทีม Elation (Aha) — ปรับ flatSpeed ของ `aha` ตาม speed ของสมาชิก Elation |

**กติกา priority ที่ยืนยันแล้ว:**
- forward จาก **สกิลเดียวกัน พร้อมกัน** → ตัวที่ใกล้ได้เทิร์นอยู่แล้วเล่นก่อน (มาจากการ sort ใน `All_Action_forward`)
- ถ้า A `atv=0` ค้างอยู่ (ยังไม่เข้าเทิร์น) แล้วมีตัวใหม่ถูก forward จน `atv=0` → **ตัวใหม่แซงขึ้นนำ** (priority ใหม่สูงกว่า)

**`nextForwardPriority`** (global, `Setting.h:87`, เดิมชื่อ `Turn_priority`) = ตัวนับที่แจกค่า `priority` ให้ unit ตัวถัดไปที่โดน `Action_forward` จน atv แตะ 0 — เพิ่มอย่างเดียว (`++`) reset เป็น 0 **ต่อ run** ที่ `Reset()` (`SetCombat.h`)

> **speedBuff บน unit ที่ `baseSpeed <= 0`:** unit ที่ baseSpeed ติดลบ **ไม่ได้ถูกห้ามรับบัฟ** — แต่ `speedBuff` บวก `flatSpeed`/`speedPercent` เข้าไปแล้ว `Update_Max_atv` เจอ `baseSpeed <= 0` `return` ก่อน → `Max_atv` ค้าง `1e6` บัฟสปีดเลยไม่มีผลจนกว่าจะมี `resetATV(สปีดบวก)`. ในทางปฏิบัติ **countdown / summon รับบัฟสปีดไม่ได้อยู่แล้ว** (เป็น `unique_ptr<Unit>` ส่งเข้า `buffSingle(AllyUnit*)` ไม่ได้ + ไม่อยู่ใน `allyList`) และ**ไม่มีโค้ดไหนแจกบัฟสปีดให้ countdown** → เคสนี้เกิดไม่ได้. **แผนอนาคต:** refactor ให้ countdown/summon เป็นแค่ `ActionValueStats` (atv ล้วน ๆ ไม่ใช่ `AllyUnit`) → ปัญหานี้ + `owner==nullptr` หายไปเอง (ดู [`future-improvements.md`](future-improvements.md))

### 2.3 `BuffClass` / `BuffElementClass` — payload มาตรฐานของการ `+stat`

```cpp
class BuffClass        { Stats statsType; AType actionType;                double value; };
class BuffElementClass  { Stats statsType; ElementType element; AType actionType; double value; };
```

คือ **รูปแบบมาตรฐาน** ของ "คำสั่งเพิ่ม/ลด stat" ทั้งเกม ส่งเป็น `vector<...>` เข้าฟังก์ชันตระกูล `buff*`
(`buffSingle` `buffSingleChar` `buffAllAlly` `buffAllMemosprite` `buffTargets` `buff*ExcludingBuffer` …ใน `Buff_Stats.h`)

**"delta" = `value`** — ปริมาณ stat ดิบ (เช่น `55` = ATK +55%). ปลาย ๆ ทาง:
- speed (`FLAT_SPD`/`SPD_P`) → เรียก `ptr->speedBuff(buff)` + `ahaSpeedAdjust`
- นอกนั้น → `ptr->Stats_type[statsType][actionType] += value`
- element version → `ptr->Stats_each_element[statsType][element][actionType] += value`
- ถ้า `actionType == None` → เรียก `StatsAdjust(ptr, statsType)` ต่อ (re-trigger `Stats_Adjust_List`)

**apply / remove ใช้ค่าคงที่ตัวเดียวกัน กันเลื่อน** (แพตเทิร์น Tingyun):
```cpp
constexpr double BENEDICTION_ATK = 55;
buffSingle(target, {{Stats::ATK_P, AType::None,  BENEDICTION_ATK}}, "Tingyun Benediction", 3); // ลง
buffSingle(target, {{Stats::ATK_P, AType::None, -BENEDICTION_ATK}});                           // ถอน
```

**2 โหมดของ `buffSingle`:**
| รูปแบบ | พฤติกรรม |
|---|---|
| `buffSingle(u, {…})` ไม่มีชื่อ | บวก stat **ทันที ถาวร ไม่ track** — ใช้ตอน "ถอนบัฟ" (ใส่ค่าลบ) |
| `buffSingle(u, {…}, "Name", extend)` | ผ่าน `isHaveToAddBuff`: `extendBuffTime` (refresh timer ทุกครั้ง) → ถ้า `Buff_check["Name"]` เป็น 1 อยู่แล้ว **ไม่บวกซ้ำ** (re-cast = ต่อเวลา ไม่ stack) |

### 2.4 โมเดล `Stats_type` / `Stats_each_element` (นิยาม typedef ที่ `Enum.h` ท้ายไฟล์)

```cpp
typedef unordered_map<Stats, unordered_map<AType,double>>                               Common_stats_type;
typedef unordered_map<Stats, unordered_map<ElementType, unordered_map<AType,double>>>   Common_stats_each_element;
```

**`Stats_type[X][AType]`:**
| key | ความหมาย |
|---|---|
| `[X][None]` | ค่ามาตรฐานของ stat X — ใช้กับ **ทุก** การกระทำ (`calculate*OnStats` อ่านตัวนี้ตรง ๆ) |
| `[X][Fua]` / `[X][Ult]` / `[X][SKILL]` / … | โบนัส X **เฉพาะ**เมื่อ action มี AType นั้นใน `damageTypeList` (เช่น "+CD เฉพาะ FUA") — `calAtkMultiplier` ฯลฯ วนบวกทีละ type |
| `[X][TEMP]` | **บัญชีเงา** = ส่วนของ `[X][None]` ที่มาจากบัฟที่ scale ตาม stat → `calculate*ForBuff()` เอา `[None] - [TEMP]` เพื่อ **กันลูปบัฟ** (Robin บัฟ ATK ตาม ATK ตัวเอง / Cerydra↔Robin) |

- ใครเซ็ต `TEMP`: **เขียนเองในตัวละคร** — ตัวที่ push เข้า `Stats_Adjust_List` (บัฟแบบ scale-ตาม-stat) จะบวกทั้ง `[None]` และ `[TEMP]` เท่ากัน
- `TEMP` ถูกลด/ล้างเมื่อ: (ก) `Stats_Reset` ก่อนเริ่มรอบคำนวณ substats ใหม่ (โปรแกรมวนหา substats ที่ดีสุด) (ข) เมื่อ `[None]` ที่ได้จากบัฟนั้นลดลง `TEMP` ก็ลดตาม (ค) บัฟหมดอายุ → ถอนทั้ง `[None]` และ `[TEMP]`

**`Stats_each_element[X][element][AType]`:** มิติ `element` ใช้จริงกับ **`Stats::DMG` และ `Stats::RESPEN`** เท่านั้น (`calBonusDmgMultiplier` / `calRespenMultiplier` อ่าน `act->Damage_element`) — บัฟ "DMG เฉพาะธาตุน้ำแข็ง" ตัวละครไฟจะเอาไปใช้ไม่ได้

### 2.5 `aha` — pseudo-unit ของทีม Elation

`aha` (`Setting.h:80`) = `unique_ptr<ActionValueStats>` ชื่อ `"Aha"` speed 80 — สร้างจาก `ActionValueStats` ตรง ๆ **ไม่มี object `Unit`** อยู่เบื้องหลัง → `charptr` เป็น `nullptr` ตลอด

- **วิ่งอยู่บนลู่ atv แย่งเทิร์นกับตัวละครจริง** — ถูก push เข้า `atvList` ที่ `SetCombat.h:65` **เฉพาะเมื่อ `elationCount != 0`** (มีสมาชิก Elation ในทีม)
- **ไม่มีตัวตนในสนาม** — ไม่มี HP / ไม่โดนตี / ไม่โดนบัฟ. หน้าที่เดียว = trigger `AhaInstant` ตามเวลาที่ atv พามันถึงเทิร์น
- พอ `aha` ชนะ `Find_turn` → `turn->charptr == nullptr` → `Take_action` (`Combat.h:5`) แตกไป `AhaTurn()` (`Combat.h:31`): `++aha->turnCnt` → `BeforeAhaInstant()` → วน `ElationSkill_List` → drain `AhaInstantBar` → แจกบัฟ `CertifiedBanger` ให้สมาชิก Elation → `AfterAhaInstant()` → `resetTurn(aha)` (เริ่มนับรอบใหม่)
- speed ของ `aha` ปรับด้วย `ahaSpeedAdjust(path)` (`Action_value.h:93`) — คิดจาก speed ของสมาชิก Elation ที่เรียงมากไปน้อย: `flatSpeed = spd₁/5 + spd₂/10 + spd₃/15 + …`

> ⚠️ ตาราง 2.1 บอก `charptr` "เซ็ตใน `Unit()` ctor เสมอ" — จริงสำหรับทุกตัว **ยกเว้น `aha`** ที่ตั้งใจให้เป็น null

---

## 3. `Unit.h`

`class Unit` — base ของทุกหน่วยในสนาม (ถือ `ActionValueStats`, ไม่มี HP/ATK — พวกนั้นอยู่ที่ `AllyUnit`/`Enemy`)

### 3.1 ทุก field

| field | ชนิด | ความหมาย |
|---|---|---|
| `Atv_stats` | `unique_ptr<ActionValueStats>` | สร้างใน ctor · `Atv_stats->charptr = this` |
| `Turn_func` | `function<void()>` | **สิ่งที่หน่วยทำเมื่อถึงเทิร์น** — เซ็ตต่อหน่วย (char: `ptr->Turn_func` · summon/countdown/memosprite: `xxxList[i]->Turn_func` · enemy: `SetEnemy.h:38`). สัญญา: ต้องจบด้วย `act->addToActionBar()` เสมอ |
| `Stats_each_element` | `Common_stats_each_element` | `map<Stats, map<ElementType, map<AType,double>>>` — DMG%/RESPEN แยกตามธาตุ (ดู §2.4) |
| `Stats_type` | `Common_stats_type` | `map<Stats, map<AType,double>>` — ตารางสเตตัสรวม (ดู §2.4). **Enemy ก็มี** → debuff (DEF shred / Vul / RES pen) = entry บวกใน `enemy->Stats_type` ที่สูตรดาเมจเอาไปรวมกับฝั่ง attacker |
| `status` | `UnitStatus` | `Alive` `Death` `AtvFreeze` `Retire` (⚠️ ไม่ init ใน ctor — Setup/Reset เป็นคนตั้ง) |

### 3.2 `UnitStatus` (`Enum.h:27`)

| ค่า | `isAtvChangeAble` | `isExsited` | `isTargetable` | ใช้โดย |
|---|:-:|:-:|:-:|---|
| `Alive` | ✅ | ✅ | ✅ | ปกติ |
| `Death` | ❌ | ❌ | ❌ | ตาย |
| `AtvFreeze` | ❌ | ✅ | ✅ | **Phainon เท่านั้น** — ตัวเอง + freeze summon อื่นระหว่าง ult (act ผ่าน `extraTurn` ไม่ผ่าน `Find_turn`) |
| `Retire` | ❌ | ❌ | ❌ | **Phainon เท่านั้น** — ally อื่นระหว่าง ult (atv แช่แข็งจริง — comment ที่ว่า "atv เคลื่อนปกติ" ผิด) |

- `isAtvChangeAble()` = false เมื่อ `Death | AtvFreeze | Retire` → `Atv_fix()` และ `Find_turn()` **ข้าม**
- `isExsited()` = false เมื่อ `Death | Retire` (typo: ควรเป็น `isExisted`)
- `isTargetable()` = false เมื่อ `Death | Retire | Type==OutofBounds`

### 3.3 methods

- **wrappers** ทะลุไป `Atv_stats`: `get/setBaseSpeed` `getATV` `getMaxATV` `getTurnCnt` `getNum` `getSide` `getType` `getName` …
- **check**: `isSameUnit(Unit*)` `isSameName(str)` `isSameNum(int/Unit*)` `isAlive` `isDeath` `isAtvChangeAble` `isExsited` `isTargetable`
- `speedBuff(BuffClass)` — `FLAT_SPD` → `speedBuff(0, value)` · อื่น ๆ **ทั้งหมดถือเป็น %** → `speedBuff(value, 0)`
- `resetATV()` / `resetATV(baseSpeed)` → `Atv_stats`
- `summon()` — `status = Alive` + `resetATV()` · `death()` — `status = Death` (Unit base)
- `canCastToSubUnit()` = `dynamic_cast<AllyUnit*>(this)` (ชื่อกำกวม จริง ๆ คือ "cast → AllyUnit", null ถ้าเป็น Enemy) · `canCastToEnemy()` = `dynamic_cast<Enemy*>(this)`
  - ⚠️ อย่าสับสนกับ `ActionValueStats::canCastToAllyUnit()/canCastToEnemy()` (`TargetChoose.h:3-8`) ที่ cast `charptr` — ใช้บน global `turn`
  - ⚠️ **`turn->canCastToAllyUnit()` คืน non-null ตอนเทิร์นของ Memosprite ด้วย** — `charptr` ของ memo ชี้ตัวเอง และ `Memosprite : AllyUnit` → cast ผ่าน. โค้ด ult-check / before-turn ที่เขียน `AllyUnit *ally = turn->canCastToAllyUnit(); if(ally)…` จะทำงานตอนเทิร์น memo เหมือนเทิร์น character (เช่น `Huohuo.h:95-110` Divine Provision กิน stack + ฮีล memo ที่กำลังเล่นเทิร์น). ระวังโค้ดที่สมมติว่า `ally` เป็น character แน่ ๆ แล้วไปอ่าน `Current_energy` / field ที่ memo ไม่มี

### 3.4 `death()` 2 เวอร์ชัน

| | โค้ด | ยิง event? | ใช้กับ |
|---|---|:-:|---|
| `Unit::death()` | `status = Death` | ❌ | enemy · summon · countdown |
| `AllyUnit::death()` (`ChangeHP.h:179`) | `currentHP = 0` · `status = Death` · `allEventWhenAllyDeath(this)` | ✅ `AllyDeath_List` | ally / char / memosprite |

### 3.5 `Turn_Skip` (global bool, `Setting.h:72`)

บังคับข้ามเทิร์น (CC เช่น Freeze) — `Take_action()`: `if(Turn_Skip==0){ Turn_func(); Deal_damage(); }`
- ตั้ง = 1: `Event.h:19` (enemy โดน Freeze กินเทิร์น) · `Ruan_Mei.h:104`
- reset = 0: ทุกรอบ loop (`Main.h:46` / `ManualBuilder.cpp:155`)
- before/after-turn events **ยังยิงปกติ** — ข้ามแค่ action (รวมทั้ง `allUltimateCheck` 2 จุดใน `Take_action` ก็ยังยิง)

**enemy ที่โดน freeze ทำไมไม่โดน `Find_turn` เลือกซ้ำทันที** (atv มันยัง ~0 อยู่) — คำตอบอยู่ที่ `Event.h:13-22` ใน `allEventBeforeTurn` (`side == Enemy`): ถ้าเจอ entry ใน `breakFrzList`
1. `Cal_Freeze_damage` — คิดดาเมจ freeze
2. **`Action_forward(enemy->Atv_stats.get(), -50)`** — `fwd` ติดลบ → เข้า else branch ของ `Action_forward` → `atv = atv - Max_atv*(-50)/100` = **`atv += 0.5 * Max_atv`** (ดัน atv ถอยหลังครึ่งบาร์)
3. `Turn_Skip = 1`
4. `breakFrzList.erase(itr)` + `break`

ขั้นที่ 2 คือกลไกที่ทำให้ enemy เลื่อนออกจากตำแหน่ง "ตัวถัดไป" — ไม่งั้น loop วนเลือกมันซ้ำไม่จบ. รอบหน้า freeze ถูกลบไปแล้ว → เล่นเทิร์นปกติ

---

## 4. `AllyUnit.h`

`class AllyUnit : public Unit` — base ของ `CharUnit` / `Memosprite` และเป็นชนิดที่ `SetSummonStats`/`SetCountdownStats` ใช้ดิบ ๆ
macro ในไฟล์: `#define endl '\n'` · `F`=`first` · `S`=`second` · `DMG_CAL 12`

### 4.1 stats fields

| field | เขียนโดย | อ่านโดย |
|---|---|---|
| `baseAtk` `baseHp` `baseDef` | `SetAllyBaseStats(hp,atk,def)` (บวกสะสม) + minor trace hardcode | สูตรดาเมจ (`calAtkMultiplier` ใช้ `baseAtk` + `Stats_type`) |
| `baseTaunt` | `SetCharBasicStats` / `SetMemoStats` = `tauntValueEachPath[path]` | §4.3 |
| `Element_type` | `vector<ElementType>` — **push ครั้งเดียวเสมอ (size 1)**. TODO: เปลี่ยนเป็น `ElementType` เดี่ยวไปก่อน ค่อยกลับมาทำ multi-element ทีหลัง | |
| `totalATK` `totalHP` `totalDEF` | **cache** ของ `calculate*OnStats()` — เขียนที่ `SetCombat.h:101` (ต้นรบ) + ทุกครั้งบัฟ `AType::None` ผ่าน `StatsAdjust()→{Atk,Hp,Def}Adjust` (`AdjustStats.h`) | abilities ที่ scale ตาม totalHP/ATK · requirement check · print · `HpAdjust` ใช้ปรับ `currentHP` เมื่อ maxHP เปลี่ยน · **สูตรดาเมจไม่อ่าน** (recompute เอง) |
| `currentHP` | `IncreaseCurrentHP` / `DecreaseCurrentHP` (clamp `[1, totalHP]`) · `HpAdjust` (`AdjustStats.h`) — กติกา: **maxHP เพิ่ม x → currentHP เพิ่ม x** · **maxHP ลด → currentHP คงเดิม** เว้นแต่ลดจนต่ำกว่า currentHP → clamp ลงมาเท่า maxHP. _(แก้ 2026-09-02 — โค้ดเดิมหัก currentHP ตาม delta ทุกกรณีที่ maxHP ลด แม้ currentHP ยังไม่ชนเพดานใหม่ → เป้าเสีย HP ฟรีเวลาบัฟ maxHP หลุด)_ | |
| `currentSheild` | **ไม่มีโค้ดไหนเพิ่มค่า** — ระบบโล่ยัง stub. reset = 0 เท่านั้น (`Stats_Reset.h:38`) | `decreaseSheild` (ดู 🐞) |
| `hitCount` | `Attack()` (`Combat.h`): reset 0 ต้นฟังก์ชันสำหรับทุก attacker/target → `+= damageSplit[i].size()` ต่อ hit-beat (attacker) / `++` ต่อ target | per-hit / after-attack event triggers · เช่น `Grand_Duke.h:22` (relic DoT bonus นับ hit) |
| `taunt` `tauntIncrease` `owner` | §4.3 / §4.4 | |

### 4.2 buff bookkeeping maps (ดูรายละเอียด lifecycle ที่ `character-implementation-notes.md` §4)

`Stack` `Buff_note` `Buff_countdown` `Buff_check` (`map<string,…>`) · `buffSubUnitTarget` (`map<string,AllyUnit*>`) · `buffAllyTarget` (`map<string,CharUnit*>`)
= สมุดบันทึก per-unit key ด้วย **ชื่อบัฟ (prefix ชื่อตัวละคร)** — framework track แค่ `Buff_check`(bool) + `Buff_countdown`(turnCnt เป้าหมาย) ไม่เก็บขนาด delta

- `Buff_countdown[name] = ptr->turnCnt + extend` (`Buff_Stats.h:40`) — ใช้ `turnCnt` ของ **unit ที่ entry นี้อยู่** (ปกติ = เป้าหมาย). บัฟแบบ relay (เช่น Robin skill E บัฟตัวเอง แล้วผลของมันไปเพิ่มดาเมจทั้งทีม) → entry อยู่บน Robin → นับเทิร์น Robin
- framework **ไม่ถอนค่า stat ให้เอง** ตอนบัฟหมด — ตัวละครต้องเขียน `After_turn_List` เช็ค `isBuffEnd` แล้ว `buffSingle(-v)` เอง (pattern Tingyun) → ดู [`future-improvements.md`](future-improvements.md) ข้อ 1 + [`character-implementation-notes.md`](../character-implementation-notes.md) หัวข้อ 4

### 4.3 taunt / การเลือกเป้าของ enemy

> **Concept ของ enemy basic (single-target) attack** — ไม่ได้จำลอง "1 การโจมตี = โดน 1 ตัว" ให้ตรงเกมจริง · เป้าหมายคือ (ก) จำลอง **energy** ที่ ally ได้จากการโดนตี (ข) จำลอง **การเสีย HP** เพื่อจุดชนวน mechanic ที่ผูกกับการโดนโจมตี (Blade / Clara / Mydei / Fu Xuan redistribution / Preservation counter / Meshing Cogs …) · สิ่งที่ต้องถูกคือ **จำนวนครั้งที่แต่ละตัวโดนตีต่อ N เทิร์น ≈ `N · taunt_i / Σtaunt`** — ไม่สนว่าการโจมตีเดียวจะโดน 0/1/หลายตัว

**field** (ระบบ taunt: `baseTaunt` + `tauntIncrease` → `taunt` → `Σ taunt ของ pool`)
| field | ที่อยู่ | ค่า |
|---|---|---|
| `baseTaunt` | AllyUnit | `tauntValueEachPath[path]` — Preservation 150 · Destruction 125 · Abundance/Harmony/Nihility/Remembrance/Elation 100 · Hunt/Erudition 75 (`Setting.h:50`) · เซ็ตที่ `StatsSet.h:27,52` |
| `tauntIncrease` | AllyUnit | **% เพิ่ม** (0 = ไม่มี) · `Stats_Reset` reset `= 0` ต่อ run · เพิ่มผ่าน `tauntIncreaseChange(+X)` เท่านั้น |
| `taunt` | AllyUnit | ค่า aggro จริง = `baseTaunt · (1 + tauntIncrease/100)` · `Stats_Reset` ตั้ง `= baseTaunt` ตรง ๆ (เท่ากับตอน `tauntIncrease=0`) · `tauntIncreaseChange` recompute |
| `tauntList` | **Enemy** | `vector<AllyUnit*>` — forced taunt (ดึง aggro บังคับ) |
| `AttackCoolDown` | **Enemy** | `map<string,double>` — ตัวสะสม weighted round-robin ต่อชื่อ ally |

**`calHitChance(vector<AllyUnit*> pool)`** (`AllyUnit.h:71`) = `taunt / Σtaunt(pool) * 100` — คำนวณ `Σtaunt` จาก pool สด ๆ ทุกครั้ง · **ตัวเดียวในระบบ** (no-arg version + `totalTaunt` global ลบทิ้งแล้ว 2026-09-04)

**การเลือกเป้าของ enemy basic attack** (`EnemyActionData::setBaAttack`)
1. สร้าง `pool`:
   - `tauntList` ไม่ว่าง → `pool` = สมาชิก `tauntList` ที่ `isTargetable()` และไม่ใช่ `Backup`
   - ไม่งั้น → `pool` = ทุกตัวใน `allyList` ที่ `isTargetable()` และไม่ใช่ `Backup` (รวม memosprite)
2. วน `pool`: `AttackCoolDown[name] += each->calHitChance(pool)` → ถ้า `>= 100` : `-= 100` + unit นั้นโดนเลือกในเทิร์นนี้ (ได้ energy + [ควร] โดนดาเมจ) · ถ้า `< 100` : `continue`
   → **deterministic weighted round-robin** (error-diffusion แบบ Bresenham) ไม่ใช่สุ่ม · แต่ละตัวสะสมที่อัตรา `calHitChance_i` ต่อโจมตี → โดนเลือกทุก ๆ `100/calHitChance_i` โจมตี → ต่อ N โจมตี โดน `N · taunt_i/Σtaunt` ครั้ง
   - **หลายตัวข้าม 100 พร้อมกันในโจมตีเดียว = ปกติตามดีไซน์** (ทีมสมมาตร taunt เท่ากัน → ทุก ๆ 4 โจมตีโดนพร้อมกัน 4 ตัว, 3 โจมตีระหว่างนั้นไม่โดนใคร — aggregate ต่อ N ยังถูก) · ไม่ใช่บั๊ก
   - **ไม่มี `break`** — ทุกตัวที่ข้าม 100 ในโจมตีนั้นถูกเลือกหมด
3. `Stats_Reset.h:145` วน `AttackCoolDown` reset เป็น 0 (**ต่อ run** — ไม่ reset ระหว่าง wave, เศษ aggro ค้างข้าม wave = ตั้งใจ ให้ error-diffusion ต่อเนื่อง)

**enemy AoE** (`setAoeAttack`) — วน `allyList` ทุกตัว (targetable, non-Backup) **โดนหมด ไม่สน taunt** · ให้ energy + ดาเมจทุกตัว

**cadence single vs AoE** (`SetEnemy.h:48`) — enemy ทำ `action` sub-action/เทิร์น · แต่ละครั้ง `++AoeCharge` · เป็น AoE เมื่อ `AoeCoolDown != 0 && AOEratio != 0 && AoeCharge % AoeCoolDown == AoeStart` ไม่งั้น single · ถ้าเทิร์นก่อนโดน break (`Toughness_status == 0`) → เทิร์นนี้ฟื้น toughness ก่อน (บันทึก broken time)

**`addTaunt`/`removeTaunt`** (`EnemyCombat.h:13`) — `addTaunt` มี **dedup** (เช็คชื่อก่อน push) · `removeTaunt(AllyUnit*)` erase ตัวแรกที่ชื่อตรง · _(`removeTaunt(string)` ลบทิ้งแล้ว 2026-09-04 — ไม่มี caller)_

**Mydei_Taunt lifecycle** (ตัวอย่าง forced-taunt ที่มีวันหมด, แยกอิสระต่อ enemy) — `Mydei.h`:
- ult (Blast) : ต่อ enemy ในเป้า → `debuffApply(ptr,e,"Mydei_Taunt",2)` (2 เทิร์น) + `e->addTaunt(Mydei)`
- technique (`Start_game_List`, AoE) : ต่อ enemy ทุกตัว → `debuffApply(ptr,e,"Mydei_Taunt",1)` (1 เทิร์น) + `e->addTaunt(Mydei)`
- `debuffApply` 4-arg refresh countdown เสมอ · `addTaunt` มี dedup ในตัว
- `After_turn_List` : เทิร์น enemy → `isDebuffEnd(e,"Mydei_Taunt")` จริง → `e->removeTaunt(Mydei)` — **ถอด Mydei ออกจาก tauntList ของ e ตัวนั้นตัวเดียว**
- แต่ละ enemy อิสระเต็มที่: A ครบเทิร์น → A เลิกบังคับตี Mydei ทันที แม้ B ยังบังคับอยู่
- enemy ในเกมนี้ **ไม่มี HP ไม่ตาย** → ไม่ต้องกันเคส "enemy ตายทั้งที่ยังติด taunt"

**taunt increase% (feature ที่ต่อสายไว้ให้)** — `tauntIncreaseChange(double value)` (`AllyUnit.h:62`):
```cpp
void tauntIncreaseChange(double value){ tauntIncrease += value; taunt = baseTaunt * (1 + tauntIncrease/100.0); }
```
trace "taunt +X%" → เรียก `ptr->tauntIncreaseChange(X)` (`value` = X ตรง ๆ) → `taunt = baseTaunt · (1 + X/100)` · **ยังไม่มี caller** — พร้อมใช้
> ⚠️ ถ้าเพิ่ม taunt ให้ **memosprite** ต้องเรียกใน `WhenOnField_List` (หลัง `Memosprite_reset`) ไม่ใช่ `Reset_List` — ไม่งั้น `Memosprite_reset` reset `tauntIncrease=0` / `taunt=baseTaunt` ทับ (ดูหัวข้อ 4.7)

- ✅ `UnitGotHit` populate แล้ว (2026-09-02, `EnemyActionData.h:47,72`) — enemy single-target ลงดาเมจจริง → ดู 🐞 #11

### 4.4 `owner`

| unit | `owner` ตั้งโดย | ค่า |
|---|---|---|
| `CharUnit` | `CharUnit()` ctor | `this` |
| `Memosprite` | `SetMemoStats` (`StatsSet.h:51`) | `CharUnit` เจ้าของ |
| summon / countdown (`SetSummonStats`/`SetCountdownStats`) | **ไม่มีใครตั้ง** | `nullptr` → ดู 🐞 #8 |

> จุดเสี่ยง null-deref: `buffSingle` (`Buff_Stats.h:88,99`) path บัฟ speed ทำ `ahaSpeedAdjust(ptr->owner->path[0])` — ถ้า `ptr` เป็น summon/countdown (`owner == nullptr`) = crash. **ปัจจุบันเกิดไม่ได้** เพราะ summon/countdown เป็น `unique_ptr<Unit>` ส่งเข้า `buffSingle(AllyUnit*)` ตรง ๆ ไม่ได้ + ไม่อยู่ใน `allyList`.
> **ทางแก้ที่ user เลือก** (2026-09-02): ไม่ปะจุดเดียว — อนาคต refactor summon/countdown ให้เป็นแค่ `ActionValueStats` (ไม่ใช่ `AllyUnit`) → ไม่มี field `owner` ตั้งแต่แรก → ดู [`future-improvements.md`](future-improvements.md) หัวข้อ 3

### 4.5 targeting nums

`defaultCharNum = Main_dps_num` · `defaultMemoNum = 0` · `currentCharNum` / `currentMemoNum` · `Enemy_target_num = Main_Enemy_num`
- `current*` = "ตอนนี้ unit นี้เล็งบัฟไปที่ ally/memosprite ตัวไหน" · `currentCharNum` reset กลับเป็น `defaultCharNum` ที่ `Stats_Reset.h:34`
- 🐞 **`currentMemoNum` ไม่เคย reset** — `Stats_Reset.h:35` + `:260` เขียน `currentMemoNum = currentMemoNum` (assign ตัวเอง = no-op) บรรทัดข้างบนคือ `currentCharNum = defaultCharNum` → บรรทัดนี้ตั้งใจจะเป็น `= defaultMemoNum`
  - **ผลถ้ามันค้าง ≥ 1:** `chooseSubUnitBuff` (`TargetChoose.h:17`) `if(currentMemoNum) return …->memospriteList[currentMemoNum].get()` — ตัวละครส่วนใหญ่มี memo ตัวเดียวที่ `[0]` → อ่าน `memospriteList[1]` = **out-of-bounds** บน `vector<unique_ptr>`
  - ปัจจุบันยังไม่ crash = น่าจะยังไม่มีตัวละครไหน set `currentMemoNum` เป็นค่าอื่นนอกจาก 0

### 4.6 methods

**สร้าง / ตาย**
- `summon(double percent)` — `status=Alive` · `currentHP = percent/100 * totalHP` · `resetATV()`. **ไม่ใช่ override — เป็น name-hiding** ของ `Unit::summon()` (no-arg). ที่ใช้งานได้ถูกเพราะ container คนละชนิด: `memospriteList` = `unique_ptr<Memosprite>` → เรียก `summon(100)` (เวอร์ชันนี้) · `summonList`/`countdownList` = `unique_ptr<Unit>` → เรียก `Unit::summon()` (แค่ `status=Alive` + `resetATV`, ไม่มี HP)
- `death()` — ดู §3.4 (ยิง `AllyDeath_List`)

**ฮีล — `RestoreHP` 4 overload** (`ChangeHP.h`)
| signature | คอมเมนต์ในโค้ด | กลไก |
|---|---|---|
| `(HealSrc main, HealSrc adjacent, HealSrc other)` | — | `priority_queue` เรียง ally ตาม `calculateHPLost` · ถ้าเกิน 3 ตัว → ตัวเจ็บน้อยสุดโดน `other` · เหลือ 3 ตัวสุดท้าย: เจ็บหนักสุดได้ `main`, อีก 2 ได้ `adjacent` |
| `(AllyUnit *target, HealSrc)` | "heal เดี่ยว" | ฮีล target ตัวเดียว |
| `(HealSrc)` | "heal ทั้งทีมแบบเท่าเทียม" | วน `allyList` ฮีลทุกตัวเท่ากัน |
| `(AllyUnit *target, HealSrc main, HealSrc other)` | "heal ทั้งทีมเน้นคนเดียว" | วน `allyList`: ตัวชื่อตรง target → `main` · ที่เหลือ → `other` |

**check / อื่น ๆ**
- `isSameName(AllyUnit*)` `isSameName(string)` `isSameNum(AllyUnit*)` `isSameNum(int)` — redeclare บน `AllyUnit` → **บัง** `Unit::isSameNum(Unit*)` / `Unit::isSameName(string)` (เรียกผ่าน `AllyUnit*` ไม่ได้)
- accessor: `setStack`/`getStack` · `setBuffNote`/`getBuffNote` · `setBuffCountdown`/`getBuffCountdown` · `setBuffCheck`/`getBuffCheck` · `setBuffSubUnitTarget`/`getBuffSubUnitTarget` · `setBuffAllyTarget`/`getBuffAllyTarget` · `addStack` — อยู่บน `AllyUnit` (แล้ว `CharUnit` redeclare ชุดเดียวกันซ้ำอีก — ซ้ำซ้อน)
- targeting setter: `setDefaultAllyTargetNum` `setDefaultSubUnitTargetNum` `setCurrentAllyTargetNum` `setCurrentSubUnitTargetNum` `setDefaultTargetNum(int ally, int AllyUnit)` `setCurrentTargetNum(...)` — ⚠️ พารามิเตอร์ชื่อ `AllyUnit` ชนชื่อคลาส
- `printAtkStats()` `printHpStats()` `printCritStats()` — declared (นิยามใน `PrintStats.h`)
- `tauntIncreaseChange` `calHitChance` — §4.3

> ⚠️ `#pragma region` label สลับกัน: `AllyUnit.h:98` เขียน `Getters` แต่ข้างในเป็น **setter** ทั้งหมด · `AllyUnit.h:140` เขียน `Setters` ข้างในเป็น **getter**

### 4.7 `Memosprite` (จาก `Memosprite_reset` — ยังไม่ไล่ทั้งไฟล์)

`class Memosprite : public AllyUnit` (`Memosprite.h`) — field เพิ่ม: `Unit_Speed_Ratio` `Unit_Hp_Ratio` (% ของเจ้าของ) · `fixHP` `fixSpeed` (flat บวกเพิ่ม)

**สร้างครั้งแรก** `SetMemoStats(ptr, fixHP, Hp_ratio, fixSpeed, Speed_ratio, element, name, type)` (`StatsSet.h:30`) — เซ็ต field, `owner = ptr`, `charptr` = ตัวเอง, `num` = ของเจ้าของ, `baseHp = owner.baseHp * Hp_ratio/100`, `baseAtk`/`baseDef` = ของเจ้าของดิบ ๆ

**`Memosprite_reset()` — รันใน `Reset()` = ต่อ run (ไม่ใช่ต่อ wave)** (`Stats_Reset.h:197-270`) — จุดที่กลไกจริงเกิด:
1. ล้าง `Stats_type` / `Stats_each_element` ของ memo → **ก๊อป `Stats_type` + `Stats_each_element` ของเจ้าของทั้งก้อนมาใส่** (`:215-229`) → memo สืบ crit / DMG% / ทุก stat จากเจ้าของ ณ ต้น run (หลัง relic + trace + substats แต่ก่อนบัฟกลางรบ)
2. `Stats_type[FLAT_HP]` ทุก AType `*= Unit_Hp_Ratio/100` → แล้ว `[FLAT_HP][None] += fixHP` (`:230-233`) — **`fixHP` ถูกใช้ตรงนี้** (ไม่ใช่ที่ `SetMemoStats`)
3. `baseSpeed = fixSpeed + calculateSpeedOnStats(owner) * Unit_Speed_Ratio/100` (`:255`) — **snapshot ณ ต้น run** = เอาแค่ผลของ relic + stat/trace ของเจ้าของ. **โดยตั้งใจ:** บัฟสปีดที่เจ้าของได้กลางรบ (Ruan Mei ฯลฯ) **ไม่ส่งผล** ต่อ memo — ยกเว้นบัฟสปีดที่ยิงใส่ memo โดยตรง
4. `status = Death` · `currentHP = 0` (`:262-263`) — **memo เริ่มต้น run ในสภาพตาย** (ถูกต้องตามดีไซน์) ต้องถูก summon ด้วยสกิลกลางรบ (ต่างจาก summon ที่ `Summon_reset` ตั้ง `Alive`). ภายใน run ที่มีหลาย wave: memo ที่ summon ใน wave 0 **อยู่ต่อ** wave 1+ (`Memosprite_reset` ไม่รันซ้ำระหว่าง wave)

memosprite 2 แบบ: **สปีดคงที่** (RMC "Mem" — `fixSpeed=130, Speed_ratio=0` → 130 ตายตัว) · **อิงสปีดเจ้าของ** (Aglaea "Garmentmaker" — `fixSpeed=0, Speed_ratio=35` → 35% ของสปีด Aglaea ณ ต้น run)

---

## 🐞 รายการค้าง (ไว้คุยเรื่องแก้)

1. `Unit/Library.h` — `#include "AllyUnit.h"` ซ้ำ 2 บรรทัด
2. **Jingyuan summon ไม่มีชื่อของตัวเอง** — `Jingyuan.h:108` `SetSummonStats(ptr, 60, "LL")` ส่งชื่อ `"LL"` แต่ `StatsSet.h:74` เขียน `Atv_stats->Name = ptr->Atv_stats->Name` → argument `Name` ถูกทิ้ง summon เลยชื่อ `"Jingyuan"`. ตรวจว่าปัจจุบันมีจุดไหน lookup ชื่อ summon แยกจากเจ้าของหรือไม่ ก่อนตัดสินใจแก้
3. ~~`Enum.h:30-31` comment stale~~ ✅ แก้แล้ว (2026-09-02) — `AtvFreeze`/`Retire` = ใช้ตอนอัลติ Phainon, atv แช่แข็งทั้งคู่
4. `Unit::isExsited()` — typo ควรเป็น `isExisted`
5. ~~`decreaseSheild()` บั๊ก~~ ✅ แก้แล้ว (2026-09-02, `ChangeHP.h:175`) — ดูภาคผนวก 🛡️ · ระบบ **สร้าง** โล่ยัง stub (ยังไม่แก้)
6. ~~"taunt increase%" stub เสีย~~ ✅ แก้แล้ว — 2026-09-04 rework: field `tauntIncrease` (% เพิ่ม, 0 = ไม่มี), `taunt = baseTaunt · (1 + tauntIncrease/100)`, method `tauntIncreaseChange(double)` (`AllyUnit.h:29,62` · reset `= 0` ที่ `Stats_Reset.h:36,264`) · ยังไม่มี caller → ดู #12
7. **`currentMemoNum` ไม่เคย reset** — `Stats_Reset.h:35` + `:260` `currentMemoNum = currentMemoNum` (self-assign · ควร `= defaultMemoNum`) → ถ้าค้าง ≥ 1: `chooseSubUnitBuff` (`TargetChoose.h:17`) อ่าน `memospriteList[currentMemoNum]` out-of-bounds. ยังไม่ crash = ยังไม่มีตัวละครไหน set `currentMemoNum` ≥ 1 (ณ 2026-09-02) · _รอ user ยืนยันก่อนแก้_
8. **summon/countdown `owner == nullptr`** — capture `[ptr]` ใน lambda ทำให้โค้ด summon/countdown เองไม่พึ่ง `this->owner` · **แต่** `buffSingle` path บัฟ speed (`Buff_Stats.h:88,99`) deref `ptr->owner->path[0]` → latent crash ถ้ามีใคร cast summon → `AllyUnit*` แล้ว speed-buff (ยังไม่มีใครทำ) · **แผน:** refactor summon/countdown → `ActionValueStats` ล้วน (ดู `future-improvements.md` #3) — ไม่ใช่ปะ null-guard
9. ~~`HpAdjust` หัก currentHP เกินตอนถอนบัฟ maxHP~~ ✅ แก้แล้ว (2026-09-02, `AdjustStats.h:12`) — ดูหัวข้อ 4.1 · เดิม: `maxHP` ลดแม้ currentHP ยังไม่ชนเพดานใหม่ → currentHP โดนหักตาม delta
10. ~~`Turn_priority` global ไม่ reset~~ ✅ แก้แล้ว (2026-09-02) — rename → `nextForwardPriority` (`Setting.h:87`) + reset **ต่อ run** ที่ `Reset()` (`SetCombat.h`)
11. ~~`UnitGotHit` ไม่เคยถูก populate → enemy single-target attack ลงดาเมจ 0~~ ✅ แก้แล้ว (2026-09-02, `EnemyActionData.h:47,72`) — เพิ่ม `UnitGotHit.push_back(each);` ข้าง `Increase_energy` ทั้ง 2 branch · เดิม: `setBaAttack` เดิน round-robin + ให้ energy แต่ `UnitGotHit` ว่างตลอด → damage loop ไม่วน → single-target ลงดาเมจ 0 (AoE ปกติ) · push ในลูป = โดนพร้อมกันหลายตัวได้ = ปกติตามดีไซน์ (หัวข้อ 4.3)
12. **dead code โซน taunt** — ✅ ลบแล้ว (2026-09-04): no-arg `calHitChance()` · `totalTaunt` (global + `SetCombat.h` 3 จุด) · `Enemy::removeTaunt(string)` · `totalTaunt` bookkeeping ใน `tauntMtprChange` · **ปรับ:** `tauntMtpr` (100 = ×1.0) → `tauntIncrease` (0 = ไม่มี, `taunt = baseTaunt · (1 + tauntIncrease/100)`), method → `tauntIncreaseChange(double)` (2026-09-04) · **ยังไม่ลบ** (โซนอื่น): `DecreaseHP(Unit*, vector<AllyUnit*>, ...)` (`ChangeHP.h:149`) · `Enemy::hitCount` (`Enemy.h:54` — reset+`++` ใน `Attack()` ไม่มีใครอ่าน; ฝั่ง `AllyUnit::hitCount` อ่านโดย `Grand_Duke`)
13. ~~`Enemy::addTaunt` ไม่มี dedup + Mydei ไม่ออกจาก taunt list~~ ✅ แก้แล้ว (2026-09-02) — `addTaunt` เช็คชื่อก่อน push (`EnemyCombat.h:13`) · Mydei ult `debuffApply(...,"Mydei_Taunt",2)` + `addTaunt` · `After_turn_List` `isDebuffEnd(e,...)` → `e->removeTaunt(Mydei)` (แยกอิสระต่อ enemy) — ดูหัวข้อ 4.3
14. ~~`DecreaseHP` ทั้งทีม `return` แทน `continue`~~ ✅ แก้แล้ว (2026-09-02, `ChangeHP.h:141,153,167`) — เดิม: ใน loop วน `allyList` เจอ ally ที่ `!isTargetable()` (เช่น memo ยังไม่ summon) → `return` ออกทั้งฟังก์ชัน → ตัวที่เหลือไม่โดนลดเลือด · กระทบ `Hyacnine_LC.h:28` (ลดเลือดทั้งทีม) · single-target overload (`:128`) `return` ถูกแล้ว (ไม่มี loop)
15. ℹ️ **ตัวละครตายจากดาเมจไม่ได้ = by design** (ยืนยัน 2026-09-04) — sim นี้วัด damage output ไม่แคร์ survivability · `DecreaseCurrentHP` (`ChangeHP.h:122`) clamp `currentHP` ขั้นต่ำ `1` โดยตั้งใจ · `AllyUnit::death()` ถูกเรียกแค่กับ summon/countdown/memo (FireFly/Phainon/Aglaea/Castorice/Robin) — char-death `AllyDeath_List` (Huohuo revive, Tingyun buff strip) จึงยิงเฉพาะตอน memo ตาย ไม่เคยยิงตอน char ตาย (ยอมรับได้)

---

## ภาคผนวก 🛡️ — ระบบโล่ (shield / `currentSheild`) : สถานะ + บั๊ก

### ตอนนี้เป็น stub

`currentSheild` (double, บน `AllyUnit`) — **ไม่มีโค้ดไหนเพิ่มค่าเลย**
- reset `= 0` ที่ `Stats_Reset.h:38` (char) + `:261` (memo) เท่านั้น
- ชิ้นส่วนที่มีแต่ยังไม่ต่อสาย:
  - `Stats::SHEILD` (enum) — `toString` = `"Sheild"`
  - `Knight_of_Purity_Palace.h:8` : `Stats_type[Stats::SHEILD][AType::None] += 20` (โล่ bonus %) — **ไม่มีใครอ่านค่านี้**
  - `Aventurine.h` : โค้ดสร้างโล่ + `Buff_type.push_back("Shield")` **comment ทิ้งทั้งหมด**
- ผล: `currentSheild == 0` ตลอดเกม

### จุดที่โล่ถูก "หัก" — มีที่เดียว

`decreaseSheild()` ถูกเรียกจาก `EnemyActionData` เท่านั้น (3 จุด: `setAoeAttack` · `setBaAttack` แบบมี taunt · แบบไม่มี taunt):
```cpp
double damageDeal  = calculateDmgReceive(enemy, e, SkillRatio); // ดาเมจหลังลด mitigation
double hpDecreased = decreaseSheild(e, damageDeal);             // โล่ absorb → คืนส่วนที่ทะลุ
DecreaseCurrentHP(e, hpDecreased);                              // ส่วนที่ทะลุเข้า HP
```
- **เฉพาะการโจมตีตรงของ enemy** เท่านั้นที่ผ่านโล่
- `DecreaseHP(...)` (ตระกูลลดเลือดทั้งทีม/รายตัว ใน `ChangeHP.h`) เรียก `DecreaseCurrentHP` ตรง ๆ **ไม่ผ่านโล่** — ตรงกับเกมจริง (HP loss / DoT ทะลุโล่)

### บั๊กใน `decreaseSheild()` (`ChangeHP.h:175`)

```cpp
double decreaseSheild(AllyUnit *ptr,double Value){
    ptr->currentSheild = (ptr->currentSheild - Value < 0) ? 0 : ptr->currentSheild - Value;  // ① เขียนทับเป็น newShield
    return max(0.0, Value - ptr->currentSheild);   // ② อ่าน currentSheild = newShield (ที่ ① เพิ่งเขียน) → ผิด
}
```
บรรทัด ② ตั้งใจจะคืน "ดาเมจที่ทะลุโล่" = `Value − oldShield` แต่ดันไปใช้ `newShield` ที่บรรทัด ① เขียนทับไปแล้ว

| oldShield | Value | ทะลุ (ถูก) | โค้ดคืน | หมายเหตุ |
|--:|--:|--:|--:|---|
| 100 | 30 | 0 | `max(0, 30−70)` = **0** | ผ่าน (clamp บังหน้า) |
| 100 | 90 | 0 | `max(0, 90−10)` = **80** | ผิด — ทะลุทั้งที่โล่ยังเหลือ 10 |
| 100 | 150 | 50 | `max(0, 150−0)` = **150** | ผิด — โล่ absorb 100 แต่คิดว่าทะลุหมด |
| 0 | 100 | 100 | `max(0, 100−0)` = **100** | ผ่าน (สถานะปัจจุบันของเกม) |

พังทุกกรณีที่ `Value > oldShield/2` — ตอนนี้ไม่เจอเพราะ `oldShield` = 0 เสมอ → กลายเป็น passthrough (ดาเมจเข้า HP เต็ม)

### fix ที่ถูก — ✅ apply แล้ว (2026-09-02)

```cpp
double decreaseSheild(AllyUnit *ptr,double Value){
    double absorbed = min(ptr->currentSheild,Value);   // โล่กันได้เท่าที่มี
    ptr->currentSheild -= absorbed;
    return Value - absorbed;                            // ดาเมจส่วนที่ทะลุโล่ → เข้า HP
}
```
- behavior เดิม (ตอน `currentSheild == 0`) ไม่เปลี่ยน → sim output ปัจจุบันไม่กระทบ
- **ยังค้าง:** ระบบ **สร้าง** โล่ — อ่าน `Stats_type[SHEILD]` เป็นตัวคูณ outgoing shield, เพิ่ม `currentSheild`, countdown/ถอนเหมือนบัฟ, ปลด comment Aventurine
