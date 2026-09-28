# `src/Defination/Data/Lightcone/Elation/Evanescia_LC.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `Evanescia_LC` · `lightCone.name` = `"Evanescia_LC"` · base stats `setAllyBaseStats(953, 635, 463)`

ชื่อในเกม: **Until the Flowers Bloom Again** · **signature ของ Evanescia** (ดู `../../Character/Elation/Evanescia.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 635, 463)` | `Evanescia_LC.h:7` |
| CRIT DMG 60/75/90/105/120% | บวกถาวร `45 + 15S` | `:14` |
| ERR 10/11.5/13/14.5/16% + Max Energy เกิน 120 ได้ +0.3% ทุก 10 ที่เกิน (นับสูงสุด 360) | `energyRecharge += 8.5 + 1.5S + 0.3 × floor(excess/10)` · `excess = min(360, maxEnergy − 120)` | `:15-16` |
| ใช้ Elation Skill → ศัตรูทุกตัวรับดาเมจเพิ่ม 15/18.75/22.5/26.25/30% นาน 2 เทิร์น | `whenUseElationSkillList` เฉพาะผู้สวม → `debuffAllEnemyApply(…, VUL 11.25 + 3.75S, debuffName, 2)` | `:20-23` |
| ดีบัฟหมดอายุ | `afterTurnList` เทิร์นศัตรู `isDebuffEnd` → ลบ VUL คืน | `:25-31` |

## จุดที่ควรระวัง

- Evanescia มี Max Energy 480 → เกิน 120 อยู่ 360 พอดี = +10.8% ERR เต็มเพดาน
- ERR บวกใน `resetList` ได้ เพราะ `basicReset()` ตั้ง `energyRecharge = 100` ก่อน `resetList` ทำงาน (`Function/Setup/SetCombat.h`)
- kit บอกว่า "ผลประเภทเดียวกันซ้อนไม่ได้" → ชื่อดีบัฟเป็น `"Until the Flowers Bloom Again"` ร่วมกันทุกผู้สวม **ไม่ใส่ชื่อเจ้าของนำหน้า** (ตามข้อยกเว้นของกฎ prefix)
- ใช้ Elation Skill ซ้ำตอนดีบัฟยังอยู่ → ต่ออายุอย่างเดียว ไม่บวกซ้ำ
