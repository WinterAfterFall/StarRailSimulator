# `src/Defination/Data/Lightcone/Nihility/Fermata.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Fermata"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| Break Effect `12 + 4S` | `Reset_List` |
| เป้าที่ติด Shock/WindShear รับดาเมจ +`12 + 4S` **เฉพาะก้อนนั้น** | `BeforeAttack_List` ลง / `AfterAttack_List` ถอน |

## รากฐาน: บัฟชั่วคราวครอบ action ด้วยคู่ Before/After

```cpp
BeforeAttack_List: if (each->ShockCount || each->WindSheerCount) debuffSingle(each, {{DMG,  +(12+4S)}});
AfterAttack_List:  if (each->ShockCount || each->WindSheerCount) debuffSingle(each, {{DMG,  -(12+4S)}});
```
สำนวนเดียวกับ "เพิกเฉย DEF เฉพาะก้อนนี้" ของ `../../Character/Nihility/Black Swan.md` แต่ทำกับ **ศัตรู** และแยกเป็นสอง list แทนที่จะครอบ `Attack()` ในบรรทัดเดียว

**ความเสี่ยง**: ถ้าสถานะ DoT ของศัตรูเปลี่ยนระหว่าง `BeforeAttack` กับ `AfterAttack` (เช่น DoT หมดอายุพอดี หรือ action นั้นลง DoT ใหม่) เงื่อนไขสองฝั่งจะไม่ตรงกัน → **ค่ารั่ว** · ที่ปลอดภัยกว่าคือจดว่าลงให้ใครไว้แล้วถอนตามรายการนั้น

guard ผู้โจมตีด้วย `isSameOwnerName(ptr)` ถูกต้อง
