# `src/Defination/Data/Character/Destruction/FireFly.h`

kit อ้างอิง: `docs/kit-reference/Character/FireFly.md` · **ไฟล์อ้างอิงของ Super Break และ Break Effect** — ตัวเดียวที่ดาเมจหลักมาจาก `Superbreak_trigger` ไม่ใช่ `addDamageIns`

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(104, 240, 240, E, Fire, Destruction, "FireFly", Standard)` | 10 |
| build — **BE เป็นแกน** | `pushSubstats(Stats::BE)` + main stat เชือก `BE` | 20-23 |
| **Skill** | `Skill_func(ptr)` — 40% + 60% + `Action_forward(25)` + energy 60 (ไม่ผ่าน ER) | 151-165 |
| **Enhanced Skill** (ขณะ Combustion) | `Enchance_Skill_func(ptr)` — **multiplier คำนวณจาก BE ใน callback** | 166-190 |
| **Ultimate** — เข้า Combustion State | `Ultimate_List` — SPD +60 flat, Break Effect +50, VUL +20 + `countdownList[0]->summon()` | 51-62 |
| **countdown "Combustion_state"** | `SetCountdownStats(ptr, 70, "Combustion_state")` + `Turn_func` ถอนบัฟแล้ว `death()` | 136-148 |
| **Talent / A-trace** — Super Break | `AfterAttackActionList` → `Superbreak_trigger(act, 50 หรือ 35, "")` ตามระดับ BE | 118-124 |
| **Module Y** — BE เพิ่มตาม ATK ที่เกิน 1800 | `Stats_Adjust_List` (guard `ATK_P` / `FLAT_ATK`) | 65-79 |
| **Technique** — แปะ Fire weakness | `Start_wave_List` → `weaknessApply(ptr, each, {ElementType::Fire}, "FireFly Weakness", 2)` | 88-106 |
| Enhanced Skill แปะ weakness ด้วย | `weaknessApply` ใน callback | 184-186 |
| **Minor traces** | `Reset_List` | 33-49 |
| **E1** — DEF_SHRED +15 · Enhanced Skill ไม่กิน SP | `Reset_List` · `if (ptr->Eidolon < 1) genSkillPoint(ptr,-1)` | 43-45, 167 |
| **E2** — break แล้วได้ action เพิ่ม | `Toughness_break_List` เพิ่ม stack · `AfterAttackActionList` ใช้ stack → `Action_forward(100)` | 81-86, 114-117 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — countdown ตาย → Skill ไม่งั้น Enhanced Skill | 26-32 |
| weakness หมดอายุ | `After_turn_List` → `isDebuffEnd(enemy, "FireFly Weakness")` | 127-131 |

## รากฐาน: Super Break

```cpp
if (act->isSameName("FireFly")) {
    if      (ptr->Stats_type[Stats::BE][AType::None] >= 360) Superbreak_trigger(act, 50, "");
    else if (ptr->Stats_type[Stats::BE][AType::None] >= 200) Superbreak_trigger(act, 35, "");
}
```
`Superbreak_trigger(act, ratio, ชื่อ)` เรียก **หลัง action จบ** (`AfterAttackActionList`) เพื่อแปะดาเมจ Super Break ตามจำนวน toughness ที่ action นั้นทำลายไป · ดาเมจกลุ่มนี้ผูกกับ `AType::SPB` ซึ่ง `../../Relic/Iron_Cavalry.md` มีบัฟให้โดยเฉพาะ

**เกณฑ์ BE เป็นขั้นบันไดที่อ่าน `Stats_type` สด** ไม่ได้ cache → ถ้า BE เปลี่ยนระหว่างเกม (Combustion ให้ Break Effect +50) ระดับจะขยับตาม

## รากฐาน: `weaknessApply` — แปะธาตุอ่อนแอให้ศัตรู

```cpp
weaknessApply(ptr, each, {ElementType::Fire}, "FireFly Weakness", 2);
```
ทำให้ศัตรูที่ไม่มี Fire weakness กลายเป็นมี ชั่วคราว → เปิดทางให้ break ได้ · ปลายทางคือ `WeaknessApply_List` (`TriggerByWeaknessApply_Func`) ที่ตัวละครอื่นดักได้ · ถอนด้วย `isDebuffEnd` ตามปกติ — สังเกตว่า `After_turn_List` เรียก `isDebuffEnd` **โดยไม่ใช้ค่าที่คืนมา** (130) เพราะ helper เคลียร์สถานะให้เองในตัว

## รากฐาน: Module Y — สูตรที่เขียน stat ดิบเอง

```cpp
temp = floor(((ATK_P/100 * baseAtk + baseAtk) + FLAT_ATK - 1800) / 100) * 0.8;
if (ptr->buffNote["FireFly_ModuleY"] <= 0) temp = 0;
buffSingle(FFptr, {{BE, AType::TEMP, temp - buffNote[...]}, {BE, AType::None, temp - buffNote[...]}});
```
**คำนวณ ATK รวมด้วยมือแทนที่จะใช้ `calculateAtkForBuff`** ซึ่งมีอยู่แล้ว (`CalStats.h:52`) — ผลอาจต่างกันเพราะ helper ตัวนั้นหักช่อง `TEMP` ออกก่อน ส่วนสูตรนี้ไม่หัก · ใช้สำนวน delta + คู่ `TEMP`/`None` ตามปกติ (ดู `../Remembrance/RMC.md`)

## รากฐาน: ดาเมจที่ประกอบข้างใน callback ทั้งก้อน

`Enchance_Skill_func` ไม่มี `addDamageIns` นอก callback เลย — ประกอบทั้งหมดข้างในเพราะ multiplier ขึ้นกับ BE ณ เวลานั้น (171-182) · เป็นรูปแบบเดียวกับ `../Erudition/The_Herta.md` แต่สุดโต่งกว่า (ที่นั่นมีก้อนคงที่นอก callback ด้วย)

## จุดที่ควรระวัง

- **`if (ptr->buffNote["FireFly_ModuleY"] <= 0) temp = 0;`** (70) — เช็ค**ค่าเดิม**ไม่ใช่ `temp` ที่เพิ่งคำนวณ · ผลคือถ้าครั้งแรกคำนวณได้ค่าบวกแต่ `buffNote` ยังเป็น 0 อยู่ → `temp` ถูกบังคับเป็น 0 → `buffNote` ยังเป็น 0 ตลอดไป **Module Y จึงไม่มีวันทำงาน** เว้นแต่มีอะไรตั้ง `buffNote` ให้เป็นบวกก่อน · น่าจะตั้งใจเขียน `if (temp <= 0) temp = 0;`
- **`Ultimate_List` ไม่ได้สร้าง action เลย** (51-62) — บัฟตัวเองแล้ว `summon()` countdown ตรง ๆ ไม่มี `addToActionBar()` / `Deal_damage()` · ต่างจากทุกตัวในโปรเจกต์ · ถ้า kit ระบุว่า ult ไม่มีดาเมจก็ถูก แต่แปลว่า ult นี้ไม่ผ่าน action bar และไม่ยิง `WhenUseUlt_List` ของใครเลย (ซึ่งจะกระทบ `../../Relic/Scholar.md`, `../../Relic/Eagle_Beaked_Helmet.md` และ Talent ของ `Saber.h`)
- **`SetCountdownStats` ถูกเรียกท้ายสุดของ `Setup`** (136) หลังจากที่ `Turn_func` (27) และ trigger หลายตัวอ้าง `ptr->countdownList[0]` ไปแล้ว — ทำงานได้เพราะ lambda ประเมินตอนรัน ไม่ใช่ตอนสร้าง แต่เป็นลำดับที่อ่านแล้วสับสน · ตัวอื่น (`Aglaea.h`, `Phainon.h`) เรียกไว้ต้น `Setup`
- **`Toughness_break_List` guard ด้วย `Atv_stats->num`** (82) แทนการเทียบชื่อ
- **`AfterAttackActionList` ของ E2 ยิงกับ action ของทุกคน** (114-117) ไม่ได้ guard ว่าเป็นของ FireFly → ได้ advance 100% ทุกครั้งที่ใครก็ตามโจมตี ตราบใดที่ stack ยังเหลือ
