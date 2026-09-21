# สิ่งที่น่าปรับปรุงภายหลัง

รายการงานปรับปรุง engine ที่รู้แล้วว่าควรทำ แต่ยังไม่ทำตอนนี้ (ไม่เร่ง / กระทบหลายจุด / รอตัดสินใจ)
คู่กับ [`instructor/BUGS.md`](instructor/BUGS.md) (บั๊กที่เจอระหว่างไล่โค้ด)

---

## ตัวเลือกศัตรูแบบ interactive ยังไม่ implement ครบ

User ยืนยัน 2026-09-21 ว่าตอนนี้ตั้งใจ fix ศัตรูไว้ 2 ตัวชั่วคราวใน `SettingFunction.h::EnemySelector()` คำถามจำนวนศัตรู (`Tenemy`) ยังไม่ถูกนำไปใช้ และทางเลือกกำหนดสถานะศัตรูเองยังไม่มีขั้นตอนสร้างศัตรู งานภายหลังคือเชื่อมจำนวนที่เลือกกับการสร้างศัตรู และ implement การรับค่าศัตรูแบบกำหนดเอง โดยคงทางลัดค่าตั้งต้น 2 ตัวไว้ตามต้องการ

---

## 1. การถอนค่า buff เมื่อหมดอายุ — framework ไม่ทำให้

**สภาพตอนนี้:** framework track บัฟแค่ 2 อย่าง — `buffCheck` (bool ว่ามีบัฟอยู่ไหม) กับ `buffEnd` (turnCnt เป้าหมายที่บัฟจะหมด) — **ไม่เก็บขนาด delta** ของ stat ที่บวกไป

เวลาบัฟหมดอายุ ตัวละครต้อง **ถอนค่า stat เอง** ด้วยมือ โดยเช็คผ่าน `isBuffEnd()` / `isBuffGoneByDeath()`

- `isBuffEnd(ptr, name)` (`Buff_Stats.h:21`) — คืน `true` เฉพาะตอนเป็นเทิร์นของ `ptr` เอง **และ** `turnCnt` แตะค่า countdown → เคลียร์ `buffCheck`/`buffEnd` ให้ แต่ **ไม่แตะ stat**
- `isBuffGoneByDeath(ptr, name)` (`Buff_Stats.h:29`) — ใช้ตอน ally ตาย หรือตอน retarget บัฟ (unit ไม่มีเทิร์นให้ `isBuffEnd` ยิง) — เคลียร์ flag เหมือนกัน **ไม่แตะ stat**

pattern มาตรฐาน (ดู `Tingyun.h:155` `After_turn_List`):

```cpp
auto expire = [ptr](const string &name, Stats stat, double value) {
    AllyUnit *h = ptr->getBuffSubUnitTarget(name);
    if (h && isBuffEnd(h, name)) buffSingle(h, {{stat, AType::None, -value}});  // ถอนเอง
};
expire(BUFF_BENEDICTION, Stats::ATK_P, BENEDICTION_ATK);
```

ทุกตัวละครที่มีบัฟติดเวลาต้องเขียน `After_turn_List` + `AllyDeath_List` แบบนี้เอง — ซ้ำ ๆ และพลาดง่าย (ลืมถอน = buff drift)

**ที่น่าทำ:** helper กลางที่ผูก "ขนาด delta + stat + target" เข้ากับชื่อบัฟตอน apply แล้ว auto ถอนตอน `buffEnd` แตะ / ตาย — ตัวละครไม่ต้องเขียน expiry เอง

---

## 2. ระบบ "สร้าง" โล่ (shield) ยังเป็น stub

ดู [`instructor/Function/Combat/ChangeHP.md`](instructor/Function/Combat/ChangeHP.md) (ระบบโล่) — `decreaseSheild()` แก้แล้ว แต่ยังไม่มีโค้ดไหน **เพิ่ม** `currentSheild`
ค้าง: อ่าน `Stats_type[SHEILD]` เป็นตัวคูณ outgoing shield, เพิ่ม `currentSheild`, countdown/ถอนเหมือนบัฟ, ปลด comment Aventurine

## 3. ป้องกันตัวนับดีบัฟรวมติดลบ

ปัจจุบัน `debuffRemove()` ลด `Total_debuff` โดยตรง ควรตรวจว่า debuff นั้น active อยู่ก่อนลด และ clamp ค่า `Total_debuff` ขั้นต่ำเป็น 0 เพื่อรองรับการเรียกล้างซ้ำในอนาคต ปัจจุบันยังไม่พบอาการผิดพลาด จึงเก็บไว้เป็นงานปรับปรุงภายหลัง

---

## 4. refactor: summon / countdown ให้เป็นแค่ `ActionValueStats` (atv ล้วน ๆ)

**สภาพตอนนี้:** `SetSummonStats` / `SetCountdownStats` (`StatsSet.h:55-77`) สร้าง object เป็น `AllyUnit` (เก็บใน `vector<unique_ptr<Unit>>`) แต่ใช้แค่ส่วน atv จริง ๆ — ไม่มี HP / ไม่โดนตี / ไม่รับบัฟ stat. และ **ไม่เซ็ต `owner`** (ต่างจาก `SetMemoStats` ที่เซ็ต `owner = ptr`)

ผลข้างเคียงที่ตามมา (ทั้งหมด "latent" — ยังเกิดไม่ได้เพราะกำแพง type):
- `buffSingle` path บัฟ speed (`Buff_Stats.h:88,99`) → `ahaSpeedAdjust(ptr->owner->path[0])` → null deref ถ้า `ptr` เป็น summon/countdown
- `speedBuff` บน unit ที่ `baseSpeed <= 0` → ตัวเลขสะสมเงียบ ๆ แล้วเด้งมามีผลทีหลัง ([`instructor/Function/Combat/Action_value.md`](instructor/Function/Combat/Action_value.md))

**ทางแก้ที่ user เลือก:** refactor ให้ summon/countdown เป็น **`ActionValueStats` ตรง ๆ** (เหมือน `aha`) ไม่ใช่ `AllyUnit` → ไม่มี `owner` / `Stats_type` / buff maps ที่ไม่ได้ใช้ → ปัญหา `owner==nullptr` + speed-buff-สะสม หายไปทั้งชุด · งานที่ต้องทำ: เปลี่ยน `summonList`/`countdownList` เป็น `vector<unique_ptr<ActionValueStats>>`, ปรับ `Turn_func` / `summon()` / reset ให้เข้ากับ interface ใหม่, ไล่ทุกจุดที่ cast `summonList[i].get()` เป็น `Unit*`/`AllyUnit*`

---

## 5. AllyUnit — cosmetic cleanup (ไม่กระทบพฤติกรรม)

- `AllyUnit.h:98` `#pragma region Getters` ข้างในเป็น setter · `:140` `#pragma region Setters` ข้างในเป็น getter — สลับ label
- `setDefaultTargetNum(int ally, int AllyUnit)` / `setCurrentTargetNum(...)` — พารามิเตอร์ชื่อ `AllyUnit` ชนชื่อคลาส
- `CharUnit` redeclare accessor ชุด `setStack`/`getStack`/... ที่ `AllyUnit` มีอยู่แล้ว — ซ้ำซ้อน
- ~~`Unit::isExsited()` — typo (`isExisted`)~~ ✅ แก้แล้ว 2026-09-13
- `Unit/Library.h` — `#include "AllyUnit.h"` ซ้ำ 2 บรรทัด
- `src/Declaration/Class/Class.h` ประกาศ `class CharUnit;` ซ้ำ และ `src/Declaration/Function/Print/Print.h` ประกาศ `void printRoundResult();` ซ้ำ — เก็บกวาดได้โดยไม่เปลี่ยนพฤติกรรม
- `debuffEnemyTargetsyMark()` ใน declaration/definition สะกด `Targetsy` ไม่สอดคล้องกับ `debuffEnemyTargetsApply()`; ยังไม่พบ caller ใน `src/Defination` หากจะเปลี่ยนชื่อควรค้นทั้งโปรเจกต์ก่อน
- ~~`tauntMtprChange` / no-arg `calHitChance()` / `totalTaunt` dead code~~ ✅ ลบ/ปรับแล้ว (2026-09-04) — `tauntMtpr` → `tauntIncrease` (0 = ไม่มี), เหลือ `tauntIncreaseChange(double)` ต่อสายไว้รอ trace "taunt +X%" (ดู [`instructor/BUGS.md`](instructor/BUGS.md) #12)

### Refactor ระบบเลือกเป้าหมายบัฟ

ปัจจุบันเป้าหมายเก็บแยกเป็น `defaultCharNum`/`defaultMemoNum` และ `currentCharNum`/`currentMemoNum` โดยใช้ magic value: sub-unit `0` หมายถึงตัวละคร ส่วน `1..N` หมายถึง memosprite ลำดับที่ 1..N แล้ว `chooseAllyBuff()` ต้องลบ 1 ก่อนเข้าถึง vector (แก้บั๊ก off-by-one แล้ว 2026-09-18)

ภายหลังควรรวมสองเลขเป็น target descriptor ที่ระบุชนิดเป้าหมายกับ index อย่างชัดเจน เปลี่ยนชื่อ `MemoNum` ให้ครอบคลุมความหมายของ sub-unit และเพิ่ม bounds validation เพื่อไม่ให้ configuration ที่ผิดกลายเป็น out-of-bounds access

---

## 7. ตรวจ owner ด้วยชื่อแบบ `string` — อาจ implement ภายหลัง

User ขอให้จดไว้ 2026-09-17; ยังไม่ implement และยังไม่ได้กำหนดว่าจะทำเมื่อใด

อาจเพิ่ม overload รับชื่อ owner แบบ `string` ให้ `isSameOwnerName`, `isSameOwnerAction` และ `isSameOwnerDamageType` ซึ่งปัจจุบันรับ `CharUnit*` เพื่อให้ตรวจได้ทั้งตัวละครเจ้าของและยูนิตของเจ้าของด้วยกติกาเดียวกับแบบ pointer เช่น ชื่อ `Castorice` ตรงกับทั้ง Castorice และ Netherwing

---

## 6. per-unit `priority` ไม่ reset หลังเล่นเทิร์นจบ

`priority` (ต่อ unit) reset เป็น 0 แค่ตอน `Basic_reset` (**ต่อ run**) — ภายใน run ตัวที่เคยโดน `Action_forward` จน atv แตะ 0 จะค้าง `priority` สูง แม้เล่นเทิร์นไปแล้ว (ข้าม wave ด้วย)
- ผลเฉพาะเคส `atv` เท่ากันเป๊ะ (speed เท่ากันเป๊ะ ไม่มีบัฟต่างกัน) ใน `Find_turn` → ตัวที่ค้าง `priority` สูงชนะ tie ซ้ำ ๆ
- เกิดยากมาก — _รอ user ตัดสินว่าจะ reset `priority` หลังเล่นเทิร์นจบไหม_

> **หมายเหตุ #14B (memosprite baseSpeed snapshot):** ไม่ได้อยู่ในลิสต์นี้แล้ว — user ยืนยันว่า **ตั้งใจ** (memo เอาแค่ relic + stat เจ้าของ ณ ต้น run, บัฟสปีดกลางรบของเจ้าของไม่ส่งผล เว้นบัฟที่ยิงใส่ memo ตรง ๆ) → ย้ายไปเป็น "พฤติกรรมที่ documented" ใน [`instructor/Function/Setup/Stats_Reset.md`](instructor/Function/Setup/Stats_Reset.md)

---

## 8. `Cal_Toughness_reduction` — ตัดเงื่อนไขตรวจ Weakness หลังศัตรู Broken

ปัจจุบันเงื่อนไขไม่ลด Toughness เมื่อโจมตีไม่ตรง Weakness จะตรวจเฉพาะตอน `Current_toughness > 0` ทำให้หลังศัตรู Broken แล้วโค้ดยังเดินเข้าส่วนลด Toughness ต่อได้ แม้เงื่อนไขนั้นจะไม่จำเป็นต่อช่วง Broken

ผู้ใช้เห็นว่าเป็นโค้ดที่ไม่จำเป็น แต่ยังไม่ต้องแก้พฤติกรรมตอนนี้ ควรพิจารณาตัดเงื่อนไขหรือแยกเส้นทางหลัง Broken ในการ refactor ครั้งถัดไป

6-16
