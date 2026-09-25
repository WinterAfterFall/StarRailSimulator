# `src/Defination/Data/Relic/Iron_Cavalry.h`

เซ็ตจริง: **Iron Cavalry Against the Scourge** · `Relic.Name` = `"Iron_Cavalry"`

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — Break Effect +16% | `Reset_List` → `Stats_type[Stats::BE][AType::None] += 16` | 7 |
| 4-pc — Break DMG ignore DEF 10% (ต้องมี BE ≥ 150%) | `WhenOnField_List` → `Stats_type[Stats::DEF_SHRED][AType::Break] += 10` | 11 |
| 4-pc — Super Break ignore DEF เพิ่ม 15% (ต้องมี BE ≥ 250%) | `Stats_type[Stats::DEF_SHRED][AType::SPB] += 15` | 12 |

## จุดที่ควรรู้

- **ตัวอย่างที่ชัดที่สุดของการใช้ `AType` เป็นตัวจำกัดขอบเขตของ stat** — `DEF_SHRED` ก้อนเดียวกันแต่แยกว่าใช้กับดาเมจประเภทไหน (`AType::Break` = Break DMG, `AType::SPB` = Super Break) ต่างจากตัวอื่นที่ใช้ `AType::None` = ทุกประเภท
- **เงื่อนไข BE ≥ 150% / 250% ถูกตัดทิ้ง** ใส่ทั้งสองชั้นเสมอ · ตัวละครที่ใส่เซ็ตนี้ปั้น BE สูงอยู่แล้ว
- เป็น relic ตัวเดียวในกลุ่มที่ใช้ `WhenOnField_List` แทน `Reset_List` สำหรับสแตตถาวร — ทั้งสอง list ให้ผลเหมือนกันในทางปฏิบัติ ต่างกันแค่จังหวะที่รัน
