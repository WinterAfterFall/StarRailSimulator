---
schema_version: "1.0.0"
unit_id: 21
name: "Luocha"
slug: "luocha"
rarity: 5
element: "Imaginary"
path: "Abundance"
role: "Healer"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/luocha"
source_record_updated_at: "April 7th, 2025"
dataset_snapshot: "2026-05-30"
---

# Luocha

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Luocha.h` |
| ธาตุ | **Imaginary** |
| Path | **Abundance** |
| ระดับ | 5★ |
| Energy Ultimate | 100 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1280 · ATK 756 · DEF 363 · SPD 101

---

### Basic ATK — Thorns of the Abyss (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Prayer of Abyss Flower (ฮีล, Lv.10)
- ฮีลเพื่อนเป้าหมาย = **60% ATK + 800** ทันที + Luocha ได้ **Abyss Flower 1 stack**
- เมื่อเพื่อนคนใด HP% ≤ 50% → trigger เอฟเฟกต์เทียบเท่า Skill ใส่ตัวนั้นทันที 1 ครั้ง (ไม่กิน Skill Point) — ทำซ้ำได้อีกหลัง **2 เทิร์น**
- Energy +30 · ไม่มี Toughness

### Ultimate — Death Wish (AoE, 100 energy, Lv.10)
- ลบ buff 1 อันจากศัตรูทุกตัว + Imaginary DMG = **200% ATK** AoE
- Luocha ได้ **Abyss Flower 1 stack**
- Energy +5 · Toughness 20

### Talent — Cycle of Life (Lv.10)
- เมื่อ Abyss Flower ครบ **2 stacks** → กินทั้งหมด กาง **Field** ใส่ศัตรู
- ขณะ Field: เพื่อนโจมตีศัตรูใน Field → ผู้โจมตีถูกฮีล = **18% ATK + 240** ทันที
- Field อยู่ **2 เทิร์น** ถ้า Luocha ถูกน็อค Field หาย

### Technique — Mercy of a Fool
- หลังใช้ Technique → trigger Talent ทันทีเมื่อเริ่มการต่อสู้ถัดไป (กาง Field ตั้งแต่ต้น)

---

### Major Traces
- **A2 — Cleansing Revival**: เมื่อเอฟเฟกต์ Skill trigger → ลบ debuff 1 อันจากเพื่อนเป้าหมาย
- **A4 — Sanctified**: เพื่อนโจมตีศัตรูใน Field → เพื่อนทุกคน (ยกเว้นผู้โจมตี) ฮีล = **7% ATK + 93**
- **A6 — Through the Valley**: +70% ต้านทาน Crowd Control

### Minor Traces (รวมทั้งหมด)
ATK +28% · DEF +12.5% · HP +18%

### Eidolons
- **E1 — Ablution of the Quick**: ขณะ Field active → เพื่อนทุกคน ATK **+20%**
- **E2 — Bestowal From the Pure**: เมื่อ Skill trigger ถ้าเป้าหมาย HP < 50% → Luocha Outgoing Healing **+30%**; ถ้า HP ≥ 50% → เป้าหมายได้ **Shield = 18% ATK + 240** นาน 2 เทิร์น
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Heavy Lies the Crown**: ขณะ Field active → ศัตรู Weakened, สร้าง DMG น้อยลง **12%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — Reunion With the Dust**: ใช้ Ultimate → 100% fixed chance ลด All-Type RES ศัตรูทุกตัว **20%** นาน 2 เทิร์น

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Abyss Flower**: ได้ +1 จาก Skill และ Ult; ครบ 2 → auto กาง Field + reset stack เป็น 0 (โค้ด `stack["Abyss_Flower"]`, ฟังก์ชัน `Abyss_Flower(ptr)`)
- **Auto-Skill on HP ≤ 50%**: passive heal โดยไม่กิน SP, cooldown 2 เทิร์น (ต่อ ally? ต่อ global? — เกมคือ per-trigger, cooldown ก่อน trigger ได้อีก)
- **Field heal-on-hit**: 18% ATK + 240 ให้ผู้โจมตี + A4 7% ATK + 93 ให้เพื่อนที่เหลือ
- ทุกค่าฮีล/shield สเกลกับ **ATK ของ Luocha**
- Technique (`ptr->Technique == 1`) → set `stack = 2` + กาง Field ทันทีใน `Start_game_List`
- E1 (+20% ATK ทีม) / E4 (enemy -12% DMG) ผูกกับ Field active
- E6 RES shred 20% เป็น debuff จาก Ult

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/luocha — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 21,
  "name": "Luocha",
  "slug": "luocha",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "Xianzhou Luofu",
  "release_date": "June 28th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "100",
  "base_stats": {
    "hp_base": 174.24,
    "def_base": 49.5,
    "atk_base": 102.96,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "def",
      "value": 12.5
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Craig Lee Thomas",
    "kr": "신용우 (Shin Yong-woo)",
    "jpn": "Ishida Akira (石田彰)",
    "cn": "Lu Zhao (赵路)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/luocha",
  "source_record_updated_at": "April 7th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120301` | Thorns of the Abyss | Basic ATK | Single Target |
| `skill` | `120302` | Prayer of Abyss Flower | Skill | Restore |
| `ult` | `120303` | Death Wish | Ultimate | AoE |
| `talent` | `120304` | Cycle of Life | Talent | Restore |
| `technique` | `120307` | Mercy of a Fool | Technique | Restore |

## Ability records

### Thorns of the Abyss

```json
{
  "ability_id": "120301",
  "slot": "basic",
  "name": "Thorns of the Abyss",
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
  "description_sha256": "5106c568593e106014ac94f159ffda20bf9d37248d0cffc507a858c30ceb0cb1",
  "icon_path": "icon/skill/1203_basic_atk.png"
}
```

### Prayer of Abyss Flower

```json
{
  "ability_id": "120302",
  "slot": "skill",
  "name": "Prayer of Abyss Flower",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Imaginary",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "skill_points"
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
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 42.5,
          "unit": "percent"
        },
        "p2": {
          "value": 320,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 410,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 47.5,
          "unit": "percent"
        },
        "p2": {
          "value": 500,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 560,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        },
        "p2": {
          "value": 620,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 665,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 710,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 58,
          "unit": "percent"
        },
        "p2": {
          "value": 755,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
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
          "value": 800,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 62,
          "unit": "percent"
        },
        "p2": {
          "value": 845,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 64,
          "unit": "percent"
        },
        "p2": {
          "value": 890,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 935,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 68,
          "unit": "percent"
        },
        "p2": {
          "value": 980,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 70,
          "unit": "percent"
        },
        "p2": {
          "value": 1025,
          "unit": "scalar"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b15c69483ddcf83d45445043fb60011f81d190a466c51e256d6f34ac1ee1584a",
  "icon_path": "icon/skill/1203_skill.png"
}
```

### Death Wish

```json
{
  "ability_id": "120303",
  "slot": "ult",
  "name": "Death Wish",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "100",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
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
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 170,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 190,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 208,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 224,
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
          "value": 232,
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
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8f6208cc6ae2f310550cf62f8a8932cab96585a64c0502f3a79fd300911d57c5",
  "icon_path": "icon/skill/1203_ultimate.png"
}
```

### Cycle of Life

```json
{
  "ability_id": "120304",
  "slot": "talent",
  "name": "Cycle of Life",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 60,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 12.75,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 96,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 13.5,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 123,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 14.25,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 168,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 15.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 186,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 16.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 199.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 213,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 17.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 226.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 240,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 18.6,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 253.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 19.2,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 267,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 19.8,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 280.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 20.4,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 294,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "scalar"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 307.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "7e7265d9048e7a260375751aeb73d62cefd11f626771338b86f4bb99387c9d3a",
  "icon_path": "icon/skill/1203_talent.png"
}
```

### Mercy of a Fool

```json
{
  "ability_id": "120307",
  "slot": "technique",
  "name": "Mercy of a Fool",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [],
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
  "description_sha256": "b545103462db482d13674d1131a6880ce8c5650a2e45ceeefc08a7e21ebd1f41",
  "icon_path": "icon/skill/1203_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Cleansing Revival",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "6859158eb1f7ac60e17cb5d6ec20024d393b4101d2fc145dba4740840b2423b6"
  },
  {
    "requirement": "A4",
    "name": "Sanctified",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "healing"
    ],
    "numeric_tokens": [
      "7%",
      "93"
    ],
    "description_sha256": "9e54311039d4ab933b1e06c8370a78ca171d3419aa19339763703ba2156cb2b1"
  },
  {
    "requirement": "A6",
    "name": "Through the Valley",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "70%"
    ],
    "description_sha256": "265aad1df8fd9bd34060913626e49118fb10fade316f6bcdf6c5d6e781c361af"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Ablution of the Quick",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "d6ddc9802a8a513b833bf0c850326c5c95944a0631ad1f6b37a90a397c31c882"
  },
  {
    "eidolon": 2,
    "name": "Bestowal From the Pure",
    "mechanic_tags": [
      "max_hp",
      "atk",
      "dmg",
      "healing",
      "shield"
    ],
    "numeric_tokens": [
      "50",
      "30%",
      "50",
      "18%",
      "240",
      "2"
    ],
    "description_sha256": "be18e2e58565669b738b9dac3134f7f380057e265fa1e8f69ea996d355fa925d"
  },
  {
    "eidolon": 3,
    "name": "Surveyal by the Fool",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "cc0d6a12ef7b870ada3a8cc5bf409ac765e5cddc458782b0d4d944b156f24f67"
  },
  {
    "eidolon": 4,
    "name": "Heavy Lies the Crown",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "12%"
    ],
    "description_sha256": "b21c9fbfe1f45fb0cf03ad1df449fa7dc5f3429bbccd94cb8afa95e01c707998"
  },
  {
    "eidolon": 5,
    "name": "Cicatrix 'Neath the Pain",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "a4417497ecb72e43d7a08beb9ea57ccb09e86b6838c1773e7e2ade42f7242276"
  },
  {
    "eidolon": 6,
    "name": "Reunion With the Dust",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "100%",
      "20%",
      "2"
    ],
    "description_sha256": "b9dde5a7a7371b9724691641e5d9e9189790e0e5841a8b45b20726a8da7f9a3f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
