# `src/Defination/Data/Lightcone/Nihility/Fugue_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Fugue_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Fugue** (ดู `../../Character/Nihility/Fugue.md`)

| ท่อน | โค้ด |
|---|---|
| Break Effect `50 + 10S` | `Reset_List` |
| มีการ break → เป้าติด Break VUL `15 + 3S` 2 เทิร์น stack สูงสุด 2 | `Toughness_break_List` → `debuffStackSingle(..., 1, 2, Charring, 2)` |
| ถอนทุก stack | `After_turn_List` → `isDebuffEnd` + `debuffStackRemove` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " Charring"`)

## จุดที่ควรระวัง

- **`Toughness_break_List` ไม่ guard ว่าใคร break** → ลง VUL ทุกครั้งที่ใครก็ตาม break ซึ่งน่าจะตรงกับ kit ของใบนี้ แต่ควรยืนยัน
- **`After_turn_List` ใช้ `enemyUnit[turn->num]` โดยตรงหลังเช็ค `turn->side != Side::Enemy`** แทน `turn->canCastToEnemy()` — โค้ดเก่า แต่ผลเหมือนกัน

> **แก้ 2026-09-26**: เดิมเป็น `VUL[AType::None]` (เพิ่มดาเมจทุกชนิด) และไม่ stack · kit เป็น Break DMG taken stack 2 → เปลี่ยนเป็น `VUL[AType::Break]` + `debuffStackSingle`
