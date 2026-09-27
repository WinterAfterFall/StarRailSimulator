---
schema_version: "1.0.0"
unit_id: 1513
name: "Aventurine • Waveflair"
slug: "aventurine-waveflair"
rarity: 5
element: "Quantum"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1513/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen + nanoka JSON record (2026-09-26, schema 1.1.0) — replaced by the compact nanoka.cc format"
---

# Aventurine • Waveflair

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Not implemented in code yet. Role "Main DPS" is our label (nanoka has no role field).

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1164 | 485 | 606 | 107 | 100 | 130 |

Minor traces (total): **CRIT Rate +18.7% · SPD +9 · Elation +10%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Dead Center, the Torrent Hits | Single | ST 10 | +1 | 20 | 100% ATK |
| Skill | Kill Shot, the Sands Boil | AoE | AoE 10 | −1 | 30 | 240% ATK to all enemies · +4 Punchline · +4 Fervor |
| Ultimate | Grand Slam, Crest That High Tide | AoE | AoE 20 | — | 5 | 400% ATK to all enemies · +6 Punchline · +8 Fervor · SPD +30% for 4 turns |
| Talent | Ante Up, the Abyss Answers | Enhance | — | — | — | His Certified Banger +1 turn · +1 Fervor & +1 Punchline per teammate attack · 10 Fervor → free Elation Skill · CB bonus: Skill +40% / Ult +72% Elation AoE |
| Technique | Make Waves in Still Waters | Attack | ST 20 | — | — | On engage: 100% ATK AoE · +2 Fervor · +20 Certified Banger |
| Elation Skill | Cheers! To Summer's Blaze | AoE | ST 3.33 / AoE 10 | — | 5 | 60% Elation AoE · 10 × 18% Elation bounces |
| Elation Skill (Enh.) | All In! To Summer's Blaze | AoE | ST 5 / AoE 20 | — | 5 | Same as above · then spends all Fervor: +1 × 21% Elation bounce per Fervor |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Fervor** — a personal counter, capped at 30 (E2: 50). Sources: Skill +4, Ult +8, +1 each time a teammate attacks, Technique +2, A6 +2 per trigger, E2 +4 after his Elation Skill.
- **Talent trigger** — when Fervor reaches 10, he uses "Cheers! To Summer's Blaze" once, counting a fixed 20 Punchline. After that, his next Elation Skill during an Aha Instant is upgraded to "All In! To Summer's Blaze". E1 makes the free cast trigger at 10 / 20 / 30 Fervor (E2 adds 40 / 50).
- **All In!** — same hits as Cheers!, then spends **all** Fervor and adds one 21% Quantum Elation bounce per Fervor spent. With E6, casting All In! outside an Aha Instant no longer spends Fervor.
- **Certified Banger bonus** — while holding Certified Banger, Skill adds 40% Quantum Elation DMG to all enemies and Ultimate adds 72%. His own Certified Banger lasts 1 turn longer than usual.

## Level tables

Basic ATK — Dead Center, the Torrent Hits

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Skill — Kill Shot, the Sands Boil (constant: +4 Punchline · +4 Fervor)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE ATK% | 120 | 132 | 144 | 156 | 168 | 180 | 195 | 210 | 225 | **240** | 252 | 264 | 276 | 288 | 300 |

Ultimate — Grand Slam, Crest That High Tide (constant: +6 Punchline · +8 Fervor · SPD buff 4 turns)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE ATK% | 240 | 256 | 272 | 288 | 304 | 320 | 340 | 360 | 380 | **400** | 416 | 432 | 448 | 464 | 480 |
| SPD +% | 12 | 13.8 | 15.6 | 17.4 | 19.2 | 21 | 23.25 | 25.5 | 27.75 | **30** | 31.8 | 33.6 | 35.4 | 37.2 | 39 |

Talent — Ante Up, the Abyss Answers (constant: trigger at 10 Fervor · Fervor cap 30 · fixed 20 Punchline · +1 Fervor / +1 Punchline per teammate attack)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Skill Elation% | 20 | 22 | 24 | 26 | 28 | 30 | 32.5 | 35 | 37.5 | **40** | 42 | 44 | 46 | 48 | 50 |
| Ult Elation% | 36 | 39.6 | 43.2 | 46.8 | 50.4 | 54 | 58.5 | 63 | 67.5 | **72** | 75.6 | 79.2 | 82.8 | 86.4 | 90 |

Elation Skill — Cheers! To Summer's Blaze (constant: 10 bounces)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE Elation% | 30 | 33 | 36 | 39 | 42 | 45 | 48.75 | 52.5 | 56.25 | **60** | 63 | 66 | 69 | 72 | 75 |
| Per bounce Elation% | 9 | 9.9 | 10.8 | 11.7 | 12.6 | 13.5 | 14.625 | 15.75 | 16.875 | **18** | 18.9 | 19.8 | 20.7 | 21.6 | 22.5 |

Enhanced Elation Skill — All In! To Summer's Blaze (constant: 10 bounces)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE Elation% | 30 | 33 | 36 | 39 | 42 | 45 | 48.75 | 52.5 | 56.25 | **60** | 63 | 66 | 69 | 72 | 75 |
| Per bounce Elation% | 9 | 9.9 | 10.8 | 11.7 | 12.6 | 13.5 | 14.625 | 15.75 | 16.875 | **18** | 18.9 | 19.8 | 20.7 | 21.6 | 22.5 |
| Per Fervor Elation% | 10.5 | 11.55 | 12.6 | 13.65 | 14.7 | 15.75 | 17.0625 | 18.375 | 19.6875 | **21** | 22.05 | 23.1 | 24.15 | 25.2 | 26.25 |

Technique: fixed 100% ATK AoE + 2 Fervor + 20 Certified Banger.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Party in Perfect Paradise | SPD ≥ 140 → Elation +30%, then +1% per SPD above 140 (max 200 excess SPD) |
| A4 | Revel in Raging Tides | At battle start, **if there are other Elation characters**: while he is on the field, all allies Elation +20% and his own Elation +80% more. **If he is the only Elation character**: his Elation Skill DMG counts as a Follow-Up ATK; after each teammate attack he gains +2 CB and +1 Punchline, and Aha SPD +25 until the Aha Instant ends |
| A6 | Sift Through Gilded Dreams | CRIT DMG +48%. After a teammate uses Basic / Skill / FuA / Ult → all allies CRIT DMG +48% for 3 turns and he gains +2 Fervor. Up to 6 triggers; the count resets when he uses Skill |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | A Holiday on the Line | All-Type RES PEN +24%. Talent: the free Cheers! triggers at 10 / 20 / 30 Fervor |
| 2 | Idle as the Turning Tide | Fervor cap 50; 40 / 50 also trigger the Talent. After his Elation Skill → +4 Fervor |
| 3 | A Rendezvous Served Chilled | Skill +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 4 | Sunlight Runs No Tab | Using Skill → all allies' DMG ignores 18% DEF for 3 turns |
| 5 | Into the Eye of the Jackpot | Ult +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 6 | The Past in Fast Lane | His Elation DMG merrymake +25%. After using his Elation Skill 2 times, every later one is All In!. All In! cast outside an Aha Instant no longer spends Fervor |

## Recommended (nanoka)

- LC: Summer Rides the Surf · Today's Good Luck · A Little Getaway
- Relics: Ever-Glorious Magical Girl / Genius of Brilliant Stars (4) · Punklorde Stage Zero / The Wondrous BananAmusement Park / Sigonia, the Unclaimed Desolation (2)
- Main stats: Body CRIT Rate · Feet SPD · Sphere Quantum DMG · Rope Energy Regen — substats CRIT Rate / CRIT DMG / SPD
