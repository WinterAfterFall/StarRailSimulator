# `src/Defination/Data/Character/Abundance/Huohuo.h`

kit อ้างอิง: `docs/kit-reference/Character/Abundance/huohuo.md` · **ฮีลเลอร์แบบ "ฮีลต่อเนื่อง" (Divine Provision)** — อ่าน `Luocha.md` และ `Gallagher.md` ก่อนสำหรับ API การฮีล

> **แก้ 2026-09-26** (โค้ดเดิมเป็น kit ก่อน remake → ปรับตาม kit ปัจจุบัน): ATK ฐาน 602 → 601 · Skill ฮีล 21%+560 / 16.8%+448 → 24%+640 / 19.2%+512 · Divine Provision 2 → **3 เทิร์น** (E1 +1) และ **ได้จาก Ult ด้วย** · ได้ซ้ำ = **รีเซ็ตตัวนับเป็น 6 ทุกครั้ง** (เดิมรีเซ็ตเฉพาะตอนหมดแล้วได้ใหม่) · เพิ่ม **A2** (energy 30 + Divine Provision 2 เทิร์นตอนเริ่ม) · เพิ่ม **A4** (Max Energy ≥ 160 → ATK +24% เพิ่ม) · Ult คืน energy **ยกเว้นตัวเอง** และวน `charList` (เดิมวน `allyList` → Huohuo ได้เอง + เจ้าของ memosprite ได้ 2 เท่า) · Talent ฮีลคน HP% ต่ำสุดด้วย · เพิ่ม Technique (ATK ศัตรู −25% 2 เทิร์น) · รวมโค้ด Divine Provision ที่เคย copy 2 ที่เป็น lambda เดียว

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(98, 140, 140, E, Wind, Abundance, "Huohuo", Standard)` · base `(1358, 601, 509)` | 5-6 |
| build — HP + Outgoing Healing | main stat หมวก `HEALING_OUT` + `pushSubstats(HP_P)` | 9-12 |
| **Talent** — ได้/ต่ออายุ Divine Provision | lambda `gainDivineProvision(turns)` — ตั้ง stack 6 ทุกครั้ง + `extendBuffTime` (E1 +1 เทิร์น) + E1 SPD ทีม +12% ตอนได้ครั้งแรก | 26-33 |
| **Talent** — ฮีลของ Divine Provision + **A6** energy +1 | lambda `divineProvisionHeal(ally)` — ฮีลผู้เล่น + คน HP% ต่ำสุด แล้วฮีลทุกคนที่ HP ≤ 50% | 36-51 |
| **Basic ATK** | lambda `BA` — `DmgSrc(DmgSrcType::HP, 50, 10)` | 53-63 |
| **Skill** — ฮีล Blast + Divine Provision 3 เทิร์น | lambda `Skill` — `RestoreHP(24%+640, 19.2%+512, -)` + `gainDivineProvision(3)` | 65-78 |
| **Ultimate** — ทีม ATK +40% 2 เทิร์น + energy 20% ของ Max Energy (ยกเว้นตัวเอง) + Divine Provision 3 เทิร์น | `Ultimate_List` — `buffAllAlly(..., "HH Ult", 2)` + วน `charList` ข้าม `ptr` + `gainDivineProvision(3)` | 91-111 |
| **A4** — Max Energy ≥ 160 → ATK +24% เพิ่ม | ใน Ult: `buffSingle(each, ..., "HH Ult A4", 2)` เช็ค `each->owner->Max_energy` (memosprite อิงเจ้าของ) | 97-100 |
| **Minor traces** | `Reset_List` (มี `HEALING_OUT += 40` ใต้ `// substats`) | 113-123 |
| **A2** — เริ่มต่อสู้ energy 30 + Divine Provision 2 เทิร์น | `Start_game_List` → `Increase_energy(hh, 0, 30)` + `gainDivineProvision(2)` | 126-135 |
| **Technique** — ATK ศัตรูทุกตัว −25% 2 เทิร์น | `Start_game_List` → `debuffApply(..., "HH Technique", 2)` + `atkPercent -= 25` · คืนใน `After_turn_List` | 129-134, 161-164 |
| Talent trigger — ต้นเทิร์นเพื่อน / หมดอายุ | `Before_turn_List` → `isBuffEnd(hh, ...)` (นับลดตอนเริ่มเทิร์น Huohuo) แล้ว `divineProvisionHeal(ally)` | 137-145 |
| Talent trigger — เพื่อนใช้ Ult | `WhenUseUlt_List` → `divineProvisionHeal(ally)` | 178-180 |
| **E6** — Huohuo ฮีลใคร → คนนั้น DMG +50% | `Healing_List` (ลงทะเบียนเฉพาะเมื่อ E6) | 182-187 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — `turnCnt % 3 == 0` → Skill ไม่งั้น BA | 81-84 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — เฉพาะ `BeforeTurn` ของเป้าที่บัฟ | 86-89 |
| ถอนบัฟ | `After_turn_List` + `AllyDeath_List` (`HH Ult` / `HH Ult A4` / `HH E6` ครบทั้งสองทาง) | 147-176 |

## รากฐาน: ทรัพยากรที่นับด้วย "จำนวนครั้งที่ฮีล" ไม่ใช่เทิร์น

```cpp
gainDivineProvision(turns):
    if (isHaveToAddBuff(hh, "Divine Provision")) { E1: ทีม SPD +12% }   // ลงค่าครั้งเดียว
    hh->setStack("Divine Provision", 6);                                 // ได้ซ้ำ = รีเซ็ตตัวนับเสมอ
    extendBuffTime(hh, "Divine Provision", turns (+1 ถ้า E1));

divineProvisionHeal(ally):
    if (!getBuffCheck(...) || !getStack(...)) return;
    stack--; Increase_energy(hh, 1); ... ฮีล ...
```
- **`buffCheck` บอกว่าสถานะยังอยู่ไหม (คุมด้วยเทิร์น) ส่วน `stack` บอกว่าฮีลได้อีกกี่ครั้ง** — ทั้งสองต้องเป็นจริงพร้อมกัน · คู่เดียวกับ `../Erudition/Rappa.md`
- **แยก "ลงค่าครั้งเดียว" (`isHaveToAddBuff`) ออกจาก "รีเซ็ต stack + ต่ออายุ"** — E1 SPD จึงไม่บวกซ้ำเมื่อได้ Divine Provision ขณะที่ยังมีอยู่
- ถูก trigger จาก 2 ที่ (ต้นเทิร์นเพื่อน / ใครก็ได้ใช้ ult รวม Huohuo เอง) ผ่าน lambda เดียว

## รากฐาน: ฮีลแยกเงื่อนไขต่อคน

ใช้ overload `RestoreHP(target, HealSrc)` ทีละคน: ผู้เล่น → คน HP% ต่ำสุด (ถ้าไม่ใช่คนเดียวกัน) → ทุกคนที่ HP ≤ 50% · **คนที่เข้าหลายเงื่อนไขได้ฮีลหลายครั้ง** ตามลำดับขั้นใน kit ("จากนั้นฮีลเพื่อนทุกคนที่ HP% ≤ 50%")

## ส่วนที่ยังไม่มีในโค้ด

- **ลบ debuff** (Skill / Talent) — ไม่มีระบบ cleanse
- **E1 Outgoing Healing +20%**, **E2** (กันตาย), **E4** (ฮีลเพิ่มตาม HP ที่เสีย) — เกี่ยวกับฮีล/การตาย ไม่กระทบดาเมจ
- **ตัวเลขใช้ Lv10 / Lv6** ตาม kit (ไม่ได้บวกเลเวลจาก E3/E5 แบบ `Gallagher.md`)

## จุดที่ควรระวัง

- **`Reset_List` บวก `HEALING_OUT += 40` ใต้คอมเมนต์ `// substats`** — ไม่ชัดว่ามาจาก trace หรือ substat
- **Ult คืน energy ด้วย `Increase_energy(each, 20, 0)`** — arg ที่ 2 เป็น % ของ Max Energy ไม่ผ่าน ER · ตรงข้ามกับ `../Harmony/Sunday.md` ที่ใช้ `(..., 0, 40)`
- **E6 `Healing_List` ไม่เช็คว่าเป็นการฮีลจริงหรือค่า 0** → ถ้ามีการเรียก `RestoreHP` ด้วยค่า 0 ก็ยังได้บัฟ
