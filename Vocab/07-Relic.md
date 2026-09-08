# 07 — Cavern Relic Set (เซ็ตรีลิค 4 ชิ้น)

**Cavern Relics** = ของฟาร์มจาก **Cavern of Corrosion** มี 4 ชิ้น: **Head / Hands / Body / Feet**
มีทั้งโบนัส **2-piece** และ **4-piece** (ใส่ครบ 4 ชิ้นได้ทั้งสอง)

ปัจจุบันมี **32 เซ็ต**

- ✅ = โปรเจกต์นี้ implement แล้ว ([`src/Defination/Data/Relic/`](../src/Defination/Data/Relic/))

---

## กลุ่ม 1 — เซ็ตธาตุ (2pc = ธาตุ DMG +10%)

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Champion of Streetwise Boxing** | Physical DMG +10% | หลังโจมตีหรือถูกตี → ATK +5% ตลอดการต่อสู้ ซ้อนได้ 5 ชั้น | |
| **Firesmith of Lava-Forging** | Fire DMG +10% | Skill DMG +12%; หลังใช้ Ult → Fire DMG +12% สำหรับการโจมตีครั้งถัดไป | |
| **Hunter of Glacial Forest** | Ice DMG +10% | หลังใช้ Ult → **CD +25% 2 เทิร์น** | |
| **Band of Sizzling Thunder** | Lightning DMG +10% | ใช้ Skill → ATK +20% 1 เทิร์น | |
| **Eagle of Twilight Line** | Wind DMG +10% | หลังใช้ Ult → **advance 25%** | `Eagle_Beaked_Helmet.h` ✅ |
| **Genius of Brilliant Stars** | Quantum DMG +10% | ลงดาเมจ → ignore DEF 10%; ถ้าเป้าอ่อนแอ Quantum ignore เพิ่มอีก 10% | `GeniusBrilliant.h` ✅ |
| **Wastelander of Banditry Desert** | Imaginary DMG +10% | ตีศัตรูติด debuff → CR +10%; ต่อศัตรูที่ **Imprisoned** → CD +20% | |
| **Poet of Mourning Collapse** | Quantum DMG +10% | **SPD −8%**; ก่อนเข้าสู้ ถ้า SPD <110 / <95 → CR +20% / +32% (ผลถึง memosprite ด้วย) | `Poet_Dill.h` ✅ |

---

## กลุ่ม 2 — เซ็ตสแตตดิบ / ยูทิลิตี้

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Musketeer of Wild Wheat** | ATK +12% | SPD +6% และ **BA DMG +10%** | |
| **Passerby of Wandering Cloud** | Outgoing Healing +10% | เริ่มการต่อสู้ → **คืน 1 SP ทันที** | |
| **Knight of Purity Palace** | DEF +15% | เพิ่มเพดานดาเมจที่เกราะของผู้ใส่ดูดซับได้ +20% | `Knight_of_Purity_Palace.h` ✅ |
| **Guard of Wuthering Snow** | รับ DMG ลด 8% | เริ่มเทิร์น ถ้า HP ≤50% → ฟื้น 8% Max HP + คืน 5 Energy | |
| **Longevous Disciple** | Max HP +12% | ถูกตีหรือถูกพวกกิน HP → CR +8% 2 เทิร์น ซ้อน 2 ชั้น | |
| **Messenger Traversing Hackerspace** | SPD +6% | ใช้ Ult กับพวก → **ทีม SPD +12%** 1 เทิร์น (ไม่ stack) | |
| **Self-Enshrouded Recluse** | Shield Effect +10% | Shield Effect ของผู้ใส่ +12%; พวกที่มีเกราะจากผู้ใส่ → **CD +15%** | |

---

## กลุ่ม 3 — เซ็ตสาย Break

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Thief of Shooting Meteor** | Break Effect +16% | **BE +16% เพิ่มอีก**; ทำ Weakness Break → คืน 3 Energy | |
| **Watchmaker, Master of Dream Machinations** | Break Effect +16% | ใช้ Ult กับพวก → **ทีม BE +30%** 2 เทิร์น (ไม่ stack) | |
| **Iron Cavalry Against the Scourge** | Break Effect +16% | BE ≥150% → Break DMG ignore DEF 10%; BE ≥250% → **Super Break** ignore DEF เพิ่มอีก 15% | `Iron_Cavalry.h` ✅ |

---

## กลุ่ม 4 — เซ็ตสาย Crit / DPS

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Scholar Lost in Erudition** | CRIT Rate +8% | **Skill/Ult DMG +20%**; หลังใช้ Ult เพิ่ม Skill ครั้งถัดไปอีก 25% | `Scholar.h` ✅ |
| **The Ashblazing Grand Duke** | **FuA DMG +20%** | ทุกครั้งที่ FuA ลงดาเมจ → ATK +6% ซ้อนสูงสุด 8 ชั้น | `Grand_Duke.h` ✅ |
| **The Wind-Soaring Valorous** | ATK +12% | CR +6%; หลังใช้ FuA → **Ult DMG +30%** 1 เทิร์น | |
| **Wavestrider Captain** | CRIT DMG +16% | เป็นเป้าของ ability พวก → "Help" 1 ชั้น max 2; ใช้ Ult ตอนมี 2 ชั้น → กินทิ้งแล้ว **ATK +48%** 1 เทิร์น | `Wavestrider Captain.h` ✅ |
| **As Navigator Isee Sees It** | ATK +12% | เข้าสู้หรือใช้ Skill → **Skill และ Ult DMG +18%** ซ้อน 3 ชั้น | |
| **Diviner of Distant Reach** | SPD +6% | ก่อนเข้าสู้ ถ้า SPD ≥120 / ≥160 → CR +10% / +18% (โค้ดนี้มีท่อน **Elation +10%** ให้พวกด้วย ❓) | `Diviner of Distant Reach.h` ✅ |

---

## กลุ่ม 5 — เซ็ตสาย Debuff / DoT

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Prisoner in Deep Confinement** | ATK +12% | ทุก **DoT** ที่เป้าติดอยู่ → ignore DEF 6% ต่อชั้น | `Prisoner in Deep Confinement.h` ✅ |
| **Pioneer Diver of Dead Waters** | DMG ต่อศัตรูที่ติด debuff +12% | CR +4%; CD +8% / +12% ต่อศัตรูที่ติด 2 / 3 debuff (ค่าคูณสองถ้าผู้ใส่เป็นคนลง debuff) | |
| **Divine-Querying Master Smith** | Max HP +12% | CD ต่อเป้าที่อยู่ในสถานะ **DEF reduction** +28%; หลังผู้ใส่ลง DEF reduction → ทีมได้ **"Comburent"** 2 เทิร์น | |

---

## กลุ่ม 6 — เซ็ตสาย Support / Buffer

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Sacerdos' Relived Ordeal** | SPD +6% | ใช้ Skill/Ult กับพวก 1 คน → **เป้า CD +18%** 2 เทิร์น ซ้อน 2 ชั้น | `Sacerdos_Relived_Ordeal.h` ✅ |

---

## กลุ่ม 7 — เซ็ตสาย Memosprite (Remembrance)

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Hero of Triumphant Song** | ATK +12% | memo อยู่สนาม → SPD +6%; memo โจมตี → **ผู้ใส่และ memo CD +30%** 2 เทิร์น | `Hero_Wreath.h` ✅ |
| **World-Remaking Deliverer** | CRIT Rate +8% | หลังใช้ BA/Skill ถ้า memo อยู่สนาม → **Max HP ของผู้ใส่และ memo +24%** | |
| **Warrior Goddess of Sun and Thunder** | SPD +6% | ผู้ใส่และ memo ฮีลพวก (ไม่นับตัวเอง) → ได้ **"Gentle Rain"** 2 เทิร์น (1 ครั้ง/เทิร์น) | `Goddess of Sun and Thunder.h` ✅ |

---

## กลุ่ม 8 — เซ็ตสาย Elation (v4.0+)

| เซ็ต | 2-Piece | 4-Piece | โค้ด |
|---|---|---|---|
| **Ever-Glorious Magical Girl** | CRIT DMG +16% | **Elation DMG** ของผู้ใส่และ memo → ignore DEF 10% | `Ever-Glorious Magical Girl.h` ✅ |

---

## สรุปรวม 32 เซ็ต (เรียงตามตัวอักษร)

1. As Navigator Isee Sees It
2. Band of Sizzling Thunder
3. Champion of Streetwise Boxing
4. Divine-Querying Master Smith
5. Diviner of Distant Reach ✅
6. Eagle of Twilight Line ✅
7. Ever-Glorious Magical Girl ✅
8. Firesmith of Lava-Forging
9. Genius of Brilliant Stars ✅
10. Guard of Wuthering Snow
11. Hero of Triumphant Song ✅
12. Hunter of Glacial Forest
13. Iron Cavalry Against the Scourge ✅
14. Knight of Purity Palace ✅
15. Longevous Disciple
16. Messenger Traversing Hackerspace
17. Musketeer of Wild Wheat
18. Passerby of Wandering Cloud
19. Pioneer Diver of Dead Waters
20. Poet of Mourning Collapse ✅
21. Prisoner in Deep Confinement ✅
22. Sacerdos' Relived Ordeal ✅
23. Scholar Lost in Erudition ✅
24. Self-Enshrouded Recluse
25. The Ashblazing Grand Duke ✅
26. The Wind-Soaring Valorous
27. Thief of Shooting Meteor
28. Warrior Goddess of Sun and Thunder ✅
29. Wastelander of Banditry Desert
30. Watchmaker, Master of Dream Machinations
31. Wavestrider Captain ✅
32. World-Remaking Deliverer

**implement แล้ว 13/32**

---

## หมายเหตุเชิงโค้ด

- ไฟล์ [`PairSet.h`](../src/Defination/Data/Relic/PairSet.h) ใช้เก็บ "เซ็ต 2 ชิ้น" แบบทั่วไป
  โดยเลือกผ่าน `enum class PairSetType` ใน [`RelicEnum.h`](../src/Enum/RelicEnum.h):
  `Spd_P, ATK, HP, DEF, DMG, CritRate, CritDam, Fua, BE, HealOut, ERROR`
  → ใช้จำลอง 2-piece ของเซ็ตไหนก็ได้ที่ให้สแตตดิบ โดยไม่ต้องเขียนไฟล์แยกทุกเซ็ต
- ชื่อไฟล์บางอันใช้ชื่อ **ชิ้นส่วนหัว** แทนชื่อเซ็ต (เช่น `Eagle_Beaked_Helmet.h` = Eagle of Twilight Line)
