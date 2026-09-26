# `src/Defination/Data/Lightcone/Harmony/Bronya_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Bronya_LC"` · base stats `SetAllyBaseStats(1164, 529, 463)`

**signature ของ Bronya** (ดู `../../Character/Harmony/Bronya.md`)

| ท่อน | โค้ด |
|---|---|
| ER `8 + 2S` | `Reset_List` → `ptr->Energy_recharge += 8 + 2*superimpose` |
| ใช้ Skill → ตั้ง flag | `AllyActionList` → `buffCheck["Battle_Isnt_Over_buff"] = 1` |
| ต้นเทิร์นถัดไป → คนที่กำลังจะเล่นได้ DMG `25 + 5S` | `Before_turn_List` → `buffSingle(tempstats, ..., BattleBuff, 0)` |
| กด ult → คืน SP 1 **ครั้งเว้นครั้ง** | `WhenUseUlt_List` + `buffCheck["Battle_Isnt_Over_cnt"]` สลับ |
| ถอน | `After_turn_List` → `isBuffEnd` |

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

- ใช้ `dynamic_cast<AllyUnit*>(turn->charptr)` แทน `turn->canCastToAllyUnit()` ทั้งสองที่ — โค้ดเก่า
- `buffCheck` ถูกใช้เก็บทั้ง flag (`_buff`), ตัวสลับ (`_cnt`) และสถานะบัฟ (`_check`) ในไฟล์เดียว ชื่อใกล้กันมาก
- **แก้ 2026-09-26**: ชื่อบัฟบนเพื่อนเดิมเป็น `"Battle_Isnt_Over_buff_check"` ไม่มีชื่อเจ้าของนำหน้า · kit ไม่ได้ระบุว่าห้ามซ้อน และบัฟลงบนคนอื่น จึงเติม `ptr->getName()` นำหน้าตามกฎการตั้งชื่อ (ดู `../Nihility/README.md` ข้อ 4) · key ใน `ptr->buffCheck` ยังไม่มี prefix เพราะอยู่บนตัวผู้สวมเอง
