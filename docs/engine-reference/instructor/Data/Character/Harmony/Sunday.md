# `src/Defination/Data/Character/Harmony/Sunday.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/sunday.md` · **ไฟล์อ้างอิงของ `buffAllyTarget` — การจำผู้ถือบัฟข้ามเวลา** และของบัฟที่ต้องลงถึง memosprite ทุกจุด

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `SetCharBasicStats(96, 130, 130, E, Imaginary, Harmony, "Sunday", Standard)` | 9 |
| **ตั้งตัวเองเป็น driver** | `Driver_num = SDptr->Atv_stats->num;` | 17 |
| **Skill** — Benison + CR + advance | `Skill(ptr)` — `buffSingleChar` หลายก้อน + `Action_forward(100)` ทั้งตัวละคร summon และ memosprite | 253-296 |
| Skill — DMG +80% ถ้าเป้ามี summon ไม่งั้น +30% | `chooseCharacterBuff(ptr)->isAllyHaveSummon()` | 268-271 |
| **Ultimate** — Ode: CD ตาม CD ของ Sunday | `Ultimate_List` — `calculateCritdamForBuff(ptr, 30) + 12` | 43-106 |
| Ult — คืน energy ให้เป้า | `Max_energy > 200` → `Increase_energy(..., 20, 0)` ไม่งั้น `(..., 0, 40)` | 58-61 |
| **Talent** — Skill คืน SP ถ้าเป้ามี Ode | `Buff_List` — เช็คชื่อ action `"SD Skill"` | 183-187 |
| **A-trace** — energy ต้นเกม | `Start_game_List` → `Increase_energy(ptr, 25)` | 179-181 |
| **Technique** — DMG +50% ครั้งเดียว | `Skill` → flag `Technique_use` + `"The_Glorious_Mysteries"` | 279-282 |
| **Minor traces** | `Reset_List` | 108-117 |
| **E1** — DEF_SHRED (แยกค่าให้ summon) | `Skill` → `buffSingle` + `buffSingleChar` คู่กัน | 273-278 |
| **E2** — Ult ครั้งแรกคืน SP 2 · Ode ให้ DMG +30% | `buffCheck["Ult_first_time"]` · `if (ptr->Eidolon >= 2)` หลายจุด | 48-53, 70/92/100 |
| **E4** — energy +8 ต้นเทิร์นตัวเอง | `Before_turn_List` | 121-123 |
| **E6** — CR stack + แปลง CR ส่วนเกินเป็น CD | `buffStackChar(..., "The_Sorrowing_Body", 4)` · `Stats_Adjust_List` | 55-56, 189-195 |
| AI: เทิร์นนี้กดอะไร | `Turn_func` → `Skill(ptr)` เสมอ | 22-24 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — อย่ากดถ้าเป้าใกล้เต็ม energy อยู่แล้ว (มี escape hatch ให้ Saber) | 26-38 |

## รากฐาน: `buffAllyTarget` — จำว่าใครถือบัฟอยู่จริง

```cpp
ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix", chooseCharacterBuff(ptr));
...
ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")   // คืน AllyUnit* ที่ถือบัฟอยู่จริง
...
ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix", nullptr);   // ตอนหมดอายุ
```
**ปัญหาเดียวกับ `Tingyun.md`** — `chooseCharacterBuff(ptr)` คืนเป้าที่ "ตั้งใจบัฟตอนนี้" ซึ่งเปลี่ยนได้ แต่ตอนถอนบัฟต้องถอนจาก **คนที่ถืออยู่จริง** · Sunday ใช้ `buffAllyTarget` (ตระกูลเดียวกับ `buffSubUnitTarget` ของ Tingyun) เก็บ pointer ไว้

**ทุกครั้งที่ ult ซ้ำ ต้องถอนของเจ้าเก่าก่อน** (63-83) — เช็ค `!isHaveToAddBuff(...)` = บัฟยังอยู่ → ถอนจาก `getBuffAllyTarget` แล้วค่อยลงให้คนใหม่

## รากฐาน: บัฟที่ต้องลงถึง memosprite ทุกจุด

Ode ของ Sunday ต้องลงทั้งตัวละครและ memosprite **แต่แยกกัน** เพราะต้องเช็ค `isTargetable()` รายตัว → โค้ดวน `memosprite` **ซ้ำในทุกจุด**: ตอนลง (94-101), ตอนถอนเพราะ ult ซ้ำ (73-81), ตอนหมดอายุ (133-141), ตอนคำนวณใหม่ (205-209), ตอนตาย (215-221)

> `buffSingleChar` ทำให้ในคราวเดียวได้ แต่ที่นี่ต้องเช็ค `buffCheck` รายตัวก่อนถอน จึงทำเองทุกที่

## รากฐาน: E6 — แปลง CR ส่วนเกิน 100% เป็น CD

```cpp
if (E6 && target->getStack("The_Sorrowing_Body") > 0 && StatsType == Stats::CR) {
    double temp = (calculateCritrateForBuff(target, 100) - 100) * 2;
    if (temp < 0) temp = 0;
    buffSingle(target, {{CD, AType::TEMP, temp - target->getBuffNote("The_Sorrowing_Body")}});
    buffSingle(target, {{CD, AType::None, temp - target->getBuffNote("The_Sorrowing_Body")}});
    target->buffNote["The_Sorrowing_Body"] = temp;
}
```
**`Stats_Adjust_List` ที่ผูกกับเป้าหมาย ไม่ใช่ตัวเอง** — guard ด้วย `getStack` ของเป้า ไม่ใช่ชื่อ · `buffNote` เก็บที่เป้าหมาย (เหมือน `Bronya.md`)

## จุดที่ควรระวัง

- **`Stats_Adjust_List` มี 2 ก้อนตรรกะในฟังก์ชันเดียว** (188-212) — ก้อน E6 อยู่ก่อน `if (target->Atv_stats->Name != "Sunday") return;` (197) จึงทำงานกับทุกคน ส่วนก้อน Ode อยู่หลัง guard · อ่านแล้วเข้าใจผิดง่ายว่า guard ครอบทั้งฟังก์ชัน
- **`Stats_Adjust_List` ก้อน Ode เช็ค `target->getBuffCheck("Ode...")` ของ Sunday เอง** (198) แต่ Sunday ไม่ใช่คนถือบัฟ — บัฟอยู่ที่เป้าหมาย · บรรทัด 84 ตั้ง `ptr->buffCheck["Ode..."] = 1` ไว้บน Sunday ด้วยเพื่อให้ guard นี้ผ่าน ซึ่งเป็นการใช้ `buffCheck` สองความหมาย (สถานะ ult ของตัวเอง vs ผู้ถือบัฟ)
- **`AllyDeath_List` ของ E6 เรียก `buffResetStack` โดยไม่เช็ค `isBuffGoneByDeath` ก่อน** (236-238) ต่างจากทุกบล็อกรอบข้าง → ถอน stack ของคนที่ตายแม้ไม่เคยมีบัฟ
- **`E1` ลง DEF_SHRED สองครั้งด้วยค่าต่างกัน** (273-278): `buffSingle` ให้ตัวละคร 16 + summon 24 แล้ว `buffSingleChar` ให้ทั้งตัวละครและ memosprite อีก 40 · ตอนถอน (156-162) เลือกสาขาตาม `turn->side` ซึ่ง**ไม่ตรงกับตอนลงที่ลงทั้งสองแบบพร้อมกัน** → มีโอกาสถอนไม่ครบ
- **`ult_condition(CharUnit*)` คืน `false` เสมอ ไม่มีใครเรียก** (298-301) — โค้ดตายพร้อมโค้ดเดิมที่ถูกคอมเมนต์ · เหมือน `Jingyuan.h` และ `The_Herta.h`
- **`addUltImmediatelyUseCondition` ถูกคอมเมนต์ทิ้ง** (39-42)
- **`Before_turn_List` ตอนหมดอายุ Ode ไม่เช็ค null ก่อนอ่าน memosprite** (133) — มี `return` ที่บรรทัด 125 กันไว้แล้วถ้า target เป็น null แต่ถ้า `getBuffCheck` เป็นเท็จจะข้ามบล็อกแรกแล้วมาวน memosprite ต่อ ซึ่งยังปลอดภัยเพราะ target ไม่ null
