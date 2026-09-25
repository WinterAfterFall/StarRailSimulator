# `src/Defination/Data/Character/Destruction/Phainon.h`

kit อ้างอิง: `docs/kit-reference/Character/Phainon.md` · **ไฟล์ใหญ่ที่สุดในโปรเจกต์ (476 บรรทัด)** · เป็นที่เดียวที่ใช้ `UnitStatus::Retire` / `AtvFreeze` และที่เดียวที่มี `Setup_List` ตรวจรายชื่อเพื่อนร่วมทีม

## โครงใหญ่: สถานะอัลติที่ "ลบทีมออกจากสนาม"

Ult ของ Phainon ไม่ใช่ดาเมจ แต่เป็นการเข้าสู่สถานะพิเศษที่:
1. **แช่ตัวเอง** (`AtvFreeze`) และ **ลบเพื่อนทุกคนออกจากสนาม** (`Retire`) พร้อมจำสถานะเดิมไว้ใน `buffNote["PN Retire <ชื่อ>"]`
2. เปิด countdown unit `"Phainon Extra Turn"` ที่ทำหน้าที่เป็น **ตัวเดินเทิร์นพิเศษ 8 ครั้ง**
3. ทุกเทิร์นของ countdown เลือกท่าจาก 4 อย่าง แล้วลดตัวนับ
4. เทิร์นสุดท้าย `FinalHit` คืนสถานะทุกคนกลับตามที่จำไว้

| `UnitStatus` | ความหมาย (`Enum/Enum.h:28`) |
|---|---|
| `Alive` | ปกติ |
| `AtvFreeze` | atv หยุดนิ่ง ไม่ได้เทิร์นจาก `Find_turn` แต่ยังอยู่ในสนาม เป็นเป้าได้ |
| `Retire` | ถูกลบจากสนาม ไม่ targetable และ atv หยุดนิ่ง |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / **energy ult = 0** | `SetCharBasicStats(94, 0, 0, E, Physical, Destruction, "Phainon", Standard)` | 5 |
| countdown unit | `SetCountdownStats(ptr, baseSpeed*0.6*7, "Phainon Extra Turn")` | 10 |
| **Core Flame** (ทรัพยากรกด ult) | lambda `CoreFlame(int)` — `buffNote["Core Flame"]` | 29-31 |
| **Scourge** (ทรัพยากรในสถานะอัลติ) | lambda `Scourge(int)` — `buffNote["Scourge"]` | 33-35 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 39-51 |
| **Skill** | lambda `Skill` — blast 300/120 + Core Flame +2 | 53-66 |
| **Creation** (ท่าในสถานะอัลติ) | lambda `Creation` — blast 250/75 + Scourge +2 | 68-80 |
| **Calamity** | lambda `Calamity` — ดัน action ศัตรูทุกตัว 1000 + ติด `Soulscorch` + `dmgPercent -= 75` | 82-97 |
| **Foundation** | lambda `Foundation` — ใช้ Scourge 4 + bounce 45 ×16 + 450% | 99-112 |
| **FinalHit** | lambda `FinalHit` — AoE 960% แล้วคืนสถานะทุกคน | 114-160 |
| **Ultimate** — เข้าสถานะ | `Ultimate_List` — `CoreFlame(-12)` + ATK/HP +80/+270 + แช่ทีม | 195-250 |
| **เงื่อนไขกด ult** | `addUltCondition` — Core Flame ≥ 12 และ countdown ยังไม่ทำงาน | 189-192 |
| **Talent** — ถูกบัฟ → Core Flame + CD | `Buff_List` (เฉพาะตอนไม่อยู่ในสถานะอัลติ) | 361-378 |
| Talent — ถูกตี → Core Flame | `Enemy_hit_List` | 381-390 |
| **A4** — ถูกฮีล → DMG +45% 4 เทิร์น | `Healing_List` | 392-396 |
| **A6** — ATK +50% (2 ชั้น) | `buffStackSingle(..., 1, 2, "PN A6")` ที่ `Start_game_List` และ `FinalHit` | 151, 274 |
| **Technique** | `Start_game_List` + `Start_wave_List` | 267-300 |
| **Minor traces** | `Reset_List` | 254-265 |
| **E1** — countdown เร็วขึ้น · CD +50% | `resetATV(baseSpeed*0.66*7)` · `buffSingle(CD +50, "PN E1", 3)` | 213-214, 245-249 |
| **E2** — Physical RESPEN +20 · Foundation ต่อเทิร์น | `Reset_List` · `AfterAttackActionList` | 262, 355-358 |
| **E4** — Calamity เพิ่ม Soulscorch | `if (ptr->Eidolon >= 4)` ใน `Turn_func` ของ countdown และ counter | 175, 321 |
| **E6** — Core Flame ต้นเกม + True DMG | `Start_game_List` · `AfterDealingDamage_List` + `Cal_DamageNote` | 276-278, 407-413 |
| AI: เทิร์นปกติ | `Turn_func` — `sp > Sp_Safety` → Skill ไม่งั้น BA | 166-172 |
| **AI: เทิร์นในสถานะอัลติ** | `countdownList[0]->Turn_func` — เลือก 1 ใน 4 ท่าตามตัวนับและ Scourge | 174-185 |

## รากฐาน: `UnitStatus` และการคืนสถานะ

```cpp
// ตอนเข้าสถานะ: จำสถานะเดิมของทุกคนไว้เป็นตัวเลข
if (each->isSameName(pn))              each->status = UnitStatus::AtvFreeze;
else if (each->status == Alive)      { setBuffNote("PN Retire " + ชื่อ, 1); each->status = Retire; }
else if (each->status == AtvFreeze)  { setBuffNote("PN Retire " + ชื่อ, 2); each->status = Retire; }

// ตอนออก: อ่านตัวเลขกลับมาแปลงเป็นสถานะเดิม
if (getBuffNote(...) == 1) each->status = Alive;
else if (getBuffNote(...) == 2) each->status = AtvFreeze;
setBuffNote(..., 0);
```
**เก็บ enum เป็นตัวเลขใน `buffNote` ซึ่งเป็น `double` map** — เป็นวิธีเดียวที่มีให้จำสถานะข้ามเวลาเพราะไม่มีช่องเก็บ struct · summon / countdown ของตัวละครอื่นถูกแช่เป็น `AtvFreeze` แยกต่างหาก (231-244) แล้วคืนใน `FinalHit` (139-148)

## รากฐาน: countdown unit เป็น "ตัวเดินเทิร์นพิเศษ"

ต่างจาก `../Remembrance/Aglaea.md` ที่ countdown เป็นแค่นาฬิกาจับเวลา — ของ Phainon **countdown คือตัวที่เล่นแทน** ในสถานะอัลติ

```cpp
pn->setBuffCountdown("PN Extra Turn", 8);       // จำนวนเทิร์นพิเศษ
pnCD->summon();  pnCD->resetATV(...);  Action_forward(pnCD->Atv_stats.get(), 1000);
pnCD->Atv_stats->extraTurn = 1;                 // ธงว่าเป็นเทิร์นพิเศษ
...
// Turn_func ของ countdown: เลือกท่า -> ลดตัวนับ -> resetTurn(turn)
pn->buffEnd["PN Extra Turn"] -= 1;
resetTurn(turn);
```
`buffEnd` ถูกใช้เป็น **ตัวนับรอบ** ไม่ใช่อายุบัฟ (เหมือน `Saber.h` ที่ทำกับ `"Saber E6"`) · `resetTurn(turn)` ปิดท้ายทุกเทิร์นเพื่อให้ engine เดินคิวต่อ

## รากฐาน: `Setup_List` — เงื่อนไขที่ขึ้นกับว่าใครอยู่ในทีม

```cpp
Setup_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn]() {
    CharUnit *sd = CharCmd::findAllyName("Sunday");
    ...
    if (sd) ptr->addUltCondition([...]{ return pn->getBuffCheck("Benison_of_Paper_and_Rites") && ...; });
}));
```
รันหลังประกอบทีมเสร็จ → `CharCmd::findAllyName(ชื่อ)` คืน `nullptr` ถ้าไม่มีคนนั้น · Phainon เพิ่มเงื่อนไข "รอบัฟจากซัพพอร์ตให้ครบก่อนค่อยกด ult" **ทีละคนตามที่มีจริงในทีม** (7 ตัว: Sunday, Tribbie, Robin, Bronya, RMC, Ruan_Mei, Tingyun)

**เป็นที่เดียวในโปรเจกต์ที่ตัวละครอ่านชื่อบัฟของตัวละครอื่นโดยตรง** → ชื่อบัฟของซัพพอร์ตกลายเป็น API ที่แก้ไม่ได้ ถ้าเปลี่ยนชื่อบัฟใน `Sunday.h` ต้องมาแก้ที่นี่ด้วย

## รากฐาน: `dmgPercent` บนศัตรู

`Calamity` ลด `enemyUnit[i]->dmgPercent -= 75` แล้วคืน `+= 75` ตอน `Soulscorch` หมด (309-313) — ฟิลด์ตรงบนศัตรูเหมือน `atkPercent` ที่ `../../Relic/Gallagher` ใช้ (ดู `../Abundance/Gallagher.md`)

## จุดที่ควรระวัง

- **`addEnemyBounce(DmgSrc(ATK, 45, 10/3), 16)`** (109) — `10/3` เป็นการหารจำนวนเต็ม = `3` ไม่ใช่ `3.33` · ถ้าตั้งใจให้เป็นทศนิยมต้องเขียน `10.0/3` · อาการเดียวกับ `370/150*100` ใน `Saber.md`
- **`if(ty)` ใช้ lambda ที่ capture `rm` แทน `ty`** (460-465) — copy มาจากบล็อก Ruan_Mei แล้วลืมเปลี่ยน · ตัวแปรที่ capture ไม่ได้ถูกใช้ในบอดี้จึงไม่พัง แต่เป็นสัญญาณว่า copy-paste
- **`Turn_func` ของ countdown เช็ค `getBuffCountdown("PN Extra Turn") == 4`** เป็นเงื่อนไขกด Calamity (175) — ผูกกับเลขรอบตายตัว ถ้าเปลี่ยนจำนวนเทิร์นพิเศษจาก 8 ต้องมาแก้เลขนี้ด้วย
- **`Buff_List` ของ Talent เช็คชื่อ action ของตัวละครอื่น** (371-375): `"TY Ult"`, `"SD Ult"`, `"Crd Skill"` — ผูกกับชื่อ action ที่ตั้งในไฟล์อื่น · `Luka.h` เพิ่งเปลี่ยนชื่อ action ult จาก `"Luka BA"` เป็น `"Luka Ult"` ซึ่งเป็นความเสี่ยงประเภทเดียวกัน
- **`FinalHit` ถอนบัฟ ATK/HP ด้วยค่าลบตายตัว** (144-147, 202-205) — ถ้ามีทางเข้าสถานะอัลติซ้ำโดยไม่ผ่าน `FinalHit` ค่าจะรั่ว
- **`Healing_List` ของ A4 ไม่เช็คว่าใครฮีล** (392-396) → ได้ DMG +45% ทุกครั้งที่ Phainon ถูกฮีลจากแหล่งใดก็ได้
- **`AfterAttackActionList` ฮีล 20% Max HP ทุก action ของตัวเองขณะอยู่ในสถานะอัลติ** (351-353) ไม่มี cap ต่อเทิร์น
- **substats ถูกคอมเมนต์ทิ้ง 2 บรรทัด** (16-17) เหลือแค่ `ATK_P`
