# `src/Defination/Data/Character/Preservation/Aventurine.h`

kit อ้างอิง: `docs/character-kit-reference/Aventurine.md`

## สถานะ: **ทั้งไฟล์ถูกคอมเมนต์ทิ้ง — ไม่มีโค้ดที่ทำงานเลย**

257 บรรทัด **ไม่มีบรรทัดที่ไม่ใช่คอมเมนต์สักบรรทัด** (ตรวจด้วย `grep -vc "^\s*//\|^\s*$"` → 0)
และ `All_Preservation_char.h` ก็คอมเมนต์ `#include` ทิ้งไว้ด้วย:
```cpp
//#include"Aventurine.h"
```
→ **path Preservation ไม่มีตัวละครที่ใช้งานได้เลยในโปรเจกต์นี้**

## โค้ดที่ค้างอยู่ใช้ API รุ่นเก่า

โค้ดที่คอมเมนต์ไว้เขียนด้วย API คนละรุ่นกับปัจจุบันทั้งหมด เทียบให้เห็นภาพ:

| ของเก่าในไฟล์นี้ | ของปัจจุบัน |
|---|---|
| `Ally_unit[num] = make_unique<Ally>();` | `SetCharBasicStats(...)` คืน `CharUnit*` |
| `Ally_unit[num]->stats->baseHp = 1203;` ทีละฟิลด์ | `ptr->SetAllyBaseStats(HP, ATK, DEF)` |
| `Ally_unit[num]->stats->Char_func.After_turn_func = After_turn;` | `After_turn_List.push_back(TriggerByYourSelf_Func(...))` |
| `ptr->Dmg_bonus_each_element[...]` | `ptr->Stats_each_element[Stats::DMG][...]` |
| `ptr->Def_percent[AType::None]` | `ptr->Stats_type[Stats::DEF_P][AType::None]` |
| `void Set_up(int num, int E, ...)` | `void Setup(int E, ...)` (ไม่มี `num`) |
| `ptr->stats->Eidolon` | `ptr->Eidolon` |
| `Combat_data &act` | `shared_ptr<AllyAttackAction> &act` |

**เป็นหลักฐานว่า engine เคยเปลี่ยนสถาปัตยกรรมครั้งใหญ่** — จาก "ตัวละครเก็บฟังก์ชันไว้ในตัวเอง (`Char_func`)" มาเป็น "ตัวละคร push trigger เข้า list กลาง" (ดู `../../README.md`)

## สิ่งที่ Aventurine ต้องการก่อนจะ implement ใหม่ได้

kit ของ Aventurine เป็นสาย **shield** ล้วน ซึ่ง **engine ยังไม่มีระบบสร้างโล่** — `decreaseSheild()` มีแล้วแต่ไม่มีโค้ดที่ **เพิ่ม** `currentSheild` · ดู `future-improvements.md` ข้อ 2 ซึ่งระบุ "ปลด comment Aventurine" ไว้เป็นงานปลายทางของข้อนั้นโดยตรง

> `Stats::SHEILD` ที่ `../../Relic/Knight_of_Purity_Palace.md` ใส่ไว้ก็รอระบบเดียวกันนี้

## ถ้าจะรื้อฟื้น

1. ทำระบบโล่ก่อน (`future-improvements.md` ข้อ 2)
2. เขียนไฟล์ใหม่ตามแบบแผนปัจจุบัน — **อย่าแก้โค้ดเก่าทีละบรรทัด** เพราะ API ต่างกันแทบทุกบรรทัด ใช้ `Character/Template.h` เป็นโครงแทน
3. ปลดคอมเมนต์ `#include` ใน `All_Preservation_char.h`
