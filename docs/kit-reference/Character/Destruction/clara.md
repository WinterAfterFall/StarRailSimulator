---
schema_version: "1.0.0"
unit_id: 18
name: "Clara"
slug: "clara"
rarity: 5
element: "Physical"
path: "Destruction"
role: "Main DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/clara"
source_record_updated_at: "February 15th, 2025"
dataset_snapshot: "2026-05-30"
---

# Clara

## Character record

```json
{
  "unit_id": 18,
  "name": "Clara",
  "slug": "clara",
  "rarity": "5",
  "element": "Physical",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 179.52,
    "def_base": 66,
    "atk_base": 100.32,
    "speed_base": 90
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "physicalDmg",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Emily Sun",
    "kr": "김예림",
    "jpn": "Hidaka Rina (日高里菜)",
    "cn": "Zisu (紫苏九月)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/clara",
  "source_record_updated_at": "February 15th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110701` | I Want to Help | Basic ATK | Single Target |
| `skill` | `110702` | Svarog Watches Over You | Skill | AoE |
| `ult` | `110703` | Promise, Not Command | Ultimate | Enhance |
| `talent` | `110704` | Because We're Family | Talent | Single Target |
| `technique` | `110707` | A Small Price for Victory | Technique | MazeAttack |

## Ability records

### I Want to Help

```json
{
  "ability_id": "110701",
  "slot": "basic",
  "name": "I Want to Help",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
  "description_sha256": "af807467ce64041a9fa32f1664be7579fcc954451b2df4ae986b9b12f8044423",
  "icon_path": "icon/skill/1107_basic_atk.png"
}
```

### Svarog Watches Over You

```json
{
  "ability_id": "110702",
  "slot": "skill",
  "name": "Svarog Watches Over You",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "30",
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
          "value": 60,
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
          "value": 66,
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
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        },
        "p2": {
          "value": 138,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "df8ffca2d01d72739f12aa9a1f2ddb374f93dabb0d7f6470325dc00015af9f82",
  "icon_path": "icon/skill/1107_skill.png"
}
```

### Promise, Not Command

```json
{
  "ability_id": "110703",
  "slot": "ult",
  "name": "Promise, Not Command",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 15,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 102.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 16,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 108.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 17,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 115.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 121.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 19,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 128,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 136,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 22.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 152,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.75,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 160,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 166.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 26,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 172.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 27,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 179.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 28,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 185.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 29,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        },
        "p2": {
          "value": 192,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8f21f401eeb4ecdacb723d7ac06e8a1b749266dbc8723829c560b8e0569c9c9f",
  "icon_path": "icon/skill/1107_ultimate.png"
}
```

### Because We're Family

```json
{
  "ability_id": "110704",
  "slot": "talent",
  "name": "Because We're Family",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "30",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
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
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 104,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 112,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 130,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 140,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 160,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 168,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 176,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 184,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 192,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 200,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fe799227c036e9429b3677d510da2cc1fa0b9b25fc7443ac98e8d392eafefd9a",
  "icon_path": "icon/skill/1107_talent.png"
}
```

### A Small Price for Victory

```json
{
  "ability_id": "110707",
  "slot": "technique",
  "name": "A Small Price for Victory",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
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
        },
        "p2": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1664026756c7c0c256df44f4164de60a3ec9985c5fa38ebaa7f31db2b656a21f",
  "icon_path": "icon/skill/1107_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Kinship",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "9c32f2a018468c099227ada88f701fad09c5c3203cd97df90ca2f148d0d4ade9"
  },
  {
    "requirement": "A4",
    "name": "Under Protection",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "76836ae4969b9f3c8bad621014172db87c10c09e9bf627c95e55997b7fdc7f80"
  },
  {
    "requirement": "A6",
    "name": "Revenge",
    "mechanic_tags": [
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "9e214a81f1b9371b1d39bd3be61c2a59d5650242dad092cf9b662195e2be9c5c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "A Tall Figure",
    "mechanic_tags": [
      "follow_up"
    ],
    "numeric_tokens": [],
    "description_sha256": "185b55839d716e5941b782ccd5bf6fbcac2d10100759df1998d0e4a8768afb5a"
  },
  {
    "eidolon": 2,
    "name": "A Tight Embrace",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "30%",
      "2"
    ],
    "description_sha256": "1ac7757b49515255c0677f7a666772ff0561e2e7cbacc540b9be9b10fe81f059"
  },
  {
    "eidolon": 3,
    "name": "Cold Steel Armor",
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
    "name": "Family’s Warmth",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "d2558b56436ec7466e71ab0165cbd1037c854bc2dfecab2e1e870304b788b4d1"
  },
  {
    "eidolon": 5,
    "name": "A Small Promise",
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
    "name": "Long Company",
    "mechanic_tags": [
      "follow_up"
    ],
    "numeric_tokens": [
      "50%",
      "1"
    ],
    "description_sha256": "3d38cdd9a5d621d24d85b090e1c03e92d75d00a0a681341a8cba25cb18ac260b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
