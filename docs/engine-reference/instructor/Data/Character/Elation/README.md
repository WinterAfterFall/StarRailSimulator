# `src/Defination/Data/Character/Elation/`

path Elation · 6 ไฟล์ · **อ่าน `Hibana.md` ก่อนเพราะมีตารางคำศัพท์ของ path นี้**

| ไฟล์ | ตัวจริงในเกม | บทบาท |
|---|---|---|
| `Hibana.h` | **Sparxie** (ดู `docs/kit-reference/Character/README.md`) | DPS — เผา SP ทั้งกระดานแล้วคูณดาเมจ |
| `YaoGuang.h` | Yao Guang (ชื่อ unit มีช่องว่าง) | ซัพพอร์ต — ยิง Elation Skill ของทั้งทีมผ่าน `ahaInstant` |
| `AventurineWaveflair.h` | Aventurine • Waveflair (unit `"Aventurine Waveflair"`) | DPS — สะสม Fervor จากทีมตี, Cheers! ฟรี แล้ว All In! ใช้ Fervor เป็น bounce · ดู [AventurineWaveflair.md](AventurineWaveflair.md) |
| `EMC.h` | Trailblazer • Elation (unit `"EMC"`) | ซัพพอร์ต — Ult ให้ CB + สั่งเพื่อนใช้ Elation Skill ทันที, Skill ใช้ CB สูงสุดในทีม · ดู [EMC.md](EMC.md) |
| `Evanescia.h` | Evanescia | DPS — Energy ⇄ Certified Banger, Energy ครบ 240 → Master Fox FuA · ดู [Evanescia.md](Evanescia.md) |
| `SilverWolf999.h` | Silver Wolf LV.999 (unit `"Silver Wolf 999"`) | DPS — สะสม Hidden MMR แล้วเข้า Godmode ตี Enhanced BA + Top Loot Box · ดู [SilverWolf999.md](SilverWolf999.md) |

## คำศัพท์ของ path Elation

| ของ | เก็บที่ |
|---|---|
| **Punchline** | global `punchline` · เพิ่มด้วย `genPunchLine(ptr, n)` |
| `Stats::ELATION` | ตัวคูณของดาเมจชนิด Elation |
| `Stats::CERTIFIED_BANGER` / `Stats::MERRYMAKE` | stat ที่ใช้เป็นสวิตช์เปิด/ปิดผล |
| `DmgSrcType::ELATION` | แหล่งดาเมจที่สเกลกับ `Stats::ELATION` |
| `AType::ELATION_DMG` / `AType::ELATION_SKILL` | ประเภท action/ดาเมจของ path นี้ |
| `elationSkillList` | ท่าที่ยิงตอน Aha Instant |
| `afterAhaInstantList` | trigger หลัง Aha Instant จบ |
| `elationCount` | global — จำนวนตัวละคร Elation ในทีม (นับใน `setup`) |
| `punchLineList` | trigger เมื่อ punchline เปลี่ยน |

## จุดที่ทั้งสองไฟล์มีเหมือนกัน

- **`elationSkillList` ใช้ตัวเลข priority ดิบ** (`144` ใน Hibana, `114` ใน YaoGuang, `999` ใน SilverWolf999, `146` ใน Evanescia, `120` ใน EMC, `156` ใน AventurineWaveflair — ตัวเลขนี้คือ Participant ID ในเกม) แทนค่าคงที่ `PRIORITY_*` — ไม่มีที่อื่นในโปรเจกต์ทำแบบนี้
- **ดาเมจ Elation เป็น action แยกก้อน** ไม่ใช่เพิ่ม `addDamageIns` เข้า action เดิม
- `note/Note.txt` มีงานค้าง "แก้ Aha instant เป็น unit" → ระบบนี้ยังไม่นิ่ง
