---
schema_version: "1.0.0"
unit_id: 41
name: "Argenti"
slug: "argenti"
rarity: 5
element: "Physical"
path: "Erudition"
role: "Main DPS"
affiliation: "The Knights of Beauty"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/argenti"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Argenti

## Character record

```json
{
  "unit_id": 41,
  "name": "Argenti",
  "slug": "argenti",
  "rarity": "5",
  "element": "Physical",
  "path": "Erudition",
  "default_role": "Main DPS",
  "affiliation": "The Knights of Beauty",
  "release_date": "December 6th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "90",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 49.5,
    "atk_base": 100.32,
    "speed_base": 103
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "physicalDmg",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Adam Michael Gold",
    "kr": "최승훈 (Choi Seung-hoon)",
    "jpn": "立花慎之介 (Tachibana Shinnosuke)",
    "cn": "梁达伟 (Liang Dawei)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/argenti",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130201` | Fleeting Fragrance | Basic ATK | Single Target |
| `skill` | `130202` | Justice, Hereby Blooms | Skill | AoE |
| `ult` | `130203` | For In This Garden Supreme Beauty Bestows | Ultimate | AoE |
| `ult_enh` | `130214` | Merit Bestowed in "My" Garden | Ultimate | AoE |
| `talent` | `130204` | Sublime Object | Talent | Enhance |
| `technique` | `130207` | Manifesto of Purest Virtue | Technique | Impair |

## Ability records

### Fleeting Fragrance

```json
{
  "ability_id": "130201",
  "slot": "basic",
  "name": "Fleeting Fragrance",
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
  "description_sha256": "c0d74b6987e8ea57e209e35475fe89c8f8520844848af84d51102ad6d2e08147",
  "icon_path": "icon/skill/1302_basic_atk.png"
}
```

### Justice, Hereby Blooms

```json
{
  "ability_id": "130202",
  "slot": "skill",
  "name": "Justice, Hereby Blooms",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
          "value": 60,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 72,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 84,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 97.5,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 112.5,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 126,
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
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b7df50357fbc7e2f97514f7b16675c1589913888c87fda8a562fd91438b56d9d",
  "icon_path": "icon/skill/1302_skill.png"
}
```

### For In This Garden Supreme Beauty Bestows

```json
{
  "ability_id": "130203",
  "slot": "ult",
  "name": "For In This Garden Supreme Beauty Bestows",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "90",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 102.4,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 108.8,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 115.2,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 121.6,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 166.4,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 179.2,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 185.6,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "782975c562f80684f24d79c80fe1c28dedaff7d7052db3c1e255976e20034be1",
  "icon_path": "icon/skill/1302_ultimate.png"
}
```

### Merit Bestowed in "My" Garden

```json
{
  "ability_id": "130214",
  "slot": "ult_enh",
  "name": "Merit Bestowed in \"My\" Garden",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "90",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "5",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
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
    }
  },
  "mechanic_tags": [
    "atk",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 57,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 179.2,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 60.8,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 190.4,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 64.6,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 201.6,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 68.4,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 212.8,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 72.2,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 224,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 76,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 238,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 80.75,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 252,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 85.5,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 266,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 90.25,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 280,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 95,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 291.2,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 98.8,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 302.4,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 102.6,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 313.6,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 106.4,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 324.8,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 110.2,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 336,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        },
        "p3": {
          "value": 114,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "057ce5776ca98e1be53d290e7e58d3b260b182be3808dd081d3f674ed67cc197",
  "icon_path": "icon/skill/1302_ultimate.png"
}
```

### Sublime Object

```json
{
  "ability_id": "130204",
  "slot": "talent",
  "name": "Sublime Object",
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
      "unit": "scalar",
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
    "crit_rate",
    "energy"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.15,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.3,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.45,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.6,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.75,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 1.94,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.13,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.31,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.5,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.65,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.8,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 2.95,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 3.1,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        },
        "p2": {
          "value": 3.25,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "40ff8cc4b043af1ce00fe12330f7383de3564e07f40ed65afb9249be5083fe4e",
  "icon_path": "icon/skill/1302_talent.png"
}
```

### Manifesto of Purest Virtue

```json
{
  "ability_id": "130207",
  "slot": "technique",
  "name": "Manifesto of Purest Virtue",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Physical",
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
    "energy",
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
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "5b922b648ea5888dc7293db18108d8e9f846e378eafef2db3169d5c717c22b10",
  "icon_path": "icon/skill/1302_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Piety",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "ac80c2b132e3e661c4d95ca96fa201d87556300380b421dd8f2f296ad4538493"
  },
  {
    "requirement": "A4",
    "name": "Generosity",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "f51f763acf1deeb4f5c400e22f6b8a82ee3248c94365e5b1753b47f7138a2041"
  },
  {
    "requirement": "A6",
    "name": "Courage",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "50%"
    ],
    "description_sha256": "0728ea252908896e909cbf73e37f06230f363c0588d4a2aab7cf766cdb1df555"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "A Lacuna in Kingdom of Aesthetics",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "4%"
    ],
    "description_sha256": "35c40179bff00461933ca0c24946e5a8b942241efe0019f776a28d6c8bc41082"
  },
  {
    "eidolon": 2,
    "name": "Agate's Humility",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "3",
      "40%",
      "1"
    ],
    "description_sha256": "1c58d1132b6dd5f3ec16f7256dcdef234686cb35547cd78b8ec8ab30ccd79898"
  },
  {
    "eidolon": 3,
    "name": "Thorny Road's Glory",
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
    "eidolon": 4,
    "name": "Trumpet's Dedication",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "2"
    ],
    "description_sha256": "aee43bf704b078d16e5f85943ce8f381590a46da4fc85cd1b5fb36e14a271fe8"
  },
  {
    "eidolon": 5,
    "name": "Snow, From Somewhere in Cosmos",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "46402f3fd88f0892b8f3ad52b7ab2869b27a7116aac3170c5f38c98673ff743a"
  },
  {
    "eidolon": 6,
    "name": "\"Your\" Resplendence",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "0f8b2f60726a7648a1180ed400c0e4c4df5b1fe4a3fa9d1b078f9726f1fc16f4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
