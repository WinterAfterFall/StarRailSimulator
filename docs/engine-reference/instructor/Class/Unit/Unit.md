# `src/Defination/Class/Unit/Unit.h`

`class Unit` — base ของทุกหน่วยในสนาม (ถือ `ActionValueStats`, ไม่มี HP/ATK — พวกนั้นอยู่ที่ `AllyUnit`/`Enemy`)

## ทุก field

| field | ชนิด | ความหมาย |
|---|---|---|
| `atvStats` | `unique_ptr<ActionValueStats>` | สร้างใน ctor · `atvStats->charptr = this` |
| `turnFunc` | `function<void()>` | **สิ่งที่หน่วยทำเมื่อถึงเทิร์น** — เซ็ตต่อหน่วย (char: `ptr->turnFunc` · summon/countdown/memosprite: `xxxList[i]->turnFunc` · enemy: `SetEnemy.h:38`). สัญญา: ต้องจบด้วย `act->addToActionBar()` เสมอ |
| `statsEachElement` | `CommonStatsEachElement` | `map<Stats, map<ElementType, map<AType,double>>>` — DMG%/RESPEN แยกตามธาตุ (ดูในไฟล์นี้) |
| `statsType` | `CommonStatsType` | `map<Stats, map<AType,double>>` — ตารางสเตตัสรวม (ดูในไฟล์นี้). **Enemy ก็มี** → debuff (DEF shred / Vul / RES pen) = entry บวกใน `enemy->statsType` ที่สูตรดาเมจเอาไปรวมกับฝั่ง attacker |
| `status` | `UnitStatus` | `ALIVE` `DEATH` `ATV_FREEZE` `RETIRE` (⚠️ ไม่ init ใน ctor — Setup/Reset เป็นคนตั้ง) |

## `UnitStatus` (`Enum.h:27`)

| ค่า | `isAtvChangeAble` | `isExisted` | `isTargetable` | ใช้โดย |
|---|:-:|:-:|:-:|---|
| `ALIVE` | ✅ | ✅ | ✅ | ปกติ |
| `DEATH` | ❌ | ❌ | ❌ | ตาย |
| `ATV_FREEZE` | ❌ | ✅ | ✅ | **Phainon เท่านั้น** — ตัวเอง + freeze summon อื่นระหว่าง ult (act ผ่าน `extraTurn` ไม่ผ่าน `findTurn`) |
| `RETIRE` | ❌ | ❌ | ❌ | **Phainon เท่านั้น** — ally อื่นระหว่าง ult (atv แช่แข็งจริง — comment ที่ว่า "atv เคลื่อนปกติ" ผิด) |

- `isAtvChangeAble()` = false เมื่อ `DEATH | ATV_FREEZE | RETIRE` → `atvFix()` และ `findTurn()` **ข้าม**
- `isExisted()` = false เมื่อ `DEATH | RETIRE` (เดิมสะกด `isExsited` — แก้ชื่อแล้ว 2026-09-13)
- `isTargetable()` = false เมื่อ `DEATH | RETIRE | type==OUT_OF_BOUNDS`

## methods

- **wrappers** ทะลุไป `atvStats`: `get/setBaseSpeed` `getATV` `getMaxATV` `getTurnCnt` `getNum` `getSide` `getType` `getName` …
- **check**: `isSameUnit(Unit*)` `isSameName(str)` `isSameNum(int/Unit*)` `isAlive` `isDeath` `isAtvChangeAble` `isExisted` `isTargetable`
- `speedBuff(BuffClass)` — `FLAT_SPD` → `speedBuff(0, value)` · อื่น ๆ **ทั้งหมดถือเป็น %** → `speedBuff(value, 0)`
- `resetATV()` / `resetATV(baseSpeed)` → `atvStats`
- `summon()` — `status = ALIVE` + `resetATV()` · `death()` — `status = DEATH` (Unit base)
- `canCastToSubUnit()` = `dynamic_cast<AllyUnit*>(this)` (ชื่อกำกวม จริง ๆ คือ "cast → AllyUnit", null ถ้าเป็น Enemy) · `canCastToEnemy()` = `dynamic_cast<Enemy*>(this)`
  - ⚠️ อย่าสับสนกับ `ActionValueStats::canCastToAllyUnit()/canCastToEnemy()` (`TargetChoose.h:3-8`) ที่ cast `charptr` — ใช้บน global `turn`
  - ⚠️ **`turn->canCastToAllyUnit()` คืน non-null ตอนเทิร์นของ Memosprite ด้วย** — `charptr` ของ memo ชี้ตัวเอง และ `Memosprite : AllyUnit` → cast ผ่าน. โค้ด ult-check / before-turn ที่เขียน `AllyUnit *ally = turn->canCastToAllyUnit(); if(ally)…` จะทำงานตอนเทิร์น memo เหมือนเทิร์น character (เช่น `Huohuo.h:95-110` Divine Provision กิน stack + ฮีล memo ที่กำลังเล่นเทิร์น). ระวังโค้ดที่สมมติว่า `ally` เป็น character แน่ ๆ แล้วไปอ่าน `currentEnergy` / field ที่ memo ไม่มี

## `death()` 2 เวอร์ชัน

| | โค้ด | ยิง event? | ใช้กับ |
|---|---|:-:|---|
| `Unit::death()` | `status = DEATH` | ❌ | enemy · summon · countdown |
| `AllyUnit::death()` (`ChangeHP.h:179`) | `currentHP = 0` · `status = DEATH` · `allEventWhenAllyDeath(this)` | ✅ `allyDeathList` | ally / char / memosprite |

## โมเดล `statsType` / `statsEachElement` (นิยาม typedef ที่ `Enum.h` ท้ายไฟล์)

```cpp
typedef unordered_map<Stats, unordered_map<AType,double>>                               CommonStatsType;
typedef unordered_map<Stats, unordered_map<ElementType, unordered_map<AType,double>>>   CommonStatsEachElement;
```

**`statsType[X][AType]`:**
| key | ความหมาย |
|---|---|
| `[X][NONE]` | ค่ามาตรฐานของ stat X — ใช้กับ **ทุก** การกระทำ (`calculate*OnStats` อ่านตัวนี้ตรง ๆ) |
| `[X][FUA]` / `[X][ULT]` / `[X][SKILL]` / … | โบนัส X **เฉพาะ**เมื่อ action มี AType นั้นใน `damageTypeList` (เช่น "+CD เฉพาะ FUA") — `calAtkMultiplier` ฯลฯ วนบวกทีละ type |
| `[X][TEMP]` | **บัญชีเงา** = ส่วนของ `[X][NONE]` ที่มาจากบัฟที่ scale ตาม stat → `calculate*ForBuff()` เอา `[NONE] - [TEMP]` เพื่อ **กันลูปบัฟ** (Robin บัฟ ATK ตาม ATK ตัวเอง / Cerydra↔Robin) |

- ใครเซ็ต `TEMP`: **เขียนเองในตัวละคร** — ตัวที่ push เข้า `statsAdjustList` (บัฟแบบ scale-ตาม-stat) จะบวกทั้ง `[NONE]` และ `[TEMP]` เท่ากัน
- `TEMP` ถูกลด/ล้างเมื่อ: (ก) `Stats_Reset` ก่อนเริ่มรอบคำนวณ substats ใหม่ (โปรแกรมวนหา substats ที่ดีสุด) (ข) เมื่อ `[NONE]` ที่ได้จากบัฟนั้นลดลง `TEMP` ก็ลดตาม (ค) บัฟหมดอายุ → ถอนทั้ง `[NONE]` และ `[TEMP]`

**`statsEachElement[X][element][AType]`:** มิติ `element` ใช้จริงกับ **`Stats::DMG` และ `Stats::RESPEN`** เท่านั้น (`calBonusDmgMultiplier` / `calRespenMultiplier` อ่าน `act->damageElement`) — บัฟ "DMG เฉพาะธาตุน้ำแข็ง" ตัวละครไฟจะเอาไปใช้ไม่ได้

## อธิบายที่ไฟล์อื่น

- `turnSkip` (บังคับข้ามเทิร์น) + กลไก freeze → [Combat.md](../../Function/Combat/Combat.md)
