# `src/Defination/Data/Relic/PairSet.h`

**ไม่ใช่เซ็ตจริงในเกม** แต่เป็นทางลัดสำหรับใส่ relic แบบ **2 ชิ้น + 2 ชิ้น** (ไม่เล่นเซ็ต 4 ชิ้น) ซึ่งเป็น build ที่พบบ่อย

```cpp
function<void(CharUnit *ptr)> pairSet(PairSetType first, PairSetType second)
```
เป็น **factory** คืน lambda แล้วข้างในเรียก `ptr->relicPairSet(first)` / `(second)` ซึ่งเป็นเมธอดของ `CharUnit` (`Function/Setup/SetRelic.h:16`) ที่แปลง `PairSetType` เป็น lambda ลงสแตต แล้ว push ทั้งคู่เข้า `resetList` ก้อนเดียว

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc + 2-pc จากสองเซ็ต | factory รับ `PairSetType` สองตัว · แปลงเป็น lambda ผ่าน `ptr->relicPairSet(…)` แล้วเรียกทั้งคู่ใน `resetList` ก้อนเดียว | `PairSet.h:3-13` (แปลงชนิด: `Function/Setup/SetRelic.h:16`) |
| ตั้งชื่อ | `Relic.name = "PairSet"` เสมอ | `PairSet.h:5` |

## `PairSetType` → สแตตที่ได้

(`Enum/RelicEnum.h` + `Function/Setup/SetRelic.h:16`)

| ค่า | ผล |
|---|---|
| `SPD_P` | `atvStats->speedPercent += 6` |
| `ATK` | ATK% +12 |
| `HP` | HP% +12 |
| `DEF` | DEF% +15 |
| `CRIT_RATE` | CR +8 |
| `CRIT_DAM` | CD +16 |
| `BE` | BE +16 |
| `HEAL_OUT` / `DMG` / `FUA` | ดูต่อที่ `SetRelic.h` |

## จุดที่ควรรู้

- `ptr->Relic.name` ถูกตั้งเป็น `"PairSet"` เสมอ **ไม่ได้บอกว่าใส่คู่ไหน** → ตัวละครหรือ relic อื่นที่เช็คชื่อจะแยกไม่ออก
- ใช้กับ **Relic เท่านั้นตามชื่อฟังก์ชัน** แต่โครงเดียวกันนี้ก็ใช้กับ Planar ได้เพราะรับ `CharUnit*` เหมือนกัน
- สแตตทั้งหมดลง `resetList` = ไม่มีเงื่อนไข ตรงกับธรรมชาติของโบนัส 2 ชิ้น

## ยืนยันเจตนา (2026-09-25)
- PairSet = ใส่ 2 ชิ้นจาก 2 เซ็ต · `first`/`second` เลือกโบนัส 2 ชิ้นแบบ stat ล้วน (CD, DMG, ATK, HP, DEF ฯลฯ) ที่กำหนดค่าไว้ใน `relicPairSet` · ใช้แทนเซ็ตที่ไม่มีผล 4 ชิ้นเกี่ยวข้อง
- `Relic.name` เป็น `"PairSet"` เสมอได้ เพราะไม่มีตัวละคร/relic ไหนเช็คชื่อนี้
