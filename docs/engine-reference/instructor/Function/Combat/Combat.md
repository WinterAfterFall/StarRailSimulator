# `src/Defination/Function/Combat/Combat.h`

## `Deal_damage()` กับ `actionBarUse`

User ยืนยัน 2026-09-17: `actionBarUse` ใช้กันการประมวลผลคิวซ้อน เพื่อให้แอ็กชันปัจจุบันจบก่อนทำรายการถัดไป

จากโค้ด: หาก `actionBarUse` เป็น `true` จะกลับทันที มิฉะนั้นตั้งเป็น `true` แล้ววนประมวลผล `Action_bar` จากหัวคิวจนว่าง แอ็กชันที่เพิ่มเข้าคิวระหว่างนี้รอให้ลูปเดิมทำต่อ เมื่อจบจึงคืน `actionBarUse` เป็น `false` และคืน `phaseStatus` เป็นค่าก่อนเข้าฟังก์ชัน

## จังหวะตรวจ Ultimate

User อธิบาย 2026-09-17 ว่าเจตนาคือตรวจ 2 จังหวะ: หลังจบแอ็กชันใด ๆ และหลังจบ before-turn event ของตัวละครในเทิร์น AllyUnit

จุดเรียกที่ตรวจพบในโค้ดปัจจุบัน:

- `Deal_damage()`: หลัง `allEventAfterAction(temp)` เรียก `allUltimateCheck()` เมื่อ `turn` ไม่เป็น null ก่อนนำแอ็กชันออกจากคิว
- `Take_action()`: เรียกหลังบล็อก `allEventBeforeTurn()` ก่อน `Turn_func()` เฉพาะเมื่อ `turn->canCastToAllyUnit()` คืน pointer ที่ไม่เป็น null; ยังเรียกเมื่อ `extraTurn` ทำให้ข้าม before-turn event
- User ยืนยันว่าการไม่ตรวจหลังแต่ละแอ็กชันใน `AhaInstantBar` ถูกต้องแล้ว กฎหลังจบแอ็กชันข้างต้นใช้กับคิว `Action_bar`
- User แก้โค้ด 2026-09-17: เพิ่มเงื่อนไข `canCastToAllyUnit` และลบจุดเรียกก่อน `allEventAfterTurn()` แล้ว จึงเหลือสองตำแหน่งข้างต้นใน `Combat.h`

## `aha` — pseudo-unit ของทีม Elation

`aha` (`Setting.h:80`) = `unique_ptr<ActionValueStats>` ชื่อ `"Aha"` speed 80 — สร้างจาก `ActionValueStats` ตรง ๆ **ไม่มี object `Unit`** อยู่เบื้องหลัง → `charptr` เป็น `nullptr` ตลอด

- **วิ่งอยู่บนลู่ atv แย่งเทิร์นกับตัวละครจริง** — ถูก push เข้า `atvList` ที่ `SetCombat.h:65` **เฉพาะเมื่อ `elationCount != 0`** (มีสมาชิก Elation ในทีม)
- **ไม่มีตัวตนในสนาม** — ไม่มี HP / ไม่โดนตี / ไม่โดนบัฟ. หน้าที่เดียว = trigger `AhaInstant` ตามเวลาที่ atv พามันถึงเทิร์น
- พอ `aha` ชนะ `Find_turn` → `turn->charptr == nullptr` → `Take_action` (`Combat.h:5`) แตกไป `AhaTurn()` (`Combat.h:31`): `++aha->turnCnt` → `BeforeAhaInstant()` → วน `ElationSkill_List` → drain `AhaInstantBar` → แจกบัฟ `CertifiedBanger` ให้สมาชิก Elation → `AfterAhaInstant()` → `resetTurn(aha)` (เริ่มนับรอบใหม่)
- speed ของ `aha` ปรับด้วย `ahaSpeedAdjust(path)` (`Action_value.h:93`) — คิดจาก speed ของสมาชิก Elation ที่เรียงมากไปน้อย: `flatSpeed = spd₁/5 + spd₂/10 + spd₃/15 + …`

> ⚠️ ตาราง field ใน [ActionValueStats.md](../../Class/Unit/ActionValueStats.md) บอก `charptr` "เซ็ตใน `Unit()` ctor เสมอ" — จริงสำหรับทุกตัว **ยกเว้น `aha`** ที่ตั้งใจให้เป็น null

## `Turn_Skip` (global bool, `Setting.h:72`)

บังคับข้ามเทิร์น (CC เช่น Freeze) — `Take_action()`: `if(Turn_Skip==0){ Turn_func(); Deal_damage(); }`
- ตั้ง = 1: `Event.h:19` (enemy โดน Freeze กินเทิร์น) · `Ruan_Mei.h:104`
- reset = 0: ทุกรอบ loop (`Main.h:46` / `ManualBuilder.cpp:155`)
- before/after-turn events **ยังยิงปกติ** — ข้ามแค่ action; จุดตรวจ Ultimate ก่อน action ยังเรียกเมื่อ `turn->canCastToAllyUnit` เป็นจริง

**enemy ที่โดน freeze ทำไมไม่โดน `Find_turn` เลือกซ้ำทันที** (atv มันยัง ~0 อยู่) — คำตอบอยู่ที่ `Event.h:13-22` ใน `allEventBeforeTurn` (`side == Enemy`): ถ้าเจอ entry ใน `breakFrzList`
1. `Cal_Freeze_damage` — คิดดาเมจ freeze
2. **`Action_forward(enemy->Atv_stats.get(), -50)`** — `fwd` ติดลบ → เข้า else branch ของ `Action_forward` → `atv = atv - Max_atv*(-50)/100` = **`atv += 0.5 * Max_atv`** (ดัน atv ถอยหลังครึ่งบาร์)
3. `Turn_Skip = 1`
4. `breakFrzList.erase(itr)` + `break`

ขั้นที่ 2 คือกลไกที่ทำให้ enemy เลื่อนออกจากตำแหน่ง "ตัวถัดไป" — ไม่งั้น loop วนเลือกมันซ้ำไม่จบ. รอบหน้า freeze ถูกลบไปแล้ว → เล่นเทิร์นปกติ
