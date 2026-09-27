---
schema_version: "1.0.0"
unit_id: 1512
name: "Robin • Summeretto"
slug: "robin-summeretto"
rarity: 5
element: "Wind"
path: "Remembrance"
role: "Support"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1512/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen + nanoka JSON record (2026-09-26, schema 1.1.0) — replaced by the compact nanoka.cc format"
---

# Robin • Summeretto

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent Lv.10, Memosprite Skill/Talent Lv.6**.
> Code: `src/Defination/Data/Character/Remembrance/RobinSummeretto.h`. Role "Support" is our label (nanoka has no role field). Scales on **Max HP**.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1203 | 602 | 485 | 95 | 100 | 140 |

Minor traces (total): **SPD +14 · HP +18% · CRIT Rate +6.7%**

Memosprite "Summer Songbirds" (Bessie / Drummie / Paddie): Max HP = 70% of Robin's Max HP, SPD = 180% of Robin's SPD, Taunt 100.

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | The Sea Sings in My Key | Single | ST 10 | +1 | 20 | 50% Max HP |
| Skill | Summer Strums the Soul | Summon | — | −1 | 30 | Summon Songbird Bessie · if any Songbird is already out: heal them 100% of their Max HP and +6 Vibes |
| Ultimate | Ascend That Rhapsody in Blue | Support | — | — | 5 | 1 ally (not Robin): advance 100% · fixed Energy = 20% of their Max Energy · "Special Guest" 2 turns |
| Talent | Wings Heed No Borders | Enhance | — | — | — | Vibes (cap 50) · 6 / 12 Vibes → Drummie / Paddie · all 3 out → "Fever" + Zone: allies ignore (15% + Vibes × 0.5%) DEF |
| Technique | We Are the Melody | Enhance | — | — | — | Next battle: advance 20% · +6 Vibes · all allies DMG +30% for 2 turns |
| Memosprite Skill | Chirrup Quartet | AoE | AoE 10 | — | 20 | 150% of Songbirds' Max HP to all enemies |
| Memosprite Talent | A Warble of Wings | Support | — | — | — | Fever: Robin + Songbirds DMG +(60% + Vibes × 2%) · countdown SPD 140 drains Vibes · enemies DMG taken +8 / 12 / 16% by member count |
| Memosprite Talent | Near the Sea's Heartbeat | Support | — | — | — | Songbirds summoned → Robin +20 Energy |
| Memosprite Talent | Astride Summer's Nightwind | Support | — | — | — | Songbirds disappear → Robin advance 50% |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Vibes** — Robin gains 1 Vibes whenever an ally attacks, and the first time an ally heals or shields during any unit's turn. Cap 50 (E2: 70). Other sources: Skill +6 (if a Songbird is out), Special Guest +2 per attack, Technique +6, E4 +12 on entering Fever.
- **Summoning the band** — Skill summons Bessie. While Bessie is on the field, reaching 6 Vibes immediately summons Drummie and 12 Vibes summons Paddie.
- **Fever** — starts when all 3 Songbirds are on stage. It dispels Crowd Control debuffs on Robin and the Songbirds and deploys a Zone where every ally's DMG ignores (15% + Vibes × 0.5%) of enemy DEF. During Fever, Robin and the Songbirds are CC-immune, and **Robin gets no turns until Fever ends**. The Songbirds and a countdown appear on the Action Order. The Songbirds use the Memosprite Skill on each of their turns, and Robin + Songbirds deal +(60% + Vibes × 2%) DMG.
- **Countdown** — initial SPD 140. On each countdown turn, Vibes loses 50% of its current value (at least 12). When Vibes hits 0, the Songbirds disappear and Fever ends; Robin is then advanced 50%.
- **Enemy vulnerability** — while any Songbirds are on the field, all enemies take +8% / +12% / +16% DMG for 1 / 2 / 3 members present.
- **Special Guest (Ult)** — lasts 2 turns and ticks down at the start of **Robin's** turn. When the Guest or their summon attacks, Robin gains 2 Vibes, but the Guest cannot give action advance to other allies.

## Level tables

Basic ATK — The Sea Sings in My Key (Max HP%)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Max HP% | 25 | 30 | 35 | 40 | 45 | **50** | 55 | 60 | 65 | 70 |

Skill — Summer Strums the Soul (constant: +6 Vibes)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Songbird heal (% of their Max HP) | 50 | 55 | 60 | 65 | 70 | 75 | 81.25 | 87.5 | 93.75 | **100** | 105 | 110 | 115 | 120 | 125 |

Ultimate — Ascend That Rhapsody in Blue (constant: advance 100% · +2 Vibes per Guest attack · 2 turns)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Energy (% of target's Max) | 12 | 12.8 | 13.6 | 14.4 | 15.2 | 16 | 17 | 18 | 19 | **20** | 20.8 | 21.6 | 22.4 | 23.2 | 24 |

Talent — Wings Heed No Borders (constant: Songbird HP 70% · SPD 180% · Vibes cap 50 · 6 / 12 thresholds · +0.5% DEF ignore per Vibes)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| DEF ignore base % | 10 | 10.5 | 11 | 11.5 | 12 | 12.5 | 13.125 | 13.75 | 14.375 | **15** | 15.5 | 16 | 16.5 | 17 | 17.5 |

Memosprite Skill — Chirrup Quartet (% of Songbirds' Max HP)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| AoE Max HP% | 75 | 90 | 105 | 120 | 135 | **150** | 165 | 180 | 195 | 210 |

Memosprite Talent — A Warble of Wings (constant: countdown SPD 140 · −50% Vibes per countdown turn, min 12)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Fever DMG base % | 30 | 36 | 42 | 48 | 54 | **60** | 66 | 72 | 78 | 84 |
| Fever DMG per Vibes % | 1 | 1.2 | 1.4 | 1.6 | 1.8 | **2** | 2.2 | 2.4 | 2.6 | 2.8 |
| Enemy DMG taken, 1 member % | 4 | 4.8 | 5.6 | 6.4 | 7.2 | **8** | 8.8 | 9.6 | 10.4 | 11.2 |
| Enemy DMG taken, 2 members % | 6 | 7.2 | 8.4 | 9.6 | 10.8 | **12** | 13.2 | 14.4 | 15.6 | 16.8 |
| Enemy DMG taken, 3 members % | 8 | 9.6 | 11.2 | 12.8 | 14.4 | **16** | 17.6 | 19.2 | 20.8 | 22.4 |

Near the Sea's Heartbeat: +20 Energy at every level. Astride Summer's Nightwind: advance 50% at every level.

Technique: fixed advance 20% · +6 Vibes · DMG +30% for 2 turns.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Deviated Chords | When an ally makes Robin gain Vibes: if their ATK is higher than Robin's → ATK + (16% + Vibes × 0.4%) of Robin's Max HP; otherwise → CRIT DMG + (40% + Vibes × 1.5%). 2 turns |
| A4 | Improvised Blues | When Robin or the Songbirds are healed or shielded by a teammate → Robin gets 12 "Groove" (cap 12). The first Vibes gain in any unit's turn spends 1 Groove (if any) → fixed +3 Energy |
| A6 | Rebuilt Harmony | CRIT Rate +50% for Robin and the Songbirds |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Stray Bird of Summer | The Songbirds tally 100% of allies' non-True DMG. Memosprite Skill additionally deals True DMG = (11% + Vibes × 0.1%) of the tally to the highest-HP enemy, then clears 50% of the tally |
| 2 | A Heart of Still Water | All allies All-Type RES PEN +18%. Vibes cap +20. The first time per turn an ally's ability gives Robin Vibes → +2 more |
| 3 | Echoes Left Along the Way | Skill +2 (max 15) · Talent +2 (max 15) · Memosprite Talent +1 (max 10) |
| 4 | Her Variation on the Theme | On entering Fever → +12 Vibes, and Songbirds SPD + (20% + Vibes × 0.5%) |
| 5 | To Chase the Dawn Anew | Ult +2 (max 15) · Basic ATK +1 (max 10) · Memosprite Skill +1 (max 10) |
| 6 | A Song Yet Unnamed | Memosprite Skill multiplier +100% of original. During Fever, Ult can be stored up to 2 times. First Fever entry each battle, and each countdown turn start → fixed 140 Energy |

## Recommended (nanoka)

- LC: Rise and Sing · To Evernight's Stars · Memory's Curtain Never Falls
- Relics: World-Remaking Deliverer / Sacerdos' Relived Ordeal / Messenger Traversing Hackerspace (4) · Amphoreus, The Eternal Land / Sprightly Vonwacq / Lushaka, the Sunken Seas (2)
- Main stats: Body HP% · Feet SPD · Sphere HP% · Rope Energy Regen — substats CRIT Rate / CRIT DMG / HP% / SPD
