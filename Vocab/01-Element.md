# 01 — Element / Combat Type (ธาตุ)

ในเกมเรียกทางการว่า **Combat Type** แต่คนทั่วไปเรียก **Element** หรือ **Type**
ปัจจุบันมี **7 ธาตุ** ทั้งหมด ไม่มีเพิ่มมาตั้งแต่ 1.0

โค้ด: [`src/Enum/Enum.h`](../src/Enum/Enum.h) → `enum class ElementType`

---

## ตารางหลัก

| ชื่อในเกม | โค้ด (`ElementType`) | ไทย | Break DMG debuff ที่ได้ | สีธีม |
|---|---|---|---|---|
| **Physical** | `Physical` | กายภาพ | **Bleed** (เลือดไหล) — DoT ตาม Max HP ศัตรู | ขาว/เทา |
| **Fire** | `Fire` | ไฟ | **Burn** (ไหม้) — DoT ตาม ATK ผู้ทำ Break | ส้ม/แดง |
| **Ice** | `Ice` | น้ำแข็ง | **Freeze** (แช่แข็ง) — ข้ามเทิร์น + โดน DMG ตอนละลาย | ฟ้า |
| **Lightning** | `Lightning` | สายฟ้า | **Shock** (ช็อต) — DoT ตาม ATK ผู้ทำ Break | ม่วง |
| **Wind** | `Wind` | ลม | **Wind Shear** (ลมเฉือน) — DoT ซ้อนได้สูงสุด 5 ชั้น | เขียว |
| **Quantum** | `Quantum` | ควอนตัม | **Entanglement** (พันธนาการ) — ดีเลย์ + DMG ตามจำนวนครั้งที่ถูกตี | น้ำเงินเข้ม |
| **Imaginary** | `Imaginary` | จินตภาพ | **Imprisonment** (จองจำ) — ดีเลย์ + ลด SPD | เหลือง |

> โค้ด `enum class BreakSEType` เก็บ debuff 7 ตัวนี้ไว้ (`Bleed, Burn, Shock, WindShear, Freeze, Entanglement, Imprisonment`)

---

## กฎสำคัญที่ต้องจำ

1. **ไม่มี elemental reaction แบบ Genshin** — ธาตุเป็นแค่ "ชนิดของดาเมจ" + "กุญแจไขจุดอ่อน" เท่านั้น
   ไม่มีการผสมธาตุกันแล้วเกิดเอฟเฟกต์พิเศษ
2. **ความอ่อนแอ (Weakness) เป็นของศัตรูรายตัว** ไม่ใช่ตารางธาตุตายตัว
   ศัตรู 1 ตัวมีจุดอ่อน 2–4 ธาตุ
3. **เฉพาะธาตุที่ตรงจุดอ่อนเท่านั้นที่ลด Toughness ได้** — ธาตุที่ไม่ตรงยังลง DMG ได้ปกติ แต่ไม่กินเกจ
4. **ตัวละครผู้เล่นไม่มี Toughness** และไม่ถูก Weakness Break แต่ยังติด debuff ธาตุจากศัตรูได้
5. **DMG% แยกตามธาตุ** — เช่น "Fire DMG +10%" จะบวกเฉพาะดาเมจที่เป็นธาตุไฟ
   ในโค้ดใช้ `Common_stats_each_element` = `map<Stats, map<ElementType, map<AType, double>>>`

---

## Elation DMG — ชนิดดาเมจใหม่ (v4.0)

**ไม่ใช่ธาตุที่ 8** แต่เป็น "ชนิดดาเมจ" ที่ทำงานคู่ขนานกับธาตุ

| ประเด็น | รายละเอียด |
|---|---|
| ชื่อ | **Elation DMG** |
| โค้ด | `AType::ElationDMG` (แกนดาเมจ) + `Stats::Elation` (แกนสแตต) |
| คริติคอลได้ไหม | ✅ ได้ |
| ลด Toughness ไหม | ❌ ไม่ลด (ไม่ผูกกับ Weakness) |
| สเกลตามอะไร | สแตต **Elation** (สแตตเฉพาะทางใหม่) + `DmgSrcType::Elation` |
| ใครใช้ | ตัวละคร Path of Elation ทั้งหมด |

> อ่านกลไก Punchline / Aha Instant / Certified Banger เต็มๆ ได้ที่
> [`docs/hsr-system-reference.md` §11](../docs/hsr-system-reference.md)

---

## ตัวเลขน่ารู้

- ธาตุที่มีตัวละครมากสุด: **Physical** และ **Fire**
- ธาตุที่ตัวละคร Elation ใช้อยู่ตอนนี้: Physical (Yao Guang, Evanescia), Fire (Sparxie),
  Imaginary (Silver Wolf LV.999), Lightning (Elation Trailblazer), Quantum (Aventurine • Waveflair)
- Relic 2-piece ที่ให้ "ธาตุ DMG +10%" มีครบทั้ง 7 ธาตุ (ดู [07-Relic.md](07-Relic.md))
