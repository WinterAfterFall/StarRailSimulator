---
schema_version: "1.0.0"
unit_id: 5
name: "Himeko"
slug: "himeko"
rarity: 5
element: "Fire"
path: "Erudition"
role: "Main DPS"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/himeko"
source_record_updated_at: "February 15th, 2025"
dataset_snapshot: "2026-05-30"
---

# Himeko

## Character record

```json
{
  "unit_id": 5,
  "name": "Himeko",
  "slug": "himeko",
  "rarity": "5",
  "element": "Fire",
  "path": "Erudition",
  "default_role": "Main DPS",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 59.4,
    "atk_base": 102.96,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "fireDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Cia Court",
    "kr": "김보나",
    "jpn": "Tanaka Rie (田中理恵)",
    "cn": "Lin Su (林簌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/himeko",
  "source_record_updated_at": "February 15th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100301` | Sawblade Tuning | Basic ATK | Single Target |
| `skill` | `100302` | Molten Detonation | Skill | Blast |
| `ult` | `100303` | Heavenly Flare | Ultimate | AoE |
| `talent` | `100304` | Victory Rush | Talent | AoE |
| `technique` | `100307` | Incomplete Combustion | Technique | Impair |

## Ability records

### Sawblade Tuning

```json
{
  "ability_id": "100301",
  "slot": "basic",
  "name": "Sawblade Tuning",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
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
  "description_sha256": "24bf813519bb92f982b941fe3ca636abb61ffe7e2f249523002dfa2969dbd3c3",
  "icon_path": "icon/skill/1003_basic_atk.png"
}
```

### Molten Detonation

```json
{
  "ability_id": "100302",
  "slot": "skill",
  "name": "Molten Detonation",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 40,
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
        },
        "p2": {
          "value": 44,
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
        },
        "p2": {
          "value": 48,
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
        },
        "p2": {
          "value": 52,
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
        },
        "p2": {
          "value": 56,
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
        },
        "p2": {
          "value": 60,
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
        },
        "p2": {
          "value": 65,
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
        },
        "p2": {
          "value": 70,
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
        },
        "p2": {
          "value": 75,
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
        },
        "p2": {
          "value": 80,
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
        },
        "p2": {
          "value": 84,
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
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c59bab75ea3a5d4088da5379242c0412e73aa4ddfd495ab36991f1fb3c680ba2",
  "icon_path": "icon/skill/1003_skill.png"
}
```

### Heavenly Flare

```json
{
  "ability_id": "100303",
  "slot": "ult",
  "name": "Heavenly Flare",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 147.2,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 156.4,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 165.6,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 174.8,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 184,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 195.5,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 207,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 218.5,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 239.2,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 248.4,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 257.6,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 266.8,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 276,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "5fc61d7f976dc1071f1910828a6e67016702c238101fd0f4664a9f76427d456e",
  "icon_path": "icon/skill/1003_ultimate.png"
}
```

### Victory Rush

```json
{
  "ability_id": "100304",
  "slot": "talent",
  "name": "Victory Rush",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "follow_up",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 98,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 113.75,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 122.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 147,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 161,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3da76e8b2c750366d738c2a8a9256cf979b1cf5324e22fc9ae55f50e6968b280",
  "icon_path": "icon/skill/1003_talent.png"
}
```

### Incomplete Combustion

```json
{
  "ability_id": "100307",
  "slot": "technique",
  "name": "Incomplete Combustion",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "31dc36861cdf71f9aa75f467ce5a80586bf88bfc4d9157c5564100429116ee6a",
  "icon_path": "icon/skill/1003_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Starfire",
    "mechanic_tags": [
      "atk",
      "dot"
    ],
    "numeric_tokens": [
      "50%",
      "2",
      "30%"
    ],
    "description_sha256": "0fd27882229d3c921a60d27b32285a53713f1907d2bf088c83d3898ca2672311"
  },
  {
    "requirement": "A4",
    "name": "Magma",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "00152d4fba16d0d8967aa1d5b3e7796d256941214e0d8a68bea4c594d1b65ced"
  },
  {
    "requirement": "A6",
    "name": "Benchmark",
    "mechanic_tags": [
      "max_hp",
      "crit_rate"
    ],
    "numeric_tokens": [
      "80%",
      "15%"
    ],
    "description_sha256": "14f0d35b21b8964548d13bb6e06e25d912133f06bbee147eefd6ccadc1f922e4"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Childhood",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "20%",
      "2"
    ],
    "description_sha256": "732a99e32ced071c2ae0d4b8bc7a92b28faf6f51cc103a1f02d3d35d159617d3"
  },
  {
    "eidolon": 2,
    "name": "Convergence ",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "50%"
    ],
    "description_sha256": "0728ea252908896e909cbf73e37f06230f363c0588d4a2aab7cf766cdb1df555"
  },
  {
    "eidolon": 3,
    "name": "Poised",
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
    "name": "Dedication ",
    "mechanic_tags": [
      "weakness"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "b91038334013228a206d016c04962ea1044f6d596aebd2420a683225e7a88c5a"
  },
  {
    "eidolon": 5,
    "name": "Aspiration",
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
    "name": "Trailblaze ",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "2",
      "40%"
    ],
    "description_sha256": "8fc0e3955dfa82f7520da5b869e7648127525b5ba10ce753e207dbd6d0afd1c8"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
