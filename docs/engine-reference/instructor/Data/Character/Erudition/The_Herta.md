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
| ธาตุ / path / energy ult (220) | `SetCharBasicStats(99, 220, 220, E, ElementType::Ice, Path::Erudition, "The_Herta", UnitType::Standard)` | 16 |
| Base HP/ATK/DEF | `SetAllyBaseStats(1164, 679, 485)` | 18 |
| **Basic ATK** | `Basic_Atk(ptr)` — single 100%/10 | 200-210 |
| **Skill** — Big Brain Energy | `Skill(ptr)` — `addDamageIns` **3 ครั้ง ด้วย 1 / 2 / 3 args** = single → blast → AoE ก้อนละ 70%/5 | 212-232 |
| **Enhanced Skill** — Hear Me Out | `Enchance_Skill(ptr)` — โครงเดียวกันที่ 80%/5 + **ก้อนดาเมจที่คำนวณจาก stack ถูก `addDamageIns` ข้างใน callback** | 234-282 |
| multiplier ตาม Interpretation (+8%/+4% ต่อ stack) | `DmgSrc(..., 40 + Increase_mtpr*8, 5)` / `*4` | 254-258 |
| ทีมมี Erudition ≥ 2 → คูณสอง | `if (ptr->buffCheck["Two_Erudition"] == 1) Increase_mtpr *= 2;` | 251-253 |
| Enhanced Skill reset stack เป็น 1 (E1 → 15) | เขียน `debuffCheck["Herta_Stack"]` ตรง ๆ | 261-264 |
| **Ultimate** — Told Ya! | `Ultimate_List` (`PRIORITY_ACTTACK`) — AoE 200%×3 args | 49-74 |
| Ult multiplier +1% ต่อ Answer (A6) | `act->addDamage(DmgSrcType::ATK, ptr->stack["The_Herta_A6"])` **ใน callback** | 53-54 |
| Ult → ATK +80% 3 เทิร์น | `buffSingle(Hertaptr, {{ATK_P, ..., 80}}, "Ult_The_Herta_Buff", 3)` | 59 |
| Ult → action ทันที + Inspiration +1 | `Action_forward(ptr->Atv_stats.get(), 100)` + `buffNote[...]++` | 55, 64 |
| Ult → จัดเรียง Interpretation ใหม่ | `Herta_reset_Stack()` | 65, 285-295 |
| **Talent** — ต้น wave 25 stack + ศัตรูเข้าฉาก 1 stack | `Start_game_List` → `Apply_Herta_Stack(..., Main_Enemy_num, 25)` แล้ววนทุกตัว +1 | 97-105 |
| **A2** — เพื่อนโจมตี → +1 stack, energy | `AfterAttackActionList` → วน `act->targetList` `Apply_Herta_Stack(..., 1)` + `Increase_energy` | 122-143 |
| **A4** — Erudition ≥ 2 → CD ทีม +80% | ตรวจใน `Reset_List` (ตั้ง `buffCheck["Two_Erudition"]`) แล้วบัฟใน `WhenOnField_List` | 84-93, 116-120 |
| A4 — ผู้โจมตีเป็น Erudition → +3 stack | `AfterAttackActionList` เช็ค `act->Attacker->owner->path` | 127-139 |
| **A6** — Answer cap 99 | `Apply_Herta_Stack()` บวก `ptr->stack["The_Herta_A6"]` ทุกครั้งที่ยัด Interpretation | 296-301 |
| **Minor traces** (รวม SPD +5) | `Reset_List` → `ptr->Atv_stats->flatSpeed += 5` | 76-79 |
| **Technique** — ATK +60% 2 เทิร์น | `Start_game_List` → `if (ptr->Technique == 1)` | 98-100 |
| **E1** — นับ 50% ของ stack สูงสุดตัวอื่น | ลูปหา `mx` ใน `Enchance_Skill` → `Increase_mtpr += 0.5*mx` | 242-249 |
| **E2** — Ult ได้ Inspiration เพิ่ม + ESkill advance 35% | `buffNote[...]++` ที่ Ult · `Action_forward(..., 35)` ใน `AfterAttackActionList` | 56-58, 125 |
| **E4** — Erudition ในทีม SPD +12% | **ไม่มี** | — |
| Interpretation ย้ายเมื่อศัตรูตาย | `Enemy_Death_List` — **list นี้ไม่เคยถูกยิง** | 145-147 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` → `Enchance_Skill_Condition()` ก่อน ไม่งั้นดูเศรษฐกิจ skill point | 33-42 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `atv < Max_atv*0.2` = ยังไม่กด (ใกล้ได้เล่นแล้ว อย่าเพิ่งเสีย advance) | 44-47 |
| หมดบัฟ → ถอน | `After_turn_List` + `isBuffEnd` | 107-114 |

## รากฐานที่เพิ่ม

**1. ก้อนดาเมจที่ขึ้นกับสถานะ ณ เวลายิง ต้อง `addDamageIns` ข้างใน callback**
`Skill` / `Basic_Atk` ประกอบดาเมจไว้ก่อน `addToActionBar()` ตามปกติ แต่ `Enchance_Skill` เรียก `addDamageIns` **ข้างใน callback** (254-258) เพราะ multiplier ขึ้นกับ Interpretation ณ ตอนที่ถึงคิวจริง ไม่ใช่ตอนสั่ง · เช่นเดียวกับ `act->addDamage(DmgSrcType::ATK, ค่า)` ของ Ult (54) ที่บวก multiplier เข้าก้อนที่ประกอบไว้แล้ว · **นี่คือเส้นแบ่งว่าอะไรต้องอยู่ในหรือนอก callback**

**2. `debuffCheck[ชื่อ]` ใช้เป็นตัวนับได้ ไม่จำเป็นต้องเป็น 0/1**
Interpretation 42 stack เก็บตรง ๆ ใน `enemy->debuffCheck["Herta_Stack"]` · แลกมากับการที่ helper มาตรฐาน (`isDebuffEnd`, `debuffSingle`, `Total_debuff`) ใช้กับมันไม่ได้ ต้องเขียน `Apply_Herta_Stack()` / `Herta_reset_Stack()` จัดการเองทั้งหมด

**3. กฎ "ย้าย stack ไปกอง Elite ก่อน" = sort ค่าทั้งหมดแล้วแจกกลับตามลำดับ**
`Herta_reset_Stack()` (285-295) เรียง `debuffCheck["Herta_Stack"]` ของศัตรูทุกตัวจากมากไปน้อยแล้วเขียนกลับตามดัชนี — สมมติว่า `enemyUnit[1]` คือตัวที่สำคัญที่สุดเสมอ · `Apply_Herta_Stack()` ก็มี logic overflow: ถ้าเป้าเต็ม 42 แล้วให้ไหลไปตัวแรกที่ยังไม่เต็ม (302-314)

**4. `Turn_func` เข้าถึงเศรษฐกิจ skill point ระดับเกมได้**
`sp > Sp_Safety || spMode == SPMode::Positive` (37) — ตัวแปรกลางที่บอกว่าตอนนี้ทีมมี SP เหลือพอให้กด Skill ไหม · เป็นวิธีมาตรฐานสำหรับตัวละครที่กด Skill ได้แต่ไม่ควรแย่ง SP ตลอด

**5. AI ปรับจูนตามรูปแบบทีมได้ผ่าน `driverType` / `Driver_num`**
`Enchance_Skill_Condition()` (169-198) มีสาขาพิเศษสำหรับ `driverType == DriverType::DoubleTurn` ที่เทียบ `Max_atv` และ `atv` ของ driver กับของตัวเอง เพื่อเลือกว่าจะเก็บ energy ไว้หรือใช้ตอนนี้ — เป็นการ hardcode กลยุทธ์ของทีมรูปแบบหนึ่งลงในไฟล์ตัวละคร

**6. `Action_forward(Atv_stats*, เปอร์เซ็นต์)` = ดัน action bar** ใช้ทั้ง "action ทันทีหลัง ult" (100) และ advance บางส่วนของ E2 (35)

**7. เงื่อนไข "ทีมมี path นี้กี่คน" ตรวจครั้งเดียวที่ `Reset_List` แล้วเก็บเป็น flag**
`buffCheck["Two_Erudition"]` (90) — คำนวณตอน setup แล้วให้ `WhenOnField_List` และ `Enchance_Skill` อ่านซ้ำ ไม่ต้องวน `charUnit` ทุกครั้ง

## แก้เมื่อ 2026-09-23 (user สั่ง)

- **สูตร energy ของ A2 ไม่ตรง kit** — เดิม `energy_gen = act->targetList.size();` แล้ว `if (energy_gen < 9) energy_gen = 9;` คือนับ **1 energy ต่อเป้า** (ไม่คูณ 3) ยกพื้นที่ 9 และไม่มีเพดาน · แก้เป็นสูตรตาม kit:
  ```cpp
  int targetCnt = act->targetList.size();
  if(ptr->buffCheck["Two_Erudition"] == 1 && targetCnt < 3) targetCnt = 3;   // A4
  if(targetCnt > 5) targetCnt = 5;                                            // A2 cap
  Increase_energy(ptr, 0, 3 * targetCnt);
  ```
  > พื้น 9 ของเดิมคือ "3 เป้า × 3 energy" ที่ถูกคำนวณไว้ล่วงหน้าแล้วลืมคูณกับจำนวนเป้าจริง · ของใหม่ผูกพื้น 3 เป้าไว้กับ `Two_Erudition` ตามที่ kit ระบุว่าเป็นผลของ **A4** ไม่ใช่ของ A2 เอง — ทีมที่ไม่มี Erudition 2 คนจะได้ energy น้อยลงกว่าเดิมอย่างตั้งใจ

## `Stack_Herta_Check()` — รื้อฟื้นแล้ว 2026-09-23 (user สั่ง)

ฟังก์ชันนี้เคยเป็นโค้ดตาย: คืน `true` เสมอ (`if (temp >= 42) return true;` แล้วตามด้วย `return true;`) และไม่มีใครเรียก — ผู้เรียกเดียวถูกคอมเมนต์ทิ้งไว้ใน `Enchance_Skill_Condition` · **เจตนาเดิม** คือให้ AI ถาม 2 อย่างก่อนปล่อย Enhanced Skill: SP เหลือพอไหม (`CharCmd::Using_Skill`) และ Interpretation ถึงเกณฑ์ที่ A2 ให้ Ice DMG +50% (42 stack) หรือยัง ถ้ายังไม่ถึงให้กด Basic ATK รอ **โดยไม่เสีย Inspiration**

แก้ครบ 4 จุด:

1. `return true` ท้ายฟังก์ชัน → `return false` เกณฑ์ถึงมีความหมาย
2. **การนับ E1 ให้ตรงกับดาเมจจริง** — เดิม `temp += mx` (stack เต็มของตัวสูงสุด) แต่ `Enchance_Skill` คำนวณ multiplier ด้วย `0.5*mx` ตาม kit → เปลี่ยนเป็น `temp += 0.5*mx` ไม่งั้นเกณฑ์หลวมกว่าดาเมจที่จะได้จริง
3. **`mx` เริ่มที่ `-1` → `0`** เดิมถ้ามีศัตรูตัวเดียว ลูปข้าม `Main_Enemy_num` ทุกตัว `mx` ค้างที่ `-1` แล้วถูกบวกเข้า `temp` ทำให้เกณฑ์เพี้ยน
4. **`temp` / `mx` เป็น `int` → `double`** ไม่งั้น `0.5*mx` ถูกตัดทศนิยมทิ้ง
5. เอาคอมเมนต์ออกจากผู้เรียก

**ผลต่อพฤติกรรม:** เดิม The Herta ปล่อย Enhanced Skill ทันทีที่มี Inspiration ไม่สน SP และไม่สนจำนวน stack · ตอนนี้จะกด Basic ATK รอจนกว่า stack ที่นับได้จะถึง 42 และ SP พอ — **ตัวเลขผลลัพธ์จะเปลี่ยนไปทั้งสองทาง**: เสียดาเมจจากเทิร์นที่ไปกด Basic ATK แต่ได้ Ice DMG +50% จาก A2 ทุกครั้งที่ปล่อย Enhanced Skill และ Enhanced Skill แต่ละครั้งแรงขึ้นเพราะ stack เยอะกว่า · ควร build เทียบก่อน/หลังก่อนสรุปว่าดีขึ้น

> สาขา `DriverType::DoubleTurn` ข้างบน (E2) **ไม่ได้ผ่านเกณฑ์นี้** ยังปล่อย Enhanced Skill ตามตรรกะ energy ของตัวเองเหมือนเดิม

## ส่วนที่ยังไม่มี / ต้องแก้

- **`Stack_Herta_Check()` เป็นฟังก์ชันตาย** (157-171) — ดูหัวข้อแยกข้างล่าง
- **A2 ส่วน Ice DMG +50% ไม่ได้ผูกเงื่อนไข 42 stack** — `buffSingle(ptr, {{DMG, ..., 50}})` ถูกใส่ทุกครั้งที่ใช้ Enhanced Skill (268) แล้วถอนคืนใน `AfterAttackActionList` โดยจับจากชื่อ action `"THerta ESkill"` (123-124) · การถอนคืนถูกต้อง แต่เงื่อนไขการได้บัฟหายไป
- **`AfterAttackActionList` ไม่ guard ผู้โจมตี** — ทำงานกับการโจมตีของทุกคนตามเจตนาของ A2 แต่รวมถึงการโจมตีของ The Herta เองและ additional/DoT ทุกก้อน → จำนวน stack และ energy ที่ได้น่าจะสูงกว่าจริง
- **Interpretation ไม่ย้ายเมื่อศัตรูตาย** — โค้ดเขียนไว้แล้วบน `Enemy_Death_List` (145-147) แต่ยังไม่ได้ตัดสินใจว่า engine ควรยิงเหตุการณ์ศัตรูตายตรงไหน ดู `README.md` หัวข้อ "`Enemy_Death_List` — ยังไม่มีทางเข้า"
- **E4 (Erudition ในทีม SPD +12%) ยังไม่มี**
- **Inspiration ไม่มีเพดาน 4** `buffNote[...]++` ไม่ clamp (55-58) — ตรงกับ default ของโปรเจกต์ (ดู `README.md` หัวข้อ "cap ของ stack สะสม") แต่ **ยังไม่ได้ถาม user เรื่องตัวนี้โดยเฉพาะ** · ต่างจาก Interpretation (cap 42) และ Answer (cap 99) ที่ clamp อยู่ใน `Apply_Herta_Stack()` เพราะ cap เป็นส่วนหนึ่งของกลไก
- **Skill/ESkill กระจายเป้าไม่ตรง kit เป๊ะ** — kit คือ "เป้าหลัก แล้วเป้าหลัก+ข้างเคียง ซ้ำ 2 ครั้ง" แต่โค้ดเป็น single → blast → **AoE** (221-230, 271-280) ก้อนที่สามจึงโดนศัตรูแถวหลังด้วย
