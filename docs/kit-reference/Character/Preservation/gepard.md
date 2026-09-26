---
schema_version: "1.0.0"
unit_id: 15
name: "Gepard"
slug: "gepard"
rarity: 5
element: "Ice"
path: "Preservation"
role: "Shielder"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/gepard"
source_record_updated_at: "February 19th, 2025"
dataset_snapshot: "2026-05-30"
---

# Gepard

## Character record

```json
{
  "unit_id": 15,
  "name": "Gepard",
  "slug": "gepard",
  "rarity": "5",
  "element": "Ice",
  "path": "Preservation",
  "default_role": "Shielder",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 190.08,
    "def_base": 89.1,
    "atk_base": 73.92,
    "speed_base": 92
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "effectRes",
      "value": 18
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Bryson Baugus",
    "kr": "민승우",
    "jpn": "Furukawa Makoto (古川慎)",
    "cn": "Yang Ma (马洋)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/gepard",
  "source_record_updated_at": "February 19th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110401` | Fist of Conviction | Basic ATK | Single Target |
| `skill` | `110402` | Daunting Smite | Skill | Impair |
| `ult` | `110403` | Enduring Bulwark | Ultimate | Defense |
| `talent` | `110404` | Unyielding Will | Talent | Restore |
| `technique` | `110407` | Comradery | Technique | Defense |

## Ability records

### Fist of Conviction

```json
{
  "ability_id": "110401",
  "slot": "basic",
  "name": "Fist of Conviction",
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
  "description_sha256": "e3ce345da765b647df6d049b3a041cd007c210ab5ae73b033203e1580d16ea73",
  "icon_path": "icon/skill/1104_basic_atk.png"
}
```

### Daunting Smite

```json
{
  "ability_id": "110402",
  "slot": "skill",
  "name": "Daunting Smite",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 162.5,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 220,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 69,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 75,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "606b3530b83bfa0685dded60a8eb13985b569bf73ec0d70294a852c1bedd5451",
  "icon_path": "icon/skill/1104_skill.png"
}
```

### Enduring Bulwark

```json
{
  "ability_id": "110403",
  "slot": "ult",
  "name": "Enduring Bulwark",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Ice",
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
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "def",
    "dmg",
    "shield"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 31.88,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 240,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 33.75,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 307.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 35.63,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 375,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 420,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 465,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 40.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 498.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 532.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 43.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 566.25,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 600,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 46.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 633.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 667.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 49.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 701.25,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 51,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 735,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 768.75,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9a187517299c8ec3cf3eebd823b9ea3bc9f261245384fdd161f83353ad1e88a4",
  "icon_path": "icon/skill/1104_ultimate.png"
}
```

### Unyielding Will

```json
{
  "ability_id": "110404",
  "slot": "talent",
  "name": "Unyielding Will",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
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
    "healing"
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
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 40.63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.88,
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
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 57.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7c8b441493ec1292d65de0dded8d5527e806b19a51feb5872d397347c61fadce",
  "icon_path": "icon/skill/1104_talent.png"
}
```

### Comradery

```json
{
  "ability_id": "110407",
  "slot": "technique",
  "name": "Comradery",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "def",
    "dmg",
    "shield"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c9cefc49d7f400977835faa25ec8c16d462c50ca00df303da1d08fbb76ee98fa",
  "icon_path": "icon/skill/1104_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Integrity",
    "mechanic_tags": [],
    "numeric_tokens": [],
    "description_sha256": "f826cdd82abe600388abdb57099ad9379660c1b6aa7da86ecd09986431b1737c"
  },
  {
    "requirement": "A4",
    "name": "Commander",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "c165897603b5b79491220fd01c0b9d8d381c8474654fd2a6e9d985e9221253c6"
  },
  {
    "requirement": "A6",
    "name": "Fighting Spirit",
    "mechanic_tags": [
      "atk",
      "def"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "1454c88de3448df7011ead7c425a97166ab30aba7209ae141c41bef12922c904"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Due Diligence",
    "mechanic_tags": [],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "b7d95d3bd51c08111c92d4879f4ae0705dbdc1b4374f8eb233c9a241e8d999e1"
  },
  {
    "eidolon": 2,
    "name": "Lingering Cold",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "20%",
      "1"
    ],
    "description_sha256": "6b01cb49aad6ff996943748c2f5c9d30e531790424160e06aaa8cf0700cc05c6"
  },
  {
    "eidolon": 3,
    "name": "Never Surrender",
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
    "eidolon": 4,
    "name": "Faith Moves Mountains",
    "mechanic_tags": [
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "518f5ad705e9b4682d60f084ea97650f286f9d0b093fa8994279300a8c5ac3c3"
  },
  {
    "eidolon": 5,
    "name": "Cold Iron Fist",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "dfc289407dbc553d0a60b619a82ff2cb35c322892c7f2b225426b96a861b9dfd"
  },
  {
    "eidolon": 6,
    "name": "Unyielding Determination",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "100%",
      "50%"
    ],
    "description_sha256": "c8283ae9bf4f70ff97c8cf6cdf3afd417583c2ffd632496c5c486b067e5b9a2a"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
