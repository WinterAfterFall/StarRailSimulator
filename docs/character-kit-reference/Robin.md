# Robin — โรบิน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Robin.h` |
| ธาตุ | **Physical** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 4.0) |

## Base Stats (Lv.80, ascended)
HP 1280 · ATK 640 · DEF 485 · SPD 102

> Harmony support สาย ATK buff + Concerto (Additional DMG on every ally attack)

---

## Basic ATK — Wingflip White Noise (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Pinion's Aria (Support, Lv.10)
- เพื่อนทุกคน +DMG dealt **50%** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Robin)
- Energy +30

## Ultimate — Vox Harmonique, Opus Cosmique (Support, 160 energy, Lv.10)
- Robin เข้าสถานะ **Concerto** + เพื่อนคนอื่นทุกคน **action ทันที**
- ขณะ Concerto:
  - เพื่อนทุกคน ATK **+เท่ากับ 22.8% ของ ATK ของ Robin + 200**
  - หลังเพื่อนโจมตีทุกครั้ง → Robin สร้าง Additional Physical DMG = **120% ATK** 1 ครั้ง (fixed CRIT Rate 100%, fixed CRIT DMG 150%)
  - Robin ภูมิคุ้มกัน CC, ไม่มีเทิร์น/action จนกว่า Concerto จบ
- Concerto countdown ใน action order, SPD คงที่ **90**; ถึงตา → ออกจาก Concerto + action ทันที
- Energy +5

## Talent — Tonal Resonance (Lv.10)
- เพื่อนทุกคน CRIT DMG **+20%**
- หลังเพื่อนโจมตีศัตรู → Robin คืน Energy **2** ให้ตัวเอง

## Technique — Overture of Inebriation
- สร้าง dimension 15 วิ (ศัตรูไม่โจมตี Robin, ตาม Robin)
- เข้าฉากใน dimension → Robin คืน Energy **5** ต้นแต่ละ wave

---

## Major Traces
- **A2 — Coloratura Cadenza**: ต้นการต่อสู้ → Robin action advance **25%**
- **A4 — Impromptu Flourish**: ขณะ Concerto → CRIT DMG ของ follow-up attack ของเพื่อนทุกคน **+25%**
- **A6 — Sequential Passage**: ใช้ Skill → คืน Energy **5** เพิ่ม

## Minor Traces (รวมทั้งหมด)
ATK +28% · HP +18% · SPD +5

## Eidolons
- **E1 — Land of Smiles**: ขณะ Concerto → เพื่อนทุกคน All-Type RES PEN **+24%**
- **E2 — Afternoon Tea For Two**: ขณะ Concerto → เพื่อนทุกคน SPD **+16%**. Talent energy regen **+1** (รวม 3)
- **E3**: Skill Lv. +2 · Ultimate Lv. +2
- **E4 — Raindrop Key**: ใช้ Ult → ล้าง CC เพื่อนทุกคน. ขณะ Concerto → เพื่อนทุกคน Effect RES **+50%**
- **E5**: Basic ATK Lv. +1 · Talent Lv. +2
- **E6 — Moonless Midnight**: ขณะ Concerto → CRIT DMG ของ Additional Physical DMG จาก Ult **+450%** (trigger สูงสุด 8 ครั้ง, ตัวนับรีเซ็ตทุกครั้งใช้ Ult)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Concerto** = countdown unit SPD 90; Robin ไม่มีเทิร์นระหว่างนั้น; เพื่อน action ทันทีตอนเข้า
- **ATK buff (Concerto)**: 0.228 × (ATK ของ Robin) + 200 — flat ATK ผูกกับ ATK ของ Robin ต้อง re-eval (`Stats_Adjust_List` ในโค้ด: `Concerto_state` buff note)
- **Additional Physical DMG**: 120% ATK ต่อการโจมตีของเพื่อน, fixed crit 100%/150% (+E6 CD +450%, cap 8/Ult)
- **Talent energy**: +2 (E2 +3) ต่อการโจมตีของเพื่อน — ป้อน energy Robin กลับ
- โค้ด: `Start_game_List` (`Robin.h:113`) = action forward 25% (A2); `Start_wave_List` = technique energy 5; countdown ใช้ `SetCountdownStats(ptr,90,"Concerto_state")`
- `Double_Turn` / `driverType` logic — Robin มี `addUltCondition` หลายชั้นในโค้ด

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/robin — kit tab (review patch 2.6, calc patch 4.0, profile 01/Jun/2026)
