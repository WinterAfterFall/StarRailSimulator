# `src/Defination/Data/Lightcone/Erudition/Anaxa_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Anaxa_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Anaxa** (ดู `../../Character/Erudition/Anaxa.md`)

| ท่อน | โค้ด |
|---|---|
| DMG `50 + 10S` | `Reset_List` |
| ต้นเทิร์นของผู้สวม → energy 10 | `Before_turn_List` + `turn->isSameName` |
| ผู้สวมโจมตี → เป้าติด DEF_SHRED `9 + 3S` 2 เทิร์น | `When_attack_List` + `act->isSameName(ptr)` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

## จุดที่ควรระวัง

- **DMG `50 + 10S` ตัดเงื่อนไขทิ้ง** — kit ให้เฉพาะเป้าที่ผู้สวมแปะ weakness ไว้ โค้ดให้ทุกเป้า
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ**

> เคยไม่ guard ทั้ง `Before_turn_List` (ได้ energy ทุกต้นเทิร์นรวมศัตรู) และ `When_attack_List` (ใครโจมตีก็ลด DEF) — kit ระบุ "wearer's turn" / "attacked by the wearer" · แก้แล้ว
