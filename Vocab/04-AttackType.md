# 04 — Attack Type / Damage Type (การโจมตีทุกประเภท)

โค้ด: [`src/Enum/Enum.h`](../src/Enum/Enum.h) → `enum class AType`

> 🔑 **แกนสองแกนที่ต้องแยกให้ออก** (กฎของโปรเจกต์นี้)
> - **`actionTypeList`** = *แกน trigger* — ใช้ตอบว่า "action นี้นับเป็นอะไร" สำหรับ trigger/เงื่อนไข
>   (เช่น "หลังใช้ Ultimate ให้..." จะดูจากลิสต์นี้)
> - **`damageTypeList`** = *แกน buff lookup* — ใช้ตอบว่า "ก้อนดาเมจนี้กินบัฟตัวไหนได้บ้าง"
>   (เช่น `Stats_type[DMG][Ult]` จะบวกเมื่อ `Ult` อยู่ในลิสต์นี้)
>
> ปกติสองลิสต์นี้**เท่ากัน** มีแค่เคสพิเศษ (DoT, Joint Attack, Super Break, memo skill) ที่ต่างกัน

---

## 1. Action Type — "ทำอะไรในเทิร์น"

| ชื่อในเกม | โค้ด (`AType`) | ไทย | SP | Energy |
|---|---|---|---|---|
| **Basic ATK** | `BA` | โจมตีปกติ | **+1** | +20 (มาตรฐาน) |
| **Skill** | `SKILL` | สกิล | **−1** | +30 (มาตรฐาน) |
| **Ultimate** | `Ult` | อัลติเมท | 0 | +5 หลังใช้ |
| **Technique** | `Technique` | เทคนิค (ใช้ก่อนเข้าสู้ นอกสนามรบ) | 0 | ใช้ Technique Point |
| **Talent** | `Talent` | ทาเลนต์ (passive / ท่าที่ยิงเองอัตโนมัติ) | 0 | แล้วแต่ท่า |
| **Enhanced Basic ATK** | `BA` (+ flag) | Basic ATK เวอร์ชันอัป (เช่น DHIL, RMC) | มักไม่ได้ SP | ต่างจากปกติ |
| **Assist Skill** ❓ | ยังไม่มี | สกิลช่วยแบบใหม่ (v4.4 — Himeko • Nova) | ❓ | ❓ |

> **Technique** ยิงก่อนเข้าสู้ ไม่กิน AV และไม่นับเป็นเทิร์น — เป็น "โบนัสเปิดเกม"

---

## 2. Damage Type — "ก้อนดาเมจนี้เป็นชนิดไหน"

| ชื่อในเกม | โค้ด (`AType`) | ไทย | คริตได้? | ลด Toughness? |
|---|---|---|---|---|
| **Follow-up ATK (FuA)** | `Fua` | โจมตีตาม — ยิงนอกเทิร์นตัวเอง | ✅ | ✅ |
| **Additional DMG** | `Addtional` | ดาเมจเสริม — ไม่ใช่ "การโจมตี" | ✅ | ❌ |
| **DoT (Damage over Time)** | `Dot` | ดาเมจต่อเนื่องตอนต้นเทิร์นศัตรู | ❌ | ❌ |
| **Break DMG** | `Break` | ดาเมจตอนทำ Weakness Break | ❌ | — |
| **Super Break DMG** | `SPB` | Super Break — ดาเมจพิเศษตอนตีศัตรูที่ Broken แล้ว | ❌ | — |
| **Memosprite DMG** | `Summon` | ดาเมจจาก memosprite | ✅ | ✅ |
| **Elation DMG** | `ElationDMG` | ดาเมจชนิด Elation (v4.0) | ✅ | ❌ |
| **Elation Skill** | `ElationSkill` | ท่าของสาย Elation ที่ยิงจาก Punchline | ✅ | ❌ |
| **True DMG** | ยังไม่มี | ดาเมจตรงข้าม ไม่ผ่าน DEF/RES (หายาก) | ❌ | ❌ |

> ⚠️ **`Addtional` สะกดผิดในโค้ด** (ควรเป็น *Additional*) — เขียนตามนี้เวลาเรียก enum

### กฎเคสพิเศษ (สรุปจาก review ของโปรเจกต์นี้)

| เคส | `actionTypeList` | `damageTypeList` | เหตุผล |
|---|---|---|---|
| **DoT** | `Dot` | `Dot` (+ธาตุ) | DoT ไม่นับเป็น "attack" → ไม่ trigger on-attack |
| **Joint Attack** | ของผู้ริเริ่ม | ของ**ทุกคน**ที่ร่วมโจมตี | บัฟของแต่ละคนต้องเข้าก้อนดาเมจของตัวเอง |
| **Super Break** | `SPB` | `SPB` + type ของ hit ที่ทำให้เกิด | SPB เกาะบน hit ปกติ |
| **Memosprite Skill** | `Summon` | `Summon` + `SKILL` ❓ | memo skill นับเป็นสกิลของ memo ไม่ใช่ของเจ้าของ |
| **Enhanced BA** | `BA` | `BA` | ยังนับเป็น Basic ATK ทุกประการ |
| **Break DMG** | `Break` | `Break` (+ธาตุที่ทำ Break) | ไม่คริต ไม่กินบัฟ CD |

---

## 3. Break Debuff / Status — สถานะจากการ Break

| ชื่อในเกม | โค้ด (`AType` / `BreakSEType`) | ธาตุที่ทำให้เกิด | ผล |
|---|---|---|---|
| **Bleed** | `Bleed` | Physical | DoT ตาม **Max HP ศัตรู** (มีเพดาน) |
| **Burn** | `Burn` | Fire | DoT ตาม ATK ผู้ทำ Break |
| **Shock** | `Shock` | Lightning | DoT ตาม ATK ผู้ทำ Break |
| **Wind Shear** | `WindShear` | Wind | DoT ซ้อนได้สูงสุด **5 ชั้น** |
| **Freeze** | `Freeze` | Ice | ข้ามเทิร์น + โดนดาเมจตอนละลาย |
| **Entanglement** | `Entanglement` | Quantum | ดีเลย์ + ดาเมจตามจำนวนครั้งที่ถูกตีตอนติดสถานะ |
| **Imprisonment** | `BreakSEType::Imprisonment` | Imaginary | ดีเลย์ + **ลด SPD 10%** |

> `enum class DotType` แยกอีกชุด: `Shock, Bleed, Burn, WindShear, General`
> (`General` = DoT ที่ไม่ผูกธาตุ เช่นที่มาจาก Light Cone)

---

## 4. Targeting Pattern — รูปแบบการเล็งเป้า

โค้ด: `enum class TraceType`

| ชื่อในเกม | โค้ด | ไทย |
|---|---|---|
| **Single Target** | `Single` | ตีเป้าเดียว |
| **Blast** | `Blast` | ตีเป้าหลัก + ซ้าย/ขวาข้างละ 1 (3 ตัว) |
| **AoE** | `Aoe` | ตีศัตรูทุกตัวในสนาม |
| **Bounce** | `Bounce` | เด้งสุ่มหลายครั้ง (เช่น Serval, Sampo) |

ตำแหน่งศัตรูที่เกี่ยว: `enum class EnemyType` → `Main` (เป้าหลัก), `Adjacent` (ข้างๆ), `Other` (ที่เหลือ)

---

## 5. Damage / Heal Source — สแตตต้นทางของตัวคูณ

| โค้ด (`DmgSrcType`) | ความหมาย | ตัวอย่าง |
|---|---|---|
| `ATK` | สเกลตาม ATK | ส่วนใหญ่ของเกม |
| `HP` | สเกลตาม Max HP | Blade, Mydei, Castorice |
| `DEF` | สเกลตาม DEF | Aventurine, Fu Xuan, March 7th |
| `CONST` | ค่าคงที่ ไม่สเกล | ดาเมจ fix บางท่า |
| `Elation` | สเกลตามสแตต Elation | สาย Elation |

| โค้ด (`HealSrcType`) | ความหมาย |
|---|---|
| `ATK` / `HP` / `DEF` | ฮีลตามสแตตนั้น |
| `TOTAL_HP` | ฮีลตาม **Max HP ของเป้า** |
| `LOST_HP` | ฮีลตาม **HP ที่หายไปของเป้า** |
| `CONST` | ฮีลค่าคงที่ |

---

## 6. AType ที่เหลือในโค้ด

| โค้ด | ใช้ทำอะไร |
|---|---|
| `TEMP` | ที่พักค่าชั่วคราว — ใช้จำว่าบัฟนี้ให้ไปเท่าไร เพื่อถอนคืนตรงจำนวน |
| `None` | "ทุกชนิดการโจมตี" — บัฟรวมที่ไม่แยกชนิด |
| `ERROR` | ค่าที่ไม่ควรมี ใช้ดัก bug |

---

## 7. ศัพท์การโจมตีที่ไม่มีใน enum แต่เจอในเกม

| ชื่อ | ความหมาย |
|---|---|
| **Joint Attack** | หลายตัวยิงพร้อมกันเป็นก้อนเดียว (Feixiao, Yunli, Tribbie) |
| **Counter / Counterattack** | ตอบโต้เมื่อถูกตี (Clara, Yunli) — เป็น FuA ชนิดหนึ่ง |
| **Delay / Action Delay** | ดัน AV ศัตรูถอยหลัง (ยิ่งช้าลง) |
| **Advance Forward** | ดัน AV ตัวเองไปข้างหน้า (ได้เทิร์นเร็วขึ้น) |
| **Extra Turn** | ได้เทิร์นเพิ่มโดยไม่กิน AV (เช่นสาย Remembrance/Elation บางท่า) |
| **Hit Split** | 1 ท่ายิงหลาย hit — สำคัญมากกับ Toughness และ Ashblazing Grand Duke |
| **Aha Instant** | หน้าต่างพิเศษของ Path of Elation ที่เปิดเมื่อ Punchline เต็ม |
| **Punchline** | แต้มสะสมของสาย Elation → ครบแล้วเปิด Aha Instant |
| **Break** vs **Weakness Break** | คำเดียวกัน — ตอนเกจ Toughness หมด |
