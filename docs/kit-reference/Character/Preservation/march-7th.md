---
schema_version: "1.0.0"
unit_id: 3
name: "March 7th"
slug: "march-7th"
rarity: 4
element: "Ice"
path: "Preservation"
role: "Shielder"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/march-7th"
source_record_updated_at: "February 19th, 2025"
dataset_snapshot: "2026-05-30"
---

# March 7th

## Character record

```json
{
  "unit_id": 3,
  "name": "March 7th",
  "slug": "march-7th",
  "rarity": "4",
  "element": "Ice",
  "path": "Preservation",
  "default_role": "Shielder",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 144,
    "def_base": 78,
    "atk_base": 69.6,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Skyler Davenport",
    "kr": "Jung Hye-Won (정혜원)",
    "jpn": "Yui Ogura (小倉唯)",
    "cn": "Nuò Yǎ (诺亚)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/march-7th",
  "source_record_updated_at": "February 19th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100101` | Frigid Cold Arrow | Basic ATK | Single Target |
| `skill` | `100102` | The Power of Cuteness | Skill | Defense |
| `ult` | `100103` | Glacial Cascade | Ultimate | AoE |
| `talent` | `100104` | Girl Power | Talent | Single Target |
| `technique` | `100107` | Freezing Beauty | Technique | MazeAttack |

## Ability records

### Frigid Cold Arrow

```json
{
  "ability_id": "100101",
  "slot": "basic",
  "name": "Frigid Cold Arrow",
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
  "description_sha256": "afdee80d8c2e1792844f64ae1bb11051e720cd655524ee4bdcbc34332fd5740e",
  "icon_path": "icon/skill/1001_basic_atk.png"
}
```

### The Power of Cuteness

```json
{
  "ability_id": "100102",
  "slot": "skill",
  "name": "The Power of Cuteness",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Ice",
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
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "def",
    "dmg",
    "shield"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 38,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 190,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 40.38,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 304,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42.75,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 389.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 45.13,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 475,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 47.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 532,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 49.4,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 589,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 51.3,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 631.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 53.2,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 674.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 55.1,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 717.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 57,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 760,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 58.9,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 802.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 60.8,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 845.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 62.7,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 888.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 64.6,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 931,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 66.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 973.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "580c8c9fecaec3560ef9dd468a682d4db088748476ee23193f9ff51958c112b0",
  "icon_path": "icon/skill/1001_skill.png"
}
```

### Glacial Cascade

```json
{
  "ability_id": "100103",
  "slot": "ult",
  "name": "Glacial Cascade",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": "60",
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
    "atk",
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 30,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 33,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 36,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 39,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 42,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 45,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 48.75,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 52.5,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 56.25,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 60,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 63,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 66,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 69,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 72,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 75,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8fea6c3962a7987317406eb5431c6c212a5844a3077b9a9856f42553fa25dd9a",
  "icon_path": "icon/skill/1001_ultimate.png"
}
```

### Girl Power

```json
{
  "ability_id": "100104",
  "slot": "talent",
  "name": "Girl Power",
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f4db29b96b5ba244ed5621ebaa1610826ef25139ac816ca64182ce4f5f0c4080",
  "icon_path": "icon/skill/1001_talent.png"
}
```

### Freezing Beauty

```json
{
  "ability_id": "100107",
  "slot": "technique",
  "name": "Freezing Beauty",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "770a3b29730a8e45fffe7f5e26c437491fb2e2d9a756535ca426b47c11ac4ab5",
  "icon_path": "icon/skill/1001_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Purify",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "aa2db8794b1124e4d57fe5c1ff07f3dba597672b1c0bc175734902b048c8e069"
  },
  {
    "requirement": "A4",
    "name": "Reinforce",
    "mechanic_tags": [
      "shield"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "ffbd24fff2ed340de42b54a4af576925fc43c5fd7c7d69b3945bed172b9bee57"
  },
  {
    "requirement": "A6",
    "name": "Ice Spell",
    "mechanic_tags": [],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "d4c50c9738cc59f30e54ce224d4f5cc2a2dd190c3f993f5f96c1b0a7935d6c2e"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Memory of You",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "7",
      "6"
    ],
    "description_sha256": "be3c90cdda211bc1771cfc25bec2204b59f6929b42bf8d65cb8547230bd5dcb1"
  },
  {
    "eidolon": 2,
    "name": "Memory of It ",
    "mechanic_tags": [
      "max_hp",
      "def",
      "shield"
    ],
    "numeric_tokens": [
      "24%",
      "7",
      "320",
      "3"
    ],
    "description_sha256": "1a5acb4130cdcb15360fef3adef526f1147ec26348aae8511cfed0a8e23276a4"
  },
  {
    "eidolon": 3,
    "name": "Memory of Everything",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "ef41c0ce13bfa86071ef69fe2f437f6e8c5c3a055a9891381b35b408b406063e"
  },
  {
    "eidolon": 4,
    "name": "Never Forfeit Again",
    "mechanic_tags": [
      "def",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "1",
      "30%",
      "7"
    ],
    "description_sha256": "904cb78addb31e4cbb4bd41d50f851ba8173d7b4b4e8a9672001c4de3138a33c"
  },
  {
    "eidolon": 5,
    "name": "Never Forget Again",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "2",
      "15"
    ],
    "description_sha256": "44510026b640c061e66a47941f11c1c4630d9468a08550a63ed1ea32fdb09b0c"
  },
  {
    "eidolon": 6,
    "name": "Just Like This, Always...",
    "mechanic_tags": [
      "max_hp",
      "healing",
      "shield"
    ],
    "numeric_tokens": [
      "4%",
      "106"
    ],
    "description_sha256": "6b90226a66dcfe0ba34d2822773a2ff90898a905210b2f0bfcaa58dc9dbec88e"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
