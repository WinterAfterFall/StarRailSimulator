# `src/Defination/Data/Character/Abundance/`

ฮีลเลอร์ · 3 ไฟล์

| ไฟล์ | บทบาท | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `Luocha.h` | ฮีลอัตโนมัติ + Field | **ระบบฮีลทั้งหมด** (`RestoreHP` 4 overload, `HealSrc`) · Field เป็นแค่บัฟ ไม่ใช่วัตถุ |
| `Gallagher.h` | ฮีล + Break | **`Stats_Adjust_List`** — stat ที่คำนวณจาก stat อื่นแบบ live · `RestoreHP(HealSrc)` = ฮีลทั้งทีม |
| `Huohuo.h` | ฮีลต่อเนื่อง | ทรัพยากรที่นับด้วยจำนวนครั้งฮีล ไม่ใช่เทิร์น |

## สิ่งที่ต้องรู้

**1. `RestoreHP` มี 4 overload และแต่ละตัวเลือกผู้รับต่างกัน**

| รูปแบบ | ผู้รับ |
|---|---|
| `RestoreHP(HealSrc)` | **ทุกคนในทีม** |
| `RestoreHP(main, adjacent, other)` | เรียงตามคนที่เสีย HP มากสุด (priority queue ข้างใน) |
| `RestoreHP(target, HealSrc)` | คนเดียวที่ระบุ |
| `RestoreHP(target, main, other)` | คนที่ระบุได้ `main` ที่เหลือได้ `other` |

**2. `HealSrcType` มี 6 แบบ** (`ATK`/`HP`/`DEF`/`TOTAL_HP`/`LOST_HP`/`CONST`) มากกว่า `DmgSrcType` ที่มี 5

**3. ตัวเลขฮีลไม่ใช่ตัวเลขที่ซิมนี้วัด** — ซิมวัดดาเมจที่ทีมทำได้ · ผลของฮีลเลอร์ที่กระทบผลลัพธ์จริงคือบัฟ/debuff ที่แถมมา (Luocha E1/E6, Gallagher Besotted, Huohuo Ult ATK+40%)

**4. Field / Divine Provision ไม่ใช่ concept ของ engine** — เป็นบัฟบนตัวฮีลเลอร์ที่โค้ดอ่านเอง

**5. ระบบโล่ยังไม่มี** — ดู `../Preservation/Aventurine.md` และ `../../../future-improvements.md` ข้อ 2
