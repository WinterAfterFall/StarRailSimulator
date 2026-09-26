---
schema_version: "1.0.0"
unit_id: 46
name: "Black Swan"
slug: "black-swan"
rarity: 5
element: "Wind"
path: "Nihility"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/black-swan"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Black Swan

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Black Swan.h` (เวอร์ชันเก่า `Black SwanV1.h` — ข้าม) |
| ธาตุ | **Wind** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 485 · SPD 102

> Nihility DoT DPS สาย "Arcana" stack

---

### Basic ATK — Percipience, Silent Dawn (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Decadence, False Twilight (Blast, Lv.10)
- Wind DMG = **90% ATK** ใส่เป้าหมาย + ข้างเคียง
- 100% base chance ลด DEF เป้าหมาย + ข้างเคียง **20.8%** นาน 3 เทิร์น
- Energy +30 · Toughness 20 (+10)

### Ultimate — Bliss of Otherworld's Embrace (AoE, 120 energy, Lv.10)
- ติด **"Epiphany"** ศัตรูทุกตัว นาน 2 เทิร์น → Wind DMG = **120% ATK** AoE
- ขณะ Epiphany: ศัตรูรับดาเมจเพิ่ม **+25%**; ต่อ 1 stack ของ Arcana ที่ยัด → 50% fixed chance เพิ่มจำนวน stack อีก 1; Arcana ไม่ถูกหาร 2 หลังสร้างความเสียหายต้นเทิร์น
- Energy +5 · Toughness 20

### Talent — Loom of Fate's Caprice (Lv.10)
- ทุกครั้งศัตรูรับ 1 instance ของ DoT → 65% base chance ติด **"Arcana" 1 stack**
- ขณะติด Arcana: ถือว่าติด Wind Shear + Bleed + Burn + Shock พร้อมกัน
- ต้นทุกเทิร์น: Wind DoT = **240% ATK** จากนั้น stack ถูกหาร 2; ต่อ 1 stack ของ Arcana → multiplier **+12%**
- Arcana stack ได้ **50** (เกินได้ ส่วนเกินหายหลังสร้างความเสียหาย)
- ดาเมจ Arcana เพิกเฉย DEF **20%**; เมื่อ Arcana สร้างความเสียหายต้นเทิร์นของศัตรู → ข้างเคียงรับ Wind DoT เพิ่ม **180% ATK** 1 instance
- Energy +5

### Technique — From Façade to Vérité
- หลังใช้ Technique → 150% base chance ติด Arcana 1 stack ให้ศัตรูแต่ละตัวต้นการต่อสู้; ยัดซ้ำเรื่อย ๆ จนล้มเหลว (base chance ครั้งถัดไป = 50% ของครั้งก่อนที่สำเร็จ)

---

### Major Traces
- **A2 — Viscera's Disquiet**: เมื่อ Black Swan โจมตีศัตรู → 65% base chance ติด Arcana **5 stack**
- **A4 — Goblet's Dredges**: ศัตรูเข้าฉาก → 65% base chance ติด Arcana 1 stack + 100% base chance ติด DEF reduction จาก Skill 3 เทิร์น. หลัง BA/Ult → 100% base chance ติด DEF reduction จาก Skill
- **A6 — Candleflame's Portent**: เพื่อนทุกคน +DMG = **60% ของ Effect Hit Rate ของ Black Swan** สูงสุด **+72%**

### Minor Traces (รวมทั้งหมด)
ATK +28% · Wind DMG +14.4% · Effect HIT Rate +10%

### Eidolons
- **E1**: ขณะ Black Swan active → ศัตรูที่ติด Wind Shear/Bleed/Burn/Shock → ลด Wind/Physical/Fire/Lightning RES ตามลำดับ **25%**
- **E2**: ศัตรูเข้าฉาก → 100% base chance ติด Arcana **30 stack**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Epiphany → ศัตรูรับดาเมจเพิ่ม **+20%** เพิ่ม. ต้นทุกเทิร์น/เมื่อศัตรูตาย → คืน Energy **8**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: cap Arcana **+30**. เมื่อเพื่อนโจมตีศัตรู → 65% base chance ติด Arcana 1 stack. ทุก 1 stack ของ Arcana ที่ Black Swan ยัด → เพิ่มจำนวน stack ครั้งนั้นอีก 1

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Arcana** = DoT stack แกน: DoT = 240% ATK × (1 + 0.12×stack) ต้นเทิร์น, หาร 2 หลังลง (ยกเว้น Epiphany); cap 50 (E6 80); เพิกเฉย DEF 20%
- **แหล่ง Arcana**: DoT tick (65%), A2 (BS attack 65% → 5 stack), A4 (enter 65%), E2 (enter 30), E6 (ally attack 65%), Technique (cascade), Ult (50% double)
- **Epiphany (Ult)**: vulnerability +25% (E4 +20%) + Arcana ไม่หาร 2 + double-chance
- **Talent adjacent**: 180% ATK DoT ให้ข้างเคียงตอน Arcana tick ต้นเทิร์นศัตรู
- **A6**: DMG amp ทีมจาก EHR ของ BS (cap 72%) — EHR เป็น stat สำคัญ
- โค้ด: `Start_game_List` (`Black Swan.h:147`, `bs`)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/black-swan — kit tab (review/calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 46,
  "name": "Black Swan",
  "slug": "black-swan",
  "rarity": "5",
  "element": "Wind",
  "path": "Nihility",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "February 6th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 147.84,
    "def_base": 66,
    "atk_base": 89.76,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "Wind DMG",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "Effect Hit Rate",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Arryn Zech",
    "kr": "김하영 (Kim Ha-Young)",
    "jpn": "生天目仁美 (Hitomi Nabatame)",
    "cn": "杨梦露 (Yang Menglu)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/black-swan",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130701` | Percipience, Silent Dawn | Basic ATK | Single Target |
| `skill` | `130702` | Decadence, False Twilight | Skill | Blast |
| `ult` | `130703` | Bliss of Otherworld's Embrace | Ultimate | AoE |
| `talent` | `130704` | Loom of Fate's Caprice | Talent | Impair |
| `technique` | `130707` | From Façade to Vérité | Technique | Enhance |

## Ability records

### Percipience, Silent Dawn

```json
{
  "ability_id": "130701",
  "slot": "basic",
  "name": "Percipience, Silent Dawn",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "0757c6c911056d7e4f600a526000a4d064edc1b38883f9a7ede9e6fbbbb247ea",
  "icon_path": "icon/skill/1307_basic_atk.png"
}
```

### Decadence, False Twilight

```json
{
  "ability_id": "130702",
  "slot": "skill",
  "name": "Decadence, False Twilight",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Wind",
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
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
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
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 14.8,
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
          "value": 49.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 15.4,
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
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 16,
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
          "value": 58.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 16.6,
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
          "value": 63,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 17.2,
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
          "value": 67.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 17.8,
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
          "value": 73.12,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 18.55,
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
          "value": 78.75,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 19.3,
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
          "value": 84.38,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 20.05,
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
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 20.8,
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
          "value": 94.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 21.4,
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
          "value": 99,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 22,
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
          "value": 103.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 22.6,
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
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.2,
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
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 23.8,
          "unit": "percent"
        },
        "p5": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "4a91d2a3f157f881a781b84472fdcf989477ec49cffafc026c4a357be84d48bd",
  "icon_path": "icon/skill/1307_skill.png"
}
```

### Bliss of Otherworld's Embrace

```json
{
  "ability_id": "130703",
  "slot": "ult",
  "name": "Bliss of Otherworld's Embrace",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Wind",
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
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 17,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 19,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 21.25,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 22.5,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 23.75,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 25,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 26,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 27,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 28,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 29,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f74d2f3ddea3167a5fa2f086a1618308ba3a79ff664992fcb0e02a0c1d2f5cf9",
  "icon_path": "icon/skill/1307_ultimate.png"
}
```

### Loom of Fate's Caprice

```json
{
  "ability_id": "130704",
  "slot": "talent",
  "name": "Loom of Fate's Caprice",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Wind",
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
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
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
          "value": 96,
          "unit": "percent"
        },
        "p3": {
          "value": 4.8,
          "unit": "percent"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 51.5,
          "unit": "percent"
        },
        "p2": {
          "value": 111.84,
          "unit": "percent"
        },
        "p3": {
          "value": 5.592,
          "unit": "percent"
        },
        "p4": {
          "value": 83.88,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 53,
          "unit": "percent"
        },
        "p2": {
          "value": 127.68,
          "unit": "percent"
        },
        "p3": {
          "value": 6.384,
          "unit": "percent"
        },
        "p4": {
          "value": 95.76,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 54.5,
          "unit": "percent"
        },
        "p2": {
          "value": 143.52,
          "unit": "percent"
        },
        "p3": {
          "value": 7.176,
          "unit": "percent"
        },
        "p4": {
          "value": 107.64,
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
          "value": 159.36,
          "unit": "percent"
        },
        "p3": {
          "value": 7.968,
          "unit": "percent"
        },
        "p4": {
          "value": 119.52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 57.5,
          "unit": "percent"
        },
        "p2": {
          "value": 175.2,
          "unit": "percent"
        },
        "p3": {
          "value": 8.76,
          "unit": "percent"
        },
        "p4": {
          "value": 131.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 59.375,
          "unit": "percent"
        },
        "p2": {
          "value": 189.6,
          "unit": "percent"
        },
        "p3": {
          "value": 9.48,
          "unit": "percent"
        },
        "p4": {
          "value": 142.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 61.25,
          "unit": "percent"
        },
        "p2": {
          "value": 204,
          "unit": "percent"
        },
        "p3": {
          "value": 10.2,
          "unit": "percent"
        },
        "p4": {
          "value": 153,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 63.125,
          "unit": "percent"
        },
        "p2": {
          "value": 222,
          "unit": "percent"
        },
        "p3": {
          "value": 11.1,
          "unit": "percent"
        },
        "p4": {
          "value": 166.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 240,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 66.5,
          "unit": "percent"
        },
        "p2": {
          "value": 252,
          "unit": "percent"
        },
        "p3": {
          "value": 12.6,
          "unit": "percent"
        },
        "p4": {
          "value": 189,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 264,
          "unit": "percent"
        },
        "p3": {
          "value": 13.2,
          "unit": "percent"
        },
        "p4": {
          "value": 198,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 69.5,
          "unit": "percent"
        },
        "p2": {
          "value": 276,
          "unit": "percent"
        },
        "p3": {
          "value": 13.8,
          "unit": "percent"
        },
        "p4": {
          "value": 207,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 71,
          "unit": "percent"
        },
        "p2": {
          "value": 288,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 216,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 72.5,
          "unit": "percent"
        },
        "p2": {
          "value": 300,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 225,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c6f6d629ecaca402db083b635f9dbaa92f627ba35dec204cdc21164b854eeda3",
  "icon_path": "icon/skill/1307_talent.png"
}
```

### From Façade to Vérité

```json
{
  "ability_id": "130707",
  "slot": "technique",
  "name": "From Façade to Vérité",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
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
  "mechanic_tags": [],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "4971014df71d762167d168ad19f74dfcaf3cba731e858561f2c3e8945dfc32ce",
  "icon_path": "icon/skill/1307_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Viscera's Disquiet",
    "mechanic_tags": [],
    "numeric_tokens": [
      "65%",
      "5"
    ],
    "description_sha256": "e02124a33bedc943163348b0c81235985af329e3ef3accf3e023582bbafc1820"
  },
  {
    "requirement": "A4",
    "name": "Goblet's Dredges",
    "mechanic_tags": [
      "atk",
      "def"
    ],
    "numeric_tokens": [
      "65%",
      "1",
      "100%",
      "3",
      "100%",
      "3"
    ],
    "description_sha256": "60370339b92580317e1e2aba4e1b2734760b8e869922c27e82efc0d119dc12bc"
  },
  {
    "requirement": "A6",
    "name": "Candleflame's Portent",
    "mechanic_tags": [
      "effect_hit_rate",
      "dmg"
    ],
    "numeric_tokens": [
      "60%",
      "72%"
    ],
    "description_sha256": "59376b2226a46ebbc8fff79077ce9df938755ad377ab64c073aba76ded713d60"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Seven Pillars of Wisdom",
    "mechanic_tags": [
      "res",
      "dot"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "f69e503d15aa67bff0088fa2621f92d0d4ffe635c2ee79bb67cbf777993c16a2"
  },
  {
    "eidolon": 2,
    "name": "Weep Not For Me, My Lamb",
    "mechanic_tags": [],
    "numeric_tokens": [
      "100%",
      "30"
    ],
    "description_sha256": "3b451f26eaf7c8c368e952ef79ab98eafe999d08f4e4c6d92415c4c0ce218e64"
  },
  {
    "eidolon": 3,
    "name": "As Above, So Below",
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
    "name": "In Tears We Gift",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "8"
    ],
    "description_sha256": "13c10af90f0c926eab4e239191e825131d5e58b197f1b27929bc65c1d1e004b5"
  },
  {
    "eidolon": 5,
    "name": "Linnutee Flyway",
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
    "name": "Pantheon Merciful, Masses Pitiful",
    "mechanic_tags": [],
    "numeric_tokens": [
      "30",
      "65%",
      "1",
      "1",
      "1"
    ],
    "description_sha256": "d09843ed6b5891b7787cb10452e03d692f4eefde78788e4541857e77a46c6294"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
