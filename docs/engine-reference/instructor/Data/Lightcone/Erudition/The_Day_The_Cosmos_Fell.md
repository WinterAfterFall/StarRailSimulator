# `src/Defination/Data/Lightcone/Erudition/The_Day_The_Cosmos_Fell.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"Cosmos_Fell"` · base stats `setAllyBaseStats(953, 476, 331)`

ฟังก์ชันชื่อ `Cosmos_Fell` (สั้นกว่าชื่อไฟล์)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `The_Day_The_Cosmos_Fell.h:5` |
| ATK% `14 + 2S` และ CD `15 + 5S` (kit: CD ต้องตีเป้าที่อ่อนธาตุ ≥ 2 ตัว) | ลงถาวรตอนเข้าสนาม ไม่เช็คเงื่อนไข | `:8-11` |

มีก้อนเดียว ไม่มี trigger อื่น

## ข้อสังเกต

**ใช้ `whenOnFieldList` แทน `resetList`** ทั้งที่เป็นสแตตถาวรไม่มีเงื่อนไข — ทั้งสอง list ให้ผลเหมือนกัน ต่างกันแค่จังหวะที่รัน (ดู `../../Planar/README.md`)
