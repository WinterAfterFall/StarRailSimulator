# `ManualBuilder.cpp` — ทางเข้ารันที่กำหนดทีมในโค้ด

ไฟล์นี้มี `main()` ของตัวเอง จึงเป็นทางเข้าแยกจาก `Application.cpp` ไม่ใช่โค้ดที่รันต่อกันใน executable เดียวกัน `SetValue()` ตั้งค่าจำลองเริ่มต้นเช่น `Wave[0]`, `spMode`, `driverType` และโหมด reroll; `SetCharacterPtr()` ผูก `Char1`–`Char4` กับ `charUnit[1..4]`

ภายใน `main()` มีตัวอย่าง `Setup()` ของตัวละคร/อุปกรณ์จำนวนมากที่ comment ไว้ ชุดที่ไม่ comment ในโค้ดปัจจุบันคือ FireFly, RuanMei, Fugue และ Gallagher จากนั้นเปิด `CharCmd::Timing_print()` ให้ตัวละครสี่ช่องและสร้างศัตรูสองตัวด้วย `SetupEnemy()` ส่วนการปรับจุดอ่อนศัตรูและตัวเลือกปรับการรันอื่น ๆ หลายรายการยังอยู่ใน comment

หลัง `Setup()` หนึ่งครั้ง ไฟล์นี้มีลูป run/wave/turn ของตัวเอง: `Reset()` → `Set_Stats()` → `Start_game()` → `Start_wave()`/`Deal_damage()` → `Find_turn()`/`Atv_fix()`/`Take_action()` แล้วรวมดาเมจ พิมพ์ผล และถาม `Reroll_substats()` ว่าจะวนอีกหรือไม่ โครงนี้ซ้ำกับ [Main.md](Main.md); หากแก้ลำดับจำลองภายหลังต้องตรวจทั้งสองทางเข้า
