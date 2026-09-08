# 09 — Glossary (ศัพท์ระบบทั่วไป)

ศัพท์ที่เจอบ่อยแต่ไม่เข้าหมวด Element/Path/Stats/AType

---

## A. ระบบการต่อสู้พื้นฐาน

| ศัพท์ | ย่อ | ความหมาย |
|---|---|---|
| **Skill Point** | SP | แต้มกลางของทีม เพดาน 5 (ขยายได้ด้วย Light Cone บางใบ) — Basic ATK +1, Skill −1 |
| **Energy** | EP | พลังงานส่วนตัวของแต่ละตัว เต็มแล้วใช้ Ultimate ได้ |
| **Max Energy** | — | เพดาน Energy ของตัวละครนั้น (มักเป็น 100/110/120/130/140/180) |
| **Energy Regeneration Rate** | ERR | ตัวคูณพลังงานที่ได้รับ (ฐาน 100%) |
| **Turn** | — | ตาของยูนิตหนึ่งตัว |
| **Cycle** | — | หน่วยเวลาของ endgame — 1 Cycle = 100 AV (Cycle แรก = 150 AV) |
| **Wave** | — | คลื่นศัตรู — จบเวฟหนึ่งแล้วขึ้นเวฟถัดไปในการต่อสู้เดียวกัน |
| **Ultimate** | Ult | ท่าไม้ตาย — **ใช้แทรกได้ทันทีโดยไม่กิน AV** (interrupt) |
| **Technique** | — | ท่าที่กดก่อนเข้าสู้ในโลกสำรวจ ใช้ Technique Point |

---

## B. ระบบ AV / ลำดับเทิร์น

> 🏃 **เปรียบเทียบง่ายๆ**: คิดว่าเป็นการวิ่งแข่งระยะ **10,000 เมตร**
> ทุกตัวเริ่มที่เส้นสตาร์ทเหมือนกัน SPD = ความเร็วในการวิ่ง
> ใครถึงเส้นชัยก่อนได้เทิร์นก่อน แล้วถูกส่งกลับไปเริ่มวิ่งใหม่

| ศัพท์ | ความหมาย |
|---|---|
| **Action Value (AV)** | "ระยะทางที่เหลือ" ก่อนได้เทิร์น — `AV = 10000 / SPD` |
| **ATV** | ชื่อที่ใช้เรียก AV ในโปรเจกต์นี้ (`Atv_stats`, `atv`, `Max_atv`) |
| **Advance Forward** | ดึงตัวเองเข้าใกล้เส้นชัย — `AV ใหม่ = AV × (1 − x%)` **ไม่ใช่การเพิ่ม SPD** |
| **Delay / Action Delay** | ดันศัตรูถอยห่างเส้นชัย — `AV ใหม่ = AV × (1 + x%)` |
| **Extra Turn** | ได้เทิร์นเพิ่มโดยไม่ต้องวิ่งครบรอบ (ไม่รีเซ็ต AV) |
| **SPD Breakpoint** | ค่า SPD ที่ทำให้ได้เทิร์นเพิ่มพอดีในหนึ่ง Cycle (เช่น 134.0 / 143.0 / 160.1) |
| **Turn Order** | ลำดับที่จะได้เทิร์น เรียงจาก AV น้อยไปมาก |

> ⚠️ **จุดที่สับสนบ่อย**: "advance 25%" กับ "SPD +25%" **ไม่เหมือนกัน**
> advance ลด AV ครั้งเดียว ส่วน SPD ทำให้ AV ทุกรอบต่อจากนี้สั้นลง

---

## C. Toughness / Break

| ศัพท์ | ความหมาย |
|---|---|
| **Toughness** | เกจเหนือแถบ HP ศัตรู — ลดได้ด้วยธาตุที่ตรง Weakness เท่านั้น |
| **Weakness** | ธาตุที่ศัตรูอ่อนแอ (2–4 ธาตุต่อตัว) |
| **Weakness Break** | เกจ Toughness หมด → ลง Break DMG + ดีเลย์ศัตรู 25% + ลง debuff ธาตุ (base chance 150%) |
| **Weakness Broken** | สถานะหลัง Break — คงถึงเทิร์นถัดไปของศัตรู แล้วเกจเต็มใหม่ |
| **Broken Multiplier** | ตัวคูณ **0.9** ที่คูณดาเมจทุกชนิดขณะศัตรู**ยังไม่**ถูก Break |
| **Break DMG** | ดาเมจก้อนเดียวตอนทำ Break สำเร็จ — ไม่คริต สเกลตาม BE + Level Multiplier |
| **Super Break DMG** | ดาเมจพิเศษที่เกิดตอนตีศัตรูที่**ถูก Break แล้ว** ต้องมีตัวปลดล็อก (Harmony TB / Fugue / Rappa) |
| **Exo-Toughness** | เกจ Toughness เสริมที่ฟื้นเองได้ ใช้กับบอสบางตัว |
| **Weakness Implant** | การฝัง Weakness ธาตุใหม่ให้ศัตรู (Silver Wolf, Anaxa, Boothill, Fugue) |
| **Toughness Reduction** | ปริมาณ Toughness ที่ลดได้ต่อ hit — ท่าเป้าเดียวมักลด 30, AoE ลด 60 ฯลฯ |

---

## D. ระบบพัฒนาตัวละคร

| ศัพท์ | ความหมาย |
|---|---|
| **Ascension** | การก้าวข้ามระดับ ปลดเพดานเลเวล (Lv.20/30/40/50/60/70 → 80) |
| **Trace** | ระบบต้นไม้สกิล — แบ่งเป็น **Skill Trees** (อัปเลเวลท่า) และ **Bonus Abilities** (A2/A4/A6) |
| **A2 / A4 / A6** | Bonus Ability 3 ตัวที่ปลดตาม Ascension — เป็น passive ติดตัว |
| **Eidolon (E1–E6)** | การซ้อนตัวละครซ้ำ 6 ระดับ — เพิ่มพลังและบางทีเปลี่ยนกลไก |
| **E0** | ตัวละครที่ยังไม่มี Eidolon |
| **E1/E2/E4/E6** | มักเป็นเอฟเฟกต์ใหม่ |
| **E3 / E5** | เพิ่มเลเวลท่า — **E3 = Skill+Basic ATK, E5 = Ultimate+Talent** |
| **Superimposition (S1–S5)** | การซ้อน Light Cone ซ้ำ — เพิ่มความแรงของ passive (ไม่เพิ่ม base stat) |

> 📌 **ธรรมเนียมของโปรเจกต์นี้**: 5★ จำลองที่ระดับพื้นฐาน (Basic Lv.6, Skill/Ult/Talent Lv.10)
> ส่วน 4★ จำลองที่ **E6** (Basic Lv.7, Skill/Ult/Talent Lv.12, เปิด eidolon ครบ)

---

## E. Memosprite (Path of Remembrance, v3.0)

| ศัพท์ | ความหมาย |
|---|---|
| **Memosprite** | ยูนิตที่ตัวละคร Remembrance เรียกออกมา — มีเทิร์นและ AV ของตัวเอง |
| **Memosprite Skill** | ท่าของ memo ที่กดในเทิร์นของ memo |
| **Memosprite Talent** | passive ของ memo |
| **Memo Charge** | ทรัพยากรที่บาง memo ใช้ (เช่น Aglaea) |
| **Summon** | คำกว้างกว่า memosprite — รวม Lightning-Lord (Jing Yuan), Numby (Topaz), Fuyuan (Lingsha) |
| **Joint Attack** | หลายยูนิตยิงพร้อมกันเป็นดาเมจก้อนเดียว |

> `enum class Side` ในโค้ด: `Ally, Enemy, Memosprite, Summon, Countdown`

---

## F. Path of Elation (v4.0)

| ศัพท์ | ความหมาย |
|---|---|
| **Punchline** | แต้มสะสมของสาย Elation — สะสมจากการใช้ SP และท่าต่างๆ |
| **Aha Instant** | หน้าต่างพิเศษที่เปิดเมื่อ Punchline ครบ — ตัว Elation ได้ทำท่าพิเศษ |
| **Certified Banger** | บัฟที่แจกให้ตัว Elation ตอนเข้าสู้/หลัง Aha Instant ตามจำนวน Punchline |
| **Merrymake** | บัฟเฉพาะที่ Yao Guang แจกให้ทีม (เพิ่ม Elation DMG) |
| **Elation Skill** | ท่าที่ยิงในช่วง Aha Instant |
| **Elation (สแตต)** | ตัวคูณดาเมจ Elation โดยตรง |

---

## G. โหมดเนื้อหา / endgame

| ศัพท์ | ย่อ | ความหมาย |
|---|---|---|
| **Memory of Chaos** | MoC | ด่านท้าทาย 12 ชั้น เน้นดาเมจต่อ Cycle |
| **Pure Fiction** | PF | เน้นล้างศัตรูจำนวนมาก (AoE) |
| **Apocalyptic Shadow** | AS | เน้นบอสเดี่ยว + Break |
| **Simulated Universe** | SU | โหมดโรกไลก์ ฟาร์ม Planar |
| **Divergent Universe** | DU | SU เวอร์ชันใหม่ ฟาร์ม Planar เช่นกัน |
| **Cavern of Corrosion** | — | ที่ฟาร์ม Cavern Relic |
| **Planarcadia** | — | โหมด/เนื้อหาใหม่ในสาย 4.x |
| **Trailblaze Power** | TP | สแตมิน่าใช้ฟาร์ม |
| **Equilibrium Level** | EL | ระดับความยากของโลก (EL0–EL6) |

---

## H. ศัพท์ที่ชุมชนใช้

| ศัพท์ | ความหมาย |
|---|---|
| **DPS / Carry** | ตัวหลักที่ทำดาเมจ |
| **Sub-DPS** | ตัวรอง ทำดาเมจแต่ไม่ใช่หลัก |
| **Sustain** | ตัวประคองทีม (Abundance / Preservation) |
| **Support / Buffer** | ตัวบัฟ (Harmony) |
| **Debuffer** | ตัวลด stat ศัตรู (Nihility) |
| **Hypercarry** | ทีมที่ทุ่มบัฟทั้งหมดให้ DPS คนเดียว |
| **DoT team** | ทีมที่เน้นดาเมจต่อเนื่อง |
| **Break team** | ทีมที่เน้น Break/Super Break |
| **FuA team** | ทีมที่เน้น Follow-up ATK |
| **SP-positive / SP-negative** | ตัวที่คืน SP ให้ทีม / ตัวที่กิน SP |
| **Rotation** | ลำดับการกดท่าที่วนซ้ำได้ |
| **Snapshot** | บัฟถูก "ถ่ายภาพ" ตอนยิง แล้วใช้ค่านั้นไปตลอด |
| **Drip marketing** | การปล่อยภาพตัวละครใหม่ก่อนประกาศแพตช์ |
| **SP version (ตัวละคร)** | ร่างที่ 2 ของตัวละครเดิม (คนละ Path/ธาตุ) |

---

## I. ศัพท์เฉพาะของโปรเจกต์นี้

| ศัพท์ / โค้ด | ความหมาย |
|---|---|
| **ATV** | ชื่อที่โปรเจกต์นี้ใช้เรียก Action Value |
| `UnitStatus::Alive / Death` | สถานะปกติ |
| `UnitStatus::AtvFreeze` | ATV หยุดนิ่ง + ไม่ได้เทิร์นจาก `Find_turn` แต่ยังอยู่ในสนามและเป็นเป้าได้ (ใช้ตอน Ult ของ Phainon) |
| `UnitStatus::Retire` | ถูกลบจากสนาม ไม่ targetable + ATV หยุดนิ่ง (Ult ของ Phainon) |
| `UnitType::Standard / Backup / OutofBounds` | ประเภทยูนิตในทีม |
| `EnemyType::Main / Adjacent / Other` | ตำแหน่งศัตรูเทียบกับเป้าหลัก |
| `DriverType::DoubleTurn` | โหมดจำลอง: บังคับให้ได้ 2 เทิร์นติด |
| `DriverType::AlwaysPull` | โหมดจำลอง: ดึงเทิร์นตลอด |
| `DriverType::SwapPull` | โหมดจำลอง: สลับดึง |
| `DriverType::DotTrigger` | โหมดจำลอง: บังคับจุด DoT |
| `SPMode::Positive / Negative` | จำลองว่าทีมเป็น SP-positive หรือ SP-negative |
| `PhaseStatus::BeforeTurn / AfterTurn / WhileAction / DotBeforeTurn` | เฟสของการจำลองในหนึ่งเทิร์น |
| `SubstatsRerollMode::Standard / AllCombination / AllPossible` | โหมดสุ่ม substat ตอนหา build ที่ดีที่สุด |
| **Buff drift** | บั๊กที่บัฟถูกใส่กับถอนไม่เท่ากัน ทำให้สแตตค่อยๆ เพี้ยนไปเรื่อยๆ |
| **Taunt increase %** | ระบบ aggro ของโปรเจกต์นี้ — เก็บเป็น "เปอร์เซ็นต์ที่เพิ่ม" ไม่ใช่ตัวคูณ |
| `Buff_note` | ที่เก็บว่าบัฟนี้ให้ไปเท่าไร เพื่อถอนคืนตรงจำนวน |
| `AType::TEMP` | ช่องพักค่าชั่วคราวสำหรับ pattern ข้างบน |

---

## J. คำย่อรวม

| ย่อ | เต็ม |
|---|---|
| BA | Basic ATK |
| Ult | Ultimate |
| FuA | Follow-up ATK |
| DoT | Damage over Time |
| SPB | Super Break |
| AoE | Area of Effect |
| CR / CD | CRIT Rate / CRIT DMG |
| BE | Break Effect |
| EHR | Effect Hit Rate |
| ERR / ER | Energy Regeneration Rate |
| OHB / IHB | Outgoing / Incoming Healing Boost |
| SP | Skill Point |
| AV / ATV | Action Value |
| LC | Light Cone |
| E0–E6 | Eidolon |
| S1–S5 | Superimposition |
| MoC / PF / AS | Memory of Chaos / Pure Fiction / Apocalyptic Shadow |
| SU / DU | Simulated / Divergent Universe |
| DHIL | Dan Heng • Imbibitor Lunae |
| DHPT | Dan Heng • Permansor Terrae |
| TB / MC | Trailblazer / Main Character |
| RMC | Remembrance Trailblazer |
| SW | Silver Wolf |
