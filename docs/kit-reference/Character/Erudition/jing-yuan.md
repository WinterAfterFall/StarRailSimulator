---
schema_version: "1.0.0"
unit_id: 22
name: "Jing Yuan"
slug: "jing-yuan"
rarity: 5
element: "Lightning"
path: "Erudition"
role: "Main DPS"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/jing-yuan"
source_record_updated_at: "March 24th, 2026"
dataset_snapshot: "2026-05-30"
---

# Jing Yuan

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/Jingyuan.h` |
| ธาตุ | **Lightning** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 2.7 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1164 · ATK 698 · DEF 485 · SPD 99

> Erudition DPS สาย summon "Lightning-Lord" (LL)

---

### Basic ATK — Glistening Light (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Rifting Zenith (AoE, Lv.10)
- Lightning DMG = **100% ATK** AoE
- เพิ่ม **Hits Per Action ของ Lightning-Lord +2** สำหรับเทิร์นถัดไป
- Energy +30 · Toughness 10

### Ultimate — Lightbringer (AoE, 130 energy, Lv.10)
- Lightning DMG = **200% ATK** AoE
- เพิ่ม **Hits Per Action ของ Lightning-Lord +3** สำหรับเทิร์นถัดไป
- Energy +5 · Toughness 20

### Talent — Prana Extirpated (Bounce, Lv.10)
- เรียก **Lightning-Lord** ต้นการต่อสู้: base SPD **60**, base Hits Per Action **3**
- LL action นับเป็น follow-up attack: แต่ละ hit = **66% ATK** Lightning DMG ใส่ศัตรูสุ่ม 1 ตัว + ศัตรูข้างเคียงรับ **25% ของดาเมจที่ทำกับเป้าหมาย**
- Hits Per Action สูงสุด **10**; ทุก +1 hit → LL SPD +10. หลัง LL action จบ → SPD และ Hits Per Action กลับค่า base
- Jing Yuan ถูกน็อค → LL หาย; Jing Yuan ติด CC → LL ทำ action ไม่ได้
- Toughness 5 (ต่อ hit)

### Technique — Spirit Invocation
- หลังใช้ Technique → LL Hits Per Action ในเทิร์นแรกของการต่อสู้ถัดไป **+3**

---

### Major Traces
- **A2 — Battalia Crush**: ถ้า LL Hits Per Action ≥ 6 ในเทิร์นถัดไป → LL CRIT DMG **+25%** สำหรับเทิร์นนั้น
- **A4 — Savant Providence**: ต้นการต่อสู้ → คืน Energy **15** ทันที
- **A6 — War Marshal**: หลังใช้ Skill → CRIT Rate **+10%** นาน 2 เทิร์น

### Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · ATK +28% · DEF +12.5%

### Eidolons
- **E1**: เมื่อ LL โจมตี → multiplier ใส่ศัตรูข้างเคียงเพิ่มอีก **25% ของ multiplier ที่ใส่เป้าหมาย**
- **E2**: หลัง LL action → ดาเมจจาก BA/Skill/Ult ของ Jing Yuan **+20%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ต่อ hit ของ LL → Jing Yuan คืน Energy **2**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ทุก hit ของ LL → เป้าหมาย Vulnerable รับดาเมจเพิ่ม **12%** จนจบเทิร์นของ LL stack 3 ครั้ง

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Lightning-Lord** = summon แยก action bar: base SPD 60, base HPA 3, SPD = 60 + 10×(HPA−3)
- **HPA**: base 3 + Skill(+2) + Ult(+3) + Technique(+3 เทิร์นแรก) สำหรับ **เทิร์นถัดไปเท่านั้น** แล้ว reset — สะสมได้จนถึง cap 10
- LL hit = FUA 66% ATK ต่อ hit ใส่ศัตรูสุ่ม + blast 25% ให้ข้างเคียง (E1: +25% ของ main multiplier)
- **A2**: LL CRIT DMG +25% ถ้า HPA ≥ 6
- โค้ด: `Start_game_List` (`Jingyuan.h:97`, `JYptr`) — summon LL + Technique HPA
- ต้อง track "next turn HPA" แยกจาก current

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/jing-yuan — kit tab (review patch 2.7, calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 22,
  "name": "Jing Yuan",
  "slug": "jing-yuan",
  "rarity": "5",
  "element": "Lightning",
  "path": "Erudition",
  "default_role": "Main DPS",
  "affiliation": "Xianzhou Luofu",
  "release_date": "May 17th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 158.4,
    "def_base": 66,
    "atk_base": 95.04,
    "speed_base": 99
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "critRate",
      "value": 12
    },
    "traceStat2": {
      "stat": "atk",
      "value": 28
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "Alejandro Saab",
    "kr": "Ryu Seung-gon (류승곤)",
    "jpn": "Ono Daisuke (小野大輔)",
    "cn": "Sun Ye (孫曄)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/jing-yuan",
  "source_record_updated_at": "March 24th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `120401` | Glistening Light | Basic ATK | Single Target |
| `skill` | `120402` | Rifting Zenith | Skill | AoE |
| `ult` | `120403` | Lightbringer | Ultimate | AoE |
| `talent` | `120404` | Prana Extirpated | Talent | Bounce |
| `technique` | `120407` | Spirit Invocation | Technique | Enhance |

## Ability records

### Glistening Light

```json
{
  "ability_id": "120401",
  "slot": "basic",
  "name": "Glistening Light",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Thunder",
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
  "description_sha256": "68915605a8131b36703066defa8b92fde387c8a0514bde90ea5dc3af30718ec4",
  "icon_path": "icon/skill/1204_basic_atk.png"
}
```

### Rifting Zenith

```json
{
  "ability_id": "120402",
  "slot": "skill",
  "name": "Rifting Zenith",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Thunder",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
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
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b6d0a7b6ff6e9530cb528bf0a750e31ce1f7ec3542d03acaa87081fccebb4fb1",
  "icon_path": "icon/skill/1204_skill.png"
}
```

### Lightbringer

```json
{
  "ability_id": "120403",
  "slot": "ult",
  "name": "Lightbringer",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Thunder",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": "60",
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
    "atk",
    "dmg"
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
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
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b6d0a7b6ff6e9530cb528bf0a750e31ce1f7ec3542d03acaa87081fccebb4fb1",
  "icon_path": "icon/skill/1204_ultimate.png"
}
```

### Prana Extirpated

```json
{
  "ability_id": "120404",
  "slot": "talent",
  "name": "Prana Extirpated",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Thunder",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "p5": {
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "dmg",
    "follow_up",
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 36.3,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 39.6,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 42.9,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 46.2,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 49.5,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 53.63,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 57.75,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 61.88,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 69.3,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 72.6,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 75.9,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 79.2,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "scalar"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        },
        "p5": {
          "value": 25,
          "unit": "percent"
        },
        "p6": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "4f826c1d11b84163e5eb5d344f5fb0379ac78909b4053ff3c2d1d675bc36f8e1",
  "icon_path": "icon/skill/1204_talent.png"
}
```

### Spirit Invocation

```json
{
  "ability_id": "120407",
  "slot": "technique",
  "name": "Spirit Invocation",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "6749796d8aa473f0b9156382b1d5828b2b01787055591fc75c384b00ba1e89ef",
  "icon_path": "icon/skill/1204_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Battalia Crush",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "6",
      "25%"
    ],
    "description_sha256": "deb4f91d32d0fb4797c631d51f66ade3248952bb1a35245dae3de9be0f4f562d"
  },
  {
    "requirement": "A4",
    "name": "Savant Providence",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "15"
    ],
    "description_sha256": "49cd4ce181fe9ef5e523e5e955c0ba45a10293d800b6cada079d46e153b03889"
  },
  {
    "requirement": "A6",
    "name": "War Marshal",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "10%",
      "2"
    ],
    "description_sha256": "42c6d329b542fd05b8371ba11ae3657819b018228607ac8debe91a314bbeb834"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Slash, Seas Split",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "4d9e02681be6d6671faa18e8f0ef7011ced96ffdac6089827e0c4507e458c962"
  },
  {
    "eidolon": 2,
    "name": "Swing, Skies Squashed",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "2"
    ],
    "description_sha256": "8eece55558024c774c0bcbf25f94447211c622d81d916f4044e15500910a2925"
  },
  {
    "eidolon": 3,
    "name": "Strike, Suns Subdued",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "bc9b09b7015c543b22391cfc36d3f3dbfe0ab3ca7a74e98b7e29242a899157fb"
  },
  {
    "eidolon": 4,
    "name": "Spin, Stars Sieged",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "f0b94820226cbef870ed9c24b958e2b190fb2e56b87a0e9584d47c6c90d6a035"
  },
  {
    "eidolon": 5,
    "name": "Stride, Spoils Seized",
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
    "name": "Sweep, Souls Slain",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "12%",
      "3"
    ],
    "description_sha256": "adbdfb659a4d95eb1d2a9783d4cb24941c09687efe4fafd432b8250633b4b5b7"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
