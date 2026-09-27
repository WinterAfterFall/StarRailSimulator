# `src/Defination/Data/Relic/Sacerdos_Relived_Ordeal.h`

เซ็ตจริง: **Sacerdos Relived Ordeal** · `Relic.Name` = `"Sacerdos_Relived_Ordeal"`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | บวก `speedPercent` ถาวร | `Sacerdos_Relived_Ordeal.h:9` |
| 4-pc — ใช้ Skill/Ult บัฟเพื่อนเป้าเดี่ยว → เป้าได้ CD +18% (ซ้อน 2, นาน 2 เทิร์น) | `Buff_List` กรองผู้กระทำ = ผู้สวม, `TraceType::Single`, และเป็น Skill หรือ Ult · ลงที่ทุกคนใน `buffTargetList` ด้วย `buffStackSingle` | `:12-19` |
| — หมดอายุ | ท้ายเทิร์นของ ally ทุกตัว เช็ค `isBuffEnd` บนตัวนั้น → `buffResetStack` ถอนทั้งกอง | `:21-27` |
| ชื่อบัฟผูกเจ้าของ | `ptr->getName() + " Sacerdos"` กันบัฟของสองคนชนกัน | `:6` |

## รากฐาน: `Buff_List` — trigger จาก action ประเภทบัฟ

`Buff_List.push_back(TriggerByAllyBuffAction_Func(...))` รับ `shared_ptr<AllyBuffAction>&` ไม่ใช่ `AllyAttackAction` → เป็นคู่ขนานของ `When_attack_List` สำหรับฝั่งบัฟ · เงื่อนไขของเซ็ตนี้คือ **บัฟเป้าหมายเดี่ยว** จึงเช็ค `act->traceType == TraceType::Single` (`:13`) ประกอบกับผู้กระทำเป็นเจ้าของ relic

## รากฐาน: ชื่อบัฟที่ผูกกับเจ้าของ

```cpp
string Sacerdos = ptr->getName() + " Sacerdos";
```
`Buff_check` / `Buff_countdown` เป็น map เดียวทั้งเกม (ดู `../Character/Harmony/Tingyun.md`) แต่ relic ใส่ได้หลายคน → ต้องเอาชื่อเจ้าของมา prefix ไม่งั้นบัฟของสองคนจะทับกัน · สร้างครั้งเดียวตอน setup แล้ว capture เข้าไปทุก lambda

## รากฐาน: `buffStackSingle` + `buffResetStack`

- `buffStackSingle(เป้า, {stat}, เพิ่ม, cap, ชื่อ, เทิร์น)` — engine นับ stack และ clamp ที่ cap ให้เอง ไม่ต้องนับเอง
- `buffResetStack(เป้า, {stat}, ชื่อ)` — ถอน **ทั้งกอง** ในครั้งเดียวตอนหมดอายุ โดยที่ผู้เรียกไม่ต้องรู้ว่ามีกี่ stack
- คู่นี้เป็นทางที่สะอาดกว่าการนับ stack เองแบบ `Grand_Duke.h`

## จุดที่ควรรู้

- **บัฟลงที่เป้าหมายของ action ไม่ใช่เจ้าของ relic** — `for (auto each : act->buffTargetList)` (`:15`) · relic ของคนหนึ่งจึงไปเพิ่ม CD ให้อีกคน
- `After_turn_List` ใช้ `dynamic_cast<AllyUnit*>(turn->charptr)` (`:22`) เป็นรูปเก่า ที่อื่นในโปรเจกต์ขยับไปใช้ helper แล้ว (`canCastToEnemy` ฝั่งศัตรู) — ฝั่ง ally ยังไม่มี helper คู่กัน

## แก้เมื่อ 2026-09-25
- ลบ guard `turn->num != ptr->currentCharNum` ใน `After_turn_List` · `currentCharNum` คือเป้าบัฟที่เลือกอยู่ ไม่ใช่ผู้ถือบัฟ → ถ้าบัฟลงคนอื่น (memosprite / เปลี่ยนเป้า) stack CD จะไม่ถูกถอน · ตอนนี้ `isBuffEnd(tempstats, ...)` ตัดสินเองว่าเป็นเทิร์นของผู้ถือบัฟหรือไม่

## แก้เมื่อ 2026-09-26
- เดิมนับทุก buff action เป้าเดี่ยว · kit ระบุ "When using Skill or Ultimate" → เพิ่มเงื่อนไข `act->isSameAction(AType::SKILL) || act->isSameAction(AType::Ult)`
