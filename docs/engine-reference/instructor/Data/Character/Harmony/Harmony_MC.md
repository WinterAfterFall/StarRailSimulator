# `src/Defination/Data/Character/Harmony/Harmony_MC.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/trailblazer-harmony.md` · namespace `HarmonyMC` · **ซัพพอร์ต Super Break** — เป็นแหล่ง Super Break ให้ทั้งทีม ไม่ใช่แค่ตัวเอง (ต่างจาก `../Destruction/FireFly.md` และ `../Erudition/Rappa.md`)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(105, 140, 140, E, IMAGINARY, HARMONY, "Harmony_MC", STANDARD)` | 10 |
| **Basic ATK** | `basicAtk(ptr)` — single 110%/10 | 111-121 |
| **Skill** | `skillFunc(ptr)` — `TraceType::BOUNCE` + `addEnemyBounce(55/5, 6)` | 122-133 |
| **Ultimate** — ทีม BE +33% 3 เทิร์น | `ultimateList` + `isHaveToAddBuff("Harmony_MC_ult", 3)` | 32-44 |
| **Talent** — Super Break ให้ทั้งทีม | `afterAttackActionList` → `superbreakTrigger(act, 100*(1.7 - 0.1*totalEnemy), "HMC")` | 86-90 |
| **A-trace** — Break แล้วได้ energy + ถอยคิวศัตรู | `toughnessBreakList` → `increaseEnergy(ptr, 11)` + `actionForward(target, -30)` | 92-95 |
| **E4** — ทีม BE เพิ่มตาม BE ของตัวเอง | `whenOnFieldList` ตั้งครั้งแรก + `statsAdjustList` คำนวณใหม่ | 56-60, 97-105 |
| **Technique** — ทีม BE +30% | `startGameList` + ถอนใน `afterTurnList` ตอน `turnCnt == 2` | 62-67, 79-83 |
| ER +25% ช่วงต้นเกม | `startGameList` → `energyRecharge += 25` · ถอนที่เทิร์น 3 | 66, 76-78 |
| **Minor traces** | `resetList` | 46-54 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — SP พอ หรือเทิร์นแรก → Skill ไม่งั้น BA | 24-30 |

## รากฐาน: Super Break ที่ให้ทั้งทีม

```cpp
afterAttackActionList: if (buffCheck["Harmony_MC_ult"] == 1)
    superbreakTrigger(act, 100 * (1.7 - 0.1 * totalEnemy), "HMC");
```
- **ไม่ guard ผู้โจมตี** → ยิงกับ action ของ **ทุกคนในทีม** ขณะที่บัฟ ult ยังอยู่ ซึ่งตรงกับ kit
- **ratio ลดตามจำนวนศัตรู** — 1 ตัว = 160%, 3 ตัว = 140%, 5 ตัว = 120% · เขียนเป็นสูตรแทนสาขา if
- **ส่งชื่อ `"HMC"` เป็น arg ที่ 3** ต่างจากตัวอื่นที่ส่ง `""` — น่าจะใช้แยกแหล่งที่มาในสถิติดาเมจ

## รากฐาน: E4 — สูตร BE → BE ที่ต้องกันลูป

```cpp
double temp = calculateBreakEffectForBuff(ptr, 15);
buffAllAllyExcludingBuffer(hmcPtr, {{BE, AType::TEMP, temp - buffNote["Harmony_MC_E4"]}});
buffAllAllyExcludingBuffer(hmcPtr, {{BE, AType::NONE, temp - buffNote["Harmony_MC_E4"]}});
buffNote["Harmony_MC_E4"] = temp;
```
**เป็นเคสที่ต้องใช้ `AType::TEMP` จริง ๆ** — สูตรอ่าน BE แล้วให้ผลเป็น BE · `calculateBreakEffectForBuff` หักช่อง `TEMP` ออกก่อนคำนวณ (`CalStats.h:86`) จึงไม่นับส่วนที่ตัวเองแจกไปแล้ว · ถ้าลงแต่ `NONE` จะวนไม่จบ (ดู `../Remembrance/RMC.md` หัวข้อเดียวกัน)

**ใช้ `buffAllAllyExcludingBuffer` เพราะ Harmony MC ไม่ควรได้ BE จากตัวเอง** — ซึ่งก็เป็นอีกชั้นที่ช่วยกันลูป

## จุดที่ควรระวัง

- **ชื่อ action ของ Skill เป็น `"RMC Skill"`** (125) — copy มาจาก `../Remembrance/RMC.h` แล้วลืมเปลี่ยน · ถ้ามี trigger ไหนจับชื่อ action จะชนกับ Skill ของ RMC จริง ๆ
- **ถอน Technique buff ด้วยเงื่อนไข `turn->turnCnt == 2`** (80-82) และถอน ER ด้วย `turn->turnCnt == 3` (76-78) — **ผูกกับเลขเทิร์นตายตัว** ไม่ได้ใช้ระบบ `isBuffEnd` · ถ้าลำดับเทิร์นเปลี่ยน (advance/delay) จะถอนผิดจังหวะ
- **ถอน Technique buff ด้วย `buffSingle(charUnit[turn->num].get(), ...)`** (81) — ถอนทีละคนตามเทิร์น แต่ลงด้วย `buffAllAlly` ทั้งทีม (64) · ถ้าใครไม่ได้เล่นถึงเทิร์นที่ 2 จะไม่ถูกถอน
- **`skillFunc` ไม่กิน SP ในเทิร์นแรก** (123) — `if (ptr->atvStats->turnCnt != 1) genSkillPoint(ptr,-1);` ไม่มีคอมเมนต์อธิบายว่ามาจาก kit ข้อไหน
- **`toughnessBreakList` ไม่ guard ว่าใคร break** (92-95) → ได้ energy 11 และถอยคิวศัตรู 30 ทุกครั้งที่ใครก็ตาม break
- **`whenOnFieldList` กับ `statsAdjustList` มีโค้ด E4 เหมือนกัน** ต่างกันแค่ตัวแรกไม่ได้หัก `buffNote` (57-59 vs 100-103) — ตัวแรกตั้งค่าเริ่มต้นจึงถูกต้อง แต่ถ้าแก้สูตรต้องแก้สองที่
