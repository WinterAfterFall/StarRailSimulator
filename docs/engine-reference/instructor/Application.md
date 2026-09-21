# `Application.cpp` — ทางเข้ารันแบบ interactive

`main()` เรียก `SetValue()` ตั้งค่าเริ่มต้น แล้วถามจำนวนตัวละครและเรียก `BuildSelector()` ตามจำนวนนั้น ตัวเลือกแต่ละคนถูกเก็บเป็น `CharSelect` ซึ่งมี callback สำหรับตัวละคร, Light Cone, Relic และ Planar จากนั้นจึงวนเรียก callback ตัวละครพร้อม Eidolon และ callback อุปกรณ์เพื่อสร้างยูนิตจริง

หลังสร้างทีม จะเรียก `EnemySelector()` เพื่อสร้างศัตรู, `SetCharacterPtr()` เพื่อผูก `Char1`–`Char4` กับ `charUnit[1..4]`, เปิด `DmgFormulaMode::Crit` ให้ `Char1`, แล้วเรียก `Main()` เข้าลูปจำลอง

ไฟล์นี้ไม่ implement ตัวเลือกหรือสูตรเอง; ดู [SettingFunction.md](SettingFunction.md) สำหรับการรับตัวเลือก และ [Main.md](Main.md) สำหรับลำดับจำลอง ขณะนี้เส้นทางเลือกศัตรูยัง fix สองตัวชั่วคราวตามที่ user ยืนยัน (ดู [future-improvements.md](../future-improvements.md))
