# `src/Defination/Function/Combat/ChangeHP.h`

## กติกาการตาย

การลด HP ปกติจะไม่ทำให้ยูนิตตาย เพราะ `decreaseCurrentHP()` จำกัด HP ต่ำสุดไว้ที่ `1` การตายต้องเกิดจากการเรียก `death()` หรือ explicit death effect โดยตรงเท่านั้น ซึ่งรองรับเมมอสไปรต์บางตัวที่มีท่าบังคับตาย และเงื่อนไขการจำลองแบบ perfect score ที่ต้องรักษาทุกยูนิตไม่ให้ตาย

## ฮีล — `restoreHP` 4 overload
| signature | คอมเมนต์ในโค้ด | กลไก |
|---|---|---|
| `(HealSrc main, HealSrc adjacent, HealSrc other)` | — | `priority_queue` เรียง ally ตาม `calculateHPLost` · ถ้าเกิน 3 ตัว → ตัวเจ็บน้อยสุดโดน `other` · เหลือ 3 ตัวสุดท้าย: เจ็บหนักสุดได้ `main`, อีก 2 ได้ `adjacent` |
| `(AllyUnit *target, HealSrc)` | "heal เดี่ยว" | ฮีล target ตัวเดียว |
| `(HealSrc)` | "heal ทั้งทีมแบบเท่าเทียม" | วน `allyList` ฮีลทุกตัวเท่ากัน |
| `(AllyUnit *target, HealSrc main, HealSrc other)` | "heal ทั้งทีมเน้นคนเดียว" | วน `allyList`: ตัวชื่อตรง target → `main` · ที่เหลือ → `other` |

## 🛡️ ระบบโล่ (shield / `currentSheild`) : สถานะ + บั๊ก

### ตอนนี้เป็น stub

`currentSheild` (double, บน `AllyUnit`) — **ไม่มีโค้ดไหนเพิ่มค่าเลย**
- reset `= 0` ที่ `Stats_Reset.h:38` (char) + `:261` (memo) เท่านั้น
- ชิ้นส่วนที่มีแต่ยังไม่ต่อสาย:
  - `Stats::SHEILD` (enum) — `toString` = `"Sheild"`
  - `Knight_of_Purity_Palace.h:8` : `statsType[Stats::SHEILD][AType::NONE] += 20` (โล่ bonus %) — **ไม่มีใครอ่านค่านี้**
  - `Aventurine.h` : โค้ดสร้างโล่ + `Buff_type.push_back("Shield")` **comment ทิ้งทั้งหมด**
- ผล: `currentSheild == 0` ตลอดเกม

### จุดที่โล่ถูก "หัก" — มีที่เดียว

`decreaseSheild()` ถูกเรียกจาก `EnemyActionData` เท่านั้น (3 จุด: `setAoeAttack` · `setBaAttack` แบบมี taunt · แบบไม่มี taunt):
```cpp
double damageDeal  = calculateDmgReceive(enemy, e, skillRatio); // ดาเมจหลังลด mitigation
double hpDecreased = decreaseSheild(e, decreaseBlock(e, damageDeal));             // โล่ absorb → คืนส่วนที่ทะลุ
decreaseCurrentHP(e, hpDecreased);                              // ส่วนที่ทะลุเข้า HP
```
- **เฉพาะการโจมตีตรงของ enemy** เท่านั้นที่ผ่านโล่
- `decreaseHP(...)` (ตระกูลลดเลือดทั้งทีม/รายตัว ใน `ChangeHP.h`) เรียก `decreaseCurrentHP` ตรง ๆ **ไม่ผ่านโล่** — ตรงกับเกมจริง (HP loss / DoT ทะลุโล่)

### บั๊กใน `decreaseSheild()` (`ChangeHP.h:175`)

```cpp
double decreaseSheild(AllyUnit *ptr,double value){
    ptr->currentSheild = (ptr->currentSheild - value < 0) ? 0 : ptr->currentSheild - value;  // ① เขียนทับเป็น newShield
    return max(0.0, value - ptr->currentSheild);   // ② อ่าน currentSheild = newShield (ที่ ① เพิ่งเขียน) → ผิด
}
```
บรรทัด ② ตั้งใจจะคืน "ดาเมจที่ทะลุโล่" = `value − oldShield` แต่ดันไปใช้ `newShield` ที่บรรทัด ① เขียนทับไปแล้ว

| oldShield | Value | ทะลุ (ถูก) | โค้ดคืน | หมายเหตุ |
|--:|--:|--:|--:|---|
| 100 | 30 | 0 | `max(0, 30−70)` = **0** | ผ่าน (clamp บังหน้า) |
| 100 | 90 | 0 | `max(0, 90−10)` = **80** | ผิด — ทะลุทั้งที่โล่ยังเหลือ 10 |
| 100 | 150 | 50 | `max(0, 150−0)` = **150** | ผิด — โล่ absorb 100 แต่คิดว่าทะลุหมด |
| 0 | 100 | 100 | `max(0, 100−0)` = **100** | ผ่าน (สถานะปัจจุบันของเกม) |

พังทุกกรณีที่ `value > oldShield/2` — ตอนนี้ไม่เจอเพราะ `oldShield` = 0 เสมอ → กลายเป็น passthrough (ดาเมจเข้า HP เต็ม)

### fix ที่ถูก — ✅ apply แล้ว (2026-09-02)

```cpp
double decreaseSheild(AllyUnit *ptr,double value){
    double absorbed = min(ptr->currentSheild,value);   // โล่กันได้เท่าที่มี
    ptr->currentSheild -= absorbed;
    return value - absorbed;                            // ดาเมจส่วนที่ทะลุโล่ → เข้า HP
}
```
- behavior เดิม (ตอน `currentSheild == 0`) ไม่เปลี่ยน → sim output ปัจจุบันไม่กระทบ
- **ยังค้าง:** ระบบ **สร้าง** โล่ — อ่าน `statsType[SHEILD]` เป็นตัวคูณ outgoing shield, เพิ่ม `currentSheild`, countdown/ถอนเหมือนบัฟ, ปลด comment Aventurine

## primitive เพิ่ม/ลด HP — 4 ตัวที่ทุกอย่างวิ่งผ่าน

| ฟังก์ชัน | บรรทัด | ยิง event | เช็คสถานะยูนิต | clamp |
|---|---|---|---|---|
| `increaseCurrentHP(ptr, value)` | 112 | ❌ | ❌ | เพดานที่ `totalHP` |
| `increaseHP(healer, target, value)` | 115 | ✅ `allEventHeal` | `isExisted()` | ผ่าน `increaseCurrentHP` |
| `decreaseCurrentHP(ptr, value)` | 121 | ❌ | ❌ | **พื้นที่ `1`** · คืนค่าที่ลดจริง |
| `decreaseHP(...)` 4 overload | 126–176 | ✅ `allEventChangeHP` | `isExisted()` / `isTargetable()` | ผ่าน `decreaseCurrentHP` |

กติกาเดียวกันทั้งสองฝั่ง: ตัว `…CurrentHP` คือ **ตัวเขียนเลขดิบ** ไม่ยิง event ไม่เช็คอะไร ส่วนตัวไม่มี `Current` คือ **ทางเข้าที่ถูกต้อง** ที่ห่อ event และเงื่อนไขไว้ให้

### `increaseHP()` — 2 เงื่อนไขที่ทำให้ฮีล "หายไปเงียบ ๆ"

```cpp
if (value == 0 || !target->isExisted()) return;   // ← ออกก่อน ไม่ยิง allEventHeal
increaseCurrentHP(target, value);
allEventHeal(healer, target, value);
```

- **ฮีล 0 ไม่ยิง event** — ตัวละคร/LC ที่ผูก trigger ไว้กับ `Heal_List` จะไม่ทำงาน แม้ผู้ฮีลจะ "ใช้ท่าฮีล" จริง
- **ยูนิตที่ตายแล้วรับฮีลไม่ได้** — `isExisted()` เป็นตัวกั้น (การชุบชีวิตต้องทำผ่านทางอื่น)
- ⚠️ `allEventHeal` ส่ง `value` **ก่อน clamp** ไม่ใช่จำนวนที่เข้า HP จริง — ฮีล 5000 ใส่ยูนิตที่ขาด HP อยู่ 200 จะยิง event ด้วยเลข 5000 ต่างจากฝั่งลด HP ที่ `allEventChangeHP` ส่ง `actualDecrease` (ค่าที่ลดจริง) ถ้าเขียนตัวละครที่อ่าน "ฮีลไปเท่าไร" ต้องระวังจุดนี้

### `decreaseHP()` — 4 overload

| signature | คอมเมนต์ในโค้ด | ตัวกรอง |
|---|---|---|
| `(AllyUnit *target, Unit *trigger, value, %totalHP, %currentHP)` | — | `isExisted()` |
| `(Unit *trigger, value, %totalHP, %currentHP)` | "ลดเลือดทั้งทีม" | `isTargetable()` |
| `(Unit *trigger, vector<AllyUnit*> target, value, %totalHP, %currentHP)` | — | `isTargetable()` |
| `(Unit *trigger, string name, value, %totalHP, %currentHP)` | "ลดเลือดทั้งทีมยกเว้นตัวเอง" | `isSameName(name)` แล้ว `isTargetable()` |

ทุกตัวรวมสามแหล่งเข้าด้วยกันก่อนหัก: `value` (แบน) + `%totalHP × totalHP` + `%currentHP × currentHP` แล้วส่ง `actualDecrease` (ค่าที่ลดจริงหลังชน floor `1`) เข้า `allEventChangeHP`

⚠️ สองข้อควรระวัง:
- `decreaseHPCount++` เกิด **ก่อน** การเช็ค `isExisted()` ในทุก overload — ตัวนับจึงขยับแม้ไม่มีใครเสียเลือดจริง
- overload เป้าเดียวใช้ `isExisted()` แต่อีกสามตัวใช้ `isTargetable()` ซึ่งเข้มกว่า (ตัด `OUT_OF_BOUNDS` ออกด้วย ดู [ActionValueStats.md](../../Class/Unit/ActionValueStats.md)) การลดเลือดเป้าเดียวจึงยิงโดน unit ที่อยู่นอกสนามได้ ส่วนแบบทั้งทีมไม่โดน

### สวิตช์ debug ของฝั่งฮีล

กรอบ `Heal Count : N` ที่ `restoreHP` ทั้ง 4 overload พิมพ์ออกมา คุมด้วย `checkHeal || checkHealFormula` ของ **ผู้ฮีล** เท่านั้น ส่วนบรรทัดตัวเลขข้างในคุมด้วยเงื่อนไข AND ระหว่างผู้ฮีลกับผู้รับ — รายละเอียดทั้งหมดอยู่ใน [FormulaCheck.md](../AdjustFunction/FormulaCheck.md) · ฝั่งลด HP **ไม่มี debug print ของตัวเอง** แม้จะมี flag `checkHpChange` ค้างอยู่

## `decreaseBlock(AllyUnit*, value)` — Repellency (เพิ่ม 2026-09-28)

เรียกก่อน `decreaseSheild` ในทั้ง 3 จุดของ `EnemyActionData` · กันดาเมจ `value × BLOCK% ของผู้รับ` แต่ไม่เกินที่เหลือในกองกลาง `repellency` (global ใน `Setting.h` รีเซ็ตเป็น 0 ใน `reset()`) แล้วหักกองเท่าที่กันไป คืนดาเมจส่วนที่เหลือ

- `Stats::BLOCK` อยู่บนตัวผู้รับ (ช่อง `AType::NONE`) = เปอร์เซ็นต์ที่กันได้ต่อครั้ง
- ผู้ใช้ตอนนี้: Pearl (CB 1 = 200 Repellency · ทุกคน `BLOCK` 60)
