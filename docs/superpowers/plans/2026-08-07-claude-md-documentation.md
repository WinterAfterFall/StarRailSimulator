# CLAUDE.md and Agent Documentation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Produce a lean always-loaded `CLAUDE.md`, four deep-dive documents under `docs/`, and three skills under `.claude/skills/`, so Claude Code can add characters, add gear, audit damage formulas, and refactor the engine in this repository without re-deriving context each session.

**Architecture:** `CLAUDE.md` stays small and acts as a routing hub; the heavy detail lives in `docs/*.md` that Claude reads on demand; `.claude/skills/*/SKILL.md` encode the multi-step workflows that are easy to get wrong. Documentation only — no engine, character, or gear code is modified.

**Tech Stack:** Markdown. The subject codebase is C++17, header-only, single translation unit, built with MSYS2/MinGW UCRT64 GCC 14.2.0.

## Global Constraints

- **All deliverable documentation is written in English.** (`note/*.txt` in the repo is Thai; do not translate it, do not imitate it.)
- **No engine, character, or gear source file is modified by this plan.** The only files created or modified are `CLAUDE.md`, `docs/**`, and `.claude/skills/**`.
- **Every factual claim must be verified against the source before it is written.** File paths, function names, list names, and enum values are all checkable with `Grep`. A doc that names a symbol that does not exist is a defect.
- **Do not fix the Dahlia/Fugue `CharSelector()` gap.** It is out of scope and is documented as a known gap.
- **Do not commit `.exe` files.** They are gitignored; keep it that way.
- **Do not modify `.vscode/tasks.json`**, even though one of its tasks specifies `-std=c++14` while the documented command uses `-std=c++17`.
- **Build artifacts go to the scratchpad directory**, never the repository root.
- Commit message prefixes follow the repo convention: `feat : `, `fix : `, `docs : `.
- Line-count targets are guidance, not hard limits. Accuracy beats hitting a number.

## A Note on Testing

This plan produces documentation, so there is no unit-test cycle. The equivalent of a failing test is a **factual-accuracy check**: every symbol, path, and command a document claims must be confirmed to exist. Each task therefore follows this cycle:

1. Gather facts from the source (read/grep).
2. Write the document.
3. Run the verification commands — every one must produce a match.
4. Commit.

Verification commands are given verbatim in each task. Run them from the repository root, `C:\c++\StarRailSimulator`.

## File Structure

| File | Responsibility |
|---|---|
| `CLAUDE.md` | Always-loaded core: build commands, repo map, mental model, hard rules, routing table |
| `docs/architecture.md` | Engine loop, action-value model, complete trigger-list reference, class hierarchy, global state |
| `docs/adding-character.md` | Three-point registration checklist, `Setup()` template, helper-function map |
| `docs/adding-gear.md` | Lightcone / Relic / Planar patterns and their registration points |
| `docs/damage-formula.md` | Damage pipeline, break/DoT/heal paths, debug-flag reference, bug-isolation procedure |
| `.claude/skills/verify-build/SKILL.md` | Compile both entry points, run `ManualBuilder`, compare against baseline |
| `.claude/skills/add-character/SKILL.md` | End-to-end character workflow, calls `verify-build` |
| `.claude/skills/add-gear/SKILL.md` | End-to-end gear workflow, calls `verify-build` |

Tasks are ordered so that each document exists before another document links to it.

---

### Task 1: docs/architecture.md

**Files:**
- Create: `docs/architecture.md`
- Read for facts: `src/Setting.h`, `src/Defination/Function/Event/Event.h`, `src/StdInclude.h`, `src/Defination/Function/Combat/Combat.h`, `src/Defination/Class/Unit/*.h`, `src/Defination/Class/ActionData/*.h`, `Main.h`

**Interfaces:**
- Consumes: nothing.
- Produces: the file path `docs/architecture.md`, and these section anchors that later documents link to: `## Simulation Loop`, `## Trigger Lists`, `## Priority Constants`, `## Class Hierarchy`, `## Global State`, `## Include Structure`.

- [ ] **Step 1: Extract the complete trigger-list inventory**

Run:

```bash
grep -n "^vector<Trigger" src/Setting.h
```

Expected: 40+ lines, each declaring one global trigger list. This is the authoritative inventory — the doc's table must contain a row for every one of them, with none invented.

- [ ] **Step 2: Map each list to where it is fired**

Run:

```bash
grep -n "for(Trigger.*: \|for (Trigger.*: " src/Defination/Function/Event/Event.h
```

`Event.h` fires most lists inside an `allEvent*()` wrapper. For the lists that do **not** appear in `Event.h` — `Setup_List`, `Reset_List`, `WhenOnField_List`, `Tune_stats_List`, `Start_game_List`, `Start_wave_List`, `Ultimate_List`, `ElationSkill_List`, `BeforeAhaInstant_List`, `AfterAhaInstant_List`, `WhenUseUlt_List`, `Dot_List` — find their firing site with:

```bash
grep -rn "Setup_List\|Reset_List\|WhenOnField_List\|Tune_stats_List\|Start_game_List\|Start_wave_List\|Ultimate_List\|ElationSkill_List\|BeforeAhaInstant_List\|AfterAhaInstant_List\|WhenUseUlt_List\|Dot_List" src/Defination/Function/ --include=*.h
```

Record the actual file and function for each. Do not guess.

- [ ] **Step 3: Write `docs/architecture.md`**

The document contains these sections, in this order:

**`# Architecture`** — one paragraph: this is a Honkai: Star Rail combat simulator that replays a fight on an action-value timeline and reports total damage; it is header-only and compiled as a single translation unit.

**`## Simulation Loop`** — the loop as it actually appears in `Main.h` and `ManualBuilder.cpp`:

```
Setup()
loop (substat reroll):
  Reset()
  Set_Stats(charUnit[i])  for each ally
  Start_game()
  for each wave i:
    Current_atv = 0
    Start_wave(i)
    Deal_damage()
    loop:
      Turn_Skip = 0
      Find_turn()
      Atv_fix(turn->atv)
      if Current_atv > Wave[i]: EndWave(Wave[i]); break
      Take_action()
  Cal_DamageSummary()
  printRoundResult()
  if Reroll_substats(): break
printSummaryResult()
```

State plainly that both entry points contain this same loop, copy-pasted — so a change to the loop must be made in `Main.h` **and** `ManualBuilder.cpp`.

**`## Action Value Model`** — `Current_atv` is the simulated clock; `Wave[]` (in `src/Setting.h`) is the action-value budget per wave, and the fight ends when the clock exceeds it; `turn` is a `ActionValueStats*` pointing at whoever acts next; `Find_turn()` picks it; `Action_forward(atvStats, percent)` advances or delays a unit. Note the idiom `Wave[0] += 0.01` seen in `SetValue()` — a tie-breaker nudge.

**`## Trigger Lists`** — a table with one row per list from Step 1:

| Column | Content |
|---|---|
| List | e.g. `AfterAttackActionList` |
| Callback type | e.g. `TriggerByAllyAttackAction_Func` |
| Signature | e.g. `void(shared_ptr<AllyAttackAction>&)` — copy from `src/Defination/Class/Trigger/Trigger_Function.h` |
| Fired by | e.g. `allEventAfterAttackAction()` in `Event.h` |
| Use for | one short phrase |

Follow the table with three worked examples copied from real characters, each with a one-line explanation:
- `Reset_List` with `PRIORITY_IMMEDIATELY` for static trace stats (see `Dahlia.h`).
- `Before_turn_List` / `After_turn_List` for buff expiry via `isBuffEnd()` (see `Dahlia.h`).
- `AfterAttackActionList` for follow-up attacks and Super Break (see `Dahlia.h`).

**`## Priority Constants`** — a table of the `PRIORITY_*` macros with their numeric values, copied from `src/StdInclude.h`, plus the rule: higher runs first (`TriggerFunc::Trigger_cmp` sorts descending), so buffs must be registered above attacks.

**`## Class Hierarchy`** — `Unit → AllyUnit → CharUnit` and `Unit → AllyUnit → MemoSprite`, `Unit → Enemy`; `ActionData → AllyActionData → AllyAttackAction` and `→ AllyBuffAction`; `EnemyActionData`. Mention `turn->canCastToAllyUnit()` and `turn->canCastToEnemy()` return `nullptr` when the current turn is the other side, so both must be null-checked.

**`## Global State`** — a table of the mutable globals in `src/Setting.h` that matter: `charUnit`, `enemyUnit`, `charList`, `allyList`, `enemyList`, `atvList`, `turn`, `Action_bar`, `sp` / `Max_sp`, `Current_atv`, `phaseStatus`, `Turn_Skip`, `Total_ally` / `Total_enemy`. Follow with an explicit warning: there is no encapsulation, every character's lambdas mutate this shared state, and one-off flags such as `DahliaCheck` exist because of it. Refactors here affect every unit.

**`## Include Structure`** — `src/Declaration` holds forward declarations, `src/Defination` holds definitions; the chain is `Setting.h → Class → Function → Data`; every new data header begins with `#include "../include.h"`; each directory has a `Library.h` that includes its members. State that because everything is one translation unit, a full rebuild is required for any change and takes about 42 seconds.

- [ ] **Step 4: Verify every claimed symbol exists**

Run each of these; every one must return at least one match:

```bash
grep -n "PRIORITY_IMMEDIATELY\|PRIORITY_BUFF\|PRIORITY_ACTTACK\|PRIORITY_First\|PRIORITY_Last\|PRIORITY_HEAL\|PRIORITY_DEBUFF\|PRIORITY_ACTION" src/StdInclude.h
grep -n "Trigger_cmp" src/Defination/Class/Trigger/Trigger_Function.h
grep -n "canCastToAllyUnit\|canCastToEnemy" src/Defination/Class/Unit/ActionValueStats.h
grep -rn "void Find_turn\|void Atv_fix\|void Take_action\|void Deal_damage\|void Action_forward" src/Defination/Function/
grep -n "DahliaCheck" src/Setting.h
```

Then confirm the trigger table is complete — the row count must equal the declaration count:

```bash
grep -c "^vector<Trigger" src/Setting.h
```

Compare against the number of rows written. If they differ, add the missing rows.

- [ ] **Step 5: Commit**

```bash
git add docs/architecture.md
git commit -m "docs : add engine architecture reference"
```

---

### Task 2: docs/adding-character.md

**Files:**
- Create: `docs/adding-character.md`
- Read for facts: `src/Defination/Data/Character/Nihility/Dahlia.h` (reference implementation), `src/Defination/Data/Character/Nihility/All_Nihility_char.h`, `SettingFunction.h:67-180`, `src/Defination/Class/Unit/CharUnit.h`

**Interfaces:**
- Consumes: `docs/architecture.md` — links to its `## Trigger Lists` and `## Priority Constants` sections rather than repeating them.
- Produces: `docs/adding-character.md` with anchors `## Registration Checklist`, `## Setup() Template`, `## Helper Reference`, `## Known Gaps`.

- [ ] **Step 1: Confirm the three registration points and the known gap**

Run:

```bash
grep -n "Dahlia\|Fugue" src/Defination/Data/Character/Nihility/All_Nihility_char.h
grep -n "Dahlia\|Fugue" SettingFunction.h
```

Expected: both appear in `All_Nihility_char.h`; **neither appears in `SettingFunction.h`**. This confirms the gap the document warns about. If a future run finds them present, drop the `## Known Gaps` entry rather than writing something false.

- [ ] **Step 2: Confirm every helper name before listing it**

Run:

```bash
grep -rn "void Attack(\|void genSkillPoint(\|void Superbreak_trigger(\|void Dot_trigger(\|void Action_forward(\|void Increase_energy(" src/Defination/Function/
grep -rn "buffSingle\|buffAllAlly\|debuffSingle\|debuffSingleApply\|debuffAllEnemyApply\|isHaveToAddBuff\|isBuffEnd\|isDebuffEnd\|weaknessApply\|chooseCharacterBuff\|chooseSubUnitBuff\|ultUseCheck" src/Defination/Function/Combat/ --include=*.h -l
grep -n "addDamageIns\|addEnemyBounce\|addToActionBar\|isSameName\|isSameAction" src/Defination/Class/ActionData/AllyAttackAction.h
grep -n "setBuffNote\|getBuffNote\|setBuffCheck\|getBuffCheck\|setDebuff\|getDebuff\|pushSubstats\|setTotalSubstats\|setSpeedRequire\|setApplyBaseChance\|setRelicMainStats\|SetAllyBaseStats\|addUltCondition\|Turn_func\|Eidolon\|Technique" src/Defination/Class/Unit/CharUnit.h src/Defination/Class/Unit/AllyUnit.h
```

Any name that returns no match must be dropped from the document or corrected to the real name.

- [ ] **Step 3: Write `docs/adding-character.md`**

**`# Adding a Character`** — opening line: `src/Defination/Data/Character/Nihility/Dahlia.h` is the reference implementation; read it alongside this document.

**`## Registration Checklist`** — a checkbox list, stated as mandatory:

1. Create `src/Defination/Data/Character/<Path>/<Name>.h`, starting with `#include "../include.h"`.
2. Add `#include"<Name>.h"` to `src/Defination/Data/Character/<Path>/All_<Path>_char.h`.
3. Add an `else if (name == "<Name>") Char = <Name>::Setup;` branch to `CharSelector()` in `SettingFunction.h`.

Add the warning: skipping step 3 compiles cleanly and works in `ManualBuilder.cpp`, so it fails silently — the character simply cannot be picked in `Application.exe`.

**`## Setup() Template`** — a complete annotated skeleton. Include the real signature:

```cpp
#include "../include.h"

namespace <Name>{
    void Setup(int E,
               function<void(CharUnit *ptr)> LC,
               function<void(CharUnit *ptr)> Relic,
               function<void(CharUnit *ptr)> Planar){
        // 1. identity and level-scaled base stats
        CharUnit *ptr = SetCharBasicStats(/*spd*/, /*ult cost*/, /*max energy*/, E,
                                          ElementType::<X>, Path::<Y>, "<Name>",
                                          UnitType::Standard);
        ptr->SetAllyBaseStats(/*HP*/, /*ATK*/, /*DEF*/);

        // 2. substats and stat requirements
        ptr->pushSubstats(Stats::<X>);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::<body>, Stats::<feet>, Stats::<sphere>, Stats::<rope>);

        // 3. gear — always after base stats, always in this order
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability
        // 4. abilities as function<void()> so triggers can call them
        function<void()> BA    = [ptr]() { /* ... */ };
        function<void()> Skill = [ptr]() { /* ... */ };
        function<void()> Fua   = [ptr]() { /* ... */ };
        #pragma endregion

        // 5. what this unit does on its own turn
        ptr->Turn_func = [ptr,BA,Skill]() { /* ... */ };

        // 6. ultimate
        ptr->addUltCondition([ptr]() -> bool { return true; });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            /* ... */
        }));

        // 7. everything else: Reset_List, WhenOnField_List, Before_turn_List,
        //    After_turn_List, AfterAttackActionList, Start_game_List, ...
    }
}
```

Explain each numbered block in one or two sentences, and state that the order matters: gear functions must run after `SetAllyBaseStats` because a Lightcone calls `SetAllyBaseStats` itself to add its own base stats (point at `Resolution.h` as evidence).

Show the ability body pattern with a real, complete example lifted from `Dahlia.h` — the Skill lambda — covering `make_shared<AllyAttackAction>(AType::SKILL, ptr, TraceType::Blast, "Name", callback)`, `act->addDamageIns(DmgSrc(DmgSrcType::ATK, 160, 10))`, `act->addToActionBar()`, and when `Deal_damage()` must be called explicitly (follow-up attacks and ultimates, as in `Dahlia`'s Fua and Ult).

**`## Helper Reference`** — a table of helper, signature, and purpose, restricted to names confirmed in Step 2. Group them: action construction, damage, buffs and debuffs, buff bookkeeping, resources, weakness and break, targeting.

**`## Conventions That Matter`**
- Buff and debuff names are string keys. Prefix every one with the character name (`"Dahlia A2"`, `"Dahlia E4"`) — a collision silently overwrites another character's buff.
- Eidolons are plain conditionals: `if (ptr->Eidolon >= 4) { ... }`.
- Technique is handled in `Start_game_List` behind `if (ptr->Technique)`.
- **Every timed buff needs a matching removal.** Applying via `buffSingle(..., "Name", turns)` requires a paired `isBuffEnd(unit, "Name")` check in `Before_turn_List` or `After_turn_List` that subtracts the same amount. Show the matched pair from `Dahlia.h` (`"Dahlia A2"` applied in the Skill, removed in `Before_turn_List`) as the model.
- Trace-derived static stats go in `Reset_List`, because `Reset()` runs once per reroll iteration.

**`## Known Gaps`** — `Dahlia` and `Fugue` are missing from `CharSelector()` in `SettingFunction.h`, so they cannot be selected in `Application.exe`. Recorded, deliberately not fixed.

- [ ] **Step 4: Verify**

Re-run every command from Steps 1 and 2. Every helper named in the finished table must return a match. Then confirm the referenced line range is still right:

```bash
grep -n "void CharSelector" SettingFunction.h
```

- [ ] **Step 5: Commit**

```bash
git add docs/adding-character.md
git commit -m "docs : add character authoring guide"
```

---

### Task 3: docs/adding-gear.md

**Files:**
- Create: `docs/adding-gear.md`
- Read for facts: `src/Defination/Data/Lightcone/Nihility/Resolution.h`, `src/Defination/Data/Relic/Iron_Cavalry.h`, `src/Defination/Data/Relic/PairSet.h`, `src/Defination/Data/Planar/Lushaka.h`, `SettingFunction.h:179-450`

**Interfaces:**
- Consumes: `docs/architecture.md` (trigger lists), `docs/adding-character.md` (the gear functions are invoked from `Setup()`).
- Produces: `docs/adding-gear.md` with anchors `## Lightcones`, `## Relics`, `## Planars`.

- [ ] **Step 1: Confirm the three registration points**

Run:

```bash
grep -n "void LightConeSelector\|void RelicSelector\|void PlanarSelector" SettingFunction.h
ls src/Defination/Data/Lightcone/ src/Defination/Data/Relic/ src/Defination/Data/Planar/
```

- [ ] **Step 2: Write `docs/adding-gear.md`**

**`## Lightcones`** — path `src/Defination/Data/Lightcone/<Path>/<Name>.h`; namespace `<Path>_Lightcone`; the shape is a factory taking superimpose level and returning the setup lambda:

```cpp
#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Resolution(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);   // the cone's own base stats
            ptr->Light_cone.Name = "Resolution";
            // register triggers here, capturing [ptr, superimpose, ...]
        };
    }
}
```

Note that `SetAllyBaseStats` here **adds** the cone's stats on top of the character's, which is why `LC(ptr)` must be called after the character sets its own. Note the idiom of building a per-character unique debuff key: `string ensnared = ptr->getName() + " Ensnared";`.

Registration: `#include` in `All_<Path>_LC.h`, then a branch in `LightConeSelector()` assigning `lightConeFunction = <Path>_Lightcone::<Name>;` (assigning the factory, not the result — the selector applies the superimpose level afterwards).

**`## Relics`** — path `src/Defination/Data/Relic/<Name>.h`; namespace `Relic`. Two shapes:

Parameterless (four-piece), passed by name:

```cpp
namespace Relic{
    void Iron_Cavalry(CharUnit *ptr);
    void Iron_Cavalry(CharUnit *ptr){
        ptr->Relic.Name = "Iron_Cavalry";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::BE][AType::None] += 16;
        }));
    }
}
```

Parameterised (returns a `function<void(CharUnit*)>`), used by `PairSet(PairSetType, PairSetType)` and `DivinerOfDistant(bool)`.

Explain the split: a two-piece + two-piece combination goes through `Relic::PairSet`, which resolves each half via `ptr->RelicPairSet(type)`.

Registration: `#include` in `All_Relic.h`, branch in `RelicSelector()`. Show that a parameterised relic prompts the user first, as `DivinerOfDistant` does with `askYesNo()`.

**`## Planars`** — identical in shape to relics, under `src/Defination/Data/Planar/`, namespace `Planar`; some take an argument (`GiantTree(0)`, `FirmanentFrontline(0)`). Registration: `All_Planar.h` plus `PlanarSelector()`. Use `Lushaka.h` as the worked example, and point out that it reaches into `charUnit[1]` directly — evidence that gear can mutate other units, so gear bugs can look like character bugs.

**`## Which Trigger List`** — a short table mapping intent to list, for the gear case specifically: permanent stats → `Reset_List`; on-field conditional stats → `WhenOnField_List`; on-hit effects → `AfterAttackActionList`; expiry cleanup → `After_turn_List`. Link to `docs/architecture.md#trigger-lists` for the full set.

- [ ] **Step 3: Verify**

Every one of these must return a match:

```bash
grep -n "RelicPairSet" src/Defination/Class/Unit/CharUnit.h
grep -n "Light_cone.Name" src/Defination/Data/Lightcone/Nihility/Resolution.h
grep -n "Relic.Name" src/Defination/Data/Relic/Iron_Cavalry.h
grep -n "Planar.Name" src/Defination/Data/Planar/Lushaka.h
grep -n "DivinerOfDistant\|PairSet" SettingFunction.h
grep -rn "GiantTree\|FirmanentFrontline" src/Defination/Data/Planar/
```

- [ ] **Step 4: Commit**

```bash
git add docs/adding-gear.md
git commit -m "docs : add lightcone, relic and planar authoring guide"
```

---

### Task 4: docs/damage-formula.md

**Files:**
- Create: `docs/damage-formula.md`
- Read for facts: `src/Defination/Function/Calculate/CalDamage.h`, `CalStats.h`, `CalHeal.h`, `CalDmgReceive.h`, `src/Defination/Function/Combat/Combat.h`, `src/Defination/Function/Combat/Dot.h`, `src/Enum/CheckMode.h`, `src/Defination/Class/Unit/CharUnit.h:311-318`, `src/Defination/Function/AdjustFunction/CharCmd.h`

**Interfaces:**
- Consumes: `docs/architecture.md`.
- Produces: `docs/damage-formula.md` with anchors `## Damage Pipeline`, `## Break and Super Break`, `## Damage over Time`, `## Healing and HP`, `## Debug Flags`, `## Isolating a Bug`.

- [ ] **Step 1: Read the calculation entry points**

These are the confirmed functions in `CalDamage.h` — read each before describing it:

| Function | Line |
|---|---|
| `calDamage(shared_ptr<AllyAttackAction>&, Enemy*, DmgSrc)` | 3 |
| `calElationDamage(shared_ptr<AllyAttackAction>&, Enemy*, DmgSrc)` | 34 |
| `Cal_Break_damage(shared_ptr<AllyAttackAction>&, Enemy*, double&)` | 61 |
| `Cal_Freeze_damage(shared_ptr<AllyAttackAction>&, Enemy*)` | 93 |
| `Cal_Dot_Toughness_break_damage(shared_ptr<AllyAttackAction>&, Enemy*, double)` | 123 |
| `Cal_Superbreak_damage(shared_ptr<AllyAttackAction>&, Enemy*, double)` | 153 |
| `Cal_Toughness_reduction(shared_ptr<AllyAttackAction>&, Enemy*, double)` | 184 |
| `Cal_Total_Toughness_Reduce(shared_ptr<AllyAttackAction>&, Enemy*, double)` | 203 |

Line numbers are from the current revision; re-confirm with `grep -n "void Cal\|double Cal\|void calDamage\|void calElation" src/Defination/Function/Calculate/CalDamage.h` and use whatever it reports.

- [ ] **Step 2: Write `docs/damage-formula.md`**

**`## Damage Pipeline`** — trace the path end to end, naming the real functions:

```
ability lambda
  → act->addDamageIns(DmgSrc(DmgSrcType::ATK, ratio, toughness))
  → act->addToActionBar()
  → Attack(act)              [Combat.h:166]
  → per target, per instance: calDamage(act, target, dmgSrc)   [CalDamage.h:3]
  → Deal_damage()            [Combat.h:111]  flushes the action bar
```

Then a table of the multiplicative terms `calDamage` composes, read directly from the source — base value by `DmgSrcType`, damage boost, defence multiplier, resistance and RES PEN, vulnerability, crit, and the break/Super Break specific terms. Write the terms as they actually appear in the code; do not reproduce a formula from the game wiki.

Explain `DmgSrc(DmgSrcType, ratio, toughnessReduce)` and `damageSplit` — the nested per-target, per-instance structure that `BeforeAttack_List` handlers walk to modify individual hits (the `Dahlia A6` toughness bump is the worked example).

**`## Break and Super Break`** — `Toughness_break()` and `Cal_Toughness_reduction()` in the break path; `Superbreak_trigger(act, ratio, triggerName)` in `Combat.h:240` as the character-facing entry point; the break status effects tracked on `Enemy` (`breakDotList`, `breakEngList`, `breakFrzList`, `breakImsList`) and where they tick down (`allEventBeforeTurn` / `allEventAfterTurn` in `Event.h`); `weaknessApply()` and the `WeaknessApply_List` trigger, including the `Weakness_typeCountdown` expiry in `allEventAfterTurn`.

**`## Damage over Time`** — `Dot_trigger(ratio, target, DotType)` at `Combat.h:263`, fired from `allEventBeforeTurn` for enemy turns; `Cal_Dot_Toughness_break_damage`; the per-type counters on `Enemy` (`BurnCount`, `ShockCount`, `WindSheerCount`, `BleedCount`, `DotCount`).

**`## Healing and HP`** — `CalHeal.h` and `CalHealStats.h`; `allEventHeal` and `Healing_List`; `allEventChangeHP` and `HPDecrease_List`; `CalDmgReceive.h` for incoming damage; shields.

**`## Debug Flags`** — a table of every method confirmed at `CharUnit.h:311-318`:

| Call | Effect |
|---|---|
| `ptr->enableCheckDamage()` | print each damage instance |
| `ptr->enableCheckDamageFormula(DmgFormulaMode::X)` | print the named term of the formula |
| `ptr->enableCheckHeal()` / `enableCheckHealFormula()` | outgoing heal |
| `ptr->enableCheckHealReceive()` / `enableCheckHealReceiveFormula()` | incoming heal |
| `ptr->enableCheckHpChange()` / `enableCheckHpChangeFormula()` | HP changes |
| `CharCmd::Timing_print(ptr)` | per-turn timing trace |

Follow it with the full list of `DmgFormulaMode` values copied verbatim from `src/Enum/CheckMode.h`: `None, All, ATK, HP, DEF, Const, Src, Dmg, Crit, CritRate, CritDam, DefShred, Respen, Vul, BE, Mtgt, SpbInc, MtprInc, Elation, Merrymake, CB`.

Also document the other `CharCmd` levers confirmed to exist: `Set_Technique`, `Set_Tune_Speed`, `Set_Reroll_check`, `Set_Other_buff`, `Using_Skill`, `printUltStart`, `printUltEnd`, `printText`; and `EnemyCmd::setEnemyWeakness(bool Physical, bool Fire, bool Ice, bool Wind, bool Lightning, bool Quantum, bool Imaginary)`.

**`## Isolating a Bug`** — the procedure:
1. In `ManualBuilder.cpp`, cut the team down to the smallest set that reproduces it — often the damage dealer alone.
2. Fix the enemy setup with `SetupEnemy(...)` so numbers are reproducible; optionally pin weaknesses with `EnemyCmd::setEnemyWeakness(...)`.
3. Enable `enableCheckDamageFormula(DmgFormulaMode::All)` on the unit under test, then narrow to a single term once you see which one is wrong.
4. Rebuild and run; compare against the same team before the change.
5. Restore `ManualBuilder.cpp` when finished.

- [ ] **Step 3: Verify**

```bash
grep -n "enableCheck" src/Defination/Class/Unit/CharUnit.h
grep -n "enum class DmgFormulaMode" -A 25 src/Enum/CheckMode.h
grep -n "void Attack(\|void Deal_damage(\|void Superbreak_trigger(\|void Dot_trigger(\|void Toughness_break(" src/Defination/Function/Combat/Combat.h
grep -n "void Cal\|void calDamage\|void calElation\|double Cal" src/Defination/Function/Calculate/CalDamage.h
grep -n "breakDotList\|breakEngList\|breakFrzList\|breakImsList\|BurnCount\|ShockCount\|WindSheerCount\|BleedCount" src/Defination/Class/Unit/Enemy.h
grep -n "Set_Technique\|Set_Tune_Speed\|Set_Reroll_check\|Set_Other_buff\|Using_Skill" src/Defination/Function/AdjustFunction/CharCmd.h
grep -n "setEnemyWeakness" src/Defination/Function/AdjustFunction/EnemyCmd.h
```

Every command must return a match. Any that does not means the document names something that no longer exists — correct the document.

- [ ] **Step 4: Commit**

```bash
git add docs/damage-formula.md
git commit -m "docs : add damage formula and debugging reference"
```

---

### Task 5: CLAUDE.md

**Files:**
- Create: `CLAUDE.md`
- Read for facts: `Main.h`, `Application.cpp`, `ManualBuilder.cpp`, `.gitignore`, `src/Setting.h`

**Interfaces:**
- Consumes: all four `docs/*.md` files from Tasks 1–4 — they must exist before this task, because the routing table links to them.
- Produces: `CLAUDE.md`, the always-loaded context file.

- [ ] **Step 1: Confirm the build facts still hold**

Run (each takes ~42s, so allow a 300000 ms timeout):

```bash
"C:/MinGW/ucrt64/bin/g++.exe" -std=c++17 -g ManualBuilder.cpp -o "$SCRATCH/ManualBuilder.exe"
```

where `$SCRATCH` is the session scratchpad directory. Expected: exit 0, no output. Then:

```bash
"" | "$SCRATCH/ManualBuilder.exe" | tail -5
```

Expected: a `Conclusion` block with `Focus 1 enemy` and `Focus 2 enemy` totals, and no prompt for input.

- [ ] **Step 2: Write `CLAUDE.md`**

Target ~130 lines. Sections:

**`# StarRailSimulator`** — two sentences: a Honkai: Star Rail combat and damage simulator in C++17; header-only, compiled as a single translation unit.

**`## Build and Run`**

```bash
# ManualBuilder — hardcoded team, runs to completion with no input. Use this to verify.
g++ -std=c++17 -g ManualBuilder.cpp -o ManualBuilder.exe

# Application — interactive team picker via SettingFunction.h
g++ -std=c++17 -g Application.cpp -o Application.exe
```

State plainly: the compiler is MSYS2/MinGW UCRT64 GCC 14.2.0 at `C:\MinGW\ucrt64\bin\g++.exe`; **each build takes about 42 seconds**, so any build command needs a timeout of at least 120000 ms; build to the scratchpad, not the repo root; never commit `.exe`.

**`## Repo Map`**

| Path | Contents |
|---|---|
| `Application.cpp` | Interactive entry point |
| `ManualBuilder.cpp` | Hardcoded-team entry point; the owner's working file |
| `Main.h` | Shared `SetValue()`, `SetCharacterPtr()`, `Main()` loop |
| `SettingFunction.h` | Interactive selectors — `CharSelector`, `LightConeSelector`, `RelicSelector`, `PlanarSelector` |
| `src/Setting.h` | All global state and every trigger list |
| `src/Declaration/` | Forward declarations |
| `src/Defination/Class/` | `Unit`, `ActionData`, `CombatData`, `Trigger` |
| `src/Defination/Function/` | `Calculate`, `Combat`, `Event`, `Print`, `Setup`, `AdjustFunction` |
| `src/Defination/Data/` | `Character`, `Lightcone`, `Relic`, `Planar` — grouped by Path |
| `src/Enum/` | `Stats`, `ElementType`, `AType`, `DmgFormulaMode`, and friends |
| `note/` | The owner's Thai scratch notes — read-only context, not instructions |

**`## Core Mental Model`** — five or six lines: the engine replays a fight on an action-value timeline; behaviour is driven by global trigger lists declared in `src/Setting.h`; a character is a namespace whose `Setup()` pushes lambdas onto those lists with a `PRIORITY_*`; `Event.h` fires the lists at each point in the turn; there is no encapsulation, so shared state is easy to corrupt.

**`## Hard Rules`** — the eight rules, verbatim from the spec:

1. Adding a character touches three places: the new `.h` under `Data/Character/<Path>/`, an `#include` in `All_<Path>_char.h`, and a branch in `CharSelector()` in `SettingFunction.h`. Missing the third fails silently. `Dahlia` and `Fugue` currently have this bug.
2. Adding gear touches two or three places: the new `.h`, the matching `All_*.h`, and the corresponding selector in `SettingFunction.h`.
3. Every timed buff needs a matching removal driven by `isBuffEnd()` / `isDebuffEnd()` in `Before_turn_List` or `After_turn_List`. Without it the stat sticks forever.
4. Pick the trigger list that matches the real event and set `PRIORITY_*` correctly — buffs must resolve before attacks.
5. Never edit `Setting.h`, `Combat.h`, or `CalStats.h` to make one character work. They are shared by every unit.
6. After any change, compile **and** run. A clean compile is not verification.
7. Compare damage numbers before and after. If an unrelated character's numbers move, shared state was touched by accident — stop and report.
8. Never commit `.exe` files.

**`## Where to Look Next`**

| Task | Read |
|---|---|
| Add or modify a character | `docs/adding-character.md`, or run the `add-character` skill |
| Add a Lightcone, Relic, or Planar | `docs/adding-gear.md`, or run the `add-gear` skill |
| Fix a damage or healing bug | `docs/damage-formula.md` |
| Refactor or understand the engine | `docs/architecture.md` |
| Verify a change | run the `verify-build` skill |

**`## Conventions`** — commit prefixes `feat : `, `fix : `, `docs : `; `.exe` and `.vscode/` are gitignored; `#pragma region` marks foldable blocks; `endl` is `#define`d to `'\n'` in `src/StdInclude.h`; the codebase spells "Defination" and "Aplly" — match existing spelling rather than correcting it, since names are load-bearing.

- [ ] **Step 3: Verify the routing table points at real files**

```bash
ls docs/architecture.md docs/adding-character.md docs/adding-gear.md docs/damage-formula.md
grep -n "endl" src/StdInclude.h
grep -n "exe\|vscode" .gitignore
```

All four docs must exist. If any is missing, that task was skipped — go back and complete it.

- [ ] **Step 4: Commit**

```bash
git add CLAUDE.md
git commit -m "docs : add CLAUDE.md project context for Claude Code"
```

---

### Task 6: .claude/skills/verify-build/SKILL.md

**Files:**
- Create: `.claude/skills/verify-build/SKILL.md`

**Interfaces:**
- Consumes: the build facts established in Task 5.
- Produces: a skill named `verify-build`, invoked by name from Tasks 7 and 8.

- [ ] **Step 1: Write the skill**

Frontmatter:

```markdown
---
name: verify-build
description: Compile and run StarRailSimulator to verify a change. Use after modifying any character, Lightcone, Relic, Planar, or engine file, and whenever the user asks to check that the simulator still builds and produces sane damage numbers.
---
```

Body sections:

**`# Verify Build`** — one line on what this does.

**`## Before You Change Anything`** — capture a baseline. If `ManualBuilder.cpp` already compiles, build and run it first and save the output:

```bash
g++ -std=c++17 -g ManualBuilder.cpp -o "$SCRATCH/baseline.exe"
"" | "$SCRATCH/baseline.exe" > "$SCRATCH/baseline.txt"
```

State that without a baseline, rule 7 in `CLAUDE.md` cannot be checked and the verification is incomplete — say so in the report rather than skipping it silently.

**`## Steps`**

1. Compile `ManualBuilder.cpp` with `-std=c++17 -g` to the scratchpad. Timeout at least 120000 ms; it takes about 42 seconds. Any error or warning is a failure — report the compiler output verbatim and stop.
2. Compile `Application.cpp` the same way. It is a separate translation unit and can break independently — most often because a new character was added to `All_<Path>_char.h` but `CharSelector()` was not updated, or was updated with a wrong namespace.
3. Run `ManualBuilder.exe` with empty piped input. It needs no interaction. Capture stdout.
4. Diff against the baseline. Report: which characters' numbers changed, and the `Focus 1 enemy` / `Focus 2 enemy` totals before and after.
5. Judge the result. Numbers changing for the unit that was modified is expected. **Numbers changing for an unrelated unit means shared state was touched — stop and report rather than proceeding.**

**`## Reporting`** — the report must state: compile result for both entry points; whether the run completed; the before/after totals; and any unrelated-unit drift. Never report success on a compile alone.

**`## Rules`**
- Build artifacts go to the scratchpad, never the repo root.
- Never commit `.exe`.
- If a compile fails, fix the cause; do not work around it by reverting to `-std=c++14` or by editing `.vscode/tasks.json`.

- [ ] **Step 2: Verify the skill is well-formed**

```bash
ls .claude/skills/verify-build/SKILL.md
head -5 .claude/skills/verify-build/SKILL.md
```

Expected: frontmatter opens on line 1 with `---`, and contains both `name:` and `description:`.

- [ ] **Step 3: Commit**

```bash
git add .claude/skills/verify-build/SKILL.md
git commit -m "feat : add verify-build skill"
```

---

### Task 7: .claude/skills/add-character/SKILL.md

**Files:**
- Create: `.claude/skills/add-character/SKILL.md`

**Interfaces:**
- Consumes: `docs/adding-character.md` (Task 2), the `verify-build` skill (Task 6).
- Produces: a skill named `add-character`.

- [ ] **Step 1: Write the skill**

Frontmatter:

```markdown
---
name: add-character
description: Add a new playable character to StarRailSimulator, or modify an existing one. Use when the user asks to implement a character, port a kit, or change a character's abilities, eidolons, traces, or technique.
---
```

Body:

**`## Step 1 — Gather the kit`** — ask for anything missing before writing code: Path and element; base HP/ATK/DEF and base speed; ultimate cost and max energy; Basic Attack, Skill, Ultimate, and Talent multipliers with toughness damage; trace bonuses (A2/A4/A6); technique; eidolons E1–E6; and the intended relic main stats and substat priority. State that guessing multipliers produces a plausible-looking but wrong simulator, which is worse than asking.

**`## Step 2 — Read the pattern`** — read `docs/adding-character.md`, then open the existing character whose mechanics are closest (a follow-up attack unit, a break unit, a DoT unit) and use it as a structural reference. Name concrete examples: `Dahlia.h` for break and Super Break, `Kafka.h` or `Hysilens.h` for DoT, `RuanMei.h` or `Sunday.h` for buffers, `Gallagher.h` for sustain.

**`## Step 3 — Write the header`** — create `src/Defination/Data/Character/<Path>/<Name>.h` starting with `#include "../include.h"`, following the `Setup()` template in the doc.

**`## Step 4 — Register all three points`** — an explicit checklist that must be fully ticked:

- [ ] `src/Defination/Data/Character/<Path>/<Name>.h` created
- [ ] `#include"<Name>.h"` added to `All_<Path>_char.h`
- [ ] `else if (name == "<Name>") Char = <Name>::Setup;` added to `CharSelector()` in `SettingFunction.h`

State that step 3 is the one that gets forgotten, and that `Dahlia` and `Fugue` are the existing evidence.

**`## Step 5 — Test`** — add the character to a team in `ManualBuilder.cpp`, then invoke the `verify-build` skill. Capture the baseline **before** editing `ManualBuilder.cpp`.

**`## Step 6 — Restore and report`** — restore `ManualBuilder.cpp` to its original contents unless the user asked to keep the test team. Use `git diff ManualBuilder.cpp` to confirm it is clean. Then report: compile status for both entry points, the damage the new character produced, whether any other character's numbers moved, and anything in the kit that was assumed rather than supplied.

**`## Rules`**
- Follow the hard rules in `CLAUDE.md`. Rules 3 (paired buff removal) and 5 (do not edit shared engine files) are the ones this workflow breaks most often.
- Prefix every buff and debuff string key with the character name.
- Never edit `Setting.h`, `Combat.h`, or `CalStats.h` to make one character work. If the character genuinely needs a new engine capability, stop and say so instead of adding a special-case flag.

- [ ] **Step 2: Verify the references resolve**

```bash
ls docs/adding-character.md .claude/skills/verify-build/SKILL.md
ls src/Defination/Data/Character/Nihility/Dahlia.h src/Defination/Data/Character/Nihility/Kafka.h src/Defination/Data/Character/Harmony/Ruan_Mei.h src/Defination/Data/Character/Abundance/Gallagher.h
```

Every path must exist. Note that Ruan Mei's file is `Ruan_Mei.h` while the namespace is `RuanMei` — name the file correctly in the skill.

- [ ] **Step 3: Commit**

```bash
git add .claude/skills/add-character/SKILL.md
git commit -m "feat : add add-character skill"
```

---

### Task 8: .claude/skills/add-gear/SKILL.md

**Files:**
- Create: `.claude/skills/add-gear/SKILL.md`

**Interfaces:**
- Consumes: `docs/adding-gear.md` (Task 3), the `verify-build` skill (Task 6).
- Produces: a skill named `add-gear`.

- [ ] **Step 1: Write the skill**

Frontmatter:

```markdown
---
name: add-gear
description: Add a Lightcone, Relic set, or Planar ornament to StarRailSimulator. Use when the user asks to implement or change a light cone, relic set, or planar set.
---
```

Body:

**`## Step 1 — Identify the type`** — Lightcone, Relic, or Planar. The three differ in file location, function shape, and registration point, so settle this first.

**`## Step 2 — Gather the data`** — for a Lightcone: Path, base HP/ATK/DEF, and the effect at each superimpose level (the code scales arithmetically from the S1 value plus a per-level increment, as in `Resolution.h`). For a Relic or Planar: the two-piece and four-piece effects, and whether any of it is conditional on a stat threshold.

**`## Step 3 — Read the pattern`** — read `docs/adding-gear.md`, then open the closest existing example: `Resolution.h` for a Lightcone that applies a debuff, `Iron_Cavalry.h` for a parameterless relic, `PairSet.h` for a parameterised one, `Lushaka.h` for a planar that buffs another slot.

**`## Step 4 — Write and register`** — a per-type checklist:

Lightcone:
- [ ] `src/Defination/Data/Lightcone/<Path>/<Name>.h` created, namespace `<Path>_Lightcone`, factory takes `int superimpose`
- [ ] `#include` added to `All_<Path>_LC.h`
- [ ] Branch added to `LightConeSelector()` assigning the factory, not its result

Relic:
- [ ] `src/Defination/Data/Relic/<Name>.h` created, namespace `Relic`
- [ ] `#include` added to `All_Relic.h`
- [ ] Branch added to `RelicSelector()`

Planar:
- [ ] `src/Defination/Data/Planar/<Name>.h` created, namespace `Planar`
- [ ] `#include` added to `All_Planar.h`
- [ ] Branch added to `PlanarSelector()`

**`## Step 5 — Test`** — equip the new gear on a character in `ManualBuilder.cpp`, then invoke `verify-build`. Capture the baseline before editing.

**`## Step 6 — Restore and report`** — restore `ManualBuilder.cpp`, confirm with `git diff ManualBuilder.cpp`, and report compile status, the damage change the gear produced, and any unrelated drift.

**`## Rules`**
- A Lightcone's `SetAllyBaseStats` adds to the character's stats, so `LC(ptr)` must stay after the character's own call. Do not reorder the `LC / Relic / Planar` block in `Setup()`.
- Gear can mutate other units (`Lushaka.h` writes to `charUnit[1]`), so a gear bug can present as a character bug. Check gear when a character's numbers are wrong for no visible reason.
- Every timed effect needs a paired removal, same as characters.

- [ ] **Step 2: Verify the references resolve**

```bash
ls docs/adding-gear.md .claude/skills/verify-build/SKILL.md
ls src/Defination/Data/Lightcone/Nihility/Resolution.h src/Defination/Data/Relic/Iron_Cavalry.h src/Defination/Data/Relic/PairSet.h src/Defination/Data/Planar/Lushaka.h
```

- [ ] **Step 3: Final check — the whole deliverable set exists**

```bash
ls CLAUDE.md docs/architecture.md docs/adding-character.md docs/adding-gear.md docs/damage-formula.md .claude/skills/verify-build/SKILL.md .claude/skills/add-character/SKILL.md .claude/skills/add-gear/SKILL.md
git status --short
```

Expected: all eight files present, and no stray `.exe` or modified source file in `git status`. If `ManualBuilder.cpp` shows as modified, restore it.

- [ ] **Step 4: Commit**

```bash
git add .claude/skills/add-gear/SKILL.md
git commit -m "feat : add add-gear skill"
```

---

## Self-Review

**Spec coverage.** Every deliverable in the spec maps to a task: `CLAUDE.md` → Task 5; `docs/architecture.md` → Task 1; `docs/adding-character.md` → Task 2; `docs/adding-gear.md` → Task 3; `docs/damage-formula.md` → Task 4; the three skills → Tasks 6, 7, 8. The spec's eight hard rules appear verbatim in Task 5. The spec's restore rule for `ManualBuilder.cpp` appears in Tasks 7 and 8. The spec's known-gap decision appears in Task 2 and rule 1 of Task 5. The spec's out-of-scope items are carried into Global Constraints.

**Ordering.** Docs precede `CLAUDE.md` because its routing table links to them; `verify-build` precedes the two skills that invoke it.

**Naming consistency.** Skill names are `verify-build`, `add-character`, `add-gear` throughout. The trigger list is `AfterAttackActionList` — note it has no underscore before `List`, unlike its neighbours; the docs must copy `src/Setting.h` exactly rather than normalising. Ruan Mei is file `Ruan_Mei.h`, namespace `RuanMei`.
