---
schema_version: "1.0.0"
unit_id: 56
name: "Yunli"
slug: "yunli"
rarity: 5
element: "Physical"
path: "Destruction"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/yunli"
source_record_updated_at: "March 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Yunli

## Character record

```json
{
  "unit_id": 56,
  "name": "Yunli",
  "slug": "yunli",
  "rarity": "5",
  "element": "Physical",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "July 17th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 185,
    "def_base": 62.7,
    "atk_base": 92.4,
    "speed_base": 94
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 6.7
    },
    "traceStat2": {
      "stat": "atk",
      "value": 28
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Brenna Larsen",
    "kr": "Lee Ju-eun (이주은)",
    "jpn": "Shion Wakayama (若山詩音)",
    "cn": "Liu Wen (刘雯)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/yunli",
  "source_record_updated_at": "March 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122101` | Galespin Summersault | Basic ATK | Single Target |
| `skill` | `122102` | Bladeborne Quake | Skill | Blast |
| `ult` | `122103` | Earthbind, Etherbreak | Ultimate | Enhance |
| `talent` | `122104` | Flashforge | Talent | Blast |
| `technique` | `122107` | Posterior Precedence | Technique | Enhance |

## Ability records

### Galespin Summersault

```json
{
  "ability_id": "122101",
  "slot": "basic",
  "name": "Galespin Summersault",
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
  "description_sha256": "b5e29738e41e98327920b4547bd9d1ac0d71a08dd9e6741e9fe3a29d2daff633",
  "icon_path": null
}
```

### Bladeborne Quake

```json
{
  "ability_id": "122102",
  "slot": "skill",
  "name": "Bladeborne Quake",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
  "energy_gain": "30",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dmg",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 21.25,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 66,
          "unit": "percent"
        },
        "p4": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 102.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
        },
        "p4": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 23.75,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "scalar"
        },
        "p3": {
          "value": 78,
          "unit": "percent"
        },
        "p4": {
          "value": 39,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "scalar"
        },
        "p3": {
          "value": 84,
          "unit": "percent"
        },
        "p4": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 155,
          "unit": "scalar"
        },
        "p3": {
          "value": 90,
          "unit": "percent"
        },
        "p4": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 27,
          "unit": "percent"
        },
        "p2": {
          "value": 166.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 97.5,
          "unit": "percent"
        },
        "p4": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 177.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 105,
          "unit": "percent"
        },
        "p4": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 29,
          "unit": "percent"
        },
        "p2": {
          "value": 188.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 112.5,
          "unit": "percent"
        },
        "p4": {
          "value": 56.25,
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
        },
        "p2": {
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 120,
          "unit": "percent"
        },
        "p4": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31,
          "unit": "percent"
        },
        "p2": {
          "value": 211.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 126,
          "unit": "percent"
        },
        "p4": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        },
        "p2": {
          "value": 222.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 132,
          "unit": "percent"
        },
        "p4": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 0.02,
          "unit": "scalar"
        },
        "p3": {
          "value": 28,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 0.02,
          "unit": "scalar"
        },
        "p3": {
          "value": 29,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 0.02,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6047e652880719085f43e9dc1fd35345c17b9183cf97fb5579646cd9c0421d2e",
  "icon_path": "icon/skill/1314_skill.png"
}
```

### Earthbind, Etherbreak

```json
{
  "ability_id": "122103",
  "slot": "ult",
  "name": "Earthbind, Etherbreak",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
      "occurrences": 2
    },
    "p3": {
      "unit": "percent",
      "occurrences": 2
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_dmg",
    "energy",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        },
        "p3": {
          "value": 66,
          "unit": "percent"
        },
        "p4": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 140.8,
          "unit": "percent"
        },
        "p3": {
          "value": 70.4,
          "unit": "percent"
        },
        "p4": {
          "value": 46.08,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 149.6,
          "unit": "percent"
        },
        "p3": {
          "value": 74.8,
          "unit": "percent"
        },
        "p4": {
          "value": 48.96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 158.4,
          "unit": "percent"
        },
        "p3": {
          "value": 79.2,
          "unit": "percent"
        },
        "p4": {
          "value": 51.84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 76,
          "unit": "percent"
        },
        "p2": {
          "value": 167.2,
          "unit": "percent"
        },
        "p3": {
          "value": 83.6,
          "unit": "percent"
        },
        "p4": {
          "value": 54.72,
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
        },
        "p2": {
          "value": 176,
          "unit": "percent"
        },
        "p3": {
          "value": 88,
          "unit": "percent"
        },
        "p4": {
          "value": 57.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 85,
          "unit": "percent"
        },
        "p2": {
          "value": 187,
          "unit": "percent"
        },
        "p3": {
          "value": 93.5,
          "unit": "percent"
        },
        "p4": {
          "value": 61.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 198,
          "unit": "percent"
        },
        "p3": {
          "value": 99,
          "unit": "percent"
        },
        "p4": {
          "value": 64.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 95,
          "unit": "percent"
        },
        "p2": {
          "value": 209,
          "unit": "percent"
        },
        "p3": {
          "value": 104.5,
          "unit": "percent"
        },
        "p4": {
          "value": 68.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 220,
          "unit": "percent"
        },
        "p3": {
          "value": 110,
          "unit": "percent"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 228.8,
          "unit": "percent"
        },
        "p3": {
          "value": 114.4,
          "unit": "percent"
        },
        "p4": {
          "value": 74.88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 237.6,
          "unit": "percent"
        },
        "p3": {
          "value": 118.8,
          "unit": "percent"
        },
        "p4": {
          "value": 77.76,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 28,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 29,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3000,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 300,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b0cb2217f8329714ffab1aa3aad7e66439bf35a70f59d95b068dafb8691c894e",
  "icon_path": "icon/skill/1314_ultimate.png"
}
```

### Flashforge

```json
{
  "ability_id": "122104",
  "slot": "talent",
  "name": "Flashforge",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
    "energy",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
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
          "value": 66,
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
          "value": 72,
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
          "value": 78,
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
          "value": 84,
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
          "value": 90,
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
          "value": 97.5,
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
          "value": 105,
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
          "value": 112.5,
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
          "value": 120,
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
          "value": 126,
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
          "value": 132,
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
          "value": 2.76,
          "unit": "percent"
        },
        "p2": {
          "value": 5000,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 2.88,
          "unit": "percent"
        },
        "p2": {
          "value": 5000,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "percent"
        },
        "p2": {
          "value": 5000,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c56a367e52fe131393fdca5b7c05bfad72181d5c44c24ce498cef8d8d1f56b1f",
  "icon_path": "icon/skill/1314_talent.png"
}
```

### Posterior Precedence

```json
{
  "ability_id": "122107",
  "slot": "technique",
  "name": "Posterior Precedence",
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
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dmg"
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
  "description_sha256": "f60cc165b2da0c0022c3762870e0b2c03f1dc83536104c6a7be731add9fb5f72",
  "icon_path": "icon/skill/1314_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Fiery Wheel",
    "mechanic_tags": [],
    "numeric_tokens": [],
    "description_sha256": "2f943b0764010c07fcf49df2dadd6b82c1dd08f30feecdd90c8769289db2374a"
  },
  {
    "requirement": "A4",
    "name": "Demon Quell",
    "mechanic_tags": [
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "f9bf9e3fc934e137f90f1b479fc7acfe6f6b4c15326b878206e955110b1b955d"
  },
  {
    "requirement": "A6",
    "name": "True Sunder",
    "mechanic_tags": [
      "atk",
      "follow_up"
    ],
    "numeric_tokens": [
      "30%",
      "1"
    ],
    "description_sha256": "ab571abfebc5b14fc7bea052c421f415bdb24fc5076bf5084830e8977738825f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Weathered Blade Does Not Sully",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "3"
    ],
    "description_sha256": "78a3dec03a36fa151f9ab31750662cbfad84df45af6530e946fcbc41d1a7bcbe"
  },
  {
    "eidolon": 2,
    "name": "First Luster Breaks Dawn",
    "mechanic_tags": [
      "def",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "55e073d1ac78942232c00c3f29a4f61bbe0a231db8e3b046cfd63b05aa20ae30"
  },
  {
    "eidolon": 3,
    "name": "Mastlength Twirls Mountweight",
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
    "name": "Artisan's Ironsong",
    "mechanic_tags": [
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "50%",
      "1"
    ],
    "description_sha256": "abb35a8b505cae295f1e14310a247bb23eb43f4e9b2fe2bf45abf792cad9cdee"
  },
  {
    "eidolon": 5,
    "name": "Blade of Old Outlasts All",
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
    "name": "Walk in Blade, Talk in Zither",
    "mechanic_tags": [
      "crit_rate",
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "20%"
    ],
    "description_sha256": "817a211d2cd88669f6856ea6b561b52d8b9dbb78c6fbf407cbacfd7589015a18"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
