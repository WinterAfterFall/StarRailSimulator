# `src/Defination/Data/Lightcone/Elation/`

4 ใบ · `namespace Elation_Lightcone` · อ่าน `../README.md` และ `../../Character/Elation/README.md` (ตารางคำศัพท์ของ path) ก่อน

| ไฟล์ | ชื่อในเกม | ฟังก์ชัน | `lightCone.name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|---|
| `Hibana_LC.h` | Dazzled by a Flowery World | `Hibana_LC` | `Hibana_LC` | CD `40+8S` | **`maxSp += min(3, elationCount)`** (ผู้สวมคนแรกเท่านั้น) · ใช้ SP → DEF_SHRED[ElationDMG] stack + Elation ทีม |
| `YaoGuang_LC.h` | When She Decided to See | `YaoGuang_LC` | `YaoGuang_LC` | SPD% `15+3S` | ต้นเกม/Ult → ER `10+2S` + ทีม CR `9+S` / CD `22.5+7.5S` 3 เทิร์น |
| `Today's Good Luck.h` | Today's Good Luck | `TodayGoodLuck` | `Today's Good Luck` | CR `10+2S` | ใช้ Elation Skill → Elation stack `10+2S` (cap 2) |
| `Mushy Shroomy's Adventures.h` | Mushy Shroomy's Adventures | `MushyShroomy` | `Mushy Shroomy's Adventures` | Elation `10+2S` | ใช้ Elation Skill → ศัตรูทุกตัวติด VUL[ElationDMG] `5+S` 2 เทิร์น |

> **แก้ 2026-09-26** (รีวิวเทียบ kit): YaoGuang CD ทีม `30+5S` → `22.5+7.5S` · Mushy VUL เดิมค้างถาวร → 2 เทิร์น · Hibana `maxSp` ไม่บวกซ้ำเมื่อสวมหลายคน · เพิ่มคอลัมน์ชื่อในเกม · แก้ข้อ 2 ด้านล่าง (เดิมเขียนว่าทั้ง 4 ใบใช้ `beforeAllyActionList`)

## จุดเด่นของโฟลเดอร์นี้

**1. `Hibana_LC.h` แก้ `maxSp` ผ่าน `setupList`**
```cpp
setupList.push_back(... { /* ผู้สวมคนแรกเท่านั้น */ maxSp += min(3, elationCount); });
```
เป็น **LC ใบเดียวที่แก้ `maxSp`** และเป็นที่เดียวในกลุ่ม LC ที่ใช้ `setupList` — จำเป็นเพราะต้องรอให้ `elationCount` ถูกนับครบทุกตัวก่อน (`setupList` รันหลังประกอบทีมเสร็จ เหมือน `../../Character/Destruction/Phainon.md`)

**2. trigger ของแต่ละใบ**
- `Today's Good Luck.h` / `Mushy Shroomy's Adventures.h` — `beforeAllyActionList` + `act->isSameAction(ptr, AType::ELATION_SKILL)`
- `Hibana_LC.h` — `skillPointList` (นับ SP ที่ผู้สวมใช้) · DEF_SHRED ผูกกับ `AType::ELATION_DMG`
- `YaoGuang_LC.h` — `startGameList` + `buffList` (`isSameAction(ptr, AType::ULT)`) · ไม่ผูกกับ Elation

**3. `Stats::ELATION` เป็นทั้งสแตตติดตัวและเป้าหมายของบัฟ** — ต่างจาก path อื่นที่ stat หลักเป็น ATK/CD
