# `src/Defination/Data/Lightcone/Elation/Pearl_LC.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `Pearl_LC` · `lightCone.name` = `"Pearl_LC"` · base stats `setAllyBaseStats(1058, 476, 595)`

ชื่อในเกม: **Colors for Tomorrow** · **signature ของ Pearl** (ดู `../../Character/Elation/Pearl.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 476, 595)` | `Pearl_LC.h:8` |
| DEF 48/60/72/84/96% | บวกถาวร `36 + 12S` | `:14` |
| ใช้ Elation Skill "ใส่เพื่อนทุกคน" | `whenUseElationSkillList` (event ใหม่ ดู `../../../Function/Combat/AhaCombat.md`) เฉพาะผู้สวม | `:19-24` |
| → ศัตรูทุกตัวรับดาเมจเพิ่ม 22/27.5/33/38.5/44% นาน 3 เทิร์น | `debuffAllEnemyApply(ptr, {VUL 16.5 + 5.5S}, debuffName, 3)` | `:25` |
| → Energy แบบ fixed 10 | `increaseEnergy(ptr, 0, 10)` (ไม่คูณ ERR เพราะ kit เขียนว่า fixed) | `:26` |
| → ฮีลเพื่อนทุกคน 10/12.5/15/17.5/20% ของ DEF ผู้สวม | `restoreHP(HealSrc(HealSrcType::DEF, 7.5 + 2.5S))` | `:27` |
| ดีบัฟหมดอายุ | `afterTurnList` เทิร์นศัตรู `isDebuffEnd` → ลบ VUL คืน | `:30-36` |

## จุดที่ควรระวัง

- **"Elation Skill ใส่เพื่อนทุกคน"** (user ยืนยัน 2026-09-28): ถ้า Elation Skill ของผู้สวมใส่ action โจมตีของตัวเองลงคิว Aha (`ahaInstantBar.back()` เป็น `AllyAttackAction` ของผู้สวม) ถือว่าเป็นท่าโจมตี → **ไม่ติด** (`:21-24`) · Pearl ไม่ใส่ action ใดลงคิว (Elation Skill ของเธอเป็นธงให้ทุกคน) → ติด
- Silver Wolf LV.999 นอก Godmode ใช้ Pro-Gamer Move (บัฟตัวเอง ไม่ใส่ action) ถูกนับว่า "ใส่ทุกคน" ไปด้วย — user ยืนยันว่ารับได้ (2026-09-28)
- ชื่อดีบัฟ `"<ชื่อผู้สวม> Colors for Tomorrow"` (kit ไม่ได้บอกว่าซ้อนไม่ได้ จึงใส่ชื่อเจ้าของนำหน้า)
