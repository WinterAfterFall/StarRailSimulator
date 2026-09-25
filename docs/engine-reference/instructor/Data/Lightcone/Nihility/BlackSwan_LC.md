# `src/Defination/Data/Lightcone/Nihility/BlackSwan_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"BlackSwan_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Black Swan** (ดู `../../Character/Nihility/Black Swan.md`)

| ท่อน | โค้ด |
|---|---|
| EHR `35 + 5S` | `Reset_List` |
| ศัตรูติด DoT ชนิดไหน → ATK `4+S` + DEF_SHRED `6.5+0.7S` **ชนิดละครั้ง** | `AfterApplyDebuff` |

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
- **เช็คจาก `target` ที่เพิ่งถูกลง debuff เท่านั้น** ไม่ได้วนศัตรูทุกตัว → ถ้าศัตรูตัวอื่นมี DoT ชนิดที่ยังไม่เคยเห็น จะไม่ได้บัฟจนกว่าจะลง debuff ใส่ตัวนั้น
