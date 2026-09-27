---
schema_version: "1.0.0"
unit_id: 1502
name: "Yao Guang"
slug: "yao-guang"
rarity: 5
element: "Physical"
path: "Elation"
role: "Support"
affiliation: null
released: true
source_url: "https://hsr.nanoka.cc/character/1502/"
source_game_version: "4.5.54"
dataset_snapshot: "2026-09-28"
overrides: "prydwen record (2026-05-30) — replaced by nanoka.cc data"
---

# Yao Guang

> Source: hsr.nanoka.cc (game data 4.5.54). Mechanics below are paraphrased, not the in-game prose.
> Values are shown at the sim's convention: **5★ = Basic Lv.6, Skill/Ult/Talent/Elation Skill Lv.10**.
> Code: `src/Defination/Data/Character/Elation/YaoGuang.h`.

## Base stats (Lv.80)

| HP | ATK | DEF | SPD | Taunt | Max Energy |
|---:|---:|---:|---:|---:|---:|
| 1242 | 466 | 655 | 101 | 100 | 180 |

Minor traces (total): **SPD +9 · CRIT Rate +18.7% · Elation +10%**

## Abilities

| Slot | Name | Tag | Toughness | SP | Energy | Key values (sim level) |
|---|---|---|---|---|---|---|
| Basic | Whistlebolt Sings Joy | Blast | ST 10 / adj 5 | +1 | 30 | 90% ATK main · 30% ATK adjacent |
| Skill | Decalight Unveils All | Support | — | −1 | 30 | Zone 3 turns · all allies Elation + 20% of Yao Guang's Elation · +3 Punchline after her Basic/Skill |
| Ultimate | Hexagram of Feathered Fortune | Support | — | — | 5 | +5 Punchline · Aha gets 1 extra turn counting a fixed 20 Punchline (no Punchline spent) · all allies All-Type RES PEN +20% for 3 turns |
| Talent | Behold Wherever Light Unfolds | Support | — | — | — | While holding Certified Banger: "Great Boon" 20% Elation follow-up after each ally attack (+1 more if it spent SP) |
| Technique | Untethered Glimmer Sails Far | Support | — | — | — | Next battle start: auto-cast Skill once, no SP cost |
| Elation Skill | Let Thy Fortune Burst in Flames | AoE | ST 5 / AoE 20 | — | 5 | Woe's Whisper (+16% DMG taken, 3 turns) · 100% Elation AoE · 5 × 20% Elation bounces |

Toughness uses the game's raw stance ÷ 3 (raw 30 = 10 toughness), same as the Silver Wolf doc.

### Mechanics (paraphrased)

- **Zone (Skill)** — lasts 3 turns and loses 1 at the start of each of Yao Guang's turns. While it is up, every ally gains Elation equal to 20% of Yao Guang's Elation. Whenever Yao Guang uses Basic ATK or Skill, she gains 3 Punchline (Zone or not).
- **Ultimate → Aha extra turn** — Aha immediately gets 1 extra turn. That Aha Instant counts a fixed 20 Punchline and does not spend team Punchline. The RES PEN buff is +20% All-Type for 3 turns on all allies.
- **Great Boon (Talent)** — while Yao Guang holds Certified Banger, after any ally attacks, 1 extra hit of 20% Elation DMG (in the attacker's element) lands on 1 random enemy that was hit. If that attack consumed SP, Great Boon triggers 1 more time. If the attacker's Elation is lower than Yao Guang's, the hit uses Yao Guang's Elation. Great Boon does not count as an attack.
- **Woe's Whisper** — the Elation Skill debuffs all enemies: DMG taken +16% for 3 turns.

## Level tables

Basic ATK — Whistlebolt Sings Joy (constant: Energy 30)

| Lv | 1 | 2 | 3 | 4 | 5 | **6** | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Main ATK% | 45 | 54 | 63 | 72 | 81 | **90** | 99 | 108 | 117 | 126 |
| Adjacent ATK% | 15 | 18 | 21 | 24 | 27 | **30** | 33 | 36 | 39 | 42 |

Skill — Decalight Unveils All (constant: Zone 3 turns · +3 Punchline)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Elation share % | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |

Ultimate — Hexagram of Feathered Fortune (constant: +5 Punchline · fixed 20 Punchline · 3 turns)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| All-Type RES PEN % | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |

Talent — Behold Wherever Light Unfolds

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Great Boon Elation% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |

Elation Skill — Let Thy Fortune Burst in Flames (constant: Woe's Whisper +16% · 3 turns · 5 bounces)

| Lv | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | **10** | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| AoE Elation% | 50 | 55 | 60 | 65 | 70 | 75 | 81.25 | 87.5 | 93.75 | **100** | 105 | 110 | 115 | 120 | 125 |
| Per bounce Elation% | 10 | 11 | 12 | 13 | 14 | 15 | 16.25 | 17.5 | 18.75 | **20** | 21 | 22 | 23 | 24 | 25 |

## Major traces

| | Name | Effect |
|---|---|---|
| A2 | Amaze-In Grace | SPD ≥ 120 → Elation +30%, then +1% per SPD above 120 (max 200 excess SPD) |
| A4 | Poised and Sated | CRIT DMG +60%. After using Elation Skill → team +1 SP |
| A6 | Felicity Ensemble | When she gains Certified Banger, its duration +1 turn |

## Eidolons

| E | Name | Effect |
|---|---|---|
| 1 | Chuckle Chimes Where Jade Falls | The Ult's Aha extra turn counts a fixed 40 Punchline instead of 20. All allies' Elation DMG ignores 20% DEF |
| 2 | Blind Arrows Guided by Feathers | While the Zone is up: all allies SPD +12% and Elation +16% |
| 3 | Auspices Mirrored In Decalight | Skill +2 (max 15) · Basic ATK +1 (max 10) · Elation Skill +1 (max 15) |
| 4 | Threads of Fate Colored by Plumes | In the Aha extra turn from her Ult, all allies' Elation Skill DMG becomes 150% of the original |
| 5 | Bejeweled in Radiant Grace | Ult +2 (max 15) · Talent +2 (max 15) · Elation Skill +1 (max 15) |
| 6 | Ferried Along the Astral Arc | All allies' Elation DMG merrymake +25%. Her Elation Skill multiplier +100% of the original |

## Recommended (nanoka)

- LC: When She Decided to See · Mushy Shroomy's Adventures
- Relics: Diviner of Distant Reach / Messenger Traversing Hackerspace (4) · Lushaka, the Sunken Seas / Sprightly Vonwacq / Broken Keel (2)
- Main stats: Body CRIT DMG · Feet SPD · Sphere HP% · Rope Energy Regen — substats SPD / CRIT DMG / CRIT Rate

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)

ส่วนนี้ยกมาจากไฟล์เดิม (prydwen, patch 4.0) ค่าตัวเลขที่อ้างถึงตรงกับข้อมูล nanoka 4.5.54 ด้านบน

- **การแชร์ Elation** — ขณะมี Zone เพื่อนทุกคนได้ Elation เพิ่ม 20% ของ Elation ของ Yao Guang (E2 ให้ Elation +16% เพิ่มอีก) ส่วน "Great Boon" จะใช้ Elation ของใครก็ได้ที่สูงกว่าในการคำนวณ
- **A2** — Elation สเกลกับ SPD (SPD ≥120 ได้ +30% แล้ว +1% ต่อ SPD ที่เกิน นับได้สูงสุด 200)
- **Punchline** — ใช้ Basic/Skill ได้ +3, Ult ได้ +5; เทิร์นพิเศษของ Aha นับ Punchline คงที่ 20 (E1 = 40)
- **Great Boon** — ตีเพิ่ม 20% Elation DMG ทุกครั้งที่เพื่อนโจมตี และตีซ้ำอีกครั้งถ้าการโจมตีนั้นใช้ SP เชื่อมกับ `whenAttackList` / `afterAhaInstantList` ในโค้ด
- โค้ดใน `startGameList`: ถ้ามี `Technique` จะสร้าง AllyBuffAction "YG Skill" (genPunchLine 3, energy 30, buff E2 SPD 12 / Elation 16, buff Elation คำนวณด้วย `calculateElationForBuff`) แล้ว `addToActionBar` + `dealDamage()` (flush เอง)
- Elation Skill: ติด Woe's Whisper (+16% vul) และ A4 คืน SP 1
