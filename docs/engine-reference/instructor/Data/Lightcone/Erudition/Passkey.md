# `src/Defination/Data/Lightcone/Erudition/Passkey.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Passkey"` · base stats `SetAllyBaseStats(741, 370, 265)`

**base stats ต่ำสุดในทุกโฟลเดอร์** (3★)

| ท่อน | โค้ด |
|---|---|
| ใช้ Skill ครั้งแรกของเทิร์น → energy `7 + S` | `AllyActionList` + flag `Passkey` |
| ล้าง flag ต้นเทิร์นตัวเอง | `Before_turn_List` → `turn->isSameName(ptr->Atv_stats->Name)` |

**ไม่มีสแตตติดตัว**

## จุดที่ทำถูก

**flag ที่มีอายุ "หนึ่งเทิร์นของตัวเอง"** — ล้างใน `Before_turn_List` โดย guard ว่าเป็นเทิร์นของผู้สวมจริง ๆ · ต่างจาก `../../Planar/Tengoku@Livestream.md` และ `../../Character/Remembrance/RMC.md` ที่ล้างทุกต้นเทิร์นของทุก unit (ซึ่งทำให้หน้าต่างสั้นกว่าที่ควร)
