---
schema_version: "1.0.0"
unit_id: 75
name: "Hyacine"
slug: "hyacine"
rarity: 5
element: "Wind"
path: "Remembrance"
role: "Healer"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/hyacine"
source_record_updated_at: "June 10th, 2025"
dataset_snapshot: "2026-05-30"
---

# Hyacine

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Hyacine.h` |
| ธาตุ | **Wind** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1087 · ATK 388 · DEF 630 · SPD 110

> Remembrance healer สาย SPD scaling + memosprite **Little Ica** + healing-tally DMG

---

### Basic ATK — When Breeze Kisses Cirrus (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Love Over the Rainbow (Restore, Lv.10)
- เรียก **Little Ica**
- ฮีลเพื่อนทุกคน (ยกเว้น Little Ica) = **8% Max HP + 160**
- ฮีล Little Ica = **10% Max HP + 200**
- Energy +30

### Ultimate — We Who Fly Into Twilight (Support, 140 energy, Lv.10)
- เรียก Little Ica
- ฮีลเพื่อนทุกคน (ยกเว้น Little Ica) = **10% Max HP + 200**; ฮีล Little Ica = **12% Max HP + 240**
- Hyacine เข้าสถานะ **"After Rain"** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Hyacine)
- ขณะ After Rain: เพื่อนทุกคน Max HP **+30% + 600**
- Energy +5

### Talent — First Light Heals the World (Lv.10)
- Little Ica: initial Max HP = **50% ของ Max HP ของ Hyacine**
- เมื่อ Hyacine หรือ Little Ica ฮีล → Little Ica +DMG **80%** นาน 2 เทิร์น stack 3 ครั้ง

### Technique — Day So Right, Life So Fine!
- ต้นการต่อสู้ถัดไป → ฮีลเพื่อนทุกคน **30% Max HP + 600** + Max HP **+20%** นาน 2 เทิร์น

### Memosprite: Little Ica
#### Memosprite Skill — Rainclouds, Time to Go! (AoE, Lv.6)
- Wind DMG AoE = **20% ของ tally การฮีลทั้งหมดของ Hyacine + Little Ica ในการต่อสู้นี้** + ล้าง tally **50%** (E6 → 12%)
- Energy +5 · Toughness 10

#### Memosprite Talent
- **Take Sky in Hand**: Little Ica SPD คงที่ 0, ต้าน debuff, ไม่อยู่ใน Action Order. เมื่อเพื่อน (ยกเว้น Little Ica) เสีย HP → Little Ica กิน HP ตัวเอง **4% Max HP** และฮีลเพื่อนคนนั้น = **2% Max HP ของ Hyacine + 20** (ต้นเทิร์นใด ๆ / หลัง action ใด ๆ)
  - ขณะ After Rain: Little Ica ได้เทิร์นพิเศษทันที + auto "Rainclouds, Time to Go!" หลัง Hyacine ใช้ ability; เมื่อ Little Ica trigger heal → ฮีลเพื่อนทุกคนเพิ่ม **2% Max HP ของ Hyacine + 20**; หลัง Little Ica ใช้ ability → Continuous Effect ทั้งหมด duration −1
- **Soar, Unto the Sunlight**: เรียก Little Ica → คืน Energy **15** ให้ Hyacine (ครั้งแรก **30**)
- **Roar Rumbles the Realm**: Little Ica หาย → advance action Hyacine **30%**

---

### Major Traces
- **A2 — Gloomy Grin**: Hyacine + Little Ica CRIT Rate **+100%**. ฮีลเพื่อนที่ HP ≤ 50% Max HP → Hyacine + Little Ica Outgoing Healing **+25%**
- **A4 — Stormy Caress**: Hyacine Effect RES **+50%**. ใช้ Skill/Ult → ลบ debuff 1 อันจากเพื่อนทุกคน
- **A6 — Tempestuous Halt**: SPD > 200 → Hyacine + Little Ica Max HP **+20%**; ทุก 1 SPD ส่วนเกิน → Outgoing Healing **+1%** (นับสูงสุด 200 SPD ส่วนเกิน)

### Minor Traces (รวมทั้งหมด)
HP +10% · SPD +14 · Effect RES +18%

### Eidolons
- **E1**: ขณะ After Rain → เพื่อนทุกคน Max HP **+50%** เพิ่ม + หลัง Hyacine โจมตี → ฮีลตัวเอง **8% Max HP**
- **E2**: เมื่อเพื่อนเสีย HP → SPD **+30%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Skill Lv. +1
- **E4**: A6 enhanced — ทุก 1 SPD ส่วนเกิน → Hyacine + Little Ica CRIT DMG **+2%** เพิ่ม
- **E5**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Talent Lv. +1
- **E6**: Little Ica "Rainclouds" ล้าง tally เหลือ **12%**. ขณะ Little Ica อยู่ในสนาม → เพื่อนทุกคน All-Type RES PEN **+20%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Healing tally** = ผลรวมการฮีลของ Hyacine + Little Ica ทั้งการต่อสู้ → Little Ica Skill DMG = 20% ของ tally, ล้าง 50% (E6 12%)
- **Little Ica (memosprite)**: SPD 0, ไม่อยู่ใน action order, HP = 50% Hyacine HP; reactive heal เมื่อเพื่อนเสีย HP (กิน 4% HP ตัวเอง → ฮีล 2% Hyacine HP + 20)
- **ดาเมจ BA สเกลกับ Max HP** (50%); healing สเกลกับ Max HP ของ Hyacine
- **After Rain (Ult)**: Max HP +30%+600 ทีม (E1 +50%) + Little Ica extra turn loop
- **SPD scaling** (A6 > 200 → HP + heal%; E4 → CD) — Hyacine เป็น SPD-stacking healer
- **A2 CRIT Rate +100%** ให้ Hyacine + Little Ica
- โค้ด: `Start_game_List` (`Hyacine.h:97`, `Hycptr`, `Icaptr`) — Ica = Little Ica

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/hyacine — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 75,
  "name": "Hyacine",
  "slug": "hyacine",
  "rarity": "5",
  "element": "Wind",
  "path": "Remembrance",
  "default_role": "Healer",
  "affiliation": null,
  "release_date": "May 21st, 2025",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 148,
    "def_base": 85.8,
    "atk_base": 52.8,
    "speed_base": 110
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 10
    },
    "traceStat2": {
      "stat": "speed",
      "value": 14
    },
    "traceStat3": {
      "stat": "Effect RES",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "Holly Earl",
    "kr": "Kim Yeon-woo (김연우)",
    "jpn": "Yomiya Hina (羊宮 妃那)",
    "cn": "Jing Chen (静宸)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/hyacine",
  "source_record_updated_at": "June 10th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140901` | When Breeze Kisses Cirrus | Basic ATK | Single Target |
| `skill` | `140902` | Love Over the Rainbow | Skill | Restore |
| `ult` | `140903` | We Who Fly Into Twilight | Ultimate | Support |
| `talent` | `140904` | First Light Heals the World | Talent | Enhance |
| `technique` | `140907` | Day So Right, Life So Fine! | Technique | MazeAttack |
| `supplementary` | `1409010` | Rainclouds, Time to Go! | Memosprite Skill | AoE |
| `supplementary` | `1409011` | Take Sky in Hand | Memosprite Talent | Restore |
| `supplementary` | `1409012` | Soar, Unto the Sunlight | Memosprite Talent | Support |
| `supplementary` | `1409013` | Roar Rumbles the Realm | Memosprite Talent | Support |

## Ability records

### When Breeze Kisses Cirrus

```json
{
  "ability_id": "140901",
  "slot": "basic",
  "name": "When Breeze Kisses Cirrus",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
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
    "max_hp",
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
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 55,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 65,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7a48f2dfbf800b5b5aff857b1692a5b66a71313afac3c22b8611f5bedbae49c8",
  "icon_path": null
}
```

### Love Over the Rainbow

```json
{
  "ability_id": "140902",
  "slot": "skill",
  "name": "Love Over the Rainbow",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Wind",
  "energy_gain": "30",
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
    },
    "p3": {
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
    "healing",
    "summon"
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
          "value": 40,
          "unit": "scalar"
        },
        "p3": {
          "value": 5,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 4.5,
          "unit": "percent"
        },
        "p2": {
          "value": 64,
          "unit": "scalar"
        },
        "p3": {
          "value": 5.625,
          "unit": "percent"
        },
        "p4": {
          "value": 80,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        },
        "p2": {
          "value": 82,
          "unit": "scalar"
        },
        "p3": {
          "value": 6.25,
          "unit": "percent"
        },
        "p4": {
          "value": 102.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 5.5,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "scalar"
        },
        "p3": {
          "value": 6.875,
          "unit": "percent"
        },
        "p4": {
          "value": 125,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 6,
          "unit": "percent"
        },
        "p2": {
          "value": 112,
          "unit": "scalar"
        },
        "p3": {
          "value": 7.5,
          "unit": "percent"
        },
        "p4": {
          "value": 140,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 6.4,
          "unit": "percent"
        },
        "p2": {
          "value": 124,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "percent"
        },
        "p4": {
          "value": 155,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 6.8,
          "unit": "percent"
        },
        "p2": {
          "value": 133,
          "unit": "scalar"
        },
        "p3": {
          "value": 8.5,
          "unit": "percent"
        },
        "p4": {
          "value": 166.25,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 7.2,
          "unit": "percent"
        },
        "p2": {
          "value": 142,
          "unit": "scalar"
        },
        "p3": {
          "value": 9,
          "unit": "percent"
        },
        "p4": {
          "value": 177.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 7.6,
          "unit": "percent"
        },
        "p2": {
          "value": 151,
          "unit": "scalar"
        },
        "p3": {
          "value": 9.5,
          "unit": "percent"
        },
        "p4": {
          "value": 188.75,
          "unit": "scalar"
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
          "value": 160,
          "unit": "scalar"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 200,
          "unit": "scalar"
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
          "value": 169,
          "unit": "scalar"
        },
        "p3": {
          "value": 10.5,
          "unit": "percent"
        },
        "p4": {
          "value": 211.25,
          "unit": "scalar"
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
          "value": 175,
          "unit": "scalar"
        },
        "p3": {
          "value": 12,
          "unit": "percent"
        },
        "p4": {
          "value": 225.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9dea4a127a89b7e34ef8ca74cc4383be1eabfb5b25604d790a6f410e1d32807d",
  "icon_path": null
}
```

### We Who Fly Into Twilight

```json
{
  "ability_id": "140903",
  "slot": "ult",
  "name": "We Who Fly Into Twilight",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "140",
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
    "p5": {
      "unit": "percent",
      "occurrences": 1
    },
    "p6": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
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
    "healing",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 5,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 150,
          "unit": "scalar"
        },
        "p5": {
          "value": 6,
          "unit": "percent"
        },
        "p6": {
          "value": 60,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 5.625,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 16.5,
          "unit": "percent"
        },
        "p4": {
          "value": 240,
          "unit": "scalar"
        },
        "p5": {
          "value": 6.75,
          "unit": "percent"
        },
        "p6": {
          "value": 96,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 6.25,
          "unit": "percent"
        },
        "p2": {
          "value": 102.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 307.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 7.5,
          "unit": "percent"
        },
        "p6": {
          "value": 123,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 6.875,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "scalar"
        },
        "p3": {
          "value": 19.5,
          "unit": "percent"
        },
        "p4": {
          "value": 375,
          "unit": "scalar"
        },
        "p5": {
          "value": 8.25,
          "unit": "percent"
        },
        "p6": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 7.5,
          "unit": "percent"
        },
        "p2": {
          "value": 140,
          "unit": "scalar"
        },
        "p3": {
          "value": 21,
          "unit": "percent"
        },
        "p4": {
          "value": 420,
          "unit": "scalar"
        },
        "p5": {
          "value": 9,
          "unit": "percent"
        },
        "p6": {
          "value": 168,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 8,
          "unit": "percent"
        },
        "p2": {
          "value": 155,
          "unit": "scalar"
        },
        "p3": {
          "value": 22.5,
          "unit": "percent"
        },
        "p4": {
          "value": 465,
          "unit": "scalar"
        },
        "p5": {
          "value": 9.6,
          "unit": "percent"
        },
        "p6": {
          "value": 186,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 8.5,
          "unit": "percent"
        },
        "p2": {
          "value": 166.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 24.375,
          "unit": "percent"
        },
        "p4": {
          "value": 498.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.2,
          "unit": "percent"
        },
        "p6": {
          "value": 199.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 9,
          "unit": "percent"
        },
        "p2": {
          "value": 177.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 26.25,
          "unit": "percent"
        },
        "p4": {
          "value": 532.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.8,
          "unit": "percent"
        },
        "p6": {
          "value": 213,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 9.5,
          "unit": "percent"
        },
        "p2": {
          "value": 188.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 28.125,
          "unit": "percent"
        },
        "p4": {
          "value": 566.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 11.4,
          "unit": "percent"
        },
        "p6": {
          "value": 226.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 10,
          "unit": "percent"
        },
        "p2": {
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 600,
          "unit": "scalar"
        },
        "p5": {
          "value": 12,
          "unit": "percent"
        },
        "p6": {
          "value": 240,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 10.5,
          "unit": "percent"
        },
        "p2": {
          "value": 211.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 31.5,
          "unit": "percent"
        },
        "p4": {
          "value": 633.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 12.6,
          "unit": "percent"
        },
        "p6": {
          "value": 253.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 11,
          "unit": "percent"
        },
        "p2": {
          "value": 222.5,
          "unit": "scalar"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        },
        "p4": {
          "value": 667.5,
          "unit": "scalar"
        },
        "p5": {
          "value": 13.2,
          "unit": "percent"
        },
        "p6": {
          "value": 267,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 11.5,
          "unit": "percent"
        },
        "p2": {
          "value": 233.75,
          "unit": "scalar"
        },
        "p3": {
          "value": 34.5,
          "unit": "percent"
        },
        "p4": {
          "value": 701.25,
          "unit": "scalar"
        },
        "p5": {
          "value": 13.8,
          "unit": "percent"
        },
        "p6": {
          "value": 280.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 245,
          "unit": "scalar"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
        },
        "p4": {
          "value": 735,
          "unit": "scalar"
        },
        "p5": {
          "value": 14.4,
          "unit": "percent"
        },
        "p6": {
          "value": 294,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 12.5,
          "unit": "percent"
        },
        "p2": {
          "value": 256.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 37.5,
          "unit": "percent"
        },
        "p4": {
          "value": 768.75,
          "unit": "scalar"
        },
        "p5": {
          "value": 15,
          "unit": "percent"
        },
        "p6": {
          "value": 307.5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9ca4537f74b5a9327bb940919cc37de6ee96a52abad13b0144a4e6b1113575bf",
  "icon_path": null
}
```

### First Light Heals the World

```json
{
  "ability_id": "140904",
  "slot": "talent",
  "name": "First Light Heals the World",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Wind",
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
    "max_hp",
    "dmg",
    "healing",
    "summon"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 40,
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
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 48,
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
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 56,
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
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 65,
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
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 75,
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
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 84,
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
        }
      }
    }
  ],
  "description_sha256": "8142c5bc533c1a001c2538d29bad150f2f4cc644762b94aa992c7e5941c2ccaa",
  "icon_path": null
}
```

### Day So Right, Life So Fine!

```json
{
  "ability_id": "140907",
  "slot": "technique",
  "name": "Day So Right, Life So Fine!",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "max_hp",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 30,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1ec2b1f96ddf1ab5b6b4fd9b59049a3968f4be0455cd948d2887eaa24266e72d",
  "icon_path": null
}
```

### Rainclouds, Time to Go!

```json
{
  "ability_id": "1409010",
  "slot": "supplementary",
  "name": "Rainclouds, Time to Go!",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Wind",
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
    "healing"
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
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "640b7b46eeb1cc070a74464553334e6f02415802d62f02252a06bdd04b004f9c",
  "icon_path": null
}
```

### Take Sky in Hand

```json
{
  "ability_id": "1409011",
  "slot": "supplementary",
  "name": "Take Sky in Hand",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 2
    },
    "p2": {
      "unit": "scalar",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "max_hp",
    "spd",
    "healing",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "percent"
        },
        "p2": {
          "value": 10,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1.2,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1.4,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1.6,
          "unit": "percent"
        },
        "p2": {
          "value": 16,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1.8,
          "unit": "percent"
        },
        "p2": {
          "value": 18,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 2,
          "unit": "percent"
        },
        "p2": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 2.2,
          "unit": "percent"
        },
        "p2": {
          "value": 22,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 2.4,
          "unit": "percent"
        },
        "p2": {
          "value": 24,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 2.6,
          "unit": "percent"
        },
        "p2": {
          "value": 26,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "a1895907af2cb2dd306e3ef2199b6bed658276a6ae936fafa2a6d2041b896fe9",
  "icon_path": null
}
```

### Soar, Unto the Sunlight

```json
{
  "ability_id": "1409012",
  "slot": "supplementary",
  "name": "Soar, Unto the Sunlight",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "energy",
    "summon"
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
    }
  ],
  "description_sha256": "a464409154a3aad3e068fff6d94eafcff31634a69854c3742c1f0d05e55cfaad",
  "icon_path": null
}
```

### Roar Rumbles the Realm

```json
{
  "ability_id": "1409013",
  "slot": "supplementary",
  "name": "Roar Rumbles the Realm",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
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
  "description_sha256": "ec63ee1ba6de5de8184521dee9d0b1210eef5b3c81698894ee006cac2db470f0",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Gloomy Grin",
    "mechanic_tags": [
      "max_hp",
      "crit_rate",
      "healing"
    ],
    "numeric_tokens": [
      "100%",
      "50%",
      "25%"
    ],
    "description_sha256": "76ed5770d8f54e7d0b76d25eaf71d9765d64d0c7e45ae148d78681fb72e63b94"
  },
  {
    "requirement": "A4",
    "name": "Stormy Caress",
    "mechanic_tags": [
      "effect_res",
      "res",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "50%",
      "1"
    ],
    "description_sha256": "e0ca6661a9fae73d0cb6ae7a84db3a71e71eb2360a6914d220a07caad360a3e8"
  },
  {
    "requirement": "A6",
    "name": "Tempestuous Halt",
    "mechanic_tags": [
      "max_hp",
      "spd",
      "healing"
    ],
    "numeric_tokens": [
      "200",
      "20%",
      "1",
      "1%",
      "200"
    ],
    "description_sha256": "c23a40e10d19d65236342fc21b1842d68e16949410e0936a3ce535f8433dcda9"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Cradle the Candle of Night",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "50%",
      "8%"
    ],
    "description_sha256": "9ee753e493493e370f9369cf4477bba75745921628649d726aeab56da49c1389"
  },
  {
    "eidolon": 2,
    "name": "Come Sit in My Courtyard",
    "mechanic_tags": [
      "max_hp",
      "spd"
    ],
    "numeric_tokens": [
      "30%",
      "2"
    ],
    "description_sha256": "6a7d9a32a2b9d761a295d9e87b49b7700ed3cb214338028cecf74862dd357cf9"
  },
  {
    "eidolon": 3,
    "name": "Depart, Unto the Sun!",
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
    "eidolon": 4,
    "name": "Sunlit Amber, Yours to Keep",
    "mechanic_tags": [
      "spd",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "1",
      "2%"
    ],
    "description_sha256": "e6780e861b2f29c64f62695ee9cdb30b8387cf3a02a5620b583f063ef2857822"
  },
  {
    "eidolon": 5,
    "name": "Twilight Drapes the Tide",
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
    "eidolon": 6,
    "name": "O Sky, Heed My Plea",
    "mechanic_tags": [
      "res_pen",
      "res",
      "healing",
      "summon"
    ],
    "numeric_tokens": [
      "12%",
      "20%"
    ],
    "description_sha256": "2f1473c5e98569358e3cecbbc6cf55b7b2f1c27511f024035279288526f18e97"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
