# `src/Defination/Data/Lightcone/Elation/ElationHertaShop.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `ElationHertaShop` · `lightCone.name` = `"Elation Brimming With Blessings"` · base stats `setAllyBaseStats(953, 529, 463)`

ชื่อในเกม: **Elation Brimming With Blessings** · ได้จาก **Herta Shop** (ไม่มีเจ้าของ)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 529, 463)` | `ElationHertaShop.h:6` |
| ATK 20/25/30/35/40% | บวกถาวร `15 + 5S` | `:12` |
| ผู้สวมใช้ Skill หรือ Ult ใส่เพื่อน 1 คน → เพื่อนคนนั้น Elation 12/15/18/21/24% นาน 2 เทิร์น | `buffList` + `isSameAction(ptr, SKILL / ULT)` + `buffTargetList` มี 1 ตัวและเป็นตัวละคร (`CharUnit`) → `buffSingle(target, …, buffName, 2)` | `:16-22` |
| บัฟหมดอายุ | `afterTurnList` เทิร์นเพื่อน `isBuffEnd` → ลบ Elation คืน | `:24-28` |

## จุดที่ควรระวัง

- ใช้ `buffList` จึงติดเฉพาะ Skill / Ult ที่เป็น **buff action** · ท่าที่เป็น attack action ไม่ติด
- เป้าหมายที่เป็น memosprite ไม่ติด (kit เขียนว่า "ally character") · เป้าหมายเป็นตัวผู้สวมเองก็ติด
- ชื่อบัฟ `"<ชื่อผู้สวม> Elation Brimming"` (ใส่ชื่อเจ้าของนำหน้า) · ใช้ซ้ำใส่คนเดิมตอนบัฟยังอยู่ = ต่ออายุอย่างเดียว
