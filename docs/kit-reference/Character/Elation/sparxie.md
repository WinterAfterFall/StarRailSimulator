---
schema_version: "1.0.0"
unit_id: 1501
name: "Sparxie"
slug: "sparxie"
rarity: 5
element: "Fire"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1501/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen record (2026-05-30) — replaced by nanoka.cc data"
---

# Sparxie

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Code: `src/Defination/Data/Character/Elation/Hibana.h` (namespace `Hibana` — codename ≠ in-game name).

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1048 | 640 | 461 | 107 | 100 | 160 |

Minor traces (total): **Elation +28% · CRIT Rate +12% · CRIT DMG +13.3%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Cat Got Your Flametongue? | Single | ST 10 | +1 | 20 | 100% ATK |
| Basic (Enh.) | Bloom! Winner Takes All | Blast | ST 10 / adj 5 | +1 | 40 | Ends the livestream · 100% ATK main · 50% ATK adjacent (+ Engagement Farming bonuses) |
| Skill | Boom! Sparxicle's Poppin' | Enhance | — | −1 | — | Starts livestream: Basic → Enhanced Basic, triggers Engagement Farming ×1; repeatable up to 20× · not counted as using a Skill |
| Skill (Enh.) | Engagement Farming | Enhance | — | −1 | — | Enhanced Basic multiplier +20% main / +10% adjacent · random gift: Straight Fire (+2 Punchline, +2 SP) or Unreal Banger (+1 Punchline) · not counted as using a Skill |
| Ultimate | Party's Wildin' and Camera's Rollin' | AoE | AoE 20 | — | 5 | +2 Punchline · (0.6 × Elation + 50%) ATK to all enemies |
| Talent | Sleight of Sparx Hand | Enhance | ST 5 | — | — | While holding Certified Banger: Enh. Basic +40% / 20% Elation (main / adj) + 20% per Engagement Farming · Ult +48% Elation AoE |
| Technique | Content Monetization | Impair | — | — | — | Block 10s · on engage: 50% ATK AoE + 2 SP |
| Elation Skill | Signal Overflow: The Great Encore! | AoE | ST 1.67 / AoE 6.67 | — | 5 | 50% Elation AoE + 20 × 25% Elation bounces · +2 Thrill |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Livestream** — Skill switches Basic ATK to "Bloom! Winner Takes All" and triggers Engagement Farming once. While the livestream is open, Engagement Farming (the Enhanced Skill, costs SP) can be triggered again, up to 20 times total. Using the Enhanced Basic ATK ends the livestream. Neither the Skill nor Engagement Farming counts as "using a Skill".
- **Engagement Farming stacking** — each trigger adds +20% (main) / +10% (adjacent) ATK to the Enhanced Basic's multiplier, and gives one random gift: **Straight Fire** = +2 Punchline and +2 SP, or **Unreal Banger** = +1 Punchline. The Skill's level table also carries constants 28 / 3 / 7 / 4 that the text does not explain (probably the gift weights).
- **Certified Banger bonus (Talent)** — while holding Certified Banger: Enhanced Basic adds 40% Fire Elation DMG to the main target and 20% to adjacent ones, plus one extra 20% Elation hit on a random hit enemy per Engagement Farming triggered; Ultimate adds 48% Fire Elation DMG to all enemies.
- **Thrill** — the Elation Skill gives Sparxie +2 Thrill. Thrill pays for Sparxie's own SP costs instead of team SP, and spending Thrill **counts as consuming SP**.
- **Ultimate scaling** — the Ultimate's ability DMG scales with Elation: multiplier = 0.6 × Elation + 50% ATK.

## Level tables

Basic ATK — Cat Got Your Flametongue?

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |

Enhanced Basic — Bloom! Winner Takes All

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Main ATK% | 50 | 60 | 70 | 80 | 90 | **100** | 110 | 120 | 130 | 140 |
| Adjacent ATK% | 25 | 30 | 35 | 40 | 45 | **50** | 55 | 60 | 65 | 70 |

Skill — Boom! Sparxicle's Poppin': max 20 Engagement Farming triggers at every level.

Enhanced Skill — Engagement Farming (constant: Straight Fire +2 PL +2 SP · Unreal Banger +1 PL)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Main +ATK% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |
| Adjacent +ATK% | 5 | 5.5 | 6 | 6.5 | 7 | 7.5 | 8.125 | 8.75 | 9.375 | **10** | 10.5 | 11 | 11.5 | 12 | 12.5 |

Ultimate — Party's Wildin' and Camera's Rollin' (constant: +2 Punchline · Elation coefficient 0.6)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Base ATK% | 30 | 32 | 34 | 36 | 38 | 40 | 42.5 | 45 | 47.5 | **50** | 52 | 54 | 56 | 58 | 60 |

Talent — Sleight of Sparx Hand

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Enh. Basic main Elation% | 20 | 22 | 24 | 26 | 28 | 30 | 32.5 | 35 | 37.5 | **40** | 42 | 44 | 46 | 48 | 50 |
| Enh. Basic adjacent Elation% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |
| Per Engagement Farming Elation% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |
| Ult Elation% | 24 | 26.4 | 28.8 | 31.2 | 33.6 | 36 | 39 | 42 | 45 | **48** | 50.4 | 52.8 | 55.2 | 57.6 | 60 |

Elation Skill — Signal Overflow: The Great Encore! (constant: 20 bounces · +2 Thrill)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE Elation% | 25 | 27.5 | 30 | 32.5 | 35 | 37.5 | 40.625 | 43.75 | 46.875 | **50** | 52.5 | 55 | 57.5 | 60 | 62.5 |
| Per bounce Elation% | 12.5 | 13.75 | 15 | 16.25 | 17.5 | 18.75 | 20.3125 | 21.875 | 23.4375 | **25** | 26.25 | 27.5 | 28.75 | 30 | 31.25 |

Technique: fixed 50% ATK AoE + 2 SP.

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Sweet! Punchline Signing | Every 100 ATK above 2000 → Elation +5%, max +80% |
| A4 | Dazzling! Persona Kaleidoscope | With 1 / 2 / ≥3 Elation characters on the team, Ultimate additionally gives 2 / 4 / 8 Punchline and 1 / 1 / 4 Thrill |
| A6 | Frenzy! Palette of Truth and Lies | Each 1 Punchline currently held → all allies CRIT DMG +8%, max +80% |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | #GoingViral #WhoIsShe | When Aha Instant ends → +5 Punchline. Each 1 Punchline held → all allies All-Type RES PEN +1.5%, max +15% |
| 2 | #AudienceKnows | When Aha Instant ends → Sparxie gets 1 extra turn and +2 Thrill. Each Thrill consumed → her CRIT DMG +10% for 2 turns, stacks 4× |
| 3 | #LinkUp #HeartSkip | Skill +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 4 | #LockedIn #FaceCard | Using Ultimate → +5 Punchline and her Elation +36% for 3 turns |
| 5 | #HealingTheWorld #GoodVibesOnly | Ult +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 6 | #BuiltDifferent #GoingExtinct | All-Type RES PEN +20%. Each 1 Punchline counted → +1 extra Elation Skill bounce, max 40 |

## Recommended (nanoka)

- LC: Dazzled by a Flowery World · Today's Good Luck
- Relics: Ever-Glorious Magical Girl / Wavestrider Captain (4) · Tengoku@Livestream / The Wondrous BananAmusement Park / Rutilant Arena (2)
- Main stats: Body CRIT Rate · Feet ATK% · Sphere ATK% · Rope ATK% — substats CRIT Rate / CRIT DMG / ATK%

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)

ส่วนนี้ยกมาจากไฟล์เดิม (prydwen, patch 4.0) ค่าตัวเลขที่อ้างถึงตรงกับข้อมูล nanoka 4.5.54 ด้านบน

- **ระบบ Elation (Aha Instant)** — ในโค้ดมี `elationCount`, `genPunchLine`, `afterAhaInstantList` ฯลฯ
- **Punchline** (สะสมได้) — ได้จาก Engagement Farming, Ult (+2), A4, E1/E4 แล้วไปป้อน A6 (CRIT DMG ทั้งทีม), E1 (RES PEN) และ E6 (จำนวนครั้งที่ Elation Skill ตีเพิ่ม)
- **Thrill** — ได้จาก Elation Skill (+2), A4 และ E2 ใช้จ่ายแทน Skill Point ของ Sparxie เอง และการใช้ Thrill นับว่าเป็นการใช้ Skill Point
- **Elation stat** — ความเสียหายของ Ult สเกลกับ Elation (`0.6×Elation + 0.5`) ส่วน A2 แปลง ATK ส่วนที่เกิน 2000 เป็น Elation
- **livestream / Skill** ไม่นับว่าเป็น "การใช้ Skill" (สำคัญกับ trigger อื่นที่นับการใช้ Skill)
- **Engagement Farming** ใช้ได้สูงสุด 20 ครั้งต่อหนึ่ง livestream สุ่มได้ 2 แบบ
- ในโค้ดมี `setAtkRequire(3600)` คือ ATK เป้าหมายของ build
