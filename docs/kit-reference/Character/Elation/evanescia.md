---
schema_version: "1.0.0"
unit_id: 89
name: "Evanescia"
slug: "evanescia"
rarity: 5
element: "Physical"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/evanescia"
source_record_updated_at: "May 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Evanescia

## Character record

```json
{
  "unit_id": 89,
  "name": "Evanescia",
  "slug": "evanescia",
  "rarity": "5",
  "element": "Physical",
  "path": "Elation",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "March 19th, 2026",
  "is_released": true,
  "ultimate_energy_cost": "480",
  "base_stats": {
    "hp_base": 143,
    "def_base": 62.7,
    "atk_base": 100.32,
    "speed_base": 104
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Elation",
      "value": 18
    },
    "traceStat2": {
      "stat": "speed",
      "value": 5
    },
    "traceStat3": {
      "stat": "critRate",
      "value": 18.7
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "",
    "jpn": "",
    "cn": ""
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/evanescia",
  "source_record_updated_at": "May 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150501` | Syllabus: Pop Quiz | Basic ATK | Single Target |
| `skill` | `150502` | Discipline: Final Verdict | Skill | Blast |
| `ult` | `150503` | Swordsong: Absolution Denied | Ultimate | AoE |
| `talent` | `150504` | Youth: Halcyon Evermore | Talent | Enhance |
| `technique` | `150507` | Petalfall: Floral Reminiscence | Technique | Enhance |
| `supplementary` | `150510` | I Said "Elation," Did I Stutter? | Elation Skill | AoE |

## Ability records

### Syllabus: Pop Quiz

```json
{
  "ability_id": "150501",
  "slot": "basic",
  "name": "Syllabus: Pop Quiz",
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
  "description_sha256": "fb5aed4d4d3263329c3bbc1d2c93e13a1aac1962fc7ff7c71817395834872639",
  "icon_path": null
}
```

### Discipline: Final Verdict

```json
{
  "ability_id": "150502",
  "slot": "skill",
  "name": "Discipline: Final Verdict",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
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
    "atk",
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
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
      "source_row": 2,
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
      "source_row": 3,
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
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 195,
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
          "value": 210,
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
          "value": 225,
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
          "value": 243.75,
          "unit": "percent"
        },
        "p2": {
          "value": 121.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 262.5,
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
          "value": 281.25,
          "unit": "percent"
        },
        "p2": {
          "value": 140.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 300,
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
          "value": 315,
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
          "value": 330,
          "unit": "percent"
        },
        "p2": {
          "value": 165,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "336b000a8b40cb6c0a814aaa4be08b3694b1df58447a74d75c343866df24146d",
  "icon_path": null
}
```

### Swordsong: Absolution Denied

```json
{
  "ability_id": "150503",
  "slot": "ult",
  "name": "Swordsong: Absolution Denied",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "480",
  "toughness_break_primary_source": "15",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 76.8,
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
        },
        "p2": {
          "value": 81.6,
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
          "value": 86.4,
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
        },
        "p2": {
          "value": 91.2,
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
          "value": 96,
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
        },
        "p2": {
          "value": 102,
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
        },
        "p2": {
          "value": 108,
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
        },
        "p2": {
          "value": 114,
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
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 124.8,
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
        },
        "p2": {
          "value": 129.6,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "99ef6ea16ee24b2ec6ecd6e0d551db4f02ced399f845e48065db8ab1f6c4c800",
  "icon_path": null
}
```

### Youth: Halcyon Evermore

```json
{
  "ability_id": "150504",
  "slot": "talent",
  "name": "Youth: Halcyon Evermore",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
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
    "atk",
    "crit_dmg",
    "energy",
    "energy_regen_rate",
    "dmg",
    "follow_up",
    "elation"
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
          "value": 8,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 14,
          "unit": "percent"
        },
        "p5": {
          "value": 12.5,
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
          "value": 8.8,
          "unit": "percent"
        },
        "p3": {
          "value": 13.2,
          "unit": "percent"
        },
        "p4": {
          "value": 15.4,
          "unit": "percent"
        },
        "p5": {
          "value": 13.75,
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
          "value": 9.6,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 16.8,
          "unit": "percent"
        },
        "p5": {
          "value": 15,
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
          "value": 10.4,
          "unit": "percent"
        },
        "p3": {
          "value": 15.6,
          "unit": "percent"
        },
        "p4": {
          "value": 18.2,
          "unit": "percent"
        },
        "p5": {
          "value": 16.25,
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
          "value": 11.2,
          "unit": "percent"
        },
        "p3": {
          "value": 16.8,
          "unit": "percent"
        },
        "p4": {
          "value": 19.6,
          "unit": "percent"
        },
        "p5": {
          "value": 17.5,
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
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 21,
          "unit": "percent"
        },
        "p5": {
          "value": 18.75,
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
          "value": 13,
          "unit": "percent"
        },
        "p3": {
          "value": 19.5,
          "unit": "percent"
        },
        "p4": {
          "value": 22.75,
          "unit": "percent"
        },
        "p5": {
          "value": 20.3125,
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
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 21,
          "unit": "percent"
        },
        "p4": {
          "value": 24.5,
          "unit": "percent"
        },
        "p5": {
          "value": 21.875,
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 22.5,
          "unit": "percent"
        },
        "p4": {
          "value": 26.25,
          "unit": "percent"
        },
        "p5": {
          "value": 23.4375,
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
          "value": 16,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 28,
          "unit": "percent"
        },
        "p5": {
          "value": 25,
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
          "value": 16.8,
          "unit": "percent"
        },
        "p3": {
          "value": 25.2,
          "unit": "percent"
        },
        "p4": {
          "value": 29.4,
          "unit": "percent"
        },
        "p5": {
          "value": 26.25,
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
          "value": 17.6,
          "unit": "percent"
        },
        "p3": {
          "value": 26.4,
          "unit": "percent"
        },
        "p4": {
          "value": 30.8,
          "unit": "percent"
        },
        "p5": {
          "value": 27.5,
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
          "value": 18.4,
          "unit": "percent"
        },
        "p3": {
          "value": 27.6,
          "unit": "percent"
        },
        "p4": {
          "value": 32.2,
          "unit": "percent"
        },
        "p5": {
          "value": 28.75,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9a45af2df895d9edca1beff22b0cab8266d2312fcfa3cfdc0eefb4bf007b44e0",
  "icon_path": null
}
```

### Petalfall: Floral Reminiscence

```json
{
  "ability_id": "150507",
  "slot": "technique",
  "name": "Petalfall: Floral Reminiscence",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "cea40409c571f37af85dc430455d7b09279b68f7df9455fbfd61e32ae92cc13b",
  "icon_path": null
}
```

### I Said "Elation," Did I Stutter?

```json
{
  "ability_id": "150510",
  "slot": "supplementary",
  "name": "I Said \"Elation,\" Did I Stutter?",
  "type_code": "Elation Skill",
  "type_label": "Elation Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 12,
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
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 60.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 71.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 89.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 96.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 103.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 115.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 121,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 126.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ca3a3d9b0d44178e32700b64c671f09504167c3e2fe01310a02d5a042039bf11",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Watch All Revels",
    "mechanic_tags": [
      "crit_rate",
      "elation"
    ],
    "numeric_tokens": [
      "30%",
      "3",
      "2",
      "1",
      "1",
      "2",
      "4",
      "50%"
    ],
    "description_sha256": "cdf34a8e4d6ecbb3fa4ee33a9302a7a8983a2bf5cc6c9d58c72d41ae476f9115"
  },
  {
    "requirement": "A4",
    "name": "Weigh All Truths",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "12%",
      "3"
    ],
    "description_sha256": "e211994940ec07ab2f683c0053a8f8bb0d8671b4f2b0e2e86012dd703bee45cc"
  },
  {
    "requirement": "A6",
    "name": "Best All Blooms",
    "mechanic_tags": [],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "0dc8ebadc5c1ea4c55d3c01a4f81e6a2dd00528793ea91ad98d80cc34355d9fa"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Home: A Prayer in Dance",
    "mechanic_tags": [
      "res_pen",
      "res",
      "elation"
    ],
    "numeric_tokens": [
      "20%",
      "1",
      "10"
    ],
    "description_sha256": "0a32f503dd7d0f0dd8ba564802d71b9b1e8d5b0baf3e943784a853e14f47d9b7"
  },
  {
    "eidolon": 2,
    "name": "Voyage: A Wish for Everbloom",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "36%",
      "50%",
      "100%"
    ],
    "description_sha256": "c0ae5f967f0b3e60d0818108f1964b1daf14f9f1f6bb1a9a5b0e38ec83a47779"
  },
  {
    "eidolon": 3,
    "name": "Blade: A Feast on Evils",
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
    "description_sha256": "739de4cd025749274ffd70e501e9900a51caa6e27396b57030ae434e5f1c181f"
  },
  {
    "eidolon": 4,
    "name": "Meadow: A Ruin by Vice",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "709c0d1401bebec6551d87a0784e8b69d6d7564522de24e3241c2ec13d3d84ac"
  },
  {
    "eidolon": 5,
    "name": "Arcadia: A Glimpse of Fates",
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
    "description_sha256": "4eff7a0b39dd1c4f26ebdffb9a77d1ce82e30a14dbe2c1d5b0a9c28a66c1cf9f"
  },
  {
    "eidolon": 6,
    "name": "Maiden: A Step into Dreams",
    "mechanic_tags": [
      "energy",
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "1",
      "15%",
      "100",
      "2%",
      "1000",
      "120",
      "1",
      "4"
    ],
    "description_sha256": "822615aaf10e6d82a097cc18399a30bd87b5f1c8e66a2a1be1450605f759932e"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
