# `src/Defination/Function/Combat/AdjustStats.h`

## `statsAdjust(ptr, statsType)`

จากโค้ด: ถ้า stat ที่เปลี่ยนเป็น ATK% / flat ATK → `atkAdjust`, HP% / flat HP → `hpAdjust`, DEF% / flat DEF → `defAdjust` (คำนวณ `totalATK` / `totalHP` / `totalDEF` ใหม่ผ่าน `calculate*OnStats`) แล้วปล่อย `allEventAdjustStats(ptr, statsType)` เฉพาะเมื่อ `adjustCheck == 0`

## `adjustCheck` (`Setting.h:70`)

User ยืนยัน 2026-09-20: เป็นตัวกันวนซ้ำ (recursion guard) — `allEventAdjustStats` ตั้งเป็น `1` ระหว่างวน `statsAdjustList` (`Event.h:203-207`) เพื่อให้ trigger ที่แปลง/เปลี่ยนสเตตัสไม่ปล่อย event ปรับสเตตัสซ้อนจนวนไม่จบ

## `hpAdjust`

จากโค้ด: maxHP เพิ่ม x → currentHP เพิ่ม x; maxHP ลดจนต่ำกว่า currentHP → clamp เท่า maxHP; ลดแต่ยังสูงกว่า → currentHP คงเดิม (ที่มาของการแก้ดู [BUGS.md](../../BUGS.md) #9)
