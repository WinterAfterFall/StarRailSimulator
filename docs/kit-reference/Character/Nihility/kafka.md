---
schema_version: "1.0.0"
unit_id: 7
name: "Kafka"
slug: "kafka"
rarity: 5
element: "Lightning"
path: "Nihility"
role: "Main DPS"
affiliation: "Stellaron Hunters"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/kafka"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Kafka

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Kafka.h` |
| ธาตุ | **Lightning** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review patch 4.0 / calc patch 3.5) |

### Base Stats (Lv.80, ascended)
HP 1086 · ATK 679 · DEF 485 · SPD 100

> Nihility DoT DPS สาย Shock + DoT detonation

---

### Basic ATK — Midnight Tumult (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Caressing Moonlight (Blast, Lv.10)
- Lightning DMG หลัก = **160% ATK**, ข้างเคียง = **60% ATK**
- ถ้าเป้าหมาย/ข้างเคียงติด DoT → DoT ทั้งหมดสร้างความเสียหายทันที = **75% (หลัก) / 50% (ข้างเคียง)** ของดาเมจเดิม
- Energy +30 · Toughness 20 (+10)

### Ultimate — Twilight Trill (AoE, 120 energy, Lv.10)
- Lightning DMG = **80% ATK** AoE
- 100% base chance ศัตรูติด **Shocked** + DoT ปัจจุบันสร้างความเสียหายทันที = **120%** ของดาเมจเดิม
- Shock: Lightning DoT = **290% ATK** ต้นทุกเทิร์น นาน 2 เทิร์น
- Energy +5 · Toughness 20

### Talent — Gentle but Cruel (Lv.10)
- หลังเพื่อนใช้การโจมตีใส่ศัตรู → Kafka ยิง Follow-up ATK: Lightning DMG = **140% ATK** ใส่เป้าหมายหลัก + 100% base chance ติด Shock (แบบ Ult) นาน 2 เทิร์น
- trigger ได้ **2 ครั้ง**, คืน 1 use ตอนจบเทิร์นของ Kafka
- Energy +10 · Toughness 10

### Technique — Mercy Is Not Forgiveness
- เข้าฉากโจมตี AoE: Lightning DMG = **50% ATK** + 100% base chance ติด Shock (แบบ Ult) ศัตรูทุกตัว นาน 2 เทิร์น
- Toughness 20

---

### Major Traces
- **A2 — Torture**: ถ้าเพื่อนมี Effect Hit Rate ≥ 75% → Kafka เพิ่ม ATK ให้เพื่อนคนนั้น **+100%**
- **A4 — Plunder**: ถ้าศัตรูตายขณะ Shocked → Kafka คืน Energy **5**
- **A6 — Thorns**: หลังใช้ Ult → Talent Follow-up ATK trigger ได้ 1 ครั้ง + Follow-up ATK นั้นทำให้ DoT ทั้งหมดบนเป้าสร้างความเสียหายทันที = **80%** ของดาเมจเดิม

### Minor Traces (รวมทั้งหมด)
ATK +28% · Effect HIT Rate +18% · HP +10%

### Eidolons
- **E1**: เมื่อโจมตี → 100% base chance เป้าหมายรับ DoT เพิ่ม **+30%** นาน 2 เทิร์น
- **E2**: ขณะ Kafka อยู่ในสนาม → DoT ของเพื่อนทุกคน **+33%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: เมื่อศัตรูรับดาเมจจาก Shock ของ Kafka → Kafka คืน Energy **2**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Shock DMG multiplier จาก Ult/Technique/Talent-FUA **+156%** + Shock **+1 เทิร์น**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Shock** DoT: 290% ATK/2t (E6 +156% + 1t) — จาก Ult / Technique / Talent FUA
- **DoT detonation**: Skill 75/50%, Ult 120%, A6 FUA 80% — ต้อง track DoT "original DMG" ต่อ instance
- **Talent FUA**: 140% ATK + Shock, 2 charges, +1/turn (A6 +1 หลัง Ult) — trigger ต่อการโจมตีของเพื่อน
- **A2**: ATK +100% ให้เพื่อนที่ EHR ≥ 75% (มักคู่ Black Swan)
- **E2 DoT +33% ทีม** / E1 DoT vulnerability +30%
- **energy**: A4 (+5 kill), E4 (+2 ต่อ Shock tick)
- โค้ด: `Start_game_List` (`Kafka.h:136`, `kafka`) — technique Shock + self-flush

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/kafka — kit tab (review patch 4.0, calc patch 3.5, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 7,
  "name": "Kafka",
  "slug": "kafka",
  "rarity": "5",
  "element": "Lightning",
  "path": "Nihility",
  "default_role": "Main DPS",
  "affiliation": "Stellaron Hunters",
  "release_date": "August 9th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 147.84,
    "def_base": 66,
    "atk_base": 92.4,
    "speed_base": 100
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
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Cheryl Texiera",
    "kr": "Sa Moon-young (사문영)",
    "jpn": "Itoh Shizuka (伊藤静)",
    "cn": "Hui Xu (徐慧)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/kafka",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `100501` | Midnight Tumult | Basic ATK | Single Target |
| `skill` | `100502` | Caressing Moonlight | Skill | Blast |
| `ult` | `100503` | Twilight Trill | Ultimate | AoE |
| `talent` | `100504` | Gentle but Cruel | Talent | Single Target |
| `technique` | `100507` | Mercy Is Not Forgiveness | Technique | MazeAttack |

## Ability records

### Midnight Tumult

```json
{
  "ability_id": "100501",
  "slot": "basic",
  "name": "Midnight Tumult",
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
  "description_sha256": "9efb353fdbe817fd978c71d5035bf8866be74b99ea6ce59627d705cc734aa81f",
  "icon_path": "icon/skill/1005_basic_atk.png"
}
```

### Caressing Moonlight

```json
{
  "ability_id": "100502",
  "slot": "skill",
  "name": "Caressing Moonlight",
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
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
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
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 61.5,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        },
        "p4": {
          "value": 41,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
        },
        "p4": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 104,
          "unit": "percent"
        },
        "p2": {
          "value": 64.5,
          "unit": "percent"
        },
        "p3": {
          "value": 39,
          "unit": "percent"
        },
        "p4": {
          "value": 43,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 112,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
          "unit": "percent"
        },
        "p4": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 67.5,
          "unit": "percent"
        },
        "p3": {
          "value": 45,
          "unit": "percent"
        },
        "p4": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 69.38,
          "unit": "percent"
        },
        "p3": {
          "value": 48.75,
          "unit": "percent"
        },
        "p4": {
          "value": 46.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 71.25,
          "unit": "percent"
        },
        "p3": {
          "value": 52.5,
          "unit": "percent"
        },
        "p4": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 73.13,
          "unit": "percent"
        },
        "p3": {
          "value": 56.25,
          "unit": "percent"
        },
        "p4": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 76.5,
          "unit": "percent"
        },
        "p3": {
          "value": 63,
          "unit": "percent"
        },
        "p4": {
          "value": 51,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 176,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        },
        "p3": {
          "value": 66,
          "unit": "percent"
        },
        "p4": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 184,
          "unit": "percent"
        },
        "p2": {
          "value": 79.5,
          "unit": "percent"
        },
        "p3": {
          "value": 69,
          "unit": "percent"
        },
        "p4": {
          "value": 53,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 81,
          "unit": "percent"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
        },
        "p4": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 55,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "1f2ed21bbf522f8a8a190001ae3b40c3a7831495763ae71dafce3a95cf71a0f0",
  "icon_path": "icon/skill/1005_skill.png"
}
```

### Twilight Trill

```json
{
  "ability_id": "100503",
  "slot": "ult",
  "name": "Twilight Trill",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Thunder",
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
    "p5": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "dot",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 116,
          "unit": "percent"
        },
        "p5": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 51.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 126.88,
          "unit": "percent"
        },
        "p5": {
          "value": 102,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 54.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 137.75,
          "unit": "percent"
        },
        "p5": {
          "value": 104,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 57.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 148.63,
          "unit": "percent"
        },
        "p5": {
          "value": 106,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 60.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 159.5,
          "unit": "percent"
        },
        "p5": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 175.81,
          "unit": "percent"
        },
        "p5": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 197.56,
          "unit": "percent"
        },
        "p5": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 224.75,
          "unit": "percent"
        },
        "p5": {
          "value": 115,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 76,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 257.38,
          "unit": "percent"
        },
        "p5": {
          "value": 117.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 80,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 290,
          "unit": "percent"
        },
        "p5": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 83.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 304.14,
          "unit": "percent"
        },
        "p5": {
          "value": 122,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 318.28,
          "unit": "percent"
        },
        "p5": {
          "value": 124,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 89.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 332.41,
          "unit": "percent"
        },
        "p5": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 92.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 346.55,
          "unit": "percent"
        },
        "p5": {
          "value": 128,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 360.69,
          "unit": "percent"
        },
        "p5": {
          "value": 130,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "109df5019f5d91cef0fbe0539292b8ad2e52f497d96b65ab00cf9beef216adce",
  "icon_path": "icon/skill/1005_ultimate.png"
}
```

### Gentle but Cruel

```json
{
  "ability_id": "100504",
  "slot": "talent",
  "name": "Gentle but Cruel",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
    "follow_up",
    "dot"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 51.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 61.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 71.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 81.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 91,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 103.25,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 115.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 127.75,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
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
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 149.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 159.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 169.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 179.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 189,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "bac4d196de24a28a520a2f655612c4c83af2f9779a5b1bab51e526175b591ea2",
  "icon_path": "icon/skill/1005_talent.png"
}
```

### Mercy Is Not Forgiveness

```json
{
  "ability_id": "100507",
  "slot": "technique",
  "name": "Mercy Is Not Forgiveness",
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
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
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
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c027acee96ee63fa5b5b4db328c47390dfddf89ae4aa409a14e349974f794520",
  "icon_path": "icon/skill/1005_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Torture",
    "mechanic_tags": [
      "atk",
      "effect_hit_rate"
    ],
    "numeric_tokens": [
      "75%",
      "100%"
    ],
    "description_sha256": "6bd32981365df839c669465c93c64b115917212f00d602733aa720f9bb09f7d5"
  },
  {
    "requirement": "A4",
    "name": "Plunder",
    "mechanic_tags": [
      "energy",
      "dot"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "e832b883931a490dbfcdf9e1124325743616af51c763ff8001b9450e0784cf7b"
  },
  {
    "requirement": "A6",
    "name": "Thorns",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up",
      "dot",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1",
      "80%"
    ],
    "description_sha256": "e4c354eb09f38a585af935a61a186f71f5c33ba97d90488bd65de0875fc569a5"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Da Capo",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "100%",
      "30%",
      "2"
    ],
    "description_sha256": "116a857368372847f5712f75109c5da8843977d5e84878e54ce5cd49be55fb06"
  },
  {
    "eidolon": 2,
    "name": "Fortississimo",
    "mechanic_tags": [
      "dot"
    ],
    "numeric_tokens": [
      "33%"
    ],
    "description_sha256": "ed7712ffefd14ef6aecdb02a18acaf74aa20dfbb3d0a296cc96b18ed09815b37"
  },
  {
    "eidolon": 3,
    "name": "Capriccio",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "1db409cc64230c6d43effaf06e14357557fc834777bb0a6ecd7f7a41e74a4ec5"
  },
  {
    "eidolon": 4,
    "name": "Recitativo",
    "mechanic_tags": [
      "energy",
      "dmg",
      "dot"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "90a1c15cfab2b8ca53c8007cfb745d8242ae6c494e64bc93af6e763fab0a2b65"
  },
  {
    "eidolon": 5,
    "name": "Doloroso ",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "2",
      "15"
    ],
    "description_sha256": "c69db63dc4ccfd8e2f5f7edcd607380a48587a0e5fd5f4cd7871a4e975585803"
  },
  {
    "eidolon": 6,
    "name": "Leggiero",
    "mechanic_tags": [
      "dmg",
      "follow_up",
      "dot"
    ],
    "numeric_tokens": [
      "156%",
      "1"
    ],
    "description_sha256": "9b60ef072a0aed600f1cd35b77c2437aefb6c8068f8c170f940bee91ae1a4dcb"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
