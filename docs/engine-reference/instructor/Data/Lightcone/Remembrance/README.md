# `src/Defination/Data/Lightcone/Remembrance/`

8 ใบ · `namespace Remembrance_Lightcone` · **ทุกใบเกี่ยวกับ memosprite** — อ่าน `../../Character/Remembrance/README.md` ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `Aglaea_LC.h` | `Aglaea_LC` | `Aglaea_LC` | **`baseSpeed += 10+2S`** | โจมตี → CD stack (cap 6) · ครบ 6 → BA DMG ก้อนใหญ่ |
| `Castorice_LC.h` | `Castorice_LC` | `Castorice_LC` | HP% `22.5+7.5S` | memosprite ตาย → advance · เสีย HP ในเทิร์นตัวเอง → DEF_SHRED `25+5S` |
| `Hyacnine_LC.h` | `Hyacnine_LC` | `Hyacnine_LC` | SPD% `15+3S` | memosprite ใช้ Skill → ศัตรูติด VUL · สะสม HP ทีมที่เสีย แล้วปล่อยเป็น Additional DMG หลัง memosprite โจมตีครั้งถัดไป |
| `Victory_In_Blink.h` | `Victory_In_Blink` | `Victory_In_Blink` | CD `9+3S` | memosprite ใช้ buff action → ทีม DMG `6+2S` 3 เทิร์น |
| `Reminiscence.h` | `Reminiscence` | `Reminiscence` | — | ต้นเทิร์น memosprite → DMG stack (cap 4) · memosprite ตาย → ล้างทันที |
| `SweatNowCryLess.h` | `SweatNowCryLess` | `SweatNowCryLess` | CR `10+2S` | ขณะ memosprite อยู่บนสนาม → DMG `21+3S` |
| `Geniuses_Greetings.h` | `Geniuses_Greetings` | `Geniuses_Greetings` | ATK% `12+4S` | กด ult → BA DMG `15+5S` 3 เทิร์น |
| `RemembranceHertaShop.h` | `RemembranceHertaShop` | `Memory's Curtain Never Falls` | SPD% `4.5+1.5S` | ใช้ Skill → ทีม DMG `6+2S` 3 เทิร์น |

## จุดเด่นของโฟลเดอร์นี้

**1. ใช้ตระกูล `...Char` เป็นมาตรฐาน** — `buffSingleChar`, `buffStackChar`, `buffCharResetStack` เพราะบัฟต้องลงถึง memosprite ด้วย

**2. guard "เป็น memosprite ของผู้สวมหรือไม่" มี 2 สำนวน**
```cpp
act->Attacker->Atv_stats->side == Side::Memosprite && act->Attacker->Atv_stats->num == ptr->Atv_stats->num
act->Attacker->Atv_stats->side == Side::Memosprite && act->Attacker->owner->Atv_stats->Name == ptr->Atv_stats->Name
```
แบบแรกเทียบเลขช่อง (`Castorice_LC`, `Hyacnine_LC`; `Aglaea_LC` เปลี่ยนเป็น `isSameOwnerName` แล้ว 2026-09-26) แบบหลังเทียบชื่อเจ้าของ (`Victory_In_Blink`) — **แบบหลังปลอดภัยกว่า**

**3. `All_Remembrance_LC.h` มี `namespace Remembrance_Lightcone{}` ว่างอยู่ก่อน `#include`** — ไฟล์เดียวในโปรเจกต์ที่ทำแบบนี้

## จุดที่ควรระวังร่วมกัน

- แก้แล้ว 2026-09-26: `Hyacnine_LC.h` Additional DMG ไม่ออก/ยอดสะสม/จังหวะปล่อย · `SweatNowCryLess.h` ค่า DMG + ถอนเมื่อ memosprite ตาย + null · `Geniuses_Greetings.h` บัฟ memosprite ค้าง · `Castorice_LC.h` HP% · `RemembranceHertaShop.h` prefix ชื่อบัฟทีม · `Reminiscence.h` ล้างทันทีเมื่อ memosprite ตาย · `Victory_In_Blink.h` ถอนผ่าน `buffSingle`
- `Aglaea_LC.h` นับการโจมตีของ memosprite ด้วย เป็นเจตนาตาม kit · guard เปลี่ยนจากเทียบเลขช่องเป็น `isSameOwnerName(ptr)` แล้ว
