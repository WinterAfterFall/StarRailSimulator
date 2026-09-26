# `src/Defination/Data/Relic/Ever-Glorious Magical Girl.h`

`Relic.Name` = `"Ever-Glorious Magical Girl"` · ฟังก์ชันชื่อ `MagicalGirl` · **เซ็ตสาย Elation**

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — CD +16% | `Reset_List` → `Stats_type[Stats::CD][AType::None] += 16` | 7 |
| 4-pc — ignore DEF สำหรับ Elation DMG +10% (ผู้สวม + memosprite) | `WhenOnField_List` → `buffSingleChar` | 9-11 |
| 4-pc — บัฟทั้งทีมตามค่า `punchline` | `PunchLine_List` | 11-17 |

## รากฐาน: `PunchLine_List` และตัวแปร `punchline`

```cpp
PunchLine_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *SP_maker, int SP){ ... }));
```
เป็น trigger ที่ผูกกับกลไก **Punchline** ของ path Elation · `punchline` เป็นตัวแปร global (ไม่ได้ส่งเข้ามาทาง callback) ที่อ่านตรง ๆ ได้ · callback รับ `SP_maker` กับจำนวน SP เหมือน trigger ฝั่ง skill point

```cpp
int buff = max(0, min(50, punchline) / 5);   // 0..10
buffAllAlly({{Stats::DEF_SHRED, AType::ElationDMG, buff - ptr->buffNote["MagicalGirl Buff"]}});
ptr->setBuffNote("MagicalGirl Buff", buff);
```

**ใช้สำนวน delta + `buffNote` เหมือน A2 ของ `../Character/Abundance/Gallagher.md`** — ลงเฉพาะส่วนต่างจากค่าที่เคยลงไว้แล้วจำค่าใหม่ เพราะ `buffAllAlly` บวกค่าดิบ ไม่มี "ตั้งค่าเป็น" · `punchline` เปลี่ยนได้ตลอดเกม จึงต้องคำนวณใหม่ทุกครั้งที่ trigger ยิง

## จุดที่ควรรู้

- **`AType::ElationDMG` เป็นประเภทดาเมจเฉพาะทางของ path Elation** ใช้จำกัดขอบเขตของ `DEF_SHRED` แบบเดียวกับที่ `Iron_Cavalry.h` ใช้ `AType::Break` / `AType::SPB`
- **`buffNote` เก็บบนตัวเจ้าของ relic แต่บัฟลงทั้งทีม** → ถ้ามีสองคนในทีมใส่เซ็ตนี้ ต่างคนต่างมี `buffNote` ของตัวเอง แต่ `buffAllAlly` บวกให้ทีมทั้งคู่ ผลจะซ้อนกันได้ (ในทางปฏิบัติไม่ค่อยเกิด)
- `min(50, punchline) / 5` เป็นการหารจำนวนเต็ม → ค่าเพิ่มเป็นขั้น ๆ ทีละ 5 punchline

## แก้เมื่อ 2026-09-25
- `PunchLine_List` เปลี่ยนจาก `buffAllAlly` → `buffSingleChar(ptr, ...)` · DEF_SHRED (ElationDMG) จาก Punchline ลงเฉพาะผู้สวมและ memosprite · เดิมแจกทั้งทีม และถ้าใส่สองคนค่าจะซ้อนกัน

## แก้เมื่อ 2026-09-26
- ท่อนพื้นฐาน DEF_SHRED 10 (ElationDMG) เดิมเขียน `Stats_type` ของผู้สวม → memosprite ไม่ได้ · ย้ายไป `WhenOnField_List` + `buffSingleChar` ให้ตรงกับท่อน Punchline
