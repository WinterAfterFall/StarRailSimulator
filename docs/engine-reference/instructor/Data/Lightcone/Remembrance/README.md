# `src/Defination/Data/Lightcone/Remembrance/`

8 ใบ · `namespace Remembrance_Lightcone` · **ทุกใบเกี่ยวกับ memosprite** — อ่าน `../../Character/Remembrance/README.md` ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `Aglaea_LC.h` | `Aglaea_LC` | `Aglaea_LC` | **`baseSpeed += 10+2S`** | โจมตี → CD stack (cap 6) · ครบ 6 → BA DMG ก้อนใหญ่ |
| `Castorice_LC.h` | `Castorice_LC` | `Castorice_LC` | HP% `22+8S` | memosprite ตาย → advance · เสีย HP ในเทิร์นตัวเอง → DEF_SHRED `25+5S` |
| `Hyacnine_LC.h` | `Hyacnine_LC` | `Hyacnine_LC` | SPD% `15+3S` | memosprite ใช้ Skill → ศัตรูติด VUL · สะสม HP ทีมแล้วแปลงเป็น Additional DMG |
| `Victory_In_Blink.h` | `Victory_In_Blink` | `Victory_In_Blink` | CD `9+3S` | memosprite ใช้ buff action → ทีม DMG `6+2S` 3 เทิร์น |
| `Reminiscence.h` | `Reminiscence` | `Reminiscence` | — | ต้นเทิร์น memosprite → DMG stack (cap 4) · memosprite ตาย → ล้าง |
| `SweatNowCryLess.h` | `SweatNowCryLess` | `SweatNowCryLess` | CR `10+2S` | memosprite ยังอยู่ → DMG `20+4S` (ครั้งเดียว) |
| `Geniuses_Greetings.h` | `Geniuses_Greetings` | `Geniuses_Greetings` | ATK% `12+4S` | กด ult → BA DMG `15+5S` 3 เทิร์น |
| `RemembranceHertaShop.h` | `RemembranceHertaShop` | `Memory's Curtain Never Falls` | SPD% `4.5+1.5S` | ใช้ Skill → ทีม DMG `6+2S` 3 เทิร์น |

## จุดเด่นของโฟลเดอร์นี้

**1. ใช้ตระกูล `...Char` เป็นมาตรฐาน** — `buffSingleChar`, `buffStackChar`, `buffCharResetStack` เพราะบัฟต้องลงถึง memosprite ด้วย

**2. guard "เป็น memosprite ของผู้สวมหรือไม่" มี 2 สำนวน**
```cpp
act->Attacker->Atv_stats->side == Side::Memosprite && act->Attacker->Atv_stats->num == ptr->Atv_stats->num
act->Attacker->Atv_stats->side == Side::Memosprite && act->Attacker->owner->Atv_stats->Name == ptr->Atv_stats->Name
```
แบบแรกเทียบเลขช่อง (`Aglaea_LC`, `Castorice_LC`, `Hyacnine_LC`) แบบหลังเทียบชื่อเจ้าของ (`Victory_In_Blink`) — **แบบหลังปลอดภัยกว่า**

**3. `All_Remembrance_LC.h` มี `namespace Remembrance_Lightcone{}` ว่างอยู่ก่อน `#include`** — ไฟล์เดียวในโปรเจกต์ที่ทำแบบนี้

## จุดที่ควรระวังร่วมกัน

- **`Victory_In_Blink.h` ถอนบัฟด้วยการเขียน `Stats_type` ตรง ๆ** แทน `buffSingle` ค่าติดลบ — ผลเหมือนกันแต่ผิดแผน
- **`Hyacnine_LC.h` มีบั๊กใหญ่**: `act->addDamageIns(...)` ใส่ดาเมจเข้า action ที่ **เพิ่งยิงจบไปแล้ว** แทนที่จะใส่เข้า `addtionaldmg` ที่เพิ่งสร้าง — ดู `Hyacnine_LC.md`
- **`Geniuses_Greetings.h` มี `dynamic_cast` ที่ไม่ได้ใช้** — ประกาศ `tempstats` แล้วเช็ค null แต่บล็อกข้างในใช้ `ptr` ทั้งหมด
