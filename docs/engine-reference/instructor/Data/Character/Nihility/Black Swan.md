# `src/Defination/Data/Character/Nihility/Black Swan.h`

หลัง Arcana สร้างความเสียหายตอน `DotBeforeTurn` ถ้าไม่มี `Arcana Ignore` จะลด stack ลงครึ่งหนึ่งแบบหารจำนวนเต็ม แต่คงขั้นต่ำ 1 stack (user ยืนยัน 2026-09-21) ผ่าน `arcanaStacksAfterTick()` เช่น 1 → 1, 2 → 1, 4 → 2 จึงไม่ทำให้ Arcana กลายเป็นสถานะ 0 stack โดยการลดตามรอบนี้; ถ้ามี `Arcana Ignore` จะไม่ลด stack และล้าง flag ดังกล่าวแทน

`Black SwanV1.h` ที่ยังอยู่ใน repo ใช้หลักคงขั้นต่ำ 1 stack แบบตรง ๆ เช่นกัน แต่มีวิธีลด stack ต่างจาก implementation ปัจจุบัน
