---
schema_version: "1.0.0"
unit_id: 72
name: "Castorice"
slug: "castorice"
rarity: 5
element: "Quantum"
path: "Remembrance"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/castorice"
source_record_updated_at: "December 27th, 2025"
dataset_snapshot: "2026-05-30"
---

# Castorice

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Castorice.h` |
| ธาตุ | **Quantum** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 0 (ใช้ "Newbud" เป็นทรัพยากร ไม่มี energy) |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.6) |

### Base Stats (Lv.80, ascended)
HP 1631 · ATK 523 · DEF 485 · SPD 95

> Remembrance DPS สาย HP-consumption + memosprite **Netherwing** (มังกร)

---

### Basic ATK — Lament, Nethersea's Ripple (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +0 · Toughness 10

### Skill — Silence, Wraithfly's Caress (Blast, Lv.10)
- กิน HP **30% ของ HP ปัจจุบัน** ของเพื่อนทุกคน (ไม่พอ → HP = 1)
- Quantum DMG หลัก = **50% Max HP**, ข้างเคียง = **30% Max HP**
- ถ้ามี Netherwing ในสนาม → Skill เป็น "Boneclaw, Doomdrake's Embrace" แทน
- Energy +0 · Toughness 20 (+10)

### Skill (Enhanced) — Boneclaw, Doomdrake's Embrace (AoE, Lv.10)
- กิน HP **40% ของ HP ปัจจุบัน** ของเพื่อนทุกคน (ยกเว้น Netherwing)
- Joint ATK (Castorice + Netherwing): Quantum DMG = **30%** + **50% Max HP ของ Castorice** ใส่ศัตรูทุกตัว
- Energy +0 · Toughness 20

### Ultimate — Doomshriek, Dawn's Chime (Summon, 0 energy, Lv.10)
- เรียก **Netherwing** + advance action **100%**
- สร้าง Territory **"Lost Netherland"**: ศัตรูทุกตัว All-Type RES **−20%**
- ถ้า DMG Boost จาก Talent active → ขยายผลให้ Netherwing ด้วย
- Netherwing: initial SPD **165**, Max HP = **100% ของ max Newbud**
- Netherwing อยู่ 3 เทิร์น หรือ HP = 0 → หาย + Territory หาย

### Talent — Desolation Across Palms (Lv.10)
- max "Newbud" อิงตามเลเวลของตัวละครทุกตัวในสนาม
- ต่อ 1 HP ที่เพื่อนทุกคนเสีย → Castorice ได้ "Newbud" **+1**
- Newbud เต็ม → ใช้ Ultimate ได้
- เมื่อเพื่อนเสีย HP → Castorice + Netherwing +DMG **20%** stack 3 ครั้ง นาน 3 เทิร์น
- ขณะมี Netherwing → ได้ Newbud จาก Talent ไม่ได้ + HP ที่เพื่อน (ยกเว้น Netherwing) เสีย → แปลงเป็น HP ให้ Netherwing เท่ากัน

### Technique — Wail, Death's Herald
- เข้าสถานะ "Netherveil" 20 วิ
- โจมตี → ศัตรูในระยะเข้าฉาก + เรียก Netherwing (advance 100%) + สร้าง Territory
- Netherwing เริ่มด้วย HP = **50% ของ max Newbud**
- เข้าฉาก → กิน HP **40%** ของ HP ปัจจุบันเพื่อน (ยกเว้น Netherwing); ก่อนเรียก Netherwing → Castorice ได้ Newbud = **30% ของ max**

### Unique — Sanctuary of Mooncocoon
- เมื่อเพื่อนโดน killing blow → เข้าสถานะ "Mooncocoon" (เลื่อนการล้ม, ทำ action ได้ปกติ); หลัง action ถ้า HP เพิ่มหรือได้ Shield → หาย, ไม่งั้นล้มทันที. trigger 1 ครั้ง/การต่อสู้

### Memosprite: Netherwing
#### Memosprite Skill — Claw Splits the Veil (AoE, Lv.6)
- Quantum DMG = **40% Max HP ของ Castorice** ใส่ศัตรูทุกตัว · Toughness 10

#### Memosprite Skill — Breath Scorches the Shadow (AoE, Lv.6)
- กิน **25% Max HP ของ Netherwing** → Quantum DMG = **24% Max HP ของ Castorice** AoE
- ใช้ซ้ำในการโจมตีเดียวได้ multiplier เพิ่มเป็น **28% / 34%** (สูงสุด 34%; boost คงอยู่จนกว่า Netherwing หาย)
- HP Netherwing ≤ 25% → ใช้แล้ว HP เหลือ 1 + trigger effect ของ "Wings Sweep the Ruins"
- Toughness 10

#### Memosprite Talent
- **Mooncocoon Shrouds the Form**: Netherwing เป็น backup — เมื่อเพื่อนรับดาเมจ/เสีย HP → HP เพื่อนลดต่ำสุดถึง 1, จากนั้น Netherwing เสีย HP = **500% ของค่าเดิม**
- **Roar Rumbles the Realm**: เรียก Netherwing → เพื่อนทุกคน +DMG **10%** นาน 3 เทิร์น
- **Wings Sweep the Ruins**: Netherwing หาย → **6 instance × 40% Max HP ของ Castorice** Quantum DMG ใส่ศัตรูสุ่ม + ฮีลเพื่อนทุกคน **6% Max HP ของ Castorice + 800**

---

### Major Traces
- **A2 — Contained Dark Tide**: หลังเพื่อน (ยกเว้น Netherwing) รับ heal → แปลง **100% ของ heal** เป็น Newbud (หรือ HP ของ Netherwing ถ้ามีในสนาม); ต่อ ally ไม่เกิน **12% ของ max Newbud**; รีเซ็ตสะสมหลังหน่วยใด action
- **A4 — Inverted Torch**: HP Castorice ≥ 50% Max HP → SPD **+40%**. เมื่อ Breath Scorches the Shadow ทำ fatal ทั้งสนาม → Netherwing SPD **+100%** 1 เทิร์น
- **A6 — Where The West Wind Dwells**: ทุกครั้ง Breath Scorches the Shadow → Netherwing +DMG **30%** stack 6 ครั้ง (จนจบเทิร์น)

### Minor Traces (รวมทั้งหมด)
CRIT Rate +18.7% · CRIT DMG +13.3% · Quantum DMG +14.4%

### Eidolons
- **E1**: HP ศัตรู ≤ 80%/50% ของ Max HP ของ Castorice → ดาเมจของ Boneclaw/Claw Splits/Breath Scorches/Wings Sweep = **120%/140%** ของเดิม
- **E2**: หลังเรียก Netherwing → Castorice ได้ "Ardent Will" 2 stack (cap 2) → ใช้หักล้าง HP consumption ของ Breath Scorches + advance action Castorice 100%. Enhanced Skill ครั้งถัดไป → Castorice ได้ Newbud 30% ของ max
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Talent Lv. +1
- **E4**: ขณะ Castorice อยู่ในสนาม → เพื่อนทุกคน Incoming Healing **+20%** เมื่อได้รับการฮีล
- **E5**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Skill Lv. +1
- **E6**: เมื่อ Castorice/Netherwing สร้างดาเมจ → Quantum RES PEN **+20%**. Netherwing โจมตีได้ ignore weakness toughness + trigger Quantum break. Wings Sweep the Ruins bounce **+3**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ไม่มี energy** — Ult ใช้ "Newbud" (สะสมจาก HP loss ของทีม 1:1, max อิงเลเวล); โค้ด `SetCharBasicStats(...,0,0,...)` (energy 0)
- **ดาเมจทุกท่าสเกลกับ Max HP ของ Castorice** (BA 50%, Skill 50/30, Boneclaw 30+50, Claw 40%, Breath 24-34%, Wings 40%/hit)
- **Netherwing (memosprite)**: SPD 165, HP = 100% max Newbud; อยู่ 3 เทิร์น/HP 0; auto-action; Mooncocoon backup (500% HP drain); Wings Sweep ตอนหาย
- **HP consumption**: Skill 30%, Boneclaw 40%, Technique 40% — ทีมต้องรอด (Mooncocoon / floor HP 1)
- **DMG Boost (Talent)**: +20%/stack เมื่อเพื่อนเสีย HP (cap 3)
- **A2 heal→Newbud/Netherwing HP conversion** 100% (cap 12% max ต่อ ally)
- โค้ด: `Start_game_List` (`Castorice.h:174`, `Casptr`, `Polluxptr`) — "Pollux" = ชื่อภายในของ Netherwing?

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/castorice — kit tab (review patch 3.2, calc patch 3.6, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 72,
  "name": "Castorice",
  "slug": "castorice",
  "rarity": "5",
  "element": "Quantum",
  "path": "Remembrance",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "April 2nd, 2025",
  "is_released": true,
  "ultimate_energy_cost": "0",
  "base_stats": {
    "hp_base": 222,
    "def_base": 66,
    "atk_base": 71.28,
    "speed_base": 95
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 18.7
    },
    "traceStat2": {
      "stat": "CRIT DMG",
      "value": 13.3
    },
    "traceStat3": {
      "stat": "Quantum DMG",
      "value": 14.4
    }
  },
  "voice_actors": {
    "en": "Melody Muze",
    "kr": "Lee Serena (이세레나)",
    "jpn": "Saitou Chiwa (斎藤 千和)",
    "cn": "Ruan Congqing (阮从青)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/castorice",
  "source_record_updated_at": "December 27th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140701` | Lament, Nethersea's Ripple | Basic ATK | Single Target |
| `skill` | `140702` | Silence, Wraithfly's Caress | Skill | Blast |
| `skill_enh` | `140708` | Boneclaw, Doomdrake's Embrace | AoE | AoE |
| `ult` | `140703` | Doomshriek, Dawn's Chime | Ultimate | Summon |
| `talent` | `140704` | Desolation Across Palms | Talent | Enhance |
| `technique` | `140707` | Wail, Death's Herald | Technique | MazeAttack |
| `supplementary` | `140706` | Sanctuary of Mooncocoon | Unique | Unique |
| `supplementary` | `1407010` | Claw Splits the Veil | Memosprite Skill | AoE |
| `supplementary` | `1407011` | Breath Scorches the Shadow | Memosprite Skill | AoE |
| `supplementary` | `1407012` | Mooncocoon Shrouds the Form | Memosprite Talent | Support |
| `supplementary` | `1407013` | Roar Rumbles the Realm | Memosprite Talent | Support |
| `supplementary` | `1407014` | Wings Sweep the Ruins | Memosprite Talent | Bounce |

## Ability records

### Lament, Nethersea's Ripple

```json
{
  "ability_id": "140701",
  "slot": "basic",
  "name": "Lament, Nethersea's Ripple",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "0",
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
  "description_sha256": "b14d46a9c5a0c66438ee32d5b6e91b9d98e728112bf5d4fcdfec0c0914ea0328",
  "icon_path": "icon/skill/1407_basic_atk.png"
}
```

### Silence, Wraithfly's Caress

```json
{
  "ability_id": "140702",
  "slot": "skill",
  "name": "Silence, Wraithfly's Caress",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
  "energy_gain": "0",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
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
    "dmg"
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
          "value": 15,
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
        },
        "p2": {
          "value": 16.5,
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
        },
        "p2": {
          "value": 18,
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
        },
        "p2": {
          "value": 19.5,
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
        },
        "p2": {
          "value": 21,
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
        },
        "p2": {
          "value": 22.5,
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
        },
        "p2": {
          "value": 24.375,
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
        },
        "p2": {
          "value": 26.25,
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
        },
        "p2": {
          "value": 28.125,
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
          "value": 52.5,
          "unit": "percent"
        },
        "p2": {
          "value": 31.5,
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
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9f6242f5018c6c37a98d169e0a80ebb40ab61c8c29d37abbbb3cad8cd183e1e6",
  "icon_path": "icon/skill/1407_skill.png"
}
```

### Boneclaw, Doomdrake's Embrace

```json
{
  "ability_id": "140708",
  "slot": "skill_enh",
  "name": "Boneclaw, Doomdrake's Embrace",
  "type_code": "Normal",
  "type_label": "AoE",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
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
    "max_hp",
    "atk",
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
          "value": 25,
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
          "value": 27.5,
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
          "value": 30,
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
          "value": 32.5,
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
          "value": 35,
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
          "value": 37.5,
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
          "value": 40.625,
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
          "value": 43.75,
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
          "value": 46.875,
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
          "value": 50,
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
          "value": 52.5,
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
          "value": 55,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "722030d767578b001cd6234b3280b686819794b16185afbdbde0e8238b9d5752",
  "icon_path": "icon/skill/1407_basic_atk.png"
}
```

### Doomshriek, Dawn's Chime

```json
{
  "ability_id": "140703",
  "slot": "ult",
  "name": "Doomshriek, Dawn's Chime",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Summon",
  "targeting_label": "Summon",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": "0",
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
    "spd",
    "res",
    "dmg",
    "action_advance",
    "summon"
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
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 18.75,
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
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "9fd88a7b7fbe469b8f781544344171c2ca11bace927adf3618c0fa1a3264544c",
  "icon_path": "icon/skill/1407_ultimate.png"
}
```

### Desolation Across Palms

```json
{
  "ability_id": "140704",
  "slot": "talent",
  "name": "Desolation Across Palms",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
  "energy_gain": "0",
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
    "dmg"
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
          "value": 11,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 12,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 13,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 14,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 16.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 17.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 18.75,
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
          "value": 21,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 22,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "6862d43b988483441a781e9b670fb4c67779df184de7935b675c7d80111550ef",
  "icon_path": "icon/skill/1407_talent.png"
}
```

### Wail, Death's Herald

```json
{
  "ability_id": "140707",
  "slot": "technique",
  "name": "Wail, Death's Herald",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "MazeAttack",
  "targeting_label": null,
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "max_hp",
    "action_advance",
    "summon"
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
  "description_sha256": "bee7aedb018f30dcbd4c4a9650f5f816547d567f8f964e0bf649a1d7bd9b9c4f",
  "icon_path": "icon/skill/1407_technique.png"
}
```

### Sanctuary of Mooncocoon

```json
{
  "ability_id": "140706",
  "slot": "supplementary",
  "name": "Sanctuary of Mooncocoon",
  "type_code": "Unique",
  "type_label": "Unique",
  "effect_code": "Unique",
  "targeting_label": "Unique",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "max_hp",
    "shield"
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
  "description_sha256": "3c702602da491b1c12925d036a449ca5f22867d63b19e78c49aeb05201039759",
  "icon_path": "icon/skill/1407_basic_atk.png"
}
```

### Claw Splits the Veil

```json
{
  "ability_id": "1407010",
  "slot": "supplementary",
  "name": "Claw Splits the Veil",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Quantum",
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
    "max_hp",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7748d8833e76c6063b9975d0ed8952ae5a76daa24d0fd272cccc005146c560a8",
  "icon_path": null
}
```

### Breath Scorches the Shadow

```json
{
  "ability_id": "1407011",
  "slot": "supplementary",
  "name": "Breath Scorches the Shadow",
  "type_code": "Normal",
  "type_label": "Memosprite Skill",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Quantum",
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
    },
    "p3": {
      "unit": "percent",
      "occurrences": 2
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
          "value": 12,
          "unit": "percent"
        },
        "p2": {
          "value": 14,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 14.4,
          "unit": "percent"
        },
        "p2": {
          "value": 16.8,
          "unit": "percent"
        },
        "p3": {
          "value": 20.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 16.8,
          "unit": "percent"
        },
        "p2": {
          "value": 19.6,
          "unit": "percent"
        },
        "p3": {
          "value": 23.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 19.2,
          "unit": "percent"
        },
        "p2": {
          "value": 22.4,
          "unit": "percent"
        },
        "p3": {
          "value": 27.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 21.6,
          "unit": "percent"
        },
        "p2": {
          "value": 25.2,
          "unit": "percent"
        },
        "p3": {
          "value": 30.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 28,
          "unit": "percent"
        },
        "p3": {
          "value": 34,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        },
        "p2": {
          "value": 30.8,
          "unit": "percent"
        },
        "p3": {
          "value": 37.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 28.8,
          "unit": "percent"
        },
        "p2": {
          "value": 33.6,
          "unit": "percent"
        },
        "p3": {
          "value": 40.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 31.2,
          "unit": "percent"
        },
        "p2": {
          "value": 36.4,
          "unit": "percent"
        },
        "p3": {
          "value": 44.2,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "24987faccd0c14883ab86c0476ec99d47946ddb8fa37f5aff7913c737df02251",
  "icon_path": null
}
```

### Mooncocoon Shrouds the Form

```json
{
  "ability_id": "1407012",
  "slot": "supplementary",
  "name": "Mooncocoon Shrouds the Form",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "max_hp",
    "dmg"
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
  "description_sha256": "ad8f84646411b7ae8555e778289a8df6ff8a2a72b239a82b6ef8ff035af081bc",
  "icon_path": null
}
```

### Roar Rumbles the Realm

```json
{
  "ability_id": "1407013",
  "slot": "supplementary",
  "name": "Roar Rumbles the Realm",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Quantum",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 7,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "dmg",
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
  "description_sha256": "779c6f93693acc1444f074fd315073f7908abdeafbbb7c14b924da6a0af937fc",
  "icon_path": null
}
```

### Wings Sweep the Ruins

```json
{
  "ability_id": "1407014",
  "slot": "supplementary",
  "name": "Wings Sweep the Ruins",
  "type_code": "Normal",
  "type_label": "Memosprite Talent",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Quantum",
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
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "max_hp",
    "dmg",
    "healing"
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
          "value": 3,
          "unit": "percent"
        },
        "p3": {
          "value": 400,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 3.6,
          "unit": "percent"
        },
        "p3": {
          "value": 480,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 4.2,
          "unit": "percent"
        },
        "p3": {
          "value": 560,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 32,
          "unit": "percent"
        },
        "p2": {
          "value": 4.8,
          "unit": "percent"
        },
        "p3": {
          "value": 640,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 5.4,
          "unit": "percent"
        },
        "p3": {
          "value": 720,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 40,
          "unit": "percent"
        },
        "p2": {
          "value": 6,
          "unit": "percent"
        },
        "p3": {
          "value": 800,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 44,
          "unit": "percent"
        },
        "p2": {
          "value": 6.6,
          "unit": "percent"
        },
        "p3": {
          "value": 880,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 48,
          "unit": "percent"
        },
        "p2": {
          "value": 7.2,
          "unit": "percent"
        },
        "p3": {
          "value": 960,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 52,
          "unit": "percent"
        },
        "p2": {
          "value": 7.8,
          "unit": "percent"
        },
        "p3": {
          "value": 1040,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "a97da99c1999c55caecd5d8990220ab12920ec5ee662d804693beb0fdbff032a",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Contained Dark Tide",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "100%",
      "12%"
    ],
    "description_sha256": "c649c17049ae2488e66fb3a6e79dd93d8999ed8692b3fe6e7d3b21d20ffa3d14"
  },
  {
    "requirement": "A4",
    "name": "Inverted Torch",
    "mechanic_tags": [
      "max_hp",
      "spd"
    ],
    "numeric_tokens": [
      "50%",
      "40%",
      "100%",
      "1"
    ],
    "description_sha256": "3c891dce3c8de24c82c3e27cac7594ccaec12f8bf83638ff73f25c9a8c3516bb"
  },
  {
    "requirement": "A6",
    "name": "Where The West Wind Dwells",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%",
      "6"
    ],
    "description_sha256": "e0ab7a1ff7d96c31567659d4f6b4e7cfcf4102f6d70808e541de7ef6c9504a20"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Snowbound Maiden, Memory to Tomb",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "80%",
      "50%",
      "120%",
      "140%"
    ],
    "description_sha256": "39eea7154c25b6228653c1db88eb2a167f5ec9752718c2fb3443119fe8369b04"
  },
  {
    "eidolon": 2,
    "name": "Crown on Wings of Bloom",
    "mechanic_tags": [
      "max_hp",
      "summon"
    ],
    "numeric_tokens": [
      "2",
      "2",
      "100%",
      "30%"
    ],
    "description_sha256": "06e043980de00d5519b4d41beb50b808c162ba9ddae54f99cdc06a9db76881fb"
  },
  {
    "eidolon": 3,
    "name": "Pious Pilgrim, Dance in Doom",
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
    "description_sha256": "805147110a228ec2ac9a8cb2bfb0cb8c25e99b883ea916d6e5aa771d131fec8f"
  },
  {
    "eidolon": 4,
    "name": "Rest in Songs of Gloom",
    "mechanic_tags": [
      "max_hp",
      "healing"
    ],
    "numeric_tokens": [
      "20%"
    ],
    "description_sha256": "9f1970ca7aca635d9a49b3e4af87daed806eda5264b05c3781aebfb88af397b6"
  },
  {
    "eidolon": 5,
    "name": "Pristine Pages, Prophecy as Plume",
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
    "description_sha256": "b191e38e96ecfa8c3660963bc890c9013a8576a14ab8c3536c1201a706095cf3"
  },
  {
    "eidolon": 6,
    "name": "Await for Years to Loom",
    "mechanic_tags": [
      "break_effect",
      "res_pen",
      "res",
      "dmg",
      "toughness",
      "weakness"
    ],
    "numeric_tokens": [
      "20%",
      "3"
    ],
    "description_sha256": "d2c8e6731d308ce6c3a9e88c3e0fd970050dd13de1bf86a2fcb9982208dffab4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
