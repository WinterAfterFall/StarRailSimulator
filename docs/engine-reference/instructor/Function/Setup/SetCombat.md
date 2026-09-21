# `src/Defination/Function/Setup/SetCombat.h`

## ลำดับการเรียก

`Main.h` เรียก `Setup()` หนึ่งครั้งก่อนลูป reroll; ในแต่ละ run เรียก `Reset()` → `Set_Stats()` → `Start_game()` แล้วเรียก `Start_wave(i)` ก่อนจำลองแต่ละ wave เมื่อเวลาเกิน `Wave[i]` จึงเรียก `EndWave()`

## `Setup()` — เตรียมระบบครั้งเดียว

ถ้ามี Driver แต่ยังไม่ได้เลือกชนิด จะตั้งเป็น `DoubleTurn` จากนั้นเรียง trigger list หลายกลุ่มด้วย `TriggerFunc::Trigger_cmp` เพื่อกำหนดลำดับ callback ภายใน event เดียวกัน เลือก `StandardReroll` เมื่อโหมด reroll เป็น Standard, ขยาย `AvgDmgRecord` ของตัวละครแต่ละตัวให้มีช่องตามจำนวนศัตรู, เรียก `Setup_List` และเพิ่ม Aha ใน `atvList` เมื่อมี Elation โหมด reroll อีกสองแบบถูก comment ไว้ ไม่ได้เลือกในเส้นทางปัจจุบัน

## `Reset()` — ก่อนเริ่ม run ใหม่

ล้างตัวชี้เทิร์นและตัวนับกลาง (`sp` กลับเป็น 3, `punchline` จาก `elationCount`, `Current_atv`, priority, จำนวน heal/HP decrease) แล้วเรียก `Basic_reset()`, `Summon_reset()`, `Countdown_reset()` ตามลำดับ จากนั้นเรียก `Reset_List`, `Memosprite_reset()` และ `WhenOnField_List`

ต่อมาเรียกเมธอด requirement ของตัวละครแต่ละตัวในลำดับ ATK → HP → DEF → SPD → EHR, เรียก `Tune_stats_List`, คำนวณ ATK/HP/DEF รวมใหม่ให้ตัวละครและ memosprite แล้วเติม `currentHP` ของตัวละครเท่ากับ HP รวม ถ้ามี Elation จะปรับความเร็ว Aha และให้ `CertifiedBanger` 20 แก่ตัวละคร Path Elation ด้วยบัฟชื่อ `CB Buff` อายุ 2 เทิร์น

`Reset()` เคยพิมพ์ Crit DMG ของตัวละครช่อง 1 เพื่อ debug ทุก run โดยไม่มี label/newline; ลบ output นี้แล้วเมื่อ 2026-09-18 เพราะไม่มีผลต่อการคำนวณ

## เริ่มเกมและเปลี่ยน wave

`Start_game()` รีเซ็ต ATV ทุกยูนิตผ่าน `All_atv_reset()` แล้วเรียก `Start_game_List`

`Start_wave(WAVE)` รีเซ็ต ATV อีกครั้งเฉพาะ wave หลังแรก (`WAVE != 0`), ล้างตัวนับการถูก Break ของศัตรูแต่ละตัว (`when_toughness_broken`, `Total_toughness_broken_time`) แล้วเรียก `Start_wave_List` ส่วนโค้ดรีเซ็ต Toughness ที่อยู่ใน comment ไม่ได้ทำงาน

`EndWave(double Total_atv)` ปัจจุบันเป็นฟังก์ชันว่าง ถึงแม้ `Main.h` จะเรียกเมื่อจบ wave
