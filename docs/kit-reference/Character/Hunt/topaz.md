---
schema_version: "1.0.0"
unit_id: 38
name: "Topaz & Numby"
slug: "topaz"
rarity: 5
element: "Fire"
path: "Hunt"
role: "Sub DPS"
affiliation: "Interastral Peace Corporation"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/topaz"
source_record_updated_at: "March 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Topaz & Numby

## Character record

```json
{
  "unit_id": 38,
  "name": "Topaz & Numby",
  "slug": "topaz",
  "rarity": "5",
  "element": "Fire",
  "path": "Hunt",
  "default_role": "Sub DPS",
  "affiliation": "Interastral Peace Corporation",
  "release_date": "October 27th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 126.72,
    "def_base": 56.1,
    "atk_base": 84.48,
    "speed_base": 110
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "dmg_fire",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "crit_rate",
      "value": 12
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Sam Slade",
    "kr": " 방시우 (Bang Siu)",
    "jpn": "南條愛乃 (Nanjō Yoshino)",
    "cn": "陆敏悦 (Mace)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/topaz",
  "source_record_updated_at": "March 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `111201` | Deficit... | Basic ATK | Single Target |
| `skill` | `111202` | Difficulty Paying? | Skill | Single Target |
| `ult` | `111203` | Turn a Profit! | Ultimate | Enhance |
| `talent` | `111204` | Trotter Market!? | Talent | Single Target |
| `technique` | `111207` | Explicit Subsidy | Technique | Enhance |

## Ability records

### Deficit...

```json
{
  "ability_id": "111201",
  "slot": "basic",
  "name": "Deficit...",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
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
  "description_sha256": "8c3e624c9dd4234a05ef486798c312b9ef8043272c4b00bb8ef855cda6183e78",
  "icon_path": "icon/skill/1112_basic_atk.png"
}
```

### Difficulty Paying?

```json
{
  "ability_id": "111202",
  "slot": "skill",
  "name": "Difficulty Paying?",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121.88,
          "unit": "percent"
        },
        "p2": {
          "value": 40.63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 43.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 140.63,
          "unit": "percent"
        },
        "p2": {
          "value": 46.88,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 172.5,
          "unit": "percent"
        },
        "p2": {
          "value": 57.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7d1c710bbb65a67b6eda93e5c02206aa57acc00f2e937f8564f36c40ee144787",
  "icon_path": "icon/skill/1112_skill.png"
}
```

### Turn a Profit!

```json
{
  "ability_id": "111203",
  "slot": "ult",
  "name": "Turn a Profit!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": null,
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
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 12.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 82.5,
          "unit": "percent"
        },
        "p2": {
          "value": 13.75,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 18.75,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 121.88,
          "unit": "percent"
        },
        "p2": {
          "value": 20.31,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 21.88,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 140.63,
          "unit": "percent"
        },
        "p2": {
          "value": 23.44,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 157.5,
          "unit": "percent"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 165,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 172.5,
          "unit": "percent"
        },
        "p2": {
          "value": 28.75,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
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
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 31.25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "e2684e3592e3bd9d90de73e6ea0699cd3f794c2a24471f27fa3b0bd0a10fa641",
  "icon_path": "icon/skill/1112_ultimate.png"
}
```

### Trotter Market!?

```json
{
  "ability_id": "111204",
  "slot": "talent",
  "name": "Trotter Market!?",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg",
    "action_advance",
    "follow_up",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 121.88,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 131.25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 140.63,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 157.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 165,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 172.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "scalar"
        },
        "p2": {
          "value": 187.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "adfc05b98c75834d2763bfa3c1b5a273e858ea59597c0439f2c89ecc08b5f255",
  "icon_path": "icon/skill/1112_talent.png"
}
```

### Explicit Subsidy

```json
{
  "ability_id": "111207",
  "slot": "technique",
  "name": "Explicit Subsidy",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 10000,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "46e81cc436544c96301be12c1d1dc0d38a8c1bb2ce169ba24cab8e7423a1f882",
  "icon_path": "icon/skill/1112_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Overdraft",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [],
    "description_sha256": "75fee9e58fd3864b7e12ed09260d6f8a246ced0214fe7633c245088d8aa99f1f"
  },
  {
    "requirement": "A4",
    "name": "Financial Turmoil",
    "mechanic_tags": [
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "7bc12e16ad2398498aa84a82f48dde92f40907bfbe3f4919b9ead3cbfe08d7ed"
  },
  {
    "requirement": "A6",
    "name": "Stonks Market",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "d048a82072d5672e31d7a6d89dfa986a8335aede9bdf139470cc77f647fb1ede"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Future Market",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "25%",
      "2"
    ],
    "description_sha256": "35ecff012f8003adfbc27501d433d724ee457950cf83eab1caf22adfe08422dc"
  },
  {
    "eidolon": 2,
    "name": " Bona Fide Acquisition",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "add2abdd157886132183f4abc6e09051d2ff96c4c1d3dc9171b61e90ef980195"
  },
  {
    "eidolon": 3,
    "name": "Seize the Big and Free the Small",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "311d42dde2d7bf6c4a627823a42a2c5441ae282e5abb36042eba435acdec6ef8"
  },
  {
    "eidolon": 4,
    "name": "Agile Operation",
    "mechanic_tags": [],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "35fd1abf6edadab36dc5a42043737363a86a319b8ee524e341dcd557ed3eef88"
  },
  {
    "eidolon": 5,
    "name": " Inflationary Demand",
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
    "name": "Incentive Mechanism",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "1",
      "10%"
    ],
    "description_sha256": "d89a13905e76858f27a23e5b5deda16d665a3e34d5d9d9e1b341f626b5b65a60"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
