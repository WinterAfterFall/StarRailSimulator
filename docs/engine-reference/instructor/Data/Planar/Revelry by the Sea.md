# `src/Defination/Data/Planar/Revelry by the Sea.h`

`Planar.Name` = `"Revelry"` · ฟังก์ชันชื่อ `Revelry` (สั้นกว่าชื่อไฟล์) · เซ็ตสาย DoT

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| ATK +12% | `Reset_List` | 7 |
| DoT DMG +24% (kit: +12% เมื่อ ATK ≥ 2400, +24% เมื่อ ATK ≥ 3600) | `WhenOnField_List` → `Stats_type[Stats::DMG][AType::Dot] += 24` | 10 |

## จุดที่ควรรู้

- **เงื่อนไข ATK ถูกตัดทิ้ง** ได้ DoT DMG +24% (ชั้นบน) เสมอ
- ใช้ `AType::Dot` เป็นตัวจำกัดขอบเขต — เข้าเฉพาะดาเมจที่ `damageTypeList` มี `AType::Dot` · ตัวละคร DoT สร้าง action ด้วย `AType::Shock` / `AType::Bleed` / `AType::Burn` / `AType::WindShear` (ดู `../Character/Nihility/Kafka.md`) แต่ **constructor ของ `AllyAttackAction` เติม `AType::Dot` ให้ทั้ง 4 ประเภทอัตโนมัติ** (`Class/ActionData/AllyAttackAction.h:148-175`) → บัฟนี้เข้า DoT ทุกธาตุตามปกติ ไม่ต้องใส่ `AType::Dot` เองตอนสร้าง action
