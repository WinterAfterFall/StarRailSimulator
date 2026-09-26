---
schema_version: "1.0.0"
unit_id: 86
name: "Sparxie"
slug: "sparxie"
rarity: 5
element: "Fire"
path: "Elation"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/sparxie"
source_record_updated_at: "March 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Sparxie

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Elation/Hibana.h` (namespace `Hibana`) |
| ธาตุ | **Fire** |
| Path | **Elation** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1051 · ATK 640 · DEF 460 · SPD 107

> Sparxie = "the Mask" คู่กับ Sparkle ("the Fool") — Elation DPS สาย Punchline/Thrill

---

### Basic ATK — Cat Got Your Flametongue? (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Bloom! Winner Takes All (Blast, Lv.6)
- จบ livestream: Fire DMG หลัก = **100% ATK**, ข้างเคียง = **50% ATK**
- Energy +40 · Toughness 10 (+5)

### Skill — Boom! Sparxicle's Poppin (Enhance, Lv.10)
- เริ่ม livestream → เปลี่ยน Basic ATK เป็น "Bloom! Winner Takes All" + trigger "Engagement Farming" 1 ครั้ง
- ระหว่างนี้ trigger "Engagement Farming" ซ้ำได้สูงสุด **20 ครั้ง**
- **การใช้ท่านี้ไม่นับเป็นการใช้ Skill**
- Energy +0

### Skill (Enhanced) — Engagement Farming (Enhance, Lv.10)
- ทำให้ "Bloom! Winner Takes All" +multiplier ใส่เป้าหมายหลัก **+20%**, ข้างเคียง **+10%**
- สุ่มได้ของขวัญ 1 อย่าง:
  - **"Straight Fire"**: Punchline +2, Skill Point +2
  - **"Unreal Banger"**: Punchline +1
- ไม่นับเป็นการใช้ Skill

### Ultimate — Party's Wildin' and Camera's Rollin' (AoE, 160 energy, Lv.10)
- Punchline **+2**
- Fire DMG = **(0.6 × Elation + 50%) ATK** ใส่ศัตรูทุกตัว
- Energy +5 · Toughness 20

### Talent — Sleight of Sparx Hand (Lv.10)
- ขณะถือ **"Certified Banger"**:
  - Enhanced BA → **40% Fire Elation DMG** เป้าหมายหลัก + **20%** ข้างเคียง; ต่อ 1 instance ของ "Engagement Farming" ที่ trigger → +1 instance ของ **20% Fire Elation DMG** ใส่ศัตรูสุ่ม
  - Ultimate → **48% Fire Elation DMG** ใส่ศัตรูทุกตัว
- Energy +5

### Technique — The Heart Makes the Finest Tomb
- ติด "Block" ให้ศัตรู 10 วิ
- โจมตีศัตรู Blocked → เข้าฉาก: Fire DMG = **50% ATK** AoE + คืน Skill Point **2** ให้ทีม

### Elation Skill — Signal Overflow: The Great Encore! (AoE, Lv.10)
- **50% Fire Elation DMG** AoE + **20 instance × 25% Fire Elation DMG** ใส่ศัตรูสุ่ม
- Sparxie ได้ **"Thrill" +2** (ใช้หักล้างการกิน Skill Point; การกิน Thrill นับเป็นการกิน Skill Point)
- Energy +5

---

### Major Traces
- **A2 — Sweet! Punchline Signing**: ทุก 100 ATK ที่เกิน **2000** → Elation **+5%** สูงสุด **+80%**
- **A4 — Dazzling! Persona Kaleidoscope**: มีตัวละคร Elation ในทีม 1/2/(3+) → ใช้ Ult ได้ Punchline เพิ่ม **2/4/8** + Thrill **1/1/4**
- **A6 — Frenzy! Palette of Truth and Lies**: ทุก 1 Punchline ที่ถืออยู่ → เพื่อนทุกคน CRIT DMG **+8%** สูงสุด **+80%**

### Minor Traces (รวมทั้งหมด)
Elation +28% · CRIT Rate +12% · CRIT DMG +13.3%

### Eidolons
- **E1**: จบ Aha Instant → Punchline +5. ทุก 1 Punchline → เพื่อนทุกคน All-Type RES PEN **+1.5%** สูงสุด **+15%**
- **E2**: จบ Aha Instant → Sparxie ได้เทิร์นพิเศษ + Thrill +2. ทุก 1 Thrill ที่กิน → Sparxie CRIT DMG **+10%** นาน 2 เทิร์น stack 4 ครั้ง
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Elation Skill Lv. +1
- **E4**: ใช้ Ult → Punchline +5 + Sparxie Elation **+36%** นาน 3 เทิร์น
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Elation Skill Lv. +1
- **E6**: All-Type RES PEN **+20%**. ทุก 1 Punchline ที่ Elation Skill นับ → +1 instance ของ additional DMG สูงสุด **40**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ระบบ Elation (Aha Instant)** — โค้ดมี `elationCount`, `genPunchLine`, `AfterAhaInstant_List` ฯลฯ
- **Punchline** (สะสม): จาก Engagement Farming, Ult(+2), A4, E1/E4 → ป้อน A6 (CRIT DMG ทีม), E1 (RES PEN), E6 (Elation Skill instances)
- **Thrill**: จาก Elation Skill(+2), A4, E2 → ใช้หักล้าง Skill Point consumption
- **Elation stat**: Ult/Talent DMG สเกลกับ Elation (`0.6×Elation + 0.5`); A2 แปลง ATK เกิน 2000 → Elation
- **livestream/Skill** ไม่นับเป็น "การใช้ Skill" (สำคัญต่อ trigger อื่น ๆ ที่นับ skill-use)
- **Engagement Farming** cap 20 ครั้ง/livestream, สุ่ม 2 outcome
- `setAtkRequire(3600)` ในโค้ด — build เป้า ATK

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/sparxie — kit tab (review/calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 86,
  "name": "Sparxie",
  "slug": "sparxie",
  "rarity": "5",
  "element": "Fire",
  "path": "Elation",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "March 3rd, 2026",
  "is_released": true,
  "ultimate_energy_cost": "160",
  "base_stats": {
    "hp_base": 143,
    "def_base": 62.7,
    "atk_base": 87.12,
    "speed_base": 107
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Elation",
      "value": 28
    },
    "traceStat2": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat3": {
      "stat": "CRIT DMG",
      "value": 13.3
    }
  },
  "voice_actors": {
    "en": "Lizzie Freeman",
    "kr": "성예원 (Sung Ye-won)",
    "jpn": "上田丽奈 (Ueda Reina)",
    "cn": "赵爽 (Zhao Shuang)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/sparxie",
  "source_record_updated_at": "March 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150101` | Cat Got Your Flametongue? | Basic ATK | Single Target |
| `basic_enh` | `150109` | Bloom! Winner Takes All | Basic ATK | Blast |
| `skill` | `150102` | Boom! Sparxicle's Poppin | Skill | Enhance |
| `skill_enh` | `150108` | Engagement Farming | Skill | Enhance |
| `ult` | `150103` | Party's Wildin' and Camera's Rollin' | Ultimate | AoE |
| `talent` | `150104` | Sleight of Sparx Hand | Talent | Enhance |
| `technique` | `150107` | The Heart Makes the Finest Tomb | Technique | Impair |
| `supplementary` | `150110` | Signal Overflow: The Great Encore! | Elation Skill | AoE |

## Ability records

### Cat Got Your Flametongue?

```json
{
  "ability_id": "150101",
  "slot": "basic",
  "name": "Cat Got Your Flametongue?",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 10,
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
  "description_sha256": "c128b3cbee59c909187f83ccee2b2a43d2446df391ee33405044e026c554371d",
  "icon_path": null
}
```

### Bloom! Winner Takes All

```json
{
  "ability_id": "150109",
  "slot": "basic_enh",
  "name": "Bloom! Winner Takes All",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": "40",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "15",
  "source_max_level": 10,
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
          "value": 50,
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
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
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
        },
        "p2": {
          "value": 40,
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
        },
        "p2": {
          "value": 45,
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
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
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
        },
        "p2": {
          "value": 60,
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
        },
        "p2": {
          "value": 65,
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
          "value": 70,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2769da00409776e4eef550d907ba645955ff642df046b37549751f7ea4d21f2c",
  "icon_path": null
}
```

### Boom! Sparxicle's Poppin

```json
{
  "ability_id": "150102",
  "slot": "skill",
  "name": "Boom! Sparxicle's Poppin",
  "type_code": "BPSkill",
  "type_label": "Skill",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "33afe61d6629ab29a86d297db1d09e06720b151573d356dd717ccc00ba9d70b5",
  "icon_path": null
}
```

### Engagement Farming

```json
{
  "ability_id": "150108",
  "slot": "skill_enh",
  "name": "Engagement Farming",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
  "energy_gain": "0",
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
    "dmg",
    "skill_points",
    "elation"
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
          "value": 5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        },
        "p2": {
          "value": 5.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
          "unit": "percent"
        },
        "p2": {
          "value": 6.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        },
        "p2": {
          "value": 7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 7.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        },
        "p2": {
          "value": 8.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        },
        "p2": {
          "value": 8.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 18.75,
          "unit": "percent"
        },
        "p2": {
          "value": 9.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 10.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 23,
          "unit": "percent"
        },
        "p2": {
          "value": 11.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 12.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7ebbf32262e636a3eee41e2529ecbf4f00300bd0d7d408d301406e96f0ac51b9",
  "icon_path": null
}
```

### Party's Wildin' and Camera's Rollin'

```json
{
  "ability_id": "150103",
  "slot": "ult",
  "name": "Party's Wildin' and Camera's Rollin'",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "160",
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
    "dmg",
    "elation"
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
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 42.55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 58,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "f23b2c4c465d6216200c3ddf57ad94c5fd60338cccf8ecb5356ce31ab20eee5f",
  "icon_path": null
}
```

### Sleight of Sparx Hand

```json
{
  "ability_id": "150104",
  "slot": "talent",
  "name": "Sleight of Sparx Hand",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
    "p2": {
      "unit": "percent",
      "occurrences": 2
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "elation"
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
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
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
          "value": 11,
          "unit": "percent"
        },
        "p3": {
          "value": 26.4,
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
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 28.8,
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
          "value": 13,
          "unit": "percent"
        },
        "p3": {
          "value": 31.2,
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
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 33.6,
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
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
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
          "value": 16.25,
          "unit": "percent"
        },
        "p3": {
          "value": 39,
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
          "value": 17.5,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
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
          "value": 18.75,
          "unit": "percent"
        },
        "p3": {
          "value": 45,
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
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 48,
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
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 50.4,
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
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 52.8,
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
          "value": 23,
          "unit": "percent"
        },
        "p3": {
          "value": 55.2,
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
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 57.6,
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
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6ed280b5bf38784c0cf04404b46d3f770ce8020be98cafd83ef971cc843c1081",
  "icon_path": null
}
```

### The Heart Makes the Finest Tomb

```json
{
  "ability_id": "150107",
  "slot": "technique",
  "name": "The Heart Makes the Finest Tomb",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c2130744dd11d0565b96608629966cd1f0d31e7440b40038c660425671a9ace5",
  "icon_path": null
}
```

### Signal Overflow: The Great Encore!

```json
{
  "ability_id": "150110",
  "slot": "supplementary",
  "name": "Signal Overflow: The Great Encore!",
  "type_code": "BPSkill",
  "type_label": "Elation Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "skill_points",
    "elation"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 12.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        },
        "p2": {
          "value": 13.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 18.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 40.625,
          "unit": "percent"
        },
        "p2": {
          "value": 20.3125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.75,
          "unit": "percent"
        },
        "p2": {
          "value": 21.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.875,
          "unit": "percent"
        },
        "p2": {
          "value": 23.4375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 57.5,
          "unit": "percent"
        },
        "p2": {
          "value": 28.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
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
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 62.5,
          "unit": "percent"
        },
        "p2": {
          "value": 31.25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a9cee96dd4aa11b7b01ee7eea31e56ad6a47b4dd68fc270103bbfef72008f3a9",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Sweet! Punchline Signing",
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "numeric_tokens": [
      "100",
      "2000",
      "5%",
      "80%"
    ],
    "description_sha256": "467916a002a74a15b0beba3298e5ec742f43b0ed5dc49195c0408ce5afdfa211"
  },
  {
    "requirement": "A4",
    "name": "Dazzling! Persona Kaleidoscope",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "3",
      "2",
      "4",
      "8",
      "1",
      "1",
      "4"
    ],
    "description_sha256": "1f27cf37562ce6fd802fdf6a55aea46ca0a45b00018dbc4d4d9ca85094c48efd"
  },
  {
    "requirement": "A6",
    "name": "Frenzy! Palette of Truth and Lies",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "1",
      "8%",
      "80%"
    ],
    "description_sha256": "3df7b027920f76ba156026f8739b283c8eb464536712c3a1a9e24b9723d82b81"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "#GoingViral #WhoIsShe",
    "mechanic_tags": [
      "res_pen",
      "res",
      "elation"
    ],
    "numeric_tokens": [
      "5",
      "1",
      "1.5%",
      "15%"
    ],
    "description_sha256": "580160a9d1e4fac8009ff1ead8b94f8de805ca00e2869b40b070affab62a4fde"
  },
  {
    "eidolon": 2,
    "name": "#AudienceKnows",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "2",
      "1",
      "10%",
      "2",
      "4"
    ],
    "description_sha256": "329e4e5707a5c6767ea9f8a08df2074ab68b2350cacb85f38dca7993ee98ae0a"
  },
  {
    "eidolon": 3,
    "name": "#LinkUp #HeartSkip",
    "mechanic_tags": [
      "atk",
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "15"
    ],
    "description_sha256": "2c2b0cd806752f685be137d0cd9014f1a7d64e5d125dfe20a0ec8afa7396b8a7"
  },
  {
    "eidolon": 4,
    "name": "#LockedIn #FaceCard",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "5",
      "36%",
      "3"
    ],
    "description_sha256": "04ada43b0bcfb82d81475958ec35dc3003efdc6f26b1bf46d1681cbd82180f7b"
  },
  {
    "eidolon": 5,
    "name": "#HealingTheWorld #GoodVibesOnly",
    "mechanic_tags": [
      "elation"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "15"
    ],
    "description_sha256": "986fac450a960dd679455251c1caba553f7294fce93fd4fb862a66d22b5014d7"
  },
  {
    "eidolon": 6,
    "name": "#BuiltDifferent #GoingExtinct",
    "mechanic_tags": [
      "res_pen",
      "res",
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "20%",
      "1",
      "1",
      "40"
    ],
    "description_sha256": "90686949e76e483b512bbe653c8a1301a75322c6eb7ba316de02ad44eff234fe"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
