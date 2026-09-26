---
schema_version: "1.0.0"
unit_id: 27
name: "Sushang"
slug: "sushang"
rarity: 4
element: "Physical"
path: "Hunt"
role: "Main DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/sushang"
source_record_updated_at: "January 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# Sushang

## Character record

```json
{
  "unit_id": 27,
  "name": "Sushang",
  "slug": "sushang",
  "rarity": "4",
  "element": "Physical",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 124.8,
    "def_base": 57,
    "atk_base": 76.8,
    "speed_base": 107
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "hp",
      "value": 18
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Anjali Kunapanen",
    "kr": "Park Si-yoon (박시윤)",
    "jpn": "Fukuen Misato (福圓美里)",
    "cn": "Chen Tingting (陈婷婷)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/sushang",
  "source_record_updated_at": "January 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120601` | Cloudfencer Art: Starshine | Basic ATK | Single Target |
| `skill` | `120602` | Cloudfencer Art: Mountainfall | Skill | Single Target |
| `ult` | `120603` | Shape of Taixu: Dawn Herald | Ultimate | Single Target |
| `talent` | `120604` | Dancing Blade | Talent | Enhance |
| `technique` | `120607` | Cloudfencer Art: Warcry | Technique | MazeAttack |

## Ability records

### Cloudfencer Art: Starshine

```json
{
  "ability_id": "120601",
  "slot": "basic",
  "name": "Cloudfencer Art: Starshine",
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
  "description_sha256": "f5377e0d67ef307d597b8f49f7952247857e4719417597cef62329e2c4b6c7f3",
  "icon_path": "icon/skill/1206_basic_atk.png"
}
```

### Cloudfencer Art: Mountainfall

```json
{
  "ability_id": "120602",
  "slot": "skill",
  "name": "Cloudfencer Art: Mountainfall",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
    "p3": {
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
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 115.5,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 136.5,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 147,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 170.63,
          "unit": "percent"
        },
        "p2": {
          "value": 81.25,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 183.75,
          "unit": "percent"
        },
        "p2": {
          "value": 87.5,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 196.88,
          "unit": "percent"
        },
        "p2": {
          "value": 93.75,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 220.5,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 231,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 241.5,
          "unit": "percent"
        },
        "p2": {
          "value": 115,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 252,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 262.5,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8a2353d1ce35afec0b8fa917f01f8fc35c543a0644c2096140295167de9c107c",
  "icon_path": "icon/skill/1206_skill.png"
}
```

### Shape of Taixu: Dawn Herald

```json
{
  "ability_id": "120603",
  "slot": "ult",
  "name": "Shape of Taixu: Dawn Herald",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": "90",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
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
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 204.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 19.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 217.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 20.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 230.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 21.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 243.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 22.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 256,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 272,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 25.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 27,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 28.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 320,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
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
          "value": 332.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 31.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 345.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 32.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 358.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 33.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 371.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 34.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 384,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 36,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6bcd3694fa59dc374650553f5fca3e8eb5fcc36b2a5c76b494f19c717803fa78",
  "icon_path": "icon/skill/1206_ultimate.png"
}
```

### Dancing Blade

```json
{
  "ability_id": "120604",
  "slot": "talent",
  "name": "Dancing Blade",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
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
    "spd",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
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
          "value": 15.5,
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
          "value": 16,
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
          "value": 16.5,
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
          "value": 17,
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
          "value": 17.5,
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
          "value": 18.13,
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
          "value": 18.75,
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
          "value": 19.38,
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
          "value": 20,
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
          "value": 20.5,
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
          "value": 21,
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
          "value": 21.5,
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
          "value": 22,
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
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "217c03103bd6d327dd126e11be5914c8c7a0328b725769b29f1d067e6e0b7088",
  "icon_path": "icon/skill/1206_talent.png"
}
```

### Cloudfencer Art: Warcry

```json
{
  "ability_id": "120607",
  "slot": "technique",
  "name": "Cloudfencer Art: Warcry",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Physical",
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
  "description_sha256": "61d9fa24d548b436d234dd754ecc23ac7efca5ab511221d35e62b356bfd79428",
  "icon_path": "icon/skill/1206_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Guileless",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "79d31eeba68010abf0a70b23afb2d5255dd81b33fe432c98f0b29a3dc6db8c56"
  },
  {
    "requirement": "A4",
    "name": "Riposte",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "2.5%",
      "10"
    ],
    "description_sha256": "ec602255e352d5ec458ccbdcddcbb23c3aea15575b5f2c82e992acfbc833dc35"
  },
  {
    "requirement": "A6",
    "name": "Vanquisher",
    "mechanic_tags": [
      "atk",
      "weakness"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "8e06dc7c3e687dd224819b5586f9a9382b06d82e4c22f4a630e1cf24cc3f5b48"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Cut With Ease",
    "mechanic_tags": [
      "weakness",
      "skill_points"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "8efc2400abeeae38abd5a4a89ddcd7d9da748eeb29defc573ec505b7e8f691ce"
  },
  {
    "eidolon": 2,
    "name": "Refine in Toil",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "1"
    ],
    "description_sha256": "f056ab1414ed9f9ab42f121f362bd139eda2caaca4a2157697a8de2e4eea044f"
  },
  {
    "eidolon": 3,
    "name": "Rise From Fame",
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
    "eidolon": 4,
    "name": "Cleave With Heart",
    "mechanic_tags": [
      "break_effect"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "49e7e7f353130651f9d137235dbc6019ee22f1ca883fc88a038a79779ebf02a0"
  },
  {
    "eidolon": 5,
    "name": "Prevail via Taixu",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "cc0d6a12ef7b870ada3a8cc5bf409ac765e5cddc458782b0d4d944b156f24f67"
  },
  {
    "eidolon": 6,
    "name": "Dwell Like Water",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "2",
      "1"
    ],
    "description_sha256": "b094fc9616818dc7ace669223f917025a11b6521c052dd690e0d62235f94a1bc"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
