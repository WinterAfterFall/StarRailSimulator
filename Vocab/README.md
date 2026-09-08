# Vocab — คลังศัพท์ Honkai: Star Rail

โฟลเดอร์นี้คือ **พจนานุกรมศัพท์** ของเกม Honkai: Star Rail สำหรับใช้อ้างอิงตอนเขียน/อ่านโค้ด
ของ StarRailSimulator — เน้น "ชื่อเรียก + ความสามารถแบบย่อ" ไม่ใช่การอธิบายกลไกเชิงลึก

ถ้าอยากได้ **กลไกเชิงลึก + สูตรคำนวณ** ให้ไปอ่าน [`docs/hsr-system-reference.md`](../docs/hsr-system-reference.md) แทน
ถ้าอยากได้ **kit เต็มของตัวละครรายตัว** ให้ไปอ่าน [`docs/character-kit-reference/`](../docs/character-kit-reference/)

---

## สารบัญ

| ไฟล์ | เนื้อหา | จำนวนรายการ |
|---|---|---|
| [01-Element.md](01-Element.md) | ธาตุทั้งหมด + Elation DMG | 7 ธาตุ (+1 ชนิดดาเมจใหม่) |
| [02-Path.md](02-Path.md) | Path ทั้งหมด (เล่นได้ + เฉพาะเนื้อเรื่อง) + Aeon | 9 + 9 |
| [03-Stats.md](03-Stats.md) | สแตตทุกประเภท + map เข้ากับ `enum class Stats` | ~40 |
| [04-AttackType.md](04-AttackType.md) | การโจมตี/ชนิดดาเมจทุกประเภท + map เข้ากับ `enum class AType` | ~25 |
| [05-Character.md](05-Character.md) | ตัวละครที่เล่นได้ทั้งหมด | 91 |
| [06-LightCone.md](06-LightCone.md) | Light Cone ทั้งหมด + ความสามารถ | ~170 |
| [07-Relic.md](07-Relic.md) | Cavern Relic Set ทั้งหมด + 2pc/4pc | 32 |
| [08-Planar.md](08-Planar.md) | Planar Ornament Set ทั้งหมด + 2pc | 28 |
| [09-Glossary.md](09-Glossary.md) | ศัพท์ระบบทั่วไป (SP, AV, Toughness, Eidolon ฯลฯ) | ~80 |

---

## วิธีอ่าน

- **ชื่อภาษาอังกฤษ = คีย์หลัก** เพราะเป็นชื่อที่ใช้จริงในโค้ดและในเกม
- คำอธิบายไทยอยู่ข้างๆ เพื่อให้จำความหมายได้
- คอลัมน์ `โค้ด` = ชื่อ enum / ตัวแปรที่ใช้ในโปรเจกต์นี้ (ถ้ามี) — ถ้าเว้นว่างแปลว่ายังไม่ได้ implement
- ตัวเลขความสามารถของ Light Cone = ค่าที่ **S1** (Superimposition 1) เว้นแต่ระบุเป็นอย่างอื่น
- ตัวเลขของ Relic/Planar = ค่าเต็มของเซ็ต (ไม่ขึ้นกับระดับ +15 หรือไม่)

---

## เวอร์ชันอ้างอิง

- ข้อมูลถึง **Version 4.5 "To Roll the Stars in Astropolis"** (เปิด 26 ส.ค. 2026)
- รวบรวมเมื่อ **2026-09-05**
- ตัวละคร/Light Cone ที่ยังไม่ปล่อย (เช่น Pearl v4.6) จะทำเครื่องหมาย ⏳ ไว้

## แหล่งอ้างอิง

- Game8 — [Relic/Ornament sets](https://game8.co/games/Honkai-Star-Rail/archives/406885), [All Light Cones](https://game8.co/games/Honkai-Star-Rail/archives/406599)
- GameWith — [All Light Cones List](https://gamewith.net/honkai-starrail/article/show/38073)
- HSR Maps (fortoffans) — [Relic & Ornament Sets](https://hsr.fortoffans.com/relic)
- Beebom — [All HSR Characters](https://beebom.com/honkai-star-rail-characters-list/)
- LootBar — [Character List by Path/Version](https://www.lootbar.com/blog/en/honkai-star-rail-character-list.html)
- AllThings.how — [4.5 Light Cones](https://allthings.how/honkai-star-rail-4-5-every-new-light-cone-and-how-to-get-it/)
- Icy Veins — [4.0 Light Cones](https://www.icy-veins.com/honkai-star-rail/news/cehck-out-the-new-light-cones-to-arrive-in-honkai-star-rail-version-4-0/)
- DualShockers — [Relic Sets & Effects](https://www.dualshockers.com/honkai-star-rail-complete-all-relic-sets-effects/)

> ⚠️ ข้อมูล patch 4.1–4.5 บางส่วนมาจากเว็บสรุป ไม่ใช่ text ในเกมโดยตรง
> จุดที่ยังไม่ชัวร์จะทำเครื่องหมาย ❓ ไว้ ถ้าจะเอาไป implement จริงควรเช็คในเกมอีกรอบ
