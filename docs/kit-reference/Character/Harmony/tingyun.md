---
schema_version: "1.0.0"
unit_id: 25
name: "Tingyun"
slug: "tingyun"
rarity: 4
element: "Lightning"
path: "Harmony"
role: "Support"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/tingyun"
source_record_updated_at: "October 26th, 2024"
dataset_snapshot: "2026-05-30"
---

# Tingyun

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Tingyun.h` |
| ธาตุ | **Lightning** |
| Path | **Harmony** |
| ระดับ | 4★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 846 · ATK 529 · DEF 396 · SPD 112

> Harmony support สาย ATK buff + Additional DMG (single-target "Benediction")

---

### Basic ATK — Dislodged (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Soothing Melody (Support, Lv.10)
- มอบ **Benediction** ให้เพื่อน 1 ตัว → ATK **+50%** แต่ไม่เกิน **25% ของ ATK ปัจจุบันของ Tingyun**
- เพื่อนที่มี Benediction เมื่อโจมตี → สร้าง Additional Lightning DMG = **40% ของ ATK ของเพื่อนคนนั้น** 1 ครั้ง
- Benediction นาน 3 เทิร์น มีผลกับเป้าหมาย Skill ล่าสุดเท่านั้น
- Energy +30

### Ultimate — Amidst the Rejoicing Clouds (Support, 130 energy, Lv.10)
- คืน Energy **50** ให้เพื่อน 1 ตัว + เป้าหมาย +DMG **50%** นาน 2 เทิร์น
- Energy +5

### Talent — Violet Sparknado (Lv.10)
- เมื่อ Tingyun โจมตีศัตรู → เพื่อนที่มี Benediction สร้าง Additional Lightning DMG = **60% ของ ATK ของเพื่อนคนนั้น** ใส่ศัตรูตัวเดียวกันทันที

### Technique — Gentle Breeze
- ใช้ Technique → Tingyun คืน Energy **50** ทันที

---

### Major Traces
- **A2 — Nourished Joviality**: หลังใช้ Skill → Tingyun SPD **+20%** นาน 1 เทิร์น
- **A4 — Knell Subdual**: Basic ATK DMG **+40%**
- **A6 — Jubilant Passage**: ต้นเทิร์นของ Tingyun → คืน Energy **5** ทันที

### Minor Traces (รวมทั้งหมด)
ATK +28% · DEF +22.5% · Lightning DMG +8%

### Eidolons
- **E1**: หลังเพื่อนที่มี Benediction ใช้ Ultimate → SPD **+20%** นาน 1 เทิร์น
- **E2**: เพื่อนที่มี Benediction คืน Energy **5** หลังฆ่าศัตรู (1 ครั้ง/เทิร์น)
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: multiplier ของ Benediction Additional DMG **+20%** (40%→60% skill hit, 60%→80% talent)
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Ultimate คืน Energy ให้เป้าหมายเพิ่ม **+10** (รวม 60)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Benediction**: ATK% buff = min(50%, 25% × ATK ปัจจุบันของ Tingyun / ATK เป้าหมาย?) — จริง ๆ คือ "ATK +50% แต่ค่า flat ที่เพิ่มไม่เกิน 25% ของ ATK ของ Tingyun" → ต้องคิด cap ให้ถูก
- **Additional Lightning DMG**: 40% ATK ของเพื่อน (Skill trigger, ต่อการโจมตี) + 60% ATK ของเพื่อน (Talent trigger เมื่อ Tingyun ตี) — สเกลกับ ATK ของ **เพื่อน** ไม่ใช่ Tingyun (E4 +20%)
- single-target buffer — ผูกกับ target ล่าสุด, 3 เทิร์น
- **Ult** = pure energy battery (50, E6 60) + DMG% 50%
- โค้ด: `Start_game_List` (`Tingyun.h:95`, `TYptr`)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tingyun — kit tab (review patch 2.6, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 25,
  "name": "Tingyun",
  "slug": "tingyun",
  "rarity": "4",
  "element": "Lightning",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Xianzhou Luofu",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 115.2,
    "def_base": 54,
    "atk_base": 72,
    "speed_base": 112
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat3": {
      "stat": "lightningDmg",
      "value": 8
    }
  },
  "voice_actors": {
    "en": "Laci Morgan",
    "kr": "이명호 (Lee Myeong-ho)",
    "jpn": "高田 憂希 (Yūki Takada)",
    "cn": "蒋丽 (Li Jiang)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/tingyun",
  "source_record_updated_at": "October 26th, 2024"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120201` | Dislodged | Basic ATK | Single Target |
| `skill` | `120202` | Soothing Melody | Skill | Support |
| `ult` | `120203` | Amidst the Rejoicing Clouds | Ultimate | Support |
| `talent` | `120204` | Violet Sparknado | Talent | Enhance |
| `technique` | `120207` | Gentle Breeze | Technique | Support |

## Ability records

### Dislodged

```json
{
  "ability_id": "120201",
  "slot": "basic",
  "name": "Dislodged",
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
  "description_sha256": "b71aa63bbd86fa94248496c5d3af35cc7b9ac298fe41a84410d4a64519166971",
  "icon_path": "icon/skill/1202_basic_atk.png"
}
```

### Soothing Melody

```json
{
  "ability_id": "120202",
  "slot": "skill",
  "name": "Soothing Melody",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Lightning",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
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
    "p1": {
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 16,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 17,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 19,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        },
        "p2": {
          "value": 40.63,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 43.75,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 46.88,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 40,
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
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 27,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 46,
          "unit": "percent"
        },
        "p2": {
          "value": 57.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 29,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a9d0c992a5fb0bbe0ea93594eff450ea62947adc0ac1c6007aef10a8b68b8aaa",
  "icon_path": "icon/skill/1202_skill.png"
}
```

### Amidst the Rejoicing Clouds

```json
{
  "ability_id": "120203",
  "slot": "ult",
  "name": "Amidst the Rejoicing Clouds",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 23,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 29,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 38.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 42.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 46.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
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
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 53,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 59,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 62,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "201243f1e22b2dfc3374e54f6356c9fa654ed29b080f2bffbec8ec702ef28845",
  "icon_path": "icon/skill/1202_ultimate.png"
}
```

### Violet Sparknado

```json
{
  "ability_id": "120204",
  "slot": "talent",
  "name": "Violet Sparknado",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 48.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 56.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 66,
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
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 72,
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
        }
      }
    }
  ],
  "description_sha256": "5e5bcdf41393e434111f5cd5acf1506fcd412ef42637ae0d46f1b9fbf62fc6c3",
  "icon_path": "icon/skill/1202_talent.png"
}
```

### Gentle Breeze

```json
{
  "ability_id": "120207",
  "slot": "technique",
  "name": "Gentle Breeze",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "35bd1ab21f9933b4081f8998c2cd8057bdd0cd6ad1d829a662b9635b0a79d38f",
  "icon_path": "icon/skill/1202_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Nourished Joviality",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "20%",
      "1"
    ],
    "description_sha256": "600b8d989f8fbb3b3ea88eeb9b9fd44f5a729e2d8e5181caa29cab160483be6b"
  },
  {
    "requirement": "A4",
    "name": "Knell Subdual",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "ced3785ab27c32af1149df54dca96a8495387e20c46854a6aa173ec5bf2b9d12"
  },
  {
    "requirement": "A6",
    "name": "Jubilant Passage",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "d9de202bef73b28738cf2bfd9a23cbb8ccf73cfe36d7034d7b26dfd155390ab9"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Windfall of Lucky Springs",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "20%",
      "1"
    ],
    "description_sha256": "338170b8a8359f48440bc5ca87520acb15ccae6051321aa0127f6bf8312bce6f"
  },
  {
    "eidolon": 2,
    "name": "Gainfully Gives, Givingly Gains",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "0ac40c05f7f4a79ae873993143ffdc3a2432a1afc745d89d8698256aaab35c4e"
  },
  {
    "eidolon": 3,
    "name": "Halcyon Bequest",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "2",
      "15",
      "1",
      "10"
    ],
    "description_sha256": "ef41c0ce13bfa86071ef69fe2f437f6e8c5c3a055a9891381b35b408b406063e"
  },
  {
    "eidolon": 4,
    "name": "Jovial Versatility",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "83b8202d3a80e3964ed8fc61d1d637324164cc4591aaff5ac4e568119fbe9810"
  },
  {
    "eidolon": 5,
    "name": "Sauntering Coquette",
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
    "name": "Peace Brings Wealth to All",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "10"
    ],
    "description_sha256": "27bb37992390c2fe5beace03d4dd3fc9aef55bf192d1726587a3b6947089536b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
