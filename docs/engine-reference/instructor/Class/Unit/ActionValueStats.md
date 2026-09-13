# `src/Defination/Class/Unit/ActionValueStats.h`

## คลาส `ActionValueStats` — ทุก field

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
| `charptr` | `Unit*` | `nullptr` | back-pointer กลับไปที่ Unit เจ้าของ (Ally / Enemy / Memosprite / …) เซ็ตใน `Unit()` ctor · **ยกเว้น `aha`** (`Setting.h:80`) สร้างจาก `ActionValueStats` ตรง ๆ ไม่ผ่าน `Unit` → `charptr == nullptr` โดยตั้งใจ = สัญญาณว่าเป็น pseudo-unit (`Take_action` เห็น `!turn->charptr` → เรียก `AhaTurn()`) ดู [Combat.md](../../Function/Combat/Combat.md) |

**Constructors:** `()` · `(name)` · `(name, speed)`

**Methods (ในคลาส):** get/set ครบทุก field · `isSameName(str)` `isSameNum(int)` · (นิยามภายนอกใน `Unit.h`) `isSameUnit(Unit*)` `isSameNum(Unit*)` · `canCastToAllyUnit()` `canCastToEnemy()` · `speedBuff(%, flat)` `resetATV()` `resetATV(baseSpeed)` (นิยามใน `Action_value.h`)

## อธิบายที่ไฟล์อื่น

- ฟังก์ชันระบบ ATV (`Update_Max_atv` · `Action_forward` · `Atv_fix` · `Find_turn` …) → [Action_value.md](../../Function/Combat/Action_value.md)
- `BuffClass` / `BuffElementClass` (นิยามท้ายไฟล์นี้) และวิธีบวก stat → [Buff_Stats.md](../../Function/Combat/Buff_Stats.md)
- `aha` — pseudo-unit ของทีม Elation → [Combat.md](../../Function/Combat/Combat.md)
