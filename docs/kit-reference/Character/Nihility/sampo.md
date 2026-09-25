---
schema_version: "1.0.0"
unit_id: 19
name: "Sampo"
slug: "sampo"
rarity: 4
element: "Wind"
path: "Nihility"
role: "Sub DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/sampo"
source_record_updated_at: "July 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Sampo

## Character record

```json
{
  "unit_id": 19,
  "name": "Sampo",
  "slug": "sampo",
  "rarity": "4",
  "element": "Wind",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 139.2,
    "def_base": 54,
    "atk_base": 84,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "effectHitRate",
      "value": 18
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Roger Rose",
    "kr": "정재헌",
    "jpn": "Hirakawa Daisuke (平川大輔)",
    "cn": "刘圣博"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/sampo",
  "source_record_updated_at": "July 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110801` | Dazzling Blades | Basic ATK | Single Target |
| `skill` | `110802` | Ricochet Love | Skill | Bounce |
| `ult` | `110803` | Surprise Present | Ultimate | Impair |
| `talent` | `110804` | Windtorn Dagger | Talent | Enhance |
| `technique` | `110807` | Shining Bright | Technique | Impair |

## Ability records

### Dazzling Blades

```json
{
  "ability_id": "110801",
  "slot": "basic",
  "name": "Dazzling Blades",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
  "description_sha256": "7b30855c5a5810ae0842cfcbe9f25d995c186deeca90d0f5885f499ebf1a239e",
  "icon_path": "icon/skill/1108_basic_atk.png"
}
```

### Ricochet Love

```json
{
  "ability_id": "110802",
  "slot": "skill",
  "name": "Ricochet Love",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Wind",
  "energy_gain": "6",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 2
    },
    "p1": {
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
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 30.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 33.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 36.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 39.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 45.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 49,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 58.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 61.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 64.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 67.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "scalar"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d8993498f3f8c92f11a7e61f200a0091d213caf5f2b0ce83552cc9a64456fd1b",
  "icon_path": "icon/skill/1108_skill.png"
}
```

### Surprise Present

```json
{
  "ability_id": "110803",
  "slot": "ult",
  "name": "Surprise Present",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Wind",
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
    "p4": {
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
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 102.4,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 108.8,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 115.2,
          "unit": "percent"
        },
        "p2": {
          "value": 23,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 121.6,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        },
        "p2": {
          "value": 28.75,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 166.4,
          "unit": "percent"
        },
        "p2": {
          "value": 31,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 179.2,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 185.6,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "faeab3aeba04c211d8d7e6d2699851fb4e404b7308fad555647ab8d7f16bdbb8",
  "icon_path": "icon/skill/1108_ultimate.png"
}
```

### Windtorn Dagger

```json
{
  "ability_id": "110804",
  "slot": "talent",
  "name": "Windtorn Dagger",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
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
    "p3": {
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
    }
  },
  "mechanic_tags": [
    "atk",
    "dot"
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
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
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
          "value": 26,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 31,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 40,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 46,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 52,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 54.6,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 57.2,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 59.8,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 62.4,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "35b90001ab52ceb22691bc86ce03f96b3cd0edcefa08ce69a94772fbb0741cfa",
  "icon_path": "icon/skill/1108_talent.png"
}
```

### Shining Bright

```json
{
  "ability_id": "110807",
  "slot": "technique",
  "name": "Shining Bright",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Wind",
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
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8a34a893266e1eff61eca4d6a7c16923c6097777eef015378ac8bed566b5589b",
  "icon_path": "icon/skill/1108_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Trap",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "401416cd777d9028b116995a184237d2d253ca73afeb00b5cf13c8c218c625b9"
  },
  {
    "requirement": "A4",
    "name": "Defensive Position",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "cb15678f84a94f0de1186291fb49fd19a3bbfbfa130451fac9c03e284e63120a"
  },
  {
    "requirement": "A6",
    "name": "Spice Up",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "127f85be3455fc5e30d3b8ab6a25272b753bd19d906098ae257816fd790b663c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Rising Love",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "6707bdca770970005f11b4cb2b00c7014d69e435f137b0dee28834f448eab360"
  },
  {
    "eidolon": 2,
    "name": "Infectious Enthusiasm",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "100%",
      "1"
    ],
    "description_sha256": "fab711dcfbf3687e3a0fc0111c237e2f68452f6660dbd79b6350537091dc60c0"
  },
  {
    "eidolon": 3,
    "name": "Big Money!",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "dfc289407dbc553d0a60b619a82ff2cb35c322892c7f2b225426b96a861b9dfd"
  },
  {
    "eidolon": 4,
    "name": "The Deeper the Love, the Stronger the Hate",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "5",
      "8%"
    ],
    "description_sha256": "3f4a6127eac2c2ccaf81e6705f682eba98b0e6b01028f552c7be215df2f1af95"
  },
  {
    "eidolon": 5,
    "name": "Huuuuge Money!",
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
    "eidolon": 6,
    "name": "Increased Spending",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "377d15c40d784f2fd821e542dd301e1b441f3009a1e8ff5ca2bd25ec769b6495"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
