# `src/Setting.h` — configuration และสถานะกลางของการจำลอง

ไฟล์นี้ประกาศและกำหนดค่า global ที่ส่วนต่าง ๆ ของ engine ใช้ร่วมกัน กลุ่ม configuration ได้แก่ `sp`/`Max_sp`, `Total_wave`/`Wave`, `spMode`, `driverType`, `rerollSubstatsMode`, ตัวเลือกพิมพ์ (`Print_Atv`) และค่าเริ่มต้นของศัตรู (`Enemy_res`, `Enemy_weak`, `Enemy_effect_res`) `SetValue()` ในทางเข้ารันเปลี่ยนค่าบางส่วนก่อนเริ่ม setup

## ค่าที่มีผลต่อหนึ่งรอบจำลอง

| ค่า | ค่าเริ่มต้นใน `Setting.h` | ผลและจุดที่เปลี่ยน |
|---|---|---|
| `Total_wave`, `Wave` | `1`, `{1100,450,450}` | จำนวน wave และขอบเวลา ATV ของแต่ละ wave; `Wave` เป็น array ขนาด 3 จึงต้องขยาย array ก่อนใช้มากกว่า 3 wave ปัจจุบัน `SetValue()` ของทางเข้าทั้งสองตั้ง `Wave[0] = 800.01` |
| `sp`, `Max_sp`, `spMode`, `Sp_Safety` | `3`, `5`, `Positive`, `1` | `Reset()` ตั้ง SP กลับเป็น 3 ทุก run; `genSkillPoint()` จำกัดเพดานที่ `Max_sp`; `CharCmd::Using_Skill()` ใช้โหมดและค่า safety ตัดสินการใช้สกิล `SetValue()` ทั้งสองทางเข้าตั้ง `spMode = Negative` |
| `driverType`, `Driver_num` | `None`, `0` | กำหนดการเลือก driver; `Setup()` อาจปรับเป็น `DoubleTurn` เมื่อมี driver แต่ยังไม่เลือกชนิด |
| `rerollSubstatsMode` | `Standard` | `Setup()` ผูก `StandardReroll`; ลูป run ประเมินผลและเลือกชุด substats ถัดไปตาม [Substats_Reset.md](Function/Setup/Substats_Reset.md) |
| `Force_break` | `1` | เมื่อไม่เป็นศูนย์ บังคับให้ตัวละครตาม index นี้เป็นผู้ทำ Weakness Break; `0` ใช้ผู้โจมตีจริง ดู [Combat.md](Function/Combat/Combat.md) |
| `SuperBreak__Mode` | `0` | ถ้าเป็น `1` จะตั้ง ATV ศัตรูเป็นครึ่งหนึ่งของ `Max_atv` ตอน Break ก่อน delay ตามธาตุ ดู [Combat.md](Function/Combat/Combat.md) |
| `Print_Atv`, `bestBounce` | `0`, `0` | เปิด trace เทิร์นและบังคับ bounce ให้เลือกเป้าหลักตามลำดับ `SetValue()` ทั้งสองทางเข้าตั้งเป็น `1` |
| `Enemy_res`, `Enemy_weak`, `Enemy_effect_res` | RES ทุกธาตุ `0`, weakness ทุกธาตุ `true`, effect RES `40` | `SetupEnemy()` คัดลอก RES ธาตุและ weakness ไปยังศัตรูใหม่; `Enemy_effect_res` ใช้คำนวณ EHR requirement ดู [SetEnemy.md](Function/Setup/SetEnemy.md) และ [CalRequireStats.md](Function/Calculate/CalRequireStats.md) |

กลุ่ม runtime state ได้แก่ `Total_ally`/`Total_enemy`, `charUnit`/`enemyUnit` ที่เป็นเจ้าของ object, รายการ pointer `charList`/`allyList`/`enemyList`/`atvList`, `turn`, `Current_atv`, คิว `Action_bar`/`AhaInstantBar`, แต้ม `punchline`, Aha และตัวนับ/flag ระหว่างต่อสู้ การ reset ไม่ได้อยู่รวมที่นี่ แต่กระจายใน [SetCombat.md](Function/Setup/SetCombat.md) และ [Stats_Reset.md](Function/Setup/Stats_Reset.md)

ท้ายไฟล์เก็บ trigger lists แยกตามจังหวะ เช่น Setup/Reset, เริ่ม wave, ก่อน–หลังเทิร์น/แอ็กชัน, การโจมตี, heal, debuff, DoT และพลังงาน `Setup()` เรียงรายการเหล่านี้ด้วย priority ก่อนเริ่ม run นอกจากนี้มี `toString(ElementType)` และ `toString(Stats)` สำหรับชื่อที่แสดงผล; enum ของโหมดต่าง ๆ อยู่ใน `src/Enum/StatusEnum.h`
