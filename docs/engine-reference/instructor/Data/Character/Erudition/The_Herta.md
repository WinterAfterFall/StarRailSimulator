# `src/Defination/Data/Character/Erudition/The_Herta.h`

kit อ้างอิง: `docs/kit-reference/Character/Erudition/the-herta.md` · **ไฟล์ที่ซับซ้อนที่สุดในกลุ่มที่สำรวจแล้ว (320 บรรทัด)** — ตัวอย่างของตัวละครที่มีทรัพยากร 3 ชั้น (Interpretation บนศัตรู / Inspiration บนตัวเอง / Answer บนตัวเอง) และ AI ที่ปรับจูนตามรูปแบบทีม · มี `//temp` (บรรทัด 6) ส่วน AI ยังไม่นิ่ง

## ทรัพยากร 3 ตัว เก็บที่ไหน

| ชื่อใน kit | เก็บที่ | หมายเหตุ |
|---|---|---|
| **Interpretation** (บนศัตรู, cap 42) | `enemy->debuffCheck["Herta_Stack"]` | ใช้ช่อง `debuffCheck` **เป็นตัวนับจำนวนเต็ม** ไม่ใช่ flag 0/1 |
| **Inspiration** (ชาร์จ Enhanced Skill) | `ptr->buffNote["The_Herta_Skill_Enchance"]` | `buffNote` = map จำนวนเต็มอิสระบนตัวละคร |
| **Answer** (A6, cap 99 → Ult multiplier) | `ptr->stack["The_Herta_A6"]` | เข้าถึง `stack` ตรง ๆ ไม่ผ่าน `addStack`/`getStack` |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult (220) | `setCharBasicStats(99, 220, 220, E, ElementType::ICE, Path::ERUDITION, "The_Herta", UnitType::STANDARD)` | 16 |
| Base HP/ATK/DEF | `setAllyBaseStats(1164, 679, 485)` | 18 |
| **Basic ATK** | `basicAtk(ptr)` — single 100%/10 | 200-210 |
| **Skill** — Big Brain Energy | `skill(ptr)` — `addDamageIns` **3 ครั้ง ด้วย 1 / 2 / 3 args** = single → blast → AoE ก้อนละ 70%/5 | 212-232 |
| **Enhanced Skill** — Hear Me Out | `enchanceSkill(ptr)` — โครงเดียวกันที่ 80%/5 + **ก้อนดาเมจที่คำนวณจาก stack ถูก `addDamageIns` ข้างใน callback** | 234-282 |
| multiplier ตาม Interpretation (+8%/+4% ต่อ stack) | `DmgSrc(..., 40 + increaseMtpr*8, 5)` / `*4` | 254-258 |
| ทีมมี Erudition ≥ 2 → คูณสอง | `if (ptr->buffCheck["Two_Erudition"] == 1) increaseMtpr *= 2;` | 251-253 |
| Enhanced Skill reset stack เป็น 1 (E1 → 15) | เขียน `debuffCheck["Herta_Stack"]` ตรง ๆ | 261-264 |
| **Ultimate** — Told Ya! | `ultimateList` (`PRIORITY_ACTTACK`) — AoE 200%×3 args | 49-74 |
| Ult multiplier +1% ต่อ Answer (A6) | `act->addDamage(DmgSrcType::ATK, ptr->stack["The_Herta_A6"])` **ใน callback** | 53-54 |
| Ult → ATK +80% 3 เทิร์น | `buffSingle(hertaPtr, {{ATK_P, ..., 80}}, "Ult_The_Herta_Buff", 3)` | 59 |
| Ult → action ทันที + Inspiration +1 | `actionForward(ptr->atvStats.get(), 100)` + `buffNote[...]++` | 55, 64 |
| Ult → จัดเรียง Interpretation ใหม่ | `hertaResetStack()` | 65, 285-295 |
| **Talent** — ต้น wave 25 stack + ศัตรูเข้าฉาก 1 stack | `startGameList` → `applyHertaStack(..., mainEnemyNum, 25)` แล้ววนทุกตัว +1 | 97-105 |
| **A2** — เพื่อนโจมตี → +1 stack, energy | `afterAttackActionList` → วน `act->targetList` `applyHertaStack(..., 1)` + `increaseEnergy` | 122-143 |
| **A4** — Erudition ≥ 2 → CD ทีม +80% | ตรวจใน `resetList` (ตั้ง `buffCheck["Two_Erudition"]`) แล้วบัฟใน `whenOnFieldList` | 84-93, 116-120 |
| A4 — ผู้โจมตีเป็น Erudition → +3 stack | `afterAttackActionList` เช็ค `act->attacker->owner->path` | 127-139 |
| **A6** — Answer cap 99 | `applyHertaStack()` บวก `ptr->stack["The_Herta_A6"]` ทุกครั้งที่ยัด Interpretation | 296-301 |
| **Minor traces** (รวม SPD +5) | `resetList` → `ptr->atvStats->flatSpeed += 5` | 76-79 |
| **Technique** — ATK +60% 2 เทิร์น | `startGameList` → `if (ptr->technique == 1)` | 98-100 |
| **E1** — นับ 50% ของ stack สูงสุดตัวอื่น | ลูปหา `mx` ใน `enchanceSkill` → `increaseMtpr += 0.5*mx` | 242-249 |
| **E2** — Ult ได้ Inspiration เพิ่ม + ESkill advance 35% | `buffNote[...]++` ที่ Ult · `actionForward(..., 35)` ใน `afterAttackActionList` | 56-58, 125 |
| **E4** — Erudition ในทีม SPD +12% | **ไม่มี** | — |
| Interpretation ย้ายเมื่อศัตรูตาย | `enemyDeathList` — **list นี้ไม่เคยถูกยิง** | 145-147 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` → `enchanceSkillCondition()` ก่อน ไม่งั้นดูเศรษฐกิจ skill point | 33-42 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `atv < maxAtv*0.2` = ยังไม่กด (ใกล้ได้เล่นแล้ว อย่าเพิ่งเสีย advance) | 44-47 |
| หมดบัฟ → ถอน | `afterTurnList` + `isBuffEnd` | 107-114 |

## รากฐานที่เพิ่ม

**1. ก้อนดาเมจที่ขึ้นกับสถานะ ณ เวลายิง ต้อง `addDamageIns` ข้างใน callback**
`skill` / `basicAtk` ประกอบดาเมจไว้ก่อน `addToActionBar()` ตามปกติ แต่ `enchanceSkill` เรียก `addDamageIns` **ข้างใน callback** (254-258) เพราะ multiplier ขึ้นกับ Interpretation ณ ตอนที่ถึงคิวจริง ไม่ใช่ตอนสั่ง · เช่นเดียวกับ `act->addDamage(DmgSrcType::ATK, ค่า)` ของ Ult (54) ที่บวก multiplier เข้าก้อนที่ประกอบไว้แล้ว · **นี่คือเส้นแบ่งว่าอะไรต้องอยู่ในหรือนอก callback**

**2. `debuffCheck[ชื่อ]` ใช้เป็นตัวนับได้ ไม่จำเป็นต้องเป็น 0/1**
Interpretation 42 stack เก็บตรง ๆ ใน `enemy->debuffCheck["Herta_Stack"]` · แลกมากับการที่ helper มาตรฐาน (`isDebuffEnd`, `debuffSingle`, `totalDebuff`) ใช้กับมันไม่ได้ ต้องเขียน `applyHertaStack()` / `hertaResetStack()` จัดการเองทั้งหมด

**3. กฎ "ย้าย stack ไปกอง Elite ก่อน" = sort ค่าทั้งหมดแล้วแจกกลับตามลำดับ**
`hertaResetStack()` (285-295) เรียง `debuffCheck["Herta_Stack"]` ของศัตรูทุกตัวจากมากไปน้อยแล้วเขียนกลับตามดัชนี — สมมติว่า `enemyUnit[1]` คือตัวที่สำคัญที่สุดเสมอ · `applyHertaStack()` ก็มี logic overflow: ถ้าเป้าเต็ม 42 แล้วให้ไหลไปตัวแรกที่ยังไม่เต็ม (302-314)

**4. `turnFunc` เข้าถึงเศรษฐกิจ skill point ระดับเกมได้**
`sp > spSafety || spMode == SPMode::POSITIVE` (37) — ตัวแปรกลางที่บอกว่าตอนนี้ทีมมี SP เหลือพอให้กด Skill ไหม · เป็นวิธีมาตรฐานสำหรับตัวละครที่กด Skill ได้แต่ไม่ควรแย่ง SP ตลอด

**5. AI ปรับจูนตามรูปแบบทีมได้ผ่าน `driverType` / `driverNum`**
`enchanceSkillCondition()` (169-198) มีสาขาพิเศษสำหรับ `driverType == DriverType::DOUBLE_TURN` ที่เทียบ `maxAtv` และ `atv` ของ driver กับของตัวเอง เพื่อเลือกว่าจะเก็บ energy ไว้หรือใช้ตอนนี้ — เป็นการ hardcode กลยุทธ์ของทีมรูปแบบหนึ่งลงในไฟล์ตัวละคร

**6. `actionForward(atvStats*, เปอร์เซ็นต์)` = ดัน action bar** ใช้ทั้ง "action ทันทีหลัง ult" (100) และ advance บางส่วนของ E2 (35)

**7. เงื่อนไข "ทีมมี path นี้กี่คน" ตรวจครั้งเดียวที่ `resetList` แล้วเก็บเป็น flag**
`buffCheck["Two_Erudition"]` (90) — คำนวณตอน setup แล้วให้ `whenOnFieldList` และ `enchanceSkill` อ่านซ้ำ ไม่ต้องวน `charUnit` ทุกครั้ง

## แก้เมื่อ 2026-09-23 (user สั่ง)

- **สูตร energy ของ A2 ไม่ตรง kit** — เดิม `energy_gen = act->targetList.size();` แล้ว `if (energy_gen < 9) energy_gen = 9;` คือนับ **1 energy ต่อเป้า** (ไม่คูณ 3) ยกพื้นที่ 9 และไม่มีเพดาน · แก้เป็นสูตรตาม kit:
  ```cpp
  int targetCnt = act->targetList.size();
  if(ptr->buffCheck["Two_Erudition"] == 1 && targetCnt < 3) targetCnt = 3;   // A4
  if(targetCnt > 5) targetCnt = 5;                                            // A2 cap
  increaseEnergy(ptr, 0, 3 * targetCnt);
  ```
  > พื้น 9 ของเดิมคือ "3 เป้า × 3 energy" ที่ถูกคำนวณไว้ล่วงหน้าแล้วลืมคูณกับจำนวนเป้าจริง · ของใหม่ผูกพื้น 3 เป้าไว้กับ `Two_Erudition` ตามที่ kit ระบุว่าเป็นผลของ **A4** ไม่ใช่ของ A2 เอง — ทีมที่ไม่มี Erudition 2 คนจะได้ energy น้อยลงกว่าเดิมอย่างตั้งใจ

## `stackHertaCheck()` — รื้อฟื้นแล้ว 2026-09-23 (user สั่ง)

ฟังก์ชันนี้เคยเป็นโค้ดตาย: คืน `true` เสมอ (`if (temp >= 42) return true;` แล้วตามด้วย `return true;`) และไม่มีใครเรียก — ผู้เรียกเดียวถูกคอมเมนต์ทิ้งไว้ใน `enchanceSkillCondition` · **เจตนาเดิม** คือให้ AI ถาม 2 อย่างก่อนปล่อย Enhanced Skill: SP เหลือพอไหม (`CharCmd::usingSkill`) และ Interpretation ถึงเกณฑ์ที่ A2 ให้ Ice DMG +50% (42 stack) หรือยัง ถ้ายังไม่ถึงให้กด Basic ATK รอ **โดยไม่เสีย Inspiration**

แก้ครบ 4 จุด:

1. `return true` ท้ายฟังก์ชัน → `return false` เกณฑ์ถึงมีความหมาย
2. **การนับ E1 ให้ตรงกับดาเมจจริง** — เดิม `temp += mx` (stack เต็มของตัวสูงสุด) แต่ `enchanceSkill` คำนวณ multiplier ด้วย `0.5*mx` ตาม kit → เปลี่ยนเป็น `temp += 0.5*mx` ไม่งั้นเกณฑ์หลวมกว่าดาเมจที่จะได้จริง
3. **`mx` เริ่มที่ `-1` → `0`** เดิมถ้ามีศัตรูตัวเดียว ลูปข้าม `mainEnemyNum` ทุกตัว `mx` ค้างที่ `-1` แล้วถูกบวกเข้า `temp` ทำให้เกณฑ์เพี้ยน
4. **`temp` / `mx` เป็น `int` → `double`** ไม่งั้น `0.5*mx` ถูกตัดทศนิยมทิ้ง
5. เอาคอมเมนต์ออกจากผู้เรียก

**ผลต่อพฤติกรรม:** เดิม The Herta ปล่อย Enhanced Skill ทันทีที่มี Inspiration ไม่สน SP และไม่สนจำนวน stack · ตอนนี้จะกด Basic ATK รอจนกว่า stack ที่นับได้จะถึง 42 และ SP พอ — **ตัวเลขผลลัพธ์จะเปลี่ยนไปทั้งสองทาง**: เสียดาเมจจากเทิร์นที่ไปกด Basic ATK แต่ได้ Ice DMG +50% จาก A2 ทุกครั้งที่ปล่อย Enhanced Skill และ Enhanced Skill แต่ละครั้งแรงขึ้นเพราะ stack เยอะกว่า · ควร build เทียบก่อน/หลังก่อนสรุปว่าดีขึ้น

> สาขา `DriverType::DOUBLE_TURN` ข้างบน (E2) **ไม่ได้ผ่านเกณฑ์นี้** ยังปล่อย Enhanced Skill ตามตรรกะ energy ของตัวเองเหมือนเดิม

## ส่วนที่ยังไม่มี / ต้องแก้

- **`stackHertaCheck()` เป็นฟังก์ชันตาย** (157-171) — ดูหัวข้อแยกข้างล่าง
- **A2 ส่วน Ice DMG +50% ไม่ได้ผูกเงื่อนไข 42 stack** — `buffSingle(ptr, {{DMG, ..., 50}})` ถูกใส่ทุกครั้งที่ใช้ Enhanced Skill (268) แล้วถอนคืนใน `afterAttackActionList` โดยจับจากชื่อ action `"THerta ESkill"` (123-124) · การถอนคืนถูกต้อง แต่เงื่อนไขการได้บัฟหายไป
- **`afterAttackActionList` ไม่ guard ผู้โจมตี** — ทำงานกับการโจมตีของทุกคนตามเจตนาของ A2 แต่รวมถึงการโจมตีของ The Herta เองและ additional/DoT ทุกก้อน → จำนวน stack และ energy ที่ได้น่าจะสูงกว่าจริง
- **Interpretation ไม่ย้ายเมื่อศัตรูตาย** — โค้ดเขียนไว้แล้วบน `enemyDeathList` (145-147) แต่ยังไม่ได้ตัดสินใจว่า engine ควรยิงเหตุการณ์ศัตรูตายตรงไหน ดู `README.md` หัวข้อ "`enemyDeathList` — ยังไม่มีทางเข้า"
- **E4 (Erudition ในทีม SPD +12%) ยังไม่มี**
- **Inspiration ไม่มีเพดาน 4** `buffNote[...]++` ไม่ clamp (55-58) — ตรงกับ default ของโปรเจกต์ (ดู `README.md` หัวข้อ "cap ของ stack สะสม") แต่ **ยังไม่ได้ถาม user เรื่องตัวนี้โดยเฉพาะ** · ต่างจาก Interpretation (cap 42) และ Answer (cap 99) ที่ clamp อยู่ใน `applyHertaStack()` เพราะ cap เป็นส่วนหนึ่งของกลไก
- **Skill/ESkill กระจายเป้าไม่ตรง kit เป๊ะ** — kit คือ "เป้าหลัก แล้วเป้าหลัก+ข้างเคียง ซ้ำ 2 ครั้ง" แต่โค้ดเป็น single → blast → **AoE** (221-230, 271-280) ก้อนที่สามจึงโดนศัตรูแถวหลังด้วย
