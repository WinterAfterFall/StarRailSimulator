---
schema_version: "1.0.0"
unit_id: 84
name: "The Dahlia"
slug: "the-dahlia"
rarity: 5
element: "Fire"
path: "Nihility"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/the-dahlia"
source_record_updated_at: "February 8th, 2026"
dataset_snapshot: "2026-05-30"
---

# The Dahlia

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Dahlia.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review/calc patch 3.8) |

### Base Stats (Lv.80, ascended)
HP 1087 · ATK 679 · DEF 606 · SPD 96

> Nihility support สาย Super Break enabler + "Dance Partner" + weakness implant

---

### Basic ATK — Fiddle... Fissured Memory (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Lick... Enkindled Betrayal (Blast, Lv.10)
- กาง **Zone** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ The Dahlia)
- Fire DMG = **160% ATK** ใส่เป้าหมาย + ข้างเคียง
- ขณะ Zone: เพื่อนทุกคน Weakness Break Efficiency **+50%**; Toughness Reduction ที่ศัตรู (ยังไม่ broken) รับ → แปลงเป็น **Super Break DMG** ได้
- Energy +30 · Toughness 10 (+10)

### Ultimate — Wallow...Entombed Ash (AoE, 130 energy, Lv.10)
- ติด **"Wilt"** ศัตรูทุกตัว นาน 4 เทิร์น
- Fire DMG = **300% ATK** กระจายเท่ากันทุกศัตรู
- ศัตรูที่ Wilt: DEF **−18%** + ถูกยัด Weakness ตาม Type ของ "Dance Partner" ทุกคน
- Energy +5 · Toughness 20

### Talent — Who's Afraid of Constance? (Lv.10)
- เข้าฉาก → The Dahlia คืน Energy **35** + มอบ **"Dance Partner"** ให้ตัวเอง + เพื่อนที่ trigger การต่อสู้
- เมื่อไม่มี "Dance Partner" คนอื่นในสนาม → มอบให้ตัวเอง + เพื่อนที่ Break Effect สูงสุด
- หลัง "Dance Partner" ตีศัตรู Weakness Broken → Toughness Reduction ของการโจมตีนั้นแปลงเป็น **Super Break DMG 60%** 1 instance
- หลังศัตรูถูก "Dance Partner" คนอื่นโจมตี → The Dahlia ยิง Follow-Up ATK: **5 instance × 30% ATK** Fire DMG ใส่ศัตรูสุ่ม
  - แต่ละ instance ที่โดนศัตรู Weakness Broken → Toughness Reduction แปลงเป็น **Super Break DMG 200%**
  - trigger 1 ครั้ง/เทิร์น
- Energy +2 · Toughness 3

### Technique — The Heart Makes the Finest Tomb
- สร้าง Special Dimension 20 วิ (ศัตรูไม่โจมตีเพื่อน)
- เข้าฉากกับศัตรูใน Dimension → กาง Zone ของ Skill ทันที + แปลง Toughness Reduction จากการเข้าฉากเป็น Super Break DMG 60% กับศัตรู Weakness Broken

---

### Major Traces
- **A2 — Yet Another Funeral**: เข้าฉาก → เพื่อนคนอื่น Break Effect **+เท่ากับ 24% ของ BE ของ The Dahlia + 50%** นาน 1 เทิร์น. trigger อีกครั้ง (นาน 3 เทิร์น) เมื่อ The Dahlia รับ heal/Shield จากเพื่อน (ไม่ซ้ำในเทิร์นเดียว)
- **A4 — Lament, Lost Soul**: ใช้ Talent Follow-Up ATK → คืน Skill Point **1** ให้ทีม (ทุก ๆ 2 Follow-Up ATK)
- **A6 — Outgrow the Old, Espouse the New**: เมื่อเพื่อนยัด Weakness ให้ศัตรู → SPD **+30%** นาน 2 เทิร์น. ถ้าเพื่อน Fire ยัด Weakness ตอนโจมตี → หลังโจมตี ต่อเป้าที่โดนยัด → Fire Toughness Reduction คงที่ **20** + คืน Energy **10% ของ Max Energy** (cap รวม 50% Max Energy)

### Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · SPD +5 · Effect RES +18%

### Eidolons
- **E1**: apply Super Break DMG multiplier ของ Talent ให้เพื่อนทุกคน ("Dance Partner" ได้ **+40%** เพิ่ม). หลัง "Dance Partner" โจมตี → Toughness Reduction คงที่ = **25% ของ Max Toughness** ของศัตรู (min 10, max 300) 1 ครั้ง/ศัตรู (reset เมื่อศัตรูโดน killing blow)
- **E2**: ขณะ The Dahlia อยู่ในสนาม → ศัตรูทุกตัว All-Type RES **−20%**. ศัตรูเข้าฉาก → ติด "Wilt" ทันที นาน 3 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: Talent Follow-Up ATK instance **+5** (รวม 10) + แต่ละ hit → เป้าหมายรับดาเมจเพิ่ม **+12%** นาน 2 เทิร์น
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: "Dance Partner" Break Effect **+150%**. ใช้ Talent Follow-Up ATK → advance action ของ "Dance Partner" ทุกคน **20%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Dance Partner** = แกน: มอบตอนเข้าฉาก (self + trigger ally) หรือ self + BE สูงสุด; ได้ Super Break conversion 60% เมื่อตี broken enemy (E1 → apply ทีม, +40% Dance Partner, E6 BE +150%)
- **Talent FUA**: 5 hit (E4 10) × 30% ATK, ต่อ hit ที่โดน broken → Super Break 200%; trigger เมื่อ Dance Partner คนอื่นตีศัตรู (1/เทิร์น)
- **Super Break** ต้องมี model (f(toughness reduction, BE))
- **Ult "Wilt"**: DEF −18% + weakness implant ตาม Dance Partner types
- **Zone (Skill)**: WBE +50% + Super Break conversion แม้ยังไม่ broken
- **A2**: BE share 24%×BE + 50% ให้เพื่อน
- โค้ด: `Start_game_List` (`Dahlia.h:203`)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/the-dahlia — kit tab (review/calc patch 3.8, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 84,
  "name": "The Dahlia",
  "slug": "the-dahlia",
  "rarity": "5",
  "element": "Fire",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "December 17th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 148,
    "def_base": 82.5,
    "atk_base": 92.4,
    "speed_base": 96
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Break Effect",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "speed",
      "value": 5
    },
    "traceStat3": {
      "stat": "Effect RES",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Jennifer Losi",
    "kr": "Kim Do Hee (김도희)",
    "jpn": "Sasaki Mikoi (佐々木未来)",
    "cn": "Ruan Congqing (阮从青)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/the-dahlia",
  "source_record_updated_at": "February 8th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `132101` | Fiddle... Fissured Memory | Basic ATK | Single Target |
| `skill` | `132102` | Lick... Enkindled Betrayal | Skill | Blast |
| `ult` | `132103` | Wallow...Entombed Ash | Ultimate | AoE |
| `talent` | `132104` | Who's Afraid of Constance? | Talent | Defense |
| `technique` | `132107` | The Heart Makes the Finest Tomb | Technique | Impair |

## Ability records

### Fiddle... Fissured Memory

```json
{
  "ability_id": "132101",
  "slot": "basic",
  "name": "Fiddle... Fissured Memory",
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
  "description_sha256": "17917dbdee2220bf4b351c3f8447e681f8da4fbeea2c13b6c666e4aec13ffe2b",
  "icon_path": null
}
```

### Lick... Enkindled Betrayal

```json
{
  "ability_id": "132102",
  "slot": "skill",
  "name": "Lick... Enkindled Betrayal",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "30",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "weakness_break_efficiency",
    "dmg",
    "toughness",
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
  "description_sha256": "34765051f01b641985239dae263f556a044747e320bd1b22b6cd2bc47966385a",
  "icon_path": null
}
```

### Wallow...Entombed Ash

```json
{
  "ability_id": "132103",
  "slot": "ult",
  "name": "Wallow...Entombed Ash",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Fire",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "def",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 192,
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
          "value": 204,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 255,
          "unit": "percent"
        },
        "p2": {
          "value": 14.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 15.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 285,
          "unit": "percent"
        },
        "p2": {
          "value": 16.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 312,
          "unit": "percent"
        },
        "p2": {
          "value": 19,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 324,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 336,
          "unit": "percent"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 348,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 360,
          "unit": "percent"
        },
        "p2": {
          "value": 23,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ef934a2996ca9bb85822a410c79bb5625283992c56ddc3c2bf172e3d88f19319",
  "icon_path": null
}
```

### Who's Afraid of Constance?

```json
{
  "ability_id": "132104",
  "slot": "talent",
  "name": "Who's Afraid of Constance?",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Fire",
  "energy_gain": "2",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "9",
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
    }
  },
  "mechanic_tags": [
    "atk",
    "break_effect",
    "energy",
    "dmg",
    "toughness",
    "follow_up",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
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
          "value": 100,
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
        },
        "p2": {
          "value": 16.5,
          "unit": "percent"
        },
        "p3": {
          "value": 110,
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
        },
        "p2": {
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 120,
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
        },
        "p2": {
          "value": 19.5,
          "unit": "percent"
        },
        "p3": {
          "value": 130,
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
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
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
        },
        "p2": {
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
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
        },
        "p2": {
          "value": 24.375,
          "unit": "percent"
        },
        "p3": {
          "value": 162.5,
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
        },
        "p2": {
          "value": 26.25,
          "unit": "percent"
        },
        "p3": {
          "value": 175,
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
        },
        "p2": {
          "value": 28.125,
          "unit": "percent"
        },
        "p3": {
          "value": 187.5,
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
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 200,
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
        },
        "p2": {
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 210,
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
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 220,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 69,
          "unit": "percent"
        },
        "p2": {
          "value": 34.5,
          "unit": "percent"
        },
        "p3": {
          "value": 230,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
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
          "value": 250,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "16343c7e3f6a08bad49bb422e33d1038683282be2f16023e66072c4ba5bbc9f4",
  "icon_path": null
}
```

### The Heart Makes the Finest Tomb

```json
{
  "ability_id": "132107",
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
    "dmg",
    "toughness",
    "weakness"
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
  "description_sha256": "9ce98013675d621ad0044c88b40337eb3074adf919d7157ef08f1ac45fa92655",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Yet Another Funeral",
    "mechanic_tags": [
      "break_effect",
      "healing",
      "shield"
    ],
    "numeric_tokens": [
      "24%",
      "50%",
      "1",
      "3"
    ],
    "description_sha256": "26d06ecd4002b38af52793da3ef85372cf576d10fbfce24202b32d0115b6948b"
  },
  {
    "requirement": "A4",
    "name": "Lament, Lost Soul",
    "mechanic_tags": [
      "atk",
      "follow_up",
      "skill_points"
    ],
    "numeric_tokens": [
      "1",
      "2"
    ],
    "description_sha256": "45ee8d921074bece8a504eb42b3eac5cd24d3a4bbe12746ffd05de214814a457"
  },
  {
    "requirement": "A6",
    "name": "Outgrow the Old, Espouse the New",
    "mechanic_tags": [
      "spd",
      "energy",
      "energy_regen_rate",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "30%",
      "2",
      "20",
      "10%",
      "50%"
    ],
    "description_sha256": "5a31c05d3655b7b28b5b80f120c304f4209fc8828b627e55ee9e7ddbf6cb6b34"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "When a Bud Readies to Bloom",
    "mechanic_tags": [
      "dmg",
      "toughness"
    ],
    "numeric_tokens": [
      "40%",
      "25%",
      "10",
      "300"
    ],
    "description_sha256": "5b38aa6d855ed24a36b22cec70f670de06df970403b8c968f195da82ee4d428f"
  },
  {
    "eidolon": 2,
    "name": "Fresh, Ethereal, and Beloved",
    "mechanic_tags": [
      "res"
    ],
    "numeric_tokens": [
      "20%",
      "3"
    ],
    "description_sha256": "b48d2ac890e8bb331c78a3c11c65837525d7be8d1138858c05b2c4701bfce53f"
  },
  {
    "eidolon": 3,
    "name": "Pity Its Petals Thin as Mist",
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
    "name": "Pity Its Heart Gnawed by Worms",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "5",
      "12%",
      "2"
    ],
    "description_sha256": "556d9edeb97f9fbc837d07b3fc5cef92aa1a75879e235f70001ed04a49777deb"
  },
  {
    "eidolon": 5,
    "name": "Fallen, Decayed, and Despised",
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
    "name": "And Yet, Always, Deathly Beautiful",
    "mechanic_tags": [
      "atk",
      "break_effect",
      "action_advance",
      "follow_up"
    ],
    "numeric_tokens": [
      "150%",
      "20%"
    ],
    "description_sha256": "a6fbe9b7dbec710df78ea7d2215601ff453fdae2f8cabfc7e3d7845255148a9c"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
