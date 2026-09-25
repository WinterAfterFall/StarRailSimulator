# `src/Defination/Data/Lightcone/Destruction/HertaShop.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Fall of an Aeon"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `Hertashop` แต่ `Light_cone.Name` เป็น `"Fall of an Aeon"`** — ชื่อไฟล์บอกแหล่งที่มา

| ท่อน | โค้ด |
|---|---|
| โจมตี → ATK stack `6 + 2S` (cap 4) | `When_attack_List` → `buffStackSingle(..., 1, 4, "Aeon Atk")` |
| ผู้สวม break → DMG `9 + 3S` 2 เทิร์น | `Toughness_break_List` + guard `Trigger->isSameNum(ptr)` |
| ถอน DMG | `After_turn_List` |

**ไม่มีสแตตติดตัว**

## จุดที่ควรระวัง

- **ATK stack ไม่มีอายุและไม่มีโค้ดถอน** → สะสมจนเต็ม 4 แล้วค้างตลอดการต่อสู้
- **`Toughness_break_List` guard ด้วย `Trigger->isSameNum(ptr)`** (แก้ 2026-09-26 — เดิมไม่มี guard ใคร break ก็ได้บัฟ) · ใช้ `isSameNum` เพราะ `AllyUnit` ไม่มี `isSameOwner` และ memosprite ใช้ `num` ร่วมกับเจ้าของ
- ชื่อบัฟ `"Aeon Dmg%"` มีอักขระ `%` — ใช้ได้เพราะเป็น key ของ map แต่ผิดแผนจากชื่ออื่น

> มีไฟล์ชื่อ `HertaShop.h` ใน `../Nihility/` ด้วย — คนละใบ คนละ namespace
