---
schema_version: "1.0.0"
unit_id: 33
name: "Luka"
slug: "luka"
rarity: 4
element: "Physical"
path: "Nihility"
role: "Sub DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/luka"
source_record_updated_at: "July 4th, 2025"
dataset_snapshot: "2026-05-30"
---

# Luka

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Luka.h` |
| ธาตุ | **Physical** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.5 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 917 · ATK 582 · DEF 485 · SPD 103

> Nihility single-target DPS สาย Bleed + "Fighting Will" + DMG vulnerability

---

### Basic ATK — Direct Punch (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Sky-Shatter Fist (โจมตีเดี่ยว, Lv.6)
- กิน **Fighting Will 2 stacks**
- Direct Punch **3 hit × 20% ATK** + Rising Uppercut **1 hit × 80% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 20

### Skill — Lacerating Fist (โจมตีเดี่ยว, Lv.10)
- Physical DMG = **120% ATK** ใส่ศัตรู 1 ตัว
- 100% base chance ติด **Bleed** นาน 3 เทิร์น
- Bleed: Physical DoT ต้นทุกเทิร์น = **24% ของ Max HP ศัตรู** แต่ไม่เกิน **338% ATK ของ Luka**
- Energy +30 · Toughness 20

### Ultimate — Coup de Grâce (โจมตีเดี่ยว, 130 energy, Lv.10)
- ได้ **Fighting Will 2 stacks**
- 100% base chance ศัตรูเป้าหมายรับดาเมจเพิ่ม **+20%** นาน 3 เทิร์น
- Physical DMG = **330% ATK** ใส่เป้าหมาย
- Energy +5 · Toughness 30

### Talent — Flying Sparks (Lv.10)
- หลังใช้ Direct Punch หรือ Lacerating Fist → Fighting Will **+1** (สูงสุด 4)
- มี Fighting Will ≥ 2 → Direct Punch enhanced เป็น "Sky-Shatter Fist"
- หลัง Rising Uppercut ของ Enhanced BA โดนศัตรู Bleeding → Bleed สร้างความเสียหายทันที 1 ครั้ง = **85% ของดาเมจเดิม**
- ต้นการต่อสู้ → มี Fighting Will 1 stack

### Technique — Anticipator
- เข้าฉากโจมตี: Physical DMG = **50% ATK** ใส่ศัตรูสุ่ม + 100% base chance ติด Bleed (แบบ Skill) + Fighting Will **+1**
- Toughness 20

---

### Major Traces
- **A2 — Kinetic Overload**: ใช้ Skill → ลบ buff 1 อันจากเป้าหมาย
- **A4 — Cycle Braking**: ทุก Fighting Will ที่ได้ → คืน Energy **3**
- **A6 — Crush Fighting Will**: ใช้ Enhanced BA ทุก hit ของ Direct Punch → 50% fixed chance ตีเพิ่มอีก 1 hit (ไม่ apply กับ hit ที่เกิดจาก effect นี้)

### Minor Traces (รวมทั้งหมด)
ATK +28% · Effect HIT Rate +18% · DEF +12.5%

### Eidolons
- **E1**: เมื่อ Luka action ถ้าเป้าหมาย Bleeding → Luka +DMG **+15%** นาน 2 เทิร์น
- **E2**: ถ้า Skill โดนศัตรูที่มี Physical Weakness → Fighting Will **+1**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ทุก Fighting Will ที่ได้ → ATK **+5%** stack 4 ครั้ง
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: หลัง Rising Uppercut โดนศัตรู Bleeding → Bleed สร้างความเสียหายทันที = **8% ของดาเมจเดิม ต่อ hit ของ Direct Punch ที่ปล่อยไปแล้วใน Enhanced BA ครั้งนั้น**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Fighting Will** (0–4): +1 ต่อ Direct Punch/Skill, +2 Ult, +1 Technique, start 1 (E2 +1 conditional); ≥ 2 → BA enhanced, กิน 2/Enhanced BA
- **Bleed**: min(24% enemy Max HP, 338% ATK)/turn — HP-scaling DoT capped by ATK
- **Bleed detonation**: Talent 85% ของดาเมจเดิม หลัง Uppercut โดน bleeding (E6 +8%/Direct Punch hit)
- **A6**: 50% chance extra Direct Punch hit ต่อ hit (variance สูง)
- **Ult vulnerability +20%** (3t) — Luka มักเป็น trigger enabler ให้ Black Swan/Kafka
- **A4 energy**: +3 ต่อ Fighting Will → energy generation สูง
- โค้ด: `Start_game_List` (`Luka.h:140`, `lk`, `FW`) — start Fighting Will + technique

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/luka — kit tab (review patch 2.5, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 33,
  "name": "Luka",
  "slug": "luka",
  "rarity": "4",
  "element": "Physical",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": "Belobog",
  "release_date": "August 9th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 124.8,
    "def_base": 66,
    "atk_base": 79.2,
    "speed_base": 103
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "effectHitRate",
      "value": 18
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Howard Wang",
    "kr": "Lee Joo-Seung (이주승)",
    "jpn": "Kajiwara Gakuto (梶原岳人)",
    "cn": "Xiao Zhai (萧翟)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/luka",
  "source_record_updated_at": "July 4th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `111101` | Direct Punch | Basic ATK | Single Target |
| `basic_enh` | `111108` | Sky-Shatter Fist | Basic ATK | Single Target |
| `skill` | `111102` | Lacerating Fist | Skill | Single Target |
| `ult` | `111103` | Coup de Grâce | Ultimate | Single Target |
| `talent` | `111104` | Flying Sparks | Talent | Enhance |
| `technique` | `111107` | Anticipator | Technique | MazeAttack |

## Ability records

### Direct Punch

```json
{
  "ability_id": "111101",
  "slot": "basic",
  "name": "Direct Punch",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
  "description_sha256": "df74dda2b4fe30eb7613a1c000f9fdf9611856570ff8234c83edced53681e463",
  "icon_path": "icon/skill/1111_basic_atk.png"
}
```

### Sky-Shatter Fist

```json
{
  "ability_id": "111108",
  "slot": "basic_enh",
  "name": "Sky-Shatter Fist",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
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
          "value": 10,
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
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 64,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 104,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a7aa523ad02940488a932f8b4fdc01988bff038fef6a00c2e96571dff6234396",
  "icon_path": "icon/skill/1111_basic_atk.png"
}
```

### Lacerating Fist

```json
{
  "ability_id": "111102",
  "slot": "skill",
  "name": "Lacerating Fist",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
    "p5": {
      "unit": "scalar",
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
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 130,
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
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 143,
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
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 156,
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
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 169,
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
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 182,
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
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 201.5,
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
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 227.5,
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
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 260,
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
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 299,
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
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 338,
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
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 354.9,
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
          "value": 132,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 371.8,
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
          "value": 138,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 388.7,
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
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 405.6,
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
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 422.5,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "72e30d8ba718b9da927cffb734b668209e5041368d34edb9cd6760a433d70e06",
  "icon_path": "icon/skill/1111_skill.png"
}
```

### Coup de Grâce

```json
{
  "ability_id": "111103",
  "slot": "ult",
  "name": "Coup de Grâce",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p5": {
      "unit": "scalar",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 198,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 211.2,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 12.8,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 224.4,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 13.6,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 237.6,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 250.8,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 15.2,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 264,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 280.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 297,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 313.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 19,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 330,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 343.2,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 20.8,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 356.4,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 21.6,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 369.6,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 22.4,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 382.8,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 23.2,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
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
          "value": 396,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "29e8a71b3269a20ad11773f13034af5c41cbf8d70aee15476bd65e5703e074fa",
  "icon_path": "icon/skill/1111_ultimate.png"
}
```

### Flying Sparks

```json
{
  "ability_id": "111104",
  "slot": "talent",
  "name": "Flying Sparks",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
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
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 68,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 69.7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 71.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 73.1,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 74.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 76.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 78.63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 80.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 82.88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 85,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 86.7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 88.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 90.1,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 91.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 93.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ea84634c3fed74b09ae7b3951f0b52b3b3930a9a73ae6e2660e02e1c47d4201f",
  "icon_path": "icon/skill/1111_talent.png"
}
```

### Anticipator

```json
{
  "ability_id": "111107",
  "slot": "technique",
  "name": "Anticipator",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "795b492ac702168964cbfb0bd57e44c2a3c9ddfe866610ac12377237694cbb28",
  "icon_path": "icon/skill/1111_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Kinetic Overload",
    "mechanic_tags": [
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "a9c5d6e0c4482445b590b0e078e6ea25f80645186491cca46d2a1b6e96b150e2"
  },
  {
    "requirement": "A4",
    "name": "Cycle Braking",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "3"
    ],
    "description_sha256": "89086dfe2a5d509dfb314dd4cfdfcf156179c3cdc523aed97538995294066264"
  },
  {
    "requirement": "A6",
    "name": "Crush Fighting Will",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "50%",
      "1"
    ],
    "description_sha256": "c9dddbc2d94ef4628a6b8ffe0354db860655e521915354570d7a671cd49a03c6"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Fighting Endlessly",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "15%",
      "2"
    ],
    "description_sha256": "13181abb7a4b544314839bd2e07ef46ddfcb4192639d2d7aa5e4b8a736d7fbef"
  },
  {
    "eidolon": 2,
    "name": "The Enemy is Weak, I am Strong",
    "mechanic_tags": [
      "weakness"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "e97fb9087605ab7e1f37851c6fb15469a9cc6cd53031714c4c3ee53e5e2968e4"
  },
  {
    "eidolon": 3,
    "name": "Born for the Ring",
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
    "eidolon": 4,
    "name": "Never Turning Back",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "5%",
      "4"
    ],
    "description_sha256": "5085d1ce1c5d9999964024aa5dfb65fbdda094a9058200258aa36cee7e5929ad"
  },
  {
    "eidolon": 5,
    "name": "The Spirit of Wildfire",
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
    "eidolon": 6,
    "name": "A Champion's Applause",
    "mechanic_tags": [
      "atk",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "1",
      "8%"
    ],
    "description_sha256": "2ed2e954e720552d289e79a537b76cba13f0b9daf1f63aa3972ae0cc3253dcea"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
