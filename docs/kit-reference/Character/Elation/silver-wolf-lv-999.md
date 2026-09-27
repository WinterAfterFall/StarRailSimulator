---
schema_version: "1.0.0"
unit_id: 1506
name: "Silver Wolf • Lv. 999"
slug: "silver-wolf-lv-999"
rarity: 5
element: "Imaginary"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1506/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen record (2026-05-30) — replaced by nanoka.cc data; toughness, level tables and the Pro-Gamer Move Elation Skill were missing before"
---

# Silver Wolf • Lv. 999

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1048 | 388 | 655 | 110 | 100 | 60 (not used — Ult is gated by Hidden MMR) |

Minor traces (total): **SPD +9 · CRIT Rate +18.7% · Elation +10%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Key values (sim level) |
|---|---|---|---|---|---|
| Basic | One Punch! | Single | ST 10 | +1 | 100% ATK |
| Basic (Enh.) | Bonus Stage: αWolf Instant | Bounce | ST 10 / AoE 10 | 0 (cannot recover SP) | 240% ATK over 100 bounces · 3× Top Loot Box · Final Hit 100% ATK split across all enemies · +15% per 60 Hidden MMR, max 2 stacks |
| Skill | Trigger Happy | AoE | AoE 10 | −1 | +5 Punchline · 160% ATK to all enemies |
| Ultimate | God Mode: ON! | Enhance | — | — | Enter "Godmode Player", advance 100% · Zone · Top Loot Box 90% Elation (split) |
| Top Loot Box effects | Big Flipping Sword / Kaboom Eggsplosion / Funky Munch Bean | AoE | AoE 10 each | — | True DMG 20% of this box's total → highest-HP enemy / +2 SP / +3 Punchline |
| Talent | I Carry, We Win | Enhance | — | — | Ult at 60 Hidden MMR (+240 overflow → 300) · CR +0.4%/MMR, past 100% CR → CD +0.8%/MMR · 40% Elation DMG on BA/Skill while holding Certified Banger |
| Technique | This? Absolute Meta! | Summon | — | — | Each wave start: 1 Top Loot Box using fixed 99 Certified Banger |
| Elation Skill | Pro-Gamer Move | Enhance | — | — | +15 Hidden MMR (normal state) |
| Elation Skill (Enh.) | Honkai-DMG Demo | Bounce | ST 10 | — | 6 × 90% Elation DMG to random enemies · reset Top Loot Box chance to initial (Godmode only) |
| Exclusive | McAwolfee 999 | Support | — | — | Once per wave: first enemy CC on an ally → all allies "Firewall" (CC immune) 1 turn |

### Mechanics (paraphrased)

- **Hidden MMR** — whenever Punchline is gained, SW999 gains the same amount of Hidden MMR. Ult usable at 60; cap 60 + 240 overflow = 300. Each point = CRIT Rate +0.4%; once CRIT Rate reaches 100%, each remaining point = CRIT DMG +0.8%.
- **Godmode Player** — CC immune, cannot Ult, gets Enhanced Basic ATK + Enhanced Elation Skill. Leaves after fully using Enhanced Basic ATK 3 times; Hidden MMR is cleared on exit.
- **Certified Banger bonus** — while holding Certified Banger, Basic ATK / Skill also deal 40% Imaginary Elation DMG to the enemies hit, and Enhanced Basic ATK's ability DMG becomes Elation DMG at the same multiplier.
- **Zone / Top Loot Box** — while in Godmode and holding Certified Banger, every 1 SP consumed by an ally has a fixed chance to trigger a Top Loot Box: 90% Imaginary Elation DMG split evenly among all enemies + 1 random effect. Chance starts at 100%; after each successful trigger the next chance becomes 20% of the current one. Honkai-DMG Demo resets it to 100%. Box effect weights: Kaboom is more likely when SP is low, Bean is more likely when Hidden MMR is low. A box triggered from Enhanced Basic ATK does not count as launching an attack.
- **Enhanced Basic ATK kill clause** — if every enemy dies mid-ability, it ends; when new enemies appear SW999 gets 1 extra turn and resumes with the remaining bounces/boxes; the first time per turn this happens, all buffs on her extend by 1 turn.

## Level tables

Basic ATK — One Punch! (A = ATK%)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Enhanced Basic — αWolf Instant (constant: 100 bounces · 3 boxes · per 60 MMR · max 2 stacks · +15%/stack)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Bounce total ATK% | 120 | 144 | 168 | 192 | 216 | **240** | 264 | 288 | 312 | 336 |
| Final Hit ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Skill — Trigger Happy (constant: +5 Punchline)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 80 | 88 | 96 | 104 | 112 | 120 | 130 | 140 | 150 | **160** | 168 | 176 | 184 | 192 | 200 |

Ultimate — God Mode: ON! (constant: advance 100% · chance decay ×0.2 · Sword True DMG 20% · Bean +3 PL · Kaboom +2 SP)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Top Loot Box Elation% | 45 | 49.5 | 54 | 58.5 | 63 | 67.5 | 73.125 | 78.75 | 84.375 | **90** | 94.5 | 99 | 103.5 | 108 | 112.5 |

Talent — I Carry, We Win (constant: Ult at 60 MMR · +240 overflow)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| BA/Skill Elation% | 20 | 22 | 24 | 26 | 28 | 30 | 32.5 | 35 | 37.5 | **40** | 42 | 44 | 46 | 48 | 50 |
| CR per MMR % | 0.2 | 0.22 | 0.24 | 0.26 | 0.28 | 0.3 | 0.325 | 0.35 | 0.375 | **0.4** | 0.42 | 0.44 | 0.46 | 0.48 | 0.5 |
| CD per MMR % | 0.4 | 0.44 | 0.48 | 0.52 | 0.56 | 0.6 | 0.65 | 0.7 | 0.75 | **0.8** | 0.84 | 0.88 | 0.92 | 0.96 | 1.0 |

Elation Skill — Pro-Gamer Move: +15 Hidden MMR at every level.

Elation Skill (Enh.) — Honkai-DMG Demo (constant: 6 hits)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Elation% per hit | 45 | 49.5 | 54 | 58.5 | 63 | 67.5 | 73.125 | 78.75 | 84.375 | **90** | 94.5 | 99 | 103.5 | 108 | 112.5 |

Technique: fixed 99 Certified Banger for the wave-start Top Loot Box.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | False Ending Speedrun | SPD ≥ 160 → Elation +50%, then +2% per SPD above 160 (max 100 excess SPD) |
| A4 | True Ending Unlocked | Using an Elation Skill with ≥ 20 Punchline counted → +20 Hidden MMR; ≥ 40 → another +20 |
| A6 | Secret Level Maxed | On entering Godmode Player → +20 Hidden MMR |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Aether Editing: Eidolon +1 | Enemies in the Zone take +20% DMG. On leaving Godmode, keep 20% of Hidden MMR instead of clearing it |
| 2 | It's a Feature, Not a Bug | On entering Godmode, all buffs on her extend by 1 turn. Within one Godmode, every 120 Hidden MMR gained (initial MMR counts) → 1 extra turn + 1 more Enhanced Basic ATK use |
| 3 | Max Lv. 15? Says who? | Skill +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 4 | I Came. I Saw. I One-Shot. | Honkai-DMG Demo additionally counts Punchline equal to the original amount × 5 |
| 5 | Basic ATK Is the New Ultimate | Ult +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 6 | Solo Maxxing! | Elation DMG during Enhanced Basic ATK: Merrymake +50%. Enemies entering combat get "Absolute Weakness": all-type Weakness, all-type Base RES → 0 (if already 0, that type's RES −20%) |

## Recommended (nanoka)

- LC: Welcome to the Cosmic City · Today's Good Luck
- Relics: Ever-Glorious Magical Girl (4) · Punklorde Stage Zero / Sigonia / Tengoku@Livestream (2)
- Main stats: Body CRIT Rate · Feet SPD · Sphere HP · Rope DEF — substats SPD / CRIT Rate / CRIT DMG
