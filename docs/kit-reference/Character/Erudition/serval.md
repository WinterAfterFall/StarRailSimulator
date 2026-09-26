---
schema_version: "1.0.0"
unit_id: 14
name: "Serval"
slug: "serval"
rarity: 4
element: "Lightning"
path: "Erudition"
role: "Sub DPS"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/serval"
source_record_updated_at: "June 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Serval

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Serval.h` |
| ธาตุ | **Lightning** |
| Path | **Erudition** |
| ระดับ | 4★ |
| Energy Ultimate | 100 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 917 · ATK 652 · DEF 374 · SPD 104

> Erudition DoT/DPS สาย Shock

---

### Basic ATK — Roaring Thunderclap (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Lightning Flash (Blast, Lv.10)
- Lightning DMG หลัก = **140% ATK**, ข้างเคียง = **60% ATK**
- 80% base chance → ศัตรูที่โดนติด **Shocked** นาน 2 เทิร์น
- Shocked: Lightning DoT = **104% ATK** ต้นทุกเทิร์น
- Energy +30 · Toughness 20 (+10)

### Ultimate — Here Comes the Mechanical Fever (AoE, 100 energy, Lv.10)
- Lightning DMG = **180% ATK** AoE
- ศัตรูที่ Shocked อยู่แล้ว → ยืด Shock **+2 เทิร์น**
- Energy +5 · Toughness 20

### Talent — Galvanic Chords (Lv.10)
- หลัง Serval โจมตี → Additional Lightning DMG = **72% ATK** ใส่ศัตรู Shocked ทุกตัว

### Technique — Good Night, Belobog
- เข้าฉากโจมตีทันที: Lightning DMG = **50% ATK** ใส่ศัตรูสุ่ม + 100% base chance ศัตรูทุกตัวติด **Shocked** นาน 3 เทิร์น
- Shock (จาก Technique): Lightning DoT = **50% ATK** ต้นทุกเทิร์น
- Toughness 20

---

### Major Traces
- **A2 — Rock 'n' Roll**: Skill มี base chance ติด Shock **+20%**
- **A4 — String Vibration**: ต้นการต่อสู้ → คืน Energy **15** ทันที
- **A6 — Mania**: ฆ่าศัตรู → ATK **+20%** นาน 2 เทิร์น

### Minor Traces (รวมทั้งหมด)
Effect HIT Rate +18% · CRIT Rate +18.7% · Effect RES +10%

### Eidolons
- **E1 — Echo Chamber**: Basic ATK → Lightning DMG = **60% ของดาเมจ Basic ATK** ใส่ศัตรูข้างเคียงสุ่ม 1 ตัว
- **E2 — Encore!**: ทุกครั้งที่ Talent trigger Additional DMG → คืน Energy **4**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4 — Make Some Noise!**: Ultimate มี 100% base chance ติด Shock ให้ศัตรูที่ยังไม่ Shocked (effect เหมือน Skill)
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Serval สร้างดาเมจกับศัตรู Shocked **+30%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Shock** = DoT debuff: Skill 104% ATK/2t (E4 Ult ก็ติด), Technique 50% ATK/3t; Ult ยืด +2t
- **Talent**: post-attack Additional 72% ATK ใส่ Shocked ทุกตัว — trigger บ่อย (`When_attack_List`)
- E1: BA splash 60% ของดาเมจ BA (ไม่ใช่ % ATK) ใส่ข้างเคียง
- E2: energy +4 ต่อ Talent trigger
- E6 / A6: DMG amp vs Shocked / on-kill ATK
- โค้ด: `Start_game_List` priority `PRIORITY_ACTTACK` (`Serval.h:90`) — น่าจะ technique attack + self-flush

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/serval — kit tab (review patch 2.6, calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 14,
  "name": "Serval",
  "slug": "serval",
  "rarity": "4",
  "element": "Lightning",
  "path": "Erudition",
  "default_role": "Sub DPS",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 124.8,
    "def_base": 51,
    "atk_base": 88.8,
    "speed_base": 104
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "effectHitRate",
      "value": 18
    },
    "traceStat2": {
      "stat": "critRate",
      "value": 18.7
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Natalie Van Sistine",
    "kr": "민아",
    "jpn": "Aimi",
    "cn": "穆雪婷"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/serval",
  "source_record_updated_at": "June 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110301` | Roaring Thunderclap | Basic ATK | Single Target |
| `skill` | `110302` | Lightning Flash | Skill | Blast |
| `ult` | `110303` | Here Comes the Mechanical Fever | Ultimate | AoE |
| `talent` | `110304` | Galvanic Chords | Talent | Enhance |
| `technique` | `110307` | Good Night, Belobog | Technique | MazeAttack |

## Ability records

### Roaring Thunderclap

```json
{
  "ability_id": "110301",
  "slot": "basic",
  "name": "Roaring Thunderclap",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
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
  "description_sha256": "f3c87ff95b0922bb7c47566f71b09739ba892832cb6c7b716da9ea0daf5fe07f",
  "icon_path": "icon/skill/1103_basic_atk.png"
}
```

### Lightning Flash

```json
{
  "ability_id": "110302",
  "slot": "skill",
  "name": "Lightning Flash",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Thunder",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
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
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 40,
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
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 44,
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
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 48,
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
          "value": 39,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 52,
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
          "value": 42,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 56,
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
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 62,
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
          "value": 48.75,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 70,
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
          "value": 52.5,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 80,
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
          "value": 56.25,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 92,
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 104,
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
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 109.2,
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
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 114.4,
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
          "value": 69,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 119.6,
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
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 124.8,
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
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 80,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 130,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "f334da8aefa7bc016f549f465a1c7ce0fbf1c77c2225830c1a3af1d2efdc22c9",
  "icon_path": "icon/skill/1103_skill.png"
}
```

### Here Comes the Mechanical Fever

```json
{
  "ability_id": "110303",
  "slot": "ult",
  "name": "Here Comes the Mechanical Fever",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Thunder",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "atk",
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 115.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 122.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 129.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 136.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 153,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 162,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 171,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 187.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 194.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 201.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 208.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "0e9806fb3e6442ef9c2a68977e08dd44c343228fda96dc6df76e3abebb42a9a0",
  "icon_path": "icon/skill/1103_ultimate.png"
}
```

### Galvanic Chords

```json
{
  "ability_id": "110304",
  "slot": "talent",
  "name": "Galvanic Chords",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Thunder",
  "energy_gain": null,
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
    "atk",
    "dmg",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 46.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 75.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 79.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 82.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c2b5060078e3ac2b70ec5d0ba76d1f31a491e23f5a4f3dac0e17f505d8bf515f",
  "icon_path": "icon/skill/1103_talent.png"
}
```

### Good Night, Belobog

```json
{
  "ability_id": "110307",
  "slot": "technique",
  "name": "Good Night, Belobog",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Thunder",
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
    "p3": {
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "aac525103eb381acc9b6c482bea34c6ceaa1aea60a8128277c413b8d6df0cd72",
  "icon_path": "icon/skill/1103_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Rock 'n' Roll",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "20a6b31b47ad125887848b31a8b74eb82ae9b074c553325b86fdeb6ab15be0d6"
  },
  {
    "requirement": "A4",
    "name": "String Vibration",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15"
    ],
    "description_sha256": "49cd4ce181fe9ef5e523e5e955c0ba45a10293d800b6cada079d46e153b03889"
  },
  {
    "requirement": "A6",
    "name": "Mania",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "20%",
      "2"
    ],
    "description_sha256": "cf3b92a5d130175ed303c4542a020dca9ef72065e4776c619986c1f2e20920ed"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Echo Chamber",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "60%"
    ],
    "description_sha256": "95bc3b5ccc803f60d782b897d080923f4875d05249159b1b6de26e31ac3b7469"
  },
  {
    "eidolon": 2,
    "name": "Encore! ",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "4"
    ],
    "description_sha256": "88782d32a038b4ed7b85ca46f41d6a850c4573a41559edc7cbaf04f47b015731"
  },
  {
    "eidolon": 3,
    "name": "Listen, the Heartbeat of the Gears",
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
    "name": "Make Some Noise!",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "dfbe55e56b6c9495bd267e8d12dde6706357b00a8ba4b8b9d721e3ed924a101a"
  },
  {
    "eidolon": 5,
    "name": "Belobog’s Loudest Roar!",
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
    "name": "This Song Rocks to Heaven!",
    "mechanic_tags": [
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "613203b3fd09fb498e412998c46b16be2feee645815f6f14d1d94ab54322da49"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
