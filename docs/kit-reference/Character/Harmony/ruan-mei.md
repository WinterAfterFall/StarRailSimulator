---
schema_version: "1.0.0"
unit_id: 43
name: "Ruan Mei"
slug: "ruan-mei"
rarity: 5
element: "Ice"
path: "Harmony"
role: "Support"
affiliation: "Herta Space Station"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/ruan-mei"
source_record_updated_at: "December 16th, 2025"
dataset_snapshot: "2026-05-30"
---

# Ruan Mei

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Ruan_Mei.h` |
| ธาตุ | **Ice** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1086 · ATK 659 · DEF 485 · SPD 104

> Harmony support สายบัฟรวม + Break/Super Break

---

### Basic ATK — Threading Fragrance (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — String Sings Slow Swirls (Support, Lv.10)
- Ruan Mei ได้ **Overtone** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Ruan Mei)
- ขณะมี Overtone: เพื่อนทุกคน +DMG **32%** + Weakness Break Efficiency **+50%**
- Energy +30

### Ultimate — Petals to Stream, Repose in Dream (Support, 130 energy, Lv.10)
- กาง field นาน 2 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Ruan Mei)
- ขณะอยู่ใน field: เพื่อนทุกคน All-Type RES PEN **+25%** + การโจมตีของเพื่อนติด **Thanatoplum Rebloom** ให้ศัตรูที่โดน
- เมื่อศัตรูนั้นพยายามฟื้นจาก Weakness Break → trigger Thanatoplum Rebloom: ยืด Weakness Break, delay action = **20% ของ Break Effect ของ Ruan Mei + 10%**, Break DMG = **50% ของ Ice Break DMG ของ Ruan Mei**
- ศัตรูจะโดนติดซ้ำไม่ได้จนกว่าจะฟื้นจาก Weakness Break
- Energy +5

### Talent — Somatotypical Helix (Lv.10)
- เพื่อน (ยกเว้น Ruan Mei) SPD **+10%**
- เมื่อเพื่อน Break Weakness ศัตรู → Ruan Mei สร้าง Break DMG = **120% ของ Ice Break DMG ของเธอ** ใส่ศัตรูนั้น

### Technique — Silken Serenade
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป trigger Skill อัตโนมัติ 1 ครั้ง โดยไม่กิน Skill Points

---

### Major Traces
- **A2 — Inert Respiration**: เพื่อนทุกคน Break Effect **+20%**
- **A4 — Days Wane, Thoughts Wax**: Ruan Mei คืน Energy **5** ตอนเริ่มเทิร์น
- **A6 — Candle Lights on Still Waters**: ทุก 10% ของ Break Effect ของ Ruan Mei ที่เกิน **120%** → Skill เพิ่ม +DMG เพื่อน **+6%** สูงสุด **+36%**

### Minor Traces (รวมทั้งหมด)
DEF +22.5% · SPD +5 · Break Effect +37.3%

### Eidolons
- **E1**: ขณะ field ของ Ult กางอยู่ → ดาเมจเพื่อนทุกคนเพิกเฉย DEF **20%**
- **E2**: ขณะ Ruan Mei อยู่ในสนาม → เพื่อนทุกคน ATK **+40%** เมื่อสร้างดาเมจกับศัตรู Weakness Broken
- **E3**: Ultimate Lv. +2 · Talent Lv. +2
- **E4**: ศัตรู Weakness Broken → Ruan Mei Break Effect **+100%** นาน 3 เทิร์น
- **E5**: Skill Lv. +2 · Basic ATK Lv. +1
- **E6**: field ของ Ult **+1 เทิร์น**. Talent Break DMG multiplier **+200%** (รวม 320%)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Overtone (Skill)**: DMG +32% + WBE +50% (A6 → +6%/10% BE เกิน 120% สูงสุด +36% DMG)
- **Talent Break DMG**: 120% Ice Break DMG (E6 320%) ต่อการ break ของเพื่อน — ต้องมี Ice Break DMG model
- **Ult field**: RES PEN +25%, Thanatoplum Rebloom (delay + break-dmg 50% ตอนศัตรูจะฟื้นจาก break)
- **A2 BE +20% ทีม** / E4 BE +100% self
- **Talent SPD +10%** ทีม (ยกเว้นตัวเอง)
- โค้ด: `Start_game_List` priority `PRIORITY_ACTION` (`Ruan_Mei.h:66`) + มี addToActionBar + `Deal_damage()` (technique auto-skill self-flush)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/ruan-mei — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 43,
  "name": "Ruan Mei",
  "slug": "ruan-mei",
  "rarity": "5",
  "element": "Ice",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Herta Space Station",
  "release_date": "December 27th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 147.84,
    "def_base": 66,
    "atk_base": 89.76,
    "speed_base": 104
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "def",
      "value": 22.5
    },
    "traceStat2": {
      "stat": "speed",
      "value": 5
    },
    "traceStat3": {
      "stat": "Break Effect",
      "value": 37.3
    }
  },
  "voice_actors": {
    "en": "Emi Lo",
    "kr": "윤여진 (Yoon Yeo-jin)",
    "jpn": "大西沙织 (Onishi Saori)",
    "cn": "张文钰 (Zhang Wenyu)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/ruan-mei",
  "source_record_updated_at": "December 16th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130301` | Threading Fragrance | Basic ATK | Single Target |
| `skill` | `130302` | String Sings Slow Swirls | Skill | Support |
| `ult` | `130303` | Petals to Stream, Repose in Dream | Ultimate | Support |
| `talent` | `130304` | Somatotypical Helix | Talent | Support |
| `technique` | `130307` | Silken Serenade | Technique | Enhance |

## Ability records

### Threading Fragrance

```json
{
  "ability_id": "130301",
  "slot": "basic",
  "name": "Threading Fragrance",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Ice",
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
  "description_sha256": "eb9bf3aabce41efb6541e80fb5c44e93d3c3232eefc20bc6fc02a16507f6960a",
  "icon_path": "icon/skill/1303_basic_atk.png"
}
```

### String Sings Slow Swirls

```json
{
  "ability_id": "130302",
  "slot": "skill",
  "name": "String Sings Slow Swirls",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
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
    "weakness_break_efficiency",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 17.6,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 20.8,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 22.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
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
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
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
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 33.6,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 35.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 36.8,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 38.4,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
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
        }
      }
    }
  ],
  "description_sha256": "1b1bbcdcea8855f57c94363e64214782a9d0691fdd7e9d3cac5a025e994653a3",
  "icon_path": "icon/skill/1303_skill.png"
}
```

### Petals to Stream, Repose in Dream

```json
{
  "ability_id": "130303",
  "slot": "ult",
  "name": "Petals to Stream, Repose in Dream",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": null,
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "break_effect",
    "res_pen",
    "res",
    "dmg",
    "action_delay",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 17,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 18,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 19,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 38,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 21.25,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 42.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 22.5,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 23.75,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 47.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 25,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 26,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 27,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 28,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 29,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 58,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 30,
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
          "value": 10,
          "unit": "percent"
        },
        "p5": {
          "value": 60,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e77fc99fb0f67ae773f33750a28bd2b2ed30eb8884b7f07295b1c24b6b827f69",
  "icon_path": "icon/skill/1303_ultimate.png"
}
```

### Somatotypical Helix

```json
{
  "ability_id": "130304",
  "slot": "talent",
  "name": "Somatotypical Helix",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
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
    "spd",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 8.2,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 8.6,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 8.8,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
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
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 9.25,
          "unit": "percent"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 9.5,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.75,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.2,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 10.4,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 10.6,
          "unit": "percent"
        },
        "p2": {
          "value": 138,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        },
        "p2": {
          "value": 150,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9f2b587cc5e75f3a874a12a4ad82c5b1089b07a04565f5063bfa482c2409321b",
  "icon_path": "icon/skill/1303_talent.png"
}
```

### Silken Serenade

```json
{
  "ability_id": "130307",
  "slot": "technique",
  "name": "Silken Serenade",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
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
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
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
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "97633edc8900a3fb774983086ad69b4db78937b2c0cdf1bab5971ca327ac210c",
  "icon_path": "icon/skill/1303_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Inert Respiration",
    "mechanic_tags": [
      "break_effect"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "8c1c0ca0fb8ad8ad51313ed17972cf3e8d3c08b525997374941776aed1c08079"
  },
  {
    "requirement": "A4",
    "name": "Days Wane, Thoughts Wax",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "c936de100b60357c0d654a265aadab1424411ce9d4e7198f57f22739a249211f"
  },
  {
    "requirement": "A6",
    "name": "Candle Lights on Still Waters",
    "mechanic_tags": [
      "break_effect",
      "dmg"
    ],
    "numeric_tokens": [
      "10%",
      "120%",
      "6%",
      "36%"
    ],
    "description_sha256": "44eb515df4bcd0cd86f59fa774203b8c95303f6620bc3d343fa8e67eebedae33"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Neuronic Embroidery",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "a00d562091367864b20f05407322180f539500f61949820e0be0e2960a78f436"
  },
  {
    "eidolon": 2,
    "name": "Reedside Promenade",
    "mechanic_tags": [
      "atk",
      "dmg",
      "weakness"
    ],
    "numeric_tokens": [
      "40%"
    ],
    "description_sha256": "1e00c8aa818b4499919ff48cf589f42902f35b527d6d947aa22489874cf81975"
  },
  {
    "eidolon": 3,
    "name": "Viridescent Pirouette",
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
    "eidolon": 4,
    "name": "Chatoyant Éclat",
    "mechanic_tags": [
      "break_effect",
      "weakness"
    ],
    "numeric_tokens": [
      "100%",
      "3"
    ],
    "description_sha256": "7ac545bcae665e080f517e5f743442962507027dc2d91ca401699b58f54fe69c"
  },
  {
    "eidolon": 5,
    "name": "Languid Barrette",
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
    "eidolon": 6,
    "name": "Sash Cascade",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "200%"
    ],
    "description_sha256": "e5c76fddd7bff7c76dd18d4549db46b32d301b58a1ebd7e94552a9c61885b063"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
