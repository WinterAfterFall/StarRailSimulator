---
schema_version: "1.0.0"
unit_id: 10
name: "Asta"
slug: "asta"
rarity: 4
element: "Fire"
path: "Harmony"
role: "Support"
affiliation: "Herta Space Station"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/asta"
source_record_updated_at: "February 15th, 2025"
dataset_snapshot: "2026-05-30"
---

# Asta

## Character record

```json
{
  "unit_id": 10,
  "name": "Asta",
  "slug": "asta",
  "rarity": "4",
  "element": "Fire",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Herta Space Station",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 139.2,
    "def_base": 63,
    "atk_base": 69.6,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "fireDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat3": {
      "stat": "critRate",
      "value": 6.7
    }
  },
  "voice_actors": {
    "en": "Felecia Angelle",
    "kr": "김현지",
    "jpn": "Akasaki Chinatsu (赤﨑千夏)",
    "cn": "Guiniang (龟娘)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/asta",
  "source_record_updated_at": "February 15th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100901` | Spectrum Beam | Basic ATK | Single Target |
| `skill` | `100902` | Meteor Storm | Skill | Bounce |
| `ult` | `100903` | Astral Blessing | Ultimate | Support |
| `talent` | `100904` | Astrometry | Talent | Support |
| `technique` | `100907` | Miracle Flash | Technique | MazeAttack |

## Ability records

### Spectrum Beam

```json
{
  "ability_id": "100901",
  "slot": "basic",
  "name": "Spectrum Beam",
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
  "description_sha256": "a1344c3611baf176562ded92f1621fb6e954a4998b85a75ce41d310f35f5ba8d",
  "icon_path": "icon/skill/1009_basic_atk.png"
}
```

### Meteor Storm

```json
{
  "ability_id": "100902",
  "slot": "skill",
  "name": "Meteor Storm",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Fire",
  "energy_gain": "6",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
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
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 40.63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 57.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7d5d08e8e5cfe953da738f55e53c0486f2a6a859d0c7fee46b61f638f9fe4137",
  "icon_path": "icon/skill/1009_skill.png"
}
```

### Astral Blessing

```json
{
  "ability_id": "100903",
  "slot": "ult",
  "name": "Astral Blessing",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "spd"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 37.4,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 38.8,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40.2,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 41.6,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 43,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 44.75,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 46.5,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 48.25,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 51.4,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 52.8,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 54.2,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 55.6,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 57,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "ad32fabc53eef9fa6715bae6d94d1d83150f1cae5cdb852d024ebbd0e828d267",
  "icon_path": "icon/skill/1009_ultimate.png"
}
```

### Astrometry

```json
{
  "ability_id": "100904",
  "slot": "talent",
  "name": "Astrometry",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.7,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.1,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 9.8,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 11.38,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 12.25,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 13.13,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 14.7,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 15.4,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 16.1,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "def3bc4c5897b58060a4754b7013a8aefb0e1b51b56202511922812c609c1531",
  "icon_path": "icon/skill/1009_talent.png"
}
```

### Miracle Flash

```json
{
  "ability_id": "100907",
  "slot": "technique",
  "name": "Miracle Flash",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Fire",
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
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2da182903ca578266d372a4858332d7c36ad7a244dde8ab28702f0466df48974",
  "icon_path": "icon/skill/1009_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Sparks",
    "mechanic_tags": [
      "atk",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "80%",
      "3",
      "50%"
    ],
    "description_sha256": "16c00bb6011e0789b0f749888fbb5894cf2811832356eedbf329cb0eb28e8529"
  },
  {
    "requirement": "A4",
    "name": "Ignite",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "18%"
    ],
    "description_sha256": "64fe388d51dc06aa9456db5e05fc69e9224a6fd48559c1dc1da6f85e9f1e2229"
  },
  {
    "requirement": "A6",
    "name": "Constellation",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "6%"
    ],
    "description_sha256": "abf539cdb6bae3619d9b74b376136873972ecdd08964559c535b3e9bac396bbb"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Star Sings Sans Verses or Vocals",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "5e8ab46fdd2866b86955e18cde8c600b38644eac54a897e4e00db8c15e93bbff"
  },
  {
    "eidolon": 2,
    "name": "Moon Speaks in Wax and Wane",
    "mechanic_tags": [],
    "numeric_tokens": [],
    "description_sha256": "ecbcef5ec9bcbab4213cd922a996a6a914858da09bfc965e603feb9cd68f76a3"
  },
  {
    "eidolon": 3,
    "name": "Meteor Showers for Wish and Want",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "4c910ab9157733f3234ecdaa8bba52b244d201a478bad2528e5caf200f7c4227"
  },
  {
    "eidolon": 4,
    "name": "Aurora Basks in Beauty and Bliss",
    "mechanic_tags": [
      "energy",
      "energy_regen_rate"
    ],
    "numeric_tokens": [
      "15%",
      "2"
    ],
    "description_sha256": "ff8ee6f2e97800ea8d4189432f7d1735858503cfb9a945cffed553d27c9548e4"
  },
  {
    "eidolon": 5,
    "name": "Nebula Secludes in Cold Cosmos",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "bc9b09b7015c543b22391cfc36d3f3dbfe0ab3ca7a74e98b7e29242a899157fb"
  },
  {
    "eidolon": 6,
    "name": "Galaxy Dreams in Calm and Comfort",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "deff312eb59014bc843cd1ad659d8f5aa94c79a819d26aa3261d1fad0942d729"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
