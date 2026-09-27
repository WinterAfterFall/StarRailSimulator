# `src/Defination/Data/Lightcone/Nihility/BP2.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Holiday"` · base stats `SetAllyBaseStats(1058, 529, 331)`

**ฟังก์ชันชื่อ `BP2` แต่ `Light_cone.Name` เป็น `"Holiday"`** — ชื่อไฟล์บอกว่ามาจาก Battle Pass · บังคับ `newApplyBaseChanceRequire(100)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 529, 331)` | `BP2.h:5` |
| (AI) ตั้งเป้า EHR ขั้นต่ำ 100 สำหรับจัด substats | `newApplyBaseChanceRequire(100)` | `:7` |
| DMG `12 + 4S` | บวกถาวร | `:9` |
| ผู้สวมโจมตี → เป้ารับ DMG +`8.5 + 1.5S`% นาน 2 เทิร์น | `AfterAttackActionList` guard `isSameOwnerName` → `debuffEnemyTargetsApply(…, "Holiday Vul", 2)` | `:12-16` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` | `:19-26` |

guard ผู้โจมตีด้วย `isSameOwnerName(ptr)` ถูกต้อง

## จุดที่ควรระวัง

**ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ — ตั้งใจ** (user ยืนยัน 2026-09-26: debuff ที่มีได้ชั้นเดียว ต่อให้สวม 2 คนก็ติดแค่อันเดียว จะไม่ใส่ชื่อเจ้าของ) → สองคนสวมจะใช้ debuff ร่วมกัน ไม่ซ้อนกัน

> มีไฟล์ชื่อ `BP2.h` ใน `../Destruction/` ด้วย — คนละใบ คนละ namespace
