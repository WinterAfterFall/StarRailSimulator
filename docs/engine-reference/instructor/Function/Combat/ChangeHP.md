# `src/Defination/Function/Combat/ChangeHP.h`

## กติกาการตาย

การลด HP ปกติจะไม่ทำให้ยูนิตตาย เพราะ `DecreaseCurrentHP()` จำกัด HP ต่ำสุดไว้ที่ `1` การตายต้องเกิดจากการเรียก `death()` หรือ explicit death effect โดยตรงเท่านั้น ซึ่งรองรับเมมอสไปรต์บางตัวที่มีท่าบังคับตาย และเงื่อนไขการจำลองแบบ perfect score ที่ต้องรักษาทุกยูนิตไม่ให้ตาย

## ฮีล — `RestoreHP` 4 overload
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
  - `Knight_of_Purity_Palace.h:8` : `Stats_type[Stats::SHEILD][AType::None] += 20` (โล่ bonus %) — **ไม่มีใครอ่านค่านี้**
  - `Aventurine.h` : โค้ดสร้างโล่ + `Buff_type.push_back("Shield")` **comment ทิ้งทั้งหมด**
- ผล: `currentSheild == 0` ตลอดเกม

### จุดที่โล่ถูก "หัก" — มีที่เดียว

`decreaseSheild()` ถูกเรียกจาก `EnemyActionData` เท่านั้น (3 จุด: `setAoeAttack` · `setBaAttack` แบบมี taunt · แบบไม่มี taunt):
```cpp
double damageDeal  = calculateDmgReceive(enemy, e, SkillRatio); // ดาเมจหลังลด mitigation
double hpDecreased = decreaseSheild(e, damageDeal);             // โล่ absorb → คืนส่วนที่ทะลุ
DecreaseCurrentHP(e, hpDecreased);                              // ส่วนที่ทะลุเข้า HP
```
- **เฉพาะการโจมตีตรงของ enemy** เท่านั้นที่ผ่านโล่
- `DecreaseHP(...)` (ตระกูลลดเลือดทั้งทีม/รายตัว ใน `ChangeHP.h`) เรียก `DecreaseCurrentHP` ตรง ๆ **ไม่ผ่านโล่** — ตรงกับเกมจริง (HP loss / DoT ทะลุโล่)

### บั๊กใน `decreaseSheild()` (`ChangeHP.h:175`)

```cpp
double decreaseSheild(AllyUnit *ptr,double Value){
    ptr->currentSheild = (ptr->currentSheild - Value < 0) ? 0 : ptr->currentSheild - Value;  // ① เขียนทับเป็น newShield
    return max(0.0, Value - ptr->currentSheild);   // ② อ่าน currentSheild = newShield (ที่ ① เพิ่งเขียน) → ผิด
}
```
บรรทัด ② ตั้งใจจะคืน "ดาเมจที่ทะลุโล่" = `Value − oldShield` แต่ดันไปใช้ `newShield` ที่บรรทัด ① เขียนทับไปแล้ว

| oldShield | Value | ทะลุ (ถูก) | โค้ดคืน | หมายเหตุ |
|--:|--:|--:|--:|---|
| 100 | 30 | 0 | `max(0, 30−70)` = **0** | ผ่าน (clamp บังหน้า) |
| 100 | 90 | 0 | `max(0, 90−10)` = **80** | ผิด — ทะลุทั้งที่โล่ยังเหลือ 10 |
| 100 | 150 | 50 | `max(0, 150−0)` = **150** | ผิด — โล่ absorb 100 แต่คิดว่าทะลุหมด |
| 0 | 100 | 100 | `max(0, 100−0)` = **100** | ผ่าน (สถานะปัจจุบันของเกม) |

พังทุกกรณีที่ `Value > oldShield/2` — ตอนนี้ไม่เจอเพราะ `oldShield` = 0 เสมอ → กลายเป็น passthrough (ดาเมจเข้า HP เต็ม)

### fix ที่ถูก — ✅ apply แล้ว (2026-09-02)

```cpp
double decreaseSheild(AllyUnit *ptr,double Value){
    double absorbed = min(ptr->currentSheild,Value);   // โล่กันได้เท่าที่มี
    ptr->currentSheild -= absorbed;
    return Value - absorbed;                            // ดาเมจส่วนที่ทะลุโล่ → เข้า HP
}
```
- behavior เดิม (ตอน `currentSheild == 0`) ไม่เปลี่ยน → sim output ปัจจุบันไม่กระทบ
- **ยังค้าง:** ระบบ **สร้าง** โล่ — อ่าน `Stats_type[SHEILD]` เป็นตัวคูณ outgoing shield, เพิ่ม `currentSheild`, countdown/ถอนเหมือนบัฟ, ปลด comment Aventurine
