# `src/Defination/Data/Lightcone/Nihility/Cipher_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Cipher_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Cipher** (ดู `../../Character/Nihility/Cipher.md`) · บังคับ `newApplyBaseChanceRequire(120)`

| ท่อน | โค้ด |
|---|---|
| SPD% `15 + 3S` | `Reset_List` → `Atv_stats->speedPercent` |
| ผู้สวมโจมตีเสร็จ → ศัตรูทุกตัวติด `Bamboozle` DEF_SHRED `14+2S` · ถ้า SPD ≥ 170 ติด `Theft` `7+S` เพิ่ม | `AfterAttackActionList` + guard `isSameOwnerName` → `debuffAllEnemyApply` |
| ถอน | `After_turn_List` → `isDebuffEnd` ทั้งสองชื่อ |

## จุดที่ควรระวัง

- **แก้ 2026-09-26**: เดิมลงใน `BeforeAttackAction_List` ไม่ guard ผู้โจมตี (ใครตีก็ลง) และ Theft ไม่เช็ค SPD 170 · ตอนนี้ย้ายไป `AfterAttackActionList` ตาม kit ("After the wearer uses an attack") guard ผู้สวม และคำนวณ SPD จริงเป็น `baseSpeed × (1 + speedPercent/100) + flatSpeed`
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ — ตั้งใจ**: `Bamboozle` / `Theft` มีได้ชั้นเดียวบนศัตรู ต่อให้สวม 2 คนก็ติดแค่อันเดียว (ดูแบบแผนข้อ 4 ใน `README.md`)
- SPD เขียนที่ `Atv_stats->speedPercent` ไม่ใช่ `Stats_type[Stats::SPD_P]`
