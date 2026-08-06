# Design: CLAUDE.md and Agent Documentation for StarRailSimulator

**Date:** 2026-08-07
**Status:** Approved

## Goal

Give Claude Code the context it needs to work productively in this repository across
four kinds of task the owner cares about equally: adding characters, adding gear
(Lightcones / Relics / Planars), fixing bugs and verifying damage formulas, and
refactoring the engine.

## Constraints and Decisions

| Decision | Choice | Reason |
|---|---|---|
| Documentation language | English | Matches the code and Claude's training; the owner reads English fine |
| Structure | Lean `CLAUDE.md` + deep-dive `docs/` + `.claude/skills/` | The four task types need disjoint context; a single always-loaded file taxes every session |
| Verification standard | Compile **and** run | The owner wants damage output checked, not just a clean build |
| Scope | Documentation only | No engine or gameplay code is modified by this work |

The owner initially asked for a single 500+ line `CLAUDE.md`. The context cost of
loading that every session was raised; the owner then chose the split structure plus
skills. Total documentation exceeds 500 lines, but only the ~130-line core is always
resident.

## Verified Facts

These were confirmed by running commands against the repository, not inferred:

- `g++` is MSYS2/MinGW UCRT64 GCC 14.2.0 at `C:\MinGW\ucrt64\bin\g++.exe`.
- `g++ -std=c++17 -g ManualBuilder.cpp -o ManualBuilder.exe` compiles clean, ~42s.
- `g++ -std=c++17 -g Application.cpp -o Application.exe` compiles clean, ~42s.
- `ManualBuilder.exe` runs to completion with no interactive input and prints a
  per-enemy damage summary with percentage breakdown plus a final `Conclusion` block
  (`Focus 1 enemy` / `Focus 2 enemy` totals).
- `Application.exe` is interactive: it prompts for team size, then character, eidolon,
  Lightcone, relic, and planar per slot via `SettingFunction.h`.
- Adding a character requires edits in three places. `Dahlia` and `Fugue` have their
  own headers and are included in `All_Nihility_char.h`, but are absent from
  `CharSelector()` in `SettingFunction.h`, so they cannot be selected through the
  interactive menu. This is recorded as a known gap, not fixed by this work.

## Deliverables

```
CLAUDE.md                          ~130 lines   loaded every session
docs/
  architecture.md                  ~200 lines   engine loop + trigger system
  adding-character.md              ~180 lines   checklist + template
  adding-gear.md                   ~120 lines   Lightcone / Relic / Planar
  damage-formula.md                ~150 lines   damage pipeline + debug flags
.claude/skills/
  add-character/SKILL.md                        character workflow
  add-gear/SKILL.md                             gear workflow
  verify-build/SKILL.md                         compile + run + compare
```

### CLAUDE.md

Contains only what is needed on every task:

- **Project overview** — HSR combat/damage simulator, C++17, header-only, single
  translation unit.
- **Build and run** — the two entry points, exact commands, ~42s compile time (so
  timeouts must be set generously), and the note that `ManualBuilder.exe` needs no
  input while `Application.exe` is interactive.
- **Repo map** — a short table: `src/Declaration` vs `src/Defination`, `Data/`,
  `Enum/`, `Setting.h`, `SettingFunction.h`, `note/`.
- **Core mental model** — five or six lines: the engine is driven by global trigger
  lists declared in `src/Setting.h`; a character is a namespace whose `Setup()` pushes
  lambdas onto those lists.
- **Hard rules** — see below.
- **Where to look next** — a routing table from task type to `docs/*.md` and skills.
- **Conventions** — commit prefixes `feat :` / `fix :`, `.exe` and `.vscode/` are
  gitignored, `#pragma region` is used for folding, `note/*.txt` is the owner's Thai
  scratch list.

### Hard Rules

1. Adding a character touches three places: the new `.h` under
   `Data/Character/<Path>/`, an `#include` in `All_<Path>_char.h`, and a branch in
   `CharSelector()` in `SettingFunction.h`. Missing the third is the existing
   Dahlia/Fugue bug.
2. Adding gear touches two or three places: the new `.h`, the matching `All_*.h`, and
   the corresponding selector in `SettingFunction.h`.
3. Every timed buff needs a matching removal, driven by `isBuffEnd()` / `isDebuffEnd()`
   in `Before_turn_List` or `After_turn_List`. Without it the stat stays applied
   forever.
4. Pick the trigger list that matches the actual event, and set `PRIORITY_*`
   correctly — buffs must resolve before attacks.
5. Never edit `Setting.h`, `Combat.h`, or `CalStats.h` to make one character work.
   Those are shared by every unit.
6. After any change, compile **and** run. A clean compile alone is not verification.
7. Compare damage numbers before and after. If an unrelated character's numbers move,
   shared state was touched by accident — stop and report.
8. Never commit `.exe` files.

### docs/architecture.md

For refactoring and engine comprehension.

- The full simulation loop:
  `Setup() → Reset() → Set_Stats() → Start_game() →` per wave
  `Start_wave() → [Find_turn() → Atv_fix() → Take_action()] → Cal_DamageSummary() →
  printRoundResult() → Reroll_substats()`.
- The action-value model: `Current_atv`, `Wave[]` as a budget, `turn` as the current
  `ActionValueStats*`, and `Action_forward()`.
- A complete table of every trigger list in `Setting.h`: list name, the `TriggerFunc`
  subclass and its callback signature, where `Event.h` fires it, and a real usage
  example from an existing character.
- A table of the `PRIORITY_*` constants and what ordering they buy.
- Class hierarchy: `Unit → AllyUnit → CharUnit / MemoSprite`, `Enemy`, and
  `ActionData → AllyActionData → AllyAttackAction / AllyBuffAction`.
- The global state in `Setting.h` (`charUnit`, `allyList`, `enemyList`, `sp`,
  `phaseStatus`, and one-off flags such as `DahliaCheck`) and why it is fragile.
- The Declaration/Defination split, the include order
  (`Setting.h → Class → Function → Data`), and the rule that a new data header starts
  with `#include "../include.h"`.

### docs/adding-character.md

Uses `Dahlia.h` as the reference implementation.

- The three-point registration checklist, plus confirming the correct Path folder.
- A commented `namespace X { void Setup(int E, LC, Relic, Planar) { ... } }` template.
- The standard order inside `Setup()`: `SetCharBasicStats` → `SetAllyBaseStats` →
  substats and stat requirements → `LC(ptr); Relic(ptr); Planar(ptr);` →
  `#pragma region Ability` with BA/Skill/Fua as `function<void()>` → `Turn_func` →
  `addUltCondition` and `Ultimate_List` → remaining trigger registrations.
- A helper-function map: `Attack`, `addDamageIns(DmgSrc(...))`, `addEnemyBounce`,
  `addToActionBar`, `Deal_damage`, `buffSingle` / `buffAllAlly`, `debuffSingleApply` /
  `debuffAllEnemyApply`, `isHaveToAddBuff` / `isBuffEnd` / `isDebuffEnd`,
  `getBuffNote` / `setBuffNote`, `getBuffCheck` / `setBuffCheck`, `genSkillPoint`,
  `Increase_energy`, `weaknessApply`, `Superbreak_trigger`, `Action_forward`,
  `chooseCharacterBuff` / `chooseSubUnitBuff`, and
  `turn->canCastToAllyUnit()` / `canCastToEnemy()`.
- The Eidolon pattern (`ptr->Eidolon >= N`) and the Technique pattern
  (`ptr->Technique` checked inside `Start_game_List`).
- Buff-name strings are real lookup keys and must be unique per character
  (`"Dahlia A2"`, `"Dahlia E4"`).

### docs/adding-gear.md

- **Lightcone** — file under `Lightcone/<Path>/`, exposed as a function returning
  `function<void(CharUnit*)>` parameterised by superimpose level; registered in
  `All_<Path>_LC.h` and `LightConeSelector()`.
- **Relic** — four-piece sets plus `PairSet(PairSetType, PairSetType)` for two
  two-piece bonuses; registered in `All_Relic.h` and `RelicSelector()`.
- **Planar** — some take an argument (`GiantTree(0)`, `FirmanentFrontline(0)`);
  registered in `All_Planar.h` and `PlanarSelector()`.
- Relic main stats are declared per character via `setRelicMainStats(...)`.

### docs/damage-formula.md

For bug fixing and formula auditing.

- The damage pipeline: `DmgSrc` → `damageSplit` → `Attack()` → `CalDamage`
  (base × damage boost × defence multiplier × resistance multiplier × vulnerability ×
  crit × …), with file and line references into `Calculate/`.
- Break, Super Break, and toughness handling; DoT (`Dot_trigger`, `breakDotList`);
  Freeze and Entanglement.
- Healing (`CalHeal`, `CalHealStats`), shields, and `ChangeHP`.
- A table of the `CharUnit` debug flags — `enableCheckDamage()`,
  `enableCheckDamageFormula(DmgFormulaMode::…)`, the `enableCheckHeal*` family, and
  `CharCmd::Timing_print()` — describing the output each one produces.
- A procedure for isolating a bug: build the smallest possible team in
  `ManualBuilder.cpp`, then enable formula checking on the unit under test.

### Skills

**`add-character`** — triggered when the user asks to add or modify a character:

1. Ask for any missing data (path, element, base stats, multipliers, E1–E6, traces,
   technique).
2. Read `docs/adding-character.md` and open the most mechanically similar existing
   character as a reference.
3. Write the new header under `Data/Character/<Path>/`.
4. Register all three points, as an explicit checklist.
5. Add the character to a test team in `ManualBuilder.cpp`, then invoke `verify-build`.
6. Report: compile result, damage produced, and whether any unrelated character's
   numbers changed.

**`add-gear`** — the same shape, branching by gear type because the registration
points differ.

**`verify-build`** — callable on its own and used by the other two:

1. Compile both `ManualBuilder.cpp` and `Application.cpp` with `-std=c++17`. Each
   takes about 42 seconds, so tool timeouts must be at least 120 seconds.
2. Run `ManualBuilder.exe` with empty piped input and capture the summary.
3. Compare against the baseline captured before the change. If an unrelated
   character's numbers moved, stop and report rather than continuing.
4. Write build artifacts to the scratchpad directory, not the repository root, to
   avoid scattering `.exe` files.

**Restore rule:** `add-character` and `add-gear` edit `ManualBuilder.cpp` to build a
test team. That file is the owner's personal workspace, full of commented-out team
compositions. The skills must restore it to its original state after testing unless
the owner asks to keep the change.

## Out of Scope

- Fixing the missing `Dahlia` and `Fugue` entries in `CharSelector()`. It is recorded
  as a known gap in `docs/adding-character.md`.
- Any change to engine, character, or gear code.
- Build system changes. The existing `.vscode/tasks.json` is left alone even though
  one of its tasks specifies `-std=c++14`.
