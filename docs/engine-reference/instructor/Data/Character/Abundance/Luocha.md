# `src/Defination/Data/Character/Abundance/Luocha.h`

kit อ้างอิง: `docs/kit-reference/Character/Abundance/luocha.md` · **ไฟล์อ้างอิงของสายฮีล (Abundance) ไฟล์แรกที่สำรวจ** — สิ่งที่ต่างจากตัวอื่นทั้งหมดคือ API การฮีล (`RestoreHP` / `HealSrc`) และการที่ผลของตัวละครไม่ได้อยู่ที่ดาเมจ

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(101, 100, 100, E, ElementType::Imaginary, Path::Abundance, "Luocha", UnitType::Standard)` | 12 |
| Base HP/ATK/DEF | `SetAllyBaseStats(1280, 756, 363)` | 13 |
| build — **main stat หมวกเป็น `HEALING_OUT`** | `setRelicMainStats(Stats::HEALING_OUT, FLAT_SPD, ATK_P, ER)` + `setSpeedRequire(150)` | 17-18 |
| **Basic ATK** — Thorns of the Abyss | `Luocha::Basic_Atk(ptr)` — `addDamageIns` 3 ครั้ง (30/3, 30/3, 40/4) = ตีเป้าเดียว 3 จังหวะ | 108-125 |
| **Skill** — Prayer of Abyss Flower (กดเอง) | **ไม่มี** — มีแต่ทาง auto ผ่าน `Talent()` | — |
| **Talent** (เอฟเฟกต์ Skill ที่ trigger เอง) | `Luocha::Talent(ptr)` — energy 30 + `++stack["Abyss_Flower"]` + `RestoreHP` 60% ATK + 800 + เรียก `Abyss_Flower()` | 93-99 |
| จังหวะ trigger Talent | ใน callback ของ BA: `if (ptr->Atv_stats->turnCnt % 2 == 1) Talent(ptr);` | 116-118 |
| **Talent** — ครบ 2 stack → กาง Field | `Luocha::Abyss_Flower(ptr)` — `if (stack >= 2)` → กิน 2 stack + `setBuffCheck` + `extendBuffTime(..., "Cycle_of_Life", 2)` | 100-112 |
| Field — ฮีลผู้โจมตีเมื่อตีศัตรู | `When_attack_List` → `if (ptr->getBuffCheck("Cycle_of_Life"))` → `ptr->RestoreHP(act->Attacker, ...)` | 78-87 |
| **A4** — เพื่อนที่เหลือฮีล 7% ATK + 93 | arg ที่ 3 ของ `RestoreHP(target, main, other)` | 83 |
| **Ultimate** — Death Wish | `Ultimate_List` (`PRIORITY_DEBUFF`) — AoE 200%×3 args + `++stack` + `Abyss_Flower()` | 33-47 |
| **Technique** — กาง Field ตั้งแต่ต้นเกม | `Start_game_List` → `stack["Abyss_Flower"] = 2` แล้วเรียก `Abyss_Flower()` | 71-76 |
| **Minor traces** | `Reset_List` | 49-57 |
| **E1** — Field active → ทีม ATK +20% | `buffAllAlly({{ATK_P, ..., 20}})` ใน `Abyss_Flower()` และ `-20` ตอนหมดใน `After_turn_List` | 63-65, 103-105 |
| **E2** — เป้าหมาย HP < 50% → Outgoing Healing +30% | `Talent()` — หาเป้าที่เสีย HP เยอะสุด แล้วครอบ `buffSingle(HEALING_OUT +30)` → `RestoreHP` → `-30` | 99-118 |
| **E6** — Ult → All-Type RES −20% 2 เทิร์น | `debuffAllEnemyApply(ptr, {{Stats::RESPEN, AType::None, 20}}, "Luocha E6", 2)` ใน callback ของ Ult + ถอนใน `After_turn_List` | 38-40, 68-71 |
| **A2 / A6 / E4** | **ไม่มี** | — |
| AI: เทิร์นนี้กดอะไร | `Turn_func` → `Basic_Atk(ptr)` เสมอ | 25-27 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` → `!getBuffCheck("Cycle_of_Life")` — **Field กางอยู่ = ยังไม่กด รอให้หมดก่อน** | 29-32 |
| Field หมดอายุ → ถอน E1 | `After_turn_List` → `isBuffEnd(Charptr, "Cycle_of_Life")` (stack ถูกกินตอนกางไปแล้ว) | 60-69 |

## รากฐานที่เพิ่ม: การฮีล

**1. `RestoreHP` มี 4 overload เลือกตามว่าใครได้ฮีล**
(`Class/Unit/AllyUnit.h:185-188`)
| รูปแบบ | ความหมาย |
|---|---|
| `RestoreHP(HealSrc)` | ฮีลตัวเอง |
| `RestoreHP(main, adjacent, other)` | แจกตาม `Target_type` แบบเดียวกับ `addDamageIns` 3 args |
| `RestoreHP(target, HealSrc)` | ฮีลเป้าที่ระบุคนเดียว |
| `RestoreHP(target, main, other)` | เป้าที่ระบุได้ `main` ที่เหลือได้ `other` — ตรงกับรูปของ Field + A4 พอดี (78-87) |

**2. `HealSrc` รวมหลายแหล่งในก้อนเดียว**
`HealSrc(HealSrcType::ATK, 18, HealSrcType::CONST, 240)` = 18% ATK **บวก** 240 คงที่ · `HealSrcType` มี `ATK` / `HP` / `DEF` / `TOTAL_HP` / `LOST_HP` / `CONST` (`Enum/Enum.h:99`) ซึ่งมากกว่าฝั่งดาเมจ (`DmgSrcType` มีแค่ 5) เพราะฮีลสเกลกับ HP ที่หายไปได้ · `HealSrc()` เปล่า ๆ = ไม่ฮีล ใช้เติมช่องที่ไม่ต้องการ (96)

**3. ฝ่ายพันธมิตรมี HP แต่ศัตรูไม่มี**
`RestoreHP` ทำงานได้เพราะ `AllyUnit` มี HP จริง ขณะที่ `Enemy` ไม่มี (ดู `README.md` หัวข้อ "ศัตรูไม่มี HP") · **ผลคือเงื่อนไขของ kit ที่อิง HP ของเพื่อน เขียนได้ในหลักการ แต่ไฟล์นี้ไม่ได้ใช้** — Talent ที่ kit บอกว่า trigger เมื่อเพื่อน HP ≤ 50% ถูกแทนด้วย "ทุก ๆ 2 เทิร์นของ Luocha" (116) ซึ่งเป็นการประมาณ cooldown 2 เทิร์นของ kit แทนการเช็ค HP จริง

**4. "Field" ไม่ใช่วัตถุใน engine — เป็นแค่ค่าของตัวนับ**
ไม่มี concept ของพื้นที่หรือ aura บนสนาม · Field active = `buffCheck["Cycle_of_Life"]` บนตัว Luocha ซึ่งถูกอ่านใน `When_attack_List` (79) และ `addUltCondition` (30) ส่วนอายุ 2 เทิร์นอยู่ที่ `buffEnd` ของชื่อเดียวกัน · **ตัวนับ stack กับสถานะ Field เป็นคนละเรื่อง**: stack คือทรัพยากรที่สะสมแล้วถูกกิน สถานะ Field คือผลที่ได้จากการกิน — เดิมโค้ดใช้ `stack >= 2` แทนสถานะ Field ซึ่งทำให้ทั้งสองอย่างพันกันจนพัง (ดูหัวข้อ "แก้เมื่อ")

**5. `addUltCondition` ใช้ gate ด้วยทรัพยากรได้ ไม่จำเป็นต้องเป็นเรื่องจังหวะ**
`return stack["Abyss_Flower"] < 2;` (30) — มี Field อยู่แล้วก็ยังไม่ต้องกด ult · ต่างจาก Tingyun/The Herta ที่ gate ด้วย action bar หรือ energy ของเพื่อน

## ส่วนที่ยังไม่มีในโค้ด

- **Skill แบบกดเอง** ไม่มี — และ **ไม่มี `genSkillPoint(-1)` ทั้งไฟล์** แปลว่า Luocha ในซิมนี้ปั่น skill point +1 ทุกเทิร์นโดยไม่เคยใช้ · ตรงกับวิธีเล่นจริงที่ Luocha เล่นแบบไม่กด Skill แต่ก็แปลว่าทางฮีลมีทางเดียวคือ Talent ที่ trigger เองทุก 2 เทิร์น
- **A2** (ลบ debuff 1 อันจากเป้าหมาย) — ไม่มีระบบ cleanse ในไฟล์นี้
- **A6** (+70% ต้านทาน CC) — ไม่มี
- **E4** (ศัตรูใน Field สร้าง DMG น้อยลง 12%) — **ไม่มีจุดให้เกาะ** engine ไม่ได้คำนวณดาเมจที่ศัตรูสร้างใส่ฝ่ายเรา · `Stats::Mitigration` ที่ชื่อใกล้เคียงเป็นการลดดาเมจ **ที่ฝ่ายเราตีออก** ไม่ใช่ที่รับเข้า (`CalStats.h:399`) · เขียนคอมเมนต์อธิบายไว้ในไฟล์แล้ว
- **Ult ไม่ได้ลบ buff ศัตรู** ตามที่ kit ระบุ (ไม่มีกลไก buff ฝั่งศัตรูให้ลบ)

## แก้เมื่อ 2026-09-23 (user สั่ง)

**ชื่อบัฟ Field สะกดไม่ตรงกัน** — ตั้งด้วย `"Cycle _of_Life"` (มีช่องว่าง, บรรทัด 102 เดิม) แต่เช็คหมดอายุด้วย `"Cycle_of_Life"` · `isBuffEnd` อ่าน `buffEnd["Cycle_of_Life"]` ที่ไม่เคยถูกเขียน (default 0) จึงไม่มีวันเป็นจริง → **Field ค้างถาวรตั้งแต่ครั้งแรกที่กางได้**, E1 ATK +20% ไม่เคยถูกถอน, และ `addUltCondition` ที่เป็น `stack < 2` กลายเป็นเท็จตลอด → **Luocha ไม่กด Ult อีกเลยหลังกาง Field ครั้งแรก**

แก้ชื่ออย่างเดียวไม่พอ เพราะโค้ดใช้ `stack >= 2` เป็นทั้ง "ทรัพยากรครบ" และ "Field กางอยู่" — พอ reset กลับมาทำงาน stack จะเดินต่อเป็น 3, 4 แล้ว `== 2` ก็ไม่จริงอีก จึงแยกสองความหมายออกจากกันทั้งชุด:

| จุด | เดิม | ใหม่ |
|---|---|---|
| `Abyss_Flower()` | `if (stack == 2)` ไม่กิน stack | `if (stack >= 2)` → `stack -= 2` ตาม kit |
| Field active | `stack["Abyss_Flower"] >= 2` | `getBuffCheck("Cycle_of_Life")` |
| ตั้งสถานะ Field | `extendBuffTime` อย่างเดียว | `setBuffCheck(..., 1)` + `extendBuffTime` |
| `addUltCondition` | `stack < 2` (ซึ่งหลังแยกความหมายแล้วจะเป็นจริงเกือบเสมอ = กดทุกครั้งที่ energy เต็ม) | `!getBuffCheck("Cycle_of_Life")` = **Field กางอยู่ไม่กด รอให้หมดก่อน** (user ยืนยัน 2026-09-23) |
| `After_turn_List` | ถอน E1 + `setStack(..., 0)` | ถอน E1 อย่างเดียว (stack ถูกกินตอนกางแล้ว) |
| E1 ตอนกาง Field | `buffAllAlly(+20)` ทุกครั้ง | เฉพาะตอน Field ยังไม่ active (`wasActive`) |

> **`extendBuffTime` ตั้งแค่ `buffEnd` ไม่ได้ตั้ง `buffCheck`** (`Function/Combat/Buff_Stats.h:39`) — ถ้าจะใช้ `getBuffCheck` เป็นตัวบอกสถานะต้อง `setBuffCheck` เองคู่กันเสมอ ส่วน `isBuffEnd` เป็นฝ่ายล้าง `buffCheck` ให้ตอนหมดอายุ
> **guard `wasActive` จำเป็น** เพราะตอนนี้ Field ถูกกางซ้ำระหว่างที่ยัง active ได้ (Luocha สะสมครบ 2 stack อีกรอบ) ถ้าไม่กัน `buffAllAlly(+20)` จะซ้อนแต่ถูกถอนครั้งเดียวตอนหมดอายุ → ค่ารั่วสะสม

**ผลต่อตัวเลข:** Luocha กลับมากด Ult ได้อีกครั้ง (เดิมหยุดกดถาวรหลังกาง Field ครั้งแรก) แต่ Field ไม่ค้างถาวรอีกแล้ว → ฮีลและ E1 ATK +20% หายไปช่วงที่ยังไม่ได้กาง **ทั้งสองทางกระทบตัวเลขทีม ควร build เทียบก่อน/หลัง**

> **จังหวะกด ult เป็นการตัดสินใจของ user ไม่ใช่ผลพลอยได้จากการแก้บั๊ก** — Luocha จะเก็บ ult ไว้จนกว่า Field จะหมดก่อน แลกกับการเสียดาเมจ AoE 200% ระหว่างที่ Field กางอยู่ 2 เทิร์น

## เพิ่มเมื่อ 2026-09-23 (user สั่ง): E2 / E4 / E6

**E6 — ลด All-Type RES ศัตรู 20%** (กระทบดาเมจทั้งทีม สำคัญที่สุดในสามตัวนี้)
`debuffAllEnemyApply(ptr, {{Stats::RESPEN, AType::None, 20}}, "Luocha E6", 2)` ใน callback ของ Ult + ถอนด้วย `isDebuffEnd` ใน `After_turn_List`
> **`Stats::RESPEN` ที่ `Stats_type` (ไม่ผูก element) = ลดทุกธาตุ** ส่วนที่ `Stats_each_element` คือเฉพาะธาตุนั้น — `calRespenMultiplier` (`CalStats.h:274`) บวกทั้งสองช่องเข้าด้วยกัน · ต่างจาก E1 ของ `Black Swan.h` ที่ไล่ใส่ทีละธาตุเพราะ kit ระบุแค่ 4 ธาตุ

**E2 — Outgoing Healing +30% เมื่อเป้าหมาย HP < 50%**
ใน `Talent()` หาเป้าที่เสีย HP เยอะสุดเอง (`calculateHPLost`) แล้วครอบการฮีลด้วย `buffSingle(HEALING_OUT +30)` → `RestoreHP` → `-30` — **สำนวนเดียวกับที่ `Black Swan.h` ใช้ทำ "เพิกเฉย DEF เฉพาะก้อนนี้"** ใช้ได้เพราะการฮีลคำนวณจบในบรรทัดเดียว
> เหตุผลที่ต้องหาเป้าเอง: `RestoreHP(main, adjacent, other)` เลือกผู้รับ `main` เป็น **คนที่เสีย HP เยอะสุด** ผ่าน priority queue ข้างใน (`Function/Combat/ChangeHP.h:3-41`) ตัวเรียกไม่ได้ส่งเป้าเข้าไป จึงต้องคำนวณซ้ำข้างนอกถ้าจะดูเงื่อนไขของเป้านั้น
> **สาขา HP ≥ 50% ของ kit (Shield 18% ATK + 240) ข้ามไป** — engine ไม่มีระบบ shield · `Stats::SHEILD` ที่มีใน enum เป็น *shield effectiveness %* (ใช้ที่ `Relic/Knight_of_Purity_Palace.h:8`) ไม่ใช่ตัวกาง shield และโค้ด shield ของ `Aventurine.h` ถูกคอมเมนต์ทิ้งทั้งหมด · **จดไว้ที่ `future-improvements.md` ข้อ 2 (ระบบสร้างโล่)** ว่า Luocha E2 รอระบบนี้อยู่

**E4 — ศัตรูสร้าง DMG น้อยลง 12% : ไม่ได้ implement**
engine ไม่ได้คำนวณดาเมจที่ศัตรูสร้างใส่ฝ่ายเรา จึงไม่มีจุดให้ผลนี้เกาะ · `Stats::Mitigration` ที่ชื่อใกล้เคียงรับ `act` เป็น `AllyAttackAction` (`CalStats.h:399`) คือลดดาเมจ **ที่ฝ่ายเราตีออก** — ใส่ไปจะกลายเป็นทำให้ทีมตัวเองตีเบาลง · เขียนคอมเมนต์อธิบายไว้เหนือ `Abyss_Flower()` ในไฟล์ และ **จดเป็น `future-improvements.md` ข้อ 9 (ไม่ได้จำลองดาเมจที่ศัตรูสร้างใส่ฝ่ายเรา)**

> **E2 และ E4 ไม่กระทบตัวเลขที่ซิมนี้วัด** (ดาเมจที่ทีมทำได้) เพราะเป็นเรื่องฮีลกับความอยู่รอด · ที่ทำ E2 เพราะราคาถูกและตัวเลขฮีลถูก track อยู่ (`healCount`, `printHpStats`) ส่วน E4 ไม่มีทางทำให้ถูกได้เลยในสภาพปัจจุบัน

## จุดที่ควรระวัง

- **E1 บัฟ/ถอนด้วย `buffAllAlly` แบบไม่มีชื่อบัฟ** (บรรทัด 64, 108) เป็นการบวก/ลบค่าดิบ ไม่มี `buffCheck` ของตัวเองกำกับ → ความถูกต้องขึ้นกับการจับคู่ครั้งกาง/ครั้งหมดให้สมดุล ซึ่งตอนนี้พึ่ง `wasActive` กับ `isBuffEnd` · ถ้าเพิ่มทางกาง Field ใหม่เมื่อไหร่ ต้องดูจุดนี้ด้วย
- **`Talent()` ไม่ได้เช็คว่า Field กางอยู่หรือยัง** — ทุก ๆ 2 เทิร์นจะ `++stack` เสมอ ซึ่งตอนนี้ถูกต้องแล้ว เพราะ stack เป็นทรัพยากรที่สะสมข้าม Field ได้
