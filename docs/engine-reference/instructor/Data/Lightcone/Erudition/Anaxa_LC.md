# `src/Defination/Data/Lightcone/Erudition/Anaxa_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Anaxa_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Anaxa** (ดู `../../Character/Erudition/Anaxa.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 582, 529)` | `Anaxa_LC.h:5` |
| DMG `50 + 10S` | บวกถาวร | `:9` |
| ต้นเทิร์นผู้สวม → energy +10 | `Before_turn_List` guard `turn` เป็นผู้สวม | `:12-15` |
| ผู้สวมโจมตี → เป้าติด DEF ลด `9 + 3S`% นาน 2 เทิร์น | `When_attack_List` → `debuffSingleApply(…, "AnaxaLC_Debuff", 2)` ทุกเป้า | `:17-22` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` | `:25-31` |

## จุดที่ควรระวัง

- **DMG `50 + 10S` ตัดเงื่อนไขทิ้ง** — kit ให้เฉพาะเป้าที่ผู้สวมแปะ weakness ไว้ โค้ดให้ทุกเป้า
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ**

> เคยไม่ guard ทั้ง `Before_turn_List` (ได้ energy ทุกต้นเทิร์นรวมศัตรู) และ `When_attack_List` (ใครโจมตีก็ลด DEF) — kit ระบุ "wearer's turn" / "attacked by the wearer" · แก้แล้ว
