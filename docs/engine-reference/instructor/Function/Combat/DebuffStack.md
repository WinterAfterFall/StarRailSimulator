# `src/Defination/Function/Combat/DebuffStack.h`

ชั้น stack ของฝั่งศัตรู — คู่ขนานกับ [BuffStack.md](BuffStack.md) แต่มีงานเพิ่มอีก 2 อย่างที่ฝั่ง ally ไม่มี: **ปล่อย event ตอนลงดีบัฟ** และ **ดูแลตัวนับ `Total_debuff`**

โครงไฟล์: `calDebuffStack` (คิดเลข + event + ตัวนับ) · `debuffRemoveStack` (เคลียร์ stack ดิบ) → `debuffStackSingle` / `debuffStackRemove` (ยิงใส่ศัตรูตัวเดียว) → `debuffStackAll` / `debuffStackEnemyTargets` (กระจายเป้าหมาย)

## แกนกลาง — `calDebuffStack()` (บรรทัด 3)

```cpp
allEventBeforeApplyDebuff(ptr, enemy);
int current = enemy->getStack(debuffName);
int next    = min(StackLimit, max(0, current + Stack_increase));
int applied = next - current;
if      (current == 0 && next > 0) enemy->addTotalDebuff(1);
else if (current > 0 && next == 0) enemy->addTotalDebuff(-1);
enemy->addStack(debuffName, applied);
allEventAfterApplyDebuff(ptr, enemy);
return {applied, next};
```

สี่เรื่องที่ต้องจำ:

1. **clamp `0 .. StackLimit`** และคืน `applied` = ส่วนต่างจริง เหมือน `calStack()` ฝั่ง ally — มี 1 stack แล้วสั่งลด 3 จะลดจริงแค่ 1 และค่าที่เอาไปคูณ `debuffSet` คือค่าที่ลดจริง ไม่ใช่ค่าที่ขอ
2. **`Total_debuff` นับที่ "มี/ไม่มี" ไม่ใช่จำนวน stack** — เพิ่มเมื่อ 0 → บวก, ลดเมื่อ บวก → 0, กรณี 0 → 0 ไม่ขยับ (User ยืนยัน 2026-09-21 ว่าสถานะ stack 0 ไม่ควรถูกนับใน `Total_debuff`) มี regression test ที่ `test/debuff_zero_stack_regression.cpp`
3. **event ยิงทุกครั้งที่เรียก** แม้ `applied == 0` — ต่างจาก `debuffMark()` ที่ยิงเฉพาะตอนสร้างสถานะใหม่ (ดู [Debuff_Stats.md](Debuff_Stats.md))
4. ตัวนับชนิด DoT (`changeDotType`) **ไม่ได้อยู่ในนี้** — `dotSingleStack()` เป็นคนจัดการเองก่อนเรียกฟังก์ชันนี้ ดู [Dot.md](Dot.md)

## `debuffRemoveStack()` (บรรทัด 14)

```cpp
int ans = enemy->getStack(debuffName);
enemy->setStack(debuffName, 0);
return ans;                       // คืน stack ก่อนล้าง
```

เป็น primitive ดิบล้วน — **ไม่ปล่อย event · ไม่แตะ `debuffCheck` flag · ไม่ลด `Total_debuff`** ผู้เรียกต้องจัดการเองทั้งหมด ผู้เรียกปัจจุบันมี 2 ตัว: `debuffStackRemove()` ในไฟล์นี้ และ `dotStackRemove()` ใน `Dot.h:117`

### กติกา: ใช้คู่กับ `isDebuffEnd()` เสมอ (user ยืนยัน 2026-09-22)

การที่ฟังก์ชันนี้ไม่ลด `Total_debuff` **เป็นการออกแบบ ไม่ใช่บั๊ก** — มันถูกใช้เป็นคอมโบคู่กับ `isDebuffEnd()` ซึ่งเป็นคนเรียก `debuffRemove()` ที่ล้าง flag และลด `Total_debuff` ให้แล้ว ถ้า `debuffRemoveStack()` ลดเองด้วยจะกลายเป็นลดสองรอบ

แพตเทิร์นที่ตัวละครใช้จริง (เช่น `Black Swan.h:117-125`) คือ:

```cpp
if(isDebuffEnd(enemy, "ชื่อดีบัฟ")){      // ถึงเทิร์นหมดอายุ → ล้าง flag + Total_debuff -1
    debuffSingle(enemy, {…ค่าติดลบ…});    // แล้วค่อยถอน stat ที่เคยบวกไว้
}
```

`debuffStackRemove()` คือเวอร์ชันสำเร็จรูปของสองบรรทัดนี้สำหรับดีบัฟที่มี stack — ผู้เรียกยังต้องเป็นคนตัดสินจังหวะหมดอายุผ่าน `isDebuffEnd()` เองอยู่ดี

⚠️ ปัจจุบัน **ยังไม่มีตัวละครไหนเรียก `debuffStackRemove()`** (ตรวจทั้ง `src/Defination/Data` 2026-09-22) เป็นเครื่องมือที่เตรียมไว้

## `debuffStackRemove()` (บรรทัด 20–33, 2 overload)

ถอนบัฟลบทั้งกองในครั้งเดียว — รูปแบบเดียวกับ `buffResetStack()` ฝั่ง ally:

```cpp
int stack = debuffRemoveStack(enemy, debuffName);   // เคลียร์ stack แล้วคืนค่าเดิม
e.value *= -stack;                                  // คูณลบ = หักออกให้หมดพอดี
debuffSingle(enemy, debuffSet);
```

ต้องส่ง `debuffSet` ชุดเดียวกับตอนแจก ไม่งั้น stat ของศัตรูจะไหล

## `debuffStackSingle()` — 4 overload (บรรทัด 34–63)

`BuffClass` / `BuffElementClass` × มี/ไม่มี `extend` ทุกตัวทำ 3 จังหวะเหมือนกัน: `calDebuffStack()` → คูณ `applied` ลง `debuffSet` → `debuffSingle()` · overload ที่มี `extend` เรียก `extendDebuff()` **ต่อท้ายสุด**

⚠️ ลำดับนี้กลับด้านกับฝั่ง ally: `buffStackSingle()` ต่ออายุ **ก่อน** บวกค่า ส่วนที่นี่ต่ออายุ **หลัง**

## wrapper กระจายเป้าหมาย

| ฟังก์ชัน | บรรทัด | วนอะไร |
|---|---|---|
| `debuffStackAll(AllyUnit*, …)` | 64–86 | `enemyList` ทั้งหมด |
| `debuffStackEnemyTargets(AllyUnit*, vector<Enemy*>, …)` | 88–110 | เฉพาะรายการเป้าหมายที่ส่งมา |

ทั้งคู่มีครบ 4 คอมบิเนชัน (`BuffClass`/`BuffElementClass` × มี/ไม่มี `extend`) และเป็น loop บาง ๆ รอบ `debuffStackSingle()` ไม่มี logic เพิ่ม — แปลว่า **event `BeforeApplyDebuff`/`AfterApplyDebuff` ยิงหนึ่งคู่ต่อศัตรูหนึ่งตัว** ไม่ใช่หนึ่งคู่ต่อการเรียกหนึ่งครั้ง

⚠️ ยังไม่มี wrapper `debuffStackRemove` แบบกระจายเป้าหมาย (all / targets) — ถ้าต้องถอนหลายตัวต้องวนเรียกเอง

## ที่อธิบายไว้ไฟล์อื่น

- `debuffSingle()` · `debuffApply()` · `debuffMark()` · `extendDebuff()` · `isDebuffEnd()` → [Debuff_Stats.md](Debuff_Stats.md)
- ตัวนับชนิด DoT และ `dotSingleStack()` → [Dot.md](Dot.md)
- `getStack` / `addStack` / `setStack` / `addTotalDebuff` ของศัตรู → [Enemy.md](../../Class/Unit/Enemy.md)
- ฝั่ง ally ที่โครงสร้างคู่ขนานกัน → [BuffStack.md](BuffStack.md)
