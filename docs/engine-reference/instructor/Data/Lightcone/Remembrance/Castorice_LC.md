# `src/Defination/Data/Lightcone/Remembrance/Castorice_LC.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Castorice_LC"` · base stats `SetAllyBaseStats(1270, 529, 397)`

**signature ของ Castorice** (ดู `../../Character/Remembrance/Castorice.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(1270, 529, 397)` | `Castorice_LC.h:5` |
| HP% `22.5 + 7.5S` | บวกถาวร | `:9` |
| memosprite ของผู้สวมตาย → ผู้สวม advance `9 + 3S`% (ครั้งเดียวต่อ Ult) | `AllyDeath_List` เช็ค `side == Memosprite` และ `num` ตรงกัน · flag `"Castorice_LC_check"` | `:12-19` |
| กด Ult → รีเซ็ต flag ข้างบน | `WhenUseUlt_List` + `isSameOwner` | `:21-25` |
| ในเทิร์นของผู้สวม/memosprite เขาเสีย HP → "Death Flower": ignore DEF `25 + 5S`% นาน 2 เทิร์น (ทั้งคู่) | `HPDecrease_List` เช็คเจ้าของเทิร์นและเป้าเป็นฝั่งผู้สวม · `isHaveToAddBuff(…, 2)` + `buffSingleChar` | `:27-35` |
| ถอน Death Flower | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:38-42` |

## จุดที่ทำถูก

**`HPDecrease_List` guard 3 ชั้น** (บรรทัด 24-27):
```cpp
if (!turn) return;                                                    // กัน null
if ((turn->side == Side::Memosprite || turn->side == Side::Ally)
    && turn->num == ptr->Atv_stats->num                               // เทิร์นของผู้สวมหรือ memosprite
    && target->Atv_stats->num == ptr->Atv_stats->num)                 // คนที่เสีย HP คือผู้สวม
```
เป็นการ guard ที่รัดกุมที่สุดในกลุ่ม LC — เทียบกับ `../Destruction/Jingliu_LC.md` ที่ไม่ guard เลย

**`isHaveToAddBuff(ptr, "Death Flower", 2)`** แบบ 3 args ทำให้ต่ออายุได้โดยไม่บวกซ้ำ

## ข้อสังเกต

flag `Castorice_LC_check` ทำให้ advance เกิดได้ครั้งเดียวต่อรอบ ult — ล้างเมื่อกด ult ใหม่ · ตรงกับ kit ที่ผูกกับรอบของ Netherwing

> **แก้ 2026-09-26 ตาม kit**: HP% เดิม `22 + 8S` (30/38/46/54/62) → kit 30/38/45/53/60 (ปัดจาก 30/37.5/45/52.5/60) = `22.5 + 7.5S`
