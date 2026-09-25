---
schema_version: "1.0.0"
unit_id: 85
name: "Yao Guang"
slug: "yao-guang"
rarity: 5
element: "Physical"
path: "Elation"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/yao-guang"
source_record_updated_at: "March 2nd, 2026"
dataset_snapshot: "2026-05-30"
---

# Yao Guang

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Elation/YaoGuang.h` (โค้ดเรียก `"Yao Guang"`) |
| ธาตุ | **Physical** |
| Path | **Elation** |
| ระดับ | 5★ |
| Energy Ultimate | 180 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1242 · ATK 465 · DEF 654 · SPD 101

> Elation support/amplifier — Zone + Punchline + "Great Boon" follow-up

---

### Basic ATK — Whistlebolt Sings Joy (Blast, Lv.6)
- Physical DMG หลัก = **90% ATK**, ข้างเคียง = **30% ATK**
- Energy จาก Basic ATK เพิ่มเป็น **30**
- Toughness 10 (+5)

### Skill — Decalight Unveils All (Support, Lv.10)
- กาง **Zone** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Yao Guang)
- ขณะ Zone active: เพื่อนทุกคน Elation **+เท่ากับ 20% ของ Elation ของ Yao Guang**
- หลัง Yao Guang ใช้ BA/Skill → Punchline **+3**
- Energy +30

### Ultimate — Hexagram of Feathered Fortune (Support, 180 energy, Lv.10)
- Punchline **+5**
- Aha ได้เทิร์นพิเศษทันที 1 ครั้ง โดยนับ Punchline คงที่ **20** (E1 → 40) — เทิร์นนี้ไม่กิน Punchline
- เพื่อนทุกคน All-Type RES PEN **+20%** นาน 3 เทิร์น
- Energy +5

### Talent — Behold Wherever Light Unfolds (Support, Lv.10)
- ขณะถือ **"Certified Banger"**:
  - หลังเพื่อนโจมตี → trigger **"Great Boon"**: +1 instance ของ **20% Elation DMG** (Type ตามผู้โจมตี) ใส่เป้าหมายที่โดนสุ่ม 1 ตัว
  - ถ้าการโจมตีนั้นกิน Skill Point → trigger "Great Boon" เพิ่มอีก 1 ครั้ง
  - ถ้า Elation ของผู้โจมตี < Elation ของ Yao Guang → instance นี้ใช้ Elation ของ Yao Guang คำนวณ
- "Great Boon" ไม่นับเป็น 1 การโจมตี

### Technique — Untethered Glimmer Sails Far
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป trigger Skill อัตโนมัติ 1 ครั้ง โดยไม่กิน Skill Point

### Elation Skill — Let Thy Fortune Burst in Flames (AoE, Lv.10)
- ติด **"Woe's Whisper"** ศัตรูทุกตัว นาน 3 เทิร์น → รับดาเมจเพิ่ม **16%**
- **100% Physical Elation DMG** AoE + **5 instance × 20% Physical Elation DMG** ใส่ศัตรูสุ่ม
- Energy +5 · Toughness 5 (+20)

---

### Major Traces
- **A2 — Amaze-In Grace**: SPD ≥ 120 → Elation **+30%**; ทุก 1 SPD ที่เกิน → Elation **+1%** (นับ SPD ส่วนเกินสูงสุด 200)
- **A4 — Poised and Sated**: CRIT DMG **+60%**. หลังใช้ Elation Skill → คืน Skill Point **1** ให้ทีม
- **A6 — Felicity Ensemble**: เมื่อ Yao Guang ได้ "Certified Banger" → duration **+1 เทิร์น**

### Minor Traces (รวมทั้งหมด)
CRIT Rate +18.7% · SPD +9 · Elation +10%

### Eidolons
- **E1**: Aha extra turn จาก Ult → Punchline คงที่เพิ่มเป็น **40**. เมื่อสร้าง Elation DMG → เพื่อนทุกคนเพิกเฉย DEF **20%**
- **E2**: ขณะ Zone active → เพื่อนทุกคน SPD **+12%** + Elation **+16%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Elation Skill Lv. +1
- **E4**: ใน Aha extra turn จาก Ult ของ Yao Guang → ดาเมจ Elation Skill ของเพื่อนทุกคน = **150%** ของเดิม
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Elation Skill Lv. +1
- **E6**: เพื่อนทุกคน Elation DMG **+25%**. multiplier ของ Elation Skill ของ Yao Guang **+100%** ของเดิม

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Elation share**: Zone ให้เพื่อน +20% ของ Elation ของ Yao Guang (E2 +16% เพิ่ม); "Great Boon" ใช้ Elation ที่สูงกว่าคำนวณ
- **A2**: Elation scaling จาก SPD (≥120 → +30%, +1%/SPD เกิน, cap 200)
- **Punchline**: Skill BA/Skill +3, Ult +5; Aha extra turn นับ Punchline คงที่ 20/40
- **Great Boon**: follow-up 20% Elation DMG ต่อการโจมตีของเพื่อน + ซ้ำถ้ากิน SP — เข้ากับ `When_attack_List` / `AfterAhaInstant_List` ในโค้ด
- โค้ด `Start_game_List`: ถ้า `Technique` → สร้าง AllyBuffAction "YG Skill" (genPunchLine 3, energy 30, E2 buff SPD 12/Elation 16, Elation buff คำนวณ `calculateElationForBuff`), `addToActionBar` + `Deal_damage()` (self-flush)
- Elation Skill: Woe's Whisper (+16% vul) + A4 คืน SP 1

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/yao-guang — kit tab (review/calc patch 4.0, profile 15/Jun/2026)

## Character record

```json
{
  "unit_id": 85,
  "name": "Yao Guang",
  "slug": "yao-guang",
  "rarity": "5",
  "element": "Physical",
  "path": "Elation",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "February 12th, 2026",
  "is_released": true,
  "ultimate_energy_cost": "180",
  "base_stats": {
    "hp_base": 169,
    "def_base": 89.1,
    "atk_base": 63.36,
    "speed_base": 101
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 18.7
    },
    "traceStat2": {
      "stat": "speed",
      "value": 9
    },
    "traceStat3": {
      "stat": "Elation",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "이슬 (Lee Seul)",
    "jpn": "花澤 香菜 (Hanazawa Kana)",
    "cn": "秦紫翼 (Qin Ziyi)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/yao-guang",
  "source_record_updated_at": "March 2nd, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150201` | Whistlebolt Sings Joy | Basic ATK | Blast |
| `skill` | `150202` | Decalight Unveils All | Skill | Support |
| `ult` | `150203` | Hexagram of Feathered Fortune | Ultimate | Support |
| `talent` | `150204` | Behold Wherever Light Unfolds | Talent | Support |
| `technique` | `150207` | Untethered Glimmer Sails Far | Technique | Impair |
| `supplementary` | `150210` | Let Thy Fortune Burst in Flames | Elation Skill | AoE |

## Ability records

### Whistlebolt Sings Joy

```json
{
  "ability_id": "150201",
  "slot": "basic",
  "name": "Whistlebolt Sings Joy",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Blast",
  "element": "Physical",
  "energy_gain": "20",
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
    "energy",
    "energy_regen_rate",
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
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "a65668b1db587a82c983b81b5157a6f99dc3632e30eee739213a3190956e717d",
  "icon_path": null
}
```

### Decalight Unveils All

```json
{
  "ability_id": "150202",
  "slot": "skill",
  "name": "Decalight Unveils All",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Physical",
  "energy_gain": "30",
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
    "atk",
    "elation"
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
          "value": 11,
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
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
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
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
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
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
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
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
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
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
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
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 24,
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
        }
      }
    }
  ],
  "description_sha256": "b9115db0d7d9213e4b47e29c09c32066f96f3fd65c3d9036a5bcf6048fd741e7",
  "icon_path": null
}
```

### Hexagram of Feathered Fortune

```json
{
  "ability_id": "150203",
  "slot": "ult",
  "name": "Hexagram of Feathered Fortune",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "180",
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
    "res_pen",
    "res",
    "elation"
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
          "value": 11,
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
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
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
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
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
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
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
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
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
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
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
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 24,
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
        }
      }
    }
  ],
  "description_sha256": "cb61d87db9e31ef646e195d1d4c24fe13f4a223bfb3607f3c1d8d67523c1e699",
  "icon_path": null
}
```

### Behold Wherever Light Unfolds

```json
{
  "ability_id": "150204",
  "slot": "talent",
  "name": "Behold Wherever Light Unfolds",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Physical",
  "energy_gain": null,
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
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 11,
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
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
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
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
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
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
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
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 20,
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
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
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
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 24,
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
        }
      }
    }
  ],
  "description_sha256": "185a491ca7c05b407bafeb769580cfbaed38d3ea3dd4034349e48f9ca21db2c9",
  "icon_path": null
}
```

### Untethered Glimmer Sails Far

```json
{
  "ability_id": "150207",
  "slot": "technique",
  "name": "Untethered Glimmer Sails Far",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
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
  "description_sha256": "55a73b8eb6281eb9323d0944ee394fed340c7596324b25a1d1e819c7a1ccb25e",
  "icon_path": null
}
```

### Let Thy Fortune Burst in Flames

```json
{
  "ability_id": "150210",
  "slot": "supplementary",
  "name": "Let Thy Fortune Burst in Flames",
  "type_code": "BPSkill",
  "type_label": "Elation Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
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
    "elation"
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
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 55,
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
          "value": 60,
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
          "value": 65,
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
          "value": 70,
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
          "value": 75,
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
          "value": 81.25,
          "unit": "percent"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 87.5,
          "unit": "percent"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 93.75,
          "unit": "percent"
        },
        "p2": {
          "value": 18.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 115,
          "unit": "percent"
        },
        "p2": {
          "value": 23,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 125,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9f44da19b7c28e3bb78ec6eca81759c3c95053cb9563e8970874418b1c256f17",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Amaze-In Grace",
    "mechanic_tags": [
      "spd",
      "elation"
    ],
    "numeric_tokens": [
      "120",
      "30%",
      "1",
      "1%",
      "200"
    ],
    "description_sha256": "6e25e1b42b608251f959ccf5f472e182ae9d0790d9bc188ea1655bf85c9ab7eb"
  },
  {
    "requirement": "A4",
    "name": "Poised and Sated",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "skill_points",
      "elation"
    ],
    "numeric_tokens": [
      "60%",
      "1"
    ],
    "description_sha256": "07e0d7481b522e9521b85834c032c19d7b8aedb0c02bfd1ddb9c4c5fc08b9f0f"
  },
  {
    "requirement": "A6",
    "name": "Felicity Ensemble",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "2616681bb45827ddf788faf7a30fc7fa77d38b3a868d28f0c81af09ed3c09f94"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Chuckle Chimes Where Jade Falls",
    "mechanic_tags": [
      "def",
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "40",
      "20%"
    ],
    "description_sha256": "5acd8287d2de2fe4d06fb67d27a0aaa17e432bacb71d233b824e16393832b602"
  },
  {
    "eidolon": 2,
    "name": "Blind Arrows Guided by Feathers",
    "mechanic_tags": [
      "spd",
      "elation"
    ],
    "numeric_tokens": [
      "12%",
      "16%"
    ],
    "description_sha256": "8678cb5234110a8edc5f31d1696dd620a2da244a6650d83e97ed1ffd46c5625e"
  },
  {
    "eidolon": 3,
    "name": "Auspices Mirrored In Decalight",
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
    "name": "Threads of Fate Colored by Plumes",
    "mechanic_tags": [
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "150%"
    ],
    "description_sha256": "d62a05554a1c22a3ee5c6682d1e739701f3ec48bab7469d75628243c5a41ac81"
  },
  {
    "eidolon": 5,
    "name": "Bejeweled in Radiant Grace",
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
    "name": "Ferried Along the Astral Arc",
    "mechanic_tags": [
      "dmg",
      "elation"
    ],
    "numeric_tokens": [
      "25%",
      "100%"
    ],
    "description_sha256": "b4863b3c4d76fecf0d8717a763df64a9b1a22fbf37dfc8ebc9834fd8957fefa1"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
