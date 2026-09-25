---
schema_version: "1.0.0"
unit_id: 2
name: "Trailblazer • Preservation"
slug: "trailblazer-preservation"
rarity: 5
element: "Fire"
path: "Preservation"
role: "Shielder"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/trailblazer-preservation"
source_record_updated_at: "January 5th, 2025"
dataset_snapshot: "2026-05-30"
---

# Trailblazer • Preservation

## Character record

```json
{
  "unit_id": 2,
  "name": "Trailblazer • Preservation",
  "slug": "trailblazer-preservation",
  "rarity": "5",
  "element": "Fire",
  "path": "Preservation",
  "default_role": "Shielder",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 82.5,
    "atk_base": 81.84,
    "speed_base": 95
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "def",
      "value": 35
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Rachael Chau | Caleb Yen",
    "kr": "Kim Ha-ru (김하루) | Kim Myung-jun (김명준)",
    "jpn": "Ishikawa Yui (石川 由依) | Enoki Junya (榎木 淳弥)",
    "cn": "Chen Tingting (陈婷婷) | Qin Juge (秦且歌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/trailblazer-preservation",
  "source_record_updated_at": "January 5th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `800301` | Ice-Breaking Light | Basic ATK | Single Target |
| `basic_enh` | `800308` | Ice-Breaking Light | Basic ATK | Blast |
| `skill` | `800302` | Ever-Burning Amber | Skill | Defense |
| `ult` | `800303` | War-Flaming Lance | Ultimate | AoE |
| `talent` | `800304` | Treasure of the Architects | Talent | Enhance |
| `technique` | `800307` | Call of the Guardian | Technique | Defense |

## Ability records

### Ice-Breaking Light

```json
{
  "ability_id": "800301",
  "slot": "basic",
  "name": "Ice-Breaking Light",
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
  "description_sha256": "bc556e6324a70f88972168205922defb6eeee5afa1b29ae6b02cf5435e1447dc",
  "icon_path": "icon/skill/8003_basic_atk.png"
}
```

### Ice-Breaking Light

```json
{
  "ability_id": "800308",
  "slot": "basic_enh",
  "name": "Ice-Breaking Light",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
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
    "atk",
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
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        },
        "p2": {
          "value": 39.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
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
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 50.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 135,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 146.25,
          "unit": "percent"
        },
        "p2": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 168.75,
          "unit": "percent"
        },
        "p2": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "98d3803684f7a39f6112a7c91b79d2192fdf05c2f791e5d92b63c4643ec97b8e",
  "icon_path": "icon/skill/8003_basic_atk.png"
}
```

### Ever-Burning Amber

```json
{
  "ability_id": "800302",
  "slot": "skill",
  "name": "Ever-Burning Amber",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Fire",
  "energy_gain": "30",
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
          "value": 41,
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
          "value": 42,
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
          "value": 43,
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
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 45,
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
          "value": 46.25,
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
          "value": 47.5,
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
          "value": 48.75,
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
          "value": 50,
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
          "value": 51,
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
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 53,
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
          "value": 54,
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
          "value": 55,
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
  "description_sha256": "baa067210f166faf741954e88151dc59b3969bcec0dff72f18c9bd50bc5cf2c8",
  "icon_path": "icon/skill/8003_skill.png"
}
```

### War-Flaming Lance

```json
{
  "ability_id": "800303",
  "slot": "ult",
  "name": "War-Flaming Lance",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
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
        },
        "p2": {
          "value": 82.5,
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
        },
        "p2": {
          "value": 90,
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
        },
        "p2": {
          "value": 97.5,
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
        },
        "p2": {
          "value": 105,
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
        },
        "p2": {
          "value": 112.5,
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
        },
        "p2": {
          "value": 121.88,
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
        },
        "p2": {
          "value": 131.25,
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
        },
        "p2": {
          "value": 140.63,
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
        },
        "p2": {
          "value": 150,
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
        },
        "p2": {
          "value": 157.5,
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
        },
        "p2": {
          "value": 165,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 115,
          "unit": "percent"
        },
        "p2": {
          "value": 172.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent"
        },
        "p2": {
          "value": 187.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2666aaf7e7fcc228547ffc2dab8f0d3c5404036835e21dec9e1b1821d81dbb47",
  "icon_path": "icon/skill/8003_ultimate.png"
}
```

### Treasure of the Architects

```json
{
  "ability_id": "800304",
  "slot": "talent",
  "name": "Treasure of the Architects",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "dmg",
    "shield"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 4.25,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 32,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 4.5,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 41,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 4.75,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 56,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 5.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 62,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 5.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 66.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 5.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 71,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 5.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 75.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 80,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 6.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 84.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 6.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 89,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 6.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 93.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 6.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 98,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 102.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "72944a77fdb0b88055036b2271bcb07cc6811a5896f209ecced8f6a5ee2e771c",
  "icon_path": "icon/skill/8003_talent.png"
}
```

### Call of the Guardian

```json
{
  "ability_id": "800307",
  "slot": "technique",
  "name": "Call of the Guardian",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
    "def",
    "dmg",
    "shield"
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
          "value": 384,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "79e72cf2d2fbe5d56339e9e193041ed5165b28fea2f9ae56a6f14e6ed718ac1a",
  "icon_path": "icon/skill/8003_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "The Strong Defend the Weak",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "1"
    ],
    "description_sha256": "8aa56edee832d9bf9d995e2e4b957f783c551bda69f5debdc2e02f96cd8967c3"
  },
  {
    "requirement": "A4",
    "name": "Unwavering Gallantry",
    "mechanic_tags": [
      "max_hp",
      "atk"
    ],
    "numeric_tokens": [
      "5%"
    ],
    "description_sha256": "69e40646b6c0bf225aad11a6766818ea4dee73531c8a3f29188c1187014568ff"
  },
  {
    "requirement": "A6",
    "name": "Action Beats Overthinking",
    "mechanic_tags": [
      "atk",
      "energy",
      "shield"
    ],
    "numeric_tokens": [
      "15%",
      "5"
    ],
    "description_sha256": "49cd019bbcb277a93eb8eb5740a81e345e80bc8cc8270dc2cce8737ecf7b1d8a"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Earth-Shaking Resonance",
    "mechanic_tags": [
      "atk",
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "25%",
      "50%"
    ],
    "description_sha256": "f912722e59ae1da96584bd44c9dcef339ff983a205d774b068cec77c474b3f1e"
  },
  {
    "eidolon": 2,
    "name": "Time-Defying Tenacity",
    "mechanic_tags": [
      "def",
      "dmg",
      "shield"
    ],
    "numeric_tokens": [
      "2%",
      "27"
    ],
    "description_sha256": "b2507ea8f87f854d110496ddf8df5a7937d65d3666c4e13c582fdd95504f3d84"
  },
  {
    "eidolon": 3,
    "name": "Trail-Blazing Blueprint",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "1793fc6d7e120b7ef51027a8a54682b42062f5c45a2641a90351e34693a1e854"
  },
  {
    "eidolon": 4,
    "name": "Nation-Building Oath",
    "mechanic_tags": [],
    "numeric_tokens": [
      "4"
    ],
    "description_sha256": "c84b76675957226fde41af0f3d63f6fc09efc4b51e4ecf91d287ca0d0d79bcca"
  },
  {
    "eidolon": 5,
    "name": "Spirit-Warming Flame",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "ef41c0ce13bfa86071ef69fe2f437f6e8c5c3a055a9891381b35b408b406063e"
  },
  {
    "eidolon": 6,
    "name": "City-Forging Bulwarks",
    "mechanic_tags": [
      "atk",
      "def"
    ],
    "numeric_tokens": [
      "10%",
      "3"
    ],
    "description_sha256": "745ded621532377b8c1a4ee6db5100545eccb950860962b99764d412ce1f6e82"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
