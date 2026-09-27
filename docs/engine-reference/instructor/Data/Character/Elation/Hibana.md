# `src/Defination/Data/Character/Elation/Hibana.h`

kit อ้างอิง: `docs/kit-reference/Character/Elation/sparxie.md` · **ตัวจริงในเกมชื่อ Sparxie** (ดู `docs/kit-reference/Character/README.md` ตาราง codename) · **ไฟล์อ้างอิงหลักของ path Elation**

## ระบบ Elation — คำศัพท์

| ของ | เก็บที่ / ตัวแปร | ใช้ทำอะไร |
|---|---|---|
| **Punchline** | global `punchline` · เพิ่มด้วย `genPunchLine(ptr, n)` | ทรัพยากรกลางของ path Elation |
| **`Stats::ELATION`** | stat บนตัวละคร | ตัวคูณของดาเมจชนิด Elation |
| **`DmgSrcType::ELATION`** | ประเภทแหล่งดาเมจ | ดาเมจที่สเกลกับ `Stats::ELATION` แทน ATK/HP/DEF |
| **`AType::ELATION_DMG` / `AType::ELATION_SKILL`** | ประเภท action | แยกดาเมจ Elation ออกจากดาเมจปกติ |
| **Aha Instant** | `act->addToAhaInstant()` · `afterAhaInstantList` | action พิเศษที่แทรกนอกลำดับเทิร์นปกติ |
| **`elationCount`** | global | จำนวนตัวละคร Elation ในทีม (นับตอน `setup`) |

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(107, 160, 160, E, FIRE, ELATION, "Hibana", STANDARD)` | 5 |
| build — **เกณฑ์ ATK ไม่ใช่ SPD** | `setAtkRequire(3600)` · main stat 3 ช่องเป็น `ATK_P` | 13-14 |
| นับตัวเองเข้าจำนวน Elation ในทีม | `elationCount++` | 16 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 25-37 |
| **Enhanced BA** — เผา SP ทั้งหมด | lambda `EBA` — `while(sp)` กิน SP/Thrill ทุกแต้ม แล้วคูณดาเมจตามจำนวนที่กิน | 39-79 |
| **Ultimate** | `ultimateList` — AoE ที่ multiplier คำนวณจาก `Stats::ELATION` | 91-127 |
| Ult — punchline ตามจำนวน Elation ในทีม | `if (elationCount == 1) genPunchLine(ptr, 4)` … `else { genPunchLine(ptr, 10); addStack("Hbn Thrill", 3); }` | 98-103 |
| **Elation Skill** | `elationSkillList` — AoE 50 ×3 + bounce 25 ×20 + `addToAhaInstant()` | 129-148 |
| **Talent / Punchline buff ทีม** | `punchLineList` → CD ทีม = `min(10, punchline) * 8` | 172-185 |
| **Minor traces** | `resetList` (มี `ELATION += 80` เพิ่มจาก 28) | 150-159 |
| **E1** — RESPEN ทีมตาม punchline + punchline หลัง Aha | `punchLineList` ท่อนหลัง · `afterAhaInstantList` | 179-184, 189 |
| **E2** — กิน Thrill → CD stack · Aha แล้วได้ action เพิ่ม | `buffStackSingle(..., 1, 4, "Hbn E2", 2)` · `afterAhaInstantList` | 47-49, 191-195 |
| **E4** — Ult ให้ punchline + Elation +36 | `if (ptr->eidolon >= 4)` ใน Ult | 104-107 |
| **E6** — RESPEN +20 · bounce เพิ่มตาม punchline | `resetList` · `addEnemyBounce(..., min(punchline, 40))` | 146, 157 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — `sp + Thrill >= 3` → EBA ไม่งั้น BA | 82-85 |

## รากฐาน: ดาเมจ Elation เป็น action แยกก้อน

ทุกท่าที่มีดาเมจ Elation จะสร้าง **action ที่สองต่างหาก** ไม่ใช่เพิ่มก้อนดาเมจเข้า action เดิม:

```cpp
attack(act);                                                    // ดาเมจ ATK ปกติ
shared_ptr<AllyAttackAction> elDmg =
    make_shared<AllyAttackAction>(AType::ELATION_DMG, ptr, TraceType::BLAST, "...");
elDmg->addDamageIns(DmgSrc(DmgSrcType::ELATION, 40), DmgSrc(DmgSrcType::ELATION, 20));
elDmg->addEnemyBounce(DmgSrc(DmgSrcType::ELATION, 20), skillCharge);
attack(elDmg);
```
เพราะสเกลกับคนละ stat (`Stats::ELATION` ไม่ใช่ ATK) และต้องแยกประเภทให้บัฟที่เจาะจง `AType::ELATION_DMG` เข้าได้ (เช่น `../../Relic/Ever-Glorious Magical Girl.md`)

## รากฐาน: `while(sp)` — ท่าที่กินทรัพยากรจนหมด

```cpp
int skillCharge = 0;
while (sp) {
    if (ptr->getStack("Hbn Thrill")) { addStack("Hbn Thrill", -1); allEventSkillPoint(ptr, -1); }
    else                              genSkillPoint(ptr, -1);
    skillCharge++;
    addStack("Hibana Skill Count", 1);
    if (stack["Hibana Skill Count"] % 6 == 3) { genSkillPoint(ptr, 2); genPunchLine(ptr, 2); }
    else                                        genPunchLine(ptr, 1);
}
act->multiplyDmg(100 + 20 * skillCharge);
```
- **`sp` เป็น global ของทีม** — EBA กิน SP ทั้งกระดานในครั้งเดียว
- **`Hbn Thrill` เป็น SP เสมือน** ใช้ก่อน SP จริง · เวลาใช้ Thrill เรียก `allEventSkillPoint(ptr, -1)` (ยิง event อย่างเดียว) ไม่ใช่ `genSkillPoint(ptr, -1)` (ที่จะไปหัก `sp` จริง) — **ความต่างนี้สำคัญ** ถ้าใช้ผิดตัว SP จะติดลบ
- `multiplyDmg(100 + 20 * n)` คูณเป็นเปอร์เซ็นต์หลังประกอบ action แล้ว

## รากฐาน: Aha Instant

`act->addToAhaInstant()` แทน `addToActionBar()` → action นั้นเข้าคิวพิเศษที่แทรกนอกลำดับเทิร์นปกติ · เมื่อทำงานจบจะยิง **`afterAhaInstantList`** ซึ่ง E2 ของ Hibana ใช้สั่งให้ตัวเองทำ BA/EBA ต่อทันที (191-195) พร้อม `dealDamage()` เอง

> `note/Note.txt` มีรายการ "แก้ Aha instant เป็น unit" ค้างอยู่ — ระบบนี้ยังไม่นิ่ง

## รากฐาน: multiplier ที่คำนวณจาก stat ตอนสร้าง action

```cpp
double mtpr = 0.6 * calculateElationOnStats(ptr) + 50;
act->addDamageIns(DmgSrc(DmgSrcType::ATK, mtpr, 20), ...);
```
ต่างจาก `The_Herta.h` ที่ต้องคำนวณ **ใน callback** เพราะค่าขึ้นกับ stack ที่เปลี่ยนระหว่างรอคิว — ของ Hibana ขึ้นกับ stat ตัวเองซึ่งไม่เปลี่ยนระหว่างนั้น จึงคำนวณตอนประกอบ action ได้

## จุดที่ควรระวัง

- **`elationSkillList` ใช้ตัวเลข priority ดิบ `144`** (129) แทนค่าคงที่ `PRIORITY_*` — ไม่มีที่อื่นในโปรเจกต์ทำแบบนี้ ถ้าลำดับ priority ถูกปรับ ค่านี้จะเพี้ยนโดยไม่มีใครรู้
- **`resetList` บวก `Stats::ELATION` สองครั้ง** (151 กับ 155) — 28 จาก minor traces แล้ว +80 อีกก้อนที่ไม่มีคอมเมนต์อธิบายว่ามาจากไหน
- **`afterTurnList` ถอน `Hbn E2` ด้วย `buffCharResetStack`** (163) ขณะที่ลงด้วย `buffStackSingle` (48) — คนละตระกูล (`...charSetup` ลงถึง memosprite ด้วย) · Hibana ไม่มี memosprite จึงยังไม่เห็นอาการ
- **`setSpeedRequire` ถูกคอมเมนต์ทิ้ง** (12)
- **`while(sp)` ไม่มีตัวกันวนไม่จบ** ถ้ามี trigger ไหนคืน SP ระหว่างลูป (`% 6 == 3` คืน SP 2 แต้มอยู่แล้ว!) — ตอนนี้รอดเพราะ `genSkillPoint(ptr, 2)` เกิดหลังจากหักไปแล้วและลูปจะกินต่อจนหมดจริง แต่เป็นจุดที่เปราะ
- **`printUltStart` ถูกเรียกนอก callback** (92) ต่างจากตัวอื่นที่เรียกข้างใน → ข้อความขึ้นตอนสั่ง ไม่ใช่ตอนถึงคิว
