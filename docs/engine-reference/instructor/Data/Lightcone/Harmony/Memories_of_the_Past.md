# `src/Defination/Data/Lightcone/Harmony/Memories_of_the_Past.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Memories_of_the_Past"` · base stats `SetAllyBaseStats(953, 423, 397)`

**4★**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 423, 397)` | `Memories_of_the_Past.h:5` |
| Break Effect `21 + 7S` | บวกถาวร | `:20` |
| ผู้สวมโจมตี → energy `3 + S` (ครั้งเดียวต่อเทิร์น) | `AfterAttackActionList` + flag `"Memories_of_the_Past_Triggered"` | `:8-13` |
| ล้าง flag | ต้นเทิร์นของทุก unit | `:15-17` |

ไม่มีบัฟที่ต้องถอน

## จุดที่น่าสังเกต

guard ผู้โจมตีด้วยการเทียบชื่อ: `act->Attacker->Atv_stats->Name == ptr->Atv_stats->Name` — ทำถูก (LC หลายใบในโปรเจกต์ลืม guard) แต่ใช้การเทียบชื่อแทน `act->isSameName(ptr)` ที่มีอยู่

> **แก้ 2026-09-26 ตาม kit** ("This effect can only be triggered 1 time per turn"): เดิมได้ energy ทุกครั้งที่โจมตี · ใช้แพตเทิร์น flag + ล้างใน `Before_turn_List` แบบเดียวกับ `../Destruction/Clara_LC.h`
