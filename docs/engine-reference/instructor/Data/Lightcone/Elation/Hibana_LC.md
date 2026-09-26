# `src/Defination/Data/Lightcone/Elation/Hibana_LC.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Hibana_LC"` · base stats `SetAllyBaseStats(1058, 582, 463)`

ชื่อในเกม: **Dazzled by a Flowery World** · **signature ของ Hibana/Sparxie** (ดู `../../Character/Elation/Hibana.md`)

| ท่อน | โค้ด |
|---|---|
| CD `40 + 8S` | `Reset_List` |
| **`Max_sp += min(3, elationCount)`** | `Setup_List` |
| ล้างตัวนับ SP ต้นเทิร์น | `Before_turn_List` |
| ผู้สวมใช้ SP → DEF_SHRED[ElationDMG] `4+S` ต่อแต้ม (cap 4) | `Skill_point_List` |
| ใช้ SP ครบ 4 ในเทิร์น → ทีม Elation `16+4S` (ครั้งเดียวต่อคน) | `isHaveToAddBuff(each, "Stream Promo")` |

## รากฐาน: `Setup_List` ในไฟล์ LC

```cpp
Setup_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
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
