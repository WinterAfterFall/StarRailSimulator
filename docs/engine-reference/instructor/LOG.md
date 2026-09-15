# LOG — บันทึกการไล่โค้ด

> บันทึกก่อน **2026-09-13 (ต่อ 6)** เขียนตอนเอกสารยังเป็นไฟล์เดียว `docs/engine-reference/unit.md` — การอ้างถึงหัวข้อในบันทึกเก่าถูกเปลี่ยนเป็นลิงก์ไปไฟล์ใหม่แล้ว

**2026-09-02** — ทัวร์โค้ดรอบแรก: แก้ description `extraTurn` / `Type` / `priority` · เพิ่ม [Combat.md](Function/Combat/Combat.md) (aha) · กลไก freeze ใน [Combat.md](Function/Combat/Combat.md) · [Stats_Reset.md](Function/Setup/Stats_Reset.md) (Memosprite) · แก้โค้ด `HpAdjust` + rename `Turn_priority` → `nextForwardPriority`

**2026-09-04** — โฟกัสระบบ **taunt + การรับดาเมจ** · push 4 commit:
| commit | ทำอะไร |
|---|---|
| `8690113` | `UnitGotHit` populate (enemy single-target สร้างความเสียหาย 0 → แก้) · `DecreaseHP` ทั้งทีม `return`→`continue` · `addTaunt` dedup · Mydei_Taunt lifecycle (ult 2t / tech 1t / per-enemy removal) · `currentMemoNum` self-assign fix |
| `ce329ef` | ลบ dead code taunt: `totalTaunt` · no-arg `calHitChance()` · `removeTaunt(string)` · + `nextForwardPriority` reset, Enum comment |
| `4d2aa35` | `tauntMtpr` (100=×1) → `tauntIncrease` (0=ไม่มี) · `taunt = baseTaunt·(1+tauntIncrease/100)` · `tauntIncreaseChange(double)` |
| `babcc2f` | เอกสารชุดนี้เข้า git |

**2026-09-09** — เริ่มทัวร์ `CharUnit.h` · จบ **[CharUnit.md](Class/Unit/CharUnit.md)**: คลาสผู้ช่วย 4 ตัว (`Func_class` `DamageSrc` `DamageRecord` `DamageAvgRecord`) + **โมเดล True DMG** (ทำไม `DamageSrc` ต้องมี `src` **และ** `recv`, engine implement เป็น note ล้วนผ่าน `Cal_DamageNote` ไม่ใช่ AType) · ค้นยืนยันกับ wiki/Game8 · เจอ [🐞 #16](BUGS.md) (non-real-time True DMG คูณ toughnessAvgMultiplier ของ `recv` แทน `src`)

**2026-09-13** — ทัวร์ `CharUnit.h` ต่อ · เพิ่ม **[CalDamageNote.md](Function/Calculate/CalDamageNote.md)** (สมุดดาเมจ 2 เล่ม real-time vs non-real-time + `toughnessAvgCalculate` + ข้อยกเว้น Dahlia) และ **[Energy.md](Function/Combat/Energy.md)** (energy: convention 2-arg/3-arg ของ `Increase_energy`, `Ult_cost` vs `Max_energy`, `Max_energy == 0`) · **แก้คำอธิบายที่กลับข้างใน [CharUnit.md](Class/Unit/CharUnit.md) + [🐞 #16](BUGS.md)** — เดิมเขียนว่า Break/SPB/DoT ตกสมุดเฉลี่ย ที่ถูกคือ Break/SPB ตกสมุด**คิดสด** ส่วน DoT + การโจมตีปกติตกสมุด**เฉลี่ย** → ทำให้ [🐞 #16](BUGS.md) เป็นเคสหลักไม่ใช่เคสหายาก

**2026-09-13 (ต่อ)** — เพิ่ม **[FormulaCheck.md](Function/AdjustFunction/FormulaCheck.md)** (CalCheck: โครง 3 ชั้น `All`/กลุ่ม `Src`+`Crit`/เดี่ยว + ถอดตัวย่อ `Mtgt` `MtprInc` `SpbInc` `MM` `PL`/`CB`) · **แก้ [🐞 #18](BUGS.md)** — `calPunchLineMultiplier` อ่าน `Merrymake` แทน `CertifiedBanger` ฝั่งเป้าหมาย 4 จุด (copy-paste จาก `calMerryMakeMultiplier`) คอมไพล์ผ่าน

**2026-09-13 (ต่อ 2)** — เพิ่ม **[Substats_Reset.md](Function/Setup/Substats_Reset.md)** (substats reroll) · **refactor ระบบ reroll ให้โครงเดียวกับ WuwaSimulator**: ตั้งชื่อตัวแปรใหม่ (`spiltPoint` → `rerollTargetIndex` ฯลฯ) · เขียน `StandardReroll` ใหม่ + แยก `trySwapSubstat` / `restoreBestSubstats` · ลบ `SeparateRatio` · ลบ `Damage_data` / `*_Compare` + `Print_All_Substats` (user สั่งทิ้ง E3/E4) · comment `AllCombination` / `AllPossible` ทั้งหมด · เทียบผลเก่า/ใหม่ด้วย Python 6000 เคส ผลตรงกันทุกเคส · เพิ่มหมายเหตุใน [🐞 #16](BUGS.md) (`Cal_DamageSummary` ใช้ `src` ถูกแล้ว ที่ผิดคือ `Cal_AverageDamage`)

**2026-09-13 (ต่อ 3)** — user ตอบ E2: จำนวน roll รวมกำหนดเอง ปกติ **25** · ลบ `currentTotalSubstats` (ไม่มีใครอ่าน) · ปิด [🐞 #8](BUGS.md) (summon/countdown ไม่ได้ใช้ `owner`) · dead code ปล่อยไว้ · [🐞 #16](BUGS.md) ระบุบรรทัดแล้ว (ต้องแก้ 2 จุด) · **ต่อจากนี้ทำทีละหัวข้อ**

**2026-09-13 (ต่อ 4)** — แก้ตามที่ user สั่ง: `Total_substats` ค่าเริ่มต้น 20 → 25 · [🐞 #1](BUGS.md) ลบ include ซ้ำ · [🐞 #2](BUGS.md) summon ใช้ชื่อที่ส่งมา (`LL`) · [🐞 #4](BUGS.md) rename `isExsited` → `isExisted` (9 จุด) · [🐞 #16](BUGS.md) `Cal_AverageDamage` อัปเดตตัวคูณเฉลี่ยให้ศัตรูทุกตัว แล้วใช้ของ `src` · คอมไพล์ผ่าน

**2026-09-13 (ต่อ 5)** — เพิ่ม **[CharUnit.md](Class/Unit/CharUnit.md)** (Build: `Func_class` 4 ช่อง) · ลบเงื่อนไขอัลติของ Tribbie ทั้งก้อน (DDD 2 บรรทัด + เช็ค Eagle ผิดช่องที่ไม่มีวันจริง) · ลบเช็ค DDD ของ Hanabi / HanabiV1 (ใส่ DDD แล้วไม่มีวันกดอัลติ) · แก้ชื่อ planar `Rutilant` / `Inert` · user: เก็บช่อง `Name` / `Print_Func` ไว้ก่อน

**2026-09-13 (ต่อ 6)** — ย้าย `docs/engine-reference/unit.md` ทั้งไฟล์มาเป็น `instructor/` ที่ mirror โครง `src/Defination/` (README ทุกโฟลเดอร์ + `.md` ทุกไฟล์โค้ด · ไฟล์ที่ยังไม่มีข้อมูลปล่อยว่าง) · บั๊กย้ายไป [BUGS.md](BUGS.md) · บันทึกนี้ย้ายมาเป็น LOG.md · ปรับสถานะ [🐞 #7](BUGS.md) เป็น ✅ (โค้ดแก้ไปตั้งแต่ `8690113` แต่รายการเดิมลืมอัปเดต)

**ค้าง / session หน้า:**
- **2026-09-15 (ต่อ 20)** — ตรวจชื่อ field ใหม่ใน `Enemy.h` / `AllyUnit.h` และปรับเอกสารอ้างอิง: `DebuffNote` → `debuffNote`, `Debuff_time_count` → `debuffEnd`, `Stack` → `stack`, `Buff_note` → `buffNote`, `Buff_countdown` → `buffEnd`, `Buff_check` → `buffCheck` · `debuffCheck`, `buffSubUnitTarget`, `buffAllyTarget` ตรงกับโค้ดแล้ว · ชื่อ accessor เดิมยังคงอยู่ · เก็บชื่อเก่าในบันทึกย้อนหลังไว้ตามเหตุการณ์ · ตรวจกลไก `debuffEnd` จาก `Debuff_Stats.h` แล้ว
- **2026-09-15 (ต่อ 19)** — user ยืนยันว่า `Enemy::Stack` เก็บจำนวนสแต็กตามชื่อ · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `Debuff_time_count`
- **2026-09-15 (ต่อ 18)** — user อธิบาย `DebuffNote` ว่าเก็บปริมาณเอฟเฟกต์เดิมของ debuff เพื่อคำนวณส่วนต่างเมื่ออัปเดต เช่น ลด DEF ตาม ATK ผู้ร่าย · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `Stack`
- **2026-09-15 (ต่อ 17)** — user เปลี่ยน `Enemy::Debuff` เป็น `debuffCheck` และอธิบายว่าใช้เช็กว่า debuff นั้นยังอยู่หรือไม่ · ตรวจชื่อใหม่ใน `Enemy.h` แล้ว · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `DebuffNote`
- **2026-09-15 (ต่อ 16)** — ตรวจเส้นทาง Damage Record ตามคำขอ user: ระหว่างต่อสู้เก็บฝั่ง `CharUnit`, ค่าเฉลี่ยเก็บตัวอย่างดาเมจสะสม / ATV ตั้งแต่ ATV 300 โดยเพิ่มตัวอย่างเมื่อห่างอย่างน้อย 20 ATV; field ของ `Enemy` รวมตอน `printSummaryResult()` · บันทึกใน [Enemy.md](Class/Unit/Enemy.md)
- **2026-09-15 (ต่อ 15)** — user ยืนยันว่า `BreakSideEffect::type` ระบุชนิดสถานะจาก Break · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · อธิบาย field ทั้ง 4 ตัวแล้ว ถัดไปกลุ่ม Damage Record ของ `Enemy`
- **2026-09-15 (ต่อ 14)** — user ยืนยันว่า `BreakSideEffect::stack` เก็บจำนวนชั้นของสถานะจาก Break เช่น Wind Shear และ Entanglement · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `type`
- **2026-09-15 (ต่อ 13)** — user ยืนยันว่า `BreakSideEffect::countdown` เก็บเลขเทิร์นของศัตรูที่สถานะจะหมดอายุ เช่น `turnCnt + 2` · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `stack`
- **2026-09-15 (ต่อ 12)** — เริ่ม `Enemy.h`: user ยืนยันว่า `BreakSideEffect::ptr` คือยูนิตที่เป็นคนทำ Break · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `countdown`
- **2026-09-15 (ต่อ 11)** — user ยืนยันว่า `Eidolon` เก็บระดับ E0–E6 เพื่อเปิดความสามารถตามระดับตัวละคร · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ได้คำอธิบายเจตนาของ field ที่ค้างแล้ว แต่รายละเอียดสูตรและการทำงานที่ระบุว่ายังไม่ได้ไล่ยังคงค้าง · เริ่มหัวข้อถัดไป `Enemy.h`
- **2026-09-15 (ต่อ 10)** — user อธิบายว่า `vector<Path> path` เดิมเผื่อหลาย Path ในอนาคต ตอนนี้รอเปลี่ยนกลับเป็น Path เดียว · บันทึกเจตนาใน [CharUnit.md](Class/Unit/CharUnit.md) ยังไม่ได้แก้โค้ด · `Eidolon` ยังไม่ได้อธิบาย
- **2026-09-15 (ต่อ 9)** — user อธิบาย `Adjust` เป็นค่าปรับเฉพาะตัวละคร เช่น จำนวนเป้าหมาย True DMG ของอัลติ Cipher ซึ่งกำหนดเองเพราะศัตรูใน sim ไม่ตาย · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `path`
- **2026-09-15 (ต่อ 8)** — user อธิบายว่า `Print` ใช้เปิด/ปิดการแสดงผลตอนเริ่มและจบอัลติ · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `Adjust`
- **2026-09-15 (ต่อ 7)** — user ลบ `Wait_Other_Buff` แล้ว; ตรวจ `CharUnit.h` ไม่พบ field นี้ · อัปเดตสารบัญ field ใน [CharUnit.md](Class/Unit/CharUnit.md) ให้ตรงกับหัวข้อที่อธิบายแล้ว · ถัดไป `Print`
- **2026-09-15 (ต่อ 6)** — user อธิบายว่า `Technique` บางตัวละครใช้เปิด/ปิด บางตัวใช้กำหนดจำนวนครั้ง · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md)
- **2026-09-15 (ต่อ 5)** — user ยืนยันว่าส่วน EHR (`ApplyBaseChance` / `EhrRequire` / `ExtraEhr`) ใช้งานจริงแล้ว · อัปเดต [CharUnit.md](Class/Unit/CharUnit.md)
- **2026-09-15 (ต่อ 4)** — user อธิบายว่า `ApplyBaseChance` ใช้หา EHR ที่ต้องการใน `EhrRequire` ส่วน `ExtraEhr` ใช้หลักเดิมคือเก็บส่วนที่ยังขาดสำหรับ reroll ถัดไป · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ยืนยันสถานะการใช้งานของส่วน EHR
- **2026-09-15 (ต่อ 3)** — user ยืนยันว่าคู่ requirement ของ ATK / HP / DEF ใช้หลักเดียวกับ SPD แต่ยังเป็น dead code · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `ApplyBaseChance` / `EhrRequire` / `ExtraEhr`
- **2026-09-15 (ต่อ 2)** — user อธิบาย `SpeedRequire` เป็นเป้าหมาย SPD รวม และ `ExtraSpeed` เก็บ SPD ที่ยังขาดหลังคำนึงถึง base SPD, SPD ที่มี และบัฟ เพื่อใช้ในรอบ reroll ถัดไป · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ยืนยันคู่ requirement stats อื่น
- **2026-09-15 (ต่อ)** — user ยืนยันว่า `Body` / `Boot` / `Orb` / `Rope` กำหนด main stat แต่ละช่องและคงไว้ระหว่าง reroll substats · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป requirement stats
- **2026-09-15** — ทัวร์ `CharUnit.h` ต่อ: user อธิบาย `summonList` (โดนตีไม่ได้ ใช้ stats เจ้าของคำนวณดาเมจ), `countdownList` (กำหนดเวลาเริ่ม/จบบัฟ) และ `memospriteList` (เอกสิทธิ์ของ Remembrance ที่อัญเชิญ memosprite ได้ เป็นยูนิตแยก โดนตีได้ มี stats ของตัวเอง) · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ไล่รายละเอียดการทำงานของแต่ละ list ครบ
- ~~รัน sim จริง~~ ✅ user รันผ่านแล้ว (2026-09-13) · push แล้ว `31c9a49..e8de52b` · **Dahlia (`Combat.h`) ยังไม่ commit — user จะอ่านวันหลัง**
- ~~E2~~ ✅ ตอบแล้ว (2026-09-13): จำนวน roll รวม user กำหนดเอง ปกติ **25** — ตัวละครทุกตัวเรียก `setTotalSubstats(25)` (ค่าเริ่มต้นใน `CharUnit.h` แก้จาก 20 เป็น 25 แล้ว) · `currentTotalSubstats` ไม่มีใครอ่าน → **ลบแล้ว**
- ทัวร์ต่อ `CharUnit.h` หัวข้อที่เหลือ (ทีละหัวข้อ): summon/memo/countdown lists · relic main-stat slots · requirement stats
- แล้วค่อย: `Enemy.h` → `StatsSet.h`
- 🐞 ~~#1 · #2 · #4 · #16~~ ✅ แก้แล้ว 2026-09-13 (push แล้ว) · ~~#8~~ ปิด — user: summon/countdown ไม่ได้ใช้ `owner`
- dead code (โซนอื่น): `DecreaseHP(Unit*, vector, ...)` overload · `Enemy::hitCount` — **ปล่อยไว้** (user 2026-09-13)
- `future-improvements.md`: ระบบสร้างโล่ · per-unit `priority` reset · buff auto-removal helper · AllyUnit cosmetic
- ~~`docs/character-kit-reference/*.md` (~40 ไฟล์) ยัง untracked~~ ✅ เข้า git แล้ว (`f6af8b7`)
