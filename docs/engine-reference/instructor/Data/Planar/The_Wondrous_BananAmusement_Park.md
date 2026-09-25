# `src/Defination/Data/Planar/The_Wondrous_BananAmusement_Park.h`

`Planar.Name` = `"The_Wondrous_BananAmusement_Park"` · เซ็ตสาย summon / memosprite

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| CD +16% | `Reset_List` | 7 |
| CD +32% เพิ่ม ขณะมี summon หรือ memosprite อยู่ในสนาม | `Before_turn_List` + flag `buffCheck["Banana"]` — **เช็คเงื่อนไขจริง** | 10-19 |

```cpp
bool onField = ptr->summonList.size() != 0 || (ptr->memosprite && ptr->memosprite->isExisted());
if (onField && !flag)  { flag = 1; CD += 32; }
else if (!onField && flag) { flag = 0; CD -= 32; }
```

## จุดที่ควรรู้

- **`summonList` กับ `memosprite` เป็นคนละระบบ** — summon เป็นของเก่าที่กำลังจะถูก refactor เป็น `ActionValueStats` ล้วน (ดู `future-improvements.md` ข้อ 4) ส่วน memosprite เป็นระบบปัจจุบันของ path Remembrance · เซ็ตนี้รับทั้งสองแบบ
- **เช็คทุกต้นเทิร์นแบบเปิด/ปิด** เหมือน SPD ของ `../Relic/Hero_Wreath.md` · memosprite ถูกสร้างตั้งแต่ setup แต่มีสถานะ `Death` (`Function/Setup/Stats_Reset.h:261`) จนกว่าจะ `summon()` จึงต้องเช็ค `isExisted()` ไม่ใช่แค่ว่า pointer มีอยู่
- ลงด้วยการเขียน `Stats_type` ตรง ๆ ไม่ผ่าน `buffSingle` → ไม่ยิง `StatsAdjust` และไม่ถึง memosprite (ต่างจาก `buffSingleChar` ที่ `Bone_Collection.h` ใช้)

## แก้เมื่อ 2026-09-26
- หลัง refactor `memosprite` เป็นตัวเดียว เงื่อนไขกลายเป็น `ptr->memosprite` (มีอยู่ตั้งแต่ setup) → ตัวละครสาย memosprite ได้ CD +32 ตั้งแต่เข้าสนาม · เปลี่ยนเป็นเช็ค `isExisted()` ทุกต้นเทิร์นใน `Before_turn_List` และถอนเมื่อ memosprite ออกจากสนาม
