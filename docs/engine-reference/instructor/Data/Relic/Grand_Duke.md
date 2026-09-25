# `src/Defination/Data/Relic/Grand_Duke.h`

เซ็ตจริง: **The Ashblazing Grand Duke** · `Relic.Name` = `"Grand_Duke"`

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — Follow-up ATK DMG +20% | `Reset_List` → `Stats_type[Stats::DMG][AType::Fua] += 20` | 7 |
| 4-pc — ATK +6% ต่อ hit ของ follow-up (สูงสุด 8 ชั้น) | `BeforeAttackPerHit_List` | 10-31 |
| — หมดอายุ 3 เทิร์น | `After_turn_List` + `isBuffEnd` | 33-40 |

## รากฐาน: `BeforeAttackPerHit_List` — trigger ราย hit ไม่ใช่ราย action

list นี้ยิง **ทุก hit** ของ action หนึ่ง ต่างจาก `BeforeAttack_List` / `When_attack_List` ที่ยิงครั้งเดียวต่อ action · จำเป็นสำหรับเซ็ตนี้เพราะ stack นับตามจำนวน hit ที่ follow-up ปล่อยไปแล้ว ซึ่งอ่านจาก `act->Attacker->hitCount`

การเช็คว่าเป็น follow-up ทำโดยวน `act->actionTypeList` หา `AType::Fua` (14-19) ไม่ใช่เทียบ `AType` ตัวเดียว เพราะ action หนึ่งมีได้หลายประเภทพร้อมกัน

## รากฐาน: สำนวน "ถอนของเก่า-ตั้งค่าใหม่-ใส่ของใหม่"

```cpp
act->Attacker->Stats_type[Stats::ATK_P][AType::None] -= act->Attacker->stack["Grand_Duke"] * 6;
act->Attacker->stack["Grand_Duke"] = hitCnt;
act->Attacker->Stats_type[Stats::ATK_P][AType::None] += act->Attacker->stack["Grand_Duke"] * 6;
```

`Stats_type` บวก/ลบค่าดิบเท่านั้น ไม่มี "ตั้งค่าเป็น" → เมื่อจำนวน stack **เปลี่ยนเป็นค่าใหม่ทั้งก้อน** (ไม่ใช่เพิ่มทีละ 1) ต้องถอนของเดิมออกทั้งหมดก่อนแล้วค่อยใส่ค่าใหม่ · เป็นอีกรูปหนึ่งของสำนวน delta ที่ `../Character/Abundance/Gallagher.md` ใช้กับ `buffNote`

## จุดที่ควรรู้

- **`hitCnt` ไม่ได้บวกสะสม** — `hitCnt = act->Attacker->hitCount` (22) คือค่าจาก unit ไม่ใช่การนับเพิ่มเอง แล้ว clamp ที่ 8 · ตัวแปรถูกประกาศ `int hitCnt = 0;` ไว้นอก `if` (20) ทั้งที่ใช้ข้างในอย่างเดียว
- **อายุบัฟต่ออายุใหม่ทุก hit** (`extendBuffTime(..., 3)` บรรทัด 29) ไม่ใช่ตั้งครั้งเดียวตอนเริ่มสะสม
- `After_turn_List` guard ด้วย `turn->Name != ptr->Atv_stats->Name` (34) — ต่างจากที่อื่นในกลุ่ม relic ที่ปล่อยให้ `isBuffEnd` เช็คเจ้าของเทิร์นเอง ผลเหมือนกันแต่เป็นการเช็คซ้ำ
