# `src/Defination/Data/Lightcone/Remembrance/RemembranceHertaShop.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Memory’s Curtain Never Falls"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `RemembranceHertaShop` แต่ชื่อใบจริงต่างออกไป** — ชื่อไฟล์บอกแหล่งที่มา (ร้าน Herta)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 529, 397)` | `RemembranceHertaShop.h:5` |
| SPD `4.5 + 1.5S`% | บวก `speedPercent` ถาวร | `:10` |
| ผู้สวมใช้ Skill → ทั้งทีม DMG `6 + 2S` นาน 3 เทิร์น | `AfterAction_List` เฉพาะ Skill ของผู้สวม → `buffAllAlly(…, Curtain, 3)` ชื่อผูกเจ้าของ (`:7`) | `:13-21` |
| ถอนเมื่อหมดอายุ / ตาย | ท้ายเทิร์นผู้ถือ `isBuffEnd` · `AllyDeath_List` + `isBuffGoneByDeath` | `:23-31` · `:33-39` |

## จุดที่ทำถูก

**ถอนครบทั้ง 2 ทาง** (`isBuffEnd` และ `isBuffGoneByDeath`)

**ใช้ `AfterAction_List` + `castToAllyActionData()`** เพื่อจับ Skill ที่เป็นได้ทั้ง attack และ buff action

> **แก้ 2026-09-26**: ชื่อบัฟทีมเดิม `"Curtain Never Falls"` ไม่มี prefix · kit ไม่ได้บอกว่าซ้อนไม่ได้และบัฟลงคนอื่น → เติม `ptr->getName()` นำหน้าตามกฎ (ดู `../Nihility/README.md` ข้อ 4)

> มีไฟล์ชื่อคล้ายกันอีก 2 ใบ: `../Nihility/HertaShop.h` และ `../Destruction/HertaShop.h` — คนละใบ คนละ namespace
