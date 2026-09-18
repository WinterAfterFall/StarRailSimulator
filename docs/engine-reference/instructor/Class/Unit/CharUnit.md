# `src/Defination/Class/Unit/CharUnit.h`

`class CharUnit : public AllyUnit` — ตัวละครผู้เล่นจริง · ctor ตั้ง `owner = this` (`CharUnit.h:155`)

## field ของ CharUnit — อธิบายที่ไหน

| กลุ่ม (`#pragma region`) | field | อธิบายที่ |
|---|---|---|
| status | `Max_energy` `Current_energy` `Ult_cost` `Energy_recharge` `Eidolon` | [Energy.md](../../Function/Combat/Energy.md) · `Eidolon` อธิบายในไฟล์นี้ |
| Build | `Char` `Light_cone` `Relic` `Planar` | ในไฟล์นี้ (หัวข้อ Build) · [Data/README.md](../../Data/README.md) |
| DmgRecord | `maxTotalDmg` `currentTotalDmg` `currentRealTimeDmg` `currentNonRealTimeDmg` `maxRealTimeDmg` `maxNonRealTimeDmg` `AvgDmgRecord` | [CalDamageNote.md](../../Function/Calculate/CalDamageNote.md) |
| CalCheck | `checkDamage` · `checkDmgFormula*` · `checkHeal*` · `checkHpChange*` | [FormulaCheck.md](../../Function/AdjustFunction/FormulaCheck.md) |
| Substats Reroll | `Substats` `bestSubstats` `Total_substats` `rerollActive` `rerollTargetIndex` `rerollSourceIndex` `rerollImproved` `rerollSweepBase` | [Substats_Reset.md](../../Function/Setup/Substats_Reset.md) |
| Ult condition | `ultCondition` · `addUltCondition()` | [Energy.md](../../Function/Combat/Energy.md) (`ultUseCheck`) |
| Sub-unit lists | `summonList` `memospriteList` `countdownList` | ในไฟล์นี้ (เจตนาการออกแบบ ยังไม่ได้ไล่การทำงานครบ) |
| Technique | `Technique` | ในไฟล์นี้ (ความหมายขึ้นอยู่กับตัวละคร) |
| Relic main stats | `Body` `Boot` `Orb` `Rope` | ในไฟล์นี้ (คงค่าระหว่าง reroll substats) |
| Requirement stats | `SpeedRequire` … `ExtraEhr` · `ApplyBaseChance` | ในไฟล์นี้ (เจตนาการออกแบบ ยังไม่ได้ไล่สูตรครบ) |
| Print | `Print` | ในไฟล์นี้ (เปิด/ปิดการแสดงผลตอนเริ่มและจบอัลติ) |
| Adjust | `Adjust` | ในไฟล์นี้ (ค่าปรับเฉพาะตัวละคร) |
| Path | `path` | ในไฟล์นี้ (เดิมเผื่อหลาย Path มีแผนเปลี่ยนเป็นค่าเดียว) |

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

## Summon / Memosprite / Countdown lists

คำอธิบายเจตนาการออกแบบจาก user (2026-09-15):

- `summonList` — เก็บซัมมอนที่ไม่มีตัวตนให้ถูกโจมตี จึงโดนตีไม่ได้ และคำนวณความเสียหายโดยอิง stats ของเจ้าของ
- `countdownList` — เก็บ countdown ตามระบบของเกม ใช้กำหนดเวลาจบบัฟหรือเริ่มบัฟของเอฟเฟกต์บางอย่างที่ตัวละครบางตัวมี
- `memospriteList` — เป็นเอกสิทธิ์ของตัวละครสาย Remembrance ที่สามารถอัญเชิญ memosprite ได้ โดย memosprite เป็นอีกยูนิตหนึ่งแยกจากเจ้าของ โดนโจมตีได้ และมี stats ของตัวเอง

User ยืนยัน 2026-09-18: `isAllyHaveSummon()` คืน true เมื่อตัวละครมี `summonList` หรือ `memospriteList` อย่างใดอย่างหนึ่ง เพื่อแยกเอฟเฟกต์สำหรับตัวละครที่มีสิ่งอัญเชิญ เช่นบัฟของ Sunday; จงใจไม่รวม `countdownList` เพราะเป็นตัวจับเวลา ไม่ใช่ยูนิตอัญเชิญ

`setTargetAlly`, `setTargetSubUnit` และ `setTargetBuff` เป็น API ตั้งเป้าหมายเริ่มต้นของบัฟ ไม่ใช่ dead code ที่ควรลบ แม้ยังไม่มี caller ภายใน repository: user ยืนยัน 2026-09-18 ว่า `0` ในช่อง sub-unit ให้ `chooseAllyBuff()` คืน `CharUnit` และ `1..N` เลือก memosprite ลำดับที่ 1..N. ฟังก์ชันจึงแปลงเป็น index ของ vector ด้วย `currentMemoNum - 1`; ก่อนแก้ ค่า 1 อ่าน `memospriteList[1]` ผิดเป็นตัวที่สองหรือ out-of-bounds

User ยืนยัน 2026-09-18: ปัจจุบันทุกตัวละครใช้ memosprite ตัวเดียวผ่าน `getMemosprite()` ซึ่งคืน index 0 แต่ให้เก็บ overload `getMemosprite(int num)` ที่ยังไม่มี caller ไว้รองรับตัวละครที่อาจมีหลาย memosprite ในอนาคต

User ยืนยัน 2026-09-18: `isSameOwner()` ตั้งใจเทียบด้วยชื่อของตัวละคร ไม่ใช่ pointer identity เพราะ simulator ไม่อนุญาตตัวละครชื่อซ้ำในทีม; memosprite จะเทียบชื่อของ `owner` ส่วนตัวละครปกติเทียบชื่อตัวเอง

ไล่เส้นทางหลักของทั้งสาม list ครบแล้ว 2026-09-18 รวมการสร้าง/reset, การเลือกเป้าหมาย buff, การตรวจว่ามีสิ่งอัญเชิญ และสถานะเริ่มต้นของแต่ละประเภท

## Main stat ของ relic — `Body` / `Boot` / `Orb` / `Rope`

user ยืนยัน (2026-09-15): ทั้ง 4 ช่องใช้กำหนด main stat ที่เลือกให้แต่ละช่องของ relic และคง main stat เหล่านี้ไว้ระหว่าง reroll substats

- `Body` — เสื้อ
- `Boot` — รองเท้า
- `Orb` — ลูกแก้ว
- `Rope` — เชือก

## Requirement stats — `SpeedRequire` / `ExtraSpeed`

คำอธิบายเจตนาการออกแบบจาก user (2026-09-15):

- `SpeedRequire` — รับค่า SPD รวมที่ต้องการให้ตัวละครมี
- นำค่าเป้าหมายนี้ไปคำนวณหักลบโดยคำนึงถึง base SPD, SPD ที่มีอยู่ และบัฟ เพื่อหาว่ายังขาด SPD อีกเท่าไร
- `ExtraSpeed` — เก็บค่า SPD ที่ยังขาดจากการคำนวณดังกล่าว เพื่อใช้ในรอบ reroll ถัดไป

ตรวจสูตรแล้ว 2026-09-18: `SpeedRequirment()` หาความเร็วปัจจุบันจาก base SPD + SPD% + flat SPD, ปัดจำนวน rolls ที่ยังขาดขึ้นด้วยค่าเฉลี่ย 2.3 แล้วเก็บใน `ExtraSpeed`; memo รับ flat SPD เพิ่มตาม `Unit_Speed_Ratio`

### ATK / HP / DEF requirements

คู่ต่อไปนี้ใช้หลักการเดียวกับ SPD คือ `*Require` เก็บค่า stat รวมที่ต้องการ และ `Extra*` เก็บเปอร์เซ็นต์ stat ที่ได้จากการแลก substat rolls เพื่อให้ถึงเป้าหมาย:

- `AtkRequire` / `ExtraAtk`
- `HpRequire` / `ExtraHp`
- `DefRequire` / `ExtraDef`

ตรวจโค้ดและยืนยันกับ user ใหม่ 2026-09-18:

- `SetCombat()` เรียก `AtkRequirment()`, `HpRequirment()` และ `DefRequirment()` ให้ตัวละครทุกตัว จึงไม่ใช่ dead code
- ATK มี caller จริง: Hibana ตั้ง `setAtkRequire(3600)`
- ยังไม่พบตัวละครตั้ง `HpRequire` หรือ `DefRequire` ในโค้ดปัจจุบัน จึงต่อระบบไว้แล้วแต่ยังไม่มีข้อมูลเข้า
- ทั้งสามสูตรปัดจำนวน roll ขึ้น หัก roll ผ่าน `changeTotalSubStats()` แล้วเพิ่มค่า `Extra*` และ stat% ให้ตัวละครกับ memosprite

### ค่าเฉลี่ยต่อหนึ่ง substat roll

User ยืนยัน 2026-09-18 ว่าค่าคงที่ใน `CalRequireStats.h` ใช้เป็นค่าเฉลี่ยของ substat หนึ่ง roll:

- SPD = `2.3`
- ATK% / HP% / EHR = `3.888`
- DEF% = `4.86`

ระบบนำส่วนที่ยังขาดหารด้วยค่านี้และปัดขึ้น เพื่อหาจำนวน roll ที่ต้องกันไว้ก่อน reroll stats ส่วนที่เหลือ

2026-09-18: แก้ `EhrRequirment()` ให้เพิ่ม `Stats_type[EHR]` ด้วย `x` ที่เพิ่งจัดสรรในรอบนั้น แทนการเพิ่ม `ExtraEhr` สะสมทั้งก้อน มิฉะนั้นกรณีมี `ExtraEhr` เดิมแล้วยังต้องเติมเพิ่มจะบวกค่าเดิมซ้ำ

User ยืนยัน 2026-09-18: ลำดับเรียก requirement ใน `Reset()` คือ priority เมื่อ substat rolls ไม่พอ โดยกันให้ ATK → HP → DEF → SPD → EHR ตามลำดับ; `changeTotalSubStats()` clamp จำนวนที่จัดสรรตาม rolls ที่เหลือ จึงตั้งใจให้ requirement ช่วงท้ายถูกตัดก่อน

2026-09-18: แก้ `HpRequirment()` ให้เพิ่ม HP% ที่จัดสรรใหม่แก่ memosprite เต็มค่า `x` เหมือน ATK%/DEF% เดิมโค้ดคูณ `Unit_Hp_Ratio` ซ้ำทั้งที่ `baseHp` ของ memo ถูกสเกลด้วย ratio แล้ว ทำให้ HP% ที่ได้รับต่ำเกินไป

### EHR — `ApplyBaseChance` / `EhrRequire` / `ExtraEhr`

คำอธิบายเจตนาการออกแบบจาก user (2026-09-15):

- `ApplyBaseChance` — อัตราสร้างสถานะที่นำมาใช้คำนวณว่าต้องการ EHR เท่าไร
- `EhrRequire` — ค่า EHR ที่ต้องการจากการคำนวณดังกล่าว
- `ExtraEhr` — ส่วนของ EHR ที่ยังขาดหลังคำนึงถึงค่าที่มีและบัฟ เพื่อใช้ในรอบ reroll ถัดไป ตามหลักเดียวกับ `SpeedRequire` / `ExtraSpeed`

user ยืนยัน (2026-09-15): ส่วน EHR **ใช้งานจริงแล้ว**

ตรวจสูตรแล้ว 2026-09-18: เมื่อมี `ApplyBaseChance` จะหา EHR ที่ต้องใช้ให้โอกาสติดหลังหัก `Enemy_effect_res` เท่ากับ 100%; เปรียบเทียบกับ `EhrRequire` แล้วเลือกเป้าหมายที่สูงกว่า จากนั้นปัดจำนวน rolls ที่ขาดขึ้นด้วยค่าเฉลี่ย 3.888

## `Technique`

user ยืนยัน (2026-09-15): ความหมายของ `Technique` ขึ้นอยู่กับตัวละคร บางตัวใช้เป็นค่าเปิด/ปิดการใช้ Technique ส่วนบางตัวใช้กำหนดจำนวนครั้งที่ใช้ จึงต้องดูการตีความค่าในโค้ดของตัวละครนั้น

## `Print`

user ยืนยัน (2026-09-15): `Print` ใช้เปิด/ปิดการแสดงผลตอนเริ่มอัลติและจบอัลติ

## `Adjust` — ค่าปรับเฉพาะตัวละคร

คำอธิบายเจตนาการออกแบบจาก user (2026-09-15): `Adjust` เก็บค่าที่เปิดให้ปรับสำหรับตัวละครบางตัว โดยความหมายของแต่ละค่าขึ้นอยู่กับตัวละครนั้น

ตัวอย่าง: อัลติของ Cipher สามารถกำหนดได้ว่า True DMG จะโฟกัสใส่กี่เป้าหมาย ตามคำอธิบายของ user ในเกมจำนวนเป้าหมายขึ้นอยู่กับศัตรูที่เหลือ 1–3 ตัว แต่ใน sim ศัตรูไม่ตาย จึงให้กำหนดค่านี้เองเพื่อจำลองสถานการณ์ดังกล่าว

## `path`

user อธิบาย (2026-09-15): เดิมใช้ `vector<Path>` เพื่อเผื่ออนาคตที่ตัวละครอาจมีหลาย Path ปัจจุบันมีแผนเปลี่ยนกลับเป็น Path เดียว แต่ยังไม่ได้ดำเนินการแก้โค้ดในหัวข้อนี้

## Field ที่ลบแล้ว

- `Wait_Other_Buff` — user ลบแล้ว (2026-09-15); ตรวจ `CharUnit.h` แล้วไม่พบ field นี้ จึงนำออกจากรายการที่รอไล่
- 2026-09-16: ลบ `Set_Other_buff` ทั้ง declaration, definition และคอมเมนต์เก่าที่อ้างถึง field นี้ครบแล้ว; ตรวจ syntax ของ `Application.cpp` ผ่าน

## `Eidolon`

user ยืนยัน (2026-09-15): เก็บระดับ Eidolon ของตัวละครตั้งแต่ E0–E6 เพื่อเปิดความสามารถตามระดับของตัวละคร
