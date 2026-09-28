# `src/Defination/Data/Lightcone/Elation/`

11 ใบ · `namespace Elation_Lightcone` · อ่าน `../README.md` และ `../../Character/Elation/README.md` (ตารางคำศัพท์ของ path) ก่อน

| ไฟล์ | ชื่อในเกม | ฟังก์ชัน | `lightCone.name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|---|
| `Hibana_LC.h` | Dazzled by a Flowery World | `Hibana_LC` | `Hibana_LC` | CD `40+8S` | **`maxSp += min(3, elationCount)`** (ผู้สวมคนแรกเท่านั้น) · ใช้ SP → DEF_SHRED[ElationDMG] stack + Elation ทีม |
| `YaoGuang_LC.h` | When She Decided to See | `YaoGuang_LC` | `YaoGuang_LC` | SPD% `15+3S` | ต้นเกม/Ult → ER `10+2S` + ทีม CR `9+S` / CD `22.5+7.5S` 3 เทิร์น |
| `Today's Good Luck.h` | Today's Good Luck | `TodayGoodLuck` | `Today's Good Luck` | CR `10+2S` | ใช้ Elation Skill → Elation stack `10+2S` (cap 2) |
| `Mushy Shroomy's Adventures.h` | Mushy Shroomy's Adventures | `MushyShroomy` | `Mushy Shroomy's Adventures` | Elation `10+2S` | ใช้ Elation Skill → ศัตรูทุกตัวติด VUL[ElationDMG] `5+S` 2 เทิร์น |
| `Pearl_LC.h` | Colors for Tomorrow (Pearl) | `Pearl_LC` | `Pearl_LC` | DEF% `36+12S` | Elation Skill ใส่ทุกคน → ศัตรู VUL `16.5+5.5S` 3 เทิร์น + Energy fixed 10 + ฮีลทีม DEF `7.5+2.5S`% |
| `Evanescia_LC.h` | Until the Flowers Bloom Again (Evanescia) | `Evanescia_LC` | `Evanescia_LC` | CD `45+15S` · ERR `8.5+1.5S` (+0.3% ต่อ Max Energy เกิน 120 ทุก 10) | ใช้ Elation Skill → ศัตรู VUL `11.25+3.75S` 2 เทิร์น (ชื่อร่วม ไม่ซ้อน) |
| `SilverWolf999_LC.h` | Welcome to the Cosmic City (SW999) | `SilverWolf999_LC` | `SilverWolf999_LC` | SPD% `15+3S` · DEF_SHRED[ElationDMG] `16+4S` | Ult ใส่ตัวเอง → Punchline `15+5S` (ครั้งเดียว รีเซ็ตหลัง BA 3 ครั้ง) |
| `AventurineWaveflair_LC.h` | Summer Rides the Surf (Aventurine • Waveflair) | `AventurineWaveflair_LC` | `AventurineWaveflair_LC` | CR `15+3S` | ใช้ Elation Skill → SPD% `20+4S` · Elation Skill ต่างจากครั้งก่อน → Elation `25+15S` · ทุก 3 ครั้ง / ต้น wave → SP +1 |
| `A Little Getaway.h` | A Little Getaway | `ALittleGetaway` | `A Little Getaway` | Elation `15+5S` · DEF_SHRED[ElationSkill] `6+2S` | — |
| `Tomorrow Together.h` | Tomorrow, Together | `TomorrowTogether` | `Tomorrow, Together` | CD `9+3S` | หลังใช้ Ult → ทีม Elation `7+S` 1 เทิร์น |
| `ElationHertaShop.h` | Elation Brimming With Blessings (Herta Shop) | `ElationHertaShop` | `Elation Brimming With Blessings` | ATK% `15+5S` | Skill/Ult ใส่เพื่อน 1 คน → คนนั้น Elation `9+3S` 2 เทิร์น |

> **เพิ่ม 2026-09-28** (user สั่ง): 7 ใบจาก kit nanoka 4.5.54 (`docs/kit-reference/Lightcone/Elation.md`) · ใบที่ต้องรู้ว่า "ผู้สวมใช้ Elation Skill" ใช้ event ใหม่ `whenUseElationSkillList` (ยิงครั้งละ 1 ตัวละคร ดู `../../../Function/Combat/AhaCombat.md`)

> **แก้ 2026-09-26** (รีวิวเทียบ kit): YaoGuang CD ทีม `30+5S` → `22.5+7.5S` · Mushy VUL เดิมค้างถาวร → 2 เทิร์น · Hibana `maxSp` ไม่บวกซ้ำเมื่อสวมหลายคน · เพิ่มคอลัมน์ชื่อในเกม · แก้ข้อ 2 ด้านล่าง (เดิมเขียนว่าทั้ง 4 ใบใช้ `beforeAllyActionList`)

## จุดเด่นของโฟลเดอร์นี้

**1. `Hibana_LC.h` แก้ `maxSp` ผ่าน `setupList`**
```cpp
setupList.push_back(... { /* ผู้สวมคนแรกเท่านั้น */ maxSp += min(3, elationCount); });
```
เป็น **LC ใบเดียวที่แก้ `maxSp`** และเป็นที่เดียวในกลุ่ม LC ที่ใช้ `setupList` — จำเป็นเพราะต้องรอให้ `elationCount` ถูกนับครบทุกตัวก่อน (`setupList` รันหลังประกอบทีมเสร็จ เหมือน `../../Character/Destruction/Phainon.md`)

**2. trigger ของแต่ละใบ**
- `Today's Good Luck.h` / `Mushy Shroomy's Adventures.h` — `whenUseElationSkillList` + `ally == ptr` (ย้ายจาก `beforeAllyActionList` 2026-09-28)
- `Hibana_LC.h` — `skillPointList` (นับ SP ที่ผู้สวมใช้) · DEF_SHRED ผูกกับ `AType::ELATION_DMG`
- `YaoGuang_LC.h` — `startGameList` + `buffList` (`isSameAction(ptr, AType::ULT)`) · ไม่ผูกกับ Elation

**3. `Stats::ELATION` เป็นทั้งสแตตติดตัวและเป้าหมายของบัฟ** — ต่างจาก path อื่นที่ stat หลักเป็น ATK/CD

**4. ตรวจจับ "ผู้สวมใช้ Elation Skill" — ใช้ `whenUseElationSkillList` ไม่ใช่ `beforeAllyActionList`**
ใน Aha Instant ทุก Elation Skill รวมเป็น 1 action และ `beforeAllyActionList` ยิงครั้งเดียวด้วย action ตัวแรกเป็นตัวแทน (`Function/Combat/AhaCombat.h` `runAhaInstantBar`) · `isSameAction(ptr, ELATION_SKILL)` จึงจริงเฉพาะเมื่อผู้สวมเป็นตัวแรกในคิว และไม่จริงเลยถ้า Elation Skill ของผู้สวมไม่ใส่ action (Pearl, SW999 นอก Godmode)
- ทุกใบที่ต้องรู้เรื่องนี้ใช้ `whenUseElationSkillList` ซึ่งยิงแยกทุกตัวละคร: `Pearl_LC.h`, `Evanescia_LC.h`, `AventurineWaveflair_LC.h`, `Today's Good Luck.h`, `Mushy Shroomy's Adventures.h`
- `Today's Good Luck.h` และ `Mushy Shroomy's Adventures.h` เดิมใช้ `beforeAllyActionList` → ติดเฉพาะเมื่อผู้สวมอยู่หัวคิว Aha · ย้ายมาใช้ event ใหม่แล้ว (user สั่ง 2026-09-28)
