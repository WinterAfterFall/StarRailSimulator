# `src/Defination/Data/Lightcone/Nihility/Kafka_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Kafka_LC"` · base stats `SetAllyBaseStats(1058, 582, 463)`

**signature ของ Kafka** (ดู `../../Character/Nihility/Kafka.md`) · **LC ใบเดียวในโปรเจกต์ที่มี `Dot_List` ของตัวเอง**

| ท่อน | โค้ด |
|---|---|
| DMG `20 + 4S` | `Reset_List` |
| โจมตี → SPD stack `4 + 0.8S` (cap 3) | `AfterAttackActionList` → `buffStackSingle(..., 1, 3, "Kafka LC")` |
| โจมตี → เป้าติด Shock ชื่อ `Erode` 1 เทิร์น | `dotSingleApply(ptr, each, {DotType::Shock}, Erode, 1)` |
| Erode DoT `50 + 10S` | **`Dot_List` ของตัว LC เอง** |
| ถอน | `After_turn_List` → `isDebuffEnd(enemy, Erode)` → `dotRemove(enemy, {DotType::Shock})` |

## รากฐาน: LC ที่ลงทะเบียน `Dot_List`

```cpp
Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Erode](Enemy* target, double Dot_ratio, DotType Dot_type) {
    if (Dot_type != DotType::General && Dot_type != DotType::Shock) return;
    if (target->getDebuff(Erode)) { ... Attack(act); }
}));
```
guard 2 ชั้นเหมือน handler ของตัวละคร (ดู `../../Character/Nihility/Kafka.md` รากฐานข้อ 3) — **แปลว่า `Dot_trigger` ของ Kafka จะจุดระเบิด DoT ของ LC ใบนี้ด้วย** ซึ่งเป็นเจตนาของ kit

## ข้อควรรู้

- **SPD stack ไม่มี duration โดยตั้งใจ** — kit: "their SPD increases by ... stacking up to 3 times" ไม่มีระยะเวลา จึงค้างตลอดการต่อสู้ถูกต้อง
- **แก้ 2026-09-26**: เดิมถอน Shock ด้วย `changeShock(-1)` (ผลเท่ากัน) → เปลี่ยนเป็น `dotRemove(enemy, {DotType::Shock})` คู่กับ `dotSingleApply` ตามแบบแผน (ดู `../../Character/Nihility/Guinaifen.md`)
