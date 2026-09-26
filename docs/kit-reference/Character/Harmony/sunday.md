---
schema_version: "1.0.0"
unit_id: 64
name: "Sunday"
slug: "sunday"
rarity: 5
element: "Imaginary"
path: "Harmony"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/sunday"
source_record_updated_at: "February 15th, 2025"
dataset_snapshot: "2026-05-30"
---

# Sunday

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Sunday.h` |
| ธาตุ | **Imaginary** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.7 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1241 · ATK 640 · DEF 533 · SPD 96

> Harmony support สาย summon-buffer + CRIT DMG/CRIT Rate + turn advance + energy

---

### Basic ATK — Gleaming Admonition (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Benison of Paper and Rites (Support, Lv.10)
- ให้เพื่อน 1 ตัว + summon ของเขา **action ทันที** + **+DMG dealt 30%**
- ถ้าเป้าหมายมี summon → +DMG dealt เพิ่มอีก **50%** นาน 2 เทิร์น
- ใช้ Skill ใส่ **The Beatified** → คืน Skill Point **1**
- ใช้ใส่ตัวละคร Path Harmony → ไม่ trigger immediate action
- Energy +30

### Ultimate — Ode to Caress and Cicatrix (Support, 130 energy, Lv.10)
- คืน Energy = **20% ของ Max Energy** ให้เพื่อน 1 ตัว
- เปลี่ยนเป้าหมาย + summon เป็น **"The Beatified"** → CRIT DMG **+เท่ากับ 30% ของ CRIT DMG ของ Sunday + 12%**
- ต้นเทิร์นของ Sunday → duration ลด 1, รวม 3 เทิร์น; มีผลกับเป้าหมาย Ult ล่าสุดเท่านั้น (ยกเว้น Sunday); Sunday ถูกน็อค → หาย
- Energy +5

### Talent — The Sorrowing Body (Lv.10)
- ใช้ Skill → เป้าหมาย CRIT Rate **+20%** นาน 3 เทิร์น

### Technique — The Glorious Mysteries
- หลังใช้ Technique → ครั้งแรกที่ Sunday ใช้ ability ใส่เพื่อนในการต่อสู้ถัดไป → เป้าหมาย +DMG dealt **50%** นาน 2 เทิร์น

---

### Major Traces
- **A2 — Rest Day's Longing**: ใช้ Ult ถ้า Energy ที่คืนให้เป้าหมาย < 40 → เพิ่มเป็น **40**
- **A4 — Exalted Sweep**: ต้นการต่อสู้ → Sunday คืน Energy **25**
- **A6 — Haven in Palm**: ใช้ Skill → ลบ debuff 1 อันจากเป้าหมาย

### Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · Effect RES +18% · DEF +12.5%

### Eidolons
- **E1**: ใช้ Skill → เป้าหมายเพิกเฉย DEF **16%**, summon ของเป้าหมายเพิกเฉย DEF **40%** นาน 2 เทิร์น
- **E2**: หลังใช้ Ult ครั้งแรก → คืน Skill Point **2**. ดาเมจของ "The Beatified" **+30%**
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ต้นเทิร์น → คืน Energy **8**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Talent CRIT Rate boost → stack ได้ 3 ครั้ง + duration **+1 เทิร์น**. ใช้ Ult → apply Talent CRIT Rate boost ให้เป้าหมายด้วย. เมื่อ CRIT Rate เป้าหมายเกิน 100% → ทุก 1% ส่วนเกิน → CRIT DMG **+2%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill**: forced action + DMG% (30%, +50% ถ้ามี summon) — ไม่ trigger action ตอนใส่ Harmony char; คืน SP 1 ถ้าเป้าเป็น The Beatified
- **Ult CRIT DMG buff**: 0.30 × (CD ของ Sunday) + 12% — ผูกกับ CD ของ Sunday, single target ล่าสุด, 3 เทิร์น
- **Talent CRIT Rate +20%** (E6: stack 3, +CD conversion เมื่อเกิน 100%)
- **Energy support**: Ult 20% Max Energy (A2 floor 40), A4 +25 start, E4 +8/turn
- summon-centric — ทำงานดีกับ Jing Yuan / Robin / remembrance
- โค้ด: `Start_game_List` (`Sunday.h:179`, `SDptr`)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sunday — kit tab (review patch 2.7, calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 64,
  "name": "Sunday",
  "slug": "sunday",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "December 4th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 72.6,
    "atk_base": 87.12,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT DMG",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "Effect RES",
      "value": 18
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "-",
    "kr": "강성우 (Kang Seong-woo)",
    "jpn": "大塚剛央 (Otsuka Takeo)",
    "cn": "徐翔 (Xu Xiang)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/sunday",
  "source_record_updated_at": "February 15th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `131301` | Gleaming Admonition | Basic ATK | Single Target |
| `skill` | `131302` | Benison of Paper and Rites | Skill | Support |
| `ult` | `131303` | Ode to Caress and Cicatrix | Ultimate | Support |
| `talent` | `131304` | The Sorrowing Body | Talent | Enhance |
| `technique` | `131307` | The Glorious Mysteries | Technique | Support |

## Ability records

### Gleaming Admonition

```json
{
  "ability_id": "131301",
  "slot": "basic",
  "name": "Gleaming Admonition",
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
  "description_sha256": "dc7c8c0f1ce96a4dcb707e6ef541b92bef52980354b95022bd53258e80481cfc",
  "icon_path": null
}
```

### Benison of Paper and Rites

```json
{
  "ability_id": "131302",
  "slot": "skill",
  "name": "Benison of Paper and Rites",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
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
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "skill_points",
    "summon"
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
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16.5,
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
          "value": 18,
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
          "value": 19.5,
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
          "value": 21,
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
          "value": 22.5,
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
          "value": 24.375,
          "unit": "percent"
        },
        "p2": {
          "value": 40.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 26.25,
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
          "value": 28.125,
          "unit": "percent"
        },
        "p2": {
          "value": 46.875,
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
          "value": 31.5,
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
          "value": 33,
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
          "value": 69,
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
          "value": 72,
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
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "339d6f96b136b3c5b09b723b9bdabc470aa0b7b394a7028b5355af0db4f9a030",
  "icon_path": null
}
```

### Ode to Caress and Cicatrix

```json
{
  "ability_id": "131303",
  "slot": "ult",
  "name": "Ode to Caress and Cicatrix",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
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
    "crit_dmg",
    "energy",
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.8,
          "unit": "percent"
        },
        "p2": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 8.8,
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
        },
        "p2": {
          "value": 9.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 17.4,
          "unit": "percent"
        },
        "p2": {
          "value": 9.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 10.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 23.25,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 27.75,
          "unit": "percent"
        },
        "p2": {
          "value": 11.5,
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
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.8,
          "unit": "percent"
        },
        "p2": {
          "value": 12.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33.6,
          "unit": "percent"
        },
        "p2": {
          "value": 12.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8e23994135410bd233d99bfe16dec434a487dc607e574b721dd9bff0e2378198",
  "icon_path": null
}
```

### The Sorrowing Body

```json
{
  "ability_id": "131304",
  "slot": "talent",
  "name": "The Sorrowing Body",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": "0",
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
    "crit_rate"
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
  "description_sha256": "07b89d56bb83dc8666a53dc3726ac3584fe4e1af59c493651fe1e9f98b2d43b6",
  "icon_path": null
}
```

### The Glorious Mysteries

```json
{
  "ability_id": "131307",
  "slot": "technique",
  "name": "The Glorious Mysteries",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b0b46ef308959ee5ba0af5d8a5279c5ad9a614984f0331186df4ee1548acda03",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Rest Day's Longing",
    "mechanic_tags": [
      "energy",
      "energy_regen_rate"
    ],
    "numeric_tokens": [
      "40",
      "40"
    ],
    "description_sha256": "e83234a24aa1a929c23ff067c6c050e000d45e99e897853a06245c559b548a93"
  },
  {
    "requirement": "A4",
    "name": "Exalted Sweep",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "25"
    ],
    "description_sha256": "b98c610c1214959a6c97e08783430789a1cfac54149bef740574c49718af90ae"
  },
  {
    "requirement": "A6",
    "name": "Haven in Palm",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "e96e21d35edd884f0b2d7c7ead5923a421d85a4d372664ecbad8b3b44e4eba93"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Millennium's Quietus",
    "mechanic_tags": [
      "def",
      "dmg",
      "summon"
    ],
    "numeric_tokens": [
      "16%",
      "40%",
      "2"
    ],
    "description_sha256": "8afce23f177dced11c215bcd9179f570d8fe7087e54de721ede334cd77ced8a9"
  },
  {
    "eidolon": 2,
    "name": "Faith Outstrips Frailty",
    "mechanic_tags": [
      "dmg",
      "skill_points"
    ],
    "numeric_tokens": [
      "2",
      "30%"
    ],
    "description_sha256": "2dc3cb2b56aa42f4e039e2d86a58fa886af995beb645c1381822d0c91180aaf7"
  },
  {
    "eidolon": 3,
    "name": "Hermitage of Thorns",
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
    "name": "Sculpture's Preamble",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "8"
    ],
    "description_sha256": "1f47c456f87c440b295f1919ceb98251f2b72f441efe7eedab104c1b991ef449"
  },
  {
    "eidolon": 5,
    "name": "Paper Raft in Silver Bay",
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
    "name": "Dawn of Sidereal Cacophony",
    "mechanic_tags": [
      "crit_rate",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "3",
      "1",
      "100%",
      "1%",
      "2%"
    ],
    "description_sha256": "b13539cf848e1aca315db624812f5537a567e48dd7f0a85755030cacd1c0b041"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
