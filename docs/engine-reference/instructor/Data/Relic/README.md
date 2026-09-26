# `src/Defination/Data/Relic/`

15 ไฟล์ = 15 เซ็ต + `All_Relic.h` ที่ `#include` ทุกตัว · ทุกเซ็ตอยู่ใน `namespace Relic` ไฟล์เดียวต่อเซ็ต
เอกสารชุดนี้เขียนคู่กับ `../README.md` (กฎกลางของ `Data/`) — อ่านอันนั้นก่อน

## รูปทรงมาตรฐานของไฟล์ relic

```cpp
namespace Relic{
    void ชื่อเซ็ต(CharUnit *ptr){
        ptr->Relic.Name = "ชื่อ";                    // บังคับ: ตัวละครอื่นใช้ชื่อนี้เช็คเงื่อนไข
        Reset_List.push_back(...);                  // โบนัส 2 ชิ้น = สแตตดิบ
        <list ที่ตรงกับเงื่อนไข>.push_back(...);      // โบนัส 4 ชิ้น = เอฟเฟกต์มีเงื่อนไข
    }
}
```

- ตัวที่ต้องรับพารามิเตอร์จะเป็น **factory คืน lambda** แทน: `PairSet(first, second)`, `DivinerOfDistant(bool)` — แบบเดียวกับ Light Cone ที่รับ superimpose
- `ptr->Relic.Name` เก็บแค่ **ชื่อ** ตัวฟังก์ชันไม่ได้ถูกเก็บไว้ที่ไหน (ดู `../README.md` หัวข้อ LC/Relic/Planar)
- relic ใส่ `addUltCondition` ของตัวเองได้ (`Eagle_Beaked_Helmet.h`) — จังหวะกดอัลติจึงไม่ได้ขึ้นกับไฟล์ตัวละครอย่างเดียว

## ชื่อในโค้ด vs ชื่อเซ็ตจริง

ชื่อฟังก์ชัน ชื่อไฟล์ และค่าที่เขียนลง `Relic.Name` **ไม่ตรงกันเสมอ** เวลาจะเช็คชื่อจากไฟล์ตัวละครต้องใช้ค่าในคอลัมน์ขวาสุด

| ไฟล์ | ฟังก์ชัน | `Relic.Name` | เซ็ตจริงในเกม |
|---|---|---|---|
| `Eagle_Beaked_Helmet.h` | `Eagle_Beaked_Helmet` | `Eagle_Beaked_Helmet` | Eagle of Twilight Line |
| `Knight_of_Purity_Palace.h` | `Knight` | `Knight` | Knight of Purity Palace |
| `Hero_Wreath.h` | `Hero_Wreath` | `Hero_Wreath` | Hero of Triumphant Song |
| `Poet_Dill.h` | `Poet_Dill` | `Poet_Dill` | Poet of Mourning Collapse |
| `GeniusBrilliant.h` | `GeniusBrilliant` | `GeniusBrilliant` | Genius of Brilliant Stars |
| `Grand_Duke.h` | `Grand_Duke` | `Grand_Duke` | The Ashblazing Grand Duke |
| `Iron_Cavalry.h` | `Iron_Cavalry` | `Iron_Cavalry` | Iron Cavalry Against the Scourge |
| `Scholar.h` | `Scholar` | `Scholar` | Scholar Lost in Erudition |
| `Prisoner in Deep Confinement.h` | `Prisoner` | `Prisoner` | Prisoner in Deep Confinement |
| `Wavestrider Captain.h` | `Captain` | `Captain` | Wavestrider Captain |
| `Ever-Glorious Magical Girl.h` | `MagicalGirl` | `Ever-Glorious Magical Girl` | Ever-Glorious Magical Girl |
| `Sacerdos_Relived_Ordeal.h` | `Sacerdos_Relived_Ordeal` | `Sacerdos_Relived_Ordeal` | Sacerdos Relived Ordeal |
| `Diviner of Distant Reach.h` | `DivinerOfDistant` | `Diviner of Distant Reach` | Diviner of Distant Reach |
| `Goddess of Sun and Thunder.h` | `Goddess_of_Sun_and_Thunder` | `Goddess of Sun and Thunder` | Goddess of Sun and Thunder |
| `PairSet.h` | `PairSet` | `PairSet` | (ไม่ใช่เซ็ตจริง — ดูไฟล์ของมัน) |

> **กับดัก**: `Tribbie.h` เคยมีบรรทัดเช็ค `Light_cone.Name == "Eagle_Beaked_Helmet"` ซึ่งไม่มีวันจริง เพราะ Eagle เป็น relic ชื่ออยู่ใน `Relic.Name` (ลบไปแล้ว ดู `../README.md`)

## helper ที่โผล่เฉพาะในกลุ่ม relic

| helper | ใช้ทำอะไร |
|---|---|
| `isHaveToAddBuff(ptr, ชื่อ)` / `(ptr, ชื่อ, เทิร์น)` | เช็คว่ายังไม่มีบัฟนี้แล้วจองไว้ในคราวเดียว — กันลงซ้ำ · แบบ 3 args ตั้งอายุให้ด้วย |
| `buffStackSingle(เป้า, {stat}, เพิ่ม, cap, ชื่อ, เทิร์น)` | บัฟซ้อนได้แบบมีเพดาน ที่ engine นับ stack ให้ (ดู `../Character/Nihility/Luka.md`) |
| `buffResetStack(เป้า, {stat}, ชื่อ)` | ถอนบัฟแบบ stack ทั้งกองในครั้งเดียวตอนหมดอายุ |
| `calStack(เป้า, เพิ่ม, cap, ชื่อ)` | นับ stack ล้วน ๆ ไม่ผูกกับ stat |
| `ally->isSameOwner(ptr)` | ใช้ใน `WhenUseUlt_List` เพื่อดูว่าคนที่กดอัลติคือเจ้าของ relic ชิ้นนี้ไหม |

## แบบแผนที่เห็นซ้ำ

**1. โบนัส 2 ชิ้นอยู่ที่ `Reset_List` เสมอ** เพราะเป็นสแตตดิบที่ไม่มีเงื่อนไข · ค่าที่ใช้ตรงกับตาราง 2-pc ของเกม (ATK 12 / HP 12 / DEF 15 / CR 8 / CD 16 / BE 16 / SPD 6 / Type DMG 10)

**2. เงื่อนไขของโบนัส 4 ชิ้นส่วนใหญ่ถูกตัดทิ้ง** — `Iron_Cavalry` ไม่เช็ค BE ≥ 150/250, `Poet_Dill` ไม่เช็ค SPD < 110/95, `GeniusBrilliant` ไม่เช็ค weakness, `Prisoner` ไม่เช็คจำนวน DoT · ทุกตัวใส่ค่าขั้นสูงสุดตรง ๆ เพราะ build ที่ซิมนี้ใช้เข้าเงื่อนไขอยู่แล้ว — แนวเดียวกับ A2 ของ `../Character/Nihility/Pela.md`

**3. บัฟที่ต้องถอนเอง ใช้ `After_turn_List` + `isBuffEnd` คู่กับค่าติดลบ** เหมือนฝั่งตัวละครทุกประการ (`Goddess of Sun and Thunder`, `Grand_Duke`, `Sacerdos`, `Captain`)

**4. `Reset_List` vs `WhenOnField_List`** — ทั้งสองใช้ลงสแตตถาวรได้ `Iron_Cavalry` ใช้ `WhenOnField_List` ตัวเดียวในกลุ่มนี้ ที่เหลือใช้ `Reset_List`
