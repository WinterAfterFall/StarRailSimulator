# `src/Defination/Data/Lightcone/Harmony/Tribbie_LC.h`

`namespace Harmony_Lightcone` · `lightCone.name` = `"Tribbie_LC"` · base stats `setAllyBaseStats(1270, 529, 397)`

**signature ของ Tribbie** (ดู `../../Character/Harmony/Tribbie.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1270, 529, 397)` | `Tribbie_LC.h:5` |
| CD `30 + 6S` | บวกถาวร | `:9` |
| ต้นเกม → energy 21 และ "Presage": ทั้งทีม CD `36 + 12S` นาน 2 เทิร์น | `startGameList` · `isHaveToAddBuff(ptr, "Presage", 2)` | `:12-17` |
| ผู้สวมใช้ Follow-up → energy 12 และ Presage เหมือนกัน | `beforeAllyActionList` เฉพาะ `AType::FUA` | `:25-32` |
| ถอน Presage เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:19-23` |

## จุดที่น่าสนใจ

**`isHaveToAddBuff(ptr, "Presage", 2)` ถูกเรียก 2 ที่** (ต้นเกมและตอน FuA) — เวอร์ชัน 3 args ต่ออายุให้ทุกครั้งแม้บัฟยังอยู่ แล้วคืน `false` ถ้ามีอยู่แล้ว จึงไม่บวกค่าซ้ำ · **เป็นสำนวนที่ถูกต้องสำหรับบัฟที่ต่ออายุได้แต่ไม่ซ้อน**

**ใช้ `beforeAllyActionList` ไม่ใช่ `whenAttackList`** เพื่อจับ FuA ที่อาจเป็น action ประเภทไหนก็ได้ (ดู `../../Character/Harmony/Cerydra.md` รากฐานข้อ 1)

## จุดที่ควรระวัง

- บัฟทีมใช้ `buffAllAlly` ไม่มีชื่อ คุมอายุด้วยบัฟบนผู้สวม → ไม่มี `allyDeathList`
