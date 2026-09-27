---
schema_version: "1.0.0"
unit_id: 8009
name: "Trailblazer • Elation"
slug: "trailblazer-elation"
rarity: 5
element: "Lightning"
path: "Elation"
role: "Support"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/8009/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen record (2026-05-30, unit_id 90) — replaced by nanoka.cc data"
---

# Trailblazer • Elation

> Source: hsr.nanoka.cc (game data 4.5.54; the data file names the unit `{NICKNAME}`). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Code: `src/Defination/Data/Character/Elation/EMC.h` (unit `"EMC"`) · Elation Skill Participant ID = 120.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1087 | 466 | 631 | 106 | 100 | 160 |

Minor traces (total): **ATK +28% · CRIT Rate +12% · CRIT DMG +13.3%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Make Some Noise | Single | ST 10 | +1 | 20 | 100% ATK |
| Skill | Let the Storm Rage On | AoE | AoE 20 | −1 | 30 | 60% ATK to all enemies · +20 Certified Banger |
| Ultimate | May the Trailblaze Fly You Starward | Support | — | — | 5 | +5 Punchline · 1 ally CRIT DMG +50% for 3 turns + CC cleanse · Elation-Skill target: +10 CB and casts its Elation Skill now (fixed 20 Punchline) · otherwise: advance 50% |
| Talent | That Smile Hits Different | Support | — | — | — | After attacking: fixed +10 Energy, +3 Punchline · CB bonus: Skill +30% Elation AoE (uses the team's highest CB) |
| Technique | We Are So Back! | Enhance | — | — | — | Next battle: all allies Elation +20% (high chance) or +30% (low chance) for 3 turns |
| Elation Skill | I Said "Elation," Did I Stutter? | AoE | AoE 20 | — | 5 | 8 × 20% Elation bounces · then 60% Elation split across all enemies |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Ultimate, two branches** — always: +5 Punchline, 1 chosen ally CRIT DMG +50% for 3 turns, and Crowd Control debuffs on them are dispelled. If that ally **has an Elation Skill**, they gain +10 Certified Banger and immediately use their Elation Skill once, counting a fixed 20 Punchline (if the enemy dies first, it goes to a newly entering enemy). If the ally **has no Elation Skill**, they are advanced forward by 50% instead.
- **Talent** — after every attack, Trailblazer regenerates a fixed 10 Energy and gains 3 Punchline. While holding Certified Banger, the Skill adds 30% Lightning Elation DMG to all enemies, and that hit is calculated with the **highest Certified Banger value among all allies**.
- **Technique** — rolls one effect: "Irrepressible Laughter" (high chance) = Elation +20%, or "Hearty Laughter" (low chance) = Elation +30%; applied to all allies for 3 turns at battle start. The sim should pick one deterministically (see the determinism rule).

## Level tables

Basic ATK — Make Some Noise

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Skill — Let the Storm Rage On (constant: +20 Certified Banger)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE ATK% | 30 | 33 | 36 | 39 | 42 | 45 | 48.75 | 52.5 | 56.25 | **60** | 63 | 66 | 69 | 72 | 75 |

Ultimate — May the Trailblaze Fly You Starward (constant: +5 Punchline · 3 turns · +10 CB · fixed 20 Punchline · advance 50%)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| CRIT DMG +% | 30 | 32 | 34 | 36 | 38 | 40 | 42.5 | 45 | 47.5 | **50** | 52 | 54 | 56 | 58 | 60 |

Talent — That Smile Hits Different (constant: fixed +10 Energy · +3 Punchline)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Skill Elation% | 15 | 16.5 | 18 | 19.5 | 21 | 22.5 | 24.375 | 26.25 | 28.125 | **30** | 31.5 | 33 | 34.5 | 36 | 37.5 |

Elation Skill — I Said "Elation," Did I Stutter? (constant: 8 bounces)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Per bounce Elation% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |
| Final split Elation% | 30 | 33 | 36 | 39 | 42 | 45 | 48.75 | 52.5 | 56.25 | **60** | 63 | 66 | 69 | 72 | 75 |

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | On Cloud Nine | Every 200 ATK above 1000 → Elation +10%, max +60% |
| A4 | Screw It, We Ball | CRIT Rate +15%. After using Ult → team +1 SP |
| A6 | Aha, Sic 'Em! | After any ally uses an Elation Skill → Trailblazer's next Skill gives +2 more Certified Banger |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Believe In the Light | After using Skill → the next Ult gives allies +2 more Certified Banger; stacks up to 3× |
| 2 | History in the Making... | Ult also gives the target ally Elation +12% for 2 turns |
| 3 | Into the Spotlight | Skill +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 4 | Save the World. Just Because. | Using Elation Skill → enemies take +10% DMG for 2 turns |
| 5 | Love & Courage: Always in Style | Ult +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 6 | The Cosmic Legend Cometh! | Using Elation Skill → own CRIT DMG +100% for 3 turns |

## Recommended (nanoka)

- LC: When She Decided to See · Elation Brimming With Blessings · Tomorrow, Together
- Relics: Diviner of Distant Reach / Ever-Glorious Magical Girl / Musketeer of Wild Wheat (4) · Lushaka, the Sunken Seas / Punklorde Stage Zero / Space Sealing Station (2)
- Main stats: Body CRIT DMG · Feet SPD · Sphere ATK% · Rope Energy Regen — substats CRIT Rate / CRIT DMG / SPD / ATK%
