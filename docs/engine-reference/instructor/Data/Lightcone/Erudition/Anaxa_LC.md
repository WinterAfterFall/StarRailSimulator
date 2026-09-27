# `src/Defination/Data/Lightcone/Erudition/Anaxa_LC.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"Anaxa_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Anaxa** (ดู `../../Character/Erudition/Anaxa.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Anaxa_LC.h:5` |
| DMG `50 + 10S` | บวกถาวร | `:9` |
| ต้นเทิร์นผู้สวม → energy +10 | `beforeTurnList` guard `turn` เป็นผู้สวม | `:12-15` |
| ผู้สวมโจมตี → เป้าติด DEF ลด `9 + 3S`% นาน 2 เทิร์น | `whenAttackList` → `debuffSingleApply(…, "AnaxaLC_Debuff", 2)` ทุกเป้า | `:17-22` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` | `:25-31` |

## จุดที่ควรระวัง

- **DMG `50 + 10S` ตัดเงื่อนไขทิ้ง** — kit ให้เฉพาะเป้าที่ผู้สวมแปะ weakness ไว้ โค้ดให้ทุกเป้า
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ**

> เคยไม่ guard ทั้ง `beforeTurnList` (ได้ energy ทุกต้นเทิร์นรวมศัตรู) และ `whenAttackList` (ใครโจมตีก็ลด DEF) — kit ระบุ "wearer's turn" / "attacked by the wearer" · แก้แล้ว
