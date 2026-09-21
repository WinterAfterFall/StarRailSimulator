# `src/Setting.h` — configuration และสถานะกลางของการจำลอง

ไฟล์นี้ประกาศและกำหนดค่า global ที่ส่วนต่าง ๆ ของ engine ใช้ร่วมกัน กลุ่ม configuration ได้แก่ `sp`/`Max_sp`, `Total_wave`/`Wave`, `spMode`, `driverType`, `rerollSubstatsMode`, ตัวเลือกพิมพ์ (`Print_Atv`) และค่าเริ่มต้นของศัตรู (`Enemy_res`, `Enemy_weak`, `Enemy_effect_res`) `SetValue()` ในทางเข้ารันเปลี่ยนค่าบางส่วนก่อนเริ่ม setup

กลุ่ม runtime state ได้แก่ `Total_ally`/`Total_enemy`, `charUnit`/`enemyUnit` ที่เป็นเจ้าของ object, รายการ pointer `charList`/`allyList`/`enemyList`/`atvList`, `turn`, `Current_atv`, คิว `Action_bar`/`AhaInstantBar`, แต้ม `punchline`, Aha และตัวนับ/flag ระหว่างต่อสู้ การ reset ไม่ได้อยู่รวมที่นี่ แต่กระจายใน [SetCombat.md](Function/Setup/SetCombat.md) และ [Stats_Reset.md](Function/Setup/Stats_Reset.md)

ท้ายไฟล์เก็บ trigger lists แยกตามจังหวะ เช่น Setup/Reset, เริ่ม wave, ก่อน–หลังเทิร์น/แอ็กชัน, การโจมตี, heal, debuff, DoT และพลังงาน `Setup()` เรียงรายการเหล่านี้ด้วย priority ก่อนเริ่ม run นอกจากนี้มี `toString(ElementType)` และ `toString(Stats)` สำหรับชื่อที่แสดงผล; enum ของโหมดต่าง ๆ อยู่ใน `src/Enum/StatusEnum.h`
