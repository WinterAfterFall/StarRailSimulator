---
schema_version: "1.0.0"
unit_id: 6
name: "Welt"
slug: "welt"
rarity: 5
element: "Imaginary"
path: "Nihility"
role: "Sub DPS"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/welt"
source_record_updated_at: "April 21st, 2026"
dataset_snapshot: "2026-05-30"
---

# Welt

## Character record

```json
{
  "unit_id": 6,
  "name": "Welt",
  "slug": "welt",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 153.12,
    "def_base": 69.3,
    "atk_base": 84.48,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "imaginaryDmg",
      "value": 14.4
    },
    "traceStat2": {
      "stat": "Effect Hit Rate",
      "value": 28
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Corey Landis",
    "kr": "한신",
    "jpn": "Hosoya Yoshimasa (細谷佳正)",
    "cn": "Bo Peng (彭博)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/welt",
  "source_record_updated_at": "April 21st, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100401` | Gravity Suppression | Basic ATK | Single Target |
| `skill` | `100402` | Edge of the Void | Skill | Bounce |
| `ult` | `100403` | Synthetic Black Hole | Ultimate | AoE |
| `talent` | `100404` | Time Distortion | Talent | Enhance |
| `technique` | `100407` | Gravitational Imprisonment | Technique | Impair |

## Ability records

### Gravity Suppression

```json
{
  "ability_id": "100401",
  "slot": "basic",
  "name": "Gravity Suppression",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
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
  "description_sha256": "85a44e919429ab5fa164582d339c7f6d2d9c2fc3de56caf8dbe9344c444712fb",
  "icon_path": null
}
```

### Edge of the Void

```json
{
  "ability_id": "100402",
  "slot": "skill",
  "name": "Edge of the Void",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Imaginary",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
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
        },
        "p2": {
          "value": 66,
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
        },
        "p2": {
          "value": 67,
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
        },
        "p2": {
          "value": 68,
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
        },
        "p2": {
          "value": 69,
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
        },
        "p2": {
          "value": 70,
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
        },
        "p2": {
          "value": 71.25,
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
        },
        "p2": {
          "value": 72.5,
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
        },
        "p2": {
          "value": 73.75,
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
        },
        "p2": {
          "value": 75,
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
        },
        "p2": {
          "value": 76,
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
        },
        "p2": {
          "value": 77,
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
        },
        "p2": {
          "value": 78,
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
        },
        "p2": {
          "value": 79,
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
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "cce9ca92e1fdf5b58fc1fd0ad8ebc0792c27922b1b2c3dd7b8351bf3fac7d13f",
  "icon_path": null
}
```

### Synthetic Black Hole

```json
{
  "ability_id": "100403",
  "slot": "ult",
  "name": "Synthetic Black Hole",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
    "spd",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 6.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 102,
          "unit": "percent"
        },
        "p2": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 7.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 114,
          "unit": "percent"
        },
        "p2": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 127.5,
          "unit": "percent"
        },
        "p2": {
          "value": 9.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 135,
          "unit": "percent"
        },
        "p2": {
          "value": 10.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 142.5,
          "unit": "percent"
        },
        "p2": {
          "value": 11.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        },
        "p2": {
          "value": 12.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 162,
          "unit": "percent"
        },
        "p2": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "dafb662664a9db19f39d4c9ebb7d7f4cf8137024dab567860a90232022130aca",
  "icon_path": null
}
```

### Time Distortion

```json
{
  "ability_id": "100404",
  "slot": "talent",
  "name": "Time Distortion",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
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
    "atk",
    "def",
    "spd",
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
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 81.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 93.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fd0b53bf8ed245c1cbd8bf301c3132a3df053a280ae8379eb44899ef3b1820e1",
  "icon_path": null
}
```

### Gravitational Imprisonment

```json
{
  "ability_id": "100407",
  "slot": "technique",
  "name": "Gravitational Imprisonment",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "spd"
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
          "value": 0.2,
          "unit": "scalar"
        },
        "p3": {
          "value": 0.1,
          "unit": "scalar"
        },
        "p4": {
          "value": 15,
          "unit": "scalar"
        },
        "p5": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f8704b951762a8a13291bccfc050bfca3c7cc8daa2438da4f2dc468a3e82d98b",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Retribution",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "10%",
      "10",
      "2",
      "30"
    ],
    "description_sha256": "c75e07db285e842da46ebdaec2a8d025139919e8c3f01cb35b9aca5fa8b18248"
  },
  {
    "requirement": "A4",
    "name": "Judgment",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "80%",
      "120%"
    ],
    "description_sha256": "4f694f25ed9d26d59e7de43de4c6c3424cb48d73bc3c9fb55e260d412c54c7a6"
  },
  {
    "requirement": "A6",
    "name": "Punishment",
    "mechanic_tags": [
      "atk",
      "effect_hit_rate",
      "energy"
    ],
    "numeric_tokens": [
      "40%",
      "10%",
      "20%",
      "80%",
      "5"
    ],
    "description_sha256": "9920cba713733d7a3e3f0ce11eb9c02ca60f07ea5f670b22c10d3d3fb6b28f83"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Legacy of Honor ",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "40%"
    ],
    "description_sha256": "77cf737946ccd26e26211397662c74563972b225c0321a9afccc00029e67cc5d"
  },
  {
    "eidolon": 2,
    "name": "Conflux of Stars",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "3"
    ],
    "description_sha256": "808162445a9b606d3fd286d0005690a8eee40c375b9b6dc1550bd78b91fd04ac"
  },
  {
    "eidolon": 3,
    "name": "Prayer of Peace",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "dfc289407dbc553d0a60b619a82ff2cb35c322892c7f2b225426b96a861b9dfd"
  },
  {
    "eidolon": 4,
    "name": "Appellation of Justice ",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "d9cc49726431753198c66cde4f348133ac31ffa7eec83c102d7f7932e267bb9b"
  },
  {
    "eidolon": 5,
    "name": "Power of Kindness",
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
    "eidolon": 6,
    "name": "Prospect of Glory",
    "mechanic_tags": [
      "crit_rate",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "30%",
      "60%"
    ],
    "description_sha256": "00e094beb6853130a277456a217d848c07e08c524d874eb0e3e4b133734a56fe"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
