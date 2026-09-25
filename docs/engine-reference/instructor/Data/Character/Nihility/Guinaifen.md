# `src/Defination/Data/Character/Nihility/Guinaifen.h`

kit อ้างอิง: `docs/kit-reference/Character/Guinaifen.md` · **DoT สาย Burn** — โครงเดียวกับ `Kafka.md` แต่เรียบกว่ามาก อ่าน Kafka ก่อน

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(106, 120, 120, E, Fire, Nihility, "Guinaifen", Standard)` | 5 |
| **A-trace** — ลด Effect RES ศัตรูทั้งเกม (E1) | `if (ptr->Eidolon >= 1) Enemy_effect_res -= 10;` | 24 |
| **Basic ATK** | lambda `BA` — single 110%/10 + ลง Burn | 26-41 |
| **Skill** | lambda `Skill` — blast 132/44 + ลง Burn | 43-59 |
| **Ultimate** | `Ultimate_List` — AoE 129.6%×3 + `Dot_trigger(96, each, DotType::Burn)` | 71-88 |
| **Talent** — Firekiss: ศัตรูโดน Burn → VUL stack | `BeforeAttack_List` → `debuffStackEnemyTargets(..., 1, 3, "Firekiss")` | 129-137 |
| Burn DoT | `Dot_List` + guard `getDebuff("Gui Burn")` + `Dot_type` | 139-149 |
| **Technique** | `Start_game_List` — AoE 50% + Burn + advance ตัวเอง 25% | 100-119 |
| **Minor traces** | `Reset_List` · `WhenOnField_List` (DMG +20) | 90-98 |
| **E1** — Effect RES ศัตรู −10 | บรรทัด 24 | |
| **E2** — Burn 240 → 280 | `Dot_List` | 144-145 |
| **E4** — energy 2 ต่อ tick | `if (ptr->Eidolon >= 4) Increase_energy(ptr, 2)` | 147 |
| **E6** — Firekiss ซ้อนได้ 4 ชั้น | `debuffStackEnemyTargets(..., 4, ...)` | 132 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — `sp > Sp_Safety` → Skill ไม่งั้น BA | 62-65 |
| Burn หมดอายุ | `After_turn_List` + `isDebuffEnd` → `dotRemove` | 121-127 |

## รากฐานที่เพิ่ม

**1. `Enemy_effect_res` — ตัวแปร global ของฝั่งศัตรู**
`Enemy_effect_res -= 10;` (24) แก้ค่า Effect RES ของศัตรู **ทั้งเกม** ตอน `Setup` — ไม่ใช่ debuff รายตัว จึงไม่ต้องถอน · เป็นตัวแปรเดียวกับที่ `setApplyBaseChance` / `setEhrRequire` ของตัวละครต้องสู้ด้วย

**2. `debuffStackEnemyTargets(ผู้ลง, targetList, {stat}, เพิ่ม, cap, ชื่อ)`**
เวอร์ชัน stack ของ `debuffEnemyTargetsApply` — engine นับ stack และ clamp ให้เอง เหมือน `buffStackSingle` ฝั่ง ally (ดู `Luka.md`)

**3. `act->isSameDamageType(AType::Burn)`**
กรองจาก **ประเภทดาเมจ** ของ action ไม่ใช่ประเภท action — ใช้จับว่า "มีดาเมจ Burn เกิดขึ้น" ไม่ว่าจะมาจากใคร · `Black Swan.h:107` ใช้ `isSameDamageType(AType::Dot)` ในทางเดียวกัน

## จุดที่ควรระวัง

- **ทุก action สร้างด้วย `AType::BA`** — Skill (46) และ **Ult (73)** ใช้ `AType::BA` และ Ult ยังตั้งชื่อว่า `"Gui Skill"` ซ้ำกับ Skill จริง · อาการเดียวกับที่แก้ไปแล้วใน `Black Swan.md` และ `Luka.md` **แต่ไฟล์นี้ยังไม่ได้แก้**
- **`BeforeAttack_List` ของ Firekiss ไม่ guard ผู้โจมตี** (129-137) → ศัตรูติด VUL stack ทุกครั้งที่มีดาเมจ Burn จากใครก็ได้ รวมถึง Burn ของ `../Nihility/Luka.h` ที่ลง `DotType::Burn` ผิดชนิดอยู่ก่อนหน้านี้ (แก้แล้ว)
- **Firekiss ไม่มีโค้ดถอน** — `debuffStackEnemyTargets` ลงโดยไม่ระบุ duration และไม่มี `isDebuffEnd` ที่ไหนรองรับ → VUL +7.6 ต่อชั้นค้างถาวรจนจบการต่อสู้
- **`Dot_trigger` ใน Ult ใช้ `DotType::Burn`** (77) จุดชนวนเฉพาะ Burn ไม่ใช่ `General` — ต่างจาก `Kafka.h` ที่ใช้ `General` เพื่อจุดทุกชนิด · ตรงกับ kit ของ Guinaifen ที่เกี่ยวกับ Burn อย่างเดียว
- **`WhenOnField_List` บวก `Stats::DMG += 20` ลอย ๆ** (97) ไม่มีคอมเมนต์ว่ามาจาก trace ไหน
