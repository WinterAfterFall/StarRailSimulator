# `src/Defination/Data/Lightcone/Destruction/Saber_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Saber_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Saber** (ดู `../../Character/Destruction/Saber.md`)

| ท่อน | โค้ด |
|---|---|
| CD `27 + 9S` | `Reset_List` |
| กด ult → ATK `30 + 10S` 2 เทิร์น | `WhenUseUlt_List` + `isSameOwner` |
| **ถ้า `Max_energy >= 300`** → ATK อีกก้อน + energy 10 (ไม่ผ่าน ER) | บัฟชื่อ `"Extra Saber_LC"` แยก |
| ถอน | `After_turn_List` → เช็คทั้งสองชื่อ |

## จุดที่น่าสนใจ

**เงื่อนไข `Max_energy >= 300` เป็นการเช็คว่าผู้สวมคือ Saber หรือไม่โดยอ้อม** — Saber มี energy ult 360 ซึ่งเป็นค่าเดียวในโปรเจกต์ที่ถึงเกณฑ์นี้ · เขียนแบบนี้ทำให้ LC ใช้กับตัวอื่นได้โดยไม่ต้องเช็คชื่อ

**ใช้บัฟสองชื่อแยกกันแทนการคูณค่า** — ต่างจาก `Mydei_LC.md` ที่นับจำนวนก้อนไว้ใน `buffNote` · ทั้งสองวิธีใช้ได้ แต่แบบนี้อ่านง่ายกว่าเมื่อแต่ละก้อนมีเงื่อนไขต่างกัน
