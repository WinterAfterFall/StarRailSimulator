# `src/Defination/Data/Lightcone/Harmony/Robin_LC.h`

`namespace Harmony_Lightcone` · `lightCone.name` = `"Robin_LC"` · base stats `setAllyBaseStats(953, 635, 463)`

**signature ของ Robin** (ดู `../../Character/Harmony/Robin.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 635, 463)` | `Robin_LC.h:5` |
| ใครก็ตามในทีมโจมตี → ผู้สวมได้ "Cantillation" ER `2.5 + 0.5S` ต่อชั้น (สูงสุด 5) | `whenAttackList` นับ `stack["Cantillation"]` แล้วบวก `energyRecharge` | `:8-13` |
| ผู้สวมกด Ult → ล้าง Cantillation และเปิด "Cadenza": ทั้งทีม DMG `20 + 4S` · ผู้สวม ATK `36 + 12S` นาน 1 เทิร์น | `whenUseUltList` + `isSameOwner` · คืน ER ตาม stack · `isHaveToAddBuff(ptr, "Cadenza", 1)` | `:15-24` |
| ถอน Cadenza เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:26-31` |

## รากฐาน: ER เป็นทรัพยากรที่สะสมแล้วคืน

```cpp
When_attack: if (stack < 5) { stack++; ptr->energyRecharge += 2.5 + 0.5*S; }
WhenUseUlt:  ptr->energyRecharge -= stack * (2.5 + 0.5*S);  stack = 0;
```
**เขียน `energyRecharge` ตรง ๆ ไม่ผ่าน `buffSingle`** — เป็นฟิลด์แยกจาก `statsType[Stats::ER]` (ดู `../../Planar/Lushaka.md`) · การถอนคำนวณจาก stack ที่เหลือ ซึ่งถูกต้องตราบใดที่ค่าต่อ stack ไม่เปลี่ยน

## จุดที่ควรระวัง

- **`whenAttackList` ไม่ guard ผู้โจมตีโดยตั้งใจ** — kit: "Every time **any ally** attacks, the wearer gains 1 stack of Cantillation" จึงถูกต้อง
- **บัฟทีมใช้ `buffAllAlly` แบบไม่มีชื่อ** แล้วคุมอายุด้วยบัฟ `"Cadenza"` บนตัวผู้สวม → ไม่มี `allyDeathList` รองรับ
