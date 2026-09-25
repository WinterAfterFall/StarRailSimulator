---
schema_version: "1.0.0"
unit_id: 39
name: "Guinaifen"
slug: "guinaifen"
rarity: 4
element: "Fire"
path: "Nihility"
role: "Sub DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/guinaifen"
source_record_updated_at: "July 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Guinaifen

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Guinaifen.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 882 · ATK 582 · DEF 441 · SPD 106

> Nihility DoT/support สาย Burn + "Firekiss" (vulnerability)

---

### Basic ATK — Standing Ovation (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Blazing Welcome (Blast, Lv.10)
- Fire DMG หลัก = **120% ATK**, ข้างเคียง = **40% ATK**
- 100% base chance ติด **Burn** เป้าหมาย + ข้างเคียง
- Burn: Fire DoT = **218.2% ATK** ต้นทุกเทิร์น นาน 2 เทิร์น
- Energy +30 · Toughness 20 (+10)

### Ultimate — Watch This Showstopper (AoE, 120 energy, Lv.10)
- Fire DMG = **120% ATK** AoE
- ถ้าเป้าหมายติด Burn → Burn สร้างความเสียหายทันที = **92% ของดาเมจ Burn เดิม**
- Energy +5 · Toughness 20

### Talent — PatrAeon Benefits (Lv.10)
- ขณะ Guinaifen อยู่ในสนาม → 100% base chance ติด **Firekiss** ให้ศัตรูหลังจาก Burn สร้างความเสียหาย
- Firekiss: ศัตรูรับดาเมจเพิ่ม **+7%** นาน 3 เทิร์น stack 3 ครั้ง
- Energy +5

### Technique — Skill Showcase
- เข้าฉากโจมตี: **4 instance × 50% ATK** Fire DMG ใส่ศัตรูสุ่ม + 100% base chance ติด Firekiss
- Toughness 20

---

### Major Traces
- **A2 — High Poles**: Basic ATK 80% base chance ติด Burn (แบบเดียวกับ Skill)
- **A4 — Bladed Hoop**: ต้นการต่อสู้ → Guinaifen action advance **25%**
- **A6 — Walking on Knives**: สร้างดาเมจกับศัตรู Burned **+20%**

### Minor Traces (รวมทั้งหมด)
Fire DMG +22.4% · Effect HIT Rate +10% · Break Effect +24%

### Eidolons
- **E1**: ใช้ Skill → 100% base chance ลด Effect RES ศัตรูที่โดน **10%** นาน 2 เทิร์น
- **E2**: ศัตรูติด Burn → Basic ATK/Skill ของ Guinaifen เพิ่ม multiplier ของ Burn **+40%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: ทุกครั้ง Burn ของ Guinaifen สร้างความเสียหาย → คืน Energy **2**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Firekiss stack cap **+1** (รวม 4)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Burn** DoT: 218.2% ATK/2t (E2 +40% multiplier ถ้าตีด้วย BA/Skill ตอน burned)
- **Firekiss** = vulnerability debuff: +7%/stack, cap 3 (E6 4) — trigger หลัง Burn สร้างความเสียหาย (Talent) + Technique
- **Ult**: บังคับ Burn สร้างความเสียหายทันที 92%
- **A6**: DMG amp vs Burned +20% (self)
- **E4 energy**: +2 ต่อ Burn tick
- โค้ด: `Start_game_List` (`Guinaifen.h:100`, `gui`) — A4 advance + technique

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/guinaifen — kit tab (review patch 3.0, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 39,
  "name": "Guinaifen",
  "slug": "guinaifen",
  "rarity": "4",
  "element": "Fire",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "October 27th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 120,
    "def_base": 60,
    "atk_base": 79.2,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "dmg_fire",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "effect_hit",
      "value": 10
    },
    "traceStat3": {
      "stat": "break",
      "value": 24
    }
  },
  "voice_actors": {
    "en": "Morgan Lauré",
    "kr": "김수영 (Kim Soo-young)",
    "jpn": "直田姫奈 (Suguta Hina)",
    "cn": "小敢 (Xiaogan)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/guinaifen",
  "source_record_updated_at": "July 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121001` | Standing Ovation | Basic ATK | Single Target |
| `skill` | `121002` | Blazing Welcome | Skill | Blast |
| `ult` | `121003` | Watch This Showstopper | Ultimate | AoE |
| `talent` | `121004` | PatrAeon Benefits | Talent | Impair |
| `technique` | `121007` | Skill Showcase | Technique | MazeAttack |

## Ability records

### Standing Ovation

```json
{
  "ability_id": "121001",
  "slot": "basic",
  "name": "Standing Ovation",
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
  "description_sha256": "cdf93205897452578c4ce3fa3cd14e2e504e912c56e259f2f90a56161becb735",
  "icon_path": "icon/skill/1210_basic_atk.png"
}
```

### Blazing Welcome

```json
{
  "ability_id": "121002",
  "slot": "skill",
  "name": "Blazing Welcome",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
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
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 83.9,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 92.3,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 100.69,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 26,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 109.09,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 117.48,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
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
          "value": 130.07,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 146.86,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 167.84,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
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
          "value": 193.03,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 40,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 218.21,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 229.12,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 240.03,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        },
        "p2": {
          "value": 46,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 250.94,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 261.86,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 272.77,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "761ec2de27b6325a42b2d2d52e9ccba8ac33eadb2da52836f1bee8789d3d099e",
  "icon_path": "icon/skill/1210_skill.png"
}
```

### Watch This Showstopper

```json
{
  "ability_id": "121003",
  "slot": "ult",
  "name": "Watch This Showstopper",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 76.8,
          "unit": "percent"
        },
        "p2": {
          "value": 74,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 81.6,
          "unit": "percent"
        },
        "p2": {
          "value": 76,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 91.2,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 82,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 102,
          "unit": "percent"
        },
        "p2": {
          "value": 84.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 87,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 114,
          "unit": "percent"
        },
        "p2": {
          "value": 89.5,
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
        },
        "p2": {
          "value": 92,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 124.8,
          "unit": "percent"
        },
        "p2": {
          "value": 94,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 129.6,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 134.4,
          "unit": "percent"
        },
        "p2": {
          "value": 98,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 139.2,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 102,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6759be2387963efad027820e60b39cc13a86e53cdf1fff94e51d3da9d8f88077",
  "icon_path": "icon/skill/1210_ultimate.png"
}
```

### PatrAeon Benefits

```json
{
  "ability_id": "121004",
  "slot": "talent",
  "name": "PatrAeon Benefits",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
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
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "dot"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 4,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.3,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.6,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 4.9,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.2,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.5,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 5.88,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 6.25,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 6.63,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 7,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 7.3,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 7.6,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 7.9,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 8.2,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 8.5,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        },
        "p6": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "5116d9b3c40e1e7b42654418d2a5ed960a75a5ed4a7d2ed0cdcc86ac69965dce",
  "icon_path": "icon/skill/1210_talent.png"
}
```

### Skill Showcase

```json
{
  "ability_id": "121007",
  "slot": "technique",
  "name": "Skill Showcase",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
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
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "112177c91273d450f334e8fae2259b619016878bda1b8d336d67341f85e39f5c",
  "icon_path": "icon/skill/1210_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "High Poles",
    "mechanic_tags": [
      "atk",
      "dot"
    ],
    "numeric_tokens": [
      "80%"
    ],
    "description_sha256": "b120270ca62b105c233d734e8a1df1f94b22e9ce0a5f57d0d3a5c2f3ed493534"
  },
  {
    "requirement": "A4",
    "name": "Bladed Hoop",
    "mechanic_tags": [],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "0c21c402239d3da78d2c8db257621ae0a2e488a70648feac116d075afbb3e639"
  },
  {
    "requirement": "A6",
    "name": "Walking on Knives",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "2481690be39e359649edc43be3b7692c261ec3b01e3eb9130982dedba309333b"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Slurping Noodles During Handstand",
    "mechanic_tags": [
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "100%",
      "10%",
      "2"
    ],
    "description_sha256": "93088d65a5228f13434c53750b02c15723dda9e107e98496e2be0a22110504ea"
  },
  {
    "eidolon": 2,
    "name": "Brushing Teeth While Whistling",
    "mechanic_tags": [
      "atk",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "830d2062e2bf9fffe747a2fa9615ac07a3a4268302c3a366c30bc3c2ae7c8c93"
  },
  {
    "eidolon": 3,
    "name": "Smashing Boulder on Chest",
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
    "name": "Blocking Pike with Neck",
    "mechanic_tags": [
      "energy",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "92787065938186e7f4d9307459d355e7b966433e42e76cd0d5ab37b3f4330cb8"
  },
  {
    "eidolon": 5,
    "name": "Swallowing Sword to Stomach",
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
    "name": "Catching Bullet with Hands",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "7803f2d98a677f2714207d1cb2c97a6d86dd4751127c53aa0c63933b04b73311"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
