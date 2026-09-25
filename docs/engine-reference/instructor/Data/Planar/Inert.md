# `src/Defination/Data/Planar/Inert.h`

`Planar.Name` = `"Inert"` · เซ็ตจริง: **Inert Salsotto**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| CR +8% | `Reset_List` | 7 |
| Ultimate DMG +15% · Follow-up DMG +15% (kit: ต้องมี CR ≥ 50%) | `Reset_List` ก้อนเดียวกัน | 8-9 |

## จุดที่ควรรู้

- **ต่างจากเซ็ตอื่นในโฟลเดอร์ตรงที่รวมทุกอย่างไว้ใน `Reset_List` ก้อนเดียว** ไม่ได้แยกท่อนมีเงื่อนไขไป `WhenOnField_List` — ผลเหมือนกัน แต่อ่านแล้วไม่เห็นว่าท่อนไหนของ kit มีเงื่อนไข
- **เงื่อนไข CR ≥ 50% ถูกตัดทิ้ง**

> `Planar.Name` ของไฟล์นี้เคยเป็น `"SpaceSealing"` เพราะ copy มา แก้แล้ว
