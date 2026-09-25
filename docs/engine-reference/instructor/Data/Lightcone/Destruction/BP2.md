# `src/Defination/Data/Lightcone/Destruction/BP2.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"A Trail of Bygone Blood"` · base stats `SetAllyBaseStats(1058, 529, 331)`

**ฟังก์ชันชื่อ `BP2` แต่ `Light_cone.Name` เป็น `"A Trail of Bygone Blood"`** — ชื่อไฟล์บอกว่ามาจาก Battle Pass

| ท่อน | โค้ด |
|---|---|
| CR `10 + 2S` | `Reset_List` |
| Skill DMG `20 + 4S` | `Stats_type[Stats::DMG][AType::SKILL]` |
| Ult DMG `20 + 4S` | `Stats_type[Stats::DMG][AType::Ult]` |

มี `Reset_List` ก้อนเดียว ไม่มี trigger

## ข้อควรรู้

บัฟผูกกับ `AType::SKILL` / `AType::Ult` → **ตัวละครที่สร้าง action ด้วย `AType` ผิดจะไม่ได้บัฟนี้** · ดูรายชื่อไฟล์ที่ยังผิดใน `../../Character/README.md`

> มีไฟล์ชื่อ `BP2.h` ใน `../Nihility/` ด้วย — คนละใบ คนละ namespace
