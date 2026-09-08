# Cipher (Cifera) — ไซเฟอร์

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Cipher.h` |
| ธาตุ | **Quantum** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review/calc patch 3.3) |

## Base Stats (Lv.80, ascended)
HP 931 · ATK 640 · DEF 509 · SPD 106

> Nihility sub-DPS/amplifier สาย "Patron" + DMG tally → True DMG burst

---

## Basic ATK — Oops, a Missed Catch (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Hey, Jackpot for the Taking (Blast, Lv.10)
- 120% base chance ติด Weaken เป้าหมาย + ข้างเคียง (−10% DMG dealt) + Cipher ATK **+30%** นาน 2 เทิร์น
- Quantum DMG หลัก = **200% ATK**, ข้างเคียง = **100% ATK**
- Energy +30 · Toughness 20 (+10)

## Ultimate — Yours Truly, Kitty Phantom Thief! (Blast, 130 energy, Lv.10)
- Quantum DMG = **120% ATK** ใส่เป้าหมายหลัก
- True DMG = **25% ของ tally ปัจจุบันจาก Talent** ใส่เป้าหมายหลัก
- Quantum DMG = **40% ATK** + True DMG = **75% ของ tally** ใส่เป้าหมายหลัก + ข้างเคียง (True DMG นี้กระจายเท่ากันทุกเป้าของท่านี้)
- หลังใช้ → ล้าง tally
- Energy +5 · Toughness 30 (+20)

## Talent — The Hospitable Dolosian (Lv.10)
- ถ้าไม่มีศัตรูสถานะ "Patron" → Cipher ทำให้ศัตรู Max HP สูงสุดเป็น "Patron" ทันที
- ใช้ Skill/Ult → เป้าหมายหลักเป็น "Patron" (มีผลกับ target ล่าสุด)
- หลัง "Patron" ถูกเพื่อนคนอื่นโจมตี → Cipher ยิง Follow-up ATK ใส่ "Patron": Quantum DMG = **150% ATK** (1 ครั้ง/เทิร์น, reset ต้นเทิร์นของ Cipher)
- Cipher **tally 12% ของ non-True DMG** ที่เพื่อนทำกับ "Patron" (overflow ไม่นับ); ล้าง tally หลังใช้ Ult
- Energy +5 · Toughness 20

## Technique — Puss in Boots
- ได้ "Zagreus's Blessing" 15 วิ
- เข้าฉากพร้อม Blessing → Quantum DMG = **100% ATK** AoE + เพิ่ม recorded DMG จาก instance นี้ **+200%**

---

## Major Traces
- **A2 — Empyrean Strides**: SPD ≥ 140/170 → CRIT Rate **+25%/+50%** + tally ที่ได้ **+50%/+100%**
- **A4 — 300 Rogues**: Cipher tally **8% ของ non-True DMG** ที่เพื่อนทำกับศัตรูตัวอื่นที่ไม่ใช่ "Patron"
- **A6 — Sleight of Sky**: Talent Follow-up ATK CRIT DMG **+100%**. ขณะ Cipher อยู่ในสนาม → ศัตรูทุกตัวรับดาเมจเพิ่ม **+40%**

## Minor Traces (รวมทั้งหมด)
Quantum DMG +14.4% · SPD +14 · Effect HIT Rate +10%

## Eidolons
- **E1**: recorded DMG = **150%** ของเดิม. ใช้ Talent Follow-up ATK → Cipher ATK **+80%** นาน 2 เทิร์น
- **E2**: Cipher ตีโดนศัตรู → 120% base chance ศัตรูรับดาเมจเพิ่ม **+30%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: หลัง "Patron" ถูกเพื่อนโจมตี → Cipher สร้าง Quantum Additional DMG = **50% ATK**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Talent Follow-up ATK DMG **+350%**. record เพิ่มอีก **16%** ของ non-overflow DMG ของ FUA. หลังล้าง record ตอน Ult → คืน **20%** ของ record ที่ล้าง

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **DMG tally**: 12% ของ non-True DMG ที่เพื่อนทำกับ Patron (+A4 8% non-Patron, A2 ×1.5/×2, E6 +16% FUA) — overflow (kill) ไม่นับ
- **Ult burst**: True DMG 25% (single) + 75% (blast, กระจาย) ของ tally → ล้าง tally (E6 คืน 20%)
- **Patron**: auto-assign HP สูงสุด, หรือ Skill/Ult target; FUA 150% ATK เมื่อเพื่อนตี Patron (1/เทิร์น)
- **A6**: enemy DMG-taken +40% ทีม (huge global amp)
- โค้ด: `Start_game_List` priority `PRIORITY_Last` (`Cipher.h:132`, `cph`) มี addToActionBar + `Deal_damage()` (technique attack self-flush) — **หมายเหตุ**: ตัวนี้เป็น `PRIORITY_Last` จงใจให้รันหลัง technique อื่น
- `BeforeAttackAction_List` มี "Cipher Fua" trigger (E2 vuln, Patron debuff)

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/cipher — kit tab (review/calc patch 3.3, profile 01/Jun/2026)
