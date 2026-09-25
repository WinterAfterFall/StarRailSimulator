# `src/Defination/Data/Planar/Talia.h`

`Planar.Name` = `"Talia"` · เซ็ตจริง: **Talia: Kingdom of Banditry**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| Break Effect +16% | `Reset_List` | 7 |
| Break Effect +20% เพิ่ม (kit: ต้องมี SPD ≥ 145) | `WhenOnField_List` | 11 |

## จุดที่ควรรู้

- **เงื่อนไข SPD ถูกตัดทิ้ง** ได้ BE +36% รวมเสมอ
- เป็นตัวอย่างที่ชัดว่าการแยก `Reset_List` / `WhenOnField_List` ในโฟลเดอร์นี้สื่อว่า **ท่อนไหนของ kit มีเงื่อนไข** ไม่ได้ต่างกันทางพฤติกรรม
