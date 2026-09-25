---
schema_version: "1.0.0"
unit_id: 17
name: "Pela"
slug: "pela"
rarity: 4
element: "Ice"
path: "Nihility"
role: "Sub DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/pela"
source_record_updated_at: "February 19th, 2025"
dataset_snapshot: "2026-05-30"
---

# Pela

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Pela.h` |
| ธาตุ | **Ice** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.3) |

### Base Stats (Lv.80, ascended)
HP 987 · ATK 546 · DEF 463 · SPD 105

> Nihility debuffer สาย DEF shred (Exposed) + buff strip

---

### Basic ATK — Frost Shot (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Frostbite (Impair, Lv.10)
- ลบ buff 1 อัน + Ice DMG = **210% ATK** ใส่ศัตรู 1 ตัว
- Energy +30 · Toughness 20

### Ultimate — Zone Suppression (Impair, 110 energy, Lv.10)
- Ice DMG = **100% ATK** AoE + 100% base chance ติด **Exposed** ศัตรูทุกตัว
- Exposed: DEF **−40%** นาน 2 เทิร์น
- Energy +5 · Toughness 20

### Talent — Data Collecting (Lv.10)
- ถ้าศัตรูติด debuff หลัง Pela โจมตี → Pela คืน Energy เพิ่ม **10** (1 ครั้ง/การโจมตี)

### Technique — Preemptive Strike
- เข้าฉากโจมตี: Ice DMG = **80% ATK** ใส่ศัตรูสุ่ม + 100% base chance ลด DEF ศัตรูทุกตัว **20%** นาน 2 เทิร์น
- Toughness 20

---

### Major Traces
- **A2 — Bash**: สร้างดาเมจกับศัตรูที่ติด debuff **+20%**
- **A4 — The Secret Strategy**: ขณะ Pela อยู่ในสนาม → เพื่อนทุกคน Effect Hit Rate **+10%**
- **A6 — Wipe Out**: ใช้ Skill ลบ buff → การโจมตีครั้งถัดไปของ Pela **+DMG 20%**

### Minor Traces (รวมทั้งหมด)
Ice DMG +22.4% · ATK +18% · Effect HIT Rate +10%

### Eidolons
- **E1**: ศัตรูตาย → Pela คืน Energy **5**
- **E2**: ใช้ Skill ลบ buff → SPD **+10%** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: ใช้ Skill → 100% base chance ลด Ice RES เป้าหมาย **12%** นาน 2 เทิร์น
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Pela ตีศัตรูที่ติด debuff → Additional Ice DMG = **40% ATK**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Exposed (Ult)**: DEF −40% AoE, 2t — DEF shred หลัก
- **Talent energy**: +10 ถ้าศัตรูมี debuff หลัง Pela attack (1/attack) — energy engine
- **A2 / E6**: DMG amp / Additional DMG vs debuffed enemy
- **A4**: EHR +10% ทีม
- Technique DEF −20% AoE
- โค้ด: `Start_game_List` (`Pela.h:63`) — technique DEF shred

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/pela — kit tab (review patch 2.6, calc patch 3.3, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 17,
  "name": "Pela",
  "slug": "pela",
  "rarity": "4",
  "element": "Ice",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 134.4,
    "def_base": 63,
    "atk_base": 74.4,
    "speed_base": 105
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "effectHitRate",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Xanthe Huynh",
    "kr": "이다은",
    "jpn": "Morohoshi Sumire (諸星すみれ)",
    "cn": "宴宁"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/pela",
  "source_record_updated_at": "February 19th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110601` | Frost Shot | Basic ATK | Single Target |
| `skill` | `110602` | Frostbite | Skill | Impair |
| `ult` | `110603` | Zone Suppression | Ultimate | Impair |
| `talent` | `110604` | Data Collecting | Talent | Support |
| `technique` | `110607` | Preemptive Strike | Technique | MazeAttack |

## Ability records

### Frost Shot

```json
{
  "ability_id": "110601",
  "slot": "basic",
  "name": "Frost Shot",
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
  "description_sha256": "0251cb954f08ea4c1a5f05a38bc2d5b634bc9123823245319c71ab279cc405dd",
  "icon_path": "icon/skill/1106_basic_atk.png"
}
```

### Frostbite

```json
{
  "ability_id": "110602",
  "slot": "skill",
  "name": "Frostbite",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
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
    "dmg",
    "buff"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "6308da0bc7b5bd36d1c90ffbd8f840c832028f6cdb3ad6905610dd6f2b3bdd47",
  "icon_path": "icon/skill/1106_skill.png"
}
```

### Zone Suppression

```json
{
  "ability_id": "110603",
  "slot": "ult",
  "name": "Zone Suppression",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "def",
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
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 31,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 64,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 68,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 76,
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
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 36.25,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 85,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 38.75,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 95,
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
          "value": 40,
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 41,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 104,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 43,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 112,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 116,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 120,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c8288f34811f1dd4cab8e40d20b030961b6af10651cb81aea3795fb894db7f2d",
  "icon_path": "icon/skill/1106_ultimate.png"
}
```

### Data Collecting

```json
{
  "ability_id": "110604",
  "slot": "talent",
  "name": "Data Collecting",
  "type_code": "Talent",
  "type_label": "Talent",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
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
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8.125,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 8.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.375,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 12.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b1d82904766b1d6e60f59700128ac87558c02376fd8086f09904997c3944a454",
  "icon_path": "icon/skill/1106_talent.png"
}
```

### Preemptive Strike

```json
{
  "ability_id": "110607",
  "slot": "technique",
  "name": "Preemptive Strike",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Ice",
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
    "def",
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
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 80,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "643c726cab6748d8330d0123b5f8c1daf0bf718c234defd073883caa704299b4",
  "icon_path": "icon/skill/1106_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Bash",
    "mechanic_tags": [
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "208eccadab3808e9cfb57d0cd7d0cc725cf07050635fcfa94e9f462be74070cb"
  },
  {
    "requirement": "A4",
    "name": "The Secret Strategy",
    "mechanic_tags": [
      "effect_hit_rate"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "235f6f9533ff96e3b5018e93bb908c367094df9c061d15b4a7573609c8536018"
  },
  {
    "requirement": "A6",
    "name": "Wipe Out",
    "mechanic_tags": [
      "dmg",
      "buff"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "f98bcd9986e1229f2485084c8a63d67e067423bf968e4ec2918fe5d8220bd939"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Victory Report",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "9c1a749dc0a311f67da6c003eb8631b3912dfbf0240f947544b4b799e32bc05e"
  },
  {
    "eidolon": 2,
    "name": "Adamant Charge",
    "mechanic_tags": [
      "spd",
      "buff"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "75f42276e86504971c5f7236e68b6dd870ab84a766cbfb38cc96071e04aede18"
  },
  {
    "eidolon": 3,
    "name": "Suppressive Force",
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
    "name": "Full Analysis ",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "100%",
      "12%",
      "2"
    ],
    "description_sha256": "752b5cdd52521e524d2a9d1dee0d686d0adfa1d70ad3734aa89b12e4ae5425df"
  },
  {
    "eidolon": 5,
    "name": "Absolute Jeopardy",
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
    "name": "Feeble Pursuit",
    "mechanic_tags": [
      "atk",
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "be6b087b36ed010e63db5e4b1ecfdca8dd60ae47004bd91514ced740c30d69bf"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
