# `ManualBuilder.cpp` — ทางเข้ารันที่กำหนดทีมในโค้ด

ไฟล์นี้มี `main()` ของตัวเอง จึงเป็นทางเข้าแยกจาก `Application.cpp` ไม่ใช่โค้ดที่รันต่อกันใน executable เดียวกัน `setValue()` ตั้งค่าจำลองเริ่มต้นเช่น `wave[0]`, `spMode`, `driverType` และโหมด reroll; `setCharacterPtr()` ผูก `char1`–`char4` กับ `charUnit[1..4]`

ภายใน `main()` มีตัวอย่าง `setup()` ของตัวละคร/อุปกรณ์จำนวนมากที่ comment ไว้ ชุดที่ไม่ comment ในโค้ดปัจจุบันคือ FireFly, RuanMei, Fugue และ Gallagher จากนั้นเปิด `CharCmd::timingPrint()` ให้ตัวละครสี่ช่องและสร้างศัตรูสองตัวด้วย `setupEnemy()` ส่วนการปรับจุดอ่อนศัตรูและตัวเลือกปรับการรันอื่น ๆ หลายรายการยังอยู่ใน comment

หลัง `setup()` หนึ่งครั้ง ไฟล์นี้มีลูป run/wave/turn ของตัวเอง: `reset()` → `setStats()` → `startGame()` → `startWave()`/`dealDamage()` → `findTurn()`/`atvFix()`/`takeAction()` แล้วรวมดาเมจ พิมพ์ผล และถาม `rerollSubstats()` ว่าจะวนอีกหรือไม่ โครงนี้ซ้ำกับ [Main.md](Main.md); หากแก้ลำดับจำลองภายหลังต้องตรวจทั้งสองทางเข้า
