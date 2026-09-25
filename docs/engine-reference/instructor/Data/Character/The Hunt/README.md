# `src/Defination/Data/Character/The Hunt/`

**มีตัวละครเดียว**: `Archer.h` (ตัวละคร collab ชุดเดียวกับ `../Destruction/Saber.h`)

ดู `Archer.md`

## สิ่งที่ยังไม่มีในโฟลเดอร์นี้

path The Hunt ในเกมมีตัวละครอีกหลายตัว (Seele, Feixiao, Dan Heng, Yanqing, Sushang, Topaz, Boothill, Moze, ...) ซึ่งอยู่ในคิว `../../IMPLEMENT-QUEUE.md`

**สิ่งที่ `Archer.h` ให้เป็นแบบอย่างได้เมื่อทำตัว The Hunt ตัวอื่น**
- โครงของ DPS เป้าเดียวที่มี FuA (`Charge` + `AfterAttackActionList`)
- ท่าที่กิน SP มากกว่า 1 แต้ม (`genSkillPoint(ac, -2)`)
- การกด Skill ต่อเนื่องหลายครั้งในเทิร์นเดียวพร้อมตัวหยุด 2 ชั้น
- `Max_sp` (แก้เพดาน SP ของทีม — มีแค่ Archer กับ Hanabi)
