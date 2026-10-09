# `src/Defination/Data/Relic/Goddess of Sun and Thunder.h`

`Relic.name` = `"Goddess of Sun and Thunder"` · **เซ็ตสำหรับสายฮีล** · kit: Warrior Goddess of Sun and Thunder ใน [`docs/kit-reference/Relic.md`](../../../../kit-reference/Relic.md)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | บวก `speedPercent` ถาวร | `Goddess of Sun and Thunder.h:22` |
| 4-pc — ผู้สวม (หรือ memosprite ของเขา) ฮีล**เพื่อนที่ไม่ใช่ตัวผู้ฮีลเอง** → ได้ "Gentle Rain" 2 เทิร์น (ติดได้ครั้งเดียวต่อเทิร์น) | `healingList` เช็ค `healer->owner` เป็นผู้สวม · **ข้ามถ้า `target == healer`** (ฮีลตัวเองไม่นับ) · `isHaveToAddBuff(…, 2)` ใส่ค่าครั้งเดียวแล้วต่ออายุทุกครั้งที่ฮีล | `:26-30` |
| — ขณะมี Gentle Rain: ผู้สวม SPD +6% · ทุกคน CRIT DMG +15% · **ซ้อนไม่ได้** | `gentleRain(+1 / −1)`: SPD ใส่/ถอนรายผู้สวม · CD ทั้งทีมผ่านตัวนับกลาง `sunThunderHolders` — ใส่ +15 ตอนนับจาก 0 → 1 และถอนตอน 1 → 0 เท่านั้น | `:7`, `:13-19` |
| — ถอนเมื่อครบเวลา | ท้ายเทิร์นผู้สวม `isBuffEnd` → `gentleRain(-1)` | `:32-34` |
| — ถอนเมื่อผู้สวมตาย | `allyDeathList` + `isBuffGoneByDeath` → `gentleRain(-1)` | `:36-38` |

## รากฐาน: `healingList` — trigger จากการฮีล

```cpp
healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *healer, AllyUnit *target, double value){ ... }));
```
callback ได้ทั้ง **ผู้ฮีล เป้าหมาย และจำนวนที่ฮีล** และถูกเรียก**ทีละเป้า** (`increaseHP` ใน `ChangeHP.h` ยิง `allEventHeal` ต่อเป้าหนึ่งคน) · ฮีลทั้งทีมจึงยิงหลายครั้ง ครั้งที่เป้าเป็นคนอื่นก็พอให้ติด

**guard ใช้ `healer->owner->isSameName(ptr)`** (`:27`) ไม่ใช่ `healer->isSameName(ptr)` — เพราะผู้ฮีลอาจเป็น memosprite ของเจ้าของ relic ก็ได้ ต้องเทียบที่ `owner` · ส่วน "ไม่ใช่ตัวเอง" เทียบกับ `healer` (`:28`) → memosprite ฮีลเจ้าของก็นับ

## รากฐาน: `isHaveToAddBuff(ptr, ชื่อ, เทิร์น)` แบบ 3 args

เวอร์ชันนี้ทำ 3 อย่างในครั้งเดียว: ต่ออายุ → เช็คว่ายังไม่มีบัฟ → จองชื่อไว้ · ฮีลซ้ำในเทิร์นเดียวกันได้วันหมดอายุเดิม จึงเท่ากับ "ติดได้ครั้งเดียวต่อเทิร์น" · ต่างจากแบบ 2 args ที่ `Scholar.h` ใช้กับบัฟที่หมดอายุด้วยเงื่อนไขอื่น

## ซ้อนไม่ได้ — ตัวนับ `sunThunderHolders`

kit เขียนว่า *"This effect cannot be stacked"* → ใส่เซ็ตนี้ 2 คนและมี Gentle Rain พร้อมกัน ทีมยังได้ CD +15% ก้อนเดียว (กฎ prefix: ข้ามการแยกชื่อตามเจ้าของเมื่อ kit บอกว่าซ้อนไม่ได้)

- `sunThunderHolders` (`:7`) เป็น `inline int` ระดับ namespace = จำนวนผู้สวมที่ถือ Gentle Rain อยู่ · รีเซ็ตเป็น 0 ใน `resetList` ทุกรอบรัน (`:23`)
- SPD +6% ยังเป็นของผู้สวมแต่ละคน
- ถ้าผู้สวมคนแรกหมด Gentle Rain แต่อีกคนยังถืออยู่ ตัวนับเป็น 2 → 1 จึงไม่ถอน CD

## จุดที่ควรระวัง

- **บัฟ CD ลงทั้งทีมด้วย `buffAllAlly` แบบไม่มีชื่อบัฟ** เป็นการบวก/ลบค่าดิบ ความถูกต้องขึ้นกับตัวนับให้สมดุล (+1 ตอนได้ / −1 ตอนหมดหรือตาย) · เพื่อนที่เข้ามาใหม่ระหว่างที่บัฟติดอยู่จะไม่ได้ CD (เหมือน E1 ของ `../Character/Abundance/Luocha.md`)

## แก้เมื่อ 2026-09-25
- เพิ่ม `allyDeathList`: เมื่อเจ้าของตาย (`isBuffGoneByDeath`) ถอน SPD +6% ของเจ้าของ และ CD +15% ของทั้งทีม · เดิมบัฟทีมค้างเพราะการถอนผูกกับเทิร์นเจ้าของ

## แก้เมื่อ 2026-10-09 (user สั่ง หลังเทียบ kit)
- ฮีลตัวเองไม่ทำให้ติด (`target == healer` → ข้าม) ตาม kit *"to ally targets other than themselves"*
- CD +15% ทั้งทีมซ้อนไม่ได้ระหว่างผู้สวมหลายคน → ตัวนับ `sunThunderHolders`
- รันเทียบเคสผู้สวมคนเดียว (Pearl ในทีม SW999 / Hibana / Yao Guang) ได้ดาเมจเท่าเดิมทุกหลัก · เคสผู้สวม 2 คน (Pearl + Hyacine) ตัวนับขึ้นถึง 2 และ CD ใส่ครั้งเดียว
