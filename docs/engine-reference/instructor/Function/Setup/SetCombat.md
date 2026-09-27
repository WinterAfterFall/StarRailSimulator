# `src/Defination/Function/Setup/SetCombat.h`

## ลำดับการเรียก

`Main.h` เรียก `setup()` หนึ่งครั้งก่อนลูป reroll; ในแต่ละ run เรียก `reset()` → `setStats()` → `startGame()` แล้วเรียก `startWave(i)` ก่อนจำลองแต่ละ wave เมื่อเวลาเกิน `wave[i]` จึงเรียก `endWave()`

## `setup()` — เตรียมระบบครั้งเดียว

ถ้ามี Driver แต่ยังไม่ได้เลือกชนิด จะตั้งเป็น `DOUBLE_TURN` จากนั้นเรียง trigger list หลายกลุ่มด้วย `TriggerFunc::triggerCmp` เพื่อกำหนดลำดับ callback ภายใน event เดียวกัน เลือก `standardReroll` เมื่อโหมด reroll เป็น Standard, ขยาย `avgDmgRecord` ของตัวละครแต่ละตัวให้มีช่องตามจำนวนศัตรู, เรียก `setupList` และเพิ่ม Aha ใน `atvList` เมื่อมี Elation โหมด reroll อีกสองแบบถูก comment ไว้ ไม่ได้เลือกในเส้นทางปัจจุบัน

## `reset()` — ก่อนเริ่ม run ใหม่

ล้างตัวชี้เทิร์นและตัวนับกลาง (`sp` กลับเป็น 3, `punchline` จาก `elationCount`, `currentAtv`, priority, จำนวน heal/HP decrease) แล้วเรียก `basicReset()`, `summonReset()`, `countdownReset()` ตามลำดับ จากนั้นเรียก `resetList`, `memospriteReset()` และ `whenOnFieldList`

ต่อมาเรียกเมธอด requirement ของตัวละครแต่ละตัวในลำดับ ATK → HP → DEF → SPD → EHR, เรียก `tuneStatsList`, คำนวณ ATK/HP/DEF รวมใหม่ให้ตัวละครและ memosprite แล้วเติม `currentHP` ของตัวละครเท่ากับ HP รวม ถ้ามี Elation จะปรับความเร็ว Aha และให้ `CERTIFIED_BANGER` 20 แก่ตัวละคร Path Elation ด้วยบัฟชื่อ `CB Buff` อายุ 2 เทิร์น

`reset()` เคยพิมพ์ Crit DMG ของตัวละครช่อง 1 เพื่อ debug ทุก run โดยไม่มี label/newline; ลบ output นี้แล้วเมื่อ 2026-09-18 เพราะไม่มีผลต่อการคำนวณ

## เริ่มเกมและเปลี่ยน wave

`startGame()` รีเซ็ต ATV ทุกยูนิตผ่าน `allAtvReset()` แล้วเรียก `startGameList`

`startWave(wave)` รีเซ็ต ATV อีกครั้งเฉพาะ wave หลังแรก (`wave != 0`), ล้างตัวนับการถูก Break ของศัตรูแต่ละตัว (`whenToughnessBroken`, `totalToughnessBrokenTime`) แล้วเรียก `startWaveList` ส่วนโค้ดรีเซ็ต Toughness ที่อยู่ใน comment ไม่ได้ทำงาน

`endWave(double totalAtv)` ปัจจุบันเป็นฟังก์ชันว่าง ถึงแม้ `Main.h` จะเรียกเมื่อจบ wave
