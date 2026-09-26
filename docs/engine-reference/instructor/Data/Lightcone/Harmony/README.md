# `src/Defination/Data/Lightcone/Harmony/`

10 ใบ · `namespace Harmony_Lightcone` · อ่าน `../README.md` ก่อน

| ไฟล์ | ประเภท | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|
| `Cerydra LC.h` | signature | ATK% `48+16S` | Skill เป้าเดียว → เป้าได้ DMG `40.5+13.5S` 3 เทิร์น |
| `Sunday_LC.h` | signature | — | Skill เป้าเดียว → energy `5.5+0.5S` + เป้าได้ DMG stack (cap 3) · ทุก 2 ครั้งคืน SP 1 |
| `Robin_LC.h` | signature | — | โจมตี → ER stack (cap 5) · กด ult → ล้าง stack + ทีม DMG `20+4S` + ตัวเอง ATK `36+12S` |
| `Tribbie_LC.h` | signature | CD `30+6S` | ต้นเกม/FuA → ทีม CD `36+12S` 2 เทิร์น |
| `Bronya_LC.h` | signature | ER `8+2S` | ใช้ Skill → เป้าที่เล่นถัดไปได้ DMG `25+5S` · กด ult สลับครั้งเว้นครั้งคืน SP 1 |
| `DDD.h` | 4★ | — | **กด ult → advance ทั้งทีม `14+2S`%** |
| `Memories_of_the_Past.h` | 4★ | BE `21+7S` | โจมตี → energy `3+S` |
| `The Forever Victual.h` | free | ATK% `12+4S` | ใช้ Skill → ATK stack `6+2S` (cap 3) |
| `For_Tomorrow_Journey.h` | free | ATK% `12+4S` | กด ult → ตัวเอง DMG `15+3S` 1 เทิร์น |
| `Meshing_Cogs.h` | free | — | โจมตี หรือ ถูกโจมตี → energy `3+S` |

## `DDD.h` — ใบที่กระทบ AI ของทั้งทีม

```cpp
WhenUseUlt_List: if (ally->isSameOwner(ptr)) All_Action_forward(14 + 2 * superimpose);
```
**ไม่มีเงื่อนไขในตัว** → ถ้าผู้สวมกด ult ตอนที่ทีมใกล้ได้เล่นอยู่แล้ว advance จะเสียเปล่า · ต่างจาก `../../Relic/Eagle_Beaked_Helmet.md` ที่ใส่ `addUltCondition` ของตัวเอง

**ตัวละครที่อยากกันการเสียเปล่าต้องเขียนเงื่อนไขเองในไฟล์ตัวเอง** — ดูประวัติการตัดสินใจเรื่องนี้ที่ `../../README.md` หัวข้อ "แก้เมื่อ 2026-09-13" (Tribbie และ Hanabi เคยมีเงื่อนไขเช็ค DDD แล้วถูกเอาออก)

## จุดที่ควรระวัง

- **`For_Tomorrow_Journey.h` ถอนบัฟด้วยชื่อ `"Himeko_LC_buff"`** (บรรทัด 20) แต่ลงด้วยชื่อ `"For_Tomorrow_Journey_Buff"` (บรรทัด 15) → **copy มาจาก `../Erudition/Himeko_LC.h` แล้วลืมเปลี่ยน · บัฟนี้ไม่มีวันถูกถอน**
- **`Bronya_LC.h` ใช้ `buffSingle(..., "ชื่อ", 0)` duration = 0** (บรรทัด 33) แล้วถอนใน `After_turn_List` — พึ่งพฤติกรรมของ `isBuffEnd` ที่ `turnCnt == buffEnd` ซึ่งกับ `extend = 0` หมายถึงหมดในเทิร์นเดียวกัน
- **`Bronya_LC.h` ใช้ `buffCheck["Battle_Isnt_Over_cnt"]` เป็น bool สลับ** (บรรทัด 22-27) → คืน SP ครั้งเว้นครั้ง · สำนวนเดียวกับ Luka A6 (ดู `../../Character/Nihility/Luka.md`)
- **`Sunday_LC.h` `AllyDeath_List` เรียก `buffResetStack` โดยไม่เช็ค `isBuffGoneByDeath`** (บรรทัด 17-19) → ถอนกับคนที่ตายทุกคนแม้ไม่เคยมีบัฟ (อาการเดียวกับ `../../Character/Harmony/Sunday.md` E6)
- **`Robin_LC.h` `When_attack_List` ไม่ guard ผู้โจมตี** → ได้ stack จากการโจมตีของทุกคนในทีม
- **หลายใบใช้ `dynamic_cast<AllyUnit*>(turn->charptr)`** แทน `turn->canCastToAllyUnit()` — โค้ดเก่า
