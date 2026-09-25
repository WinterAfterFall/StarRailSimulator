---
schema_version: "1.0.0"
unit_id: 62
name: "Moze"
slug: "moze"
rarity: 4
element: "Lightning"
path: "Hunt"
role: "Sub DPS"
affiliation: "The Xianzhou Laofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/moze"
source_record_updated_at: "February 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Moze

## Character record

```json
{
  "unit_id": 62,
  "name": "Moze",
  "slug": "moze",
  "rarity": "4",
  "element": "Lightning",
  "path": "Hunt",
  "default_role": "Sub DPS",
  "affiliation": "The Xianzhou Laofu",
  "release_date": "September 10th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 110,
    "def_base": 48,
    "atk_base": 81.6,
    "speed_base": 111
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 18
    },
    "traceStat2": {
      "stat": "CRIT DMG",
      "value": 37.3
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Ben Balmaceda",
    "kr": "Choi Hyun-sik (최현식)",
    "jpn": "Sakata Shogo (坂田将吾)",
    "cn": "Huang Jinze (黄进泽)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/moze",
  "source_record_updated_at": "February 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122301` | Hurlthorn | Basic ATK | Single Target |
| `skill` | `122302` | Fleetwinged Raid | Skill | Single Target |
| `ult` | `122303` | Dash In, Gash Out | Ultimate | Single Target |
| `talent` | `122304` | Cascading Featherblade | Talent | Single Target |
| `technique` | `122307` | Bated Wings | Technique | Enhance |

## Ability records

### Hurlthorn

```json
{
  "ability_id": "122301",
  "slot": "basic",
  "name": "Hurlthorn",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
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
  "description_sha256": "e19a315e3fce9c12e57b41e44e78a3e85bf2c37d4270eace620238735bace50e",
  "icon_path": null
}
```

### Fleetwinged Raid

```json
{
  "ability_id": "122302",
  "slot": "skill",
  "name": "Fleetwinged Raid",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 140.625,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "879183888018aefd327144df18487d48df3a1ed91e0d734ba8c29108ab4018d5",
  "icon_path": null
}
```

### Dash In, Gash Out

```json
{
  "ability_id": "122303",
  "slot": "ult",
  "name": "Dash In, Gash Out",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
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
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 162,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 183.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 194.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 205.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 229.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 243,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 256.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 280.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 291.6,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "402ce7a38fbcaa94e90861e0bfc9cd72a433a31c4a46ef63de90b0cbcff75e5e",
  "icon_path": null
}
```

### Cascading Featherblade

```json
{
  "ability_id": "122304",
  "slot": "talent",
  "name": "Cascading Featherblade",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
    "follow_up"
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
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        },
        "p2": {
          "value": 104,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 112,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.375,
          "unit": "percent"
        },
        "p2": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 26.25,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.125,
          "unit": "percent"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 30,
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
          "value": 31.5,
          "unit": "percent"
        },
        "p2": {
          "value": 168,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 176,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "bf03b7c51451ebf892aad76e664c32bf5bccbe26c8395dfd89c767d68f1900ad",
  "icon_path": null
}
```

### Bated Wings

```json
{
  "ability_id": "122307",
  "slot": "technique",
  "name": "Bated Wings",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
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
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 15,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c5058801a7d80476eb1ac464034cf7070b5ef7f6f2787896ff8c90ac87192267",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Nightfeather",
    "mechanic_tags": [
      "follow_up",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "1"
    ],
    "description_sha256": "898fde9e42d5d8039a54403f1ea9124130e1129f8170f2fa4637ed64f2eceba7"
  },
  {
    "requirement": "A4",
    "name": "Daggerhold",
    "mechanic_tags": [
      "action_advance"
    ],
    "numeric_tokens": [
      "20%",
      "30%"
    ],
    "description_sha256": "7a437bf980c20e6f5cc2d4914954469f248e6f2025a491c50ce32bd11c86d7a6"
  },
  {
    "requirement": "A6",
    "name": "Vengewise",
    "mechanic_tags": [
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "14c0db21052cd011e352461465191f16fbc2a8fcbd0e862a8672d5a075fac937"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Oathkeeper",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "20",
      "2"
    ],
    "description_sha256": "5a0927418f3421d3113e763d0da4eb4d078650624600cb02f6286169b23fe493"
  },
  {
    "eidolon": 2,
    "name": "Wrathbearer",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "95dfb424e72b12957f3e1bb27f6ae41e803bc3bb7911a4978fae2aef0cba776a"
  },
  {
    "eidolon": 3,
    "name": "Deathchaser",
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
    "name": "Heathprowler",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%",
      "2"
    ],
    "description_sha256": "83bb2fe6881ccc63673345ea9453f606bccac1fd5c498fe80c0e72f8518eca3d"
  },
  {
    "eidolon": 5,
    "name": "Truthbender",
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
    "name": "Faithbinder",
    "mechanic_tags": [
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "5ca6e500fc5bdedc12faf74c2d5fd7fbe3298f0a6ff322ac1163a6195fa5718b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
