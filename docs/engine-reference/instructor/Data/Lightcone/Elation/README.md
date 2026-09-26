# `src/Defination/Data/Lightcone/Elation/`

4 ใบ · `namespace Elation_Lightcone` · อ่าน `../README.md` และ `../../Character/Elation/README.md` (ตารางคำศัพท์ของ path) ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `Hibana_LC.h` | `Hibana_LC` | `Hibana_LC` | CD `40+8S` | **`Max_sp += min(3, elationCount)`** · ใช้ SP → DEF_SHRED[ElationDMG] stack + Elation ทีม |
| `YaoGuang_LC.h` | `YaoGuang_LC` | `YaoGuang_LC` | SPD% `15+3S` | ต้นเกม/Ult → ER `10+2S` + ทีม CR `9+S` / CD `30+5S` 3 เทิร์น |
| `Today's Good Luck.h` | `TodayGoodLuck` | `Today's Good Luck` | CR `10+2S` | ใช้ Elation Skill → Elation stack `10+2S` (cap 2) |
| `Mushy Shroomy's Adventures.h` | `MushyShroomy` | `Mushy Shroomy's Adventures` | Elation `10+2S` | ใช้ Elation Skill → ศัตรูทุกตัวติด VUL[ElationDMG] `5+S` |

## จุดเด่นของโฟลเดอร์นี้

**1. `Hibana_LC.h` แก้ `Max_sp` ผ่าน `Setup_List`**
```cpp
Setup_List.push_back(... { Max_sp += min(3, elationCount); });
```
เป็น **LC ใบเดียวที่แก้ `Max_sp`** และเป็นที่เดียวในกลุ่ม LC ที่ใช้ `Setup_List` — จำเป็นเพราะต้องรอให้ `elationCount` ถูกนับครบทุกตัวก่อน (`Setup_List` รันหลังประกอบทีมเสร็จ เหมือน `../../Character/Destruction/Phainon.md`)

**2. ทั้ง 4 ใบผูกกับ `AType::ElationSkill` / `AType::ElationDMG`** — ใช้ `BeforeAllyActionList` + `act->isSameAction(ptr, AType::ElationSkill)` เป็นมาตรฐานของโฟลเดอร์

**3. `Stats::Elation` เป็นทั้งสแตตติดตัวและเป้าหมายของบัฟ** — ต่างจาก path อื่นที่ stat หลักเป็น ATK/CD
