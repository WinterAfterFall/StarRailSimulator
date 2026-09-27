---
schema_version: "1.0.0"
unit_id: 1505
name: "Evanescia"
slug: "evanescia"
rarity: 5
element: "Physical"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1505/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen record (2026-05-30, unit_id 89) — replaced by nanoka.cc data"
---

# Evanescia

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Code: `src/Defination/Data/Character/Elation/Evanescia.h` · Elation Skill Participant ID = 146.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1048 | 737 | 461 | 104 | 100 | 480 |

Minor traces (total): **CRIT Rate +18.7% · Elation +18% · SPD +5**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Syllabus: Pop Quiz | Single | ST 10 | +1 | 20 | 100% ATK |
| Skill | Discipline: Final Verdict | Blast | ST 20 / adj 10 | −1 | 30 | 300% ATK main · 150% ATK adjacent · +10 Punchline |
| Ultimate | Swordsong: Absolution Denied | AoE | ST 5 / AoE 20 | — | 5 | 160% ATK to all enemies · then 5 × 120% ATK bounces |
| Talent | Youth: Halcyon Evermore | Enhance | AoE 10 (Master Fox) | — | — | Elation = 20% of CRIT DMG · Energy ⇄ Certified Banger · every 240 Energy → Master Fox FuA 100% ATK AoE |
| Technique | Petalfall: Floral Reminiscence | Attack | ST 20 | — | — | On engage: 100% ATK AoE · +20 Certified Banger |
| Elation Skill | Scarlet: Elation or Execution | AoE | AoE 20 | — | 5 | 110% Elation AoE · +5 Certified Banger |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Elation from CRIT DMG** — Evanescia gains Elation equal to 20% of her CRIT DMG.
- **Energy ⇄ Certified Banger** — whenever she gains Energy she gains the same amount of Certified Banger, and whenever she gains Certified Banger she gains the same amount of Energy. At most 100 points per single gain are counted for this conversion.
- **Master Fox** — each time she has accumulated 240 Energy gained, that 240 is spent and "Master Fox" launches a Follow-Up ATK: 100% ATK Physical DMG to all enemies, then Evanescia regenerates 10 Energy. A single Energy gain can add at most 240 to the accumulation.
- **Certified Banger bonus (Talent)** — while holding Certified Banger: Skill adds 16% Physical Elation DMG to the enemies hit; Ultimate adds 24% Elation DMG to all enemies plus 28% Elation DMG to each enemy hit by the bounces; Master Fox's FuA adds 25% Elation DMG to all enemies. When the Ultimate deals Elation DMG, it counts at least as much Certified Banger as her Max Energy.
- The Ultimate's level table also carries a constant 88 that the text does not explain.

## Level tables

Basic ATK — Syllabus: Pop Quiz

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Skill — Discipline: Final Verdict (constant: +10 Punchline)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Main ATK% | 150 | 165 | 180 | 195 | 210 | 225 | 243.75 | 262.5 | 281.25 | **300** | 315 | 330 | 345 | 360 | 375 |
| Adjacent ATK% | 75 | 82.5 | 90 | 97.5 | 105 | 112.5 | 121.875 | 131.25 | 140.625 | **150** | 157.5 | 165 | 172.5 | 180 | 187.5 |

Ultimate — Swordsong: Absolution Denied (constant: 5 bounces)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE ATK% | 80 | 88 | 96 | 104 | 112 | 120 | 130 | 140 | 150 | **160** | 168 | 176 | 184 | 192 | 200 |
| Per bounce ATK% | 72 | 76.8 | 81.6 | 86.4 | 91.2 | 96 | 102 | 108 | 114 | **120** | 124.8 | 129.6 | 134.4 | 139.2 | 144 |

Talent — Youth: Halcyon Evermore (constant: Elation = 20% CRIT DMG · 240 Energy per Master Fox · +10 Energy · 100 CB cap per gain)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Master Fox FuA ATK% | 50 | 55 | 60 | 65 | 70 | 75 | 81.25 | 87.5 | 93.75 | **100** | 105 | 110 | 115 | 120 | 125 |
| Master Fox Elation% | 12.5 | 13.75 | 15 | 16.25 | 17.5 | 18.75 | 20.3125 | 21.875 | 23.4375 | **25** | 26.25 | 27.5 | 28.75 | 30 | 31.25 |
| Skill Elation% | 8 | 8.8 | 9.6 | 10.4 | 11.2 | 12 | 13 | 14 | 15 | **16** | 16.8 | 17.6 | 18.4 | 19.2 | 20 |
| Ult AoE Elation% | 12 | 13.2 | 14.4 | 15.6 | 16.8 | 18 | 19.5 | 21 | 22.5 | **24** | 25.2 | 26.4 | 27.6 | 28.8 | 30 |
| Ult bounce-target Elation% | 14 | 15.4 | 16.8 | 18.2 | 19.6 | 21 | 22.75 | 24.5 | 26.25 | **28** | 29.4 | 30.8 | 32.2 | 33.6 | 35 |

Elation Skill — Scarlet: Elation or Execution (constant: +5 Certified Banger)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE Elation% | 55 | 60.5 | 66 | 71.5 | 77 | 82.5 | 89.375 | 96.25 | 103.125 | **110** | 115.5 | 121 | 126.5 | 132 | 137.5 |

Technique: fixed 100% ATK AoE + 20 Certified Banger.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Watch All Revels | CRIT Rate +30%. Ult bounces +1 / +2 / +4 when there are ≥3 / 2 / 1 enemies. When a teammate with a lower Elation Skill Participant ID gains Certified Banger, Evanescia converts 50% of it into her own |
| A4 | Weigh All Truths | Master Fox's attacks apply Vulnerability: DMG taken +12% for 3 turns |
| A6 | Best All Blooms | When a teammate's Certified Banger ends, Evanescia converts 50% of it into her own |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Home: A Prayer in Dance | All-Type RES PEN +20%. After Master Fox attacks → triggers her Elation Skill 1 more time. Elation Skill gives her +10 Certified Banger |
| 2 | Voyage: A Wish for Everbloom | CRIT DMG +36%. CB gained through A2 / A6 is increased by a further 50% / 100% |
| 3 | Blade: A Feast on Evils | Ult +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 4 | Meadow: A Ruin by Vice | Her DMG ignores 15% DEF |
| 5 | Arcadia: A Glimpse of Fates | Skill +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 6 | Maiden: A Step into Dreams | Her Certified Banger lasts +1 turn. Her Elation DMG merrymake +15%, +2% per 100 CB held (max 1000 CB counted). First Ult after entering combat → fixed 120 Energy; can trigger again every 4 more Ults |

## Recommended (nanoka)

- LC: Until the Flowers Bloom Again · Today's Good Luck · Tomorrow, Together
- Relics: Ever-Glorious Magical Girl / Wavestrider Captain / Champion of Streetwise Boxing (4) · Punklorde Stage Zero / Sigonia, the Unclaimed Desolation / Space Sealing Station (2)
- Main stats: Body CRIT Rate · Feet SPD · Sphere ATK% · Rope Energy Regen — substats CRIT Rate / CRIT DMG / SPD / ATK%
