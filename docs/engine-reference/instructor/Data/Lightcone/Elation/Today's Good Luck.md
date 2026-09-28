# `src/Defination/Data/Lightcone/Elation/Today's Good Luck.h`

`namespace Elation_Lightcone` · `lightCone.name` = `"Today's Good Luck"` · base stats `setAllyBaseStats(953, 529, 397)`

ฟังก์ชันชื่อ `TodayGoodLuck`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 529, 397)` | `Today's Good Luck.h:5` |
| CR `10 + 2S` | บวกถาวร | `:9` |
| ผู้สวมใช้ Elation Skill → Elation `10 + 2S` ต่อ stack (สูงสุด 2) | `whenUseElationSkillList` (เฉพาะ `ally == ptr`) → `buffStackSingle(…, 1, 2, "TDGL Stack")` · ไม่มีอายุ | `:12-16` |

## จุดที่ควรระวัง

**stack ไม่มีอายุและไม่มีการถอน** → สะสมจนเต็ม 2 แล้วค้างตลอดการต่อสู้

> **แก้ 2026-09-28** (user สั่ง): เดิมใช้ `beforeAllyActionList` + `act->isSameAction(ptr, AType::ELATION_SKILL)` → ใน Aha Instant ยิงครั้งเดียวด้วย action ตัวแรกเป็นตัวแทน จึงติดเฉพาะเมื่อผู้สวมอยู่หัวคิว และไม่ติดเลยถ้า Elation Skill ของผู้สวมไม่สร้าง action · ตอนนี้ใช้ `whenUseElationSkillList` ที่ยิงแยกทุกตัวละคร (ดู `../../../Function/Event/Event.md`)
