---
schema_version: "1.0.0"
unit_id: 9
name: "Arlan"
slug: "arlan"
rarity: 4
element: "Lightning"
path: "Destruction"
role: "Main DPS"
affiliation: "Herta Space Station"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/arlan"
source_record_updated_at: "February 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Arlan

## Character record

```json
{
  "unit_id": 9,
  "name": "Arlan",
  "slug": "arlan",
  "rarity": "4",
  "element": "Lightning",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Herta Space Station",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 163.2,
    "def_base": 45,
    "atk_base": 81.6,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "effectRes",
      "value": 18
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Dani Chambers",
    "kr": "김율",
    "jpn": "Shiraishi Ryoko (白石涼子)",
    "cn": "Dian Tao (陶典)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/arlan",
  "source_record_updated_at": "February 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100801` | Lightning Rush | Basic ATK | Single Target |
| `skill` | `100802` | Shackle Breaker | Skill | Single Target |
| `ult` | `100803` | Frenzied Punishment | Ultimate | Blast |
| `talent` | `100804` | Pain and Anger | Talent | Enhance |
| `technique` | `100807` | Swift Harvest | Technique | MazeAttack |

## Ability records

### Lightning Rush

```json
{
  "ability_id": "100801",
  "slot": "basic",
  "name": "Lightning Rush",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
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
  "description_sha256": "55d73ccaa98117c3d9b6c5fbbb5ab33b7c9f50c64f5aa14be2e8cd71c0b11d4c",
  "icon_path": "icon/skill/1008_basic_atk.png"
}
```

### Shackle Breaker

```json
{
  "ability_id": "100802",
  "slot": "skill",
  "name": "Shackle Breaker",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
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
    "max_hp",
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 156,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 168,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 195,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 210,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 225,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 252,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 264,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 276,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 288,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 300,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8f8a7214d02f3c74bc202fb39e03bc82e02dd02ebc1d9e4f900c2e17feb64107",
  "icon_path": "icon/skill/1008_skill.png"
}
```

### Frenzied Punishment

```json
{
  "ability_id": "100803",
  "slot": "ult",
  "name": "Frenzied Punishment",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Thunder",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "60",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 204.8,
          "unit": "percent"
        },
        "p2": {
          "value": 102.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 217.6,
          "unit": "percent"
        },
        "p2": {
          "value": 108.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 230.4,
          "unit": "percent"
        },
        "p2": {
          "value": 115.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 243.2,
          "unit": "percent"
        },
        "p2": {
          "value": 121.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 256,
          "unit": "percent"
        },
        "p2": {
          "value": 128,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 272,
          "unit": "percent"
        },
        "p2": {
          "value": 136,
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
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 152,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 320,
          "unit": "percent"
        },
        "p2": {
          "value": 160,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 332.8,
          "unit": "percent"
        },
        "p2": {
          "value": 166.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 345.6,
          "unit": "percent"
        },
        "p2": {
          "value": 172.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 358.4,
          "unit": "percent"
        },
        "p2": {
          "value": 179.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 371.2,
          "unit": "percent"
        },
        "p2": {
          "value": 185.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 384,
          "unit": "percent"
        },
        "p2": {
          "value": 192,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "763ae7dcab68cf1f25f773fb7f68b8c0799dee3ebf693da9cc3ae769b893b637",
  "icon_path": "icon/skill/1008_ultimate.png"
}
```

### Pain and Anger

```json
{
  "ability_id": "100804",
  "slot": "talent",
  "name": "Pain and Anger",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
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
    "max_hp",
    "dmg"
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
  "description_sha256": "2b38f47b9c0ed1534447b76522a6fa22c36a85263a5e3020ccff904af755bc45",
  "icon_path": "icon/skill/1008_talent.png"
}
```

### Swift Harvest

```json
{
  "ability_id": "100807",
  "slot": "technique",
  "name": "Swift Harvest",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Thunder",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
          "value": 80,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c8a10c308ca1d5fe5658c05446e7a34f070382ef4ea4ce450e56bd1a07619e14",
  "icon_path": "icon/skill/1008_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Revival",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "30%",
      "20%"
    ],
    "description_sha256": "94c023804e40bcb854308b9f4937a295bd378e61248f4985e75d3a587db4a41f"
  },
  {
    "requirement": "A4",
    "name": "Endurance",
    "mechanic_tags": [
      "dot",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "43ebb479e8739d310a9919001bac725b7183f6702df75f106fdf41c55f0a970b"
  },
  {
    "requirement": "A6",
    "name": "Repel",
    "mechanic_tags": [
      "max_hp",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "5573a234f2bb71624b924f261801aa6bda9dceab06d9a0f31e5f0ab634676986"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "To the Bitter End",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "50%",
      "10%"
    ],
    "description_sha256": "71e5f03c2c145a8b444ffc890dea2d5b97d6d1ce003de0c705ba19309a6f170d"
  },
  {
    "eidolon": 2,
    "name": "Breaking Free   ",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "5bc0dc8a1b88b50d58b993a5658c84efc17b714782484eb720eea52625922d9d"
  },
  {
    "eidolon": 3,
    "name": "Power Through ",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "cc0d6a12ef7b870ada3a8cc5bf409ac765e5cddc458782b0d4d944b156f24f67"
  },
  {
    "eidolon": 4,
    "name": "Turn the Tables     ",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "25%",
      "2"
    ],
    "description_sha256": "1f15bc79f71773b34d8b7f2f2c716814649fdfac2f8525645da20017688cac11"
  },
  {
    "eidolon": 5,
    "name": "Hammer and Tongs ",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a4417497ecb72e43d7a08beb9ea57ccb09e86b6838c1773e7e2ade42f7242276"
  },
  {
    "eidolon": 6,
    "name": "Self-Sacrifice",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "50%",
      "20%"
    ],
    "description_sha256": "85d4ef2f7fa2876264c7443e6dbc6ae40911f6f738813c7bd66d32abef2995ca"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
