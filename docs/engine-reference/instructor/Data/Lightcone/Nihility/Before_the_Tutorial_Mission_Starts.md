# `src/Defination/Data/Lightcone/Nihility/Before_the_Tutorial_Mission_Starts.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Before_the_Tutorial"` · base stats `SetAllyBaseStats(953, 476, 331)`

ฟังก์ชันชื่อ `Before_the_Tutorial` (สั้นกว่าชื่อไฟล์)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(953, 476, 331)` | `Before_the_Tutorial_Mission_Starts.h:5` |
| EHR `15 + 5S` | บวกถาวร | `:9` |
| ผู้สวมโจมตีเป้าที่ติด DEF ลดอยู่ → energy `3 + S` | `AfterAttackActionList` วนเป้าหา `DEF_SHRED` ช่องใดก็ได้ที่ > 0 · เจอแล้วให้ energy ครั้งเดียวแล้ว `return` | `:12-21` |

## รากฐาน: เช็คเงื่อนไขจาก stat ของศัตรูโดยตรง

```cpp
if (!act->isSameOwnerName(ptr)) return;
for (auto e : act->targetList)
    for (auto &shred : e->Stats_type[Stats::DEF_SHRED])
        if (shred.second > 0) { Increase_energy(ptr, 3 + superimpose); return; }
```
**อ่าน `Stats_type` ของศัตรูเพื่อถามว่า "มี DEF shred อยู่ไหม"** แทนการเช็คชื่อ debuff — ใช้ได้กับ DEF shred จากทุกแหล่ง และทุกช่อง `AType`

`return` หลังเจอตัวแรก = ได้ energy ครั้งเดียวต่อ action

> **แก้ 2026-09-26**: (1) เดิม guard ด้วยชื่อ `Attacker->Atv_stats->Name` → memosprite ของผู้สวมไม่นับ · เปลี่ยนเป็น `isSameOwnerName(ptr)` (2) เดิมเช็คเฉพาะช่อง `AType::None` → วนทุกช่อง
