# `src/Defination/Function/Combat/BuffStack.h`

ไฟล์นี้คือ "ชั้น stack" ของระบบบัฟฝ่ายเรา — ทุกฟังก์ชันในไฟล์นี้ **ไม่ได้บวก stat เอง** แต่แปลง "จำนวน stack ที่เปลี่ยนจริง" ให้เป็นตัวคูณ แล้วโยนต่อให้ `buffSingle()` ใน [Buff_Stats.md](Buff_Stats.md) เป็นคนบวกลง `Stats_type` / `Stats_each_element`

โครงทั้งไฟล์มี 4 ชั้น: `calStack` (คิดเลข) → `buffStackSingle` (ยิงใส่ยูนิตเดียว) → wrapper กระจายเป้าหมาย (`Char` / `AllAlly` / `AllMemosprite` / `Targets` / `ExcludingBuffer`) → กลุ่มรีเซ็ต (`buffResetStack` …)

## แกนกลาง — `calStack()` (บรรทัด 4)

```cpp
int current = ptr->getStack(buffName);
int next    = min(StackLimit, max(0, current + Stack_increase));
int applied = next - current;
ptr->addStack(buffName, applied);
return {applied, next};
```

- **clamp สองด้าน** — stack ใหม่อยู่ในช่วง `0 .. StackLimit` เสมอ
- คืน `pair{applied, next}` — `applied` คือ **ส่วนต่างจริง** ไม่ใช่ค่าที่ร้องขอ ถ้ามี 4 stack เพดาน 5 แล้วสั่ง `+3` จะได้ `applied = 1` · ถ้ามี 1 stack แล้วสั่ง `-3` จะได้ `applied = -1`
- ผู้เรียกทุกตัวใช้แค่ `.first` (`applied`) — `.second` ยังไม่มีใครใช้
- `Stack_increase` **ติดลบได้** เป็นทางปกติของตัวละครที่กินบัฟตัวเองทีละ stack
- ⚠️ ต่างจากฝั่งศัตรู: `calStack` **ไม่ปล่อย event** และ **ไม่นับจำนวนสถานะ** อะไรเลย ขณะที่ `calDebuffStack()` ([DebuffStack.md](DebuffStack.md)) ปล่อย `BeforeApplyDebuff`/`AfterApplyDebuff` และดูแล `Total_debuff` ด้วย — ฝั่ง ally ไม่มีตัวนับแบบ `Total_debuff` จึงไม่ต้องมี

## `buffStackSingle()` — 4 overload (บรรทัด 13–42)

| ชนิด buffSet | มี `extend` | ทำอะไร |
|---|---|---|
| `vector<BuffClass>` | ไม่มี | `value *= applied` ทุกตัว → `buffSingle()` |
| `vector<BuffClass>` | มี | `value *= applied` → **`extendBuffTime()` ก่อน** → `buffSingle()` |
| `vector<BuffElementClass>` | ไม่มี | เหมือนข้างบน แต่ลง `Stats_each_element` |
| `vector<BuffElementClass>` | มี | เหมือนข้างบน + `extendBuffTime()` |

`buffSet` รับมาแบบ **by value** จึงคูณทับได้โดยไม่กระทบตัวแปรของผู้เรียก — สำคัญมาก เพราะตัวละครส่วนใหญ่ประกาศ `vector<BuffClass>` ไว้เป็นค่าคงที่แล้วส่งซ้ำทุกครั้ง

⚠️ **ลำดับต่างจากฝั่งดีบัฟ**: ที่นี่ `extendBuffTime()` ถูกเรียก **ก่อน** `buffSingle()` (บรรทัด 25, 40) แต่ `debuffStackSingle()` เรียก `extendDebuff()` **หลัง** `debuffSingle()` (`DebuffStack.h:54`) ผลลัพธ์ปัจจุบันเหมือนกันเพราะทั้งสองฝั่งไม่มี event คั่นกลาง แต่ถ้าวันหนึ่งใส่ event ระหว่างสองขั้นนี้ พฤติกรรมจะแยกกันทันที

เมื่อ `applied == 0` (เต็มเพดานแล้ว หรือ stack เป็น 0 อยู่แล้วแล้วสั่งลด) ค่าบัฟทุกตัวจะกลายเป็น `0` แล้ว `buffSingle()` ยังถูกเรียกอยู่ดี — เป็นการบวก 0 ไม่มีผล แต่ **overload ที่มี `extend` ยังต่ออายุให้เสมอ** แม้ stack ไม่ขยับ

## wrapper กระจายเป้าหมาย

ทุกตัวเป็น loop บาง ๆ รอบ `buffStackSingle()` และมีครบทั้ง 4 คอมบิเนชัน (`BuffClass`/`BuffElementClass` × มี/ไม่มี `extend`)

| ฟังก์ชัน | บรรทัด | วนอะไร | หมายเหตุ |
|---|---|---|---|
| `buffStackChar(CharUnit*, …)` | 44–67 | ตัวละคร **+ memosprite ทุกตัวของมัน** | ใช้เมื่อบัฟต้องตกถึงเมมอสไปรต์ด้วย |
| `buffStackAllAlly(…)` | 69–88 | `allyList` | `allyList` = ทุกยูนิตฝ่ายเรารวมเมมอสไปรต์ |
| `buffStackAllMemosprite(…)` | 90–117 | `charList` → `memosprite` ของแต่ละตัว (ถ้ามี) | ⚠️ ต้องส่งตัวเมมอสไปรต์ ไม่ใช่พอยน์เตอร์เจ้าของ |
| `buffStackTargets(vector<AllyUnit*>, …)` | 119–138 | เฉพาะรายการที่ส่งมา | |
| `buffStackExcludingBuffer(AllyUnit*, …)` | 140–163 | `allyList` **ยกเว้นตัวผู้บัฟ** | ตัดด้วย `isSameName()` |
| `buffStackExcludingBuffer(AllyUnit*, targets, …)` | 164–187 | รายการที่ส่งมา ยกเว้นผู้บัฟ | |

⚠️ การตัดตัวเองใช้ `isSameName()` คือเทียบ **ชื่อ** ไม่ใช่พอยน์เตอร์ — ดูกติกาชื่อเป็น key หลักใน [ActionValueStats.md](../../Class/Unit/ActionValueStats.md)

## กลุ่มรีเซ็ต stack (บรรทัด 189–224)

`buffResetStack(AllyUnit*, buffSet, Stack_Name)` — ถอนบัฟทั้งกองในครั้งเดียว:

```cpp
e.value *= -ptr->getStack(Stack_Name);   // คูณ -stack ปัจจุบัน = หักออกให้หมดพอดี
ptr->setStack(Stack_Name, 0);            // แล้วเคลียร์ตัวนับ
buffSingle(ptr, buffSet);
```

จุดสำคัญคือ **ต้องส่ง `buffSet` ชุดเดียวกับตอนที่แจก** ไม่งั้นค่าที่หักออกจะไม่ตรงกับที่บวกเข้าไป → เกิดอาการ stat ไหลลง/ไหลขึ้นข้ามเทิร์น (วิธีจับอาการนี้อยู่ใน [BUGS.md](../../BUGS.md))

- `buffCharResetStack(CharUnit*, …)` (203–214) — รีเซ็ตทั้งตัวละครและเมมอสไปรต์ของมัน คู่กับ `buffStackChar`
- `buffResetStackAllAlly(…)` (215–224) — วน `allyList` คู่กับ `buffStackAllAlly`
- ⚠️ ยังไม่มีคู่รีเซ็ตของ `buffStackTargets` / `buffStackExcludingBuffer` / `buffStackAllMemosprite` — ถ้าต้องถอน ต้องวนเรียก `buffResetStack()` เอง

## ที่อธิบายไว้ไฟล์อื่น

- `buffSingle()` · `extendBuffTime()` · `BuffClass` / `BuffElementClass` → [Buff_Stats.md](Buff_Stats.md)
- `getStack` / `addStack` / `setStack` ของฝั่ง ally → [CharUnit.md](../../Class/Unit/CharUnit.md)
- ฝั่งศัตรูที่โครงสร้างคู่ขนานกัน → [DebuffStack.md](DebuffStack.md)
