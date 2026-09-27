# `src/Defination/Data/Planar/The_Wondrous_BananAmusement_Park.h`

`Planar.name` = `"The_Wondrous_BananAmusement_Park"` · เซ็ตสาย summon / memosprite

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| CD +16% | บวก CD ถาวร | `The_Wondrous_BananAmusement_Park.h:7` |
| CD +32% เพิ่ม ขณะมี summon หรือ memosprite อยู่สนาม | ต้นทุกเทิร์นเช็ค `summonList` ไม่ว่าง หรือ `memosprite->isExisted()` · ลง/ถอน 32 ตามสถานะ ใช้ flag `buffCheck["Banana"]` กันลงซ้ำ — **เช็คเงื่อนไขจริง** | `:10-19` (เงื่อนไข `:11`) |

```cpp
bool onField = ptr->summonList.size() != 0 || (ptr->memosprite && ptr->memosprite->isExisted());
if (onField && !flag)  { flag = 1; CD += 32; }
else if (!onField && flag) { flag = 0; CD -= 32; }
```

## จุดที่ควรรู้

- **`summonList` กับ `memosprite` เป็นคนละระบบ** — summon ตอนนี้เป็น `TimerATV` (ATV ล้วน ไม่มี stats · `Class/Unit/ActionValueStats.h`) ส่วน memosprite เป็นระบบปัจจุบันของ path Remembrance · เซ็ตนี้รับทั้งสองแบบ
- **เช็คทุกต้นเทิร์นแบบเปิด/ปิด** เหมือน SPD ของ `../Relic/Hero_Wreath.md` · memosprite ถูกสร้างตั้งแต่ setup แต่มีสถานะ `DEATH` (`Function/Setup/Stats_Reset.h`) จนกว่าจะ `summon()` จึงต้องเช็ค `isExisted()` ไม่ใช่แค่ว่า pointer มีอยู่
- ลงด้วยการเขียน `statsType` ตรง ๆ ไม่ผ่าน `buffSingle` → ไม่ยิง `statsAdjust` และไม่ถึง memosprite (ต่างจาก `buffSingleChar` ที่ `Bone_Collection.h` ใช้)

## แก้เมื่อ 2026-09-26
- หลัง refactor `memosprite` เป็นตัวเดียว เงื่อนไขกลายเป็น `ptr->memosprite` (มีอยู่ตั้งแต่ setup) → ตัวละครสาย memosprite ได้ CD +32 ตั้งแต่เข้าสนาม · เปลี่ยนเป็นเช็ค `isExisted()` ทุกต้นเทิร์นใน `beforeTurnList` และถอนเมื่อ memosprite ออกจากสนาม
