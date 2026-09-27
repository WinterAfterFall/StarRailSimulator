# `src/Defination/Data/Lightcone/Nihility/Cipher_LC.h`

`namespace Nihility_Lightcone` · `lightCone.name` = `"Cipher_LC"` · base stats `setAllyBaseStats(953, 582, 529)`

**signature ของ Cipher** (ดู `../../Character/Nihility/Cipher.md`) · บังคับ `newApplyBaseChanceRequire(120)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 582, 529)` | `Cipher_LC.h:5` |
| (AI) EHR ขั้นต่ำ 120 | `newApplyBaseChanceRequire(120)` | `:7` |
| SPD `15 + 3S`% | บวก `speedPercent` ถาวร | `:18` |
| ผู้สวมโจมตี → ศัตรูทุกตัว DEF ลด `14 + 2S`% ("Bamboozle") นาน 2 เทิร์น | `afterAttackActionList` → `debuffAllEnemyApply` | `:9-11` |
| ถ้า SPD ≥ 170 → DEF ลดเพิ่ม `7 + S`% ("Theft") | คำนวณ SPD จาก `baseSpeed`/`speedPercent`/`flatSpeed` ในบล็อกเดียวกัน | `:12-14` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` ทั้งสองชื่อ | `:21-30` |

## จุดที่ควรระวัง

- **แก้ 2026-09-26**: เดิมลงใน `beforeAttackActionList` ไม่ guard ผู้โจมตี (ใครตีก็ลง) และ Theft ไม่เช็ค SPD 170 · ตอนนี้ย้ายไป `afterAttackActionList` ตาม kit ("After the wearer uses an attack") guard ผู้สวม และคำนวณ SPD จริงเป็น `baseSpeed × (1 + speedPercent/100) + flatSpeed`
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ — ตั้งใจ**: `Bamboozle` / `Theft` มีได้ชั้นเดียวบนศัตรู ต่อให้สวม 2 คนก็ติดแค่อันเดียว (ดูแบบแผนข้อ 4 ใน `README.md`)
- SPD เขียนที่ `atvStats->speedPercent` ไม่ใช่ `statsType[Stats::SPD_P]`
