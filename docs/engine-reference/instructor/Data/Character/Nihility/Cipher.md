# `src/Defination/Data/Character/Nihility/Cipher.h`

kit อ้างอิง: `docs/kit-reference/Character/Nihility/cipher.md` · **ไฟล์ที่ใช้ True DMG (`calDamageNote`) หนักที่สุดในโปรเจกต์** — ดาเมจหลักของตัวละครนี้คือ True DMG ที่แปะจากดาเมจของทั้งทีม

## `adjust` ที่ต้องตั้งจากข้างนอก

| key | ค่าเริ่มต้น | ความหมาย |
|---|---|---|
| `"Cipher A2"` | 2 | จำนวนชั้นของ A2 → CR `25 × ค่านี้` และตัวคูณ True DMG `(1 + 0.5 × ค่านี้)` |
| `"Cipher Ult Share"` | 1 | จำนวนศัตรูที่ True DMG 75% ถูกกระจายให้ |
| `"Cipher Use Only BA"` | 1 | บังคับให้ AI ใช้แต่ BA |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(105, 130, 130, E, QUANTUM, NIHILITY, "Cipher", STANDARD)` | 7 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 34-46 |
| **Skill** — Weaken + ATK ตัวเอง | lambda `skill` — blast 200/100 + `dmgPercent -= 10` + ATK +30% | 47-66 |
| **Ultimate** | `ultimateList` — 120% single + AoE 40%×3 | 74-90 |
| **Talent** — เพื่อนโจมตี → Cipher ยิง FuA | `beforeAttackActionList` + flag `Cipher FUA` (รีเซ็ตต้นเทิร์นตัวเอง) | 155-177, 108-110 |
| FuA — คริติคอลแรงขึ้นชั่วคราว | `buffSingle(CD +100)` ครอบ `attack` | 165-171 |
| **A2** — CR ตามจำนวนชั้น | `resetList` → `CR += 25 * getAdjust("Cipher A2")` | 96 |
| **A6** — ศัตรู VUL +40 ถาวร | `debuffAllEnemyMark({{VUL, 40}}, ptr, "Cipher A6")` | 102 |
| **True DMG หลัก** | `afterDealingDamageList` → `calDamageNote` สองก้อน (75% กระจาย / 25% เป้าหลัก) | 181-216 |
| **Patron** — mark บนเป้าหลักจาก Skill/Ult | `beforeAttackActionList` → `debuffApply(cph, enemyUnit[mainEnemyNum], "Patron")` | 152-153 |
| **Technique** | `startGameList` — AoE 100%×3 (**ไม่เช็ค `ptr->technique`**) | 132-145 |
| **Minor traces** | `resetList` | 92-106 |
| **E1** — FuA ให้ ATK +80% · True DMG ×1.5 | `buffSingle(..., "Cipher E1", 2)` · `percent *= 1.5` | 163-164, 190 |
| **E2** — VUL +30 จากทุกการโจมตี · base chance 120 | `beforeAttackActionList` · `setApplyBaseChance(120)` | 147-151, 19-20 |
| **E4** — เป้าที่มี Patron → Additional DMG | `whenAttackList` (ลงทะเบียนเฉพาะเมื่อ E4) | 219-231 |
| **E6** — FuA แรงขึ้น + สะสมดาเมจแล้วระเบิดตอน Ult | `percent += 16*(...)` · บล็อกใหญ่ใน `afterDealingDamageList` | 186-188, 198-215 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — `CharCmd::usingSkill(ptr)` และไม่ได้บังคับ BA → Skill | 69-72 |

## รากฐาน: True DMG ที่กระจายหลายเป้า

```cpp
double percent = (target->targetType == EnemyType::MAIN)
               ? (12 * (1 + 0.5 * adjust["Cipher A2"]))
               : ( 8 * (1 + 0.5 * adjust["Cipher A2"]));
...
for (int i = 1; i <= getAdjust("Cipher Ult Share") && i <= totalEnemy; i++)
    calDamageNote(act, target, enemyUnit[i].get(), damage*percent/100, 75.0/getAdjust("Cipher Ult Share"), "...");
calDamageNote(act, target, enemyUnit[mainEnemyNum].get(), damage*percent/100, 25, "...");
```
- **`calDamageNote(act, ต้นทาง, ปลายทาง, ฐานดาเมจ, เปอร์เซ็นต์, ชื่อ)`** — ที่นี่ใช้ทั้ง 6 พารามิเตอร์เต็มที่: ฐานดาเมจคือ `damage*percent/100` (ส่วนแบ่งจากดาเมจที่เพิ่งออก) แล้วคูณเปอร์เซ็นต์อีกชั้น
- **แบ่ง 75/25**: 75% กระจายให้ศัตรูตามจำนวน `Cipher ULT Share` (หารเท่ากัน) · 25% ลงเป้าหลักเสมอ
- **ไม่ guard ผู้โจมตี** → ดาเมจของ **ทุกคนในทีม** ถูกแปลงเป็น True DMG ของ Cipher ซึ่งตรงกับ kit

## รากฐาน: E6 — สะสมดาเมจไว้ระเบิดทีเดียว

```cpp
act->attacker->owner->buffNote["CipherNote" + target->getName()] += damage * percent/100 * 0.2;
if (act->actionName != "Cipher Ult") return;
// ตอน ULT: วนทุก ally × ทุกศัตรู แล้วปล่อยยอดสะสมออกเป็น True DMG
act->attacker = charUnit[i].get();        // <- เปลี่ยนผู้กระทำของ action กลางคัน
calDamageNote(act, enemyUnit[j].get(), enemyUnit[k].get(), totaldmg*0.75/..., 100, "...");
charUnit[i]->buffNote["CipherNote" + ...] *= 0.2;   // เหลือไว้ 20%
```
- **`buffNote` ที่ key ผูกกับชื่อศัตรู** (`"CipherNote" + target->getName()`) — เก็บยอดสะสมแยกรายคู่ (ally × enemy) · เป็นวิธีจำลอง 2-มิติบน map 1 มิติ
- **เขียน `act->attacker` ทับกลางลูป** (207) เพื่อให้ `calDamageNote` คิดว่าเป็นดาเมจของ ally คนนั้น — **แก้ object ที่ยืมมาจาก callback** ซึ่งอันตราย (ดูจุดที่ควรระวัง)

## จุดที่ควรระวัง

- **`act->attacker` ถูกเขียนทับใน `afterDealingDamageList` แล้วไม่คืนค่า** (207) — `act` เป็น action ที่เพิ่งยิงจบ ถ้ามี trigger อื่นอ่าน `attacker` ต่อจากนี้จะได้คนผิด · ควร copy action หรือเก็บค่าเดิมไว้คืน
- **Technique ไม่เช็ค `ptr->technique`** (132-145) → ยิง AoE 100%×3 ต้นเกมเสมอไม่ว่าจะเปิด technique หรือไม่ · ทุกตัวละครอื่นเช็ค
- **`turnFunc` ขึ้นกับ `adjust["Cipher Use Only BA"]` ที่ตั้งเป็น 1 ตายตัว** (31) → Cipher ไม่เคยใช้ Skill เลยเว้นแต่มีใครแก้ `adjust` จากข้างนอก · แปลว่า `Patron` ก็ติดได้เฉพาะจาก Ult
- **`resetList` มี 3 บรรทัดถูกคอมเมนต์ทิ้ง** (98-100) ซึ่งเป็นค่า trace อีกชุด — ไม่ชัดว่าชุดไหนถูก
- **FuA ใช้ `buffSingle(CD +100)` / `(DMG +350)` ครอบ `attack`** (168-172) — สำนวนปกติ แต่ค่า 350 ของ E6 ใหญ่ผิดสังเกตและไม่มีคอมเมนต์
- **`afterDealingDamageList` ยิงกับดาเมจทุกก้อนรวมถึง True DMG ที่ตัวเองสร้าง** — ถ้า `calDamageNote` ยิง event นี้ซ้ำจะ recursion · ตอนนี้ไม่เห็นตัวกัน ต้องตรวจที่ `calDamageNote`
- **E6 วน `totalAlly × totalEnemy × Cipher ULT Share`** ทุกครั้งที่ Ult ยิงดาเมจ (ซึ่งมีหลายก้อน) → ต้นทุนสูงและอาจนับซ้ำต่อก้อนดาเมจ
