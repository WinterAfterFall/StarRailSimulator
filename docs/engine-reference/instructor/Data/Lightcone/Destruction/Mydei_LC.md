# `src/Defination/Data/Lightcone/Destruction/Mydei_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Mydei_LC"` · base stats `SetAllyBaseStats(1376, 476, 397)`

**signature ของ Mydei** (ดู `../../Character/Destruction/Mydei.md`) · base HP สูงสุดในโฟลเดอร์

| ท่อน | โค้ด |
|---|---|
| HP% `15 + 3S` · Incoming Healing `15 + 5S` (`HEALING_IN`) | `Reset_List` |
| Skill/Ult → จ่าย HP `5.5 + 0.5S`% Max HP ทุกครั้ง + DMG `25 + 5S` (อีกก้อนถ้า HP ที่จ่ายจริง > 500) | `BeforeAttackAction_List` |
| ถอนทั้งหมด | `AfterAttackActionList` → คูณด้วย `buffNote["Mydei_LC_Mark"]` |

## รากฐาน: นับจำนวนก้อนบัฟไว้ใน `buffNote` เพื่อถอนทีเดียว

```cpp
Before:  hpBefore = ptr->currentHP;
         DecreaseHP(ptr, ptr, 0, (5.5+0.5S), 0);           // จ่ายทุกครั้ง เหลือต่ำสุด 1
         buffNote["Mydei_LC_Mark"]++;  buffSingle(ptr, {{DMG, +(25+5S)}});
         if (hpBefore - ptr->currentHP > 500) {            // HP ที่จ่ายจริง
             buffNote[...]++;  buffSingle(ptr, {{DMG, +(25+5S)}});
         }
After:   buffSingle(ptr, {{DMG, -(25+5S) * buffNote["Mydei_LC_Mark"]}});  buffNote[...] = 0;
```
บัฟถูกลงได้ 1 หรือ 2 ก้อนต่อ action → จดจำนวนไว้แล้วถอนครั้งเดียวด้วยการคูณ · **สะอาดกว่าการเรียก `buffSingle` ติดลบหลายรอบ**

## ประวัติแก้ (2026-09-26)

- เดิมเพิ่ม `HEALING_OUT` → kit เป็น Incoming Healing จึงเปลี่ยนเป็น `HEALING_IN`
- เดิมหัก HP เฉพาะตอนผ่านเงื่อนไข และเทียบ `currentHP >= 50000/(5.5+0.5S)` → ตอนนี้หักทุกครั้ง แล้วเทียบ HP ที่หักไปจริง (`DecreaseCurrentHP` กันไม่ให้ต่ำกว่า 1 จึงวัดจากส่วนต่าง)
