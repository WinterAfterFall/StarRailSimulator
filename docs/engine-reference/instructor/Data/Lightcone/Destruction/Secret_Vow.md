# `src/Defination/Data/Lightcone/Destruction/Secret_Vow.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Secret_Vow"` · base stats `SetAllyBaseStats(1058, 476, 265)`

| ท่อน | โค้ด |
|---|---|
| DMG `30 + 10S` | `Reset_List` |

มี `Reset_List` ก้อนเดียว ไม่มี trigger

## คู่แฝดกับ `Secret_Vow_Nobuff.h`

สองไฟล์นี้เป็น **ใบเดียวกันสองเวอร์ชัน** และตั้ง `Light_cone.Name` เหมือนกันว่า `"Secret_Vow"`:

| ไฟล์ | ฟังก์ชัน | ค่า | หมายถึง |
|---|---|---|---|
| `Secret_Vow.h` | `Secret_Vow` | DMG `30 + 10S` | เข้าเงื่อนไขของ kit |
| `Secret_Vow_Nobuff.h` | `Secret_Vow_NoBuff` | DMG `15 + 5S` | ไม่เข้าเงื่อนไข |

**เป็นวิธีจำลองเงื่อนไขด้วยการทำสองไฟล์** — ต่างจาก `../Nihility/Jiaoqiu_LC.md` และ `../../Relic/Diviner of Distant Reach.md` ที่รับ `bool` เข้ามา · ข้อเสียคือ `Light_cone.Name` เหมือนกันทั้งคู่ ตัวละครที่เช็คชื่อจะแยกไม่ออกว่าใช้เวอร์ชันไหน
