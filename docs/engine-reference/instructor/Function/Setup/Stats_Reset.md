# `src/Defination/Function/Setup/Stats_Reset.h`

## `Memosprite` (จาก `memospriteReset` — ยังไม่ไล่ทั้งไฟล์)

`class Memosprite : public AllyUnit` (`Memosprite.h`) — field เพิ่ม: `unitSpeedRatio` `unitHpRatio` (% ของเจ้าของ) · `fixHP` `fixSpeed` (flat บวกเพิ่ม)

**สร้างครั้งแรก** `setMemoStats(ptr, fixHP, hpRatio, fixSpeed, speedRatio, element, name, type)` (`StatsSet.h:30`) — เซ็ต field, `owner = ptr`, `charptr` = ตัวเอง, `num` = ของเจ้าของ, `baseHp = owner.baseHp * Hp_ratio/100`, `baseAtk`/`baseDef` = ของเจ้าของดิบ ๆ

**`memospriteReset()` — รันใน `reset()` = ต่อ run (ไม่ใช่ต่อ wave)** (`Stats_Reset.h:197-270`) — จุดที่กลไกจริงเกิด:
1. ล้าง `statsType` / `statsEachElement` ของ memo → **ก๊อป `statsType` + `statsEachElement` ของเจ้าของทั้งก้อนมาใส่** (`:215-229`) ณ ต้น run ก่อน `setStats()` ลง substats ที่เลือกใน run นี้; `setStats()` เพิ่ม substats ให้เจ้าของและ memo ภายหลัง
2. `statsType[FLAT_HP]` ทุก AType `*= Unit_Hp_Ratio/100` → แล้ว `[FLAT_HP][NONE] += fixHP` (`:230-233`) — **`fixHP` ถูกใช้ตรงนี้** (ไม่ใช่ที่ `setMemoStats`)
3. `baseSpeed = fixSpeed + calculateSpeedOnStats(owner) * Unit_Speed_Ratio/100` (`:255`) — **คำนวณ ณ ต้น run ก่อน `setStats()`**; `setStats()` เพิ่ม flat SPD ของ substats ให้ memo แยกต่างหากตาม `unitSpeedRatio` บัฟสปีดที่เจ้าของได้กลางรบ (Ruan Mei ฯลฯ) จึงไม่คำนวณ `baseSpeed` ของ memo ใหม่ — ยกเว้นบัฟสปีดที่ยิงใส่ memo โดยตรง
4. `status = DEATH` · `currentHP = 0` (`:262-263`) — **memo เริ่มต้น run ในสภาพตาย** (ถูกต้องตามดีไซน์) ต้องถูก summon ด้วยสกิลกลางรบ (ต่างจาก summon ที่ `summonReset` ตั้ง `ALIVE`). ภายใน run ที่มีหลาย wave: memo ที่ summon ใน wave 0 **อยู่ต่อ** wave 1+ (`memospriteReset` ไม่รันซ้ำระหว่าง wave)

memosprite 2 แบบ: **สปีดคงที่** (RMC "Mem" — `fixSpeed=130, speedRatio=0` → 130 ตายตัว) · **อิงสปีดเจ้าของ** (Aglaea "Garmentmaker" — `fixSpeed=0, speedRatio=35` → 35% ของสปีด Aglaea ณ ต้น run)

## Base stats จาก relic เริ่มต้น

2026-09-18: พบ EHR `3.888 * 2` ถูกเพิ่มซ้ำสองบรรทัด ทำให้ตัวละครเริ่มด้วย EHR 4 rolls (`15.552`) แทน 2 rolls (`7.776`) ตามกติกาค่าเฉลี่ย substat แก้โดยลบบรรทัดซ้ำแล้ว และลบ `HEALING_OUT += 0` ซึ่งไม่มีผลต่อค่า

User ยืนยัน 2026-09-18: ตั้งใจให้ตัวละครทุกตัวได้รับ 2 average substat rolls ของทุก stat ที่ระบุพร้อมกัน ได้แก่ ATK%, Flat ATK, HP%, Flat HP, DEF%, Flat DEF, CR, CD, BE, EHR, RES และ SPD ก่อนใส่ main stats จาก Body/Boot/Orb/Rope โดย CR/CD รวมค่าฐาน 5%/50% และ Flat ATK/HP รวม main stat จากถุงมือ/หมวก

บันทึกการแก้เดิมระบุว่าเคยมี regression test `test/basic_reset_stats_regression.cpp` ตรวจ EHR เริ่มต้น `3.888 * 2` แต่ไม่พบไฟล์นี้ใน workspace ปัจจุบัน (`test/` ถูก `.gitignore`) จึงยังรันยืนยันเคสนี้ซ้ำจากไฟล์ดังกล่าวไม่ได้ ดูวิธีตรวจไฟล์ทดสอบที่มีจริงใน [build-run-and-test.md](../../../../build-run-and-test.md)

## Enemy elemental resistance

User ยืนยัน 2026-09-18: ระบบตั้งใจเก็บ RES ธาตุพื้นฐานของศัตรูเป็นค่าลบใน `statsEachElement[RESPEN]` ส่วน RES PEN และการลด RES เป็นค่าบวก สูตร `calRespenMultiplier()` เริ่มจาก 100 แล้วบวกค่าทั้งหมด เช่น RES ศัตรู 20% ถูกเก็บเป็น `-20` และให้ multiplier 0.8

## Summon และ countdown

2026-09-18: แก้ `summonReset()` และ `countdownReset()` ให้ล้าง `atvStats->extraTurn` เหมือน unit ประเภทอื่น ป้องกัน state รั่วข้าม simulation run โดยมีกรณีใช้งานจริงคือ countdown ของ Phainon ถูกตั้ง `extraTurn = 1` เมื่อใช้ Ultimate

## ฟังก์ชันทั้งไฟล์ — อยู่ที่ไหนบ้าง

ไฟล์นี้มี 4 ฟังก์ชัน ทุกตัวเป็น "ล้างกระดานต่อ 1 run" ไม่ใช่ต่อเทิร์น

| ฟังก์ชัน | บรรทัด | อธิบายไว้ที่ |
|---|---|---|
| `basicReset()` | 3 | ➡️ [SetCombat.md](SetCombat.md) — ล้าง `statsType` / `statsEachElement` ทั้งกอง แล้วรีเซ็ต speed, `turnCnt`, `priority` ฯลฯ ของ ally ทุกตัว · มี regression test ที่ `test/basic_reset_stats_regression.cpp` |
| `memospriteReset()` | 195 | ในไฟล์นี้ (หัวข้อแรก — ยังไล่ไม่ครบทั้งฟังก์ชัน) |
| `summonReset()` | 269 | ในไฟล์นี้ (หัวข้อ "Summon และ countdown") |
| `countdownReset()` | 284 | ในไฟล์นี้ (หัวข้อ "Summon และ countdown") |
