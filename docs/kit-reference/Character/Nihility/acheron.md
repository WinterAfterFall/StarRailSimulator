---
schema_version: "1.0.0"
unit_id: 49
name: "Acheron"
slug: "acheron"
rarity: 5
element: "Lightning"
path: "Nihility"
role: "Main DPS"
affiliation: "Galaxy Ranger"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/acheron"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Acheron

## Character record

```json
{
  "unit_id": 49,
  "name": "Acheron",
  "slug": "acheron",
  "rarity": "5",
  "element": "Lightning",
  "path": "Nihility",
  "default_role": "Main DPS",
  "affiliation": "Galaxy Ranger",
  "release_date": "March 27th, 2024",
  "is_released": true,
  "ultimate_energy_cost": null,
  "base_stats": {
    "hp_base": 153.12,
    "def_base": 59.4,
    "atk_base": 95.04,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "Lightning DMG",
      "value": 8
    },
    "traceStat3": {
      "stat": "CRIT DMG",
      "value": 24
    }
  },
  "voice_actors": {
    "en": "Allegra Clark",
    "kr": "박지윤 (Park Ji-yoon)",
    "jpn": "沢城みゆき (Sawashiro Miyuki)",
    "cn": "菊花花 (Juhuahua)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/acheron",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140001` | Trilateral Wiltcross | Basic ATK | Single Target |
| `skill` | `140002` | Octobolt Flash | Skill | Blast |
| `ult` | `140003` | Slashed Dream Cries in Red | Ultimate | AoE |
| `talent` | `140004` | Atop Rainleaf Hangs Oneness | Talent | Enhance |
| `technique` | `140007` | Quadrivalent Ascendance | Technique | - |

## Ability records

### Trilateral Wiltcross

```json
{
  "ability_id": "140001",
  "slot": "basic",
  "name": "Trilateral Wiltcross",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
  "energy_gain": null,
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
  "description_sha256": "9bd7eac7c4949ae4ab7d2c611187ca636fed1d7cd0a8a56208cf692d6bcde7a1",
  "icon_path": "icon/skill/1306_basic_atk.png"
}
```

### Octobolt Flash

```json
{
  "ability_id": "140002",
  "slot": "skill",
  "name": "Octobolt Flash",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Lightning",
  "energy_gain": null,
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
          "value": 30,
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
        },
        "p2": {
          "value": 33,
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
          "value": 36,
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
          "value": 39,
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
          "value": 45,
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
          "value": 48.75,
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
          "value": 52.5,
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
          "value": 56.25,
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
          "value": 60,
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
          "value": 63,
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
          "value": 66,
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
          "value": 100,
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
          "value": 100,
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
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9fc7e12932bbbff24156b44b28b8b69f22845cdb3a7370f93bfa896d90e33a8e",
  "icon_path": "icon/skill/1306_skill.png"
}
```

### Slashed Dream Cries in Red

```json
{
  "ability_id": "140003",
  "slot": "ult",
  "name": "Slashed Dream Cries in Red",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
  "toughness_break_secondary_source": "15",
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
    },
    "p6": {
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
          "value": 223.2,
          "unit": "percent"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 9,
          "unit": "percent"
        },
        "p5": {
          "value": 36,
          "unit": "percent"
        },
        "p6": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 238.08,
          "unit": "percent"
        },
        "p2": {
          "value": 192,
          "unit": "percent"
        },
        "p3": {
          "value": 15.36,
          "unit": "percent"
        },
        "p4": {
          "value": 9.6,
          "unit": "percent"
        },
        "p5": {
          "value": 38.4,
          "unit": "percent"
        },
        "p6": {
          "value": 76.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 252.96,
          "unit": "percent"
        },
        "p2": {
          "value": 204,
          "unit": "percent"
        },
        "p3": {
          "value": 16.32,
          "unit": "percent"
        },
        "p4": {
          "value": 10.2,
          "unit": "percent"
        },
        "p5": {
          "value": 40.8,
          "unit": "percent"
        },
        "p6": {
          "value": 81.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 267.84,
          "unit": "percent"
        },
        "p2": {
          "value": 216,
          "unit": "percent"
        },
        "p3": {
          "value": 17.28,
          "unit": "percent"
        },
        "p4": {
          "value": 10.8,
          "unit": "percent"
        },
        "p5": {
          "value": 43.2,
          "unit": "percent"
        },
        "p6": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 282.72,
          "unit": "percent"
        },
        "p2": {
          "value": 228,
          "unit": "percent"
        },
        "p3": {
          "value": 18.24,
          "unit": "percent"
        },
        "p4": {
          "value": 11.4,
          "unit": "percent"
        },
        "p5": {
          "value": 45.6,
          "unit": "percent"
        },
        "p6": {
          "value": 91.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 297.6,
          "unit": "percent"
        },
        "p2": {
          "value": 240,
          "unit": "percent"
        },
        "p3": {
          "value": 19.2,
          "unit": "percent"
        },
        "p4": {
          "value": 12,
          "unit": "percent"
        },
        "p5": {
          "value": 48,
          "unit": "percent"
        },
        "p6": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 316.2,
          "unit": "percent"
        },
        "p2": {
          "value": 255,
          "unit": "percent"
        },
        "p3": {
          "value": 20.4,
          "unit": "percent"
        },
        "p4": {
          "value": 12.75,
          "unit": "percent"
        },
        "p5": {
          "value": 51,
          "unit": "percent"
        },
        "p6": {
          "value": 102,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 334,
          "unit": "percent"
        },
        "p2": {
          "value": 270,
          "unit": "percent"
        },
        "p3": {
          "value": 21.6,
          "unit": "percent"
        },
        "p4": {
          "value": 13.5,
          "unit": "percent"
        },
        "p5": {
          "value": 54,
          "unit": "percent"
        },
        "p6": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 353.4,
          "unit": "percent"
        },
        "p2": {
          "value": 285,
          "unit": "percent"
        },
        "p3": {
          "value": 22.8,
          "unit": "percent"
        },
        "p4": {
          "value": 14.25,
          "unit": "percent"
        },
        "p5": {
          "value": 57,
          "unit": "percent"
        },
        "p6": {
          "value": 114,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 372,
          "unit": "percent"
        },
        "p2": {
          "value": 300,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 15,
          "unit": "percent"
        },
        "p5": {
          "value": 60,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 386.88,
          "unit": "percent"
        },
        "p2": {
          "value": 312,
          "unit": "percent"
        },
        "p3": {
          "value": 24.96,
          "unit": "percent"
        },
        "p4": {
          "value": 15.6,
          "unit": "percent"
        },
        "p5": {
          "value": 62.4,
          "unit": "percent"
        },
        "p6": {
          "value": 124.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 401.76,
          "unit": "percent"
        },
        "p2": {
          "value": 324,
          "unit": "percent"
        },
        "p3": {
          "value": 25.92,
          "unit": "percent"
        },
        "p4": {
          "value": 16.2,
          "unit": "percent"
        },
        "p5": {
          "value": 64.8,
          "unit": "percent"
        },
        "p6": {
          "value": 129.6,
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a082ed6a08e1cadfb8a7d739daed19c810b8ffc5df4ef2c64d3604e2255c3840",
  "icon_path": "icon/skill/1306_ultimate.png"
}
```

### Atop Rainleaf Hangs Oneness

```json
{
  "ability_id": "140004",
  "slot": "talent",
  "name": "Atop Rainleaf Hangs Oneness",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
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
    "res",
    "toughness",
    "debuff",
    "buff",
    "weakness"
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
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
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
          "value": 12,
          "unit": "percent"
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
          "value": 13,
          "unit": "percent"
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
          "value": 14,
          "unit": "percent"
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
          "value": 15,
          "unit": "percent"
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
          "value": 16.25,
          "unit": "percent"
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
          "value": 17.5,
          "unit": "percent"
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
          "value": 18.75,
          "unit": "percent"
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
          "value": 20,
          "unit": "percent"
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
          "value": 21,
          "unit": "percent"
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
          "value": 22,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "96fb1854548808357396ff178a53098e3e4a1e6e788964c7fd04d209ad89e708",
  "icon_path": "icon/skill/1306_talent.png"
}
```

### Quadrivalent Ascendance

```json
{
  "ability_id": "140007",
  "slot": "technique",
  "name": "Quadrivalent Ascendance",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": null,
  "targeting_label": null,
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "break_effect",
    "dmg",
    "toughness",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b61dcf48095bcb20cc8ddfce212270464e7cc96cc5ecbdd02656e8ad5c13a2ec",
  "icon_path": "icon/skill/1306_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Red Oni",
    "mechanic_tags": [],
    "numeric_tokens": [
      "5",
      "5",
      "1",
      "3"
    ],
    "description_sha256": "56395d7f6ae70d080b6f728e73e5e37ad7d98cab4adc0c9ff58c81afb063fab9"
  },
  {
    "requirement": "A4",
    "name": "The Abyss",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "115%",
      "160%"
    ],
    "description_sha256": "7e66a55b3a4b9bc48c0c5539893838b479ed60f38c0946dc4a6899d47d2542dd"
  },
  {
    "requirement": "A6",
    "name": "Thunder Core",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "30%",
      "3",
      "3",
      "6",
      "25%"
    ],
    "description_sha256": "a1d1e1cca595e10d8e5071ec4696da3e6d9ce1d16bf16533e3dcdc91e4b33925"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Silenced Sky Spake Sooth",
    "mechanic_tags": [
      "crit_rate",
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "18%"
    ],
    "description_sha256": "48469e7e222e7e63f5467993a752838a1ad59d0fea6fa383923b58ec20ce2d58"
  },
  {
    "eidolon": 2,
    "name": "Mute Thunder in Still Tempest",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "1",
      "1"
    ],
    "description_sha256": "07fea2a776b419f6d4be44d9542eda45fc5882aba85623edde3cb8454a83224a"
  },
  {
    "eidolon": 3,
    "name": "Frost Bites in Death",
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
    "name": "Shrined Fire for Mirrored Soul",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "8%"
    ],
    "description_sha256": "20a10b8bdafe6a17cb7aba77603b110bf765b6afbf260f8081e3b1e295d34eee"
  },
  {
    "eidolon": 5,
    "name": "Strewn Souls on Erased Earths",
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
    "name": "Apocalypse, the Emancipator",
    "mechanic_tags": [
      "atk",
      "break_effect",
      "res_pen",
      "res",
      "dmg",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "9ba6b3811f923f04ef839245fcff6671958134990ab1b572000682fd158d9ca4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
