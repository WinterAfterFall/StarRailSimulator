---
schema_version: "1.0.0"
unit_id: 81
name: "March 7th • Evernight"
slug: "march-7th-evernight"
rarity: 5
element: "Ice"
path: "Remembrance"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/march-7th-evernight"
source_record_updated_at: "October 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# March 7th • Evernight

## Character record

```json
{
  "unit_id": 81,
  "name": "March 7th • Evernight",
  "slug": "march-7th-evernight",
  "rarity": "5",
  "element": "Ice",
  "path": "Remembrance",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "September 24th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "240",
  "base_stats": {
    "hp_base": 180,
    "def_base": 79.2,
    "atk_base": 73.92,
    "speed_base": 99
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 18.7
    },
    "traceStat2": {
      "stat": "CRIT DMG",
      "value": 13.3
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Skyler Davenport",
    "kr": "Jung Hye-Won (정혜원)",
    "jpn": "Yui Ogura (小倉唯)",
    "cn": "Nuò Yǎ (诺亚)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/march-7th-evernight",
  "source_record_updated_at": "October 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `141301` | Time Thence Blurs | Basic ATK | Single Target |
| `skill` | `141302` | Day Gently Slips | Skill | Summon |
| `ult` | `141303` | O Wakeful World, Goodnight | Ultimate | AoE |
| `talent` | `141304` | With Me, This Night | Talent | Enhance |
| `technique` | `141307` | Let it Rain Cold On Thee | Technique | MazeAttack |
| `supplementary` | `1413010` | Remembrance, Whirling, Like Rain | Memosprite Skill | Single Target |
| `supplementary` | `1413011` | Dream, Dissolving, as Dew | Memosprite Skill | AoE |
| `supplementary` | `1413012` | Solitude, Drifting, In Murk | Memosprite Talent | Support |
| `supplementary` | `1413013` | Night, Trailing, In Step | Memosprite Talent | Support |
| `supplementary` | `1413014` | You, Parting, Beyond Reach | Memosprite Talent | Enhance |

## Ability records

### Time Thence Blurs

```json
{
  "ability_id": "141301",
  "slot": "basic",
  "name": "Time Thence Blurs",
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "39814beba5a15365b1836ce5349fad9cf03ae57dbc148c0347ee23376bcdb881",
  "icon_path": null
}
```

### Day Gently Slips

```json
{
  "ability_id": "141302",
  "slot": "skill",
  "name": "Day Gently Slips",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Summon",
  "targeting_label": "Summon",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "crit_dmg",
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6ec48cfd7d6550f768459c7e12cc5fb577825ed5125c5d97ac7b8ef1dd5a39d3",
  "icon_path": null
}
```

### O Wakeful World, Goodnight

```json
{
  "ability_id": "141303",
  "slot": "ult",
  "name": "O Wakeful World, Goodnight",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "240",
  "toughness_break_primary_source": "90",
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
    "max_hp",
    "dmg",
    "debuff",
    "buff",
    "summon"
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
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
          "value": 16.5,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
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
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
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
          "value": 19.5,
          "unit": "percent"
        },
        "p3": {
          "value": 39,
          "unit": "percent"
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
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
          "unit": "percent"
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
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 45,
          "unit": "percent"
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
          "value": 24.375,
          "unit": "percent"
        },
        "p3": {
          "value": 48.75,
          "unit": "percent"
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
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 52.5,
          "unit": "percent"
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
          "value": 28.125,
          "unit": "percent"
        },
        "p3": {
          "value": 56.25,
          "unit": "percent"
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
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
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 63,
          "unit": "percent"
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
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 66,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "cea94a611077f224c7f533eae86574829793c6e3098f3cacc8a6f06844e6a513",
  "icon_path": null
}
```

### With Me, This Night

```json
{
  "ability_id": "141304",
  "slot": "talent",
  "name": "With Me, This Night",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
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
    "spd",
    "crit_dmg",
    "dmg",
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 56.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c4cc2e6c3ec3ea324c922d64b41b23563c50bf0f840eab4fce99e91a1264b44d",
  "icon_path": null
}
```

### Let it Rain Cold On Thee

```json
{
  "ability_id": "141307",
  "slot": "technique",
  "name": "Let it Rain Cold On Thee",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "crit_dmg",
    "dmg",
    "summon"
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
  "description_sha256": "4b933a8a35adc0fa32ac5d3a0ba25474eb68bbf92e551d15afc89bd374f51550",
  "icon_path": null
}
```

### Remembrance, Whirling, Like Rain

```json
{
  "ability_id": "1413010",
  "slot": "supplementary",
  "name": "Remembrance, Whirling, Like Rain",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "Single Target",
  "targeting_label": "Single Target",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
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
          "value": 13,
          "unit": "percent"
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
          "value": 14,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2c6ffb98d5d612b2b4a0e82a7b86acd042ef11c21df343d63c06c15a2ec4cc4d",
  "icon_path": null
}
```

### Dream, Dissolving, as Dew

```json
{
  "ability_id": "1413011",
  "slot": "supplementary",
  "name": "Dream, Dissolving, as Dew",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 3.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 4.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.6,
          "unit": "percent"
        },
        "p2": {
          "value": 4.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 5.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 6.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        },
        "p2": {
          "value": 7.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        },
        "p2": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "75497604e9adbc914182f6a6e39c0996e7bb19110c4b21c4301ab8945cbb2ce8",
  "icon_path": null
}
```

### Solitude, Drifting, In Murk

```json
{
  "ability_id": "1413012",
  "slot": "supplementary",
  "name": "Solitude, Drifting, In Murk",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5f73a7bb5ee213ccff517dffd21975b9baef98570f6824cba6de29ae4ca9f5c3",
  "icon_path": null
}
```

### Night, Trailing, In Step

```json
{
  "ability_id": "1413013",
  "slot": "supplementary",
  "name": "Night, Trailing, In Step",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.06,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9e9897a8cb0f147cf847e73de772c6210afccbffdcb59f6a92be09a128dd25fd",
  "icon_path": null
}
```

### You, Parting, Beyond Reach

```json
{
  "ability_id": "1413014",
  "slot": "supplementary",
  "name": "You, Parting, Beyond Reach",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "spd"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.06,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "de34afde4f07a4c558c9df3dfe2fadfd8609f908c809932092f89f9426412e72",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Dark the Night, Still the Moon ",
    "mechanic_tags": [
      "max_hp",
      "crit_rate",
      "crit_dmg",
      "dmg",
      "skill_points",
      "summon"
    ],
    "numeric_tokens": [
      "35%",
      "5%",
      "15%",
      "2",
      "1"
    ],
    "description_sha256": "42836a0bc53ce933626b7b623f79bc9622a06f58234fb698b69072a428cf54dd"
  },
  {
    "requirement": "A4",
    "name": "Rouse the Flame, Lull the Light",
    "mechanic_tags": [
      "energy",
      "summon"
    ],
    "numeric_tokens": [
      "70",
      "1",
      "5",
      "1"
    ],
    "description_sha256": "a899656b2c63009ba3f977da16bbd4b924e8ff7675d9e25396423576cbfa0584"
  },
  {
    "requirement": "A6",
    "name": "Kindle the Morn, Drop the Rain",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "summon"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "3",
      "4",
      "5%",
      "15%",
      "50%",
      "65%"
    ],
    "description_sha256": "d8f28e39cf44458239ce486f85b3f3f5689b16caad22d5995c2a8f298d5fcb9b"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Sleep Tight, the Night Dreams Long",
    "mechanic_tags": [
      "dmg",
      "summon"
    ],
    "numeric_tokens": [
      "4",
      "3",
      "2",
      "1",
      "120%",
      "125%",
      "130%",
      "150%"
    ],
    "description_sha256": "ff9852889451ad07a9ab84bf9a8ddf4ac75049e0906605b50b68147fe729c12e"
  },
  {
    "eidolon": 2,
    "name": "Listen Up, the Slumber Speaks Soft",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "summon"
    ],
    "numeric_tokens": [
      "40%",
      "2",
      "2"
    ],
    "description_sha256": "ebc149dca54a84da8ad5294377dd05760701f7d439cf697877b518ba0b34c458"
  },
  {
    "eidolon": 3,
    "name": "Fear Not, the Nightmare Lies Past",
    "mechanic_tags": [
      "atk",
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "10"
    ],
    "description_sha256": "caa57e8e3ae8bb906e5bee9b2eaa3b89cd95e7183ecf5eb6915f8e39c828eb66"
  },
  {
    "eidolon": 4,
    "name": "Wake Up, the Tomorrow is Yours",
    "mechanic_tags": [
      "weakness_break_efficiency",
      "weakness",
      "summon"
    ],
    "numeric_tokens": [
      "25%",
      "25%"
    ],
    "description_sha256": "b3e93d21ace70479b339a34f5fa1f1f9420e93c77fa785c3eca910bacb716461"
  },
  {
    "eidolon": 5,
    "name": "Let Go, the \"Me\" in Memories",
    "mechanic_tags": [
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "23416b132409e1464c2f5c3c885cc7f59b28156ac8c3f54b8f5810ee688bfff6"
  },
  {
    "eidolon": 6,
    "name": "Like This, Always",
    "mechanic_tags": [
      "res_pen",
      "res",
      "summon"
    ],
    "numeric_tokens": [
      "20%",
      "30%"
    ],
    "description_sha256": "67513699a168f8704b882a31d44e52cb318f5292dfebd8166d9e2ff2423741f0"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
