# `src/Defination/Data/Lightcone/Destruction/Clara_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Clara_LC"` · base stats `setAllyBaseStats(1164, 582, 397)`

**signature ของ Clara** (ตัวละครยังไม่มีในโปรเจกต์)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 582, 397)` | `Clara_LC.h:5` |
| ATK% `20 + 4S` | บวกถาวร | `:8` |
| ผู้สวมถูกตี → ฮีลตัวเอง `7 + S`% ATK และ DMG `20 + 4S` นาน 1 เทิร์น (ครั้งเดียวต่อเทิร์น) | `enemyHitList` หาผู้สวมใน `target` · flag `"Clara_LC_Triggered"` กันติดซ้ำ · `restoreHP` + `buffSingle(…, "Clara_LC", 1)` | `:10-20` (ฮีล `:15` · บัฟ `:16`) |
| ล้าง flag "ครั้งเดียวต่อเทิร์น" | ต้นเทิร์นของทุก unit | `:21-23` |
| ถอน DMG เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:24-28` |

## จุดที่น่าสังเกต

**เป็น LC ใบเดียวในโฟลเดอร์ที่ฮีล** — `e->restoreHP(e, HealSrc(HealSrcType::ATK, 7.0 + superimpose))` ใช้ overload `restoreHP(target, HealSrc)` โดยให้ผู้สวมฮีลตัวเอง

guard ตัวเองด้วย `e->isSameName(ptr)` แล้ว `return` ถูกต้อง

## ครั้งเดียวต่อเทิร์น

kit: "can only trigger 1 time per turn" → ตั้ง `buffCheck["Clara_LC_Triggered"] = 1` ตอนติด แล้วล้างเป็น 0 ใน `beforeTurnList` (ยิงทุกเทิร์นของทุกยูนิต รวมศัตรู) · ศัตรูหลายตัวตีในเทิร์นเดียวกันจึงติดได้ครั้งเดียว

## ส่วนที่ยังไม่มี

- trigger "เมื่อผู้สวมกำจัดศัตรู" — ยังไม่ได้ทำ
