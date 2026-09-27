# `src/Defination/Data/Character/Elation/SilverWolf999.h`

kit อ้างอิง: [`docs/kit-reference/Character/Elation/silver-wolf-lv-999.md`](../../../../../kit-reference/Character/Elation/silver-wolf-lv-999.md) (ข้อมูลเกม 4.5.54 จาก nanoka) · ชื่อ unit ในโค้ด `"Silver Wolf 999"` · เลือกใน `SettingFunction.h` ด้วยชื่อ `SilverWolf999`
คำศัพท์ของ path Elation (Punchline, Certified Banger, Aha Instant) อยู่ใน [Hibana.md](Hibana.md) — อ่านก่อน

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**

## ภาพรวมแบบสั้น

Silver Wolf LV.999 เป็น DPS ที่ "สะสมแต้มก่อน แล้วระเบิดทีเดียว"

1. **ช่วงสะสม** — ตีปกติ/ใช้สกิล ทุกครั้งที่ทีมได้ Punchline เธอได้แต้มลับชื่อ **Hidden MMR** เท่ากัน MMR ทำให้คริเรตสูงขึ้น (และคริดาเมจเมื่อคริเรตเต็ม)
2. **ครบ 60 MMR** — กด Ult ได้ (ไม่ใช้พลังงานเลย) เข้าสถานะ **Godmode Player**
3. **ช่วง Godmode** — ทุกเทิร์นใช้ **Enhanced Basic ATK** (100 bounce + เปิด "Top Loot Box" 3 กล่อง + Final Hit) ครบ 3 ครั้งก็ออก และ MMR ถูกล้าง · ระหว่างนี้มี **Zone**: เพื่อนใช้ SP ทีไร มีโอกาสเปิดกล่องเพิ่ม

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 110, Imaginary, Elation, HP/ATK/DEF 1048/388/655 | `setCharBasicStats(110,0,0,...)` — energy 0 / ult cost 0 แบบ Phainon เพราะ Ult ใช้ MMR แทน | 12-13 |
| build | main stat ตาม nanoka: CR / SPD / HP% / DEF% · เป้า SPD 160 (เปิด A2) | `setSpeedRequire(160)` · `setRelicMainStats(...)` | 16-20 |
| นับเข้า Elation ในทีม | — | `elationCount++` | 22 |
| **Hidden MMR → คริ** (Talent) | 1 แต้ม = CR +0.4% จน CR ถึง 100% แล้วแต้มที่เหลือ = CD +0.8% | **ตัดเหลือ CD +0.8% ต่อแต้มตั้งแต่แต้มแรก** (user 2026-09-28) — ถือว่า CR เต็ม 100% อยู่แล้วเพราะ substat reroll เติม CR ให้จนเต็ม · `updateMMRCritDmg` ใส่ส่วนต่างเทียบ `buffNote["SW999 MMR CD"]` | 31-38 |
| **ได้ MMR** (Talent) | ได้ Punchline เท่าไหร่ ได้ MMR เท่านั้น · เพดาน 60 + ล้น 240 = 300 | `gainMMR` clamp 0–300 → `updateMMRCritDmg` → ส่งส่วนที่เพิ่มจริงให้ `e2Gain` · ดักจาก `punchLineList` เฉพาะค่าบวกที่มีเจ้าของ (`spMaker != nullptr`) | 50-56, 267-270 |
| **Basic ATK** | 100% ATK เดี่ยว · toughness 10 · SP +1 | lambda `ba` | 109-121 |
| **Skill** | Punchline +5 · 160% ATK ทุกตัว · toughness 10 · SP −1 | lambda `skill` | 123-138 |
| **ดาเมจ Elation 40% ของ Talent** | ถือ Certified Banger อยู่ → BA/Skill ตีเพิ่ม 40% Elation DMG ใส่เป้าที่โดน | `talentElation` สร้าง action `ELATION_DMG` แยกก้อน (แบบเดียวกับ Hibana) · เช็ค `CERTIFIED_BANGER[NONE] > 0` | 95-107 |
| **Ultimate** | เข้า Godmode · ดันแอคชัน 100% · กาง Zone | ตั้ง `buffCheck[GODMODE]`, `EBA Left = 3`, รีเซ็ตโอกาสกล่องเป็น 100% · `actionForward(...,100)` | 202-227 |
| เงื่อนไขกด Ult | MMR ≥ 60 และยังไม่อยู่ใน Godmode | `addUltCondition` | 198-200 |
| **Enhanced Basic ATK** | 240% ATK แบ่ง 100 bounce · หยุดเปิดกล่องเป็นระยะ รวม 3 กล่อง · Final Hit 100% หารทุกตัว · ทุก 60 MMR ดาเมจ +15% (สูงสุด 2 ชั้น) · ถือ Certified Banger → ดาเมจทั้งท่ากลายเป็น Elation DMG | `fillEbaSegment` สร้างช่วงละ 25 bounce (2.4% × ตัวคูณ MMR ต่อ bounce) · `eba` ตีช่วงแรก → วน 3 รอบ: เปิดกล่อง → ตีอีก 25 bounce (รอบสุดท้ายแปะ Final Hit) · เลือก `DmgSrcType::ELATION` แทน `ATK` เมื่อมี CB | 143-155, 165-188 |
| ออกจาก Godmode | ใช้ EBA ครบ → ออก · ล้าง MMR | `EBA Left` ลดทีละ 1 · ถึง 0 เรียก `exitGodmode` | 157-163, 183-184 |
| AI เลือกท่า | — | Godmode → EBA · ไม่งั้น `sp > spSafety` → Skill · ไม่งั้น BA | 192-196 |
| **Top Loot Box** | 90% Elation DMG หารทุกตัว + สุ่ม 1 ใน 3 เอฟเฟกต์ · เอฟเฟกต์แต่ละแบบลด toughness AoE 10 | `makeLootBox` คืน action `ELATION_DMG` ชื่อบอกเอฟเฟกต์ · `turnReset = 0` (ไม่ใช่เทิร์นของใคร) | 69-88 |
| ↳ Big Flipping Sword | True DMG 20% ของดาเมจกล่องนั้น ใส่ศัตรู HP มากสุด | `afterDealingDamageList` จับชื่อ `"SW999 Loot Sword"` → `calDamageNote(...,20,...)` ใส่เป้าหลัก (`mainEnemyNum`) แบบ Phainon E6 | 273-277 |
| ↳ Kaboom Eggsplosion | SP +2 | `genSkillPoint(ptr,2)` ใน callback | 77 |
| ↳ Funky Munch Bean | Punchline +3 (→ MMR +3 ด้วย) | `genPunchLine(ptr,3)` | 78 |
| **Zone** | ใน Godmode + ถือ CB: เพื่อนใช้ SP 1 แต้ม = มีโอกาสเปิดกล่อง · เริ่ม 100% ติดแล้วเหลือ 20% ของเดิม | `skillPointList` · สะสมโอกาส (ดูหัวข้อ "แปลงความสุ่ม") · เปิดแล้ว `addToActionBar()` + `dealDamage()` → ถ้าอยู่กลาง action อื่นจะต่อคิวหลัง action นั้น | 253-264 |
| **Elation Skill ปกติ** — Pro-Gamer Move | MMR +15 | ใน `elationSkillList` ถ้าไม่ได้อยู่ใน Godmode → `gainMMR(15)` ตรง ๆ **ไม่สร้าง action** (ท่านี้ไม่มีดาเมจ และ `AllyBuffAction` ไม่มี `addToAhaInstant`) | 230-236 |
| **Elation Skill เสริม** — Honkai-DMG Demo | (Godmode) 6 ฮิต × 90% Elation สุ่มเป้า · toughness 10 · รีเซ็ตโอกาสกล่องเป็น 100% | action `ELATION_SKILL` · `addEnemyBounce(...,6)` · `addToAhaInstant()` | 237-249 |
| priority ของ Elation Skill | Participant ID 999 | ตัวเลขดิบ `999` แบบเดียวกับ Hibana `144` / Yao Guang `114` | 230 |
| **Technique** | ทุกต้น wave เปิดกล่อง 1 ใบ คิด Certified Banger ตายตัว 99 | `startWaveList` · ครอบ callback ของกล่อง: ตั้ง CB ให้เป็น 99 ชั่วคราว → ตี → คืนค่า | 302-314 |
| **Minor traces** | CR +18.7 · Elation +10 · SPD +9 | `resetList` | 279-285 |
| **A2** | SPD ≥ 160 → Elation +50% แล้ว +2% ต่อ SPD ที่เกิน (นับเกินได้ 100) | `statsAdjustList` เมื่อ SPD เปลี่ยน ใส่ส่วนต่างเทียบ `buffNote["SW999 A2"]` · `whenOnFieldList` ปลุกครั้งแรกด้วย `statsAdjust(ptr,SPD_P)` (แบบ Yao Guang A2) | 316-325, 298 |
| **A4** | ใช้ Elation Skill ตอนนับ Punchline ≥ 20 → MMR +20 · ≥ 40 → +40 | `a4` อ่าน global `punchline` (ตอน Aha Instant มันคือ PL ที่นับอยู่) · เรียกทั้งสอง Elation Skill | 59-62, 234, 244 |
| **A6** | เข้า Godmode → MMR +20 | `gainMMR(20)` ท้าย Ult | 222 |
| **E1** | ศัตรูใน Zone รับดาเมจ +20% · ออก Godmode เก็บ MMR ไว้ 20% | ใส่ VUL +20 ทุกตัวตอนเข้า ถอนตอนออก · `exitGodmode` เก็บ `MMR × 0.2` | 213, 159-161 |
| **E2** | เข้า Godmode → บัฟทุกตัวบนเธอยืด 1 เทิร์น · ทุก 120 MMR ที่เพิ่มในรอบ Godmode นั้น (นับ MMR ตั้งต้นด้วย) → extra turn + EBA เพิ่ม 1 ครั้ง | วน `ptr->buffEnd` ที่ยังไม่หมด +1 · `e2Gain` สะสมใน `buffNote["SW999 E2 MMR"]` ครบ 120 → `EBA Left +1` + `actionForward(100)` | 215-221, 40-48 |
| **E4** | Demo นับ Punchline เพิ่มอีก 5 เท่าของเดิม | ตั้ง global `punchline = เดิม × 6` ชั่วคราวตอนตี แล้วคืนค่า | 241 |
| **E6** | ดาเมจ Elation ระหว่าง EBA: Merrymake +50% · ศัตรูมีจุดอ่อนทุกธาตุ, RES พื้นฐาน → 0 (ถ้าเป็น 0 อยู่แล้ว −20%) | ใส่ `MERRYMAKE` +50 ตลอด EBA รวมกล่อง แล้วถอน · `whenOnFieldList` เปิด `weaknessType` ทุกธาตุ + `RESPEN` +20 ทุกตัว | 169-181, 287-297 |

## แปลงความสุ่มให้ได้ผลเดิมทุกครั้ง (determinism)

เกมจริงมีสุ่ม 2 จุด โค้ดแปลงเป็นกติกาตายตัวตามหลักของโปรเจกต์

- **โอกาสเปิดกล่องจาก Zone** — ทุก SP ที่ใช้ บวก "โอกาสปัจจุบัน" เข้าตัวสะสม `buffNote["SW999 Loot Acc"]` ถึง 100 เมื่อไหร่ = เปิด 1 กล่อง แล้วลบ 100 ออก และโอกาสถัดไปเหลือ ×0.2
  ผลที่ได้: SP แต้มแรกเปิดทันที → ต่อไปต้องใช้ 5 แต้ม → ต่อไป 25 แต้ม · Demo รีเซ็ตกลับ 100% (บรรทัด 245-246)
- **เอฟเฟกต์ของกล่อง** — เกมบอกแค่ว่า Kaboom ออกบ่อยขึ้นเมื่อ SP น้อย และ Bean ออกบ่อยขึ้นเมื่อ MMR น้อย แต่ไม่มีสูตร → โค้ดหมุนวน **Sword → Kaboom → Bean** ด้วย `buffNote["SW999 Loot Idx"]` (บรรทัด 70-72) · ทุกกล่องนับรวม ทั้งจาก Zone, EBA และ Technique

## จุดที่ตีความเอง / ตัดทิ้ง

- **toughness ของท่า bounce นับเป็นยอดรวมทั้งท่า** — EBA 10 → 0.1 ต่อ bounce, Demo 10 → 10/6 ต่อฮิต (ถ้านับต่อฮิต EBA จะได้ 1000 ซึ่งเป็นไปไม่ได้)
- **E4** อ่านว่า "นับเพิ่มอีก 5 เท่า" = รวมเป็น 6 เท่า ถ้าตั้งใจเป็น 5 เท่า แก้บรรทัด 241
- **E2 extra turn** = ดันแอคชัน 100% (ไม่ได้ใช้ `extraTurn` flag แบบ Phainon)
- **E6 RES** — engine ถือว่า RES ศัตรูเริ่มที่ 0 อยู่แล้ว จึงเหลือผลแค่ −20% ทุกธาตุ · ไม่ได้บวก `currentWeaknessElementAmount` (ตัวนับนี้ไม่ถูกรีเซ็ตต่อรอบรันอยู่แล้ว ดู Anaxa)
- **กล่องจาก EBA ไม่นับเป็นการโจมตี** — เรียก `box->actionFunction(box)` ตรง ๆ ไม่ผ่าน action bar จึงไม่ยิง Before/AfterAttackAction · ส่วนกล่องจาก Zone ผ่าน action bar ปกติ (kit เรียกว่า Special Attack)
- **ตัดทิ้ง**: ศัตรูตายหมดกลาง EBA แล้วได้ extra turn ตีต่อ (sim ศัตรูไม่ตาย) · กัน Crowd Control และ McAwolfee 999 (engine ไม่มีระบบ CC) · Light Cone ประจำตัวยังไม่ได้ทำ

## จุดที่ควรระวัง

- **ค่าของ EBA ถูก snapshot ตอนสร้างช่วงแรก** (`fillEbaSegment` ในบรรทัด 186 ถูกเรียกตอน `turnFunc`) แต่ช่วงที่ 2–4 สร้างตอนตีจริง → ถ้า MMR ขึ้นจาก Bean กลางท่า ช่วงหลังได้ตัวคูณใหม่ ส่วนช่วงแรกไม่ได้
- **เช็ค Certified Banger ด้วย `statsType[CERTIFIED_BANGER][NONE] > 0`** เหมือน Yao Guang — ถ้า engine เปลี่ยนวิธีเก็บ CB ต้องแก้ 4 จุด (96, 145, 169, 255)
- **VUL ของ E1 ใส่/ถอนแบบไม่มีชื่อ** — ถ้ารันจบกลาง Godmode ไม่ค้างเพราะ `basicReset` ล้าง stat ศัตรูทุกรอบ แต่ถ้ามีศัตรูเข้ามาใหม่กลาง Zone จะไม่ได้ VUL
- **ยังไม่ได้รัน sim** — ควรดู CR/CD และ Elation ที่ ATV 1000–5000 ว่าไม่ไหลลง (buff drift)
