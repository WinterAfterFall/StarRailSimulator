# `src/Defination/Data/Planar/`

15 ไฟล์ = 15 เซ็ต + `All_Planar.h` ที่ `#include` ทุกตัว · อยู่ใน `namespace Planar` · อ่าน `../README.md` (กฎกลางของ `Data/`) และ `../Relic/README.md` ก่อน เพราะโครงเหมือนกันเกือบทั้งหมด

## ต่างจาก Relic ยังไง

**Planar มีโบนัสเซ็ตเดียว (2 ชิ้น) ไม่มี 4 ชิ้น** — เอฟเฟกต์เดียวจบ (ดู `docs/hsr-system-reference.md` 5.1) · แต่เอฟเฟกต์นั้นมักมี 2 ท่อน: สแตตพื้นฐาน + ส่วนที่มีเงื่อนไข · โค้ดแยกสองท่อนนี้ด้วย **list คนละตัว**:

| ท่อน | list ที่ใช้ | ตัวอย่าง |
|---|---|---|
| สแตตพื้นฐาน | `Reset_List` | `Talia` BE +16 |
| ส่วนมีเงื่อนไข | `WhenOnField_List` | `Talia` BE +20 เพิ่ม |

ทั้งสอง list ให้ผลถาวรเหมือนกัน การแยกจึงเป็นเรื่องของการอ่านโค้ด ไม่ใช่พฤติกรรม

## แบบแผนที่เห็นซ้ำ

**1. เงื่อนไขส่วนใหญ่ถูกตัดทิ้ง** เหมือนฝั่ง relic — `Talia` ไม่เช็ค SPD, `Kalpagni_Lantern` ไม่เช็ค Fire weakness, `Rutilant` / `Inert` ไม่เช็ค CR, `Broken_Keel` ไม่เช็ค Effect RES, `Revelry` ไม่เช็ค ATK (ให้ชั้นบน +24 เสมอ), `SpaceSealing` รวมเป็น ATK +24 ก้อนเดียว · ใส่ค่าเต็มเพราะ build ที่ซิมใช้เข้าเงื่อนไขอยู่แล้ว (ดู `../Character/Nihility/Pela.md`)

**2. เซ็ตที่ต้องรับตัวเลือกจากข้างนอกเป็น factory** — `GiantTree(bool)` และ `FirmanentFrontline(bool)` คืน lambda คนละตัวตามค่า `bool` แบบเดียวกับ `Relic::DivinerOfDistant(bool)` · **ทั้งสามตัวเขียนสองสาขาแบบ copy ทั้งก้อน** ต่างกันแค่ตัวเลขเดียว ซึ่งเป็นหนี้ที่ควรยุบเป็นตัวแปร

**3. เซ็ตที่ผลตกไปที่คนอื่น** — `Lushaka` บัฟ `charUnit[1]` (เพื่อนช่องแรก) ไม่ใช่ตัวเอง · `Broken_Keel` บัฟทั้งทีมด้วย `buffAllAlly`

**4. เซ็ตที่ต้องคำนวณใหม่ตลอดเกมใช้สำนวน delta + `buffNote`** — `Arcadia` เป็นตัวเดียวในกลุ่มนี้ (ดู `../Character/Abundance/Gallagher.md` หัวข้อรากฐาน ข้อ 2)

## ตารางสรุปทั้งโฟลเดอร์

| ไฟล์ | `Planar.Name` | สแตตพื้นฐาน | ส่วนมีเงื่อนไข (ในโค้ดมักไม่เช็คเงื่อนไข) |
|---|---|---|---|
| `Arcadia.h` | `Arcadia` | — | DMG ตามส่วนต่างจำนวนเพื่อน 4 คน: ขาด ×12 / เกิน ×9 |
| `Bone_Collection.h` | `Bone_Collection` | HP +12 | CD +28 (ถึง memosprite ด้วย) |
| `Broken_Keel.h` | `Broken_Keel` | Effect RES +10 | ทั้งทีม CD +10 |
| `FirmanentFrontline.h` | `FirmanentFrontline` | ATK +12 | DMG +18 / +12 ตาม `bool` |
| `GiantTree.h` | `GiantTree` | SPD +6 | Outgoing Healing +20 / +12 ตาม `bool` |
| `Inert.h` | `Inert` | CR +8 | Ult +15, FuA +15 |
| `Izumo.h` | `Izumo` | ATK +12 | CR +12 ถ้ามีเพื่อน path เดียวกัน (**เช็คจริง**) |
| `Kalpagni_Lantern.h` | `Kalpagni_Lantern` | SPD +6 | BE +40 |
| `Lushaka.h` | `Lushaka` | Energy Recharge +5 | เพื่อนช่องแรก ATK +12 (**เช็คจริง**) |
| `Revelry by the Sea.h` | `Revelry` | ATK +12 | DoT DMG +24 |
| `Rutilant.h` | `Rutilant` | CR +8 | Skill +20, BA +20 |
| `SpaceSealing.h` | `SpaceSealing` | ATK +24 (รวมสองท่อนแล้ว) | — |
| `Talia.h` | `Talia` | BE +16 | BE +20 |
| `Tengoku@Livestream.h` | `Tengoku@Livestream` | CD +16 | CD +32 เมื่อใช้ SP ครบ 3 ในเทิร์นเดียว (**เช็คจริง**) |
| `The_Wondrous_BananAmusement_Park.h` | `The_Wondrous_BananAmusement_Park` | CD +16 | CD +32 ขณะมี summon หรือ memosprite อยู่ในสนาม (**เช็คจริง** ทุกต้นเทิร์น) |

> มี 4 เซ็ตเท่านั้นที่ยังเช็คเงื่อนไขจริง — `Izumo`, `Lushaka`, `Tengoku@Livestream`, `The_Wondrous_BananAmusement_Park`

## กับดักชื่อ

- `Rutilant.h` เคยตั้ง `Planar.Name = "    "` และ `Inert.h` เคยตั้งเป็น `"SpaceSealing"` (copy มา) — แก้แล้ว ดู `../README.md` หัวข้อ "แก้เมื่อ 2026-09-13"
- ชื่อฟังก์ชันกับชื่อไฟล์ไม่ตรงกันบางตัว: `Revelry by the Sea.h` → `Planar::Revelry` · `Tengoku@Livestream.h` → `Planar::TengokuLivestream`
