# `src/Defination/Data/Lightcone/Nihility/`

14 ใบ — มากที่สุดในทุก path · `namespace Nihility_Lightcone` · อ่าน `../README.md` ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `Kafka_LC.h` | `Kafka_LC` | `Kafka_LC` | DMG `20+4S` | โจมตี → SPD stack (cap 3) + ลง Shock `Erode` · มี `Dot_List` ของตัวเอง |
| `BlackSwan_LC.h` | `BlackSwan_LC` | `BlackSwan_LC` | EHR `35+5S` | ผู้สวมตีเป้าติด DoT ชนิดไหน → ATK/DEF_SHRED[Dot] เพิ่มชนิดละครั้ง (4 ชนิด) |
| `Hysilens_LC.h` | `Hysilens_LC` | `Hysilens_LC` | EHR `35+5S` | ลง debuff → เป้าเข้า Enthrallment 3 เทิร์น · ระหว่างนั้น debuff ที่ลงเพิ่ม → VUL[Dot] stack (cap 6) · ตีเป้าติด Enthrallment → ผู้ตี SPD `7.5+2.5S` 3 เทิร์น |
| `Cipher_LC.h` | `Cipher_LC` | `Cipher_LC` | SPD% `15+3S` | ผู้สวมโจมตีเสร็จ → ศัตรูทุกตัวติด `Bamboozle` · SPD ≥ 170 ติด `Theft` เพิ่ม |
| `Fugue_LC.h` | `Fugue_LC` | `Fugue_LC` | BE `50+10S` | มีการ break → เป้าติด Break VUL `15+3S` 2 เทิร์น (stack 2) |
| `Jiaoqiu_LC.h` | `Jiaoqiu_LC(S, **bool isDot**)` | `Jiaoqiu_LC` | EHR `50+10S` | BA/Skill/Ult → เป้าติด VUL · ค่าต่างกันตาม `isDot` |
| `ShowTime.h` | `ShowTime` | `ShowTime` | ATK% `16+4S` | ลง debuff → DMG stack `5+S` (cap 3, 1 เทิร์น) |
| `Resolution.h` | `Resolution` | `Resolution` | — | โจมตี → เป้าติด `Ensnared` DEF_SHRED `11+S` |
| `Fermata.h` | `Fermata` | `Fermata` | BE `12+4S` | เป้าที่ติด Shock/WindShear รับดาเมจ +`12+4S` **เฉพาะก้อนนั้น** |
| `Eyes of the Prey.h` | `EyesOfThePrey` | `Eyes of the Prey` | EHR `15+5S` · DoT DMG `18+6S` | — |
| `HertaShop.h` | `HertaShop` | `Solitary Healing` | BE `15+5S` | กด ult → DoT DMG `18+6S` 2 เทิร์น |
| `BP2.h` | `BP2` | `Holiday` | DMG `12+4S` | โจมตี → เป้าติด VUL `8.5+1.5S` 2 เทิร์น |
| `Before_the_Tutorial_Mission_Starts.h` | `Before_the_Tutorial` | `Before_the_Tutorial` | EHR `15+5S` | โจมตีเป้าที่ DEF ถูกลด → energy `3+S` |
| `GNSW.h` | `GNSW` | `GNSW` | DMG `(9+3S)×3` | — |

## แบบแผนของโฟลเดอร์นี้

**1. `newApplyBaseChanceRequire` / `newEhrRequire` — LC ที่บังคับเกณฑ์ build**
`BP2.h` (100), `Cipher_LC.h` (120), `Hysilens_LC.h` (80), `Resolution.h` (`50 + S*10`), `ShowTime.h` (`newEhrRequire(80)`) · เป็นกลไกเดียวกับที่ `../../Character/Nihility/Kafka.md` A2 ใช้ยกเกณฑ์ให้เพื่อน

**2. trigger เฉพาะกลุ่มนี้: `BeforeApplyDebuff` / `AfterApplyDebuff`**
`TriggerBySomeAlly_Func` รับ `(Enemy *target, AllyUnit *Trigger)` — ยิงก่อน/หลังการลง debuff · ใช้โดย `Hysilens_LC.h`, `ShowTime.h`

**3. ตัวนับชนิด DoT บนศัตรูอ่านได้ตรง ๆ** — `target->ShockCount`, `WindSheerCount`, `BurnCount`, `BleedCount` (สะกด `WindSheer` ไม่ใช่ `WindShear`) · ใช้โดย `BlackSwan_LC.h` และ `Fermata.h`

**4. กฎการ prefix ชื่อ buff/debuff ด้วยชื่อเจ้าของ** (user ยืนยัน 2026-09-26)
- **ค่าเริ่มต้น = ใส่ prefix** เพราะ buff/debuff ปกติซ้อนกันได้ถ้าสวมหลายคน: `Fugue_LC.h`, `Jiaoqiu_LC.h`, `Kafka_LC.h`, `Resolution.h`
- **ยกเว้น 1: kit ระบุว่าซ้อนไม่ได้** ("same effect type cannot be stacked" / "only the most recently inflicted instance takes effect"): `BP2.h` (`Holiday Vul`), `Cipher_LC.h` (`Bamboozle`/`Theft`), `Hysilens_LC.h` (`Hys LC`, `Hys LC SPD`)
- **ยกเว้น 2: บัฟอยู่บนตัวผู้สวมเท่านั้น**: `ShowTime.h`, `HertaShop.h`, `BlackSwan_LC.h`, stack SPD ของ `Kafka_LC.h`
- นอกเหนือจากนี้ = ลืมใส่ ต้องแก้

## จุดที่ควรระวังร่วมกัน

- แก้ตาม kit แล้ว 2026-09-26: `Cipher_LC.h` guard/SPD 170 · `Fugue_LC.h` Break VUL · `BlackSwan_LC.h` DEF ignore เฉพาะ DoT · `Hysilens_LC.h` Enthrallment/SPD/ถอด VUL stack · EHR ของ `Before_the_Tutorial` / `Jiaoqiu_LC` · `Fermata.h` ถอนตามรายการ · `Before_the_Tutorial` guard memosprite + DEF shred ทุกช่อง
- รีแฟกเตอร์โค้ดเก่าแล้ว 2026-09-26: `Resolution.h` → `debuffSingleApply` + `isDebuffEnd` · `Kafka_LC.h` → `dotRemove` · `Fugue_LC.h` → `canCastToEnemy()` · ลบโค้ด debug ใน `Hysilens_LC.h`
- ตั้งใจ ไม่ใช่บั๊ก: `GNSW.h` สมมติ 3 stack เต็มเสมอ · `Jiaoqiu_LC.h` ให้ผู้จัดทีมเลือก `isDot` · SPD stack ของ `Kafka_LC.h` ถาวรตาม kit
