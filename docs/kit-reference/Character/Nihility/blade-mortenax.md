---
schema_version: "1.0.0"
unit_id: 1507
name: "Mortenax Blade"
slug: "blade-mortenax"
rarity: 5
element: "Fire"
path: "Nihility"
role: "Support / Sub DPS"
affiliation: null
released: false
source_url: "https://hsr.gachabase.net/characters/beta?lang=en"
source_game_version: "beta"
dataset_snapshot: "2026-11-20"
overrides: "prydwen record (2026-05-27, unit_id 91, hideSkills — no ability data) — replaced by gachabase beta data pasted by user"
---

# Mortenax Blade

> Source: hsr.gachabase.net beta page (ID 1507), pasted by the user 2026-11-20. **Beta data — may change before release.**
> Only the sim's level is known (no per-level tables): **5★ = Basic Lv.6, Skill/Ult/Talent Lv.10**.
> Mechanics below are paraphrased, not the in-game prose.
> Code: `src/Defination/Data/Character/Nihility/MortenaxBlade.h` (name `"MortenaxBlade"`, selector `MortenaxBlade` / `MBlade`).

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | CRIT Rate | CRIT DMG | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 1358 | 543 | 485 | 107 | 5% | 50% | 100 | 160 |

Minor traces (total): **Fire DMG +22.4% · HP +10% · CRIT Rate +12%** (page shows Fire DMG "22%")

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | A Broken Blade Still Slays | Single | ST 10 | +1 | 20 | 50% Max HP · Taunt target 1 turn |
| Enhanced Basic (Infinite Fury) | A Tempered Blade Severs Souls | Single | ST 10 | +1 | 20 | 100% Max HP · Taunt target 1 turn |
| Skill (Infinite Fury only) | A Rain of Blades Seals Fate | AoE | AoE 10 · bounce 5 each | 0 | 30 | Costs 10% Max HP · 72% Max HP to all enemies · then 4 × 24% Max HP to random enemies |
| Ultimate | Fornax Ex Corpore | Enhance | — | — | 5 | Balefire Bind on all enemies · costs 20% Max HP · deploys the Zone → Infinite Fury |
| Ultimate (Infinite Fury) | Tenax Per Ignem | AoE | AoE 20 | — | 5 | 350% Max HP to all enemies · cost 160 |
| Talent | All Karma Comes Due | Support | — | — | 25 | Zone: every ally attack → Balefire Bind on the targets + 1 Charge · 9 Charge → +25 Energy + 1 extra Skill (Follow-Up ATK) |
| Technique | Blade's Reach Spares None | Attack | ST 20 | — | 0 | Attacks on entry (no multiplier given) · Taunt all enemies 1 turn · his DMG taken −90% for 2 turns |

### Mechanics (paraphrased)

- **Balefire Bind** (debuff) — enemy DEF −30% and DMG taken +50% for 2 turns.
- **HP costs** — when his HP is too low to pay a cost, it drops to 1 instead. The Skill cannot be used outside Infinite Fury or at 1 HP. The Skill does not use Skill Points.
- **Zone / Infinite Fury** (from Fornax Ex Corpore) — CRIT Rate +20% · CRIT DMG +60% · Basic ATK enhanced · Skill unlocked · Ultimate becomes Tenax Per Ignem.
  - A countdown with fixed SPD 70 starts on the Action Order. On its turn the Zone ends and he leaves Infinite Fury.
  - A killing blow does not knock him down. Instead the Zone ends, he leaves Infinite Fury and restores 50% Max HP.
- **Talent extra Skill** — needs HP above 1. It counts as a Follow-Up ATK.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Bone, Hardened ad Nauseam | Stores up to 80 overflow Energy; after an Ultimate it is cleared and regenerated. At battle start or when the Zone ends, Energy below 75% → set to 75%. Reaching max Energy dispels his debuffs |
| A4 | Soul, Tempered ad Mortem | Zone: more likely to be attacked · his DMG taken −50% · Incoming Healing +50% · after being attacked → Balefire Bind on the attacker + 1 Charge |
| A6 | Heart, Refined ad Infinitum | Zone: allies' DMG +50%. With another Nihility character in the team, allies' Ultimate DMG +75%; otherwise his own DMG +75% |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Ere My Death, I Stood Unmade | Zone: all enemies' All-Type RES −20%. After the Talent's extra Skill → the countdown is delayed 15% |
| 2 | Ash Was My Heart, Yet the Flame Stayed | Allies' Ultimate DMG counts as a Follow-Up ATK · allies' Follow-Up ATK DMG +75% · Charge needed drops to 7 |
| 3 | Across the Shore, Wrath Laid Bare | Ult +2 · Talent +2 (max 15) |
| 4 | Odium I've Smitten, Thence Came the Blade | A6 gives allies a further +50% DMG |
| 5 | I Severed My Woes, Knowing Death Begets Life | Skill +2 (max 15) · Basic ATK +1 (max 10) |
| 6 | If Immortality Could Die, I Swore THEM Slain | Zone: taking DMG or using HP → +1 Charge (again after any target's turn ends). Tenax Per Ignem multiplier ×1.5 (525%) |

## สรุป kit ภาษาไทย + จุดเทียบโค้ด

| ส่วน | เกม (sim level) | โค้ด (`MortenaxBlade.h`) |
|---|---|---|
| Base | HP 1358 / ATK 543 / DEF 485 · SPD 107 · Energy 160 | `setCharBasicStats(107,160,160,…)` · `setAllyBaseStats(1358,543,485)` |
| Minor traces | Fire DMG +22.4 · HP +10 · CR +12 | `resetList` |
| Basic / Enhanced Basic | 50% / 100% HP · Taunt 1 เทิร์น | `ba` / `eba` · Taunt แบบ Mydei (`debuffApply` + `addTaunt`, ถอนใน `afterTurnList`) |
| Skill | ใช้ HP 10% · 72% AoE + 4 × 24% สุ่ม | `makeSkill(false)` · 4 hit สุ่มลงเป้าหลักทั้งหมด (= `bestBounce`) |
| Fornax Ex Corpore | Balefire Bind ทั้งหมด · ใช้ HP 20% · กาง Zone | `AllyBuffAction` ใน `ultimateList` · countdown `"Infinite Fury"` (SPD 70) |
| Tenax Per Ignem | 350% HP AoE (E6 525%) | `ultimateList` สาขาที่ Zone ทำงานอยู่ |
| บัฟระหว่าง Zone | CR +20 · CD +60 · A4 · A6 (+E4) | `zoneBuff(±1)` · เช็คว่ามี Nihility ตัวอื่นไหมครั้งเดียวตอนกาง Zone |
| Talent | ทุกการโจมตีของฝั่งเรา → Bind + Charge · ครบ 9 (E2: 7) → +25 Energy + Skill เพิ่ม (FuA) | `afterAttackActionList` → `addCharge` → `tryCharge` · Skill เพิ่มเป็น `AType::FUA` + `addAttackType(SKILL)` |
| Killing blow | ไม่ล้ม · Zone หาย · ฟื้น HP 50% | engine ไม่ให้ HP ต่ำกว่า 1 → **โดนศัตรูตีจน HP เหลือ 1 ระหว่าง Zone = killing blow** (`hpDecreaseList`) |
| A2 | overflow ≤ 80 · Energy ขั้นต่ำ 75% | `whenEnergyIncreaseList` เก็บส่วนเกิน · `releaseOverflow` หลัง Ult · `energyFloor` |
| A4 | DMG taken −50% · Incoming Healing +50% · โดนตี → Bind + Charge | `DMG_REDUCE` / `HEALING_IN` ใน `zoneBuff` · `enemyHitList` |
| E1 | RES −20% ศัตรูทั้งหมด · หน่วง countdown 15% | `applyE1` / `removeE1` (ลงใหม่ตอนเริ่ม wave ถ้า Zone ยังอยู่) · `actionForward(countdown,-15)` |
| E2 | Ult ของพวกเรา = FuA · FuA DMG +75% | `beforeAttackActionList` เติม `AType::FUA` ให้ Ult ของตัวละคร · `whenOnFieldList` |
| E6 | โดนดาเมจ / ใช้ HP → Charge (1 ครั้งต่อการจบเทิร์น) | `hpDecreaseList` + flag รีเซ็ตใน `afterTurnList` |

**ตัดทิ้ง / สมมติ**
- E3 / E5 ไม่ใส่ (ตัว 5★ ใช้เลเวลพื้นฐาน)
- ดาเมจของ Technique ไม่ใส่ เพราะ kit ไม่ให้ตัวเลข
- A4 "โดนโจมตีบ่อยขึ้น" ไม่ใส่ เพราะไม่มีตัวเลข
- A2 การล้าง debuff ไม่ใส่ เพราะ engine ไม่มี debuff ฝั่งพวกเรา
- AI เลือกท่า: ใน Zone ใช้ Skill ตลอดถ้า HP > 1 (ปรับได้ที่ `adjust["MortenaxBlade Skill HP"]`) · Ult ทันทีที่ Energy เต็ม
