# `src/Defination/Data/Lightcone/Destruction/Phainon LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Phainon_LC"` · base stats `setAllyBaseStats(953, 687, 397)`

**signature ของ Phainon** (ดู `../../Character/Destruction/Phainon.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 687, 397)` | `Phainon LC.h:5` |
| SPD `10 + 2S` (ค่าคงที่) | บวก `baseSpeed` ตรง ๆ ตอน setup (นอก trigger) | `:7` |
| ignore DEF `13.5 + 4.5S`% | บวกถาวร | `:9` |
| ผู้สวมกด Ult → DMG `42 + 18S`% นาน 1 เทิร์น ("Blazing Sun") | `whenUseUltList` + `isSameOwner` | `:12-16` |
| ถอนเมื่อหมดอายุ | **ต้นเทิร์น** ผู้สวม `isBuffEnd` (ไม่ใช่ท้ายเทิร์น) | `:18-22` |

## จุดที่ต่างจากใบอื่น

**เป็น LC ใบเดียวในโปรเจกต์ที่แก้ `baseSpeed`** (`:7`) — `ptr->atvStats->baseSpeed += 10 + superimpose * 2;` เขียนตรงใน lambda ของ LC ก่อน `resetList` · **ไม่ได้เรียก `updateMaxAtv`** ต่างจาก `../../Character/Harmony/Robin.md` ที่เรียกเสมอหลังแก้ `baseSpeed` — ที่นี่รอดเพราะทำตอน setup ก่อนการต่อสู้เริ่ม

**ถอนบัฟใน `beforeTurnList` ไม่ใช่ `afterTurnList`** — ต่างจากเกือบทุกใบ · เหมาะกับบัฟอายุ 1 เทิร์นที่ต้องอยู่จนจบเทิร์นของตัวเอง
