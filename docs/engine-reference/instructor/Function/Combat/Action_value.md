# `src/Defination/Function/Combat/Action_value.h`

## ฟังก์ชันระบบ ATV (`src/Defination/Function/Combat/Action_value.h`)

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

> **speedBuff บน unit ที่ `baseSpeed <= 0`:** unit ที่ baseSpeed ติดลบ **ไม่ได้ถูกห้ามรับบัฟ** — แต่ `speedBuff` บวก `flatSpeed`/`speedPercent` เข้าไปแล้ว `Update_Max_atv` เจอ `baseSpeed <= 0` `return` ก่อน → `Max_atv` ค้าง `1e6` บัฟสปีดเลยไม่มีผลจนกว่าจะมี `resetATV(สปีดบวก)`. ในทางปฏิบัติ **countdown / summon รับบัฟสปีดไม่ได้อยู่แล้ว** (เป็น `unique_ptr<Unit>` ส่งเข้า `buffSingle(AllyUnit*)` ไม่ได้ + ไม่อยู่ใน `allyList`) และ**ไม่มีโค้ดไหนแจกบัฟสปีดให้ countdown** → เคสนี้เกิดไม่ได้. **แผนอนาคต:** refactor ให้ countdown/summon เป็นแค่ `ActionValueStats` (atv ล้วน ๆ ไม่ใช่ `AllyUnit`) → ปัญหานี้ + `owner==nullptr` หายไปเอง (ดู [`future-improvements.md`](../../../future-improvements.md))
