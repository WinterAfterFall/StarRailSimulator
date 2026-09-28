---
schema_version: "1.0.0"
unit_id: 1503
name: "Pearl"
slug: "pearl"
rarity: 5
element: "Ice"
path: "Elation"
role: "Sustain"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1503/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
---

# Pearl

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Code: `src/Defination/Data/Character/Elation/Pearl.h` · Elation Skill Participant ID = 104. Role "Sustain" is our label (nanoka has no role field). Scales on **DEF**, not ATK.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1203 | 466 | 728 | 99 | 100 | 180 |

Minor traces (total): **DEF +22.5% · SPD +9 · Effect RES +10% · Elation +10%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Brushstroke: Trace the Severed Stream | Single | ST 10 | +1 | 20 | 90% DEF |
| Basic (Enh., non-Elation Archetype) | Brushstroke: Render the Great Wave | AoE | AoE 30 | +1 | 30 | 100% DEF to all enemies · heal all allies 8% DEF + 160, and the lowest-HP% ally again for the same |
| Basic (Enh., Elation Archetype) | Brushstroke: Imagenate the Starry Night | AoE | AoE 30 | +1 | 30 | Same as Great Wave + 15% Ice Elation DMG while holding Certified Banger |
| Skill | Relume Life's Light | Defence | — | −1 | 30 | +15 Certified Banger · heal all allies 12% DEF + 240, and the lowest-HP% ally again for the same |
| Ultimate | Appraise Soul's Ground | Support | — | — | 5 | +20 Certified Banger · "Deep Learning" on 1 other ally → "Aesthetic Archetype" · advance / extra turn by Elation count · 60% Elation after each Enhanced Basic |
| Talent | Grow Grace from Grit | Defence | — | — | — | Certified Banger = Repellency (1 pt = 200) blocking 60% of DMG · ally at ≤50% HP takes −30% DMG · CB never expires, max 50 |
| Technique | Recast Masterwork in Nacre | Support | — | — | — | Next battle: +20 Certified Banger, Deep Learning (2 Charges) on the Archetype holder |
| Elation Skill | Dissolve Reason into Elation | Support | — | — | 5 | All allies' next attack adds 10 / 15 / 20 / 40% Elation DMG (1 / 2 / 3 / 4+ Elation characters) |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Pearl's Certified Banger** — Pearl gains Certified Banger directly from her kit (Skill +15, Ult +20, A4 +5 per ally turn start). Hers **never expires** and is capped at **50**.
- **Certified Banger as Repellency (Talent)** — each 1 point of Certified Banger works as 200 Repellency. When an ally takes DMG, Pearl spends Repellency to block **60%** of that DMG. Separately, any ally at ≤50% current HP takes 30% less DMG.
- **Deep Learning / Aesthetic Archetype (Ult)** — targets 1 ally other than Pearl, who becomes the "Aesthetic Archetype". It gives the Archetype an action advance based on how many Elation characters are on the team: 1 → 10%, 2 → 15%, 3+ → 30%. With 4+ Elation characters the Archetype gets 1 extra turn instead. At its start they gain 30 Certified Banger and 60 Punchline, both removed when that extra turn ends.
- **Enhanced Basic (during Deep Learning)** — Pearl's Basic becomes "Render the Great Wave", or "Imagenate the Starry Night" if the Archetype is Elation-path. After attacking it deals 60% Ice Elation DMG **calculated with the Archetype's stats**. Deep Learning has 3 Charges (2 from the Technique); each Enhanced Basic uses 1 Charge, and when none are left after acting it ends.
- **Elation Skill** — the bonus hit uses each ally's own element and lands on the target of their next attack; E4 doubles the multiplier.

## Level tables

Basic ATK — Brushstroke: Trace the Severed Stream (DEF%)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| DEF% | 45 | 54 | 63 | 72 | 81 | **90** | 99 | 108 | 117 | 126 |

Enhanced Basic — Render the Great Wave / Imagenate the Starry Night (they share the table; Starry Night adds the CB Elation row). These follow **Basic ATK level**.

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| AoE DEF% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |
| Heal DEF% | 4 | 4.8 | 5.6 | 6.4 | 7.2 | **8** | 8.8 | 9.6 | 10.4 | 11.2 |
| Heal flat | 80 | 96 | 112 | 128 | 144 | **160** | 176 | 192 | 208 | 224 |
| CB Elation% (Starry Night only) | 10 | 11 | 12 | 13 | 14 | **15** | 16.25 | 17.5 | 18.75 | 20 |

Skill — Relume Life's Light (constant: +15 Certified Banger)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Heal DEF% | 6 | 6.6 | 7.2 | 7.8 | 8.4 | 9 | 9.75 | 10.5 | 11.25 | **12** | 12.6 | 13.2 | 13.8 | 14.4 | 15 |
| Heal flat | 120 | 132 | 144 | 156 | 168 | 180 | 195 | 210 | 225 | **240** | 252 | 264 | 276 | 288 | 300 |

Ultimate — Appraise Soul's Ground (constant: +20 CB · 3 Charges · advance 10/15/30% · extra turn +30 CB +60 Punchline)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| After-attack Elation% | 30 | 33 | 36 | 39 | 42 | 45 | 48.75 | 52.5 | 56.25 | **60** | 63 | 66 | 69 | 72 | 75 |

Talent — Grow Grace from Grit (constant: 1 CB = 200 Repellency · block 60% · HP ≤ 50% · CB cap 50)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| DMG reduction % | 15 | 16.5 | 18 | 19.5 | 21 | 22.5 | 24.375 | 26.25 | 28.125 | **30** | 31.5 | 33 | 34.5 | 36 | 37.5 |

Elation Skill — Dissolve Reason into Elation (by number of Elation characters on the team)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 Elation char % | 5 | 5.5 | 6 | 6.5 | 7 | 7.5 | 8.125 | 8.75 | 9.375 | **10** | 10.5 | 11 | 11.5 | 12 | 12.5 |
| 2 Elation chars % | 7.5 | 8.25 | 9 | 9.75 | 10.5 | 11.25 | 12.1875 | 13.125 | 14.0625 | **15** | 15.75 | 16.5 | 17.25 | 18 | 18.75 |
| 3 Elation chars % | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |
| 4+ Elation chars % | 20 | 22 | 24 | 26 | 28 | 30 | 32.5 | 35 | 37.5 | **40** | 42 | 44 | 46 | 48 | 50 |

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Panoptic Vision | DEF ≥ 2400 → Elation +32%, then +3% per 100 DEF above 2400 (max 3600 excess DEF). Outgoing Healing + 20% of her Elation |
| A4 | Sensory Latitude | While holding Certified Banger: all allies Effect RES +50%. At the start of each ally's turn → Pearl +5 CB (max 50; the gainable amount resets at the start of Pearl's turn). Enhanced Basic or Skill → dispel 1 debuff from all allies |
| A6 | Aesthetic Firewall | After entering combat and using Ult, if the Archetype is an Elation character, their next Ult gives Pearl a fixed 90 Energy. Does not stack |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Nestle That Pearl in Uninked Tides | With 2 / 3 / 4+ Elation characters → all allies Elation +10 / 20 / 60%. An ally hit by a fatal blow is not knocked down and instead heals 50% Max HP (2× per battle) |
| 2 | Crop That Dappled Dawn | All allies' Elation DMG merrymake +15%. Ult also gives the action advance to other Elation allies (not Pearl or the Archetype), and the extra turn's CB and Punchline gains are +100% |
| 3 | Sketch That Suspended Wave | Ult +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 4 | Study That Veiled Smile | Elation Skill's granted Elation DMG multiplier +100% for all allies |
| 5 | Render Those Starlit Swirls | Skill +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 6 | Compute Life From One Shell | While Deep Learning is active: all allies All-Type RES PEN +20%. Pearl's Enhanced Basic adds Ice Elation DMG equal to 240% based on the Archetype's stats |

## Recommended (nanoka)

- LC: Colors for Tomorrow · Mushy Shroomy's Adventures
- Relics: Dreamlit Actor / Diviner of Distant Reach / Messenger Traversing Hackerspace (4) · Sprightly Vonwacq / Lushaka, the Sunken Seas / Broken Keel (2)
- Main stats: Body Outgoing Healing · Feet SPD · Sphere DEF% · Rope Energy Regen — substats DEF% / SPD
