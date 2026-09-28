# `src/Defination/Data/Lightcone/Elation/AventurineWaveflair_LC.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `AventurineWaveflair_LC` · `lightCone.name` = `"AventurineWaveflair_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

ชื่อในเกม: **Summer Rides the Surf** · **signature ของ Aventurine • Waveflair** (ดู `../../Character/Elation/AventurineWaveflair.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `AventurineWaveflair_LC.h:9` |
| CRIT Rate 18/21/24/27/30% | บวกถาวร `15 + 3S` | `:15` |
| ใช้ Elation Skill → "Updraft" SPD 24/28/32/36/40% | `whenUseElationSkillList` เฉพาะผู้สวม → ลง `SPD_P 20 + 4S` ครั้งแรกครั้งเดียว | `:25-33` |
| Elation Skill ที่ใช้ต่างจากครั้งก่อน → "Uptrend" Elation 40/55/70/85/100% | เทียบชื่อ action ที่ผู้สวมใส่ลงคิว Aha กับครั้งก่อน (`lastSkill`) ต่างกัน → ลง `ELATION 25 + 15S` ครั้งเดียว | `:28`, `:34-39` |
| ใช้ Elation Skill ครบ 3 ครั้ง → ทีม SP +1 | ตัวนับ `"Summer Surf Uses"` ครบ 3 → `genSkillPoint(ptr, 1)` แล้วเริ่มนับใหม่ | `:41-45` |
| ทุกต้น wave → SP +1 | `startWaveList` → `genSkillPoint(ptr, 1)` | `:49-51` |

## จุดที่ควรระวัง

- **kit ไม่ได้บอกอายุของ Updraft / Uptrend** → ได้แล้วอยู่ตลอดการต่อสู้ (ไม่หมดอายุ ไม่ซ้อน) · user ยืนยัน 2026-09-28
- **"Elation Skill อันไหน" = ชื่อ action** ที่ผู้สวมใส่ลงคิว Aha (`ahaInstantBar.back()->actionName`) เช่น Aventurine • Waveflair มี `"AvWF Cheers"` กับ `"AvWF All In"` · ถ้า Elation Skill ไม่ใส่ action ใด ชื่อจะเป็น `""`
- ครั้งแรกที่ใช้ยังไม่มี "ครั้งก่อน" จึงยังไม่ได้ Uptrend (ธง `"Summer Surf Used Once"`)
- ต้น wave แรกก็ได้ SP +1 ด้วย (ถ้า `startWaveList` ยิงตอนเริ่ม wave แรก)
