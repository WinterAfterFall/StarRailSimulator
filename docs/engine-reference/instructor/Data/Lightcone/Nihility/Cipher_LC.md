# `src/Defination/Data/Lightcone/Nihility/Cipher_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Cipher_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Cipher** (ดู `../../Character/Nihility/Cipher.md`) · บังคับ `newApplyBaseChanceRequire(120)`

| ท่อน | โค้ด |
|---|---|
| SPD% `15 + 3S` | `Reset_List` → `Atv_stats->speedPercent` |
| ก่อนทุก action โจมตี → ศัตรูทุกตัวติด DEF_SHRED 2 ชั้น | `BeforeAttackAction_List` → `debuffAllEnemyApply` ×2 (`Bamboozle` `14+2S` · `Theft` `7+S`) |
| ถอน | `After_turn_List` → `isDebuffEnd` ทั้งสองชื่อ |

## จุดที่ควรระวัง

- **`BeforeAttackAction_List` ไม่ guard ผู้โจมตี** → debuff ถูกลง/ต่ออายุ **ทุกครั้งที่ใครก็ตามในทีมโจมตี** รวมถึง DoT และ additional · ถ้า kit ระบุเฉพาะผู้สวม จะเกินจริงมาก
- **ชื่อ debuff ไม่ได้ prefix ด้วยชื่อเจ้าของ** — ถ้ามีสองคนสวมใบนี้ ค่าจะชนกัน (ต่างจาก `Fugue_LC.h`, `Jiaoqiu_LC.h` ที่ทำถูก)
- SPD เขียนที่ `Atv_stats->speedPercent` ไม่ใช่ `Stats_type[Stats::SPD_P]`
