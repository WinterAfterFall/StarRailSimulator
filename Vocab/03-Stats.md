# 03 — Stats (สแตตทุกประเภท)

โค้ด: [`src/Enum/Enum.h`](../src/Enum/Enum.h) → `enum class Stats`
ชื่อที่ใช้พิมพ์ออกจอ: [`src/Setting.h:151`](../src/Setting.h) → `toString(Stats)`

แบ่งเป็น 5 กลุ่ม: **Base / Advanced / Combat-only / Enemy-side / Path-specific**

---

## 1. Base Stats — สแตตพื้นฐาน (เห็นในหน้าตัวละคร)

| ชื่อในเกม | ย่อ | โค้ด (`Stats`) | ชื่อพิมพ์ออกจอ | ไทย |
|---|---|---|---|---|
| **HP** | HP | `HP_P` / `FLAT_HP` | `HP%` / `Flat HP` | พลังชีวิต |
| **ATK** | ATK | `ATK_P` / `FLAT_ATK` | `ATK%` / `Flat ATK` | พลังโจมตี |
| **DEF** | DEF | `DEF_P` / `FLAT_DEF` | `DEF%` / `Flat DEF` | พลังป้องกัน |
| **SPD** | SPD | `SPD_P` / `FLAT_SPD` | `Spd%` / `Flat Spd` | ความเร็ว → กำหนดว่าได้เทิร์นบ่อยแค่ไหน |
| **CRIT Rate** | CR | `CR` | `Crit rate` | โอกาสคริติคอล (ฐาน 5%) |
| **CRIT DMG** | CD | `CD` | `Crit dam` | ดาเมจคริติคอล (ฐาน 50%) |

**กฎการรวมค่า** (สำคัญมากตอน implement):
```
ATK สุดท้าย = (Base ATK ตัวละคร + Base ATK ของ Light Cone) × (1 + ผลรวม ATK%) + ผลรวม Flat ATK
```
- `Base ATK` มาจากตัวละคร + Light Cone เท่านั้น (Relic main/substat นับเป็น flat/%)
- **% กับ flat แยกกันคนละถัง** — flat ไม่ถูกคูณด้วย %
- SPD ในเกมจริงมี **floor ทศนิยม** ตอนคำนวณ AV จริง — ระวังตอนหา breakpoint

---

## 2. Advanced Stats — สแตตขั้นสูง (เห็นในหน้า detail)

| ชื่อในเกม | ย่อ | โค้ด (`Stats`) | ชื่อพิมพ์ | ไทย / ผลที่ได้ |
|---|---|---|---|---|
| **Break Effect** | BE | `BREAK_EFF` | `Break Effeciency` | เพิ่ม Break DMG + Super Break DMG (ฐาน 100%) |
| **Effect Hit Rate** | EHR | `EHR` | `Ehr` | โอกาสลง debuff สำเร็จ |
| **Effect RES** | RES | `RES` | `Res` | ต้านการโดน debuff |
| **Energy Regeneration Rate** | ERR / ER | `ER` | `ER` | เพิ่มพลังงาน Ultimate ที่ได้รับ (ฐาน 100%) |
| **Outgoing Healing Boost** | OHB | `HEALING_OUT` | `Healing out` | เพิ่มการฮีลที่ "ปล่อยออก" |
| **Incoming Healing Boost** | IHB | `HEALING_IN` | `Healing in` | เพิ่มการฮีลที่ "รับเข้า" |

> ⚠️ **BE สะกดผิดในโค้ด** — `"Break Effeciency"` (ควรเป็น *Efficiency*/*Effect*) ที่ [`Setting.h:174`](../src/Setting.h)
> ปล่อยไว้ได้เพราะเป็นแค่ string ที่พิมพ์ออกจอ แต่ถ้าจะแก้ต้องแก้ทีเดียวทั้งไฟล์

> ⚠️ โค้ดมี **`BE` กับ `BREAK_EFF` แยกกันสองตัว** ใน `enum class Stats` — ตรวจให้ดีว่าตัวไหนใช้จริง

---

## 3. Combat-only Stats — มีเฉพาะตอนสู้ (ไม่เห็นในหน้าตัวละคร)

พวกนี้คือ "ตัวคูณดาเมจ" ที่ไม่มีช่องสแตตในเกม แต่มีจริงในสูตร

| ชื่อในเกม | โค้ด (`Stats`) | ชื่อพิมพ์ | ไทย / กฎ |
|---|---|---|---|
| **DMG Boost** | `DMG` | `DMG%` | เพิ่มดาเมจ — แยกตามธาตุและตาม `AType` ได้ |
| **Vulnerability** | `VUL` | `Vul` | ศัตรูรับดาเมจเพิ่ม (ติดที่ตัวศัตรู) |
| **DEF Reduction / DEF Ignore** | `DEF_SHRED` | `DEF Shred` | ลด/ข้าม DEF ศัตรู |
| **RES PEN** | `RESPEN` | `Respen` | เจาะ Elemental RES ของศัตรู |
| **DMG Mitigation / DMG Reduction** | `Mitigration` | — | ลดดาเมจที่ทีมเรารับ (คูณกันแบบ multiplicative) |
| **Shield Effect** | `SHEILD` | `Sheild` | เพิ่มค่าเกราะที่สร้าง |
| **Toughness Reduction Boost** | `TOUGH_REDUCE` | `Toughness Reduce` | เพิ่มการลด Toughness ต่อครั้ง (เช่น Fugue) |
| **Super Break Multiplier** | `SPB_inc` | — | เพิ่ม Super Break DMG (SPB = Super BreaK) |
| **Multiplier Increase** | `MtprInc` | — | เพิ่มตัวคูณสกิลตรงๆ (Mtpr = **M**ul**t**i**p**lie**r**) |
| **Aggro / Taunt** | (ระบบแยก) | — | โอกาสถูกศัตรูเลือกเป็นเป้า — โปรเจกต์นี้ใช้ "taunt increase %" |

> 📌 `Mitigration` = พิมพ์ผิดของ *Mitigation* ในโค้ด — เขียนตามนี้เวลาเรียก enum

> 📌 `MtprInc` ต่างจาก `DMG` ตรงที่: `MtprInc` บวกเข้า **ตัวคูณสกิล** (เช่น 250% → 300%)
> ส่วน `DMG` บวกเข้า **DMG Boost bucket** ในสูตรดาเมจ ผลลัพธ์ต่างกัน

### สูตรดาเมจ (ย่อ) — ว่าแต่ละสแตตเข้าถังไหน

```
DMG = BaseDMG                      ← ตัวคูณสกิล (MtprInc บวกตรงนี้) × สแตตต้นทาง (ATK/HP/DEF)
    × (1 + DMG Boost)              ← Stats::DMG  (แยกตามธาตุ / AType)
    × (1 + CRIT DMG)               ← Stats::CD   (ถ้าคริต)
    × DEF Multiplier               ← Stats::DEF_SHRED
    × RES Multiplier               ← Stats::RESPEN
    × (1 + Vulnerability)          ← Stats::VUL
    × Broken Multiplier            ← 0.9 ถ้าศัตรูยังไม่ถูก Break
    × (1 - DMG Mitigation)         ← Stats::Mitigration (ฝั่งรับ)
```
รายละเอียดเต็มดู [`docs/hsr-system-reference.md` §10](../docs/hsr-system-reference.md)

---

## 4. Path-specific Stats — สแตตเฉพาะทาง (Path of Elation, v4.0)

| ชื่อในเกม | โค้ด (`Stats`) | ไทย |
|---|---|---|
| **Elation** | `Elation` | สแตตหลักของ Path of Elation — คูณ Elation DMG โดยตรง |
| **Certified Banger** | `CertifiedBanger` | แต้มสะสมจาก Punchline ที่ให้ Elation char ตอนเข้าสู้/หลัง Aha Instant |
| **Merrymake** | `Merrymake` | บัฟที่ Yao Guang แจกให้ทีม (เพิ่ม Elation DMG) |

> โค้ดที่เกี่ยวข้อง: [`CalStats.h:339`](../src/Defination/Function/Calculate/CalStats.h) (คำนวณ elationMtpr),
> [`Combat.h:57`](../src/Defination/Function/Combat/Combat.h) (แจก Certified Banger ตาม Punchline)

---

## 5. Enemy-side Stats — สแตตฝั่งศัตรู

| ชื่อในเกม | ไทย / หมายเหตุ |
|---|---|
| **Toughness** | เกจเหนือแถบ HP — ลดได้ด้วยธาตุที่ตรงจุดอ่อนเท่านั้น หมดแล้วเกิด Weakness Break |
| **Exo-Toughness** | เกจ Toughness เสริมที่ฟื้นเองได้ ใช้กับบอสบางตัว |
| **Weakness** | ธาตุที่ศัตรูอ่อนแอ (2–4 ธาตุต่อตัว) |
| **Enemy Level** | ใช้ในสูตร DEF Multiplier และ Level Multiplier ของ Break DMG |
| **Enemy DEF** | ป้องกัน — ลดได้ด้วย DEF Shred |
| **Enemy RES** | ต้านทานธาตุ — เจาะได้ด้วย RES PEN |
| **Enemy Effect RES** | ต้าน debuff |
| **Max Toughness** | ค่าสูงสุดของเกจ (มีผลกับ Break DMG บางสูตร) |

---

## 6. Relic Main Stat — สแตตหลักที่ออกได้ต่อชิ้น

| ชิ้น | Main Stat ที่เป็นไปได้ | ค่าสูงสุด 5★ +15 |
|---|---|---|
| **Head** (หัว) | flat HP เท่านั้น | 705.6 |
| **Hands** (มือ) | flat ATK เท่านั้น | 352.8 |
| **Body** (ตัว) | HP% / ATK% / DEF% / EHR / Outgoing Healing / CRIT Rate / CRIT DMG | CR 32.4%, CD 64.8%, OHB 34.56% |
| **Feet** (เท้า) | HP% / ATK% / DEF% / **SPD** | SPD 25.032 |
| **Planar Sphere** (ลูกแก้ว) | HP% / ATK% / DEF% / **Type DMG Boost** 7 ธาตุ | Type DMG 38.88% |
| **Link Rope** (เชือก) | HP% / ATK% / DEF% / **Break Effect** / **ERR** | BE 64.8%, ERR 19.44% |

ค่าทั่วไป: ATK%/HP%/EHR = 43.2% · DEF% = 54%

---

## 7. Relic Substat — สแตตย่อย (มี 10 ชนิด)

| Substat | น้ำหนักสุ่ม | ค่าต่อ roll 5★ (Low/Med/High) |
|---|---|---|
| flat HP | 10 | — |
| flat ATK | 10 | — |
| flat DEF | 10 | — |
| HP% | 10 | 3.456 / 3.888 / 4.32 |
| ATK% | 10 | 3.456 / 3.888 / 4.32 |
| DEF% | 10 | 4.32 / 4.86 / 5.4 |
| Effect Hit Rate | 8 | — |
| Effect RES | 8 | — |
| Break Effect | 8 | 5.184 / 5.832 / 6.48 |
| CRIT Rate | 6 | 2.592 / 2.916 / 3.24 |
| CRIT DMG | 6 | 5.184 / 5.832 / 6.48 |
| **SPD** | **4 (ต่ำสุด)** | 2 / 2.3 / 2.6 |

> ไม่มี substat ชนิด: SPD%, ERR, Outgoing Healing, Type DMG — พวกนี้เป็น main stat เท่านั้น

---

## 8. หมายเหตุสำหรับโค้ดนี้โดยเฉพาะ

- `Test1`–`Test6` ใน `enum class Stats` = ช่องทดสอบ ไม่ใช่สแตตจริงในเกม
- โครงสร้างที่ใช้เก็บสแตต 3 แบบ:
  ```cpp
  typedef unordered_map<Stats,double>                                          Common_stats;
  typedef unordered_map<Stats,unordered_map<AType,double>>                     Common_stats_type;
  typedef unordered_map<Stats,map<ElementType,map<AType,double>>>              Common_stats_each_element;
  ```
  - `Common_stats` = สแตตเปล่าๆ
  - `Common_stats_type` = สแตตที่แยกตาม **ชนิดการโจมตี** (เช่น "Ult DMG +30%")
  - `Common_stats_each_element` = สแตตที่แยกทั้ง **ธาตุและชนิดการโจมตี**
- `AType::None` ใน `Stats_type` = "ใช้กับทุกชนิดการโจมตี" (บัฟรวม)
- `AType::TEMP` = ที่พักค่าชั่วคราว ใช้จำว่าบัฟนี้ให้ไปเท่าไรจะได้ถอนคืนตรงจำนวน
  (ดู [`03`] pattern ใน `YaoGuang.h` ที่เก็บ `Stats::Elation` ทั้ง `None` และ `TEMP`)
- โปรเจกต์นี้เก็บบัฟเป็น **raw +/- delta** ไม่ใช่ snapshot — ถ้าใส่กับถอนไม่เท่ากันจะเกิด **buff drift**
