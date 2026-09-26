---
schema_version: "1.0.0"
unit_id: 47
name: "Sparkle"
slug: "sparkle"
rarity: 5
element: "Quantum"
path: "Harmony"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/sparkle"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Sparkle

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Hanabi.h` (มีเวอร์ชันเก่า `HanabiV1.h` — ข้าม) |
| ธาตุ | **Quantum** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1397 · ATK 523 · DEF 485 · SPD 101

> Harmony support สาย Skill Point battery + CRIT DMG + turn advance

---

### Basic ATK — Monodrama (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Dreamdiver (Support, Lv.10)
- เพื่อน 1 ตัว CRIT DMG **+เท่ากับ 24% ของ CRIT DMG ของ Sparkle + 45%** นาน 2 เทิร์น
- advance action เพื่อนคนนั้น **50%**
- ใช้ใส่ตัวเอง → ไม่ได้ Action Advance
- Energy +30

### Ultimate — The Hero with a Thousand Faces (Support, 110 energy, Lv.10)
- คืน **Skill Point 6** ให้ทีม
- ถ้า SP overflow → บันทึกส่วนเกินสูงสุด **10**; เมื่อจบเทิร์นเพื่อน ถ้า SP < max → กินค่าที่บันทึกไว้เติม SP
- มอบ **"Cipher"** ให้เพื่อนทุกคน — เพื่อนที่มี Cipher: ต่อ stack ของ DMG Boost จาก Talent → เพิ่มอีก **+6%/stack** นาน 3 เทิร์น
- Energy +5

### Talent — Red Herring (Lv.10)
- ขณะ Sparkle อยู่ในสนาม → Max Skill Points **+2**
- ทุกครั้งเพื่อนกิน 1 Skill Point → Sparkle ได้ **"Figment" 1 stack** — ต่อ stack: ศัตรูทุกตัวรับดาเมจเพิ่ม **+4%** นาน 2 เทิร์น stack 3 ครั้ง

### Technique — Unreliable Narrator
- มอบ Misdirect ให้เพื่อนทุกคน 20 วิ
- เข้าฉากใน Misdirect → คืน Skill Point **3** ให้ทีม + Sparkle คืน Energy **20**

---

### Major Traces
- **A2 — Almanac**: ใช้ BA → คืน Energy **10**. เมื่อเพื่อนที่ถือ CRIT DMG Boost จาก Skill กิน Skill Point → Sparkle คืน Energy **1**
- **A4 — Artificial Flower**: ถ้าเพื่อนกิน ≥ 3 Skill Point ในเทิร์นเดียว → Skill ครั้งถัดไปของ Sparkle ไม่กิน Skill Point
- **A6 — Nocturne**: เพื่อนทุกคน ATK **+45%**. เพื่อนที่ถือ CRIT DMG Boost จาก Skill → All-Type RES PEN **+10%**

### Minor Traces (รวมทั้งหมด)
HP +28% · CRIT DMG +24% · Effect RES +10%

### Eidolons
- **E1**: เพื่อนที่มี "Cipher" ATK **+40%**. ต้นการต่อสู้ หรือใช้ Skill → Sparkle SPD **+15%** นาน 2 เทิร์น
- **E2**: ทุก stack ของ Talent → ลด DEF ศัตรู **10%** เพิ่ม
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: Ult คืน Skill Point **+1** (รวม 7). Talent → Max Skill Points **+1** เพิ่ม
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: CRIT DMG Boost จาก Skill → เพิ่มอีก **30% ของ CRIT DMG ของ Sparkle**. ใช้ Skill → Boost apply ให้เพื่อนที่มี "Cipher" ทั้งหมด. ใช้ Ult → เพื่อน 1 ตัวที่มี Boost กระจาย Boost ให้เพื่อนที่มี "Cipher"

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill Point economy** เป็นแกน: Max SP +2 (E4 +1), Ult คืน 6 (E4 7) + overflow bank 10, Technique +3
- **Skill CRIT DMG buff**: 0.24 × (CD ของ Sparkle) + 45% (E6 +0.30×CD) — ผูกกับ CD ของ Sparkle
- **Figment/Talent** vulnerability: +4%/stack (cap 3), Cipher → +6%/stack เพิ่ม, E2 → −10% DEF/stack
- **Skill action advance 50%** (ไม่ทำงานตอน self-target)
- โค้ด: `Start_game_List` (`Hanabi.h:141`) — น่าจะ technique SP/energy
- ระวัง: `HanabiV1.h` เป็น implement เก่า อย่าอ้างอิง

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sparkle — kit tab (review/calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 47,
  "name": "Sparkle",
  "slug": "sparkle",
  "rarity": "5",
  "element": "Quantum",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "February 28th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 190.08,
    "def_base": 66,
    "atk_base": 71.28,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 28
    },
    "traceStat2": {
      "stat": "CRIT DMG",
      "value": 24
    },
    "traceStat3": {
      "stat": "Effect RES",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Lizzie Freeman",
    "kr": "성예원 (Sung Ye-won)",
    "jpn": "上田丽奈 (Ueda Reina)",
    "cn": "赵爽 (Zhao Shuang)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/sparkle",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130601` | Monodrama | Basic ATK | Single Target |
| `skill` | `130602` | Dreamdiver | Skill | Support |
| `ult` | `130603` | The Hero with a Thousand Faces | Ultimate | Support |
| `talent` | `130604` | Red Herring | Talent | Support |
| `technique` | `130607` | Unreliable Narrator | Technique | Support |

## Ability records

### Monodrama

```json
{
  "ability_id": "130601",
  "slot": "basic",
  "name": "Monodrama",
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
  "description_sha256": "7bf4b71dc9f287b41ce907553c492d64a686473ef78287c11dc0ec6e12dbbab4",
  "icon_path": "icon/skill/1306_basic_atk.png"
}
```

### Dreamdiver

```json
{
  "ability_id": "130602",
  "slot": "skill",
  "name": "Dreamdiver",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
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
    "crit_dmg",
    "dmg",
    "action_advance"
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
          "value": 27,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 28.8,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 30.6,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
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
          "value": 32.4,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        },
        "p2": {
          "value": 34.2,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
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
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        },
        "p2": {
          "value": 38.25,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 40.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 42.75,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 46.8,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        },
        "p2": {
          "value": 48.6,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 27.6,
          "unit": "percent"
        },
        "p2": {
          "value": 50.4,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 28.8,
          "unit": "percent"
        },
        "p2": {
          "value": 52.2,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f7830792a6a2ca45fda9e60ec79ef8593bfad7f3475f93e4ab0e38c9468d8f4b",
  "icon_path": "icon/skill/1306_skill.png"
}
```

### The Hero with a Thousand Faces

```json
{
  "ability_id": "130603",
  "slot": "ult",
  "name": "The Hero with a Thousand Faces",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
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
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 3.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 3.84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 4.08,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 4.32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 4.56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 4.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 5.1,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 5.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 5.7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 6.24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 6.48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 6.72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 6.96,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "759ffdc4ca48d158d5aaacfd384d06594e1119f74edd3da7ee90c8a87a553d2f",
  "icon_path": "icon/skill/1306_ultimate.png"
}
```

### Red Herring

```json
{
  "ability_id": "130604",
  "slot": "talent",
  "name": "Red Herring",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
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
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 2.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 2.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 2.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 2.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 3.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 3.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 3.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 4.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 4.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 4.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 4.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "482554d5a57a5a7110285a2c859f8ed980f92bc5189ed1a8486344c17a52ba3e",
  "icon_path": "icon/skill/1306_talent.png"
}
```

### Unreliable Narrator

```json
{
  "ability_id": "130607",
  "slot": "technique",
  "name": "Unreliable Narrator",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 2
    },
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "skill_points"
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
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "fed5444c779b8c95e59454c17bf156f67436c01fdc45bab291683bc4d0692dc5",
  "icon_path": "icon/skill/1306_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Almanac",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "energy",
      "dmg",
      "skill_points"
    ],
    "numeric_tokens": [
      "10",
      "1"
    ],
    "description_sha256": "11a7b35bc5406a74ea94a57171b87f6cae77169d97efcc8c5e4e1c11cd815576"
  },
  {
    "requirement": "A4",
    "name": "Artificial Flower",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "3"
    ],
    "description_sha256": "36800d5710d7c06b2caf8372272f4bc775cc31f0165b3cb4362e39de10023ca6"
  },
  {
    "requirement": "A6",
    "name": "Nocturne",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "45%",
      "10%"
    ],
    "description_sha256": "39f22773adea9ba67e87d293aa3f22ac56ea8b19b5f0532b0447cf31eda272f2"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Suspension of Disbelief",
    "mechanic_tags": [
      "atk",
      "spd"
    ],
    "numeric_tokens": [
      "40%",
      "15%",
      "2"
    ],
    "description_sha256": "f9b62c71ed2dab6b1e925092aca3c90c616688344dae42cdeb110a426c6833f1"
  },
  {
    "eidolon": 2,
    "name": "Purely Fictitious",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "e76c39b8192ef98b0341e307fdabc4da6d5d8905576167a05762ab0ad1939e2e"
  },
  {
    "eidolon": 3,
    "name": "Pipedream",
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
    "name": "Life Is a Gamble",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "1"
    ],
    "description_sha256": "622d408263aa1bce4ebbb9b7f11d9f275ab4b2d04534d8ba2492e54ddd3ff080"
  },
  {
    "eidolon": 5,
    "name": "Parallax Truth",
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
    "name": "Narrative Polysemy",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "161450e3c85e75160a2b3ad159716f2dce73a640866cd79e256c44d4ddf43b98"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
