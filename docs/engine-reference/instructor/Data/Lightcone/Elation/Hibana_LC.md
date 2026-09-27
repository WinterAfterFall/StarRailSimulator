# `src/Defination/Data/Lightcone/Elation/Hibana_LC.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Hibana_LC"` · base stats `SetAllyBaseStats(1058, 582, 463)`

ชื่อในเกม: **Dazzled by a Flowery World** · **signature ของ Hibana/Sparxie** (ดู `../../Character/Elation/Hibana.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 582, 463)` | `Hibana_LC.h:5` |
| CD `40 + 8S` | บวกถาวร | `:9` |
| SP สูงสุดของทีม +จำนวนตัว Elation (สูงสุด 3) — ไม่ซ้อนถ้าใส่หลายคน | `Setup_List` ให้เฉพาะผู้สวมคนแรกใน `charList` บวก `Max_sp` | `:12-20` |
| ล้างตัวนับ SP | ต้นทุกเทิร์นตั้ง stack `"Hibana LC sp count"` = 0 | `:22-24` |
| ผู้สวมใช้ SP → Elation DMG ignore DEF `4 + S`% ต่อแต้ม (สูงสุด 4) | `Skill_point_List` เฉพาะผู้สวม SP ติดลบ · `buffStackSingle(…, -SP, 4, "Hibana LC Defshred")` | `:26-29` |
| ใช้ SP ครบ 4 ในเทิร์น → ทั้งทีม Elation `16 + 4S` | วน `allyList` · `isHaveToAddBuff(each, "Stream Promo")` ลงคนละครั้ง | `:30-35` |

## รากฐาน: `Setup_List` ในไฟล์ LC

```cpp
Setup_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
    for (auto &each : charList) {           // ผู้สวมคนแรกเท่านั้นที่บวก
        if (each->Light_cone.Name != "Hibana_LC") continue;
        if (each != ptr) return;
        break;
    }
    Max_sp += min(3, elationCount);
}));
```
> **แก้ 2026-09-26**: เดิมผู้สวมทุกคนบวก `Max_sp` → สวม 2 คนได้ SP limit 2 เท่า · kit "Light Cone effects of the same type cannot stack" → ตอนนี้ให้เฉพาะผู้สวมคนแรกใน `charList` บวก (ชื่อ LC ถูกตั้งตอนประกอบทีม จึงอ่านได้ใน `Setup_List`)

**ต้องรอให้ทีมประกอบเสร็จก่อน** เพราะ `elationCount` ถูก `++` ใน `Setup` ของตัวละคร Elation แต่ละตัว — ถ้าเขียนตรง ๆ ใน lambda ของ LC จะได้ค่าที่ยังนับไม่ครบ

เป็น LC ใบเดียวที่ใช้ `Setup_List` · ตัวละครที่ใช้ `Setup_List` ด้วยเหตุผลเดียวกัน (รอทีมประกอบเสร็จ) คือ `../../Character/Destruction/Phainon.md` (แก้ 2026-09-26: เดิมเขียนกำกวมเหมือน Phainon ใช้ LC ใบนี้)

## จุดที่ควรระวัง

- **`Max_sp` ถูกแก้โดย 3 ที่ในโปรเจกต์** — `../../Character/Harmony/Hanabi.h`, `../../Character/The Hunt/Archer.h` และใบนี้ · ถ้าอยู่ในทีมเดียวกันจะบวกสะสม
- **บัฟ `"Stream Promo"` ไม่มีอายุและไม่มีการถอน** — `isHaveToAddBuff` แบบ 2 args ทำให้ลงได้ครั้งเดียวต่อคนตลอดการต่อสู้
- **`buffStackSingle` ของ DEF_SHRED ไม่มี duration** → stack ค้างถาวร
