---
schema_version: "1.0.0"
unit_id: 87
name: "Ashveil"
slug: "ashveil"
rarity: 5
element: "Lightning"
path: "Hunt"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/ashveil"
source_record_updated_at: "April 21st, 2026"
dataset_snapshot: "2026-05-30"
---

# Ashveil

## Character record

```json
{
  "unit_id": 87,
  "name": "Ashveil",
  "slug": "ashveil",
  "rarity": "5",
  "element": "Lightning",
  "path": "Hunt",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "March 24th, 2026",
  "is_released": true,
  "ultimate_energy_cost": "150",
  "base_stats": {
    "hp_base": 116,
    "def_base": 52,
    "atk_base": 105,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "ATK%",
      "value": 10
    },
    "traceStat2": {
      "stat": "Lightning DMG",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "CRIT DMG",
      "value": 37.3
    }
  },
  "voice_actors": {
    "en": "Blythe Melin",
    "kr": "강수진 (Kang Soo-jin)",
    "jpn": "子安 武人 (Koyasu Takehito)",
    "cn": "张沛 (Zhang Pei)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/ashveil",
  "source_record_updated_at": "April 21st, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150401` | Talons: Inculcate Decorum | Basic ATK | Single Target |
| `skill` | `150402` | Flog: Smite Evil | Skill | Single Target |
| `ult` | `150403` | Banquet: Insatiable Appetite | Ultimate | Single Target |
| `talent` | `150404` | Rancor: Enmity Reprisal | Talent | Single Target |
| `technique` | `150407` | Devour: O Loathsome Hand | Technique | Impair |

## Ability records

### Talons: Inculcate Decorum

```json
{
  "ability_id": "150401",
  "slot": "basic",
  "name": "Talons: Inculcate Decorum",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 10,
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
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "65919cd800464ae204d2c34f54c38414c72bcd39e1e6b52a3feaef0c5a65b6e6",
  "icon_path": null
}
```

### Flog: Smite Evil

```json
{
  "ability_id": "150402",
  "slot": "skill",
  "name": "Flog: Smite Evil",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "def",
    "dmg",
    "skill_points"
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
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 22,
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
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
          "value": 26,
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
          "value": 70,
          "unit": "percent"
        },
        "p3": {
          "value": 28,
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
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
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
          "value": 81.25,
          "unit": "percent"
        },
        "p3": {
          "value": 32.5,
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
          "value": 87.5,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
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
          "value": 93.75,
          "unit": "percent"
        },
        "p3": {
          "value": 37.5,
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 40,
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
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
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
          "value": 110,
          "unit": "percent"
        },
        "p3": {
          "value": 44,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d7fd9ccac8eea12574ade2c940da5085e3a5f96a813be6f397ecaf29f74192cc",
  "icon_path": null
}
```

### Banquet: Insatiable Appetite

```json
{
  "ability_id": "150403",
  "slot": "ult",
  "name": "Banquet: Insatiable Appetite",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": "150",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
        },
        "p2": {
          "value": 200,
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
          "value": 220,
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
          "value": 240,
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
          "value": 260,
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
          "value": 280,
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
          "value": 300,
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
          "value": 325,
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
          "value": 350,
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
          "value": 375,
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
          "value": 400,
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
          "value": 420,
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
          "value": 440,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "46ba55894a8849f49fdabb18bcd23d5aa08ee6790d601d68b41e08cd9d01b70b",
  "icon_path": null
}
```

### Rancor: Enmity Reprisal

```json
{
  "ability_id": "150404",
  "slot": "talent",
  "name": "Rancor: Enmity Reprisal",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
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
    "energy",
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
    }
  ],
  "description_sha256": "1df94899f9fa7c2c2d5600c0fc39bb87b978a18f920b0a527e24a14c77d0b444",
  "icon_path": null
}
```

### Devour: O Loathsome Hand

```json
{
  "ability_id": "150407",
  "slot": "technique",
  "name": "Devour: O Loathsome Hand",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "06fd6ddd77762e35de9a7b5626c033ea00efd412446f945d15aade09474280b0",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Damnation Trail",
    "mechanic_tags": [
      "atk",
      "follow_up"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "1",
      "1"
    ],
    "description_sha256": "7d9de0d0b7bb9b60e4f3a31c70325c5e92e2915a48faa6660045f73a296250a2"
  },
  {
    "requirement": "A4",
    "name": "Phantom Limb",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "80%",
      "1",
      "10%"
    ],
    "description_sha256": "674bfe7f9dd3aa407afe121e45687c744c77f7945927eb5159faf8075f8262a9"
  },
  {
    "requirement": "A6",
    "name": "First Fang",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "40%",
      "80%"
    ],
    "description_sha256": "808c3db8cbff3349dc72a0d6d779961e3548876eb6a7f0e3f96ecb7be7c180b6"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Beware: Venture Not at Full Moon",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "24%",
      "50%",
      "36%"
    ],
    "description_sha256": "c1b2fe70dad36e5b1e4582da8644f1f6de5fb9e126e73f07293b4ccdc581bf00"
  },
  {
    "eidolon": 2,
    "name": "Knock: Where Snickers Echo",
    "mechanic_tags": [
      "atk",
      "follow_up"
    ],
    "numeric_tokens": [
      "18",
      "35%"
    ],
    "description_sha256": "25fb1e52c5157e0a80f74608d657b3a0831745013593aee1d00a8c41f3f1b740"
  },
  {
    "eidolon": 3,
    "name": "Hush: Unsaid Between Friends",
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
    "name": "Heed: Swallow Truth Whole",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "40%",
      "3"
    ],
    "description_sha256": "c6cf3f0e4c99c51ef07e02919f26f070524ab9b02bf63afb2e94d382ac002ee3"
  },
  {
    "eidolon": 5,
    "name": "Caution: Sleuth Turns Slayer",
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
    "name": "Finale: And Then There Were None",
    "mechanic_tags": [
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "1",
      "4%",
      "30"
    ],
    "description_sha256": "28c8daeccc7817d86f55b57808952f91a9edb6bfe5b2982a140fd0b625943033"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
