---
schema_version: "1.0.0"
unit_id: 4
name: "Dan Heng"
slug: "dan-heng"
rarity: 4
element: "Wind"
path: "Hunt"
role: "Main DPS"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/dan-heng"
source_record_updated_at: "January 10th, 2025"
dataset_snapshot: "2026-05-30"
---

# Dan Heng

## Character record

```json
{
  "unit_id": 4,
  "name": "Dan Heng",
  "slug": "dan-heng",
  "rarity": "4",
  "element": "Wind",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 120,
    "def_base": 54,
    "atk_base": 74.4,
    "speed_base": 110
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "windDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Nicholas Leung",
    "kr": "Kim Hye-sung (김혜성)",
    "jpn": "Kento Itō (伊東健人)",
    "cn": "Yú Dòng (魚凍)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/dan-heng",
  "source_record_updated_at": "January 10th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100201` | Cloudlancer Art: North Wind | Basic ATK | Single Target |
| `skill` | `100202` | Cloudlancer Art: Torrent | Skill | Single Target |
| `ult` | `100203` | Ethereal Dream | Ultimate | Single Target |
| `talent` | `100204` | Superiority of Reach | Talent | Enhance |
| `technique` | `100207` | Splitting Spearhead | Technique | Enhance |

## Ability records

### Cloudlancer Art: North Wind

```json
{
  "ability_id": "100201",
  "slot": "basic",
  "name": "Cloudlancer Art: North Wind",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
  "description_sha256": "c1964607e548c8011d4fa65183048b8ac534e3525da5b19e4602b63dcdd0b09d",
  "icon_path": "icon/skill/1002_basic_atk.png"
}
```

### Cloudlancer Art: Torrent

```json
{
  "ability_id": "100202",
  "slot": "skill",
  "name": "Cloudlancer Art: Torrent",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
    "p4": {
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
    }
  },
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
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 143,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 169,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 182,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 195,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 211.25,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 227.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 243.75,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 260,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 273,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 286,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 299,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 312,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 325,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e40cc7519da4addcaced1e15e2c6fb3213b935bef8fa0518b4e4309c8fa2f33d",
  "icon_path": "icon/skill/1002_skill.png"
}
```

### Ethereal Dream

```json
{
  "ability_id": "100203",
  "slot": "ult",
  "name": "Ethereal Dream",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
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
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 256,
          "unit": "percent"
        },
        "p2": {
          "value": 76.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 272,
          "unit": "percent"
        },
        "p2": {
          "value": 81.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 91.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 320,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 340,
          "unit": "percent"
        },
        "p2": {
          "value": 102,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 114,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 400,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 416,
          "unit": "percent"
        },
        "p2": {
          "value": 124.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 432,
          "unit": "percent"
        },
        "p2": {
          "value": 129.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 448,
          "unit": "percent"
        },
        "p2": {
          "value": 134.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 464,
          "unit": "percent"
        },
        "p2": {
          "value": 139.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "dead92fc451c9d92f6f68260db49fce47000f89cf122dce8a65548a2f28fc928",
  "icon_path": "icon/skill/1002_ultimate.png"
}
```

### Superiority of Reach

```json
{
  "ability_id": "100204",
  "slot": "talent",
  "name": "Superiority of Reach",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "res_pen",
    "res"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 19.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 23.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 27,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 29.25,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 31.5,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 33.75,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 37.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 41.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "0e7c9229e581e353870e4a9679eff5e9541ef9b73ee35335bbce5ecf3d6a8d59",
  "icon_path": "icon/skill/1002_talent.png"
}
```

### Splitting Spearhead

```json
{
  "ability_id": "100207",
  "slot": "technique",
  "name": "Splitting Spearhead",
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
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1c3814190cabf932b662eefe14c386b17898604a06731f3b1ed40b08f391fbfa",
  "icon_path": "icon/skill/1002_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Hidden Dragon",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "512ae4646d9d7df5bb5201c71f92b147d7758edcf5459687282e43b6b5ede112"
  },
  {
    "requirement": "A4",
    "name": "Faster Than Light",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "50%",
      "20%",
      "2"
    ],
    "description_sha256": "e12915d2d7d2807fa6ee222c3593e56c2a6668854c277b9f14fc62835aeb2809"
  },
  {
    "requirement": "A6",
    "name": "High Gale",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "a074b98ef697823a9e7cddccb16627901dc50876ddbd0c54db4f1ed115507f1d"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "The Higher You Fly, the Harder You Fall",
    "mechanic_tags": [
      "max_hp",
      "crit_rate"
    ],
    "numeric_tokens": [
      "50%",
      "12%"
    ],
    "description_sha256": "15f247fc5aeeb165aece83f9641b146e41b84c974eb59a7b87b855e7ca06aa00"
  },
  {
    "eidolon": 2,
    "name": "Quell the Venom Octet, Quench the Vice O'Flame",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "6b7263a6dbc560292789b1464a6b74e7a4db7ef5b7e302c8b968428aa0739887"
  },
  {
    "eidolon": 3,
    "name": "Seen and Unseen",
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
    "eidolon": 4,
    "name": "Roaring Dragon and Soaring Sun",
    "mechanic_tags": [],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "4f5454bd8580979976ccf8e669d8d11aed28bf9452dfac7884e94cfb1d8b7bdc"
  },
  {
    "eidolon": 5,
    "name": "A Drop of Rain Feeds a Torrent",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a4417497ecb72e43d7a08beb9ea57ccb09e86b6838c1773e7e2ade42f7242276"
  },
  {
    "eidolon": 6,
    "name": "The Troubled Soul Lies in Wait",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "8%"
    ],
    "description_sha256": "37f4dc81ace58879d1dcff4b60b7d260ac45cee481dd9c9c2f020075c3fd7cff"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
