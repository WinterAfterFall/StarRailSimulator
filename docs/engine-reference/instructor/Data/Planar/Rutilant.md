# `src/Defination/Data/Planar/Rutilant.h`

`Planar.Name` = `"Rutilant"` · เซ็ตจริง: **Rutilant Arena**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| CR +8% | `Reset_List` | 7 |
| Basic ATK / Skill DMG +20% (kit: ต้องมี CR ≥ 70%) | `WhenOnField_List` | 11-12 |

## จุดที่ควรรู้

- **เงื่อนไข CR ≥ 70% ถูกตัดทิ้ง**
- ใช้ `AType::SKILL` และ `AType::BA` แยกกันสองบรรทัด — `Stats_type[DMG]` ที่ `AType` เจาะจงจะเข้าเฉพาะ action ประเภทนั้น · **ตัวละครที่สร้าง Skill ด้วย `AType::BA` ผิดประเภทจะได้บัฟผิดก้อน** (เคยเป็นปัญหาใน `Black Swan.h` และ `Luka.h` แก้แล้ว)

> `Planar.Name` ของไฟล์นี้เคยเป็น `"    "` (ช่องว่าง) แก้แล้ว ดู `../README.md`
