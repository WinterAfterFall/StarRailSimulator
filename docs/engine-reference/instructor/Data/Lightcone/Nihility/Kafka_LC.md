# `src/Defination/Data/Lightcone/Nihility/Kafka_LC.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"Kafka_LC"` · base stats `setAllyBaseStats(1058, 582, 463)`

**signature ของ Kafka** (ดู `../../Character/Nihility/Kafka.md`) · **LC ใบเดียวในโปรเจกต์ที่มี `dotList` ของตัวเอง**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 582, 463)` | `Kafka_LC.h:5` |
| DMG `20 + 4S` | บวกถาวร | `:9` |
| ผู้สวมโจมตี → SPD `4 + 0.8S`% ต่อชั้น (สูงสุด 3) | `afterAttackActionList` → `buffStackSingle(…, 1, 3, "Kafka LC")` · ไม่มีอายุ | `:12-14` |
| ผู้สวมโจมตี → เป้าที่ยังไม่มี "Erode" ติด Shock พิเศษ 1 เทิร์น | `dotSingleApply(…, SHOCK, erode, 1)` ชื่อผูกเจ้าของ (`:7`) | `:15-17` |
| Shock/DoT ยิงบนเป้าที่ติด Erode → ดาเมจเพิ่ม `50 + 10S`% ATK × ตัวคูณ DoT | `dotList` สร้าง action `AType::SHOCK` แล้ว `multiplyDmg(dotRatio)` | `:31-40` |
| ถอน Erode | ท้ายเทิร์นศัตรู `isDebuffEnd` → `dotRemove` | `:22-29` |

## รากฐาน: LC ที่ลงทะเบียน `dotList`

```cpp
dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,erode](Enemy* target, double dotRatio, DotType dotType) {
    if (dotType != DotType::GENERAL && dotType != DotType::SHOCK) return;
    if (target->getDebuff(erode)) { ... attack(act); }
}));
```
guard 2 ชั้นเหมือน handler ของตัวละคร (ดู `../../Character/Nihility/Kafka.md` รากฐานข้อ 3) — **แปลว่า `dotTrigger` ของ Kafka จะจุดระเบิด DoT ของ LC ใบนี้ด้วย** ซึ่งเป็นเจตนาของ kit

## ข้อควรรู้

- **SPD stack ไม่มี duration โดยตั้งใจ** — kit: "their SPD increases by ... stacking up to 3 times" ไม่มีระยะเวลา จึงค้างตลอดการต่อสู้ถูกต้อง
- **แก้ 2026-09-26**: เดิมถอน Shock ด้วย `changeShock(-1)` (ผลเท่ากัน) → เปลี่ยนเป็น `dotRemove(enemy, {DotType::SHOCK})` คู่กับ `dotSingleApply` ตามแบบแผน (ดู `../../Character/Nihility/Guinaifen.md`)
