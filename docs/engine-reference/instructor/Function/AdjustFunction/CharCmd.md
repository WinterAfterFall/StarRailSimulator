# `src/Defination/Function/AdjustFunction/CharCmd.h`

namespace `CharCmd` รวมคำสั่งช่วยตั้งค่าและ trace ตัวละคร:

- `printUltStart`, `printUltEnd`, `printText` พิมพ์ข้อความพร้อม `currentAtv`
- `findAllyName()` ค้นเฉพาะตัวละครหลัก index 1..`totalAlly` ด้วยชื่อ ไม่รวม memosprite
- `setTechnique`, `setTuneSpeed`, `setRerollCheck`, `timingPrint` ตั้งค่า build/simulation ที่เกี่ยวข้อง; tune speed ค่า 0 จะไม่เปลี่ยน requirement
- `usingSkill()` คืนจริงเสมอใน `SPMode::POSITIVE`; โหมดอื่นคืนจริงเมื่อ `sp > spSafety` (ไม่รวมกรณีเท่ากัน)
