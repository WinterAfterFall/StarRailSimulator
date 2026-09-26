# `src/Defination/Data/Relic/Goddess of Sun and Thunder.h`

`Relic.Name` = `"Goddess of Sun and Thunder"` · **เซ็ตสำหรับสายฮีล**

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | `Reset_List` → `Atv_stats->speedPercent += 6` | 7 |
| 4-pc — เมื่อเจ้าของฮีล: เจ้าของ SPD +6% และทั้งทีม CD +15% (2 เทิร์น) | `Healing_List` | 10-19 |
| — ถอนเมื่อหมดอายุ | `After_turn_List` + `isBuffEnd` | 21-28 |

## รากฐาน: `Healing_List` — trigger จากการฮีล

```cpp
Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *Healer, AllyUnit *target, double Value){ ... }));
```
callback ได้ทั้ง **ผู้ฮีล เป้าหมาย และจำนวนที่ฮีล** · เป็น list เดียวที่ผูกกับระบบฮีลโดยตรง (ดูระบบฮีลเต็ม ๆ ที่ `../Character/Abundance/Luocha.md`)

**guard ใช้ `Healer->owner->isSameName(ptr)`** (11) ไม่ใช่ `Healer->isSameName(ptr)` — เพราะผู้ฮีลอาจเป็น memosprite ของเจ้าของ relic ก็ได้ ต้องเทียบที่ `owner`

## รากฐาน: `isHaveToAddBuff(ptr, ชื่อ, เทิร์น)` แบบ 3 args

เวอร์ชันนี้ทำ 3 อย่างในครั้งเดียว: เช็คว่ายังไม่มีบัฟ → จองชื่อไว้ → **ตั้งอายุให้ด้วย** · ต่างจากแบบ 2 args ที่ `Scholar.h` ใช้กับบัฟที่หมดอายุด้วยเงื่อนไขอื่น (ไม่ใช่เทิร์น) · ที่นี่ฮีลเกิดได้หลายครั้งต่อเทิร์น ตัว guard นี้จึงกันการบวกซ้ำ

## จุดที่ควรระวัง

- **บัฟ CD ลงทั้งทีมด้วย `buffAllAlly` แบบไม่มีชื่อบัฟ** (14-16, 24-26) เป็นการบวก/ลบค่าดิบ ความถูกต้องขึ้นกับการจับคู่ครั้งลง/ครั้งถอนให้สมดุล ซึ่งที่นี่พึ่ง `isHaveToAddBuff` กับ `isBuffEnd` อย่างละครั้ง · อาการเดียวกับ E1 ของ `../Character/Abundance/Luocha.md`
- **ไม่มีการถอนเมื่อเพื่อนตาย** — ต่างจาก `Wavestrider Captain.h` ที่มี `AllyDeath_List` คู่กับ `After_turn_List` · บัฟ CD ที่ค้างบนคนที่ตายจะไม่ถูกถอน
- `isBuffEnd(ptr, ...)` เช็คบนตัวเจ้าของ relic แต่บัฟ CD อยู่กับทุกคน → ถ้าเจ้าของตายก่อนบัฟหมดอายุ ทั้งทีมจะค้าง CD +15% ต่อไป

## แก้เมื่อ 2026-09-25
- เพิ่ม `AllyDeath_List`: เมื่อเจ้าของตาย (`isBuffGoneByDeath`) ถอน SPD +6% ของเจ้าของ และ CD +15% ของทั้งทีม · เดิมบัฟทีมค้างเพราะการถอนผูกกับเทิร์นเจ้าของ
