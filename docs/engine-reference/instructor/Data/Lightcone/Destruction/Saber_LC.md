# `src/Defination/Data/Lightcone/Destruction/Saber_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Saber_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Saber** (ดู `../../Character/Destruction/Saber.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Saber_LC.h:5` |
| CD `27 + 9S` | บวกถาวร | `:9` |
| ผู้สวมกด Ult → ATK `30 + 10S`% นาน 2 เทิร์น | `whenUseUltList` + `isSameOwner` → บัฟชื่อ `"Saber_LC"` | `:14-16` |
| ถ้า Max Energy ≥ 300 → energy +10% ของ max และ ATK อีกก้อน | บัฟชื่อแยก `"Extra Saber_LC"` | `:17-21` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม เช็คทั้งสองชื่อ | `:25-32` |

## จุดที่น่าสนใจ

**เงื่อนไข `maxEnergy >= 300` เป็นการเช็คว่าผู้สวมคือ Saber หรือไม่โดยอ้อม** — Saber มี energy ult 360 ซึ่งเป็นค่าเดียวในโปรเจกต์ที่ถึงเกณฑ์นี้ · เขียนแบบนี้ทำให้ LC ใช้กับตัวอื่นได้โดยไม่ต้องเช็คชื่อ

**ใช้บัฟสองชื่อแยกกันแทนการคูณค่า** — ต่างจาก `Mydei_LC.md` ที่นับจำนวนก้อนไว้ใน `buffNote` · ทั้งสองวิธีใช้ได้ แต่แบบนี้อ่านง่ายกว่าเมื่อแต่ละก้อนมีเงื่อนไขต่างกัน
