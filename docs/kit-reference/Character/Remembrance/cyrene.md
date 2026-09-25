---
schema_version: "1.0.0"
unit_id: 83
name: "Cyrene"
slug: "cyrene"
rarity: 5
element: "Ice"
path: "Remembrance"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/cyrene"
source_record_updated_at: "December 16th, 2025"
dataset_snapshot: "2026-05-30"
---

# Cyrene

## Character record

```json
{
  "unit_id": 83,
  "name": "Cyrene",
  "slug": "cyrene",
  "rarity": "5",
  "element": "Ice",
  "path": "Remembrance",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "November 5th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "24",
  "base_stats": {
    "hp_base": 190,
    "def_base": 79.2,
    "atk_base": 60.72,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "crit_dmg",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "speed",
      "value": 9
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Aiden Dawn",
    "kr": "Jo Kyoung-i (조경이)",
    "jpn": "Inoue Marina (井上 麻里奈)",
    "cn": "Yanning (宴宁)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/cyrene",
  "source_record_updated_at": "December 16th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `141501` | Lo, Hope Takes Flight! | Basic ATK | Single Target |
| `basic_enh` | `141508` | To Love and Tomorrow ♪ | Basic ATK | AoE |
| `skill` | `141502` | Bloom, Elysium of Beyond | Skill | Support |
| `ult` | `141503` | Verse ◦ Vow ∞ | Ultimate | Summon |
| `talent` | `141504` | Hearts Gather as One | Talent | Enhance |
| `technique` | `141507` | Peace at West Wind's End | Technique | Support |
| `supplementary` | `1415010` | Minuet of Blooms and Plumes | Memosprite Skill | AoE |
| `supplementary` | `1415011` | This Ode, to All Lives | Memosprite Skill | Support |
| `supplementary` | `1415012` | Waiting, In Every Past | Memosprite Talent | Enhance |
| `supplementary` | `1415013` | "Hello, World ♪" | Memosprite Talent | Support |
| `supplementary` | `1415014` | Ode to Genesis | Memosprite Talent | Support |
| `supplementary` | `1415015` | Ode to Romance | Memosprite Talent | Support |
| `supplementary` | `1415016` | Ode to Passage | Memosprite Talent | Support |
| `supplementary` | `1415017` | Ode to Strife | Memosprite Talent | Support |
| `supplementary` | `1415018` | Ode to Life and Death | Memosprite Talent | Support |
| `supplementary` | `1415019` | Ode to Reason | Memosprite Talent | Support |
| `supplementary` | `1415020` | Ode to Sky | Memosprite Talent | Support |
| `supplementary` | `1415021` | Ode to Trickery | Memosprite Talent | Support |
| `supplementary` | `1415022` | Ode to Worldbearing | Memosprite Talent | Support |
| `supplementary` | `1415023` | Ode to Time | Memosprite Talent | Support |
| `supplementary` | `1415024` | Ode to Law | Memosprite Talent | Support |
| `supplementary` | `1415025` | Ode to ██ | Memosprite Talent | Support |
| `supplementary` | `1415026` | Ode to Earth | Memosprite Talent | Support |
| `supplementary` | `1415027` | Ode to Ocean | Memosprite Talent | Support |

## Ability records

### Lo, Hope Takes Flight!

```json
{
  "ability_id": "141501",
  "slot": "basic",
  "name": "Lo, Hope Takes Flight!",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
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
    "max_hp",
    "dmg"
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
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "467c35969354608532ba8e6e39721075c662e46c703e49df14cf4f4c3d7b46da",
  "icon_path": null
}
```

### To Love and Tomorrow ♪

```json
{
  "ability_id": "141508",
  "slot": "basic_enh",
  "name": "To Love and Tomorrow ♪",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 9,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg",
    "skill_points"
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
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 27,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8f5f9603299e97d8f1436df55226ba044a066ec23d8df8591be0c22fed2b420f",
  "icon_path": null
}
```

### Bloom, Elysium of Beyond

```json
{
  "ability_id": "141502",
  "slot": "skill",
  "name": "Bloom, Elysium of Beyond",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b82d0df8d4697422d83983320d90f0affc6dde0c169ea58093fabb51d41aab76",
  "icon_path": null
}
```

### Verse ◦ Vow ∞

```json
{
  "ability_id": "141503",
  "slot": "ult",
  "name": "Verse ◦ Vow ∞",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Summon",
  "targeting_label": "Summon",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": "24",
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
    "atk",
    "crit_rate",
    "summon"
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
          "value": 40.625,
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
          "value": 46.875,
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
    }
  ],
  "description_sha256": "5f2ba7e91034bec913a25c48d7e4a67c94048c33c7b77acd26b4d0b4fbcda7cf",
  "icon_path": null
}
```

### Hearts Gather as One

```json
{
  "ability_id": "141504",
  "slot": "talent",
  "name": "Hearts Gather as One",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
    "dmg",
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 18.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "3500b50cd533541307b670c2330acc71e01518ca7ebc6e3a3a86a0f512d48e10",
  "icon_path": null
}
```

### Peace at West Wind's End

```json
{
  "ability_id": "141507",
  "slot": "technique",
  "name": "Peace at West Wind's End",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "spd"
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
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "95c6f942fc72d1bed1cabb338c19dcb7f3f60fa50ef5652d918fde8e8f6cf01b",
  "icon_path": null
}
```

### Minuet of Blooms and Plumes

```json
{
  "ability_id": "1415010",
  "slot": "supplementary",
  "name": "Minuet of Blooms and Plumes",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8ea9095a98bc91412f9cfd120f3882e9a935a94ce2b35819e7114fc6e3a4ad76",
  "icon_path": null
}
```

### This Ode, to All Lives

```json
{
  "ability_id": "1415011",
  "slot": "supplementary",
  "name": "This Ode, to All Lives",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "916af10e7159f0421689c8d78d20e2818dbb482f64922a67a7f36a0ba4f42003",
  "icon_path": null
}
```

### Waiting, In Every Past

```json
{
  "ability_id": "1415012",
  "slot": "supplementary",
  "name": "Waiting, In Every Past",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "spd"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 28.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 31.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 33.6,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5d5378026a518816b9131ddd474e166ce951e7b91c57b2f809d9fcaee9f5e804",
  "icon_path": null
}
```

### "Hello, World ♪"

```json
{
  "ability_id": "1415013",
  "slot": "supplementary",
  "name": "\"Hello, World ♪\"",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.06,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1f556071a4be858e4c4ea4a8750b09fda5584a3420543fe179056edd4e4435ce",
  "icon_path": null
}
```

### Ode to Genesis

```json
{
  "ability_id": "1415014",
  "slot": "supplementary",
  "name": "Ode to Genesis",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "atk",
    "crit_rate"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 9.6,
          "unit": "percent"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 11.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 12.8,
          "unit": "percent"
        },
        "p2": {
          "value": 57.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 64.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 17.6,
          "unit": "percent"
        },
        "p2": {
          "value": 79.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 20.8,
          "unit": "percent"
        },
        "p2": {
          "value": 93.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 22.4,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5cb9ee1e50ae4acfc9a27961c2f8bff3f13462d668d8b5471793c6fabd32dfa1",
  "icon_path": null
}
```

### Ode to Romance

```json
{
  "ability_id": "1415015",
  "slot": "supplementary",
  "name": "Ode to Romance",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "def",
    "spd",
    "energy",
    "dmg",
    "summon"
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
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 28.8,
          "unit": "percent"
        },
        "p2": {
          "value": 57.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 32.4,
          "unit": "percent"
        },
        "p2": {
          "value": 64.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 79.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        },
        "p2": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.8,
          "unit": "percent"
        },
        "p2": {
          "value": 93.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e5236e68b0d4019ddae7436b37e8131f37fab95e07cbccb75f5ea20cb959a009",
  "icon_path": null
}
```

### Ode to Passage

```json
{
  "ability_id": "1415016",
  "slot": "supplementary",
  "name": "Ode to Passage",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2fc3ce745b5b8cbbbb4b486e4bbcbc03ed7dfc6a505ac6608fbf59297eb0123e",
  "icon_path": null
}
```

### Ode to Strife

```json
{
  "ability_id": "1415017",
  "slot": "supplementary",
  "name": "Ode to Strife",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "crit_dmg",
    "dmg",
    "action_advance",
    "debuff",
    "buff"
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
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 180,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 260,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 280,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "dadd085c759d44ea84588d9e85028b36114b593ed2e186ca1cce492b59971daf",
  "icon_path": null
}
```

### Ode to Life and Death

```json
{
  "ability_id": "1415018",
  "slot": "supplementary",
  "name": "Ode to Life and Death",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.12,
          "unit": "percent"
        },
        "p2": {
          "value": 0.24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 0.144,
          "unit": "percent"
        },
        "p2": {
          "value": 0.288,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 0.168,
          "unit": "percent"
        },
        "p2": {
          "value": 0.336,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 0.192,
          "unit": "percent"
        },
        "p2": {
          "value": 0.384,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 0.216,
          "unit": "percent"
        },
        "p2": {
          "value": 0.432,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 0.24,
          "unit": "percent"
        },
        "p2": {
          "value": 0.48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 0.264,
          "unit": "percent"
        },
        "p2": {
          "value": 0.528,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 0.288,
          "unit": "percent"
        },
        "p2": {
          "value": 0.576,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 0.312,
          "unit": "percent"
        },
        "p2": {
          "value": 0.624,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 0.336,
          "unit": "percent"
        },
        "p2": {
          "value": 0.672,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ea2d190ca3cc81dc09130fe338173037581175da3ef58039aa0f00b652b3e430",
  "icon_path": null
}
```

### Ode to Reason

```json
{
  "ability_id": "1415019",
  "slot": "supplementary",
  "name": "Ode to Reason",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "skill_points"
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
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e4cc11034226a41f679e048595005cf01d65a2332d742478e7c33ef803181415",
  "icon_path": null
}
```

### Ode to Sky

```json
{
  "ability_id": "1415020",
  "slot": "supplementary",
  "name": "Ode to Sky",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "energy",
    "healing",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        },
        "p2": {
          "value": 14.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        },
        "p2": {
          "value": 16.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 57.6,
          "unit": "percent"
        },
        "p2": {
          "value": 19.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 64.8,
          "unit": "percent"
        },
        "p2": {
          "value": 21.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 79.2,
          "unit": "percent"
        },
        "p2": {
          "value": 26.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        },
        "p2": {
          "value": 28.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 93.6,
          "unit": "percent"
        },
        "p2": {
          "value": 31.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 100.8,
          "unit": "percent"
        },
        "p2": {
          "value": 33.6,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "e794d16d35adfbcadb7fd7e91849ae803eb7c721fc030060f5eb6f809d1aeb10",
  "icon_path": null
}
```

### Ode to Trickery

```json
{
  "ability_id": "1415021",
  "slot": "supplementary",
  "name": "Ode to Trickery",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "def",
    "dmg"
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
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 28.8,
          "unit": "percent"
        },
        "p2": {
          "value": 16,
          "unit": "percent"
        },
        "p3": {
          "value": 9.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 32.4,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 10.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.8,
          "unit": "percent"
        },
        "p2": {
          "value": 26,
          "unit": "percent"
        },
        "p3": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "175e282edf582617dbc468800fb6b9e0591ea1b60a5781072ce475215653caef",
  "icon_path": null
}
```

### Ode to Worldbearing

```json
{
  "ability_id": "1415022",
  "slot": "supplementary",
  "name": "Ode to Worldbearing",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "crit_rate",
    "crit_dmg",
    "dmg"
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
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 8,
          "unit": "percent"
        },
        "p4": {
          "value": 5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        },
        "p3": {
          "value": 9.6,
          "unit": "percent"
        },
        "p4": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50.4,
          "unit": "percent"
        },
        "p3": {
          "value": 11.2,
          "unit": "percent"
        },
        "p4": {
          "value": 7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.6,
          "unit": "percent"
        },
        "p2": {
          "value": 57.6,
          "unit": "percent"
        },
        "p3": {
          "value": 12.8,
          "unit": "percent"
        },
        "p4": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 64.8,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 79.2,
          "unit": "percent"
        },
        "p3": {
          "value": 17.6,
          "unit": "percent"
        },
        "p4": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 86.4,
          "unit": "percent"
        },
        "p3": {
          "value": 19.2,
          "unit": "percent"
        },
        "p4": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        },
        "p2": {
          "value": 93.6,
          "unit": "percent"
        },
        "p3": {
          "value": 20.8,
          "unit": "percent"
        },
        "p4": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "percent"
        },
        "p3": {
          "value": 22.4,
          "unit": "percent"
        },
        "p4": {
          "value": 14,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9cb146e44ac663f23ffc9793776e4e9805f1b60a35cc263814fc51d2fc2bb57e",
  "icon_path": null
}
```

### Ode to Time

```json
{
  "ability_id": "1415023",
  "slot": "supplementary",
  "name": "Ode to Time",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "crit_dmg",
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 12.6,
          "unit": "percent"
        },
        "p2": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 9.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.2,
          "unit": "percent"
        },
        "p2": {
          "value": 10.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.8,
          "unit": "percent"
        },
        "p2": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 23.4,
          "unit": "percent"
        },
        "p2": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "eef7fd089767d5258de81e5d19fbcd536bcc721d2a23733ce4ef514dfc04a6c5",
  "icon_path": null
}
```

### Ode to Law

```json
{
  "ability_id": "1415024",
  "slot": "supplementary",
  "name": "Ode to Law",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "crit_dmg",
    "dmg"
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
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 27,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "aa9f97af887b6c1fbf07c3c799d480508156b915d1de082f5e62f206bf4c9808",
  "icon_path": null
}
```

### Ode to ██

```json
{
  "ability_id": "1415025",
  "slot": "supplementary",
  "name": "Ode to ██",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "0fa483dfde55b318ee0c2301e45e29bc764b29d4751ebdda1a90f3e0f9789208",
  "icon_path": null
}
```

### Ode to Earth

```json
{
  "ability_id": "1415026",
  "slot": "supplementary",
  "name": "Ode to Earth",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
    "dmg",
    "action_advance",
    "shield",
    "summon"
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
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 19.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 21.6,
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
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 28.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 31.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 112,
          "unit": "percent"
        },
        "p2": {
          "value": 33.6,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7bc005b78e909c08e1cc9152a04094f53313fcc2df3bdfa65ae31088a4f826cf",
  "icon_path": null
}
```

### Ode to Ocean

```json
{
  "ability_id": "1415027",
  "slot": "supplementary",
  "name": "Ode to Ocean",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 2
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "energy",
    "dmg",
    "dot"
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 0.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 0.72,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        },
        "p3": {
          "value": 0.84,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        },
        "p3": {
          "value": 0.96,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 1.08,
          "unit": "scalar"
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 1.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 1.32,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 1.44,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        },
        "p3": {
          "value": 1.56,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 112,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 1.68,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b811d13cd4e1726042810b9617ebf6310fd1bec67978da584faef47e915d914b",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Child of Remembrance",
    "mechanic_tags": [
      "summon"
    ],
    "numeric_tokens": [],
    "description_sha256": "4434fb638add81c78949eb5c21c702b95c00b426557892353699200350043388"
  },
  {
    "requirement": "A4",
    "name": "Ripples Across Time",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "2",
      "3",
      "2",
      "3",
      "6"
    ],
    "description_sha256": "838c705feb04a23202da7b3000b40aa554d46c8691eafa1827e09f37b13f9953"
  },
  {
    "requirement": "A6",
    "name": "Causality in Trichotomy",
    "mechanic_tags": [
      "spd",
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "180",
      "20%",
      "2%",
      "60"
    ],
    "description_sha256": "742db0c3c19ea576d5d53ed48029701354345976fa6f2b787749c018aacb315f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Epics, Born on a Blank Slate",
    "mechanic_tags": [
      "summon"
    ],
    "numeric_tokens": [
      "6",
      "12"
    ],
    "description_sha256": "4dd156fad793a665b9c00a01d5cb8c3511079b984d4df5b38bcc8146be4e80ed"
  },
  {
    "eidolon": 2,
    "name": "A Tomorrow in Thirteen Shades",
    "mechanic_tags": [
      "dmg",
      "buff",
      "summon"
    ],
    "numeric_tokens": [
      "12",
      "6%",
      "24%"
    ],
    "description_sha256": "c5a7941bf912d122a52776bb88b61be097f7f300c39a3b71e5285c767d9a0412"
  },
  {
    "eidolon": 3,
    "name": "By Thy Being, As I've Written",
    "mechanic_tags": [
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "23416b132409e1464c2f5c3c885cc7f59b28156ac8c3f54b8f5810ee688bfff6"
  },
  {
    "eidolon": 4,
    "name": "Please Write On, With a Smile",
    "mechanic_tags": [
      "dmg",
      "summon"
    ],
    "numeric_tokens": [
      "6%",
      "24"
    ],
    "description_sha256": "997607cdd8d942406d37ca2d66c8894bec57f3fdc2adb310af3b5e6e70b73d6e"
  },
  {
    "eidolon": 5,
    "name": "Gaze, Steeped in Yesterbloom",
    "mechanic_tags": [
      "atk",
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "10"
    ],
    "description_sha256": "caa57e8e3ae8bb906e5bee9b2eaa3b89cd95e7183ecf5eb6915f8e39c828eb66"
  },
  {
    "eidolon": 6,
    "name": "Remembrance, Sung in Ripples ♪",
    "mechanic_tags": [
      "def",
      "action_advance",
      "summon"
    ],
    "numeric_tokens": [
      "100%",
      "1",
      "20%",
      "2",
      "24%"
    ],
    "description_sha256": "1dc909b6ffd08e837cf511123b8cfab0e8bd47552a4a87ada2589d81e1440b7c"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
