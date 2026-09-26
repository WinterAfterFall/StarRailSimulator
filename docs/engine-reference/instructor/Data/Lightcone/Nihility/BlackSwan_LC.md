# `src/Defination/Data/Lightcone/Nihility/BlackSwan_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"BlackSwan_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Black Swan** (ดู `../../Character/Nihility/Black Swan.md`)

| ท่อน | โค้ด |
|---|---|
| EHR `35 + 5S` | `Reset_List` |
| ผู้สวมตีศัตรูที่ติด DoT ชนิดไหน → ATK `4+S` + DEF_SHRED[Dot] `6.5+0.7S` **ชนิดละครั้ง** | `BeforeAttackAction_List` + guard `isSameOwnerName` วนทุกเป้า |

## รากฐาน: อ่านตัวนับชนิด DoT บนศัตรูตรง ๆ

```cpp
if (target->ShockCount     > 0 && isHaveToAddBuff(ptr,"BS LC Shock"))     buffSingle(ptr, {...});
if (target->WindSheerCount > 0 && isHaveToAddBuff(ptr,"BS LC WindShear")) buffSingle(ptr, {...});
if (target->BurnCount      > 0 && isHaveToAddBuff(ptr,"BS LC Burn"))      buffSingle(ptr, {...});
if (target->BleedCount     > 0 && isHaveToAddBuff(ptr,"BS LC Bleed"))     buffSingle(ptr, {...});
```
- **`ShockCount` / `WindSheerCount` / `BurnCount` / `BleedCount`** เป็นฟิลด์บน `Enemy` ที่ `changeDotType()` ขยับให้ (`Class/Unit/Enemy.h:86`) — **สะกด `WindSheer` ไม่ใช่ `WindShear`** เวลา grep ต้องระวัง
- **`isHaveToAddBuff` แบบ 2 args เป็นตัวกันลงซ้ำถาวร** — บัฟแต่ละชนิดลงได้ครั้งเดียวตลอดการต่อสู้ ไม่มีการถอน · ตรงกับ kit ที่ให้บัฟสะสมตามชนิด DoT ที่เคยเห็น

## จุดที่ควรระวัง

- **บล็อก 4 ก้อนเหมือนกันทุกบรรทัดต่างแค่ชื่อฟิลด์และชื่อบัฟ** — ถ้าแก้ตัวเลขต้องแก้ 4 ที่
- **แก้ 2026-09-26**: เดิมใช้ `AfterApplyDebuff` (ใครลง debuff ก็นับ) และ DEF_SHRED เป็น `AType::None` (ได้กับดาเมจทุกชนิด) · ตอนนี้นับเมื่อผู้สวมโจมตีเป้าที่มี DoT และ DEF ignore เฉพาะ `AType::Dot` ตาม kit
