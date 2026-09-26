---
schema_version: "1.0.0"
unit_id: 65
name: "Tingyun • Fugue"
slug: "tingyun-fugue"
rarity: 5
element: "Fire"
path: "Nihility"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/tingyun-fugue"
source_record_updated_at: "April 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Tingyun • Fugue

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Fugue.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1125 · ATK 582 · DEF 557 · SPD 102

> Nihility Break/Super Break support — คนแรกที่บังคับใส่ Exo Toughness ให้ break ได้รอบสอง

---

### Basic ATK — Radiant Streak (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Fiery Caress (Blast, Lv.6)
- Fire DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- Energy +20 · Toughness 10 (+5)

### Skill — Virtue Beckons Bliss (Support, Lv.10)
- มอบ **"Foxian Prayer"** ให้เพื่อน 1 ตัว + เข้าสถานะ **"Torrid Scorch"** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Fugue)
- "Foxian Prayer" มีผลกับเป้าหมาย Skill ล่าสุดเท่านั้น:
  - Break Effect **+30%**
  - ลด Toughness ได้แม้ตีศัตรูที่ไม่มี Weakness type ตรง = **50% ของปกติ** (ไม่ stack กับ ignore-weakness อื่น)
- ขณะ "Torrid Scorch": Fugue enhanced Basic ATK; ทุกครั้งเพื่อนที่มี "Foxian Prayer" โจมตี → 100% base chance ลด DEF ศัตรูที่โดน **18%** นาน 2 เทิร์น
- Energy +30

### Ultimate — Solar Splendor Shines Upon All (AoE, 130 energy, Lv.10)
- Fire DMG = **200% ATK** AoE
- ลด Toughness ศัตรูทุกตัวโดยไม่สน Weakness type; เมื่อ break → trigger Fire Weakness Break effect
- Energy +5 · Toughness 20

### Talent — Fortune Follows Where Virtue Spreads (Lv.10)
- ขณะ Fugue อยู่ในสนาม → ศัตรูถูกใส่ **"Cloudflame Luster"** = **40% ของ Max Toughness**
  - เมื่อ Toughness เริ่มต้นถูกลดเป็น 0 → ลด "Cloudflame Luster" ต่อได้; เมื่อ "Cloudflame Luster" ถึง 0 → ศัตรูรับ Weakness Break DMG อีกครั้ง
- ขณะ Fugue อยู่ในสนาม หลังเพื่อนตีศัตรู Weakness Broken → แปลง Toughness Reduction ของการโจมตีนั้นเป็น **Super Break DMG 100%** 1 instance

### Technique — Percipient Shine
- ติด Daze ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Dazed → Fugue action advance **40%** + 100% base chance ติด DEF Reduction แบบ Skill ให้ศัตรูทุกตัว นาน 2 เทิร์น

---

### Major Traces
- **A2 — Verdantia Renaissance**: หลังเพื่อน break weakness → delay action ศัตรู **+15%**
- **A4 — Sylvan Enigma**: Fugue Break Effect **+30%**. ใช้ Skill ครั้งแรก → คืน Skill Point **1**
- **A6 — Phecda Primordia**: ศัตรูถูก break → เพื่อน (ยกเว้น Fugue) Break Effect **+6%**; ถ้า BE ของ Fugue ≥ 220% → เพิ่มอีก **+12%** นาน 2 เทิร์น stack 2 ครั้ง

### Minor Traces (รวมทั้งหมด)
Break Effect +24% · SPD +14 · HP +10%

### Eidolons
- **E1**: เพื่อนที่มี "Foxian Prayer" → Weakness Break Efficiency **+50%**
- **E2**: ศัตรูถูก break → Fugue คืน Energy **3**. หลังใช้ Ult → advance action เพื่อนทุกคน **24%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: เพื่อนที่มี "Foxian Prayer" → Break DMG dealt **+20%**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Fugue Weakness Break Efficiency **+50%**. ขณะ "Torrid Scorch" → "Foxian Prayer" มีผลกับเพื่อนทุกคน

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Cloudflame Luster (Talent)** = Exo Toughness = 40% Max Toughness → break ได้รอบสอง (กลไก unique ต้องมี second-toughness bar)
- **Super Break conversion 100%** เมื่อเพื่อนตี broken enemy (ขณะ Fugue อยู่ในสนาม)
- **Foxian Prayer (Skill)**: BE +30% + ignore-weakness toughness 50% ให้เพื่อน 1 ตัว (E6 → ทั้งทีมขณะ Torrid Scorch)
- **Ult**: ignore-weakness toughness reduction + Fire weakness break
- **BE breakpoint 220%** (A6) — Fugue เป็น BE-scaling support
- โค้ด: `Fugue.h` — ตรวจ `Start_game_List` / weakness apply

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tingyun-fugue — kit tab (review patch 3.2, calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 65,
  "name": "Tingyun • Fugue",
  "slug": "tingyun-fugue",
  "rarity": "5",
  "element": "Fire",
  "path": "Nihility",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "December 25th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 153.12,
    "def_base": 75.9,
    "atk_base": 79.2,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Break Effect",
      "value": 24
    },
    "traceStat2": {
      "stat": "speed",
      "value": 14
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Anya Floris",
    "kr": "이명호 (Lee Myeong-ho)",
    "jpn": "高田 憂希 (Yūki Takada)",
    "cn": "蒋丽 (Li Jiang)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/tingyun-fugue",
  "source_record_updated_at": "April 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `122501` | Radiant Streak | Basic ATK | Single Target |
| `basic_enh` | `122508` | Fiery Caress | Basic ATK | Blast |
| `skill` | `122502` | Virtue Beckons Bliss | Skill | Support |
| `ult` | `122503` | Solar Splendor Shines Upon All | Ultimate | AoE |
| `talent` | `122504` | Fortune Follows Where Virtue Spreads | Talent | Impair |
| `technique` | `122507` | Percipient Shine | Technique | Impair |

## Ability records

### Radiant Streak

```json
{
  "ability_id": "122501",
  "slot": "basic",
  "name": "Radiant Streak",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
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
  "description_sha256": "04e4edf448433b7f21c2d9e23b66dec6ff451beb1d6fa29ead4617a85341537b",
  "icon_path": "icon/skill/1225_basic_atk.png"
}
```

### Fiery Caress

```json
{
  "ability_id": "122508",
  "slot": "basic_enh",
  "name": "Fiery Caress",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "15",
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
          "value": 25,
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
        },
        "p2": {
          "value": 30,
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
        },
        "p2": {
          "value": 35,
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
        },
        "p2": {
          "value": 40,
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
        },
        "p2": {
          "value": 45,
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
          "value": 50,
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
        },
        "p2": {
          "value": 55,
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
        },
        "p2": {
          "value": 60,
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
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6fce2857e33cd81ecbf91d8516d7784d7064c027399f33328567c5c1deeb0148",
  "icon_path": null
}
```

### Virtue Beckons Bliss

```json
{
  "ability_id": "122502",
  "slot": "skill",
  "name": "Virtue Beckons Bliss",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Fire",
  "energy_gain": "30",
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
    "p6": {
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
    "break_effect",
    "toughness",
    "weakness"
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 8,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 16.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 9,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 19.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 11,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 12,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 13,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 24.37,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 14.25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 15.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 28.12,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 16.75,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 19,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 34.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 21,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 22,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
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
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 23,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        },
        "p6": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "59b0f1c0fdc83090dde439b72f30ce9858c0b185446a99bb87d29225e13e83dd",
  "icon_path": "icon/skill/1225_skill.png"
}
```

### Solar Splendor Shines Upon All

```json
{
  "ability_id": "122503",
  "slot": "ult",
  "name": "Solar Splendor Shines Upon All",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
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
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "dfbbab3489dd597813a3d79b70c2665a7462c58af9cdfb7669591e34c5576125",
  "icon_path": "icon/skill/1225_ultimate.png"
}
```

### Fortune Follows Where Virtue Spreads

```json
{
  "ability_id": "122504",
  "slot": "talent",
  "name": "Fortune Follows Where Virtue Spreads",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Fire",
  "energy_gain": "0",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
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
    "dmg",
    "toughness",
    "weakness"
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
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
          "value": 40,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "51a9c20d8d7fd50f7805b89a533032606374995e81c987ad0475c8f139aba44e",
  "icon_path": "icon/skill/1225_talent.png"
}
```

### Percipient Shine

```json
{
  "ability_id": "122507",
  "slot": "technique",
  "name": "Percipient Shine",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Fire",
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
    "p4": {
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
    "def",
    "action_advance"
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 40,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "90faf3b360cd0b7655b99cbab6406d5232c8e476acb24e8d9df0446bb454f5ec",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Verdantia Renaissance",
    "mechanic_tags": [
      "weakness"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "5b9109d59c7dd1125bc33b53ac39f6d08dd75ac868e2745b225b483c4813869d"
  },
  {
    "requirement": "A4",
    "name": "Sylvan Enigma",
    "mechanic_tags": [
      "break_effect",
      "skill_points"
    ],
    "numeric_tokens": [
      "30%",
      "1"
    ],
    "description_sha256": "75f1b8e100322ed74c821c54a69381a0e296a4012a6da83efcc6a3cbe5b51466"
  },
  {
    "requirement": "A6",
    "name": "Phecda Primordia",
    "mechanic_tags": [
      "break_effect",
      "weakness"
    ],
    "numeric_tokens": [
      "6%",
      "220%",
      "12%",
      "2",
      "2"
    ],
    "description_sha256": "0b690408867b131763df4618a1f264431885c1b018dff98ead0ed09c05b119d5"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Earthbound I Was, Cloudward I Be",
    "mechanic_tags": [
      "weakness_break_efficiency",
      "weakness"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "6283a1292f99bba1fd35b4002b4b981af76ce87a774cd5589cb70af51561effb"
  },
  {
    "eidolon": 2,
    "name": "Beatitude Dawns for the Worthy",
    "mechanic_tags": [
      "energy",
      "action_advance",
      "weakness"
    ],
    "numeric_tokens": [
      "3",
      "24%"
    ],
    "description_sha256": "0e6e922b5c22503493afcb27b1c1acddd371fb6a76cadb72bd4e617110827a0a"
  },
  {
    "eidolon": 3,
    "name": "Verity Weaves Thoughts to Blade",
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
    "name": "Bereft of Form, Which Name to Bear",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "da3c5d3f3e2bf921c23ad689eda43868d9f980569aa6199714a93a2d9f501e04"
  },
  {
    "eidolon": 5,
    "name": "Colored Cloud Rains Fortune",
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
    "name": "Clairvoyance of Boom and Doom",
    "mechanic_tags": [
      "weakness_break_efficiency",
      "weakness"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "1626a51ba0536cc2fd7b162ba71f9e5fc96998fb1decfd9335f87a14bb3d4b9f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
