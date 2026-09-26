# `src/Defination/Data/Lightcone/Harmony/Meshing_Cogs.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Meshing_Cogs"` · base stats `SetAllyBaseStats(847, 318, 265)`

**free (3★)** — base stats ต่ำสุดในโฟลเดอร์

| ท่อน | โค้ด |
|---|---|
| โจมตี → energy `3 + S` | `AfterAttackActionList` |
| **ถูกโจมตี** → energy `3 + S` | `Enemy_hit_List` |

## จุดที่น่าสังเกต

**เป็น LC ใบเดียวในโฟลเดอร์นี้ที่ใช้ `Enemy_hit_List`** — trigger ที่มองจากฝั่งศัตรูเป็นผู้กระทำ callback รับ `(Enemy *Attacker, vector<AllyUnit*> target)` · ต้องวน `target` หาตัวเองเอง (ดู `../../Character/Destruction/Mydei.md` E4)

guard ตัวเองด้วย `e->Atv_stats->num == ptr->Atv_stats->num` (เทียบเลขช่อง) ต่างจาก `AfterAttackActionList` ที่เทียบชื่อ — สองสำนวนในไฟล์เดียว
