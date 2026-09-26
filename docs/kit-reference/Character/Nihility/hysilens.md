---
schema_version: "1.0.0"
unit_id: 80
name: "Hysilens"
slug: "hysilens"
rarity: 5
element: "Physical"
path: "Nihility"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/hysilens"
source_record_updated_at: "September 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Hysilens

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Hysilens.h` |
| ธาตุ | **Physical** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 3.5) |

### Base Stats (Lv.80, ascended)
HP 1205 · ATK 601 · DEF 485 · SPD 102

> Nihility DoT support/sub-DPS สาย multi-DoT + Zone + vulnerability

---

### Basic ATK — Aeolian Mode: Echoes in Still Waters (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Overtone Hum: Chorus After Dark Tides (AoE, Lv.10)
- 100% base chance ศัตรูทุกตัวรับดาเมจเพิ่ม **+20%** นาน 3 เทิร์น
- Physical DMG = **140% ATK** AoE
- Energy +30 · Toughness 10

### Ultimate — Maelstrom Rhapsody (AoE, 110 energy, Lv.10)
- กาง **Zone**: ศัตรู ATK **−15%**, DEF **−25%**
- Physical DMG = **200% ATK** AoE
- ต่อ 1 instance ของ DoT ที่ศัตรูใน Zone รับ → Hysilens สร้าง Physical DoT = **80% ATK** ใส่ตัวนั้น
  - trigger ต้นทุกเทิร์น หรือหลังเพื่อนโจมตี 1 ครั้ง สูงสุด **8 ครั้ง** (ไม่ trigger ซ้ำ)
- Zone นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Hysilens); Hysilens ถูกน็อค → Zone หาย
- Energy +5 · Toughness 20

### Talent — Sirenic Serenade (Lv.10)
- เมื่อเพื่อนโจมตี → 100% base chance Hysilens ยัดสถานะ 1 อย่าง: **Wind Shear / Bleed / Burn / Shock** (เลือกที่ยังไม่มีก่อน)
- Wind Shear/Burn/Shock: DoT ต้นทุกเทิร์น = **25% ATK** (Wind/Fire/Lightning) นาน 2 เทิร์น
- Bleed: Physical DoT ต้นทุกเทิร์น = **20% ของ Max HP ศัตรู** แต่ไม่เกิน **25% ATK ของ Hysilens** นาน 2 เทิร์น

### Technique — At Ocean's Abode
- สร้าง Special Dimension 20 วิ (ศัตรู "Soulstruck" ไม่โจมตีเพื่อน)
- เข้าฉากกับศัตรู Soulstruck → 100% base chance ยัด 2 สถานะจาก Wind Shear/Bleed/Burn/Shock (แบบเดียวกับ Talent)

---

### Major Traces
- **A2 — The Gladius of Conquest**: ต้นการต่อสู้ → Hysilens กาง Zone (แบบ Ult) นาน 3 เทิร์น. ทุกครั้งที่กาง Zone → คืน Skill Point **1**
- **A4 — The Bubble of Banquets**: ใช้ Ult ถ้าเป้าหมายติด DoT → DoT ทั้งหมดบนเป้าหมายสร้างความเสียหายทันที = **150% ของดาเมจเดิม**
- **A6 — The Fiddle of Pearls**: ทุก 10% ของ Effect Hit Rate ที่เกิน **60%** → Hysilens +DMG **+15%** สูงสุด **+90%**

### Minor Traces (รวมทั้งหมด)
ATK +18% · SPD +14 · Effect HIT Rate +10%

### Eidolons
- **E1**: ขณะ Hysilens อยู่ในสนาม → เพื่อนทุกคนสร้าง DoT = **116%** ของเดิม. เมื่อ Talent ยัด Wind Shear/Bleed/Burn/Shock → 100% base chance ยัดเพิ่มอีก 1 instance (เหมือนเดิม, coexist ได้)
- **E2**: ขณะ Zone active → A6 DMG Boost apply ให้เพื่อนทุกคน
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ขณะ Zone active → ศัตรูทุกตัว All-Type RES **−20%**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ขณะ Zone active → cap ของ Physical DoT effect เพิ่มเป็น **12** + multiplier **+20%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Multi-DoT**: Talent ยัด 4 ชนิด (E1 ×2), แต่ละชนิด DoT 25% ATK/2t; Bleed = min(20% enemy Max HP, 25% ATK)
- **Zone reactive DoT**: 80% ATK ต่อ DoT instance ที่ศัตรูรับ, cap 8/turn (E6 12, +20%), trigger ต้นเทิร์น/หลัง ally attack
- **A4**: Ult → detonate DoT 150%
- **Vulnerability**: Skill +20% DMG taken (3t) + Ult Zone ATK/DEF shred
- **A6**: DMG scaling จาก EHR เกิน 60% (cap 90%, E2 → ทีม)
- โค้ด: `Start_game_List` (`Hysilens.h:191`, `hys`, `Talent`, `E1`) — A2 Zone ต้นการต่อสู้ + SP

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/hysilens — kit tab (review/calc patch 3.5, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 80,
  "name": "Hysilens",
  "slug": "hysilens",
  "rarity": "5",
  "element": "Physical",
  "path": "Nihility",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "August 13th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 164,
    "def_base": 66,
    "atk_base": 81.84,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 18
    },
    "traceStat2": {
      "stat": "speed",
      "value": 14
    },
    "traceStat3": {
      "stat": "Effect Hit Rate",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "오은수 (Oh Eun-soo)",
    "jpn": "石見 舞菜香 (Iwami Manaka)",
    "cn": "浮梦若薇 (Fumeng Ruowei)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/hysilens",
  "source_record_updated_at": "September 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `141001` | Aeolian Mode: Echoes in Still Waters | Basic ATK | Single Target |
| `skill` | `141002` | Overtone Hum: Chorus After Dark Tides | Skill | AoE |
| `ult` | `141003` | Maelstrom Rhapsody | Ultimate | AoE |
| `talent` | `141004` | Sirenic Serenade | Talent | Impair |
| `technique` | `141007` | At Ocean's Abode | Technique | Enhance |

## Ability records

### Aeolian Mode: Echoes in Still Waters

```json
{
  "ability_id": "141001",
  "slot": "basic",
  "name": "Aeolian Mode: Echoes in Still Waters",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
  "description_sha256": "7950e298ce2615bab5f619fc1b7f605486bd9f6e23a1418372edb3729a9210d7",
  "icon_path": "icon/skill/1410_basic_atk.png"
}
```

### Overtone Hum: Chorus After Dark Tides

```json
{
  "ability_id": "141002",
  "slot": "skill",
  "name": "Overtone Hum: Chorus After Dark Tides",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        },
        "p2": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 98,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 113.75,
          "unit": "percent"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 122.5,
          "unit": "percent"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 18.75,
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
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 147,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 161,
          "unit": "percent"
        },
        "p2": {
          "value": 23,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2fd91ed136d65b86a9f84bc547227c527e5603f5192c93240211897486530ad2",
  "icon_path": "icon/skill/1410_skill.png"
}
```

### Maelstrom Rhapsody

```json
{
  "ability_id": "141003",
  "slot": "ult",
  "name": "Maelstrom Rhapsody",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "60",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 32,
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
        },
        "p2": {
          "value": 16,
          "unit": "percent"
        },
        "p3": {
          "value": 37.28,
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
        },
        "p2": {
          "value": 17,
          "unit": "percent"
        },
        "p3": {
          "value": 42.56,
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
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 47.84,
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
        },
        "p2": {
          "value": 19,
          "unit": "percent"
        },
        "p3": {
          "value": 53.12,
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
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 58.4,
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
        },
        "p2": {
          "value": 21.25,
          "unit": "percent"
        },
        "p3": {
          "value": 63.2,
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
        },
        "p2": {
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 68,
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
        },
        "p2": {
          "value": 23.75,
          "unit": "percent"
        },
        "p3": {
          "value": 74,
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
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
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
        },
        "p2": {
          "value": 26,
          "unit": "percent"
        },
        "p3": {
          "value": 84,
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
        },
        "p2": {
          "value": 27,
          "unit": "percent"
        },
        "p3": {
          "value": 88,
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
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 92,
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
        },
        "p2": {
          "value": 29,
          "unit": "percent"
        },
        "p3": {
          "value": 96,
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
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7c13762ad2eeaf616db9a3e457525be35bc04c19f6d3cc0b4aa41ae8cc7c5885",
  "icon_path": "icon/skill/1410_ultimate.png"
}
```

### Sirenic Serenade

```json
{
  "ability_id": "141004",
  "slot": "talent",
  "name": "Sirenic Serenade",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dot"
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
          "value": 11.65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 13.3,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 14.95,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 18.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 23.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 26.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 28.75,
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
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 31.25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "19e2295a4fe6882268e80dbe70d45d03694f959f403d8267f4358e6920ab6a70",
  "icon_path": "icon/skill/1410_talent.png"
}
```

### At Ocean's Abode

```json
{
  "ability_id": "141007",
  "slot": "technique",
  "name": "At Ocean's Abode",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "820c6f60d6239bf660539f9c06c1cf9ed7e2de60055eefa1ff1c0e3b08ae59d6",
  "icon_path": "icon/skill/1410_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "The Gladius of Conquest",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "3",
      "1"
    ],
    "description_sha256": "99aeb422c0542822934d6c9b7622126971de3a6e2e2b72a6018f4497f73d13aa"
  },
  {
    "requirement": "A4",
    "name": "The Bubble of Banquets",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "150%"
    ],
    "description_sha256": "c482c9156a0b90798491a08c0a386e50ba294a28d4dffcc1ab5ccd2f52d15bb4"
  },
  {
    "requirement": "A6",
    "name": "The Fiddle of Pearls",
    "mechanic_tags": [
      "effect_hit_rate",
      "dmg"
    ],
    "numeric_tokens": [
      "10%",
      "60%",
      "15%",
      "90%"
    ],
    "description_sha256": "3665fb98778d96512fb3ef1170601fac27ce686a77b38f6bb48e7a6225c17cf6"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "You Ask Why Hearts Cry",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "116%",
      "100%",
      "1"
    ],
    "description_sha256": "e44053bf3dfa40400b702ba53b9d1b7acf33135f27baec97c317c37f7fb2e7fb"
  },
  {
    "eidolon": 2,
    "name": "Tell Me Why Waves Roar High",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [],
    "description_sha256": "4cb40e4726091b979d11fb7e3abbfadbdbdcf2f20da072b7ad7e783fae8da265"
  },
  {
    "eidolon": 3,
    "name": "Why Do Lights Bid Goodbye",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "a7feeb7d754cfe954c7d1d3f1cd8dac81e25e12ef4d2da9be8cd9c1585c4e488"
  },
  {
    "eidolon": 4,
    "name": "Lo, How Time Flows By",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "b8748975344ef4f970e7ebe8d8f4ec6702127a61d4f42de4cba7b5cff452a717"
  },
  {
    "eidolon": 5,
    "name": "In Ablution, I Hum and Sigh",
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
    "name": "When to Return From Where You Lie",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "12",
      "20%"
    ],
    "description_sha256": "c3c3d1f1a720674562904df9aa327ea29b1c4de0208a9ae8024a52dac11141de"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
