# `src/Setting.h` — configuration และสถานะกลางของการจำลอง

ไฟล์นี้ประกาศและกำหนดค่า global ที่ส่วนต่าง ๆ ของ engine ใช้ร่วมกัน กลุ่ม configuration ได้แก่ `sp`/`maxSp`, `totalWave`/`wave`, `spMode`, `driverType`, `rerollSubstatsMode`, ตัวเลือกพิมพ์ (`printAtv`) และค่าเริ่มต้นของศัตรู (`enemyRes`, `enemyWeak`, `enemyEffectRes`) `setValue()` ในทางเข้ารันเปลี่ยนค่าบางส่วนก่อนเริ่ม setup

## ค่าที่มีผลต่อหนึ่งรอบจำลอง

| ค่า | ค่าเริ่มต้นใน `Setting.h` | ผลและจุดที่เปลี่ยน |
|---|---|---|
| `totalWave`, `wave` | `1`, `{1100,450,450}` | จำนวน wave และขอบเวลา ATV ของแต่ละ wave; `wave` เป็น array ขนาด 3 จึงต้องขยาย array ก่อนใช้มากกว่า 3 wave ปัจจุบัน `setValue()` ของทางเข้าทั้งสองตั้ง `wave[0] = 800.01` |
| `sp`, `maxSp`, `spMode`, `spSafety` | `3`, `5`, `POSITIVE`, `1` | `reset()` ตั้ง SP กลับเป็น 3 ทุก run; `genSkillPoint()` จำกัดเพดานที่ `maxSp`; `CharCmd::usingSkill()` ใช้โหมดและค่า safety ตัดสินการใช้สกิล `setValue()` ทั้งสองทางเข้าตั้ง `spMode = NEGATIVE` |
| `driverType`, `driverNum` | `NONE`, `0` | กำหนดการเลือก driver; `setup()` อาจปรับเป็น `DOUBLE_TURN` เมื่อมี driver แต่ยังไม่เลือกชนิด |
| `rerollSubstatsMode` | `STANDARD` | `setup()` ผูก `standardReroll`; ลูป run ประเมินผลและเลือกชุด substats ถัดไปตาม [Substats_Reset.md](Function/Setup/Substats_Reset.md) |
| `forceBreak` | `1` | เมื่อไม่เป็นศูนย์ บังคับให้ตัวละครตาม index นี้เป็นผู้ทำ Weakness Break; `0` ใช้ผู้โจมตีจริง ดู [Combat.md](Function/Combat/Combat.md) |
| `superBreakMode` | `0` | ถ้าเป็น `1` จะตั้ง ATV ศัตรูเป็นครึ่งหนึ่งของ `maxAtv` ตอน Break ก่อน delay ตามธาตุ ดู [Combat.md](Function/Combat/Combat.md) |
| `printAtv`, `bestBounce` | `0`, `0` | เปิด trace เทิร์นและบังคับ bounce ให้เลือกเป้าหลักตามลำดับ `setValue()` ทั้งสองทางเข้าตั้งเป็น `1` |
| `enemyRes`, `enemyWeak`, `enemyEffectRes` | RES ทุกธาตุ `0`, weakness ทุกธาตุ `true`, effect RES `40` | `setupEnemy()` คัดลอก RES ธาตุและ weakness ไปยังศัตรูใหม่; `enemyEffectRes` ใช้คำนวณ EHR requirement ดู [SetEnemy.md](Function/Setup/SetEnemy.md) และ [CalRequireStats.md](Function/Calculate/CalRequireStats.md) |

กลุ่ม runtime state ได้แก่ `totalAlly`/`totalEnemy`, `charUnit`/`enemyUnit` ที่เป็นเจ้าของ object, รายการ pointer `charList`/`allyList`/`enemyList`/`atvList`, `turn`, `currentAtv`, คิว `actionBar`/`ahaInstantBar`, แต้ม `punchline`, Aha และตัวนับ/flag ระหว่างต่อสู้ การ reset ไม่ได้อยู่รวมที่นี่ แต่กระจายใน [SetCombat.md](Function/Setup/SetCombat.md) และ [Stats_Reset.md](Function/Setup/Stats_Reset.md)

ท้ายไฟล์เก็บ trigger lists แยกตามจังหวะ เช่น Setup/Reset, เริ่ม wave, ก่อน–หลังเทิร์น/แอ็กชัน, การโจมตี, heal, debuff, DoT และพลังงาน `setup()` เรียงรายการเหล่านี้ด้วย priority ก่อนเริ่ม run นอกจากนี้มี `toString(ElementType)` และ `toString(Stats)` สำหรับชื่อที่แสดงผล; enum ของโหมดต่าง ๆ อยู่ใน `src/Enum/StatusEnum.h`
