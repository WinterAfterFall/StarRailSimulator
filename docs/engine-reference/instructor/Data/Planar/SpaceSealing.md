# `src/Defination/Data/Planar/SpaceSealing.h`

`Planar.Name` = `"SpaceSealing"` · เซ็ตจริง: **Space Sealing Station**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| ATK +24% | `Reset_List` → `Stats_type[Stats::ATK_P][AType::None] += 24` | 7 |

ไฟล์ที่สั้นที่สุดในโฟลเดอร์ — มี `Reset_List` ก้อนเดียว ไม่มี trigger

## จุดที่ควรรู้

kit แยกเป็น ATK +12% พื้นฐาน **บวกอีก 12% เมื่อ SPD ≥ 120** แต่โค้ดรวมเป็น 24 ก้อนเดียว ไม่มีการเช็ค SPD · ตัวละครที่ใส่เซ็ตนี้ตั้ง `setSpeedRequire` สูงกว่า 120 อยู่แล้วแทบทุกตัว

> เคยเป็นต้นทางของบั๊กชื่อ: `Inert.h` เคยตั้ง `Planar.Name = "SpaceSealing"` เพราะ copy ไฟล์นี้มา (แก้แล้ว)
