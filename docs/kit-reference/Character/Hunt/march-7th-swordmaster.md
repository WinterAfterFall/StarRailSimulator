---
schema_version: "1.0.0"
unit_id: 58
name: "March 7th • The Hunt"
slug: "march-7th-swordmaster"
rarity: 4
element: "Imaginary"
path: "Hunt"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/march-7th-swordmaster"
source_record_updated_at: "September 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# March 7th • The Hunt

## Character record

```json
{
  "unit_id": 58,
  "name": "March 7th • The Hunt",
  "slug": "march-7th-swordmaster",
  "rarity": "4",
  "element": "Imaginary",
  "path": "Hunt",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "July 17th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 144,
    "def_base": 60,
    "atk_base": 76.8,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT DMG",
      "value": 24
    },
    "traceStat2": {
      "stat": "atk",
      "value": 28
    },
    "traceStat3": {
      "stat": "def",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Skyler Davenport",
    "kr": "Jung Hye-Won (정혜원)",
    "jpn": "Yui Ogura (小倉唯)",
    "cn": "Nuò Yǎ (诺亚)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/march-7th-swordmaster",
  "source_record_updated_at": "September 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122401` | My Sword Zaps Demons | Basic ATK | Single Target |
| `basic_enh` | `122406` | Brows Be Smitten, Heart Be Bitten | Basic ATK | Single Target |
| `skill` | `122402` | Master, It's Tea Time! | Skill | Support |
| `ult` | `122403` | March 7th, the Apex Heroine | Ultimate | Single Target |
| `talent` | `122404` | Master, I've Ascended! | Talent | Enhance |
| `technique` | `122407` | Feast in One Go | Technique | Enhance |

## Ability records

### My Sword Zaps Demons

```json
{
  "ability_id": "122401",
  "slot": "basic",
  "name": "My Sword Zaps Demons",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
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
  "description_sha256": "a58998891423d9bbc89f29e2eaa638dea6e398bfa0a7f7aa9675646dc15db75b",
  "icon_path": null
}
```

### Brows Be Smitten, Heart Be Bitten

```json
{
  "ability_id": "122406",
  "slot": "basic_enh",
  "name": "Brows Be Smitten, Heart Be Bitten",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
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
    "energy",
    "energy_regen_rate",
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ba242456fd27d35b166ec72f991c2577571dba2406cf6b702420fe8ceaaddcd1",
  "icon_path": null
}
```

### Master, It's Tea Time!

```json
{
  "ability_id": "122402",
  "slot": "skill",
  "name": "Master, It's Tea Time!",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg",
    "toughness"
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
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 6.4,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 6.8,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 7.6,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8.5,
          "unit": "percent"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.5,
          "unit": "percent"
        },
        "p2": {
          "value": 18.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.4,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "13d4c8dc6fa5d84e34e46d935c159ed0e532576f5314e96b8a198f1742a0151d",
  "icon_path": null
}
```

### March 7th, the Apex Heroine

```json
{
  "ability_id": "122403",
  "slot": "ult",
  "name": "March 7th, the Apex Heroine",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Single Target",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "90",
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
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 153.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 163.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 182.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 204,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 249.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 259.2,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d3c3c68f49afc42ae281423584b7d4ff4f6d53b413d76b33816c80bc92e45422",
  "icon_path": null
}
```

### Master, I've Ascended!

```json
{
  "ability_id": "122404",
  "slot": "talent",
  "name": "Master, I've Ascended!",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": "5",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "eaa827e92c6da6eb92748f231ab82dab26c1a5eabe29cca1542a248a7c9775b3",
  "icon_path": null
}
```

### Feast in One Go

```json
{
  "ability_id": "122407",
  "slot": "technique",
  "name": "Feast in One Go",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "energy"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "99cf76549733dfc9c46db44e74a56e44c3c3a8cb45d36358440417e668e346b7",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Swan Soar",
    "mechanic_tags": [],
    "numeric_tokens": [
      "7",
      "25%"
    ],
    "description_sha256": "238110f39e4898443e08b043762ce5cbb305a73713d07ba1296cc91a0a822689"
  },
  {
    "requirement": "A4",
    "name": "Filigree",
    "mechanic_tags": [
      "break_effect",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "7"
    ],
    "description_sha256": "af53ac4556cc2f6d2782fcc90bae288d2eb2a69ffd2826d72e6e5724fca6877a"
  },
  {
    "requirement": "A6",
    "name": "Tide Tamer",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "break_effect",
      "dmg"
    ],
    "numeric_tokens": [
      "60%",
      "36%",
      "2"
    ],
    "description_sha256": "6f38cadec95f10d6e59470d82ed32f4f9ffa16772f9b2e64d8d10d46faa0c77c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "My Sword Stirs Starlight",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "7",
      "10%"
    ],
    "description_sha256": "ba66d12bfd316efc2b157c97882469e5da56d7b7c468287d8b9a60ba3a279618"
  },
  {
    "eidolon": 2,
    "name": "Blade Dances on Waves' Fight",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "7",
      "60%",
      "7",
      "1"
    ],
    "description_sha256": "9d2e7ffcb868db8d300012e4ad67f74ab2085494c232421b1203dca7c89d33e2"
  },
  {
    "eidolon": 3,
    "name": "Sharp Wit in Martial Might",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "56255746fa0a52881eb340407e446477fdaa880e43e6d5ceab5240492ba6dc06"
  },
  {
    "eidolon": 4,
    "name": "Being Fabulous Never Frights",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "f504d4b7acc5e2301a45c33a525abd57e53992ee758ba3f48463c2738f259957"
  },
  {
    "eidolon": 5,
    "name": "Sword Delights, Sugar Blights",
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
    "name": "Me, the Best Girl in Sight",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "4bff794ededb30bb6e7cb6865f1df63738f8960aaece81e9c7344d44d4b6ce72"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
