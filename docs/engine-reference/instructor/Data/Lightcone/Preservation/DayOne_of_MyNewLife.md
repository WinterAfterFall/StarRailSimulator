# `src/Defination/Data/Lightcone/Preservation/DayOne_of_MyNewLife.h`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| (ทั้งใบ) DEF% +24 | **ถูกคอมเมนต์ทิ้งทั้งไฟล์** ไม่มีโค้ดที่ทำงานจริง | `DayOne_of_MyNewLife.h:1-22` (คอมเมนต์ทั้งหมด) |

## สถานะ: **ถูกคอมเมนต์ทิ้งทั้งไฟล์**

`All_Preservation_LC.h` ยัง `#include"DayOne_of_MyNewLife.h"` อยู่ (ไม่ได้คอมเมนต์) แต่ตัวไฟล์ไม่มีโค้ดที่ทำงานเลย

## โค้ดที่ค้างอยู่ใช้ API รุ่นเก่า

```cpp
// namespace Preservation_Lightcone{
//     void DayOne_of_MyNewLife(ALLY *ptr){
//         ptr->setAllyBaseStats(953,370,463);
//         ptr->lightCone.name = "DayOne_of_MyNewLife";
//         ptr->lightCone.Reset_func = [](ALLY *ptr){
//             ptr->statsType[Stats::DEF_P][AType::NONE]+=24;
//         };
//     }
// }
```

| ของเก่า | ของปัจจุบัน |
|---|---|
| `void DayOne_of_MyNewLife(ALLY *ptr)` | `function<void(CharUnit*)> ชื่อ(int superimpose)` — เป็น factory และรับ `superimpose` |
| `ALLY *ptr` | `CharUnit *ptr` |
| `ptr->lightCone.Reset_func = [](ALLY *ptr){...}` | `resetList.push_back(TriggerByYourSelfFunc(...))` |

**เก็บฟังก์ชันไว้ในช่องของตัวเอง (`lightCone.Reset_func`) แทนการ push เข้า list กลาง** — หลักฐานของสถาปัตยกรรมรุ่นก่อน เหมือนที่เห็นใน `../../Character/Preservation/Aventurine.md`

## ถ้าจะรื้อฟื้น

เขียนใหม่ตามรูปทรงปัจจุบัน (ดู `../README.md`) — สแตตเดียวที่ใบนี้ให้คือ DEF% ซึ่งไม่ต้องรอระบบโล่ จึงทำได้ทันทีถ้าอยากได้ไว้เทียบ
