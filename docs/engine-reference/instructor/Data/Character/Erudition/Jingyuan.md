# `src/Defination/Data/Character/Erudition/Jingyuan.h`

kit อ้างอิง: `docs/kit-reference/Character/Erudition/jing-yuan.md` · **ไฟล์อ้างอิงเดียวของระบบ `summon`** (ต่างจาก memosprite ของ path Remembrance)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(99, 130, 130, E, LIGHTNING, ERUDITION, "Jingyuan", STANDARD)` | 15 |
| **สร้าง Lightning-Lord** | `setSummonStats(ptr, 60, "LL")` — SPD 60 | 108 |
| **Basic ATK** | `basicAtk(ptr)` — 55% + 45% สองจังหวะ | 158-170 |
| **Skill** | `skill(ptr)` — AoE 3 ชุด + CR +10% 2 เทิร์น + LL stack +2 | 171-203 |
| **Ultimate** | `ultimateList` (`PRIORITY_ACTTACK`) — AoE 200%×3 + LL stack +3 | 41-62 |
| **Talent** — LL โจมตีตามจำนวน stack | `summonList[0]->turnFunc` — วน `addDamageIns` ตาม `stack["LL_stack"]` | 109-155 |
| LL stack ≥ 6 → CR +25 (เฉพาะ Summon) | `statsType[Stats::CR][AType::SUMMON] += 25` ครอบ `attack` | 114-135 |
| **Technique** | `startGameList` — LL stack +3 + SPD +30 | 97-104 |
| **Minor traces** | `resetList` (ตั้งค่าเริ่มต้น LL ด้วย) | 82-95 |
| **E1** — ดาเมจข้างเคียงของ LL แรงขึ้น | `if (ptr->eidolon >= 1)` ในลูปของ LL | 119-128 |
| **E2** — หลัง LL ตี → Jingyuan DMG +20% | `buffSingle(..., "Swing_Skies_Squashed", 2)` + ถอนใน `afterTurnList` | 141-148, 72-78 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` — SP ไม่พอ หรือเทิร์นแรกในโหมด Negative → BA ไม่งั้น Skill | 33-39 |

## รากฐาน: `summon` vs `memosprite`

| | `summon` (`setSummonStats`) | `memosprite` (`setMemoStats`) |
|---|---|---|
| ใช้กับ | Jingyuan (ไฟล์นี้) | path Remembrance ทั้งหมด |
| เข้าถึง | `ptr->summonList[0]` | `ptr->memosprite` / `getMemosprite()` |
| มี HP ของตัวเอง | ไม่ | มี |
| ผู้กระทำของ action | **เจ้าของ** (`jyPtr`) ไม่ใช่ตัว summon | ตัว memosprite เอง |
| `Side` | `Side::ALLY` | `Side::MEMOSPRITE` |

**action ของ LL ถูกสร้างในนามของ Jingyuan** (บรรทัด 112: `make_shared<AllyAttackAction>(AType::FUA, jyPtr, ...)`) แล้วเติม `addAttackType(AType::SUMMON)` — ต่างจาก memosprite ที่ส่งตัวเองเป็นผู้กระทำ · จึงใช้ `statsType[...][AType::SUMMON]` เป็นช่องแยก stat ของ summon ออกจากของเจ้าของ

> summon เป็นระบบเก่าที่มีแผน refactor ให้เหลือแค่ `ActionValueStats` — ดู `future-improvements.md` ข้อ 4

## รากฐาน: ความเร็วของ summon เป็นกลไกหลัก

```cpp
// skill / ULT:
if (ptr->stack["LL_stack"] >= 10) {
    ptr->summonList[0]->atvStats->flatSpeed = 70;        // ตั้งค่าตรง ๆ
    ptr->summonList[0]->speedBuff({FLAT_SPD, AType::NONE, 0});   // แจ้ง engine ให้คำนวณ atv ใหม่
} else {
    ptr->summonList[0]->speedBuff({FLAT_SPD, AType::NONE, 20});  // เพิ่มทีละขั้น
}
// หลัง LL ตี:
turn->flatSpeed = 0;   ptr->stack["LL_stack"] = 3;
```
LL ไม่ได้ถูกเรียก/ยุบ แต่ **ขยับเร็วขึ้นตามจำนวน stack** จนได้เทิร์น แล้วรีเซ็ตกลับ · `speedBuff(...)` ต้องเรียกเสมอแม้ค่าเป็น 0 เพราะเป็นตัวสั่งให้ engine คำนวณ action value ใหม่

## รากฐาน: ประกอบดาเมจตามจำนวน stack ใน callback

```cpp
for (int i = 1; i <= ptr->stack["LL_stack"]; i++) {
    act->addDamageIns(DmgSrc(ATK, 66, 5), DmgSrc(ATK, 66*0.25, 5));   // 2 args = main + adjacent
}
```
จำนวน hit ขึ้นกับ stack ณ เวลาที่ LL ได้เทิร์น จึงต้องประกอบใน callback (เหมือน `The_Herta.md`, `FireFly.md`) · `setTurnReset(true)` (151) บอกให้รีเซ็ตเทิร์นของ summon หลังยิงเสร็จ

## จุดที่ควรระวัง

- **`turnFunc` มีลำดับ `||` / `&&` ที่กำกวม** (34):
  ```cpp
  if ((sp <= spSafety) || allyPtr->atvStats->turnCnt == 1 && spMode == SPMode::NEGATIVE)
  ```
  C++ ให้ `&&` ผูกแน่นกว่า `||` → อ่านเป็น `(sp <= spSafety) || (turnCnt == 1 && spMode == NEGATIVE)` ซึ่งน่าจะตรงเจตนา แต่ไม่มีวงเล็บกำกับ
- **`tempTurnCondition` / `tempUltCondition` คืน `true` เสมอและไม่มีใครเรียก** (207-212) — โค้ดตายแบบเดียวกับ `stackHertaCheck` ที่เพิ่งรื้อฟื้นใน `The_Herta.md`
- **`resetList` ตั้งค่า LL** (92-94) ทั้งที่ `setSummonStats` ถูกเรียกทีหลังที่บรรทัด 108 — ทำงานได้เพราะ `resetList` รันตอนเริ่มการต่อสู้ ไม่ใช่ตอน `setup` แต่เป็นลำดับที่อ่านแล้วสับสน (อาการเดียวกับ `FireFly.h`)
- **`afterTurnList` guard ด้วย `ptr->atvStats->num == turn->num && turn->side == Side::ALLY`** (66) — เทียบเลขช่อง ซึ่ง LL อาจใช้เลขเดียวกับเจ้าของ ทำให้บัฟถูกถอนตอนจบเทิร์นของ LL ด้วย
- **CR +25 ของ stack ≥ 6 เขียน `statsType` ตรง ๆ** (115, 134) ไม่ผ่าน `buffSingle` → ไม่ยิง `statsAdjust` (ที่นี่ไม่มีผลเพราะไม่มีสูตรที่อิง CR)
- **ไม่มี `addUltCondition`** — กด ult ทันทีที่ energy เต็มเสมอ ทั้งที่จังหวะ ult สัมพันธ์กับ stack ของ LL โดยตรง
