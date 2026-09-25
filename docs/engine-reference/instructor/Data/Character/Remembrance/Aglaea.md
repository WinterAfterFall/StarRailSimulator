# `src/Defination/Data/Character/Remembrance/Aglaea.h`

kit อ้างอิง: `docs/kit-reference/Character/Aglaea.md` · **ไฟล์อ้างอิงของ countdown unit และ joint attack** · อ่าน `RMC.md` ก่อนสำหรับพื้นฐาน memosprite · มี `//temp` (บรรทัด 6)

## unit ที่ไฟล์นี้สร้าง 3 ตัว

| unit | สร้างด้วย | บทบาท |
|---|---|---|
| Aglaea (ตัวละคร) | `SetCharBasicStats(102, 350, 350, ...)` — **energy ult 350** | ตัวหลัก |
| Garmentmaker (memosprite) | `SetMemoStats(ptr, 720, 66, 0, 35, Lightning, "Garmentmaker", ...)` | โจมตีเอง มีเทิร์นของตัวเอง |
| Supreme_Stance (countdown) | `SetCountdownStats(ptr, 100, "Supreme_Stance")` | **นับถอยหลังจบสถานะอัลติ** |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| **Basic ATK** | `Basic_Atk(ptr)` — single 100%/10 | 224-237 |
| **Enhanced BA** — joint attack กับ Garmentmaker | `Enchance_Basic_Atk(ptr)` — blast 200/90 **สองชุด** + `setJoint()` + `switchAttacker` | 204-223 |
| **Skill** — เรียก Garmentmaker | `Skill(ptr)` — `AllyBuffAction` + `addActionType(AType::Summon)` → `Summon(ptr)` + `act->Turn_reset = false` | 238-252 |
| **Memosprite Skill** | `Memo_Skill(ptr)` — blast 110/65 + `addAttackType(AType::Summon)` | 260-273 |
| **Ultimate** — เข้าสถานะ Supreme Stance | `Ultimate_List` — `AllyBuffAction` ไม่มีดาเมจ · เรียก Garmentmaker ถ้าตาย · `countdownList[0]->summon()` · advance ตัวเอง 100% | 57-80 |
| **A2** — ATK ตาม SPD ของทั้งคู่ | `calculateSpeedForBuff(ptr, 360) + calculateSpeedForBuff(Garmentmaker, 720)` → `FLAT_ATK` | 69-74, 160-165 |
| A2 คำนวณใหม่เมื่อ SPD เปลี่ยน | `Stats_Adjust_List` (guard `FLAT_SPD` / `SPD_P` และต้องอยู่ในสถานะอัลติ) | 155-168 |
| **Talent** — Brewed by Tears | `When_attack_List` — Garmentmaker โจมตี → SPD +55 flat (สูงสุด 6 stack) | 107-116 |
| Talent — ขณะอัลติ stack ยังให้ Aglaea SPD +15% ต่อชั้น | `if (!countdownList[0]->isDeath()) buffSingle(AGptr, SPD_P +15)` | 112-114 |
| Seam Stitch (debuff บนเป้าหลัก) | `When_attack_List` → `debuffApply(ptr, enemyUnit[Main_Enemy_num], "Seam_Stitch")` | 117-123 |
| Additional DMG เมื่อ Aglaea โจมตี | `When_attack_List` → `AType::Addtional` 30% | 124-132 |
| **Technique** | `Start_game_List` — AoE 100%×3 + energy 30 + เรียก memosprite | 88-105 |
| **Minor traces** | `Reset_List` | 82-86 |
| **E1** — Seam Stitch → VUL +15 · Additional DMG → energy 20 | `if (ptr->Eidolon >= 1)` 2 จุดใน `When_attack_List` | 119-121, 129-131 |
| **E2** — DEF_SHRED ซ้อนได้ 3 ชั้น | `BeforeAttackAction_List` + `Buff_List` → `buffStackChar` / `buffCharResetStack` | 135-153 |
| AI: เทิร์นตัวละคร | `Turn_func` — memosprite ตาย → Skill · ไม่อยู่ในสถานะอัลติ → BA · อยู่ → Enhanced BA | 37-48 |
| AI: เทิร์น memosprite | `Memo_Skill` เสมอ | 171-175 |
| **จบสถานะอัลติ** | `countdownList[0]->Turn_func` — ถอนบัฟทั้งหมดแล้วฆ่าทั้ง countdown และ memosprite | 177-196 |

## รากฐาน: countdown unit

`SetCountdownStats(ptr, SPD, ชื่อ)` สร้าง unit ที่ **มีเทิร์นเหมือน unit อื่นแต่ไม่โจมตี** — ใช้เป็นนาฬิกาจับเวลาสถานะที่กินหลายเทิร์น

- เริ่มสถานะ: `ptr->countdownList[0]->summon()` (68)
- เช็คว่าอยู่ในสถานะไหม: `ptr->countdownList[0]->isDeath()` — **ตาย = ไม่อยู่ในสถานะ**
- จบสถานะ: ใส่โค้ดทำความสะอาดทั้งหมดไว้ใน `countdownList[0]->Turn_func` แล้วปิดท้ายด้วย `death()` (177-196)

**เป็นทางเลือกแทนการนับเทิร์นด้วย `buffEnd`** เมื่อสถานะนั้นซับซ้อนเกินกว่าจะถอนด้วย `isBuffEnd` ก้อนเดียว · `Turn_func` ของ countdown ที่นี่ถอน 4 อย่าง: SPD% ของ Aglaea, FLAT_ATK จาก A2 (ทั้ง `TEMP` และ `None`), SPD flat ของ Garmentmaker, และ reset stack

> summon/countdown เป็นระบบเก่าที่มีแผน refactor ให้เหลือแค่ `ActionValueStats` — ดู `future-improvements.md` ข้อ 4

## รากฐาน: joint attack

```cpp
act->setJoint();
act->switchAttacker.push_back(SwitchAtk(1,1));
```
`Enchance_Basic_Atk` ใส่ `addDamageIns` **สองชุด** (ชุดละ blast 200/90) แล้ว `setJoint()` + `switchAttacker` บอกว่าชุดที่ 2 เป็นของ **Garmentmaker** ไม่ใช่ Aglaea → ดาเมจชุดหลังสเกลกับ ATK ของ memosprite

## รากฐาน: A2 — สูตรที่อ้างอิง SPD ของสอง unit

```cpp
double BuffValue = calculateSpeedForBuff(ptr, 360) + calculateSpeedForBuff(Garmentmaker, 720);
buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP,  BuffValue - buffNote["Aglaea_A2"]}});
buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::None,  BuffValue - buffNote["Aglaea_A2"]}});
ptr->buffNote["Aglaea_A2"] = BuffValue;
```
สำนวน **delta + `buffNote` + คู่ `TEMP`/`None`** เดียวกับ Talent ของ `RMC.md` — ที่นี่ `TEMP` ไม่ได้กันลูปกับตัวเอง (ATK ไม่ป้อนกลับเข้า SPD) แต่ใช้เป็นบันทึกว่า ATK ก้อนนี้มาจากบัฟที่คำนวณเอง

โค้ดก้อนเดียวกันถูก copy ไว้ **3 ที่**: ตอนกดอัลติ (69-74), ตอน SPD เปลี่ยน (160-165), และตอนถอนใน countdown (182-185)

## รากฐาน: `buffStackChar` / `buffCharResetStack`

E2 ต้องการ "สะสมเมื่อ Aglaea หรือ Garmentmaker ทำ action, **ล้างทั้งกอง** เมื่อคนอื่นทำ" → `buffStackChar(ptr, {stat}, เพิ่ม, cap, ชื่อ)` กับ `buffCharResetStack(ptr, {stat}, ชื่อ)` · เป็นคู่เดียวกับ `buffStackSingle` / `buffResetStack` แต่ลงถึง memosprite ด้วย (ตระกูล `...Char`)

**ลงทะเบียนไว้ 2 list ที่มีเนื้อหาเหมือนกันเป๊ะ** (135-153) — `BeforeAttackAction_List` สำหรับ action โจมตี และ `Buff_List` สำหรับ action บัฟ เพราะ "ใครทำ action" ต้องนับทั้งสองแบบ

## จุดที่ควรระวัง

- **`act->Turn_reset = false`** ใน Skill (246) — ตั้งเฉพาะตอนที่เรียก memosprite จริง ๆ ทำให้เทิร์นไม่ถูกรีเซ็ต · เป็นฟิลด์ที่ไม่มีใครใช้ที่อื่นในโปรเจกต์ ต้องดู `AllyActionData` ประกอบ
- **`setSpeedRequire` ถูกคอมเมนต์ทิ้ง** (29) → Aglaea ไม่มีเกณฑ์ SPD ทั้งที่ทั้ง A2 และ Talent สเกลกับ SPD โดยตรง
- **`countdownList[0]->Turn_func` ถอน SPD ของ Garmentmaker ด้วย `temp = stack - 1`** (187-192) คือเหลือไว้ 1 ชั้นโดยตั้งใจ แล้วตั้ง stack กลับเป็น 1 — ตรงกับ kit ที่ Garmentmaker เก็บ stack แรกไว้ แต่ต้องระวังถ้า stack เป็น 0 อยู่แล้ว
- **`addUltCondition` ซับซ้อนและอ่านยาก** (49-55) มีทั้งการเทียบ `atv` ของ countdown กับของตัวเอง และเช็ค `atv == 0` ของ memosprite
- **`When_attack_List` ไม่ guard ว่าใครโจมตีในก้อนที่ 3** (124) ใช้ `act->Attacker->Atv_stats->num == ptr->Atv_stats->num` ซึ่งเทียบเลขช่อง ไม่ใช่ชื่อ — ถ้า memosprite ใช้เลขช่องเดียวกับเจ้าของ Additional DMG จะยิงตอน Garmentmaker โจมตีด้วย
