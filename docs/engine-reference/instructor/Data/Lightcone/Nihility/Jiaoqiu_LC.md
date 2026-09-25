# `src/Defination/Data/Lightcone/Nihility/Jiaoqiu_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Jiaoqiu_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Jiaoqiu** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

## เป็น LC ใบเดียวที่รับพารามิเตอร์ 2 ตัว

```cpp
function<void(CharUnit *ptr)> Jiaoqiu_LC(int superimpose, bool isDot)
```
`isDot` เลือกว่าจะใช้ค่าชุดไหน — ผู้ประกอบทีมตัดสินเอง ไม่ใช่โค้ดเช็ค:

| `isDot` | debuff | ค่า |
|---|---|---|
| `true` | `Cornered` | VUL `20 + 4S` |
| `false` | `Unarmored` | VUL `8 + 2S` |

| ท่อน | โค้ด |
|---|---|
| EHR `40 + 10S` | `Reset_List` |
| BA/Skill/Ult ของผู้สวม → เป้าติด VUL 2 เทิร์น | `BeforeAttackAction_List` + guard `isSameOwnerName(ptr)` |
| ถอน | `After_turn_List` → `isDebuffEnd` ทั้งสองชื่อ |

## จุดที่ทำถูก

- **guard ประเภท action ด้วย 3 เงื่อนไข** `isSameAction(AType::BA) || isSameAction(AType::SKILL) || isSameAction(AType::Ult)` — ทำให้ DoT/additional ไม่ trigger · เป็นตัวอย่างที่ LC ใบอื่นในโฟลเดอร์นี้ควรลอก
- **guard ผู้กระทำด้วย `isSameOwnerName(ptr)`** ซึ่งครอบ memosprite ของเจ้าของด้วย
- **ชื่อ debuff prefix ด้วยชื่อเจ้าของ**
