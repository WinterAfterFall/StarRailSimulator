# `Main.h` — ลูปจำลองของทางเข้า interactive

`SetValue()` กำหนดค่าตั้งต้นของ driver, SP, wave แรก, การพิมพ์ ATV, bounce และ Standard reroll `SetCharacterPtr()` ชี้ `Char1`–`Char4` ไปยัง `charUnit[1..4]` ที่สร้างไว้ก่อนแล้ว

`Main()` เรียก `Setup()` หนึ่งครั้ง แล้ววนรอบ run: `Reset()`, ใส่ substats ด้วย `Set_Stats()` ให้ตัวละครทุกคน, และ `Start_game()` ในแต่ละ wave จะตั้ง `Current_atv = 0`, เรียก `Start_wave(i)` กับ `Deal_damage()` ก่อนเข้าสู่ลูปเทิร์น `Find_turn()` เลือกผู้เล่นถัดไป, `Atv_fix(turn->atv)` เลื่อนเวลา, ถ้าเกิน `Wave[i]` จะเรียก `EndWave()` และออกจาก wave; มิฉะนั้นเรียก `Take_action()`

เมื่อจบทุก wave ใน run จะเรียก `Cal_DamageSummary()` และ `printRoundResult()` แล้วใช้ `Reroll_substats()` ตัดสินใจวนอีกครั้งหรือจบ เมื่อจบทั้งหมดจึงเรียก `printSummaryResult()` และรอ Enter ก่อนออก ดู [SetCombat.md](Function/Setup/SetCombat.md) สำหรับงานของแต่ละช่วง setup/reset/wave
