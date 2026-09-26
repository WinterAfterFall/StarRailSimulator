---
schema_version: "1.0.0"
unit_id: 63
name: "Rappa"
slug: "rappa"
rarity: 5
element: "Imaginary"
path: "Erudition"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/rappa"
source_record_updated_at: "March 2nd, 2026"
dataset_snapshot: "2026-05-30"
---

# Rappa

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Rappa.h` |
| ธาตุ | **Imaginary** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.8) |

### Base Stats (Lv.80, ascended)
HP 1087 · ATK 717 · DEF 460 · SPD 96

> Erudition Break DPS สาย Super Break / Sealform

---

### Basic ATK — Ninjutsu: Rise Above Tumbles (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Ningu: Demonbane Petalblade (Blast, Lv.6)
- hit 1–2: Imaginary DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- hit 3: Imaginary DMG = **100% ATK** ใส่ศัตรูทุกตัว
- ไม่คืน Skill Point
- ตีศัตรูที่ไม่มี Imaginary Weakness ยังลด Toughness ได้ = **50% ของปกติ**; เมื่อ Break → trigger Imaginary Weakness Break effect
- Energy +20 · Toughness 25 (+15 ข้างเคียง)

### Skill — Ninja Strike: Rooted Resolute (AoE, Lv.10)
- Imaginary DMG = **120% ATK** AoE
- Energy +30 · Toughness 10

### Ultimate — Nindō Supreme: Aishiteru (Enhance, 140 energy, Lv.10)
- เข้าสถานะ **"Sealform"**, ได้เทิร์นพิเศษทันที, ได้ **"Chroma Ink" 3 แต้ม**, Weakness Break Efficiency **+50%**, Break Effect **+30%**
- ขณะ Sealform: Basic ATK enhanced, ใช้ Skill/Ult ไม่ได้; หลัง Enhanced BA → กิน Chroma Ink 1 แต้ม; Chroma Ink หมด → ออกจาก Sealform
- Energy +5

### Talent — Ninja Tech: Endurance Gauge (Lv.10)
- ทุกครั้งศัตรู Weakness Broken → Rappa Charge **+1** (สูงสุด 10)
- hit ที่ 3 ของ Ningu: Demonbane Petalblade ครั้งถัดไป → เพิ่ม Break DMG = **60% ของ Imaginary Break DMG ของ Rappa** AoE
  - ดาเมจนี้ลด Toughness ได้โดยไม่สน Weakness type = 2; กิน Charge ทั้งหมด
  - ต่อ 1 Charge → Break DMG multiplier **+50%** + ignore-weakness Toughness Reduction **+1**
- Toughness 2

### Technique — Wisps of Aurora
- เข้าฉากโดยตีศัตรู: ลด Toughness 30 โดยไม่สน Weakness type + Break DMG = **200% ของ Imaginary Break DMG** ต่อศัตรู, ข้างเคียง = **180%**
- คืน Energy **10**
- Toughness 10

---

### Major Traces
- **A2 — Sky High**: ศัตรู elite+ ถูก Weakness Broken → Rappa Charge **+1** + คืน Energy **10**
- **A4 — Sea Echo**: ขณะ Sealform หลัง Enhanced BA ตีศัตรู Weakness Broken → แปลง Toughness Reduction ของ instance นั้นเป็น **Super Break DMG 60%** 1 instance
- **A6 — Withered Leaf**: ศัตรู Weakness Broken → รับ Break DMG **+2%**; ถ้า ATK > 2400 ต่อ 100 ส่วนเกิน → **+1%** สูงสุด **+8%** (นาน 2 เทิร์น)

### Minor Traces (รวมทั้งหมด)
ATK +28% · SPD +9 · Break Effect +13.3%

### Eidolons
- **E1**: ขณะ Sealform จาก Ult → ดาเมจเพิกเฉย DEF **15%**. ออกจาก Sealform → คืน Energy **20**
- **E2**: Enhanced BA hit 1–2 → Toughness Reduction ใส่เป้าหมายหลัก **+50%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Sealform → เพื่อนทุกคน SPD **+12%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: ต้นการต่อสู้ → Charge **+5** + cap **+5**. หลัง hit ที่ 3 ของ Ningu → Charge **+5**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Imaginary Break DMG** เป็นฐานคำนวณ Talent/Technique (ต้องมี break dmg model)
- **Sealform**: Chroma Ink 3 (E ไม่เพิ่ม), Enhanced BA กิน 1/ครั้ง, extra turn ตอนเข้า, +50% WBE +30% BE
- **Charge** (0–10, E6 15): +1 ต่อ enemy break + A2 (elite +1) + E6; ปลดที่ hit 3 → Break DMG 60% × (1 + 0.5×Charge) AoE + ignore-weakness toughness
- **A4 Super Break** ตอน Sealform ตี broken target
- Enhanced BA ไม่คืน SP, break weakness ได้แม้ไม่มี Imaginary weakness (50% toughness)
- โค้ด: `Start_game_List` priority `PRIORITY_ACTTACK` (`Rappa.h:140`) + `Rappa_LC.h` มี Start_game entry ด้วย

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/rappa — kit tab (review patch 3.0, calc patch 3.8, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 63,
  "name": "Rappa",
  "slug": "rappa",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Erudition",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "October 23rd, 2024",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 148,
    "def_base": 62.7,
    "atk_base": 97.68,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "speed",
      "value": 9
    },
    "traceStat3": {
      "stat": "Break Effect",
      "value": 13.3
    }
  },
  "voice_actors": {
    "en": "Kendell Byrd ",
    "kr": "Kim Yurim (김유림)",
    "jpn": "Han Megumi (潘めぐみ)",
    "cn": "Jin Na (金娜)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/rappa",
  "source_record_updated_at": "March 2nd, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `131701` | Ninjutsu: Rise Above Tumbles | Basic ATK | Single Target |
| `basic_enh` | `131709` | Ningu: Demonbane Petalblade | Basic ATK | Blast |
| `skill` | `131702` | Ninja Strike: Rooted Resolute | Skill | AoE |
| `ult` | `131703` | Nindō Supreme: Aishiteru | Ultimate | Enhance |
| `talent` | `131704` | Ninja Tech: Endurance Gauge | Talent | Enhance |
| `technique` | `131707` | Wisps of Aurora | Technique | Support |

## Ability records

### Ninjutsu: Rise Above Tumbles

```json
{
  "ability_id": "131701",
  "slot": "basic",
  "name": "Ninjutsu: Rise Above Tumbles",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
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
  "description_sha256": "7be1dab2c0e8d883dd953743c1a2800155c33c6617310cf87f4a4178298f5161",
  "icon_path": null
}
```

### Ningu: Demonbane Petalblade

```json
{
  "ability_id": "131709",
  "slot": "basic_enh",
  "name": "Ningu: Demonbane Petalblade",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "75",
  "toughness_break_secondary_source": "45",
  "source_max_level": 9,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "break_effect",
    "dmg",
    "toughness",
    "weakness",
    "skill_points"
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
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 76,
          "unit": "percent"
        },
        "p2": {
          "value": 38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 92,
          "unit": "percent"
        },
        "p2": {
          "value": 46,
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
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 116,
          "unit": "percent"
        },
        "p2": {
          "value": 58,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 124,
          "unit": "percent"
        },
        "p2": {
          "value": 62,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "99dc0c2ccc3cf1c8260d89c166a3520f8425f7efb04c9e38b3ca58f28d87c418",
  "icon_path": null
}
```

### Ninja Strike: Rooted Resolute

```json
{
  "ability_id": "131702",
  "slot": "skill",
  "name": "Ninja Strike: Rooted Resolute",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Imaginary",
  "energy_gain": "30",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 84,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 112.5,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "35a6b0ae4da502f861261f891a4d170bacc51510560466f94e4295fcb6da6abc",
  "icon_path": null
}
```

### Nindō Supreme: Aishiteru

```json
{
  "ability_id": "131703",
  "slot": "ult",
  "name": "Nindō Supreme: Aishiteru",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
    "break_effect",
    "weakness_break_efficiency",
    "weakness"
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
          "value": 12,
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
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16,
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
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "91b0ecb99d57008025d765cd080349c915e9deeda64bd34bd674f7072fdaf19e",
  "icon_path": null
}
```

### Ninja Tech: Endurance Gauge

```json
{
  "ability_id": "131704",
  "slot": "talent",
  "name": "Ninja Tech: Endurance Gauge",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "6",
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
          "value": 30,
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
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
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
        },
        "p2": {
          "value": 30,
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
        },
        "p2": {
          "value": 32.5,
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
        },
        "p2": {
          "value": 35,
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
        },
        "p2": {
          "value": 37.5,
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
        },
        "p2": {
          "value": 40.625,
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
        },
        "p2": {
          "value": 43.75,
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
        },
        "p2": {
          "value": 46.875,
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
        },
        "p2": {
          "value": 50,
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
        },
        "p2": {
          "value": 52.5,
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
        },
        "p2": {
          "value": 55,
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
        },
        "p2": {
          "value": 57.5,
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
        },
        "p2": {
          "value": 60,
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
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "581fa6cad84603a5c31faa957542679de6c75be46c0238603dd83acb9f7f4a39",
  "icon_path": null
}
```

### Wisps of Aurora

```json
{
  "ability_id": "131707",
  "slot": "technique",
  "name": "Wisps of Aurora",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "energy",
    "dmg",
    "toughness",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8b1fde2c2b6f4fd6a8778fed516270091d2f4c862d1e3d848e8e659d3f95f20c",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Ninjutsu Inscription: Sky High",
    "mechanic_tags": [
      "energy",
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "10"
    ],
    "description_sha256": "4b094fa066913a8053b074b19f6667df9ab62bc63fdd677a4ba49170653b2b8f"
  },
  {
    "requirement": "A4",
    "name": "Ninjutsu Inscription: Sea Echo",
    "mechanic_tags": [
      "atk",
      "dmg",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "60%"
    ],
    "description_sha256": "2b1db205dbd17d79a3ae73f8abe0e75e125b5e54d41671a9ef6c4a2da6182d0b"
  },
  {
    "requirement": "A6",
    "name": "Ninjutsu Inscription: Withered Leaf",
    "mechanic_tags": [
      "atk",
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "2%",
      "2400",
      "100",
      "1%",
      "8%",
      "2"
    ],
    "description_sha256": "f0132e71801a406436e2df6196a4dc1cc771f80889dc4d5e24bdf9c4d3c6edb8"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Returned Is the Revenant With No Ferry Toll",
    "mechanic_tags": [
      "def",
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "20"
    ],
    "description_sha256": "2f5d3f32dd73628eb024f954bc5b2c161191a6e505ab9dd9e0c9ec7e71b86cc9"
  },
  {
    "eidolon": 2,
    "name": "Free Is the Mind Enlightened by Haikus",
    "mechanic_tags": [
      "atk",
      "toughness"
    ],
    "numeric_tokens": [
      "2",
      "50%"
    ],
    "description_sha256": "2b630ae1e4a8408a82c8097b4288da44d9dd37fcca9585f814ec11639ef1e56b"
  },
  {
    "eidolon": 3,
    "name": "Many Are the Shrines That Repel No Hell",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a13cfabe952f8b0ba721dae6b62a903cc39e4f5027181a39a15d220998ab9d0b"
  },
  {
    "eidolon": 4,
    "name": "Lost Is the Nindō Devoured by Time",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "12%"
    ],
    "description_sha256": "ec9f3909e74b63962e3e8af49c195ee55a68cb4a6fe1279502bcbec8a057f782"
  },
  {
    "eidolon": 5,
    "name": "Steady Is The Ranger With Unerring Arrows",
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
    "name": "Righteous Is the Wrath That Spares No Evil",
    "mechanic_tags": [],
    "numeric_tokens": [
      "5",
      "5",
      "5"
    ],
    "description_sha256": "a8544a8dce39dbfdc9b400dd939664b55c20ccf77155159394896876a054cafe"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
