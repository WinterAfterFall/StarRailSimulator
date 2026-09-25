# `src/Defination/Data/Lightcone/Destruction/Mydei_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Mydei_LC"` · base stats `SetAllyBaseStats(1376, 476, 397)`

**signature ของ Mydei** (ดู `../../Character/Destruction/Mydei.md`) · base HP สูงสุดในโฟลเดอร์

| ท่อน | โค้ด |
|---|---|
| HP% `15 + 3S` · Healing Out `15 + 5S` | `Reset_List` |
| Skill/Ult → DMG `25 + 5S` (จ่าย HP เพื่อได้อีกก้อน) | `BeforeAttackAction_List` |
| ถอนทั้งหมด | `AfterAttackActionList` → คูณด้วย `buffNote["Mydei_LC_Mark"]` |

## รากฐาน: นับจำนวนก้อนบัฟไว้ใน `buffNote` เพื่อถอนทีเดียว

```cpp
Before:  buffNote["Mydei_LC_Mark"]++;  buffSingle(ptr, {{DMG, +(25+5S)}});
         if (ptr->currentHP >= 50000.0/(5.5+0.5S)) {
             buffSingle(ptr, {{DMG, +(25+5S)}});  buffNote[...]++;
             DecreaseHP(ptr, ptr, 0, (5.5+0.5S), 0);      // จ่าย HP เป็นต้นทุน
         }
After:   buffSingle(ptr, {{DMG, -(25+5S) * buffNote["Mydei_LC_Mark"]}});  buffNote[...] = 0;
```
บัฟถูกลงได้ 1 หรือ 2 ก้อนต่อ action → จดจำนวนไว้แล้วถอนครั้งเดียวด้วยการคูณ · **สะอาดกว่าการเรียก `buffSingle` ติดลบหลายรอบ**

## จุดที่ควรระวัง

**เงื่อนไข `ptr->currentHP >= 50000.0 / (5.5 + 0.5 * superimpose)`** — เป็นการเทียบ HP ปัจจุบันกับค่าคงที่ที่ไม่ได้อิง Max HP ของตัวละคร · ถ้า kit ระบุเป็นเปอร์เซ็นต์ของ Max HP ควรเขียนเป็น `ptr->currentHP >= ptr->totalHP * x` แทน · ตัวเลข 50000 ไม่มีคอมเมนต์อธิบายที่มา
