# `src/Defination/Data/Character/Elation/`

path Elation · 2 ไฟล์ · **อ่าน `Hibana.md` ก่อนเพราะมีตารางคำศัพท์ของ path นี้**

| ไฟล์ | ตัวจริงในเกม | บทบาท |
|---|---|---|
| `Hibana.h` | **Sparxie** (ดู `docs/character-kit-reference/README.md`) | DPS — เผา SP ทั้งกระดานแล้วคูณดาเมจ |
| `YaoGuang.h` | Yao Guang (ชื่อ unit มีช่องว่าง) | ซัพพอร์ต — ยิง Elation Skill ของทั้งทีมผ่าน `AhaInstant` |

## คำศัพท์ของ path Elation

| ของ | เก็บที่ |
|---|---|
| **Punchline** | global `punchline` · เพิ่มด้วย `genPunchLine(ptr, n)` |
| `Stats::Elation` | ตัวคูณของดาเมจชนิด Elation |
| `Stats::CertifiedBanger` / `Stats::Merrymake` | stat ที่ใช้เป็นสวิตช์เปิด/ปิดผล |
| `DmgSrcType::Elation` | แหล่งดาเมจที่สเกลกับ `Stats::Elation` |
| `AType::ElationDMG` / `AType::ElationSkill` | ประเภท action/ดาเมจของ path นี้ |
| `ElationSkill_List` | ท่าที่ยิงตอน Aha Instant |
| `AfterAhaInstant_List` | trigger หลัง Aha Instant จบ |
| `elationCount` | global — จำนวนตัวละคร Elation ในทีม (นับใน `Setup`) |
| `PunchLine_List` | trigger เมื่อ punchline เปลี่ยน |

## จุดที่ทั้งสองไฟล์มีเหมือนกัน

- **`ElationSkill_List` ใช้ตัวเลข priority ดิบ** (`144` ใน Hibana, `114` ใน YaoGuang) แทนค่าคงที่ `PRIORITY_*` — ไม่มีที่อื่นในโปรเจกต์ทำแบบนี้
- **ดาเมจ Elation เป็น action แยกก้อน** ไม่ใช่เพิ่ม `addDamageIns` เข้า action เดิม
- `note/Note.txt` มีงานค้าง "แก้ Aha instant เป็น unit" → ระบบนี้ยังไม่นิ่ง
