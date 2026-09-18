# `src/Defination/Function/Setup/Stats_Reset.h`

## `Memosprite` (จาก `Memosprite_reset` — ยังไม่ไล่ทั้งไฟล์)

`class Memosprite : public AllyUnit` (`Memosprite.h`) — field เพิ่ม: `Unit_Speed_Ratio` `Unit_Hp_Ratio` (% ของเจ้าของ) · `fixHP` `fixSpeed` (flat บวกเพิ่ม)

**สร้างครั้งแรก** `SetMemoStats(ptr, fixHP, Hp_ratio, fixSpeed, Speed_ratio, element, name, type)` (`StatsSet.h:30`) — เซ็ต field, `owner = ptr`, `charptr` = ตัวเอง, `num` = ของเจ้าของ, `baseHp = owner.baseHp * Hp_ratio/100`, `baseAtk`/`baseDef` = ของเจ้าของดิบ ๆ

**`Memosprite_reset()` — รันใน `Reset()` = ต่อ run (ไม่ใช่ต่อ wave)** (`Stats_Reset.h:197-270`) — จุดที่กลไกจริงเกิด:
1. ล้าง `Stats_type` / `Stats_each_element` ของ memo → **ก๊อป `Stats_type` + `Stats_each_element` ของเจ้าของทั้งก้อนมาใส่** (`:215-229`) → memo สืบ crit / DMG% / ทุก stat จากเจ้าของ ณ ต้น run (หลัง relic + trace + substats แต่ก่อนบัฟกลางรบ)
2. `Stats_type[FLAT_HP]` ทุก AType `*= Unit_Hp_Ratio/100` → แล้ว `[FLAT_HP][None] += fixHP` (`:230-233`) — **`fixHP` ถูกใช้ตรงนี้** (ไม่ใช่ที่ `SetMemoStats`)
3. `baseSpeed = fixSpeed + calculateSpeedOnStats(owner) * Unit_Speed_Ratio/100` (`:255`) — **snapshot ณ ต้น run** = เอาแค่ผลของ relic + stat/trace ของเจ้าของ. **โดยตั้งใจ:** บัฟสปีดที่เจ้าของได้กลางรบ (Ruan Mei ฯลฯ) **ไม่ส่งผล** ต่อ memo — ยกเว้นบัฟสปีดที่ยิงใส่ memo โดยตรง
4. `status = Death` · `currentHP = 0` (`:262-263`) — **memo เริ่มต้น run ในสภาพตาย** (ถูกต้องตามดีไซน์) ต้องถูก summon ด้วยสกิลกลางรบ (ต่างจาก summon ที่ `Summon_reset` ตั้ง `Alive`). ภายใน run ที่มีหลาย wave: memo ที่ summon ใน wave 0 **อยู่ต่อ** wave 1+ (`Memosprite_reset` ไม่รันซ้ำระหว่าง wave)

memosprite 2 แบบ: **สปีดคงที่** (RMC "Mem" — `fixSpeed=130, Speed_ratio=0` → 130 ตายตัว) · **อิงสปีดเจ้าของ** (Aglaea "Garmentmaker" — `fixSpeed=0, Speed_ratio=35` → 35% ของสปีด Aglaea ณ ต้น run)

## Base stats จาก relic เริ่มต้น

2026-09-18: พบ EHR `3.888 * 2` ถูกเพิ่มซ้ำสองบรรทัด ทำให้ตัวละครเริ่มด้วย EHR 4 rolls (`15.552`) แทน 2 rolls (`7.776`) ตามกติกาค่าเฉลี่ย substat แก้โดยลบบรรทัดซ้ำแล้ว และลบ `HEALING_OUT += 0` ซึ่งไม่มีผลต่อค่า

มี regression test ที่ `test/basic_reset_stats_regression.cpp` ตรวจว่า `Basic_reset()` ให้ EHR เริ่มต้นเท่ากับ `3.888 * 2`
