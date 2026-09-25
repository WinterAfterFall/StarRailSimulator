---
schema_version: "1.0.0"
unit_id: 57
name: "Jiaoqiu"
slug: "jiaoqiu"
rarity: 5
element: "Fire"
path: "Nihility"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/jiaoqiu"
source_record_updated_at: "April 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Jiaoqiu

## Character record

```json
{
  "unit_id": 57,
  "name": "Jiaoqiu",
  "slug": "jiaoqiu",
  "rarity": "5",
  "element": "Fire",
  "path": "Nihility",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "August 21st, 2024",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 184.8,
    "def_base": 69.3,
    "atk_base": 81.84,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Effect Hit Rate",
      "value": 28
    },
    "traceStat2": {
      "stat": "Fire DMG",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "Speed",
      "value": 5
    }
  },
  "voice_actors": {
    "en": "Mark Whitten ",
    "kr": "Jeongmin Lee (이정민)",
    "jpn": "Toshiyuki Toyonaga (丰永利行)",
    "cn": "Taikang Chenzhang (陈张太康)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/jiaoqiu",
  "source_record_updated_at": "April 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121801` | Heart Afire | Basic ATK | Single Target |
| `skill` | `121802` | Scorch Onslaught | Skill | Blast |
| `ult` | `121803` | Pyrograph Arcanum | Ultimate | AoE |
| `talent` | `121804` | Quartet Finesse, Octave Finery | Talent | Impair |
| `technique` | `121807` | Fiery Queller | Technique | Impair |

## Ability records

### Heart Afire

```json
{
  "ability_id": "121801",
  "slot": "basic",
  "name": "Heart Afire",
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
  "description_sha256": "49c83c3584935b0da8aa9f882c27fd9b4f3bc90e806b574cf40e6ca045f227a6",
  "icon_path": "icon/skill/1218_basic_atk.png"
}
```

### Scorch Onslaught

```json
{
  "ability_id": "121802",
  "slot": "skill",
  "name": "Scorch Onslaught",
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
    },
    "p3": {
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
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 49.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 58.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 67.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121.88,
          "unit": "percent"
        },
        "p2": {
          "value": 73.12,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 78.75,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 140.62,
          "unit": "percent"
        },
        "p2": {
          "value": 84.38,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 94.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
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
        },
        "p2": {
          "value": 99,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 172.5,
          "unit": "percent"
        },
        "p2": {
          "value": 103.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "4a375a214a3b6523f68a83687a28b683f83229705844ae6dbaba34b3de55278d",
  "icon_path": "icon/skill/1218_skill.png"
}
```

### Pyrograph Arcanum

```json
{
  "ability_id": "121803",
  "slot": "ult",
  "name": "Pyrograph Arcanum",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
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
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 9,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 51,
          "unit": "percent"
        },
        "p3": {
          "value": 9.6,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
          "unit": "percent"
        },
        "p3": {
          "value": 10.2,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 53,
          "unit": "percent"
        },
        "p3": {
          "value": 10.8,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 76,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 11.4,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 85,
          "unit": "percent"
        },
        "p2": {
          "value": 56.25,
          "unit": "percent"
        },
        "p3": {
          "value": 12.75,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 57.5,
          "unit": "percent"
        },
        "p3": {
          "value": 13.5,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 95,
          "unit": "percent"
        },
        "p2": {
          "value": 58.75,
          "unit": "percent"
        },
        "p3": {
          "value": 14.25,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 61,
          "unit": "percent"
        },
        "p3": {
          "value": 15.6,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 62,
          "unit": "percent"
        },
        "p3": {
          "value": 16.2,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 112,
          "unit": "percent"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 16.8,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 116,
          "unit": "percent"
        },
        "p2": {
          "value": 64,
          "unit": "percent"
        },
        "p3": {
          "value": 17.4,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f3f2d76ed022cc945f16c292581cc93f5bbd667a45e35d424f1677e2d312b9dc",
  "icon_path": "icon/skill/1218_ultimate.png"
}
```

### Quartet Finesse, Octave Finery

```json
{
  "ability_id": "121804",
  "slot": "talent",
  "name": "Quartet Finesse, Octave Finery",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
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
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p6": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "dot"
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
          "value": 7.5,
          "unit": "percent"
        },
        "p3": {
          "value": 2.5,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 8.25,
          "unit": "percent"
        },
        "p3": {
          "value": 2.75,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 99,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 9,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 9.75,
          "unit": "percent"
        },
        "p3": {
          "value": 3.25,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 117,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 10.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3.5,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 126,
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
        },
        "p2": {
          "value": 11.25,
          "unit": "percent"
        },
        "p3": {
          "value": 3.75,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 135,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 12.19,
          "unit": "percent"
        },
        "p3": {
          "value": 4.06,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 146.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 13.13,
          "unit": "percent"
        },
        "p3": {
          "value": 4.37,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 157.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 14.06,
          "unit": "percent"
        },
        "p3": {
          "value": 4.69,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 168.75,
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 5,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 15.75,
          "unit": "percent"
        },
        "p3": {
          "value": 5.25,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 189,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 16.5,
          "unit": "percent"
        },
        "p3": {
          "value": 5.5,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 198,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 17.25,
          "unit": "percent"
        },
        "p3": {
          "value": 5.75,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 207,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 6,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 216,
          "unit": "percent"
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
          "value": 18.75,
          "unit": "percent"
        },
        "p3": {
          "value": 6.25,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 225,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "810889e25a2817e8875c710966a99187c92c4a606048225678eabaa20004c9f5",
  "icon_path": "icon/skill/1218_talent.png"
}
```

### Fiery Queller

```json
{
  "ability_id": "121807",
  "slot": "technique",
  "name": "Fiery Queller",
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
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
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
          "value": 15,
          "unit": "scalar"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "56231097924b83017083d8488b87f3e45e4bc24b6ad2518737f5203b41daf329",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Pyre Cleanse",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15"
    ],
    "description_sha256": "68f543f2e0fa0259e5ec70f114a60beee26fb9b3a8d4a19d82c4b2333cab6356"
  },
  {
    "requirement": "A4",
    "name": "Hearth Kindle",
    "mechanic_tags": [
      "atk",
      "effect_hit_rate"
    ],
    "numeric_tokens": [
      "15%",
      "80%",
      "60%",
      "240%"
    ],
    "description_sha256": "cf50b48c988744be295d850cf053af01e0c496099acf2664cdd6fc1bacf40397"
  },
  {
    "requirement": "A6",
    "name": "Seared Scent",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "925d27331f8cfe7cca7107b3bc56f2c41e716fe851efd507d94f00d796b2c366"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Pentapathic Transference",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "40%",
      "1"
    ],
    "description_sha256": "e85f14a62ecc265b52c656ab839a4e89eeb63b514054239060b9397cfc3b8636"
  },
  {
    "eidolon": 2,
    "name": "From Savor Comes Suffer",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "300%"
    ],
    "description_sha256": "261384beec8d6bcbaafbaaa8fe112c6e430f808a1349cfa12ea19b5d6b3c81d6"
  },
  {
    "eidolon": 3,
    "name": "Flavored Euphony Reigns Supreme",
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
    "name": "Leisure In, Luster Out",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "c241ddf8cc82ac924717816cede35db08f10d044d69ad9d574b226ea41bb2902"
  },
  {
    "eidolon": 5,
    "name": "Duel in Dawn, Dash in Dusk",
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
    "name": "Nonamorphic Pyrobind",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "9",
      "3%"
    ],
    "description_sha256": "1d94c36a647d7d2f9ccefb828bf6a6469310712013949bad929eaeac38fea58f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
