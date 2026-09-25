---
schema_version: "1.0.0"
unit_id: 29
name: "Fu Xuan"
slug: "fu-xuan"
rarity: 5
element: "Quantum"
path: "Preservation"
role: "Support"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/fu-xuan"
source_record_updated_at: "March 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Fu Xuan

## Character record

```json
{
  "unit_id": 29,
  "name": "Fu Xuan",
  "slug": "fu-xuan",
  "rarity": "5",
  "element": "Quantum",
  "path": "Preservation",
  "default_role": "Support",
  "affiliation": "Xianzhou Luofu",
  "release_date": "September 20th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "135",
  "base_stats": {
    "hp_base": 200.64,
    "def_base": 82.5,
    "atk_base": 63.36,
    "speed_base": 100
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "effect_res",
      "value": 10
    },
    "traceStat2": {
      "stat": "critRate",
      "value": 18.7
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Sarah Wiedenheft",
    "kr": "이지현 (Lee Ji-hyeon)",
    "jpn": "伊藤美来 (Miku Itō)",
    "cn": "花玲 (Huā Líng)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/fu-xuan",
  "source_record_updated_at": "March 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120801` | Novaburst | Basic ATK | Single Target |
| `skill` | `120802` | Known by Stars, Shown by Hearts | Skill | Defense |
| `ult` | `120803` | Woes of Many Morphed to One | Ultimate | AoE |
| `talent` | `120804` | Bleak Breeds Bliss | Talent | Restore |
| `technique` | `120807` | Of Fortune Comes Fate | Technique | Defense |

## Ability records

### Novaburst

```json
{
  "ability_id": "120801",
  "slot": "basic",
  "name": "Novaburst",
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
  "description_sha256": "9af07774f0221b9814d1eb1610b6248b216cfe0e37544e85af276e6165eacc34",
  "icon_path": "icon/skill/1208_basic_atk.png"
}
```

### Known by Stars, Shown by Hearts

```json
{
  "ability_id": "120802",
  "slot": "skill",
  "name": "Known by Stars, Shown by Hearts",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Defence",
  "targeting_label": "Defense",
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
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "crit_rate",
    "dmg",
    "shield"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "percent"
        },
        "p5": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.3,
          "unit": "percent"
        },
        "p5": {
          "value": 6.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.6,
          "unit": "percent"
        },
        "p5": {
          "value": 7.2,
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 3.9,
          "unit": "percent"
        },
        "p5": {
          "value": 7.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.2,
          "unit": "percent"
        },
        "p5": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.5,
          "unit": "percent"
        },
        "p5": {
          "value": 9,
          "unit": "percent"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.88,
          "unit": "percent"
        },
        "p5": {
          "value": 9.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.25,
          "unit": "percent"
        },
        "p5": {
          "value": 10.5,
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
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.63,
          "unit": "percent"
        },
        "p5": {
          "value": 11.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "percent"
        },
        "p5": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 6.3,
          "unit": "percent"
        },
        "p5": {
          "value": 12.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 6.6,
          "unit": "percent"
        },
        "p5": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 6.9,
          "unit": "percent"
        },
        "p5": {
          "value": 13.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 7.2,
          "unit": "percent"
        },
        "p5": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 7.5,
          "unit": "percent"
        },
        "p5": {
          "value": 15,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a808aa51058d59160ad79e072a137190e12a776c91f6dbb80b80ea31ba7d8cd5",
  "icon_path": "icon/skill/1208_skill.png"
}
```

### Woes of Many Morphed to One

```json
{
  "ability_id": "120803",
  "slot": "ult",
  "name": "Woes of Many Morphed to One",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "135",
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 76,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 85,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 95,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 112,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 116,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a3b2ec2b528c79fd2250e841660336a0693c11ad995989fbe29582111f2ee52e",
  "icon_path": "icon/skill/1208_ultimate.png"
}
```

### Bleak Breeds Bliss

```json
{
  "ability_id": "120804",
  "slot": "talent",
  "name": "Bleak Breeds Bliss",
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 81,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 11.6,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 82,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 12.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 83,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 85,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 86.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 87.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 17,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 88.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 18.8,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 91,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 19.6,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 92,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 20.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 93,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 21.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 94,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 95,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "040e4d87655182153de5c7be8ad03b6606ad1dbc19d1c6b957c4d6930f58e071",
  "icon_path": "icon/skill/1208_talent.png"
}
```

### Of Fortune Comes Fate

```json
{
  "ability_id": "120807",
  "slot": "technique",
  "name": "Of Fortune Comes Fate",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Defence",
  "targeting_label": "Defense",
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
    },
    "p2": {
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
          "value": 20,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "4ea22e7c74c32e099e2cbf9c404b3cdfb93329438d5c415c953b3efd5a2f7df8",
  "icon_path": "icon/skill/1208_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Taiyi, the Macrocosmic",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "20"
    ],
    "description_sha256": "50e68203dd7579f59c1b2c1c06c29e3bd65224d1a634442b11247c039cbfcac9"
  },
  {
    "requirement": "A4",
    "name": "Dunjia, the Metamystic",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "5%",
      "133"
    ],
    "description_sha256": "2b1155897a7492fc872e738a305da65527c7e72e6e8842a05befa7ce3aaa0849"
  },
  {
    "requirement": "A6",
    "name": "Liuren, the Sexagenary",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [],
    "description_sha256": "30c054e77d14655a2f45944a8fc7651d1b108256194d97aa8b0c59f37ad741f1"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Dominus Pacis",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "f033871e230e0059f9781f28b0e1c866b34d3ecf28dc56a8212cff2989cc0df5"
  },
  {
    "eidolon": 2,
    "name": "Optimus Felix",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "70%",
      "1"
    ],
    "description_sha256": "7907183670902d9a8db6bfb7ea33564460e514a116269b3ab0eae2dc3b7b7988"
  },
  {
    "eidolon": 3,
    "name": "Apex Nexus",
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
    "name": "Fortuna Stellaris",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "d4538f16d5adbce03d1fed535f4477211edb4efe678cee3671bb536472664772"
  },
  {
    "eidolon": 5,
    "name": "Arbiter Primus",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "2ffb3c62aa12bac23b64d49468abd535ec168c317a13fea36f100d73f86a6708"
  },
  {
    "eidolon": 6,
    "name": "Omnia Vita",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "200%",
      "120%"
    ],
    "description_sha256": "9b0083b0763c144bf3c40a6e05f220118272792225ad6e571f979a5e8ae9554b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
