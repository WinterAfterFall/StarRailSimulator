# `src/Defination/Data/Lightcone/Harmony/Cerydra LC.h`

`namespace Harmony_Lightcone` · `lightCone.name` = `"Cerydra LC"` · base stats `setAllyBaseStats(953, 635, 463)`

**signature ของ Cerydra** (ดู `../../Character/Harmony/Cerydra.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 635, 463)` | `Cerydra LC.h:5` |
| ATK% `48 + 16S` | บวกถาวร | `:10` |
| ใช้ Skill บัฟเพื่อนเป้าเดี่ยว → เป้าได้ Skill DMG `40.5 + 13.5S` นาน 3 เทิร์น | `buffList` เฉพาะ Skill ของผู้สวม + `TraceType::SINGLE` · ชื่อบัฟผูกเจ้าของ (`:7`) | `:31-37` |
| ใช้ Ult → SP +1 | `afterAttackActionList` เฉพาะ Ult ของผู้สวม | `:27-29` |
| ถอนเมื่อหมดอายุ / เป้าตาย | ท้ายเทิร์นของผู้ถือบัฟ `isBuffEnd` · `allyDeathList` + `isBuffGoneByDeath` | `:13-19` · `:21-25` |

## จุดที่ทำถูกและควรลอก

**1. ชื่อบัฟ prefix ด้วยชื่อเจ้าของ**
```cpp
string cerydraLCBuff = ptr->getName() + " Cerydra LC Buff";
```
สร้างครั้งเดียวตอน setup แล้ว capture เข้าทุก lambda — จำเป็นเพราะ `Buff_check` เป็น map เดียวทั้งเกม และ LC ใบเดียวกันอาจมีหลายคนสวม (ดู `../../Relic/Sacerdos_Relived_Ordeal.md`)

**2. ถอนบัฟครบทั้ง 2 ทาง** — `isBuffEnd` (หมดอายุ) และ `isBuffGoneByDeath` (ผู้ถือตาย) · LC หลายใบในโปรเจกต์ทำแค่ทางแรก

**3. guard ด้วย `traceType == TraceType::SINGLE`** เพื่อให้ตรงกับ kit ที่ระบุว่าเป็นบัฟเป้าเดียว

> **แก้ 2026-09-26 ตาม kit**: (1) บัฟเดิมลง `DMG[AType::NONE]` (ดาเมจทุกชนิด) → kit ระบุ "Skill DMG" จึงเปลี่ยนเป็น `AType::SKILL` (2) เพิ่ม "After using Ultimate to attack, recovers 1 Skill Point" ที่เดิมไม่มี
