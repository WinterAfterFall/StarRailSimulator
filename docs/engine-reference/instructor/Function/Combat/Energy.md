# `src/Defination/Function/Combat/Energy.h`

## Energy (`maxEnergy` `currentEnergy` `ultCost` `energyRecharge`)

field อยู่ที่ `CharUnit.h:36-39` · เซ็ตครั้งแรกโดย `setCharBasicStats(baseSpeed, maxEnergy, ultCost, eidolon, ...)` (`StatsSet.h:10,18-19`)

### กฎสำคัญ: ERR ไม่ได้คูณ energy ทุกชนิด

ในเกม Energy Recharge เพิ่มเฉพาะ energy ที่ได้จาก **การกระทำ** (ตี / โดนตี / จบเทิร์น) แต่ **ไม่** เพิ่ม energy ที่สกิลเพื่อน "มอบให้" ตรง ๆ (fix energy)

เอนจินแยกด้วย **overload ของ `increaseEnergy`** (`Energy.h`) — **นี่คือ convention ที่ต้องยึดเวลาเขียนตัวละครใหม่ (ยืนยัน 2026-09-13):**

| overload | สูตร | ERR คูณ? | ใช้กับ |
|---|---|---|---|
| `increaseEnergy(ptr, energy)` | `energy × Energy_recharge/100` | ✅ | energy จากการกระทำ — ตี, โดนตี, จบเทิร์น |
| `increaseEnergy(ptr, energyPercent, flatEnergy)` | `Flat + percent/100 × maxEnergy` | ❌ | **fix energy** — ที่สกิล/LC มอบให้ตรง ๆ |

> มี overload ที่รับ `AllyUnit*` คู่กันทั้ง 2 แบบ — เด้งไปใช้ `ptr->owner` ให้ (memosprite เติม energy ให้เจ้าของ)

ตัวอย่างที่ใช้ถูกฝั่ง:
- Tingyun ตีเอง → 2-arg (`Tingyun.h:60,75`) · **Benediction ยัด energy ให้เพื่อน → 3-arg** `increaseEnergy(target, 0, E6?60:50)` (`Tingyun.h:120`) · technique → `(ptr, 0, 50*TECHNIQUE)` (`:169`)
- Huohuo ult → `(each, 20, 0)` = 20% ของ `maxEnergy` ไม่โดน ERR (`Huohuo.h:75`)

### ขอบเขต Energy

`increaseEnergy()` ทุก overload จะ clamp `currentEnergy` ให้อยู่ระหว่าง `0` และ `maxEnergy` ดังนั้นเอฟเฟกต์ที่ส่งค่า Energy ติดลบจะลดได้ แต่ไม่ทำให้หลอดติดลบ

### `ultCost` vs `maxEnergy`

- `maxEnergy` = **เพดานสะสม** — `increaseEnergy` clamp ทุก overload
- `ultCost` = **ราคาที่ต้องจ่าย** — `ultUseCheck` เช็ค `if(ptr->ultCost > ptr->currentEnergy) return false;` แล้วหักออก (`Energy.h`)
- ปกติสองค่าเท่ากัน แยกไว้เพื่อรองรับตัวที่กติกาต่าง เช่น Saber (`Saber.h:220,248` · `Saber_LC.h:17` เช็ค `maxEnergy>=300`)

### `maxEnergy == 0` = ตัวที่ไม่มีหลอดพลังงาน

บางตัว**เก็บอัลติด้วยเงื่อนไขอื่น** ไม่ใช่ energy → ตั้ง `maxEnergy = 0` (ยืนยัน 2026-09-13)

โค้ดที่ buff energy ต้อง **เช็คก่อนเสมอ** ไม่งั้นจะไปเติมหลอดที่ไม่มีอยู่ / หารศูนย์:
- Tingyun: `if (charUnit[...]->maxEnergy == 0) return true;` = escape hatch ไม่เลือกเป้านี้ (`Tingyun.h:106`)
- Sunday: `if(chooseCharacterBuff(ptr)->maxEnergy != 0)` ก่อนคิดเงื่อนไข (`Sunday.h:28`)
- RMC: `if(chooseCharacterBuff(...)->maxEnergy == 0)` แยก branch ของ Mem's Support (`RMC.h:251`)

### ใช้ ult แล้วคืน 5 energy

`ultUseCheck` หัก `ultCost` เสร็จแล้วเรียก `increaseEnergy(ptr, 5)` ทันที = กฎเกม "ใช้ ult แล้วได้คืน 5 energy" · ใช้ **2-arg** ถูกแล้ว เพราะในเกม 5 ก้อนนี้**โดน ERR คูณ** (ยืนยัน 2026-09-13)

`ultUseCheck(ptr)` ตรวจตามลำดับ: ยูนิตยังอยู่ → `currentEnergy >= ultCost` → `ultCondition` ทุกข้อคืน `true` → หัก `ultCost` → เรียก `increaseEnergy(ptr, 5)` → ยิง `whenUseUltList` ถ้าเงื่อนไขข้อใดไม่ผ่าน จะคืน `false` ก่อนหักพลังงานและก่อนยิง event; เพิ่มเงื่อนไขผ่าน `CharUnit::addUltCondition(function<bool()>)` (`Energy.h`)

## ฟังก์ชันทั้งไฟล์ — อยู่ที่ไหนบ้าง

| ฟังก์ชัน | บรรทัด | อธิบายไว้ที่ |
|---|---|---|
| `increaseEnergy(CharUnit*, energy)` · `(AllyUnit*, energy)` | 3 · 10 | ในไฟล์นี้ — แบบ 2-arg (ERR คูณ) ดูตารางหัวข้อ ERR ด้านบน |
| `increaseEnergy(CharUnit*, %, flat)` · `(AllyUnit*, %, flat)` | 17 · 24 | ในไฟล์นี้ — แบบ 3-arg (fix energy, ERR ไม่คูณ) |
| `ultUseCheck(CharUnit*)` | 31 | ในไฟล์นี้ (หัวข้อ "จังหวะตรวจ Ultimate") |
| `allUltimateCheck()` | 44 | ➡️ [Combat.md](Combat.md) หัวข้อ "จังหวะตรวจ Ultimate" — เป็นตัววน `ultimateList` แล้วเรียก `dealDamage()` ให้เมื่อไม่ได้อยู่ใน `WHILE_ACTION` |
| `CharUnit::addUltCondition(condition)` | 51 | ➡️ [CharUnit.md](../../Class/Unit/CharUnit.md) — ต่อเงื่อนไขเพิ่มให้ `ultUseCheck` |
