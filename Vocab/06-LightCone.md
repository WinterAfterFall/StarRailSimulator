# 06 — Light Cone (กรวยแสง)

**Light Cone = อาวุธของ HSR** ให้ 3 อย่าง:
1. **Base HP / Base ATK / Base DEF** (บวกเข้า base stat ของตัวละครก่อนคูณ %)
2. **Passive ability** — ทำงานเฉพาะเมื่อ **Path ตรงกับตัวละคร** เท่านั้น
3. ถ้า Path ไม่ตรง → ได้แค่ base stat ไม่ได้ passive

**Superimposition (S1–S5)** = การซ้อนใบซ้ำ ทำให้ตัวเลขของ passive แรงขึ้น (base stat ไม่เปลี่ยน)
**ตัวเลขในเอกสารนี้ = ค่า S1 ทั้งหมด**

| ระดับ | จำนวนใบ | Base stat สูงสุด (Lv.80) |
|---|---|---|
| 5★ | 1 ใบ = S1 | สูงสุด |
| 4★ | 1 ใบ = S1 | กลาง |
| 3★ | 1 ใบ = S1 | ต่ำ (แต่ S5 ง่ายมาก) |

> โค้ด: [`src/Defination/Data/Lightcone/<Path>/`](../src/Defination/Data/Lightcone/) — แยกโฟลเดอร์ตาม Path
> ตัวแปร `superimpose` ในโค้ด = S1→1, S5→5

---

## 💥 The Destruction

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Thankless Coronation** | CD +36%. ใช้ Ult → ATK +40%; ถ้า Max Energy ≥300 คืน Energy = 10% ของ Max Energy และ ATK +40% อีก 2 เทิร์น |
| **Brighter Than the Sun** | CR +18%. ใช้ BA → Dragon's Call 1 ชั้น 2 เทิร์น (ATK +18%, ERR +6%) ซ้อนได้ 2 ชั้น |
| **Dance at Sunset** | เพิ่ม taunt มาก + CD +36%. ใช้ Ult → Firedance 1 ชั้น (max 2, 2 เทิร์น) แต่ละชั้นเพิ่ม **FuA DMG +36%** |
| **Flame of Blood, Blaze My Path** | Max HP +18%, Incoming Healing +20%. ใช้ Skill/Ult กิน HP 6% Max HP → DMG ครั้งนั้น +30%; ถ้า HP ที่กิน >500 เพิ่มอีก +30% (HP ไม่พอจะเหลือ 1) |
| **I Am As You Behold** | ATK +18%, ERR +10%. ใช้ Ult: ทุก 1 Energy ที่ใช้ → Ult DMG +0.2% (max +72%). เข้าสู้/ใช้ Ult → King's Entertainment 3 เทิร์น: **ทีม CD +24%** |
| **I Shall Be My Own Sword** | CD +20%. พวก (ไม่รวมผู้ใส่) ถูกตี/เสีย HP → Eclipse 1 ชั้น max 3; แต่ละชั้นเพิ่ม DMG การโจมตีถัดไป +14%; ครบ 3 ชั้น ignore DEF 12% (ลบหลังโจมตี) |
| **On the Fall of an Aeon** | ทุกครั้งที่โจมตี ATK +8% (ทั้งเกม max 4 ครั้ง). ทำ Weakness Break → DMG +12% 2 เทิร์น |
| **Something Irreplaceable** | ATK +24%. ฆ่าศัตรูหรือถูกตี → ฟื้น HP = 8% ATK + DMG +24% จนจบเทิร์นถัดไป (1 ครั้ง/เทิร์น ไม่ stack) |
| **The Unreachable Side** | CR +18%, Max HP +18%. ถูกตีหรือกิน HP ตัวเอง → DMG +24% (หายเมื่อโจมตี) |
| **Thus Burns the Dawn** | base SPD +12. DMG ignore DEF 18%. ใช้ Ult → Blazing Sun (ลบตอนเริ่มเทิร์น): DMG +60% |
| **Whereabouts Should Dreams Rest** | BE +60%. ลง Break DMG → Routed 2 เทิร์น: รับ Break DMG จากผู้ใส่ +24%, SPD −20% |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Secret Vow** | DMG +20%; ตีศัตรูที่ HP% ≥ ของผู้ใส่ เพิ่มอีก 20% |
| **A Trail of Bygone Blood** | CR +12%. Skill DMG และ Ult DMG +24% |
| **Flames Afar** | เสีย HP สะสมใน 1 การโจมตี >25% Max HP (หรือกิน HP ตัวเอง >25%) → ฮีล 15% Max HP + DMG +25% 2 เทิร์น |
| **Indelible Promise** | BE +28%. ใช้ Ult → CR +15% 2 เทิร์น |
| **Ninja Record: Sound Hunt** | Max HP +12%. เสียหรือฟื้น HP → CD +18% 2 เทิร์น (1 ครั้ง/เทิร์น) |
| **Nowhere to Run** | ATK +24%. ฆ่าศัตรู → ฟื้น HP = 12% ATK |
| **The Moles Welcome You** | ใช้ BA/Skill/Ult โจมตี → Mischievous 1 ชั้น; แต่ละชั้น ATK +12% |
| **Under the Blue Sky** | ATK +16%. ฆ่าศัตรู → CR +12% 3 เทิร์น |
| **Woof! Walk Time!** | ATK +10%; DMG ต่อศัตรูที่ติด Burn/Bleed +16% (รวม DoT) |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Collapsing Sky** | BA และ Skill DMG +20% |
| **Mutual Demise** | HP ปัจจุบัน <80% → CR +12% |
| **Shattered Home** | DMG ต่อศัตรูที่ HP >50% +20% |

---

## 🎯 The Hunt

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Baptism of Pure Thought** | CD +20%. ทุก debuff บนเป้า → CD ต่อเป้านั้น +8% max 3 ชั้น. ใช้ Ult ตี → Disputation 2 เทิร์น: DMG +36% + FuA ignore DEF 24% |
| **Cruising in the Stellar Sea** | CR +8%; ต่อศัตรู HP ≤50% เพิ่มอีก 8%. ฆ่าศัตรู → ATK +20% 2 เทิร์น |
| **I Venture Forth to Hunt** | CR +15%. ยิง FuA → Luminflux 1 ชั้น max 2; แต่ละชั้นทำให้ **Ult** ignore DEF 27%. จบเทิร์นลบ 1 ชั้น |
| **In the Night** | CR +18%. ทุก 10 SPD ที่เกิน 100 → BA/Skill DMG +6% และ Ult CD +12%, max 6 ชั้น |
| **Sailing Towards A Second Life** | BE +60%. Break DMG ignore DEF 20%. BE ในสนาม ≥150% → SPD +12% |
| **Sleep Like the Dead** | CD +30%. ถ้า BA/Skill ไม่คริต → CR +36% 1 เทิร์น (ทริกเกอร์ได้ทุก 3 เทิร์น) |
| **The Finale of a Lie** | CR +18%. เข้าสู้ หรือทุก 4 ครั้งของ FuA → Umbra Devourer 3 เทิร์น: ATK +40% + ศัตรูทุกตัวรับ DMG +20% (ไม่ stack) |
| **The Hell Where Ideals Burn** | CR +16%. เข้าสู้ ถ้าเพดาน SP ของทีม ≥6 → ATK +40%. ใช้ Skill → ATK +10% max 4 ชั้น |
| **Worrisome, Blissful** | CR +18%, FuA DMG +30%. ยิง FuA → Tame บนเป้า max 2 ชั้น; พวกที่ตีเป้าติด Tame ได้ CD +12% ต่อชั้น |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Final Victor** | ATK +12%. คริตแล้วได้ Good Fortune max 4 ชั้น (CD +8%/ชั้น) ลบตอนจบเทิร์น |
| **Only Silence Remains** | ATK +16%; ถ้าศัตรูในสนาม ≤2 ตัว → CR +12% |
| **Race to the Horizon** | ATK +12%. หลังใช้ FuA → CD +3% 2 เทิร์น ซ้อนได้ 10 ชั้น *(v4.5)* |
| **Return to Darkness** | CR +12%. หลังคริต มีโอกาส fixed 16% ลบบัฟศัตรู 1 อัน (1 ครั้ง/การโจมตี) |
| **River Flows in Spring** | เข้าสู้ SPD +8%, DMG +12%; หายเมื่อถูกตี กลับมาหลังจบเทิร์นถัดไป |
| **See You at the End** | CD +24%. Skill DMG และ FuA DMG +24% |
| **Shadowed by Night** | BE +28%. เข้าสู้/หลังลง Break DMG → SPD +8% 2 เทิร์น (1 ครั้ง/เทิร์น) |
| **Subscribe for More!** | BA และ Skill DMG +24%; ถ้า Energy เต็ม เพิ่มอีก 24% |
| **Swordplay** | ตีเป้าเดิมซ้ำ → DMG +8% ต่อครั้ง max 5 ชั้น; เปลี่ยนเป้าแล้วรีเซ็ต |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Adversarial** | ฆ่าศัตรู → SPD +10% 2 เทิร์น |
| **Arrows** | เข้าสู้ CR +12% 3 เทิร์น |
| **Darting Arrow** | ฆ่าศัตรู → ATK +24% 3 เทิร์น |

---

## 📚 The Erudition

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Star That Lights the Night** | ignore DEF 32%. ใช้ **Assist Skill** → คืน 6 Energy + Sail 2 เทิร์น max 3 ชั้น (Assist Skill DMG +20%/ชั้น); ครบ 3 ชั้น แต่ละชั้นเพิ่ม Ult DMG +20% |
| **An Instant Before A Gaze** | CD +36%. ใช้ Ult → Ult DMG เพิ่มตาม Max Energy 0.36% ต่อแต้ม (นับสูงสุด 180 แต้ม) |
| **Before Dawn** | CD +36%, Skill/Ult DMG +18%. หลัง Skill/Ult → Somnus Corpus; FuA ครั้งถัดไปกิน Somnus Corpus แล้ว DMG +48% |
| **Eternal Calculus** | ATK +8%. หลังโจมตี ทุกศัตรูที่โดน → ATK +4% max 5 ชั้น (คงถึงการโจมตีครั้งถัดไป); ถ้าโดน ≥3 ตัว → SPD +8% 1 เทิร์น |
| **Flickering Stars** | CR +18%. เมื่อพวกใช้ SP รวม ≥4 ใน 1 เทิร์น → Radiant Crown 3 เทิร์น: **ทีม ignore DEF 20%** + Skill DMG ผู้ใส่ +72% (ไม่ stack) |
| **Into the Unreachable Veil** | CR +12%. ใช้ Ult → Skill/Ult DMG +60% 3 เทิร์น; ถ้า Ult นั้นใช้ ≥140 Energy คืน 1 SP |
| **Life Should Be Cast to Flames** | เริ่มเทิร์นคืน 10 Energy. ถ้าเป้ามี Weakness ที่ผู้ใส่ฝัง → DMG ต่อเป้านั้น +60%; ตีศัตรู → DEF ศัตรู −12% 2 เทิร์น (ไม่ stack) |
| **Night on the Milky Way** | ทุกศัตรูในสนาม → ATK +9% max 5 ชั้น; ศัตรูถูก Weakness Break → DMG +30% 1 เทิร์น |
| **Ninjutsu Inscription: Dazzling Evilbreaker** | BE +60%. เข้าสู้คืน 30 Energy. ใช้ Ult → Raiton; หลังใช้ BA 2 ครั้ง → advance 50% แล้วลบ Raiton (ใช้ Ult รีเซ็ต Raiton) |
| **Yet Hope Is Priceless** | CR +16%. ทุก 20% CD ที่เกิน 120% → FuA DMG +12% max 4 ชั้น; เข้าสู้/หลัง BA → Ult หรือ FuA ignore DEF 20% 2 เทิร์น |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Dream Scented in Wheat** | CR +12%. Ult DMG และ FuA DMG +24% |
| **After the Charmony Fall** | BE +28%. ใช้ Ult → SPD +8% 2 เทิร์น |
| **Geniuses' Repose** | ATK +16%. ฆ่าศัตรู → CD +24% 3 เทิร์น |
| **Make the World Clamor** | เข้าสู้คืน 20 Energy + Ult DMG +32% |
| **The Birth of the Self** | FuA DMG +24%; ถ้าเป้า HP ≤50% เพิ่มอีก 24% |
| **The Day The Cosmos Fell** | ATK +16%. โจมตีแล้วมีศัตรู ≥2 ตัวที่ตรง Weakness → CD +20% 2 เทิร์น |
| **The Great Cosmic Enterprise** | ATK +8%. ทุก 1 Weakness Type ที่เป้ามี → DMG ต่อเป้านั้น +4% (นับสูงสุด 7 ชนิด) |
| **The Seriousness of Breakfast** | DMG +12%; ทุกศัตรูที่ฆ่าได้ ATK +4% max 3 ชั้น |
| **Today Is Another Peaceful Day** | เข้าสู้ DMG เพิ่มตาม Max Energy 0.20% ต่อแต้ม (นับสูงสุด 160) |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Data Bank** | Ult DMG +28% |
| **Passkey** | หลังใช้ Skill คืน 8 Energy (1 ครั้ง/เทิร์น) |
| **Sagacity** | ใช้ Ult → ATK +24% 2 เทิร์น |

---

## 🎵 The Harmony

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Grounded Ascent** | ใช้ Skill/Ult กับพวก 1 คน → ผู้ใส่คืน 6 Energy + เป้าได้ Hymn 3 เทิร์น max 3 ชั้น (DMG +15%/ชั้น). ทุก 2 ครั้งที่ใช้ Skill/Ult กับพวก → คืน 1 SP |
| **But the Battle Isn't Over** | ERR +10%; ใช้ Ult กับพวกคืน 1 SP (ทริกเกอร์ทุก 2 ครั้ง). ใช้ Skill → พวกคนถัดไปที่ลงมือ (ไม่รวมผู้ใส่) DMG +30% 1 เทิร์น |
| **Earthly Escapade** | CD +32%. เข้าสู้ได้ Mask 3 เทิร์น: พวกได้ CR +10%, CD +28%. ทุก 1 SP ที่ผู้ใส่คืน (รวมที่ล้นเพดาน) → Radiant Flame 1 ชั้น; ครบ 4 ชั้นแลก Mask 4 เทิร์น |
| **Epoch Etched in Golden Blood** | ATK +64%. ใช้ Ult โจมตีคืน 1 SP. ใช้ Skill กับพวก 1 คน → **Skill DMG ของเป้า +54%** 3 เทิร์น |
| **Flowing Nightglow** | ทุกครั้งที่พวกโจมตี → Cantillation 1 ชั้น (ERR +3%/ชั้น max 5). ใช้ Ult ลบ Cantillation แล้วได้ Cadenza 1 เทิร์น: ATK +48%, **ทีม DMG +24%** |
| **If Time Were a Flower** | CD +36%. หลังยิง FuA → คืน 12 Energy + Presage 2 เทิร์น: **ทีม CD +48%**. เข้าสู้คืน 21 Energy + Presage 2 เทิร์น |
| **Past Self in Mirror** | BE +60%. ใช้ Ult → ทีม DMG +24% 3 เทิร์น; ถ้า BE ≥150% คืน 1 SP. เริ่มแต่ละเวฟคืน 10 Energy ให้ทุกคน (ไม่ stack) |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Carve the Moon, Weave the Clouds** | เริ่มสู้และทุกครั้งที่เริ่มเทิร์น สุ่ม 1 อย่าง: ทีม ATK +10% / ทีม CD +12% / ทีม ERR +6% |
| **Dance! Dance! Dance!** | ใช้ Ult → advance ทีมทั้งหมด 16% |
| **Dreamville Adventure** | หลังใช้ ability ชนิดหนึ่ง (BA/Skill/Ult) → ทีมได้ Childishness: DMG ของ ability ชนิดเดียวกัน +12% |
| **For Tomorrow's Journey** | ATK +16%. ใช้ Ult → DMG +18% 1 เทิร์น |
| **In Pursuit of the Wind** | เข้าสู้ → **ทีม Break DMG +16%** (ไม่ stack) |
| **Memories of the Past** | BE +28%. โจมตีคืน 4 Energy เพิ่ม (1 ครั้ง/เทิร์น) |
| **Past and Future** | ใช้ Skill → พวกคนถัดไป (ไม่รวมผู้ใส่) DMG +16% 1 เทิร์น |
| **Planetary Rendezvous** | เข้าสู้ ถ้ามีพวกที่ธาตุเดียวกับผู้ใส่ → DMG +12% |
| **Poised to Bloom** | ATK +16%. เข้าสู้ ถ้ามีพวก **Path เดียวกัน ≥2 คน** → คนเหล่านั้น CD +16% (ไม่ stack) |
| **The Forever Victual** | ATK +16%. ใช้ Skill → ATK +8% max 3 ชั้น |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Chorus** | เข้าสู้ ทีม ATK +8% (ไม่ stack) |
| **Mediation** | เข้าสู้ ทีม **SPD +12 แต้ม** (flat) 1 เทิร์น |
| **Meshing Cogs** | โจมตีหรือถูกตี → คืน 4 Energy (1 ครั้ง/เทิร์น) |

---

## 🕳️ The Nihility

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Along the Passing Shore** | CD +36%. ตีศัตรู → ติด Mirage Fizzle 1 เทิร์น (1 ครั้ง/เป้า/การโจมตี). DMG ต่อเป้าที่ติด +24% และ **Ult DMG เพิ่มอีก +24%** |
| **In the Name of the World** | DMG ต่อศัตรูที่ติด debuff +24%. ใช้ Skill → EHR ของการโจมตีนั้น +18% และ ATK +24% |
| **Incessant Rain** | EHR +24%. ตีศัตรูที่ติด debuff ≥3 → CR +12%. หลัง BA/Skill/Ult โอกาสฐาน 100% ฝัง Aether Code บนเป้าสุ่มที่ยังไม่มี → รับ DMG +12% 1 เทิร์น |
| **Lies Dance on the Breeze** | SPD +18%. หลังโจมตี โอกาสฐาน 120% ลง **Bamboozle** ทุกตัว (DEF −16% 2 เทิร์น). ถ้า SPD ≥170 ลง **Theft** ด้วย (DEF −8% 2 เทิร์น) — ลงซ้ำนับเฉพาะครั้งล่าสุด |
| **Long Road Leads Home** | BE +60%. ศัตรูถูก Break → โอกาสฐาน 100% ติด **Charring**: รับ Break DMG +18% 2 เทิร์น ซ้อน 2 ชั้น |
| **Never Forget Her Flame** | BE +60%. เข้าสู้ → Break DMG ของผู้ใส่ + เพื่อนที่ trigger การสู้ +32% (ถ้าไม่มี ให้คนที่ BE สูงสุด). ฝัง Weakness → คืน 1 SP (1 ครั้ง รีเซ็ตตอนใช้ Ult) |
| **Patience Is All You Need** | DMG +24%. หลังทุกการโจมตี SPD +4.8% max 3 ชั้น. ตีศัตรูที่ยังไม่ติด **Erode** → โอกาสฐาน 100% ลง Erode (นับเป็น Shock, Lightning DoT = 60% ATK 1 เทิร์น) |
| **Reforged in Hellfire** | Max HP +30%. เริ่มเทิร์นคืน 20 Energy (1 ครั้ง/เวฟ). หลังใช้ Skill โจมตี → เป้าติด **Purgatory** 2 เทิร์น: รับ CRIT DMG +30% และจากผู้ใส่เพิ่มอีก +30% |
| **Reforged Remembrance** | EHR +40%. ตีศัตรูที่ติด Wind Shear/Burn/Shock/Bleed → ได้ **Prophet** ชนิดละ 1 ชั้น max 4. แต่ละชั้น ATK +5% + DoT ignore DEF 7.2% |
| **Solitary Healing** | BE +20%. ใช้ Ult → DoT DMG +24% 2 เทิร์น. เป้าที่ติด DoT ของผู้ใส่ตาย → คืน 4 Energy |
| **Those Many Springs** | EHR +60%. หลัง BA/Skill/Ult โจมตี โอกาสฐาน 60% ลง **Unarmored** (รับ DMG +10% 2 เทิร์น); ถ้าเป้าติด DoT ของผู้ใส่ โอกาส 60% อัปเป็น **Cornered** (รับ DMG +14%) |
| **Why Does the Ocean Sing** | EHR +40%. ลง debuff → โอกาสฐาน 80% ติด **Enthrallment** 3 เทิร์น: ทุก debuff ที่ผู้ใส่ลงบนเป้าเพิ่ม DoT ที่เป้ารับ +5% max 6 ชั้น. ถูกพวกตี → attacker SPD +10% 3 เทิร์น |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Before the Tutorial Mission Starts** | EHR +20%. ตีศัตรูที่ DEF ถูกลด → คืน 4 Energy |
| **Boundless Choreo** | CR +8%. ตีศัตรูที่ถูก Slow หรือ DEF ถูกลด → CD +24% |
| **Eyes of the Prey** | EHR +20% และ **DoT +24%** |
| **Fermata** | BE +16%; DMG ต่อศัตรูที่ติด Shock/Wind Shear +16% (รวม DoT) |
| **Good Night and Sleep Well** | ทุก debuff บนเป้า → DMG +12% max 3 ชั้น (รวม DoT) |
| **Holiday Thermae Escapade** | DMG +16%. หลังโจมตี โอกาสฐาน 100% ลง Vulnerability: เป้ารับ DMG +10% 2 เทิร์น |
| **It's Showtime** | ลง debuff → Trick 1 ชั้น (DMG +6%/ชั้น max 3, 1 เทิร์น). ถ้า EHR ≥80% → ATK +20% |
| **Resolution Shines As Pearls of Sweat** | ตีศัตรูที่ยังไม่ติด Ensnare → โอกาสฐาน 60% ลง Ensnare: DEF −12% 1 เทิร์น |
| **We Will Meet Again** | หลัง BA/Skill → Additional DMG = 48% ATK ใส่ศัตรูสุ่มที่โดนตี |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Hidden Shadow** | หลังใช้ Skill, BA ครั้งถัดไปเพิ่ม Additional DMG = 60% ATK |
| **Loop** | DMG ต่อศัตรูที่ถูก Slow +24% |
| **Void** | เข้าสู้ EHR +20% 3 เทิร์น |

---

## 🛡️ The Preservation

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Inherently Unjust Destiny** | DEF +40%. ให้เกราะพวก → CD +40% 2 เทิร์น. FuA โดนศัตรู → โอกาสฐาน 100% เพิ่ม DMG ที่เป้ารับ +10% 2 เทิร์น |
| **Moment of Victory** | DEF +24%, EHR +24%. เพิ่ม taunt. ถูกตี → DEF เพิ่มอีก 24% จนจบเทิร์นของผู้ใส่ |
| **She Already Shut Her Eyes** | Max HP +24%, ERR +12%. HP ผู้ใส่ลด → **ทีม DMG +9%** 2 เทิร์น. เริ่มทุกเวฟ ฮีลทีม 80% ของ HP ที่หายไป |
| **Texture of Memories** | Effect RES +8%. ถูกตีตอนไม่มีเกราะ → ได้เกราะ 16% Max HP 2 เทิร์น (ทุก 3 เทิร์น). ถ้ามีเกราะตอนถูกตี → รับ DMG ลด 12% |
| **Though Worlds Apart** | ATK +64%. ใช้ Ult → ฮีลทีม 10% ATK + ฮีลคน HP ต่ำสุดอีก 10% ATK + ทีมได้ **Redoubt** 3 เทิร์น: DMG +24% (เพิ่มอีก +12% ถ้าเป้ามี summon) |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Concert for Two** | DEF +16%. ทุกตัวในสนามที่มีเกราะ → DMG ผู้ใส่ +4% |
| **Day One of My New Life** | DEF +16%. เข้าสู้ → ทีม DMG RES +8% (ไม่ stack) |
| **Destiny's Threads Forewoven** | Effect RES +12%. ทุก 100 DEF → DMG +0.8% (เพดาน +32%) |
| **Journey, Forever Peaceful** | Shield Effect ที่ผู้ใส่สร้าง +12%. พวกที่มีเกราะ → DMG +12% |
| **Landau's Choice** | เพิ่ม taunt, รับ DMG ลด 16% |
| **This Is Me!** | DEF +16%. Ult DMG เพิ่มขึ้น 60% ของ DEF ผู้ใส่ (1 ครั้ง/เป้า) |
| **Trend of the Universal Market** | DEF +16%. ถูกตี → โอกาสฐาน 100% ลง Burn: DoT = 40% DEF 2 เทิร์น |
| **We Are Wildfire** | เริ่มสู้ ทีมรับ DMG ลด 8% 5 เทิร์น + ฮีลทีม 30% ของ HP ที่หายไป |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Amber** | DEF +16%; ถ้า HP <50% เพิ่มอีก 16% |
| **Defense** | ใช้ Ult ฟื้น HP 18% Max HP |
| **Pioneering** | ทำ Weakness Break → ฟื้น HP 12% Max HP |

---

## 💚 The Abundance

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Echoes of the Coffin** | ATK +24%. หลังโจมตี ทุกศัตรูที่ต่างกันที่โดน → คืน 3 Energy (max 3 ครั้ง/การโจมตี). หลัง Ult ทีมได้ SPD +12 (flat) 1 เทิร์น |
| **Night of Fright** | ERR +12%. พวกใช้ Ult → ฮีลคนที่ HP% ต่ำสุด = 10% Max HP ของคนนั้น. ฮีลพวก → เป้า ATK +2.4% max 5 ชั้น 2 เทิร์น |
| **Scent Alone Stays True** | BE +60%. ใช้ Ult โจมตี → เป้าติด **Woefree** 2 เทิร์น: รับ DMG +10% (เพิ่มอีก +8% ถ้า BE ผู้ใส่ ≥150%) |
| **Time Waits for No One** | Max HP +18%, Outgoing Healing +12%. ฮีลพวกแล้วบันทึกค่าฮีล; เมื่อพวกโจมตี → ศัตรูสุ่มรับ Additional DMG = 36% ของค่าที่บันทึก (ธาตุเดียวกับผู้ใส่ ไม่กินบัฟอื่น 1 ครั้ง/เทิร์น) |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Dream's Montage** | SPD +8%. ตีศัตรูที่ Weakness Broken → คืน 3 Energy (max 2 ครั้ง/เทิร์น) |
| **Hey, Over Here** | Max HP +8%. ใช้ Skill → Outgoing Healing +16% 2 เทิร์น |
| **Perfect Timing** | Effect RES +16%; Outgoing Healing เพิ่ม = 33% ของ Effect RES (เพดาน +15%) |
| **Post-Op Conversation** | ERR +8%, Outgoing Healing ตอนใช้ Ult +12% |
| **Quid Pro Quo** | เริ่มเทิร์น คืน 8 Energy ให้พวกสุ่ม 1 คน (ไม่รวมผู้ใส่) ที่ Energy <50% |
| **Shared Feeling** | Outgoing Healing +10%. ใช้ Skill คืน 2 Energy ให้ทุกคน |
| **Unto Tomorrow's Morrow** | Outgoing Healing +12%. พวกที่ HP% ≥50% → DMG +12% |
| **Warmth Shortens Cold Nights** | Max HP +16%. ใช้ BA/Skill → ฮีลทีม 2% Max HP ของแต่ละคน |
| **What Is Real?** | BE +24%. หลัง BA → ฟื้น HP ตัวเอง 2% Max HP + 800 |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Cornucopia** | ใช้ Skill/Ult → Outgoing Healing +12% |
| **Fine Fruit** | เริ่มสู้คืน 6 Energy ให้ทุกคน |
| **Multiplication** | หลัง BA → advance การกระทำถัดไป 12% |

---

## 🌸 The Remembrance

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Long May Rainbows Adorn the Sky** | SPD +18%. ใช้ BA/Skill/Ult กิน HP พวกทุกคน 1% ของ HP ปัจจุบัน; หลัง memosprite โจมตีครั้งถัดไป → Additional DMG = **250% ของ HP ที่กินรวม** แล้วรีเซ็ต. memo ใช้ Skill → ศัตรูรับ DMG +18% 2 เทิร์น (ไม่ stack) |
| **Make Farewells More Beautiful** | Max HP +30%. ผู้ใส่/memo เสีย HP ในเทิร์นตัวเอง → **Death Flower**: ผู้ใส่และ memo ignore DEF 30% 2 เทิร์น. memo หายไป → advance ผู้ใส่ 12% (1 ครั้ง รีเซ็ตตอนใช้ Ult) |
| **Memory's Curtain Never Falls** | SPD +6%. หลังใช้ Skill → ทีม DMG +8% 3 เทิร์น |
| **Rise and Sing** | Max HP +30%. ใช้ Ult → คืน 1 SP ให้ทีม. เข้าสู้ advance 30% + **New Melody** 2 เทิร์น: ทีม SPD +20% *(v4.5)* |
| **This Love, Forever** | SPD +18%. memo ใช้ Memosprite Skill กับพวก → **Blank** (ศัตรูรับ DMG +10%); ใช้กับศัตรู → **Verse** (ทีม CD +16%); ถ้ามีทั้งคู่ → ผลของทั้งคู่ +60% |
| **Time Woven into Gold** | base SPD +12. หลังผู้ใส่และ memo โจมตี → **Brocade** 1 ชั้น (CD ผู้ใส่+memo +9%/ชั้น max 6); ครบ max แต่ละชั้นเพิ่ม BA DMG +9% |
| **To Evernight's Stars** | Max HP +30%. memo ใช้ ability → **Noctis**: memo ของทีมทุกตัว ignore DEF 20% + ผู้ใส่และ memo DMG +30%. memo หาย → คืน 8 Energy (ไม่ stack) |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Fly Into a Pink Tomorrow** | CD +12%. ถ้า Trailblazer (Remembrance) ใส่ → ทีม DMG +8% และ Enhanced BA *"Together, We Script Tomorrow!"* DMG +60% |
| **Geniuses' Greetings** | ATK +16%. หลัง Ult → ผู้ใส่และ memo BA DMG +20% 3 เทิร์น |
| **Sweat Now, Cry Less** | CR +12%. memo อยู่สนาม → ผู้ใส่และ memo DMG +24% |
| **The Flower Remembers** | CD +24%. CD ของ memo +24% |
| **The Story's Next Page** | Max HP +16%. หลัง memo โจมตี → Outgoing Healing ของผู้ใส่และ memo +12% 1 เทิร์น |
| **Victory in a Blink** | CD +12%. memo ใช้ ability กับพวก → ทีม DMG +8% 3 เทิร์น |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Reminiscence** ❓ | เริ่มเทิร์นของ memo → Commemoration 1 ชั้น (DMG +12%/ชั้น max 4) |
| **Shadowburn** ❓ | เรียก memo ครั้งแรก → คืน 1 SP + 20 Energy |

---

## 🎭 The Elation (Path ใหม่ v4.0)

### 5★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Dazzled by a Flowery World** | CD +48%. ขณะผู้ใส่อยู่สนาม ทุกตัว Elation ในทีม → **เพดาน SP +1** (max +3). ทุก 1 SP ที่ผู้ใส่ใช้ → Elation DMG ignore DEF 5% max 4 ชั้น. ถ้าใช้ SP ≥4 ในเทิร์นเดียว → **Stream Promo**: ทีม Elation +20% (ไม่ stack) |
| **Elation Brimming With Blessings** | ATK +20%. ใช้ Skill/Ult กับพวก 1 คน → เป้า **Elation +12%** 2 เทิร์น |
| **Summer Rides the Surf** | CR +18%. ใช้ Elation Skill → **Updraft** (SPD +20%); ถ้า Elation Skill ต่างจากครั้งก่อน → **Uptrend** (Elation +36%). คืน 1 SP ตอนเริ่มเวฟ หรือหลังใช้ Elation Skill 3 ครั้ง *(v4.5)* |
| **Until the Flowers Bloom Again** | CD +60%, ERR +10%. ถ้า Max Energy >120 ทุก 10 แต้มที่เกิน → ERR +0.3% (นับสูงสุด 360 แต้ม). ใช้ Elation Skill → ศัตรูรับ DMG +15% 2 เทิร์น (ไม่ stack) |
| **Welcome to the Cosmic City** | SPD +18%, Elation DMG ignore DEF 20%. ใช้ Ult ใส่ตัวเอง → **+20 Punchline** (1 ครั้ง รีเซ็ตหลังใช้ BA 3 ครั้ง) |
| **When She Decided to See** | SPD +18%. เข้าสู้/ใช้ Ult กับพวก → **Great Fortune** 3 เทิร์น: ทีม CR +10%, CD +30%, ผู้ใส่ ERR +12%. เริ่มแต่ละเวฟคืน 15 Energy |

### 4★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **A Little Getaway** | Elation +20%. ใช้ Elation Skill → ignore DEF 8% *(v4.5)* |
| **Mushy Shroomy's Adventures** | Elation +12%. ใช้ Elation Skill → ศัตรูรับ Elation DMG +6% 2 เทิร์น ❓ |
| **Today's Good Luck** | CR +12%. ใช้ Elation Skill → Elation +12% ซ้อนได้ 2 ชั้น |
| **Tomorrow, Together** | CD +12%. ใช้ Ult → ทีม Elation +8% 1 เทิร์น |

### 3★
| ชื่อ | ความสามารถ (S1) |
|---|---|
| **Lingering Tear** | Punchline ≥10 → CD +20% |
| **Sneering** ❓ | เปิด Aha Instant → Elation +32% จนกว่า Aha Instant จะจบ |

---

## Signature Light Cone — ใครคู่กับใบไหน

| ตัวละคร | Light Cone |
|---|---|
| Acheron | Along the Passing Shore |
| Aglaea | Time Woven into Gold |
| Anaxa | Life Should Be Cast to Flames |
| Argenti | An Instant Before A Gaze |
| Aventurine | Inherently Unjust Destiny |
| Aventurine • Waveflair | Summer Rides the Surf |
| Bailu | Time Waits for No One |
| Black Swan | Reforged Remembrance |
| Blade | The Unreachable Side |
| Boothill | Sailing Towards A Second Life |
| Bronya | But the Battle Isn't Over ❓ |
| Castorice | Long May Rainbows Adorn the Sky |
| Cerydra | Epoch Etched in Golden Blood |
| Cipher | Lies Dance on the Breeze |
| Clara | Something Irreplaceable |
| Dan Heng • Imbibitor Lunae | Brighter Than the Sun |
| Dan Heng • Permansor Terrae | Though Worlds Apart |
| Dr. Ratio | Baptism of Pure Thought |
| Evernight | To Evernight's Stars |
| Feixiao | I Venture Forth to Hunt |
| Firefly | Whereabouts Should Dreams Rest |
| Fu Xuan | She Already Shut Her Eyes |
| Fugue | Long Road Leads Home ❓ / Never Forget Her Flame ❓ |
| Gepard | Texture of Memories |
| Gilgamesh | I Am As You Behold |
| Himeko • Nova | A Star That Lights the Night |
| Huohuo | Night of Fright |
| Hyacine | This Love, Forever |
| Hysilens | Why Does the Ocean Sing |
| Jade | Yet Hope Is Priceless |
| Jiaoqiu | Those Many Springs |
| Jing Yuan | Before Dawn |
| Jingliu | I Shall Be My Own Sword |
| Kafka | Patience Is All You Need |
| Lingsha | Scent Alone Stays True |
| Luocha | Echoes of the Coffin |
| Mortenax Blade | Reforged in Hellfire |
| Mydei | Flame of Blood, Blaze My Path |
| Phainon | Thus Burns the Dawn |
| Rappa | Ninjutsu Inscription: Dazzling Evilbreaker |
| Rin Tohsaka | Flickering Stars |
| Robin | Flowing Nightglow |
| Robin • Summeretto | Rise and Sing |
| Ruan Mei | Past Self in Mirror |
| Saber | A Thankless Coronation |
| Seele | In the Night |
| Silver Wolf | Incessant Rain |
| Sparkle | Earthly Escapade |
| Sparxie | Dazzled by a Flowery World |
| Sunday | A Grounded Ascent |
| The Herta | Eternal Calculus |
| Topaz & Numby | Worrisome, Blissful |
| Tribbie | If Time Were a Flower |
| Welt | In the Name of the World |
| Yao Guang | When She Decided to See |
| Yunli | Dance at Sunset |

---

## Light Cone ที่ implement แล้วในโปรเจกต์นี้

ดูโฟลเดอร์ [`src/Defination/Data/Lightcone/`](../src/Defination/Data/Lightcone/) — ชื่อไฟล์บางอันย่อ/สะกดต่าง:

| ไฟล์โค้ด | Light Cone จริง |
|---|---|
| `Destruction/BP2.h`, `Nihility/BP2.h` | Light Cone จาก Battle Pass |
| `Destruction/HertaShop.h`, `Nihility/HertaShop.h` | Light Cone จากร้าน Herta |
| `Nihility/GNSW.h` | Good Night and Sleep Well |
| `Harmony/DDD.h` | Dance! Dance! Dance! |
| `Erudition/GreatCosmic.h` | The Great Cosmic Enterprise |
| `Erudition/Calculus.h` | Eternal Calculus |
| `Remembrance/Hyacnine_LC.h` | This Love, Forever (สะกดผิด Hyacine) |
| `Remembrance/SweatNowCryLess.h` | Sweat Now, Cry Less |
| `Remembrance/Victory_In_Blink.h` | Victory in a Blink |
| `Destruction/Secret_Vow.h` / `Secret_Vow_Nobuff.h` | A Secret Vow (มีเวอร์ชันปิดบัฟไว้เทียบ) |
| `Nihility/ShowTime.h` | It's Showtime |
| `Elation/Today's Good Luck.h` | Today's Good Luck |
