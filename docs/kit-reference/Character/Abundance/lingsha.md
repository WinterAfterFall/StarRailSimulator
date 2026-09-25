---
schema_version: "1.0.0"
unit_id: 61
name: "Lingsha"
slug: "lingsha"
rarity: 5
element: "Fire"
path: "Abundance"
role: "Healer"
affiliation: "The Xianzhou Laofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/lingsha"
source_record_updated_at: "March 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Lingsha

## Character record

```json
{
  "unit_id": 61,
  "name": "Lingsha",
  "slug": "lingsha",
  "rarity": "5",
  "element": "Fire",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "The Xianzhou Laofu",
  "release_date": "October 2nd, 2024",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 184.8,
    "def_base": 59.4,
    "atk_base": 92.4,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Break Effect",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "hp",
      "value": 18
    },
    "traceStat3": {
      "stat": "atk",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Whitney Holland",
    "kr": "Jang Ye-na (장예나)",
    "jpn": "Maeda Kaori (前田佳織里)",
    "cn": "Rao Zijun (饶梓君)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/lingsha",
  "source_record_updated_at": "March 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122201` | Votive Incense | Basic ATK | Single Target |
| `skill` | `122202` | Smoke and Splendor | Skill | AoE |
| `ult` | `122203` | Dripping Mistscape | Ultimate | AoE |
| `talent` | `122204` | Mistdance Manifest | Talent | AoE |
| `technique` | `122207` | Wisps of Aurora | Technique | Support |

## Ability records

### Votive Incense

```json
{
  "ability_id": "122201",
  "slot": "basic",
  "name": "Votive Incense",
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
  "description_sha256": "e086f8f46a09bf37d93a92c2855b2d61d34aed116aed76e12749d022fff96663",
  "icon_path": "icon/skill/1222_basic_atk.png"
}
```

### Smoke and Splendor

```json
{
  "ability_id": "122202",
  "slot": "skill",
  "name": "Smoke and Splendor",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dmg",
    "action_advance",
    "healing"
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
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 105,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 10.5,
          "unit": "percent"
        },
        "p3": {
          "value": 168,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 11,
          "unit": "percent"
        },
        "p3": {
          "value": 215.25,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 11.5,
          "unit": "percent"
        },
        "p3": {
          "value": 262.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 294,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
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
          "value": 12.4,
          "unit": "percent"
        },
        "p3": {
          "value": 325.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
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
          "value": 12.8,
          "unit": "percent"
        },
        "p3": {
          "value": 349.125,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 13.2,
          "unit": "percent"
        },
        "p3": {
          "value": 372.75,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 13.6,
          "unit": "percent"
        },
        "p3": {
          "value": 396.375,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 420,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 14.4,
          "unit": "percent"
        },
        "p3": {
          "value": 443.625,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 14.8,
          "unit": "percent"
        },
        "p3": {
          "value": 467.25,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 15.2,
          "unit": "percent"
        },
        "p3": {
          "value": 490.875,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
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
          "value": 15.6,
          "unit": "percent"
        },
        "p3": {
          "value": 514.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
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
          "value": 16,
          "unit": "percent"
        },
        "p3": {
          "value": 538.125,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b4de41928779190a0effb64f529187e067be0726c056c8e988653f9f24a25c9b",
  "icon_path": "icon/skill/1222_skill.png"
}
```

### Dripping Mistscape

```json
{
  "ability_id": "122203",
  "slot": "ult",
  "name": "Dripping Mistscape",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
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
    },
    "p6": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dmg",
    "action_advance",
    "healing"
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
          "value": 8,
          "unit": "percent"
        },
        "p3": {
          "value": 90,
          "unit": "scalar"
        },
        "p4": {
          "value": 15,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 8.5,
          "unit": "percent"
        },
        "p3": {
          "value": 144,
          "unit": "scalar"
        },
        "p4": {
          "value": 16,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 9,
          "unit": "percent"
        },
        "p3": {
          "value": 184.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 17,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 9.5,
          "unit": "percent"
        },
        "p3": {
          "value": 225,
          "unit": "scalar"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 252,
          "unit": "scalar"
        },
        "p4": {
          "value": 19,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 10.4,
          "unit": "percent"
        },
        "p3": {
          "value": 279,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 10.8,
          "unit": "percent"
        },
        "p3": {
          "value": 299.25,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 11.2,
          "unit": "percent"
        },
        "p3": {
          "value": 319.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 22.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 11.6,
          "unit": "percent"
        },
        "p3": {
          "value": 339.75,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.75,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
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
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 360,
          "unit": "scalar"
        },
        "p4": {
          "value": 25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 12.4,
          "unit": "percent"
        },
        "p3": {
          "value": 380.25,
          "unit": "scalar"
        },
        "p4": {
          "value": 26,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 12.8,
          "unit": "percent"
        },
        "p3": {
          "value": 400.5,
          "unit": "scalar"
        },
        "p4": {
          "value": 27,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 13.2,
          "unit": "percent"
        },
        "p3": {
          "value": 420.75,
          "unit": "scalar"
        },
        "p4": {
          "value": 28,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 13.6,
          "unit": "percent"
        },
        "p3": {
          "value": 441,
          "unit": "scalar"
        },
        "p4": {
          "value": 29,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
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
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 461.25,
          "unit": "scalar"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7ec4ec7a6b163070b77149648e89f3989d8a0619542a70f5bc8818a210965171",
  "icon_path": "icon/skill/1222_ultimate.png"
}
```

### Mistdance Manifest

```json
{
  "ability_id": "122204",
  "slot": "talent",
  "name": "Mistdance Manifest",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p7": {
      "unit": "scalar",
      "occurrences": 2
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p8": {
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "scalar",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "spd",
    "dmg",
    "toughness",
    "healing",
    "follow_up",
    "debuff",
    "buff",
    "weakness",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 8,
          "unit": "percent"
        },
        "p4": {
          "value": 90,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 41.25,
          "unit": "percent"
        },
        "p3": {
          "value": 8.5,
          "unit": "percent"
        },
        "p4": {
          "value": 144,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
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
          "unit": "scalar"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 9,
          "unit": "percent"
        },
        "p4": {
          "value": 184.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 48.75,
          "unit": "percent"
        },
        "p3": {
          "value": 9.5,
          "unit": "percent"
        },
        "p4": {
          "value": 225,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 252,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 56.25,
          "unit": "percent"
        },
        "p3": {
          "value": 10.4,
          "unit": "percent"
        },
        "p4": {
          "value": 279,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 56.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 60.94,
          "unit": "percent"
        },
        "p3": {
          "value": 10.8,
          "unit": "percent"
        },
        "p4": {
          "value": 299.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 60.94,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 65.62,
          "unit": "percent"
        },
        "p3": {
          "value": 11.2,
          "unit": "percent"
        },
        "p4": {
          "value": 319.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 65.62,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 70.31,
          "unit": "percent"
        },
        "p3": {
          "value": 11.6,
          "unit": "percent"
        },
        "p4": {
          "value": 339.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 70.31,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 360,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 78.75,
          "unit": "percent"
        },
        "p3": {
          "value": 12.4,
          "unit": "percent"
        },
        "p4": {
          "value": 380.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 78.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 12.8,
          "unit": "percent"
        },
        "p4": {
          "value": 400.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 86.25,
          "unit": "percent"
        },
        "p3": {
          "value": 13.2,
          "unit": "percent"
        },
        "p4": {
          "value": 420.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 86.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 13.6,
          "unit": "percent"
        },
        "p4": {
          "value": 441,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "scalar"
        },
        "p2": {
          "value": 93.75,
          "unit": "percent"
        },
        "p3": {
          "value": 14,
          "unit": "percent"
        },
        "p4": {
          "value": 461.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        },
        "p7": {
          "value": 3,
          "unit": "scalar"
        },
        "p8": {
          "value": 93.75,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ece90540d87d5498bec349326475b3e092cb70c998ef3c4ff27aa36440c2f414",
  "icon_path": "icon/skill/1222_talent.png"
}
```

### Wisps of Aurora

```json
{
  "ability_id": "122207",
  "slot": "technique",
  "name": "Wisps of Aurora",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Fire",
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
    "dmg",
    "summon"
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
  "description_sha256": "01bc2769626b3a9756fb5b8dc2a9f2302fd82085fece582eb6458e37e3154d66",
  "icon_path": "icon/skill/1222_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Vermilion Waft",
    "mechanic_tags": [
      "atk",
      "break_effect",
      "healing"
    ],
    "numeric_tokens": [
      "25%",
      "10%",
      "50%",
      "20%"
    ],
    "description_sha256": "036f3d3c44db1670ffbd00bf72a77509a2a2cc90f9eb23b79831ebdf4341e735"
  },
  {
    "requirement": "A4",
    "name": "Sylvan Smoke",
    "mechanic_tags": [
      "atk",
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "9b20378ad54124c9167077ffa1722ffe04f4a747263f18cb2af574b775e8de49"
  },
  {
    "requirement": "A6",
    "name": "Ember's Echo",
    "mechanic_tags": [
      "max_hp",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "60%",
      "2"
    ],
    "description_sha256": "e4a073ae5640b646398dd586cf9b2ee94ff37d683c49f951a6fab8158c137052"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Bloom on Vileward Bouquet",
    "mechanic_tags": [
      "def",
      "weakness_break_efficiency",
      "weakness"
    ],
    "numeric_tokens": [
      "50%",
      "20%"
    ],
    "description_sha256": "2e6e2ad1a67f5d190fb7bbee5b8d86f37988a088ce7fa1eebe9759eeb64fd839"
  },
  {
    "eidolon": 2,
    "name": "Leisure in Carmine Smokeveil",
    "mechanic_tags": [
      "break_effect"
    ],
    "numeric_tokens": [
      "40%",
      "3"
    ],
    "description_sha256": "30faf58c56c54390c8d7b6875ab3853e2f00d8d24d012ee7bb4997833eafd762"
  },
  {
    "eidolon": 3,
    "name": "Shine of Floral Wick",
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
    "name": "Redolence from Canopied Banquet",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "healing"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "22b8778335e0090ff9e743e918ea6fd83e36c0f7372fc808095acaedd61b7e8e"
  },
  {
    "eidolon": 5,
    "name": "Poise Atop Twists and Turns",
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
    "name": "Arcadia Under Deep Seclusion",
    "mechanic_tags": [
      "atk",
      "res",
      "dmg",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "20%",
      "4",
      "50%",
      "5",
      "0"
    ],
    "description_sha256": "b0082aa8de9731172e16cc4f09bd5fd9bd1ab80c0e298fb1176a904a0aea41b0"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
