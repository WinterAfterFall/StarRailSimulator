# `src/Defination/Data/Lightcone/Nihility/Fugue_LC.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"Fugue_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Fugue** (ดู `../../Character/Nihility/Fugue.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Fugue_LC.h:5` |
| Break Effect `50 + 10S` | บวกถาวร | `:9` |
| ศัตรูถูก break (โดยใครก็ได้) → รับ Break DMG +`15 + 3S`% ต่อชั้น (สูงสุด 2, นาน 2 เทิร์น) | `toughnessBreakList` → `debuffStackSingle(…, 1, 2, charring, 2)` ชื่อผูกเจ้าของ (`:7`) | `:12-14` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` → `debuffStackRemove` | `:16-22` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " Charring"`)

## จุดที่ควรระวัง

- **`toughnessBreakList` ไม่ guard ว่าใคร break** → ลง VUL ทุกครั้งที่ใครก็ตาม break ซึ่งน่าจะตรงกับ kit ของใบนี้ แต่ควรยืนยัน
- ~~`afterTurnList` ใช้ `enemyUnit[turn->num]` ตรง ๆ~~ — เปลี่ยนเป็น `turn->canCastToEnemy()` แล้ว 2026-09-26

> **แก้ 2026-09-26**: เดิมเป็น `VUL[AType::NONE]` (เพิ่มดาเมจทุกชนิด) และไม่ stack · kit เป็น Break DMG taken stack 2 → เปลี่ยนเป็น `VUL[AType::BREAK]` + `debuffStackSingle`
