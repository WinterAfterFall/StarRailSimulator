# `src/Defination/Data/Character/Abundance/Huohuo.h`

kit อ้างอิง: `docs/character-kit-reference/Huohuo.md` · **ฮีลเลอร์แบบ "ฮีลต่อเนื่อง" (Divine Provision)** — อ่าน `Luocha.md` และ `Gallagher.md` ก่อนสำหรับ API การฮีล

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(98, 140, 140, E, Wind, Abundance, "Huohuo", Standard)` | 5 |
| build — HP + Outgoing Healing | main stat หมวก `HEALING_OUT` + `pushSubstats(HP_P)` | 9-12 |
| **Basic ATK** | lambda `BA` — `DmgSrc(DmgSrcType::HP, 50, 10)` | 25-35 |
| **Skill** — ฮีลทีม + ตั้ง Divine Provision | lambda `Skill` — `RestoreHP(main, adjacent, other)` + `setStack("Divine Provision", 6)` | 37-55 |
| **Ultimate** — ทีม ATK +40% + คืน energy 20 | `Ultimate_List` — `buffAllAlly(..., "HH Ult", 2)` + วน `allyList` | 68-81 |
| **Talent** — Divine Provision ฮีลต่อเนื่อง | `Before_turn_List` + `WhenUseUlt_List` (โค้ดเหมือนกัน) | 95-111, 134-145 |
| **Minor traces** | `Reset_List` (มี `HEALING_OUT += 40` ใต้ `// substats`) | 83-93 |
| **E1** — Skill ให้ทีม SPD +12% · Divine Provision อยู่ 3 เทิร์น | `if (ptr->Eidolon >= 1)` 3 จุด | 48, 50-51, 100 |
| **E6** — Huohuo ฮีลใคร → คนนั้น DMG +50% | `Healing_List` (ลงทะเบียนเฉพาะเมื่อ E6) | 147-153 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — `turnCnt % 3 == 0` → Skill ไม่งั้น BA | 58-61 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — เฉพาะ `BeforeTurn` ของเป้าที่บัฟ | 63-66 |
| ถอนบัฟ | `After_turn_List` + `AllyDeath_List` (ครบทั้งสองทาง) | 113-132 |

## รากฐาน: ทรัพยากรที่นับด้วย "จำนวนครั้งที่ฮีล" ไม่ใช่เทิร์น

```cpp
Skill:   if (isHaveToAddBuff(hh, "Divine Provision")) hh->setStack("Divine Provision", 6);
         extendBuffTime(hh, "Divine Provision", 2);          // E1 -> 3

ใช้:     if (getBuffCheck("Divine Provision") && getStack("Divine Provision")) {
             hh->stack["Divine Provision"]--;
             Increase_energy(hh, 1);
             ... ฮีล ...
         }
```
- **`buffCheck` บอกว่าสถานะยังอยู่ไหม (คุมด้วยเทิร์น) ส่วน `stack` บอกว่าฮีลได้อีกกี่ครั้ง** — ทั้งสองต้องเป็นจริงพร้อมกัน · คู่เดียวกับ `../Erudition/Rappa.md`
- **ถูก trigger จาก 2 ที่**: ต้นเทิร์นของ ally (`Before_turn_List`) และเมื่อมีใครใช้ ult (`WhenUseUlt_List`) — **โค้ดในสองที่นี้เหมือนกันทั้งก้อน**
- `isHaveToAddBuff` แบบ 2 args ใช้กันการรีเซ็ต stack ถ้าสถานะยังอยู่ แล้วค่อย `extendBuffTime` แยกเพื่อต่ออายุเสมอ — **เป็นสำนวนที่ต่างจาก `buffSingle(..., ชื่อ, เทิร์น)` ตรงที่แยก "ตั้ง stack" ออกจาก "ต่ออายุ"**

## รากฐาน: ฮีลแยกเงื่อนไขต่อคน

```cpp
for (auto &each : allyList)
    if (each->currentHP <= each->totalHP/2)
        hh->RestoreHP(each, HealSrc(HP, 4.5, CONST, 120));    // คนเลือดต่ำได้ก่อน
hh->RestoreHP(ally, HealSrc(HP, 4.5, CONST, 120));            // แล้วคนที่กำลังจะเล่นได้อีกครั้ง
```
ใช้ overload `RestoreHP(target, HealSrc)` ทีละคนแทน overload 3 args เพราะเงื่อนไขไม่ใช่ "ใครเสีย HP มากสุด" · **คนที่เลือดต่ำและกำลังจะเล่นจะได้ฮีล 2 ครั้ง** ซึ่งอาจเป็นเจตนาหรือไม่ก็ได้

## จุดที่ควรระวัง

- **`Before_turn_List` เช็ค `ally` แล้ว return ถ้า null (97) แต่ `isBuffEnd(hh, ...)` ที่ตามมาไม่เกี่ยวกับ `ally` เลย** → ถ้าเป็นเทิร์นศัตรู Divine Provision จะไม่ถูกตรวจหมดอายุ
- **โค้ด Divine Provision ถูก copy 2 ที่** (102-110 กับ 135-144) เหมือนกันทุกบรรทัด
- **`WhenUseUlt_List` ไม่ guard ว่าใครกด ult** (134) → Talent ทำงานเมื่อ **ใครก็ตาม** ใช้ ult รวมถึง Huohuo เอง ซึ่งน่าจะตรงกับ kit
- **`Reset_List` บวก `HEALING_OUT += 40` ใต้คอมเมนต์ `// substats`** (91) — ไม่ชัดว่ามาจาก trace หรือ substat
- **Ult คืน energy ด้วย `Increase_energy(each, 20, 0)`** (75) — arg ที่ 3 เป็น 0 แปลว่าไม่มีส่วนที่ข้าม ER · ตรงข้ามกับ `../Harmony/Sunday.md` ที่ใช้ `(..., 0, 40)` สำหรับเป้า energy ต่ำ
- **ไม่มี Technique** — ไม่มีการเช็ค `ptr->Technique` ทั้งไฟล์
- **E6 `Healing_List` ไม่เช็คว่าเป็นการฮีลจริงหรือค่า 0** (149-152) → ถ้ามีการเรียก `RestoreHP` ด้วยค่า 0 ก็ยังได้บัฟ
