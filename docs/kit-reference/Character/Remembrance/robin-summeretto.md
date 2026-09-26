---
schema_version: "1.1.0"
unit_id: 1512
name: "Robin • Summeretto"
slug: "robin-summeretto"
rarity: 5
element: "Wind"
path: "Remembrance"
released: true
source_page: "https://www.prydwen.gg/star-rail/characters/robin-summeretto"
structured_source: "https://static.nanoka.cc/hsr/4.5.54/en/character/1512.json"
data_version: "4.5.54"
dataset_snapshot: "2026-09-26"
---

# Robin • Summeretto

## Character record

```json
{
  "unit_id": 1512,
  "name": "Robin • Summeretto",
  "slug": "robin-summeretto",
  "rarity": 5,
  "element": "Wind",
  "path": "Remembrance",
  "ultimate_energy_cost": 140,
  "release_timestamp": 1787734800,
  "release_datetime_utc": "2026-08-26T09:00:00+00:00",
  "released_status": "released",
  "base_stats_level_1": {
    "attack_base": 81.84,
    "attack_add": 4.092,
    "defence_base": 66,
    "defence_add": 3.3,
    "hp_base": 163.68,
    "hp_add": 8.184,
    "speed_base": 95,
    "critical_chance": 0.05,
    "critical_damage": 0.5,
    "base_aggro": 100
  },
  "computed_stats_level_80": {
    "hp": 1203.048,
    "atk": 601.524,
    "def": 485.1,
    "spd": 95,
    "crit_rate": 0.05,
    "crit_dmg": 0.5,
    "formula_note": "stage_6_base + per_level_add * 79"
  },
  "voice_actors": {
    "chinese": null,
    "japanese": null,
    "korean": null,
    "english": null
  },
  "memosprite_core": {
    "name": "Summer Songbirds",
    "icon": "SpriteOutput/ServantIconTeam/11512B.png",
    "hp_base": "0",
    "hp_inherit": "#1",
    "hp_skill": 151204,
    "speed_base": "0",
    "speed_inherit": "#2",
    "aggro": 100
  },
  "source_page": "https://www.prydwen.gg/star-rail/characters/robin-summeretto",
  "structured_source": "https://static.nanoka.cc/hsr/4.5.54/en/character/1512.json",
  "data_version": "4.5.54"
}
```

## Ability index

| Owner | Type | ID | Name | Levels |
|---|---|---:|---|---:|
| `character` | `Basic ATK` | `151201` | The Sea Sings in My Key | 10 |
| `character` | `Skill` | `151202` | Summer Strums the Soul | 15 |
| `character` | `Ultimate` | `151203` | Ascend That Rhapsody in Blue | 15 |
| `character` | `Talent` | `151204` | Wings Heed No Borders | 15 |
| `character` | `Technique` | `151207` | We Are the Melody | 1 |
| `memosprite` | `Memosprite Skill` | `None` | Chirrup Quartet | 10 |
| `memosprite` | `Memosprite Talent` | `None` | A Warble of Wings | 10 |
| `memosprite` | `Memosprite Talent` | `None` | Near the Sea's Heartbeat | 10 |
| `memosprite` | `Memosprite Talent` | `None` | Astride Summer's Nightwind | 10 |

## Ability records

### The Sea Sings in My Key

```json
{
  "ability_id": "151201",
  "slot": "basic_atk",
  "owner": "character",
  "name": "The Sea Sings in My Key",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "element": "Wind",
  "energy_gain": 20,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": 1,
  "toughness_stance_list_raw": [
    30,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent",
          "source_value": 0.25
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent",
          "source_value": 0.3
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent",
          "source_value": 0.35
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent",
          "source_value": 0.4
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent",
          "source_value": 0.45
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent",
          "source_value": 0.55
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent",
          "source_value": 0.65
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        }
      }
    }
  ],
  "extra_terms": [],
  "description_sha256": "1121ab4d28c1c24696f13dde4106e6a0be82a3c0567c079b6ca1aeedfc6ff775"
}
```

### Summer Strums the Soul

```json
{
  "ability_id": "151202",
  "slot": "skill",
  "owner": "character",
  "name": "Summer Strums the Soul",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Summon",
  "element": "Wind",
  "energy_gain": 30,
  "skill_point_need_raw": 1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p2": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent",
          "source_value": 0.55
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent",
          "source_value": 0.65
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent",
          "source_value": 0.75
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 81.25,
          "unit": "percent",
          "source_value": 0.8125
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent",
          "source_value": 0.875
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 93.75,
          "unit": "percent",
          "source_value": 0.9375
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent",
          "source_value": 1.05
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent",
          "source_value": 1.1
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 115,
          "unit": "percent",
          "source_value": 1.15
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent",
          "source_value": 1.2
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent",
          "source_value": 1.25
        },
        "p2": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000018",
      "name": "Summon Memosprite",
      "description_sha256": "2aa9afd8febfaa6e6973d4ddf9281145952e6e4a943909dacf978ba2988c22f8",
      "parameters": []
    }
  ],
  "description_sha256": "3ff09e2e13471df239aaa4785ec773dfb7f04573d429bcee9802a7da040c52ef"
}
```

### Ascend That Rhapsody in Blue

```json
{
  "ability_id": "151203",
  "slot": "ultimate",
  "owner": "character",
  "name": "Ascend That Rhapsody in Blue",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "element": "Wind",
  "energy_gain": 5,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p3": {
      "format": "f1",
      "unit": "percent"
    },
    "p2": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "energy",
    "action_advance"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 12,
          "unit": "percent",
          "source_value": 0.12
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 12.8,
          "unit": "percent",
          "source_value": 0.128
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 13.6,
          "unit": "percent",
          "source_value": 0.136
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 14.4,
          "unit": "percent",
          "source_value": 0.144
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 15.2,
          "unit": "percent",
          "source_value": 0.152
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 16,
          "unit": "percent",
          "source_value": 0.16
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 17,
          "unit": "percent",
          "source_value": 0.17
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 18,
          "unit": "percent",
          "source_value": 0.18
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 19,
          "unit": "percent",
          "source_value": 0.19
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 20,
          "unit": "percent",
          "source_value": 0.2
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 20.8,
          "unit": "percent",
          "source_value": 0.208
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 21.6,
          "unit": "percent",
          "source_value": 0.216
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 22.4,
          "unit": "percent",
          "source_value": 0.224
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 23.2,
          "unit": "percent",
          "source_value": 0.232
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent",
          "source_value": 1
        },
        "p2": {
          "value": 2,
          "unit": "scalar",
          "source_value": 2
        },
        "p3": {
          "value": 24,
          "unit": "percent",
          "source_value": 0.24
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000001",
      "name": "Action Advance",
      "description_sha256": "39a2f3a30a494301828c2524510a89cae1b21abe1409cbdb72dd00f8f565362e",
      "parameters": []
    }
  ],
  "description_sha256": "73915ec07eb28de3b9d86905faac0da136f618f59e1fe05b80c6da3ea87918fd"
}
```

### Wings Heed No Borders

```json
{
  "ability_id": "151204",
  "slot": "talent",
  "owner": "character",
  "name": "Wings Heed No Borders",
  "type_code": null,
  "type_label": "Talent",
  "effect_code": "Enhance",
  "element": "Wind",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p2": {
      "format": "i",
      "unit": "percent"
    },
    "p5": {
      "format": "i",
      "unit": "scalar"
    },
    "p6": {
      "format": "i",
      "unit": "scalar"
    },
    "p7": {
      "format": "i",
      "unit": "scalar"
    },
    "p8": {
      "format": "f1",
      "unit": "percent"
    },
    "p9": {
      "format": "f1",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "max_hp",
    "def",
    "spd",
    "dmg",
    "healing",
    "shield",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 10,
          "unit": "percent",
          "source_value": 0.1
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 10.5,
          "unit": "percent",
          "source_value": 0.105
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 11,
          "unit": "percent",
          "source_value": 0.11
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 11.5,
          "unit": "percent",
          "source_value": 0.115
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 12,
          "unit": "percent",
          "source_value": 0.12
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 12.5,
          "unit": "percent",
          "source_value": 0.125
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 13.125,
          "unit": "percent",
          "source_value": 0.13125
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 13.75,
          "unit": "percent",
          "source_value": 0.1375
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 14.375,
          "unit": "percent",
          "source_value": 0.14375
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 15,
          "unit": "percent",
          "source_value": 0.15
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 15.5,
          "unit": "percent",
          "source_value": 0.155
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 16,
          "unit": "percent",
          "source_value": 0.16
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 16.5,
          "unit": "percent",
          "source_value": 0.165
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 17,
          "unit": "percent",
          "source_value": 0.17
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent",
          "source_value": 0.7
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p3": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p4": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p5": {
          "value": 50,
          "unit": "scalar",
          "source_value": 50
        },
        "p6": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p7": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p8": {
          "value": 17.5,
          "unit": "percent",
          "source_value": 0.175
        },
        "p9": {
          "value": 0.5,
          "unit": "percent",
          "source_value": 0.005
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000011",
      "name": "Crowd Control debuff",
      "description_sha256": "6551beb5f4f5dc240284c335a68e8ea650890590291ea9f823cd244a7202f30f",
      "parameters": []
    }
  ],
  "description_sha256": "342996f2728692302366e2f0ffb32c3f2eafcb04adcb04af2ef93d61df7e06f4"
}
```

### We Are the Melody

```json
{
  "ability_id": "151207",
  "slot": "technique",
  "owner": "character",
  "name": "We Are the Melody",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "element": "Wind",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p3": {
      "format": "i",
      "unit": "percent"
    },
    "p1": {
      "format": "i",
      "unit": "scalar"
    },
    "p2": {
      "format": "i",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "dmg",
    "action_advance"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p2": {
          "value": 30,
          "unit": "percent",
          "source_value": 0.3
        },
        "p3": {
          "value": 20,
          "unit": "percent",
          "source_value": 0.2
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000001",
      "name": "Action Advance",
      "description_sha256": "39a2f3a30a494301828c2524510a89cae1b21abe1409cbdb72dd00f8f565362e",
      "parameters": []
    }
  ],
  "description_sha256": "c9cc26ecb2dc66e8dd9d6e0917a65003b45f1fddfcab7d9bea73e24361183f50"
}
```

### Chirrup Quartet

```json
{
  "ability_id": "None",
  "slot": "memosprite_skill",
  "owner": "memosprite",
  "name": "Chirrup Quartet",
  "type_code": "Servant",
  "type_label": "Memosprite Skill",
  "effect_code": "AoEAttack",
  "element": "Wind",
  "energy_gain": 20,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    30,
    0
  ],
  "parameter_placeholders": {
    "p2": {
      "format": "f1",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 75,
          "unit": "percent",
          "source_value": 0.75
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 90,
          "unit": "percent",
          "source_value": 0.9
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 105,
          "unit": "percent",
          "source_value": 1.05
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 120,
          "unit": "percent",
          "source_value": 1.2
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 135,
          "unit": "percent",
          "source_value": 1.35
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 150,
          "unit": "percent",
          "source_value": 1.5
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 165,
          "unit": "percent",
          "source_value": 1.65
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 195,
          "unit": "percent",
          "source_value": 1.95
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p2": {
          "value": 210,
          "unit": "percent",
          "source_value": 2.1
        }
      }
    }
  ],
  "extra_terms": [],
  "description_sha256": "5e40a904268ed9ea6c301a51af0f759925f759c40b49f71d49222707f55f8cac"
}
```

### A Warble of Wings

```json
{
  "ability_id": "None",
  "slot": "memosprite_talent",
  "owner": "memosprite",
  "name": "A Warble of Wings",
  "type_code": null,
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "element": "Wind",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p2": {
      "format": "f1",
      "unit": "percent"
    },
    "p9": {
      "format": "i",
      "unit": "scalar"
    },
    "p10": {
      "format": "i",
      "unit": "percent"
    },
    "p6": {
      "format": "i",
      "unit": "scalar"
    },
    "p3": {
      "format": "f1",
      "unit": "percent"
    },
    "p4": {
      "format": "f1",
      "unit": "percent"
    },
    "p5": {
      "format": "f1",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "spd",
    "dmg",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent",
          "source_value": 0.3
        },
        "p2": {
          "value": 1,
          "unit": "percent",
          "source_value": 0.01
        },
        "p3": {
          "value": 4,
          "unit": "percent",
          "source_value": 0.04
        },
        "p4": {
          "value": 6,
          "unit": "percent",
          "source_value": 0.06
        },
        "p5": {
          "value": 8,
          "unit": "percent",
          "source_value": 0.08
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent",
          "source_value": 0.36
        },
        "p2": {
          "value": 1.2,
          "unit": "percent",
          "source_value": 0.012
        },
        "p3": {
          "value": 4.8,
          "unit": "percent",
          "source_value": 0.048
        },
        "p4": {
          "value": 7.2,
          "unit": "percent",
          "source_value": 0.072
        },
        "p5": {
          "value": 9.6,
          "unit": "percent",
          "source_value": 0.096
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent",
          "source_value": 0.42
        },
        "p2": {
          "value": 1.4,
          "unit": "percent",
          "source_value": 0.014
        },
        "p3": {
          "value": 5.6,
          "unit": "percent",
          "source_value": 0.056
        },
        "p4": {
          "value": 8.4,
          "unit": "percent",
          "source_value": 0.084
        },
        "p5": {
          "value": 11.2,
          "unit": "percent",
          "source_value": 0.112
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent",
          "source_value": 0.48
        },
        "p2": {
          "value": 1.6,
          "unit": "percent",
          "source_value": 0.016
        },
        "p3": {
          "value": 6.4,
          "unit": "percent",
          "source_value": 0.064
        },
        "p4": {
          "value": 9.6,
          "unit": "percent",
          "source_value": 0.096
        },
        "p5": {
          "value": 12.8,
          "unit": "percent",
          "source_value": 0.128
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent",
          "source_value": 0.54
        },
        "p2": {
          "value": 1.8,
          "unit": "percent",
          "source_value": 0.018
        },
        "p3": {
          "value": 7.2,
          "unit": "percent",
          "source_value": 0.072
        },
        "p4": {
          "value": 10.8,
          "unit": "percent",
          "source_value": 0.108
        },
        "p5": {
          "value": 14.4,
          "unit": "percent",
          "source_value": 0.144
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
        },
        "p2": {
          "value": 2,
          "unit": "percent",
          "source_value": 0.02
        },
        "p3": {
          "value": 8,
          "unit": "percent",
          "source_value": 0.08
        },
        "p4": {
          "value": 12,
          "unit": "percent",
          "source_value": 0.12
        },
        "p5": {
          "value": 16,
          "unit": "percent",
          "source_value": 0.16
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent",
          "source_value": 0.66
        },
        "p2": {
          "value": 2.2,
          "unit": "percent",
          "source_value": 0.022
        },
        "p3": {
          "value": 8.8,
          "unit": "percent",
          "source_value": 0.088
        },
        "p4": {
          "value": 13.2,
          "unit": "percent",
          "source_value": 0.132
        },
        "p5": {
          "value": 17.6,
          "unit": "percent",
          "source_value": 0.176
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent",
          "source_value": 0.72
        },
        "p2": {
          "value": 2.4,
          "unit": "percent",
          "source_value": 0.024
        },
        "p3": {
          "value": 9.6,
          "unit": "percent",
          "source_value": 0.096
        },
        "p4": {
          "value": 14.4,
          "unit": "percent",
          "source_value": 0.144
        },
        "p5": {
          "value": 19.2,
          "unit": "percent",
          "source_value": 0.192
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent",
          "source_value": 0.78
        },
        "p2": {
          "value": 2.6,
          "unit": "percent",
          "source_value": 0.026
        },
        "p3": {
          "value": 10.4,
          "unit": "percent",
          "source_value": 0.104
        },
        "p4": {
          "value": 15.6,
          "unit": "percent",
          "source_value": 0.156
        },
        "p5": {
          "value": 20.8,
          "unit": "percent",
          "source_value": 0.208
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent",
          "source_value": 0.84
        },
        "p2": {
          "value": 2.8,
          "unit": "percent",
          "source_value": 0.028
        },
        "p3": {
          "value": 11.2,
          "unit": "percent",
          "source_value": 0.112
        },
        "p4": {
          "value": 16.8,
          "unit": "percent",
          "source_value": 0.168
        },
        "p5": {
          "value": 22.4,
          "unit": "percent",
          "source_value": 0.224
        },
        "p6": {
          "value": 12,
          "unit": "scalar",
          "source_value": 12
        },
        "p7": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p8": {
          "value": 0,
          "unit": "scalar",
          "source_value": 0
        },
        "p9": {
          "value": 140,
          "unit": "scalar",
          "source_value": 140
        },
        "p10": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    }
  ],
  "extra_terms": [],
  "description_sha256": "46fbbeb0f5507a7a29aa5629e6b4b267addefb9f14ffd6996e490be8a4fd9e88"
}
```

### Near the Sea's Heartbeat

```json
{
  "ability_id": "None",
  "slot": "memosprite_talent",
  "owner": "memosprite",
  "name": "Near the Sea's Heartbeat",
  "type_code": null,
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "element": "Wind",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "energy",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    }
  ],
  "extra_terms": [],
  "description_sha256": "b06b5ebd26accb3cc1091a0140cfabe28b0e81e1670485d79f5bba2bfb430a8b"
}
```

### Astride Summer's Nightwind

```json
{
  "ability_id": "None",
  "slot": "memosprite_talent",
  "owner": "memosprite",
  "name": "Astride Summer's Nightwind",
  "type_code": null,
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "element": "Wind",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "action_advance",
    "memosprite"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000001",
      "name": "Action Advance",
      "description_sha256": "39a2f3a30a494301828c2524510a89cae1b21abe1409cbdb72dd00f8f565362e",
      "parameters": []
    }
  ],
  "description_sha256": "30cd9d0fdfdda4c38e3771b500b686cec4feec7af8ed077487dc62a936586150"
}
```

## Major traces

```json
[
  {
    "anchor": "point06",
    "point_id": 1512101,
    "trace_type": "major",
    "name": "Deviated Chords",
    "unlock_ascension": 2,
    "unlock_level": null,
    "parameters": [
      16,
      0.4,
      40,
      1.5,
      2
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "max_hp",
      "atk",
      "crit_dmg",
      "dmg"
    ],
    "description_sha256": "81045cee3c06817e7bd65a3f5437e51a33d89dcb45bdf5a2ee73e878136dfad8"
  },
  {
    "anchor": "point07",
    "point_id": 1512102,
    "trace_type": "major",
    "name": "Improvised Blues",
    "unlock_ascension": 4,
    "unlock_level": null,
    "parameters": [
      12,
      3,
      12
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "energy",
      "healing",
      "shield",
      "memosprite"
    ],
    "description_sha256": "03421868ee27e0049d8ec631140aeb609c12d39cd5c5eb3ed70f602ffd3094f9"
  },
  {
    "anchor": "point08",
    "point_id": 1512103,
    "trace_type": "major",
    "name": "Rebuilt Harmony",
    "unlock_ascension": 6,
    "unlock_level": null,
    "parameters": [
      50,
      2
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "crit_rate",
      "memosprite"
    ],
    "description_sha256": "f678ae6c779f15803f2c771eba86d72d483d7b95bfc9bb7d93ad307b0858bff5"
  }
]
```

## Minor traces

```json
[
  {
    "anchor": "point09",
    "point_id": 1512201,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": null,
    "unlock_level": 1,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "SpeedDelta",
        "value": 2,
        "name": "SPD"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point10",
    "point_id": 1512202,
    "trace_type": "minor",
    "name": "HP Boost",
    "unlock_ascension": 2,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "HPAddedRatio",
        "value": 0.04,
        "name": "HP"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point11",
    "point_id": 1512203,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": 3,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "SpeedDelta",
        "value": 2,
        "name": "SPD"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point12",
    "point_id": 1512204,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": 3,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "CriticalChanceBase",
        "value": 0.027,
        "name": "CRIT Rate"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point13",
    "point_id": 1512205,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": 4,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "SpeedDelta",
        "value": 3,
        "name": "SPD"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point14",
    "point_id": 1512206,
    "trace_type": "minor",
    "name": "HP Boost",
    "unlock_ascension": 5,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "HPAddedRatio",
        "value": 0.06,
        "name": "HP"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point15",
    "point_id": 1512207,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": 5,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "SpeedDelta",
        "value": 3,
        "name": "SPD"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point16",
    "point_id": 1512208,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": 6,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "CriticalChanceBase",
        "value": 0.04,
        "name": "CRIT Rate"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point17",
    "point_id": 1512209,
    "trace_type": "minor",
    "name": "HP Boost",
    "unlock_ascension": null,
    "unlock_level": 75,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "HPAddedRatio",
        "value": 0.08,
        "name": "HP"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point18",
    "point_id": 1512210,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": null,
    "unlock_level": 80,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "SpeedDelta",
        "value": 4,
        "name": "SPD"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "eidolon_id": 151201,
    "name": "Stray Bird of Summer",
    "parameters": [
      {
        "value": 11,
        "unit": "percent",
        "source_value": 0.11
      },
      {
        "value": 0.1,
        "unit": "percent",
        "source_value": 0.001
      },
      {
        "value": 100,
        "unit": "percent",
        "source_value": 1
      },
      {
        "value": 50,
        "unit": "percent",
        "source_value": 0.5
      }
    ],
    "mechanic_tags": [
      "max_hp",
      "dmg",
      "memosprite",
      "true_dmg"
    ],
    "description_sha256": "99d0063ca323a3da39d3acee747f2e13c46ee21025c20f5c64e756c45b17cd05"
  },
  {
    "eidolon": 2,
    "eidolon_id": 151202,
    "name": "A Heart of Still Water",
    "parameters": [
      {
        "value": 20,
        "unit": "scalar",
        "source_value": 20
      },
      {
        "value": 2,
        "unit": "scalar",
        "source_value": 2
      },
      {
        "value": 18,
        "unit": "percent",
        "source_value": 0.18
      }
    ],
    "mechanic_tags": [
      "res_pen"
    ],
    "description_sha256": "a06f7106b013d52316311f0cf80b0681b38822d1f39cd6b9578d0422024e2ae0"
  },
  {
    "eidolon": 3,
    "eidolon_id": 151203,
    "name": "Echoes Left Along the Way",
    "parameters": [],
    "mechanic_tags": [
      "memosprite"
    ],
    "description_sha256": "e63d83c6b618384c734ca867572f3041d2de4fbf90e8b4bc0661615b0931e338"
  },
  {
    "eidolon": 4,
    "eidolon_id": 151204,
    "name": "Her Variation on the Theme",
    "parameters": [
      {
        "value": 12,
        "unit": "scalar",
        "source_value": 12
      },
      {
        "value": 20,
        "unit": "percent",
        "source_value": 0.2
      },
      {
        "value": 0.5,
        "unit": "percent",
        "source_value": 0.005
      }
    ],
    "mechanic_tags": [
      "spd",
      "memosprite"
    ],
    "description_sha256": "b018e17373c8b0b27b7401b52a97041c2cb9ecc378a575c08a6dc75b03f7652f"
  },
  {
    "eidolon": 5,
    "eidolon_id": 151205,
    "name": "To Chase the Dawn Anew",
    "parameters": [],
    "mechanic_tags": [
      "atk",
      "memosprite"
    ],
    "description_sha256": "135e4150baec09601cf8b15c7c30cef3bc6c4cf00c6306e6c89c87894637dd5c"
  },
  {
    "eidolon": 6,
    "eidolon_id": 151206,
    "name": "A Song Yet Unnamed",
    "parameters": [
      {
        "value": 100,
        "unit": "percent",
        "source_value": 1
      },
      {
        "value": 140,
        "unit": "scalar",
        "source_value": 140
      },
      {
        "value": 0,
        "unit": "scalar",
        "source_value": 0
      }
    ],
    "mechanic_tags": [
      "energy",
      "dmg",
      "memosprite"
    ],
    "description_sha256": "01723cef61ec7f1d7bbe952ce8523ff86fa2e848c995f63ac224544e0fb0878c"
  }
]
```

## Data notes

- Numeric arrays and raw combat fields are preserved for programmatic use. Percentage placeholders are converted to percentage points while `source_value` retains the original decimal.
- `computed_stats_level_80` uses `stage_6_base + per_level_add × 79`; raw stage data remains represented by the level-1 and source fields.
- Long source prose is not reproduced. Names, structured numeric values, mechanic tags, source URLs, and SHA-256 fingerprints are retained for lawful change detection.
- `toughness_stance_list_raw`, `skill_point_need_raw`, and `skill_point_add_raw` deliberately retain source semantics without reinterpretation.
