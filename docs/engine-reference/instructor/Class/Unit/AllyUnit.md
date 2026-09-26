# `src/Defination/Class/Unit/AllyUnit.h`

`class AllyUnit : public Unit` — base ของ `CharUnit` / `Memosprite` และเป็นชนิดที่ `SetSummonStats`/`SetCountdownStats` ใช้ดิบ ๆ
macro ในไฟล์: `#define endl '\n'` · `F`=`first` · `S`=`second` · `DMG_CAL 12`

## stats fields

| field | เขียนโดย | อ่านโดย |
|---|---|---|
| `baseAtk` `baseHp` `baseDef` | `SetAllyBaseStats(hp,atk,def)` (บวกสะสม) + minor trace hardcode | สูตรดาเมจ (`calAtkMultiplier` ใช้ `baseAtk` + `Stats_type`) |
| `baseTaunt` | `SetCharBasicStats` / `SetMemoStats` = `tauntValueEachPath[path]` | [EnemyActionData.md](../ActionData/EnemyActionData.md) |
| `Element_type` | `ElementType` ค่าเดียว (เดิมเป็น `vector` — เปลี่ยนแล้ว 2026-09-25) | |
| `totalATK` `totalHP` `totalDEF` | **cache** ของ `calculate*OnStats()` — เขียนที่ `SetCombat.h:101` (ต้นรบ) + ทุกครั้งบัฟ `AType::None` ผ่าน `StatsAdjust()→{Atk,Hp,Def}Adjust` (`AdjustStats.h`) | abilities ที่ scale ตาม totalHP/ATK · requirement check · print · `HpAdjust` ใช้ปรับ `currentHP` เมื่อ maxHP เปลี่ยน · **สูตรดาเมจไม่อ่าน** (recompute เอง) |
| `currentHP` | `IncreaseCurrentHP` / `DecreaseCurrentHP` (clamp `[1, totalHP]`) · `HpAdjust` (`AdjustStats.h`) — กติกา: **maxHP เพิ่ม x → currentHP เพิ่ม x** · **maxHP ลด → currentHP คงเดิม** เว้นแต่ลดจนต่ำกว่า currentHP → clamp ลงมาเท่า maxHP. _(แก้ 2026-09-02 — โค้ดเดิมหัก currentHP ตาม delta ทุกกรณีที่ maxHP ลด แม้ currentHP ยังไม่ชนเพดานใหม่ → เป้าเสีย HP ฟรีเวลาบัฟ maxHP หลุด)_ | |
| `currentSheild` | **ไม่มีโค้ดไหนเพิ่มค่า** — ระบบโล่ยัง stub. reset = 0 เท่านั้น (`Stats_Reset.h:38`) | `decreaseSheild` (ดู [🐞 BUGS.md](../../BUGS.md)) |
| `hitCount` | `Attack()` (`Combat.h`): reset 0 ต้นฟังก์ชันสำหรับทุก attacker/target → `+= damageSplit[i].size()` ต่อ hit-beat (attacker) / `++` ต่อ target | per-hit / after-attack event triggers · เช่น `Grand_Duke.h:22` (relic DoT bonus นับ hit) |
| `taunt` `tauntIncrease` `owner` | [EnemyActionData.md](../ActionData/EnemyActionData.md) / ในไฟล์นี้ | |

## buff bookkeeping maps (ดูรายละเอียด lifecycle ที่ `character-implementation-notes.md` §4)

`stack` `buffNote` `buffEnd` `buffCheck` (`map<string,…>`) · `buffSubUnitTarget` (`map<string,AllyUnit*>`) · `buffAllyTarget` (`map<string,CharUnit*>`)
= สมุดบันทึก per-unit key ด้วย **ชื่อบัฟ (prefix ชื่อตัวละคร)** — framework track แค่ `buffCheck`(bool) + `buffEnd`(turnCnt เป้าหมาย) ไม่เก็บขนาด delta

- `buffEnd[name] = ptr->turnCnt + extend` (`Buff_Stats.h:40`) — ใช้ `turnCnt` ของ **unit ที่ entry นี้อยู่** (ปกติ = เป้าหมาย). บัฟแบบ relay (เช่น Robin skill E บัฟตัวเอง แล้วผลของมันไปเพิ่มดาเมจทั้งทีม) → entry อยู่บน Robin → นับเทิร์น Robin
- framework **ไม่ถอนค่า stat ให้เอง** ตอนบัฟหมด — ตัวละครต้องเขียน `After_turn_List` เช็ค `isBuffEnd` แล้ว `buffSingle(-v)` เอง (pattern Tingyun) → ดู [`future-improvements.md`](../../../future-improvements.md) ข้อ 1 + [`character-implementation-notes.md`](../../../../character-implementation-notes.md) หัวข้อ 4

## taunt / การเลือกเป้าของ enemy

→ อธิบายที่ [EnemyActionData.md](../ActionData/EnemyActionData.md) — field `baseTaunt` · `tauntIncrease` · `taunt` กับ method `calHitChance` · `tauntIncreaseChange` อยู่ในไฟล์นี้ แต่กลไกทั้งหมดเล่ารวมไว้ที่นั่น

## `owner`

| unit | `owner` ตั้งโดย | ค่า |
|---|---|---|
| `CharUnit` | `CharUnit()` ctor | `this` |
| `Memosprite` | `SetMemoStats` (`StatsSet.h:51`) | `CharUnit` เจ้าของ |
| summon / countdown (`SetSummonStats`/`SetCountdownStats`) | **ไม่มีใครตั้ง** | `nullptr` → ดู [🐞 #8](../../BUGS.md) |

> จุดเสี่ยง null-deref: `buffSingle` (`Buff_Stats.h:88,99`) path บัฟ speed ทำ `ahaSpeedAdjust(ptr->owner->path)` — ถ้า `ptr` เป็น summon/countdown (`owner == nullptr`) = crash. **ปัจจุบันเกิดไม่ได้** เพราะ summon/countdown เป็น `unique_ptr<Unit>` ส่งเข้า `buffSingle(AllyUnit*)` ตรง ๆ ไม่ได้ + ไม่อยู่ใน `allyList`.
> **ทางแก้ที่ user เลือก** (2026-09-02): ไม่ปะจุดเดียว — อนาคต refactor summon/countdown ให้เป็นแค่ `ActionValueStats` (ไม่ใช่ `AllyUnit`) → ไม่มี field `owner` ตั้งแต่แรก → ดู [`future-improvements.md`](../../../future-improvements.md) หัวข้อ 3

## targeting nums

`defaultCharNum = Main_dps_num` · `defaultMemoNum = 0` · `currentCharNum` / `currentMemoNum` · `Enemy_target_num = Main_Enemy_num`
- `current*` = "ตอนนี้ unit นี้เล็งบัฟไปที่ ally/memosprite ตัวไหน" · `currentCharNum` reset กลับเป็น `defaultCharNum` ที่ `Stats_Reset.h:34`
- ✅ ~~**`currentMemoNum` ไม่เคย reset**~~ แก้แล้ว (commit `8690113` · โค้ดตอนนี้ `Stats_Reset.h:35,260` เขียน `= defaultMemoNum`) · บันทึกเดิม: `Stats_Reset.h:35` + `:260` เขียน `currentMemoNum = currentMemoNum` (assign ตัวเอง = no-op) บรรทัดข้างบนคือ `currentCharNum = defaultCharNum` → บรรทัดนี้ตั้งใจจะเป็น `= defaultMemoNum`
  - แก้ 2026-09-18: `chooseAllyBuff` ใช้ `0` เลือกตัวละคร และค่า 1 เลือก memo ตัวแรกได้ถูกต้อง · 2026-09-25: memosprite เหลือตัวเดียว (`CharUnit::memosprite`) ค่า 1 = memosprite ค่าอื่นหรือไม่มี memosprite = ตัวละคร
  - ปัจจุบันยังไม่ crash = น่าจะยังไม่มีตัวละครไหน set `currentMemoNum` เป็นค่าอื่นนอกจาก 0

## methods

**สร้าง / ตาย**
- `summon(double percent)` — `status=Alive` · `currentHP = percent/100 * totalHP` · `resetATV()`. **ไม่ใช่ override — เป็น name-hiding** ของ `Unit::summon()` (no-arg). ที่ใช้งานได้ถูกเพราะ container คนละชนิด: `memosprite` = `unique_ptr<Memosprite>` → เรียก `summon(100)` (เวอร์ชันนี้) · `summonList`/`countdownList` = `unique_ptr<Unit>` → เรียก `Unit::summon()` (แค่ `status=Alive` + `resetATV`, ไม่มี HP)
- `death()` — ดู [Unit.md](Unit.md) (ยิง `AllyDeath_List`)

**ฮีล — `RestoreHP` 4 overload** → อธิบายที่ [ChangeHP.md](../../Function/Combat/ChangeHP.md)

**check / อื่น ๆ**
- `isSameName(AllyUnit*)` `isSameName(string)` `isSameNum(AllyUnit*)` `isSameNum(int)` — redeclare บน `AllyUnit` → **บัง** `Unit::isSameNum(Unit*)` / `Unit::isSameName(string)` (เรียกผ่าน `AllyUnit*` ไม่ได้)
- accessor: `setStack`/`getStack` · `setBuffNote`/`getBuffNote` · `setBuffCountdown`/`getBuffCountdown` · `setBuffCheck`/`getBuffCheck` · `setBuffSubUnitTarget`/`getBuffSubUnitTarget` · `setBuffAllyTarget`/`getBuffAllyTarget` · `addStack` — อยู่บน `AllyUnit` (แล้ว `CharUnit` redeclare ชุดเดียวกันซ้ำอีก — ซ้ำซ้อน)
- targeting setter: `setDefaultAllyTargetNum` `setDefaultSubUnitTargetNum` `setCurrentAllyTargetNum` `setCurrentSubUnitTargetNum` `setDefaultTargetNum(int ally, int AllyUnit)` `setCurrentTargetNum(...)` — ⚠️ พารามิเตอร์ชื่อ `AllyUnit` ชนชื่อคลาส
- `printAtkStats()` `printHpStats()` `printCritStats()` — declared (นิยามใน `PrintStats.h`)
- `tauntIncreaseChange` `calHitChance` — [EnemyActionData.md](../ActionData/EnemyActionData.md)

> ⚠️ `#pragma region` label สลับกัน: `AllyUnit.h:98` เขียน `Getters` แต่ข้างในเป็น **setter** ทั้งหมด · `AllyUnit.h:140` เขียน `Setters` ข้างในเป็น **getter**

## Memosprite

→ `class Memosprite : public AllyUnit` — การสร้าง (`SetMemoStats`) และการ reset ต่อ run อธิบายที่ [Stats_Reset.md](../../Function/Setup/Stats_Reset.md)
