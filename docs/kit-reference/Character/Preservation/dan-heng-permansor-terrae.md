---
schema_version: "1.0.0"
unit_id: 82
name: "Dan Heng • Permansor Terrae"
slug: "dan-heng-permansor-terrae"
rarity: 5
element: "Physical"
path: "Preservation"
role: "Shielder"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/dan-heng-permansor-terrae"
source_record_updated_at: "November 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Dan Heng • Permansor Terrae

## Character record

```json
{
  "unit_id": 82,
  "name": "Dan Heng • Permansor Terrae",
  "slug": "dan-heng-permansor-terrae",
  "rarity": "5",
  "element": "Physical",
  "path": "Preservation",
  "default_role": "Shielder",
  "affiliation": null,
  "release_date": "October 15th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "135",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 105.6,
    "atk_base": 79.2,
    "speed_base": 97
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "speed",
      "value": 5
    },
    "traceStat3": {
      "stat": "def",
      "value": 22.5
    }
  },
  "voice_actors": {
    "en": "Nicholas Leung",
    "kr": "Kim Hye-sung (김혜성)",
    "jpn": "Kento Itō (伊東健人)",
    "cn": "Yú Dòng (魚凍)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/dan-heng-permansor-terrae",
  "source_record_updated_at": "November 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `141401` | Aegis Vitae | Basic ATK | Single Target |
| `skill` | `141402` | Terra Omnibus | Skill | Defense |
| `ult` | `141403` | A Dragon's Zenith Knows No Rue | Ultimate | AoE |
| `talent` | `141404` | Of Virtue, Forms Unfold | Talent | Defense |
| `technique` | `141407` | Earthrend | Technique | Impair |

## Ability records

### Aegis Vitae

```json
{
  "ability_id": "141401",
  "slot": "basic",
  "name": "Aegis Vitae",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "20",
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
  "description_sha256": "9eb1601504282539552c5e5f316d2cf374e0d8656d7c8c8d2ee8c88bbc757096",
  "icon_path": "icon/skill/1414_basic_atk.png"
}
```

### Terra Omnibus

```json
{
  "ability_id": "141402",
  "slot": "skill",
  "name": "Terra Omnibus",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Physical",
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
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "shield"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 14.75,
          "unit": "percent"
        },
        "p2": {
          "value": 160,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 15.5,
          "unit": "percent"
        },
        "p2": {
          "value": 205,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        },
        "p2": {
          "value": 250,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
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
          "value": 280,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 17.6,
          "unit": "percent"
        },
        "p2": {
          "value": 310,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 18.2,
          "unit": "percent"
        },
        "p2": {
          "value": 332.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 18.8,
          "unit": "percent"
        },
        "p2": {
          "value": 355,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 19.4,
          "unit": "percent"
        },
        "p2": {
          "value": 377.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
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
          "value": 400,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 20.6,
          "unit": "percent"
        },
        "p2": {
          "value": 422.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 21.2,
          "unit": "percent"
        },
        "p2": {
          "value": 445,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 21.8,
          "unit": "percent"
        },
        "p2": {
          "value": 467.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 22.4,
          "unit": "percent"
        },
        "p2": {
          "value": 490,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 23,
          "unit": "percent"
        },
        "p2": {
          "value": 512.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b997715c72276c1a168c38f5cbbc3379cb087dfeb0e89ffc5d4212fcd6e6e1f6",
  "icon_path": "icon/skill/1414_skill.png"
}
```

### A Dragon's Zenith Knows No Rue

```json
{
  "ability_id": "141403",
  "slot": "ult",
  "name": "A Dragon's Zenith Knows No Rue",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "135",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
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
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p7": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p8": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "shield",
    "follow_up"
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
          "value": 40,
          "unit": "percent"
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
          "value": 100,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 40,
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
          "value": 44,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 14.75,
          "unit": "percent"
        },
        "p5": {
          "value": 160,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 44,
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
          "value": 48,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 15.5,
          "unit": "percent"
        },
        "p5": {
          "value": 205,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 48,
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
          "value": 52,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 16.25,
          "unit": "percent"
        },
        "p5": {
          "value": 250,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 52,
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
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 17,
          "unit": "percent"
        },
        "p5": {
          "value": 280,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 56,
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 17.6,
          "unit": "percent"
        },
        "p5": {
          "value": 310,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 60,
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
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 18.2,
          "unit": "percent"
        },
        "p5": {
          "value": 332.5,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 65,
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
          "value": 70,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 18.8,
          "unit": "percent"
        },
        "p5": {
          "value": 355,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 70,
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
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 19.4,
          "unit": "percent"
        },
        "p5": {
          "value": 377.5,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 75,
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
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 400,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 80,
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
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 20.6,
          "unit": "percent"
        },
        "p5": {
          "value": 422.5,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 84,
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
          "value": 88,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.2,
          "unit": "percent"
        },
        "p5": {
          "value": 445,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 345,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.8,
          "unit": "percent"
        },
        "p5": {
          "value": 467.5,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 92,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 22.4,
          "unit": "percent"
        },
        "p5": {
          "value": 490,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 375,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 23,
          "unit": "percent"
        },
        "p5": {
          "value": 512.5,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        },
        "p7": {
          "value": 300,
          "unit": "percent"
        },
        "p8": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "25e787e8e2dee80eca9f76488cdd7f67f9902e282aeacbbc8f1fae3aa2520a4e",
  "icon_path": "icon/skill/1414_ultimate.png"
}
```

### Of Virtue, Forms Unfold

```json
{
  "ability_id": "141404",
  "slot": "talent",
  "name": "Of Virtue, Forms Unfold",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    },
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
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg",
    "shield",
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.38,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 7.75,
          "unit": "percent"
        },
        "p2": {
          "value": 102.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 8.13,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8.5,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 8.8,
          "unit": "percent"
        },
        "p2": {
          "value": 155,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 9.1,
          "unit": "percent"
        },
        "p2": {
          "value": 166.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 9.4,
          "unit": "percent"
        },
        "p2": {
          "value": 177.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.7,
          "unit": "percent"
        },
        "p2": {
          "value": 188.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.3,
          "unit": "percent"
        },
        "p2": {
          "value": 211.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 10.6,
          "unit": "percent"
        },
        "p2": {
          "value": 222.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 10.9,
          "unit": "percent"
        },
        "p2": {
          "value": 233.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 11.2,
          "unit": "percent"
        },
        "p2": {
          "value": 245,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "percent"
        },
        "p2": {
          "value": 256.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        },
        "p5": {
          "value": 165,
          "unit": "scalar"
        },
        "p6": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "ed5c1359256d7ea07cb2ae10ffa5ac9f42b46154ad200bb251af073af4a6d1ed",
  "icon_path": "icon/skill/1414_talent.png"
}
```

### Earthrend

```json
{
  "ability_id": "141407",
  "slot": "technique",
  "name": "Earthrend",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Physical",
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
    "skill_points"
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
  "description_sha256": "bbe5ceed492178f712918a5dcac08d73eb26ac5e38254234545acc848bff582b",
  "icon_path": "icon/skill/1414_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Empyreanity",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "435e27e608d87e2b312d6f0de46994fd2dfdb6d54b192cd67bf340320187f35f"
  },
  {
    "requirement": "A4",
    "name": "Sylvanity",
    "mechanic_tags": [
      "energy",
      "action_advance"
    ],
    "numeric_tokens": [
      "40%",
      "6",
      "15%"
    ],
    "description_sha256": "212e9e459183551933c1f4cea458a0f5a386c6568234eacd27098797a2c25023"
  },
  {
    "requirement": "A6",
    "name": "Sublimity",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "dmg",
      "shield"
    ],
    "numeric_tokens": [
      "5%",
      "100",
      "300%",
      "1",
      "40%"
    ],
    "description_sha256": "7ccec2e6f6aaad77d48a783073006c4bf04c366a4f69c460ba9d99ccb3e7b2f2"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Shed Scales of Old",
    "mechanic_tags": [
      "res_pen",
      "res",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "18%",
      "3"
    ],
    "description_sha256": "c1e545a9bab8805ba8fc3e34fe81434bc8ef22d3808d51c67699c708a170c100"
  },
  {
    "eidolon": 2,
    "name": "Watch Trails to Blaze",
    "mechanic_tags": [
      "dmg",
      "action_advance",
      "shield"
    ],
    "numeric_tokens": [
      "2",
      "100%",
      "200%",
      "200%"
    ],
    "description_sha256": "e6c79853c3b4697266d76880dfa86c18d619521fc7c7be7b9373b032040f0798"
  },
  {
    "eidolon": 3,
    "name": "Bear Weight of Worlds",
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
    "name": "By Oath, This Vessel Is I",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "296a149d42c20f8591921049eb9348dd7cfd826629ed289cf4adcd7ffeaa41fe"
  },
  {
    "eidolon": 5,
    "name": "The Path of Permanence Sweeps Far",
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
    "name": "One Dream to Enfold All Wilds",
    "mechanic_tags": [
      "atk",
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "12%",
      "330%"
    ],
    "description_sha256": "4a4939976ff9720eeb5a1e8ebff75abac0b88c29d84adb593d72d983e0d05fb4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
