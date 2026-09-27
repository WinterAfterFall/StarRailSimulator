# `src/Defination/Data/Lightcone/Harmony/Meshing_Cogs.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Meshing_Cogs"` · base stats `SetAllyBaseStats(847, 318, 265)`

**free (3★)** — base stats ต่ำสุดในโฟลเดอร์

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(847, 318, 265)` | `Meshing_Cogs.h:5` |
| ผู้สวมโจมตี → energy `3 + S` (ครั้งเดียวต่อเทิร์น) | `AfterAttackActionList` + flag `"Meshing_Cogs_Triggered"` | `:8-13` |
| ผู้สวมถูกตี → energy เดียวกัน (ใช้ flag ร่วม) | `Enemy_hit_List` หาผู้สวมใน `target` ด้วย `num` | `:15-23` |
| ล้าง flag | ต้นเทิร์นของทุก unit | `:25-27` |

## จุดที่น่าสังเกต

**เป็น LC ใบเดียวในโฟลเดอร์นี้ที่ใช้ `Enemy_hit_List`** — trigger ที่มองจากฝั่งศัตรูเป็นผู้กระทำ callback รับ `(Enemy *Attacker, vector<AllyUnit*> target)` · ต้องวน `target` หาตัวเองเอง (ดู `../../Character/Destruction/Mydei.md` E4)

guard ตัวเองด้วย `e->Atv_stats->num == ptr->Atv_stats->num` (เทียบเลขช่อง) ต่างจาก `AfterAttackActionList` ที่เทียบชื่อ — สองสำนวนในไฟล์เดียว

> **แก้ 2026-09-26 ตาม kit** ("This effect can only be triggered 1 time per turn"): เดิมได้ energy ทุกครั้งที่โจมตีและทุกครั้งที่ถูกตี · ตอนนี้ใช้ flag เดียวร่วมกันทั้งสองทาง ล้างใน `Before_turn_List`
