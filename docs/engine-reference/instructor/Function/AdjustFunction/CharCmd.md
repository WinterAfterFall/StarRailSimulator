# `src/Defination/Function/AdjustFunction/CharCmd.h`

namespace `CharCmd` รวมคำสั่งช่วยตั้งค่าและ trace ตัวละคร:

- `printUltStart`, `printUltEnd`, `printText` พิมพ์ข้อความพร้อม `Current_atv`
- `findAllyName()` ค้นเฉพาะตัวละครหลัก index 1..`Total_ally` ด้วยชื่อ ไม่รวม memosprite
- `Set_Technique`, `Set_Tune_Speed`, `Set_Reroll_check`, `Timing_print` ตั้งค่า build/simulation ที่เกี่ยวข้อง; tune speed ค่า 0 จะไม่เปลี่ยน requirement
- `Using_Skill()` คืนจริงเสมอใน `SPMode::Positive`; โหมดอื่นคืนจริงเมื่อ `sp > Sp_Safety` (ไม่รวมกรณีเท่ากัน)
