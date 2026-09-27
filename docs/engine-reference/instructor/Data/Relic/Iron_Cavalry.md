# `src/Defination/Data/Relic/Iron_Cavalry.h`

เซ็ตจริง: **Iron Cavalry Against the Scourge** · `Relic.name` = `"Iron_Cavalry"`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — Break Effect +16% | บวก BE ถาวร | `Iron_Cavalry.h:7` |
| 4-pc — Break DMG ignore DEF 10% (kit: BE ≥ 150%) | ลงตอนเข้าสนาม จำกัดเฉพาะ `AType::BREAK` · ไม่เช็ค BE | `:11` |
| 4-pc — Super Break ignore DEF อีก 15% (kit: BE ≥ 250%) | จำกัดเฉพาะ `AType::SPB` · ไม่เช็ค BE | `:12` |

## จุดที่ควรรู้

- **ตัวอย่างที่ชัดที่สุดของการใช้ `AType` เป็นตัวจำกัดขอบเขตของ stat** — `DEF_SHRED` ก้อนเดียวกันแต่แยกว่าใช้กับดาเมจประเภทไหน (`AType::BREAK` = Break DMG, `AType::SPB` = Super Break) ต่างจากตัวอื่นที่ใช้ `AType::NONE` = ทุกประเภท
- **เงื่อนไข BE ≥ 150% / 250% ถูกตัดทิ้ง** ใส่ทั้งสองชั้นเสมอ · ตัวละครที่ใส่เซ็ตนี้ปั้น BE สูงอยู่แล้ว
- เป็น relic ตัวเดียวในกลุ่มที่ใช้ `whenOnFieldList` แทน `resetList` สำหรับสแตตถาวร — ทั้งสอง list ให้ผลเหมือนกันในทางปฏิบัติ ต่างกันแค่จังหวะที่รัน
