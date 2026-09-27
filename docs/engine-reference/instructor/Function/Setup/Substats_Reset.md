# `src/Defination/Function/Setup/Substats_Reset.h`

## Substats reroll — หา substats ที่ดาเมจสูงสุด

field อยู่ที่ `CharUnit.h` (region `substats Reroll`) · อัลกอริทึมอยู่ที่ `Substats_Reset.h` (`standardReroll` / `trySwapSubstat` / `restoreBestSubstats`) · ถูกเรียกท้ายทุก run จาก `Main.h`: `if(rerollSubstats())break;`

_refactor 2026-09-13 ให้อ่านง่าย และโครงเดียวกับ `rerollSubstats()` ของ WuwaSimulator (ซึ่งเดิมพอร์ตไปจากโค้ดนี้) — ตารางชื่อเก่า → ใหม่อยู่ท้ายหัวข้อ_

### ภาพรวม: 1 run = ลอง substats 1 ชุด

- `substats` = `vector<pair<Stats,int>>` : ชนิด substat + **จำนวน roll** ที่ลงช่องนั้น
- `setStats` (`Substats_Reset.h`) แปลง roll → ค่าจริงด้วยค่า **Med roll** (CR 2.9 · CD 5.8 · ATK%/HP% 3.888 · DEF% 4.86 · BE 5.8 · SPD 2.3) — ตรงกับ[คู่มือเกม](../../../../hsr-system-reference.md) §4.5 คอลัมน์ Med · memosprite ของตัวนั้นได้ค่าเดียวกันด้วย (SPD คูณ `unitSpeedRatio`)
- ลูปใน `Main.h`: รัน sim ด้วยชุดปัจจุบัน → `calDamageSummary` → `rerollSubstats()` ตั้งชุดถัดไปให้ทุกตัวละครที่ยังค้นหาอยู่ → วนจนไม่มีใครขยับแล้ว (`rerollSubstats` คืน `true`)

### จุดเริ่ม: ช่อง 0 คือคลัง

`pushSubstats(Stats)` เพิ่มช่องทีละตัว (roll = 0) → `setTotalSubstats(25)` ยัด roll **ทั้งหมด** ลง `substats[0]` → requirement (speed/atk/hp/def/ehr ใน `CalRequireStats.h`) หัก roll ที่ต้องจ่ายออกจากช่อง 0 ผ่าน `changeTotalSubStats(-x)`

ผลที่ตามมา: **ลำดับการ `pushSubstats` มีผลกับผลลัพธ์** — ช่องแรกเป็นผู้ให้อย่างเดียว ช่องสุดท้ายเป็นผู้รับอย่างเดียว

### อัลกอริทึม `standardReroll` (อธิบายโดย user 2026-09-13)

1. เลือก **target** = ช่องที่จะเติม (`rerollTargetIndex` เริ่มที่ 1)
2. ลอง **source** ทีละช่องตั้งแต่ 0 ถึง target-1 — แต่ละครั้ง **ดึง 1 roll จาก source ไปใส่ target** แล้วรัน sim
   - ทุกชุดทดลองแตกจากจุดตั้งต้นเดียวกัน (`rerollSweepBase`) ไม่สะสมต่อกัน
   - source ที่ไม่มี roll เหลือ → ข้ามไปเลย ไม่เสียรอบ sim
3. ลองครบทุก source (= 1 **sweep**) แล้ว:
   - มีชุดที่ดาเมจดีขึ้น → เอาชุดที่ **ดาเมจเยอะสุด** เป็นฐานใหม่ แล้ว sweep target เดิมซ้ำ
   - ไม่มีชุดไหนดีขึ้นเลย → **target +1** แล้ว source กลับไปเริ่มที่ 0
4. target เลยช่องสุดท้าย → คืน `substats` เป็นชุดที่ดีที่สุดแล้วจบ

"เอาชุดที่ดาเมจเยอะสุด" ไม่ต้องเขียนเอง — `changeMaxDamage` (`CalDamageNote.h`) บันทึกชุดที่ทำลายสถิติลง `bestSubstats` ทุกครั้งอยู่แล้ว ครบ sweep เมื่อไหร่ `bestSubstats` ก็คือผู้ชนะของ sweep นั้น

### จังหวะของ 1 คอล

`standardReroll` ถูกเรียก **1 ครั้งต่อ 1 run** และทำ 2 อย่างตามลำดับ:
1. **วัดผล** run ที่เพิ่งจบ — `changeMaxDamage` · ถ้าทำลายสถิติ **และ** เป็นชุดทดลอง (`rerollSourceIndex >= 0`) → `rerollImproved = true` · run แรกสุดคือ baseline ไม่นับ
2. **ตั้งชุดถัดไป** แล้วคืน `true` ให้ `Main.h` ไปรัน — หรือคืน `false` ถ้าจบแล้ว

> ดาเมจที่ใช้เทียบคือ **`avgDmgRecord[0].currentDmgRecord`** (ดาเมจเฉลี่ยต่อ ATV) ไม่ใช่ total → [🐞 #16](../../BUGS.md) จึงกระทบว่า optimizer เลือก substats ชุดไหนด้วย

### field

| field | หน้าที่ |
|---|---|
| `substats` | ชนิด + จำนวน roll ต่อช่อง — ตัวที่ถูกแก้ไปเรื่อย ๆ ระหว่างค้นหา |
| `bestSubstats` | จำนวน roll ของชุดที่ดาเมจสูงสุด — เขียนโดย `changeMaxDamage` · `printSummaryResult` ปรินต์ตัวนี้ |
| `totalSubstats` | จำนวน roll รวม — user กำหนดเอง **25** · ค่าเริ่มต้นใน `CharUnit.h` = 25 (แก้จาก 20 เมื่อ 2026-09-13) และตัวละครทุกตัวเรียก `setTotalSubstats(25)` |
| `rerollActive` | `1` = ยังค้นหา · `0` = จบ หรือถูกปิดด้วย `CharCmd::setRerollCheck(ptr, 0)` |
| `rerollTargetIndex` | ช่องที่กำลังเติม — เริ่ม 1 |
| `rerollSourceIndex` | ช่องที่กำลังดึงออก ไล่ 0..target-1 · `-1` = ยังไม่เริ่ม sweep |
| `rerollImproved` | sweep นี้มีชุดทดลองที่ทำลายสถิติไหม |
| `rerollSweepBase` | จุดตั้งต้นของ sweep (สำเนาของ `bestSubstats` ตอนเริ่ม sweep) |

### ชื่อเก่า → ชื่อใหม่ (refactor 2026-09-13)

| เก่า | ใหม่ | หมายเหตุ |
|---|---|---|
| `Max_damage_Substats` | `bestSubstats` | |
| `Reroll_check` | `rerollActive` | ความหมายเดิม · ชื่อคำสั่ง `CharCmd::setRerollCheck` คงไว้ |
| `Stop_reroll` | `rerollImproved` | **กลับขั้ว** — เดิม `0` = ดีขึ้น |
| `spiltPoint` | `rerollTargetIndex` | |
| `Current_sub_choose` | `rerollSourceIndex` | เดิมเริ่ม 0 แล้ว "เลื่อน" roll ที่ถูกดึงจากช่องหนึ่งไปช่องถัดไป · ใหม่เริ่ม -1 และตั้งชุดทดลองจาก base ทุกครั้ง |
| `SeparateRatio` | **ลบ** | โควตาจำนวน sweep ซ้ำต่อ target — ไม่จำเป็น เพราะทุกครั้งที่ sweep ซ้ำ ดาเมจสูงสุดต้อง **เพิ่มขึ้นจริง** และ sim deterministic → วนไม่รู้จบไม่ได้ |
| _(ไม่มี)_ | `rerollSweepBase` | ใหม่ |
| `currentTotalSubstats` | **ลบ** | ไม่มีใครอ่าน (เดิมใช้แค่โหมด `AllPossible` ที่ปิดไปแล้ว) · user อนุมัติ 2026-09-13 |
| `Damage_data` · `StatsType_Compare` · `TotalSubstats_Compare` (+ `_MAX_MIN`) | **ลบ** | ของโหมด `AllCombination` / `AllPossible` + `Print_All_Substats` / `Calculate_All_Substats` ที่ไม่มีใครเรียก (user สั่งทิ้ง E3/E4) |

- `goto again` ใน `rerollSubstats` (ข้ามชุดที่ roll ติดลบ) → ย้ายไปเป็นการเช็คใน `trySwapSubstat`
- `AllCombinationReroll` / `AllPossibleReroll` → **comment ไว้** ทั้งนิยาม (ท้าย `Substats_Reset.h`) · declaration · enum `SubstatsRerollMode` · สาขาใน `SetCombat.h` — ตัวโค้ดคงชื่อเก่าไว้ ถ้าจะเปิดกลับต้องแก้ตามหมายเหตุหัว block

### ยืนยันว่า refactor ไม่เปลี่ยนผล

sandbox ที่ใช้ทำงาน link C++ ไม่ได้ (`ld returned 116` แม้แต่ hello world) → พอร์ต `standardReroll` ทั้งเก่า (รวม `goto again` + `SeparateRatio`) และใหม่เป็น Python แล้วเทียบกัน **6000 เคส** (1–3 ตัวละครที่ดาเมจผูกกัน · 1–5 ช่อง · roll 0–20 · มี requirement หัก · มีตัวที่ปิด reroll · landscape แบบสุ่ม / concave / มีค่าเสมอ / ต้องเทใส่ช่องเดียว)
- **ชุด substats สุดท้าย + ดาเมจสูงสุด ตรงกันทุกเคส (6000/6000)** — รวมเคสที่โควตา `SeparateRatio` เก่าเคยทำงาน
- ต่างแค่จำนวน run: โค้ดเก่า **รันเกิน 1 รอบ** ใน 2495 เคส · โค้ดใหม่ไม่เคยรันมากกว่า
  - รอบที่เกินเป็น **run สุดท้ายเสมอ** (2495/2495) และส่วนใหญ่ (2322) คือการรันชุดที่เคยวัดไปแล้วซ้ำ
  - สาเหตุคือบั๊กเก่าใน `rerollSubstats`: คอลแรกคืน `true` พร้อมชุดที่ roll ติดลบ → ตั้ง `ans = false` ไปแล้ว → `goto again` คอลซ้ำพบว่าค้นหาจบ คืน `false` แต่ `ans` ไม่ถูกแก้กลับ → `Main.h` รันเพิ่มอีก 1 รอบเปล่า ๆ
  - ไม่กระทบผลสรุป เพราะตัวที่ค้นหาจบแล้วไม่เรียก `changeMaxDamage` อีก · โค้ดใหม่ไม่มีปัญหานี้เพราะเช็คค่าติดลบก่อนคืน `true`
- คอมไพล์ผ่านทั้ง `ManualBuilder.cpp` และ `Application.cpp` (`g++ -std=c++17 -fsyntax-only`) · user รัน sim จริงบนเครื่องตัวเองแล้วผ่าน (2026-09-13)
