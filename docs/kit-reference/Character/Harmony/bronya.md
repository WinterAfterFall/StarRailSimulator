---
schema_version: "1.0.0"
unit_id: 12
name: "Bronya"
slug: "bronya"
rarity: 5
element: "Wind"
path: "Harmony"
role: "Support"
affiliation: "Belobog"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/bronya"
source_record_updated_at: "January 25th, 2025"
dataset_snapshot: "2026-05-30"
---

# Bronya

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Bronya.h` |
| ธาตุ | **Wind** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

### Base Stats (Lv.80, ascended)
HP 1241 · ATK 582 · DEF 533 · SPD 99

> Harmony support สาย turn-advance + DMG/ATK/CRIT DMG buff

---

### Basic ATK — Windrider Bullet (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Combat Redeployment (Support, Lv.10)
- ลบ debuff 1 อันจากเพื่อน 1 ตัว, ให้เพื่อนคนนั้น **action ทันที**, +DMG **66%** นาน 1 เทิร์น
- ถ้าใช้ใส่ Bronya เอง → ไม่ได้ action ทันที
- Energy +30

### Ultimate — The Belobog March (Support, 120 energy, Lv.10)
- เพื่อนทุกคน ATK **+55%**
- เพื่อนทุกคน CRIT DMG **+เท่ากับ 16% ของ CRIT DMG ของ Bronya + 20%** นาน 2 เทิร์น
- Energy +5

### Talent — Leading the Way (Lv.10)
- หลังใช้ Basic ATK → action ครั้งถัดไปของ Bronya advance **30%**
- Energy +5 · Toughness 10

### Technique — Banner of Command
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป เพื่อนทุกคน ATK **+15%** นาน 2 เทิร์น

---

### Major Traces
- **A2 — Command**: CRIT Rate ของ Basic ATK เพิ่มเป็น **100%**
- **A4 — Battlefield**: ต้นการต่อสู้ → เพื่อนทุกคน DEF **+20%** นาน 2 เทิร์น
- **A6 — Military Might**: ขณะ Bronya อยู่ในสนาม → เพื่อนทุกคน +DMG **10%**

### Minor Traces (รวมทั้งหมด)
Wind DMG +22.4% · CRIT DMG +24% · Effect RES +10%

### Eidolons
- **E1 — Hone Your Strength**: ใช้ Skill มี 50% fixed chance คืน Skill Point 1 (cooldown 1 เทิร์น)
- **E2 — Quick March**: ใช้ Skill → เป้าหมาย SPD **+30%** หลัง action นาน 1 เทิร์น
- **E3**: Ultimate Lv. +2 · Talent Lv. +2
- **E4 — Take by Surprise**: หลังเพื่อนใช้ Basic ATK ใส่ศัตรูที่มี Wind Weakness → Bronya ยิง follow-up: Wind DMG = **80% ของดาเมจ Basic ATK ของ Bronya** (1 ครั้ง/เทิร์น)
- **E5**: Skill Lv. +2 · Basic ATK Lv. +1
- **E6 — Piercing Rainbow**: DMG Boost จาก Skill → duration **+1 เทิร์น** (รวม 2)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Skill**: forced action (turn advance 100% effectively) + DMG% buff 66%/1t — ไม่ทำงานตอนใส่ตัวเอง (โค้ดต้อง handle self-target case)
- **Ult CRIT DMG buff**: 0.16 × (CRIT DMG ของ Bronya) + 20% — ผูกกับ CD stat ของ Bronya ต้อง snapshot/re-eval
- **Talent**: BA → self advance 30%
- **A2**: BA CRIT Rate = 100% (มักใช้กับ Bronya-as-DPS niche / E4)
- โค้ด: `Start_game_List` (`Bronya.h:65`, `Bronyaptr`) — A4 DEF buff + technique ATK buff
- driver logic ในโค้ดมี `DriverType` — Bronya skill = pull target ให้ action

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/bronya — kit tab (review/calc patch 3.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 12,
  "name": "Bronya",
  "slug": "bronya",
  "rarity": "5",
  "element": "Wind",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Belobog",
  "release_date": "April 26th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 72.6,
    "atk_base": 79.2,
    "speed_base": 99
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "windDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "critDmg",
      "value": 24
    },
    "traceStat3": {
      "stat": "effectRes",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Madeline Reiter",
    "kr": "이보희",
    "jpn": "Asumi Kana (阿澄佳奈)",
    "cn": "谢莹"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/bronya",
  "source_record_updated_at": "January 25th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `110101` | Windrider Bullet | Basic ATK | Single Target |
| `skill` | `110102` | Combat Redeployment | Skill | Support |
| `ult` | `110103` | The Belobog March | Ultimate | Support |
| `talent` | `110104` | Leading the Way | Talent | Enhance |
| `technique` | `110107` | Banner of Command | Technique | Support |

## Ability records

### Windrider Bullet

```json
{
  "ability_id": "110101",
  "slot": "basic",
  "name": "Windrider Bullet",
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
    }
  ],
  "description_sha256": "4b11abf617715d6917817cad2b90acf71943ce12c29aa70401c5c7694e7fec73",
  "icon_path": "icon/skill/1101_basic_atk.png"
}
```

### Combat Redeployment

```json
{
  "ability_id": "110102",
  "slot": "skill",
  "name": "Combat Redeployment",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
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
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 36.3,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 42.9,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 46.2,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 49.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 53.63,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 57.75,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 61.88,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 69.3,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 72.6,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 75.9,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 79.2,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
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
          "value": 82.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3984f95acca48cc19cba34dc5790970e0c1f182d52b37ea96733a8d88dd3963d",
  "icon_path": "icon/skill/1101_skill.png"
}
```

### The Belobog March

```json
{
  "ability_id": "110103",
  "slot": "ult",
  "name": "The Belobog March",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
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
          "value": 35.2,
          "unit": "percent"
        },
        "p2": {
          "value": 12.4,
          "unit": "percent"
        },
        "p3": {
          "value": 12.8,
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
          "value": 37.4,
          "unit": "percent"
        },
        "p2": {
          "value": 12.8,
          "unit": "percent"
        },
        "p3": {
          "value": 13.6,
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
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 13.2,
          "unit": "percent"
        },
        "p3": {
          "value": 14.4,
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
          "value": 41.8,
          "unit": "percent"
        },
        "p2": {
          "value": 13.6,
          "unit": "percent"
        },
        "p3": {
          "value": 15.2,
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
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
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
          "value": 46.75,
          "unit": "percent"
        },
        "p2": {
          "value": 14.5,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
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
          "value": 49.5,
          "unit": "percent"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
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
          "value": 52.25,
          "unit": "percent"
        },
        "p2": {
          "value": 15.5,
          "unit": "percent"
        },
        "p3": {
          "value": 19,
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
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 16,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
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
          "value": 57.2,
          "unit": "percent"
        },
        "p2": {
          "value": 16.4,
          "unit": "percent"
        },
        "p3": {
          "value": 20.8,
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
          "value": 59.4,
          "unit": "percent"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        },
        "p3": {
          "value": 21.6,
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
          "value": 61.6,
          "unit": "percent"
        },
        "p2": {
          "value": 17.2,
          "unit": "percent"
        },
        "p3": {
          "value": 22.4,
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
          "value": 63.8,
          "unit": "percent"
        },
        "p2": {
          "value": 17.6,
          "unit": "percent"
        },
        "p3": {
          "value": 23.2,
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
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 24,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "10497f2b614a424c281dc7d20ae2d3531432cc65c729789f0854461f50409381",
  "icon_path": "icon/skill/1101_ultimate.png"
}
```

### Leading the Way

```json
{
  "ability_id": "110104",
  "slot": "talent",
  "name": "Leading the Way",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
  "energy_gain": "5",
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
    "action_advance"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.38,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 26.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.13,
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
          "value": 31.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 34.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "f5237e8f471848532335c7cea9e4cf786eda1b4a626b32ba16788fc8ab96fc4c",
  "icon_path": "icon/skill/1101_talent.png"
}
```

### Banner of Command

```json
{
  "ability_id": "110107",
  "slot": "technique",
  "name": "Banner of Command",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
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
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "81cd3572c6a2b5a50e8108e8566df5ccc2b5448b623ce86db4a8194755984128",
  "icon_path": "icon/skill/1101_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Command",
    "mechanic_tags": [
      "atk",
      "crit_rate"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "475183ea7cfe26fdff39829e6be95f15f745e30950f7efb02332074463c04a64"
  },
  {
    "requirement": "A4",
    "name": "Battlefield",
    "mechanic_tags": [
      "def"
    ],
    "numeric_tokens": [
      "20%",
      "2"
    ],
    "description_sha256": "43877e3a579155cc73afbb05cff869ee320574f798d5140f7cf1d49c09a02844"
  },
  {
    "requirement": "A6",
    "name": "Military Might",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "1cb80625c2f0d85049d870e9f5663685fba1a9a39a3fc3c648dcc948db891b00"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Hone Your Strength",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "50%",
      "1",
      "1"
    ],
    "description_sha256": "56ca73d23313c3e54aaac33871d83d2a4e91c6576cface83ce432eaad224acc7"
  },
  {
    "eidolon": 2,
    "name": "Quick March",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "30%",
      "1"
    ],
    "description_sha256": "a95fd9b9259094820d0fe14dc8ec90ac6cb1878bb67d3c66d14fcd46ac409a06"
  },
  {
    "eidolon": 3,
    "name": "Bombardment",
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
    "name": "Take by Surprise",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up",
      "weakness"
    ],
    "numeric_tokens": [
      "80%",
      "1"
    ],
    "description_sha256": "5117399118d91671731bdc9637ee8c9b26b393ca9b3738b8040667fb53d09e0f"
  },
  {
    "eidolon": 5,
    "name": "Unstoppable",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "dfc289407dbc553d0a60b619a82ff2cb35c322892c7f2b225426b96a861b9dfd"
  },
  {
    "eidolon": 6,
    "name": "Piercing Rainbow",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "ae6987664aa6a0a0bc4455e74a3d1e7d219d22e4a5b57cb8263a680f714cb037"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
