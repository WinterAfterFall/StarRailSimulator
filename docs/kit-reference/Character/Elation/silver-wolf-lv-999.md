---
schema_version: "1.0.0"
unit_id: 88
name: "Silver Wolf • Lv. 999"
slug: "silver-wolf-lv-999"
rarity: 5
element: "Imaginary"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/silver-wolf-lv-999"
source_record_updated_at: "May 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Silver Wolf • Lv. 999

## Character record

```json
{
  "unit_id": 88,
  "name": "Silver Wolf • Lv. 999",
  "slug": "silver-wolf-lv-999",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Elation",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "April 22nd, 2026",
  "is_released": true,
  "ultimate_energy_cost": null,
  "base_stats": {
    "hp_base": 143,
    "def_base": 89.1,
    "atk_base": 52.8,
    "speed_base": 110
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Elation",
      "value": 10
    },
    "traceStat2": {
      "stat": "speed",
      "value": 9
    },
    "traceStat3": {
      "stat": "critRate",
      "value": 18.7
    }
  },
  "voice_actors": {
    "en": "Melissa Fahn",
    "kr": "장미",
    "jpn": "Asumi Kana (阿澄佳奈)",
    "cn": "Hanser"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/silver-wolf-lv-999",
  "source_record_updated_at": "May 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150601` | One Punch! | Basic ATK | Single Target |
| `basic_enh` | `150608` | Bonus Stage: αWolf Instant | Basic ATK | Bounce |
| `skill` | `150602` | Trigger Happy | Skill | AoE |
| `ult` | `150603` | God Mode: ON! | Ultimate | Enhance |
| `talent` | `150604` | I Carry, We Win | Talent | Enhance |
| `technique` | `150607` | This? Absolute Meta! | Technique | Impair |
| `supplementary` | `150610` | Honkai-DMG Demo | Elation Skill | AoE |
| `supplementary` | `150611` | McAwolfee 999 | Unique | Unique |

## Ability records

### One Punch!

```json
{
  "ability_id": "150601",
  "slot": "basic",
  "name": "One Punch!",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 10,
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
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "4973732010b1d47f06992331ce068bcf4b6d9f7c104cda5db0d5d35de78d5133",
  "icon_path": null
}
```

### Bonus Stage: αWolf Instant

```json
{
  "ability_id": "150608",
  "slot": "basic_enh",
  "name": "Bonus Stage: αWolf Instant",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 10,
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
    "buff",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "74e64adbcdad669532bbad267614d38492ce55468e900bd2edebf65625bf3a59",
  "icon_path": null
}
```

### Trigger Happy

```json
{
  "ability_id": "150602",
  "slot": "skill",
  "name": "Trigger Happy",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Imaginary",
  "energy_gain": null,
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
    "atk",
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 96,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 112,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 176,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 184,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7cc97e8fdbf4c9fe59eeb21be47c07d62abd673cff261ff77d240aac1c61a81a",
  "icon_path": null
}
```

### God Mode: ON!

```json
{
  "ability_id": "150603",
  "slot": "ult",
  "name": "God Mode: ON!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg",
    "action_advance",
    "skill_points",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 49.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 73.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 78.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 84.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 94.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 103.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "86d2b2becd34161eeaf8ea07a3f13e9595108a7ff9db810b694d76b07fc1a077",
  "icon_path": null
}
```

### I Carry, We Win

```json
{
  "ability_id": "150604",
  "slot": "talent",
  "name": "I Carry, We Win",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
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
    "debuff",
    "buff",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.2,
          "unit": "percent"
        },
        "p2": {
          "value": 0.4,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 0.22,
          "unit": "percent"
        },
        "p2": {
          "value": 0.44,
          "unit": "percent"
        },
        "p3": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 0.24,
          "unit": "percent"
        },
        "p2": {
          "value": 0.48,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 0.26,
          "unit": "percent"
        },
        "p2": {
          "value": 0.52,
          "unit": "percent"
        },
        "p3": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 0.28,
          "unit": "percent"
        },
        "p2": {
          "value": 0.56,
          "unit": "percent"
        },
        "p3": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 0.3,
          "unit": "percent"
        },
        "p2": {
          "value": 0.6,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 0.325,
          "unit": "percent"
        },
        "p2": {
          "value": 0.65,
          "unit": "percent"
        },
        "p3": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 0.35,
          "unit": "percent"
        },
        "p2": {
          "value": 0.7,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 0.375,
          "unit": "percent"
        },
        "p2": {
          "value": 0.75,
          "unit": "percent"
        },
        "p3": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 0.4,
          "unit": "percent"
        },
        "p2": {
          "value": 0.8,
          "unit": "percent"
        },
        "p3": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 0.42,
          "unit": "percent"
        },
        "p2": {
          "value": 0.84,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 0.44,
          "unit": "percent"
        },
        "p2": {
          "value": 0.88,
          "unit": "percent"
        },
        "p3": {
          "value": 44,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6371d441e4dec5eec28fc7592348245d162a23e0434bdf4656178728ae6967db",
  "icon_path": null
}
```

### This? Absolute Meta!

```json
{
  "ability_id": "150607",
  "slot": "technique",
  "name": "This? Absolute Meta!",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dmg",
    "summon",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8448d4161eb4761aa3f208d82f837b4d52f65f6f404a65ba6cb97e99d6913bb1",
  "icon_path": null
}
```

### Honkai-DMG Demo

```json
{
  "ability_id": "150610",
  "slot": "supplementary",
  "name": "Honkai-DMG Demo",
  "type_code": "BPSkill",
  "type_label": "Elation Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
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
    }
  },
  "mechanic_tags": [
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 49.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 73.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 78.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 84.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 94.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 103.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "191902b588b4733bd9c0fd15527f586160700dfa9aac3b8ad02d65dfb1b9653e",
  "icon_path": null
}
```

### McAwolfee 999

```json
{
  "ability_id": "150611",
  "slot": "supplementary",
  "name": "McAwolfee 999",
  "type_code": "Unique",
  "type_label": "Unique",
  "effect_code": "Unique",
  "targeting_label": "Unique",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
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
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "4e3fbac3f281ee447125b36dd013546d5388fac7aaeea53ed4804dfdda4c0e64",
  "icon_path": "icon/skill/1407_basic_atk.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "False Ending Speedrun",
    "mechanic_tags": [
      "spd",
      "elation"
    ],
    "numeric_tokens": [
      "160",
      "50%",
      "1",
      "2%",
      "100"
    ],
    "description_sha256": "e1cb60f8b2b777e2ca01958b6e149cb8a290b63254d37ba04443a88045643db0"
  },
  {
    "requirement": "A4",
    "name": "True Ending Unlocked",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "20",
      "20",
      "40",
      "20"
    ],
    "description_sha256": "60db4ee53c361834361b51cf8ada4b4374aad2898ccbf331a3bb109de7be3ff9"
  },
  {
    "requirement": "A6",
    "name": "Secret Level Maxed",
    "mechanic_tags": [],
    "numeric_tokens": [
      "20"
    ],
    "description_sha256": "89f990d1561323d6ef158bea5448160f36bb448791fcd1acd2777447bc54f593"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Aether Editing: Eidolon +1",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "20%"
    ],
    "description_sha256": "07ab8d8666214917a528b82aa2c47c6766e389dd24d7b29bd951ad201d900f8a"
  },
  {
    "eidolon": 2,
    "name": "It's a Feature, Not a Bug",
    "mechanic_tags": [
      "atk",
      "buff"
    ],
    "numeric_tokens": [
      "1",
      "120",
      "999",
      "1",
      "1"
    ],
    "description_sha256": "3f382f56fd9f50db1bab292394abe11db13199bd27f5722d6815d159ab49d837"
  },
  {
    "eidolon": 3,
    "name": "Max Lv. 15? Says who?",
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "15"
    ],
    "description_sha256": "620842faaf202acd4da4712f3949a4fe619c03e84523166773a2b56c797aad5f"
  },
  {
    "eidolon": 4,
    "name": "I Came. I Saw. I One‑Shot.",
    "mechanic_tags": [
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "dc5d7ded3436a6b79aa4ee685c88d9e7b83728d1a07d0ca83b0bd224247cadd4"
  },
  {
    "eidolon": 5,
    "name": "Basic ATK Is the New Ultimate",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "15"
    ],
    "description_sha256": "986fac450a960dd679455251c1caba553f7294fce93fd4fb862a66d22b5014d7"
  },
  {
    "eidolon": 6,
    "name": "Solo Maxxing!",
    "mechanic_tags": [
      "atk",
      "res",
      "dmg",
      "weakness",
      "elation"
    ],
    "numeric_tokens": [
      "50%",
      "0",
      "0",
      "20%"
    ],
    "description_sha256": "fa542b91e78c044592e526557bb581fa344fdc94332b851fd75894f7c796cd81"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
