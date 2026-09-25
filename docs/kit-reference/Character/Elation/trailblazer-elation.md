---
schema_version: "1.0.0"
unit_id: 90
name: "Trailblazer • Elation"
slug: "trailblazer-elation"
rarity: 5
element: "Lightning"
path: "Elation"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/trailblazer-elation"
source_record_updated_at: "May 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Trailblazer • Elation

## Character record

```json
{
  "unit_id": 90,
  "name": "Trailblazer • Elation",
  "slug": "trailblazer-elation",
  "rarity": "5",
  "element": "Lightning",
  "path": "Elation",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "April 22nd, 2026",
  "is_released": true,
  "ultimate_energy_cost": "160",
  "base_stats": {
    "hp_base": 148,
    "def_base": 85.8,
    "atk_base": 63.36,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "critDmg",
      "value": 13.3
    },
    "traceStat3": {
      "stat": "critRate",
      "value": 12
    }
  },
  "voice_actors": {
    "en": "Rachael Chau | Caleb Yen",
    "kr": "Kim Ha-ru (김하루) | Kim Myung-jun (김명준)",
    "jpn": "Ishikawa Yui (石川 由依) | Enoki Junya (榎木 淳弥)",
    "cn": "Chen Tingting (陈婷婷) | Qin Juge (秦且歌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/trailblazer-elation",
  "source_record_updated_at": "May 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `800901` | Make Some Noise | Basic ATK | Single Target |
| `skill` | `800902` | Let the Storm Rage On | Skill | AoE |
| `ult` | `800903` | May the Trailblaze Fly You Starward | Ultimate | Support |
| `talent` | `800904` | That Smile Hits Different | Talent | Support |
| `technique` | `800907` | Immortal Third Strike | Technique | Enhance |
| `supplementary` | `800910` | I Said "Elation," Did I Stutter? | Elation Skill | AoE |

## Ability records

### Make Some Noise

```json
{
  "ability_id": "800901",
  "slot": "basic",
  "name": "Make Some Noise",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
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
  "description_sha256": "2d4e5771da1407486c440bde3f4cbfedfe3a4042dbe827865ec4abe664953af7",
  "icon_path": null
}
```

### Let the Storm Rage On

```json
{
  "ability_id": "800902",
  "slot": "skill",
  "name": "Let the Storm Rage On",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Lightning",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
  "description_sha256": "66960a0eda8f118dca3e9d7c7fcf5fbe03542ba6dd8477f24b024b30a34343bb",
  "icon_path": null
}
```

### May the Trailblaze Fly You Starward

```json
{
  "ability_id": "800903",
  "slot": "ult",
  "name": "May the Trailblaze Fly You Starward",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": "160",
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
    "crit_dmg",
    "dmg",
    "action_advance",
    "debuff",
    "buff",
    "elation"
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
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 42.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "567d7a78ee74d0fc7c1b9a8bed8f3c1c62573b991bcc1121350335acd0e2ba26",
  "icon_path": null
}
```

### That Smile Hits Different

```json
{
  "ability_id": "800904",
  "slot": "talent",
  "name": "That Smile Hits Different",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "dmg",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 26.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 34.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "32915fd1ab6bb473d0bebe3cdfb247c10a2c032deca9f27db0dd19f6bd0a841f",
  "icon_path": null
}
```

### Immortal Third Strike

```json
{
  "ability_id": "800907",
  "slot": "technique",
  "name": "Immortal Third Strike",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "50eccc004edda77e654198d593c1b0a12d00a62b7cc467721c610591030f13bf",
  "icon_path": null
}
```

### I Said "Elation," Did I Stutter?

```json
{
  "ability_id": "800910",
  "slot": "supplementary",
  "name": "I Said \"Elation,\" Did I Stutter?",
  "type_code": "Elation Skill",
  "type_label": "Elation Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 12,
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
    "dmg",
    "elation"
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
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 11,
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
          "value": 12,
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
          "value": 13,
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
          "value": 14,
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
          "value": 15,
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
          "value": 16.25,
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
          "value": 17.5,
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
          "value": 18.75,
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
          "value": 20,
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
          "value": 21,
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
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "1d1e3e471100393ba686f0decd32ac4fc5a4f73f26bfd4e5acf61a953f6c070f",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "On Cloud Nine",
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "numeric_tokens": [
      "200",
      "1000",
      "10%",
      "60%"
    ],
    "description_sha256": "c03acc0508744ba6fab548a19bd0964c0f5bce763f24b145a8bd869465eeb42a"
  },
  {
    "requirement": "A4",
    "name": "Screw It, We Ball",
    "mechanic_tags": [
      "crit_rate",
      "skill_points"
    ],
    "numeric_tokens": [
      "15%",
      "1"
    ],
    "description_sha256": "bea4d511c33da83b563d1a15cea97605f42cd6d6b480e66fa1617f313f627782"
  },
  {
    "requirement": "A6",
    "name": "Aha, Sic 'Em!",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "466a8de178ca57eb47b17ce79e9ac5a640f782be1e588a89816293a82ba7aeb9"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Believe In the Light",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "3"
    ],
    "description_sha256": "a1eb5e2afb4bdb7555b399fff62901820334fb55687439261a8b088388ca7ca2"
  },
  {
    "eidolon": 2,
    "name": "History in the Making...",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "12%",
      "2"
    ],
    "description_sha256": "3082e1a9dcf30f8c00773b5c86c9d55823f5a87489456e1d8070f1109db30a83"
  },
  {
    "eidolon": 3,
    "name": "Into the Spotlight",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "15"
    ],
    "description_sha256": "4eff7a0b39dd1c4f26ebdffb9a77d1ce82e30a14dbe2c1d5b0a9c28a66c1cf9f"
  },
  {
    "eidolon": 4,
    "name": "Save the World. Just Because.",
    "mechanic_tags": [
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "730e48a1502066c73a2fe5779fe08d79c49563fd081f21ae140ccfa62fc600ae"
  },
  {
    "eidolon": 5,
    "name": "Love & Courage: Always in Style",
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "15"
    ],
    "description_sha256": "739de4cd025749274ffd70e501e9900a51caa6e27396b57030ae434e5f1c181f"
  },
  {
    "eidolon": 6,
    "name": "The Cosmic Legend Cometh!",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "100%",
      "3"
    ],
    "description_sha256": "2928c08be5dbe99ab04b88b1b8fe6d817b91a77ddab5be0b6cccbbc682bebbc3"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
