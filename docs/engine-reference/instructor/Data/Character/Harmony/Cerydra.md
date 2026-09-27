# `src/Defination/Data/Character/Harmony/Cerydra.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/cerydra.md` · **ไฟล์อ้างอิงของ `beforeAllyActionList` และการ copy action ทั้งก้อนเพื่อยิงซ้ำ**

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(99, 130, 130, E, WIND, HARMONY, "Cerydra", STANDARD)` | 5 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 28-40 |
| **Skill** — Veci: SPD +20 flat ทั้งคู่ | lambda `skill` — `buffSingle` ให้ตัวเองและเป้าหมาย | 42-61 |
| **Ultimate** | `ultimateList` — AoE 240%×3 + charge +2 + ล้าง Talent limit | 78-95 |
| **charge** (ทรัพยากรแกน) | lambda `charge(int)` → `addStack("Cerydra charge", value)` | 22-24 |
| charge จาก action ของเป้าที่บัฟ | `beforeAllyActionList` — เป้าใช้ Skill/BA → energy +5 และ charge +1 | 176-182 |
| **Peerage** — charge ครบ 6 → บัฟ Skill ของเป้า | `afterAttackActionList` → `DMG[SKILL] +72`, `RESPEN[SKILL] +10` | 203-217 |
| **Coup de Main** — ยิง Skill ของเป้าซ้ำ 1 ครั้ง | `make_shared<AllyAttackAction>(*act)` แล้ว `addToActionBar()` | 186-190 |
| **Talent** — Additional DMG เมื่อเป้าโจมตี (cap 20 ครั้ง) | `whenAttackList` → `AType::ADDTIONAL` 60% | 219-229 |
| **A2** — ทีม FLAT_ATK = 24% ของ ATK Cerydra | `startGameList` + `statsAdjustList` | 138-147, 231-250 |
| **A4** — CD ตาม ATK ที่เกิน 2000 (cap 20 ขั้น ×18) | สูตร `temp2` ในสองที่เดียวกัน | 148-154 |
| **Technique** | `startGameList` — ทำ Skill ทันที + `act->turnReset = 0` | 156-174 |
| **Minor traces** | `resetList` (มี `CR += 100` และ charge เริ่มต้น 2) | 97-104 |
| **E1** — เป้าได้ energy · DEF_SHRED | `increaseEnergy(chooseAllyBuff(crd), 2)` · `whenOnFieldList` | 55-57, 107-111 |
| **E2** — DMG ให้เป้า +40 / ตัวเอง +140 | `whenOnFieldList` | 112-119 |
| **E4** — Ult ดาเมจ ×2 | `if (ptr->eidolon >= 4) act->multiplyDmg(200)` | 92 |
| **E6** — RESPEN ทั้งคู่ · Additional DMG ×6 | `whenOnFieldList` · `newAct->multiplyDmg(600)` | 120-127, 226 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — `sp > spSafety + 1` → Skill ไม่งั้น BA | 64-67 |

## รากฐาน: `beforeAllyActionList` — trigger จาก action ทุกชนิดของฝ่ายเรา

```cpp
beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,
    [](shared_ptr<AllyActionData> &act){ ... }));
```
รับ `AllyActionData` (คลาสแม่ของ attack และ buff action) → **เป็นตัวเดียวที่เห็นทั้ง Skill ที่เป็นดาเมจและ Skill ที่เป็นบัฟ** · ต่างจาก `beforeActionList` / `afterActionList` ของ `../Remembrance/Hyacine.md` ที่เห็น action ของศัตรูด้วย

Cerydra ใช้จับว่า "เป้าที่บัฟใช้ Skill หรือ BA" เพื่อเก็บ charge — ถ้าใช้ `whenAttackList` จะพลาด Skill ที่เป็นบัฟล้วน

## รากฐาน: copy action เพื่อยิงซ้ำ

```cpp
shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(*act);
newAct->addToActionBar();
```
**Coup de Main ของ kit คือ "ทำซ้ำ Skill ของเป้าหมาย"** — โค้ดใช้ copy constructor คัดลอก action ทั้งก้อนแล้วโยนเข้าคิวใหม่ · เป็นที่เดียวในโปรเจกต์ที่ทำแบบนี้

> **ข้อควรระวัง**: action ที่ copy มามี callback เดิมติดมาด้วย → ผลข้างเคียงทั้งหมดของ Skill ต้นฉบับ (ได้ energy, ลง debuff, กิน SP) จะเกิดซ้ำด้วย ซึ่งอาจไม่ตรงกับ kit ที่ให้ซ้ำเฉพาะดาเมจ

## รากฐาน: บัฟที่ผูกกับ `AType` ของท่าเฉพาะ

Peerage ลง `Stats::DMG` และ `Stats::RESPEN` ที่ **`AType::SKILL`** (208-216) → เข้าเฉพาะ action ที่สร้างด้วย `AType::SKILL` · เป็นเหตุผลที่ตัวละครต้องตั้ง `AType` ให้ถูก (ดูการแก้ใน `../Nihility/Luka.md` และ `../Nihility/Black Swan.md`)

## รากฐาน: สูตรขั้นบันไดจาก ATK

```cpp
double temp2 = min(max(0.0, floor((calculateAtkForBuff(crd,100) - 2000)/100)), 20.0) * 18;
```
A4: ทุก 100 ATK ที่เกิน 2000 → CD +18 สูงสุด 20 ขั้น · `min`/`max`/`floor` ซ้อนกันเป็นสำนวนมาตรฐานของสูตรขั้นบันได (เทียบ `../Destruction/Mydei.md` A6 และ `../Erudition/Rappa.md` Withered Leaf)

## จุดที่ควรระวัง

- **`statsAdjustList` ใช้ `temp` (ค่า FLAT_ATK ที่แจกไป) แทน ATK รวม ในสูตร A4** (245): `floor((temp - 2000)/100)` ขณะที่ `startGameList` ใช้ `floor((calculateAtkForBuff(crd,100) - 2000)/100)` (148) — **สองที่คำนวณคนละอย่าง** · `temp` คือ 24% ของ ATK ส่วน `calculateAtkForBuff(crd,100)` คือ ATK เต็ม → A4 จะเพี้ยนทันทีที่ ATK เปลี่ยนระหว่างเกม
- **`resetList` ใส่ `CR += 100`** (102) ไม่มีคอมเมนต์ — เหมือน `../Remembrance/Hyacine.md`
- **`act->addBuffSingleTarget()` เรียกโดยไม่ส่งเป้าหมาย** (59) ต่างจากทุกที่ที่ส่ง `chooseAllyBuff(ptr)` — ต้องดู default ของ overload นี้
- **Technique copy โค้ด Skill ทั้งก้อน** (157-171) — อาการเดียวกับ `Ruan_Mei.md`, `../Elation/YaoGuang.md`
- **`afterAttackActionList` เรียก `chooseAllyBuff(crd)` สด 6 ครั้ง** (183-217) ทั้งตอนลงและตอนถอน Peerage → **ถ้าเป้าหมายเปลี่ยนระหว่างนั้น บัฟจะถูกถอนผิดคน** · ควรใช้ `buffAllyTarget` แบบ `Sunday.md` หรือ `buffSubUnitTarget` แบบ `Tingyun.md`
- **`turnFunc` ทางเลือกถูกคอมเมนต์ทิ้ง** (69-72) และ `setSpeedRequire` ถูกคอมเมนต์ (11)
- **`whenAttackList` ของ Talent เช็ค `crd->getStack("Cerydra Talent Limit") < 20`** แต่ล้างเฉพาะตอน Ult (85) → ถ้าไม่ได้กด ult นาน ๆ Talent จะหยุดทำงานถาวร
