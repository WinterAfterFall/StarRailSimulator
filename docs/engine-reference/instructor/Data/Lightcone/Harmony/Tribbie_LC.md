# `src/Defination/Data/Lightcone/Harmony/Tribbie_LC.h`

`namespace Harmony_Lightcone` · `Light_cone.Name` = `"Tribbie_LC"` · base stats `SetAllyBaseStats(1270, 529, 397)`

**signature ของ Tribbie** (ดู `../../Character/Harmony/Tribbie.md`)

| ท่อน | โค้ด |
|---|---|
| CD `30 + 6S` | `Reset_List` |
| ต้นเกม → energy 21 + ทีม CD `36 + 12S` 2 เทิร์น | `Start_game_List` + `isHaveToAddBuff(ptr, "Presage", 2)` |
| ใช้ FuA → energy 12 + ต่ออายุบัฟทีม | `BeforeAllyActionList` → `act->isSameAction(ptr, AType::Fua)` |
| ถอน | `After_turn_List` → `isBuffEnd(ptr, "Presage")` |

## จุดที่น่าสนใจ

**`isHaveToAddBuff(ptr, "Presage", 2)` ถูกเรียก 2 ที่** (ต้นเกมและตอน FuA) — เวอร์ชัน 3 args ต่ออายุให้ทุกครั้งแม้บัฟยังอยู่ แล้วคืน `false` ถ้ามีอยู่แล้ว จึงไม่บวกค่าซ้ำ · **เป็นสำนวนที่ถูกต้องสำหรับบัฟที่ต่ออายุได้แต่ไม่ซ้อน**

**ใช้ `BeforeAllyActionList` ไม่ใช่ `When_attack_List`** เพื่อจับ FuA ที่อาจเป็น action ประเภทไหนก็ได้ (ดู `../../Character/Harmony/Cerydra.md` รากฐานข้อ 1)

## จุดที่ควรระวัง

- บัฟทีมใช้ `buffAllAlly` ไม่มีชื่อ คุมอายุด้วยบัฟบนผู้สวม → ไม่มี `AllyDeath_List`
