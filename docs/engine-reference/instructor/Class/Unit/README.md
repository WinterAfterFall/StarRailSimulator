# `src/Defination/Class/Unit/`

## Include graph
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
> ~~`Unit/Library.h` `#include "AllyUnit.h"` ซ้ำ 2 บรรทัด~~ ✅ ลบบรรทัดซ้ำแล้ว (2026-09-13)

## ลำดับชั้น
```
Unit  ────────────────┬─ AllyUnit ──┬─ CharUnit  (ตัวละครผู้เล่น; owner = this)
 (ถือ ActionValueStats)│             ├─ Memosprite (owner = CharUnit เจ้าของ)
                       │             └─ (summon/countdown ใช้ AllyUnit ดิบ ๆ ผ่าน SetSummonStats/SetCountdownStats)
                       └─ Enemy
```
