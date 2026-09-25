# `src/Defination/Data/Lightcone/Elation/Mushy Shroomy's Adventures.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Mushy Shroomy's Adventures"` · base stats `SetAllyBaseStats(847, 476, 397)`

ฟังก์ชันชื่อ `MushyShroomy`

| ท่อน | โค้ด |
|---|---|
| Elation `10 + 2S` | `Reset_List` |
| ใช้ Elation Skill → ศัตรูทุกตัวติด VUL[ElationDMG] `5 + S` | `AllyActionList` → `debuffAllEnemyApply(..., debuffName)` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " MushyShroomy Debuff"`)

## จุดที่ควรระวัง

**`debuffAllEnemyApply` ถูกเรียกโดยไม่ส่ง duration** → debuff ไม่มีอายุ · แต่ `After_turn_List` เรียก `isDebuffEnd` ซึ่งเทียบ `debuffEnd` ที่ไม่เคยถูกตั้ง (default 0) → **เป็นจริงเฉพาะตอน `turnCnt == 0`** → **VUL ค้างถาวรและซ้อนทับทุกครั้งที่ใช้ Elation Skill**

เป็นอาการเดียวกับ `../Harmony/For_Tomorrow_Journey.md` แต่คนละสาเหตุ (ที่นั่นชื่อผิด ที่นี่ลืมส่ง duration)
