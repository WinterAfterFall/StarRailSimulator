# `src/Defination/Data/Lightcone/Harmony/Memories_of_the_Past.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Memories_of_the_Past"` · base stats `SetAllyBaseStats(953, 423, 397)`

**4★**

| ท่อน | โค้ด |
|---|---|
| Break Effect `21 + 7S` | `Reset_List` |
| โจมตี → energy `3 + S` | `AfterAttackActionList` + guard ชื่อผู้โจมตี |

ไฟล์เรียบ ไม่มีบัฟที่ต้องถอน

## จุดที่น่าสังเกต

guard ผู้โจมตีด้วยการเทียบชื่อ: `act->Attacker->Atv_stats->Name == ptr->Atv_stats->Name` — ทำถูก (LC หลายใบในโปรเจกต์ลืม guard) แต่ใช้การเทียบชื่อแทน `act->isSameName(ptr)` ที่มีอยู่
