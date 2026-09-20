# `src/Defination/Function/Combat/Energy.h`

## Energy (`Max_energy` `Current_energy` `Ult_cost` `Energy_recharge`)

field อยู่ที่ `CharUnit.h:36-39` · เซ็ตครั้งแรกโดย `SetCharBasicStats(BaseSpeed, Max_Energy, Ult_cost, Eidolon, ...)` (`StatsSet.h:10,18-19`)

### กฎสำคัญ: ERR ไม่ได้คูณ energy ทุกชนิด

ในเกม Energy Recharge เพิ่มเฉพาะ energy ที่ได้จาก **การกระทำ** (ตี / โดนตี / จบเทิร์น) แต่ **ไม่** เพิ่ม energy ที่สกิลเพื่อน "มอบให้" ตรง ๆ (fix energy)

เอนจินแยกด้วย **overload ของ `Increase_energy`** (`Energy.h`) — **นี่คือ convention ที่ต้องยึดเวลาเขียนตัวละครใหม่ (ยืนยัน 2026-09-13):**

| overload | สูตร | ERR คูณ? | ใช้กับ |
|---|---|---|---|
| `Increase_energy(ptr, Energy)` | `Energy × Energy_recharge/100` | ✅ | energy จากการกระทำ — ตี, โดนตี, จบเทิร์น |
| `Increase_energy(ptr, Energy_percent, Flat_energy)` | `Flat + percent/100 × Max_energy` | ❌ | **fix energy** — ที่สกิล/LC มอบให้ตรง ๆ |

> มี overload ที่รับ `AllyUnit*` คู่กันทั้ง 2 แบบ — เด้งไปใช้ `ptr->owner` ให้ (memosprite เติม energy ให้เจ้าของ)

ตัวอย่างที่ใช้ถูกฝั่ง:
- Tingyun ตีเอง → 2-arg (`Tingyun.h:60,75`) · **Benediction ยัด energy ให้เพื่อน → 3-arg** `Increase_energy(target, 0, E6?60:50)` (`Tingyun.h:120`) · technique → `(ptr, 0, 50*Technique)` (`:169`)
- Huohuo ult → `(each, 20, 0)` = 20% ของ `Max_energy` ไม่โดน ERR (`Huohuo.h:75`)

### ขอบเขต Energy

`Increase_energy()` ทุก overload จะ clamp `Current_energy` ให้อยู่ระหว่าง `0` และ `Max_energy` ดังนั้นเอฟเฟกต์ที่ส่งค่า Energy ติดลบจะลดได้ แต่ไม่ทำให้หลอดติดลบ

### `Ult_cost` vs `Max_energy`

- `Max_energy` = **เพดานสะสม** — `Increase_energy` clamp ทุก overload
- `Ult_cost` = **ราคาที่ต้องจ่าย** — `ultUseCheck` เช็ค `if(ptr->Ult_cost > ptr->Current_energy) return false;` แล้วหักออก (`Energy.h`)
- ปกติสองค่าเท่ากัน แยกไว้เพื่อรองรับตัวที่กติกาต่าง เช่น Saber (`Saber.h:220,248` · `Saber_LC.h:17` เช็ค `Max_energy>=300`)

### `Max_energy == 0` = ตัวที่ไม่มีหลอดพลังงาน

บางตัว**เก็บอัลติด้วยเงื่อนไขอื่น** ไม่ใช่ energy → ตั้ง `Max_energy = 0` (ยืนยัน 2026-09-13)

โค้ดที่ buff energy ต้อง **เช็คก่อนเสมอ** ไม่งั้นจะไปเติมหลอดที่ไม่มีอยู่ / หารศูนย์:
- Tingyun: `if (charUnit[...]->Max_energy == 0) return true;` = escape hatch ไม่เลือกเป้านี้ (`Tingyun.h:106`)
- Sunday: `if(chooseCharacterBuff(ptr)->Max_energy != 0)` ก่อนคิดเงื่อนไข (`Sunday.h:28`)
- RMC: `if(chooseCharacterBuff(...)->Max_energy == 0)` แยก branch ของ Mem's Support (`RMC.h:251`)

### ใช้ ult แล้วคืน 5 energy

`ultUseCheck` หัก `Ult_cost` เสร็จแล้วเรียก `Increase_energy(ptr, 5)` ทันที = กฎเกม "ใช้ ult แล้วได้คืน 5 energy" · ใช้ **2-arg** ถูกแล้ว เพราะในเกม 5 ก้อนนี้**โดน ERR คูณ** (ยืนยัน 2026-09-13)

จากนั้นวน `ultCondition` ทุกข้อ (ต้องผ่านหมด) แล้วยิง `WhenUseUlt_List` — `ultCondition` เพิ่มผ่าน `CharUnit::addUltCondition(function<bool()>)` (`Energy.h`)
