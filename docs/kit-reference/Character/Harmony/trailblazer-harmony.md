---
schema_version: "1.0.0"
unit_id: 60
name: "Trailblazer • Harmony"
slug: "trailblazer-harmony"
rarity: 5
element: "Imaginary"
path: "Harmony"
role: "Support"
affiliation: "Astral Express"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/trailblazer-harmony"
source_record_updated_at: "January 25th, 2025"
dataset_snapshot: "2026-05-30"
---

# Trailblazer • Harmony

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Harmony_MC.h` |
| ธาตุ | **Imaginary** |
| Path | **Harmony** |
| ระดับ | 5★ (MC) |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 2.6 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1086 · ATK 446 · DEF 679 · SPD 105

> Harmony support สาย Super Break enabler

---

### Basic ATK — Swing Dance Etiquette (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Halftime to Make It Rain (Bounce, Lv.10)
- Imaginary DMG = **50% ATK** ใส่เป้าหมาย + เพิ่ม **4 instance × 50% ATK** ใส่ศัตรูสุ่ม
- Energy +6 · Toughness 10 (ต่อ instance)

### Ultimate — All-Out Footlight Parade (Support, 140 energy, Lv.10)
- มอบ **Backup Dancer** ให้เพื่อนทุกคน นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Trailblazer)
- เพื่อนที่มี Backup Dancer: Break Effect **+30%**
- เมื่อเพื่อนที่มี Backup Dancer โจมตีศัตรูที่ **Weakness Broken** → Toughness Reduction ของการโจมตีนั้นแปลงเป็น **Super Break DMG** 1 instance
- Energy +5

### Talent — Full-on Aerial Dance (Lv.10)
- เมื่อศัตรู Weakness Broken → Trailblazer คืน Energy **10** ทันที

### Technique — Now! I'm the Band!
- หลังใช้ Technique → เริ่มการต่อสู้ถัดไป เพื่อนทุกคน Break Effect **+30%** นาน 2 เทิร์น

---

### Major Traces
- **A2 — Dance With the One**: จำนวนศัตรู 5+/4/3/2/1 → Super Break DMG จาก Backup Dancer **+20%/+30%/+40%/+50%/+60%**
- **A4 — Shuffle Along**: ใช้ Skill → Toughness Reduction ของ instance แรก **+100%**
- **A6 — Hat of the Theater**: เมื่อเพื่อน Break Weakness ศัตรู → delay action ศัตรู **+30%**

### Minor Traces (รวมทั้งหมด)
Break Effect +37.3% · Imaginary DMG +14.4% · Effect RES +10%

### Eidolons
- **E1**: ใช้ Skill ครั้งแรก → คืน Skill Point **1**
- **E2**: ต้นการต่อสู้ → Trailblazer Energy Regen Rate **+25%** นาน 3 เทิร์น
- **E3**: Skill Lv. +2 · Talent Lv. +2
- **E4**: ขณะ Trailblazer อยู่ในสนาม → เพื่อน (ยกเว้น Trailblazer) Break Effect **+เท่ากับ 15% ของ Break Effect ของ Trailblazer**
- **E5**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E6**: จำนวน additional DMG instance ของ Skill **+2** (รวม 6)

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Backup Dancer** = แกนกลไก: BE +30% + Super Break conversion เมื่อตี broken enemy
- **Super Break DMG** = f(Toughness Reduction ของการโจมตี, BE ของผู้โจมตี) × A2 multiplier (ตามจำนวนศัตรู)
- **A4**: Skill instance แรก toughness reduction ×2
- **Talent**: energy +10 ต่อ enemy break (ตัว Trailblazer เอง)
- **E4**: BE share 15% ของ Trailblazer ให้เพื่อน — ผูกกับ BE stat ต้อง re-eval
- โค้ด: `Start_game_List` (`Harmony_MC.h:62`) — technique BE buff

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/trailblazer-harmony — kit tab (review patch 2.6, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 60,
  "name": "Trailblazer • Harmony",
  "slug": "trailblazer-harmony",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": "Astral Express",
  "release_date": "May 8th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 147.84,
    "def_base": 92.4,
    "atk_base": 60.72,
    "speed_base": 105
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Break Effect",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "Imaginary DMG",
      "value": 14.4
    },
    "traceStat3": {
      "stat": "Effect RES",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Rachael Chau | Caleb Yen",
    "kr": "Kim Ha-ru (김하루) | Kim Myung-jun (김명준)",
    "jpn": "Ishikawa Yui (石川 由依) | Enoki Junya (榎木 淳弥)",
    "cn": "Chen Tingting (陈婷婷) | Qin Juge (秦且歌)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/trailblazer-harmony",
  "source_record_updated_at": "January 25th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `800501` | Swing Dance Etiquette | Basic ATK | Single Target |
| `skill` | `800502` | Halftime to Make It Rain | Skill | Bounce |
| `ult` | `800503` | All-Out Footlight Parade | Ultimate | Support |
| `talent` | `800504` | Full-on Aerial Dance | Talent | Impair |
| `technique` | `800507` | Now! I'm the Band! | Technique | Defense |

## Ability records

### Swing Dance Etiquette

```json
{
  "ability_id": "800501",
  "slot": "basic",
  "name": "Swing Dance Etiquette",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
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
  "description_sha256": "8b79745b8c85f1ba73150fae70b425a9ef1891ee6600c4106d7b9df05793b552",
  "icon_path": "icon/skill/1304_basic_atk.png"
}
```

### Halftime to Make It Rain

```json
{
  "ability_id": "800502",
  "slot": "skill",
  "name": "Halftime to Make It Rain",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Imaginary",
  "energy_gain": "6",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
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
    }
  ],
  "description_sha256": "3bfca81c63b7f610c293964285d9c8ca10d837673f8bc494fc151a023f1df56b",
  "icon_path": "icon/skill/1304_skill.png"
}
```

### All-Out Footlight Parade

```json
{
  "ability_id": "800503",
  "slot": "ult",
  "name": "All-Out Footlight Parade",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
    "break_effect",
    "dmg",
    "toughness",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 18,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 24.375,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 28.125,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 31.5,
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
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 34.5,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2e1001aaff74bacd42d27921decec268b00b38f36e54d3993822334bb9c39b88",
  "icon_path": "icon/skill/1304_ultimate.png"
}
```

### Full-on Aerial Dance

```json
{
  "ability_id": "800504",
  "slot": "talent",
  "name": "Full-on Aerial Dance",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "energy",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 6.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8.125,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 8.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.375,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "37c7ad652402cb1a8a7377b4e298ad283316a11d395f37728d52a15a5eb779fe",
  "icon_path": "icon/skill/1304_talent.png"
}
```

### Now! I'm the Band!

```json
{
  "ability_id": "800507",
  "slot": "technique",
  "name": "Now! I'm the Band!",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
    "break_effect"
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
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "2f5473fa538647b78c916cebf420f7674b65cd8e7cdecbaf0884a07fce7bbf19",
  "icon_path": "icon/skill/1304_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Dance With the One",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "5",
      "4",
      "3",
      "2",
      "1",
      "20%",
      "30%",
      "40%",
      "50%",
      "60%"
    ],
    "description_sha256": "7a8aa154bfa34d92afcb110cb2d71b48a4a55a8be42449a7b58dac6d769685ad"
  },
  {
    "requirement": "A4",
    "name": "Shuffle Along",
    "mechanic_tags": [
      "dmg",
      "toughness"
    ],
    "numeric_tokens": [
      "100%"
    ],
    "description_sha256": "85ca2009e1fd04101b3871472cbe11aa548fcfdc0546cdf0022fba8d0da03d81"
  },
  {
    "requirement": "A6",
    "name": "Hat of the Theater",
    "mechanic_tags": [
      "weakness"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "025afde11e19792c01c4591eb0f0d2b337ea2ce6ac4773404b50377bd065d2d8"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Best Seat in the House",
    "mechanic_tags": [
      "skill_points"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "b9d6b734ed9cd0397b7c9c6a263cfef98cb133aa4c638115e25925972436e41a"
  },
  {
    "eidolon": 2,
    "name": "Jailbreaking Rainbowwalk",
    "mechanic_tags": [
      "energy",
      "energy_regen_rate"
    ],
    "numeric_tokens": [
      "25%",
      "3"
    ],
    "description_sha256": "df5d28eb858dca85be6f8fe84cd1dc7df66492c39063c7634921c02fe1d989dd"
  },
  {
    "eidolon": 3,
    "name": "Sanatorium for Rest Notes",
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
    "eidolon": 4,
    "name": "Dove in Tophat",
    "mechanic_tags": [
      "break_effect"
    ],
    "numeric_tokens": [
      "15%"
    ],
    "description_sha256": "633d7d6a21344e2a7aca16024b092796c1f4bdf44aed6bea7220944b917688ab"
  },
  {
    "eidolon": 5,
    "name": "Poem Favors Rhythms of Old",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "cc300732b097e46b67b9094ab43cb9e46f3f73b77a0f20c05a0dc575ef066a9d"
  },
  {
    "eidolon": 6,
    "name": "Tomorrow, Rest in Spotlight",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "2"
    ],
    "description_sha256": "de01761d4a76b7caadfb30b9df91de6f772aac6ac2236d8f830c2d5113f44934"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
