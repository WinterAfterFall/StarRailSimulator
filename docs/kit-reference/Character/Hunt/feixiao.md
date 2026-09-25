---
schema_version: "1.0.0"
unit_id: 59
name: "Feixiao"
slug: "feixiao"
rarity: 5
element: "Wind"
path: "Hunt"
role: "Main DPS"
affiliation: "The Xianzhou Yaoqing"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/feixiao"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Feixiao

## Character record

```json
{
  "unit_id": 59,
  "name": "Feixiao",
  "slug": "feixiao",
  "rarity": "5",
  "element": "Wind",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "The Xianzhou Yaoqing",
  "release_date": "September 10th, 2024",
  "is_released": true,
  "ultimate_energy_cost": null,
  "base_stats": {
    "hp_base": 143,
    "def_base": 52.8,
    "atk_base": 81.84,
    "speed_base": 112
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Anairis Quinones",
    "kr": "Sohn Jeong Min (손정민)",
    "jpn": "Mikako Komatsu (小松未可子)",
    "cn": "Zhiqiu Ye (叶知秋)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/feixiao",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122001` | Boltsunder | Basic ATK | Single Target |
| `skill` | `122002` | Waraxe | Skill | Single Target |
| `ult` | `122003` | Terrasplit | Ultimate | Single Target |
| `talent` | `122004` | Thunderhunt | Talent | Single Target |
| `technique` | `122007` | Stormborn | Technique | Enhance |

## Ability records

### Boltsunder

```json
{
  "ability_id": "122001",
  "slot": "basic",
  "name": "Boltsunder",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
  "energy_gain": null,
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
  "description_sha256": "152feecd5ee842b27f75a529e6cf4ad41b02e42248a5e3cc6f08e5e4969521e0",
  "icon_path": null
}
```

### Waraxe

```json
{
  "ability_id": "122002",
  "slot": "skill",
  "name": "Waraxe",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
  "energy_gain": null,
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
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 100,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 120,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 140,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 162.5,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 187.5,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 210,
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
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "228ae5e91f54fd4ec4048d164583c5c0e1d4aa3965f3c7a5d340a162fa12158e",
  "icon_path": null
}
```

### Terrasplit

```json
{
  "ability_id": "122003",
  "slot": "ult",
  "name": "Terrasplit",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
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
      "occurrences": 2
    },
    "p4": {
      "unit": "percent",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "atk",
    "weakness_break_efficiency",
    "dmg",
    "toughness",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 402,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
        },
        "p4": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 431.8,
          "unit": "percent"
        },
        "p2": {
          "value": 102.4,
          "unit": "percent"
        },
        "p3": {
          "value": 38.4,
          "unit": "percent"
        },
        "p4": {
          "value": 16.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 461.6,
          "unit": "percent"
        },
        "p2": {
          "value": 108.8,
          "unit": "percent"
        },
        "p3": {
          "value": 40.8,
          "unit": "percent"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 491.4,
          "unit": "percent"
        },
        "p2": {
          "value": 115.2,
          "unit": "percent"
        },
        "p3": {
          "value": 43.2,
          "unit": "percent"
        },
        "p4": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 521.2,
          "unit": "percent"
        },
        "p2": {
          "value": 121.6,
          "unit": "percent"
        },
        "p3": {
          "value": 45.6,
          "unit": "percent"
        },
        "p4": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 551,
          "unit": "percent"
        },
        "p2": {
          "value": 128,
          "unit": "percent"
        },
        "p3": {
          "value": 48,
          "unit": "percent"
        },
        "p4": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 588.25,
          "unit": "percent"
        },
        "p2": {
          "value": 136,
          "unit": "percent"
        },
        "p3": {
          "value": 51,
          "unit": "percent"
        },
        "p4": {
          "value": 24.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 625.5,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        },
        "p3": {
          "value": 54,
          "unit": "percent"
        },
        "p4": {
          "value": 26.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 662.75,
          "unit": "percent"
        },
        "p2": {
          "value": 152,
          "unit": "percent"
        },
        "p3": {
          "value": 57,
          "unit": "percent"
        },
        "p4": {
          "value": 28.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 700,
          "unit": "percent"
        },
        "p2": {
          "value": 160,
          "unit": "percent"
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
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 729.8,
          "unit": "percent"
        },
        "p2": {
          "value": 166.4,
          "unit": "percent"
        },
        "p3": {
          "value": 62.4,
          "unit": "percent"
        },
        "p4": {
          "value": 31.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 759.6,
          "unit": "percent"
        },
        "p2": {
          "value": 172.8,
          "unit": "percent"
        },
        "p3": {
          "value": 64.8,
          "unit": "percent"
        },
        "p4": {
          "value": 33,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "740cea279a5a2dc02a68702ff72c94aa46d7a2ebec4c36a23b3e098c092923ad",
  "icon_path": null
}
```

### Thunderhunt

```json
{
  "ability_id": "122004",
  "slot": "talent",
  "name": "Thunderhunt",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
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
    "p2": {
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
          "value": 55,
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
          "value": 60.5,
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
          "value": 66,
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
          "value": 71.5,
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
          "value": 77,
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
          "value": 82.5,
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
          "value": 89.375,
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
          "value": 96.25,
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
          "value": 103.125,
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
          "value": 110,
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
          "value": 115.5,
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
          "value": 121,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "09267db1eef388c820f0d0c8c5a74226d24006944b418d1e254daeba6d3ae5f6",
  "icon_path": null
}
```

### Stormborn

```json
{
  "ability_id": "122007",
  "slot": "technique",
  "name": "Stormborn",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg"
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
          "value": 15,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "bcdee2285b788a306796d235de9be021c1b0cfa93a6dad75fdb415a8019e45ba",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Heavenpath",
    "mechanic_tags": [
      "follow_up"
    ],
    "numeric_tokens": [
      "3",
      "1"
    ],
    "description_sha256": "55bf3bbf31e4773f1ce95bc3d221103b6d0a22bd1c10064c9c050fd9a2d83013"
  },
  {
    "requirement": "A4",
    "name": "Formshift",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "36%"
    ],
    "description_sha256": "00a31c5926e2066579add819bbc895a597c64ad8b216ab021410409c58b03718"
  },
  {
    "requirement": "A6",
    "name": "Boltcatch",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "48%",
      "3"
    ],
    "description_sha256": "4e3f524f8511b3a9c502c321fb726e3e74bc4b4abc845553dacd11287ec7a509"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Skyward I Quell",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%",
      "5"
    ],
    "description_sha256": "487589e5adaf0e95163626b7b4c644edd05a292371552fbe36be6283593dc54b"
  },
  {
    "eidolon": 2,
    "name": "Moonward I Wish",
    "mechanic_tags": [
      "follow_up"
    ],
    "numeric_tokens": [
      "1",
      "1",
      "6"
    ],
    "description_sha256": "1f4edd4ae257e782d1eaf06f74173a16a5adad3d67e679e4499e8dc7086a6187"
  },
  {
    "eidolon": 3,
    "name": "Starward I Bode",
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
    "name": "Stormward I Hear",
    "mechanic_tags": [
      "spd",
      "toughness",
      "follow_up"
    ],
    "numeric_tokens": [
      "100%",
      "8%",
      "2"
    ],
    "description_sha256": "4611d4a1f54b1e30278f3ba887f6fa6152839ec5483ec8b272999e1dbb22d1bb"
  },
  {
    "eidolon": 5,
    "name": "Heavenward I Leap",
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
    "name": "Homeward I Near",
    "mechanic_tags": [
      "res_pen",
      "res",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "20%",
      "140%"
    ],
    "description_sha256": "9478f47d102ba30ef8369c740b3bbfed4b49cf9ccc2f08f0911e80eb4191ef32"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
