---
schema_version: "1.0.0"
unit_id: 76
name: "Saber"
slug: "saber"
rarity: 5
element: "Wind"
path: "Destruction"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/saber"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Saber

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Saber.h` |
| ธาตุ | **Wind** |
| Path | **Destruction** |
| ระดับ | 5★ (collab) |
| Energy Ultimate | 360 |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1241 · ATK 601 · DEF 654 · SPD 101

---

### Basic ATK — Invisible Air: Barrier of the Wind King (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Release, the Golden Scepter (AoE, Lv.6)
- ได้ **Core Resonance +2**
- Wind DMG = **150% ATK** ใส่ศัตรูทุกตัว
- ถ้าจำนวนศัตรู = 2/1 → เพิ่ม Wind DMG **150%/220% ATK** ใส่ศัตรูทุกตัว
- Energy +30 · Toughness 20

### Skill — Strike Air: Hammer of the Wind King (Blast, Lv.10)
- Wind DMG หลัก = **150% ATK**, ข้างเคียง = **75% ATK**
- ถ้ามี "Core Resonance" และการกิน Core Resonance หลัง Skill นี้จะเติม Energy เต็มพอดี → เพิ่ม multiplier ของ Skill ครั้งนี้ **+14% ต่อ stack** ของ Core Resonance และกิน Core Resonance ทั้งหมดเพื่อคืน Energy
- มิฉะนั้น → ได้ **Core Resonance +3**
- Energy +30 · Toughness 20 (+10)

### Ultimate — Excalibur (AoE, 360 energy, Lv.10)
- Wind DMG = **280% ATK** ใส่ศัตรูทุกตัว
- เพิ่ม **10 instance × 110% ATK** Wind DMG ใส่ศัตรูสุ่ม
- หลังใช้ Ult → Basic ATK ถัดไปเปลี่ยนเป็น "Release, the Golden Scepter" และใช้ได้แต่ท่านั้น
- Energy +5 · Toughness 20 (+40 ข้างเคียง)

### Talent — Dragon Reactor Core (Lv.10)
- เข้าฉาก → Core Resonance **+1**
- เมื่อเพื่อนคนใดใช้ Ultimate → Saber +DMG dealt **60%** นาน 2 เทิร์น + Core Resonance **+3**
- กิน Core Resonance 1 แต้ม → คืน Energy คงที่ **8**
- Energy +5

### Technique — Behold, the King of Knights
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป Saber ATK **+35%** นาน 2 เทิร์น + Core Resonance **+2**

---

### Major Traces
- **A2 — Knight of the Dragon**: CRIT Rate **+20%**. เข้าฉาก / ใช้ Enhanced BA → ได้ **'Mana Burst'**. ขณะมี Mana Burst ถ้ามี Core Resonance และ Skill+กิน Core Resonance จะเติม Energy เต็มพอดี → กิน Mana Burst คืน **Skill Point 1** ให้ทีม + Saber action ทันที
- **A4 — Blessing of the Lake**: สะสม excess Energy ได้สูงสุด **120**. หลังใช้ Ult → ล้าง excess แล้วคืนตามจำนวนนั้น. ต้นการต่อสู้ ถ้า Energy < 60% → เติมเป็น 60%
- **A6 — Crown of the Star**: ใช้ Skill → CRIT DMG **+50%** นาน 2 เทิร์น. ตลอดการต่อสู้ ทุก Core Resonance ที่ได้ → CRIT DMG **+4%** stack 8 ครั้ง

### Minor Traces (รวมทั้งหมด)
Wind DMG +22.4% · CRIT Rate +12% · HP +10%

### Eidolons
- **E1**: Ultimate DMG **+60%**. หลังใช้ BA/Skill → Core Resonance +1
- **E2**: ทุก Core Resonance ที่ได้ → ดาเมจเพิกเฉย DEF **1%** stack 15 ครั้ง. เมื่อ trigger Skill-multiplier effect → ทุก Core Resonance เพิ่ม multiplier ครั้งนั้น **+7%**
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: Wind RES PEN **+8%**. หลังใช้ Ult → Wind RES PEN **+4%** stack 3 ครั้ง
- **E5**: Skill Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: Ultimate DMG ได้ Wind RES PEN **+20%**. A4 overflow cap เพิ่มเป็น **200**. Ult ครั้งแรกหลังเข้าฉาก → คืน Energy คงที่ **300** (trigger ได้อีกทุก ๆ 3 Ult)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Energy = ทรัพยากรหลัก** (Ult cost 360). Talent: กิน Core Resonance 1 → +8 energy. A4/E6: overflow energy 120/200/300
- **Core Resonance**: ได้จาก Enhanced BA(+2), Skill(+3 ถ้าไม่ trigger), Talent (เข้าฉาก +1, เพื่อน Ult +3), Technique(+2), E1(+1 หลัง BA/Skill)
- **Skill conditional**: "ถ้ากิน Core Resonance หลัง Skill แล้ว energy เต็มพอดี" → Skill multiplier +14%/stack (+E2 7%/stack), กิน Core Resonance หมด; ไม่งั้น +3 Core Resonance — เงื่อนไข energy-math สำคัญมาก
- **Ult** → next BA locked เป็น Enhanced (AoE)
- **A6 CRIT DMG**: +4% ต่อ Core Resonance ที่เคยได้ (สะสมทั้งเกม stack 8)
- โค้ด: `Start_game_List` (energy 10, `Mana Flow` buff check, `CoreResonance(1)`; Technique → `CoreResonance(2)` + ATK% 35 buff)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/saber — kit tab (review/calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 76,
  "name": "Saber",
  "slug": "saber",
  "rarity": "5",
  "element": "Wind",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "July 11th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "360",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 89.1,
    "atk_base": 81.84,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Wind DMG",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "",
    "jpn": "",
    "cn": ""
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/saber",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `101401` | Invisible Air: Barrier of the Wind King | Basic ATK | Single Target |
| `basic_enh` | `101408` | Release, the Golden Scepter | Basic ATK | AoE |
| `skill` | `101402` | Strike Air: Hammer of the Wind King | Skill | Blast |
| `ult` | `101403` | Excalibur | Ultimate | AoE |
| `talent` | `101404` | Dragon Reactor Core | Talent | Enhance |
| `technique` | `101407` | Behold, the King of Knights | Technique | Enhance |

## Ability records

### Invisible Air: Barrier of the Wind King

```json
{
  "ability_id": "101401",
  "slot": "basic",
  "name": "Invisible Air: Barrier of the Wind King",
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
  "description_sha256": "2cc1f1b484cb4b2651a62faf21faa481f686240c90948ab7422d490d4bfd4c22",
  "icon_path": null
}
```

### Release, the Golden Scepter

```json
{
  "ability_id": "101408",
  "slot": "basic_enh",
  "name": "Release, the Golden Scepter",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Wind",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 154,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 176,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 135,
          "unit": "percent"
        },
        "p2": {
          "value": 198,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 220,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        },
        "p2": {
          "value": 242,
          "unit": "percent"
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
          "value": 264,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "db7a06793975accf15ea4b571a5909f5b3fc5ae50e1d904efc558a5affc91f22",
  "icon_path": null
}
```

### Strike Air: Hammer of the Wind King

```json
{
  "ability_id": "101402",
  "slot": "skill",
  "name": "Strike Air: Hammer of the Wind King",
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
    "atk",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 7,
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
        },
        "p2": {
          "value": 41.25,
          "unit": "percent"
        },
        "p3": {
          "value": 7.7,
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
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 8.4,
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
        },
        "p2": {
          "value": 48.75,
          "unit": "percent"
        },
        "p3": {
          "value": 9.1,
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
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        },
        "p3": {
          "value": 9.8,
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
        },
        "p2": {
          "value": 56.25,
          "unit": "percent"
        },
        "p3": {
          "value": 10.5,
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
        },
        "p2": {
          "value": 60.93,
          "unit": "percent"
        },
        "p3": {
          "value": 11.37,
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
        },
        "p2": {
          "value": 65.62,
          "unit": "percent"
        },
        "p3": {
          "value": 12.25,
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
        },
        "p2": {
          "value": 70.31,
          "unit": "percent"
        },
        "p3": {
          "value": 13.12,
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
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 14,
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
        },
        "p2": {
          "value": 78.75,
          "unit": "percent"
        },
        "p3": {
          "value": 14.7,
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
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 15.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5879951aeb2e77bd9ea4403ced9a23a8f5d43a3576197f9affc588d8943563e2",
  "icon_path": null
}
```

### Excalibur

```json
{
  "ability_id": "101403",
  "slot": "ult",
  "name": "Excalibur",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "360",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "120",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        },
        "p2": {
          "value": 60.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 182,
          "unit": "percent"
        },
        "p2": {
          "value": 71.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 196,
          "unit": "percent"
        },
        "p2": {
          "value": 77,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 227.5,
          "unit": "percent"
        },
        "p2": {
          "value": 89.37,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 245,
          "unit": "percent"
        },
        "p2": {
          "value": 96.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 262.5,
          "unit": "percent"
        },
        "p2": {
          "value": 103.125,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 280,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 294,
          "unit": "percent"
        },
        "p2": {
          "value": 115.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 308,
          "unit": "percent"
        },
        "p2": {
          "value": 121,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "aeb0bd4951ce9bf83413d1f391264058f9808017ee7a99eb5a01b00162e6426d",
  "icon_path": null
}
```

### Dragon Reactor Core

```json
{
  "ability_id": "101404",
  "slot": "talent",
  "name": "Dragon Reactor Core",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
    }
  ],
  "description_sha256": "5ecaf761c75bfaa4150904e8f1870faf30979297d5c27e9f7307bb53f596db20",
  "icon_path": null
}
```

### Behold, the King of Knights

```json
{
  "ability_id": "101407",
  "slot": "technique",
  "name": "Behold, the King of Knights",
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
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk"
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
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "36f4018c31f0f2983f1cd1817a62e7a9693f6e166bb943dee0afc6c2e7e15384",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Knight of the Dragon",
    "mechanic_tags": [
      "atk",
      "crit_rate",
      "energy",
      "skill_points"
    ],
    "numeric_tokens": [
      "20%",
      "1"
    ],
    "description_sha256": "9d1bbcea09465eb7f36c4c16d16859a80cf225135f1c60e4a1a26cfbe69ca1ce"
  },
  {
    "requirement": "A4",
    "name": "Blessing of the Lake",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "120",
      "60%",
      "60%"
    ],
    "description_sha256": "7ca490d291d36e819bf2bf07668f055a58272d05c77c254e32bf4913e189b2d8"
  },
  {
    "requirement": "A6",
    "name": "Crown of the Star",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "50%",
      "2",
      "4%",
      "8"
    ],
    "description_sha256": "27edf342681d713376e5b6046559f0c8d2b8dc23f4224d54610066e7fc5e6cb2"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "The Lost White Walls",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "60%",
      "1"
    ],
    "description_sha256": "a462af4640928644654a386c120bdec329b826d913eec050732194cc0ee15479"
  },
  {
    "eidolon": 2,
    "name": "The Lost Oath of the Round Table",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "1%",
      "15",
      "7%"
    ],
    "description_sha256": "e245a09e4715875fb3652974bf86fecffc2d51a8fa03e6ddac6e23a1fa6e8e46"
  },
  {
    "eidolon": 3,
    "name": "A Wish Across Fifteen Centuries",
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
    "name": "The Saga of Sixteen Winter Days",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "8%",
      "4%",
      "3"
    ],
    "description_sha256": "7b6961d4530abafcba616757a2e3be5d136350e149d8fa644a3ed555914a17d5"
  },
  {
    "eidolon": 5,
    "name": "The Dreamed Utopian Dawn",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "2",
      "15"
    ],
    "description_sha256": "44510026b640c061e66a47941f11c1c4630d9468a08550a63ed1ea32fdb09b0c"
  },
  {
    "eidolon": 6,
    "name": "The Long Fated Night",
    "mechanic_tags": [
      "energy",
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "200",
      "300",
      "1",
      "3"
    ],
    "description_sha256": "a45dedde225ec32039f087d80204c6d10c0a9ec0fc560e94ec048dba3143aec4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
