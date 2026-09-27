# `src/Defination/Data/Lightcone/Destruction/Secret_Vow.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Secret_Vow"` · base stats `setAllyBaseStats(1058, 476, 265)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 476, 265)` | `Secret_Vow.h:5` |
| DMG `30 + 10S` (เวอร์ชันเข้าเงื่อนไขของ kit) | บวก DMG ทุกประเภทถาวร | `:8` |

มี `resetList` ก้อนเดียว ไม่มี trigger

## คู่แฝดกับ `Secret_Vow_Nobuff.h`

สองไฟล์นี้เป็น **ใบเดียวกันสองเวอร์ชัน** และตั้ง `lightCone.name` เหมือนกันว่า `"Secret_Vow"`:

| ไฟล์ | ฟังก์ชัน | ค่า | หมายถึง |
|---|---|---|---|
| `Secret_Vow.h` | `Secret_Vow` | DMG `30 + 10S` | เข้าเงื่อนไขของ kit |
| `Secret_Vow_Nobuff.h` | `Secret_Vow_NoBuff` | DMG `15 + 5S` | ไม่เข้าเงื่อนไข |

**เป็นวิธีจำลองเงื่อนไขด้วยการทำสองไฟล์** — ต่างจาก `../Nihility/Jiaoqiu_LC.md` และ `../../Relic/Diviner of Distant Reach.md` ที่รับ `bool` เข้ามา · ข้อเสียคือ `lightCone.name` เหมือนกันทั้งคู่ ตัวละครที่เช็คชื่อจะแยกไม่ออกว่าใช้เวอร์ชันไหน
