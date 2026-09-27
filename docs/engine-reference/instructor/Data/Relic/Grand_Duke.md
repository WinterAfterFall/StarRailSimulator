# `src/Defination/Data/Relic/Grand_Duke.h`

เซ็ตจริง: **The Ashblazing Grand Duke** · `Relic.name` = `"Grand_Duke"`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — Follow-up DMG +20% | บวก DMG ที่จำกัดเฉพาะ `AType::FUA` | `Grand_Duke.h:7` |
| 4-pc — Follow-up แต่ละ hit ให้ ATK +6% (สูงสุด 8 ชั้น) นาน 3 เทิร์น | `beforeAttackPerHitList` ยิงทุก hit · ถ้า action มี `FUA` ถอน ATK ชั้นเดิมทั้งหมด ตั้ง stack = `hitCount` (clamp 8) แล้วลงใหม่ · ต่ออายุ 3 เทิร์นทุก hit | `:10-31` |
| — หมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` → ถอน ATK ทั้งกอง stack กลับ 0 | `:33-40` |

## รากฐาน: `beforeAttackPerHitList` — trigger ราย hit ไม่ใช่ราย action

list นี้ยิง **ทุก hit** ของ action หนึ่ง ต่างจาก `beforeAttackList` / `whenAttackList` ที่ยิงครั้งเดียวต่อ action · จำเป็นสำหรับเซ็ตนี้เพราะ stack นับตามจำนวน hit ที่ follow-up ปล่อยไปแล้ว ซึ่งอ่านจาก `act->attacker->hitCount`

การเช็คว่าเป็น follow-up ทำโดยวน `act->actionTypeList` หา `AType::FUA` (`:14-19`) ไม่ใช่เทียบ `AType` ตัวเดียว เพราะ action หนึ่งมีได้หลายประเภทพร้อมกัน

## รากฐาน: สำนวน "ถอนของเก่า-ตั้งค่าใหม่-ใส่ของใหม่"

```cpp
act->attacker->statsType[Stats::ATK_P][AType::NONE] -= act->attacker->stack["Grand_Duke"] * 6;
act->attacker->stack["Grand_Duke"] = hitCnt;
act->attacker->statsType[Stats::ATK_P][AType::NONE] += act->attacker->stack["Grand_Duke"] * 6;
```

`statsType` บวก/ลบค่าดิบเท่านั้น ไม่มี "ตั้งค่าเป็น" → เมื่อจำนวน stack **เปลี่ยนเป็นค่าใหม่ทั้งก้อน** (ไม่ใช่เพิ่มทีละ 1) ต้องถอนของเดิมออกทั้งหมดก่อนแล้วค่อยใส่ค่าใหม่ · เป็นอีกรูปหนึ่งของสำนวน delta ที่ `../Character/Abundance/Gallagher.md` ใช้กับ `buffNote`

## จุดที่ควรรู้

- **`hitCnt` ไม่ได้บวกสะสม** — `hitCnt = act->attacker->hitCount` (`:22`) คือค่าจาก unit ไม่ใช่การนับเพิ่มเอง แล้ว clamp ที่ 8 · ตัวแปรถูกประกาศ `int hitCnt = 0;` ไว้นอก `if` (`:20`) ทั้งที่ใช้ข้างในอย่างเดียว
- **อายุบัฟต่ออายุใหม่ทุก hit** (`extendBuffTime(..., 3)` `:29`) ไม่ใช่ตั้งครั้งเดียวตอนเริ่มสะสม
- `afterTurnList` guard ด้วย `turn->name != ptr->atvStats->name` (`:34`) — ต่างจากที่อื่นในกลุ่ม relic ที่ปล่อยให้ `isBuffEnd` เช็คเจ้าของเทิร์นเอง ผลเหมือนกันแต่เป็นการเช็คซ้ำ
