# instructor — คู่มือการทำงานของโค้ด `src/Defination/`

เอกสารชุดนี้ mirror โครงโฟลเดอร์ของ `src/Defination/` และไฟล์นอก `Data/` ที่สำรวจแล้วใน `src/Declaration/` กับ `src/Enum/` เอาไว้บันทึกว่าโค้ดแต่ละไฟล์ทำงานยังไง — เขียนจากการไล่อ่านโค้ดทีละไฟล์กับ user (ย้ายมาจาก `docs/engine-reference/unit.md` เมื่อ 2026-09-13)

## วิธีอ่าน

- **path เดียวกับโค้ด** — `src/Defination/X/Y.h` → `instructor/X/Y.md`; `src/Declaration/X/Y.h` → `instructor/Declaration/X/Y.md`; `src/Enum/Y.h` → `instructor/Enum/Y.md` · ทุกโฟลเดอร์ที่เพิ่มใหม่มี `README.md`
- **ไฟล์คู่มือรายโค้ดที่ว่าง = ยังไม่ได้ไล่ หรือยังไม่มีข้อมูลละเอียด**; `README.md` ของบางโฟลเดอร์ยังเป็น placeholder สำหรับสารบัญ ไม่ใช่หลักฐานว่าสำรวจโค้ดในหมวดนั้นไม่ครบ
- ไม่มี `.md` ให้ไฟล์ที่เป็นแค่รวม include: `Library.h` · `include.h` · `All_*.h`
- **กลไกอธิบายไว้ที่ไฟล์ของโค้ดที่ทำงานจริง** — ไฟล์คลาสมีตาราง field แล้วลิงก์ชี้ไป · เรื่องที่เล่ากลไกเดียวข้ามหลายไฟล์เก็บไว้ที่ไฟล์หลักของกลไกนั้นทั้งก้อน
- โค้ดนอก `Defination/` ที่สำรวจแล้วมีคู่มือรายไฟล์ในรากโฟลเดอร์นี้ เช่น [Setting.md](Setting.md), [StdInclude.md](StdInclude.md), [Application.md](Application.md), [SettingFunction.md](SettingFunction.md), [Main.md](Main.md) และ [ManualBuilder.md](ManualBuilder.md); คำประกาศอยู่ใน [Declaration/](Declaration/README.md) และ enum อยู่ใน [Enum/](Enum/README.md)
- ทางเข้ารันแบบ interactive คือ `Application.cpp` → `SettingFunction.h` → `Main.h`; `ManualBuilder.cpp` เป็นทางเข้าอีกแบบสำหรับกำหนดทีมในโค้ดโดยตรง (ไม่ใช่ไฟล์ที่ `Application.cpp` include)
- บั๊กทั้งหมด → [BUGS.md](BUGS.md) · บันทึกการทำงานแต่ละวัน + รายการค้าง → [LOG.md](LOG.md)
- เอกสารคู่กัน: [`character-implementation-notes.md`](../../character-implementation-notes.md) (วิธีเขียนตัวละคร) · [`build-run-and-test.md`](../../build-run-and-test.md) (วิธี build/run/test) · [`future-improvements.md`](../future-improvements.md) (ของที่รู้ว่าควรปรับ แต่เลื่อนไว้)

## แผนที่สถานะ

ณ 2026-09-21 ไฟล์โค้ดนอก `Data/` ที่อยู่ในขอบเขต mirror มี `.md` คู่ครบแล้ว (ไม่รวม `Library.h`/`include.h` ที่เป็นไฟล์รวม) แต่ความละเอียดของแต่ละไฟล์ยังต่างกัน: ไฟล์ `Declaration/` หลายไฟล์เพียงบันทึกบทบาทและชี้ไปนิยามจริง ไม่ควรตีความว่าการมีไฟล์หมายถึงพิสูจน์ทุกเส้นทางการรันแล้ว ดูจุดต่อที่อัปเดตล่าสุดใน [LOG.md](LOG.md)

`Data/` ยังเป็นงานใหญ่ที่ไม่ได้ไล่แบบทีละไฟล์เป็นส่วนมาก แม้บางไฟล์ เช่น [Black Swan.md](Data/Character/Nihility/Black%20Swan.md) มีบันทึกจากการตรวจบั๊กแล้ว จึงอย่าใช้การมีไฟล์ `.md` เป็นหลักฐานว่าสำรวจชุดตัวละคร/อุปกรณ์นั้นครบ

## ทางเข้ารันและการเลือกชุดจำลอง

`Application.cpp::main()` เรียก `SetValue()` ตั้งค่าตั้งต้น, รับจำนวนตัวละคร, เรียก `BuildSelector()` เก็บตัวเลือกตัวละคร/Light Cone/Relic/Planar เป็น callback ใน `CharSelectList`, แล้วจึงเรียก callback `Setup()` ของแต่ละตัวละครให้สร้างยูนิตจริง หลัง `EnemySelector()` จะผูก `Char1`–`Char4` กับ `charUnit[1..4]`, เปิดการตรวจสูตร Crit ให้ `Char1` และเข้า `Main()`

`SettingFunction.h` เป็นตัวแปลงชื่อที่ผู้ใช้พิมพ์เป็น callback ของแต่ละชุดอุปกรณ์; `askYesNo()` ถือ Enter เป็น yes ส่วน `askNoYes()` ถือ Enter เป็น no ทั้งคู่รับข้อความด้วย `getline()` `EnemySelector()` ปัจจุบันถามจำนวนศัตรูแต่ไม่ได้ใช้ตัวเลขนั้น: ต้องตอบ `yes` ที่คำถามกำหนดสถานะศัตรูเอง จึงจะสร้างศัตรูค่าคงที่ 2 ตัว (`Main` และ `Adjacent`); ตอบ `no` หรือ Enter จะไม่สร้างศัตรู เพราะสาขานั้นยังไม่ implement ชื่อคำถามยังชวนเข้าใจผิด ดูวิธีรันใน [build-run-and-test.md](../../build-run-and-test.md)

`Main.h::Main()` เรียก `Setup()` หนึ่งครั้ง แล้ววน run เพื่อรีเซ็ต/สุ่ม substats/จำลองทุก wave/รวมดาเมจ/พิมพ์ผล ก่อนให้ `Reroll_substats()` ตัดสินว่าจะวนอีกหรือจบ; ลำดับย่อยดูหัวข้อ run/wave ด้านล่าง `ManualBuilder.cpp` ใช้ชุดตัวละคร/อุปกรณ์และศัตรูที่เขียนไว้ในไฟล์ พร้อมเปิดตัวช่วยพิมพ์เวลาของตัวละครทั้งสี่ แล้วทำลูปจำลองแบบเดียวกันภายใน `main()` ของตัวเอง จึงเป็นทางเข้าแยกสำหรับ build คนละ executable

ค่าที่ทางเข้ารันแก้ เช่น `Wave`, `spMode`, `driverType`, `rerollSubstatsMode` อยู่ใน `src/Setting.h` พร้อม global state ของการจำลอง: จำนวนยูนิต, รายการตัวละคร/ศัตรู/ยูนิตในสนาม, คิว action, ตัวชี้เทิร์นและเวลา ATV, และ trigger lists `Setup()` เรียง trigger lists ก่อนเริ่ม run ส่วน `Reset()` ล้างค่าต่อ run ตามที่อธิบายใน [SetCombat.md](Function/Setup/SetCombat.md) `src/Enum/StatusEnum.h` นิยามโหมด Driver/SP/Phase/reroll ที่ค่าตั้งต้นเหล่านี้ใช้

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
