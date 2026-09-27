# `src/Defination/Data/Relic/GeniusBrilliant.h`

เซ็ตจริง: **Genius of Brilliant Stars** · `Relic.name` = `"GeniusBrilliant"`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — Quantum DMG +10% | บวก DMG ธาตุควอนตัมถาวร | `GeniusBrilliant.h:7` |
| 4-pc — ignore DEF 10% (+10% ถ้าเป้าอ่อน Quantum) | รวมเป็น 20 ถาวรทุกดาเมจ ไม่เช็ค weakness ของเป้า | `:8` |

## เงื่อนไขที่ถูกตัดทิ้ง

kit แยกเป็น 10% พื้นฐาน + อีก 10% เฉพาะเป้าที่มี Quantum weakness แต่โค้ด**รวมเป็น 20 แบบไม่มีเงื่อนไข** — ตัวละครที่ใส่เซ็ตนี้เป็นสาย Quantum อยู่แล้วและซิมตั้งศัตรูให้มี weakness ตรงกัน จึงถือว่าเข้าเงื่อนไขเสมอ (แนวเดียวกับ `Iron_Cavalry.md`, `Poet_Dill.md`, `Prisoner in Deep Confinement.md`)

> ผลข้างเคียง: ถ้าวันหนึ่งจำลองศัตรูที่ไม่มี Quantum weakness ตัวเลขจะสูงเกินจริง 10%
