# `src/Defination/Data/Lightcone/Elation/A Little Getaway.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `ALittleGetaway` · `lightCone.name` = `"A Little Getaway"` · base stats `setAllyBaseStats(953, 423, 397)` · 4★ ไม่มีเจ้าของ

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 423, 397)` | `A Little Getaway.h:6` |
| Elation 20/25/30/35/40% | บวกถาวร `15 + 5S` | `:11` |
| ตอนผู้สวมใช้ Elation Skill ดาเมจเจาะ DEF 8/10/12/14/16% | บวก `DEF_SHRED` ช่อง `AType::ELATION_SKILL` ถาวร `6 + 2S` | `:12` |

## จุดที่ควรระวัง

- ข้อความในเกมคือ "ระหว่างที่ผู้สวมใช้ Elation Skill" จึงผูกกับช่อง `ELATION_SKILL` ไม่ใช่ `ELATION_DMG` — ดาเมจ Elation ที่มาจาก Talent หรือท่าอื่นของผู้สวม **ไม่ได้** เจาะ DEF เพิ่ม
- มีผลเฉพาะ Elation Skill ที่สร้าง action โจมตีด้วย `AType::ELATION_SKILL` (เช่น Sparxie, Yao Guang, Aventurine • Waveflair) · Elation Skill แบบบัฟล้วน (Pearl) ไม่มีดาเมจให้เจาะอยู่แล้ว
