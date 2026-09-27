# `src/Defination/Data/Relic/Prisoner in Deep Confinement.h`

เซ็ตจริง: **Prisoner in Deep Confinement** · `Relic.name` = `"Prisoner"` (ชื่อย่อ)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — ATK +12% | บวก ATK% ถาวร | `Prisoner in Deep Confinement.h:7` |
| 4-pc — ignore DEF 6% ต่อ DoT บนเป้า (สูงสุด 3) | ลงเต็มเพดาน 18 ถาวร ไม่นับ DoT จริง | `:8` |

## เงื่อนไขที่ถูกตัดทิ้ง

18 = 6 × 3 คือ **ค่าเต็มเพดาน** โค้ดไม่ได้นับจำนวน DoT บนเป้าจริง · เซ็ตนี้ใส่ให้ตัว DoT (Kafka / Black Swan / Luka) ซึ่งในรอบจำลองจะมี DoT ครบ 3 ชนิดอยู่แล้วเกือบตลอด

> ถ้าจะทำให้ตรง kit ต้องนับจาก `enemy->dotCount` หรือตัวนับชนิด DoT บนศัตรู (`Class/Unit/Enemy.h:86` `changeDotType`) แล้วปรับค่าแบบ delta ทุกครั้งที่จำนวนเปลี่ยน — ราคาแพงกว่าที่ได้คืน
