---
schema_version: "1.0.0"
unit_id: 16
name: "Natasha"
slug: "natasha"
rarity: 4
element: "Physical"
path: "Abundance"
role: "Healer"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/natasha"
source_record_updated_at: "January 14th, 2025"
dataset_snapshot: "2026-05-30"
---

# Natasha

## Character record

```json
{
  "unit_id": 16,
  "name": "Natasha",
  "slug": "natasha",
  "rarity": "4",
  "element": "Physical",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "90",
  "base_stats": {
    "hp_base": 158.4,
    "def_base": 69,
    "atk_base": 64.8,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 28
    },
    "traceStat2": {
      "stat": "def",
      "value": 12.5
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Elizabeth Maxwell",
    "kr": "강은애",
    "jpn": "Uchiyama Yumi (内山夕実)",
    "cn": "秦紫翼"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/natasha",
  "source_record_updated_at": "January 14th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110501` | Behind the Kindness | Basic ATK | Single Target |
| `skill` | `110502` | Love, Heal, and Choose | Skill | Restore |
| `ult` | `110503` | Gift of Rebirth | Ultimate | Restore |
| `talent` | `110504` | Innervation | Talent | Enhance |
| `technique` | `110507` | Hypnosis Research | Technique | MazeAttack |

## Ability records

### Behind the Kindness

```json
{
  "ability_id": "110501",
  "slot": "basic",
  "name": "Behind the Kindness",
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
  "description_sha256": "d27810526b49dadf1e43b75f9fa2a026fe25fed14b63a87a5015360e4b67e81d",
  "icon_path": "icon/skill/1105_basic_atk.png"
}
```

### Love, Heal, and Choose

```json
{
  "ability_id": "110502",
  "slot": "skill",
  "name": "Love, Heal, and Choose",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Physical",
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
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
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
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 4.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 70,
          "unit": "scalar"
        },
        "p5": {
          "value": 48,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.44,
          "unit": "percent"
        },
        "p2": {
          "value": 5.1,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 112,
          "unit": "scalar"
        },
        "p5": {
          "value": 76.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 7.88,
          "unit": "percent"
        },
        "p2": {
          "value": 5.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 143.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 98.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 8.31,
          "unit": "percent"
        },
        "p2": {
          "value": 5.7,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 175,
          "unit": "scalar"
        },
        "p5": {
          "value": 120,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8.75,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 196,
          "unit": "scalar"
        },
        "p5": {
          "value": 134.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 9.1,
          "unit": "percent"
        },
        "p2": {
          "value": 6.24,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 217,
          "unit": "scalar"
        },
        "p5": {
          "value": 148.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 9.45,
          "unit": "percent"
        },
        "p2": {
          "value": 6.48,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 232.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 159.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 9.8,
          "unit": "percent"
        },
        "p2": {
          "value": 6.72,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 248.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 170.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 10.15,
          "unit": "percent"
        },
        "p2": {
          "value": 6.96,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 264.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 181.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 7.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 280,
          "unit": "scalar"
        },
        "p5": {
          "value": 192,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.85,
          "unit": "percent"
        },
        "p2": {
          "value": 7.44,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 295.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 202.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 11.2,
          "unit": "percent"
        },
        "p2": {
          "value": 7.68,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 311.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 213.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 11.55,
          "unit": "percent"
        },
        "p2": {
          "value": 7.92,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 327.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 224.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 11.9,
          "unit": "percent"
        },
        "p2": {
          "value": 8.16,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 343,
          "unit": "scalar"
        },
        "p5": {
          "value": 235.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 12.25,
          "unit": "percent"
        },
        "p2": {
          "value": 8.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 358.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 246,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "ad2aff5e0339294e648678323a603f7a5034d8fd2710e7832bdf8ce7757a174b",
  "icon_path": "icon/skill/1105_skill.png"
}
```

### Gift of Rebirth

```json
{
  "ability_id": "110503",
  "slot": "ult",
  "name": "Gift of Rebirth",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "90",
  "toughness_break_primary_source": "90",
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
    "max_hp",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 9.2,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 9.78,
          "unit": "percent"
        },
        "p2": {
          "value": 147.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 10.35,
          "unit": "percent"
        },
        "p2": {
          "value": 188.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 10.92,
          "unit": "percent"
        },
        "p2": {
          "value": 230,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "percent"
        },
        "p2": {
          "value": 257.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 11.96,
          "unit": "percent"
        },
        "p2": {
          "value": 285.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 12.42,
          "unit": "percent"
        },
        "p2": {
          "value": 305.9,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 12.88,
          "unit": "percent"
        },
        "p2": {
          "value": 326.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 13.34,
          "unit": "percent"
        },
        "p2": {
          "value": 347.3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 13.8,
          "unit": "percent"
        },
        "p2": {
          "value": 368,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 14.26,
          "unit": "percent"
        },
        "p2": {
          "value": 388.7,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 14.72,
          "unit": "percent"
        },
        "p2": {
          "value": 409.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 15.18,
          "unit": "percent"
        },
        "p2": {
          "value": 430.1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 15.64,
          "unit": "percent"
        },
        "p2": {
          "value": 450.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 16.1,
          "unit": "percent"
        },
        "p2": {
          "value": 471.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "146feb35b20e63d12cc66d5e82a4e515479fcec133da31fd82290e30850aece5",
  "icon_path": "icon/skill/1105_ultimate.png"
}
```

### Innervation

```json
{
  "ability_id": "110504",
  "slot": "talent",
  "name": "Innervation",
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
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
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2fdf75dd048ac21c04829c9bb17a61bc1306740a56bf35cf6f5114a98567d28f",
  "icon_path": "icon/skill/1105_talent.png"
}
```

### Hypnosis Research

```json
{
  "ability_id": "110507",
  "slot": "technique",
  "name": "Hypnosis Research",
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
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 80,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e7087f37942c497914b05e9eff1309b682def92584a5c0e57b21041a3d667af2",
  "icon_path": "icon/skill/1105_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Soothe",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "cea140cf7200e57176f12f50fb0584d2390c16521d7fd71062188feedbc41b09"
  },
  {
    "requirement": "A4",
    "name": "Healer",
    "mechanic_tags": [
      "healing"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "a0afb39bc4ad7a4bc8a84f8b5462c7573522dac9c4fcde106a520119e6945da1"
  },
  {
    "requirement": "A6",
    "name": "Recuperation",
    "mechanic_tags": [
      "healing"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "fcda1bdf78f1708e9dd0b56a08a95a203b7babcf2abf60631815299363023679"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Pharmacology Expertise",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "30%",
      "1",
      "15%",
      "400",
      "1"
    ],
    "description_sha256": "2b0b5a24dca8df844d2a7a58da554dde1b4082e700a531fa1b76a7b0efa6ef97"
  },
  {
    "eidolon": 2,
    "name": "Clinical Research ",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "1",
      "30%",
      "6%",
      "160"
    ],
    "description_sha256": "f539593d0b8db471f890e26aa58c651de3117e167b24158ac92dd0f52efd9535"
  },
  {
    "eidolon": 3,
    "name": "The Right Cure",
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
    "name": "Miracle Cure",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "37245985d1408966a643e663076b3bf01022db4d5a6c798d3a5cf50c4dd8c4b2"
  },
  {
    "eidolon": 5,
    "name": "Preventive Treatment",
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
    "name": "Doctor’s Grace",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "e81b6d99e1791063bba3d808f7d2a441af1682329bafc246ce8705683c1225a5"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
