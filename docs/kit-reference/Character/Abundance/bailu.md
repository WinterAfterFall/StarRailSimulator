---
schema_version: "1.0.0"
unit_id: 24
name: "Bailu"
slug: "bailu"
rarity: 5
element: "Lightning"
path: "Abundance"
role: "Healer"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/bailu"
source_record_updated_at: "January 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# Bailu

## Character record

```json
{
  "unit_id": 24,
  "name": "Bailu",
  "slug": "bailu",
  "rarity": "5",
  "element": "Lightning",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "Xianzhou Luofu",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 179.52,
    "def_base": 66,
    "atk_base": 76.56,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 28
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
    "en": "Su Ling Chan",
    "kr": "",
    "jpn": "Emiri Katō (加藤 英美里)",
    "cn": "Duoduo Poi (多多poi)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/bailu",
  "source_record_updated_at": "January 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121101` | Diagnostic Kick | Basic ATK | Single Target |
| `skill` | `121102` | Singing Among Clouds | Skill | Restore |
| `ult` | `121103` | Felicitous Thunderleap | Ultimate | Restore |
| `talent` | `121104` | Gourdful of Elixir | Talent | Restore |
| `technique` | `121107` | Saunter in the Rain | Technique | Restore |

## Ability records

### Diagnostic Kick

```json
{
  "ability_id": "121101",
  "slot": "basic",
  "name": "Diagnostic Kick",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
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
  "description_sha256": "198abedc34c329dcef851a520d985d0f7a3c89577bd7822c49876f75fa54f18f",
  "icon_path": "icon/skill/1211_basic_atk.png"
}
```

### Singing Among Clouds

```json
{
  "ability_id": "121102",
  "slot": "skill",
  "name": "Singing Among Clouds",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Lightning",
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
    "p4": {
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
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 7.8,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 8.29,
          "unit": "percent"
        },
        "p2": {
          "value": 124.8,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.78,
          "unit": "percent"
        },
        "p2": {
          "value": 159.9,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.26,
          "unit": "percent"
        },
        "p2": {
          "value": 195,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 9.75,
          "unit": "percent"
        },
        "p2": {
          "value": 218.4,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 10.14,
          "unit": "percent"
        },
        "p2": {
          "value": 241.8,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 10.53,
          "unit": "percent"
        },
        "p2": {
          "value": 259.35,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 10.92,
          "unit": "percent"
        },
        "p2": {
          "value": 276.9,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 11.31,
          "unit": "percent"
        },
        "p2": {
          "value": 294.45,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 11.7,
          "unit": "percent"
        },
        "p2": {
          "value": 312,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 12.09,
          "unit": "percent"
        },
        "p2": {
          "value": 329.55,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 12.48,
          "unit": "percent"
        },
        "p2": {
          "value": 347.1,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 12.87,
          "unit": "percent"
        },
        "p2": {
          "value": 364.65,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 13.26,
          "unit": "percent"
        },
        "p2": {
          "value": 382.2,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 13.65,
          "unit": "percent"
        },
        "p2": {
          "value": 399.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "dd6b319b217fbd0c6129da44be8958844b8210ca545e2c35eabf9736a86ed93b",
  "icon_path": "icon/skill/1211_skill.png"
}
```

### Felicitous Thunderleap

```json
{
  "ability_id": "121103",
  "slot": "ult",
  "name": "Felicitous Thunderleap",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
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
          "value": 9.56,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "scalar"
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
          "value": 10.13,
          "unit": "percent"
        },
        "p2": {
          "value": 184.5,
          "unit": "scalar"
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
          "value": 10.69,
          "unit": "percent"
        },
        "p2": {
          "value": 225,
          "unit": "scalar"
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
          "value": 11.25,
          "unit": "percent"
        },
        "p2": {
          "value": 252,
          "unit": "scalar"
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
          "value": 11.7,
          "unit": "percent"
        },
        "p2": {
          "value": 279,
          "unit": "scalar"
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
          "value": 12.15,
          "unit": "percent"
        },
        "p2": {
          "value": 299.25,
          "unit": "scalar"
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
          "value": 12.6,
          "unit": "percent"
        },
        "p2": {
          "value": 319.5,
          "unit": "scalar"
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
          "value": 13.05,
          "unit": "percent"
        },
        "p2": {
          "value": 339.75,
          "unit": "scalar"
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
          "value": 13.5,
          "unit": "percent"
        },
        "p2": {
          "value": 360,
          "unit": "scalar"
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
          "value": 13.95,
          "unit": "percent"
        },
        "p2": {
          "value": 380.25,
          "unit": "scalar"
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
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 400.5,
          "unit": "scalar"
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
          "value": 14.85,
          "unit": "percent"
        },
        "p2": {
          "value": 420.75,
          "unit": "scalar"
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
          "value": 15.3,
          "unit": "percent"
        },
        "p2": {
          "value": 441,
          "unit": "scalar"
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
          "value": 15.75,
          "unit": "percent"
        },
        "p2": {
          "value": 461.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "ea56e95a560f36b3a6fb398ab86f89e294dc74aaca7a712d35e88c3d208bc8c5",
  "icon_path": "icon/skill/1211_ultimate.png"
}
```

### Gourdful of Elixir

```json
{
  "ability_id": "121104",
  "slot": "talent",
  "name": "Gourdful of Elixir",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
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
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 3.6,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "scalar"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 120,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 3.82,
          "unit": "percent"
        },
        "p2": {
          "value": 57.6,
          "unit": "scalar"
        },
        "p3": {
          "value": 12.75,
          "unit": "percent"
        },
        "p4": {
          "value": 192,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 4.05,
          "unit": "percent"
        },
        "p2": {
          "value": 73.8,
          "unit": "scalar"
        },
        "p3": {
          "value": 13.5,
          "unit": "percent"
        },
        "p4": {
          "value": 246,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 4.28,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        },
        "p3": {
          "value": 14.25,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 4.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 336,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 4.68,
          "unit": "percent"
        },
        "p2": {
          "value": 111.6,
          "unit": "scalar"
        },
        "p3": {
          "value": 15.6,
          "unit": "percent"
        },
        "p4": {
          "value": 372,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 4.86,
          "unit": "percent"
        },
        "p2": {
          "value": 119.7,
          "unit": "scalar"
        },
        "p3": {
          "value": 16.2,
          "unit": "percent"
        },
        "p4": {
          "value": 399,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 5.04,
          "unit": "percent"
        },
        "p2": {
          "value": 127.8,
          "unit": "scalar"
        },
        "p3": {
          "value": 16.8,
          "unit": "percent"
        },
        "p4": {
          "value": 426,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 5.22,
          "unit": "percent"
        },
        "p2": {
          "value": 135.9,
          "unit": "scalar"
        },
        "p3": {
          "value": 17.4,
          "unit": "percent"
        },
        "p4": {
          "value": 453,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 5.4,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "scalar"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 480,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 5.58,
          "unit": "percent"
        },
        "p2": {
          "value": 152.1,
          "unit": "scalar"
        },
        "p3": {
          "value": 18.6,
          "unit": "percent"
        },
        "p4": {
          "value": 507,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 5.76,
          "unit": "percent"
        },
        "p2": {
          "value": 160.2,
          "unit": "scalar"
        },
        "p3": {
          "value": 19.2,
          "unit": "percent"
        },
        "p4": {
          "value": 534,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 5.94,
          "unit": "percent"
        },
        "p2": {
          "value": 168.3,
          "unit": "scalar"
        },
        "p3": {
          "value": 19.8,
          "unit": "percent"
        },
        "p4": {
          "value": 561,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 6.12,
          "unit": "percent"
        },
        "p2": {
          "value": 176.4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20.4,
          "unit": "percent"
        },
        "p4": {
          "value": 588,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 6.3,
          "unit": "percent"
        },
        "p2": {
          "value": 184.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 21,
          "unit": "percent"
        },
        "p4": {
          "value": 615,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "12989708c20664d1e9e3c6e726aefa7c411da93afc25f60657454508bbbc7b31",
  "icon_path": "icon/skill/1211_talent.png"
}
```

### Saunter in the Rain

```json
{
  "ability_id": "121107",
  "slot": "technique",
  "name": "Saunter in the Rain",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Lightning",
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
  "mechanic_tags": [],
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
  "description_sha256": "3c3386005c5ef3c7bde57f1dc1f04b6130be1f8763dfbc37028b58fdbd9b1bbb",
  "icon_path": "icon/skill/1211_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Qihuang Analects",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "fc6fb2447ac0e3ad986196cb8de351586c19d769e4963f1ec0dbb6e3f4484f48"
  },
  {
    "requirement": "A4",
    "name": "Vidyadhara Ichor Lines",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "5b5c66285fd332f3ec80ff5859cbfb13d1c1db94a8d86b93848b756dda93648d"
  },
  {
    "requirement": "A6",
    "name": "Aquatic Benediction",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "5acbbcc8e4885d1325cc16018f805226b3392b2bf63859c0b57a9867cbe52d3f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Ambrosial Aqua",
    "mechanic_tags": [
      "max_hp",
      "energy"
    ],
    "numeric_tokens": [
      "8"
    ],
    "description_sha256": "7c4216f378fd812e8f91f4b229355568dcbf8b3c9ae701faad331276a7dd1b3c"
  },
  {
    "eidolon": 2,
    "name": "Sylphic Slumber",
    "mechanic_tags": [
      "healing"
    ],
    "numeric_tokens": [
      "15%",
      "2"
    ],
    "description_sha256": "5e4ee673ec9945d4cae064d2b3c7842bd073f29ff6258ca4487c35963d697ce9"
  },
  {
    "eidolon": 3,
    "name": "Omniscient Opulence",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "4c910ab9157733f3234ecdaa8bba52b244d201a478bad2528e5caf200f7c4227"
  },
  {
    "eidolon": 4,
    "name": "Evil Excision",
    "mechanic_tags": [
      "dmg",
      "healing"
    ],
    "numeric_tokens": [
      "10%",
      "2",
      "3"
    ],
    "description_sha256": "75168b0a6320dc65914dcce1fbaabb13a6d1cd868f0c0d328418abddb9edab78"
  },
  {
    "eidolon": 5,
    "name": "Waning Worries",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "bc9b09b7015c543b22391cfc36d3f3dbfe0ab3ca7a74e98b7e29242a899157fb"
  },
  {
    "eidolon": 6,
    "name": "Drooling Drop of Draconic Divinity",
    "mechanic_tags": [
      "healing"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "7e06e81085c927774ecba871f684bb8966ae7d09a56d4433c095bff6b674083f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
