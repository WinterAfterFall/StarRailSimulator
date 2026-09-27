# `src/Defination/Data/Character/Harmony/Ruan_Mei.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/ruan-mei.md` · namespace `RuanMei` (ไม่มี `_`) แต่ชื่อ unit เป็น `"Ruan_Mei"` · **ซัพพอร์ตสาย Break** — ใช้ `calBreakDamage` เป็นแหล่งดาเมจหลัก

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(104, 130, 130, E, ICE, HARMONY, "Ruan_Mei", STANDARD)` | 9 |
| **Basic ATK** | `basicAtk(ptr)` — single 100%/10 | 138-148 |
| **Skill** — ทีม DMG +68% / Break Effect +50% | `skillFunc(ptr)` — `AllyBuffAction` + `isHaveToAddBuff("Mei_Skill", 3)` | 149-163 |
| **Ultimate** — ทีม RESPEN +25% | `ultimateList` + `isHaveToAddBuff("RuanMei_Ult", 2)` | 33-47 |
| Ult — ศัตรูที่โดนตีติด `RuanMei_Ult_bloom` | `afterAttackActionList` (เฉพาะตอน ult ยังอยู่) | 118-124 |
| bloom — ข้ามเทิร์นศัตรู + ถอยคิว + ดาเมจ Break | `beforeTurnList` → `turnSkip = 1` + `actionForward(ติดลบ)` + `calBreakDamage` | 102-112 |
| **A-trace** — ทีม BE +20% / เพื่อน SPD +10% | `whenOnFieldList` → `buffAllAlly` + `buffAllAllyExcludingBuffer` | 59-64 |
| **Talent** — ทุกครั้งที่มีการ Break → ดาเมจเพิ่ม | `toughnessBreakList` → `calBreakDamage(act, target, 1.2)` | 126-132 |
| **Technique** | `startGameList` — ทำ Skill ทันทีโดยไม่กิน SP + `setTurnReset(false)` | 66-85 |
| energy +5 ต้นเทิร์นตัวเอง | `beforeTurnList` | 94-95 |
| **Minor traces** | `resetList` | 49-57 |
| **E1** — Ult ให้ DEF_SHRED +20 ด้วย | `if (ptr->eidolon >= 1)` ทั้งตอนลงและตอนถอน | 41, 98 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — บัฟ Skill หมดแล้ว → Skill ไม่งั้น BA | 25-31 |

## รากฐาน: `turnSkip` — ทำให้ศัตรูข้ามเทิร์น

```cpp
if (turn->side == Side::ENEMY && turnSkip == 0) {
    if (enemyUnit[turn->num]->debuffCheck["RuanMei_Ult_bloom"] == 1) {
        turnSkip = 1;                                        // global: บอก engine ให้ข้ามเทิร์นนี้
        debuffRemove(enemyUnit[turn->num].get(), "RuanMei_Ult_bloom");
        actionForward(enemyUnit[turn->num]->atvStats.get(), -10 - calculateBreakEffectForBuff(ptr, 20));
        calBreakDamage(act, enemyUnit[turn->num].get(), 0.5);
    }
}
```
- **`turnSkip` เป็น global flag** ที่ engine อ่านตอนเริ่มเทิร์น (`Function/Event/Event.h:13` ใช้ `if(!turnSkip)` กับ freeze ด้วย) — เป็นทางเดียวที่ตัวละครสั่งให้ข้ามเทิร์นศัตรูได้
- **`actionForward` ด้วยค่าติดลบ = ถอยคิว** ยิ่ง Break Effect สูงยิ่งถอยไกล
- เช็ค `turnSkip == 0` ก่อนเพื่อไม่ให้ซ้อนกับตัวอื่นที่สั่งข้ามในเทิร์นเดียวกัน

## รากฐาน: `buffAllAllyExcludingBuffer`

`buffAllAllyExcludingBuffer(ptr, {stat})` (63) — บัฟทุกคน **ยกเว้นตัวเอง** · มีตระกูลเดียวกันสำหรับ extend (`extendBuffTimeExcludingBuffer`, `Declaration/Function/Combat/Buff_Stats.h:16-19`) · ใช้กับ trace ที่ kit ระบุว่า "เพื่อนคนอื่น" ไม่รวมตัวเอง

## รากฐาน: บัฟทีมที่ไม่ได้ track รายคน

Skill และ Ult ของ Ruan Mei ใช้ `buffAllAlly` แบบไม่มีชื่อบัฟ แล้วคุมอายุด้วย **บัฟชื่อเดียวบนตัว Ruan Mei เอง** (`Mei_Skill` / `RuanMei_Ult`) — ตอนหมดอายุก็ `buffAllAlly` ด้วยค่าติดลบทั้งทีม (88-100)

**ข้อดี**: โค้ดสั้น ไม่ต้องวน `buffTargetList` · **ข้อเสีย**: ถ้าเพื่อนตายหรือเข้าสนามระหว่างที่บัฟ active ค่าจะไม่ตรง (ไม่มี `allyDeathList` รองรับ) — ต่างจาก `Bronya.md` ที่ track รายคนผ่าน `buffNote`

## จุดที่ควรระวัง

- **`afterTurnList` ว่างเปล่า** (115-116) — push lambda ที่ไม่ทำอะไรเลย
- **Technique copy โค้ด Skill ทั้งก้อน** (69-82) ต่างจาก `skillFunc` แค่ไม่มี `genSkillPoint(-1)` และมี `setTurnReset(false)` — อาการเดียวกับ `../Elation/YaoGuang.md`
- **ชื่อ action ของ Technique เป็น `"RM SKill"`** (70) สะกดต่างจาก `"RM Skill"` ของ Skill จริง (152) — ถ้ามี trigger ไหนจับชื่อ action จะแยกกัน
- **`toughnessBreakList` ไม่ guard ว่าใคร break** (126-132) → Talent ทำงานทุกครั้งที่มีการ break จากใครก็ได้ ซึ่งตรงกับ kit แต่ `act` ที่สร้างใช้ `ptr` เป็นผู้กระทำเสมอ
- **`afterAttackActionList` ไม่ guard ผู้โจมตี** (118-124) → ติด bloom ให้ศัตรูที่โดนตีจาก action ของ **ใครก็ได้** รวมถึง DoT และ additional · ตรงกับ kit ที่ Ult ของ Ruan Mei มีผลกับทั้งทีม แต่ควรตรวจว่ามากเกินไปไหม
- **`calBreakDamage` ถูกเรียกโดยส่ง `act` ที่ไม่ได้ `addToActionBar`** (108-110, 127-131) — ใช้ action เป็นแค่ภาชนะ เหมือน Technique ของ `../Erudition/Rappa.md`
