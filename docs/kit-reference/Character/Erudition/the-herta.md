---
schema_version: "1.0.0"
unit_id: 67
name: "The Herta"
slug: "the-herta"
rarity: 5
element: "Ice"
path: "Erudition"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/the-herta"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# The Herta

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Erudition/The_Herta.h` |
| ธาตุ | **Ice** |
| Path | **Erudition** |
| ระดับ | 5★ |
| Energy Ultimate | 220 |
| อ้างอิง | prydwen.gg (review/calc patch 3.0) |

### Base Stats (Lv.80, ascended)
HP 1164 · ATK 679 · DEF 485 · SPD 99

> Erudition hypercarry สาย "Interpretation" stack

---

### Basic ATK — Did You Get It (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Big Brain Energy (Blast, Lv.10)
- Ice DMG = **70% ATK** ใส่เป้าหมาย + ติด **"Interpretation" 1 stack**
- Ice DMG = **70% ATK** ใส่เป้าหมายที่โดน + ข้างเคียง — **ทำซ้ำ 2 ครั้ง**
- Energy +30 · Toughness 15 (+5)

### Skill (Enhanced) — Hear Me Out (Blast, Lv.10)
- กิน **"Inspiration" 1 stack**
- Ice DMG = **80% ATK** ใส่เป้าหมาย + ติด "Interpretation" 1 stack
- Ice DMG = **80% ATK** ใส่เป้าหมาย + ข้างเคียง — ทำซ้ำ 2 ครั้ง
- สุดท้าย Ice DMG = **40% ATK** ใส่ศัตรูทุกตัว
- Energy +30 · Toughness 20 (+5)

### Ultimate — Told Ya! Magic Happens (AoE, 220 energy, Lv.10)
- จัดเรียง "Interpretation" stack ใหม่ ย้ายไปกอง Elite+ ก่อน
- Ice DMG = **200% ATK** AoE
- The Herta ATK **+80%** นาน 3 เทิร์น
- หลังใช้ → action ทันที + ได้ **"Inspiration" 1 stack** (สูงสุด 4) — ขณะมี Inspiration → Skill เป็น "Hear Me Out"
- Energy +5 · Toughness 20

### Talent — Hand Them Over (Lv.10)
- ศัตรูเข้าฉาก → ติด "Interpretation" 1 stack
- ต้นแต่ละ wave → ติด **"Interpretation" 25 stack** ใส่ศัตรูสุ่ม (Elite+ ก่อน)
- เมื่อ Enhanced Skill เป้าหมายหลักมี "Interpretation" → multiplier เพิ่ม ต่อ stack **+8%/+4%** (หลัก/รอง)
  - ถ้าในทีมมี Erudition ≥ 2 → ต่อ stack เพิ่มอีก **+8%/+4%**
- "Interpretation" สูงสุด **42 stack**
- ใช้ Enhanced Skill → reset "Interpretation" ของเป้าหมายหลักเป็น **1** (E1 → 15)
- ศัตรูออก/ตาย → "Interpretation" ย้าย (Elite+ ก่อน)
- Energy +5

### Technique — Vibe Checker
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป ATK **+60%** นาน 2 เทิร์น

---

### Major Traces
- **A2 — Aloofly Honest**: เพื่อนโจมตี → ติด "Interpretation" 1 stack ให้ศัตรูที่โดน. หลังโจมตี ต่อเป้าหมายที่โดน → คืน Energy คงที่ **3** (นับสูงสุด 5 เป้า). ใช้ Enhanced Skill ถ้าเป้าหมายหลักมี Interpretation ครบ 42 → The Herta Ice DMG **+50%** จนจบการโจมตี
- **A4 — Message From Beyond the Veil**: เข้าฉาก ถ้าทีมมี Erudition ≥ 2 → เพื่อนทุกคน CRIT DMG **+80%**, A2 นับเป้าอย่างน้อย 3, หลังโจมตี → ติด Interpretation 1 stack ให้ศัตรูที่มี stack สูงสุด (+2 stack ถ้าผู้โจมตีเป็น Erudition)
- **A6 — Starved Landscape of Vacua**: ต่อ 1 Interpretation ที่ยัดให้ศัตรู → The Herta ได้ **"Answer" 1 stack** (สูงสุด 99). ใช้ Ult → ต่อ Answer → Ult multiplier **+1%**

### Minor Traces (รวมทั้งหมด)
Ice DMG +22.4% · ATK +18% · SPD +5

### Eidolons
- **E1**: Enhanced Skill นับ Interpretation → นับ **50%** ของ stack บนตัวที่ stack สูงสุด (ในกลุ่มเป้าหมายหลัก+ข้างเคียง) เพิ่ม. reset เป็น **15** แทน 1
- **E2**: หลังเข้าฉากและใช้ Ult → Inspiration +1 stack. หลังใช้ Enhanced Skill → action advance **35%**
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ตัวละคร Erudition ในทีม SPD **+12%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: Ice RES PEN **+20%**. ศัตรู 3+/2/1 ตัว → Ult multiplier **+140%/+250%/+400%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Interpretation** (0–42): แหล่ง — enemy enter (+1), wave start (+25 random Elite), A2 (ally attack +1), Talent ทุก stack, reset เป็น 1/15 หลัง Enhanced Skill
- **Enhanced Skill multiplier**: +8%/stack (หลัก), +4%/stack (รอง); ×2 ถ้า Erudition ≥ 2 — ผูกกับ team composition
- **Inspiration** (0–4): +1/Ult; เปลี่ยน Skill → Hear Me Out; กิน 1/Enhanced Skill
- **Answer** (0–99, A6): +1 ต่อ Interpretation ที่ยัด → Ult multiplier +1%/stack
- **Ult**: rearrange stacks + ATK +80%/3t + instant action + Inspiration
- โค้ด: `Start_game_List` (`The_Herta.h:97`, `Hertaptr`)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/the-herta — kit tab (review/calc patch 3.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 67,
  "name": "The Herta",
  "slug": "the-herta",
  "rarity": "5",
  "element": "Ice",
  "path": "Erudition",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "January 15th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "220",
  "base_stats": {
    "hp_base": 158.4,
    "def_base": 66,
    "atk_base": 92.4,
    "speed_base": 99
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "iceDmg",
      "value": 22.4
    },
    "traceStat2": {
      "stat": "atk",
      "value": 18
    },
    "traceStat3": {
      "stat": "Speed",
      "value": 5
    }
  },
  "voice_actors": {
    "en": "PJ Mattson",
    "kr": "Kim Seo-yeong (김서영)",
    "jpn": "Yamazaki Haruka (山崎はるか)",
    "cn": "Hou Xiaofei (侯小菲)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/the-herta",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140101` | Did You Get It | Basic ATK | Single Target |
| `skill` | `140102` | Big Brain Energy | Skill | Blast |
| `skill_enh` | `140108` | Hear Me Out | Skill | Blast |
| `ult` | `140103` | Told Ya! Magic Happens | Ultimate | AoE |
| `talent` | `140104` | Hand Them Over | Talent | Enhance |
| `technique` | `140107` | Vibe Checker | Technique | Enhance |

## Ability records

### Did You Get It

```json
{
  "ability_id": "140101",
  "slot": "basic",
  "name": "Did You Get It",
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
  "description_sha256": "c75de7a9a2e324a5f750079276452697e3593952c32aeba09e18c988cff83192",
  "icon_path": null
}
```

### Big Brain Energy

```json
{
  "ability_id": "140102",
  "slot": "skill",
  "name": "Big Brain Energy",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "45",
  "toughness_break_secondary_source": "15",
  "source_max_level": 15,
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
          "value": 35,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 42,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 49,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 56.875,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65.625,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 73.5,
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
        }
      }
    }
  ],
  "description_sha256": "4d2fd23802df16c35a484f2a97b11597adee3947c0cf6492dbd36195596cf0a2",
  "icon_path": null
}
```

### Hear Me Out

```json
{
  "ability_id": "140108",
  "slot": "skill_enh",
  "name": "Hear Me Out",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Ice",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "15",
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
    "atk",
    "dmg"
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
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        },
        "p2": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
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
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
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
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
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
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ceb5e4119c1b72d307d1b81f113a075f5fbded080ce83a1f2e5cc226fb618380",
  "icon_path": null
}
```

### Told Ya! Magic Happens

```json
{
  "ability_id": "140103",
  "slot": "ult",
  "name": "Told Ya! Magic Happens",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "220",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 52,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
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
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 162.5,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
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
          "value": 80,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        },
        "p2": {
          "value": 88,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "eb3b1be440e1a83e28a673398dd506d7f0a1eaa42bb0079ea4ee0c1f34cc1ef8",
  "icon_path": null
}
```

### Hand Them Over

```json
{
  "ability_id": "140104",
  "slot": "talent",
  "name": "Hand Them Over",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    },
    "p2": {
      "unit": "percent",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 4.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 4.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 5.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 5.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 3,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 6.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "percent"
        },
        "p2": {
          "value": 3.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "percent"
        },
        "p2": {
          "value": 3.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 8.4,
          "unit": "percent"
        },
        "p2": {
          "value": 4.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 8.8,
          "unit": "percent"
        },
        "p2": {
          "value": 4.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "089b7dd01e32132b378f87a1e058c252369e0d3b3a57719db6651e81c108eae1",
  "icon_path": null
}
```

### Vibe Checker

```json
{
  "ability_id": "140107",
  "slot": "technique",
  "name": "Vibe Checker",
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
  "parameter_placeholders": {},
  "mechanic_tags": [
    "max_hp",
    "atk",
    "dmg"
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
  "description_sha256": "9a3246bcb1278a86574e884274200bbe65baba092fb507091e56e1090d126a35",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Aloofly Honest",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "1",
      "3",
      "5",
      "42",
      "50%"
    ],
    "description_sha256": "97687bb80c71066b3c365b6fc6c420112cbd7468ec846a091e688615bd32b0eb"
  },
  {
    "requirement": "A4",
    "name": "Message From Beyond the Veil",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "2",
      "80%",
      "3",
      "1",
      "2"
    ],
    "description_sha256": "d690f75de835da5d0dab45c2c48189eb0d47a6732342f8c1b494cc22cc710dd8"
  },
  {
    "requirement": "A6",
    "name": "Starved Landscape of Vacua",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "1",
      "99",
      "1%"
    ],
    "description_sha256": "298faf4ea4bf68dfa0151cc554562ace15c9dc434ce32efa5abca9159ffd5525"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Night at Shorefall",
    "mechanic_tags": [],
    "numeric_tokens": [
      "50%",
      "1",
      "15"
    ],
    "description_sha256": "7414866452443556981a9d35a6fb5e1c79e6ef0b48072afae8023b465314caa4"
  },
  {
    "eidolon": 2,
    "name": "Wind Through Keyhole",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "35%"
    ],
    "description_sha256": "c2d438326d8cebdd4c15e1f47f3a6615d71bce6f6e841cf2aa36e843c4c45bf7"
  },
  {
    "eidolon": 3,
    "name": "Door into Summer",
    "mechanic_tags": [],
    "numeric_tokens": [
      "2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "cc88e8bdaab5e0e573bdc2f4324d0b52cfd3fad8af0981ccbd2f8cc6e55163d0"
  },
  {
    "eidolon": 4,
    "name": "The Sixteenth Key",
    "mechanic_tags": [
      "spd"
    ],
    "numeric_tokens": [
      "12%"
    ],
    "description_sha256": "bd652c326622f2c287b40b08e58f9c988d79a74d0b9dbc00fb844acdcecc0570"
  },
  {
    "eidolon": 5,
    "name": "Bitter Pill of Truth",
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
    "eidolon": 6,
    "name": "Sweet Lure of Answer",
    "mechanic_tags": [
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "3",
      "2",
      "1",
      "140%",
      "250%",
      "400%"
    ],
    "description_sha256": "6a87bd9876b16c0caf07ccd5808213adb73ed6103ada0e06a8d4bf1cd47d417f"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
