# `src/Defination/Data/Relic/Scholar.h`

เซ็ตจริง: **Scholar Lost in Erudition** · `Relic.Name` = `"Scholar"`

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — CR +8% | `Reset_List` → `Stats_type[Stats::CR][AType::None] += 8` | 7 |
| 4-pc — Skill / Ult DMG +20% | `Stats_type[Stats::DMG][AType::Ult] += 20` และ `[AType::SKILL] += 20` | 8-9 |
| 4-pc — หลังใช้อัลติ Skill ครั้งถัดไป +25% | `WhenUseUlt_List` ลงบัฟ → `AfterAttackActionList` ถอนเมื่อ Skill ออกไปแล้ว | 12-27 |

## รากฐาน: บัฟ "ครั้งเดียวแล้วหมด" ที่ไม่ผูกกับเทิร์น

บัฟที่หมดอายุเมื่อ **ใช้ท่าที่กำหนด** ไม่ใช่เมื่อครบจำนวนเทิร์น ใช้คู่ helper นี้แทน `isBuffEnd`:

```cpp
// ลง: จองสิทธิ์ + บวกค่า
if (isHaveToAddBuff(ptr,"Scholar_buff")) ptr->Stats_type[Stats::DMG][AType::SKILL] += 25;

// ถอน: เจอ action ที่ตรงเงื่อนไข -> เคลียร์ flag + ลบค่า
if (act->isSameAction(ptr,AType::SKILL)) {
    if (ptr->getBuffCheck("Scholar_buff")) {
        ptr->buffCheck["Scholar_buff"] = 0;
        ptr->Stats_type[Stats::DMG][AType::SKILL] -= 25;
    }
}
```

`isHaveToAddBuff(ptr, ชื่อ)` ทำ 2 อย่างในครั้งเดียว: เช็คว่ายังไม่มีบัฟนี้ และจองไว้เลยถ้ายังไม่มี → **กันการบวกซ้ำเมื่อกดอัลติสองครั้งก่อนใช้ Skill** ซึ่งเป็นบั๊กแบบเดียวกับ `atkPercent` ที่รั่วใน `../Character/Abundance/Gallagher.md`

การถอนอยู่ที่ `AfterAttackActionList` (หลัง action จบ) ไม่ใช่ `When_attack_List` เพื่อให้ดาเมจของ Skill ครั้งนั้นได้รับบัฟไปแล้วก่อนถูกถอน

## จุดที่ควรรู้

- `Stats_type[Stats::DMG][AType::SKILL]` ถูกแตะจาก 2 ที่ (`Reset_List` +20 และบัฟอัลติ +25) — ค่าที่เห็นตอนรันจึงเป็นผลรวม ไม่ใช่ค่าจากที่เดียว
