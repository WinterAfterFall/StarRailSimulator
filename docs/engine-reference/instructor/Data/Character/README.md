# `src/Defination/Data/Character/`

ตัวละครทั้งหมด แยกโฟลเดอร์ตาม Path · 1 ไฟล์ = 1 ตัวละคร = 1 `namespace` · แต่ละโฟลเดอร์มี `All_<Path>_char.h` ที่ `#include` ทุกตัวในนั้น และ `All_Character.h` รวมทุก path อีกชั้น

อ่าน `../README.md` (กฎกลางของ `Data/`) และ `Template.md` (โครงของไฟล์ตัวละคร) ก่อน

## อ่านตามลำดับนี้ถ้าเพิ่งเริ่ม

| ลำดับ | ไฟล์ | ได้อะไร |
|---|---|---|
| 1 | `Harmony/Tingyun.md` | โครงพื้นฐานทั้งหมด · บัฟ ally · การถอน stat delta · บัฟ single-target ที่ต้องจำผู้ถือจริง |
| 2 | `Nihility/Pela.md` | debuff ฝั่งศัตรู · `AfterAttackActionList` · `WhenOnField_List` · กฎ `addDamageIns` |
| 3 | `Nihility/Black Swan.md` | ระบบ DoT แบบ stack · `Dot_List` · การตัดความน่าจะเป็นทิ้ง |
| 4 | `Nihility/Kafka.md` | DoT แบบมีอายุ · `Dot_trigger` · FuA ที่มี charge |
| 5 | `Abundance/Luocha.md` | ระบบฮีล (`RestoreHP` / `HealSrc`) |
| 6 | `Abundance/Gallagher.md` | `Stats_Adjust_List` — stat ที่คำนวณจาก stat อื่น |
| 7 | `Remembrance/RMC.md` | memosprite · `AType::TEMP` กันลูป |

## สรุปแต่ละโฟลเดอร์

| Path | ตัวละคร | จุดเด่นของกลุ่ม |
|---|---|---|
| `Harmony/` | Tingyun, Bronya, Robin, Sunday, Ruan_Mei, Hanabi, Harmony_MC, Cerydra, Tribbie (+HanabiV1) | ซัพพอร์ต — บัฟทีม, `Driver_num`, การจำผู้ถือบัฟ |
| `Nihility/` | Kafka, Black Swan, Luka, Pela, Guinaifen, Silver Wolf, Hysilens, Cipher, Dahlia, Fugue (+Black SwanV1) | DoT และ debuff ฝั่งศัตรู |
| `Erudition/` | Jingyuan, Serval, Jade, Anaxa, Rappa, The_Herta | AoE, summon, Break/Super Break |
| `Destruction/` | Mydei, Phainon, Saber, FireFly | ทรัพยากรหนัก, สถานะพิเศษที่กินหลายเทิร์น |
| `Remembrance/` | RMC, Aglaea, Castorice, Hyacine | memosprite ทั้งหมด |
| `Abundance/` | Luocha, Gallagher, Huohuo | ระบบฮีล |
| `Elation/` | Hibana, YaoGuang | path Elation — punchline, Aha Instant |
| `The Hunt/` | Archer | ตัวเดียวของ path นี้ |
| `Preservation/` | Aventurine (**คอมเมนต์ทิ้งทั้งไฟล์**) | ยังไม่มีตัวที่ใช้ได้ — รอระบบโล่ |

## ของที่ควรรู้ก่อนแก้ไฟล์ไหนก็ตาม

1. **`AType` ของ action ต้องตรงกับท่าจริง** — Skill ต้องเป็น `AType::SKILL` ไม่ใช่ `AType::BA` · บัฟหลายตัว (relic, planar, ตัวละครอื่น) ผูกกับ `AType` · ไฟล์ที่ยังผิดอยู่: `Nihility/Guinaifen.h`, `Nihility/Fugue.h`, `Nihility/Dahlia.h`
2. **บัฟที่ลงต้องถอนให้ครบทุกทาง** — หมดอายุ (`isBuffEnd` / `isDebuffEnd`) และผู้ถือตาย (`isBuffGoneByDeath`) · ดู `../../future-improvements.md` ข้อ 1
3. **บัฟ single-target ต้องจำผู้ถือจริง** ไม่ใช่เรียก `chooseAllyBuff()` สดตอนถอน — ดู `Harmony/Tingyun.md`
4. **เลขในโค้ดไม่ตรง kit เป็นเรื่องปกติ** — kit เป็น Lv.6/Lv.10 โค้ดเป็นเลขที่บวก E3/E5 แล้ว
5. **`Enemy_Death_List` ไม่เคยทำงาน** — ดู `../README.md`
