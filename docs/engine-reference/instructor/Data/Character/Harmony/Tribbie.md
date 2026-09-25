# `src/Defination/Data/Character/Harmony/Tribbie.h`

kit อ้างอิง: `docs/character-kit-reference/Tribbie.md` · **ไฟล์อ้างอิงของ True DMG (`Cal_DamageNote`) และ `Char.Print_Func`** · ดาเมจสเกลกับ HP · มี `//temp` (บรรทัด 11)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(96, 120, 120, E, Quantum, Harmony, "Tribbie", Standard)` | 16 |
| **ฟังก์ชันพิมพ์สถานะของตัวเอง** | `ptr->Char.Print_Func = Print_Stats;` | 40 |
| **Basic ATK** | `Basic_Atk(ptr)` — blast `DmgSrcType::HP` 30/15 | 210-223 |
| **Skill** — ทีม RESPEN +24 | `Skill(ptr)` — `buffAllAlly` + `isHaveToAddBuff("Numinosity", 3)` | 225-237 |
| **Ultimate** — Tribbie Zone | `Ultimate_List` — `debuffAllEnemyMark(VUL +30, "Tribbie_Zone")` + AoE 30% HP | 42-92 |
| **A4** — HP ของ Tribbie เพิ่มตาม HP ทั้งทีม | `buffNote["Tribbie_A4"] = ผลรวม calculateHpForBuff(ally, 9)` | 51-56, 177-192 |
| **A2** — FuA แล้วได้ DMG stack | `When_attack_List` → `buffStackSingle(..., 1, 3, "Tribbie_A2", 3)` | 145-147 |
| **Talent** — Additional DMG ขณะ Zone เปิด | `When_attack_List` → `AType::Addtional` 12% HP × จำนวนเป้า | 150-160 |
| Talent — เพื่อนใช้ ult → Tribbie ยิง FuA | `When_attack_List` + flag `Tribbie_ult_launch` (ล้างตอน Tribbie ult) | 161-175, 62-65 |
| energy จากการโจมตีของทีม | `Increase_energy(ptr, 1.5 * targetList.size())` | 148 |
| **Technique / ต้นเกม** | `Start_game_List` — energy 30 + RESPEN ทีม + Numinosity | 135-140 |
| **Minor traces** | `Reset_List` | 94-105 |
| **E1** — True DMG 24% ขณะ Zone เปิด | `BeforeAttackAction_List` + `AfterAttackActionList` + `AfterDealingDamage_List` | 194-207 |
| **E2** — Additional DMG แรงขึ้นและนับเป้า +1 | `14.4 * (temp + 1)` แทน `12 * temp` | 152-156 |
| **E4** — ทีม DEF_SHRED +18 ขณะ Zone | `if (ptr->Eidolon >= 4)` ทั้งตอนเปิดและปิด Zone | 58-60, 115-117 |
| **E6** — FuA DMG +729% + Ult ยิง FuA เอง | `Reset_List` · บล็อกใน Ult | 102-104, 69-83 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — มี `Numinosity` → BA ไม่งั้น Skill | 32-38 |

## รากฐาน: True DMG ด้วย `Cal_DamageNote`

```cpp
BeforeAttackAction_List:  if (Zone เปิด) setBuffCheck("TB_TrueDmg", 1);
AfterDealingDamage_List:  if (!getBuffCheck("TB_TrueDmg")) return;
                          Cal_DamageNote(act, target, enemyUnit[Main_Enemy_num].get(), damage, 24, "TB True " + act->actionName);
AfterAttackActionList:    setBuffCheck("TB_TrueDmg", 0);
```
- **`Cal_DamageNote(act, ต้นทาง, ปลายทาง, ดาเมจที่ออกไป, เปอร์เซ็นต์, ชื่อ)`** — เพิ่มดาเมจที่**ไม่ผ่านสูตรป้องกัน** โดยคิดเป็น % ของดาเมจก้อนที่เพิ่งออก · ตัวที่ 2 กับ 3 แยกกันเพราะดาเมจอาจเกิดที่ศัตรูตัวหนึ่งแต่ลงที่อีกตัว (ที่นี่รวมไปที่ `Main_Enemy_num`)
- **flag ครอบ 3 list** เป็นหน้าต่างอายุ "หนึ่ง action" แบบเดียวกับ `../Elation/YaoGuang.md`
- `../Remembrance/RMC.md` และ `../Destruction/Phainon.md` ใช้ `Cal_DamageNote` เหมือนกัน

## รากฐาน: `Char.Print_Func` — ฟังก์ชันดีบักต่อตัวละคร

`ptr->Char.Print_Func = Print_Stats;` (40) — ผูกฟังก์ชันพิมพ์สถานะเฉพาะตัวเข้ากับ unit เพื่อให้ระบบล็อกเรียกได้ · `Print_Stats` (245-258) พิมพ์ flag และ stack ที่สำคัญของ Tribbie · **เป็นตัวอย่างเดียวในกลุ่มตัวละครที่สำรวจแล้ว** (`../Destruction/Mydei.h` มีฟังก์ชัน `Print` แต่ไม่ได้ผูกเข้ากับ `Char.Print_Func`)

## รากฐาน: `debuffAllEnemyMark` — debuff ที่ไม่มีอายุ

`debuffAllEnemyMark({{VUL, 30}}, ptr, "Tribbie_Zone")` (48) ลงแบบไม่มี duration → อายุถูกคุมด้วย **บัฟชื่อเดียวกันบนตัว Tribbie** (`isHaveToAddBuff(TBptr, "Tribbie_Zone", 2)`) แล้วตอนหมดต้องวน `enemyList` ถอนเองทั้ง `debuffRemove` และ `debuffSingle` ค่าติดลบ (111-114) · สำนวนเดียวกับ `Lost Netherland` ใน `../Remembrance/Castorice.md`

## จุดที่ควรระวัง

- **`Stats_Adjust_List` ของ A4 วนบวก HP ของทุกคนรวมถึง Tribbie เอง** (183-185) — และผลของมันคือ `FLAT_HP` ของ Tribbie → **สูตรป้อนกลับเข้าตัวเอง** · ที่รอดเพราะลงคู่ `TEMP`/`None` และ `calculateHpForBuff` หักช่อง `TEMP` ออก (ดู `../Remembrance/RMC.md`) แต่ **Tribbie คนเดียวที่ถูกหัก คนอื่นไม่มีปัญหาอยู่แล้ว**
- **`When_attack_List` ไม่ guard ผู้โจมตีในส่วน energy และ Additional DMG** (144-160) → ได้ energy 1.5 ต่อเป้าและยิง Additional DMG **ทุกครั้งที่ใครก็ตามโจมตี** รวม DoT/additional ของตัวเอง — ซึ่งตรงกับ kit ของ Zone แต่ควรตรวจว่ารวม additional ของตัวเองด้วยไหม (เสี่ยง recursion: Additional DMG → `When_attack_List` → Additional DMG)
- **`Reset_List` ของ E6 บวก `DMG[AType::Fua] += 729`** (103) — ตัวเลขแปลกและไม่มีคอมเมนต์ว่ามาจากไหน
- **flag `Tribbie_ult_launch` ถูกล้างเฉพาะตอน Tribbie กด ult** (62-65) → ถ้า Tribbie ไม่ได้กด ult เพื่อนแต่ละคนจะ trigger FuA ได้แค่ครั้งเดียวตลอดเกม
- **โค้ดสร้าง FuA ถูก copy 2 ที่** (70-82 ใน Ult E6 และ 164-174 ใน Talent) เหมือนกันทุกบรรทัด
- **`isHaveToAddBuff` ถูกเรียกแบบทิ้งค่าคืน** ใน `Skill` และ `Start_game_List` (140, 236) — ใช้เป็นแค่ "ตั้ง/ต่ออายุบัฟ" ซึ่งได้ผล แต่ชื่อฟังก์ชันสื่อว่าเป็นการถาม
