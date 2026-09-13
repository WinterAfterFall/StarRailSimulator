# LOG — บันทึกการไล่โค้ด

> บันทึกก่อน **2026-09-13 (ต่อ 6)** เขียนตอนเอกสารยังเป็นไฟล์เดียว `docs/engine-reference/unit.md` — การอ้างถึงหัวข้อในบันทึกเก่าถูกเปลี่ยนเป็นลิงก์ไปไฟล์ใหม่แล้ว

**2026-09-02** — ทัวร์โค้ดรอบแรก: แก้ description `extraTurn` / `Type` / `priority` · เพิ่ม [Combat.md](Function/Combat/Combat.md) (aha) · กลไก freeze ใน [Combat.md](Function/Combat/Combat.md) · [Stats_Reset.md](Function/Setup/Stats_Reset.md) (Memosprite) · แก้โค้ด `HpAdjust` + rename `Turn_priority` → `nextForwardPriority`

**2026-09-04** — โฟกัสระบบ **taunt + การรับดาเมจ** · push 4 commit:
| commit | ทำอะไร |
|---|---|
| `8690113` | `UnitGotHit` populate (enemy single-target ลงดาเมจ 0 → แก้) · `DecreaseHP` ทั้งทีม `return`→`continue` · `addTaunt` dedup · Mydei_Taunt lifecycle (ult 2t / tech 1t / per-enemy removal) · `currentMemoNum` self-assign fix |
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
- ~~รัน sim จริง~~ ✅ user รันผ่านแล้ว (2026-09-13) · push แล้ว `31c9a49..e8de52b` · **Dahlia (`Combat.h`) ยังไม่ commit — user จะอ่านวันหลัง**
- ~~E2~~ ✅ ตอบแล้ว (2026-09-13): จำนวน roll รวม user กำหนดเอง ปกติ **25** — ตัวละครทุกตัวเรียก `setTotalSubstats(25)` (ค่าเริ่มต้นใน `CharUnit.h` แก้จาก 20 เป็น 25 แล้ว) · `currentTotalSubstats` ไม่มีใครอ่าน → **ลบแล้ว**
- ทัวร์ต่อ `CharUnit.h` หัวข้อที่เหลือ (ทีละหัวข้อ): summon/memo/countdown lists · relic main-stat slots · requirement stats
- แล้วค่อย: `Enemy.h` → `StatsSet.h`
- 🐞 ~~#1 · #2 · #4 · #16~~ ✅ แก้แล้ว 2026-09-13 (push แล้ว) · ~~#8~~ ปิด — user: summon/countdown ไม่ได้ใช้ `owner`
- dead code (โซนอื่น): `DecreaseHP(Unit*, vector, ...)` overload · `Enemy::hitCount` — **ปล่อยไว้** (user 2026-09-13)
- `future-improvements.md`: ระบบสร้างโล่ · per-unit `priority` reset · buff auto-removal helper · AllyUnit cosmetic
- ~~`docs/character-kit-reference/*.md` (~40 ไฟล์) ยัง untracked~~ ✅ เข้า git แล้ว (`f6af8b7`)
