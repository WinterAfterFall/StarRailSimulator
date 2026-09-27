# `src/Defination/Data/Character/Template.h`

**โครงเปล่าสำหรับสร้างตัวละครใหม่** — ไม่ใช่ตัวละครจริง ไม่ได้ถูก `#include` ที่ไหน (ไม่มีใน `All_*_char.h` เลย) · คอมไพล์ไม่ผ่านถ้าเอาไปใช้ตรง ๆ เพราะจงใจเว้นช่องว่างไว้ให้เติม

## โครงที่ template บอกว่าต้องมี

```cpp
namespace SomeChar{
    void setup(int E, function<void(CharUnit*)> LC, function<void(CharUnit*)> Relic, function<void(CharUnit*)> Planar){
        CharUnit *ptr = setCharBasicStats(speed, maxEnergy, ultCost, E, ElementType::, Path::, name, UnitType::STANDARD);
        ptr->setAllyBaseStats(HP, ATK, DEF);

        // substats + เกณฑ์ build
        ptr->pushSubstats(Stats::);  ptr->setTotalSubstats(25);
        ptr->setSpeedRequire();  ptr->setApplyBaseChance();
        ptr->setRelicMainStats(Stats::, Stats::, Stats::, Stats::);

        lc(ptr);  Relic(ptr);  Planar(ptr);      // <- ต้องอยู่หลัง substats

        #pragma region Ability
        function<void()> BA = [ptr]() { ... };   // action เป็น lambda
        #pragma endregion

        ptr->turnFunc = [ptr,BA,skill]() { ... };
        ptr->addUltCondition([ptr]() -> bool { return true; });
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) { ... }));
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) { ... }));
    }
}
```

## สิ่งที่ template สื่อ

1. **ลำดับใน `setup` มีความหมาย** — `setCharBasicStats` → `setAllyBaseStats` → substats/เกณฑ์ → `LC/Relic/Planar` → abilities → trigger lists · ไฟล์ที่ไม่ทำตามลำดับนี้ (`../Erudition/Jingyuan.h` เรียก `setSummonStats` ท้ายสุด, `../Destruction/FireFly.h` เรียก `setCountdownStats` ท้ายสุด) อ่านแล้วสับสน
2. **action เป็น lambda ใน `#pragma region Ability`** — แต่ไฟล์จริงหลายตัวใช้ฟังก์ชันระดับ namespace แทน (`../Nihility/Pela.h`, `../Erudition/Serval.h`) ทั้งสองแบบใช้ได้ (ดู `../Nihility/Pela.md` ตารางแรก)
3. **`resetList` คือที่ของ minor traces** — ตัวอย่างในไฟล์ใส่ค่า Ice DMG 22.4 / ATK 18 / EHR 10 ไว้เป็นตัวอย่างรูปแบบ ไม่ใช่ค่าของตัวละครไหน
4. **`addUltCondition` ที่คืน `true` คือ default** — แปลว่า "กดทันทีที่ energy เต็ม"

## สิ่งที่ template **ไม่ได้** ครอบคลุม

ของพวกนี้ต้องดูไฟล์ตัวอย่างเอา:

| เรื่อง | ดูที่ |
|---|---|
| การถอนบัฟเมื่อหมดอายุ / เมื่อตาย | `Harmony/Tingyun.md` |
| debuff ฝั่งศัตรู | `Nihility/Pela.md` |
| ระบบ DoT | `Nihility/Black Swan.md`, `Nihility/Kafka.md` |
| ทรัพยากรของตัวละคร | `Nihility/Luka.md`, `Destruction/Saber.md` |
| ระบบฮีล | `Abundance/Luocha.md`, `Abundance/Gallagher.md` |
| memosprite | `Remembrance/RMC.md` |
| summon / countdown | `Erudition/Jingyuan.md`, `Remembrance/Aglaea.md` |
| stat ที่คำนวณจาก stat อื่น (`statsAdjustList`) | `Abundance/Gallagher.md` |
| Break / Super Break | `Destruction/FireFly.md`, `Erudition/Rappa.md` |
| True DMG | `Harmony/Tribbie.md`, `Nihility/Cipher.md` |

> เวลาทำตัวละครใหม่ตามคิวใน `../IMPLEMENT-QUEUE.md` ให้เริ่มจากไฟล์นี้แล้วหยิบสำนวนจากตารางข้างบนตามกลไกที่ต้องการ
