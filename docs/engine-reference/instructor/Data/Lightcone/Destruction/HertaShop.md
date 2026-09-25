# `src/Defination/Data/Lightcone/Destruction/HertaShop.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Fall of an Aeon"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `Hertashop` แต่ `Light_cone.Name` เป็น `"Fall of an Aeon"`** — ชื่อไฟล์บอกแหล่งที่มา

| ท่อน | โค้ด |
|---|---|
| โจมตี → ATK stack `6 + 2S` (cap 4) | `When_attack_List` → `buffStackSingle(..., 1, 4, "Aeon Atk")` |
| มีการ break → DMG `9 + 3S` 2 เทิร์น | `Toughness_break_List` |
| ถอน DMG | `After_turn_List` |

**ไม่มีสแตตติดตัว**

## จุดที่ควรระวัง

- **ATK stack ไม่มีอายุและไม่มีโค้ดถอน** → สะสมจนเต็ม 4 แล้วค้างตลอดการต่อสู้
- **`Toughness_break_List` ไม่ guard ว่าใคร break** → ได้ DMG ทุกครั้งที่ใครก็ตาม break
- ชื่อบัฟ `"Aeon Dmg%"` มีอักขระ `%` — ใช้ได้เพราะเป็น key ของ map แต่ผิดแผนจากชื่ออื่น

> มีไฟล์ชื่อ `HertaShop.h` ใน `../Nihility/` ด้วย — คนละใบ คนละ namespace
