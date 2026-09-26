---
schema_version: "1.0.0"
unit_id: 52
name: "Robin"
slug: "robin"
rarity: 5
element: "Physical"
path: "Harmony"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/robin"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Robin

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Robin.h` |
| ธาตุ | **Physical** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1280 · ATK 640 · DEF 485 · SPD 102

> Harmony support สาย ATK buff + Concerto (Additional DMG on every ally attack)

---

### Basic ATK — Wingflip White Noise (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Pinion's Aria (Support, Lv.10)
- เพื่อนทุกคน +DMG dealt **50%** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Robin)
- Energy +30

### Ultimate — Vox Harmonique, Opus Cosmique (Support, 160 energy, Lv.10)
- Robin เข้าสถานะ **Concerto** + เพื่อนคนอื่นทุกคน **action ทันที**
- ขณะ Concerto:
  - เพื่อนทุกคน ATK **+เท่ากับ 22.8% ของ ATK ของ Robin + 200**
  - หลังเพื่อนโจมตีทุกครั้ง → Robin สร้าง Additional Physical DMG = **120% ATK** 1 ครั้ง (fixed CRIT Rate 100%, fixed CRIT DMG 150%)
  - Robin ภูมิคุ้มกัน CC, ไม่มีเทิร์น/action จนกว่า Concerto จบ
- Concerto countdown ใน action order, SPD คงที่ **90**; ถึงตา → ออกจาก Concerto + action ทันที
- Energy +5

### Talent — Tonal Resonance (Lv.10)
- เพื่อนทุกคน CRIT DMG **+20%**
- หลังเพื่อนโจมตีศัตรู → Robin คืน Energy **2** ให้ตัวเอง

### Technique — Overture of Inebriation
- สร้าง dimension 15 วิ (ศัตรูไม่โจมตี Robin, ตาม Robin)
- เข้าฉากใน dimension → Robin คืน Energy **5** ต้นแต่ละ wave

---

### Major Traces
- **A2 — Coloratura Cadenza**: ต้นการต่อสู้ → Robin action advance **25%**
- **A4 — Impromptu Flourish**: ขณะ Concerto → CRIT DMG ของ follow-up attack ของเพื่อนทุกคน **+25%**
- **A6 — Sequential Passage**: ใช้ Skill → คืน Energy **5** เพิ่ม

### Minor Traces (รวมทั้งหมด)
ATK +28% · HP +18% · SPD +5

### Eidolons
- **E1 — Land of Smiles**: ขณะ Concerto → เพื่อนทุกคน All-Type RES PEN **+24%**
- **E2 — Afternoon Tea For Two**: ขณะ Concerto → เพื่อนทุกคน SPD **+16%**. Talent energy regen **+1** (รวม 3)
- **E3**: Skill Lv. +2 · Ultimate Lv. +2
- **E4 — Raindrop Key**: ใช้ Ult → ล้าง CC เพื่อนทุกคน. ขณะ Concerto → เพื่อนทุกคน Effect RES **+50%**
- **E5**: Basic ATK Lv. +1 · Talent Lv. +2
- **E6 — Moonless Midnight**: ขณะ Concerto → CRIT DMG ของ Additional Physical DMG จาก Ult **+450%** (trigger สูงสุด 8 ครั้ง, ตัวนับรีเซ็ตทุกครั้งใช้ Ult)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Concerto** = countdown unit SPD 90; Robin ไม่มีเทิร์นระหว่างนั้น; เพื่อน action ทันทีตอนเข้า
- **ATK buff (Concerto)**: 0.228 × (ATK ของ Robin) + 200 — flat ATK ผูกกับ ATK ของ Robin ต้อง re-eval (`Stats_Adjust_List` ในโค้ด: `Concerto_state` buff note)
- **Additional Physical DMG**: 120% ATK ต่อการโจมตีของเพื่อน, fixed crit 100%/150% (+E6 CD +450%, cap 8/Ult)
- **Talent energy**: +2 (E2 +3) ต่อการโจมตีของเพื่อน — ป้อน energy Robin กลับ
- โค้ด: `Start_game_List` (`Robin.h:113`) = action forward 25% (A2); `Start_wave_List` = technique energy 5; countdown ใช้ `SetCountdownStats(ptr,90,"Concerto_state")`
- `Double_Turn` / `driverType` logic — Robin มี `addUltCondition` หลายชั้นในโค้ด

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/robin — kit tab (review patch 2.6, calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 52,
  "name": "Robin",
  "slug": "robin",
  "rarity": "5",
  "element": "Physical",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "May 8th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "160",
  "base_stats": {
    "hp_base": 174.24,
    "def_base": 66,
    "atk_base": 87.12,
    "speed_base": 102
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 28
    },
    "traceStat2": {
      "stat": "hp",
      "value": 18
    },
    "traceStat3": {
      "stat": "Speed",
      "value": 5
    }
  },
  "voice_actors": {
    "en": "Alice Himora & Chevy",
    "kr": "신온유 (Shin On-yu) & Chevy",
    "jpn": "名冢佳织 (Nazuka Kaori) & Chevy",
    "cn": "钱琛 (Qian Chen) & Chevy"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/robin",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130901` | Wingflip White Noise | Basic ATK | Single Target |
| `skill` | `130902` | Pinion's Aria | Skill | Support |
| `ult` | `130903` | Vox Harmonique, Opus Cosmique | Ultimate | Support |
| `talent` | `130904` | Tonal Resonance | Talent | Support |
| `technique` | `130907` | Overture of Inebriation | Technique | Support |

## Ability records

### Wingflip White Noise

```json
{
  "ability_id": "130901",
  "slot": "basic",
  "name": "Wingflip White Noise",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
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
  "description_sha256": "e94cd57e64a1bb72158dddbccb26ba7b79711f7a010826323d6cacc5af19b7ee",
  "icon_path": "icon/skill/1304_basic_atk.png"
}
```

### Pinion's Aria

```json
{
  "ability_id": "130902",
  "slot": "skill",
  "name": "Pinion's Aria",
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 40.625,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 43.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 46.875,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 57.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 62.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "552362b6b94480de2df2a8143bd22aa2757d1183690ff085442ceba2d9768d25",
  "icon_path": "icon/skill/1304_skill.png"
}
```

### Vox Harmonique, Opus Cosmique

```json
{
  "ability_id": "130903",
  "slot": "ult",
  "name": "Vox Harmonique, Opus Cosmique",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Physical",
  "energy_gain": "5",
  "ultimate_energy_cost": "160",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "spd",
    "crit_rate",
    "crit_dmg",
    "dmg",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15.2,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
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
          "value": 15.96,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "scalar"
        },
        "p3": {
          "value": 76.8,
          "unit": "percent"
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
          "value": 16.72,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 81.6,
          "unit": "percent"
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
          "value": 17.48,
          "unit": "percent"
        },
        "p2": {
          "value": 95,
          "unit": "scalar"
        },
        "p3": {
          "value": 86.4,
          "unit": "percent"
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
          "value": 18.24,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "scalar"
        },
        "p3": {
          "value": 91.2,
          "unit": "percent"
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
          "value": 19,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "scalar"
        },
        "p3": {
          "value": 96,
          "unit": "percent"
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
          "value": 19.95,
          "unit": "percent"
        },
        "p2": {
          "value": 143.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 102,
          "unit": "percent"
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
          "value": 20.9,
          "unit": "percent"
        },
        "p2": {
          "value": 162.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 108,
          "unit": "percent"
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
          "value": 21.85,
          "unit": "percent"
        },
        "p2": {
          "value": 181.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 114,
          "unit": "percent"
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
          "value": 22.8,
          "unit": "percent"
        },
        "p2": {
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 120,
          "unit": "percent"
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
          "value": 23.56,
          "unit": "percent"
        },
        "p2": {
          "value": 215,
          "unit": "scalar"
        },
        "p3": {
          "value": 124.8,
          "unit": "percent"
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
          "value": 24.32,
          "unit": "percent"
        },
        "p2": {
          "value": 230,
          "unit": "scalar"
        },
        "p3": {
          "value": 129.6,
          "unit": "percent"
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
          "value": 25.08,
          "unit": "percent"
        },
        "p2": {
          "value": 245,
          "unit": "scalar"
        },
        "p3": {
          "value": 134.4,
          "unit": "percent"
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
          "value": 25.84,
          "unit": "percent"
        },
        "p2": {
          "value": 260,
          "unit": "scalar"
        },
        "p3": {
          "value": 139.2,
          "unit": "percent"
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
          "value": 26.6,
          "unit": "percent"
        },
        "p2": {
          "value": 275,
          "unit": "scalar"
        },
        "p3": {
          "value": 144,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "c6189a31432fe6bbcf614bfa68d210e6c0ea2b2f0495ad8cd5472510dd232807",
  "icon_path": "icon/skill/1304_ultimate.png"
}
```

### Tonal Resonance

```json
{
  "ability_id": "130904",
  "slot": "talent",
  "name": "Tonal Resonance",
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
    "crit_dmg",
    "energy",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 6.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 9.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 12.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 14.375,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 18.125,
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
          "value": 21.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 23,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 24.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 27.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "372b0a0a972f47577bef5563ee79c2694a538fd796ce26dd51fbb3ef9718e306",
  "icon_path": "icon/skill/1304_talent.png"
}
```

### Overture of Inebriation

```json
{
  "ability_id": "130907",
  "slot": "technique",
  "name": "Overture of Inebriation",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "energy"
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
  "description_sha256": "b8b72779e476bec59973c68491f40f4d52373efdb1de9326f41d9382aec3917b",
  "icon_path": "icon/skill/1304_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Coloratura Cadenza",
    "mechanic_tags": [],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "434ba93c760746f7f5cbacc9d4b783358bc68fef37b4f9d26094ea1c112937ad"
  },
  {
    "requirement": "A4",
    "name": "Impromptu Flourish",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "25%"
    ],
    "description_sha256": "75bf9e7ce7fda9f7d021515398df94eaab3c862686b20e31072977cc039ea0b2"
  },
  {
    "requirement": "A6",
    "name": "Sequential Passage",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "5"
    ],
    "description_sha256": "323d086e8c185cd6f9218f24f6338d4fd520566a094aa4600ee30f00d2f142c4"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Land of Smiles",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "24%"
    ],
    "description_sha256": "400538389157dd0a7a138cf0e642958df956980ea9d2a1e5a094afadea9c7064"
  },
  {
    "eidolon": 2,
    "name": "Afternoon Tea For Two",
    "mechanic_tags": [
      "spd",
      "energy",
      "energy_regen_rate"
    ],
    "numeric_tokens": [
      "16%",
      "1"
    ],
    "description_sha256": "375f1fbcb10025c040584e6caf438e43e630b52a4c4e01105eeea452f329a26a"
  },
  {
    "eidolon": 3,
    "name": "Inverted Tuning",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "522efa16d739711790168f1aa4343e8a17dc0415dadec950508277593a041dfe"
  },
  {
    "eidolon": 4,
    "name": "Raindrop Key",
    "mechanic_tags": [
      "effect_res",
      "res",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "5ba8657d0e665865baa323da6017ed044c6f8b6f87128aaa44488db520de8e9f"
  },
  {
    "eidolon": 5,
    "name": "Lonestar's Lament",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+1",
      "10",
      "+2",
      "15"
    ],
    "description_sha256": "fffc4ac6dc9459a813f80aed08884dbe9ced343fa5a25cf041417a79e7e34034"
  },
  {
    "eidolon": 6,
    "name": "Moonless Midnight",
    "mechanic_tags": [
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "450%",
      "8"
    ],
    "description_sha256": "c781df5075354ccaa8561c6c86c963bc656de8441e7aebc6bb5f1a2de1ba48df"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
