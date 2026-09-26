---
schema_version: "1.0.0"
unit_id: 77
name: "Archer"
slug: "archer"
rarity: 5
element: "Quantum"
path: "Hunt"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/archer"
source_record_updated_at: "August 11th, 2025"
dataset_snapshot: "2026-05-30"
---

# Archer

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/The Hunt/Archer.h` |
| ธาตุ | **Quantum** |
| Path | **The Hunt** |
| ระดับ | 5★ (collab) |
| Energy Ultimate | 220 |
| อ้างอิง | prydwen.gg (review patch 3.4 / calc patch 4.4) |

### Base Stats (Lv.80, ascended)
HP 1164 · ATK 620 · DEF 485 · SPD 105

> The Hunt single-target DPS สาย Skill-spam ("Circuit Connection") + Skill Point economy + "Charge" FUA

---

### Basic ATK — Kanshou and Bakuya (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Caladbolg II: Fake Spiral Sword (โจมตีเดี่ยว, Lv.10)
- เข้าสถานะ **"Circuit Connection"**
- Quantum DMG = **360% ATK** ใส่เป้าหมาย
- ใช้ Skill ขณะอยู่ในสถานะ → **เทิร์นปัจจุบันไม่จบ** + Skill DMG **+100%** (stack 2 ครั้ง, อยู่จนออกจากสถานะ)
- ใช้ Skill ครบ **5 ครั้ง** หรือ Skill Point ไม่พอ → ใช้ Skill อีกครั้ง = ออกจากสถานะ
- ออกจากสถานะเมื่อฆ่าศัตรูหมดใน wave
- Energy +30 · Toughness 20

### Ultimate — Unlimited Blade Works (โจมตีเดี่ยว, 220 energy, Lv.10)
- Quantum DMG = **1000% ATK** ใส่เป้าหมาย + Charge **+2** (สูงสุด 4)
- Energy +5 · Toughness 30

### Talent — Mind's Eye (True) (Lv.10)
- เมื่อเพื่อนโจมตีศัตรู → Archer กิน **Charge 1** + ยิง Follow-up ATK ใส่เป้าหมายหลัก: Quantum DMG = **200% ATK** + คืน Skill Point **1**
- ถ้าเป้าตายก่อน → ยิงใส่ศัตรูสุ่ม
- Energy +5 · Toughness 10

### Technique — Clairvoyance
- เข้าฉากโจมตี: Quantum DMG = **200% ATK** AoE + Charge **+1**

---

### Major Traces
- **A2 — Projection Magecraft**: ขณะ Archer อยู่ในสนาม → Max Skill Point **+2**
- **A4 — Hero of Justice**: Archer เข้าฉาก → Charge **+1**
- **A6 — Guardian**: หลังเพื่อนได้ Skill Point ถ้ามี Skill Point ≥ 4 → Archer CRIT DMG **+120%** นาน 1 เทิร์น

### Minor Traces (รวมทั้งหมด)
Quantum DMG +22.4% · ATK +18% · CRIT Rate +6.7%

### Eidolons
- **E1 — The Unreached Dream**: ใช้ Skill 3 ครั้งในเทิร์นเดียว → คืน Skill Point **2** ให้ทีม
- **E2 — The Unfulfilled Happiness**: ใช้ Ult → ลด Quantum RES เป้าหมาย **20%** + induce Quantum Weakness นาน 2 เทิร์น
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4 — The Unsung Life**: Ultimate DMG **+150%**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6 — The Endless Pilgrimage**: ต้นเทิร์น → คืน Skill Point **1** ให้ทีม. Skill DMG boost stack cap **+1** (รวม 3). Skill DMG เพิกเฉย DEF **20%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Circuit Connection**: Skill 360% ATK; ใช้ในสถานะ = เทิร์นไม่จบ (spam ได้) + Skill DMG +100%/stack (cap 2, E6 3); ออกเมื่อ Skill 5 ครั้ง / SP หมด / wave clear
- **Skill Point economy** = แกน: A2 Max SP +2, Talent FUA คืน 1, E1 (3 skills/turn → +2), E6 (+1/turn), A6 (CD +120% ถ้า SP ≥ 4)
- **Charge** (0–4): Ult +2, Technique +1, A4 +1; Talent กิน 1 ต่อการโจมตีของเพื่อน → FUA 200% ATK
- **Ult 1000% ATK** single target (E4 +150%, E2 RES −20%)
- โค้ด: `Start_game_List` priority `PRIORITY_IMMEDIATELY` (`Archer.h:130`, `ac`, `Charge`) — `Charge(1)` + Technique attack + self-flush `Deal_damage()`
- **หมายเหตุ**: element/path ในโค้ด (Quantum/Hunt) ตรงกับเกมจริง

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/archer — kit tab (review patch 3.4, calc patch 4.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 77,
  "name": "Archer",
  "slug": "archer",
  "rarity": "5",
  "element": "Quantum",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "July 11th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "220",
  "base_stats": {
    "hp_base": 158.4,
    "def_base": 66,
    "atk_base": 84.48,
    "speed_base": 105
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Quantum DMG",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "CRIT Rate",
      "value": 6.7
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "",
    "jpn": "",
    "cn": ""
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/archer",
  "source_record_updated_at": "August 11th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `101501` | Kanshou and Bakuya | Basic ATK | Single Target |
| `skill` | `101502` | Caladbolg II: Fake Spiral Sword | Skill | Single Target |
| `ult` | `101503` | Unlimited Blade Works | Ultimate | Single Target |
| `talent` | `101504` | Mind's Eye (True) | Talent | Enhance |
| `technique` | `101507` | Clairvoyance | Technique | MazeAttack |

## Ability records

### Kanshou and Bakuya

```json
{
  "ability_id": "101501",
  "slot": "basic",
  "name": "Kanshou and Bakuya",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 9,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a40005571a215754ff031958d782ca7e7ef7983444ded341317a0076d699b428",
  "icon_path": null
}
```

### Caladbolg II: Fake Spiral Sword

```json
{
  "ability_id": "101502",
  "slot": "skill",
  "name": "Caladbolg II: Fake Spiral Sword",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Single Target",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 198,
          "unit": "percent"
        },
        "p2": {
          "value": 64,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 68,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 234,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 252,
          "unit": "percent"
        },
        "p2": {
          "value": 76,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 292.5,
          "unit": "percent"
        },
        "p2": {
          "value": 85,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 337.5,
          "unit": "percent"
        },
        "p2": {
          "value": 95,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 378,
          "unit": "percent"
        },
        "p2": {
          "value": 104,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 396,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c23c31025e86993aea77b0f460b8f493c0e6d49b06cea9ea3b09f034fb764be4",
  "icon_path": null
}
```

### Unlimited Blade Works

```json
{
  "ability_id": "101503",
  "slot": "ult",
  "name": "Unlimited Blade Works",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Single Target",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "220",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 600,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 640,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 680,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 720,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 760,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 800,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 850,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 900,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 950,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1000,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1040,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1080,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "dc3ed24f4007e0d3089b0f8e4e481de454e6c73e068381748da85a2a090e88d4",
  "icon_path": null
}
```

### Mind's Eye (True)

```json
{
  "ability_id": "101504",
  "slot": "talent",
  "name": "Mind's Eye (True)",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "follow_up",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 162.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fc893b8dbcaf7e851e59a0a7c10ce5ebd9ad4f183206e9b471325a014de4b472",
  "icon_path": null
}
```

### Clairvoyance

```json
{
  "ability_id": "101507",
  "slot": "technique",
  "name": "Clairvoyance",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8cbc3523a82c66b4ad2f681ae4c8e48cdc62f7f8e3de8b481da853516676c6ab",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Projection Magecraft",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "f196caaebe09085c646ace650a0ac7384b2bfc3e196257e10def80d0c13b0580"
  },
  {
    "requirement": "A4",
    "name": "Hero of Justice",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "c4a5c9d675c4cced43918885254e837d8dd3f20413ef1db7f5a0e91f18c00b15"
  },
  {
    "requirement": "A6",
    "name": "Guardian",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "skill_points"
    ],
    "numeric_tokens": [
      "4",
      "120%",
      "1"
    ],
    "description_sha256": "f7d3f8c056677b545b9f14a8724c23aef44134ec4dc7a83f1372eeed79b51658"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "The Unreached Dream",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "3",
      "2"
    ],
    "description_sha256": "3c6b5b99b6a0eab46619035d467052b450b28d52499b01da63e444bce10799ba"
  },
  {
    "eidolon": 2,
    "name": "The Unfulfilled Happiness",
    "mechanic_tags": [
      "res",
      "weakness"
    ],
    "numeric_tokens": [
      "20%",
      "2"
    ],
    "description_sha256": "239309f8cc772a8943a04b0d7442e7b3fa6017e0a0a2a0916783e07225d03d6f"
  },
  {
    "eidolon": 3,
    "name": "The Untamed Will",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "1db409cc64230c6d43effaf06e14357557fc834777bb0a6ecd7f7a41e74a4ec5"
  },
  {
    "eidolon": 4,
    "name": "The Unsung Life",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "150%"
    ],
    "description_sha256": "d3cf241e2c222ac06aa597295a8d8e3e52632d7c5a315637ea6234041f718902"
  },
  {
    "eidolon": 5,
    "name": "The Nameless Watch",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "2",
      "15"
    ],
    "description_sha256": "c69db63dc4ccfd8e2f5f7edcd607380a48587a0e5fd5f4cd7871a4e975585803"
  },
  {
    "eidolon": 6,
    "name": "The Endless Pilgrimage",
    "mechanic_tags": [
      "def",
      "dmg",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "1",
      "20%"
    ],
    "description_sha256": "3a3ceaec7cf7d577dee67fc69e21d08fd9acfa1f37320d2ead41ad11b69d9c91"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
