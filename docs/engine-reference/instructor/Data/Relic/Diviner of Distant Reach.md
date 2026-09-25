# `src/Defination/Data/Relic/Diviner of Distant Reach.h`

`Relic.Name` = `"Diviner of Distant Reach"` · ฟังก์ชัน `DivinerOfDistant(bool trigger)` — **factory ที่รับเงื่อนไขมาจากข้างนอก**

```cpp
function<void(CharUnit *ptr)> DivinerOfDistant(bool trigger)
```

| `trigger` | CR ที่ได้ | ส่วนที่เหมือนกันทั้งสองสาขา |
|---|---|---|
| `true` | +18 | `speedPercent += 6` · `Start_game_List` แจก `Stats::Elation` +10 |
| `false` | +10 | เหมือนกันทุกอย่าง |

## รากฐาน: relic ที่รับพารามิเตอร์

เป็น **factory คืน lambda** แบบเดียวกับ Light Cone ที่รับ superimpose และ `PairSet(first, second)` — ใช้เมื่อผลของเซ็ตขึ้นกับตัวเลือกที่ตัดสินตอนประกอบทีม ไม่ใช่ตอนรัน · เรียกใช้จากฝั่งตัวละครเป็น `Relic::DivinerOfDistant(true)` ส่งผลลัพธ์เข้า `Setup` (ดู `../README.md`)

## จุดที่ควรรู้

- **สองสาขาต่างกันแค่เลข CR เดียว (18 vs 10) แต่โค้ดถูก copy ทั้งก้อน** (4-31) — ถ้าจะแก้ `Start_game_List` หรือ `speedPercent` ต้องแก้ 2 ที่เสมอ · เขียนเป็นตัวแปร `double cr = trigger ? 18 : 10;` แล้วเหลือ lambda เดียวได้
- **ลูป `Start_game_List` ดูแปลก** (12-16): วน `allyList` เช็ค `isHaveToAddBuff(each, "DoD Buff")` ทีละคน แต่ `buffSingle(ptr, ...)` ที่บวก `Stats::Elation` +10 **ลงที่เจ้าของ relic เสมอ** ไม่ใช่ที่ `each` → ผลคือเจ้าของได้ Elation +10 คูณจำนวนเพื่อนที่ยังไม่ถูก mark · ถ้าเจตนาคือ "แจกเพื่อนคนละ 10" ต้องเป็น `buffSingle(each, ...)` ถ้าเจตนาคือ "ได้ 10 ครั้งเดียว" ก็ไม่ต้องวน
- `Stats::Elation` เป็น stat เฉพาะของ path Elation (เทียบกับ `AType::ElationDMG` ที่เป็นประเภทดาเมจ)

## แก้เมื่อ 2026-09-25
- `Start_game_List` ลง Elation +10 ที่ `each` แทน `ptr` (ทั้งสองสาขา) → ทุกคนในทีมได้คนละ 10 ตาม kit · `isHaveToAddBuff(each, "DoD Buff")` ทำหน้าที่กันซ้อนเมื่อใส่หลายคน · เดิมเจ้าของได้ +10 × จำนวนคนใน `allyList`
