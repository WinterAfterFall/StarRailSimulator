# `src/Defination/Data/Lightcone/Harmony/Cerydra LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Cerydra LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Cerydra** (ดู `../../Character/Harmony/Cerydra.md`)

| ท่อน | โค้ด |
|---|---|
| ATK% `48 + 16S` | `Reset_List` |
| Skill เป้าเดียว → เป้าได้ DMG `40.5 + 13.5S` 3 เทิร์น | `Buff_List` → guard `act->isSameAction(ptr, AType::SKILL) && act->traceType == TraceType::Single` |
| ถอนเมื่อหมดอายุ / เมื่อตาย | `After_turn_List` + `AllyDeath_List` |

## จุดที่ทำถูกและควรลอก

**1. ชื่อบัฟ prefix ด้วยชื่อเจ้าของ**
```cpp
string CerydraLCBuff = ptr->getName() + " Cerydra LC Buff";
```
สร้างครั้งเดียวตอน setup แล้ว capture เข้าทุก lambda — จำเป็นเพราะ `Buff_check` เป็น map เดียวทั้งเกม และ LC ใบเดียวกันอาจมีหลายคนสวม (ดู `../../Relic/Sacerdos_Relived_Ordeal.md`)

**2. ถอนบัฟครบทั้ง 2 ทาง** — `isBuffEnd` (หมดอายุ) และ `isBuffGoneByDeath` (ผู้ถือตาย) · LC หลายใบในโปรเจกต์ทำแค่ทางแรก

**3. guard ด้วย `traceType == TraceType::Single`** เพื่อให้ตรงกับ kit ที่ระบุว่าเป็นบัฟเป้าเดียว
