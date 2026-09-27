# Character Implementation Notes

บันทึกหลักการเขียน / กลไกของ engine ที่ได้จากการอ่านโค้ด `src/Defination/Data/Character/**`
+ case study การ audit `Tingyun.h`

> ตอนนี้รวม **general** กับ **Tingyun** ไว้ไฟล์เดียวก่อน — พอมีข้อมูลมากกว่านี้ค่อยแยก

---

# ส่วนที่ 1 — หลักการทั่วไป

## 1. โครงไฟล์ตัวละคร

- **1 ตัวละคร = 1 namespace** · entry เดียว `void setup(int E, function<void(CharUnit*)> LC, Relic, Planar)`
- ในโครง: `setCharBasicStats(spd, maxEnergy, ultCost, E, element, path, "Name", type)` → `setAllyBaseStats(hp, atk, def)` → `pushSubstats` / `setTotalSubstats` / `setRelicMainStats` / `setSpeedRequire` → `lc(ptr); Relic(ptr); Planar(ptr);`
- `AllyUnit *xxxptr = ptr;` alias (CharUnit* → AllyUnit* implicit)
- **พฤติกรรม = การ push lambda เข้า trigger list** พร้อม `PRIORITY_*` + capture `ptr`:
  `ultimateList` · `resetList` · `beforeTurnList` · `afterTurnList` · `startGameList` · `startWaveList` · `whenAttackList` · `allyDeathList` · `statsAdjustList` · `buffList` · `whenOnFieldList` · ...
- `ptr->turnFunc = [...]() { ... }` = **AI เลือก action ต่อเทิร์น**
- `ptr->addUltCondition([...]() -> bool { ... })` = **AI จังหวะ ult** — stack ได้หลายอัน (ต้อง true หมด), ถูกเรียก**บ่อยมาก** (ทุก `allUltimateCheck`) → **ต้องเป็น predicate ล้วน ห้าม side-effect**

### สไตล์การนิยาม ability

| แบบ | ที่ไหน | ไฟล์ตัวอย่าง |
|---|---|---|
| **ใหม่** | `function<void()> BA = [...]() {...};` / `function<void()> skill = ...` อยู่ใน `setup` ครอบด้วย `#pragma region Ability` ... `#pragma endregion` **ก่อน** `turnFunc` (ซึ่ง capture `BA`, `skill` แล้วเรียก `skill()` / `ba()`) · helper อื่นก็เป็น local lambda | Cerydra, Hibana, Dahlia, Tingyun (หลัง refactor) |
| **เก่า** | forward-declare `void skill(CharUnit*)` ที่ namespace scope, นิยามท้ายไฟล์หลัง `setup` | Robin, Mydei, Aglaea, Sunday |

## 2. Level ของ ability (convention)

| | Basic ATK | Skill / Ultimate / Talent |
|---|---|---|
| **5★** | Lv.6 | Lv.10 |
| **4★** (สมมติ E6) | Lv.7 (E3 +1) | Lv.12 (E5 +2 skill/talent, E3 +2 ult) |

- 4★ = **E6 เสมอ** → eidolon effect E1‑E6 active หมด (`eidolon` field ตั้ง 6)
- ข้อมูล public (prydwen "Lv. 10") = **base ของ 5★** — สำหรับ 4★ ต้องบวก E3/E5 ก่อนเทียบ (เลข ~+10% จาก Lv.10)
- **eidolon effect** gate ด้วย `if (ptr->eidolon >= N)` inline ทุกจุดที่เกี่ยว → ต้องเติม check **ทุก code path** ที่ effect นั้นแตะ
  - ⚠️ pitfall: Tingyun E4 เคยมีที่ skill-hit additional แต่ลืม talent-hit
- **minor traces** hardcode เป็น stat บวกดิบใน `resetList` + comment `// relic` `// substats`

## 3. Damage

- `DmgSrc(DmgSrcType::ATK, multiplier_percent, toughness)` — multiplier เป็นจำนวนเต็ม %
- **`addDamageIns` 1 ครั้ง = 1 จังหวะการตี (hit beat)** — มี toughness ของจังหวะนั้นเอง · ในจังหวะเดียว**ตีได้หลาย unit** (joint attack เช่น Aglaea+Garmentmaker, Castorice+Netherwing) · multi-hit = เรียกหลายครั้ง
- **Additional DMG** (`AType::ADDTIONAL`): scaling source **แล้วแต่ตัวละคร** ตาม kit ระบุ
  - เช่น Tingyun additional สเกล ATK ของ**เพื่อนที่ถือบัฟ** → `make_shared<AllyAttackAction>(AType::ADDTIONAL, <holder>, ...)`
- **Additional DMG ≠ Follow-up ATK** — คนละ AType คนละ trigger semantics (Tingyun ไม่มี FUA)

## 4. ระบบบัฟ

### buffSingle 2 แบบ

- **ไม่มีชื่อ** `buffSingle(u, {{stat, AType, v}})` → `statsType[stat][AType] += v` **ทันที ถาวร ไม่ track** · ใช้ตอน "ถอนบัฟ" (ใส่ค่าลบ)
- **มีชื่อ** `buffSingle(u, {...}, "Name", extend)` → ผ่าน `isHaveToAddBuff(u, name, extend)`:
  1. `extendBuffTime` → `buffEnd[name] = turnCnt + extend` (**ทำทุกครั้ง** = refresh timer)
  2. `buffCheck[name] == 1` → return false → **ไม่บวก stat ซ้ำ**
  3. ไม่งั้น set check = 1 → บวก stat
  - re-cast = ต่อเวลา **ไม่ stack**

### framework track แค่ 2 อย่างต่อชื่อ

`buffCheck[name]` (bool) + `buffEnd[name]` (turnCnt ที่หมด) — **ไม่เก็บว่าบวก stat เท่าไหร่**
→ apply-site `+v` กับ remove-site `-v` ต้อง **match มือ** ข้ามฟังก์ชัน · เลื่อน = stat drift เงียบ ๆ

### จุดถอนบัฟ

| path | เครื่องมือ | เงื่อนไข |
|---|---|---|
| หมดเวลาปกติ | `isBuffEnd(u, name)` (ปกติใน `afterTurnList`) | `u.turnCnt == buffEnd[name]` **และเป็นเทิร์นของ u** · **ไม่เช็ค buffCheck** · เคลียร์ check+countdown แล้วคืน true |
| unit ตาย | `isBuffGoneByDeath(u, name)` (ใน `allyDeathList`) | ถ้า `getBuffCheck(name)` → force-clear check+countdown → true |
| re-target / dispel | `isBuffGoneByDeath` (ชื่อสื่อ "death" แต่เป็น primitive เดียวที่ force-remove ได้) | — |

- **ต้องเคลียร์ทั้ง check + countdown** เวลา dispel — ถ้าเหลือ countdown ค้าง `isBuffEnd` อาจยิง `-v` ซ้ำ (แต่ในทางปฏิบัติ `turnCnt` ≥ 1 หลังเทิร์นแรก ค่า countdown 0 เลยไม่ค่อย false-fire)
- จะ **stack** จริง ๆ → ห้ามใช้ named `buffSingle` · ใช้ `BuffStack.h` (`buffStackSingle` / `buffResetStack`)

### ชื่อบัฟ

- string key · ใช้ชื่อ trace/eidolon จริงในเกม
- **prefix ด้วยชื่อตัวละครหรือแหล่งบัฟ** — `buffCheck`/`buffEnd` เป็น map **แยกต่อ `AllyUnit` แต่ละตัว** ชื่อเดียวกันบนเป้าหมายเดียวกันใช้ flag และวันหมดอายุร่วมกัน แม้จะมาจากผู้แจกคนละคน จึงควรตั้งชื่อให้แยกเอฟเฟกต์ที่ตั้งใจให้เป็นคนละบัฟ ส่วนเป้าหมายคนละตัวมี map แยกกัน
- แนะนำ: buff name + magnitude เป็น `const string` / `constexpr` constant ที่ namespace scope → apply/remove อ้าง symbol เดียว
- (ไฟล์เก่าบางตัวจงใจไม่ใส่ชื่อ เมื่อรู้ว่าบัฟไม่มีทางซ้อน — convention ใหม่ = ใส่ชื่อ+prefix เสมอ)

### duration +1 quirk

ลงบัฟ**ตอนเทิร์นของ holder** (`phaseStatus == PhaseStatus::BEFORE_TURN`) → นับ duration เกิน 1
→ ในเกมนี้กระทบ **เฉพาะ ult ของ Tingyun กับ Bronya** — ชดเชยด้วย `extend - 1` เมื่อ `turn->name == target && phaseStatus == BEFORE_TURN`

### single-target buff "latest target only"

ใช้ `ptr->setBuffSubUnitTarget(name, holder)` / `getBuffSubUnitTarget(name)`
- framework map `unordered_map<string, AllyUnit*>` บน CharUnit · reset → `nullptr` ทุกรอบ ([Stats_Reset.h:54](../src/Defination/Function/Setup/Stats_Reset.h))
- เก็บ "**ใครถือบัฟนี้จริง**" แยกจาก `chooseAllyBuff(ptr)` (ซึ่งอ่าน `currentCharNum` สด อาจเปลี่ยนไปแล้ว)
- ตอน re-apply: ถ้า tracked holder ≠ target ใหม่ และยังติดบัฟ → strip จากตัวเก่า → set tracker = target ใหม่
- `buffAllyTarget` = พี่น้องระดับ CharUnit granularity (Sunday ใช้)

### SPD / AType::NONE พิเศษ

- บัฟ `SPD_P`/`FLAT_SPD` ใน `buffSingle` → route ผ่าน `speedBuff()` + `ahaSpeedAdjust()` (ต้อง recompute action value + ระบบ Aha)
- บัฟ `AType::NONE` → เรียก `statsAdjust(u, stat)` ต่อ → จุดชนวน `statsAdjustList` (ให้บัฟ snapshot re-evaluate) · AType อื่นไม่ trigger

### memosprite สืบ stat จากเจ้าของ

`memospriteReset()` รันใน `reset()` **หนึ่งครั้งต่อ run** ก่อน `setStats()` และ `startGame()` ไม่ได้รันตอนเริ่มแต่ละ wave: ก๊อป `statsType` + `statsEachElement` ของเจ้าของทั้งก้อนใส่ memo (`FLAT_HP` คูณ `unitHpRatio` แล้วบวก `fixHP`) จากนั้น `setStats()` เพิ่ม substats ที่เลือกให้ทั้งเจ้าของและ memo

- บัฟ memo หลังจุดนั้น: `buffSingleChar` (เจ้าของ + memo) หรือ `buffAllMemosprite`; memo ที่ถูก summon ใน wave แรกยังอยู่ต่อใน wave ถัดไปของ run เดียวกัน
- `baseSpeed` ของ memo คำนวณตอน `memospriteReset()` จาก `fixSpeed + calculateSpeedOnStats(owner)*Unit_Speed_Ratio/100`; `setStats()` เพิ่ม flat SPD ตาม ratio ให้ภายหลัง จึงไม่คำนวณ `baseSpeed` ใหม่ตามบัฟ speed ของเจ้าของระหว่างต่อสู้
- รายละเอียด: [`engine-reference/instructor/Function/Setup/Stats_Reset.md`](engine-reference/instructor/Function/Setup/Stats_Reset.md)

## 5. Energy

- `increaseEnergy(ptr, E)` → `+ E * Energy_recharge/100` (**ทั้งก้อนคูณ ERR**) — ใช้ skill/basic energy gain
- `increaseEnergy(ptr, percent, flat)` → `+ (percent% ของ maxEnergy) + flat` — **ทั้งคู่ไม่คูณ ERR** · `percent` = %-of-max (Huohuo/Sunday/FireFly), `flat` = energy คงที่ (technique, Tingyun ult 50)
- `ultUseCheck(ptr)`: มีชีวิต + `currentEnergy >= ultCost` + `ultCondition` ทุกตัว true → หัก cost, `increaseEnergy(ptr,5)`, fire `whenUseUltList`

## 6. Framework helper

| helper | หมายเหตุ |
|---|---|
| `chooseAllyBuff(ptr)` | `currentMemoNum == 0` เลือก `charUnit[currentCharNum]`; ค่า `1` เลือก `memosprite` (ถ้าไม่มี memosprite คืนตัวละคร) · **preset** ไม่ใช่ dynamic best-DPS · `currentCharNum`/`currentMemoNum` reset เป็น `default*` ต่อ **run** (`Stats_Reset.h:34-35`) |
| `chooseCharacterBuff` / `chooseEnemyTarget` | เวอร์ชัน CharUnit / Enemy |
| `genSkillPoint(ptr, n)` | `-1` ตอน skill, `+1` ตอน basic |
| `attack(act)` | resolve `AllyAttackAction` → สร้างความเสียหาย · จุดเข้าดาเมจหลัก |
| `statsAdjust(ptr, stat)` | fire `statsAdjustList` |
| `CharCmd::printUltStart/printUltEnd` | log |
| `allyList` | `vector<AllyUnit*>` รวม**ทั้ง character และ memosprite** |

## 7. Special-casing / cut mechanics

- **patch เฉพาะกรณี > general solution** — heuristic + รายชื่อ exception (`isSameName("Saber")`, `maxEnergy == 0`)
- **ตัดกลไกที่ implement ยาก โดยมีเหตุผล** — เช่น Tingyun Benediction "cap 25% ของ ATK Tingyun" ตัดทิ้ง เพราะ ATK Tingyun ที่ build แล้วสูงพอเสมอ (cap ไม่เคย bind)
- `TECHNIQUE` field: `int` default 1 · ทุกตัว = bool `if (TECHNIQUE == 1)` · **Tingyun ตัวเดียว** set `= 2` + `50 * TECHNIQUE` (เธอเป็นตัวเดียวที่ technique ให้ energy) — one-off ตั้งใจ · `if (TECHNIQUE == 1)` บน Tingyun = false เงียบ ๆ
- **forced taunt (ดึง aggro บังคับ)** — `enemy->tauntList` เป็น field per-enemy · `enemy->addTaunt(ally)` (มี dedup) → enemy single-target attack เล็งแค่ตัวใน list ของ enemy ตัวนั้น (AoE ไม่สน) · lifecycle pattern Mydei = ผูกกับ debuff (`debuffApply(...,"Name",turns)` + `addTaunt`) แล้ว `afterTurnList` เช็ค `isDebuffEnd(e,...)` → `e->removeTaunt(ally)` (แยกอิสระต่อ enemy ไม่ต้องนับ) · ดู [`engine-reference/instructor/Class/ActionData/EnemyActionData.md`](engine-reference/instructor/Class/ActionData/EnemyActionData.md)
- **taunt +X%** — `ptr->tauntIncreaseChange(X)` → `taunt = baseTaunt · (1 + X/100)` · `calHitChance(pool)` ใช้ `taunt` ตัวนี้อยู่แล้ว ไม่ต้องแตะอะไรเพิ่ม · ยังไม่มีตัวละครไหนใช้ · ⚠️ ถ้าเป็น memosprite ต้องเรียกใน `whenOnFieldList` (หลัง `memospriteReset`) ไม่ใช่ `resetList`

## 8. Debug — buff drift

รัน sim → ดู stat ที่ ATV **1000 / 2000 / 3000 / 4000 / 5000**
- stat ค่อย ๆ **ลดลงเรื่อย ๆ** → บัฟถูกถอนมากกว่าใส่ → **บั๊ก**
- stat นิ่ง/ขึ้นลงเป็นรอบ → ปกติ
- จับได้แค่ **monotonic drift** — ไม่จับ offset คงที่ครั้งเดียว / drift ที่หักล้างกันเอง

---

# ส่วนที่ 2 — Tingyun case study

ไฟล์: `src/Defination/Data/Character/Harmony/Tingyun.h` · kit: `docs/kit-reference/Character/Harmony/tingyun.md`

## kit ↔ code (หลัง fix)

| ส่วน | เกมจริง (4★ Lv.7/Lv.12) | โค้ด |
|---|---|---|
| Base | HP 847 / ATK 529 / DEF 397 · SPD 112 · E 130 | ✅ |
| Minor traces | ATK +28% · DEF +22.5% · Lightning DMG +8% | `resetList` ✅ |
| A2 / A4 / A6 | SPD +20% (skill) / BA DMG +40% / +5 energy ต้นเทิร์น | ✅ |
| Basic ATK | 110% (Lv.7), 2 hit beat 33+77, toughness 3+7 | ✅ |
| Skill Benediction | ATK +55% (Lv.12), cap 25% ATK Tingyun | `55` ✅ · cap **ตัดทิ้ง** (ATK สูงพอเสมอ) |
| Skill additional | 44% (E4 → 64%) ATK เพื่อน | ✅ source = holder |
| Talent additional | 66% (E4 → 86%) ATK เพื่อน | ✅ (fix #1) |
| Ultimate | energy 50 flat (E6 60) · DMG +56% (Lv.12) 2t | ✅ |
| E1 Windfall | SPD +20% 1t | ✅ gated `eidolon >= 1` |

## 6 fix ที่ทำ

| # | ปัญหา | แก้ |
|---|---|---|
| 1 | E4 ไม่ apply talent-hit additional (hardcode 66) | เพิ่ม branch `eidolon >= 4 ? 86 : 66` ให้ตรงกับ skill-hit |
| 2 | ไม่มี death cleanup → บัฟค้างถ้า DPS ตาย+ฟื้น | `allyDeathList` + `isBuffGoneByDeath` ครบ 4 บัฟ |
| 3 | Benediction ไม่ enforce "target ล่าสุด" | `buffSubUnitTarget` tracker + `clearStaleAllyBuffs()` เรียกก่อนลงบัฟทุกครั้ง |
| 4 | Ult `addBuffSingleTarget(ptr)` ผิด | → `addBuffSingleTarget(chooseAllyBuff(ptr))` ให้ตรงกับ Skill |
| 6 | ชื่อบัฟไม่มี prefix | `BUFF_BENEDICTION = "Tingyun Benediction"` ฯลฯ + magnitude เป็น `constexpr` |
| 7 | hardcode `"Tingyun"` L72 | → `ptr->atvStats->name` |

## โครง 3 path ของบัฟ single-target (source of truth = `buffSubUnitTarget`)

```
apply/retarget : Skill/Ult → clearStaleAllyBuffs(target)
                   → retarget(name): old = getBuffSubUnitTarget(name)
                                     if old && old != target && isBuffGoneByDeath(old,name) → buffSingle(old,{-v})
                                     setBuffSubUnitTarget(name, target)
                   → buffSingle(target, {+v}, name, dur)

expiry         : afterTurnList → expire(name): h = getBuffSubUnitTarget(name)
                                                 if h && isBuffEnd(h,name) → buffSingle(h,{-v})

death          : allyDeathList(target) → if isBuffGoneByDeath(target,name) → buffSingle(target,{-v})
                   (target-based, ไม่พึ่ง tracker — เป็น form ธรรมชาติของ death callback + self-guard)
```

## ยืนยันว่าถูก — ไม่ต้องแตะ

- Basic ATK 2 instance 33+77 = 110% (4★ Lv.7)
- ตัด cap 25% (ATK Tingyun สูงพอเสมอ)
- `TECHNIQUE = 2` → energy 100 (one-off ตั้งใจ)
- L127‑129 duration `-1` เมื่อลงตอนเทิร์นเป้าหมาย (บั๊ก ult Tingyun/Bronya จริง)
- energy Ult ให้ `charUnit[currentCharNum]` (character ไม่ใช่ memosprite) โดยตั้งใจ

## ยังเปิดอยู่ / รายชื่อตัวอื่นที่มีปัญหาเดียวกัน

- **death cleanup ขาด**: Bronya, Robin, Cerydra, Ruan_Mei (มี `allyDeathList` แค่ 8 ไฟล์: Sunday, Hanabi/V1, Fugue, Castorice, Hyacine, Phainon, Huohuo)
- **single-target buff ไม่ enforce latest / ไม่ใช้ `buffSubUnitTarget`**: Cerydra "Military Merit", Bronya Skill buff (Sunday ใช้ `buffAllyTarget` อยู่แล้ว)
