# 08 — Planar Ornament Set (เซ็ตเครื่องประดับ 2 ชิ้น)

**Planar Ornaments** = ของฟาร์มจาก **Simulated Universe / Divergent Universe**
มี 2 ชิ้น: **Planar Sphere** + **Link Rope**

**กฎสำคัญ**: มีแค่โบนัส **2-piece** เท่านั้น — ต้องเป็นเซ็ตเดียวกันทั้งคู่ถึงจะได้ผล
ถ้าไม่เข้าคู่ → ได้แค่ main stat + substat ไม่ได้เอฟเฟกต์เลย

ปัจจุบันมี **28 เซ็ต** · ค่าโดยประมาณของเซ็ตที่เหมาะสม ≈ **10% ของดาเมจรวม**

- ✅ = โปรเจกต์นี้ implement แล้ว ([`src/Defination/Data/Planar/`](../src/Defination/Data/Planar/))

---

## กลุ่ม 1 — เกต SPD (ต้องปั่นความเร็วถึงเส้น)

| เซ็ต | 2-Piece Effect | โค้ด |
|---|---|---|
| **Space Sealing Station** | ATK +12%; ถ้า **SPD ≥120** → ATK เพิ่มอีก 12% | `SpaceSealing.h` ✅ |
| **Fleet of the Ageless** | Max HP +12%; ถ้า **SPD ≥120** → **ทีม ATK +8%** | |
| **Sprightly Vonwacq** | ERR +5%; ถ้า **SPD ≥120** → เข้าสู้แล้ว **advance 40%** ทันที | |
| **Firmament Frontline: Glamoth** | ATK +12%; ถ้า **SPD ≥135 / ≥160** → DMG +12% / +18% | `FirmanentFrontline.h` ✅ |
| **Talia: Kingdom of Banditry** | Break Effect +16%; ถ้า **SPD ≥145** → BE เพิ่มอีก 20% | `Talia.h` ✅ |
| **Giant Tree of Rapt Brooding** | SPD +6%; ถ้า **SPD ≥135 / ≥180** → Outgoing Healing ของผู้ใส่และ memo +12% / +20% | `GiantTree.h` ✅ |

---

## กลุ่ม 2 — เกต Crit

| เซ็ต | 2-Piece Effect | โค้ด |
|---|---|---|
| **Rutilant Arena** | CR +8%; ถ้า **CR ≥70%** → **BA และ Skill DMG +20%** | `Rutilant.h` ✅ |
| **Inert Salsotto** | CR +8%; ถ้า **CR ≥50%** → **Ult และ FuA DMG +15%** | `Inert.h` ✅ |
| **Celestial Differentiator** | CD +16%; ถ้า **CD ≥120%** → เข้าสู้แล้ว CR +60% จนจบการโจมตีครั้งแรก | |
| **Sigonia, the Unclaimed Desolation** | CR +4%; ศัตรูตาย → CD +4% ซ้อนได้ 10 ชั้น | |

---

## กลุ่ม 3 — เกตสแตตอื่น

| เซ็ต | 2-Piece Effect | โค้ด |
|---|---|---|
| **Pan-Cosmic Commercial Enterprise** | EHR +10%; ATK เพิ่มขึ้น = **25% ของ EHR ปัจจุบัน** (เพดาน +25%) | |
| **Belobog of the Architects** | DEF +15%; ถ้า **EHR ≥50%** → DEF เพิ่มอีก 15% | |
| **Broken Keel** | Effect RES +10%; ถ้า **Effect RES ≥30%** → **ทีม CD +10%** | `Broken_Keel.h` ✅ |
| **Bone Collection's Serene Demesne** | Max HP +12%; ถ้า **Max HP ≥5,000** → CD ของผู้ใส่และ memo +28% | `Bone_Collection.h` ✅ |
| **Revelry by the Sea** | ATK +12%; ถ้า **ATK ≥2,400 / ≥3,600** → **DoT DMG +12% / +24%** | `Revelry by the Sea.h` ✅ |
| **Cosmic Life Sciences Institute** | เข้าสู้ ถ้า **Max Energy ≥200** → ทุก 1 แต้มที่เกิน DMG +0.2% (เพดาน +32%) | |

---

## กลุ่ม 4 — เกตองค์ประกอบทีม

| เซ็ต | 2-Piece Effect | โค้ด |
|---|---|---|
| **Penacony, Land of the Dreams** | ERR +5%; **พวกที่ธาตุเดียวกับผู้ใส่** → DMG +10% |  |
| **Izumo Gensei and Takama Divine Realm** | ATK +12%; เข้าสู้ ถ้ามีพวก **Path เดียวกัน** อย่างน้อย 1 คน → CR +12% | `Izumo.h` ✅ |
| **Lushaka, the Sunken Seas** | ERR +5%; ถ้าผู้ใส่**ไม่ใช่คนแรก**ในลิสต์ทีม → **ATK ของคนแรก +12%** | `Lushaka.h` ✅ |
| **Arcadia of Woven Dreams** | จำนวนพวกในสนาม **มากกว่า/น้อยกว่า 4** → ทุกตัวที่เกิน/ขาดเพิ่ม DMG ของผู้ใส่และ memo **+9% / +12%** (max 4 / 3 ชั้น) | `Arcadia.h` ✅ |
| **Fallen Star Anchorage** | CR +8%; เข้าสู้ ถ้าผู้ใส่และเพื่อนอีกคนเป็น **Trailblaze Companions** → CD +32% | |

---

## กลุ่ม 5 — เกตกลไกเฉพาะทาง

| เซ็ต | 2-Piece Effect | โค้ด |
|---|---|---|
| **The Wondrous BananAmusement Park** | CD +16%; ถ้ามี **summon ของผู้ใส่** อยู่ในสนาม → CD เพิ่มอีก 32% | `The_Wondrous_BananAmusement_Park.h` ✅ |
| **Amphoreus, The Eternal Land** | CR +8%; ขณะ **memosprite** ของผู้ใส่อยู่สนาม → **ทีม SPD +8%** (ไม่ stack) | |
| **Duran, Dynasty of Running Wolves** | พวกใช้ **FuA** → **Merit** 1 ชั้น max 5; แต่ละชั้นเพิ่ม FuA DMG ของผู้ใส่ +5% (ครบ 5 ชั้น → CD +25% ❓) | |
| **City of Converging Stars** | ใช้ **FuA** → ATK +24% 2 เทิร์น; ศัตรูตาย → **ทีม CD +12%** ตลอดการต่อสู้ที่เหลือ | |
| **Forge of the Kalpagni Lantern** | SPD +6%; ตีศัตรูที่มี **Fire Weakness** → BE +40% 1 เทิร์น | `Kalpagni_Lantern.h` ✅ |
| **Tengoku@Livestream** | CD +16%; ถ้าใช้ **SP ≥3 แต้มในเทิร์นเดียว** → CD เพิ่มอีก 32% เป็นเวลา 3 เทิร์น | `Tengoku@Livestream.h` ✅ |
| **Punklorde Stage Zero** | **Elation +8%**; เมื่อ Elation แตะ 40% / 80% ครั้งแรกในสนาม → CD +20% / +32% | |

---

## สรุปรวม 28 เซ็ต (เรียงตามตัวอักษร)

1. Amphoreus, The Eternal Land
2. Arcadia of Woven Dreams ✅
3. Belobog of the Architects
4. Bone Collection's Serene Demesne ✅
5. Broken Keel ✅
6. Celestial Differentiator
7. City of Converging Stars
8. Cosmic Life Sciences Institute
9. Duran, Dynasty of Running Wolves
10. Fallen Star Anchorage
11. Firmament Frontline: Glamoth ✅
12. Fleet of the Ageless
13. Forge of the Kalpagni Lantern ✅
14. Giant Tree of Rapt Brooding ✅
15. Inert Salsotto ✅
16. Izumo Gensei and Takama Divine Realm ✅
17. Lushaka, the Sunken Seas ✅
18. Pan-Cosmic Commercial Enterprise
19. Penacony, Land of the Dreams
20. Punklorde Stage Zero
21. Revelry by the Sea ✅
22. Rutilant Arena ✅
23. Sigonia, the Unclaimed Desolation
24. Space Sealing Station ✅
25. Sprightly Vonwacq
26. Talia: Kingdom of Banditry ✅
27. Tengoku@Livestream ✅
28. The Wondrous BananAmusement Park ✅

**implement แล้ว 15/28**

---

## ข้อควรระวัง

- **ชื่อที่คนสะกดผิดบ่อย**: `Pan-Cosmic` (ไม่ใช่ *Pan-Galactic*) · `Firmament` (ในโค้ดสะกด `FirmanentFrontline.h`)
- Planar **ไม่มีโบนัส 1 ชิ้น** — ถ้าเก็บ Sphere กับ Rope คนละเซ็ต จะไม่ได้เอฟเฟกต์ใดๆ
- เกต SPD/CR/ATK ของ Planar เช็คจาก **สแตตในสนามจริง** (รวมบัฟ) เว้นแต่ระบุว่า "ก่อนเข้าสู้"
  → เซ็ตที่เขียนว่า *"When entering combat"* / *"Before entering battle"* จะ snapshot ตอนเริ่ม
- ตัวเลขเกตที่เจอบ่อย: **SPD 120 / 135 / 145 / 160 / 180** · **CR 50% / 70%** · **CD 120%** · **BE 150% / 250%**
