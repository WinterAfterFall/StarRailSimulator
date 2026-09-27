# `src/Defination/Data/Planar/Revelry by the Sea.h`

`Planar.Name` = `"Revelry"` · ฟังก์ชันชื่อ `Revelry` (สั้นกว่าชื่อไฟล์) · เซ็ตสาย DoT

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| ATK +12% | บวก ATK% ถาวร | `Revelry by the Sea.h:7` |
| DoT DMG +12% (ATK ≥ 2400) / +24% (ATK ≥ 3600) | ลงชั้นบน 24 ถาวรที่ `AType::Dot` · ไม่เช็ค ATK | `:9-11` |

## จุดที่ควรรู้

- **เงื่อนไข ATK ถูกตัดทิ้ง** ได้ DoT DMG +24% (ชั้นบน) เสมอ
- ใช้ `AType::Dot` เป็นตัวจำกัดขอบเขต — เข้าเฉพาะดาเมจที่ `damageTypeList` มี `AType::Dot` · ตัวละคร DoT สร้าง action ด้วย `AType::Shock` / `AType::Bleed` / `AType::Burn` / `AType::WindShear` (ดู `../Character/Nihility/Kafka.md`) แต่ **constructor ของ `AllyAttackAction` เติม `AType::Dot` ให้ทั้ง 4 ประเภทอัตโนมัติ** (`Class/ActionData/AllyAttackAction.h:148-175`) → บัฟนี้เข้า DoT ทุกธาตุตามปกติ ไม่ต้องใส่ `AType::Dot` เองตอนสร้าง action
