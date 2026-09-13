# `src/Defination/Class/Unit/CharUnit.h`

`class CharUnit : public AllyUnit` — ตัวละครผู้เล่นจริง · ctor ตั้ง `owner = this` (`CharUnit.h:155`)

## field ของ CharUnit — อธิบายที่ไหน

| กลุ่ม (`#pragma region`) | field | อธิบายที่ |
|---|---|---|
| status | `Max_energy` `Current_energy` `Ult_cost` `Energy_recharge` `Eidolon` | [Energy.md](../../Function/Combat/Energy.md) (`Eidolon` ยังไม่ได้อธิบาย) |
| Build | `Char` `Light_cone` `Relic` `Planar` | ในไฟล์นี้ (หัวข้อ Build) · [Data/README.md](../../Data/README.md) |
| DmgRecord | `maxTotalDmg` `currentTotalDmg` `currentRealTimeDmg` `currentNonRealTimeDmg` `maxRealTimeDmg` `maxNonRealTimeDmg` `AvgDmgRecord` | [CalDamageNote.md](../../Function/Calculate/CalDamageNote.md) |
| CalCheck | `checkDamage` · `checkDmgFormula*` · `checkHeal*` · `checkHpChange*` | [FormulaCheck.md](../../Function/AdjustFunction/FormulaCheck.md) |
| Substats Reroll | `Substats` `bestSubstats` `Total_substats` `rerollActive` `rerollTargetIndex` `rerollSourceIndex` `rerollImproved` `rerollSweepBase` | [Substats_Reset.md](../../Function/Setup/Substats_Reset.md) |
| Ult condition | `ultCondition` · `addUltCondition()` | [Energy.md](../../Function/Combat/Energy.md) (`ultUseCheck`) |
| ยังไม่ได้ไล่ | `Adjust` · `path` · `summonList` `memospriteList` `countdownList` · `Technique` · `Print` `Wait_Other_Buff` · `Body` `Boot` `Orb` `Rope` · `SpeedRequire` … `ExtraEhr` · `ApplyBaseChance` | — |

## คลาสผู้ช่วย 4 ตัว + โมเดล True DMG

นิยามไว้หัวไฟล์ก่อน `class CharUnit` (`CharUnit.h:6-30`)

| คลาส | หน้าที่ |
|---|---|
| `Func_class` (`:6`) | คู่ `Name` + `function<void(CharUnit*)>` — "โมดูล" ที่ผูกกับตัวละคร (`Char` / `Light_cone` / `Relic` / `Planar`) |
| `DamageSrc` (`:11`) | key ของสมุดดาเมจ = คู่ `Enemy* src` + `Enemy* recv` · `operator<` เทียบด้วย `recv->getNum()` เท่านั้น |
| `DamageRecord` (`:19`) | `total` + `type[ชื่อท่า] → ดาเมจ` |
| `DamageAvgRecord` (`:24`) | `avgDmgInstance` = snapshot `ดาเมจสะสม/Current_atv` ทุก ๆ 20 atv (`CalDamageNote.h:49-54`) · เฉลี่ยเป็น `currentDmgRecord` · `maxDmgRecord` เก็บของ run ที่ดีที่สุด |

### ทำไม `DamageSrc` ต้องมี **สอง** `Enemy*`

**True DMG ในเกม** — ตัวคูณตัวหนึ่งในสูตร แต่แทนที่จะบวกกลับเข้าดาเมจหลัก มัน **แยกยอดที่เพิ่มออกมานำเสนอเป็นดาเมจก้อนใหม่**

ผลตามมา 2 ข้อ:
1. **True DMG ต่อยอดจาก True DMG ไม่ได้** — เลขมันสำเร็จรูปมาแล้วจากก้อนแม่ ไม่มีตัวคูณอื่นมาซ้อนได้อีก (wiki: "not modified by other multipliers during damage calculation") · เทียบ Cipher A2/A4 ที่ระบุว่า tally นับเฉพาะ **non-True DMG** (`docs/character-kit-reference/Cipher.md:39,50`)
2. **ก้อนที่แยกออกมา "ย้ายเป้า" ได้** — เช่น **Tribbie E1**: เอา 24% ของดาเมจที่ศัตรู **ทุกตัว** กินในการโจมตีนั้น ไปกองใส่ศัตรู **ตัวเดียว** (`docs/character-kit-reference/Tribbie.md:55`)

ข้อ 2 คือเหตุผลที่ key ต้องเป็นคู่ เพราะ sim มีระบบ **avg weakness multiplier**:
- **`src`** = ศัตรูที่ดาเมจ **ต้นทาง** ลง → บอกว่าต้องใช้ weaken / toughness-avg **ของใคร**
- **`recv`** = ศัตรูที่ยอดสุดท้ายไป **โผล่จริง** → บอกว่าไปกองที่ตัวไหน

> ทั้งคู่เป็น `Enemy*` เพราะ src/recv เป็นศัตรูเสมอ — ฝั่งผู้ทำดาเมจเก็บแยกที่ `act->getChar()`

### วิธีบันทึก True DMG ในเอนจิน

→ อธิบายที่ [CalDamageNote.md](../../Function/Calculate/CalDamageNote.md)

## Build — `Func_class` 4 ช่อง (`Char` / `Light_cone` / `Relic` / `Planar`)

field อยู่ที่ `CharUnit.h:43-46` · `class Func_class { string Name; function<void(CharUnit*)> Print_Func; }` (`CharUnit.h:6`)

### LC / Relic / Planar ต่อเข้าตัวละครยังไง

→ อธิบายที่ [Data/README.md](../../Data/README.md) (รวมเงื่อนไขกดอัลติที่ผูกกับของที่ใส่ และที่แก้เมื่อ 2026-09-13)

### ใครใช้ช่องไหน (ณ 2026-09-13)

| ช่อง | ใครเขียน | ใครอ่าน |
|---|---|---|
| `Light_cone.Name` | ไฟล์ LC ครบทั้ง 62 ไฟล์ | **ไม่มีแล้ว** — เดิม Tribbie / Hanabi เช็ค `"DDD"` (ลบออกแล้ว ดู [Data/README.md](../../Data/README.md)) |
| `Relic.Name` | ไฟล์ relic | ไม่มีใครอ่าน |
| `Planar.Name` | ไฟล์ planar | ไม่มีใครอ่าน |
| `Char.Name` | ไม่มีใครเขียน | ไม่มีใครอ่าน |
| `Print_Func` | Tribbie ตั้งค่า (`Tribbie.h:40`) | ไม่มีใครเรียก |

**user: เก็บทุกช่องไว้ก่อน** ถึงตอนนี้จะไม่มีใครอ่าน
