# `src/Defination/Data/Relic/Poet_Dill.h`

เซ็ตจริง: **Poet of Mourning Collapse** · `Relic.Name` = `"Poet_Dill"`

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — Quantum DMG +10% | `Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 10` | 9 |
| 4-pc — SPD −8% | `ptr->Atv_stats->speedPercent -= 8` | 8 |
| 4-pc — CR +20% / +32% ถ้า SPD < 110 / 95 (ทั้งผู้สวมและ memosprite) | `WhenOnField_List` → `buffSingleChar(ptr,{{CR, 32}})` | 11-13 |

## จุดที่ควรรู้

- **เป็นเซ็ตเดียวที่โบนัสมี "ผลเสีย"** — SPD −8% เขียนเป็นค่าติดลบที่ `speedPercent` ตรง ๆ ซึ่งกระทบ `setSpeedRequire` ของตัวละคร (ต้องปั้น SPD เผื่อ)
- **เลือกชั้น 32 (ชั้นสูงสุด) แบบไม่เช็ค SPD** — kit ให้ 20% ที่ SPD < 110 และ 32% ที่ SPD < 95 · ตัวละครที่ใส่เซ็ตนี้เป็นสาย SPD ต่ำจงใจอยู่แล้ว
- SPD เป็น stat ที่ตัวเองลดและเป็นเงื่อนไขของตัวเองด้วย → ถ้าวันหนึ่งจะทำเงื่อนไขจริง ต้องระวังว่าค่าที่เอามาเทียบคือ SPD **หลัง** หัก 8% แล้วหรือยัง

## แก้เมื่อ 2026-09-26
- CR +32 เดิมเขียน `Stats_type` ของผู้สวมใน `Reset_List` → memosprite ไม่ได้ ทั้งที่ kit ระบุ "also applies to the wearer's memosprite" · ย้ายไป `WhenOnField_List` + `buffSingleChar`
