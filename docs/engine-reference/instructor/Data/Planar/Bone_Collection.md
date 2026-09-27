# `src/Defination/Data/Planar/Bone_Collection.h`

`Planar.Name` = `"Bone_Collection"` · เซ็ตจริง: **Bone Collection Serene Demesne** · เซ็ตสาย memosprite

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| HP +12% | บวก HP% ถาวร | `Bone_Collection.h:7` |
| CD +28% (kit: มีเงื่อนไข HP / memosprite) | ลงตอนเข้าสนามด้วย `buffSingleChar` → ผู้สวมและ memosprite ได้ทั้งคู่ · ไม่เช็คเงื่อนไข | `:10-12` |

## จุดที่ควรรู้

- **ใช้ `buffSingleChar` ไม่ใช่ `buffSingle`** → CD ลงให้ทั้งตัวละครและ **memosprite ของเขา** (ดู `../Relic/Hero_Wreath.md`) · ถ้าใช้ `buffSingle` memosprite จะไม่ได้ ซึ่งเป็นความต่างที่มองไม่เห็นจากชื่อฟังก์ชัน
- kit มีเงื่อนไขผูกกับ memosprite/HP ซึ่งถูกตัดทิ้ง ใส่ค่าเต็มเสมอ
