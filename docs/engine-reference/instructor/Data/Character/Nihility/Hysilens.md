# `src/Defination/Data/Character/Nihility/Hysilens.h`

kit อ้างอิง: `docs/kit-reference/Character/Nihility/hysilens.md` · **DoT ที่จัดการ 4 ชนิดพร้อมกันเป็นรายชนิด** — ต่างจาก Arcana ของ `Black Swan.md` ที่มัดรวมเป็นก้อนเดียว · อ่าน `Kafka.md` ก่อน

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(102, 110, 110, E, PHYSICAL, NIHILITY, "Hysilens", STANDARD)` | 7 |
| build — EHR เป็นแกน | `setApplyBaseChance(100)` + `setEhrRequire(120)` | 13-14 |
| **Talent** — เลือกชนิด DoT ที่จะลง | lambda `talent(Enemy*)` — ไล่หาชนิดที่ยังไม่มี ถ้าครบแล้วเลือกตัวที่เหลืออายุน้อยสุด | 29-58 |
| **E1** — ลง DoT ชุดที่สอง | lambda `E1(Enemy*)` — โครงเดียวกัน ชื่อ `"Hys E1 *"` | 59-89 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 94-106 |
| **Skill** — AoE + VUL ทุกตัว | lambda `skill` — AoE 140%×3 + `debuffAllEnemyApply(VUL +20, "Hys Vul", 3)` | 108-128 |
| **Ultimate** — Ult state + จุดระเบิด DoT | `ultimateList` — `debuffMark(..., "Hys Ult")` + `dotTrigger(150, each, GENERAL)` | 146-171 |
| Ult state — ศัตรู ATK −15, DEF_SHRED +25 | ใน callback ของ Ult และ `startGameList` | 153-158, 193-199 |
| **A6** — DMG +90% | `whenOnFieldList` (E2 → แจกทั้งทีม) | 179-186 |
| **Talent trigger** — ทุกการโจมตีของทีมลง DoT | `beforeAttackActionList` → `talent(each)` | 248-253 |
| **DoT ต่อเนื่องจาก Ult state** | `afterAttackList` → สร้าง `"Hys Ult Dot"` ตามจำนวน stack (cap 8, E6 → 12) | 255-274 |
| **Technique** | `startGameList` → `TALENT` ×2 (+`E1` ×2 ถ้า E1) | 200-207 |
| **Minor traces** | `resetList` | 173-177 |
| **E1** — DoT ชุดที่สอง + MtprInc[Dot] ทีม | lambda `E1` · `whenOnFieldList` | 59-89, 184-186 |
| **E2** — A6 แจกทั้งทีม | `buffAllAlly({{DMG, 90}})` | 181 |
| **E4** — Ult state ลด RES ด้วย | `if (ptr->eidolon >= 4)` 3 จุด | 157, 198, 243 |
| **E6** — DoT cap 12 · ดาเมจ 100 แทน 80 | `afterAttackList` | 262-268 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — มีศัตรูยังไม่ติด `"Hys Vul"` → Skill ไม่งั้น BA | 131-139 |
| ถอน DoT ทุกชนิด | `afterTurnList` — 9 บล็อก `isDebuffEnd` | 211-232 |

## รากฐาน: เลือกชนิด DoT แบบ "เติมช่องที่ว่างก่อน แล้วค่อยต่ออายุตัวที่จะหมดเร็วสุด"

```cpp
if      (!enemy->getDebuff("Hys Bleed"))     { /* ใช้ BLEED */ }
else if (!enemy->getDebuff("Hys Burn"))      { dotName = "Hys Burn";  dotType = DotType::BURN; }
else if (!enemy->getDebuff("Hys Shock"))     { ... }
else if (!enemy->getDebuff("Hys WindShear")) { ... }
else {                                          // ครบ 4 ชนิดแล้ว -> เลือกตัวที่เหลืออายุน้อยสุด
    if (enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys Burn")) { ... }
    ...
}
dotSingleApply(hys, enemy, {dotType}, dotName, 2);
```
- **`getDebuffTimeCount(ชื่อ)`** = จำนวนเทิร์นที่เหลือของ debuff นั้น · เป็น helper ที่มีที่เดียวในไฟล์นี้
- สาขาสุดท้ายเทียบทีละตัวแบบต่อเนื่อง (ไม่ใช่หา min ด้วยลูป) — ถูกต้องเพราะเปรียบเทียบกับ `dotName` ปัจจุบันที่อัปเดตไปเรื่อย ๆ
- **`TALENT` กับ `E1` เป็นโค้ดเดียวกันทั้งก้อน** ต่างแค่ชื่อ prefix และ**ลำดับการไล่ชนิด** (Talent: Bleed→Burn→Shock→WindShear · E1: Bleed→Shock→Burn→WindShear)

## รากฐาน: `debuffMark` — debuff ที่ต้องถอนเอง

`debuffMark(hys, each, "Hys Ult")` (153) คืน `bool` ว่าลงใหม่ไหม (เหมือน `debuffApply`) แต่**ไม่มีอายุ** → อายุคุมด้วยบัฟชื่อเดียวกันบนตัว Hysilens (`isHaveToAddBuff(hys, "Hys Ult", 3)`) แล้วตอนหมดต้องวน `enemyList` ถอนเองทั้ง stat และ `debuffRemove` (236-246) · สำนวนเดียวกับ `../Harmony/Tribbie.md` และ `../Remembrance/Castorice.md`

## รากฐาน: ตัวนับที่รีเซ็ต "ต่อ action"

```cpp
beforeActionList:   for (i) enemyUnit[i]->setStack("Hys Dot Limit", 0);
beforeTurnList:    for (i) enemyUnit[i]->setStack("Hys Dot Limit", 0);
afterAttackList:    if (each->getStack("Hys Dot Limit") >= 8) break;  each->addStack(..., 1);
```
เพดาน 8 ครั้ง (E6 → 12) **ต่อหนึ่ง action** — ล้างทั้งใน `beforeActionList` (ครอบทุก action รวมของศัตรู) และ `beforeTurnList` · สำนวนเดียวกับ `NetherwingHealLimit` ของ `../Remembrance/Castorice.md`

## จุดที่ควรระวัง

- ~~**`beforeTurnList` ถอน Ult state ด้วย `each->atkPercent -= 15;`**~~ **แก้แล้ว 2026-09-28** ตอนย้ายไปใช้ `ATK_REDUCE`: ลง `+= 15` (154, 195) · ถอน `-= 15` (241) · เดิมถอนแล้วยิ่งลด ATK ศัตรูสะสม
- **`afterAttackList` เรียก `attack(newact)` ข้างในลูป** (271) โดยที่ `newact` ถูกสะสม `addDamageIns` ไปเรื่อย ๆ → **ดาเมจทบต้นตามจำนวนเป้า** อาการเดียวกับ Talent ของ `../Erudition/Serval.md` ที่แก้ไปแล้ว (ดู `Serval.md` หัวข้อ "แก้เมื่อ")
- **`beforeAttackActionList` ลง DoT ทุกการโจมตีของทุกคนโดยไม่ guard** (248-253) → DoT ถูกต่ออายุแทบตลอดเวลา
- **`TALENT` / `E1` มีบล็อก `if(...){}` ว่างเปล่า** เป็นสาขาแรก (32-33, 62-63) — ใช้ค่าเริ่มต้นที่ประกาศไว้ข้างบน ทำงานถูกแต่เขียนแบบนี้ชวนสับสน
- **`ultimateList` เรียก `genSkillPoint(hys,1)` นอก callback** (147) → ได้ SP ตอนสั่ง ไม่ใช่ตอนถึงคิว
- **`setSpeedRequire` และ `turnFunc` ทางเลือกถูกคอมเมนต์ทิ้ง** (15, 137)
- **`whenOnFieldList` ของ A6 แยกสาขาแปลก** (180-181): E2 → `buffAllAlly` ทั้งทีม, ไม่ใช่ E2 → เขียน `statsType` ของตัวเองตรง ๆ · สาขาหลังไม่ยิง `statsAdjust`
