# `src/Defination/Data/Character/Nihility/Luka.h`

kit อ้างอิง: `docs/character-kit-reference/Luka.md` · **ไฟล์อ้างอิงของตัวละครที่มี "ทรัพยากร" (Fighting Will) และ Enhanced Basic ATK**

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(103, 130, 130, E, ElementType::Physical, Path::Nihility, "Luka", UnitType::Standard)` | 5 |
| Base HP/ATK/DEF | `SetAllyBaseStats(917, 582, 485)` | 6 |
| build | `setSpeedRequire(134)` + `setApplyBaseChance(100)` + main stat ช่องแรก `Stats::EHR` | 9-13 |
| **Fighting Will** (ทรัพยากรแกน) | lambda `FW(int amount)` — จุดเดียวที่แตะ `addStack("Fighting Will", ...)` | 23-30 |
| **Basic ATK** | lambda `BA` — 110%/10 + `FW(1)` | 34-47 |
| **Enhanced BA** — Sky-Shatter Fist | lambda `EBA` — `FW(-2)` + `addDamageIns` 4 ครั้ง (22% ต่อครั้ง) + ก้อนปิดท้าย 88%/20 | 49-76 |
| **Skill** — Lacerating Fist + Bleed | lambda `Skill` — 132%/20 + `dotSingleApply(..., "Luka Bleed", 3)` + `FW(1)` | 78-95 |
| **Ultimate** — Coup de Grâce | `Ultimate_List` — 356%/30 + `FW(2)` + `debuffSingleApply({{Stats::VUL, ..., 21.6}}, "Luka Vul", 3)` | 111-127 |
| **Talent** — จุดระเบิด Bleed หลัง Rising Uppercut | `Dot_trigger(88, each, DotType::Bleed)` ท้าย callback ของ EBA | 62 |
| Bleed DoT | `Dot_List` + guard `getDebuff("Luka Bleed")` + `Dot_type` (General/Bleed) → 372% | 170-178 |
| Talent — เริ่มเกมมี FW 1 | `Start_game_List` → `FW(1)` | 141 |
| **Technique** | `Start_game_List` → `if (ptr->Technique)` FW +1 + action 50%/20 + Bleed | 142-157 |
| **A4** — FW → energy 3 | อยู่ใน `FW()` เอง: `Increase_energy(lk, 3.0 * amount)` | 25 |
| **Minor traces** | `Reset_List` | 129-133 |
| **E1** — DMG +15% | `if (ptr->Eidolon >= 1)` ครอบ `WhenOnField_List` → `Stats_type[DMG] += 15` | 135-138 |
| **E2** — Skill ได้ FW เพิ่ม | `if (ptr->Eidolon >= 2) FW(1)` ใน callback ของ Skill | 84 |
| **E4** — FW → ATK +5% (4 stack) | อยู่ใน `FW()`: `buffStackSingle(lk, {{ATK_P, ..., 5}}, amount, 4, "Luka E4")` | 26 |
| **E6** — Bleed ระเบิดเพิ่มตามจำนวน hit | ลูป `Dot_trigger(8, each, DotType::Bleed)` ตามจำนวน `act->damageSplit.size()-1` | 58-61 |
| **A2 / A6** | **ไม่มีเป็นโค้ดตรง ๆ** (A6 ถูกแปลงเป็น deterministic ดูล่าง) | — |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — ไม่มี Bleed บนเป้าหลัก → Skill · FW ≥ 2 → EBA · ไม่งั้น BA | 98-105 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `return true` | 107-109 |
| หมด Bleed / Vul → ถอน | `After_turn_List` + `turn->canCastToEnemy()` + `isDebuffEnd` → `dotRemove` / `debuffSingle` ติดลบ | 160-169 |

## รากฐานที่เพิ่ม

**1. ทรัพยากรของตัวละคร = `addStack` บนตัวเอง + lambda ตัวกลางที่ทุกทางต้องเรียกผ่าน**
`FW(amount)` (23-30) รวม 3 อย่างที่ต้องเกิดพร้อมกันทุกครั้งที่ได้ Fighting Will ไว้ที่เดียว: energy จาก A4, stack ATK จาก E4, และตัวนับจริง · **เป็นรูปแบบที่ควรลอก** — ถ้ากระจาย `addStack` ไว้หลายที่ A4/E4 จะตกหล่นทันทีที่เพิ่มแหล่งได้ทรัพยากรใหม่ · สังเกตว่า `FW` เช็ค `amount > 0` ก่อนให้ energy/stack เพื่อให้การ **ใช้** ทรัพยากร (`FW(-2)`) ผ่านฟังก์ชันเดียวกันได้

**2. `buffStackSingle(เป้า, {stat}, จำนวนที่เพิ่ม, cap, ชื่อ)` = บัฟที่ซ้อนได้แบบมีเพดาน**
ต่างจาก `buffSingle` ที่บวกค่าดิบ — engine จัดการ cap ให้เอง ไม่ต้องนับ stack เอง

**3. ความน่าจะเป็นแบบ 50% ถูกแปลงเป็น "สลับครั้งเว้นครั้ง"**
A6 ของ kit คือ "ทุก hit มี 50% ตีเพิ่ม 1 hit" — โค้ดใช้ `getBuffCheck("Luka EBA")` เป็น flag toggle: EBA ครั้งนี้ไม่ได้ hit เพิ่ม → ตั้ง flag, ครั้งถัดไปได้ hit เพิ่มแล้วล้าง flag (70-73) · **เป็นสำนวนมาตรฐานของซิมนี้ในการแทนค่าสุ่มด้วยค่าคาดหวัง** ให้ผลรันซ้ำได้เท่ากันทุกครั้ง (ดู "ความน่าจะเป็นถูกตัดทิ้ง" ใน `Black Swan.md`)

**4. Enhanced Basic ATK ไม่ใช่ action type ใหม่ — เป็นแค่ lambda อีกตัวที่ `Turn_func` เลือก**
ไม่มีกลไก "สลับร่าง" ใน engine · เงื่อนไขปลดคือเช็ค `getStack` ใน `Turn_func` และการจ่ายทรัพยากรอยู่ใน callback ของ action นั้นเอง

**5. จำนวน hit จริงของ action อ่านได้จาก `act->damageSplit.size()`** — ใช้ตอนผลของ E6 ต้องสเกลตาม "จำนวน hit ที่ปล่อยไปแล้ว" (59)

## ตัวเลขที่ถูกลดรูป

- **Bleed ของ kit สเกลกับ Max HP ศัตรู** (24% Max HP แต่ไม่เกิน 338% ATK) แต่โค้ดใช้ **372% ATK ตายตัว** (บรรทัด 179) — **ไม่ใช่การลดรูปโดยเลือก แต่เป็นเพราะ engine ไม่มี HP ของศัตรู** (ดู `README.md` หัวข้อ "ศัตรูไม่มี HP")
  > และไม่เสียความแม่นยำ: กับบอสที่ซิมนี้ใช้คำนวณ สาขา 24% Max HP ย่อมสูงกว่าเพดานเสมอ → ค่าจริงคือสาขาเพดาน ซึ่งก็คือ 338% ATK ที่ Lv.10 · 372% คือค่าเดียวกันที่ Lv.12 ตรงกับ level ที่ไฟล์นี้ใช้ทั้งไฟล์ · **ตัวเลขนี้ถูกแล้ว ไม่ต้องแก้**
- **E1 ของ kit เป็นบัฟมีเงื่อนไข** (เป้า Bleeding, 2 เทิร์น) แต่โค้ดใส่เป็น `WhenOnField_List` ถาวร (135-138)
- **E2 ของ kit ต้องการศัตรูที่มี Physical Weakness** แต่โค้ด `FW(1)` ทุกครั้งที่ใช้ Skill (84)

## แก้เมื่อ 2026-09-22 (user สั่ง)

- **`Turn_func` ยิง 2 action ในเทิร์นเดียว** — เดิม `if (FW >= 2) EBA();` ไม่มี `return` แล้วตกลงไป `BA();` ต่อ → เมื่อ FW ≥ 2 Luka ทั้ง EBA และ BA ในเทิร์นเดียว (ได้ skill point 2 แต้ม) · ใส่ `{ EBA(); return; }` ให้ทรงเดียวกับสาขา Skill ข้างบน
- **ชนิด DoT ที่ลงไม่ตรงกับที่ถอน/ตรวจ** — เดิม `dotSingleApply(..., {DotType::Burn}, "Luka Bleed", 3)` ลงเป็น **Burn** แต่ `dotRemove(enemy, {DotType::Bleed})` ถอน **Bleed** → `changeDotType` นับ `BurnCount` ค้างขึ้นเรื่อย ๆ และ `BleedCount` ไหลติดลบ (ดู `Class/Unit/Enemy.h:86`) · เปลี่ยนทั้ง 2 จุด (Skill + Technique) เป็น `{DotType::Bleed}` และ action ใน `Dot_List` จาก `AType::Burn` → `AType::Bleed`
  > ดาเมจ DoT ต่อเทิร์นไม่ได้พังจากบั๊กนี้ เพราะ tick ต้นเทิร์นเรียก `Dot_trigger(100, target, DotType::General)` เสมอ (`Function/Event/Event.h:7`) ซึ่งผ่าน guard อยู่แล้ว — ที่พังคือ **ตัวนับชนิด DoT บนศัตรู** ที่ตัวละคร/relic อื่นใช้เช็คว่า "ศัตรูติด Bleed อยู่ไหม"
- **Fighting Will ไม่มีเพดาน — จงใจ** kit กำหนดสูงสุด 4 · เคยใส่ clamp ไว้ช่วงสั้น ๆ แล้ว **เอาออกตามที่ user สั่ง 2026-09-23**: ไม่ clamp เพื่อจะได้ไม่ต้องจูน rotation ให้ไม่ยิงทะลุ cap — ดู `README.md` หัวข้อ "cap ของ stack สะสม"
  > E4 ยังคง cap ที่ 4 ตามปกติ เพราะส่ง cap เป็นพารามิเตอร์ให้ `buffStackSingle` จัดการ ไม่ต้องจูนอะไรเพิ่ม
- **Skill / Ult ใช้ `AType::BA`** — เปลี่ยนเป็น `AType::SKILL` / `AType::Ult` และเปลี่ยนชื่อ action ของ ult จาก `"Luka BA"` → `"Luka Ult"` · **การแก้นี้เปลี่ยนตัวเลขผลลัพธ์**: บัฟที่ผูกกับ `AType::BA` จะไม่เข้า Skill/Ult อีกต่อไป ส่วนบัฟที่ผูกกับ `AType::SKILL`/`AType::Ult` จะเริ่มเข้า
  > `EBA` ยังเป็น `AType::BA` ถูกต้องแล้ว เพราะ Enhanced Basic ATK นับเป็น Basic ATK จริง ๆ

## จุดที่ยังค้าง

- **ตัวเลขที่ถูกลดรูป** (Bleed ไม่สเกลกับ Max HP, E1 ถาวรแทนมีเงื่อนไข, E2 ไม่เช็ค Physical Weakness) — ดูหัวข้อข้างบน ยังไม่แก้
- **A2 (ลบ buff 1 อันตอนใช้ Skill) ยังไม่มี**
- **`FW()` สาขา `else {}` ว่างเปล่า** — ตั้งใจเว้นไว้ให้เห็นว่าการ "ใช้" ทรัพยากรไม่ให้ energy/stack แต่ก็เป็นบล็อกตายที่ชวนสับสน
