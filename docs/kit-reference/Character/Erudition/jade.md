---
schema_version: "1.0.0"
unit_id: 55
name: "Jade"
slug: "jade"
rarity: 5
element: "Quantum"
path: "Erudition"
role: "Sub DPS"
affiliation: "IPC"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/jade"
source_record_updated_at: "January 25th, 2025"
dataset_snapshot: "2026-05-30"
---

# Jade

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Jade.h` |
| ธาตุ | **Quantum** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

### Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 509 · SPD 103

> Erudition FUA DPS สาย Charge/Pawned Asset + "Debt Collector"

---

### Basic ATK — Lash of Riches (Blast, Lv.6)
- Quantum DMG หลัก = **90% ATK**, ข้างเคียง = **30% ATK**
- Energy +20 · Toughness 10 (+5)

### Skill — Acquisition Surety (Support, Lv.10)
- ทำให้เพื่อน 1 ตัวเป็น **Debt Collector** + SPD **+30** นาน 3 เทิร์น
- หลัง Debt Collector โจมตี → Jade สร้าง Additional Quantum DMG = **25% ATK** ต่อศัตรูที่โดน 1 instance + กิน HP ของ Debt Collector = **2% Max HP** (ไม่พอ → HP = 1)
- ถ้า Jade เป็น Debt Collector เอง → ไม่ได้ SPD boost และการโจมตีไม่กิน HP
- ขณะมี Debt Collector ในสนาม Jade ใช้ Skill ไม่ได้; ต้นเทิร์นของ Jade → duration ลด 1
- Energy +30

### Ultimate — Vow of the Deep (AoE, 140 energy, Lv.10)
- Quantum DMG = **240% ATK** AoE
- เสริม follow-up attack จาก Talent: +multiplier **80%** (activate ได้ 2 ครั้ง)
- Energy +5 · Toughness 20

### Talent — Fang of Flare Flaying (AoE, Lv.10)
- หลัง Jade หรือเพื่อนที่เป็น/เคยเป็น Debt Collector โจมตี → Jade ได้ **Charge +1 ต่อศัตรูที่โดน**
- Charge ถึง **8** → กิน 8, ยิง follow-up: Quantum DMG = **120% ATK** AoE (follow-up นี้ไม่สร้าง Charge)
- เมื่อยิง follow-up → Jade ได้ **Pawned Asset +5 stack** (ต่อ stack: CRIT DMG **+2.4%**, สูงสุด 50 stack)
- Energy +10 · Toughness 10

### Technique — Visionary Predation
- ติด Blind Fealty ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Blind Fealty → ศัตรูที่ติดทั้งหมดเข้าฉากพร้อมกัน + Quantum DMG = **50% ATK** AoE + Jade ได้ **Pawned Asset +15 stack** ทันที

---

### Major Traces
- **A2 — Reverse Repo**: ศัตรูเข้าฉาก → Jade Pawned Asset +1. ต้นเทิร์นของเพื่อน Debt Collector → Jade Pawned Asset **+3**
- **A4 — Collateral Ticket**: ต้นการต่อสู้ → Jade action advance **50%**
- **A6 — Asset Forfeiture**: ทุก stack ของ Pawned Asset → Jade ATK **+0.5%**

### Minor Traces (รวมทั้งหมด)
ATK +18% · Quantum DMG +22.4% · Effect RES +10%

### Eidolons
- **E1**: Talent follow-up DMG **+32%**. หลัง Debt Collector โจมตีโดน 2/1 ตัว → Jade Charge **+1/+2**
- **E2**: เมื่อมี Pawned Asset 15 stack → Jade CRIT Rate **+18%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ใช้ Ult → Jade ดาเมจเพิกเฉย DEF **12%** นาน 3 เทิร์น
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: เมื่อมีเพื่อน Debt Collector ในสนาม → Jade Quantum RES PEN **+20%** และ Jade ได้สถานะ Debt Collector ด้วย

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Charge** (0–8): +1 ต่อศัตรูที่โดน หลัง Debt Collector attack (+E1); ครบ 8 → FUA 120% + reset
- **Pawned Asset** (0–50): +5/FUA, +15 Technique, A2 (+1 enter, +3 Debt Collector turn) → CRIT DMG 2.4%/stack, A6 ATK 0.5%/stack, E2 CRIT Rate
- **Debt Collector**: SPD +30 buff (ไม่ได้ถ้าเป็น Jade), heal-tax 2% Max HP/attack, Jade Additional DMG 25% ต่อ hit
- **Ult enhance**: next 2 FUA +80% multiplier
- **A4**: action advance 50% ต้นการต่อสู้ (`Start_game_List`)
- โค้ด: `Start_game_List` (`Jade.h:70`) มี addToActionBar + self-flush `Deal_damage()` — น่าจะเป็น technique DMG

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/jade — kit tab (review/calc patch 3.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 55,
  "name": "Jade",
  "slug": "jade",
  "rarity": "5",
  "element": "Quantum",
  "path": "Erudition",
  "default_role": "Sub DPS",
  "affiliation": "IPC",
  "release_date": "July 10th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 147.84,
    "def_base": 69.3,
    "atk_base": 89.76,
    "speed_base": 103
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 18
    },
    "traceStat2": {
      "stat": "Quantum DMG",
      "value": 22.4
    },
    "traceStat3": {
      "stat": "Effect RES",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Faye Mata",
    "kr": "김순미 (Kim Soon-mi)",
    "jpn": "三石琴乃 (Kotono Mitsuishi)",
    "cn": "张若瑜 (Zhang Ruoyu)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/jade",
  "source_record_updated_at": "January 25th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `131401` | Lash of Riches | Basic ATK | Blast |
| `skill` | `131402` | Acquisition Surety | Skill | Support |
| `ult` | `131403` | Vow of the Deep | Ultimate | AoE |
| `talent` | `131404` | Fang of Flare Flaying | Talent | AoE |
| `technique` | `131407` | Visionary Predation | Technique | Impair |

## Ability records

### Lash of Riches

```json
{
  "ability_id": "131401",
  "slot": "basic",
  "name": "Lash of Riches",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
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
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 81,
          "unit": "percent"
        },
        "p2": {
          "value": 27,
          "unit": "percent"
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
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
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 117,
          "unit": "percent"
        },
        "p2": {
          "value": 39,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "f663768375a3c3cae360fea2f4474d7f6c98cf67f78f20d949a736e3e60941e6",
  "icon_path": "icon/skill/1314_basic_atk.png"
}
```

### Acquisition Surety

```json
{
  "ability_id": "131402",
  "slot": "skill",
  "name": "Acquisition Surety",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "spd",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 19,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 21.25,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 22.5,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 23.75,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 25,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 26,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 27,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 28,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 29,
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
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "05823e59fbffb5b8e2678a5fd6847bd3d2938cd7d0be2b75697cc017b2d18799",
  "icon_path": "icon/skill/1314_skill.png"
}
```

### Vow of the Deep

```json
{
  "ability_id": "131403",
  "slot": "ult",
  "name": "Vow of the Deep",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 156,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 168,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 195,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 210,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 225,
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 252,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 264,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 92,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 276,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 288,
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 300,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c9f4db9696fbac1b42e8a2d0be1cc4a8e4168a173c7fe63de68deef240874809",
  "icon_path": "icon/skill/1314_ultimate.png"
}
```

### Fang of Flare Flaying

```json
{
  "ability_id": "131404",
  "slot": "talent",
  "name": "Fang of Flare Flaying",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "scalar",
      "occurrences": 2
    },
    "p5": {
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
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_dmg",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 1.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1.32,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1.44,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1.56,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1.68,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1.8,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1.95,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 2.1,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 2.25,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 2.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
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
          "value": 2.52,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 2.64,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 2.76,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 138,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 2.88,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        },
        "p5": {
          "value": 150,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7d48f5156e34fd3a65bea45d09a0f0358b7c62f69a137a3043b8ec0893823091",
  "icon_path": "icon/skill/1314_talent.png"
}
```

### Visionary Predation

```json
{
  "ability_id": "131407",
  "slot": "technique",
  "name": "Visionary Predation",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Quantum",
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
    "dmg"
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c48c472944939fdb418ff9455f62e48dd9cc3199eeb8a56f7f82ea076aa33f26",
  "icon_path": "icon/skill/1314_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Reverse Repo",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "3"
    ],
    "description_sha256": "09044f231d037d46b0e008ab3c493e20f3860f103d0e1e4f57359699b903ec16"
  },
  {
    "requirement": "A4",
    "name": "Collateral Ticket",
    "mechanic_tags": [],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "7c91177798a8f689d5f9165167acf7e4efc3b25311726dff0b2dfcd2d834b002"
  },
  {
    "requirement": "A6",
    "name": "Asset Forfeiture",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "0.5%"
    ],
    "description_sha256": "4fe19b8889129b669e0bf55de0f7fc5be27b88ad2e7c75dd85224c598e052e9e"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Altruism? Nevertheless Tradable",
    "mechanic_tags": [
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "32%",
      "2",
      "1",
      "1",
      "2"
    ],
    "description_sha256": "31992e621ce9d8b39133728b0127a2b9aad0ea3783ad2bfb61091391b9acd662"
  },
  {
    "eidolon": 2,
    "name": "Morality? Herein Authenticated",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "15",
      "18%"
    ],
    "description_sha256": "1e6f26988052ddceaa35ad9acb05274e352dfdf3a94f75dd40948b12132da2fd"
  },
  {
    "eidolon": 3,
    "name": "Honesty? Soon Mortgaged",
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
    "name": "Sincerity? Put Option Only",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "12%",
      "3"
    ],
    "description_sha256": "013a41bafde4afdf18519e7587b9cad0699ce2f65c3bef8c43b44ee3ab629aa0"
  },
  {
    "eidolon": 5,
    "name": "Hope? Hitherto Forfeited",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "cc300732b097e46b67b9094ab43cb9e46f3f73b77a0f20c05a0dc575ef066a9d"
  },
  {
    "eidolon": 6,
    "name": "Equity? Pending Sponsorship",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "18bfd986487853d5985ee506c01ca08e5e96678fb95b632e094a122b5e1f85ab"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
