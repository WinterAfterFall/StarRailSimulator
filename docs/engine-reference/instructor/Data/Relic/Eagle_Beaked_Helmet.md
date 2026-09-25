# `src/Defination/Data/Relic/Eagle_Beaked_Helmet.h`

เซ็ตจริง: **Eagle of Twilight Line** · `Relic.Name` = `"Eagle_Beaked_Helmet"` (ชื่อไฟล์เป็นชื่อ **ชิ้นหัว** ไม่ใช่ชื่อเซ็ต)

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — Wind DMG +10% | `Reset_List` → `Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 10` | 11 |
| 4-pc — ใช้อัลติแล้ว advance ตัวเอง 25% | `WhenUseUlt_List` → `if (ally->isSameOwner(ptr)) Action_forward(ptr->Atv_stats.get(), 25)` | 14-18 |
| — | `addUltCondition`: `atv <= Max_atv * 0.25` → ยังไม่กด | 5-8 |

## รากฐาน: relic ที่แก้ AI ของตัวละคร

**เซ็ตนี้ใส่ `addUltCondition` ของตัวเอง** (5-8) — ถ้าตัวละครใกล้ได้เล่นอยู่แล้ว (`atv` เหลือไม่ถึง 25% ของ `Max_atv`) การกดอัลติจะทำให้ advance 25% เสียเปล่า จึงสั่งให้รอ

**นี่คือเหตุผลว่าทำไมจังหวะกดอัลติของตัวละครหนึ่งอาจไม่ได้อยู่ในไฟล์ตัวละครเลย** — `addUltCondition` เป็นรายการเงื่อนไขที่ต่อกันได้ ทั้งไฟล์ตัวละคร relic และ light cone ต่างเพิ่มของตัวเองได้ ทุกเงื่อนไขต้องเป็นจริงพร้อมกันถึงจะกด

> เทียบกับ **Dance! Dance! Dance!** (`Lightcone/.../DDD.h`) ที่ advance ทั้งทีม `14 + 2*S`% แต่ **ไม่มีเงื่อนไขในตัว** → ตัวละครที่อยากกันการเสียเปล่าต้องเขียนเองในไฟล์ตัวเอง · รายละเอียดการตัดสินใจเรื่องนี้อยู่ใน `../README.md` หัวข้อ "แก้เมื่อ 2026-09-13"

## จุดที่ควรรู้

- `ally->isSameOwner(ptr)` คือตัวกรองว่า "คนที่กดอัลติคือเจ้าของ relic ชิ้นนี้ไหม" — `WhenUseUlt_List` เป็น list กลาง ยิงทุกครั้งที่**ใครก็ตาม**กดอัลติ
- **ชื่อไฟล์ทำให้เข้าใจผิดได้ง่าย** — เคยมีโค้ดใน `Tribbie.h` เช็ค `Light_cone.Name == "Eagle_Beaked_Helmet"` ซึ่งไม่มีวันจริง (ลบไปแล้ว)
