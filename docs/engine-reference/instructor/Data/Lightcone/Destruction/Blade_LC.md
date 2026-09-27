# `src/Defination/Data/Lightcone/Destruction/Blade_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Blade LC"` · base stats `SetAllyBaseStats(1270, 582, 331)`

**signature ของ Blade** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1270, 582, 331)` | `Blade_LC.h:5` |
| CR `15 + 3S` และ HP% `15 + 3S` | บวกถาวร | `:9-10` |
| ผู้สวมถูกศัตรูตี → DMG `20 + 4S` สำหรับการโจมตีครั้งถัดไป | `Enemy_hit_List` หาผู้สวมใน `target` · `isHaveToAddBuff(ptr, "Blade_LC_Mark")` กันลงซ้ำ | `:14-23` |
| ผู้สวมเสีย HP (จากอะไรก็ได้) → บัฟเดียวกัน | `HPDecrease_List` guard `target` เป็นผู้สวม | `:24-30` |
| ใช้หมดเมื่อผู้สวมโจมตี | `AfterAttackActionList` → ถ้ามี flag ลบ DMG และล้าง flag | `:31-37` |

## จุดที่ทำถูก

- **guard ตัวเองใน `Enemy_hit_List`** ด้วย `e->isSameName(ptr)` แล้ว `return` — ต่างจาก `Jingliu_LC.h` ที่ลืม
- **guard `target` ใน `HPDecrease_List`**
- **`isHaveToAddBuff` แบบ 2 args กันลงซ้ำ** แล้วล้าง `buffCheck` เองตอนถอน

## ข้อสังเกต

บัฟนี้ไม่มีอายุเป็นเทิร์น แต่หมดเมื่อผู้สวมโจมตี → ใช้ `buffCheck` เป็นสถานะล้วน ไม่ใช้ `buffEnd` · สำนวนเดียวกับ `../../Relic/Scholar.md`
