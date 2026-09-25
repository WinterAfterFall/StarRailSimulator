# `src/Defination/Data/Relic/Sacerdos_Relived_Ordeal.h`

เซ็ตจริง: **Sacerdos Relived Ordeal** · `Relic.Name` = `"Sacerdos_Relived_Ordeal"`

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | `Reset_List` → `Atv_stats->speedPercent += 6` | 9 |
| 4-pc — บัฟเป้าหมายเดี่ยว → เป้าได้ CD +18% (ซ้อน 2 ชั้น, 2 เทิร์น) | `Buff_List` → `buffStackSingle(each, {{CD, 18}}, 1, 2, Sacerdos, 2)` | 12-18 |
| — หมดอายุ | `After_turn_List` + `isBuffEnd` → `buffResetStack` | 20-27 |

## รากฐาน: `Buff_List` — trigger จาก action ประเภทบัฟ

`Buff_List.push_back(TriggerByAllyBuffAction_Func(...))` รับ `shared_ptr<AllyBuffAction>&` ไม่ใช่ `AllyAttackAction` → เป็นคู่ขนานของ `When_attack_List` สำหรับฝั่งบัฟ · เงื่อนไขของเซ็ตนี้คือ **บัฟเป้าหมายเดี่ยว** จึงเช็ค `act->traceType == TraceType::Single` (13) ประกอบกับผู้กระทำเป็นเจ้าของ relic

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

- **บัฟลงที่เป้าหมายของ action ไม่ใช่เจ้าของ relic** — `for (auto each : act->buffTargetList)` (14) · relic ของคนหนึ่งจึงไปเพิ่ม CD ให้อีกคน
- `After_turn_List` ใช้ `dynamic_cast<AllyUnit*>(turn->charptr)` (22) เป็นรูปเก่า ที่อื่นในโปรเจกต์ขยับไปใช้ helper แล้ว (`canCastToEnemy` ฝั่งศัตรู) — ฝั่ง ally ยังไม่มี helper คู่กัน
- guard `turn->num != ptr->currentCharNum` (21) ผูกกับ `currentCharNum` ซึ่งเปลี่ยนได้ระหว่างเกม (memosprite) ต่างจากการเทียบชื่อตรง ๆ

## แก้เมื่อ 2026-09-25
- ลบ guard `turn->num != ptr->currentCharNum` ใน `After_turn_List` · `currentCharNum` คือเป้าบัฟที่เลือกอยู่ ไม่ใช่ผู้ถือบัฟ → ถ้าบัฟลงคนอื่น (memosprite / เปลี่ยนเป้า) stack CD จะไม่ถูกถอน · ตอนนี้ `isBuffEnd(tempstats, ...)` ตัดสินเองว่าเป็นเทิร์นของผู้ถือบัฟหรือไม่
