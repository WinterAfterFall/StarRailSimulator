# `src/Defination/Data/Lightcone/Harmony/Bronya_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Bronya_LC"` · base stats `SetAllyBaseStats(1164, 529, 463)`

**signature ของ Bronya** (ดู `../../Character/Harmony/Bronya.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1164, 529, 463)` | `Bronya_LC.h:5` |
| ER `8 + 2S` | บวก `Energy_recharge` ถาวร | `:10` |
| กด Ult → SP +1 (ทุก 2 ครั้ง) | `WhenUseUlt_List` + `isSameOwner` · flag `"Battle_Isnt_Over_cnt"` สลับ 0/1 ให้ SP ครั้งเว้นครั้ง | `:20-29` |
| ใช้ Skill → เพื่อนคนถัดไปที่ได้เทิร์น (ไม่ใช่ผู้สวม) DMG `25 + 5S` ถึงจบเทิร์นนั้น | ตั้ง flag ตอนใช้ Skill · ต้นเทิร์นของ ally ตัวถัดไปลงบัฟชื่อผูกเจ้าของ (`:7`) อายุ 0 แล้วล้าง flag | flag `:13-19` · ลง `:31-39` |
| ถอนเมื่อจบเทิร์นนั้น | ท้ายเทิร์น `isBuffEnd` บนเจ้าของเทิร์น | `:41-47` |

## รากฐาน: บัฟ duration = 0

```cpp
string BattleBuff = ptr->getName() + " Battle_Isnt_Over_buff_check";
buffSingle(tempstats, {{DMG, 25.0 + 5*S}}, BattleBuff, 0);
```
`extend = 0` → `buffEnd = turnCnt + 0` = เทิร์นปัจจุบัน → `isBuffEnd` เป็นจริงตอนจบเทิร์นนั้นพอดี · **เป็นวิธีทำบัฟที่อยู่แค่เทิร์นเดียวโดยไม่ต้องจัดการเอง** มีที่เดียวในโปรเจกต์

## รากฐาน: flag สลับครั้งเว้นครั้ง

```cpp
if (buffCheck["Battle_Isnt_Over_cnt"] == 0) { buffCheck[...] = true; genSkillPoint(ptr, 1); }
else                                        { buffCheck[...] = false; }
```
สำนวนเดียวกับ A6 ของ `../../Character/Nihility/Luka.md` — แปลง "50% chance" หรือ "ทุก 2 ครั้ง" เป็น deterministic

## จุดที่ควรระวัง

- `buffCheck` บนผู้สวมเก็บ flag (`_buff`) และตัวสลับ (`_cnt`) ชื่อใกล้กัน
- **แก้ 2026-09-26 ตาม kit** ("the next ally taking action (except the wearer)"): เดิมถ้าผู้สวมได้เล่นต่อเอง บัฟจะตกที่ตัวเอง → ตอนนี้ข้ามเทิร์นของผู้สวม flag รอเพื่อนคนถัดไป · ลบ `buffCheck["Battle_Isnt_Over_buff_check"]` ที่ตั้งแต่ไม่มีใครอ่าน · `dynamic_cast` → `turn->canCastToAllyUnit()`
- **แก้ 2026-09-26**: ชื่อบัฟบนเพื่อนเดิมเป็น `"Battle_Isnt_Over_buff_check"` ไม่มีชื่อเจ้าของนำหน้า · kit ไม่ได้ระบุว่าห้ามซ้อน และบัฟลงบนคนอื่น จึงเติม `ptr->getName()` นำหน้าตามกฎการตั้งชื่อ (ดู `../Nihility/README.md` ข้อ 4) · key ใน `ptr->buffCheck` ยังไม่มี prefix เพราะอยู่บนตัวผู้สวมเอง
