# `src/Defination/Data/Lightcone/Destruction/Mydei_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Mydei_LC"` · base stats `setAllyBaseStats(1376, 476, 397)`

**signature ของ Mydei** (ดู `../../Character/Destruction/Mydei.md`) · base HP สูงสุดในโฟลเดอร์

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1376, 476, 397)` | `Mydei_LC.h:5` |
| HP% `15 + 3S` และ Incoming Healing `15 + 5S` | บวกถาวร (`HEALING_IN`) | `:8-9` |
| ใช้ Skill/Ult → จ่าย HP `5.5 + 0.5S`% Max HP แล้ว DMG `25 + 5S`% สำหรับ action นั้น · ถ้า HP ที่จ่ายจริง > 500 ได้อีกก้อน | `beforeAttackActionList` เฉพาะผู้สวม · `decreaseHP` แล้ววัดส่วนต่าง HP · นับจำนวนก้อนใน `buffNote["Mydei_LC_Mark"]` | `:12-24` (จ่าย HP `:16` · ก้อนที่ 2 `:19-22`) |
| หลัง action → ถอนทุกก้อน | `afterAttackActionList` ถอน `(25 + 5S) × buffNote` แล้วตั้ง 0 | `:26-30` |

## รากฐาน: นับจำนวนก้อนบัฟไว้ใน `buffNote` เพื่อถอนทีเดียว

```cpp
Before:  hpBefore = ptr->currentHP;
         decreaseHP(ptr, ptr, 0, (5.5+0.5S), 0);           // จ่ายทุกครั้ง เหลือต่ำสุด 1
         buffNote["Mydei_LC_Mark"]++;  buffSingle(ptr, {{DMG, +(25+5S)}});
         if (hpBefore - ptr->currentHP > 500) {            // HP ที่จ่ายจริง
             buffNote[...]++;  buffSingle(ptr, {{DMG, +(25+5S)}});
         }
After:   buffSingle(ptr, {{DMG, -(25+5S) * buffNote["Mydei_LC_Mark"]}});  buffNote[...] = 0;
```
บัฟถูกลงได้ 1 หรือ 2 ก้อนต่อ action → จดจำนวนไว้แล้วถอนครั้งเดียวด้วยการคูณ · **สะอาดกว่าการเรียก `buffSingle` ติดลบหลายรอบ**

## ประวัติแก้ (2026-09-26)

- เดิมเพิ่ม `HEALING_OUT` → kit เป็น Incoming Healing จึงเปลี่ยนเป็น `HEALING_IN`
- เดิมหัก HP เฉพาะตอนผ่านเงื่อนไข และเทียบ `currentHP >= 50000/(5.5+0.5S)` → ตอนนี้หักทุกครั้ง แล้วเทียบ HP ที่หักไปจริง (`decreaseCurrentHP` กันไม่ให้ต่ำกว่า 1 จึงวัดจากส่วนต่าง)
