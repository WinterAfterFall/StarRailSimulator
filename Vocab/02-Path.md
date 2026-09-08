# 02 — Path (เส้นทาง / คลาส)

**Path** = ระบบคลาสของ HSR บอกว่าตัวละครทำหน้าที่อะไรในทีม
แต่ละ Path ผูกกับ **Aeon** (เทพในจักรวาล HSR) หนึ่งองค์

โค้ด: [`src/Enum/Enum.h`](../src/Enum/Enum.h) → `enum class Path`

---

## Path ที่เล่นได้ — 9 อัน

| # | ชื่อในเกม | โค้ด (`Path`) | Aeon | บทบาท | คำอธิบายไทย |
|---|---|---|---|---|---|
| 1 | **The Destruction** | `Destruction` | **Nanook** | DPS อึด | ตีแรงพร้อมความทน มักมี self-heal / HP-scaling |
| 2 | **The Hunt** | `Hunt` | **Lan** | Single-target DPS | ดาเมจเป้าเดี่ยวสูงสุด เหมาะกับ Elite/Boss มักมี follow-up |
| 3 | **The Erudition** | `Erudition` | **Nous** | AoE DPS | ตีหลายเป้า เหมาะกับศัตรูเป็นฝูง |
| 4 | **The Harmony** | `Harmony` | **Xipe** | Buffer | บัฟพวกพ้อง (ATK/CD/SPD/DMG/action advance) |
| 5 | **The Nihility** | `Nihility` | **IX** | Debuffer / DoT | ลง debuff ลดขีดความสามารถศัตรู + ดาเมจต่อเนื่อง |
| 6 | **The Preservation** | `Preservation` | **Qlipoth** | Shielder | สร้างเกราะ ป้องกันทีม มักมี taunt |
| 7 | **The Abundance** | `Abundance` | **Yaoshi** | Healer | ฮีลและฟื้น HP ปลดสถานะ |
| 8 | **The Remembrance** | `Remembrance` | **Fuli** | Memosprite user | เรียก **Memosprite** ออกมาช่วยรบ (เพิ่ม 3.0) |
| 9 | **The Elation** | `Elation` | **Aha** | Punchline / SP burner | กลไก Punchline → Aha Instant, ดาเมจชนิด Elation (เพิ่ม 4.0) |

> ⚠️ **ระวังชื่อ**: ในเกมเขียนว่า "The Hunt" แต่ใน enum ของโปรเจกต์นี้ใช้ `Hunt` (ไม่มี The)
> ส่วนโฟลเดอร์โค้ดใช้ชื่อ `src/Defination/Data/Character/The Hunt/` (มี The + มีเว้นวรรค)

---

## Path ที่ยังเล่นไม่ได้ — อีก 9 อัน

โผล่เฉพาะในเนื้อเรื่อง / Blessing ของ Simulated Universe

| ชื่อ Path | Aeon | หมายเหตุ |
|---|---|---|
| **The Trailblaze** | Akivili | Path ของ Astral Express / Trailblazer ตามเนื้อเรื่อง |
| **The Voracity** | Tayzzyronth | ความตะกละ — Swarm Disaster |
| **The Beauty** | Idrila | ความงาม — Aeon ที่หายไป |
| **The Permanence** | Ena | ความคงอยู่ |
| **The Propagation** | Tayzzyronth (แตกสาย) | การแพร่พันธุ์ — Swarm |
| **The Enigmata** | Mythus | ปริศนา |
| **The Equilibrium** | HooH | สมดุล |
| **The Finality** | Terminus | จุดจบ |
| **The Order** | Ena (แปรสภาพ) | ระเบียบ — Xianzhou lore |

> Aeon อื่นที่ถูกเอ่ยถึงแต่ไม่มี Path ให้เล่น: **Long** (The Permanence สาย Xianzhou), **Oroboros** (The Voracity)

---

## Path ใน Simulated / Divergent Universe

ในโหมด SU/DU คำว่า Path ใช้จัดหมวด **Blessing** ตามสไตล์การเล่น — คนละความหมายกับ Path ของตัวละคร

| Path (SU) | Blessing เน้นอะไร |
|---|---|
| Preservation | เกราะ / ลดดาเมจ |
| Remembrance | Freeze / ดีเลย์ |
| Nihility | DoT + debuff |
| Abundance | ฮีล / ฟื้น HP |
| The Hunt | Single-target + advance forward |
| Destruction | HP-scaling + ดาเมจสูง |
| Erudition | Ultimate + AoE |
| Harmony | **Break DMG** (สำคัญมากใน DU) |
| Elation | **Follow-up + Additional DMG** |
| Propagation | ตัวคูณดาเมจดิบ (SU only) |

---

## เรื่องที่มีผลกับโค้ด

1. **`path[0]`** — โปรเจกต์นี้เก็บ path เป็น `vector` เพราะเผื่อกรณีตัวละครมีหลาย Path
   โค้ดเช็ค Path of Elation ด้วย `each->path[0] == Path::Elation`
   (ดู [`SetCombat.h:117`](../src/Defination/Function/Setup/SetCombat.h) และ [`Combat.h:57`](../src/Defination/Function/Combat/Combat.h))
2. **Path มีผลกับ Light Cone** — Light Cone ใส่ได้เฉพาะตัวละครที่ Path ตรงกันเท่านั้น
   ถ้า Path ไม่ตรง จะได้แค่ base stat ไม่ได้ passive
3. **Planar `Izumo Gensei and Takama Divine Realm`** เช็ค Path ตรงกันในทีม → CRIT Rate +12%
4. **Light Cone `Poised to Bloom`** เช็คตัวละคร Path เดียวกัน 2 ตัวขึ้นไป → CRIT DMG +16%
5. โฟลเดอร์ข้อมูลตัวละคร/Light Cone ในโปรเจกต์แยกตาม Path ทั้งหมด
   (`src/Defination/Data/Character/<Path>/`, `src/Defination/Data/Lightcone/<Path>/`)
