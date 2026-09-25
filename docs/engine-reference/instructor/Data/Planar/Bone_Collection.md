# `src/Defination/Data/Planar/Bone_Collection.h`

`Planar.Name` = `"Bone_Collection"` · เซ็ตจริง: **Bone Collection Serene Demesne** · เซ็ตสาย memosprite

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| HP +12% | `Reset_List` → `Stats_type[Stats::HP_P][AType::None] += 12` | 7 |
| CD +28% | `WhenOnField_List` → `buffSingleChar(ptr,{{Stats::CD, AType::None, 28.0}})` | 11 |

## จุดที่ควรรู้

- **ใช้ `buffSingleChar` ไม่ใช่ `buffSingle`** → CD ลงให้ทั้งตัวละครและ **memosprite ของเขา** (ดู `../Relic/Hero_Wreath.md`) · ถ้าใช้ `buffSingle` memosprite จะไม่ได้ ซึ่งเป็นความต่างที่มองไม่เห็นจากชื่อฟังก์ชัน
- kit มีเงื่อนไขผูกกับ memosprite/HP ซึ่งถูกตัดทิ้ง ใส่ค่าเต็มเสมอ
