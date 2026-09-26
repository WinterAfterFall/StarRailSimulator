---
schema_version: "1.0.0"
unit_id: 13
name: "Seele"
slug: "seele"
rarity: 5
element: "Quantum"
path: "Hunt"
role: "Main DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/seele"
source_record_updated_at: "April 21st, 2026"
dataset_snapshot: "2026-05-30"
---

# Seele

## Character record

```json
{
  "unit_id": 13,
  "name": "Seele",
  "slug": "seele",
  "rarity": "5",
  "element": "Quantum",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 126.72,
    "def_base": 49.5,
    "atk_base": 87.12,
    "speed_base": 115
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "critDmg",
      "value": 24
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Molly Zhang",
    "kr": "송하림",
    "jpn": "Nakahara Mai (中原麻衣)",
    "cn": "Yajing Tang (唐雅菁)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/seele",
  "source_record_updated_at": "April 21st, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110201` | Thwack | Basic ATK | Single Target |
| `skill` | `110202` | Sheathed Blade | Skill | Single Target |
| `ult` | `110203` | Butterfly Flurry | Ultimate | Single Target |
| `talent` | `110204` | Resurgence | Talent | Enhance |
| `technique` | `110207` | Phantom Illusion | Technique | Enhance |

## Ability records

### Thwack

```json
{
  "ability_id": "110201",
  "slot": "basic",
  "name": "Thwack",
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
  "description_sha256": "2bc6380e1e4b5fdf4b31b3faf263767bb4f2492f32039b91ecdddf0177d51c6b",
  "icon_path": null
}
```

### Sheathed Blade

```json
{
  "ability_id": "110202",
  "slot": "skill",
  "name": "Sheathed Blade",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "spd",
    "energy",
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
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 198,
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
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 234,
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
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 270,
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
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 315,
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
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 360,
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
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 396,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a25c9cc6f6ef0187b9e90517c6fbcb469b52fc3f33ea370c1a6ce6156f4324f4",
  "icon_path": null
}
```

### Butterfly Flurry

```json
{
  "ability_id": "110203",
  "slot": "ult",
  "name": "Butterfly Flurry",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
          "value": 360,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 396,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 432,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 468,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 504,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 540,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 585,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 630,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 675,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 720,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 756,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 792,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "de8885ca5aecd1e7ceaf96150bab9eda6a8e27a50d6acc290ad4db756be69d3b",
  "icon_path": null
}
```

### Resurgence

```json
{
  "ability_id": "110204",
  "slot": "talent",
  "name": "Resurgence",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 92,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "fc79fbad96e897d45a076581d5c5c870507d86dd210a534bcd9ff411be3b9568",
  "icon_path": null
}
```

### Phantom Illusion

```json
{
  "ability_id": "110207",
  "slot": "technique",
  "name": "Phantom Illusion",
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
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "01665c615a3311a26d4df8448284d24a651025b0720d8e76f5710bbf6941a33e",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Nightshade",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "50%",
      "3",
      "3"
    ],
    "description_sha256": "1866e48105ca2dacc584da96e6d866503dbc9bfaee7508a0c9bcb0c70509d429"
  },
  {
    "requirement": "A4",
    "name": "Lacerate",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "8e130d1801c9ca10b1bc9d4d5d6ed563dc035ac35db4700964e6db3c53ba2ba7"
  },
  {
    "requirement": "A6",
    "name": "Rippling Waves",
    "mechanic_tags": [
      "atk",
      "action_advance"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "1a2a858b9c45c4984ec19bc8be23b6cca94b5705f89df9fa7807f8fab0756260"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Extirpating Slash",
    "mechanic_tags": [
      "max_hp",
      "def",
      "crit_rate",
      "dmg"
    ],
    "numeric_tokens": [
      "80%",
      "15%",
      "20%"
    ],
    "description_sha256": "acb0f9cfd5d51f2a27150f5633b5b9af46de62e4bb4fd18e26958d2631dac7ec"
  },
  {
    "eidolon": 2,
    "name": "Dancing Butterfly",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "c4c1677b940ecdf09f37b070b7a5aa3ca6566294aa91017044934fa16d91524d"
  },
  {
    "eidolon": 3,
    "name": "Dazzling Tumult",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a13cfabe952f8b0ba721dae6b62a903cc39e4f5027181a39a15d220998ab9d0b"
  },
  {
    "eidolon": 4,
    "name": "Flitting Phantasm",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15"
    ],
    "description_sha256": "a043b90396f8b7159aff230330ff86edef282bc64724f4a0cc1a11335fc844df"
  },
  {
    "eidolon": 5,
    "name": "Piercing Shards",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "2ffb3c62aa12bac23b64d49468abd535ec168c317a13fea36f100d73f86a6708"
  },
  {
    "eidolon": 6,
    "name": "Shattering Shambles",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "3",
      "1",
      "30%"
    ],
    "description_sha256": "4774ad0dc459d632ade75e934d4d997c8a26476b1f88887bbbc1c9b366ce4b2b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
