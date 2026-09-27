# `src/Defination/Data/Lightcone/Destruction/BP2.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"A Trail of Bygone Blood"` · base stats `setAllyBaseStats(1058, 529, 331)`

**ฟังก์ชันชื่อ `BP2` แต่ `lightCone.name` เป็น `"A Trail of Bygone Blood"`** — ชื่อไฟล์บอกว่ามาจาก Battle Pass

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 529, 331)` | `BP2.h:5` |
| CR `10 + 2S` | บวก CR ถาวร | `:9` |
| Skill DMG และ Ult DMG `20 + 4S` | บวก DMG ที่จำกัด `AType::SKILL` / `AType::ULT` ถาวร | `:10-11` |

มี `resetList` ก้อนเดียว ไม่มี trigger

## ข้อควรรู้

บัฟผูกกับ `AType::SKILL` / `AType::ULT` → **ตัวละครที่สร้าง action ด้วย `AType` ผิดจะไม่ได้บัฟนี้** · ดูรายชื่อไฟล์ที่ยังผิดใน `../../Character/README.md`

> มีไฟล์ชื่อ `BP2.h` ใน `../Nihility/` ด้วย — คนละใบ คนละ namespace
