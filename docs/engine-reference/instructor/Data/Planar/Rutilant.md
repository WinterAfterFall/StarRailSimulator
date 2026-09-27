# `src/Defination/Data/Planar/Rutilant.h`

`Planar.Name` = `"Rutilant"` · เซ็ตจริง: **Rutilant Arena**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| CR +8% | บวก CR ถาวร | `Rutilant.h:7` |
| Basic ATK และ Skill DMG +20% (kit: CR ≥ 70%) | บวก DMG ที่ `AType::SKILL` และ `AType::BA` ตอนเข้าสนาม · ไม่เช็ค CR | `:10-13` |

## จุดที่ควรรู้

- **เงื่อนไข CR ≥ 70% ถูกตัดทิ้ง**
- ใช้ `AType::SKILL` และ `AType::BA` แยกกันสองบรรทัด — `Stats_type[DMG]` ที่ `AType` เจาะจงจะเข้าเฉพาะ action ประเภทนั้น · **ตัวละครที่สร้าง Skill ด้วย `AType::BA` ผิดประเภทจะได้บัฟผิดก้อน** (เคยเป็นปัญหาใน `Black Swan.h` และ `Luka.h` แก้แล้ว)

> `Planar.Name` ของไฟล์นี้เคยเป็น `"    "` (ช่องว่าง) แก้แล้ว ดู `../README.md`
