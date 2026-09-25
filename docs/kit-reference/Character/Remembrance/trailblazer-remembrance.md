---
schema_version: "1.0.0"
unit_id: 69
name: "Trailblazer • Remembrance"
slug: "trailblazer-remembrance"
rarity: 5
element: "Ice"
path: "Remembrance"
role: "Support"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/trailblazer-remembrance"
source_record_updated_at: "March 18th, 2026"
dataset_snapshot: "2026-05-30"
---

# Trailblazer • Remembrance

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/RMC.h` |
| ธาตุ | **Ice** |
| Path | **Remembrance** |
| ระดับ | 5★ (MC) |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.6) |

### Base Stats (Lv.80, ascended)
HP 1047 · ATK 543 · DEF 630 · SPD 103

> Remembrance support/sub-DPS สาย memosprite **Mem** + CRIT DMG buff + True DMG ("Mem's Support")

---

### Basic ATK — Leave It to Me! (โจมตีเดี่ยว, Lv.6)
- Ice DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — I Choose You! (Summon, Lv.10)
- เรียก **Mem**; ถ้ามี Mem อยู่แล้ว → ฮีล Mem **60% Max HP ของ Mem** + Mem Charge **+10%**
- Energy +30

### Ultimate — Together, Mem! (AoE, 160 energy, Lv.10)
- เรียก Mem, Mem Charge **+40%**, จากนั้น Mem สร้าง Ice DMG = **240% ATK ของ Mem** AoE
- Energy +5 · Toughness 20

### Talent — Almighty Companion (Lv.10)
- Mem: initial SPD **130**, Max HP = **80% ของ Max HP ของ Trailblazer + 640**
- ทุก 10 Energy ที่เพื่อนทุกคนรวมกันคืน → Mem Charge **+1%**

### Technique — Memories Back as Echoes
- สร้าง Special Dimension 10 วิ (ศัตรู Time Stop)
- เข้าฉากกับศัตรู Time Stop → delay action ศัตรูทุกตัว **50%** + Ice DMG = **100% ATK** AoE

### Bonus Trace — Unfinished Epilogue
- หลังใช้ Ult → ได้ "Epic" 1 stack (สูงสุด 2). มี Epic + Mem ในสนาม → Basic ATK enhanced เป็น "Together, We Script Tomorrow!"

### Memosprite: Mem
#### Memosprite Skill — Baddies! Trouble! (AoE, Lv.6)
- **4 instance × 36% ATK ของ Mem** ใส่ศัตรูสุ่ม + สุดท้าย **90% ATK ของ Mem** AoE
- Energy +10 · Toughness 5 (+10 ข้างเคียง)

#### Memosprite Skill — Lemme! Help You! (Support, Lv.6)
- advance action เพื่อน 1 ตัว **100%** + มอบ **"Mem's Support"** นาน 3 เทิร์น
- ต่อ 1 instance ของดาเมจที่เป้าหมาย "Mem's Support" ทำ → เพิ่ม True DMG = **28% ของดาเมจเดิม** 1 instance
- ใช้ใส่ Trailblazer เอง → ไม่ได้ action advance
- Energy +10

#### Memosprite Talent
- **Friends! Together!**: เพื่อนทุกคน CRIT DMG **+เท่ากับ 12% ของ CRIT DMG ของ Mem + 24%**. Charge < 100% → Mem auto "Baddies! Trouble!" ตอน action; Charge ถึง 100% → Mem action ทันที + เลือกเพื่อน 1 คนใช้ "Lemme! Help You!" ในการกระทำถัดไป
- **Go, Mem, Go!**: เรียก Mem → Charge **+50%** ทันที
- **No... Regrets**: Mem หาย → advance action Trailblazer **25%**

---

### Major Traces
- **A2 — Rhapsode's Scepter**: ต้นการต่อสู้ → Trailblazer action advance **30%**. เรียก Mem ครั้งแรก → Mem Charge **+40%**
- **A4 — Petite Parable**: ใช้ "Baddies! Trouble!" → Mem Charge **+5%**
- **A6 — Magnets and Long Chains**: ถ้าเป้าหมาย "Mem's Support" มี Max Energy > 100 → ทุก 10 Energy ส่วนเกิน → multiplier ของ True DMG จาก "Mem's Support" **+2%** สูงสุด **+20%**

### Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · HP +14% · ATK +14%

### Eidolons
- **E1**: เพื่อนที่มี "Mem's Support" CRIT Rate **+10%**. "Mem's Support" มีผลกับ memosprite/memomaster ของเป้าหมายด้วย (ไม่ stack)
- **E2**: เมื่อ memosprite ของเพื่อน (นอกจาก Mem) action → Trailblazer คืน Energy **8** (1 ครั้ง/เทิร์น, reset ต้นเทิร์นของ Trailblazer)
- **E3**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Talent Lv. +1
- **E4**: เมื่อเพื่อนที่มี Max Energy = 0 ใช้ ability → Mem Charge **+3%** + multiplier ของ True DMG จาก "Mem's Support" ของเป้าหมายนี้ **+6%**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Skill Lv. +1
- **E6**: Ultimate CRIT Rate = **100%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Mem (memosprite)**: SPD 130, HP = 80% TB HP + 640; Charge 0–100% (Skill +10, Ult +40, Talent 1%/10 energy ทีม, summon +50%, A2 +40, A4 +5)
- **Charge < 100** → auto Baddies!; **Charge 100** → auto action + assign Lemme! Help You!
- **Mem's Support**: True DMG 28% ต่อ instance ของดาเมจเป้าหมาย (A6 +2%/10 energy เกิน 100, cap +20%; E4 +6%)
- **CRIT DMG buff (Friends! Together!)**: 12% × CD ของ Mem + 24% — ผูกกับ CD ของ Mem
- **ดาเมจ Mem สเกลกับ ATK ของ Mem** (แยก stat จาก Trailblazer)
- โค้ด: `Start_game_List` (`RMC.h:98`, `RMCptr`, `Memptr`) มี addToActionBar + `Deal_damage()` + `Action_forward 30` (A2)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/trailblazer-remembrance — kit tab (review patch 3.0, calc patch 3.6, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 69,
  "name": "Trailblazer • Remembrance",
  "slug": "trailblazer-remembrance",
  "rarity": "5",
  "element": "Ice",
  "path": "Remembrance",
  "default_role": "Support",
  "affiliation": "Astral Express",
  "release_date": "January 15th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "160",
  "base_stats": {
    "hp_base": 142.56,
    "def_base": 85.8,
    "atk_base": 73.92,
    "speed_base": 103
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT DMG",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "hp",
      "value": 14
    },
    "traceStat3": {
      "stat": "atk",
      "value": 14
    }
  },
  "voice_actors": {
    "en": "Rachael Chau | Caleb Yen",
    "kr": "Kim Ha-ru (김하루) | Kim Myung-jun (김명준)",
    "jpn": "Ishikawa Yui (石川 由依) | Enoki Junya (榎木 淳弥)",
    "cn": "Chen Tingting (陈婷婷) | Qin Juge (秦且歌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/trailblazer-remembrance",
  "source_record_updated_at": "March 18th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `800701` | Leave It to Me! | Basic ATK | Single Target |
| `skill` | `800702` | I Choose You! | Skill | Summon |
| `ult` | `800703` | Together, Mem! | Ultimate | AoE |
| `talent` | `800704` | Almighty Companion | Talent | Enhance |
| `technique` | `800707` | Memories Back as Echoes | Technique | Impair |
| `supplementary` | `8007010` | Baddies! Trouble! | Memosprite Skill | AoE |
| `supplementary` | `8007011` | Lemme! Help You! | Memosprite Skill | Support |
| `supplementary` | `8007012` | Friends! Together! | Memosprite Talent | Support |
| `supplementary` | `8007013` | Go, Mem, Go! | Memosprite Talent | Enhance |
| `supplementary` | `8007014` | No... Regrets | Memosprite Talent | Enhance |

## Ability records

### Leave It to Me!

```json
{
  "ability_id": "800701",
  "slot": "basic",
  "name": "Leave It to Me!",
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
  "description_sha256": "e82e97fc24ed0fcfdea28298b11e6574716130e9b60f72400a5ad2354e320113",
  "icon_path": null
}
```

### I Choose You!

```json
{
  "ability_id": "800702",
  "slot": "skill",
  "name": "I Choose You!",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Summon",
  "targeting_label": "Summon",
  "element": "Ice",
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
    "max_hp",
    "summon"
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
          "value": 56.5,
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
  "description_sha256": "5141b892ffc0fff0605ea0a65f4f90425c13164fa5ac30a9498ce1ec524dbe6e",
  "icon_path": null
}
```

### Together, Mem!

```json
{
  "ability_id": "800703",
  "slot": "ult",
  "name": "Together, Mem!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Ice",
  "energy_gain": "5",
  "ultimate_energy_cost": "160",
  "toughness_break_primary_source": "60",
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
    "dmg",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 156,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 195,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 252,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 264,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "1d788c71932251e8df58a3b1a17fba257f817f2493f7a9594a45126fced0ad94",
  "icon_path": null
}
```

### Almighty Companion

```json
{
  "ability_id": "800704",
  "slot": "talent",
  "name": "Almighty Companion",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": "0",
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
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "spd",
    "energy",
    "energy_regen_rate",
    "summon"
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
          "value": 400,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 53,
          "unit": "percent"
        },
        "p2": {
          "value": 424,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 56,
          "unit": "percent"
        },
        "p2": {
          "value": 448,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 59,
          "unit": "percent"
        },
        "p2": {
          "value": 472,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 62,
          "unit": "percent"
        },
        "p2": {
          "value": 496,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        },
        "p2": {
          "value": 520,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 68.75,
          "unit": "percent"
        },
        "p2": {
          "value": 550,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 72.5,
          "unit": "percent"
        },
        "p2": {
          "value": 580,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 76.25,
          "unit": "percent"
        },
        "p2": {
          "value": 610,
          "unit": "scalar"
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
          "value": 640,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 83,
          "unit": "percent"
        },
        "p2": {
          "value": 664,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 86,
          "unit": "percent"
        },
        "p2": {
          "value": 688,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "01d0bcd59394a4534713ccb5f10d15e8bba7662c418018c0a56d31d565cfe237",
  "icon_path": null
}
```

### Memories Back as Echoes

```json
{
  "ability_id": "800707",
  "slot": "technique",
  "name": "Memories Back as Echoes",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
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
  "description_sha256": "35613bb10d0a563cc1f614ef3af51f882974589575536f8703ac31a0ba9d9451",
  "icon_path": null
}
```

### Baddies! Trouble!

```json
{
  "ability_id": "8007010",
  "slot": "supplementary",
  "name": "Baddies! Trouble!",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Ice",
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
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 54,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 25.2,
          "unit": "percent"
        },
        "p2": {
          "value": 63,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 28.88,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 32.4,
          "unit": "percent"
        },
        "p2": {
          "value": 81,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 36,
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
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 99,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "b316b191c3df4fabff6c132ba7315aa6b8e20cc76cb5524b6742fe2d0e490d35",
  "icon_path": null
}
```

### Lemme! Help You!

```json
{
  "ability_id": "8007011",
  "slot": "supplementary",
  "name": "Lemme! Help You!",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "dmg",
    "action_advance"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 22,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "0f8b33b77ed87813b2d0bc660bd8fc397d00832efbe315dd376f7fe4615e2aa9",
  "icon_path": null
}
```

### Friends! Together!

```json
{
  "ability_id": "8007012",
  "slot": "supplementary",
  "name": "Friends! Together!",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Ice",
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
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 14.4,
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
          "value": 16.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.6,
          "unit": "percent"
        },
        "p2": {
          "value": 19.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 10.8,
          "unit": "percent"
        },
        "p2": {
          "value": 21.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 13.2,
          "unit": "percent"
        },
        "p2": {
          "value": 26.4,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "8cc821318faf4d721b843f21bbca61cf49719d177b2aa904c2a83a565da40dfe",
  "icon_path": null
}
```

### Go, Mem, Go!

```json
{
  "ability_id": "8007013",
  "slot": "supplementary",
  "name": "Go, Mem, Go!",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
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
  "description_sha256": "7df121edae3b87f07a663d0c5937758a6f749cc807f89c9aceae0e92eecb9f75",
  "icon_path": null
}
```

### No... Regrets

```json
{
  "ability_id": "8007014",
  "slot": "supplementary",
  "name": "No... Regrets",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Ice",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "action_advance"
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
  "description_sha256": "7c99208ec7fdfc35ab7d45eaa1f97f18bd6203c40bd53575fbb4ecdbf967a199",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Rhapsode's Scepter",
    "mechanic_tags": [
      "action_advance",
      "summon"
    ],
    "numeric_tokens": [
      "30%",
      "40%"
    ],
    "description_sha256": "4c97b03d4d715ef8a77411244fec98a8a1b4d469fb96b5a7ac9a8d9e68e825b7"
  },
  {
    "requirement": "A4",
    "name": "Petite Parable",
    "mechanic_tags": [],
    "numeric_tokens": [
      "5%"
    ],
    "description_sha256": "f83b27898077ca107669185842ffa9b287b9e56dc49ea9642aa987cc770f2b30"
  },
  {
    "requirement": "A6",
    "name": "Magnets and Long Chains",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "100",
      "10",
      "2%",
      "20%"
    ],
    "description_sha256": "a46ff2cc3d05d8d72373905ca472a60007ef5d535ac82a4e9fce4c3182c49a2b"
  },
  {
    "requirement": "Bonus",
    "name": "Unfinished Epilogue",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "1",
      "2"
    ],
    "description_sha256": "600235b5c9ac295de1ff69d4e7460da0a468961f9f0cb31a4e0b7e38664559ed"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Narrator of the Present",
    "mechanic_tags": [
      "crit_rate",
      "summon"
    ],
    "numeric_tokens": [
      "10%"
    ],
    "description_sha256": "44e723654f888663a483a2d1a8a2928dc97d5781b63ba8be1f96ec7a895478c6"
  },
  {
    "eidolon": 2,
    "name": "Gleaner of the Past",
    "mechanic_tags": [
      "energy",
      "summon"
    ],
    "numeric_tokens": [
      "8",
      "1"
    ],
    "description_sha256": "d8bcb279eb3583c629ed6fdd10941086f3dda9f0f20a30574dcae2613ea57dc8"
  },
  {
    "eidolon": 3,
    "name": "Chanter of the Future",
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
    "description_sha256": "c21c057e037373aee54ca89a779392dfaaa4c6452da41eb048f88bb2c42c142e"
  },
  {
    "eidolon": 4,
    "name": "Dancer of the Muse",
    "mechanic_tags": [
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "0",
      "3%",
      "6%"
    ],
    "description_sha256": "085ae3bca225e7564762179b0f546cea3d299fbe7271d059a44384d995731aa5"
  },
  {
    "eidolon": 5,
    "name": "Seamster of the Ode",
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
    "description_sha256": "d6647243e3f50e0ed4fcf989a5c192c02b6266587382aebfc4a62c68fa87d53e"
  },
  {
    "eidolon": 6,
    "name": "Bearer of the Revelation",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "ae48e9926e862f49c85a62ca86a539138711f0edda91e9be06d32697091379f3"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
