---
schema_version: "1.0.0"
unit_id: 1
name: "Trailblazer • Destruction"
slug: "trailblazer-destruction"
rarity: 5
element: "Physical"
path: "Destruction"
role: "Main DPS"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/trailblazer-destruction"
source_record_updated_at: "December 3rd, 2024"
dataset_snapshot: "2026-05-30"
---

# Trailblazer • Destruction

## Character record

```json
{
  "unit_id": 1,
  "name": "Trailblazer • Destruction",
  "slug": "trailblazer-destruction",
  "rarity": "5",
  "element": "Physical",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Astral Express",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 163.68,
    "def_base": 62.7,
    "atk_base": 84.48,
    "speed_base": 100
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "def",
      "value": 12.5
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
    "en": "Rachael Chau | Caleb Yen",
    "kr": "Kim Ha-ru (김하루) | Kim Myung-jun (김명준)",
    "jpn": "Ishikawa Yui (石川 由依) | Enoki Junya (榎木 淳弥)",
    "cn": "Chen Tingting (陈婷婷) | Qin Juge (秦且歌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/trailblazer-destruction",
  "source_record_updated_at": "December 3rd, 2024"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `800101` | Farewell Hit | Basic ATK | Single Target |
| `skill` | `800102` | RIP Home Run | Skill | Blast |
| `ult` | `800103` | Stardust Ace | Ultimate | Enhance |
| `ult_enh` | `800108` | Blowout: Farewell Hit | Ultimate | Single Target |
| `ult_enh2` | `800109` | Blowout: RIP Home Run | Ultimate | Blast |
| `talent` | `800104` | Perfect Pickoff | Talent | Enhance |
| `technique` | `800107` | Immortal Third Strike | Technique | Restore |

## Ability records

### Farewell Hit

```json
{
  "ability_id": "800101",
  "slot": "basic",
  "name": "Farewell Hit",
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
  "description_sha256": "0142f08aa8e2a764937f790ea5d8f7c9a4a489262122c96ff8abe580c04e3e08",
  "icon_path": "icon/skill/8001_basic_atk.png"
}
```

### RIP Home Run

```json
{
  "ability_id": "800102",
  "slot": "skill",
  "name": "RIP Home Run",
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
          "value": 62.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 68.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 81.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 93.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 101.56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 109.38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 117.19,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 137.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 143.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 156.25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a1dbf835ab0aeec51dbd79a2e51600e86a5c8473c58b5d63f92dce79707b1b50",
  "icon_path": "icon/skill/8001_skill.png"
}
```

### Stardust Ace

```json
{
  "ability_id": "800103",
  "slot": "ult",
  "name": "Stardust Ace",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        },
        "p3": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        },
        "p2": {
          "value": 189,
          "unit": "percent"
        },
        "p3": {
          "value": 113.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 330,
          "unit": "percent"
        },
        "p2": {
          "value": 198,
          "unit": "percent"
        },
        "p3": {
          "value": 118.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 345,
          "unit": "percent"
        },
        "p2": {
          "value": 207,
          "unit": "percent"
        },
        "p3": {
          "value": 124.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 216,
          "unit": "percent"
        },
        "p3": {
          "value": 129.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 375,
          "unit": "percent"
        },
        "p2": {
          "value": 225,
          "unit": "percent"
        },
        "p3": {
          "value": 135,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 393.75,
          "unit": "percent"
        },
        "p2": {
          "value": 236.25,
          "unit": "percent"
        },
        "p3": {
          "value": 141.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 412.5,
          "unit": "percent"
        },
        "p2": {
          "value": 247.5,
          "unit": "percent"
        },
        "p3": {
          "value": 148.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 431.25,
          "unit": "percent"
        },
        "p2": {
          "value": 258.75,
          "unit": "percent"
        },
        "p3": {
          "value": 155.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 450,
          "unit": "percent"
        },
        "p2": {
          "value": 270,
          "unit": "percent"
        },
        "p3": {
          "value": 162,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 465,
          "unit": "percent"
        },
        "p2": {
          "value": 279,
          "unit": "percent"
        },
        "p3": {
          "value": 167.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent"
        },
        "p2": {
          "value": 288,
          "unit": "percent"
        },
        "p3": {
          "value": 172.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 495,
          "unit": "percent"
        },
        "p2": {
          "value": 297,
          "unit": "percent"
        },
        "p3": {
          "value": 178.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 510,
          "unit": "percent"
        },
        "p2": {
          "value": 306,
          "unit": "percent"
        },
        "p3": {
          "value": 183.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 525,
          "unit": "percent"
        },
        "p2": {
          "value": 315,
          "unit": "percent"
        },
        "p3": {
          "value": 189,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "583bec9e0b0f40799d56fd4a1c24e9000cdba7a7a2ae230fee4f96e3626c6acf",
  "icon_path": "icon/skill/8001_ultimate.png"
}
```

### Blowout: Farewell Hit

```json
{
  "ability_id": "800108",
  "slot": "ult_enh",
  "name": "Blowout: Farewell Hit",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
          "value": 300,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 330,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 345,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 393.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 412.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 431.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 450,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 465,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 495,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 510,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 525,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "0142f08aa8e2a764937f790ea5d8f7c9a4a489262122c96ff8abe580c04e3e08",
  "icon_path": "icon/skill/8001_ultimate.png"
}
```

### Blowout: RIP Home Run

```json
{
  "ability_id": "800109",
  "slot": "ult_enh2",
  "name": "Blowout: RIP Home Run",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "60",
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
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 189,
          "unit": "percent"
        },
        "p2": {
          "value": 113.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 198,
          "unit": "percent"
        },
        "p2": {
          "value": 118.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 207,
          "unit": "percent"
        },
        "p2": {
          "value": 124.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 129.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        },
        "p2": {
          "value": 135,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 236.25,
          "unit": "percent"
        },
        "p2": {
          "value": 141.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 247.5,
          "unit": "percent"
        },
        "p2": {
          "value": 148.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 258.75,
          "unit": "percent"
        },
        "p2": {
          "value": 155.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 162,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 279,
          "unit": "percent"
        },
        "p2": {
          "value": 167.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 172.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 297,
          "unit": "percent"
        },
        "p2": {
          "value": 178.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 306,
          "unit": "percent"
        },
        "p2": {
          "value": 183.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        },
        "p2": {
          "value": 189,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "3c97263328c3b861f5fd7a72425d4d33a224ebd9b42b4e79ff2dbf34738cc53c",
  "icon_path": "icon/skill/8001_ultimate.png"
}
```

### Perfect Pickoff

```json
{
  "ability_id": "800104",
  "slot": "talent",
  "name": "Perfect Pickoff",
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
    "atk",
    "weakness"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
      "source_row": 12,
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
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 23,
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
          "value": 24,
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
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "fb094d31cc1b5b73a90b0371ddb2a2a6c2aa7fd4edc69080e14a715d1c02cafc",
  "icon_path": "icon/skill/8001_talent.png"
}
```

### Immortal Third Strike

```json
{
  "ability_id": "800107",
  "slot": "technique",
  "name": "Immortal Third Strike",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
          "value": 15,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "08c57cce51f7b92499d4ff7415cd7573accf11f120465781e2e63af202a3fc26",
  "icon_path": "icon/skill/8001_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Ready for Battle",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15"
    ],
    "description_sha256": "49cd4ce181fe9ef5e523e5e955c0ba45a10293d800b6cada079d46e153b03889"
  },
  {
    "requirement": "A4",
    "name": "Perseverance",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "f4b7f43d297c3f1c66e35105c1ae8873ad8183d54e04dcfd0cf12d12be6f3349"
  },
  {
    "requirement": "A6",
    "name": "Fighting Will",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "f88ca6d2a9d3149a74523df590dcdb501a30f5c718fc4db229f111d84850463b"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "A Falling Star",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "ce2da2201db6bdb4476f151700b4ebef486a3bb81314c5f11d29e1afb990080d"
  },
  {
    "eidolon": 2,
    "name": "An Unwilling Host",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "weakness"
    ],
    "numeric_tokens": [
      "5%"
    ],
    "description_sha256": "7d106e782c225dcbc6baa43eb44ca79b3980b6278bf33e522e663760df2e9f32"
  },
  {
    "eidolon": 3,
    "name": "A Leading Whisper",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "2",
      "15"
    ],
    "description_sha256": "44510026b640c061e66a47941f11c1c4630d9468a08550a63ed1ea32fdb09b0c"
  },
  {
    "eidolon": 4,
    "name": "A Destructing Glance",
    "mechanic_tags": [
      "crit_rate",
      "weakness"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "40e00141d6f18a640e6bcb329f21b7c7b04775326feeb624a296fbedd71c9e26"
  },
  {
    "eidolon": 5,
    "name": "A Surviving Hope",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "ef41c0ce13bfa86071ef69fe2f437f6e8c5c3a055a9891381b35b408b406063e"
  },
  {
    "eidolon": 6,
    "name": "A Trailblazing Will",
    "mechanic_tags": [],
    "numeric_tokens": [],
    "description_sha256": "484b2c48492855edde0209285c44ae7ae0b9cc6c1df742f0e33dcb47b011b89c"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
