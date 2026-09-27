# `src/Defination/Data/Planar/Revelry by the Sea.h`

`Planar.name` = `"Revelry"` · ฟังก์ชันชื่อ `Revelry` (สั้นกว่าชื่อไฟล์) · เซ็ตสาย DoT

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| ATK +12% | บวก ATK% ถาวร | `Revelry by the Sea.h:7` |
| DoT DMG +12% (ATK ≥ 2400) / +24% (ATK ≥ 3600) | ลงชั้นบน 24 ถาวรที่ `AType::DOT` · ไม่เช็ค ATK | `:9-11` |

## จุดที่ควรรู้

- **เงื่อนไข ATK ถูกตัดทิ้ง** ได้ DoT DMG +24% (ชั้นบน) เสมอ
- ใช้ `AType::DOT` เป็นตัวจำกัดขอบเขต — เข้าเฉพาะดาเมจที่ `damageTypeList` มี `AType::DOT` · ตัวละคร DoT สร้าง action ด้วย `AType::SHOCK` / `AType::BLEED` / `AType::BURN` / `AType::WIND_SHEAR` (ดู `../Character/Nihility/Kafka.md`) แต่ **constructor ของ `AllyAttackAction` เติม `AType::DOT` ให้ทั้ง 4 ประเภทอัตโนมัติ** (`Class/ActionData/AllyAttackAction.h:148-175`) → บัฟนี้เข้า DoT ทุกธาตุตามปกติ ไม่ต้องใส่ `AType::DOT` เองตอนสร้าง action
