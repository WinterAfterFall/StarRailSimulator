# `src/Defination/Data/Lightcone/Destruction/Clara_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Clara_LC"` · base stats `SetAllyBaseStats(1164, 582, 397)`

**signature ของ Clara** (ตัวละครยังไม่มีในโปรเจกต์)

| ท่อน | โค้ด |
|---|---|
| ATK% `20 + 4S` | `Reset_List` |
| ถูกตี → ฮีลตัวเอง `7 + S`% ATK + DMG `20 + 4S` 1 เทิร์น (ครั้งเดียวต่อเทิร์น) | `Enemy_hit_List` + flag `"Clara_LC_Triggered"` |
| ล้าง flag ต้นเทิร์นของทุกยูนิต | `Before_turn_List` |
| ถอน | `After_turn_List` |

## จุดที่น่าสังเกต

**เป็น LC ใบเดียวในโฟลเดอร์ที่ฮีล** — `e->RestoreHP(e, HealSrc(HealSrcType::ATK, 7.0 + superimpose))` ใช้ overload `RestoreHP(target, HealSrc)` โดยให้ผู้สวมฮีลตัวเอง

guard ตัวเองด้วย `e->isSameName(ptr)` แล้ว `return` ถูกต้อง

## ครั้งเดียวต่อเทิร์น

kit: "can only trigger 1 time per turn" → ตั้ง `buffCheck["Clara_LC_Triggered"] = 1` ตอนติด แล้วล้างเป็น 0 ใน `Before_turn_List` (ยิงทุกเทิร์นของทุกยูนิต รวมศัตรู) · ศัตรูหลายตัวตีในเทิร์นเดียวกันจึงติดได้ครั้งเดียว

## ส่วนที่ยังไม่มี

- trigger "เมื่อผู้สวมกำจัดศัตรู" — ยังไม่ได้ทำ
