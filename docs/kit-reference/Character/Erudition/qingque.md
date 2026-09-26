---
schema_version: "1.0.0"
unit_id: 26
name: "Qingque"
slug: "qingque"
rarity: 4
element: "Quantum"
path: "Erudition"
role: "Sub DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/qingque"
source_record_updated_at: "January 25th, 2025"
dataset_snapshot: "2026-05-30"
---

# Qingque

## Character record

```json
{
  "unit_id": 26,
  "name": "Qingque",
  "slug": "qingque",
  "rarity": "4",
  "element": "Quantum",
  "path": "Erudition",
  "default_role": "Sub DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 139.2,
    "def_base": 60,
    "atk_base": 88.8,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "quantumDmg",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Bryn Appril",
    "kr": "",
    "jpn": "Arisa Date (伊達 朱里紗)",
    "cn": "Liu Shisi (刘十四)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/qingque",
  "source_record_updated_at": "January 25th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120101` | Flower Pick | Basic ATK | Single Target |
| `basic_enh` | `120108` | Cherry on Top! | Basic ATK | Blast |
| `skill` | `120102` | A Scoop of Moon | Skill | Enhance |
| `ult` | `120103` | A Quartet? Woo-hoo! | Ultimate | AoE |
| `talent` | `120104` | Celestial Jade | Talent | Enhance |
| `technique` | `120107` | Game Solitaire | Technique | Enhance |

## Ability records

### Flower Pick

```json
{
  "ability_id": "120101",
  "slot": "basic",
  "name": "Flower Pick",
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
  "description_sha256": "b544fc0608996170280bd287bf1498c16d3bb849d90fa2f1c342636211480e7f",
  "icon_path": "icon/skill/1201_basic_atk.png"
}
```

### Cherry on Top!

```json
{
  "ability_id": "120108",
  "slot": "basic_enh",
  "name": "Cherry on Top!",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
  "source_max_level": 9,
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
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 312,
          "unit": "percent"
        },
        "p2": {
          "value": 130,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "811d2f234f8997ff14e5dc0f362d19c3d0eedb839dfb5744b79a660c33a80337",
  "icon_path": "icon/skill/1201_basic_atk.png"
}
```

### A Scoop of Moon

```json
{
  "ability_id": "120102",
  "slot": "skill",
  "name": "A Scoop of Moon",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 15.4,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 18.2,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 19.6,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 22.75,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 24.5,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 29.4,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 30.8,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 32.2,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 33.6,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 4,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "85e6a322dc1f278efd20e47006f9b020c1ff79680f7d1ebc589404d6a1a83680",
  "icon_path": "icon/skill/1201_skill.png"
}
```

### A Quartet? Woo-hoo!

```json
{
  "ability_id": "120103",
  "slot": "ult",
  "name": "A Quartet? Woo-hoo!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
  "toughness_break_primary_source": "60",
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
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 170,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 190,
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
          "value": 208,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 224,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 232,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d93841e1c61dd0c5015815049534bfeaa769c5493ab62765f0731568a2b6129b",
  "icon_path": "icon/skill/1201_ultimate.png"
}
```

### Celestial Jade

```json
{
  "ability_id": "120104",
  "slot": "talent",
  "name": "Celestial Jade",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 46.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 75.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 79.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 82.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "34003e43025c51fd30f0157da6c5ffeb3edabe988a13b0bc2b411d5c73f7bbbf",
  "icon_path": "icon/skill/1201_talent.png"
}
```

### Game Solitaire

```json
{
  "ability_id": "120107",
  "slot": "technique",
  "name": "Game Solitaire",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "4d3fa235a8cb5b719bcbb58424b47f3adf91fee5517dd4eb2e7f772a7f5ecda1",
  "icon_path": "icon/skill/1201_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Tile Battle",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "1"
    ],
    "description_sha256": "5dac18ef49940bb8619796606ef650156162ed910a3a02d82196188558aea27c"
  },
  {
    "requirement": "A4",
    "name": "Bide Time",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "811aa0ed9152797b8a79dafe01005b3a3faa43d182e98cf834efb33c8fbe3ca0"
  },
  {
    "requirement": "A6",
    "name": "Winning Hand",
    "mechanic_tags": [
      "atk",
      "spd"
    ],
    "numeric_tokens": [
      "10%",
      "1"
    ],
    "description_sha256": "a46751fab5458bfbf86c03610cfaf663723c45b25334ff017f04c56c72c8aeb2"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Rise Through the Tiles",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "68a1e0b06328f2fe744d983708a9a3970ee2ae2049f5bcd605e18b7d2413950d"
  },
  {
    "eidolon": 2,
    "name": "Sleep on the Tiles",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "bc685546e0d85d50520f7baaa27618d13dc520b2f32a5d68fc4c328e6a2bcac9"
  },
  {
    "eidolon": 3,
    "name": "Read Between the Tiles",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "6bc2a8667c00f65b21b46157e747c2499d1f3e80d0cca4572d8a1b39e557d8c1"
  },
  {
    "eidolon": 4,
    "name": "Right on the Tiles",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "24%",
      "1",
      "100%"
    ],
    "description_sha256": "3a1a325de2a5739be9f946d136f145279a00702893c705acb1894abce4365364"
  },
  {
    "eidolon": 5,
    "name": "Gambit for the Tiles",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "311d42dde2d7bf6c4a627823a42a2c5441ae282e5abb36042eba435acdec6ef8"
  },
  {
    "eidolon": 6,
    "name": "Prevail Beyond the Tiles",
    "mechanic_tags": [
      "atk",
      "skill_points"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "fd68010dd384dd658eb9441f226edb5f3084e91cbf4fc6ea904eba249724a222"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
