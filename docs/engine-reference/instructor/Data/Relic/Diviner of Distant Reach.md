# `src/Defination/Data/Relic/Diviner of Distant Reach.h`

`Relic.Name` = `"Diviner of Distant Reach"` · ฟังก์ชัน `DivinerOfDistant(bool trigger)` — **factory ที่รับเงื่อนไขมาจากข้างนอก**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — SPD +6% | บวก `speedPercent` ของผู้สวมตรง ๆ ตอนเริ่ม | `Diviner of Distant Reach.h:8` (`trigger=true`) · `:22` (`false`) |
| 4-pc — CR +10% / +18% | kit: CR สูงขึ้นเมื่อเงื่อนไขในเกมเข้า · ซิมให้คนประกอบทีมเลือกเองผ่านพารามิเตอร์ `trigger` (`true` = 18, `false` = 10) | `:9` · `:23` |
| 4-pc — ทั้งทีม Elation +10 | ตอนเริ่มเกมวนทุกคนใน `allyList` ลง `Stats::Elation` +10 · `isHaveToAddBuff(each, "DoD Buff")` กันไม่ให้ซ้อนเมื่อใส่หลายคน | `:11-16` · `:25-30` |

ฟังก์ชันเป็น factory: `DivinerOfDistant(bool trigger)` (`:3`) คืน lambda คนละก้อนตาม `trigger`

## รากฐาน: relic ที่รับพารามิเตอร์

เป็น **factory คืน lambda** แบบเดียวกับ Light Cone ที่รับ superimpose และ `PairSet(first, second)` — ใช้เมื่อผลของเซ็ตขึ้นกับตัวเลือกที่ตัดสินตอนประกอบทีม ไม่ใช่ตอนรัน · เรียกใช้จากฝั่งตัวละครเป็น `Relic::DivinerOfDistant(true)` ส่งผลลัพธ์เข้า `Setup` (ดู `../README.md`)

## จุดที่ควรรู้

- **สองสาขาต่างกันแค่เลข CR เดียว (18 vs 10) แต่โค้ดถูก copy ทั้งก้อน** (`:4-31`) — ถ้าจะแก้ `Start_game_List` หรือ `speedPercent` ต้องแก้ 2 ที่เสมอ · เขียนเป็นตัวแปร `double cr = trigger ? 18 : 10;` แล้วเหลือ lambda เดียวได้
- `Stats::Elation` เป็น stat เฉพาะของ path Elation (เทียบกับ `AType::ElationDMG` ที่เป็นประเภทดาเมจ)

## แก้เมื่อ 2026-09-25
- `Start_game_List` ลง Elation +10 ที่ `each` แทน `ptr` (ทั้งสองสาขา) → ทุกคนในทีมได้คนละ 10 ตาม kit · `isHaveToAddBuff(each, "DoD Buff")` ทำหน้าที่กันซ้อนเมื่อใส่หลายคน · เดิมเจ้าของได้ +10 × จำนวนคนใน `allyList`
