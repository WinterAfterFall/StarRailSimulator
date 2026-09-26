# `src/Defination/Data/Character/Erudition/`

AoE และ Break · 6 ไฟล์

| ไฟล์ | บทบาท | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `Jingyuan.h` | summon (Lightning-Lord) | **ระบบ `summon`** — ต่างจาก memosprite · ความเร็วของ summon เป็นกลไก |
| `Serval.h` | Shock | ตัวนับ Shock กลางบนศัตรู (`changeShock`) · `addDamageHit` · `extendDebuffAll` |
| `Jade.h` | FuA เป็นชุด | ลูปยิง FuA จากตัวนับ · ตัวนับสองชั้นที่มีหน่วยต่างกัน |
| `Anaxa.h` | แปะ weakness | `weaknessApplyChoose` · `Enemy_weak` · A6 ที่คำนวณจากสถานะศัตรู |
| `Rappa.h` | Break/Super Break | `Cal_Break_damage` / `Cal_Toughness_reduction` เรียกตรง · `Dont_care_weakness` |
| `The_Herta.h` | ทรัพยากรหลายชั้น | ดาเมจที่ `addDamageIns` ใน callback · AI ที่ปรับตาม `driverType` · `debuffCheck` เป็นตัวนับ |

## แบบแผนร่วมของกลุ่มนี้

**1. ท่าส่วนใหญ่เป็น AoE** → `addDamageIns` แบบ 3 args เป็นค่ามาตรฐานของโฟลเดอร์นี้

**2. หลายตัวมี "ท่าที่เรียกตัวเองซ้ำ"** — `Jade` (ลูป FuA), `Anaxa` (Talent เรียก Skill ซ้ำ) · **ทุกตัวต้องมีตัวหยุดที่ชัดเจน** ซึ่ง `Anaxa.h` เป็นตัวที่หลวมที่สุด

**3. `Enemy_Death_List` ถูกใช้ใน 3 ไฟล์จาก 6** (`Jade.h`, `Serval.h`, `The_Herta.h`) — และไม่ทำงานสักตัว ดู `../../README.md`

**4. มี 2 ไฟล์ที่มีฟังก์ชันตายคืนค่าคงที่เสมอ** — `Jingyuan.h` (`Temp_Turn_Condition`, `Temp_ult_Condition`) และ `The_Herta.h` (`Stack_Herta_Check` — **รื้อฟื้นแล้ว 2026-09-23**)
