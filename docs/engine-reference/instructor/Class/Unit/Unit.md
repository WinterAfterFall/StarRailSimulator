# `src/Defination/Class/Unit/Unit.h`

`class Unit` — base ของทุกหน่วยในสนาม (ถือ `ActionValueStats`, ไม่มี HP/ATK — พวกนั้นอยู่ที่ `AllyUnit`/`Enemy`)

## ทุก field

| field | ชนิด | ความหมาย |
|---|---|---|
| `Atv_stats` | `unique_ptr<ActionValueStats>` | สร้างใน ctor · `Atv_stats->charptr = this` |
| `Turn_func` | `function<void()>` | **สิ่งที่หน่วยทำเมื่อถึงเทิร์น** — เซ็ตต่อหน่วย (char: `ptr->Turn_func` · summon/countdown/memosprite: `xxxList[i]->Turn_func` · enemy: `SetEnemy.h:38`). สัญญา: ต้องจบด้วย `act->addToActionBar()` เสมอ |
| `Stats_each_element` | `Common_stats_each_element` | `map<Stats, map<ElementType, map<AType,double>>>` — DMG%/RESPEN แยกตามธาตุ (ดูในไฟล์นี้) |
| `Stats_type` | `Common_stats_type` | `map<Stats, map<AType,double>>` — ตารางสเตตัสรวม (ดูในไฟล์นี้). **Enemy ก็มี** → debuff (DEF shred / Vul / RES pen) = entry บวกใน `enemy->Stats_type` ที่สูตรดาเมจเอาไปรวมกับฝั่ง attacker |
| `status` | `UnitStatus` | `Alive` `Death` `AtvFreeze` `Retire` (⚠️ ไม่ init ใน ctor — Setup/Reset เป็นคนตั้ง) |

## `UnitStatus` (`Enum.h:27`)

| ค่า | `isAtvChangeAble` | `isExisted` | `isTargetable` | ใช้โดย |
|---|:-:|:-:|:-:|---|
| `Alive` | ✅ | ✅ | ✅ | ปกติ |
| `Death` | ❌ | ❌ | ❌ | ตาย |
| `AtvFreeze` | ❌ | ✅ | ✅ | **Phainon เท่านั้น** — ตัวเอง + freeze summon อื่นระหว่าง ult (act ผ่าน `extraTurn` ไม่ผ่าน `Find_turn`) |
| `Retire` | ❌ | ❌ | ❌ | **Phainon เท่านั้น** — ally อื่นระหว่าง ult (atv แช่แข็งจริง — comment ที่ว่า "atv เคลื่อนปกติ" ผิด) |

- `isAtvChangeAble()` = false เมื่อ `Death | AtvFreeze | Retire` → `Atv_fix()` และ `Find_turn()` **ข้าม**
- `isExisted()` = false เมื่อ `Death | Retire` (เดิมสะกด `isExsited` — แก้ชื่อแล้ว 2026-09-13)
- `isTargetable()` = false เมื่อ `Death | Retire | Type==OutofBounds`

## methods

- **wrappers** ทะลุไป `Atv_stats`: `get/setBaseSpeed` `getATV` `getMaxATV` `getTurnCnt` `getNum` `getSide` `getType` `getName` …
- **check**: `isSameUnit(Unit*)` `isSameName(str)` `isSameNum(int/Unit*)` `isAlive` `isDeath` `isAtvChangeAble` `isExisted` `isTargetable`
- `speedBuff(BuffClass)` — `FLAT_SPD` → `speedBuff(0, value)` · อื่น ๆ **ทั้งหมดถือเป็น %** → `speedBuff(value, 0)`
- `resetATV()` / `resetATV(baseSpeed)` → `Atv_stats`
- `summon()` — `status = Alive` + `resetATV()` · `death()` — `status = Death` (Unit base)
- `canCastToSubUnit()` = `dynamic_cast<AllyUnit*>(this)` (ชื่อกำกวม จริง ๆ คือ "cast → AllyUnit", null ถ้าเป็น Enemy) · `canCastToEnemy()` = `dynamic_cast<Enemy*>(this)`
  - ⚠️ อย่าสับสนกับ `ActionValueStats::canCastToAllyUnit()/canCastToEnemy()` (`TargetChoose.h:3-8`) ที่ cast `charptr` — ใช้บน global `turn`
  - ⚠️ **`turn->canCastToAllyUnit()` คืน non-null ตอนเทิร์นของ Memosprite ด้วย** — `charptr` ของ memo ชี้ตัวเอง และ `Memosprite : AllyUnit` → cast ผ่าน. โค้ด ult-check / before-turn ที่เขียน `AllyUnit *ally = turn->canCastToAllyUnit(); if(ally)…` จะทำงานตอนเทิร์น memo เหมือนเทิร์น character (เช่น `Huohuo.h:95-110` Divine Provision กิน stack + ฮีล memo ที่กำลังเล่นเทิร์น). ระวังโค้ดที่สมมติว่า `ally` เป็น character แน่ ๆ แล้วไปอ่าน `Current_energy` / field ที่ memo ไม่มี

## `death()` 2 เวอร์ชัน

| | โค้ด | ยิง event? | ใช้กับ |
|---|---|:-:|---|
| `Unit::death()` | `status = Death` | ❌ | enemy · summon · countdown |
| `AllyUnit::death()` (`ChangeHP.h:179`) | `currentHP = 0` · `status = Death` · `allEventWhenAllyDeath(this)` | ✅ `AllyDeath_List` | ally / char / memosprite |

## โมเดล `Stats_type` / `Stats_each_element` (นิยาม typedef ที่ `Enum.h` ท้ายไฟล์)

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

## อธิบายที่ไฟล์อื่น

- `Turn_Skip` (บังคับข้ามเทิร์น) + กลไก freeze → [Combat.md](../../Function/Combat/Combat.md)
