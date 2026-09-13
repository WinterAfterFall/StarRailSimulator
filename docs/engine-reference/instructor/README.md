# instructor — คู่มือการทำงานของโค้ด `src/Defination/`

เอกสารชุดนี้ mirror โครงโฟลเดอร์ของ `src/Defination/` ทุกโฟลเดอร์ เอาไว้บันทึกว่าโค้ดแต่ละไฟล์ทำงานยังไง — เขียนจากการไล่อ่านโค้ดทีละไฟล์กับ user (ย้ายมาจาก `docs/engine-reference/unit.md` เมื่อ 2026-09-13)

## วิธีอ่าน

- **path เดียวกับโค้ด** — `src/Defination/X/Y.h` → `instructor/X/Y.md` · ทุกโฟลเดอร์มี `README.md`
- **ไฟล์ว่าง = ยังไม่ได้ไล่ หรือยังไม่มีข้อมูลละเอียด**
- ไม่มี `.md` ให้ไฟล์ที่เป็นแค่รวม include: `Library.h` · `include.h` · `All_*.h`
- **กลไกอธิบายไว้ที่ไฟล์ของโค้ดที่ทำงานจริง** — ไฟล์คลาสมีตาราง field แล้วลิงก์ชี้ไป · เรื่องที่เล่ากลไกเดียวข้ามหลายไฟล์เก็บไว้ที่ไฟล์หลักของกลไกนั้นทั้งก้อน
- ของที่นิยามนอก `Defination/` (`src/Enum/` · `src/Setting.h` · `Main.h`) อธิบายไว้ที่ไฟล์ที่ใช้มันจริง หรือในไฟล์นี้
- บั๊กทั้งหมด → [BUGS.md](BUGS.md) · บันทึกการทำงานแต่ละวัน + รายการค้าง → [LOG.md](LOG.md)
- เอกสารคู่กัน: [`character-implementation-notes.md`](../../character-implementation-notes.md) (วิธีเขียนตัวละคร) · [`future-improvements.md`](../future-improvements.md) (ของที่รู้ว่าควรปรับ แต่เลื่อนไว้)

## แผนที่สถานะ

✅ ไล่ครบ · 🚧 มีเนื้อหาบางส่วน · ⬜ ยังไม่แตะ (ทุกไฟล์ในโฟลเดอร์ว่าง)

| โฟลเดอร์ | สถานะ | ไฟล์ที่มีเนื้อหา |
|---|---|---|
| `(root)` | 🚧 | [BUGS.md](BUGS.md) · [LOG.md](LOG.md) |
| `Class/` | ⬜ | — |
| `Class/ActionData/` | 🚧 | 🚧 [EnemyActionData.md](Class/ActionData/EnemyActionData.md) |
| `Class/CombatData/` | ⬜ | — |
| `Class/Trigger/` | ⬜ | — |
| `Class/Unit/` | 🚧 | [README.md](Class/Unit/README.md) · ✅ [ActionValueStats.md](Class/Unit/ActionValueStats.md) · ✅ [AllyUnit.md](Class/Unit/AllyUnit.md) · 🚧 [CharUnit.md](Class/Unit/CharUnit.md) · ✅ [Unit.md](Class/Unit/Unit.md) |
| `Data/` | 🚧 | [README.md](Data/README.md) |
| `Data/Character/` | ⬜ | — |
| `Data/Character/Abundance/` | ⬜ | — |
| `Data/Character/Destruction/` | ⬜ | — |
| `Data/Character/Elation/` | ⬜ | — |
| `Data/Character/Erudition/` | ⬜ | — |
| `Data/Character/Harmony/` | ⬜ | — |
| `Data/Character/Nihility/` | ⬜ | — |
| `Data/Character/Preservation/` | ⬜ | — |
| `Data/Character/Remembrance/` | ⬜ | — |
| `Data/Character/The Hunt/` | ⬜ | — |
| `Data/Lightcone/` | ⬜ | — |
| `Data/Lightcone/Abundance/` | ⬜ | — |
| `Data/Lightcone/Destruction/` | ⬜ | — |
| `Data/Lightcone/Elation/` | ⬜ | — |
| `Data/Lightcone/Erudition/` | ⬜ | — |
| `Data/Lightcone/Harmony/` | ⬜ | — |
| `Data/Lightcone/Nihility/` | ⬜ | — |
| `Data/Lightcone/Preservation/` | ⬜ | — |
| `Data/Lightcone/Remembrance/` | ⬜ | — |
| `Data/Lightcone/The_Hunt/` | ⬜ | — |
| `Data/Planar/` | ⬜ | — |
| `Data/Relic/` | ⬜ | — |
| `Function/` | ⬜ | — |
| `Function/AdjustFunction/` | 🚧 | 🚧 [FormulaCheck.md](Function/AdjustFunction/FormulaCheck.md) |
| `Function/Calculate/` | 🚧 | 🚧 [CalDamageNote.md](Function/Calculate/CalDamageNote.md) |
| `Function/Combat/` | 🚧 | 🚧 [Action_value.md](Function/Combat/Action_value.md) · 🚧 [Buff_Stats.md](Function/Combat/Buff_Stats.md) · 🚧 [ChangeHP.md](Function/Combat/ChangeHP.md) · 🚧 [Combat.md](Function/Combat/Combat.md) · 🚧 [Energy.md](Function/Combat/Energy.md) |
| `Function/Event/` | ⬜ | — |
| `Function/Print/` | ⬜ | — |
| `Function/Setup/` | 🚧 | 🚧 [Stats_Reset.md](Function/Setup/Stats_Reset.md) · 🚧 [Substats_Reset.md](Function/Setup/Substats_Reset.md) |

## ระบบ ATV / ลำดับเทิร์น (แนวคิด)

โมเดล "ลู่วิ่งวงกลม": ทุก unit วิ่งบนลู่ ใครเข้าเส้นชัยได้เล่นเทิร์นแล้ววิ่งรอบใหม่ ทุกอย่างเป็น real-time

| ตัวแปร | ความหมาย |
|---|---|
| `atv` (ต่อ unit) | **เวลาที่เหลือ**จนกว่า unit นี้จะได้เทิร์น (นับถอยหลังเข้าใกล้ 0) |
| `Max_atv` (ต่อ unit) | เวลาโดยประมาณต่อ 1 รอบวิ่งของ unit นั้น ณ ความเร็วปัจจุบัน = `10000 / effectiveSpeed` |
| `Current_atv` (global, `Setting.h`) | จำนวน "วินาที" ที่ผ่านไปตั้งแต่เริ่ม simulate (นาฬิกาเดินหน้าอย่างเดียว) |
| `turn` (global `ActionValueStats*`) | unit ที่กำลังเล่นเทิร์นอยู่ตอนนี้ |

`K_const = 10000` (`Trigger_Function.h:10`)
`effectiveSpeed = baseSpeed·(1 + speedPercent/100) + flatSpeed`

> การ debug buff-drift ในหน่วยความจำ ("ดู stats ที่ ATV 1000/2000/…/5000") = ดูตามค่า `Current_atv`

### คำศัพท์: run / wave / game (สำคัญ — โครงลูปใน `Main.h`)

```
Setup()                          // ครั้งเดียว — สร้างตัวละคร + register lambda ทุกตัว
while(1) {                        // ── REROLL LOOP: 1 รอบ = 1 "run" (substats ชุดหนึ่ง) ──
    Reset()                      //   per-run: Basic_reset / Summon_reset / Countdown_reset / Reset_List / Memosprite_reset
    Set_Stats(chars)             //   per-run: ใส่ substats ของ run นี้
    Start_game()                 //   per-run: All_atv_reset + Start_game_List
    for (i = 0; i < Total_wave; i++) {   // ── WAVE LOOP: หลาย wave ต่อ 1 run ──
        Current_atv = 0          //     per-wave
        Start_wave(i)            //     per-wave: (All_atv_reset ถ้า i!=0) + Start_wave_List
        while(1) { Find_turn(); Atv_fix(); Take_action(); }   // turn loop จนกว่า Current_atv > Wave[i]
    }
    Cal_DamageSummary(); printRoundResult();
    if (Reroll_substats()) break;   // ลอง substats ชุดถัดไป หรือหยุด
}
```

| คำ | หมายถึง | อะไร reset ตรงนี้ |
|---|---|---|
| **run** (รอบรัน / iteration ของ reroll loop) | รัน sim ครบ 1 จบ ด้วย substats ชุดหนึ่ง — โปรแกรมทำหลาย run เพื่อวนหา substats ที่ดีสุด | `Reset()` → `Basic_reset` `Memosprite_reset` `Summon_reset` `Countdown_reset` · `nextForwardPriority = 0` |
| **wave** | 1 ยกของศัตรู — 1 run มีได้หลาย wave (`Total_wave`) | `Start_wave` → `All_atv_reset()` (เฉพาะ wave ที่ 2 เป็นต้นไป) + `Start_wave_List` · `Current_atv = 0` |
| **game start** = ต้น run (ก่อน wave 0) | จุดที่ `Reset()` + `Start_game()` รัน | — |

⚠️ **memosprite / summon / countdown reset "ต่อ run" ไม่ใช่ "ต่อ wave"** — ตัวที่ถูก summon ใน wave 0 จะยังอยู่ต่อไป wave 1, 2, … ใน run เดียวกัน
