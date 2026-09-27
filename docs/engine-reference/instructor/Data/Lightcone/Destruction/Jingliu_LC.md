# `src/Defination/Data/Lightcone/Destruction/Jingliu_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Jingliu_LC"` · base stats `setAllyBaseStats(1164, 582, 397)`

**signature ของ Jingliu** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 582, 397)` | `Jingliu_LC.h:5` |
| CD `17 + 3S` | บวกถาวร | `:8` |
| ถูกตี → DMG `11.5 + 2.5S` ต่อ stack (สูงสุด 3) | `enemyHitList` วนทุกเป้าที่โดนแล้วบวก stack (ไม่เช็คว่าเป็นผู้สวม — ดูด้านล่าง) | `:11-19` (stack `:13`) |
| เสีย HP → stack เหมือนกัน | `hpDecreaseList` (ไม่ guard `target`) | `:21-28` (stack `:22`) |
| ครบ 3 stack → ignore DEF `10 + 2S`% | `isHaveToAddBuff(ptr, "Jingliu_LC Def Shred")` กันลงซ้ำ · มีสองชุดเหมือนกัน | `:15-18` · `:23-26` |
| ผู้สวมโจมตี → ล้างทั้งหมด | `afterAttackActionList` → `buffCharResetStack` ถอน DMG · ถอน DEF_SHRED ถ้ามี flag | `:29-37` |

## จุดที่ควรระวัง

- **`enemyHitList` วน `target` แล้ว `buffStackSingle` ทุกรอบโดยไม่เช็คว่าเป็นผู้สวม** — ตัวแปร `e` ไม่ได้ถูกใช้เลย → **ศัตรูตีโดน 3 คน = ได้ 3 stack ในครั้งเดียว** แม้ไม่ได้โดนเอง · เทียบกับ `Blade_LC.h` และ `Clara_LC.h` ที่เช็ค `e->isSameName(ptr)` ถูกต้อง
- **`hpDecreaseList` ก็ไม่ guard `target`** → ได้ stack ทุกครั้งที่ใครในทีมเสีย HP
- **บล็อกเช็คครบ 3 stack ถูก copy 2 ที่**
- ถอนด้วย `buffCharResetStack` (ตระกูล `...charSetup`) ทั้งที่ลงด้วย `buffStackSingle` — คนละตระกูล
