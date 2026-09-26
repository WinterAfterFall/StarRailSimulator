# `src/Defination/Data/Character/Destruction/Saber.h`

kit อ้างอิง: `docs/kit-reference/Character/Destruction/saber.md` · **ตัวละคร collab ที่กติกา energy ต่างจากทุกตัว** (`Ult_cost` 360 และเก็บ energy ล้นไว้ใช้ต่อ) — `Tingyun.h` มีสาขา escape hatch สำหรับ Saber โดยเฉพาะ

> **แก้ 2026-09-27** (รีวิวเทียบ kit): EBA ศัตรู 1 ตัว `370/150*100` หารจำนวนเต็มได้ 200 → `370.0/150*100` (รวม 370% ตาม kit) · A4 เริ่มต่อสู้เดิม +10% Max Energy → เติมเป็น 60% ถ้าต่ำกว่า · ESkill ได้ A6 CD +50% ด้วย · เงื่อนไข ESkill / Mana Burst นับ energy 30 (ผ่าน ER) ของ Skill ด้วย · เปลี่ยนชื่อบัฟ CD +50% เป็น `"Saber A6 Skill"` ไม่ให้ซ้ำกับชื่อ stack · **ไม่แก้ตาม user**: A4 cap 120/200, base stats (1242/602/655 vs kit 1241/601/654)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / **energy ult 360** | `SetCharBasicStats(101, 360, 360, E, Wind, Destruction, "Saber", Standard)` | 5 |
| **Core Resonance** (ทรัพยากรแกน) | lambda `CoreResonance(int value)` — จุดเดียวที่แตะ `buffNote["Core Resonance"]` | 25-29 |
| ใช้ Core Resonance | lambda `resetCR()` — คืน multiplier แล้วล้างเป็น 0 + แปลงเป็น energy | 31-38 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 44-58 |
| **Enhanced BA** (หลัง Ult) | lambda `EBA` — AoE 75%×3 สองชุด + `multiplyDmg(370.0/150*100)` (1 ตัว) / `200` (2 ตัว) | 60-88 |
| **Skill** | lambda `Skill` — blast 4 ชุด (0.1/0.1/0.1/0.7 ของ 150/75) | 90-119 |
| **Enhanced Skill** (energy ใกล้เต็ม) | lambda `ESkill` — โครงเดียวกับ Skill แต่ multiplier บวก `resetCR()` · ได้ A6 CD +50% ด้วย | 121-150 |
| **Ultimate** | `Ultimate_List` — AoE 280%×3 + bounce 110 ×10 | 166-194 |
| **A4** — เก็บ energy ส่วนที่ล้น | `When_Energy_Increase_List` → `buffNote["Saber A4"] += ส่วนเกิน` · คืนตอน Ult · เริ่มต่อสู้ Energy < 60% → เติมเป็น 60% · (ไม่มี cap 120/200 — user ไม่ให้แก้) | 248-255, 172-173, 234-235 |
| **A6** — CD จาก Core Resonance + Skill | `buffStackSingle(..., 4, cap 8, "Saber A6")` + `buffSingle(CD +50, "Saber A6 Skill", 2)` ทั้ง Skill และ ESkill | 27, 96, 127 |
| **Talent** — เพื่อนใช้ ult → DMG +60% | `WhenUseUlt_List` — ไม่ guard ว่าใครกด ตรง kit ("เพื่อนคนใดใช้ Ultimate" รวม Saber เอง) | 243-246 |
| **Technique** | `Start_game_List` → Core Resonance +2 + ATK +35% 2 เทิร์น | 232-241 |
| **Minor traces** | `Reset_List` (+ `CR += 20` ใต้ `//trace` = **A2**) | 196-209 |
| **E1** — ทุก action ได้ Core Resonance +1 · Ult DMG +60% | `if (ptr->Eidolon >= 1) CoreResonance(1)` ท้ายทุกท่า · `Reset_List` | 51, 70, 99, 129, 204 |
| **E2** — DEF_SHRED จาก Core Resonance · multiplier 21 แทน 14 | `CoreResonance` · `resetCR` | 28, 36-37 |
| **E4** — Wind RESPEN stack | `Reset_List` +8 ถาวร · `buffStackSingle(..., 1, 3, "Saber E4")` ตอน Ult — ตรง kit ทั้งสองส่วน | 174, 205 |
| **E6** — energy ก้อนใหญ่ทุก 2 ครั้งที่กด Ult | `getBuffCountdown("Saber E6")` — Energy 300 ที่ Ult ครั้งที่ 1, 4, 7 … (ทุก 3 ครั้ง) | 175-182 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — EBA → ESkill → Skill (ถ้ามี SP) → BA | 153-158 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — กดได้เฉพาะตอน **ไม่มี** `Mana Flow` | 161-164 |

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

- ~~`370/150*100` เป็นการหารจำนวนเต็ม~~ แก้ 2026-09-27 เป็น `370.0/150*100`
- **`Reset_List` บวก `CR += 20` ใต้คอมเมนต์ `//trace`** (202) = A2 "Knight of the Dragon" CRIT Rate +20% ตาม kit
- **E4 บวก Wind RESPEN สองทาง** — `Reset_List` +8 ถาวร (205) และ `buffStackSingle` +4 สูงสุด 3 ชั้นตอน Ult (174) · ตรง kit ทั้งสองส่วน
- **`WhenUseUlt_List` ไม่ guard ว่าใครกด ult** (243-246) — ตรง kit ("เมื่อเพื่อนคนใดใช้ Ultimate")
- **A4 excess energy ไม่มี cap** (248-255) — kit cap 120 (E6 200) · user ให้คงไว้ (2026-09-27)
- **`buffEnd["Saber E6"]--` แก้ฟิลด์ countdown ตรง ๆ** (180) แทนการใช้ helper — ใช้ `buffEnd` เป็นตัวนับรอบ Ult
- **`Action_forward(..., 1000)`** (225) ค่ามหาศาลเพื่อบังคับให้ได้เล่นทันที (A2 Mana Burst)
