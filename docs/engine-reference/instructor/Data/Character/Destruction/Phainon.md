# `src/Defination/Data/Character/Destruction/Phainon.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/phainon.md` · **ไฟล์ใหญ่ที่สุดในโปรเจกต์ (476 บรรทัด)** · เป็นที่เดียวที่ใช้ `UnitStatus::RETIRE` / `ATV_FREEZE` และที่เดียวที่มี `setupList` ตรวจรายชื่อเพื่อนร่วมทีม

## โครงใหญ่: สถานะอัลติที่ "ลบทีมออกจากสนาม"

Ult ของ Phainon ไม่ใช่ดาเมจ แต่เป็นการเข้าสู่สถานะพิเศษที่:
1. **แช่ตัวเอง** (`ATV_FREEZE`) และ **ลบเพื่อนทุกคนออกจากสนาม** (`RETIRE`) พร้อมจำสถานะเดิมไว้ใน `buffNote["PN Retire <ชื่อ>"]`
2. เปิด countdown unit `"Phainon Extra Turn"` ที่ทำหน้าที่เป็น **ตัวเดินเทิร์นพิเศษ 8 ครั้ง**
3. ทุกเทิร์นของ countdown เลือกท่าจาก 4 อย่าง แล้วลดตัวนับ
4. เทิร์นสุดท้าย `finalHit` คืนสถานะทุกคนกลับตามที่จำไว้

| `UnitStatus` | ความหมาย (`Enum/Enum.h:28`) |
|---|---|
| `ALIVE` | ปกติ |
| `ATV_FREEZE` | atv หยุดนิ่ง ไม่ได้เทิร์นจาก `findTurn` แต่ยังอยู่ในสนาม เป็นเป้าได้ |
| `RETIRE` | ถูกลบจากสนาม ไม่ targetable และ atv หยุดนิ่ง |

> **แก้ 2026-09-27** (รีวิวเทียบ kit): Talent CD +30% (`"PN Talent"`) และ A4 DMG +45% (`"PN A4"`) เดิม**ไม่มีโค้ดถอน → ติดถาวร** ตั้งแต่ครั้งแรก · ตอนนี้ถอนใน `afterTurnList` (+ A4 ใน `allyDeathList`) · A4 ไม่นับการฮีลตัวเองของ Khaslana · A2 ต้นเกม Coreflame 3 → 1 · Counter ของ Calamity `AType::FUA` → `AType::SKILL` (kit: นับเป็น Skill DMG) · Calamity เริ่ม Soulscorch 1 stack · HP ฐาน 1436 → 1433 · อัปเดตเลขบรรทัด · **ไม่แก้ตาม user**: Coreflame cap 15, E1 +1.5%/kill, Final Hit ลดตาม extra turn ที่เหลือ, ยืดบัฟเพื่อนตอนแปลงร่าง

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | บรรทัดใน `Phainon.h` |
|---|---|---|
| ธาตุ / path / **energy ult = 0** | `setCharBasicStats(94, 0, 0, E, PHYSICAL, DESTRUCTION, "Phainon", STANDARD)` | 5 |
| countdown unit | `setCountdownStats(ptr, baseSpeed*0.6*7, "Phainon Extra Turn")` | 10 |
| **Core Flame** (ทรัพยากรกด ult) | lambda `coreFlame(int)` — `buffNote["Core Flame"]` | 29-31 |
| **Scourge** (ทรัพยากรในสถานะอัลติ) | lambda `scourge(int)` — `buffNote["Scourge"]` | 33-35 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 41-52 |
| **Skill** | lambda `skill` — blast 300/120 + Core Flame +2 | 54-67 |
| **Creation** (ท่าในสถานะอัลติ) | lambda `creation` — blast 250/75 + Scourge +2 | 69-81 |
| **Calamity** | lambda `calamity` — ดัน action ศัตรูทุกตัว 1000 + ติด `Soulscorch` (เริ่ม 1 stack) + `dmgPercent -= 75` · Counter เป็น `AType::SKILL` (302-348) | 83-99 |
| **Foundation** | lambda `foundation` — ใช้ Scourge 4 + bounce 45 ×16 + 450% | 101-114 |
| **FinalHit** | lambda `finalHit` — AoE 960% แล้วคืนสถานะทุกคน | 116-161 |
| **Ultimate** — เข้าสถานะ | `ultimateList` — `coreFlame(-12)` + ATK/HP +80/+270 + แช่ทีม | 197-253 |
| **เงื่อนไขกด ult** | `addUltCondition` — Core Flame ≥ 12 และ countdown ยังไม่ทำงาน | 192-195 |
| **Talent** — ถูกบัฟ → Core Flame + CD | `buffList` (เฉพาะตอนไม่อยู่ในสถานะอัลติ) · CD +30% 3 เทิร์น ถอนใน `afterTurnList` | 369-384, 342-344 |
| Talent — ถูกตี → Core Flame | `enemyHitList` | 387-395 |
| **A4** — ถูกฮีล → DMG +45% 4 เทิร์น | `healingList` — **เฉพาะคนฮีลที่ไม่ใช่ Phainon เอง** · ถอนใน `afterTurnList` / `allyDeathList` | 397-402, 345-347 |
| **A6** — ATK +50% (2 ชั้น) | `buffStackSingle(..., 1, 2, "PN A6")` ที่ `startGameList` และ `finalHit` | 152, 278 |
| **Technique** | `startGameList` + `startWaveList` | 270-300 |
| **Minor traces** | `resetList` | 257-268 |
| **E1** — countdown เร็วขึ้น · CD +50% | `resetATV(baseSpeed*0.66*7)` · `buffSingle(CD +50, "PN E1", 3)` | 213-214, 244-248 |
| **E2** — Physical RESPEN +20 · Foundation ต่อเทิร์น | `resetList` · `afterAttackActionList` | 265, 362-366 |
| **E4** — Calamity เพิ่ม Soulscorch | `if (ptr->eidolon >= 4)` ใน `turnFunc` ของ countdown และ counter | 175, 323 |
| **E6** — Core Flame ต้นเกม + True DMG | `startGameList` · `afterDealingDamageList` + `calDamageNote` | 280-282, 418-423 |
| AI: เทิร์นปกติ | `turnFunc` — `sp > spSafety` → Skill ไม่งั้น BA | 167-172 |
| **AI: เทิร์นในสถานะอัลติ** | `countdownList[0]->turnFunc` — เลือก 1 ใน 4 ท่าตามตัวนับและ Scourge | 174-184 |

## รากฐาน: `UnitStatus` และการคืนสถานะ

```cpp
// ตอนเข้าสถานะ: จำสถานะเดิมของทุกคนไว้เป็นตัวเลข
if (each->isSameName(pn))              each->status = UnitStatus::ATV_FREEZE;
else if (each->status == ALIVE)      { setBuffNote("PN Retire " + ชื่อ, 1); each->status = RETIRE; }
else if (each->status == ATV_FREEZE)  { setBuffNote("PN Retire " + ชื่อ, 2); each->status = RETIRE; }

// ตอนออก: อ่านตัวเลขกลับมาแปลงเป็นสถานะเดิม
if (getBuffNote(...) == 1) each->status = ALIVE;
else if (getBuffNote(...) == 2) each->status = ATV_FREEZE;
setBuffNote(..., 0);
```
**เก็บ enum เป็นตัวเลขใน `buffNote` ซึ่งเป็น `double` map** — เป็นวิธีเดียวที่มีให้จำสถานะข้ามเวลาเพราะไม่มีช่องเก็บ struct · summon / countdown ของตัวละครอื่นถูกแช่เป็น `ATV_FREEZE` แยกต่างหาก (231-244) แล้วคืนใน `finalHit` (139-148)

## รากฐาน: countdown unit เป็น "ตัวเดินเทิร์นพิเศษ"

`pnCD` เป็น `TimerATV*` (ATV ล้วน ไม่มี stats/buff — `Class/Unit/ActionValueStats.h`) จึงส่งเข้า `actionForward` ได้ตรง ๆ และมี `status` / `summon()` / `death()` / `turnFunc` ของตัวเอง

ต่างจาก `../Remembrance/Aglaea.md` ที่ countdown เป็นแค่นาฬิกาจับเวลา — ของ Phainon **countdown คือตัวที่เล่นแทน** ในสถานะอัลติ

```cpp
pn->setBuffCountdown("PN Extra Turn", 8);       // จำนวนเทิร์นพิเศษ
pnCD->summon();  pnCD->resetATV(...);  actionForward(pnCD, 1000);
pnCD->extraTurn = 1;                 // ธงว่าเป็นเทิร์นพิเศษ
...
// turnFunc ของ countdown: เลือกท่า -> ลดตัวนับ -> resetTurn(turn)
pn->buffEnd["PN Extra Turn"] -= 1;
resetTurn(turn);
```
`buffEnd` ถูกใช้เป็น **ตัวนับรอบ** ไม่ใช่อายุบัฟ (เหมือน `Saber.h` ที่ทำกับ `"Saber E6"`) · `resetTurn(turn)` ปิดท้ายทุกเทิร์นเพื่อให้ engine เดินคิวต่อ

## รากฐาน: `setupList` — เงื่อนไขที่ขึ้นกับว่าใครอยู่ในทีม

```cpp
setupList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [pn](CharUnit *ptr) {
    CharUnit *sd = CharCmd::findAllyName("Sunday");
    ...
    if (sd) ptr->addUltCondition([...]{ return pn->getBuffCheck("Benison_of_Paper_and_Rites") && ...; });
}));
```
รันหลังประกอบทีมเสร็จ → `CharCmd::findAllyName(ชื่อ)` คืน `nullptr` ถ้าไม่มีคนนั้น · Phainon เพิ่มเงื่อนไข "รอบัฟจากซัพพอร์ตให้ครบก่อนค่อยกด ult" **ทีละคนตามที่มีจริงในทีม** (7 ตัว: Sunday, Tribbie, Robin, Bronya, RMC, Ruan_Mei, Tingyun)

**เป็นที่เดียวในโปรเจกต์ที่ตัวละครอ่านชื่อบัฟของตัวละครอื่นโดยตรง** → ชื่อบัฟของซัพพอร์ตกลายเป็น API ที่แก้ไม่ได้ ถ้าเปลี่ยนชื่อบัฟใน `Sunday.h` ต้องมาแก้ที่นี่ด้วย

## รากฐาน: `dmgPercent` บนศัตรู

`calamity` ลด `enemyUnit[i]->dmgPercent -= 75` แล้วคืน `+= 75` ตอน `Soulscorch` หมด (309-313) — ฟิลด์ตรงบนศัตรูเหมือน `atkPercent` ที่ `../../Relic/Gallagher` ใช้ (ดู `../Abundance/Gallagher.md`)

## จุดที่ควรระวัง

- **ความเร็ว countdown `baseSpeed * 0.6 * 7`** (10, 213-214) — **ตั้งใจ** (user อธิบาย 2026-09-27): Khaslana มี extra turn 8 ครั้งก่อนที่เทิร์นของ countdown ตัวจริงจะมาถึง · ครั้งแรกเกิดทันทีตอนแปลงร่าง จึงต้องเหลืออีก **7** ครั้งก่อน countdown มาถึง → คูณ 7 (E1 ใช้ `0.66 * 7`)

- **`addEnemyBounce(DmgSrc(ATK, 45, 10/3), 16)`** (109) — `10/3` เป็นการหารจำนวนเต็ม = `3` ไม่ใช่ `3.33` · ถ้าตั้งใจให้เป็นทศนิยมต้องเขียน `10.0/3` · อาการเดียวกับ `370/150*100` ใน `Saber.md`
- **`if(ty)` ใช้ lambda ที่ capture `rm` แทน `ty`** (460-465) — copy มาจากบล็อก Ruan_Mei แล้วลืมเปลี่ยน · ตัวแปรที่ capture ไม่ได้ถูกใช้ในบอดี้จึงไม่พัง แต่เป็นสัญญาณว่า copy-paste
- **`turnFunc` ของ countdown เช็ค `getBuffCountdown("PN Extra Turn") == 4`** เป็นเงื่อนไขกด Calamity (175) — ผูกกับเลขรอบตายตัว ถ้าเปลี่ยนจำนวนเทิร์นพิเศษจาก 8 ต้องมาแก้เลขนี้ด้วย
- **`buffList` ของ Talent เช็คชื่อ action ของตัวละครอื่น** (371-375): `"TY Ult"`, `"SD Ult"`, `"Crd Skill"` — ผูกกับชื่อ action ที่ตั้งในไฟล์อื่น · `Luka.h` เพิ่งเปลี่ยนชื่อ action ult จาก `"Luka BA"` เป็น `"Luka Ult"` ซึ่งเป็นความเสี่ยงประเภทเดียวกัน
- **`finalHit` ถอนบัฟ ATK/HP ด้วยค่าลบตายตัว** (144-147, 202-205) — ถ้ามีทางเข้าสถานะอัลติซ้ำโดยไม่ผ่าน `finalHit` ค่าจะรั่ว
- **`healingList` ของ A4 ไม่เช็คว่าใครฮีล** (392-396) → ได้ DMG +45% ทุกครั้งที่ Phainon ถูกฮีลจากแหล่งใดก็ได้
- **`afterAttackActionList` ฮีล 20% Max HP ทุก action ของตัวเองขณะอยู่ในสถานะอัลติ** (351-353) ไม่มี cap ต่อเทิร์น
- **substats ถูกคอมเมนต์ทิ้ง 2 บรรทัด** (16-17) เหลือแค่ `ATK_P`
