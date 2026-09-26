---
schema_version: "1.0.0"
unit_id: 70
name: "Tribbie"
slug: "tribbie"
rarity: 5
element: "Quantum"
path: "Harmony"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/tribbie"
source_record_updated_at: "March 17th, 2025"
dataset_snapshot: "2026-05-30"
---

# Tribbie

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Tribbie.h` |
| ธาตุ | **Quantum** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review/calc patch 3.1) |

### Base Stats (Lv.80, ascended)
HP 1047 · ATK 523 · DEF 727 · SPD 96

> Harmony support/sub-DPS สาย HP-scaling + RES PEN + vulnerability Zone (ดาเมจสเกลกับ Max HP)

---

### Basic ATK — Hundred Rockets (Blast, Lv.6)
- Quantum DMG หลัก = **30% Max HP**, ข้างเคียง = **15% Max HP**
- Energy +20 · Toughness 10 (+5)

### Skill — Where'd the Gifts Go (Support, Lv.10)
- ได้ **"Numinosity"** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Tribbie)
- ขณะมี Numinosity: เพื่อนทุกคน All-Type RES PEN **+24%**
- Energy +30

### Ultimate — Guess Who Lives Here (AoE, 120 energy, Lv.10)
- กาง **Zone** + Quantum DMG = **30% Max HP** AoE
- ขณะ Zone: ศัตรูรับดาเมจเพิ่ม **+30%**
- หลังเพื่อนโจมตี ต่อศัตรูที่โดน 1 ตัว → Quantum Additional DMG = **12% Max HP** ใส่ศัตรูที่ HP สูงสุดในกลุ่มที่โดน
- Zone นาน 2 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Tribbie)
- Energy +5 · Toughness 20

### Talent — Busy as Tribbie (AoE, Lv.10)
- หลังเพื่อนคนอื่นใช้ Ultimate → Tribbie ยิง Follow-up ATK: Quantum DMG = **18% Max HP** AoE
- trigger ได้ 1 ครั้ง/ตัวละคร; เมื่อ Tribbie ใช้ Ult → รีเซ็ตตัวนับของเพื่อนคนอื่น
- ถ้าเป้าตายก่อนยิง → ยิงใส่ศัตรูใหม่ที่เข้าฉาก
- Energy +5 · Toughness 5

### Technique — If You're Happy and You Know It
- หลังใช้ Technique + เข้าฉาก → ได้ "Numinosity" นาน 3 เทิร์น

---

### Major Traces
- **A2 — Lamb Outside the Wall...**: หลังยิง Talent Follow-up ATK → Tribbie +DMG **72%** stack 3 ครั้ง นาน 3 เทิร์น
- **A4 — Glass Ball with Wings!**: ขณะ Zone → Tribbie Max HP **+เท่ากับ 9% ของผลรวม Max HP ของเพื่อนทุกคน**
- **A6 — Pebble at Crossroads?**: ต้นการต่อสู้ → คืน Energy **30**. หลังเพื่อนโจมตี → คืน Energy **1.5 ต่อศัตรูที่โดน**

### Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · CRIT Rate +12% · HP +10%

### Eidolons
- **E1**: ขณะ Zone หลังเพื่อนโจมตีศัตรู → True DMG = **24% ของดาเมจรวมของการโจมตีนั้น** ใส่เป้าที่โดน Zone Additional DMG
- **E2**: Zone Additional DMG เพิ่มเป็น **120%** ของเดิม + ยิงเพิ่มอีก 1 instance
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: ขณะ Numinosity → ดาเมจเพื่อนทุกคนเพิกเฉย DEF **18%**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: หลัง Tribbie ใช้ Ult → ยิง Talent Follow-up ATK ใส่ศัตรูทุกตัว. Talent Follow-up ATK DMG **+729%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ Max HP** (BA 30/15, Ult 30, Zone Add 12, Talent FUA 18 — ทั้งหมด % Max HP)
- **A4**: Max HP ของ Tribbie += 9% × Σ(Max HP เพื่อน) ขณะ Zone — ต้อง re-eval
- **Zone**: vulnerability +30% + Additional DMG 12% Max HP ต่อการโจมตีของเพื่อน (E2 ×1.2 + extra instance)
- **Talent FUA**: trigger ต่อเพื่อน Ult (1/ตัว, reset เมื่อ Tribbie Ult), E6 → Tribbie Ult ก็ยิงเอง +729%
- **Numinosity (Skill)**: RES PEN +24% ทีม (E4 DEF ignore 18%)
- **A6 energy**: +30 start + 1.5/hit จากเพื่อน
- โค้ด: `Start_game_List` (`Tribbie.h:142`, `TBptr`) + `Tribbie_LC.h` มี Start_game entry

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/tribbie — kit tab (review/calc patch 3.1, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 70,
  "name": "Tribbie",
  "slug": "tribbie",
  "rarity": "5",
  "element": "Quantum",
  "path": "Harmony",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "February 26th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "120",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 99,
    "atk_base": 71.28,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT DMG",
      "value": 37.3
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
    "en": "-",
    "kr": "Yeon-ji Bang (방연지)",
    "jpn": "Tono Hikaru (远野光)",
    "cn": "Cai Shujin (蔡书瑾)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/tribbie",
  "source_record_updated_at": "March 17th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140301` | Hundred Rockets | Basic ATK | Blast |
| `skill` | `140302` | Where'd the Gifts Go | Skill | Support |
| `ult` | `140303` | Guess Who Lives Here | Ultimate | AoE |
| `talent` | `140304` | Busy as Tribbie | Talent | AoE |
| `technique` | `140307` | If You're Happy and You Know It | Technique | Enhance |

## Ability records

### Hundred Rockets

```json
{
  "ability_id": "140301",
  "slot": "basic",
  "name": "Hundred Rockets",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Blast",
  "element": "Quantum",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "15",
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
    "max_hp",
    "dmg"
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
          "value": 7.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
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
      "source_row": 4,
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
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 27,
          "unit": "percent"
        },
        "p2": {
          "value": 13.5,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "percent"
        },
        "p2": {
          "value": 16.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        },
        "p2": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2ae61ba10dfe4aa9a6f5bf20644a6bbff2870f9b4e957a888380c12e12a62380",
  "icon_path": null
}
```

### Where'd the Gifts Go

```json
{
  "ability_id": "140302",
  "slot": "skill",
  "name": "Where'd the Gifts Go",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
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
    "res_pen",
    "res"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 19.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c4ed48c1223622ebbf6b71818a8c865a6b76e43c02fd0a34339530b68880cec4",
  "icon_path": null
}
```

### Guess Who Lives Here

```json
{
  "ability_id": "140303",
  "slot": "ult",
  "name": "Guess Who Lives Here",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "120",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "max_hp",
    "dmg"
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
          "value": 6,
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
        },
        "p2": {
          "value": 6.6,
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
        },
        "p2": {
          "value": 7.2,
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
        },
        "p2": {
          "value": 7.8,
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
        },
        "p2": {
          "value": 8.4,
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
        },
        "p2": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.375,
          "unit": "percent"
        },
        "p2": {
          "value": 9.75,
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
        },
        "p2": {
          "value": 10.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.125,
          "unit": "percent"
        },
        "p2": {
          "value": 11.25,
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
        },
        "p2": {
          "value": 12,
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
        },
        "p2": {
          "value": 12.6,
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
        },
        "p2": {
          "value": 13.2,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "fd35db9bf3980b2a3564c6ff1d00b5c009ae710a89bc93353f00eb4921495815",
  "icon_path": null
}
```

### Busy as Tribbie

```json
{
  "ability_id": "140304",
  "slot": "talent",
  "name": "Busy as Tribbie",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "15",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 9.9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 11.7,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 12.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 13.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 14.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 15.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 16.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 18.9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 19.8,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b01b0155fa3936583f4af4849635a7dd7c60a7e62e49a0fc3e2567d8e7e05b7d",
  "icon_path": null
}
```

### If You're Happy and You Know It

```json
{
  "ability_id": "140307",
  "slot": "technique",
  "name": "If You're Happy and You Know It",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
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
          "value": 10,
          "unit": "scalar"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 0.4,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b7d81a6705c5aed88b7630b6d9b071bb88bd159c81516135fc758d8d16b72d2b",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Lamb Outside the Wall...",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "72%",
      "3",
      "3"
    ],
    "description_sha256": "113267fc61844b6d2f9898b62cb14367092aff4a2f1bfc19a42332b05b1e5fcd"
  },
  {
    "requirement": "A4",
    "name": "Glass Ball with Wings!",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "9%"
    ],
    "description_sha256": "6547b611dfaeaa766f9410779c40d0ce534ae1ed0f13f3375d3b9d6ab9b7e596"
  },
  {
    "requirement": "A6",
    "name": "Pebble at Crossroads?",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "30",
      "1.5"
    ],
    "description_sha256": "01e3a2a621d988ab755158f8b761f152865812a043b1a79b62d32c7d0c989e6e"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Rite of Sugar Scoop",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "24%"
    ],
    "description_sha256": "18bb6087439a47dc65237bb87f1ecdb1895aa4d0dcd82abb1e066f7bd277c315"
  },
  {
    "eidolon": 2,
    "name": "Guide of Dream Tour",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "120%",
      "1"
    ],
    "description_sha256": "d7436e98a6168f65d310fe3d92346170454da5fdc2fb3682f946a21337292904"
  },
  {
    "eidolon": 3,
    "name": "Trove of Morning Glow",
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
    "name": "Peace of Empathy Bond",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "18%"
    ],
    "description_sha256": "0c19ecacf1b7c502ae2282f6a397e752c171c56d611f9c66e7ba709f79b837ea"
  },
  {
    "eidolon": 5,
    "name": "Clock of Wonder Origin",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "4c910ab9157733f3234ecdaa8bba52b244d201a478bad2528e5caf200f7c4227"
  },
  {
    "eidolon": 6,
    "name": "Morrow of Star Shine",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "729%"
    ],
    "description_sha256": "cd681c3ba57814f397bf396378e8bc82a4801e497b62bad1d94a262751abdb12"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
