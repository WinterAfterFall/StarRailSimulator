# `src/Defination/Data/Lightcone/Destruction/HertaShop.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Fall of an Aeon"` · base stats `SetAllyBaseStats(1058, 529, 397)`

**ฟังก์ชันชื่อ `Hertashop` แต่ `Light_cone.Name` เป็น `"Fall of an Aeon"`** — ชื่อไฟล์บอกแหล่งที่มา

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1058, 529, 397)` | `HertaShop.h:5` |
| ผู้สวมโจมตี → ATK `6 + 2S`% ต่อ stack (สูงสุด 4) | `When_attack_List` guard `isSameOwnerName` · `buffStackSingle(…, 1, 4, "Aeon Atk")` · ไม่มีอายุ ค้างถึงจบไฟต์ | `:8-12` |
| ผู้สวม break ศัตรู → DMG `9 + 3S`% นาน 2 เทิร์น | `Toughness_break_List` guard `Trigger->isSameNum(ptr)` | `:14-17` |
| ถอน DMG เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:19-23` |

**ไม่มีสแตตติดตัว**

## จุดที่ควรระวัง

- **ATK stack ไม่มีอายุและไม่มีโค้ดถอน** → สะสมจนเต็ม 4 แล้วค้างตลอดการต่อสู้
- **`Toughness_break_List` guard ด้วย `Trigger->isSameNum(ptr)`** (แก้ 2026-09-26 — เดิมไม่มี guard ใคร break ก็ได้บัฟ) · ใช้ `isSameNum` เพราะ `AllyUnit` ไม่มี `isSameOwner` และ memosprite ใช้ `num` ร่วมกับเจ้าของ
- ชื่อบัฟ `"Aeon Dmg%"` มีอักขระ `%` — ใช้ได้เพราะเป็น key ของ map แต่ผิดแผนจากชื่ออื่น

> มีไฟล์ชื่อ `HertaShop.h` ใน `../Nihility/` ด้วย — คนละใบ คนละ namespace
