# `src/Defination/Data/Character/Erudition/Jade.h`

kit อ้างอิง: `docs/kit-reference/Character/Jade.md` · **ไฟล์อ้างอิงของ Follow-up ATK ที่ยิงเป็นชุดจากตัวนับ** · มี `//temp` (บรรทัด 10)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(103, 140, 140, E, Quantum, Erudition, "Jade", Standard)` | 18 |
| **Basic ATK** | `Basic_Atk(ptr)` — blast 90/30 | 126-140 |
| **Skill** — ติด Debt Collector ให้เพื่อน | `Skill(ptr)` — `AllyBuffAction` + `isHaveToAddBuff("Jade_Skill", 3)` → SPD +30% | 141-155 |
| **Ultimate** | `Ultimate_List` (`PRIORITY_ACTTACK`) — AoE 240%×3 + ตั้ง `Jade_Ultimate_stack = 2` | 45-59 |
| **Talent** — Pawned Asset | `Jade_Talent(ptr, amount)` → `buffStackSingle(ATK +0.5, CD +2.4, amount, cap 50, "Pawned_Asset")` | 246-255 |
| Talent — ครบ 8 แต้ม → FuA | `Jade_Fua(ptr)` — `while (stack > 8)` ยิงซ้ำ | 161-173 |
| **Follow-up ATK** | `Fua(ptr)` / `Fua_Enchance(ptr)` — AoE 5 ชุด | 174-245 |
| สะสมแต้มจากการโจมตีของเป้าที่ถูก Skill | `When_attack_List` — นับ `act->targetList.size()` | 100-112 |
| สะสมแต้มต้นเทิร์นของเป้าที่ถูก Skill | `Before_turn_List` → `Jade_Talent(ptr, 3)` | 90-93 |
| **Technique** | `Start_game_List` — AoE 50% + `Jade_Talent(ptr, 15)` | 73-87 |
| **Minor traces** | `Reset_List` | 61-68 |
| **E1** — นับเป้าอย่างน้อย 3 · FuA DMG +32% | `if (ptr->Eidolon >= 1 && temp < 3) temp = 3` · `buffSingle` ครอบ `Attack` | 109, 179-181 |
| **E2** — Pawned Asset ≥ 15 → CR +18 | `Jade_Talent` → `isHaveToAddBuff(ptr,"Jade_E2")` | 251-253 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` — บัฟ `Jade_Skill` ยังอยู่ → BA ไม่งั้น Skill | 36-43 |
| ศัตรูตาย → แต้ม +1 | `Enemy_Death_List` — **list นี้ไม่เคยถูกยิง** (ดู `../../README.md`) | 114-116 |

## รากฐาน: FuA ที่ยิงเป็นชุดจากตัวนับ

```cpp
void Jade_Fua(CharUnit *ptr){
    while (ptr->stack["Jade_Talent"] > 8) {
        ptr->stack["Jade_Talent"] -= 8;
        if (ptr->stack["Jade_Ultimate_stack"] > 0) { Fua_Enchance(ptr); ptr->stack["Jade_Ultimate_stack"]--; }
        else                                         Fua(ptr);
    }
    Deal_damage();
}
```
- **ลูปจ่ายทรัพยากรจนไม่พอ** แบบเดียวกับ `../Nihility/Luka.md` (EBA) และ `../Remembrance/Castorice.md` แต่ที่นี่ **สร้าง action ใหม่ทุกรอบ** ไม่ได้แก้ action เดิม
- `Deal_damage()` เรียกครั้งเดียวนอกลูป — ให้ทุก action ที่เข้าคิวถูกประมวลผลพร้อมกัน
- **`Jade_Ultimate_stack` คือโควตา FuA แบบเสริมพลัง** ที่ Ult เติมให้ 2 ครั้ง

## รากฐาน: ตัวนับสองชั้นที่มีหน่วยต่างกัน

| ตัวนับ | หน่วย | ใช้ทำอะไร |
|---|---|---|
| `stack["Pawned_Asset"]` | ชั้นบัฟ (cap 50) | ATK +0.5% / CD +2.4% ต่อชั้น — จัดการโดย `buffStackSingle` |
| `stack["Jade_Talent"]` | แต้มดิบ | ครบ 8 → ยิง FuA — บวก/ลบเอง |

**`Jade_Talent(ptr, amount)` เติมเฉพาะ `Pawned_Asset` ไม่ได้เติม `Jade_Talent`** — ตัวที่เติม `stack["Jade_Talent"]` มีที่เดียวคือ `When_attack_List` บรรทัด 110 · ชื่อฟังก์ชันกับชื่อ stack ตรงกันแต่คนละของ **เป็นจุดที่อ่านแล้วสับสนที่สุดในไฟล์**

## รากฐาน: บัฟชั่วคราวครอบ `Attack` (E1)

```cpp
if (ptr->Eidolon >= 1) buffSingle(ptr,{{Stats::DMG,AType::None, 32}});
Attack(act);
if (ptr->Eidolon >= 1) buffSingle(ptr,{{Stats::DMG,AType::None,-32}});
```
สำนวนเดียวกับ "เพิกเฉย DEF เฉพาะก้อนนี้" ของ `../Nihility/Black Swan.md` — ใช้ได้เพราะ `Attack()` คำนวณจบทันที

## จุดที่ควรระวัง

- **`while (stack > 8)` ใช้ `>` ไม่ใช่ `>=`** (163) → ต้องมี **9** แต้มถึงจะยิง FuA ครั้งแรก และเหลือค้าง 1 แต้มทุกครั้ง · ถ้า kit บอก "ครบ 8" ควรเป็น `>= 8`
- **`Fua` และ `Fua_Enchance` ตั้งชื่อ action เหมือนกันว่า `"Jade Fua"`** (176, 212) → แยกไม่ออกในล็อกและใน trigger ที่จับชื่อ
- **`Before_turn_List` เช็ค `chooseAllyBuff(ptr)->Atv_stats->Name == turn->Name`** (91) เทียบด้วยชื่อ ไม่ใช่ pointer
- **`Skill` ถอน SPD ใน `Before_turn_List` ด้วย `chooseAllyBuff(ptr)` สด** (96) ไม่ใช่ตัวที่ถือบัฟจริง → **ถ้าเป้าหมายเปลี่ยนระหว่างนั้น SPD จะถูกถอนผิดคน** · อาการเดียวกับที่ `../Harmony/Tingyun.md` แก้ด้วย `buffSubUnitTarget`
- **`Enemy_Death_List` เขียนไว้แล้วแต่ไม่ทำงาน** — ดู `../../README.md` หัวข้อ `Enemy_Death_List`
- **`setSpeedRequire` และ main stat ทางเลือกถูกคอมเมนต์ทิ้ง** (28-29)
- **`Increase_energy(charUnit[ptr->Atv_stats->num].get(), ...)`** (132, 147) อ้อมผ่าน index แทนที่จะใช้ `ptr` ตรง ๆ — รูปแบบเดียวกับ `Serval.h` และ `Pela.h`
