# `src/Defination/Data/Character/Destruction/Saber.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/saber.md` · **ตัวละคร collab ที่กติกา energy ต่างจากทุกตัว** (`Ult_cost` 360 และเก็บ energy ล้นไว้ใช้ต่อ) — `Tingyun.h` มีสาขา escape hatch สำหรับ Saber โดยเฉพาะ

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / **energy ult 360** | `SetCharBasicStats(101, 360, 360, E, Wind, Destruction, "Saber", Standard)` | 5 |
| **Core Resonance** (ทรัพยากรแกน) | lambda `CoreResonance(int value)` — จุดเดียวที่แตะ `buffNote["Core Resonance"]` | 25-29 |
| ใช้ Core Resonance | lambda `resetCR()` — คืน multiplier แล้วล้างเป็น 0 + แปลงเป็น energy | 31-37 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 43-57 |
| **Enhanced BA** (หลัง Ult) | lambda `EBA` — AoE 75%×3 สองชุด + `multiplyDmg` ตามจำนวนศัตรู | 59-86 |
| **Skill** | lambda `Skill` — blast 4 ชุด (0.1/0.1/0.1/0.7 ของ 150/75) | 88-118 |
| **Enhanced Skill** (energy ใกล้เต็ม) | lambda `ESkill` — โครงเดียวกับ Skill แต่ multiplier บวก `resetCR()` | 120-148 |
| **Ultimate** | `Ultimate_List` — AoE 280%×3 + bounce 110 ×10 | 164-190 |
| **A4** — เก็บ energy ส่วนที่ล้น | `When_Energy_Increase_List` → `buffNote["Saber A4"] += ส่วนเกิน` · คืนตอน Ult | 246-254, 171-172 |
| **A6** — CD จาก Core Resonance + Skill | `buffStackSingle(..., 4, cap 8, "Saber A6")` + `buffSingle(CD +50, "Saber A6", 2)` | 27, 94 |
| **Talent** — เพื่อนใช้ ult → DMG +60% | `WhenUseUlt_List` (ไม่ guard ว่าใครกด = ได้จากทุกคน) | 241-244 |
| **Technique** | `Start_game_List` → Core Resonance +2 + ATK +35% 2 เทิร์น | 232-239 |
| **Minor traces** | `Reset_List` (มี `CR += 20` เพิ่มใต้คอมเมนต์ `//trace`) | 192-206 |
| **E1** — ทุก action ได้ Core Resonance +1 · Ult DMG +60% | `if (ptr->Eidolon >= 1) CoreResonance(1)` ท้ายทุกท่า · `Reset_List` | 50, 68, 96, 127, 201 |
| **E2** — DEF_SHRED จาก Core Resonance · multiplier 21 แทน 14 | `CoreResonance` · `resetCR` | 28, 35-36 |
| **E4** — Wind RESPEN stack | `buffStackSingle(..., 1, 3, "Saber E4")` ตอน Ult | 173 |
| **E6** — energy ก้อนใหญ่ทุก 2 ครั้งที่กด Ult | `getBuffCountdown("Saber E6")` | 174-181 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — EBA → ESkill → Skill (ถ้ามี SP) → BA | 151-156 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — กดได้เฉพาะตอน **ไม่มี** `Mana Flow` | 159-162 |

## รากฐาน: ทรัพยากรที่แปลงเป็นทั้ง stat และ multiplier

```cpp
CoreResonance(value):  buffNote["Core Resonance"] += value;
                       buffStackSingle(sb, {{CD, 4}}, value, 8, "Saber A6");       // A6
                       if (E2) buffStackSingle(sb, {{DEF_SHRED, 1}}, value, 15, "Saber E2");

resetCR():             ans = buffNote["Core Resonance"];  setBuffNote(..., 0);
                       Increase_energy(sb, 0, 8.0 * ans);                          // แปลงเป็น energy
                       return (E2 ? 21 : 14) * ans;                                // คืนเป็น multiplier
```
**เป็นรูปแบบ lambda คู่ (สะสม / ใช้) ที่สะอาดกว่า `Luka.h`** — ทุกทางที่ได้ทรัพยากรเรียกผ่าน `CoreResonance` ทางเดียว และทุกการใช้ผ่าน `resetCR` ทางเดียว · `buffStackSingle` ดูแล cap ให้ ไม่ต้อง clamp เอง (ตรงกับข้อตกลงใน `../../README.md` หัวข้อ cap)

## รากฐาน: `act->setDamageNote(0)`

`BA` และ `Skill` เรียก `setDamageNote(0)` (55, 116) แต่ `EBA` / `ESkill` / `Ult` ไม่เรียก — เป็นการตั้งค่าว่าจะบันทึกดาเมจก้อนนี้ลงสถิติยังไง (ดู `dmgRecordEachType` ใน `Class/Unit/Enemy.h`) · ยังไม่ชัดว่าทำไมแยกเฉพาะสองท่านี้

## รากฐาน: `multiplyDmg` ตามจำนวนศัตรู

```cpp
if (Total_enemy == 1 || (bestBounce && Total_enemy == 5)) act->multiplyDmg(370/150*100);
if (Total_enemy == 2)                                     act->multiplyDmg(200);
```
EBA ของ kit ปรับ multiplier ตามจำนวนเป้า — โค้ดเขียนเป็นสาขาตายตัว · **`370/150*100` เป็นการหารจำนวนเต็มใน C++** → `370/150 = 2` แล้ว `*100 = 200` ไม่ใช่ 246.67 ที่น่าจะตั้งใจ **(ดูจุดที่ควรระวัง)**

## รากฐาน: การจัดจังหวะ Ult ที่ซับซ้อนที่สุดในโปรเจกต์

`After_turn_List` (208-230) ทำ 2 อย่าง: ถอนบัฟที่หมดอายุ และ **ตัดสินใจว่าเทิร์นหน้าจะใช้ Enhanced Skill ไหม**
```cpp
if (ptr->Ult_cost <= ptr->Current_energy + 8 * buffNote["Core Resonance"]) {
    setBuffCheck("Saber ESkill", 1);
    if (getBuffCheck("Mana Flow")) {
        Action_forward(sb->Atv_stats.get(), 1000);   // ดันคิวสุดตัว
        genSkillPoint(sb, 1);
        setBuffCheck("Mana Flow", 0);
    }
} else setBuffCheck("Saber ESkill", 0);
```
มองล่วงหน้าว่า energy ปัจจุบัน **บวก** energy ที่จะได้จาก Core Resonance พอกด Ult ไหม · `Mana Flow` เป็นสถานะที่ได้จาก EBA และต้นเกม ซึ่ง `addUltCondition` ใช้ห้ามกด Ult ระหว่างที่ยังมีอยู่

`Saber::UltInTurnOnly()` (256-262) เป็นฟังก์ชันนอก `Setup` ที่เพิ่มเงื่อนไข "กด ult ได้เฉพาะต้นเทิร์นตัวเอง" — เรียกจากข้างนอกเหมือน `Kafka::useKafkaA2` และ `Castorice::DriverCondition`

## จุดที่ควรระวัง

- **`370/150*100` เป็นการหารจำนวนเต็ม** (83) → ได้ `200` ไม่ใช่ `246.67` · ถ้าตั้งใจให้เป็นทศนิยมต้องเขียน `370.0/150*100` · ผลคือกรณีศัตรู 1 ตัวกับ 2 ตัวได้ multiplier เท่ากันพอดี ซึ่งน่าจะไม่ใช่เจตนา
- **`Reset_List` บวก `CR += 20` ใต้คอมเมนต์ `//trace`** (199) นอกเหนือจาก minor traces 12 — ไม่มีคำอธิบายว่ามาจาก trace ไหน
- **E4 บวก Wind RESPEN สองทาง** — `Reset_List` +8 ถาวร (202) และ `buffStackSingle` +4 สูงสุด 3 ชั้นตอน Ult (173) · ต้องดู kit ว่าซ้อนกันถูกไหม
- **`WhenUseUlt_List` ไม่ guard ว่าใครกด ult** (241-244) → Saber ได้ DMG +60% และ Core Resonance +3 **ทุกครั้งที่ใครในทีมกด ult รวมถึงตัวเอง** · ถ้า kit ระบุเฉพาะเพื่อน จะเกินจริง
- **`buffEnd["Saber E6"]--` แก้ฟิลด์ countdown ตรง ๆ** (179) แทนการใช้ helper — เป็นการใช้ `buffEnd` เป็นตัวนับรอบแทนอายุบัฟ
- **`Action_forward(..., 1000)`** (225) ค่ามหาศาลเพื่อบังคับให้ได้เล่นทันที — เป็นค่าที่ไม่มีที่อื่นใช้
