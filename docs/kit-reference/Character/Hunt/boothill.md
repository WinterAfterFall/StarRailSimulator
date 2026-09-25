---
schema_version: "1.0.0"
unit_id: 53
name: "Boothill"
slug: "boothill"
rarity: 5
element: "Physical"
path: "Hunt"
role: "Main DPS"
affiliation: "Galaxy Rangers"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/boothill"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Boothill

## Character record

```json
{
  "unit_id": 53,
  "name": "Boothill",
  "slug": "boothill",
  "rarity": "5",
  "element": "Physical",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "Galaxy Rangers",
  "release_date": "May 29th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "115",
  "base_stats": {
    "hp_base": 163.68,
    "def_base": 59.4,
    "atk_base": 84.48,
    "speed_base": 107
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Break Effect",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Andrew Russell",
    "kr": "김단 (Kim Dan)",
    "jpn": "小西克幸 (Konishi Katsuyuki)",
    "cn": "彭博 (Peng Bo)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/boothill",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `131501` | Skullcrush Spurs | Basic ATK | Single Target |
| `basic_enh` | `131508` | Fanning the Hammer | Basic ATK | Single Target |
| `skill` | `131502` | Sizzlin' Tango | Skill | Impair |
| `ult` | `131503` | Dust Devil's Sunset Rodeo | Ultimate | Single Target |
| `talent` | `131504` | Five Peas in a Pod | Talent | Enhance |
| `technique` | `131507` | 3-9× Smile | Technique | Enhance |

## Ability records

### Skullcrush Spurs

```json
{
  "ability_id": "131501",
  "slot": "basic",
  "name": "Skullcrush Spurs",
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
  "description_sha256": "78379723960eac7f3702c492e5376f7f73d542ce899df7f1aaf83ddfb6370106",
  "icon_path": "icon/skill/1315_basic_atk.png"
}
```

### Fanning the Hammer

```json
{
  "ability_id": "131508",
  "slot": "basic_enh",
  "name": "Fanning the Hammer",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
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
    "dmg",
    "skill_points"
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
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 176,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 198,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 242,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 286,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "3691caaf0b95c875c1d02834b761a76b17d113ad9ddb462919d4acf75804d3df",
  "icon_path": "icon/skill/1315_basic_atk.png"
}
```

### Sizzlin' Tango

```json
{
  "ability_id": "131502",
  "slot": "skill",
  "name": "Sizzlin' Tango",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
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
    "energy",
    "dmg",
    "weakness"
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
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.37,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 26.25,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.12,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 34.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "2693f7c6481c8459310102e374654a20a9c4762e9b3b526f3013bcfa69582840",
  "icon_path": "icon/skill/1315_skill.png"
}
```

### Dust Devil's Sunset Rodeo

```json
{
  "ability_id": "131503",
  "slot": "ult",
  "name": "Dust Devil's Sunset Rodeo",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "115",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
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
    "dmg",
    "action_delay",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 240,
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
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 256,
          "unit": "percent"
        },
        "p2": {
          "value": 31,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 272,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 320,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 340,
          "unit": "percent"
        },
        "p2": {
          "value": 36.25,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 38.75,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 400,
          "unit": "percent"
        },
        "p2": {
          "value": 40,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 416,
          "unit": "percent"
        },
        "p2": {
          "value": 41,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 432,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 448,
          "unit": "percent"
        },
        "p2": {
          "value": 43,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 464,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "18415407b35411844d0df24f2ce3e3e5df31df06bdc85533b1c373b4f83935c4",
  "icon_path": "icon/skill/1315_ultimate.png"
}
```

### Five Peas in a Pod

```json
{
  "ability_id": "131504",
  "slot": "talent",
  "name": "Five Peas in a Pod",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
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
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "toughness",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 85,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 38.5,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 93.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 102,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 45.5,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        },
        "p3": {
          "value": 110.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 49,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 119,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 127.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 56.87,
          "unit": "percent"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        },
        "p3": {
          "value": 138.13,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 61.25,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 148.75,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65.62,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        },
        "p3": {
          "value": 159.38,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 170,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 73.5,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        },
        "p3": {
          "value": 178.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        },
        "p3": {
          "value": 187,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 80.5,
          "unit": "percent"
        },
        "p2": {
          "value": 138,
          "unit": "percent"
        },
        "p3": {
          "value": 195.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        },
        "p3": {
          "value": 204,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        },
        "p3": {
          "value": 212.5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 16,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "108d3108995e5411fc5f5d4f0e47486b4d922c194a17b013305544710f7a8d26",
  "icon_path": "icon/skill/1315_talent.png"
}
```

### 3-9× Smile

```json
{
  "ability_id": "131507",
  "slot": "technique",
  "name": "3-9× Smile",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
    "weakness"
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
  "description_sha256": "1ff90eb2243a68104c66628d49baeb40e2ceb33d099ca500e1bdee363b7a2978",
  "icon_path": "icon/skill/1315_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Ghost Load",
    "mechanic_tags": [
      "crit_rate",
      "crit_dmg",
      "break_effect",
      "dmg"
    ],
    "numeric_tokens": [
      "10%",
      "50%",
      "30%",
      "150%"
    ],
    "description_sha256": "a81e8f45501af59e697b99c7fcdb91bdaea6e9707a70eeed47dea1273bfd3ea6"
  },
  {
    "requirement": "A4",
    "name": "Above Snakes",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "ffdb703b6772109b28870b1cba3686dbec95da30c8091cb475aeea21d3161395"
  },
  {
    "requirement": "A6",
    "name": "Point Blank",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "7ffd65dc2235ea8c459ca4d704a368e4093287e2a9db9d8d823fa6f7cd180019"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Dusty Trail's Lone Star",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "16%"
    ],
    "description_sha256": "b0c50d40d541dbcd2e0ea6cafda14728634ea3d48a9eb25f30f45077c5c3d202"
  },
  {
    "eidolon": 2,
    "name": "Milestonemonger",
    "mechanic_tags": [
      "break_effect",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "30%",
      "2"
    ],
    "description_sha256": "0593a242b7b2b85737d33cc9ddbb3135e48163f16d933879774b75238efe645b"
  },
  {
    "eidolon": 3,
    "name": "Marble Orchard's Guard",
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
    "name": "Cold Cuts Chef",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "12%",
      "12%"
    ],
    "description_sha256": "31b89f900e87dfe7c3fdded50ea6290e94adf7e429dc80dfe56a328b297ae5ac"
  },
  {
    "eidolon": 5,
    "name": "Stump Speech",
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
    "name": "Crowbar Hotel's Raccoon",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "40%",
      "70%"
    ],
    "description_sha256": "e462837b428b21721828f2c0353c1aa75104f27447f7d1bdc83fd22e8cdc707a"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
