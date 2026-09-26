---
schema_version: "1.1.0"
unit_id: 1513
name: "Aventurine • Waveflair"
slug: "aventurine-waveflair"
rarity: 5
element: "Quantum"
path: "Elation"
released: true
source_page: "https://www.prydwen.gg/star-rail/characters/aventurine-waveflair"
structured_source: "https://static.nanoka.cc/hsr/4.5.54/en/character/1513.json"
data_version: "4.5.54"
dataset_snapshot: "2026-09-26"
---

# Aventurine • Waveflair

## Character record

```json
{
  "unit_id": 1513,
  "name": "Aventurine • Waveflair",
  "slug": "aventurine-waveflair",
  "rarity": 5,
  "element": "Quantum",
  "path": "Elation",
  "ultimate_energy_cost": 130,
  "release_timestamp": 1789203600,
  "release_datetime_utc": "2026-09-12T09:00:00+00:00",
  "released_status": "released",
  "base_stats_level_1": {
    "attack_base": 66,
    "attack_add": 3.3,
    "defence_base": 82.5,
    "defence_add": 4.125,
    "hp_base": 158.4,
    "hp_add": 7.92,
    "speed_base": 107,
    "critical_chance": 0.05,
    "critical_damage": 0.5,
    "base_aggro": 100
  },
  "computed_stats_level_80": {
    "hp": 1164.24,
    "atk": 485.1,
    "def": 606.375,
    "spd": 107,
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
  "memosprite_core": {},
  "source_page": "https://www.prydwen.gg/star-rail/characters/aventurine-waveflair",
  "structured_source": "https://static.nanoka.cc/hsr/4.5.54/en/character/1513.json",
  "data_version": "4.5.54"
}
```

## Ability index

| Owner | Type | ID | Name | Levels |
|---|---|---:|---|---:|
| `character` | `Basic ATK` | `151301` | Dead Center, the Torrent Hits | 10 |
| `character` | `Skill` | `151302` | Kill Shot, the Sands Boil | 15 |
| `character` | `Ultimate` | `151303` | Grand Slam, Crest That High Tide | 15 |
| `character` | `Talent` | `151304` | Ante Up, the Abyss Answers | 15 |
| `character` | `Technique` | `151307` | Make Waves in Still Waters | 1 |
| `character` | `Elation Skill` | `151320` | Cheers! To Summer's Blaze | 15 |
| `character` | `Elation Skill` | `151321` | All In! To Summer's Blaze | 15 |

## Ability records

### Dead Center, the Torrent Hits

```json
{
  "ability_id": "151301",
  "slot": "basic_atk",
  "owner": "character",
  "name": "Dead Center, the Torrent Hits",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "element": "Quantum",
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
    "atk",
    "dmg"
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
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
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
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent",
          "source_value": 0.8
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent",
          "source_value": 0.9
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
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent",
          "source_value": 1.1
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent",
          "source_value": 1.2
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent",
          "source_value": 1.3
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent",
          "source_value": 1.4
        }
      }
    }
  ],
  "extra_terms": [],
  "description_sha256": "7ef72a20ce567b4624c8e4da88ac841c0e029b39a4021757459595980f486968"
}
```

### Kill Shot, the Sands Boil

```json
{
  "ability_id": "151302",
  "slot": "skill",
  "owner": "character",
  "name": "Kill Shot, the Sands Boil",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "element": "Quantum",
  "energy_gain": 30,
  "skill_point_need_raw": 1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    30,
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
    },
    "p3": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent",
          "source_value": 1.2
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent",
          "source_value": 1.32
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent",
          "source_value": 1.44
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent",
          "source_value": 1.56
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent",
          "source_value": 1.68
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent",
          "source_value": 1.8
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 195,
          "unit": "percent",
          "source_value": 1.95
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent",
          "source_value": 2.1
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent",
          "source_value": 2.25
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent",
          "source_value": 2.4
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 252,
          "unit": "percent",
          "source_value": 2.52
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent",
          "source_value": 2.64
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 276,
          "unit": "percent",
          "source_value": 2.76
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent",
          "source_value": 2.88
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent",
          "source_value": 3
        },
        "p2": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        },
        "p3": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000027",
      "name": "Punchline",
      "description_sha256": "8866320b85246502805badeb829c3875266f8219205f778524266a11e02dd41b",
      "parameters": []
    }
  ],
  "description_sha256": "5a28a53ac76fcdd420dab1a26a39534a45f547bbc55f304b1e812653a7573099"
}
```

### Grand Slam, Crest That High Tide

```json
{
  "ability_id": "151303",
  "slot": "ultimate",
  "owner": "character",
  "name": "Grand Slam, Crest That High Tide",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "element": "Quantum",
  "energy_gain": 5,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    60,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p3": {
      "format": "i",
      "unit": "scalar"
    },
    "p2": {
      "format": "i",
      "unit": "scalar"
    },
    "p4": {
      "format": "i",
      "unit": "percent"
    },
    "p5": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent",
          "source_value": 2.4
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 12,
          "unit": "percent",
          "source_value": 0.12
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 256,
          "unit": "percent",
          "source_value": 2.56
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 13.8,
          "unit": "percent",
          "source_value": 0.138
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 272,
          "unit": "percent",
          "source_value": 2.72
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 15.6,
          "unit": "percent",
          "source_value": 0.156
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent",
          "source_value": 2.88
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 17.4,
          "unit": "percent",
          "source_value": 0.174
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent",
          "source_value": 3.04
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 19.2,
          "unit": "percent",
          "source_value": 0.192
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 320,
          "unit": "percent",
          "source_value": 3.2
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 21,
          "unit": "percent",
          "source_value": 0.21
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 340,
          "unit": "percent",
          "source_value": 3.4
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 23.25,
          "unit": "percent",
          "source_value": 0.2325
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent",
          "source_value": 3.6
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 25.5,
          "unit": "percent",
          "source_value": 0.255
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent",
          "source_value": 3.8
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 27.75,
          "unit": "percent",
          "source_value": 0.2775
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 400,
          "unit": "percent",
          "source_value": 4
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 30,
          "unit": "percent",
          "source_value": 0.3
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 416,
          "unit": "percent",
          "source_value": 4.16
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 31.8,
          "unit": "percent",
          "source_value": 0.318
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 432,
          "unit": "percent",
          "source_value": 4.32
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 33.6,
          "unit": "percent",
          "source_value": 0.336
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 448,
          "unit": "percent",
          "source_value": 4.48
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 35.4,
          "unit": "percent",
          "source_value": 0.354
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 464,
          "unit": "percent",
          "source_value": 4.64
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 37.2,
          "unit": "percent",
          "source_value": 0.372
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent",
          "source_value": 4.8
        },
        "p2": {
          "value": 8,
          "unit": "scalar",
          "source_value": 8
        },
        "p3": {
          "value": 6,
          "unit": "scalar",
          "source_value": 6
        },
        "p4": {
          "value": 39,
          "unit": "percent",
          "source_value": 0.39
        },
        "p5": {
          "value": 4,
          "unit": "scalar",
          "source_value": 4
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000027",
      "name": "Punchline",
      "description_sha256": "8866320b85246502805badeb829c3875266f8219205f778524266a11e02dd41b",
      "parameters": []
    }
  ],
  "description_sha256": "579e2d2bf251e9901eaf2bc8ae902e1c1f81f3042660949553f49c59eaa16a1e"
}
```

### Ante Up, the Abyss Answers

```json
{
  "ability_id": "151304",
  "slot": "talent",
  "owner": "character",
  "name": "Ante Up, the Abyss Answers",
  "type_code": null,
  "type_label": "Talent",
  "effect_code": "Enhance",
  "element": "Quantum",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    0,
    0,
    0
  ],
  "parameter_placeholders": {
    "p7": {
      "format": "i",
      "unit": "scalar"
    },
    "p6": {
      "format": "i",
      "unit": "scalar"
    },
    "p4": {
      "format": "i",
      "unit": "scalar"
    },
    "p1": {
      "format": "i",
      "unit": "scalar"
    },
    "p5": {
      "format": "i",
      "unit": "scalar"
    },
    "p2": {
      "format": "i",
      "unit": "percent"
    },
    "p3": {
      "format": "i",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_level": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 20,
          "unit": "percent",
          "source_value": 0.2
        },
        "p3": {
          "value": 36,
          "unit": "percent",
          "source_value": 0.36
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 22,
          "unit": "percent",
          "source_value": 0.22
        },
        "p3": {
          "value": 39.6,
          "unit": "percent",
          "source_value": 0.396
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 24,
          "unit": "percent",
          "source_value": 0.24
        },
        "p3": {
          "value": 43.2,
          "unit": "percent",
          "source_value": 0.432
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 26,
          "unit": "percent",
          "source_value": 0.26
        },
        "p3": {
          "value": 46.8,
          "unit": "percent",
          "source_value": 0.468
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 28,
          "unit": "percent",
          "source_value": 0.28
        },
        "p3": {
          "value": 50.4,
          "unit": "percent",
          "source_value": 0.504
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 30,
          "unit": "percent",
          "source_value": 0.3
        },
        "p3": {
          "value": 54,
          "unit": "percent",
          "source_value": 0.54
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 32.5,
          "unit": "percent",
          "source_value": 0.325
        },
        "p3": {
          "value": 58.5,
          "unit": "percent",
          "source_value": 0.585
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 35,
          "unit": "percent",
          "source_value": 0.35
        },
        "p3": {
          "value": 63,
          "unit": "percent",
          "source_value": 0.63
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 37.5,
          "unit": "percent",
          "source_value": 0.375
        },
        "p3": {
          "value": 67.5,
          "unit": "percent",
          "source_value": 0.675
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 40,
          "unit": "percent",
          "source_value": 0.4
        },
        "p3": {
          "value": 72,
          "unit": "percent",
          "source_value": 0.72
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 42,
          "unit": "percent",
          "source_value": 0.42
        },
        "p3": {
          "value": 75.6,
          "unit": "percent",
          "source_value": 0.756
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 44,
          "unit": "percent",
          "source_value": 0.44
        },
        "p3": {
          "value": 79.2,
          "unit": "percent",
          "source_value": 0.792
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 46,
          "unit": "percent",
          "source_value": 0.46
        },
        "p3": {
          "value": 82.8,
          "unit": "percent",
          "source_value": 0.828
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 48,
          "unit": "percent",
          "source_value": 0.48
        },
        "p3": {
          "value": 86.4,
          "unit": "percent",
          "source_value": 0.864
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p2": {
          "value": 50,
          "unit": "percent",
          "source_value": 0.5
        },
        "p3": {
          "value": 90,
          "unit": "percent",
          "source_value": 0.9
        },
        "p4": {
          "value": 30,
          "unit": "scalar",
          "source_value": 30
        },
        "p5": {
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        },
        "p6": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        },
        "p7": {
          "value": 1,
          "unit": "scalar",
          "source_value": 1
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000029",
      "name": "Certified Banger",
      "description_sha256": "7eab914906dd4f89d59f01c72ee850388f58f4f5686b4e2d9ac47f11b97d6f92",
      "parameters": []
    },
    {
      "id": "10000027",
      "name": "Punchline",
      "description_sha256": "8866320b85246502805badeb829c3875266f8219205f778524266a11e02dd41b",
      "parameters": []
    },
    {
      "id": "10000028",
      "name": "Elation DMG",
      "description_sha256": "1ebfe69a35afb342af27e14a0c517a9b02239292e3c19bb8abc68541366803c5",
      "parameters": []
    }
  ],
  "description_sha256": "6a5c68a3b863362075dd04592e4007a0bbbac7e97de69f22da1f6fe23a052448"
}
```

### Make Waves in Still Waters

```json
{
  "ability_id": "151307",
  "slot": "technique",
  "owner": "character",
  "name": "Make Waves in Still Waters",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "element": "Quantum",
  "energy_gain": null,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    60,
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
    },
    "p3": {
      "format": "i",
      "unit": "scalar"
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "elation"
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
          "value": 20,
          "unit": "scalar",
          "source_value": 20
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000029",
      "name": "Certified Banger",
      "description_sha256": "7eab914906dd4f89d59f01c72ee850388f58f4f5686b4e2d9ac47f11b97d6f92",
      "parameters": []
    }
  ],
  "description_sha256": "aacec0fa7bd72b02eefadec89d1fb06a572d1721a8849f5ea248118c0cf1af43"
}
```

### Cheers! To Summer's Blaze

```json
{
  "ability_id": "151320",
  "slot": "elation_skill",
  "owner": "character",
  "name": "Cheers! To Summer's Blaze",
  "type_code": "ElationDamage",
  "type_label": "Elation Skill",
  "effect_code": "AoEAttack",
  "element": "Quantum",
  "energy_gain": 5,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    10,
    30,
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
    },
    "p3": {
      "format": "f1",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "dmg",
    "elation"
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
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 9,
          "unit": "percent",
          "source_value": 0.09
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent",
          "source_value": 0.33
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 9.9,
          "unit": "percent",
          "source_value": 0.099
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent",
          "source_value": 0.36
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 10.8,
          "unit": "percent",
          "source_value": 0.108
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent",
          "source_value": 0.39
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 11.7,
          "unit": "percent",
          "source_value": 0.117
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent",
          "source_value": 0.42
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 12.6,
          "unit": "percent",
          "source_value": 0.126
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent",
          "source_value": 0.45
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 13.5,
          "unit": "percent",
          "source_value": 0.135
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 48.75,
          "unit": "percent",
          "source_value": 0.4875
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 14.625,
          "unit": "percent",
          "source_value": 0.14625
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent",
          "source_value": 0.525
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 15.75,
          "unit": "percent",
          "source_value": 0.1575
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 56.25,
          "unit": "percent",
          "source_value": 0.5625
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 16.875,
          "unit": "percent",
          "source_value": 0.16875
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 18,
          "unit": "percent",
          "source_value": 0.18
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent",
          "source_value": 0.63
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 18.9,
          "unit": "percent",
          "source_value": 0.189
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent",
          "source_value": 0.66
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 19.8,
          "unit": "percent",
          "source_value": 0.198
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 69,
          "unit": "percent",
          "source_value": 0.69
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 20.7,
          "unit": "percent",
          "source_value": 0.207
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent",
          "source_value": 0.72
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 21.6,
          "unit": "percent",
          "source_value": 0.216
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent",
          "source_value": 0.75
        },
        "p2": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p3": {
          "value": 22.5,
          "unit": "percent",
          "source_value": 0.225
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000028",
      "name": "Elation DMG",
      "description_sha256": "1ebfe69a35afb342af27e14a0c517a9b02239292e3c19bb8abc68541366803c5",
      "parameters": []
    }
  ],
  "description_sha256": "8dacbfc5b3d549c6c02a95ed462818c1520c80b04f55ce83c2d3dadb4df970f7"
}
```

### All In! To Summer's Blaze

```json
{
  "ability_id": "151321",
  "slot": "elation_skill",
  "owner": "character",
  "name": "All In! To Summer's Blaze",
  "type_code": "ElationDamage",
  "type_label": "Elation Skill",
  "effect_code": "AoEAttack",
  "element": "Quantum",
  "energy_gain": 5,
  "skill_point_need_raw": -1,
  "skill_point_add_raw": null,
  "toughness_stance_list_raw": [
    15,
    60,
    0
  ],
  "parameter_placeholders": {
    "p1": {
      "format": "i",
      "unit": "percent"
    },
    "p3": {
      "format": "i",
      "unit": "scalar"
    },
    "p4": {
      "format": "f1",
      "unit": "percent"
    },
    "p2": {
      "format": "f1",
      "unit": "percent"
    }
  },
  "mechanic_tags": [
    "dmg",
    "elation"
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
          "value": 10.5,
          "unit": "percent",
          "source_value": 0.105
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 9,
          "unit": "percent",
          "source_value": 0.09
        }
      }
    },
    {
      "source_level": 2,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent",
          "source_value": 0.33
        },
        "p2": {
          "value": 11.55,
          "unit": "percent",
          "source_value": 0.1155
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 9.9,
          "unit": "percent",
          "source_value": 0.099
        }
      }
    },
    {
      "source_level": 3,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent",
          "source_value": 0.36
        },
        "p2": {
          "value": 12.6,
          "unit": "percent",
          "source_value": 0.126
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 10.8,
          "unit": "percent",
          "source_value": 0.108
        }
      }
    },
    {
      "source_level": 4,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent",
          "source_value": 0.39
        },
        "p2": {
          "value": 13.65,
          "unit": "percent",
          "source_value": 0.1365
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 11.7,
          "unit": "percent",
          "source_value": 0.117
        }
      }
    },
    {
      "source_level": 5,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent",
          "source_value": 0.42
        },
        "p2": {
          "value": 14.7,
          "unit": "percent",
          "source_value": 0.147
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 12.6,
          "unit": "percent",
          "source_value": 0.126
        }
      }
    },
    {
      "source_level": 6,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent",
          "source_value": 0.45
        },
        "p2": {
          "value": 15.75,
          "unit": "percent",
          "source_value": 0.1575
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 13.5,
          "unit": "percent",
          "source_value": 0.135
        }
      }
    },
    {
      "source_level": 7,
      "parameters": {
        "p1": {
          "value": 48.75,
          "unit": "percent",
          "source_value": 0.4875
        },
        "p2": {
          "value": 17.0625,
          "unit": "percent",
          "source_value": 0.170625
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 14.625,
          "unit": "percent",
          "source_value": 0.14625
        }
      }
    },
    {
      "source_level": 8,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent",
          "source_value": 0.525
        },
        "p2": {
          "value": 18.375,
          "unit": "percent",
          "source_value": 0.18375
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 15.75,
          "unit": "percent",
          "source_value": 0.1575
        }
      }
    },
    {
      "source_level": 9,
      "parameters": {
        "p1": {
          "value": 56.25,
          "unit": "percent",
          "source_value": 0.5625
        },
        "p2": {
          "value": 19.6875,
          "unit": "percent",
          "source_value": 0.196875
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 16.875,
          "unit": "percent",
          "source_value": 0.16875
        }
      }
    },
    {
      "source_level": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent",
          "source_value": 0.6
        },
        "p2": {
          "value": 21,
          "unit": "percent",
          "source_value": 0.21
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 18,
          "unit": "percent",
          "source_value": 0.18
        }
      }
    },
    {
      "source_level": 11,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent",
          "source_value": 0.63
        },
        "p2": {
          "value": 22.05,
          "unit": "percent",
          "source_value": 0.2205
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 18.9,
          "unit": "percent",
          "source_value": 0.189
        }
      }
    },
    {
      "source_level": 12,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent",
          "source_value": 0.66
        },
        "p2": {
          "value": 23.1,
          "unit": "percent",
          "source_value": 0.231
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 19.8,
          "unit": "percent",
          "source_value": 0.198
        }
      }
    },
    {
      "source_level": 13,
      "parameters": {
        "p1": {
          "value": 69,
          "unit": "percent",
          "source_value": 0.69
        },
        "p2": {
          "value": 24.15,
          "unit": "percent",
          "source_value": 0.2415
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 20.7,
          "unit": "percent",
          "source_value": 0.207
        }
      }
    },
    {
      "source_level": 14,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent",
          "source_value": 0.72
        },
        "p2": {
          "value": 25.2,
          "unit": "percent",
          "source_value": 0.252
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 21.6,
          "unit": "percent",
          "source_value": 0.216
        }
      }
    },
    {
      "source_level": 15,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent",
          "source_value": 0.75
        },
        "p2": {
          "value": 26.25,
          "unit": "percent",
          "source_value": 0.2625
        },
        "p3": {
          "value": 10,
          "unit": "scalar",
          "source_value": 10
        },
        "p4": {
          "value": 22.5,
          "unit": "percent",
          "source_value": 0.225
        }
      }
    }
  ],
  "extra_terms": [
    {
      "id": "10000028",
      "name": "Elation DMG",
      "description_sha256": "1ebfe69a35afb342af27e14a0c517a9b02239292e3c19bb8abc68541366803c5",
      "parameters": []
    }
  ],
  "description_sha256": "afd194cf8d5f3773f4f8913f64a730efd1969d073c60b44a52cdeb4ef2dfa53c"
}
```

## Major traces

```json
[
  {
    "anchor": "point06",
    "point_id": 1513101,
    "trace_type": "major",
    "name": "Party in Perfect Paradise",
    "unlock_ascension": 2,
    "unlock_level": null,
    "parameters": [
      140,
      30,
      1,
      1,
      200
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "spd",
      "elation"
    ],
    "description_sha256": "bdc98d0fee2c5936053658357e31c74330f1f08a24f32ca1f6e294547678a5f4"
  },
  {
    "anchor": "point07",
    "point_id": 1513102,
    "trace_type": "major",
    "name": "Revel in Raging Tides",
    "unlock_ascension": 4,
    "unlock_level": null,
    "parameters": [
      80,
      2,
      25,
      1,
      20
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "atk",
      "spd",
      "dmg",
      "follow_up",
      "elation"
    ],
    "description_sha256": "8f9466735ba2c4cbbaa729b2f30c807269cc3068a384016e42e1b67c41465f71"
  },
  {
    "anchor": "point08",
    "point_id": 1513103,
    "trace_type": "major",
    "name": "Sift Through Gilded Dreams",
    "unlock_ascension": 6,
    "unlock_level": null,
    "parameters": [
      48,
      48,
      3,
      2,
      6
    ],
    "status_add_list": [],
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "description_sha256": "af0b045711af9bc5e7f7b8f2eae7e8d7a57216d5d4782f3c36aebff2268a9cb6"
  }
]
```

## Minor traces

```json
[
  {
    "anchor": "point09",
    "point_id": 1513201,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": null,
    "unlock_level": 1,
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
    "anchor": "point10",
    "point_id": 1513202,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": 2,
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
    "anchor": "point11",
    "point_id": 1513203,
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
    "anchor": "point12",
    "point_id": 1513204,
    "trace_type": "minor",
    "name": "Elation Boost",
    "unlock_ascension": 3,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "ElationDamageAddedRatioBase",
        "value": 0.04,
        "name": "Elation"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point13",
    "point_id": 1513205,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": 4,
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
    "anchor": "point14",
    "point_id": 1513206,
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
    "anchor": "point15",
    "point_id": 1513207,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": 5,
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
    "anchor": "point16",
    "point_id": 1513208,
    "trace_type": "minor",
    "name": "Elation Boost",
    "unlock_ascension": 6,
    "unlock_level": null,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "ElationDamageAddedRatioBase",
        "value": 0.06,
        "name": "Elation"
      }
    ],
    "mechanic_tags": [],
    "description_sha256": null
  },
  {
    "anchor": "point17",
    "point_id": 1513209,
    "trace_type": "minor",
    "name": "SPD Boost",
    "unlock_ascension": null,
    "unlock_level": 75,
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
  },
  {
    "anchor": "point18",
    "point_id": 1513210,
    "trace_type": "minor",
    "name": "CRIT Rate Boost",
    "unlock_ascension": null,
    "unlock_level": 80,
    "parameters": [],
    "status_add_list": [
      {
        "property_type": "CriticalChanceBase",
        "value": 0.053,
        "name": "CRIT Rate"
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
    "eidolon_id": 151301,
    "name": "A Holiday on the Line",
    "parameters": [
      {
        "value": 24,
        "unit": "percent",
        "source_value": 0.24
      }
    ],
    "mechanic_tags": [
      "res_pen"
    ],
    "description_sha256": "6bd168354865ed847d6f26b0acb61d49f6749f86057cf353561e2841970e2fbd"
  },
  {
    "eidolon": 2,
    "eidolon_id": 151302,
    "name": "Idle as the Turning Tide",
    "parameters": [
      {
        "value": 50,
        "unit": "scalar",
        "source_value": 50
      },
      {
        "value": 4,
        "unit": "scalar",
        "source_value": 4
      }
    ],
    "mechanic_tags": [
      "elation"
    ],
    "description_sha256": "6cdc228506ef94a4ead13537b704c3ca27405d4805e282d440b5963e7eda6317"
  },
  {
    "eidolon": 3,
    "eidolon_id": 151303,
    "name": "A Rendezvous Served Chilled",
    "parameters": [],
    "mechanic_tags": [
      "elation"
    ],
    "description_sha256": "8a0730cb4752c33ed6a55cf9a878703ee048063e466de67c8c19837d64ba794c"
  },
  {
    "eidolon": 4,
    "eidolon_id": 151304,
    "name": "Sunlight Runs No Tab",
    "parameters": [
      {
        "value": 18,
        "unit": "percent",
        "source_value": 0.18
      },
      {
        "value": 3,
        "unit": "scalar",
        "source_value": 3
      }
    ],
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "description_sha256": "a9a88b38e67f26cee14889f3a6420d288286ea67802ac26044ef5aefd5c42821"
  },
  {
    "eidolon": 5,
    "eidolon_id": 151305,
    "name": "Into the Eye of the Jackpot",
    "parameters": [],
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "description_sha256": "8e34c54e7b18907eb9d591dfce9641364ece5ea0fa502173809cdfdac4ed1720"
  },
  {
    "eidolon": 6,
    "eidolon_id": 151306,
    "name": "The Past in Fast Lane",
    "parameters": [
      {
        "value": 2,
        "unit": "scalar",
        "source_value": 2
      },
      {
        "value": 25,
        "unit": "percent",
        "source_value": 0.25
      }
    ],
    "mechanic_tags": [
      "dmg",
      "elation"
    ],
    "description_sha256": "950f77cc45e2e0310212681d8fa3d8b40441ba2bd28788d1a511aae97549cff0"
  }
]
```

## Data notes

- Numeric arrays and raw combat fields are preserved for programmatic use. Percentage placeholders are converted to percentage points while `source_value` retains the original decimal.
- `computed_stats_level_80` uses `stage_6_base + per_level_add × 79`; raw stage data remains represented by the level-1 and source fields.
- Long source prose is not reproduced. Names, structured numeric values, mechanic tags, source URLs, and SHA-256 fingerprints are retained for lawful change detection.
- `toughness_stance_list_raw`, `skill_point_need_raw`, and `skill_point_add_raw` deliberately retain source semantics without reinterpretation.
