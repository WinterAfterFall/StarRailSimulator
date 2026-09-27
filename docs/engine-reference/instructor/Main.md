# `Main.h` — ลูปจำลองของทางเข้า interactive

`setValue()` กำหนดค่าตั้งต้นของ driver, SP, wave แรก, การพิมพ์ ATV, bounce และ Standard reroll `setCharacterPtr()` ชี้ `char1`–`char4` ไปยัง `charUnit[1..4]` ที่สร้างไว้ก่อนแล้ว

`mainLoop()` เรียก `setup()` หนึ่งครั้ง แล้ววนรอบ run: `reset()`, ใส่ substats ด้วย `setStats()` ให้ตัวละครทุกคน, และ `startGame()` ในแต่ละ wave จะตั้ง `currentAtv = 0`, เรียก `startWave(i)` กับ `dealDamage()` ก่อนเข้าสู่ลูปเทิร์น `findTurn()` เลือกผู้เล่นถัดไป, `atvFix(turn->atv)` เลื่อนเวลา, ถ้าเกิน `wave[i]` จะเรียก `endWave()` และออกจาก wave; มิฉะนั้นเรียก `takeAction()`

เมื่อจบทุก wave ใน run จะเรียก `calDamageSummary()` และ `printRoundResult()` แล้วใช้ `rerollSubstats()` ตัดสินใจวนอีกครั้งหรือจบ เมื่อจบทั้งหมดจึงเรียก `printSummaryResult()` และรอ Enter ก่อนออก ดู [SetCombat.md](Function/Setup/SetCombat.md) สำหรับงานของแต่ละช่วง setup/reset/wave
