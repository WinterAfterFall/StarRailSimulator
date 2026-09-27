# `src/Defination/Data/Lightcone/Erudition/Passkey.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"Passkey"` · base stats `setAllyBaseStats(741, 370, 265)`

**base stats ต่ำสุดในทุกโฟลเดอร์** (3★)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(741, 370, 265)` | `Passkey.h:5` |
| ใช้ Skill → energy `7 + S` (ครั้งเดียวต่อเทิร์น) | `beforeAllyActionList` เฉพาะ Skill ของผู้สวม และ flag `"Passkey"` ยังเป็น 0 | `:13-18` |
| ล้าง flag | ต้นเทิร์นของผู้สวม | `:9-11` |

**ไม่มีสแตตติดตัว**

## จุดที่ทำถูก

**flag ที่มีอายุ "หนึ่งเทิร์นของตัวเอง"** — ล้างใน `beforeTurnList` โดย guard ว่าเป็นเทิร์นของผู้สวมจริง ๆ · ต่างจาก `../../Planar/Tengoku@Livestream.md` และ `../../Character/Remembrance/RMC.md` ที่ล้างทุกต้นเทิร์นของทุก unit (ซึ่งทำให้หน้าต่างสั้นกว่าที่ควร)
