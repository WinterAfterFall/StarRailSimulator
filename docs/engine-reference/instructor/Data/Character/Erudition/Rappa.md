# `src/Defination/Data/Character/Erudition/Rappa.h`

kit อ้างอิง: `docs/character-kit-reference/Rappa.md` · **สาย Break/Super Break** — คู่กับ `../Destruction/FireFly.md` แต่ใช้ `Cal_Break_damage` โดยตรงด้วย

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(96, 140, 140, E, Imaginary, Erudition, "Rappa", Standard)` | 10 |
| build — BE เป็นแกน | `pushSubstats(Stats::BE)` + main stat เชือก `BE` | 14-17 |
| **Skill** | `Skill_func(ptr)` — AoE 60%×3 สองชุด | 208-228 |
| **Enhanced BA** (ขณะ Ult state) | `Enchance_Basic_Atk(ptr)` — blast 2 ชุด + AoE 1 ชุด + `Dont_care_weakness = 50` | 179-207 |
| **Ultimate** — เข้าสถานะ + ตี EBA ทันที | `Ultimate_List` — `AllyBuffAction` ที่ข้างในสร้าง EBA เอง | 37-80 |
| Ult state — BE +30, Break Effect +50, 2 ครั้ง | `buffCheck["Rappa_Ult"] = 1` · `stack["Rappa_Ult"] = 2` | 43-47 |
| **Talent** — Break แล้วสะสมแต้ม | `Toughness_break_List` → `stack["Rappa_Talent"]++` | 162-175 |
| Talent — แปลงแต้มเป็นดาเมจ Break | `buffNote["Rappa_Talent"] = stack * 0.5 + 0.6` แล้วใช้ใน `AfterAttackActionList` | 57-58, 130-134 |
| **Super Break** | `AfterAttackActionList` → `Superbreak_trigger(act, 60, "")` | 126 |
| **Withered Leaf** — Break VUL ตาม ATK | `Toughness_break_List` → `floor((ATK - 2400)/100) + 2` (cap 10) | 168-174 |
| **Technique** | `Start_game_List` → `Cal_Break_damage` + `Cal_Toughness_reduction` โดยตรง | 140-160 |
| **Minor traces** | `Reset_List` | 82-92 |
| **E1** — DEF_SHRED +15 ขณะ Ult state + energy คืน | `if (ptr->Eidolon >= 1)` ทั้งตอนเข้าและออกจากสถานะ | 47, 111-114 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — ไม่อยู่ใน Ult state → Skill · อยู่ → Enhanced BA | 25-31 |
| ออกจาก Ult state | `After_turn_List` — `stack["Rappa_Ult"] == 0` แล้วถอนบัฟ | 105-119 |

## รากฐาน: เรียกสูตร Break ตรง ๆ

| helper | ใช้ทำอะไร |
|---|---|
| `Superbreak_trigger(act, ratio, ชื่อ)` | แปะ Super Break ตาม toughness ที่ action นั้นทำลาย (ดู `../Destruction/FireFly.md`) |
| `Cal_Break_damage(act, enemy, ratio)` | **คำนวณดาเมจ Break ใส่ศัตรูตรง ๆ** ไม่ผ่าน action bar |
| `Cal_Toughness_reduction(act, enemy, amount)` | ลด toughness ตรง ๆ |

Technique ของ Rappa (140-160) เป็นตัวอย่างเดียวในโปรเจกต์ที่ **สร้าง action สองก้อนแล้วไม่ `addToActionBar()` เลย** — ใช้เป็นแค่ภาชนะให้ `Cal_Break_damage` / `Cal_Toughness_reduction` อ่านข้อมูลผู้กระทำ

## รากฐาน: `Dont_care_weakness`

`act->Dont_care_weakness = 50;` (60, 191) — ให้ action นั้นลด toughness ได้แม้ไม่ตรงธาตุอ่อนแอ (50%) · `Castorice.h` ใช้ `= 100` สำหรับ E6

## รากฐาน: สถานะที่นับด้วยจำนวนครั้ง ไม่ใช่เทิร์น

```cpp
Ult:            buffCheck["Rappa_Ult"] = 1;  stack["Rappa_Ult"] = 2;
Enhanced BA:    ptr->stack["Rappa_Ult"]--;                      // ใช้ไป 1 ครั้ง
After_turn:     if (stack["Rappa_Ult"] == 0 && buffCheck["Rappa_Ult"] == 1) { ถอนบัฟทั้งหมด }
```
**`buffCheck` บอกว่าอยู่ในสถานะไหม / `stack` บอกว่าเหลือกี่ครั้ง** — คู่นี้ต้องขยับพร้อมกัน · ต่างจาก countdown unit ของ `../Destruction/FireFly.md` และ `Aglaea.h` ที่นับด้วยเทิร์น

## จุดที่ควรระวัง

- **บรรทัด 173 ไม่ทำอะไรเลย**: `target->debuffNote["Withered_Leaf"] = target->debuffNote["Withered_Leaf"];` — assign ตัวเองใส่ตัวเอง · น่าจะตั้งใจเขียน `= temp;` เพื่อจำค่าใหม่ไว้สำหรับสำนวน delta ที่บรรทัดถัดไป · **ผลตอนนี้: `debuffNote` ไม่เคยถูกอัปเดต ค้างที่ 0 ตลอด** → `temp - 0 = temp` ถูกบวกเข้าไปใหม่ทุกครั้งที่ break **และการถอนที่บรรทัด 102 ก็ถอนด้วยค่า 0** → **Withered Leaf สะสมไม่มีวันถูกถอน**
- **โค้ด Enhanced BA ถูก copy ทั้งก้อนเข้าไปใน Ult** (50-75 กับ 179-207) ต่างกันแค่ Ult ไม่ได้ `stack["Rappa_Ult"]--` · ถ้าแก้ multiplier ต้องแก้สองที่
- **`Cal_Break_damage(act, ...)` ใน `AfterAttackActionList` ส่ง `act` (action ที่เพิ่งจบ) ไม่ใช่ `data_2` ที่เพิ่งสร้าง** (132) — `data_2` ถูกสร้างที่บรรทัด 128-129 แล้วไม่ได้ใช้เลย
- **`After_turn_List` ถอนบัฟโดยเขียน `Stats_type` ตรง ๆ** (107-112) ไม่ผ่าน `buffSingle` → ไม่ยิง `StatsAdjust`
- **`Start_game_List` ของ Technique ไม่มี `Deal_damage()`** (140-160) ต่างจากตัวอื่น — อาจตั้งใจเพราะ `Cal_Break_damage` คำนวณจบในตัว
- **ตัวแปร local ชื่อ `enemyUnit` บัง global `enemyUnit`** (98) ใน `After_turn_List` — ทำงานได้เพราะในบล็อกนั้นไม่ได้ใช้ global แต่เป็นชื่อที่ชวนพลาด
