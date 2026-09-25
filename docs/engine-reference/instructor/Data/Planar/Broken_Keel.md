# `src/Defination/Data/Planar/Broken_Keel.h`

`Planar.Name` = `"Broken_Keel"` · เซ็ตจริง: **Broken Keel** · เซ็ตซัพพอร์ต

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| Effect RES +10% | `Reset_List` → `Stats_type[Stats::RES][AType::None] += 10` | 7 |
| **ทั้งทีม** CD +10% (kit: ต้องมี Effect RES ≥ 30%) | `WhenOnField_List` → `buffAllAlly({{Stats::CD, AType::None, 10.0}})` | 11 |

## จุดที่ควรรู้

- **เป็นเซ็ตที่ผลตกไปที่คนอื่น** ใช้ `buffAllAlly` แบบไม่มีชื่อบัฟ = บวกค่าดิบครั้งเดียวตอนเข้าสนาม ไม่มีการถอน ซึ่งถูกต้องเพราะเป็นบัฟถาวร
- **เงื่อนไข Effect RES ≥ 30% ถูกตัดทิ้ง** — ถ้าจะทำจริงต้องอ่านค่าหลังรวม substats ซึ่งรู้ได้หลัง `Reset_List` จบ
