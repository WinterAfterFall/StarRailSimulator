# `src/Defination/Data/Lightcone/Nihility/Jiaoqiu_LC.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"Jiaoqiu_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Jiaoqiu** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

## เป็น LC ใบเดียวที่รับพารามิเตอร์ 2 ตัว

```cpp
function<void(CharUnit *ptr)> Jiaoqiu_LC(int superimpose, bool isDot)
```
`isDot` เลือกว่าจะใช้ค่าชุดไหน — ผู้ประกอบทีมตัดสินเอง ไม่ใช่โค้ดเช็ค:

| `isDot` | debuff | ค่า |
|---|---|---|
| `true` | `cornered` | VUL `20 + 4S` |
| `false` | `unarmored` | VUL `8 + 2S` |

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Jiaoqiu_LC.h:5` |
| EHR `50 + 10S` | บวกถาวร | `:10` |
| ผู้สวมใช้ BA/Skill/Ult → เป้ารับ DMG เพิ่ม นาน 2 เทิร์น: `isDot=true` → "Cornered" `20 + 4S`% · `false` → "Unarmored" `8 + 2S`% | `beforeAttackActionList` guard ชนิดท่า + `isSameOwnerName` · ชื่อ debuff ผูกเจ้าของ (`:7-8`) | `:13-23` (Cornered `:18` · Unarmored `:19`) |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` ทั้งสองชื่อ | `:25-35` |

## จุดที่ทำถูก

- **guard ประเภท action ด้วย 3 เงื่อนไข** `isSameAction(AType::BA) || isSameAction(AType::SKILL) || isSameAction(AType::ULT)` — ทำให้ DoT/additional ไม่ trigger · เป็นตัวอย่างที่ LC ใบอื่นในโฟลเดอร์นี้ควรลอก
- **guard ผู้กระทำด้วย `isSameOwnerName(ptr)`** ซึ่งครอบ memosprite ของเจ้าของด้วย
- **ชื่อ debuff prefix ด้วยชื่อเจ้าของ**
