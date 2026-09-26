# `src/Defination/Data/Character/Destruction/FireFly.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/firefly.md` · **ไฟล์อ้างอิงของ Super Break และ Break Effect** — ตัวเดียวที่ดาเมจหลักมาจาก `Superbreak_trigger` ไม่ใช่ `addDamageIns`

> **แก้ 2026-09-27** (รีวิวเทียบ kit — kit ใน repo เป็นเวอร์ชัน rework patch 4.2): Enhanced Skill hit สุดท้าย `4*` / `2*` → `0.4*` / `0.2*` (เดิมตัวคูณรวม 4.6 เท่า) · Skill 100% → 200% (80/120) · VUL ของ Combustion `AType::None` → `AType::Break` (ครอบ SPB ด้วยเพราะ SPB มี `Break` ใน `damageTypeList`) · A6 เดิมไม่เคยทำงาน (เช็ค `buffNote` แทน `temp`) และหาร 100 → หาร 10 · เพิ่ม A2 (BE +25% + หน่วง countdown 10% สูงสุด 3 ครั้ง) · A4 ตาม kit ใหม่ (BE ≥150%/300% → SPB 100%/150% เฉพาะ Enhanced Skill ขณะ Combustion — ข้อความเต็มไม่มีใน kit ตีความจากสรุปภาษาไทย) · Talent เติม energy เป็น 50% ตอนเริ่ม · E1 DEF ignore เฉพาะ `AType::SKILL` ขณะ Combustion · E2 guard เฉพาะ Enhanced Skill ของ FireFly + ครั้งเดียวต่อเทิร์น (stack เริ่ม 2 = ตั้งใจ: ประมาณว่าฆ่าศัตรูได้ 2 ตัวฟรี) · เพิ่ม E4 (Effect RES +50% ขณะ Combustion) และ E6 · base 814/523 · **ยังไม่ได้ทำ**: Ult `p3 = 1.2` / `p4 = 3` ใน kit ไม่รู้ความหมาย (user: ข้ามไปก่อน), Enhanced BA

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(104, 240, 240, E, Fire, Destruction, "FireFly", Standard)` · base `(814, 523, 776)` | 11-13 |
| build — **BE เป็นแกน** | `pushSubstats(Stats::BE)` + main stat เชือก `BE` | 21-24 |
| **Skill** | `Skill_func(ptr)` — 80% + 120% + `Action_forward(25)` หลัง `Attack` + energy 60% (ไม่ผ่าน ER) | 172-185 |
| **Enhanced Skill** (ขณะ Combustion) | `Enchance_Skill_func(ptr)` — multiplier `200 + 0.2×BE` (cap BE 360) แบ่ง 15/15/15/15/40 ข้างเคียงครึ่งหนึ่ง | 187-212 |
| **Ultimate** — เข้า Combustion | `Ultimate_List` — `buffSingle(combustionBuff(ptr, 1))` + advance 100% + `countdownList[0]->summon()` | 50-57 |
| บัฟระหว่าง Combustion | `combustionBuff(ptr, sign)` — SPD +60, Break Eff +50, VUL[Break] +20, **A2** BE +25, **E1** DEF_SHRED[SKILL] +15, **E4** Effect RES +50, **E6** RESPEN +20 / Break Eff +50 · ลงด้วย `1` ถอนด้วย `-1` | 157-170 |
| **countdown "Combustion_state"** | `SetCountdownStats(ptr, 70, ...)` + `Turn_func` ถอน `combustionBuff(ptr, -1)` แล้ว `death()` | 145-152 |
| **A2** — Break ขณะ Combustion → หน่วง countdown 10% (สูงสุด 3) | `Toughness_break_List` → `Action_forward(countdown, -10)` + stack `"FireFly A2 delay"` (รีเซ็ตตอน Ult) | 76-87 |
| **A4** — Super Break | `AfterAttackActionList` → `Superbreak_trigger(act, 150 หรือ 100, "")` เฉพาะ Enhanced Skill ขณะ Combustion | 119-134 |
| **A6** — ทุก 10 ATK ที่เกิน 1800 → BE +0.8% | `Stats_Adjust_List` (guard `ATK_P` / `FLAT_ATK`) | 59-74 |
| **Talent** — energy < 50% ตอนเริ่ม → 50% | `Start_game_List` | 109-113 |
| **Technique** — แปะ Fire weakness + 200% AoE | `Start_wave_List` → `weaknessApply(..., "FireFly Weakness", 2)` | 89-107 |
| Enhanced Skill แปะ weakness ด้วย | `weaknessApply` ใน callback | 206-208 |
| **Minor traces** | `Reset_List` | 34-48 |
| **E1** — Enhanced Skill ไม่กิน SP + DEF ignore 15% | `if (ptr->Eidolon < 1) genSkillPoint(ptr,-1)` · `combustionBuff` | 188, 164 |
| **E2** — Enhanced Skill ฆ่า/Break → เทิร์นพิเศษ ครั้งเดียวต่อเทิร์น | stack เริ่ม 2 (`Reset_List`) + `Toughness_break_List` เพิ่ม stack · `AfterAttackActionList` ใช้ stack → advance 100% · `Before_turn_List` รีเซ็ต `FireFly_E2_used` | 44-46, 79-81, 115-126 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — countdown ตาย → Skill ไม่งั้น Enhanced Skill | 27-33 |
| weakness หมดอายุ | `After_turn_List` → `isDebuffEnd(enemy, "FireFly Weakness")` | 136-140 |

## รากฐาน: Super Break

```cpp
if (!act->isSameAction(ptr, AType::SKILL)) return;      // Enhanced Skill ของ FireFly
if (ptr->countdownList[0]->isDeath()) return;            // ขณะ Combustion เท่านั้น
if      (ptr->Stats_type[Stats::BE][AType::None] >= 300) Superbreak_trigger(act, 150, "");
else if (ptr->Stats_type[Stats::BE][AType::None] >= 150) Superbreak_trigger(act, 100, "");
```
`Superbreak_trigger(act, ratio, ชื่อ)` เรียก **หลัง action จบ** (`AfterAttackActionList`) เพื่อแปะดาเมจ Super Break ตามจำนวน toughness ที่ action นั้นทำลายไป · ดาเมจกลุ่มนี้ผูกกับ `AType::SPB` ซึ่ง `../../Relic/Iron_Cavalry.md` มีบัฟให้โดยเฉพาะ

**เกณฑ์ BE เป็นขั้นบันไดที่อ่าน `Stats_type` สด** ไม่ได้ cache → ถ้า BE เปลี่ยนระหว่างเกม (A2 ให้ BE +25 ระหว่าง Combustion) ระดับจะขยับตาม

## รากฐาน: `weaknessApply` — แปะธาตุอ่อนแอให้ศัตรู

```cpp
weaknessApply(ptr, each, {ElementType::Fire}, "FireFly Weakness", 2);
```
ทำให้ศัตรูที่ไม่มี Fire weakness กลายเป็นมี ชั่วคราว → เปิดทางให้ break ได้ · ปลายทางคือ `WeaknessApply_List` (`TriggerByWeaknessApply_Func`) ที่ตัวละครอื่นดักได้ · ถอนด้วย `isDebuffEnd` ตามปกติ — สังเกตว่า `After_turn_List` เรียก `isDebuffEnd` **โดยไม่ใช้ค่าที่คืนมา** (130) เพราะ helper เคลียร์สถานะให้เองในตัว

## รากฐาน: Module Y — สูตรที่เขียน stat ดิบเอง

```cpp
temp = floor(((ATK_P/100 * baseAtk + baseAtk) + FLAT_ATK - 1800) / 10) * 0.8;
if (temp <= 0) temp = 0;
buffSingle(FFptr, {{BE, AType::TEMP, temp - buffNote[...]}, {BE, AType::None, temp - buffNote[...]}});
```
**คำนวณ ATK รวมด้วยมือแทนที่จะใช้ `calculateAtkForBuff`** ซึ่งมีอยู่แล้ว (`CalStats.h:52`) — ผลอาจต่างกันเพราะ helper ตัวนั้นหักช่อง `TEMP` ออกก่อน ส่วนสูตรนี้ไม่หัก · ใช้สำนวน delta + คู่ `TEMP`/`None` ตามปกติ (ดู `../Remembrance/RMC.md`)

## รากฐาน: ดาเมจที่ประกอบข้างใน callback ทั้งก้อน

`Enchance_Skill_func` ไม่มี `addDamageIns` นอก callback เลย — ประกอบทั้งหมดข้างในเพราะ multiplier ขึ้นกับ BE ณ เวลานั้น (191-203) · เป็นรูปแบบเดียวกับ `../Erudition/The_Herta.md` แต่สุดโต่งกว่า (ที่นั่นมีก้อนคงที่นอก callback ด้วย)

## จุดที่ควรระวัง

- **Ult ไม่ได้สร้าง action** (50-57) — บัฟตัวเองแล้ว `summon()` countdown ตรง ๆ ไม่มี `addToActionBar()` · แต่ `WhenUseUlt_List` **ยังถูกยิง** เพราะ `ultUseCheck` เรียกให้ก่อน (`Function/Combat/Energy.h:39`) — คู่มือเดิมเขียนว่าไม่ยิง ซึ่งผิด (แก้ 2026-09-27)
- **`SetCountdownStats` ถูกเรียกท้าย `Setup`** (145) หลังจากที่ `Turn_func` และ trigger หลายตัวอ้าง `ptr->countdownList[0]` ไปแล้ว — ทำงานได้เพราะ lambda ประเมินตอนรัน
- **`Toughness_break_List` guard ด้วย `Atv_stats->num`** (77) แทนการเทียบชื่อ
- **E2 stack เริ่มที่ 2 โดยตั้งใจ** — user: ปกติมีศัตรูตายฟรี ~2 ตัวต่อไฟต์ จึงแถมไว้แทนเงื่อนไข "ฆ่าศัตรู"
- **A4 / Ult ของเวอร์ชัน rework ยังไม่ครบ** — kit เก็บแค่ตัวเลข: A4 ตีความเป็นอัตรา SPB ส่วน Ult `p3 = 1.2` / `p4 = 3` ยังไม่รู้ความหมาย
