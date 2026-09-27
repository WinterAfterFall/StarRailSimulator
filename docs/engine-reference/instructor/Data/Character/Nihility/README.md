# `src/Defination/Data/Character/Nihility/`

DoT และ debuff ฝั่งศัตรู · 11 ไฟล์ (รวม `Black SwanV1.h`)

| ไฟล์ | บทบาท | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `Pela.h` | DEF shred | **debuff ฝั่งศัตรู** · กฎ `addDamageIns` (arg = การกระจายเป้า) |
| `Black Swan.h` | DoT stack (Arcana) | ระบบ DoT · `dotList` · การตัดความน่าจะเป็นทิ้ง · เพิกเฉย DEF เฉพาะก้อน |
| `Kafka.h` | DoT detonate | `dotSingleApply` (มีอายุ) · `dotTrigger` · FuA ที่มี charge · `setAdjust` |
| `Luka.h` | Bleed + ทรัพยากร | ทรัพยากรผ่าน lambda ตัวกลาง · Enhanced BA · แปลงค่าสุ่มเป็น deterministic |
| `Guinaifen.h` | Burn | `enemyEffectRes` · `debuffStackEnemyTargets` |
| `Silver Wolf.h` | debuff หลายชั้น | Bug 1/2/3 · แปะ weakness ตามธาตุของทีม |
| `Hysilens.h` | DoT 4 ชนิด | เลือกชนิด DoT รายตัว · `getDebuffTimeCount` · `debuffMark` |
| `Cipher.h` | True DMG | `calDamageNote` แบบกระจายหลายเป้า · `adjust` เป็น config |
| `Dahlia.h` | Super Break support | แก้ `toughnessReduce` ของ action คนอื่น · `weaknessApplyList` |
| `Fugue.h` | Super Break support | `toughnessBreak()` เรียกด้วยมือ (break ซ้ำ) |
| `Black SwanV1.h` | (เวอร์ชันเก่า) | ดู `Black SwanV1.md` |

## แบบแผนร่วมของกลุ่มนี้

**1. `setApplyBaseChance(100)` หรือ `setEhrRequire(n)` เกือบทุกตัว** — เพราะระบบความน่าจะเป็นถูกตัดทิ้ง debuff ลงติดเสมอ แล้วชดเชยด้วยการบังคับ build (ดู `Black Swan.md`)

**2. handler ใน `dotList` ต้อง guard 2 ชั้นเสมอ** — เป้านี้ติด DoT ของเราไหม และ `dotType` เกี่ยวกับเราไหม (ดู `Kafka.md`)

**3. debuff ที่ไม่มีอายุ (`debuffAllEnemyMark` / `debuffMark`) ต้องถอนเองทุกทาง**

**4. `AType` ผิดประเภทเป็นปัญหาที่พบบ่อยที่สุดในโฟลเดอร์นี้** — แก้แล้ว: `Black Swan.h`, `Luka.h` · **ยังไม่แก้**: `Guinaifen.h` (Skill+Ult เป็น `AType::BA`), `Fugue.h` (Skill เป็น `AType::BA`), `Dahlia.h` (Ult เป็น `AType::SKILL`)
