# `src/Defination/Data/Lightcone/Preservation/DayOne_of_MyNewLife.h`

## สถานะ: **ถูกคอมเมนต์ทิ้งทั้งไฟล์**

`All_Preservation_LC.h` ยัง `#include"DayOne_of_MyNewLife.h"` อยู่ (ไม่ได้คอมเมนต์) แต่ตัวไฟล์ไม่มีโค้ดที่ทำงานเลย

## โค้ดที่ค้างอยู่ใช้ API รุ่นเก่า

```cpp
// namespace Preservation_Lightcone{
//     void DayOne_of_MyNewLife(Ally *ptr){
//         ptr->SetAllyBaseStats(953,370,463);
//         ptr->Light_cone.Name = "DayOne_of_MyNewLife";
//         ptr->Light_cone.Reset_func = [](Ally *ptr){
//             ptr->Stats_type[Stats::DEF_P][AType::None]+=24;
//         };
//     }
// }
```

| ของเก่า | ของปัจจุบัน |
|---|---|
| `void DayOne_of_MyNewLife(Ally *ptr)` | `function<void(CharUnit*)> ชื่อ(int superimpose)` — เป็น factory และรับ `superimpose` |
| `Ally *ptr` | `CharUnit *ptr` |
| `ptr->Light_cone.Reset_func = [](Ally *ptr){...}` | `Reset_List.push_back(TriggerByYourSelf_Func(...))` |

**เก็บฟังก์ชันไว้ในช่องของตัวเอง (`Light_cone.Reset_func`) แทนการ push เข้า list กลาง** — หลักฐานของสถาปัตยกรรมรุ่นก่อน เหมือนที่เห็นใน `../../Character/Preservation/Aventurine.md`

## ถ้าจะรื้อฟื้น

เขียนใหม่ตามรูปทรงปัจจุบัน (ดู `../README.md`) — สแตตเดียวที่ใบนี้ให้คือ DEF% ซึ่งไม่ต้องรอระบบโล่ จึงทำได้ทันทีถ้าอยากได้ไว้เทียบ
