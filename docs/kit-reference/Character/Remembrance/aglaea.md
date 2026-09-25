---
schema_version: "1.0.0"
unit_id: 68
name: "Aglaea"
slug: "aglaea"
rarity: 5
element: "Lightning"
path: "Remembrance"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/aglaea"
source_record_updated_at: "July 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Aglaea

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Aglaea.h` |
| ธาตุ | **Lightning** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 350 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1241 · ATK 698 · DEF 485 · SPD 102

> Remembrance DPS สาย memosprite **Garmentmaker** + SPD scaling + "Seam Stitch"

---

### Basic ATK — Thorned Nectar (โจมตีเดี่ยว, Lv.6)
- Lightning DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Slash by a Thousandfold Kiss (Blast, Lv.6)
- Joint ATK: Aglaea + Garmentmaker
  - หลัก: Lightning DMG = **200% ATK ของ Aglaea** + **200% ATK ของ Garmentmaker**
  - ข้างเคียง: **90% ATK ของ Aglaea** + **90% ATK ของ Garmentmaker**
- ไม่คืน Skill Point
- Energy +20 · Toughness 20 (+10)

### Skill — Rise, Exalted Renown (Summon, Lv.10)
- ฮีล Garmentmaker **50% Max HP**; ถ้าไม่มี Garmentmaker → เรียก + Aglaea action ทันที
- Energy +20

### Ultimate — Dance, Destined Weaveress (Enhance, 350 energy, Lv.10)
- เรียก Garmentmaker (ถ้ามีอยู่แล้ว → ฮีลเต็ม), Aglaea เข้าสถานะ **"Supreme Stance"** + action ทันที
- ขณะ Supreme Stance: Aglaea ได้ SPD Boost stack จาก Memosprite Talent (ต่อ stack SPD **+15%**), Basic ATK เป็น "Slash by a Thousandfold Kiss", ใช้ Skill ไม่ได้, Garmentmaker ภูมิคุ้มกัน CC
- countdown ใน action order SPD คงที่ **100**; ใช้ Ult ซ้ำ → reset countdown; ถึงตา countdown → Garmentmaker self-destruct → Supreme Stance หาย
- Energy +5

### Talent — Rosy-Fingered (Lv.10)
- Garmentmaker: initial SPD = **35% ของ SPD ของ Aglaea**, Max HP = **66% ของ Max HP ของ Aglaea + 720**
- ขณะ Garmentmaker อยู่ในสนาม → การโจมตีของ Aglaea ติด **"Seam Stitch"**
- ตีศัตรูที่ติด "Seam Stitch" → Lightning Additional DMG = **30% ATK ของ Aglaea**
- "Seam Stitch" มีผลกับเป้าล่าสุดเท่านั้น
- Energy +10

### Technique — Meteoric Sunder
- เรียก Garmentmaker + joint attack; เข้าฉาก → คืน Energy **30** + Lightning DMG = **100% ATK** AoE + ติด "Seam Stitch" ศัตรูสุ่ม
- Toughness 20

### Memosprite: Garmentmaker
#### Memosprite Skill — Thorned Snare (Blast, Lv.6)
- Lightning DMG หลัก = **110% ATK**, ข้างเคียง = **66% ATK**
- Energy +10 · Toughness 10 (+5)

#### Memosprite Talent
- **A Body Brewed by Tears**: หลังตีศัตรูที่ติด "Seam Stitch" → SPD **+55** stack 6 ครั้ง. เมื่อ Garmentmaker action → ใช้ "Thorned Snare" อัตโนมัติ (เลือกศัตรู Seam Stitch ก่อน)
- **The Speeding Summer**: เมื่อ Garmentmaker ถูกเรียก → action advance **100%**
- **Bloom of Drying Grass**: เมื่อ Garmentmaker หาย → คืน Energy **20** ให้ Aglaea

---

### Major Traces
- **A2 — The Myopic's Doom**: ขณะ Supreme Stance → Aglaea + Garmentmaker ATK **+เท่ากับ 720% ของ SPD ของ Aglaea + 360% ของ SPD ของ Garmentmaker**
- **A4 — Last Thread of Fate**: Garmentmaker หาย → เก็บ SPD Boost stack ได้ 1 stack; เรียกใหม่ → ได้ stack นั้นกลับ
- **A6 — The Speeding Sol**: ต้นการต่อสู้ ถ้า Energy < 50% → เติมเป็น 50%

### Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · Lightning DMG +22.4% · DEF +12.5%

### Eidolons
- **E1**: ศัตรูที่ติด "Seam Stitch" รับดาเมจเพิ่ม **+15%**. หลัง Aglaea/Garmentmaker ตีเป้านี้ → คืน Energy **20**
- **E2**: เมื่อ Aglaea/Garmentmaker action → ดาเมจของ Aglaea + Garmentmaker เพิกเฉย DEF **14%** stack 3 ครั้ง (อยู่จนกว่าหน่วยอื่นใช้ ability)
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1 · Memosprite Talent Lv. +1
- **E4**: SPD Boost cap **+1**. หลัง Aglaea โจมตี → Garmentmaker ก็ได้ SPD Boost stack ด้วย
- **E5**: Ultimate Lv. +2 · Talent Lv. +2 · Memosprite Skill Lv. +1
- **E6**: ขณะ Supreme Stance → Aglaea + Garmentmaker Lightning RES PEN **+20%**. เมื่อ SPD > 160/240/320 → Joint ATK DMG **+10%/+30%/+60%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Garmentmaker (memosprite)**: SPD = 35% Aglaea SPD, HP = 66% Aglaea HP + 720; auto-cast Thorned Snare ทุกเทิร์น; advance 100% เมื่อเรียก; คืน energy 20 เมื่อหาย
- **SPD scaling**: A2 ATK = 720%×AglaeaSPD + 360%×GMSPD (Supreme Stance); Memosprite Talent SPD +55/stack (cap 6, E4 7); Ult SPD +15%/stack
- **Seam Stitch**: Additional DMG 30% ATK + E1 vuln 15%; single target ล่าสุด
- **Supreme Stance (Ult 350)**: countdown SPD 100, Enhanced BA (Joint ATK 200%+200%), no Skill
- **Joint ATK** = ดาเมจ 2 แหล่ง (Aglaea ATK + Garmentmaker ATK) — sim ต้องแยก ATK stat 2 ตัว
- โค้ด: `Start_game_List` (`Aglaea.h:88`, `AGptr`) + memosprite handling
- **หมายเหตุ**: `elationCount`-style — Remembrance ใช้ `memosprite`

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/aglaea — kit tab (review patch 3.0, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 68,
  "name": "Aglaea",
  "slug": "aglaea",
  "rarity": "5",
  "element": "Lightning",
  "path": "Remembrance",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "February 5th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "350",
  "base_stats": {
    "hp_base": 168.96,
    "def_base": 66,
    "atk_base": 95.04,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat2": {
      "stat": "Lightning DMG",
      "value": 22.4
    },
    "traceStat3": {
      "stat": "def",
      "value": 12.5
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "Oh Ro-ah (오로아)",
    "jpn": "Endou Aya (遠藤 綾)",
    "cn": "Chu Yue (楚越)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/aglaea",
  "source_record_updated_at": "July 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140201` | Thorned Nectar | Basic ATK | Single Target |
| `basic_enh` | `140208` | Slash by a Thousandfold Kiss | Basic ATK | Blast |
| `skill` | `140202` | Rise, Exalted Renown | Skill | Summon |
| `ult` | `140203` | Dance, Destined Weaveress | Ultimate | Enhance |
| `talent` | `140204` | Rosy-Fingered | Talent | Enhance |
| `technique` | `140207` | Meteoric Sunder | Technique | MazeAttack |
| `supplementary` | `1402010` | Thorned Snare | Memosprite Skill | Blast |
| `supplementary` | `1402012` | A Body Brewed by Tears | Memosprite Talent | Enhance |
| `supplementary` | `1402013` | The Speeding Summer | Memosprite Talent | Enhance |
| `supplementary` | `1402014` | Bloom of Drying Grass | Memosprite Talent | Enhance |

## Ability records

### Thorned Nectar

```json
{
  "ability_id": "140201",
  "slot": "basic",
  "name": "Thorned Nectar",
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
          "value": 60,
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
          "value": 70,
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
          "value": 80,
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
          "value": 90,
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
          "value": 100,
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
          "value": 110,
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
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "40b4f2144984b46772767da0e70d7fd5104a408779bb4badbd07fe8607794596",
  "icon_path": "icon/skill/1402_basic_atk.png"
}
```

### Slash by a Thousandfold Kiss

```json
{
  "ability_id": "140208",
  "slot": "basic_enh",
  "name": "Slash by a Thousandfold Kiss",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Thunder",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
  "source_max_level": 9,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "dmg",
    "skill_points"
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
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        },
        "p3": {
          "value": 120,
          "unit": "percent"
        },
        "p4": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 160,
          "unit": "percent"
        },
        "p4": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 81,
          "unit": "percent"
        },
        "p3": {
          "value": 180,
          "unit": "percent"
        },
        "p4": {
          "value": 81,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 200,
          "unit": "percent"
        },
        "p4": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        },
        "p2": {
          "value": 99,
          "unit": "percent"
        },
        "p3": {
          "value": 220,
          "unit": "percent"
        },
        "p4": {
          "value": 99,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        },
        "p3": {
          "value": 240,
          "unit": "percent"
        },
        "p4": {
          "value": 108,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 260,
          "unit": "percent"
        },
        "p2": {
          "value": 117,
          "unit": "percent"
        },
        "p3": {
          "value": 260,
          "unit": "percent"
        },
        "p4": {
          "value": 117,
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
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 140,
          "unit": "percent"
        },
        "p4": {
          "value": 56,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "48867cb860bc9e3087bf616e18d92546d6fdb748e4bb4568479a5fbf9a0e76e9",
  "icon_path": "icon/skill/1402_basic_atk.png"
}
```

### Rise, Exalted Renown

```json
{
  "ability_id": "140202",
  "slot": "skill",
  "name": "Rise, Exalted Renown",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Summon",
  "targeting_label": "Summon",
  "element": "Lightning",
  "energy_gain": "20",
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
    "max_hp",
    "healing",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 27.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 30,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 32.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 40.62,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 43.75,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 46.88,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 50,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 57.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
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
          "value": 62.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "64dc9fb302d7d57cbd2e4f6e8f5d66d6bbd487a5d728466f782e22c2d60a991a",
  "icon_path": "icon/skill/1402_skill.png"
}
```

### Dance, Destined Weaveress

```json
{
  "ability_id": "140203",
  "slot": "ult",
  "name": "Dance, Destined Weaveress",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": "5",
  "ultimate_energy_cost": "350",
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
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
    "spd",
    "debuff",
    "buff",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 13.13,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 13.75,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 14.37,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 15.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 17,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 100,
          "unit": "scalar"
        },
        "p5": {
          "value": 0,
          "unit": "scalar"
        },
        "p6": {
          "value": 0,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "33d953ca729835375a84f8823b6c22e9cb5e9c4a29ab107e0d70ab41c98ef9c6",
  "icon_path": "icon/skill/1402_ultimate.png"
}
```

### Rosy-Fingered

```json
{
  "ability_id": "140204",
  "slot": "talent",
  "name": "Rosy-Fingered",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Thunder",
  "energy_gain": "10",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p4": {
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
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "atk",
    "spd",
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 44,
          "unit": "percent"
        },
        "p6": {
          "value": 180,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 13.8,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 46.75,
          "unit": "percent"
        },
        "p6": {
          "value": 247.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 15.6,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 49.5,
          "unit": "percent"
        },
        "p6": {
          "value": 315,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 17.4,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 52.25,
          "unit": "percent"
        },
        "p6": {
          "value": 382.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 55,
          "unit": "percent"
        },
        "p6": {
          "value": 450,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 57.2,
          "unit": "percent"
        },
        "p6": {
          "value": 504,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 23.25,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 59.4,
          "unit": "percent"
        },
        "p6": {
          "value": 558,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 25.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 61.6,
          "unit": "percent"
        },
        "p6": {
          "value": 612,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 27.75,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 63.8,
          "unit": "percent"
        },
        "p6": {
          "value": 666,
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 66,
          "unit": "percent"
        },
        "p6": {
          "value": 720,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.8,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 68.2,
          "unit": "percent"
        },
        "p6": {
          "value": 774,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 33.6,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 70.4,
          "unit": "percent"
        },
        "p6": {
          "value": 828,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 35.4,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 72.6,
          "unit": "percent"
        },
        "p6": {
          "value": 882,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 37.2,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 74.8,
          "unit": "percent"
        },
        "p6": {
          "value": 936,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 0,
          "unit": "scalar"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 77,
          "unit": "percent"
        },
        "p6": {
          "value": 990,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "52bfbd03d402818e73b26357ba3ca6fea5693e55ac5a780461049ee879ee3495",
  "icon_path": "icon/skill/1402_talent.png"
}
```

### Meteoric Sunder

```json
{
  "ability_id": "140207",
  "slot": "technique",
  "name": "Meteoric Sunder",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Thunder",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
    "energy",
    "dmg",
    "summon"
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
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "3cbceea7c6461df0cc5849e512a8a1a0236053ca8b855b985a9e4f41766f6f79",
  "icon_path": "icon/skill/1402_technique.png"
}
```

### Thorned Snare

```json
{
  "ability_id": "1402010",
  "slot": "supplementary",
  "name": "Thorned Snare",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
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
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 39.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 46.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 88,
          "unit": "percent"
        },
        "p2": {
          "value": 52.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        },
        "p2": {
          "value": 59.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121,
          "unit": "percent"
        },
        "p2": {
          "value": 72.6,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7b3d3a5f8ab6f4ec99d9a2370336baea20249698017df0fc73a900919996d9eb",
  "icon_path": null
}
```

### A Body Brewed by Tears

```json
{
  "ability_id": "1402012",
  "slot": "supplementary",
  "name": "A Body Brewed by Tears",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "spd"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 46,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 57,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "8c40ffe082e6756499193ddfebd53c7e70a086ed7e0afe1e380bd528ade366ba",
  "icon_path": null
}
```

### The Speeding Summer

```json
{
  "ability_id": "1402013",
  "slot": "supplementary",
  "name": "The Speeding Summer",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "action_advance",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.06,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "a12f9225f9a146b6a44abab7f232f1765e398004d5fd17473e9a10fc7915f14f",
  "icon_path": null
}
```

### Bloom of Drying Grass

```json
{
  "ability_id": "1402014",
  "slot": "supplementary",
  "name": "Bloom of Drying Grass",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Lightning",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "energy"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.06,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.12,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "7b5e84c34217dfe44109eaf1dd4612aee0ffdc4f7e904dff5563b9582783cec4",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "The Myopic's Doom",
    "mechanic_tags": [
      "atk",
      "spd"
    ],
    "numeric_tokens": [
      "720%",
      "360%"
    ],
    "description_sha256": "e042c58c198bd7c48a752d6178b9d99e3ff2c3d21e33161a43a14f8a83268426"
  },
  {
    "requirement": "A4",
    "name": "Last Thread of Fate",
    "mechanic_tags": [
      "spd",
      "summon"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "4d0139907f0f576b922955da28e163459cd761817b992e140cf2ef87f749259b"
  },
  {
    "requirement": "A6",
    "name": "The Speeding Sol",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "50%",
      "50%"
    ],
    "description_sha256": "3624653bcb4c6644b421424c56f9f591203550ae77aa45cd6e7c352ce930ca7f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Drift at the Whim of Venus",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "15%",
      "20"
    ],
    "description_sha256": "077772cbcde363dd04e903e55f0da004184607c3353247b157e2226c7e03ab27"
  },
  {
    "eidolon": 2,
    "name": "Sail on the Raft of Eyelids",
    "mechanic_tags": [
      "def",
      "dmg"
    ],
    "numeric_tokens": [
      "14%",
      "3"
    ],
    "description_sha256": "e4c26689a1317dc5864cf9519fbbedd680d5ed64e154e3198278303eb09ea9ae"
  },
  {
    "eidolon": 3,
    "name": "Bequeath in the Coalescence of Dew",
    "mechanic_tags": [
      "atk",
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10",
      "+1",
      "10"
    ],
    "description_sha256": "caa57e8e3ae8bb906e5bee9b2eaa3b89cd95e7183ecf5eb6915f8e39c828eb66"
  },
  {
    "eidolon": 4,
    "name": "Flicker Below the Surface of Marble",
    "mechanic_tags": [
      "spd",
      "summon"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "490bb10ad5ec542965c43fa57757a5603de45027dfbcf6c1500562566347fb7b"
  },
  {
    "eidolon": 5,
    "name": "Weave Under the Shroud of Woe",
    "mechanic_tags": [
      "summon"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "23416b132409e1464c2f5c3c885cc7f59b28156ac8c3f54b8f5810ee688bfff6"
  },
  {
    "eidolon": 6,
    "name": "Fluctuate in the Tapestry of Fates",
    "mechanic_tags": [
      "atk",
      "spd",
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "160",
      "240",
      "320",
      "10%",
      "30%",
      "60%"
    ],
    "description_sha256": "64f1435a613395bb382ec05eea669c41aa123430884c933a45082ba08e846de0"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
