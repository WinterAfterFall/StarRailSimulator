# `src/Defination/Data/Character/Remembrance/Hyacine.h`

kit อ้างอิง: `docs/character-kit-reference/Hyacine.md` · **ฮีลเลอร์สาย memosprite** — รวมระบบฮีล (`Luocha.md`, `Gallagher.md`) เข้ากับ memosprite (`RMC.md`) · มี `//temp` (บรรทัด 5)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(110, 140, 140, E, Wind, Remembrance, "Hyacine", Standard)` | 16 |
| **memosprite "Little Ica"** | `SetMemoStats(ptr, 0, 50, 0, 0, Wind, "Little Ica", Standard)` — **HP/DEF/SPD = 0** | 21 |
| build — **SPD เป็นแกน** | `setSpeedRequire(210)` + main stat หมวก `HEALING_OUT` | 30-31 |
| **Basic ATK** | `Basic_Atk(ptr)` — `DmgSrc(DmgSrcType::HP, 50, 10)` + เรียก `IcaAttack` | 284-293 |
| **Skill** — ฮีลทีม + เรียก Ica | `Skill(ptr)` — `AllyBuffAction` + `addBuffAllAllies()` + `RestoreHP(main, other)` | 294-312 |
| **Memosprite Skill** | `Memo_Skill(ptr)` — AoE ที่สเกลกับ **ยอดฮีลสะสม** `Tally RestoreHP * 0.2` แล้วหักยอดลงครึ่ง | 316-334 |
| **Ultimate** — After Rain | `Ultimate_List` — ฮีลทีม + `buffAllAlly` HP% +30/+600 flat 3 เทิร์น | 55-83 |
| **A2** — เป้าเลือดต่ำกว่าครึ่ง รับฮีล +25% | `BeforeHycHeal()` / `AfterHycHeal()` ครอบทุกการฮีล | 353-373 |
| **A6** — SPD เกิน 200 → Outgoing Healing + HP% | `Start_game_List` + `Stats_Adjust_List` | 104-127, 212-241 |
| **Talent** — ใครเสีย HP → Ica ฮีลตามหลัง | `HPDecrease_List` ตั้ง flag → `AfterAction_List` ทำงานจริง | 169-184, 207-211 |
| **Technique** | `Start_game_List` → ฮีล + `buffAllAlly` HP% +20 2 เทิร์น | 95-103 |
| **Minor traces** | `Reset_List` (มี `CR += 100` ด้วย) | 85-92 |
| **E1** — After Rain → ผู้โจมตีถูกฮีล | `When_attack_List` (ลงทะเบียนเฉพาะเมื่อ E1) | 243-251 |
| **E2** — ใครเสีย HP → SPD +30% 2 เทิร์น | `HPDecrease_List` + `After_turn_List` คู่กัน | 253-265 |
| **E4** — A6 ให้ CD เพิ่มด้วย | `if (ptr->Eidolon >= 4)` ใน A6 ทั้งสองที่ | 122-126, 234-238 |
| **E6** — ทีม RESPEN +20 · Tally หักน้อยลง | `Reset_List` เพิ่ม · `*= 0.88` แทน `*= 0.5` | 267-273, 330-333 |
| AI: เทิร์นตัวละคร | `Turn_func` — SP เหลือพอ หรือ Ica ตาย → Skill ไม่งั้น BA | 36-42 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — ถ้า After Rain ยังอยู่ ให้กดเฉพาะในเทิร์นตัวเอง | 47-54 |

## รากฐาน: ครอบการฮีลด้วยฟังก์ชันคู่ (A2)

```cpp
BeforeHycHeal();                 // ใครเลือดต่ำกว่าครึ่ง -> HEALING_IN +25 (จองด้วย isHaveToAddBuff)
ptr->RestoreHP(...);
AfterHycHeal();                  // ถอนคืนทุกคนที่ถูกจองไว้
```
เป็น **สำนวนเดียวกับ "เพิกเฉย DEF เฉพาะก้อนนี้" ของ `../Nihility/Black Swan.md`** แต่ขยายเป็นหลายเป้าหมาย · เงื่อนไข "เลือดต่ำกว่าครึ่ง" ต้องเช็ค **ก่อน** ฮีล ไม่ใช่หลัง จึงแยกเป็นสองฟังก์ชันแทนการเขียนในที่เดียว · ทุกจุดที่ Hyacine ฮีลต้องครอบด้วยคู่นี้เสมอ (ult / skill / technique / talent)

## รากฐาน: `BeforeAction_List` / `AfterAction_List`

รับ `shared_ptr<ActionData>&` (คลาสแม่ของทั้ง attack และ buff action) → ยิงกับ **action ทุกชนิดรวมถึงของศัตรู** · `act->castToEnemyActionData()` ใช้แยกว่าเป็น action ของศัตรูไหม

Talent ของ Hyacine ใช้คู่นี้ทำ "ฮีลตามหลังความเสียหาย":
1. `BeforeAction_List` ล้าง flag ของทุกคน และถ้าเป็น action ศัตรู → ตั้ง `Ica Talent Trigger`
2. `HPDecrease_List` ตั้ง flag ว่าใครเสีย HP ไปบ้าง
3. `AfterAction_List` ฮีลทุกคน โดยคนที่เสีย HP ได้มากกว่า

## รากฐาน: `healCount` — การกันไม่ให้นับซ้ำในล็อก

```cpp
for (auto &each : allyList) { Icaptr->RestoreHP(each, ...); healCount--; }
AfterHycHeal();
healCount++;
```
`healCount` เป็นตัวนับ global ที่ `RestoreHP` เพิ่มเองทุกครั้ง (`Function/Combat/ChangeHP.h:66`) ใช้กับการพิมพ์ล็อก · การฮีลทีละคนในลูปจะทำให้ตัวเลขพุ่ง จึงหักกลับทีละครั้งแล้วบวกคืนทีเดียวตอนจบ = **นับทั้งลูปเป็นการฮีลครั้งเดียว**

## รากฐาน: ดาเมจที่สเกลกับยอดฮีลสะสม

```cpp
Healing_List: Icaptr->buffNote["Tally RestoreHP"] += Value;    // ทุกครั้งที่ Hyacine/Ica ฮีล
Memo_Skill:   DmgSrc(DmgSrcType::CONST, Tally * 0.2, 10) x3    // แปลงเป็นดาเมจ
              Tally *= 0.5;                                     // (E6: *= 0.88) หักยอดหลังใช้
```
ใช้ **`DmgSrcType::CONST`** เพราะค่าที่ได้เป็นตัวเลขดิบแล้ว ไม่ต้องให้ engine คูณกับ stat ใด · `Healing_List` ยังเพิ่ม `buffStackSingle` DMG +80% (สูงสุด 3 ชั้น) ให้ Ica ทุกครั้งที่ฮีลด้วย

## จุดที่ควรระวัง

- **`Stats_Adjust_List` มีเงื่อนไขที่เป็นเท็จเสมอ** (บรรทัด 216):
  ```cpp
  if(StatsType!=Stats::SPD_P||StatsType!=Stats::FLAT_SPD)return;
  ```
  ใช้ `||` แทน `&&` → ไม่ว่า `StatsType` เป็นอะไรก็ `return` เสมอ (ถ้าเป็น `SPD_P` เงื่อนไขหลังจริง, ถ้าเป็น `FLAT_SPD` เงื่อนไขหน้าจริง, อย่างอื่นจริงทั้งคู่) · **A6 จึงไม่เคยถูกคำนวณใหม่เมื่อ SPD เปลี่ยนระหว่างเกม** เหลือแค่ค่าที่ตั้งครั้งเดียวใน `Start_game_List` · เทียบกับ `RMC.h:89` และ `Aglaea.h:158` ที่ใช้ `==` กับ `||` ถูกต้อง
- **`Reset_List` ใส่ `Stats::CR += 100`** (90) — ไม่ได้อยู่ใน minor traces ของ kit · น่าจะเป็นการบังคับให้ crit เสมอเพื่อความง่าย แต่ไม่มีคอมเมนต์อธิบาย
- **Little Ica ถูกสร้างด้วย HP = 0 และ SPD = 0** (21) แล้ว `Memo_Skill` ปิดท้ายด้วย `resetATV(-1)` (321) ซึ่งเป็นค่าพิเศษ — ต้องดู `resetATV` ประกอบว่า -1 หมายถึงอะไร
- **`HPDecrease_List` ของ E2 ไม่ได้ guard ว่าใครเสีย HP** (254-256) → บัฟ SPD +30% ลงให้ทุก unit ที่เสีย HP รวมถึง Little Ica เอง
- **A6 ถูก copy ทั้งก้อน 2 ที่** (104-127 กับ 216-240) ต่างกันแค่บริบท
- **`Stats::CD` ของ E4 คูณ 2 จาก `healout`** โดยไม่มี cap ขณะที่ `healout = SPD - 200` ไม่มีเพดานเช่นกัน
