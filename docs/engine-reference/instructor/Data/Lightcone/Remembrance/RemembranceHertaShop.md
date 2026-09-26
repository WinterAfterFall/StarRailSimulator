# `src/Defination/Data/Lightcone/Remembrance/RemembranceHertaShop.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Memory’s Curtain Never Falls"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `RemembranceHertaShop` แต่ชื่อใบจริงต่างออกไป** — ชื่อไฟล์บอกแหล่งที่มา (ร้าน Herta)

| ท่อน | โค้ด |
|---|---|
| SPD% `4.5 + 1.5S` | `Reset_List` |
| ผู้สวมใช้ Skill → ทีม DMG `6 + 2S` 3 เทิร์น | `AfterAction_List` → `castToAllyActionData()` + `isSameAction(ptr, AType::SKILL)` |
| ถอน | `After_turn_List` + `AllyDeath_List` |

## จุดที่ทำถูก

**ถอนครบทั้ง 2 ทาง** (`isBuffEnd` และ `isBuffGoneByDeath`)

**ใช้ `AfterAction_List` + `castToAllyActionData()`** เพื่อจับ Skill ที่เป็นได้ทั้ง attack และ buff action

> **แก้ 2026-09-26**: ชื่อบัฟทีมเดิม `"Curtain Never Falls"` ไม่มี prefix · kit ไม่ได้บอกว่าซ้อนไม่ได้และบัฟลงคนอื่น → เติม `ptr->getName()` นำหน้าตามกฎ (ดู `../Nihility/README.md` ข้อ 4)

> มีไฟล์ชื่อคล้ายกันอีก 2 ใบ: `../Nihility/HertaShop.h` และ `../Destruction/HertaShop.h` — คนละใบ คนละ namespace
