# `src/Defination/Data/Lightcone/Erudition/Himeko_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Himeko_LC"` · base stats `SetAllyBaseStats(1164, 582, 397)`

**signature ของ Himeko** (ตัวละครยังไม่มีในโปรเจกต์)

| ท่อน | โค้ด |
|---|---|
| ATK% `(7.5 + 1.5S) × Total_enemy` | `WhenOnField_List` |
| มีการ break → DMG `25 + 5S` 1 เทิร์น | `Toughness_break_List` → `buffSingle(..., "Himeko_LC_buff", 1)` |
| ถอน | `After_turn_List` |

## จุดที่ควรระวัง

- **ถอน DMG ด้วยการเขียน `Stats_type` ตรง ๆ แต่ลงด้วย `buffSingle`** — คนละกลไก · `buffSingle` มี `isHaveToAddBuff` กันลงซ้ำ แต่การถอนแบบเขียนตรงไม่ได้ล้าง `buffCheck` (ซึ่ง `isBuffEnd` ล้างให้แล้ว จึงยังถูก)
- `Toughness_break_List` ไม่ guard ว่าใคร break → ใครในทีม break ก็ได้บัฟ ซึ่ง**ตรงกับ kit** ("When an enemy is inflicted with Weakness Break")
- **ATK% คำนวณจาก `Total_enemy` ครั้งเดียวตอนเข้าสนาม** → ถ้าจำนวนศัตรูเปลี่ยนระหว่างเกม ค่าไม่ตาม

> **ชื่อบัฟ `"Himeko_LC_buff"` ถูก copy ไปใช้ผิดที่ใน `../Harmony/For_Tomorrow_Journey.md`** ทำให้บัฟของใบนั้นไม่มีวันถูกถอน
