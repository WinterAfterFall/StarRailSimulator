# `src/Defination/Function/Combat/Dot.h`

DoT ในเอนจินนี้ **ไม่ใช่ระบบใหม่** แต่เป็นชั้นบาง ๆ ที่ซ้อนบนระบบดีบัฟ: ทุกฟังก์ชันในไฟล์นี้เรียก `debuffApply()` / `debuffMark()` / `calDebuffStack()` ของ [Debuff_Stats.md](Debuff_Stats.md) กับ [DebuffStack.md](DebuffStack.md) แล้ว **เพิ่มงานเดียว** คือดูแลตัวนับชนิด DoT ของศัตรูผ่าน `enemy->changeDotType(type, ±1)`

ตัวนับนี้มีไว้ให้ตัวละคร/Light Cone ที่อ่าน "ตอนนี้ศัตรูติด Shock/Burn/Bleed/Wind Shear กี่ชั้น" ได้ทันที เช่น Light Cone ของ Black Swan ที่ตรวจ `ShockCount`

แกนหลัก 3 เส้นทาง — **Apply** (ลงแล้วปล่อย event ทุกครั้ง) · **Mark** (ลงเงียบ ปล่อย event เฉพาะครั้งแรก) · **Stack** (ลงแบบนับชั้น) แต่ละเส้นมี `dotSingle*` เป็นตัวจริง แล้วมี `dotAllEnemy*` / `dotEnemyTargets*` เป็น loop ครอบ

## การเพิ่มและลบสถานะ

`dotSingleApply()` กับ `dotSingleMark()` เรียก `debuffApply()` / `debuffMark()` ก่อน แล้วเพิ่มตัวนับชนิด DoT ผ่าน `changeDotType(type, +1)` เฉพาะเมื่อเป็นสถานะใหม่; การแปะซ้ำจึงไม่เพิ่มตัวนับอีก overload ที่รับ `extend` ต่ออายุผ่านฝั่ง debuff ก่อนตรวจว่าเป็นสถานะใหม่

`dotSingleStack()` เทียบ stack เดิมกับค่าใหม่หลัง clamp: เพิ่มตัวนับชนิด DoT เมื่อเปลี่ยนจาก 0 เป็นบวก และลดเมื่อเปลี่ยนจากบวกเป็น 0; กรณี 0 → 0 ไม่เปลี่ยน `DotCount` หรือตัวนับรายชนิด (user ยืนยัน 2026-09-21) จากนั้นเรียก `calDebuffStack()` เพื่ออัปเดต stack และ `Total_debuff` โดยยังอัปเดตตัวนับชนิดก่อน `AfterApplyDebuff` เพื่อรักษาจังหวะที่ Light Cone ของ Black Swan ใช้ตรวจ `ShockCount` overload ที่รับ `extend` เรียก `extendDebuff()` หลังคำนวณ stack

เส้นทาง stack ของ DoT ใช้ `calDebuffStack()` เช่นเดียวกับดีบัฟทั่วไป จึงจำกัด stack อยู่ระหว่าง `0` และ `StackLimit` และใช้จำนวน stack ที่เปลี่ยนจริงเมื่อรับค่าเพิ่มหรือลด

`dotRemove()` ลดตัวนับชนิด DoT ตามรายการชนิดที่ส่งมา ส่วน `dotStackRemove()` ตั้ง stack ของสถานะชื่อที่ระบุเป็นศูนย์ผ่าน `debuffRemoveStack()` แล้วลดตัวนับชนิด DoT และคืนจำนวน stack ก่อนลบ ทั้งสองเมธอดไม่ลบ debuff flag หรือลด `Total_debuff` ด้วยตนเอง; ผู้เรียกจัดการอายุ debuff แยกต่างหาก

> ⚠️ `dotRemove()` และ `dotStackRemove()` ลด `changeDotType` **แบบไม่มีเงื่อนไข** จึงต้องเรียกเฉพาะตอนที่รู้แน่ว่าสถานะนั้นมีอยู่จริง — แพตเทิร์นที่ตั้งใจไว้คือคอมโบกับ `isDebuffEnd()` แบบเดียวกับฝั่งดีบัฟ (user ยืนยัน 2026-09-22 ดู [DebuffStack.md](DebuffStack.md)) คือให้ `isDebuffEnd()` เป็นคนตัดสินจังหวะหมดอายุและล้าง flag/`Total_debuff` แล้วสองฟังก์ชันนี้ตามมาเก็บตัวนับชนิด DoT · เรียกซ้ำเองนอกแพตเทิร์นนี้จะทำให้ตัวนับติดลบ · ปัจจุบัน **ยังไม่มีตัวละครไหนเรียก `dotStackRemove()`** (ตรวจทั้ง `src/Defination/Data` 2026-09-22)

## ตารางฟังก์ชันทั้งไฟล์

| ตัวจริง (เป้าเดียว) | loop ทุกศัตรู | loop เฉพาะเป้าหมาย | บรรทัด |
|---|---|---|---|
| `dotSingleApply(ptr, enemy, dotType, name[, extend])` | `dotAllEnemyApply(ptr, …)` | `dotEnemyTargetsApply(ptr, targets, …)` | 3–15 · 48–67 |
| `dotSingleMark(ptr, enemy, dotType, name[, extend])` | `dotAllEnemyMark(ptr, …)` | `dotEnemyTargetsMark(ptr, targets, …)` | 17–29 · 69–88 |
| `dotSingleStack(ptr, enemy, dotType, inc, limit, name[, extend])` | `dotAllEnemyStack(ptr, …)` | `dotEnemyTargetsStack(ptr, targets, …)` | 31–46 · 90–109 |
| `dotRemove(enemy, dotType)` · `dotStackRemove(enemy, dotType, name) → int` | — | — | 111–122 |

ฟังก์ชัน `dotAllEnemy*()` วน `enemyList`; `dotEnemyTargets*()` วนเฉพาะ vector เป้าหมายที่ส่งมา โดยส่งต่อไปยังเมธอด `dotSingle*()` ที่สอดคล้องกัน — ไม่มี logic เพิ่มเติม แปลว่า event ของฝั่งดีบัฟยิงหนึ่งชุดต่อศัตรูหนึ่งตัว

ฟังก์ชัน `dotEnemyTargetsStack(..., extend)` ต้องส่งค่า `extend` ต่อให้ `dotSingleStack()` ของทุกเป้าหมาย เพื่อให้ DoT แบบเพิ่ม stack พร้อมต่ออายุทำงานเหมือนกับการใช้กับศัตรูทั้งหมด

⚠️ ทุกฟังก์ชันรับ `vector<DotType>` ไม่ใช่ตัวเดียว — สถานะเดียวลงได้หลายชนิดพร้อมกัน และตัวนับจะขยับทุกชนิดในรายการพร้อมกัน

## สิ่งที่ไฟล์นี้ **ไม่ได้** ทำ

- **ไม่ได้คิดดาเมจ DoT** — การทำดาเมจเกิดตอนต้นเทิร์นศัตรูใน `allEventBeforeTurn()` ([Event.md](../Event/Event.md))
- **ไม่ได้บวก stat ใด ๆ** — DoT ในเอนจินนี้เป็นสถานะ + ตัวนับล้วน ถ้าต้องการให้ลด stat ด้วยต้องเรียกฝั่ง `debuffSingle*()` แยก
- **ไม่ได้จัดการอายุเอง** ยกเว้น overload ที่รับ `extend` ซึ่งก็แค่ส่งต่อให้ `extendDebuff()`

## ที่อธิบายไว้ไฟล์อื่น

- Break DoT (Burn/Shock/Wind Shear/Bleed ที่เกิดจากการทุบ toughness) กับการหมดอายุของมัน → [Event.md](../Event/Event.md) และ [BUGS.md](../../BUGS.md) #21
- `changeDotType` · `DotCount` · ตัวนับรายชนิด ในฐานะ field ของศัตรู → [Enemy.md](../../Class/Unit/Enemy.md)
- `debuffRemoveStack()` และกติกา `Total_debuff` → [DebuffStack.md](DebuffStack.md)
- `enum DotType` → [Enum.md](../../Enum/Enum.md)
