# `src/Defination/Data/Relic/Scholar.h`

เซ็ตจริง: **Scholar Lost in Erudition** · `Relic.name` = `"Scholar"`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — CR +8% | บวก CR ถาวร | `Scholar.h:7` |
| 4-pc — Skill และ Ult DMG +20% | บวก DMG ที่จำกัด `AType::ULT` และ `AType::SKILL` ถาวร | `:8-9` |
| 4-pc — หลังกด Ult, Skill ครั้งถัดไป DMG +25% | `whenUseUltList` (เฉพาะผู้สวม) จอง flag แล้วบวก 25 | `:12-18` |
| — ถอนหลังใช้ Skill ครั้งนั้น | `afterAttackActionList` เจอ Skill ของผู้สวม → ล้าง flag ลบ 25 (หลังดาเมจคำนวณแล้ว) | `:20-27` |

## รากฐาน: บัฟ "ครั้งเดียวแล้วหมด" ที่ไม่ผูกกับเทิร์น

บัฟที่หมดอายุเมื่อ **ใช้ท่าที่กำหนด** ไม่ใช่เมื่อครบจำนวนเทิร์น ใช้คู่ helper นี้แทน `isBuffEnd`:

```cpp
// ลง: จองสิทธิ์ + บวกค่า
if (isHaveToAddBuff(ptr,"Scholar_buff")) ptr->statsType[Stats::DMG][AType::SKILL] += 25;

// ถอน: เจอ action ที่ตรงเงื่อนไข -> เคลียร์ flag + ลบค่า
if (act->isSameAction(ptr,AType::SKILL)) {
    if (ptr->getBuffCheck("Scholar_buff")) {
        ptr->buffCheck["Scholar_buff"] = 0;
        ptr->statsType[Stats::DMG][AType::SKILL] -= 25;
    }
}
```

`isHaveToAddBuff(ptr, ชื่อ)` ทำ 2 อย่างในครั้งเดียว: เช็คว่ายังไม่มีบัฟนี้ และจองไว้เลยถ้ายังไม่มี → **กันการบวกซ้ำเมื่อกดอัลติสองครั้งก่อนใช้ Skill** ซึ่งเป็นบั๊กแบบเดียวกับ `atkPercent` ที่รั่วใน `../Character/Abundance/Gallagher.md`

การถอนอยู่ที่ `afterAttackActionList` (หลัง action จบ) ไม่ใช่ `whenAttackList` เพื่อให้ดาเมจของ Skill ครั้งนั้นได้รับบัฟไปแล้วก่อนถูกถอน

## จุดที่ควรรู้

- `statsType[Stats::DMG][AType::SKILL]` ถูกแตะจาก 2 ที่ (`resetList` +20 และบัฟอัลติ +25) — ค่าที่เห็นตอนรันจึงเป็นผลรวม ไม่ใช่ค่าจากที่เดียว
