---
schema_version: "1.0.0"
unit_id: 11
name: "Herta"
slug: "herta"
rarity: 4
element: "Ice"
path: "Erudition"
role: "Sub DPS"
affiliation: "Herta Space Station"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/herta"
source_record_updated_at: "January 25th, 2025"
dataset_snapshot: "2026-05-30"
---

# Herta

## Character record

```json
{
  "unit_id": 11,
  "name": "Herta",
  "slug": "herta",
  "rarity": "4",
  "element": "Ice",
  "path": "Erudition",
  "default_role": "Sub DPS",
  "affiliation": "Herta Space Station",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 129.6,
    "def_base": 54,
    "atk_base": 79.2,
    "speed_base": 100
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat3": {
      "stat": "critRate",
      "value": 6.7
    }
  },
  "voice_actors": {
    "en": "PJ Mattson",
    "kr": "Kim Seo-yeong (김서영)",
    "jpn": "Yamazaki Haruka (山崎はるか)",
    "cn": "Hou Xiaofei (侯小菲)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/herta",
  "source_record_updated_at": "January 25th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `101301` | What Are You Looking At? | Basic ATK | Single Target |
| `skill` | `101302` | One-Time Offer | Skill | AoE |
| `ult` | `101303` | It's Magic, I Added Some Magic | Ultimate | AoE |
| `talent` | `101304` | Fine, I'll Do It Myself | Talent | AoE |
| `technique` | `101307` | It Can Still Be Optimized | Technique | Enhance |

## Ability records

### What Are You Looking At?

```json
{
  "ability_id": "101301",
  "slot": "basic",
  "name": "What Are You Looking At?",
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
  "description_sha256": "f54156b5e89e0d1f3df5dff12a1289b320c66e7ae393c987ae353c3185af9b28",
  "icon_path": "icon/skill/1013_basic_atk.png"
}
```

### One-Time Offer

```json
{
  "ability_id": "101302",
  "slot": "skill",
  "name": "One-Time Offer",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
    "max_hp",
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
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 81.25,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 93.75,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
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
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 115,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c291ccbefe2d69ea51694c4c58bbaa5d51ce907be8c82f40a6193f5ea3c72353",
  "icon_path": "icon/skill/1013_skill.png"
}
```

### It's Magic, I Added Some Magic

```json
{
  "ability_id": "101303",
  "slot": "ult",
  "name": "It's Magic, I Added Some Magic",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
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
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 170,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 190,
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
          "value": 208,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 224,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 232,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c39947e862d45cf81f9c87a9245e8b8cc4f466f3fd036dcb2df9e4ce1f63cf8b",
  "icon_path": "icon/skill/1013_ultimate.png"
}
```

### Fine, I'll Do It Myself

```json
{
  "ability_id": "101304",
  "slot": "talent",
  "name": "Fine, I'll Do It Myself",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
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
    "atk",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 50,
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 26.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 50,
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 29.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 31,
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
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 34.38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 36.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 38.13,
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
        },
        "p2": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 41.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 43,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 44.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 46,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7723f24dcef3e03f293cf9380cbf6d2e809685df18ebf046e0f92575b9464b9e",
  "icon_path": "icon/skill/1013_talent.png"
}
```

### It Can Still Be Optimized

```json
{
  "ability_id": "101307",
  "slot": "technique",
  "name": "It Can Still Be Optimized",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
  "description_sha256": "bdb56d1993589252206f2b6a4a23d1fa4a792485af61175333f76f18698a1ec2",
  "icon_path": "icon/skill/1013_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Efficiency",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "214d42081bcc2f1519309ee9065d16bfba798972e301af395fbf32608a9706eb"
  },
  {
    "requirement": "A4",
    "name": "Puppet",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%"
    ],
    "description_sha256": "76836ae4969b9f3c8bad621014172db87c10c09e9bf627c95e55997b7fdc7f80"
  },
  {
    "requirement": "A6",
    "name": "Icing",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "bc1e09c3e1bc8cf4bbc0ea58f367c24ad9cb2581067a660b82ef023b0ca7c3b5"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Kick You When You're Down",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "50%",
      "40%"
    ],
    "description_sha256": "0f58bc9938252e73981eeee7d1182364d630116ed7b14f0305dd392b59ac3646"
  },
  {
    "eidolon": 2,
    "name": "Keep the Ball Rolling",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "3%",
      "5"
    ],
    "description_sha256": "4f4373a67abf2c78fae46544602dd57c395e7585af2d58bf729fd310a38b105d"
  },
  {
    "eidolon": 3,
    "name": "That's the Kind of Girl I Am",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "1c2c3adf318877ae262e58a125ce81f86589b66b130f834bc011350ea2fd16ee"
  },
  {
    "eidolon": 4,
    "name": "Hit Where it Hurts",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "416c80f835f236629a91d979f23e84131b154967b3959ab0610cdc7afbf766fd"
  },
  {
    "eidolon": 5,
    "name": "Cuss Big or Cuss Nothing",
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
    "name": "No One Can Betray Me",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "25%",
      "1"
    ],
    "description_sha256": "b9fc275351c300d893a3c8aadc2670bbdcd54da237af2ae3a3cff6e1edc5cedf"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
