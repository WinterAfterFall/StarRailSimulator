# Character Kit Reference (ข้อมูลสกิลจากเกมจริง)

โฟลเดอร์นี้เก็บ **สรุป kit ของตัวละคร Honkai: Star Rail จากเกมจริง** เพื่อใช้เป็น
ground-truth เวลาเทียบกับโค้ด implementation ใน `src/Defination/Data/Character/`

- แบ่งโฟลเดอร์ตาม Path: `<Path>/<slug>.md` (slug ตามชื่อในเกมของ prydwen เช่น `Harmony/cerydra.md` ↔ `Harmony/Cerydra.h`) — ครอบคลุม 92 ตัว (snapshot prydwen 2026-05-30)
- แต่ละไฟล์: frontmatter + JSON ตัวเลขทุกเลเวลจาก prydwen และสำหรับ 40 ตัวที่มีโค้ด จะมีหัวข้อ "สรุป kit ภาษาไทย + จุดเทียบโค้ด" (เนื้อหาจากไฟล์ kit-reference เดิม)
- ตัวที่ codename ในโค้ดไม่ตรงชื่อเกม ดูตารางด้านล่าง (เช่น `Hibana.h` → `Elation/sparxie.md`, `Hanabi.h` → `Harmony/sparkle.md`, `RMC.h` → `Remembrance/trailblazer-remembrance.md`)
- เนื้อหา = **เฉพาะ kit ในเกม** (Basic / Skill / Ultimate / Talent / Technique / Traces / Eidolons)
  ไม่รวมวิธีปั้น relic / lightcone / ทีมแนะนำ
- ตัวเลข multiplier เป็นค่า **max trace level** (Basic Lv.6-7 / Skill·Ult·Talent Lv.10) ก่อนบวก Eidolon
  E3 = +Skill/Basic, E5 = +Ult/Talent
- ข้าม V1 dupes (`HanabiV1`, `Black SwanV1`) — ดูไฟล์ตัวจริงแทน

## แหล่งอ้างอิงหลัก
- prydwen.gg/star-rail/characters/&lt;name&gt; (kit tab) — patch อ้างอิงส่วนใหญ่ ~3.x–4.x (review/calc date ระบุในแต่ละไฟล์)
- ทุกไฟล์ระบุ URL + patch ที่ prydwen review/calc ล่าสุดไว้ท้ายไฟล์

## Codename / เวอร์ชัน — สรุป
| ไฟล์โค้ด | ตัวจริงในเกม |
|---|---|
| `Elation/Hibana.h` (namespace `Hibana`) | **Sparxie** (Fire Elation, patch 4.0) |
| `Elation/YaoGuang.h` (`"Yao Guang"`) | **Yao Guang** (Physical Elation, patch 4.0) |
| `Harmony/Hanabi.h` (namespace `Hanabi`, JP 花火) | **Sparkle** |
| `Nihility/Dahlia.h` | **The Dahlia / Constance** (Fire Nihility, patch 3.8) |
| `Nihility/Fugue.h` | **Tingyun • Fugue** (alt ของ Tingyun, Fire Nihility) |
| `Nihility/Silver Wolf.h` (`"SW"`) | **Silver Wolf** |
| `Harmony/Harmony_MC.h` | **Trailblazer • Harmony** |
| `Remembrance/RMC.h` | **Trailblazer • Remembrance** |
| `Destruction/Saber.h` / `The Hunt/Archer.h` | **Saber (Artoria) / Archer (EMIYA)** — Fate/stay night collab |
| `Harmony/HanabiV1.h`, `Nihility/Black SwanV1.h` | เวอร์ชัน implement เก่า — **ข้าม** (ใช้ไฟล์ตัวจริงแทน) |

## สถานะ — ✅ ครบ 40/40

| ไฟล์โค้ด | ตัวละคร (เกม) | ธาตุ / Path | README |
|---|---|---|---|
| `Abundance/Gallagher.h` | Gallagher | Fire / Abundance | ✅ |
| `Abundance/Huohuo.h` | Huohuo | Wind / Abundance | ✅ |
| `Abundance/Luocha.h` | Luocha | Imaginary / Abundance | ✅ |
| `Destruction/FireFly.h` | Firefly | Fire / Destruction | ✅ |
| `Destruction/Mydei.h` | Mydei | Imaginary / Destruction | ✅ |
| `Destruction/Phainon.h` | Phainon | Physical / Destruction | ✅ |
| `Destruction/Saber.h` | Saber (Fate collab) | Wind / Destruction | ✅ |
| `Elation/Hibana.h` | Sparxie (codename: Hibana) | Fire / Elation | ✅ |
| `Elation/YaoGuang.h` | Yao Guang | Physical / Elation | ✅ |
| `Erudition/Anaxa.h` | Anaxa | Wind / Erudition | ✅ |
| `Erudition/Jade.h` | Jade | Quantum / Erudition | ✅ |
| `Erudition/Jingyuan.h` | Jing Yuan | Lightning / Erudition | ✅ |
| `Erudition/Rappa.h` | Rappa | Imaginary / Erudition | ✅ |
| `Erudition/Serval.h` | Serval | Lightning / Erudition | ✅ |
| `Erudition/The_Herta.h` | The Herta | Ice / Erudition | ✅ |
| `Harmony/Bronya.h` | Bronya | Wind / Harmony | ✅ |
| `Harmony/Cerydra.h` | Cerydra | Wind / Harmony | ✅ |
| `Harmony/Hanabi.h` | Sparkle (codename: Hanabi) | Quantum / Harmony | ✅ |
| `Harmony/Harmony_MC.h` | Trailblazer (Harmony) | Imaginary / Harmony | ✅ |
| `Harmony/Robin.h` | Robin | Physical / Harmony | ✅ |
| `Harmony/Ruan_Mei.h` | Ruan Mei | Ice / Harmony | ✅ |
| `Harmony/Sunday.h` | Sunday | Imaginary / Harmony | ✅ |
| `Harmony/Tingyun.h` | Tingyun | Lightning / Harmony | ✅ |
| `Harmony/Tribbie.h` | Tribbie | Quantum / Harmony | ✅ |
| `Nihility/Black Swan.h` | Black Swan | Wind / Nihility | ✅ |
| `Nihility/Cipher.h` | Cipher | Quantum / Nihility | ✅ |
| `Nihility/Dahlia.h` | The Dahlia (Constance) | Fire / Nihility | ✅ |
| `Nihility/Fugue.h` | Tingyun • Fugue | Fire / Nihility | ✅ |
| `Nihility/Guinaifen.h` | Guinaifen | Fire / Nihility | ✅ |
| `Nihility/Hysilens.h` | Hysilens (Helektra) | Physical / Nihility | ✅ |
| `Nihility/Kafka.h` | Kafka | Lightning / Nihility | ✅ |
| `Nihility/Luka.h` | Luka | Physical / Nihility | ✅ |
| `Nihility/Pela.h` | Pela | Ice / Nihility | ✅ |
| `Nihility/Silver Wolf.h` | Silver Wolf | Quantum / Nihility | ✅ |
| `Preservation/Aventurine.h` | Aventurine | Imaginary / Preservation | ✅ |
| `Remembrance/Aglaea.h` | Aglaea | Lightning / Remembrance | ✅ |
| `Remembrance/Castorice.h` | Castorice | Quantum / Remembrance | ✅ |
| `Remembrance/Hyacine.h` | Hyacine (Hyacinthia) | Wind / Remembrance | ✅ |
| `Remembrance/RMC.h` | Trailblazer (Remembrance) | Ice / Remembrance | ✅ |
| `The Hunt/Archer.h` | Archer (EMIYA, Fate collab) | Quantum / The Hunt | ✅ |
