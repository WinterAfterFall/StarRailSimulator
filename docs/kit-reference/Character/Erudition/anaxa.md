---
schema_version: "1.0.0"
unit_id: 73
name: "Anaxa"
slug: "anaxa"
rarity: 5
element: "Wind"
path: "Erudition"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/anaxa"
source_record_updated_at: "May 20th, 2025"
dataset_snapshot: "2026-05-30"
---

# Anaxa

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Anaxa.h` |
| ธาตุ | **Wind** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 4.3) |

### Base Stats (Lv.80, ascended)
HP 970 · ATK 756 · DEF 557 · SPD 97

> Erudition DPS สาย weakness-implant — ยัด weakness ทุก type แล้วเก็บ bonus

---

### Basic ATK — Pain, Brews Truth (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Fractal, Exiles Fallacy (Bounce, Lv.10)
- Wind DMG = **70% ATK** ใส่เป้าหมาย + เพิ่ม **4 instance × 70% ATK** ใส่ศัตรูสุ่ม (bounce เลี่ยงตัวที่โดนแล้วในรอบนี้)
- เมื่อใช้: ต่อจำนวนศัตรูที่ตีได้ในสนาม → Skill นี้ +DMG dealt **20%** ต่อตัว
- Energy +6 · Toughness 10 (ทุก instance)

### Ultimate — Sprouting Life Sculpts Earth (AoE, 140 energy, Lv.10)
- ติด **"Sublimation"** ศัตรูทุกตัว → Wind DMG = **160% ATK** AoE
- Sublimation: ติด Weakness ทั้ง 7 type (Physical/Fire/Ice/Lightning/Wind/Quantum/Imaginary) จนถึงต้นเทิร์นของเป้าหมาย; ถ้าไม่มี Control RES → ทำ action ไม่ได้ระหว่าง Sublimation
- Energy +5 · Toughness 20

### Talent — Tetrad Wisdom Reigns Thrice (Lv.10)
- ทุกครั้งที่ Anaxa ตีโดน 1 hit → ยัด Weakness type สุ่ม 1 อัน นาน 3 เทิร์น (เลือก type ที่เป้าหมายยังไม่มีก่อน)
- ขณะ Anaxa อยู่ในสนาม: ศัตรูที่มี Weakness ≥ 5 type → ติด **"Qualitative Disclosure"**
  - Anaxa สร้างดาเมจกับตัวที่ติด **+30%**
  - หลังใช้ BA/Skill ใส่ตัวนั้น → ปล่อย Skill เพิ่ม 1 instance (ไม่กิน SP, ไม่ re-trigger effect; ถ้าเป้าตายก่อน → ยิงใส่ศัตรูสุ่ม)

### Technique — Prism of the Pupil
- ติด Terrified ให้ศัตรู 10 วิ
- เข้าฉากโดยตีศัตรู Terrified → ถือว่าเข้าฉากแบบตี Weakness เสมอ + Anaxa ยัด Weakness type ของผู้โจมตี 1 อันให้ศัตรูทุกตัว นาน 3 เทิร์น

---

### Major Traces
- **A2 — Roaming Signifier**: ใช้ BA → คืน Energy **10**. ต้นเทิร์น ถ้าไม่มีศัตรูติด "Qualitative Disclosure" → คืน Energy **30** ทันที
- **A4 — Imperative Hiatus**: ตามจำนวนตัวละคร Erudition ในทีม — 1 ตัว: Anaxa CRIT DMG **+140%**; ≥ 2 ตัว: เพื่อนทุกคน +DMG dealt **50%**
- **A6 — Qualitative Shift**: ต่อ Weakness type ที่เป้าหมายมี → Anaxa ดาเมจเพิกเฉย DEF **4%** (สูงสุด 7 type = 28%)

### Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · HP +10% · Wind DMG +22.4%

### Eidolons
- **E1**: ใช้ Skill ครั้งแรก → คืน Skill Point **1**. ใช้ Skill โดนศัตรู → ลด DEF เป้าหมาย **16%** นาน 2 เทิร์น
- **E2**: ศัตรูเข้าสนาม → trigger Talent weakness implant 1 ครั้ง + ลด All-Type RES **20%**
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ใช้ Skill → ATK **+30%** นาน 2 เทิร์น stack 2 ครั้ง
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ดาเมจของ Anaxa = **130%** ของเดิม. A4 ทั้ง 2 effect trigger ทันทีโดยไม่สนจำนวน Erudition

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Weakness implant ทุก hit** (Talent) — ทุก instance ของ Skill bounce ก็ยัด weakness — โค้ดมี `weaknessApply` / `Weakness Aplly function` (มี fix commit ล่าสุด)
- **Qualitative Disclosure** = threshold 5 weakness types → +30% DMG + follow-up Skill (ไม่กิน SP, ไม่ recursion)
- **Skill DMG scaling**: base 70% + (20% × จำนวนศัตรู) DMG-dealt bonus
- **A6 DEF ignore**: 4% × weakness type count (cap 7)
- **A2 energy**: BA +10, +30 conditional ต้นเทิร์น
- **Ult Sublimation**: 7-type weakness + soft CC (ถ้าไม่มี Control RES)
- **A4** ผูกกับ Erudition count → E6 unlock ทั้งคู่; โค้ด `Start_game_List` (`Anaxaptr`, allEventAdjustStats)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/anaxa — kit tab (review patch 3.2, calc patch 4.3, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 73,
  "name": "Anaxa",
  "slug": "anaxa",
  "rarity": "5",
  "element": "Wind",
  "path": "Erudition",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "April 30th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 132,
    "def_base": 75.9,
    "atk_base": 102.96,
    "speed_base": 97
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat2": {
      "stat": "hp",
      "value": 10
    },
    "traceStat3": {
      "stat": "Wind DMG",
      "value": 22.4
    }
  },
  "voice_actors": {
    "en": "Stephen Fu",
    "kr": "Lee Sang-jun (이상준)",
    "jpn": "Uchida Yuma (内田 雄馬)",
    "cn": "Qian Wenqing (钱文青)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/anaxa",
  "source_record_updated_at": "May 20th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140501` | Pain, Brews Truth | Basic ATK | Single Target |
| `skill` | `140502` | Fractal, Exiles Fallacy | Skill | Bounce |
| `ult` | `140503` | Sprouting Life Sculpts Earth | Ultimate | AoE |
| `talent` | `140504` | Tetrad Wisdom Reigns Thrice | Talent | Impair |
| `technique` | `140507` | Prism of the Pupil | Technique | Impair |

## Ability records

### Pain, Brews Truth

```json
{
  "ability_id": "140501",
  "slot": "basic",
  "name": "Pain, Brews Truth",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
  "description_sha256": "887dc102769ecefc7f76ffc6abc71f54a656bb630bc8541a739d8d5faf6fc962",
  "icon_path": "icon/skill/1405_basic_atk.png"
}
```

### Fractal, Exiles Fallacy

```json
{
  "ability_id": "140502",
  "slot": "skill",
  "name": "Fractal, Exiles Fallacy",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Wind",
  "energy_gain": "6",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    },
    "p2": {
      "unit": "scalar",
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
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
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
          "value": 38.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 45.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 49,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 56.87,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
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
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65.62,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 73.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 80.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "scalar"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "d28c69fb098f9ec0c5bdaf2781d33de5019bde7852535322b733a920898706be",
  "icon_path": "icon/skill/1405_skill.png"
}
```

### Sprouting Life Sculpts Earth

```json
{
  "ability_id": "140503",
  "slot": "ult",
  "name": "Sprouting Life Sculpts Earth",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
    "res",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 80,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 96,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 112,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 130,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 150,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 168,
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
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 184,
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
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "f768ae49d95121cc9fb99210547a640636ee2270351479b1afeff2aa64dde4f7",
  "icon_path": "icon/skill/1405_ultimate.png"
}
```

### Tetrad Wisdom Reigns Thrice

```json
{
  "ability_id": "140504",
  "slot": "talent",
  "name": "Tetrad Wisdom Reigns Thrice",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
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
    "dmg",
    "weakness",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 20.4,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 22.8,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 25.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 27,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.2,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 32.4,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 33.6,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 34.8,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "387de1738e816c723f7bf490d1edee99feeafa3727b7c74e08d769d73ddb99c5",
  "icon_path": "icon/skill/1405_talent.png"
}
```

### Prism of the Pupil

```json
{
  "ability_id": "140507",
  "slot": "technique",
  "name": "Prism of the Pupil",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Wind",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "weakness"
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
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1ac9331bccec75b4b98cf3a83a0214c785a0f1cdeec99efc9edc87c505d261f8",
  "icon_path": "icon/skill/1405_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Roaming Signifier",
    "mechanic_tags": [
      "atk",
      "energy"
    ],
    "numeric_tokens": [
      "10",
      "30"
    ],
    "description_sha256": "3a68b658324d8347a0c3257fb6860d34f1065e5d079d52945a3c7c4ef2300cd0"
  },
  {
    "requirement": "A4",
    "name": "Imperative Hiatus",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "140%",
      "2",
      "50%"
    ],
    "description_sha256": "91051558c5b329b7ef562b8aaf6545abf92443d7c66a41d7066727191c355bb8"
  },
  {
    "requirement": "A6",
    "name": "Qualitative Shift",
    "mechanic_tags": [
      "def",
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "4%",
      "7"
    ],
    "description_sha256": "e6b4d920aa6fb17e5e33ca359c3d14c61e3ec853e1cc20f62c454dfd514d52e1"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Magician, Isolated by Stars",
    "mechanic_tags": [
      "def",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "16%",
      "2"
    ],
    "description_sha256": "6f896af4ab37796b6a7b0cc7f53d22e2c0b05b2595bc6a3f07f7450f8f2cfeb4"
  },
  {
    "eidolon": 2,
    "name": "Soul, True to History",
    "mechanic_tags": [
      "res",
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "20%"
    ],
    "description_sha256": "2ab3c098aa2c0723044978b4dd8284a76825d0dca604dc21e9aa2dd5d59499d6"
  },
  {
    "eidolon": 3,
    "name": "Pupil, Etched into Cosmos",
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
    "eidolon": 4,
    "name": "Blaze, Plunged to Canyon",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "30%",
      "2",
      "2"
    ],
    "description_sha256": "97a347814c6de77d60faab86333c3372b2663486a9be09c4b984b89cfbe25df3"
  },
  {
    "eidolon": 5,
    "name": "Embryo, Set Beyond Vortex",
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
    "name": "Everything Is in Everything",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "130%",
      "2"
    ],
    "description_sha256": "3c0667154e39d4d1b611e2ed24e17e68149960e0cf8daafeec9713084301d57f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
