# `src/Defination/Data/Character/The Hunt/Archer.h`

kit อ้างอิง: `docs/kit-reference/Character/Archer.md` · **ตัวละคร collab (ชุดเดียวกับ `../Destruction/Saber.md`)** · ตัวเดียวของ path `The Hunt` ในโปรเจกต์ · เป็นตัวที่ 2 ที่แก้ `Max_sp` (อีกตัวคือ `../Harmony/Hanabi.md`)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / **energy ult 220** | `SetCharBasicStats(105, 220, 220, E, Quantum, Path::Hunt, "Archer", Standard)` | 5 |
| **เพิ่มเพดาน SP ของทีม** | `Max_sp += 2;` | 21 |
| เกณฑ์ SP ขั้นต่ำก่อนกด Skill | `ptr->Adjust["Archer Minimum"] = 3;` | 22 |
| **Charge** (ทรัพยากรยิง FuA, cap 4) | lambda `Charge(int)` | 25-28 |
| **Basic ATK** | lambda `BA` — single 100%/10 | 34-46 |
| **Skill** — **กิน SP 2 แต้ม** | lambda `Skill` — `genSkillPoint(ac, -2)` + `buffStackSingle(DMG[SKILL] +100, cap 2)` | 48-70 |
| **Follow-up ATK** | lambda `Fua` — single 200%/10 + คืน SP 1 | 72-85 |
| **Ultimate** | `Ultimate_List` (`PRIORITY_ACTTACK`) — single **1000%**/30 + Charge +2 | 97-115 |
| **Talent** — เพื่อนโจมตี → ใช้ Charge ยิง FuA | `AfterAttackActionList` | 172-176 |
| **Skill ต่อเนื่อง** — กด Skill ซ้ำได้ถ้า SP พอ (cap 5) | `AfterAttackActionList` → เรียก `Skill()` ซ้ำ | 165-171 |
| **A6** — SP ทีม ≥ 4 → CD +120 | `Skill_point_List` → `buffSingle(..., "Archer A6", 1)` | 179-184 |
| **Technique** | `Start_game_List` — AoE 200%×3 + Charge +1 | 129-145 |
| **Minor traces** | `Reset_List` | 117-128 |
| **E1** — Skill 3 ครั้ง → คืน SP 2 | `ac->addStack("Archer E1", 1)` ใน Skill | 58-64 |
| **E2** — Ult ลด Quantum RES | `debuffSingleApply(..., "Archer E2", 2)` | 103-107 |
| **E4** — Ult DMG +150% | `Reset_List` | 125 |
| **E6** — Circuit Connection cap 3 · DEF_SHRED[SKILL] +20 · SP คืนทุกเทิร์น | บรรทัด 55, 126, 147-151 | |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — `sp >= 2 * Adjust["Archer Minimum"]` → Skill ไม่งั้น BA | 88-91 |

## รากฐาน: ท่าที่เรียกตัวเองซ้ำผ่าน `AfterAttackActionList`

```cpp
if (act->actionName == "Archer Skill") {
    if (sp >= 2 && ac->getStack("Archer Skill Limit") < 5) {
        Skill();                                                  // <- เรียกซ้ำ
    } else {
        buffResetStack(ac, {{DMG[SKILL], 100}}, "Circuit Connection");
        ac->setStack("Archer Skill Limit", 0);
    }
}
```
- **ตัวหยุดมี 2 ชั้น**: SP ต้องเหลือ ≥ 2 และ `Archer Skill Limit` (นับด้วย `calStack(ac, 1, 5, ...)` ตอนเริ่ม Skill) ต้องไม่ถึง 5
- **พอหยุดแล้วล้าง stack ทั้งสองอย่างทันที** — `Circuit Connection` (บัฟ DMG ที่สะสมระหว่างชุด) และตัวนับรอบ
- ปลอดภัยกว่า Talent ของ `../Erudition/Anaxa.md` ที่มีตัวหยุดชั้นเดียว

## รากฐาน: ทรัพยากรที่ clamp ใน lambda เอง

```cpp
function<void(int value)> Charge = [ptr,ac](int value){
    ac->stack["Archer Charge"] += value;
    if (ac->stack["Archer Charge"] >= 4) ac->stack["Archer Charge"] = 4;
};
```
**เป็นข้อยกเว้นของข้อตกลง "ไม่ clamp ทรัพยากร"** (ดู `../../README.md` หัวข้อ cap ของ stack สะสม) — ที่นี่ clamp เพราะ Charge ถูกใช้ทีละ 1 ใน `AfterAttackActionList` ซึ่งเกิดถี่มาก ถ้าไม่ clamp จะสะสมไม่จำกัด

## จุดที่ควรระวัง

- **`Skill_point_List` ของ A6 ไม่เช็คว่าใครทำให้ SP เปลี่ยน และไม่เช็คว่า SP เพิ่มหรือลด** (179-184) → ลงบัฟ CD +120 ทุกครั้งที่ `sp >= 4` ไม่ว่าจะเกิดจากอะไร · `buffSingle` มี `isHaveToAddBuff` กันซ้ำให้ แต่บัฟจะถูกต่ออายุตลอดเวลาที่ SP ยังสูง
- **A6 บัฟอายุ 1 เทิร์นแต่ถอนใน `After_turn_List` ที่ไม่ guard เทิร์น** (157-159) — `isBuffEnd` เช็คเจ้าของเทิร์นให้เองจึงยังถูก
- **`Turn_func` ใช้เกณฑ์ `sp >= 2 * Adjust["Archer Minimum"]` = 6** (89) ซึ่งสูงกว่าเพดาน SP มาตรฐาน (5) และเท่ากับเพดานใหม่หลัง `Max_sp += 2` (7) พอดี → Archer จะกด Skill ได้เฉพาะตอน SP เกือบเต็ม
- **`AfterAttackActionList` ของ Talent ไม่จำกัดจำนวน FuA ต่อเทิร์น** (172-175) — จำกัดด้วย Charge (cap 4) เท่านั้น
- **`Reset_List` ของ E6 บวก `DEF_SHRED[AType::SKILL]`** (126) ซึ่งเป็นช่องที่ผูกกับ `AType` — ต้องให้ Skill สร้างด้วย `AType::SKILL` จริง ซึ่งไฟล์นี้ทำถูก
- **ไม่มี `Enemy_Death_List` / `AllyDeath_List`** — บัฟ `Archer A6` บนตัวเองไม่ต้องถอนตอนตายเพราะเป็นของตัวเอง แต่ถ้า Archer ตายแล้วฟื้นค่าจะค้าง
