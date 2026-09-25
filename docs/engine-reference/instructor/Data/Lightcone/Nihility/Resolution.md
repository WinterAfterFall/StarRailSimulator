# `src/Defination/Data/Lightcone/Nihility/Resolution.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Resolution"` · base stats `SetAllyBaseStats(953, 476, 331)`

บังคับ `newApplyBaseChanceRequire(50 + S*10)` — เป็นใบเดียวที่เกณฑ์ขึ้นกับ superimpose

| ท่อน | โค้ด |
|---|---|
| โจมตี → เป้าติด `Ensnared` DEF_SHRED `11 + S` | `AfterAttackActionList` |
| ถอน | `After_turn_List` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ

## จุดที่ควรระวัง: จัดการ debuff ด้วยมือทั้งหมด

```cpp
ลง:   if (!debuffApply(ptr, e, ensnared)) continue;
      e->Stats_type[Stats::DEF_SHRED][AType::None] += 11 + superimpose;
      e->debuffEnd[ensnared] = 1 + e->Atv_stats->turnCnt;
ถอน:  if (enemyUnit[turn->num]->debuffEnd[ensnared] == enemyUnit[turn->num]->Atv_stats->turnCnt) {
          ... -= 11 + superimpose;  debuffCheck[ensnared] = 0;  --Total_debuff;
      }
```
**เขียน `Stats_type` / `debuffEnd` / `debuffCheck` / `Total_debuff` เองทั้งหมด** แทนที่จะใช้ `debuffSingleApply(..., ชื่อ, เทิร์น)` + `isDebuffEnd` ที่ทำให้ครบในบรรทัดเดียว

เป็นโค้ดเก่ารูปแบบเดียวกับ `../../Character/Nihility/Pela.md` (ซึ่งบันทึกไว้ว่าควรรีแฟกเตอร์) · **ใช้ `debuffApply` ถูก** (เช็คค่าคืนก่อนบวก stat) จึงไม่รั่วเหมือน `../../Relic/Gallagher`
