---
schema_version: "1.0.0"
unit_id: 36
name: "Jingliu"
slug: "jingliu"
rarity: 5
element: "Ice"
path: "Destruction"
role: "Main DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/jingliu"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Jingliu

## Character record

```json
{
  "unit_id": 36,
  "name": "Jingliu",
  "slug": "jingliu",
  "rarity": "5",
  "element": "Ice",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "October 11th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 195.36,
    "def_base": 66,
    "atk_base": 92.4,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "critDmg",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "speed",
      "value": 9
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "AmaLee",
    "kr": "박이서 (Park Yi-seo)",
    "jpn": "桑岛法子 (Houko Kuwashima)",
    "cn": "杜冥鸦 (Du Mingya)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/jingliu",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121201` | Lucent Moonglow | Basic ATK | Single Target |
| `skill` | `121202` | Transcendent Flash | Skill | Single Target |
| `skill_enh` | `121209` | Moon On Glacial River | Skill | Blast |
| `ult` | `121203` | Florephemeral Dreamflux | Ultimate | Blast |
| `talent` | `121204` | Crescent Transmigration | Talent | Enhance |
| `technique` | `121207` | Shine of Truth | Technique | Impair |

## Ability records

### Lucent Moonglow

```json
{
  "ability_id": "121201",
  "slot": "basic",
  "name": "Lucent Moonglow",
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
  "description_sha256": "0425c43efd290083eb4f86813a10806016f40cd7073de58f167920a315fff2fe",
  "icon_path": "icon/skill/1212_basic_atk.png"
}
```

### Transcendent Flash

```json
{
  "ability_id": "121202",
  "slot": "skill",
  "name": "Transcendent Flash",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
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
          "value": 0.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 0.825,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 0.9,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 0.975,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1.05,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1.125,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1.21875,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1.3125,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1.40625,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1.575,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1.65,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 1.725,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 1.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 1.875,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "bf486034738ed046d1bc1da28e1dbfbe983047266b457c087828883c5a0aee77",
  "icon_path": "icon/skill/1212_skill.png"
}
```

### Moon On Glacial River

```json
{
  "ability_id": "121209",
  "slot": "skill_enh",
  "name": "Moon On Glacial River",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Ice",
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
    "max_hp",
    "dmg",
    "skill_points"
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
          "value": 37.5,
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
          "value": 41.25,
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
          "value": 45,
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
          "value": 48.75,
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
          "value": 52.5,
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
          "value": 56.25,
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
        },
        "p2": {
          "value": 60.9375,
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
          "value": 65.625,
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
        },
        "p2": {
          "value": 70.3125,
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
          "value": 75,
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
          "value": 78.75,
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
          "value": 82.5,
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
          "value": 86.25,
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
          "value": 90,
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
          "value": 93.75,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "629f4e43870e9534f4b0a879cf70b8410f6a5c25e611146e6ff5a44c03d9e50c",
  "icon_path": "icon/skill/1212_skill.png"
}
```

### Florephemeral Dreamflux

```json
{
  "ability_id": "121203",
  "slot": "ult",
  "name": "Florephemeral Dreamflux",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
          "value": 45,
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
          "value": 49.5,
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
          "value": 54,
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
          "value": 58.5,
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
          "value": 63,
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
          "value": 67.5,
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
          "value": 73.125,
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
          "value": 78.75,
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
          "value": 84.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 189,
          "unit": "percent"
        },
        "p2": {
          "value": 94.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 198,
          "unit": "percent"
        },
        "p2": {
          "value": 99,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 207,
          "unit": "percent"
        },
        "p2": {
          "value": 103.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6a3ec263d2bbc9df17b2287c79c4040a41dc7a1fb0acf8553a13cc28537b7409",
  "icon_path": "icon/skill/1212_ultimate.png"
}
```

### Crescent Transmigration

```json
{
  "ability_id": "121204",
  "slot": "talent",
  "name": "Crescent Transmigration",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "atk",
    "crit_rate",
    "crit_dmg",
    "dmg",
    "action_advance"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 22,
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
          "value": 24.2,
          "unit": "percent"
        },
        "p2": {
          "value": 41,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 28.6,
          "unit": "percent"
        },
        "p2": {
          "value": 43,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 30.8,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 35.75,
          "unit": "percent"
        },
        "p2": {
          "value": 46.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 38.5,
          "unit": "percent"
        },
        "p2": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 41.25,
          "unit": "percent"
        },
        "p2": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 46.2,
          "unit": "percent"
        },
        "p2": {
          "value": 51,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 48.4,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 50.6,
          "unit": "percent"
        },
        "p2": {
          "value": 53,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 52.8,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
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
          "value": 55,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "945df0398838ed17a38d131cff5f315a059484f24d47fa030b9714ec307fe050",
  "icon_path": "icon/skill/1212_talent.png"
}
```

### Shine of Truth

```json
{
  "ability_id": "121207",
  "slot": "technique",
  "name": "Shine of Truth",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "energy",
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "scalar"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
        },
        "p5": {
          "value": 80,
          "unit": "percent"
        },
        "p6": {
          "value": 15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "a61ab098c13cdb51bea49a66fffc5f443d669bc2452d1e15b378fc1bb15737da",
  "icon_path": "icon/skill/1212_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Deathrealm",
    "mechanic_tags": [
      "effect_res",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "35%",
      "20%"
    ],
    "description_sha256": "cdf912290b58289fc67f7bf7f150143089df8b0ae70b54e022cf9dfda9748a7d"
  },
  {
    "requirement": "A4",
    "name": "Sword Champion",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15",
      "8"
    ],
    "description_sha256": "2b28365e2480a5eca715a75679b6abc95800f1ac8e852c1b9ce0e99bb486593f"
  },
  {
    "requirement": "A6",
    "name": "Frost Wraith",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "a841f7420fab4556aa276ae7f6a824e9c1c57a82f78e34835fdf49958333c0af"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Moon Crashes Tianguan Gate",
    "mechanic_tags": [
      "max_hp",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "36%",
      "1",
      "1",
      "80%"
    ],
    "description_sha256": "547c65085530d3ef2260ae4964fd72cb8910b9c2e219a789a0f807406cb9fade"
  },
  {
    "eidolon": 2,
    "name": "Crescent Shadows Qixing Dipper",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "80%"
    ],
    "description_sha256": "5789f90859b95a5482d690eef6c3b92a84d738c24695acfb27ce90f8ac1f430e"
  },
  {
    "eidolon": 3,
    "name": "Halfmoon Gapes Mercurial Haze",
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
    "name": "Lunarlance Shines Skyward Dome",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "b90362892019d5ef4f4e46054f42686ec3a2564f858c558ec9ed3ec9c0d06731"
  },
  {
    "eidolon": 5,
    "name": "Night Shades Astral Radiance",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "99d2bd43b5afbf74795646f302ddc66c8d3f0d597268d24ae761e8fb7ca77684"
  },
  {
    "eidolon": 6,
    "name": "Eclipse Hollows Corporeal Husk",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "30%"
    ],
    "description_sha256": "5bf2870b204f7d7ba7bfc0106ca37fb6be83d9fce4d60406fd77e1e781290ea4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
