# `src/Defination/Data/Lightcone/Elation/Tomorrow Together.h`

`namespace Elation_Lightcone` · ฟังก์ชัน `TomorrowTogether` · `lightCone.name` = `"Tomorrow, Together"` · base stats `setAllyBaseStats(953, 476, 331)` · 4★ ไม่มีเจ้าของ

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `Tomorrow Together.h:6` |
| CRIT DMG 12/15/18/21/24% | บวกถาวร `9 + 3S` | `:12` |
| หลังผู้สวมใช้ Ult → เพื่อนทุกคน Elation 8/9/10/11/12% นาน 1 เทิร์น | `afterAllyActionList` + `act->isSameAction(ptr, AType::ULT)` → `buffAllAlly(…, buffName, 1)` | `:16-19` |
| บัฟหมดอายุ | `afterTurnList` ของเทิร์นเพื่อนแต่ละคน `isBuffEnd(ally, buffName)` → ลบ Elation คืน | `:21-25` |

## จุดที่ควรระวัง

- ชื่อบัฟคือ `"<ชื่อผู้สวม> Tomorrow Together"` (ใส่ชื่อเจ้าของนำหน้าตามกฎ prefix) · สวม 2 คนจึงได้บัฟ 2 ก้อนแยกกัน
- นับ 1 เทิร์นแยกตามเทิร์นของเพื่อนแต่ละคน · ถ้าใช้ Ult ซ้ำตอนบัฟยังอยู่ จะต่ออายุอย่างเดียว ไม่บวกซ้ำ (`isHaveToAddBuff` แบบ 3 args ใน `buffSingle`)
