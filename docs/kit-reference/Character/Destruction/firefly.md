---
schema_version: "1.0.0"
unit_id: 54
name: "Firefly"
slug: "firefly"
rarity: 5
element: "Fire"
path: "Destruction"
role: "Main DPS"
affiliation: "Stellaron Hunters"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/firefly"
source_record_updated_at: "April 21st, 2026"
dataset_snapshot: "2026-05-30"
---

# Firefly

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/FireFly.h` |
| ธาตุ | **Fire** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 240 |
| อ้างอิง | prydwen.gg (review/calc patch 4.2) |

### Base Stats (Lv.80, ascended)
HP 814 · ATK 523 · DEF 776 · SPD 104

---

### Basic ATK — Order: Flare Propulsion (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Basic ATK (Enhanced) — Fyrefly Type-IV: Pyrogenic Decimation (โจมตีเดี่ยว, Lv.6)
- ฮีลตัวเอง = **20% Max HP**
- Fire DMG = **150% ATK** ใส่ศัตรู 1 ตัว
- Energy +0 · Toughness 15

### Skill — Order: Aerial Bombardment (โจมตีเดี่ยว, Lv.10)
- กิน HP = **40% Max HP** (ถ้าไม่พอ → HP เหลือ 1) และคืน Energy = **60% ของ Max Energy** (ค่าคงที่)
- Fire DMG = **200% ATK** ใส่ศัตรู 1 ตัว
- Advance action ครั้งถัดไป **25%**
- Energy +0 · Toughness 20

### Skill (Enhanced) — Fyrefly Type-IV: Deathstar Overload (Blast, Lv.10)
- ฮีลตัวเอง = **25% Max HP**
- เพิ่ม Fire Weakness ให้เป้าหมาย + ศัตรูข้างเคียง นาน 2 เทิร์น
- Fire DMG เป้าหมายหลัก = **(0.2 × Break Effect + 200%) ATK**
- Fire DMG ข้างเคียง = **(0.1 × Break Effect + 100%) ATK**
- **Break Effect ที่ใช้คำนวณ cap ที่ 360%**
- Energy +0 · Toughness 30 (+15 ข้างเคียง)

### Ultimate — Fyrefly Type-IV: Complete Combustion (Enhance, 240 energy, Lv.10)
- เข้าสถานะ **Complete Combustion**, advance action **100%**, ได้ Enhanced BA + Enhanced Skill
- ขณะ Complete Combustion: **SPD +60**; เมื่อใช้ Enhanced BA/Skill → Weakness Break Efficiency **+50%** และ Break DMG ที่ SAM ทำ **+20%** (จนจบการโจมตีนั้น)
- มี countdown timer ใน action order (SPD คงที่ **70**) เมื่อถึงตาของ timer → ออกจากสถานะ
- ใช้ Ultimate ไม่ได้ขณะอยู่ในสถานะ
- Energy +5

### Talent — Chrysalid Pyronexus (Lv.10)
- HP ยิ่งต่ำ → รับดาเมจน้อยลง; HP ≤ 20% → DMG Reduction สูงสุด **40%**
- ขณะ Complete Combustion: DMG Reduction คงที่ max + Effect RES **+30%**
- เริ่มการต่อสู้ ถ้า Energy < 50% → เติมเป็น 50%; เมื่อ Energy เต็ม → ล้าง debuff ทั้งหมดบนตัวเอง

### Technique — Δ Order: Meteoric Incineration
- ต้นแต่ละ wave: ติด Fire Weakness ศัตรูทุกตัวนาน 2 เทิร์น + Fire DMG = **200% ATK** AoE
- Toughness 20

---

### Major Traces
- **A2 — Module α: Antilag Outburst**: ขณะ Complete Combustion → Break Effect **+25%**. เมื่อใช้ Enhanced BA/Skill ทำ Weakness Break → หน่วง countdown **10%** (สูงสุด 3 ครั้ง/รอบสถานะ)
- **A4 — Module β: Autoreactive Armor**: ขณะ Complete Combustion และ Break Effect ≥ **150%/300%** → ตีศัตรูที่ Weakness-Broken จะแปลง Toughness Reduction ของการโจมตีนั้นเป็น **Super Break DMG 100%/150%** 1 instance
- **A6 — Module γ: Core Overload**: ทุก 10 ATK ที่เกิน **1800** → Break Effect **+0.8%**

### Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · SPD +5 · Effect RES +18%

### Eidolons
- **E1**: Enhanced Skill เพิกเฉย DEF **15%** และ**ไม่กิน Skill Point**
- **E2**: ขณะ Complete Combustion ใช้ Enhanced BA/Skill ฆ่าหรือ Break Weakness → ได้เทิร์นพิเศษทันที (1 ครั้ง/เทิร์น, รีเซ็ตตอนเริ่มเทิร์น SAM)
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ขณะ Complete Combustion → Effect RES **+50%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: ขณะ Complete Combustion → Fire RES PEN **+20%**; เมื่อใช้ Enhanced BA/Skill → Weakness Break Efficiency **+50%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ทุกอย่างหมุนรอบ Break Effect** — Enhanced Skill multiplier = f(BE) cap BE 360%; A6 แปลง ATK เกิน 1800 → BE
- **Enhanced Skill DMG** = `(0.2×BE + 2.0)×ATK` main, `(0.1×BE + 1.0)×ATK` blast
- **A4 Super Break**: threshold BE 150% → 100%, BE 300% → 150%; ต้องตี broken enemy ขณะ Combustion
- **Complete Combustion**: countdown unit SPD 70, มี A2 หน่วง 10%×3; SPD +60 ระหว่างสถานะ; Talent DMG-reduction locked max
- **Skill self-damage** 40% Max HP (floor ที่ HP=1) + energy refund 60% Max Energy คงที่
- **Technique** (`Start_wave_List`, `ptr->Technique == 1`) ทำต้นทุก wave: weakness + 200% AoE + self-flush `Deal_damage()`
- Talent energy top-up ถึง 50% ตอนเริ่มต่อสู้ + debuff cleanse ตอน energy เต็ม
- E1: Enhanced Skill ไม่กิน SP (สำคัญต่อ SP economy sim)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/firefly — kit tab (review/calc patch 4.2, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 54,
  "name": "Firefly",
  "slug": "firefly",
  "rarity": "5",
  "element": "Fire",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": "Stellaron Hunters",
  "release_date": "June 19th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "240",
  "base_stats": {
    "hp_base": 110.88,
    "def_base": 105.6,
    "atk_base": 71.28,
    "speed_base": 104
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
      "stat": "effectRes",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Analesa Fisher & Adin Rudd ",
    "kr": "Yu Hye-ji (유혜지) & Jang Seo-hwa (장서화)",
    "jpn": "Kusunoki Tomori (楠木ともり) & Kasama Jun (笠間淳)",
    "cn": "Song Yuanyuan (宋媛媛) &  Gan Ziqi (淦子齐)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/firefly",
  "source_record_updated_at": "April 21st, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `150901` | Order: Flare Propulsion | Basic ATK | Single Target |
| `basic_enh` | `150908` | Fyrefly Type-IV: Pyrogenic Decimation | Basic ATK | Single Target |
| `skill` | `150902` | Order: Aerial Bombardment | Skill | Single Target |
| `skill_enh` | `150909` | Fyrefly Type-IV: Deathstar Overload | Skill | Blast |
| `ult` | `150903` | Fyrefly Type-IV: Complete Combustion | Ultimate | Enhance |
| `talent` | `150904` | Chrysalid Pyronexus | Talent | Defense |
| `technique` | `150907` | Δ Order: Meteoric Incineration | Technique | Support |

## Ability records

### Order: Flare Propulsion

```json
{
  "ability_id": "150901",
  "slot": "basic",
  "name": "Order: Flare Propulsion",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
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
  "description_sha256": "fdac3461764163d997f9a46e31591b4ed301571e00b3789e4e8e0851300a2a58",
  "icon_path": null
}
```

### Fyrefly Type-IV: Pyrogenic Decimation

```json
{
  "ability_id": "150908",
  "slot": "basic_enh",
  "name": "Fyrefly Type-IV: Pyrogenic Decimation",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "45",
  "toughness_break_secondary_source": null,
  "source_max_level": 9,
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
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 100,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 120,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 140,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 162.5,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 187.5,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 210,
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
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "19ad6f449ce84414cb5a682238153540d3f147111c32b493143c5eb80a921cb3",
  "icon_path": null
}
```

### Order: Aerial Bombardment

```json
{
  "ability_id": "150902",
  "slot": "skill",
  "name": "Order: Aerial Bombardment",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
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
    "energy",
    "dmg",
    "action_advance"
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
          "value": 50,
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
          "value": 51,
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
          "value": 52,
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
          "value": 53,
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
          "value": 54,
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
          "value": 55,
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
          "value": 56.25,
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
          "value": 57.5,
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
          "value": 58.75,
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
          "value": 60,
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
          "value": 61,
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
          "value": 62,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9fd958b86f1ec8cc4c6baa0d8d76a56115c730312e365fab62e37274ab3fb96b",
  "icon_path": null
}
```

### Fyrefly Type-IV: Deathstar Overload

```json
{
  "ability_id": "150909",
  "slot": "skill_enh",
  "name": "Fyrefly Type-IV: Deathstar Overload",
  "type_code": "Normal",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": "45",
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
    "max_hp",
    "atk",
    "break_effect",
    "dmg",
    "healing",
    "weakness"
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
          "value": 50,
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
          "value": 55,
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
          "value": 60,
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
          "value": 65,
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
          "value": 70,
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
          "value": 75,
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
          "value": 81.25,
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
          "value": 87.5,
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
          "value": 93.75,
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
          "value": 100,
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
          "value": 105,
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
          "value": 110,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 115,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "c5998c4f127efcbac26d51df7ecdc10e8f78032560cc3b8a4d1b1b8ad12dff9c",
  "icon_path": null
}
```

### Fyrefly Type-IV: Complete Combustion

```json
{
  "ability_id": "150903",
  "slot": "ult",
  "name": "Fyrefly Type-IV: Complete Combustion",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Fire",
  "energy_gain": "5",
  "ultimate_energy_cost": "240",
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
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "weakness_break_efficiency",
    "dmg",
    "action_advance",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "scalar"
        },
        "p2": {
          "value": 10,
          "unit": "percent"
        },
        "p3": {
          "value": 0.72,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 33,
          "unit": "scalar"
        },
        "p2": {
          "value": 11,
          "unit": "percent"
        },
        "p3": {
          "value": 0.768,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "scalar"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 0.816,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 39,
          "unit": "scalar"
        },
        "p2": {
          "value": 13,
          "unit": "percent"
        },
        "p3": {
          "value": 0.864,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "scalar"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 0.912,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "scalar"
        },
        "p2": {
          "value": 15,
          "unit": "percent"
        },
        "p3": {
          "value": 0.96,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 48.75,
          "unit": "scalar"
        },
        "p2": {
          "value": 16.25,
          "unit": "percent"
        },
        "p3": {
          "value": 1.02,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "scalar"
        },
        "p2": {
          "value": 17.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1.08,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 56.25,
          "unit": "scalar"
        },
        "p2": {
          "value": 18.75,
          "unit": "percent"
        },
        "p3": {
          "value": 1.14,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
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
          "value": 20,
          "unit": "percent"
        },
        "p3": {
          "value": 1.2,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "scalar"
        },
        "p2": {
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 1.248,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "scalar"
        },
        "p2": {
          "value": 22,
          "unit": "percent"
        },
        "p3": {
          "value": 1.296,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 69,
          "unit": "scalar"
        },
        "p2": {
          "value": 23,
          "unit": "percent"
        },
        "p3": {
          "value": 1.344,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 0.2584,
          "unit": "scalar"
        },
        "p2": {
          "value": 26000,
          "unit": "percent"
        },
        "p3": {
          "value": 1.392,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 0.266,
          "unit": "scalar"
        },
        "p2": {
          "value": 27500,
          "unit": "percent"
        },
        "p3": {
          "value": 1.44,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "959389cead5166e257d995d557be189298acf87690388f71b641e8d884d0000a",
  "icon_path": null
}
```

### Chrysalid Pyronexus

```json
{
  "ability_id": "150904",
  "slot": "talent",
  "name": "Chrysalid Pyronexus",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Defense",
  "targeting_label": "Defense",
  "element": "Fire",
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
    "max_hp",
    "effect_res",
    "energy",
    "res",
    "dmg",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
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
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 16,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
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
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        },
        "p2": {
          "value": 22.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 42,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 46,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9eacb5efd56095f54e462620fca241acce3e04c4bde0bbe2e98996efc9d97050",
  "icon_path": null
}
```

### Δ Order: Meteoric Incineration

```json
{
  "ability_id": "150907",
  "slot": "technique",
  "name": "Δ Order: Meteoric Incineration",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Fire",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 0.24,
          "unit": "scalar"
        },
        "p2": {
          "value": 0.36,
          "unit": "scalar"
        },
        "p3": {
          "value": 0.6,
          "unit": "scalar"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9d747da63bd6964c799c699ff6319e7991fbd219c3ca6718bc7d91f3483d2ce0",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Module α: Antilag Outburst",
    "mechanic_tags": [
      "atk",
      "break_effect",
      "weakness"
    ],
    "numeric_tokens": [
      "25%",
      "10%",
      "3"
    ],
    "description_sha256": "da43b40216fcb997c9aa547914a7d49bc611ec7ae499cfbc5d6fcdb12f9e262f"
  },
  {
    "requirement": "A4",
    "name": "Module β: Autoreactive Armor",
    "mechanic_tags": [
      "break_effect",
      "dmg",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "150%",
      "300%",
      "1",
      "100%",
      "150%"
    ],
    "description_sha256": "077f6dbc059ae5be68f7b1a2d0c856b132474815941c7250fde0191dcb55945d"
  },
  {
    "requirement": "A6",
    "name": "Module γ: Core Overload",
    "mechanic_tags": [
      "atk",
      "break_effect"
    ],
    "numeric_tokens": [
      "10",
      "1800",
      "0.8%"
    ],
    "description_sha256": "b96ec1d7ce78b806f9d0fb1abebe3f4ef8dc387c2703bd7992b7393f92ee605c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "In Reddened Chrysalis, I Once Rest",
    "mechanic_tags": [
      "def",
      "skill_points"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "bd5b6946ba4004e5103ea0d9abd28664d716ac4de9099bf1652a6fd368e12856"
  },
  {
    "eidolon": 2,
    "name": "From Shattered Sky, I Free Fall",
    "mechanic_tags": [
      "atk",
      "weakness"
    ],
    "numeric_tokens": [
      "1",
      "1"
    ],
    "description_sha256": "2a8d075caab9d1b4a92b6ac5e292b19c32410aeebfad94030da669cf792ed186"
  },
  {
    "eidolon": 3,
    "name": "Amidst Silenced Stars, I Deep Sleep",
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
    "eidolon": 4,
    "name": "Upon Lighted Fyrefly, I Soon Gaze",
    "mechanic_tags": [
      "effect_res",
      "res"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "c0f43ea48fb95a7923b973f7461b3abd28812137dd26aa4d3d7bf7aa122c3b39"
  },
  {
    "eidolon": 5,
    "name": "From Undreamt Night, I Thence Shine",
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
    "eidolon": 6,
    "name": "In Finalized Morrow, I Full Bloom",
    "mechanic_tags": [
      "atk",
      "weakness_break_efficiency",
      "res_pen",
      "res",
      "weakness"
    ],
    "numeric_tokens": [
      "20%",
      "50%"
    ],
    "description_sha256": "bef5b20e2d1ed65fb64fc8c1f51cb4bc3aaca78b37ab13e31a56da98ca9f3e4b"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
