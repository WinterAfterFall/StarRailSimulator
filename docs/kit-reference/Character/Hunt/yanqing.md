---
schema_version: "1.0.0"
unit_id: 23
name: "Yanqing"
slug: "yanqing"
rarity: 5
element: "Ice"
path: "Hunt"
role: "Main DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/yanqing"
source_record_updated_at: "January 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# Yanqing

## Character record

```json
{
  "unit_id": 23,
  "name": "Yanqing",
  "slug": "yanqing",
  "rarity": "5",
  "element": "Ice",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 121.44,
    "def_base": 56.1,
    "atk_base": 92.4,
    "speed_base": 109
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 14.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 28
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Amber May",
    "kr": "",
    "jpn": "Marina Inoue (井上 麻里奈)",
    "cn": "Miaojiang (喵酱)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/yanqing",
  "source_record_updated_at": "January 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120901` | Frost Thorn | Basic ATK | Single Target |
| `skill` | `120902` | Darting Ironthorn | Skill | Single Target |
| `ult` | `120903` | Amidst the Raining Bliss | Ultimate | Single Target |
| `talent` | `120904` | One With the Sword | Talent | Single Target |
| `technique` | `120907` | The One True Sword | Technique | Enhance |

## Ability records

### Frost Thorn

```json
{
  "ability_id": "120901",
  "slot": "basic",
  "name": "Frost Thorn",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
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
  "description_sha256": "b6e401ebb2a1c91bb1f5ae9cb289162e593f05a56d29cc5565d80d9e50fd938a",
  "icon_path": "icon/skill/1209_basic_atk.png"
}
```

### Darting Ironthorn

```json
{
  "ability_id": "120902",
  "slot": "skill",
  "name": "Darting Ironthorn",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
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
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 121,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 143,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 178.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 192.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 206.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 231,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 242,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 253,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 275,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a65033cecd8f721a0089d5283b58a3888a565e0d47384739de8deceb1c36151e",
  "icon_path": "icon/skill/1209_skill.png"
}
```

### Amidst the Raining Bliss

```json
{
  "ability_id": "120903",
  "slot": "ult",
  "name": "Amidst the Raining Bliss",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
  "toughness_break_primary_source": "90",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_rate",
    "crit_dmg",
    "dmg",
    "buff"
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 210,
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
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        },
        "p3": {
          "value": 224,
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
          "value": 34,
          "unit": "percent"
        },
        "p3": {
          "value": 238,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 252,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 38,
          "unit": "percent"
        },
        "p3": {
          "value": 266,
          "unit": "percent"
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
          "value": 40,
          "unit": "percent"
        },
        "p3": {
          "value": 280,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 42.5,
          "unit": "percent"
        },
        "p3": {
          "value": 297.5,
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
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 315,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 47.5,
          "unit": "percent"
        },
        "p3": {
          "value": 332.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 350,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
          "unit": "percent"
        },
        "p3": {
          "value": 364,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 378,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 392,
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
        },
        "p2": {
          "value": 58,
          "unit": "percent"
        },
        "p3": {
          "value": 406,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 420,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "25f9e523fb6d08d97e27f20f8d410fb380f84299a032a9e516838911a44d7bc7",
  "icon_path": "icon/skill/1209_ultimate.png"
}
```

### One With the Sword

```json
{
  "ability_id": "120904",
  "slot": "talent",
  "name": "One With the Sword",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_rate",
    "crit_dmg",
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 25,
          "unit": "percent"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 15.5,
          "unit": "percent"
        },
        "p2": {
          "value": 16.5,
          "unit": "percent"
        },
        "p3": {
          "value": 51,
          "unit": "percent"
        },
        "p4": {
          "value": 27.5,
          "unit": "percent"
        },
        "p5": {
          "value": 27.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 52,
          "unit": "percent"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        },
        "p2": {
          "value": 19.5,
          "unit": "percent"
        },
        "p3": {
          "value": 53,
          "unit": "percent"
        },
        "p4": {
          "value": 32.5,
          "unit": "percent"
        },
        "p5": {
          "value": 32.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 17,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 54,
          "unit": "percent"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 35,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        },
        "p2": {
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 55,
          "unit": "percent"
        },
        "p4": {
          "value": 37.5,
          "unit": "percent"
        },
        "p5": {
          "value": 37.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 18.13,
          "unit": "percent"
        },
        "p2": {
          "value": 24.38,
          "unit": "percent"
        },
        "p3": {
          "value": 56.25,
          "unit": "percent"
        },
        "p4": {
          "value": 40.63,
          "unit": "percent"
        },
        "p5": {
          "value": 40.63,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 18.75,
          "unit": "percent"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 57.5,
          "unit": "percent"
        },
        "p4": {
          "value": 43.75,
          "unit": "percent"
        },
        "p5": {
          "value": 43.75,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 19.38,
          "unit": "percent"
        },
        "p2": {
          "value": 28.13,
          "unit": "percent"
        },
        "p3": {
          "value": 58.75,
          "unit": "percent"
        },
        "p4": {
          "value": 46.88,
          "unit": "percent"
        },
        "p5": {
          "value": 46.88,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 20.5,
          "unit": "percent"
        },
        "p2": {
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 61,
          "unit": "percent"
        },
        "p4": {
          "value": 52.5,
          "unit": "percent"
        },
        "p5": {
          "value": 52.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 62,
          "unit": "percent"
        },
        "p4": {
          "value": 55,
          "unit": "percent"
        },
        "p5": {
          "value": 55,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 21.5,
          "unit": "percent"
        },
        "p2": {
          "value": 34.5,
          "unit": "percent"
        },
        "p3": {
          "value": 63,
          "unit": "percent"
        },
        "p4": {
          "value": 57.5,
          "unit": "percent"
        },
        "p5": {
          "value": 57.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 64,
          "unit": "percent"
        },
        "p4": {
          "value": 60,
          "unit": "percent"
        },
        "p5": {
          "value": 60,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 65,
          "unit": "percent"
        },
        "p4": {
          "value": 62.5,
          "unit": "percent"
        },
        "p5": {
          "value": 62.5,
          "unit": "percent"
        },
        "p6": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b88739d303a2b66dde9ed9b13c143ef2979dd0ad28b31c28282909666d448db2",
  "icon_path": "icon/skill/1209_talent.png"
}
```

### The One True Sword

```json
{
  "ability_id": "120907",
  "slot": "technique",
  "name": "The One True Sword",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9c4b58c529efb4e4d99607ba239f8d4e20b46302b7e10e44aba5aaa3befaa134",
  "icon_path": "icon/skill/1209_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Icing on the Kick",
    "mechanic_tags": [
      "atk",
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "acb59121d53bf5e8f3a34ad7bd85a05aa9cf2530f9736c413122f7638a175480"
  },
  {
    "requirement": "A4",
    "name": "Frost Favors the Brave",
    "mechanic_tags": [
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "25a35cbb914f271d6a409451d859f1cd13d54b04107cabe08aa7d980429d830d"
  },
  {
    "requirement": "A6",
    "name": "Gentle Blade",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "8f25dadedefacde763f5cb0d3523b63596fc6efa5f9fade1d0aa06aa713b0c8c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Svelte Saber",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "60%"
    ],
    "description_sha256": "4807bee05e74850aac1c9d47e2ae5f94681fd325d206c749fca47f294154af1c"
  },
  {
    "eidolon": 2,
    "name": "Supine Serenade",
    "mechanic_tags": [
      "energy",
      "energy_regen_rate"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "756a239d27f130862b304217b8b96eb3e5ca51bd381d167196b01c7a2ce5ed9c"
  },
  {
    "eidolon": 3,
    "name": "Sword Savant",
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
    "name": "Searing Sting",
    "mechanic_tags": [
      "max_hp",
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "80%",
      "12%"
    ],
    "description_sha256": "d7dff01ef626c22c150f1f32fcadd6406050046a5878c607d789e675ce3cacbd"
  },
  {
    "eidolon": 5,
    "name": "Surging Strife",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a4417497ecb72e43d7a08beb9ea57ccb09e86b6838c1773e7e2ade42f7242276"
  },
  {
    "eidolon": 6,
    "name": "Swift Swoop",
    "mechanic_tags": [
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "0852b5a7f3ce0eda5c93186533ed87ba7cf323bd742039f1994df4bf12f86410"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
