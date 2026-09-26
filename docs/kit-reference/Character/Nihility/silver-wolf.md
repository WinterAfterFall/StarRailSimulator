---
schema_version: "1.0.0"
unit_id: 8
name: "Silver Wolf"
slug: "silver-wolf"
rarity: 5
element: "Quantum"
path: "Nihility"
role: "Sub DPS"
affiliation: "Stellaron Hunters"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/silver-wolf"
source_record_updated_at: "July 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Silver Wolf

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Silver Wolf.h` (โค้ดเรียก `"SW"`) |
| ธาตุ | **Quantum** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1047 · ATK 640 · DEF 460 · SPD 107

> Nihility debuffer สาย weakness implant + RES/DEF shred + "Bug"

---

### Basic ATK — System Warning (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Allow Changes? (Impair, Lv.10)
- 120% base chance ยัด Weakness type ของเพื่อนในสนาม 1 อัน (เลือกตามเพื่อนลำดับแรก) + ลด RES ต่อ type นั้น **20%** นาน 3 เทิร์น
  - ถ้าศัตรูมี type นั้นอยู่แล้ว → RES reduction ไม่ trigger
  - ศัตรูแต่ละตัวมี Weakness ที่ Silver Wolf ยัดได้ **1 อัน** (ยัดใหม่ = เก็บอันล่าสุด)
- 100% base chance ลด All-Type RES เป้าหมายเพิ่ม **13%** นาน 2 เทิร์น
- Quantum DMG = **196% ATK** ใส่เป้าหมาย
- Energy +30 · Toughness 20

### Ultimate — User Banned (Impair, 110 energy, Lv.10)
- 120% base chance ลด DEF ศัตรูทุกตัว **45%** นาน 3 เทิร์น
- Quantum DMG = **380% ATK** AoE
- Energy +5 · Toughness 30

### Talent — Awaiting System Response... (Lv.10)
- สร้าง "Bug" 3 ชนิด: ATK **−10%**, DEF **−12%**, SPD **−6%**
- หลัง Silver Wolf โจมตีทุกครั้ง → 100% base chance ยัด "Bug" สุ่ม 1 อัน นาน 3 เทิร์น
- ศัตรูตาย → Weakness ที่ Silver Wolf ยัด ย้ายไปศัตรูตัวอื่นที่ยังไม่โดนยัด (Elite+ ก่อน)

### Technique — Force Quit Program
- เข้าฉากโจมตี AoE: Quantum DMG = **80% ATK** + ลด Toughness โดยไม่สน Weakness type; ศัตรูที่ break จากนี้ → trigger Quantum Weakness Break effect
- Toughness 20

---

### Major Traces
- **A2 — Generate**: Bug duration **+1 เทิร์น**. ศัตรู Weakness Broken → 100% base chance ยัด Bug สุ่ม
- **A4 — Inject**: ต้นการต่อสู้ → คืน Energy **20**. ต้นเทิร์นของ Silver Wolf → คืน Energy **5**
- **A6 — Side Note**: ทุก 10% Effect Hit Rate → Silver Wolf ATK **+10%** สูงสุด **+50%**

### Minor Traces (รวมทั้งหมด)
Effect HIT Rate +18% · ATK +28% · Quantum DMG +8%

### Eidolons
- **E1**: หลังใช้ Ult โจมตีศัตรู → คืน Energy **7 ต่อ debuff ที่เป้าหมายมี** (สูงสุด 5 ครั้ง/Ult)
- **E2**: ศัตรูเข้าฉาก → รับดาเมจเพิ่ม **+20%**. เมื่อศัตรูถูกเพื่อนโจมตี → 100% base chance Silver Wolf ยัด Bug สุ่ม
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: หลังใช้ Ult โจมตีศัตรู → Quantum Additional DMG = **20% ATK ต่อ debuff ที่เป้าหมายมี** (สูงสุด 5 ครั้ง/ศัตรู/Ult)
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: ต่อ debuff ที่เป้าหมายมี → Silver Wolf +DMG **+20%** สูงสุด **+100%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Weakness implant (Skill)**: 1 อัน/ศัตรู, type ตามเพื่อนลำดับแรก, + RES −20% ต่อ type + All-Type RES −13%; ย้ายเมื่อศัตรูตาย
- **Bug** (ATK/DEF/SPD down): ยัดสุ่มหลัง SW attack (A2 +1t, +on-break, E2 on-ally-attack)
- **Ult DEF −45%** AoE (3t)
- **debuff count scaling**: E6 (+20%/debuff DMG cap 100%), E4 (Additional DMG 20% ATK/debuff), E1 (energy 7/debuff)
- **A6**: ATK scaling จาก EHR (cap 50%)
- โค้ด: `Start_game_List` (`Silver Wolf.h:164`, `sw`) — technique + implant

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/silver-wolf — kit tab (review/calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 8,
  "name": "Silver Wolf",
  "slug": "silver-wolf",
  "rarity": "5",
  "element": "Quantum",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Stellaron Hunters",
  "release_date": "June 7th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 62.7,
    "atk_base": 87.12,
    "speed_base": 107
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "effectHitRate",
      "value": 18
    },
    "traceStat2": {
      "stat": "atk",
      "value": 28
    },
    "traceStat3": {
      "stat": "quantumDmg",
      "value": 8
    }
  },
  "voice_actors": {
    "en": "Melissa Fahn",
    "kr": "장미",
    "jpn": "Asumi Kana (阿澄佳奈)",
    "cn": "Hanser"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/silver-wolf",
  "source_record_updated_at": "July 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100601` | System Warning | Basic ATK | Single Target |
| `skill` | `100602` | Allow Changes? | Skill | Impair |
| `ult` | `100603` | User Banned | Ultimate | Impair |
| `talent` | `100604` | Awaiting System Response... | Talent | Impair |
| `technique` | `100607` | Force Quit Program | Technique | MazeAttack |

## Ability records

### System Warning

```json
{
  "ability_id": "100601",
  "slot": "basic",
  "name": "System Warning",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
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
  "description_sha256": "862d3f74579e8a4763a6a8b5ae9a9eaa8fca0c9d7e3911351b8270ed97fa5197",
  "icon_path": "icon/skill/1006_basic_atk.png"
}
```

### Allow Changes?

```json
{
  "ability_id": "100602",
  "slot": "skill",
  "name": "Allow Changes?",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Quantum",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "percent",
      "occurrences": 1
    },
    "p7": {
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
    "res",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 98,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 10.5,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 107.8,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 10.75,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 117.6,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 11,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 127.4,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 11.25,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 137.2,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 11.5,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 147,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 11.75,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 159.25,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 12.0625,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 171.5,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 12.375,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 183.75,
          "unit": "percent"
        },
        "p2": {
          "value": 115,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 12.6875,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 196,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 13,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 205.8,
          "unit": "percent"
        },
        "p2": {
          "value": 124,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 13.25,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 215.6,
          "unit": "percent"
        },
        "p2": {
          "value": 128,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 13.5,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 225.4,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 13.75,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 235.2,
          "unit": "percent"
        },
        "p2": {
          "value": 136,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 14,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 245,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        },
        "p6": {
          "value": 14.25,
          "unit": "percent"
        },
        "p7": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "aa432eb214f9367ed6c884edd99d19d4d2273af5bdba66bba2c14a2e33a97fb8",
  "icon_path": "icon/skill/1006_skill.png"
}
```

### User Banned

```json
{
  "ability_id": "100603",
  "slot": "ult",
  "name": "User Banned",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
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
    "def",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
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
          "value": 243.2,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 36.9,
          "unit": "percent"
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
          "value": 258.4,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        },
        "p3": {
          "value": 37.8,
          "unit": "percent"
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
          "value": 273.6,
          "unit": "percent"
        },
        "p2": {
          "value": 92,
          "unit": "percent"
        },
        "p3": {
          "value": 38.7,
          "unit": "percent"
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
          "value": 288.8,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 39.6,
          "unit": "percent"
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
          "value": 304,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 40.5,
          "unit": "percent"
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
          "value": 323,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 41.63,
          "unit": "percent"
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
          "value": 342,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        },
        "p3": {
          "value": 42.75,
          "unit": "percent"
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
          "value": 361,
          "unit": "percent"
        },
        "p2": {
          "value": 115,
          "unit": "percent"
        },
        "p3": {
          "value": 43.88,
          "unit": "percent"
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
          "value": 380,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 45,
          "unit": "percent"
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
          "value": 395.2,
          "unit": "percent"
        },
        "p2": {
          "value": 124,
          "unit": "percent"
        },
        "p3": {
          "value": 45.9,
          "unit": "percent"
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
          "value": 410.4,
          "unit": "percent"
        },
        "p2": {
          "value": 128,
          "unit": "percent"
        },
        "p3": {
          "value": 46.8,
          "unit": "percent"
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
          "value": 425.6,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        },
        "p3": {
          "value": 47.7,
          "unit": "percent"
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
          "value": 440.8,
          "unit": "percent"
        },
        "p2": {
          "value": 136,
          "unit": "percent"
        },
        "p3": {
          "value": 48.6,
          "unit": "percent"
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
          "value": 456,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "percent"
        },
        "p3": {
          "value": 49.5,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8705d8c9cc1246ad980771a9220f25a77e24fb45fbbfe8945b2c3d4d09004c47",
  "icon_path": "icon/skill/1006_ultimate.png"
}
```

### Awaiting System Response...

```json
{
  "ability_id": "100604",
  "slot": "talent",
  "name": "Awaiting System Response...",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Quantum",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "spd",
    "weakness"
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
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "percent"
        },
        "p4": {
          "value": 60,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 6.6,
          "unit": "percent"
        },
        "p3": {
          "value": 3.3,
          "unit": "percent"
        },
        "p4": {
          "value": 64,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 7.2,
          "unit": "percent"
        },
        "p3": {
          "value": 3.6,
          "unit": "percent"
        },
        "p4": {
          "value": 68,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 7.8,
          "unit": "percent"
        },
        "p3": {
          "value": 3.9,
          "unit": "percent"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 8.4,
          "unit": "percent"
        },
        "p3": {
          "value": 4.2,
          "unit": "percent"
        },
        "p4": {
          "value": 76,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 9,
          "unit": "percent"
        },
        "p3": {
          "value": 4.5,
          "unit": "percent"
        },
        "p4": {
          "value": 80,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 9.75,
          "unit": "percent"
        },
        "p3": {
          "value": 4.88,
          "unit": "percent"
        },
        "p4": {
          "value": 85,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 10.5,
          "unit": "percent"
        },
        "p3": {
          "value": 5.25,
          "unit": "percent"
        },
        "p4": {
          "value": 90,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 11.25,
          "unit": "percent"
        },
        "p3": {
          "value": 5.63,
          "unit": "percent"
        },
        "p4": {
          "value": 95,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 6,
          "unit": "percent"
        },
        "p4": {
          "value": 100,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 12.6,
          "unit": "percent"
        },
        "p3": {
          "value": 6.3,
          "unit": "percent"
        },
        "p4": {
          "value": 104,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 13.2,
          "unit": "percent"
        },
        "p3": {
          "value": 6.6,
          "unit": "percent"
        },
        "p4": {
          "value": 108,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 13.8,
          "unit": "percent"
        },
        "p3": {
          "value": 6.9,
          "unit": "percent"
        },
        "p4": {
          "value": 112,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 14.4,
          "unit": "percent"
        },
        "p3": {
          "value": 7.2,
          "unit": "percent"
        },
        "p4": {
          "value": 116,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 7.5,
          "unit": "percent"
        },
        "p4": {
          "value": 120,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3018ca7301b54f7a8b14fc448c0da24366e98f8e18067b82e656e9ea1e216ed8",
  "icon_path": "icon/skill/1006_talent.png"
}
```

### Force Quit Program

```json
{
  "ability_id": "100607",
  "slot": "technique",
  "name": "Force Quit Program",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Quantum",
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
    "break_effect",
    "dmg",
    "toughness",
    "weakness"
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
  "description_sha256": "7f631e50a5b50d22cc1ac4131343cf7c81eeaa928640198784be4726014c5e5b",
  "icon_path": "icon/skill/1006_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Generate",
    "mechanic_tags": [
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "100%"
    ],
    "description_sha256": "40c12ac555602c0077fd714bb3a61e34086de84cba9e2c8c9ce2eb3c6d9f14fd"
  },
  {
    "requirement": "A4",
    "name": "Inject",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "20",
      "5"
    ],
    "description_sha256": "e6f0dcecec5a2b06ebf95c83d2c65481cc8eb82a148cb5e1afe4a1700c5e5001"
  },
  {
    "requirement": "A6",
    "name": "Side Note",
    "mechanic_tags": [
      "atk",
      "effect_hit_rate"
    ],
    "numeric_tokens": [
      "10%",
      "10%",
      "50%"
    ],
    "description_sha256": "8f7ae1bbbe853daddb6318f0d306dfc5fa036bb141e4e1dec8404a53a5054a5f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Social Engineering",
    "mechanic_tags": [
      "energy",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "7",
      "5"
    ],
    "description_sha256": "1b86ef3fb43d2ce787def5615726f2bb1bbce64683b228f7feaf3b9a5d98264f"
  },
  {
    "eidolon": 2,
    "name": "Zombie Network ",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "100%",
      "1"
    ],
    "description_sha256": "da2da985586946be55d6878f00fee62d3b4e0fb9cf2beaa60dd5b5c2d0fa3b30"
  },
  {
    "eidolon": 3,
    "name": "Payload",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "4c910ab9157733f3234ecdaa8bba52b244d201a478bad2528e5caf200f7c4227"
  },
  {
    "eidolon": 4,
    "name": "Bounce Attack   ",
    "mechanic_tags": [
      "atk",
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "20%",
      "5"
    ],
    "description_sha256": "6efb82c311b0bbd62d0c3ac5fb78fe78e54ef57d62fd51bd75878eba2da39c2f"
  },
  {
    "eidolon": 5,
    "name": "Brute Force Attack",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "bc9b09b7015c543b22391cfc36d3f3dbfe0ab3ca7a74e98b7e29242a899157fb"
  },
  {
    "eidolon": 6,
    "name": "Overlay Network",
    "mechanic_tags": [
      "dmg",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "20%",
      "100%"
    ],
    "description_sha256": "bfef761239cd41f1a26a8e3eeb53747ce109fe132fd28dee79f8e3668b91dc70"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
