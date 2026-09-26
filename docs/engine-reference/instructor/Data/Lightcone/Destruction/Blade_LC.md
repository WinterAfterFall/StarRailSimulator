# `src/Defination/Data/Lightcone/Destruction/Blade_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Blade LC"` · base stats `SetAllyBaseStats(1270, 582, 331)`

**signature ของ Blade** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

| ท่อน | โค้ด |
|---|---|
| CR `15 + 3S` · HP% `15 + 3S` | `Reset_List` |
| ถูกตี → DMG `20 + 4S` (ครั้งเดียว) | `Enemy_hit_List` + `isHaveToAddBuff(ptr, "Blade_LC_Mark")` |
| เสีย HP → เหมือนกัน | `HPDecrease_List` |
| ผู้สวมโจมตี → ถอนและล้าง flag | `AfterAttackActionList` |

## จุดที่ทำถูก

- **guard ตัวเองใน `Enemy_hit_List`** ด้วย `e->isSameName(ptr)` แล้ว `return` — ต่างจาก `Jingliu_LC.h` ที่ลืม
- **guard `target` ใน `HPDecrease_List`**
- **`isHaveToAddBuff` แบบ 2 args กันลงซ้ำ** แล้วล้าง `buffCheck` เองตอนถอน

## ข้อสังเกต

บัฟนี้ไม่มีอายุเป็นเทิร์น แต่หมดเมื่อผู้สวมโจมตี → ใช้ `buffCheck` เป็นสถานะล้วน ไม่ใช้ `buffEnd` · สำนวนเดียวกับ `../../Relic/Scholar.md`
