---
schema_version: "1.0.0"
unit_id: 45
name: "Xueyi"
slug: "xueyi"
rarity: 4
element: "Quantum"
path: "Destruction"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/xueyi"
source_record_updated_at: "March 26th, 2025"
dataset_snapshot: "2026-05-30"
---

# Xueyi

## Character record

```json
{
  "unit_id": 45,
  "name": "Xueyi",
  "slug": "xueyi",
  "rarity": "4",
  "element": "Quantum",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "December 27th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 144,
    "def_base": 54,
    "atk_base": 81.6,
    "speed_base": 103
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 18
    },
    "traceStat2": {
      "stat": "Quantum DMG",
      "value": 8
    },
    "traceStat3": {
      "stat": "Break Effect",
      "value": 37.3
    }
  },
  "voice_actors": {
    "en": "Jenny Yokobori",
    "kr": "박리나 (Park Ri-na)",
    "jpn": "河瀬茉希 (Kawase Maki)",
    "cn": "溯浔 (SuXun)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/xueyi",
  "source_record_updated_at": "March 26th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121401` | Mara-Sunder Awl | Basic ATK | Single Target |
| `skill` | `121402` | Iniquity Obliteration | Skill | Blast |
| `ult` | `121403` | Divine Castigation | Ultimate | Single Target |
| `talent` | `121404` | Karmic Perpetuation | Talent | Bounce |
| `technique` | `121407` | Summary Execution | Technique | MazeAttack |

## Ability records

### Mara-Sunder Awl

```json
{
  "ability_id": "121401",
  "slot": "basic",
  "name": "Mara-Sunder Awl",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
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
  "description_sha256": "56addb6469932138e281ba0e49a1b70105c1c4a668ced924b565518a0e6254f5",
  "icon_path": "icon/skill/1214_basic_atk.png"
}
```

### Iniquity Obliteration

```json
{
  "ability_id": "121402",
  "slot": "skill",
  "name": "Iniquity Obliteration",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
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
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 38.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
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
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        },
        "p2": {
          "value": 45.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 98,
          "unit": "percent"
        },
        "p2": {
          "value": 49,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
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
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 113.75,
          "unit": "percent"
        },
        "p2": {
          "value": 56.88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 122.5,
          "unit": "percent"
        },
        "p2": {
          "value": 61.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 65.63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 147,
          "unit": "percent"
        },
        "p2": {
          "value": 73.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        },
        "p2": {
          "value": 77,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 161,
          "unit": "percent"
        },
        "p2": {
          "value": 80.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 87.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e741f8ab0b84231f039ee614da51858cd8e0e6e19835fd719e4603bda9808e6c",
  "icon_path": "icon/skill/1214_skill.png"
}
```

### Divine Castigation

```json
{
  "ability_id": "121403",
  "slot": "ult",
  "name": "Divine Castigation",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": "120",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
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
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 0.09,
          "unit": "scalar"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 0.096,
          "unit": "scalar"
        },
        "p3": {
          "value": 38.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 170,
          "unit": "percent"
        },
        "p2": {
          "value": 0.102,
          "unit": "scalar"
        },
        "p3": {
          "value": 40.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 0.108,
          "unit": "scalar"
        },
        "p3": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 190,
          "unit": "percent"
        },
        "p2": {
          "value": 0.114,
          "unit": "scalar"
        },
        "p3": {
          "value": 45.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        },
        "p3": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 212.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0.1275,
          "unit": "scalar"
        },
        "p3": {
          "value": 51,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        },
        "p2": {
          "value": 0.135,
          "unit": "scalar"
        },
        "p3": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 237.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0.1425,
          "unit": "scalar"
        },
        "p3": {
          "value": 57,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 0.15,
          "unit": "scalar"
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
          "value": 260,
          "unit": "percent"
        },
        "p2": {
          "value": 0.156,
          "unit": "scalar"
        },
        "p3": {
          "value": 62.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 0.162,
          "unit": "scalar"
        },
        "p3": {
          "value": 64.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 280,
          "unit": "percent"
        },
        "p2": {
          "value": 0.168,
          "unit": "scalar"
        },
        "p3": {
          "value": 67.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 290,
          "unit": "percent"
        },
        "p2": {
          "value": 0.174,
          "unit": "scalar"
        },
        "p3": {
          "value": 69.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 0.18,
          "unit": "scalar"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9b5cfd0f428ce89272a9cb455cf387ffda6338ae40e94b6252d719edb217ebb7",
  "icon_path": "icon/skill/1214_ultimate.png"
}
```

### Karmic Perpetuation

```json
{
  "ability_id": "121404",
  "slot": "talent",
  "name": "Karmic Perpetuation",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Quantum",
  "energy_gain": "2",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "toughness",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 49.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 58.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 67.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 73.13,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 78.75,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 84.38,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 94.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 99,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 103.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "scalar"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c5764dcaf62b8c2845f8f81fbdf61c77eb27df7c71293c051753ee01486c9d81",
  "icon_path": "icon/skill/1214_talent.png"
}
```

### Summary Execution

```json
{
  "ability_id": "121407",
  "slot": "technique",
  "name": "Summary Execution",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Quantum",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d92f971d41d976c07f5f79bf3b4dbef4b845e29d47e7e4724be239764c49a2e1",
  "icon_path": "icon/skill/1214_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Clairvoyant Loom",
    "mechanic_tags": [
      "break_effect",
      "dmg"
    ],
    "numeric_tokens": [
      "100%",
      "240%"
    ],
    "description_sha256": "3340313d176ec3b69e722154ae2cdb5a5e6cb1a62a5257d5fa46f6e86c9a8b72"
  },
  {
    "requirement": "A4",
    "name": "Intrepid Rollerbearings",
    "mechanic_tags": [
      "dmg",
      "toughness"
    ],
    "numeric_tokens": [
      "50%",
      "10%"
    ],
    "description_sha256": "c656e3975ab38b3ff6a84ea0771b71eb190fe9dde0d4307d8fbfc7350581a361"
  },
  {
    "requirement": "A6",
    "name": "Perspicacious Mainframe",
    "mechanic_tags": [],
    "numeric_tokens": [
      "6"
    ],
    "description_sha256": "2f4c6bc5787f9cc7ae43d653db0a217b2c70d318461bc4b381e2b4a3fa658903"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Dvesha, Inhibited",
    "mechanic_tags": [
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "3a79ac3bdcf6ad267bad0f9d76dd80b87afa87780f087d7c4532e6ae720c5748"
  },
  {
    "eidolon": 2,
    "name": "Klesha, Breached",
    "mechanic_tags": [
      "max_hp",
      "break_effect",
      "toughness",
      "follow_up",
      "weakness"
    ],
    "numeric_tokens": [
      "5%"
    ],
    "description_sha256": "eee0d6091c4b67b3ed07d41a06a7f16e39e0514158d0f4f7ea631196679192aa"
  },
  {
    "eidolon": 3,
    "name": "Duḥkha, Ceased",
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
    "name": "Karma, Severed",
    "mechanic_tags": [
      "break_effect"
    ],
    "numeric_tokens": [
      "40%",
      "2"
    ],
    "description_sha256": "2d9c5419bf44d6d48dd3eb93c5b8c88043fe187d5f60e5d61b8761e94d8f8085"
  },
  {
    "eidolon": 5,
    "name": "Deva, Enthralled",
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
    "name": "Saṃsāra, Mastered",
    "mechanic_tags": [],
    "numeric_tokens": [
      "6"
    ],
    "description_sha256": "863f9e19e0513ce15ddf4e335132e4e3948b280bb2839eb61a36da1ae07cf9a3"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
