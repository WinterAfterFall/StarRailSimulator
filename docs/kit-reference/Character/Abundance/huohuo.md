---
schema_version: "1.0.0"
unit_id: 40
name: "Huohuo"
slug: "huohuo"
rarity: 5
element: "Wind"
path: "Abundance"
role: "Healer"
affiliation: "Xianzhou Luofu"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/huohuo"
source_record_updated_at: "April 21st, 2026"
dataset_snapshot: "2026-05-30"
---

# Huohuo

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Abundance/Huohuo.h` |
| ธาตุ | **Wind** |
| Path | **Abundance** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review/calc patch 4.2) |

### Base Stats (Lv.80, ascended)
HP 1358 · ATK 601 · DEF 509 · SPD 98

---

### Basic ATK — Banner: Stormcaller (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **50% Max HP ของ Huohuo** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Talisman: Protection (ฮีล, Lv.10)
- ลบ debuff 1 อันจากเพื่อนเป้าหมาย + ฮีลเป้าหมาย = **24% Max HP + 640**
- ฮีลเพื่อนที่อยู่ติดกับเป้าหมาย = **19.2% Max HP + 512**
- Energy +30 · ไม่มี Toughness

### Ultimate — Tail: Spiritual Domination (Support, 140 energy, Lv.10)
- คืน Energy ให้เพื่อนทุกคน (ยกเว้นตัวเอง) = **20% ของ Max Energy** ของแต่ละคน
- +ATK **40%** ให้เพื่อนทุกคน นาน 2 เทิร์น
- Energy +5 · ไม่มี Toughness

### Talent — Possession: Ethereal Metaflow (Lv.10)
- หลังใช้ Skill/Ultimate → Huohuo ได้ **"Divine Provision"** นาน 3 เทิร์น (ลด 1 เทิร์นตอนเริ่มเทิร์นของ Huohuo)
- ขณะมี "Divine Provision" เมื่อเริ่มเทิร์นของเพื่อน หรือเพื่อนใช้ Ultimate:
  - ฮีลเพื่อนคนนั้น + เพื่อนที่ HP% ต่ำสุด = **4.5% Max HP + 120**
  - จากนั้นฮีลเพื่อนทุกคนที่ HP% ≤ 50% = **4.5% Max HP + 120**
- เมื่อ "Divine Provision" trigger ฮีลเพื่อน → ลบ debuff 1 อันจากตัวนั้น
- trigger ได้ **6 ครั้ง** ต่อการได้ "Divine Provision" 1 รอบ (ได้ใหม่ = รีเซ็ตตัวนับ)

### Technique — Fiend: Impeachment of Evil
- ติด Horror-Struck ให้ศัตรูรอบข้าง (หนีจาก Huohuo 10 วิ)
- เข้าการต่อสู้กับศัตรูที่ Horror-Struck → 100% base chance ลด ATK ศัตรูทุกตัว **25%** นาน 2 เทิร์น

---

### Major Traces
- **A2 — Fearful to Act**: เริ่มการต่อสู้ → Huohuo ได้ Energy **30** + "Divine Provision" นาน 2 เทิร์น
- **A4 — The Cursed One**: +35% ต้านทาน Crowd Control. เมื่อใช้ Ultimate ถ้าเพื่อนเป้าหมายมี Max Energy ≥ 160 → +ATK เพิ่มอีก **24%**
- **A6 — Stress Reaction to Horror**: เมื่อ Talent trigger ฮีลเพื่อน → Huohuo คืน Energy **1**

### Minor Traces (รวมทั้งหมด)
HP +28% · Effect RES +18% · SPD +5

### Eidolons
- **E1**: "Divine Provision" +1 เทิร์น. ขณะมี "Divine Provision" → Huohuo Outgoing Healing **+20%**, เพื่อนทุกคน SPD **+12%**
- **E2**: ขณะมี "Divine Provision" ถ้าเพื่อนโดน killing blow → ไม่ล้ม + ฮีลทันที **50% Max HP** ของตัวนั้น, ลด "Divine Provision" 1 เทิร์น. trigger ได้ 2 ครั้ง/การต่อสู้
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E4**: ฮีลผ่าน Skill/Talent → เป้าหมาย HP ยิ่งต่ำยิ่งฮีลมาก สูงสุด **+80%**
- **E5**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E6**: เมื่อฮีลเพื่อน → เป้าหมาย +DMG dealt **50%** นาน 2 เทิร์น

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ทุกอย่างสเกลกับ Max HP ของ Huohuo** (BA 50%, Skill 24%/19.2%, Talent 4.5%)
- **Divine Provision** = สถานะแกน: ให้ทั้ง passive heal (เริ่มเทิร์นเพื่อน / เพื่อนใช้ Ult), debuff cleanse, cap 6 ครั้ง, ลดเวลาตอนเริ่มเทิร์น Huohuo
- **Ultimate** = energy regen เป็น % ของ Max Energy เพื่อน (ไม่ใช่ค่าคงที่) + ATK% buff
- A4: ATK buff แยกเป็น 40% base + 24% conditional (Max Energy ≥ 160)
- A2: pre-combat energy 30 + Divine Provision 2 เทิร์น (โค้ดใน `Start_game_List`)
- E1 SPD +12% ทีม + Huohuo outgoing heal +20% ผูกกับการถือ Divine Provision
- E6 DMG buff 50% ติดตอนฮีล — apply กว้าง (ทุกครั้งที่ heal target)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/huohuo — kit tab (review/calc patch 4.2, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 40,
  "name": "Huohuo",
  "slug": "huohuo",
  "rarity": "5",
  "element": "Wind",
  "path": "Abundance",
  "default_role": "Healer",
  "affiliation": "Xianzhou Luofu",
  "release_date": "November 15th, 2023",
  "is_released": true,
  "ultimate_energy_cost": "140",
  "base_stats": {
    "hp_base": 184.8,
    "def_base": 69.3,
    "atk_base": 81.84,
    "speed_base": 98
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "hp",
      "value": 28
    },
    "traceStat2": {
      "stat": "effectRes",
      "value": 18
    },
    "traceStat3": {
      "stat": "Speed",
      "value": 5
    }
  },
  "voice_actors": {
    "en": "Courtney Lin & Adam Michael Gold",
    "kr": "김채린 (Kim Chae-rin) & 한복현 (Han Bok-hyun)",
    "jpn": "長縄まりあ (Naganawa Maria) & 平林剛 (Hirabayashi Takeshi)",
    "cn": "葛子瑞 (Ge Zirui ) & 刘北辰 (Liu Beichen)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/huohuo",
  "source_record_updated_at": "April 21st, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `121701` | Banner: Stormcaller | Basic ATK | Single Target |
| `skill` | `121702` | Talisman: Protection | Skill | Restore |
| `ult` | `121703` | Tail: Spiritual Domination | Ultimate | Support |
| `talent` | `121704` | Possession: Ethereal Metaflow | Talent | Restore |
| `technique` | `121707` | Fiend: Impeachment of Evil | Technique | Impair |

## Ability records

### Banner: Stormcaller

```json
{
  "ability_id": "121701",
  "slot": "basic",
  "name": "Banner: Stormcaller",
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
  "description_sha256": "20d0e4b4c2da7ddb95047da2625599c3c99406909f86bfef05590e9c8412d2f6",
  "icon_path": null
}
```

### Talisman: Protection

```json
{
  "ability_id": "121702",
  "slot": "skill",
  "name": "Talisman: Protection",
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
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 160,
          "unit": "scalar"
        },
        "p3": {
          "value": 12.8,
          "unit": "percent"
        },
        "p4": {
          "value": 128,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 17,
          "unit": "percent"
        },
        "p2": {
          "value": 256,
          "unit": "scalar"
        },
        "p3": {
          "value": 13.6,
          "unit": "percent"
        },
        "p4": {
          "value": 204.8,
          "unit": "scalar"
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
          "value": 328,
          "unit": "scalar"
        },
        "p3": {
          "value": 14.4,
          "unit": "percent"
        },
        "p4": {
          "value": 262.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19,
          "unit": "percent"
        },
        "p2": {
          "value": 400,
          "unit": "scalar"
        },
        "p3": {
          "value": 15.2,
          "unit": "percent"
        },
        "p4": {
          "value": 320,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        },
        "p2": {
          "value": 448,
          "unit": "scalar"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 358.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 20.8,
          "unit": "percent"
        },
        "p2": {
          "value": 496,
          "unit": "scalar"
        },
        "p3": {
          "value": 16.64,
          "unit": "percent"
        },
        "p4": {
          "value": 396.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 532,
          "unit": "scalar"
        },
        "p3": {
          "value": 17.28,
          "unit": "percent"
        },
        "p4": {
          "value": 425.6,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 22.4,
          "unit": "percent"
        },
        "p2": {
          "value": 568,
          "unit": "scalar"
        },
        "p3": {
          "value": 17.92,
          "unit": "percent"
        },
        "p4": {
          "value": 454.4,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 23.2,
          "unit": "percent"
        },
        "p2": {
          "value": 604,
          "unit": "scalar"
        },
        "p3": {
          "value": 18.56,
          "unit": "percent"
        },
        "p4": {
          "value": 483.2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 640,
          "unit": "scalar"
        },
        "p3": {
          "value": 19.2,
          "unit": "percent"
        },
        "p4": {
          "value": 512,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 24.8,
          "unit": "percent"
        },
        "p2": {
          "value": 676,
          "unit": "scalar"
        },
        "p3": {
          "value": 19.84,
          "unit": "percent"
        },
        "p4": {
          "value": 540.8,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 25.6,
          "unit": "percent"
        },
        "p2": {
          "value": 712,
          "unit": "scalar"
        },
        "p3": {
          "value": 20.48,
          "unit": "percent"
        },
        "p4": {
          "value": 569.6,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "6489fe01a6f65056d2569af1ad6869184c1147833718eccc7332e64f2939d623",
  "icon_path": null
}
```

### Tail: Spiritual Domination

```json
{
  "ability_id": "121703",
  "slot": "ult",
  "name": "Tail: Spiritual Domination",
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
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "atk",
    "energy"
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
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 15.5,
          "unit": "percent"
        },
        "p2": {
          "value": 25.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 16,
          "unit": "percent"
        },
        "p2": {
          "value": 27.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 16.5,
          "unit": "percent"
        },
        "p2": {
          "value": 28.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 17,
          "unit": "percent"
        },
        "p2": {
          "value": 30.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        },
        "p2": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 18.125,
          "unit": "percent"
        },
        "p2": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 18.75,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 19.375,
          "unit": "percent"
        },
        "p2": {
          "value": 38,
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
          "value": 20.5,
          "unit": "percent"
        },
        "p2": {
          "value": 41.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 21,
          "unit": "percent"
        },
        "p2": {
          "value": 43.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 21.5,
          "unit": "percent"
        },
        "p2": {
          "value": 44.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        },
        "p2": {
          "value": 46.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7b41a0f4ffd6d5cfa9f28a7c3ba05ba640cf4d4a9ca05f670d2743a5dd26c2ac",
  "icon_path": null
}
```

### Possession: Ethereal Metaflow

```json
{
  "ability_id": "121704",
  "slot": "talent",
  "name": "Possession: Ethereal Metaflow",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Restore",
  "targeting_label": "Restore",
  "element": "Wind",
  "energy_gain": null,
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
      "unit": "scalar",
      "occurrences": 2
    }
  },
  "mechanic_tags": [
    "max_hp",
    "healing",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 3,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 3.188,
          "unit": "percent"
        },
        "p2": {
          "value": 48,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 3.375,
          "unit": "percent"
        },
        "p2": {
          "value": 61.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 3.563,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 3.75,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 3.9,
          "unit": "percent"
        },
        "p2": {
          "value": 93,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 4.05,
          "unit": "percent"
        },
        "p2": {
          "value": 99.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 4.2,
          "unit": "percent"
        },
        "p2": {
          "value": 106.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 4.35,
          "unit": "percent"
        },
        "p2": {
          "value": 113.25,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 4.5,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 4.65,
          "unit": "percent"
        },
        "p2": {
          "value": 126.75,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 4.8,
          "unit": "percent"
        },
        "p2": {
          "value": 133.5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 4.95,
          "unit": "percent"
        },
        "p2": {
          "value": 140.25,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 5.1,
          "unit": "percent"
        },
        "p2": {
          "value": 147,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 5.25,
          "unit": "percent"
        },
        "p2": {
          "value": 153.75,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "18b9c0fe95e2a6a10f3e14152e417fdb1d4afd4d8b36a9a1d967f197b8c2b7f9",
  "icon_path": null
}
```

### Fiend: Impeachment of Evil

```json
{
  "ability_id": "121707",
  "slot": "technique",
  "name": "Fiend: Impeachment of Evil",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": "Impair",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk"
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
          "value": 0.25,
          "unit": "scalar"
        },
        "p3": {
          "value": 2,
          "unit": "scalar"
        },
        "p4": {
          "value": 10,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "216df6995df8fe6a9821eb6eeb1c990aa0223a70bd519e73e04836790326827b",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Fearful to Act",
    "mechanic_tags": [
      "energy"
    ],
    "numeric_tokens": [
      "30",
      "2"
    ],
    "description_sha256": "695c2f6a1749bff4b7ecb0d6e57275c89f54538476affcd0d9a49d6958bfb822"
  },
  {
    "requirement": "A4",
    "name": "The Cursed One",
    "mechanic_tags": [
      "atk",
      "energy",
      "debuff",
      "buff"
    ],
    "numeric_tokens": [
      "35%",
      "160",
      "24%"
    ],
    "description_sha256": "e4b2769544aab2e393c792ea2c839ce3cc249a1f38bbd6c1cc67220bf0de5652"
  },
  {
    "requirement": "A6",
    "name": "Stress Reaction to Horror",
    "mechanic_tags": [
      "energy",
      "healing"
    ],
    "numeric_tokens": [
      "1"
    ],
    "description_sha256": "88d45ab5baac47937a422b1b8367339204bc506233ba9f99570fccb2d27cacbe"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Anchored to Vessel, Specters Nestled",
    "mechanic_tags": [
      "spd",
      "healing"
    ],
    "numeric_tokens": [
      "1",
      "20%",
      "12%"
    ],
    "description_sha256": "b0bcc82b5d551a9e4b7981be08bd8330d9fd51697d02d0337bef509f08b03f9e"
  },
  {
    "eidolon": 2,
    "name": "Sealed in Tail, Wraith Subdued",
    "mechanic_tags": [
      "max_hp"
    ],
    "numeric_tokens": [
      "50%",
      "1",
      "2"
    ],
    "description_sha256": "aa9b9060d7a755f8c7e6f04e9dbbfcb4fdcdce42bc1f92191016028ecac91090"
  },
  {
    "eidolon": 3,
    "name": "Cursed by Fate, Moths to Flame",
    "mechanic_tags": [],
    "numeric_tokens": [
      "+2",
      "15",
      "+2",
      "15"
    ],
    "description_sha256": "cfd43f8b6221653cdf8eaca74be63108fdae1e2459a53da8296e4df350449940"
  },
  {
    "eidolon": 4,
    "name": "Tied in Life, Bound to Strife",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "80%"
    ],
    "description_sha256": "ed79217ab517def27f990c9fc92c8df582243c63f4b7e7d0b28fdf1705dfe4d5"
  },
  {
    "eidolon": 5,
    "name": "Mandated by Edict, Evils Evicted",
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
    "eidolon": 6,
    "name": "Woven Together, Cohere Forever",
    "mechanic_tags": [
      "dmg",
      "healing"
    ],
    "numeric_tokens": [
      "50%",
      "2"
    ],
    "description_sha256": "47c53e56687527055f9c6a32d1fdc0a4cf7e84e35c81cec040f38583b0ade344"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
