# `src/Defination/Data/Character/Harmony/Harmony_MC.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/trailblazer-harmony.md` · namespace `HarmonyMC` · **ซัพพอร์ต Super Break** — เป็นแหล่ง Super Break ให้ทั้งทีม ไม่ใช่แค่ตัวเอง (ต่างจาก `../Destruction/FireFly.md` และ `../Erudition/Rappa.md`)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(105, 140, 140, E, Imaginary, Harmony, "Harmony_MC", Standard)` | 10 |
| **Basic ATK** | `Basic_Atk(ptr)` — single 110%/10 | 111-121 |
| **Skill** | `Skill_func(ptr)` — `TraceType::Bounce` + `addEnemyBounce(55/5, 6)` | 122-133 |
| **Ultimate** — ทีม BE +33% 3 เทิร์น | `Ultimate_List` + `isHaveToAddBuff("Harmony_MC_ult", 3)` | 32-44 |
| **Talent** — Super Break ให้ทั้งทีม | `AfterAttackActionList` → `Superbreak_trigger(act, 100*(1.7 - 0.1*Total_enemy), "HMC")` | 86-90 |
| **A-trace** — Break แล้วได้ energy + ถอยคิวศัตรู | `Toughness_break_List` → `Increase_energy(ptr, 11)` + `Action_forward(target, -30)` | 92-95 |
| **E4** — ทีม BE เพิ่มตาม BE ของตัวเอง | `WhenOnField_List` ตั้งครั้งแรก + `Stats_Adjust_List` คำนวณใหม่ | 56-60, 97-105 |
| **Technique** — ทีม BE +30% | `Start_game_List` + ถอนใน `After_turn_List` ตอน `turnCnt == 2` | 62-67, 79-83 |
| ER +25% ช่วงต้นเกม | `Start_game_List` → `Energy_recharge += 25` · ถอนที่เทิร์น 3 | 66, 76-78 |
| **Minor traces** | `Reset_List` | 46-54 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — SP พอ หรือเทิร์นแรก → Skill ไม่งั้น BA | 24-30 |

## รากฐาน: Super Break ที่ให้ทั้งทีม

```cpp
AfterAttackActionList: if (buffCheck["Harmony_MC_ult"] == 1)
    Superbreak_trigger(act, 100 * (1.7 - 0.1 * Total_enemy), "HMC");
```
- **ไม่ guard ผู้โจมตี** → ยิงกับ action ของ **ทุกคนในทีม** ขณะที่บัฟ ult ยังอยู่ ซึ่งตรงกับ kit
- **ratio ลดตามจำนวนศัตรู** — 1 ตัว = 160%, 3 ตัว = 140%, 5 ตัว = 120% · เขียนเป็นสูตรแทนสาขา if
- **ส่งชื่อ `"HMC"` เป็น arg ที่ 3** ต่างจากตัวอื่นที่ส่ง `""` — น่าจะใช้แยกแหล่งที่มาในสถิติดาเมจ

## รากฐาน: E4 — สูตร BE → BE ที่ต้องกันลูป

```cpp
double temp = calculateBreakEffectForBuff(ptr, 15);
buffAllAllyExcludingBuffer(HMCptr, {{BE, AType::TEMP, temp - buffNote["Harmony_MC_E4"]}});
buffAllAllyExcludingBuffer(HMCptr, {{BE, AType::None, temp - buffNote["Harmony_MC_E4"]}});
buffNote["Harmony_MC_E4"] = temp;
```
**เป็นเคสที่ต้องใช้ `AType::TEMP` จริง ๆ** — สูตรอ่าน BE แล้วให้ผลเป็น BE · `calculateBreakEffectForBuff` หักช่อง `TEMP` ออกก่อนคำนวณ (`CalStats.h:86`) จึงไม่นับส่วนที่ตัวเองแจกไปแล้ว · ถ้าลงแต่ `None` จะวนไม่จบ (ดู `../Remembrance/RMC.md` หัวข้อเดียวกัน)

**ใช้ `buffAllAllyExcludingBuffer` เพราะ Harmony MC ไม่ควรได้ BE จากตัวเอง** — ซึ่งก็เป็นอีกชั้นที่ช่วยกันลูป

## จุดที่ควรระวัง

- **ชื่อ action ของ Skill เป็น `"RMC Skill"`** (125) — copy มาจาก `../Remembrance/RMC.h` แล้วลืมเปลี่ยน · ถ้ามี trigger ไหนจับชื่อ action จะชนกับ Skill ของ RMC จริง ๆ
- **ถอน Technique buff ด้วยเงื่อนไข `turn->turnCnt == 2`** (80-82) และถอน ER ด้วย `turn->turnCnt == 3` (76-78) — **ผูกกับเลขเทิร์นตายตัว** ไม่ได้ใช้ระบบ `isBuffEnd` · ถ้าลำดับเทิร์นเปลี่ยน (advance/delay) จะถอนผิดจังหวะ
- **ถอน Technique buff ด้วย `buffSingle(charUnit[turn->num].get(), ...)`** (81) — ถอนทีละคนตามเทิร์น แต่ลงด้วย `buffAllAlly` ทั้งทีม (64) · ถ้าใครไม่ได้เล่นถึงเทิร์นที่ 2 จะไม่ถูกถอน
- **`Skill_func` ไม่กิน SP ในเทิร์นแรก** (123) — `if (ptr->Atv_stats->turnCnt != 1) genSkillPoint(ptr,-1);` ไม่มีคอมเมนต์อธิบายว่ามาจาก kit ข้อไหน
- **`Toughness_break_List` ไม่ guard ว่าใคร break** (92-95) → ได้ energy 11 และถอยคิวศัตรู 30 ทุกครั้งที่ใครก็ตาม break
- **`WhenOnField_List` กับ `Stats_Adjust_List` มีโค้ด E4 เหมือนกัน** ต่างกันแค่ตัวแรกไม่ได้หัก `buffNote` (57-59 vs 100-103) — ตัวแรกตั้งค่าเริ่มต้นจึงถูกต้อง แต่ถ้าแก้สูตรต้องแก้สองที่
