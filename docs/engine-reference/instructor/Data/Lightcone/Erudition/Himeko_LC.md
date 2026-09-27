# `src/Defination/Data/Lightcone/Erudition/Himeko_LC.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"Himeko_LC"` · base stats `setAllyBaseStats(1164, 582, 397)`

**signature ของ Himeko** (ตัวละครยังไม่มีในโปรเจกต์)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1164, 582, 397)` | `Himeko_LC.h:5` |
| ATK% `(7.5 + 1.5S)` × จำนวนศัตรูในสนาม | ลงครั้งเดียวตอนเข้าสนามด้วย `totalEnemy` | `:8-10` |
| มีการ break (ใครก็ได้) → DMG `25 + 5S` นาน 1 เทิร์น | `toughnessBreakList` → `buffSingle(…, "Himeko_LC_buff", 1)` | `:18-20` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:12-16` |

## จุดที่ควรระวัง

- **ถอน DMG ด้วยการเขียน `statsType` ตรง ๆ แต่ลงด้วย `buffSingle`** — คนละกลไก · `buffSingle` มี `isHaveToAddBuff` กันลงซ้ำ แต่การถอนแบบเขียนตรงไม่ได้ล้าง `buffCheck` (ซึ่ง `isBuffEnd` ล้างให้แล้ว จึงยังถูก)
- `toughnessBreakList` ไม่ guard ว่าใคร break → ใครในทีม break ก็ได้บัฟ ซึ่ง**ตรงกับ kit** ("When an enemy is inflicted with Weakness Break")
- **ATK% คำนวณจาก `totalEnemy` ครั้งเดียวตอนเข้าสนาม** → ถ้าจำนวนศัตรูเปลี่ยนระหว่างเกม ค่าไม่ตาม

> **ชื่อบัฟ `"Himeko_LC_buff"` ถูก copy ไปใช้ผิดที่ใน `../Harmony/For_Tomorrow_Journey.md`** ทำให้บัฟของใบนั้นไม่มีวันถูกถอน
