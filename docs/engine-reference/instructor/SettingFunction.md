# `SettingFunction.h` — รับตัวเลือกสำหรับทางเข้า interactive

`askYesNo()` กับ `askNoYes()` อ่านทั้งบรรทัดและรับ yes/y/no/n โดยไม่สนตัวพิมพ์ใหญ่–เล็ก; Enter เปล่าเป็น yes สำหรับตัวแรกและเป็น no สำหรับตัวหลัง ชื่อฟังก์ชันจึงกำหนดค่าปริยายต่างกัน

`CharSelect` เก็บ callback ของตัวละคร (รับ Eidolon และ callback อุปกรณ์), ค่า Eidolon และ callback ของ Light Cone/Relic/Planar `CharSelector()`, `LightConeSelector()`, `RelicSelector()` และ `PlanarSelector()` แปลงชื่อที่พิมพ์เป็น callback; หากชื่อไม่รู้จักจะถามใหม่ บางอุปกรณ์ถามเงื่อนไขหรือค่า superimpose เพิ่ม `BuildSelector()` เรียก selector ทั้งสี่แล้วสะสมผลไว้ใน `CharSelectList`; การสร้างตัวละครจริงเกิดภายหลังใน [Application.md](Application.md)

`EnemySelector()` ปัจจุบันถามจำนวนศัตรูแต่ยังไม่ใช้ `Tenemy` ถ้าตอบ `yes` ที่คำถามกำหนดสถานะศัตรูเอง จะสร้างศัตรูค่าคงที่สองตัว; ถ้าตอบ `no` หรือกด Enter จะไม่สร้างศัตรู เพราะสาขานั้นยังไม่ implement ชื่อคำถามจึงชวนเข้าใจผิด User ยืนยันว่าใช้สองตัวชั่วคราว; งานต่อบันทึกใน [future-improvements.md](../future-improvements.md)
