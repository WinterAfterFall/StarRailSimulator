---
schema_version: "1.0.0"
unit_id: 35
name: "Lynx"
slug: "lynx"
rarity: 4
element: "Quantum"
path: "Abundance"
role: "Healer"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/lynx"
source_record_updated_at: "January 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# Lynx

## Character record

```json
{
  "unit_id": 35,
  "name": "Lynx",
  "slug": "lynx",
  "rarity": "4",
  "element": "Quantum",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "Belobog",
  "release_date": "September 20th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 144,
    "def_base": 75,
    "atk_base": 67.2,
    "speed_base": 100
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat2": {
      "stat": "hp",
      "value": 28
    },
    "traceStat3": {
      "stat": "effect_res",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Risa Mei",
    "kr": "이은조 (Lee Eun-jo)",
    "jpn": "照井春佳 (Haruka Terui)",
    "cn": "米糊"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/lynx",
  "source_record_updated_at": "January 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `111001` | Ice Crampon Technique | Basic ATK | Single Target |
| `skill` | `111002` | Salted Camping Cans | Skill | Restore |
| `ult` | `111003` | Snowfield First Aid | Ultimate | Restore |
| `talent` | `111004` | Outdoor Survival Experience | Talent | Restore |
| `technique` | `111007` | Chocolate Energy Bar | Technique | Restore |

## Ability records

### Ice Crampon Technique

```json
{
  "ability_id": "111001",
  "slot": "basic",
  "name": "Ice Crampon Technique",
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
    }
  ],
  "description_sha256": "2adc612990983aab5ac8fe94732630af34b2dc7541246aafd56e953450cf9144",
  "icon_path": "icon/skill/1110_basic_atk.png"
}
```

### Salted Camping Cans

```json
{
  "ability_id": "111002",
  "slot": "skill",
  "name": "Salted Camping Cans",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Quantum",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 8,
          "unit": "percent"
        },
        "p5": {
          "value": 80,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5.25,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 8.5,
          "unit": "percent"
        },
        "p5": {
          "value": 128,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 5.5,
          "unit": "percent"
        },
        "p2": {
          "value": 102.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 9,
          "unit": "percent"
        },
        "p5": {
          "value": 164,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 5.75,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 9.5,
          "unit": "percent"
        },
        "p5": {
          "value": 200,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 224,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 6.25,
          "unit": "percent"
        },
        "p2": {
          "value": 155,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 10.4,
          "unit": "percent"
        },
        "p5": {
          "value": 248,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 6.56,
          "unit": "percent"
        },
        "p2": {
          "value": 166.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 10.8,
          "unit": "percent"
        },
        "p5": {
          "value": 266,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 6.88,
          "unit": "percent"
        },
        "p2": {
          "value": 177.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 11.2,
          "unit": "percent"
        },
        "p5": {
          "value": 284,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 7.19,
          "unit": "percent"
        },
        "p2": {
          "value": 188.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 11.6,
          "unit": "percent"
        },
        "p5": {
          "value": 302,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "percent"
        },
        "p2": {
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 12,
          "unit": "percent"
        },
        "p5": {
          "value": 320,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 7.75,
          "unit": "percent"
        },
        "p2": {
          "value": 211.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 12.4,
          "unit": "percent"
        },
        "p5": {
          "value": 338,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 222.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 12.8,
          "unit": "percent"
        },
        "p5": {
          "value": 356,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 8.25,
          "unit": "percent"
        },
        "p2": {
          "value": 233.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 13.2,
          "unit": "percent"
        },
        "p5": {
          "value": 374,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 8.5,
          "unit": "percent"
        },
        "p2": {
          "value": 245,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 13.6,
          "unit": "percent"
        },
        "p5": {
          "value": 392,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 8.75,
          "unit": "percent"
        },
        "p2": {
          "value": 256.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 14,
          "unit": "percent"
        },
        "p5": {
          "value": 410,
          "unit": "scalar"
        },
        "p6": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "e0f756e1bc27695319f0de1a4906abde1ffcafec37b8f46d8db1eaac132edf5b",
  "icon_path": "icon/skill/1110_skill.png"
}
```

### Snowfield First Aid

```json
{
  "ability_id": "111003",
  "slot": "ult",
  "name": "Snowfield First Aid",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "debuff",
    "buff"
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
          "value": 9,
          "unit": "percent"
        },
        "p3": {
          "value": 90,
          "unit": "scalar"
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
          "value": 9.56,
          "unit": "percent"
        },
        "p3": {
          "value": 144,
          "unit": "scalar"
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
          "value": 10.13,
          "unit": "percent"
        },
        "p3": {
          "value": 184.5,
          "unit": "scalar"
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
          "value": 10.69,
          "unit": "percent"
        },
        "p3": {
          "value": 225,
          "unit": "scalar"
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
          "value": 11.25,
          "unit": "percent"
        },
        "p3": {
          "value": 252,
          "unit": "scalar"
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
          "value": 11.7,
          "unit": "percent"
        },
        "p3": {
          "value": 279,
          "unit": "scalar"
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
          "value": 12.15,
          "unit": "percent"
        },
        "p3": {
          "value": 299.25,
          "unit": "scalar"
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
          "value": 12.6,
          "unit": "percent"
        },
        "p3": {
          "value": 319.5,
          "unit": "scalar"
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
          "value": 13.05,
          "unit": "percent"
        },
        "p3": {
          "value": 339.75,
          "unit": "scalar"
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
          "value": 13.5,
          "unit": "percent"
        },
        "p3": {
          "value": 360,
          "unit": "scalar"
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
          "value": 13.95,
          "unit": "percent"
        },
        "p3": {
          "value": 380.25,
          "unit": "scalar"
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
          "value": 14.4,
          "unit": "percent"
        },
        "p3": {
          "value": 400.5,
          "unit": "scalar"
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
          "value": 14.85,
          "unit": "percent"
        },
        "p3": {
          "value": 420.75,
          "unit": "scalar"
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
          "value": 15.3,
          "unit": "percent"
        },
        "p3": {
          "value": 441,
          "unit": "scalar"
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
          "value": 15.75,
          "unit": "percent"
        },
        "p3": {
          "value": 461.25,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c0b63c5309d7a4d876c6cf9ceb61c9b3f8e3cbcd119dce22899fd8e0a59759d8",
  "icon_path": "icon/skill/1110_ultimate.png"
}
```

### Outdoor Survival Experience

```json
{
  "ability_id": "111004",
  "slot": "talent",
  "name": "Outdoor Survival Experience",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Quantum",
  "energy_gain": null,
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing"
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
          "value": 2.4,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "percent"
        },
        "p5": {
          "value": 30,
          "unit": "scalar"
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
          "value": 2.55,
          "unit": "percent"
        },
        "p3": {
          "value": 38.4,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.19,
          "unit": "percent"
        },
        "p5": {
          "value": 48,
          "unit": "scalar"
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
          "value": 2.7,
          "unit": "percent"
        },
        "p3": {
          "value": 49.2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.38,
          "unit": "percent"
        },
        "p5": {
          "value": 61.5,
          "unit": "scalar"
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
          "value": 2.85,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.56,
          "unit": "percent"
        },
        "p5": {
          "value": 75,
          "unit": "scalar"
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
          "value": 3,
          "unit": "percent"
        },
        "p3": {
          "value": 67.2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.75,
          "unit": "percent"
        },
        "p5": {
          "value": 84,
          "unit": "scalar"
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
          "value": 3.12,
          "unit": "percent"
        },
        "p3": {
          "value": 74.4,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.9,
          "unit": "percent"
        },
        "p5": {
          "value": 93,
          "unit": "scalar"
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
          "value": 3.24,
          "unit": "percent"
        },
        "p3": {
          "value": 79.8,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.05,
          "unit": "percent"
        },
        "p5": {
          "value": 99.75,
          "unit": "scalar"
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
          "value": 3.36,
          "unit": "percent"
        },
        "p3": {
          "value": 85.2,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.2,
          "unit": "percent"
        },
        "p5": {
          "value": 106.5,
          "unit": "scalar"
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
          "value": 3.48,
          "unit": "percent"
        },
        "p3": {
          "value": 90.6,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.35,
          "unit": "percent"
        },
        "p5": {
          "value": 113.25,
          "unit": "scalar"
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
          "value": 3.6,
          "unit": "percent"
        },
        "p3": {
          "value": 96,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.5,
          "unit": "percent"
        },
        "p5": {
          "value": 120,
          "unit": "scalar"
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
          "value": 3.72,
          "unit": "percent"
        },
        "p3": {
          "value": 101.4,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.65,
          "unit": "percent"
        },
        "p5": {
          "value": 126.75,
          "unit": "scalar"
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
          "value": 3.84,
          "unit": "percent"
        },
        "p3": {
          "value": 106.8,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.8,
          "unit": "percent"
        },
        "p5": {
          "value": 133.5,
          "unit": "scalar"
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
          "value": 3.96,
          "unit": "percent"
        },
        "p3": {
          "value": 112.2,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.95,
          "unit": "percent"
        },
        "p5": {
          "value": 140.25,
          "unit": "scalar"
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
          "value": 4.08,
          "unit": "percent"
        },
        "p3": {
          "value": 117.6,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.1,
          "unit": "percent"
        },
        "p5": {
          "value": 147,
          "unit": "scalar"
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
          "value": 4.2,
          "unit": "percent"
        },
        "p3": {
          "value": 123,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.25,
          "unit": "percent"
        },
        "p5": {
          "value": 153.75,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "910bf14ace4a5b4b7aaa1d56a514e44963a2269926cb14727cb474e362e44cb9",
  "icon_path": "icon/skill/1110_talent.png"
}
```

### Chocolate Energy Bar

```json
{
  "ability_id": "111007",
  "slot": "technique",
  "name": "Chocolate Energy Bar",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3f4988fd001eb261cce371073db631a1ed175f7414ceba5d55541610b03f9017",
  "icon_path": "icon/skill/1110_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Advance Surveying",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "b36df0bcd6692fa078f989751a4fbcaf86291fc8a042c55e7aee07415a4b1608"
  },
  {
    "requirement": "A4",
    "name": "Exploration Techniques",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "9f826e4a935a4d9a3c8fb239c5156fa5e14bc9a0fbcb1843e41e599a6ba68291"
  },
  {
    "requirement": "A6",
    "name": "Survival in the Extreme",
    "mechanic_tags": [
      "healing"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "d06cbc7b67314da21defb6cc429822389224d5ca9e6b2b17f7cceb3f1ea71330"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Morning of Snow Hike",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "50%",
      "20%"
    ],
    "description_sha256": "4f991f3048b3e8730f108dd9c874c3bad634236b10dc396627deab6467954c85"
  },
  {
    "eidolon": 2,
    "name": "Noon of Portable Furnace",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "5c7da2de290881a5a46076f6f5ef4ef9af841da728d070f64c15931e4b99065e"
  },
  {
    "eidolon": 3,
    "name": "Afternoon of Avalanche Beacon",
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
    "name": "Dusk of Warm Campfire",
    "mechanic_tags": [
      "max_hp",
      "atk"
    ],
    "numeric_tokens": [
      "3%",
      "1"
    ],
    "description_sha256": "1281b214a9a3974b66e24d3cafc38f008ceb2a94a890bead0a9eb16febc5b25b"
  },
  {
    "eidolon": 5,
    "name": "Night of Aurora Tea",
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
    "name": "Dawn of Explorers' Chart",
    "mechanic_tags": [
      "max_hp",
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "6%",
      "30%"
    ],
    "description_sha256": "a63a113b1cf3c8a236968d4305c014e303a37765f29704622b91aaddf224a28d"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
