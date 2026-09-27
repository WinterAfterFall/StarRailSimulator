# `src/Defination/Data/Relic/Goddess of Sun and Thunder.h`

`Relic.name` = `"Goddess of Sun and Thunder"` · **เซ็ตสำหรับสายฮีล**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | บวก `speedPercent` ถาวร | `Goddess of Sun and Thunder.h:7` |
| 4-pc — เมื่อผู้สวม (หรือ memosprite ของเขา) ฮีล: ผู้สวม SPD +6% และทั้งทีม CD +15% นาน 2 เทิร์น | `healingList` เช็ค `healer->owner` เป็นผู้สวม · `isHaveToAddBuff(…, 2)` กันลงซ้ำเมื่อฮีลหลายครั้งและตั้งอายุ 2 เทิร์น | `:10-19` |
| — ถอนเมื่อครบเวลา | ท้ายเทิร์นผู้สวม `isBuffEnd` → ลบ SPD −6 และ CD −15 ทั้งทีม | `:21-28` |
| — ถอนเมื่อผู้สวมตาย | `allyDeathList` + `isBuffGoneByDeath` ลบค่าชุดเดียวกัน กันบัฟทีมค้าง | `:30-37` |

## รากฐาน: `healingList` — trigger จากการฮีล

```cpp
healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *healer, AllyUnit *target, double value){ ... }));
```
callback ได้ทั้ง **ผู้ฮีล เป้าหมาย และจำนวนที่ฮีล** · เป็น list เดียวที่ผูกกับระบบฮีลโดยตรง (ดูระบบฮีลเต็ม ๆ ที่ `../Character/Abundance/Luocha.md`)

**guard ใช้ `healer->owner->isSameName(ptr)`** (`:11`) ไม่ใช่ `healer->isSameName(ptr)` — เพราะผู้ฮีลอาจเป็น memosprite ของเจ้าของ relic ก็ได้ ต้องเทียบที่ `owner`

## รากฐาน: `isHaveToAddBuff(ptr, ชื่อ, เทิร์น)` แบบ 3 args

เวอร์ชันนี้ทำ 3 อย่างในครั้งเดียว: เช็คว่ายังไม่มีบัฟ → จองชื่อไว้ → **ตั้งอายุให้ด้วย** · ต่างจากแบบ 2 args ที่ `Scholar.h` ใช้กับบัฟที่หมดอายุด้วยเงื่อนไขอื่น (ไม่ใช่เทิร์น) · ที่นี่ฮีลเกิดได้หลายครั้งต่อเทิร์น ตัว guard นี้จึงกันการบวกซ้ำ

## จุดที่ควรระวัง

- **บัฟ CD ลงทั้งทีมด้วย `buffAllAlly` แบบไม่มีชื่อบัฟ** (`:14-16`, `:24-26`, `:33-35`) เป็นการบวก/ลบค่าดิบ ความถูกต้องขึ้นกับการจับคู่ครั้งลง/ครั้งถอนให้สมดุล ซึ่งที่นี่พึ่ง `isHaveToAddBuff` กับ `isBuffEnd` อย่างละครั้ง · อาการเดียวกับ E1 ของ `../Character/Abundance/Luocha.md`

## แก้เมื่อ 2026-09-25
- เพิ่ม `allyDeathList`: เมื่อเจ้าของตาย (`isBuffGoneByDeath`) ถอน SPD +6% ของเจ้าของ และ CD +15% ของทั้งทีม · เดิมบัฟทีมค้างเพราะการถอนผูกกับเทิร์นเจ้าของ
