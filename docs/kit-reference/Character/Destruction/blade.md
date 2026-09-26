---
schema_version: "1.0.0"
unit_id: 28
name: "Blade"
slug: "blade"
rarity: 5
element: "Wind"
path: "Destruction"
role: "Main DPS"
affiliation: "Stellaron Hunters"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/blade"
source_record_updated_at: "July 10th, 2025"
dataset_snapshot: "2026-05-30"
---

# Blade

## Character record

```json
{
  "unit_id": 28,
  "name": "Blade",
  "slug": "blade",
  "rarity": "5",
  "element": "Wind",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Stellaron Hunters",
  "release_date": "July 19th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 184.8,
    "def_base": 66,
    "atk_base": 73.92,
    "speed_base": 97
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "critRate",
      "value": 12
    },
    "traceStat2": {
      "stat": "hp",
      "value": 28
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Daman Mills",
    "kr": "Kwak Yoon-sang (곽윤상)",
    "jpn": "Miki Shinichiro (三木眞一郎)",
    "cn": "Liu Yijia (刘以嘉)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/blade",
  "source_record_updated_at": "July 10th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120501` | Shard Sword | Basic ATK | Single Target |
| `basic_enh` | `120508` | Forest of Swords | Basic ATK | Blast |
| `skill` | `120502` | Hellscape | Skill | Enhance |
| `ult` | `120503` | Death Sentence | Ultimate | Blast |
| `talent` | `120504` | Shuhu's Gift | Talent | AoE |
| `technique` | `120507` | Karma Wind | Technique | MazeAttack |

## Ability records

### Shard Sword

```json
{
  "ability_id": "120501",
  "slot": "basic",
  "name": "Shard Sword",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
    "max_hp",
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
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c30de68fd30a29e45e2b5c294ecac9c098d6368e491e465c7acc443f7aa0daab",
  "icon_path": "icon/skill/1205_basic_atk.png"
}
```

### Forest of Swords

```json
{
  "ability_id": "120508",
  "slot": "basic_enh",
  "name": "Forest of Swords",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Wind",
  "energy_gain": "30",
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
    "max_hp",
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 31.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        },
        "p2": {
          "value": 36.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 41.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 117,
          "unit": "percent"
        },
        "p2": {
          "value": 46.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
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
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 143,
          "unit": "percent"
        },
        "p2": {
          "value": 57.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        },
        "p2": {
          "value": 62.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 169,
          "unit": "percent"
        },
        "p2": {
          "value": 67.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 182,
          "unit": "percent"
        },
        "p2": {
          "value": 72.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c1df27f0f2e7e362d88d8a56ed5c9c21514b9c6261558efce10bff77939a9f28",
  "icon_path": "icon/skill/1205_basic_atk.png"
}
```

### Hellscape

```json
{
  "ability_id": "120502",
  "slot": "skill",
  "name": "Hellscape",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
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
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 14.8,
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
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 17.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 20.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 29.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 36.5,
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
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 42.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 45.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 48.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 51.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 54,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c0de694a58f9f2b1f4b8e3fa8b7a7350a1cb30cbd735a279e2e4b55a948e0373",
  "icon_path": "icon/skill/1205_skill.png"
}
```

### Death Sentence

```json
{
  "ability_id": "120503",
  "slot": "ult",
  "name": "Death Sentence",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 2
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
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
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
          "value": 64,
          "unit": "percent"
        },
        "p3": {
          "value": 38.4,
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
          "value": 68,
          "unit": "percent"
        },
        "p3": {
          "value": 40.8,
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
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 43.2,
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
          "value": 76,
          "unit": "percent"
        },
        "p3": {
          "value": 45.6,
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
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 48,
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
          "value": 85,
          "unit": "percent"
        },
        "p3": {
          "value": 51,
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
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 54,
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
          "value": 95,
          "unit": "percent"
        },
        "p3": {
          "value": 57,
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
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
          "value": 104,
          "unit": "percent"
        },
        "p3": {
          "value": 62.4,
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
          "value": 108,
          "unit": "percent"
        },
        "p3": {
          "value": 64.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 112,
          "unit": "percent"
        },
        "p3": {
          "value": 67.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 174,
          "unit": "percent"
        },
        "p2": {
          "value": 116,
          "unit": "percent"
        },
        "p3": {
          "value": 69.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "af23fe0e12e8f8caaf84ac47fe240ca954eb8758e6b00954b091f7957e57b977",
  "icon_path": "icon/skill/1205_ultimate.png"
}
```

### Shuhu's Gift

```json
{
  "ability_id": "120504",
  "slot": "talent",
  "name": "Shuhu's Gift",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Wind",
  "energy_gain": "10",
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
    "max_hp",
    "atk",
    "dmg",
    "healing",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 71.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 84.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 105.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 113.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 121.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 136.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 143,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 149.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 162.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a3abea0c4ba1e4c680e09108cc200d3bf955d110beced0dc353b4ebb311f32c6",
  "icon_path": "icon/skill/1205_talent.png"
}
```

### Karma Wind

```json
{
  "ability_id": "120507",
  "slot": "technique",
  "name": "Karma Wind",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
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
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c1e91365b72de25f790e2d3fd6a05165757921c8b74ef8778f20a16ac8e31c8e",
  "icon_path": "icon/skill/1205_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Vita Infinita",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "499f8d0b8c856e24a9e2f9bdbcaac8967f6d0c6883d8ba0f111b6e86d4450d5d"
  },
  {
    "requirement": "A4",
    "name": "Neverending Deaths",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "20%",
      "25%"
    ],
    "description_sha256": "f07a82e5367277e7eafa4c4304d8f348b974a3aa611d9a837d349e424d782b5e"
  },
  {
    "requirement": "A6",
    "name": "Cyclone of Destruction",
    "mechanic_tags": [
      "atk",
      "energy",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "20%",
      "15"
    ],
    "description_sha256": "f6562c732af489f3109f7a0dd7803239d98445eae564d11fcd39f5691da0dab7"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Blade Cuts the Deepest in Hell",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "150%"
    ],
    "description_sha256": "e33c793a4039788319a8a0330c3b402adf4e2990f76fc03632d9303245a01b61"
  },
  {
    "eidolon": 2,
    "name": "Ten Thousand Sorrows From One Broken Dream",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "9022c8abb9742c759d18b7385fa5a7a8c089f97a71cb4f0c4a075ba99b209b52"
  },
  {
    "eidolon": 3,
    "name": "Hardened Blade Bleeds Coldest Shade",
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
    "name": "Rejected by Death, Infected With Life",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "50%",
      "20%",
      "2"
    ],
    "description_sha256": "77dfcb29e87d7637a98ec0e16afecb28a0bb1cf6054e852f2cd24d5b000329ea"
  },
  {
    "eidolon": 5,
    "name": "Death By Ten Lords' Gaze",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "a72a6f519ba792484398fd1cf304fd1e5e198117773df1f976894e7d5476f6d3"
  },
  {
    "eidolon": 6,
    "name": "Reborn Into an Empty Husk",
    "mechanic_tags": [
      "max_hp",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "4",
      "50%"
    ],
    "description_sha256": "81159bc62d40d76584df390b822fad825cf5297dd6c935f3923b8be809f8dac7"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
