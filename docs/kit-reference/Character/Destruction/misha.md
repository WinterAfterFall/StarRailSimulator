---
schema_version: "1.0.0"
unit_id: 48
name: "Misha"
slug: "misha"
rarity: 4
element: "Ice"
path: "Destruction"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/misha"
source_record_updated_at: "December 3rd, 2024"
dataset_snapshot: "2026-05-30"
---

# Misha

## Character record

```json
{
  "unit_id": 48,
  "name": "Misha",
  "slug": "misha",
  "rarity": "4",
  "element": "Ice",
  "path": "Destruction",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "February 6th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 172.8,
    "def_base": 54,
    "atk_base": 81.6,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat2": {
      "stat": "Ice DMG",
      "value": 22.4
    },
    "traceStat3": {
      "stat": "CRIT Rate",
      "value": 6.7
    }
  },
  "voice_actors": {
    "en": "Cat Protano",
    "kr": "박신희 (Park Shin-hee)",
    "jpn": "松井惠理子 (Matsui Eriko)",
    "cn": "柳知萧 (Liu Zhixiao)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/misha",
  "source_record_updated_at": "December 3rd, 2024"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `131201` | E—Excuse Me, Please! | Basic ATK | Single Target |
| `skill` | `131202` | R—Room Service | Skill | Blast |
| `ult` | `131203` | G—Gonna Be Late! | Ultimate | Bounce |
| `talent` | `131204` | Horological Escapement | Talent | Enhance |
| `technique` | `131207` | Wait, You Are So Beautiful! | Technique | Impair |

## Ability records

### E—Excuse Me, Please!

```json
{
  "ability_id": "131201",
  "slot": "basic",
  "name": "E—Excuse Me, Please!",
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
  "description_sha256": "51a99e2a5e5a729a261d3275ac187d776eb8ace917dc2edb0daec79248e48844",
  "icon_path": "icon/skill/1312_basic_atk.png"
}
```

### R—Room Service

```json
{
  "ability_id": "131202",
  "slot": "skill",
  "name": "R—Room Service",
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
    "p3": {
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
          "value": 40,
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
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
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
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
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
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
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
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
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
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
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
          "value": 162.5,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
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
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
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
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
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
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
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
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
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
          "value": 220,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
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
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
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
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
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
          "value": 250,
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
  "description_sha256": "281e560d5e399cd6dae6b8b72c8993e985518429ee17ae88bb37f975bf88eb76",
  "icon_path": "icon/skill/1312_skill.png"
}
```

### G—Gonna Be Late!

```json
{
  "ability_id": "131203",
  "slot": "ult",
  "name": "G—Gonna Be Late!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 2
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
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 38.4,
          "unit": "percent"
        },
        "p3": {
          "value": 12.8,
          "unit": "percent"
        },
        "p4": {
          "value": 19.2,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 40.8,
          "unit": "percent"
        },
        "p3": {
          "value": 13.6,
          "unit": "percent"
        },
        "p4": {
          "value": 20.4,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 21.6,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 45.6,
          "unit": "percent"
        },
        "p3": {
          "value": 15.2,
          "unit": "percent"
        },
        "p4": {
          "value": 22.8,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 24,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 51,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
          "unit": "percent"
        },
        "p4": {
          "value": 25.5,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 27,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 57,
          "unit": "percent"
        },
        "p3": {
          "value": 19,
          "unit": "percent"
        },
        "p4": {
          "value": 28.5,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 62.4,
          "unit": "percent"
        },
        "p3": {
          "value": 20.8,
          "unit": "percent"
        },
        "p4": {
          "value": 31.2,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 64.8,
          "unit": "percent"
        },
        "p3": {
          "value": 21.6,
          "unit": "percent"
        },
        "p4": {
          "value": 32.4,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 67.2,
          "unit": "percent"
        },
        "p3": {
          "value": 22.4,
          "unit": "percent"
        },
        "p4": {
          "value": 33.6,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 69.6,
          "unit": "percent"
        },
        "p3": {
          "value": 23.2,
          "unit": "percent"
        },
        "p4": {
          "value": 34.8,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 36,
          "unit": "percent"
        },
        "p5": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3c59aff720d8ef3f6f3e87b1549d83f2fdf54bcf54596fb90210b3f3927a1011",
  "icon_path": "icon/skill/1312_ultimate.png"
}
```

### Horological Escapement

```json
{
  "ability_id": "131204",
  "slot": "talent",
  "name": "Horological Escapement",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "skill_points"
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
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1.1,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1.2,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1.3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1.4,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1.5,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1.625,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1.75,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1.875,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
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
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 2.1,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 2.2,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 2.3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 2.4,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 2.5,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "6012dfd3231ea289cbdadf160574db7402b1ff27359120497882593119a14abf",
  "icon_path": "icon/skill/1312_talent.png"
}
```

### Wait, You Are So Beautiful!

```json
{
  "ability_id": "131207",
  "slot": "technique",
  "name": "Wait, You Are So Beautiful!",
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
          "value": 15,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "5693ce61b33132d46b41cab374b03a7ec7e3cadc37f8a63fcbd3ebcd7987216d",
  "icon_path": "icon/skill/1312_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Release",
    "mechanic_tags": [],
    "numeric_tokens": [
      "80%"
    ],
    "description_sha256": "8bc12ee48ff7d94a6df448e3e2e89a0d1dd083bf704edc9c5ae14500aeda8154"
  },
  {
    "requirement": "A4",
    "name": "Interlock",
    "mechanic_tags": [
      "effect_hit_rate"
    ],
    "numeric_tokens": [
      "60%"
    ],
    "description_sha256": "92f406fb8958e61d54656f9506d7adc36c10211a067702cd562f7a689f287369"
  },
  {
    "requirement": "A6",
    "name": "Transmission",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "2e90703d63b058e871db2ea74860bc3a1301ab6bb9a5e4cd4cfe8eeadcf644dc"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Whimsicality of Fancy",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "5"
    ],
    "description_sha256": "ea1937757ae3f6c9b4979a3f5bb77bfdaba0cb5f8ed96b9ac1b187ad733dbc42"
  },
  {
    "eidolon": 2,
    "name": "Yearning of Youth",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "24%",
      "16%",
      "3"
    ],
    "description_sha256": "c8266d1c5adede9ee796849ff524bfa630916b01120db858c6193337bfcdee7c"
  },
  {
    "eidolon": 3,
    "name": "Vestige of Happiness",
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
    "eidolon": 4,
    "name": "Visage of Kinship",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "6%"
    ],
    "description_sha256": "a937d58d735c5ddd7be92a94f9f1d2736c299d3d39eaab95b0c59b103a0e9b44"
  },
  {
    "eidolon": 5,
    "name": "Genesis of First Love",
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
    "eidolon": 6,
    "name": "Estrangement of Dream",
    "mechanic_tags": [
      "dmg",
      "skill_points"
    ],
    "numeric_tokens": [
      "30%",
      "1"
    ],
    "description_sha256": "9fab3818aedb5fbc143599eaf4e2ba09762ee883ebe24441977a64cf50db85df"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
