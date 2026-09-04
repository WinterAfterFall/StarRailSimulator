# สิ่งที่น่าปรับปรุงภายหลัง

รายการงานปรับปรุง engine ที่รู้แล้วว่าควรทำ แต่ยังไม่ทำตอนนี้ (ไม่เร่ง / กระทบหลายจุด / รอตัดสินใจ)
คู่กับหัวข้อ 🐞 ใน [`unit.md`](unit.md) (บั๊กเฉพาะโซน Unit)

---

## 1. การถอนค่า buff เมื่อหมดอายุ — framework ไม่ทำให้

**สภาพตอนนี้:** framework track บัฟแค่ 2 อย่าง — `Buff_check` (bool ว่ามีบัฟอยู่ไหม) กับ `Buff_countdown` (turnCnt เป้าหมายที่บัฟจะหมด) — **ไม่เก็บขนาด delta** ของ stat ที่บวกไป

เวลาบัฟหมดอายุ ตัวละครต้อง **ถอนค่า stat เอง** ด้วยมือ โดยเช็คผ่าน `isBuffEnd()` / `isBuffGoneByDeath()`

- `isBuffEnd(ptr, name)` (`Buff_Stats.h:21`) — คืน `true` เฉพาะตอนเป็นเทิร์นของ `ptr` เอง **และ** `turnCnt` แตะค่า countdown → เคลียร์ `Buff_check`/`Buff_countdown` ให้ แต่ **ไม่แตะ stat**
- `isBuffGoneByDeath(ptr, name)` (`Buff_Stats.h:29`) — ใช้ตอน ally ตาย หรือตอน retarget บัฟ (unit ไม่มีเทิร์นให้ `isBuffEnd` ยิง) — เคลียร์ flag เหมือนกัน **ไม่แตะ stat**

pattern มาตรฐาน (ดู `Tingyun.h:156-165` `After_turn_List`):

```cpp
auto expire = [ptr](const string &name, Stats stat, double value) {
    AllyUnit *h = ptr->getBuffSubUnitTarget(name);
    if (h && isBuffEnd(h, name)) buffSingle(h, {{stat, AType::None, -value}});  // ถอนเอง
};
expire(BUFF_BENEDICTION, Stats::ATK_P, BENEDICTION_ATK);
```

ทุกตัวละครที่มีบัฟติดเวลาต้องเขียน `After_turn_List` + `AllyDeath_List` แบบนี้เอง — ซ้ำ ๆ และพลาดง่าย (ลืมถอน = buff drift)

**ที่น่าทำ:** helper กลางที่ผูก "ขนาด delta + stat + target" เข้ากับชื่อบัฟตอน apply แล้ว auto ถอนตอน `Buff_countdown` แตะ / ตาย — ตัวละครไม่ต้องเขียน expiry เอง

---

## 2. ระบบ "สร้าง" โล่ (shield) ยังเป็น stub

ดู [`unit.md` ภาคผนวก 🛡️](unit.md) — `decreaseSheild()` แก้แล้ว แต่ยังไม่มีโค้ดไหน **เพิ่ม** `currentSheild`
ค้าง: อ่าน `Stats_type[SHEILD]` เป็นตัวคูณ outgoing shield, เพิ่ม `currentSheild`, countdown/ถอนเหมือนบัฟ, ปลด comment Aventurine

---

## 3. refactor: summon / countdown ให้เป็นแค่ `ActionValueStats` (atv ล้วน ๆ)

**สภาพตอนนี้:** `SetSummonStats` / `SetCountdownStats` (`StatsSet.h:55-77`) สร้าง object เป็น `AllyUnit` (เก็บใน `vector<unique_ptr<Unit>>`) แต่ใช้แค่ส่วน atv จริง ๆ — ไม่มี HP / ไม่โดนตี / ไม่รับบัฟ stat. และ **ไม่เซ็ต `owner`** (ต่างจาก `SetMemoStats` ที่เซ็ต `owner = ptr`)

ผลข้างเคียงที่ตามมา (ทั้งหมด "latent" — ยังเกิดไม่ได้เพราะกำแพง type):
- `buffSingle` path บัฟ speed (`Buff_Stats.h:88,99`) → `ahaSpeedAdjust(ptr->owner->path[0])` → null deref ถ้า `ptr` เป็น summon/countdown
- `speedBuff` บน unit ที่ `baseSpeed <= 0` → ตัวเลขสะสมเงียบ ๆ แล้วเด้งมามีผลทีหลัง (หัวข้อ 2.2 ใน `unit.md`)

**ทางแก้ที่ user เลือก:** refactor ให้ summon/countdown เป็น **`ActionValueStats` ตรง ๆ** (เหมือน `aha`) ไม่ใช่ `AllyUnit` → ไม่มี `owner` / `Stats_type` / buff maps ที่ไม่ได้ใช้ → ปัญหา `owner==nullptr` + speed-buff-สะสม หายไปทั้งชุด · งานที่ต้องทำ: เปลี่ยน `summonList`/`countdownList` เป็น `vector<unique_ptr<ActionValueStats>>`, ปรับ `Turn_func` / `summon()` / reset ให้เข้ากับ interface ใหม่, ไล่ทุกจุดที่ cast `summonList[i].get()` เป็น `Unit*`/`AllyUnit*`

---

## 4. AllyUnit — cosmetic cleanup (ไม่กระทบพฤติกรรม)

- `AllyUnit.h:98` `#pragma region Getters` ข้างในเป็น setter · `:140` `#pragma region Setters` ข้างในเป็น getter — สลับ label
- `setDefaultTargetNum(int ally, int AllyUnit)` / `setCurrentTargetNum(...)` — พารามิเตอร์ชื่อ `AllyUnit` ชนชื่อคลาส
- `CharUnit` redeclare accessor ชุด `setStack`/`getStack`/... ที่ `AllyUnit` มีอยู่แล้ว — ซ้ำซ้อน
- `Unit::isExsited()` — typo (`isExisted`)
- `Unit/Library.h` — `#include "AllyUnit.h"` ซ้ำ 2 บรรทัด
- ~~`tauntMtprChange` / no-arg `calHitChance()` / `totalTaunt` dead code~~ ✅ ลบ/ปรับแล้ว (2026-09-04) — `tauntMtpr` → `tauntIncrease` (0 = ไม่มี), เหลือ `tauntIncreaseChange(double)` ต่อสายไว้รอ trace "taunt +X%" (ดู `unit.md` 🐞 #12)

---

## 5. per-unit `priority` ไม่ reset หลังเล่นเทิร์นจบ

`priority` (ต่อ unit) reset เป็น 0 แค่ตอน `Basic_reset` (**ต่อ run**) — ภายใน run ตัวที่เคยโดน `Action_forward` จน atv แตะ 0 จะค้าง `priority` สูง แม้เล่นเทิร์นไปแล้ว (ข้าม wave ด้วย)
- ผลเฉพาะเคส `atv` เท่ากันเป๊ะ (speed เท่ากันเป๊ะ ไม่มีบัฟต่างกัน) ใน `Find_turn` → ตัวที่ค้าง `priority` สูงชนะ tie ซ้ำ ๆ
- เกิดยากมาก — _รอ user ตัดสินว่าจะ reset `priority` หลังเล่นเทิร์นจบไหม_

> **หมายเหตุ #14B (memosprite baseSpeed snapshot):** ไม่ได้อยู่ในลิสต์นี้แล้ว — user ยืนยันว่า **ตั้งใจ** (memo เอาแค่ relic + stat เจ้าของ ณ ต้น run, บัฟสปีดกลางรบของเจ้าของไม่ส่งผล เว้นบัฟที่ยิงใส่ memo ตรง ๆ) → ย้ายไปเป็น "พฤติกรรมที่ documented" ใน `unit.md` หัวข้อ 4.7
