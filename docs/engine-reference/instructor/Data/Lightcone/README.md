# `src/Defination/Data/Lightcone/`

73 ไฟล์ แยกโฟลเดอร์ตาม Path · ทุกใบอยู่ใน `namespace <Path>_Lightcone` · แต่ละโฟลเดอร์มี `All_<Path>_LC.h` และ `All_Lighcone.h` รวมทุก path อีกชั้น (สะกดตก `t`)

อ่าน `../README.md` (กฎกลางของ `Data/`) และ `../Relic/README.md` ก่อน เพราะโครงคล้ายกัน

## รูปทรงมาตรฐาน — ต่างจาก Relic ตรงที่เป็น factory เสมอ

```cpp
namespace <Path>_Lightcone{
    function<void(CharUnit *ptr)> ชื่อ(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(HP, ATK, DEF);      // <- LC เขียนทับ base stats ของตัวละคร
            ptr->Light_cone.Name = "ชื่อ";
            Reset_List.push_back(...);                 // สแตตติดตัว
            <list ที่ตรงกับเงื่อนไข>.push_back(...);    // เอฟเฟกต์
        };
    }
}
```

**ทุกใบรับ `superimpose` (S1-S5)** แล้วคำนวณค่าเป็น `ฐาน + ต่อชั้น * superimpose` — ต่างจาก Relic ที่ส่วนใหญ่เป็นฟังก์ชันตรง ๆ

> **`superimpose` คือเลข S ตรง ๆ (1-5)** — `ManualBuilder.cpp` เรียกด้วย `(1)` / `(5)` · เช่น `DDD` ให้ `14 + 2*superimpose` → S1 = 16% และ S5 = 24% ตรงกับ kit · ค่าคงที่ในสูตรจึงเป็น "ค่า S1 ลบหนึ่งขั้น" ไม่ใช่ค่า S1

## รากฐานที่สำคัญที่สุด: LC เขียนทับ base stats

```cpp
ptr->SetAllyBaseStats(1164, 529, 463);
```
**ทุก LC เรียก `SetAllyBaseStats` ทับค่าที่ไฟล์ตัวละครตั้งไว้** — เพราะ base stats ของตัวละครในเกมรวม stat ของ Light Cone ที่สวมอยู่ · นี่คือเหตุผลที่ `LC(ptr)` ต้องถูกเรียก **หลัง** `SetAllyBaseStats` ของตัวละครใน `Setup` (ดู `../README.md`)

> **ผลที่ตามมา**: ถ้าลืมใส่ `SetAllyBaseStats` ใน LC ใบใหม่ ตัวละครจะใช้ base stats ที่ไม่รวม LC ซึ่งต่ำกว่าจริงมาก

## โฟลเดอร์และจำนวน

| Path | จำนวนไฟล์ | หมายเหตุ |
|---|---|---|
| `Nihility/` | 14 | มากที่สุด |
| `Destruction/` | 13 | |
| `Erudition/` | 10 | |
| `Harmony/` | 10 | มี `DDD.h` ที่มีผลต่อจังหวะ ult ของทั้งทีม |
| `Remembrance/` | 8 | |
| `Elation/` | 4 | |
| `Abundance/` | 1 | `Multiplication.h` |
| `Preservation/` | 1 | `DayOne_of_MyNewLife.h` |
| `The_Hunt/` | **0** | มีแต่โฟลเดอร์เปล่า |

## แบบแผนที่เห็นซ้ำทุกโฟลเดอร์

**1. `WhenUseUlt_List` + `ally->isSameOwner(ptr)`** — เอฟเฟกต์ที่ทำงานตอนเจ้าของกด ult · เป็น trigger ที่ LC ใช้บ่อยที่สุด

**2. บัฟที่ต้องถอนใช้ `After_turn_List` + `isBuffEnd`** เหมือนฝั่งตัวละครและ relic ทุกประการ

**3. LC ของซัพพอร์ตมักบัฟทั้งทีมด้วย `buffAllAlly`** แล้วคุมอายุด้วยบัฟชื่อเดียวบนตัวผู้สวม

**4. ชื่อบัฟที่ลงให้คนอื่นต้อง prefix ด้วยชื่อเจ้าของ** — `Cerydra LC.h` และ `Sunday_LC.h` ทำถูก (`ptr->getName() + " ..."`), ใบอื่นหลายใบไม่ได้ทำ

**5. `ptr->Light_cone.Name` เก็บแค่ชื่อ** — ตัวละครอ่านชื่อนี้เพื่อเช็คเงื่อนไขได้ (`Tingyun.h` เคยมีการเช็คแบบนี้)
