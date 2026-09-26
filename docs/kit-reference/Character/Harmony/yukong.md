---
schema_version: "1.0.0"
unit_id: 32
name: "Yukong"
slug: "yukong"
rarity: 4
element: "Imaginary"
path: "Harmony"
role: "Support"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/yukong"
source_record_updated_at: "November 8th, 2024"
dataset_snapshot: "2026-05-30"
---

# Yukong

## Character record

```json
{
  "unit_id": 32,
  "name": "Yukong",
  "slug": "yukong",
  "rarity": "4",
  "element": "Imaginary",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Xianzhou Luofu",
  "release_date": "June 28th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 124.8,
    "def_base": 51,
    "atk_base": 81.6,
    "speed_base": 107
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 10
    },
    "traceStat2": {
      "stat": "dmg_imaginary",
      "value": 22.4
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Dawn M. Bennett",
    "kr": "전숙경 (Jeon Sook-kyung)",
    "jpn": "冬馬由美 (Yumi Tōma)",
    "cn": "钟可 (Zhong Ke)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/yukong",
  "source_record_updated_at": "November 8th, 2024"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120701` | Arrowslinger | Basic ATK | Single Target |
| `skill` | `120702` | Emboldening Salvo | Skill | Support |
| `ult` | `120703` | Diving Kestrel | Ultimate | Single Target |
| `talent` | `120704` | Seven Layers, One Arrow | Talent | Enhance |
| `technique` | `120707` | Chasing the Wind | Technique | Enhance |

## Ability records

### Arrowslinger

```json
{
  "ability_id": "120701",
  "slot": "basic",
  "name": "Arrowslinger",
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
  "description_sha256": "26bf91bae52f1bc205f42f3f619fa85ae87d3212745df3199f5cb5ac2c24186c",
  "icon_path": "icon/skill/1207_basic_atk.png"
}
```

### Emboldening Salvo

```json
{
  "ability_id": "120702",
  "slot": "skill",
  "name": "Emboldening Salvo",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
  "energy_gain": "30",
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "364d940a555b3de2e4e84760337d2d6acd38179b1c35e4756a9c261e2b41248f",
  "icon_path": "icon/skill/1207_skill.png"
}
```

### Diving Kestrel

```json
{
  "ability_id": "120703",
  "slot": "ult",
  "name": "Diving Kestrel",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_rate",
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 39,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 243.2,
          "unit": "percent"
        },
        "p2": {
          "value": 21.7,
          "unit": "percent"
        },
        "p3": {
          "value": 41.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 258.4,
          "unit": "percent"
        },
        "p2": {
          "value": 22.4,
          "unit": "percent"
        },
        "p3": {
          "value": 44.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 273.6,
          "unit": "percent"
        },
        "p2": {
          "value": 23.1,
          "unit": "percent"
        },
        "p3": {
          "value": 46.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 288.8,
          "unit": "percent"
        },
        "p2": {
          "value": 23.8,
          "unit": "percent"
        },
        "p3": {
          "value": 49.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 24.5,
          "unit": "percent"
        },
        "p3": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 323,
          "unit": "percent"
        },
        "p2": {
          "value": 25.38,
          "unit": "percent"
        },
        "p3": {
          "value": 55.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 342,
          "unit": "percent"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 361,
          "unit": "percent"
        },
        "p2": {
          "value": 27.13,
          "unit": "percent"
        },
        "p3": {
          "value": 61.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 395.2,
          "unit": "percent"
        },
        "p2": {
          "value": 28.7,
          "unit": "percent"
        },
        "p3": {
          "value": 67.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 410.4,
          "unit": "percent"
        },
        "p2": {
          "value": 29.4,
          "unit": "percent"
        },
        "p3": {
          "value": 70.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 425.6,
          "unit": "percent"
        },
        "p2": {
          "value": 30.1,
          "unit": "percent"
        },
        "p3": {
          "value": 72.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 440.8,
          "unit": "percent"
        },
        "p2": {
          "value": 30.8,
          "unit": "percent"
        },
        "p3": {
          "value": 75.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 456,
          "unit": "percent"
        },
        "p2": {
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 78,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9d81c7ef660f7def69f12267ecae6eb5e789f59c3795cf1dd8115ccaa544d7ee",
  "icon_path": "icon/skill/1207_ultimate.png"
}
```

### Seven Layers, One Arrow

```json
{
  "ability_id": "120704",
  "slot": "talent",
  "name": "Seven Layers, One Arrow",
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
    "atk",
    "dmg",
    "toughness"
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "22b5d1f59564eb236e660daeba3cd63de46e82eea83ced079f1c5ed949bac9eb",
  "icon_path": "icon/skill/1207_talent.png"
}
```

### Chasing the Wind

```json
{
  "ability_id": "120707",
  "slot": "technique",
  "name": "Chasing the Wind",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
    "spd"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "6891ff9a39908f9954b765839b053e53d78ea96247c99e98a77d812b9f807cb1",
  "icon_path": "icon/skill/1207_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Archerion",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1",
      "1",
      "2"
    ],
    "description_sha256": "10fb96090e7203129a9ad0b35c404262c14425b7288a921ead02bf17a3c5a7ea"
  },
  {
    "requirement": "A4",
    "name": "Bowmaster",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "12%"
    ],
    "description_sha256": "589d58f135a8641c529e5604fdd375d0160bebd073e5b031b5e091161c817d85"
  },
  {
    "requirement": "A6",
    "name": "Majestas",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "2d0889b5cfac6d8188cf9bce1a2cba26f4b07e4b22ee3fb045bae391c72d155c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Aerial Marshal",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "f9f21feb9c8e13bcb065ff517e479e923651fc0e6cc6a14faef96a863f3ddc9e"
  },
  {
    "eidolon": 2,
    "name": "Skyward Command",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "2da004a51f63793393f236b902b6283748cc11e0073665bea4bbc23b5b1f820b"
  },
  {
    "eidolon": 3,
    "name": "Torrential Fusillade",
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
    "eidolon": 4,
    "name": "Zephyrean Echoes",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "a337d971971567638bbbfa037691c82bd47333a93e4ba7d713f40eb79f8e136b"
  },
  {
    "eidolon": 5,
    "name": "August Deadshot",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "cfd43f8b6221653cdf8eaca74be63108fdae1e2459a53da8296e4df350449940"
  },
  {
    "eidolon": 6,
    "name": "Bowstring Thunderclap",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "cf396e5c2a88dcf3e588a9f39ca62dab365412d19e2cbfd2b89013a7ce69ea1b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
