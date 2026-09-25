---
schema_version: "1.0.0"
unit_id: 51
name: "Gallagher"
slug: "gallagher"
rarity: 4
element: "Fire"
path: "Abundance"
role: "Healer"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/gallagher"
source_record_updated_at: "April 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Gallagher

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Gallagher.h` |
| ธาตุ | **Fire** |
| Path | **Abundance** |
| ระดับ | 4★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1305 · ATK 529 · DEF 441 · SPD 98

---

### Basic ATK — Corkage Fee (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Nectar Blitz (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **250% ATK** ใส่ศัตรู 1 ตัว
- ลด ATK เป้าหมาย **15%** นาน 2 เทิร์น
- Energy +20 · Toughness 30

### Skill — Special Brew (ฮีล, Lv.10)
- ฮีลเพื่อนเป้าหมายทันที **1600 HP** (ค่า flat, Lv.10)
- Energy +30 · ไม่มี Toughness

### Ultimate — Champagne Etiquette (AoE, 110 energy, Lv.10)
- ติด **Besotted** ให้ศัตรูทุกตัว นาน 2 เทิร์น
- Fire DMG = **150% ATK** ให้ศัตรูทุกตัว
- เปลี่ยน Basic ATK ครั้งถัดไปของ Gallagher เป็น **Nectar Blitz**
- Energy +5 · Toughness 20

### Talent — Tipsy Tussle (Lv.10)
- สถานะ **Besotted** ทำให้เป้าหมายรับ **Break DMG +12%**
- ทุกครั้งที่เป้าหมาย Besotted ถูกเพื่อนโจมตี → ผู้โจมตีถูกฮีล **640 HP**

### Technique — Artisan Elixir
- เข้าฉากแล้วโจมตีศัตรูทันที: ติด Besotted ให้ศัตรูทุกตัวนาน 2 เทิร์น + Fire DMG = **50% ATK** AoE
- Toughness 20

---

### Major Traces
- **A2 — Novel Concoction**: +Outgoing Healing เท่ากับ **50% ของ Break Effect** สูงสุด **+75%**
- **A4 — Organic Yeast**: หลังใช้ Ultimate → **Advance Forward 100%** ทันที
- **A6 — Bottoms Up**: เมื่อ Gallagher ใช้ Nectar Blitz ตีศัตรูที่ Besotted → เอฟเฟกต์ฮีลจาก Talent ครั้งนั้นจะ**ใช้กับเพื่อนคนอื่นด้วย**

### Minor Traces (รวมทั้งหมด)
Effect RES +28% · Break Effect +13.3% · HP +18%

### Eidolons
- **E1 — Salty Dog**: เข้าการต่อสู้ → คืน Energy **20** + Effect RES **+50%**
- **E2 — Lion's Tail**: ใช้ Skill → ลบ debuff 1 อันจากเป้าหมาย + Effect RES **+30%** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Last Word**: ยืดเวลา Besotted จาก Ultimate อีก **1 เทิร์น** (รวม 3)
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — Blood and Sand**: Break Effect **+20%** + Weakness Break Efficiency **+20%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **A2 Healing**: outgoing healing = min(50% × BreakEffect, 75%) — ผูกกับ Break Effect ปัจจุบัน ต้อง re-eval (โค้ดใช้ `calculateBreakEffectForBuff` + cap 75 + `buffNote["Novel Concoction"]`)
- **Skill / Talent heal เป็นค่า flat** (1600 / 640) ไม่สเกลกับ HP → แต่รับผลจาก outgoing healing % ของ Gallagher
- **Besotted** เป็น debuff ที่ให้ทั้ง Break-DMG-taken +12% (Talent) และเป็นทริกเกอร์ heal-on-hit
- **Enhanced BA**: Ult set flag ให้ BA ถัดไปเป็น Nectar Blitz (250%, +Besotted-ATK-down 15%/2t, Toughness 30)
- **A6**: heal-on-hit ของ Talent ครั้งที่ Nectar Blitz ตี Besotted → กระจายเป็น AoE heal (โค้ดเช็ค `buffCheck["Gallagher_enchance_basic_atk"]`)
- **A4**: action advance 100% หลัง Ult
- E1 (+20 energy, +50% RES) trigger ตอนเข้าสนาม — ในโค้ดอยู่ที่ `Start_game_List` (เฉพาะ E1) และ `WhenOnField_List` (Besotted tech + A2 buff)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/gallagher — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 51,
  "name": "Gallagher",
  "slug": "gallagher",
  "rarity": "4",
  "element": "Fire",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": null,
  "release_date": "March 27th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 177.6,
    "def_base": 60,
    "atk_base": 72,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Effect RES",
      "value": 28
    },
    "traceStat2": {
      "stat": "Break Effect",
      "value": 13.3
    },
    "traceStat3": {
      "stat": "HP",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Erik Braa",
    "kr": "박상훈 (Park Sang-Hoon)",
    "jpn": "三上哲 (Mikami Satohshi)",
    "cn": "马语非 (Ma Yufei)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/gallagher",
  "source_record_updated_at": "April 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150001` | Corkage Fee | Basic ATK | Single Target |
| `basic_enh` | `150008` | Nectar Blitz | Basic ATK | Single Target |
| `skill` | `150002` | Special Brew | Skill | Restore |
| `ult` | `150003` | Champagne Etiquette | Ultimate | AoE |
| `talent` | `150004` | Tipsy Tussle | Talent | Enhance |
| `technique` | `150007` | Artisan Elixir | Technique | - |

## Ability records

### Corkage Fee

```json
{
  "ability_id": "150001",
  "slot": "basic",
  "name": "Corkage Fee",
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
  "description_sha256": "e2f903f741d111e6f95ae6ca255295fa9a13bbb75717a8d4b86b7b0f15405985",
  "icon_path": "icon/skill/1306_basic_atk.png"
}
```

### Nectar Blitz

```json
{
  "ability_id": "150008",
  "slot": "basic_enh",
  "name": "Nectar Blitz",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "90",
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
          "value": 125,
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
          "value": 150,
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
          "value": 175,
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
          "value": 200,
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
          "value": 225,
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
          "value": 250,
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
          "value": 275,
          "unit": "percent"
        },
        "p2": {
          "value": 16,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
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
          "value": 100,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fb468ef95b6913606c5b8ec1034f7e24ca87c688b444d6f82a3fa5e79f4d5c7c",
  "icon_path": "icon/skill/1306_basic_atk.png"
}
```

### Special Brew

```json
{
  "ability_id": "150002",
  "slot": "skill",
  "name": "Special Brew",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
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
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 340,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 676,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 830,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 984,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1138,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1292,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1446,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1600,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1684,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1768,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f02c200a86d26e980026b683dfcb42b1d693559b7c3ae0b446306f60a505c226",
  "icon_path": "icon/skill/1306_skill.png"
}
```

### Champagne Etiquette

```json
{
  "ability_id": "150003",
  "slot": "ult",
  "name": "Champagne Etiquette",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 140.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 100,
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
        }
      }
    }
  ],
  "description_sha256": "aaa61a3bab1cce80dbf11d5f5f1a74534f1a21843318e9aaeea876c996252078",
  "icon_path": "icon/skill/1306_ultimate.png"
}
```

### Tipsy Tussle

```json
{
  "ability_id": "150004",
  "slot": "talent",
  "name": "Tipsy Tussle",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
  "energy_gain": null,
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 6.6,
          "unit": "percent"
        },
        "p2": {
          "value": 136,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 192,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 7.8,
          "unit": "percent"
        },
        "p2": {
          "value": 270.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 332,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 393.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 9.75,
          "unit": "percent"
        },
        "p2": {
          "value": 455.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 516.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 11.25,
          "unit": "percent"
        },
        "p2": {
          "value": 578.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 640,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 12.6,
          "unit": "percent"
        },
        "p2": {
          "value": 673.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 707.2,
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
          "value": 1,
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
          "value": 1,
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
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "00315eeec5528e0b4972c32a85cf18cb68e3807c21a26b300aff775ad8507752",
  "icon_path": "icon/skill/1306_talent.png"
}
```

### Artisan Elixir

```json
{
  "ability_id": "150007",
  "slot": "technique",
  "name": "Artisan Elixir",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": null,
  "targeting_label": null,
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
    }
  ],
  "description_sha256": "9b25210027742d9a79c0c37cba8d93fcb626772e679ec9e8c9451edb9cac126e",
  "icon_path": "icon/skill/1306_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Novel Concoction",
    "mechanic_tags": [
      "break_effect",
      "healing"
    ],
    "numeric_tokens": [
      "50%",
      "75%"
    ],
    "description_sha256": "8f58656c0f4bc07722850d356acafac193f09f300375e7bb710ffb6e2e2e5731"
  },
  {
    "requirement": "A4",
    "name": "Organic Yeast",
    "mechanic_tags": [
      "action_advance"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "a7bc97976fb1cfe8babc81f6ea9ad690d1ddc7e1b396a890577a662f4023ba56"
  },
  {
    "requirement": "A6",
    "name": "Bottoms Up",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [],
    "description_sha256": "4ebabfb267a612ddcd4171bea0dcad025ffa89a7d6ecc91adf85b9998584508b"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Salty Dog",
    "mechanic_tags": [
      "effect_res",
      "energy",
      "res"
    ],
    "numeric_tokens": [
      "20",
      "50%"
    ],
    "description_sha256": "01b0331adb9c9e3352006da04cb5c4887ebc8a90b7773b92b0bd7e86dc2591bf"
  },
  {
    "eidolon": 2,
    "name": "Lion's Tail",
    "mechanic_tags": [
      "effect_res",
      "res",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1",
      "30%",
      "2"
    ],
    "description_sha256": "faa9fd4492aef7f54da5ddf4a95fde81dc8f64231dc8e2ad044bc1c53ebb75aa"
  },
  {
    "eidolon": 3,
    "name": "Corpse Reviver",
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
    "name": "Last Word",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "bd807100b638b561db467381b7c8ec12bf74654cd823ea604ad64aafde0ab428"
  },
  {
    "eidolon": 5,
    "name": "Death in the Afternoon",
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
    "name": "Blood and Sand",
    "mechanic_tags": [
      "break_effect",
      "weakness_break_efficiency",
      "weakness"
    ],
    "numeric_tokens": [
      "20%",
      "20%"
    ],
    "description_sha256": "85f48e6abe72925ec492dac9d3aff632067e2d44789af37eedf4497a8c1ac485"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
