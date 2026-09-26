# `src/Defination/Data/Planar/Kalpagni_Lantern.h`

`Planar.Name` = `"Kalpagni_Lantern"` · เซ็ตจริง: **Lushaka, the Sunken Seas** ไม่ใช่ — เซ็ตนี้คือ **Forge of the Kalpagni Lantern**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| SPD +6% | `Reset_List` → `Atv_stats->speedPercent += 6` | 7 |
| Break Effect +40% (kit: เฉพาะเป้าที่มี Fire weakness) | `WhenOnField_List` | 11 |

## จุดที่ควรรู้

- **เงื่อนไข Fire weakness ถูกตัดทิ้ง** — เป็นเงื่อนไขที่ผูกกับ **ตัวศัตรู** ไม่ใช่ build ของตัวเอง ต่างจากเซ็ตอื่นในกลุ่มนี้ที่เงื่อนไขอยู่ที่ตัวเอง · ถ้าจะทำจริงต้องอ่าน weakness ของเป้าตอนคำนวณ ซึ่งแปลว่าค่าจะไม่คงที่ตลอดเกม
- SPD เขียนที่ `Atv_stats->speedPercent` ไม่ใช่ `Stats_type[Stats::SPD_P]` — เป็นช่องคนละช่องกัน ทุกเซ็ตที่ให้ SPD ในโฟลเดอร์นี้ใช้ `speedPercent`
