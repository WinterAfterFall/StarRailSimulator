# `src/Defination/Data/Lightcone/Elation/YaoGuang_LC.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"YaoGuang_LC"` · base stats `SetAllyBaseStats(1058, 529, 529)`

**signature ของ Yao Guang** (ดู `../../Character/Elation/YaoGuang.md`)

| ท่อน | โค้ด |
|---|---|
| SPD% `15 + 3S` | `Reset_List` → `Atv_stats->speedPercent` |
| ต้น wave → energy 15 (ไม่ผ่าน ER) | `Start_wave_List` → `Increase_energy(ptr, 0, 15)` |
| ต้นเกม → ER `10+2S` + ทีม CR `9+S` / CD `22.5+7.5S` 3 เทิร์น | `Start_game_List` + `isHaveToAddBuff(ptr, "Great Fortune", 3)` |
| ใช้ Ult → เหมือนกัน (ต่ออายุ) | `Buff_List` → `act->isSameAction(ptr, AType::Ult)` |
| ถอน | `After_turn_List` |

ชื่อในเกม: **When She Decided to See**

> **แก้ 2026-09-26**: CD ทีมเดิม `30+5S` = 35/40/45/50/55 ไม่ตรง kit 30/38/45/53/60 → `22.5+7.5S` = 30/37.5/45/52.5/60 (kit ปัด .5 ขึ้น) · แก้ครบ 3 ที่ (ลง 2 ที่ + ถอน 1 ที่) ให้ค่าเท่ากัน

## จุดที่น่าสนใจ

**บล็อกบัฟถูก copy 2 ที่** (`Start_game_List` และ `Buff_List`) เหมือนกันทุกบรรทัด — `isHaveToAddBuff(..., 3)` แบบ 3 args ทำให้ต่ออายุได้โดยไม่บวกซ้ำ จึงเรียกซ้ำได้อย่างปลอดภัย

**ใช้ `Buff_List` ไม่ใช่ `WhenUseUlt_List`** เพราะ Ult ของ Yao Guang เป็น `AllyBuffAction` ที่ไม่มีดาเมจ

## จุดที่ควรระวัง

- บัฟทีมใช้ `buffAllAlly` ไม่มีชื่อ คุมอายุด้วยบัฟบนผู้สวม → **ไม่มี `AllyDeath_List`** ถ้าเพื่อนตายค่าจะค้าง
- `Start_wave_List` vs `Start_game_List` เป็นคนละ trigger — ใบนี้ใช้ทั้งคู่
