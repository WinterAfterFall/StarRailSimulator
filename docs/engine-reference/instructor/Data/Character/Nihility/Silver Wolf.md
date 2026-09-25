`if (E2 หรือ act->isSameName(sw))`# `src/Defination/Data/Character/Nihility/Silver Wolf.h`
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`kit อ้างอิง: `docs/character-kit-reference/Silver Wolf.md` · namespace `SW` และ **ชื่อ unit เป็น `"SW"` ไม่ใช่ `"Silver Wolf"`** · **ไฟล์อ้างอิงของ debuff หลายชั้น (Bug 1/2/3) และการแปะ weakness ตามธาตุของทีม**
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`## ตาราง: ความสามารถ → โค้ด
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
`if (E2 หรือ act->isSameName(sw))`|---|---|---|
`if (E2 หรือ act->isSameName(sw))`| ธาตุ / path / energy ult | `SetCharBasicStats(107, 110, 110, E, Quantum, Nihility, "SW", Standard)` | 7 |
`if (E2 หรือ act->isSameName(sw))`| จำนวนเป้าที่ตั้งใจเล่นด้วย | `ptr->Adjust["SW Targets amount"] = 1;` | 28 |
`if (E2 หรือ act->isSameName(sw))`| **Basic ATK** | lambda `BA` — `addDamageInsByDebuff(..., "Bug 2")` ×3 | 30-42 |
`if (E2 หรือ act->isSameName(sw))`| **Skill** — แปะ weakness ตามธาตุของเพื่อน | lambda `Skill` — วน `charUnit[i]->Element_type[0]` หาธาตุที่ศัตรูยังไม่มี | 44-64 |
`if (E2 หรือ act->isSameName(sw))`| Skill — RESPEN ธาตุนั้น +20 · RESPEN รวม +13 | `debuffSingleApply(..., RESPEN[ธาตุ] 20, "SW Weakness", 3)` · `(..., RESPEN 13, "SW Res", 2)` | 54, 58 |
`if (E2 หรือ act->isSameName(sw))`| **Ultimate** — DEF_SHRED 45 ทุกตัว | `Ultimate_List` — AoE 380%×3 + `debuffAllEnemyApply(..., "SW Ult", 3)` | 78-114 |
`if (E2 หรือ act->isSameName(sw))`| **Talent** — Bug 1/2/3 | `When_attack_List` + `Toughness_break_List` (โค้ดเหมือนกัน) | 188-210, 212-226 |
`if (E2 หรือ act->isSameName(sw))`| **Technique** | `Start_game_List` — AoE 80% + `Dont_care_weakness = 100` | 165-181 |
`if (E2 หรือ act->isSameName(sw))`| energy +5 ต้นเทิร์นตัวเอง · +20 ต้นเกม | `Before_turn_List` · `Start_game_List` | 132-138, 182 |
`if (E2 หรือ act->isSameName(sw))`| **Minor traces** | `Reset_List` (มี `ATK_P += 50` ใต้คอมเมนต์ `//Trace`) | 116-130 |
`if (E2 หรือ act->isSameName(sw))`| **E1** — Ult คืน energy ตามจำนวน debuff (cap 5) | `if (ptr->Eidolon >= 1)` ใน Ult | 87-94 |
`if (E2 หรือ act->isSameName(sw))`| **E2** — ศัตรู VUL +20 ถาวร · Bug ติดจากการโจมตีของทุกคน | `debuffAllEnemyMark(..., "SW E2")` · `if (ptr->Eidolon >= 2 \|\| act->isSameName(sw))` | 185-187, 189 |
`if (E2 หรือ act->isSameName(sw))`| **E4** — Ult ยิง Additional DMG ตามจำนวน debuff | `if (ptr->Eidolon >= 4)` ใน Ult | 95-104 |
`if (E2 หรือ act->isSameName(sw))`| **E6** — DMG +100% | `Reset_List` | 126-128 |
`if (E2 หรือ act->isSameName(sw))`| AI: เทิร์นนี้กดอะไร | `Turn_func` — มีศัตรู (ตามจำนวนที่ตั้ง) ยังไม่ติด `"SW Res"` → Skill ไม่งั้น BA | 68-76 |
`if (E2 หรือ act->isSameName(sw))`| ถอน debuff ทุกชนิด | `After_turn_List` — 6 บล็อก | 140-162 |
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`## รากฐาน: debuff หลายชั้นที่เติมตามลำดับ
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))````cpp
`if (E2 หรือ act->isSameName(sw))`if (!enemy->getDebuff("Bug 1"))       debuffApply(sw, enemy, "Bug 1", 4);
`if (E2 หรือ act->isSameName(sw))`else if (!enemy->getDebuff("Bug 2"))  debuffSingleApply(sw, enemy, {{DEF_SHRED, 12}}, "Bug 2", 4);
`if (E2 หรือ act->isSameName(sw))`else {
`if (E2 หรือ act->isSameName(sw))`    debuffApply(sw, enemy, "Bug 1", 4);                       // ต่ออายุทั้งสอง
`if (E2 หรือ act->isSameName(sw))`    debuffSingleApply(sw, enemy, {{DEF_SHRED, 12}}, "Bug 2", 4);
`if (E2 หรือ act->isSameName(sw))`    if (debuffApply(sw, enemy, "Bug 3", 4)) {                 // ชั้นที่ 3 ลงได้ครั้งเดียว
`if (E2 หรือ act->isSameName(sw))`        enemy->atkPercent -= 10;
`if (E2 หรือ act->isSameName(sw))`        debuffSingle(enemy, {{SPD_P, -6}});
`if (E2 หรือ act->isSameName(sw))`    }
`if (E2 หรือ act->isSameName(sw))`}
`if (E2 หรือ act->isSameName(sw))````
`if (E2 หรือ act->isSameName(sw))`- **ใช้ค่าคืนของ `debuffApply` เป็นตัวกันลงซ้ำ** (208) ซึ่งเป็นวิธีที่ถูกต้อง — ต่างจาก `../Abundance/Gallagher.md` ที่ละเลยค่าคืนแล้วค่ารั่ว
`if (E2 หรือ act->isSameName(sw))`- **`Bug 1` ไม่มี stat** ใช้เป็นแค่ตัวนับชั้น → `After_turn_List` เรียก `isDebuffEnd(enemy, "Bug 1")` แบบทิ้งค่าคืน (152) เพื่อให้ helper เคลียร์สถานะให้
`if (E2 หรือ act->isSameName(sw))`- `addDamageInsByDebuff(..., "Bug 2")` ใน BA (38-40) ทำให้ BA **เล็งศัตรูที่ยังไม่ติด Bug 2** โดยอัตโนมัติ (ดู `Black Swan.md` รากฐานข้อ 5)
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`## รากฐาน: แปะ weakness ตามธาตุของเพื่อนร่วมทีม
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))````cpp
`if (E2 หรือ act->isSameName(sw))`for (int i = 1; i <= Total_ally; i++) {
`if (E2 หรือ act->isSameName(sw))`    if (enemy->Default_Weakness_type[charUnit[i]->Element_type[0]]) continue;   // มีอยู่แล้ว ข้าม
`if (E2 หรือ act->isSameName(sw))`    weaknessApply(sw, enemy, {charUnit[i]->Element_type[0]}, 3);
`if (E2 หรือ act->isSameName(sw))`    debuffSingleApply(sw, enemy, {{RESPEN, charUnit[i]->Element_type[0], AType::None, 20}}, "SW Weakness", 3);
`if (E2 หรือ act->isSameName(sw))`    sw->setBuffNote("SW Weakness num", i);                                      // จำว่าแปะธาตุของใคร
`if (E2 หรือ act->isSameName(sw))`    break;
`if (E2 หรือ act->isSameName(sw))`}
`if (E2 หรือ act->isSameName(sw))````
`if (E2 หรือ act->isSameName(sw))`- **`Default_Weakness_type[ธาตุ]`** = weakness ติดตัวของศัตรู (ต่างจาก weakness ที่แปะเพิ่ม)
`if (E2 หรือ act->isSameName(sw))`- **ต้องจำว่าแปะธาตุของใคร** ไว้ใน `buffNote` เพราะตอนถอนต้องรู้ว่าจะลบ RESPEN ของธาตุไหน (145-147) — เป็นเหตุผลเดียวกับที่ `../Harmony/Tingyun.md` ต้องจำผู้ถือบัฟ
`if (E2 หรือ act->isSameName(sw))`- `weaknessApply` overload นี้ไม่ได้ส่งชื่อ debuff (53) ต่างจาก `../Erudition/Anaxa.md` และ `../Destruction/FireFly.md`
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`## จุดที่ควรระวัง
`if (E2 หรือ act->isSameName(sw))`
`if (E2 หรือ act->isSameName(sw))`- **`When_attack_List` กับ `Toughness_break_List` มีโค้ด Bug เหมือนกันทั้งก้อน** (188-226) — ถ้าแก้ตัวเลขต้องแก้สองที่
`if (E2 หรือ act->isSameName(sw))`- **`After_turn_List` ถอน RESPEN ธาตุด้วย `charUnit[sw->getBuffNote("SW Weakness num")]`** (146) — `buffNote` เก็บ **เลขช่อง** ของเพื่อน ซึ่งเป็นค่าเดียวสำหรับศัตรูทุกตัว · ถ้าแปะธาตุต่างกันให้ศัตรูคนละตัว ตอนถอนจะใช้ธาตุของตัวหลังสุดกับทุกตัว
`if (E2 หรือ act->isSameName(sw))`- **`Bug 3` ถอนโดยไม่เช็คว่าเคยลงไหม** (158-161) — `isDebuffEnd` คืน true แล้วคืน `atkPercent` และ SPD เสมอ ซึ่งถูกต้องเพราะ `debuffApply` กันลงซ้ำไว้แล้ว
`if (E2 หรือ act->isSameName(sw))`- **`Reset_List` บวก `ATK_P += 50` ใต้คอมเมนต์ `//Trace`** (125) ไม่มีที่มาชัดเจน (อาการเดียวกับ `../Destruction/Saber.md`, `../Elation/Hibana.md`)
`if (E2 หรือ act->isSameName(sw))`- **`Turn_func` วนตาม `ptr->Adjust["SW Targets amount"]`** (69) ซึ่งตั้งเป็น 1 ตายตัวที่บรรทัด 28 → AI สนใจแค่ศัตรูตัวแรกเสมอ เว้นแต่มีใครแก้ `Adjust` จากข้างนอก
`if (E2 หรือ act->isSameName(sw))`- **ชื่อ unit เป็น `"SW"`** — ถ้ามีไฟล์อื่นเช็คชื่อ `"Silver Wolf"` จะไม่เจอ
