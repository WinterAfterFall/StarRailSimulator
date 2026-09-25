---
schema_version: "1.0.0"
unit_id: 34
name: "Dan Heng • Imbibitor Lunae"
slug: "imbibitor-lunae"
rarity: 5
element: "Imaginary"
path: "Destruction"
role: "Main DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/imbibitor-lunae"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Dan Heng • Imbibitor Lunae

## Character record

```json
{
  "unit_id": 34,
  "name": "Dan Heng • Imbibitor Lunae",
  "slug": "imbibitor-lunae",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "August 30th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 49.5,
    "atk_base": 95.04,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "dmg_imaginary",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "critRate",
      "value": 12
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Nicholas Leung",
    "kr": "Kim Hye-sung (김혜성)",
    "jpn": "Kento Itō (伊東健人)",
    "cn": "Yú Dòng (魚凍)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/imbibitor-lunae",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121301` | Beneficent Lotus | Basic ATK | Single Target |
| `basic_enh` | `121308` | Transcendence | Basic ATK | Single Target |
| `basic_enh2` | `121310` | Divine Spear | Basic ATK | Blast |
| `basic_enh3` | `121312` | Fulgurant Leap | Basic ATK | Blast |
| `skill` | `121302` | Dracore Libre | Skill | Enhance |
| `ult` | `121303` | Azure's Aqua Ablutes All | Ultimate | Blast |
| `talent` | `121304` | Righteous Heart | Talent | Enhance |
| `technique` | `121307` | Heaven-Quelling Prismadrakon | Technique | Enhance |
| `supplementary` | `121309` | Cancel | Skill | Cancel |

## Ability records

### Beneficent Lotus

```json
{
  "ability_id": "121301",
  "slot": "basic",
  "name": "Beneficent Lotus",
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
  "description_sha256": "29bd4184f00503f4871cfe64901331eee32f2f92e783ba99e8c1308bb4d94582",
  "icon_path": "icon/skill/1213_basic_atk.png"
}
```

### Transcendence

```json
{
  "ability_id": "121308",
  "slot": "basic_enh",
  "name": "Transcendence",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
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
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 182,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 208,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 234,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 260,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 286,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 312,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 338,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "64ab5a5c016eb9b5fd6d3cc9d38bb95a1a48d385e9d1af11bc632dcbcb5855bd",
  "icon_path": "icon/skill/1213_basic_atk.png"
}
```

### Divine Spear

```json
{
  "ability_id": "121310",
  "slot": "basic_enh2",
  "name": "Divine Spear",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "35",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": "30",
  "source_max_level": 9,
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
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 190,
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
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 266,
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
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 342,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 418,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
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
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 342,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 418,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 456,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 494,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7ff7919c1cbe9c94f9bdda596c39b0cc769d6822d6a0b4636178df5c98f80629",
  "icon_path": "icon/skill/1213_basic_atk.png"
}
```

### Fulgurant Leap

```json
{
  "ability_id": "121312",
  "slot": "basic_enh3",
  "name": "Fulgurant Leap",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "40",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "120",
  "toughness_break_secondary_source": "60",
  "source_max_level": 9,
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
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 350,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 400,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 450,
          "unit": "percent"
        },
        "p2": {
          "value": 162,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 500,
          "unit": "percent"
        },
        "p2": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 550,
          "unit": "percent"
        },
        "p2": {
          "value": 198,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 600,
          "unit": "percent"
        },
        "p2": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 650,
          "unit": "percent"
        },
        "p2": {
          "value": 234,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fa5e97eca1086e849b9b9c48ce020f491df57aeec62933b9f7586390d2dafc25",
  "icon_path": "icon/skill/1213_basic_atk.png"
}
```

### Dracore Libre

```json
{
  "ability_id": "121302",
  "slot": "skill",
  "name": "Dracore Libre",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
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
    "crit_dmg",
    "dmg",
    "skill_points"
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
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 6.6,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 7.8,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 9.75,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 11.25,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 12.6,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 13.8,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c7f5a03cc9720b320134697ad64c5b7d7c0879e14bebcef54579e626f50231eb",
  "icon_path": "icon/skill/1213_skill.png"
}
```

### Azure's Aqua Ablutes All

```json
{
  "ability_id": "121303",
  "slot": "ult",
  "name": "Azure's Aqua Ablutes All",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "skill_points"
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
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 89.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 204,
          "unit": "percent"
        },
        "p2": {
          "value": 95.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 106.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 112,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 255,
          "unit": "percent"
        },
        "p2": {
          "value": 119,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 285,
          "unit": "percent"
        },
        "p2": {
          "value": 133,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 312,
          "unit": "percent"
        },
        "p2": {
          "value": 145.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 324,
          "unit": "percent"
        },
        "p2": {
          "value": 151.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 336,
          "unit": "percent"
        },
        "p2": {
          "value": 156.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 348,
          "unit": "percent"
        },
        "p2": {
          "value": 162.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 168,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "904212829625d9bb21815728edb935a1580d009e3897fa4631bfd11d7ab230a2",
  "icon_path": "icon/skill/1213_ultimate.png"
}
```

### Righteous Heart

```json
{
  "ability_id": "121304",
  "slot": "talent",
  "name": "Righteous Heart",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 6.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8.13,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 8.75,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.38,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
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
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 12.5,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "46b834aabd73900cb544ea3d051adde2b60df56c05fb916dd5a34c5136e5aa57",
  "icon_path": "icon/skill/1213_talent.png"
}
```

### Heaven-Quelling Prismadrakon

```json
{
  "ability_id": "121307",
  "slot": "technique",
  "name": "Heaven-Quelling Prismadrakon",
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
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p1": {
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
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 20,
          "unit": "scalar"
        },
        "p3": {
          "value": 120,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "485db392c4f82fd8cb694c837d2ec2e6b66a37736ba0644a6601aba4aa5438fc",
  "icon_path": "icon/skill/1213_technique.png"
}
```

### Cancel

```json
{
  "ability_id": "121309",
  "slot": "supplementary",
  "name": "Cancel",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Enhance",
  "targeting_label": "Cancel",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [],
  "level_scaling": [],
  "description_sha256": "8f30453b2ac10a9daedc634d40db0718837ba436a245c6c2ec2c4dcf11487fcc",
  "icon_path": "icon/skill/1213_skill.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Star Veil",
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
    "name": "Aqua Reign",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "9f826e4a935a4d9a3c8fb239c5156fa5e14bc9a0fbcb1843e41e599a6ba68291"
  },
  {
    "requirement": "A6",
    "name": "Jolt Anew",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "24%"
    ],
    "description_sha256": "a3ae5528aebac1b396d56bfd092eaf71298b8b3e21719ab8b5cdab00ae3725d9"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Tethered to Sky",
    "mechanic_tags": [],
    "numeric_tokens": [
      "4",
      "1"
    ],
    "description_sha256": "ac784134d6c27684cf46c4a254986a2370166ab686d201dd806a54c97d91cb23"
  },
  {
    "eidolon": 2,
    "name": "Imperium On Cloud Nine",
    "mechanic_tags": [],
    "numeric_tokens": [
      "100%",
      "1"
    ],
    "description_sha256": "e05a267b1077703e74507e853c7aaf2926c477bf9d77d893bd4de646bf0938c8"
  },
  {
    "eidolon": 3,
    "name": "Clothed in Clouds",
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
    "name": "Zephyr's Bliss",
    "mechanic_tags": [
      "buff"
    ],
    "numeric_tokens": [],
    "description_sha256": "4439e99c29b6569229d1ee41ede71ce698560040189edd6dc3235c54f91c1b5f"
  },
  {
    "eidolon": 5,
    "name": "Fall is the Pride",
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
    "name": "Reign, Returned",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "20%",
      "3"
    ],
    "description_sha256": "7f78a2d8717368ac858000d4cdb2562a78fa526d9c6449a37815b7e98423c5a2"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
