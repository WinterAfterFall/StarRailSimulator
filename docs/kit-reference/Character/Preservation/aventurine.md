---
schema_version: "1.0.0"
unit_id: 50
name: "Aventurine"
slug: "aventurine"
rarity: 5
element: "Imaginary"
path: "Preservation"
role: "Shielder"
affiliation: "Interastral Peace Corporation"
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/aventurine"
source_record_updated_at: "February 12th, 2026"
dataset_snapshot: "2026-05-30"
---

# Aventurine

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Preservation/Aventurine.h` |
| ธาตุ | **Imaginary** |
| Path | **Preservation** |
| ระดับ | 5★ |
| Energy Ultimate | 110 |
| อ้างอิง | prydwen.gg (review/calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1203 · ATK 446 · DEF 654 · SPD 106

> Preservation tank/sub-DPS สาย DEF-scaling + shield + "Blind Bet" FUA

---

### Basic ATK — Straight Bet (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **100% ของ DEF** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Cornerstone Deluxe (Defense, Lv.10)
- มอบ **Fortified Wager** shield ให้เพื่อนทุกคน = **24% ของ DEF + 320** นาน 3 เทิร์น
- ได้ shield ซ้ำ → stack ได้ สูงสุด **200% ของ shield จาก Skill ปัจจุบัน**
- Energy +30

### Ultimate — Roulette Shark (โจมตีเดี่ยว, 110 energy, Lv.10)
- สุ่มได้ **Blind Bet 1–7 แต้ม**
- ติด **Unnerved** เป้าหมาย นาน 3 เทิร์น
- Imaginary DMG = **270% ของ DEF** ใส่เป้าหมาย
- เมื่อเพื่อนตีศัตรู Unnerved → CRIT DMG ที่ทำ **+15%**
- Energy +5 · Toughness 30

### Talent — Shot Loaded Right (Bounce, Lv.10)
- เพื่อน 1 ตัวที่มี Fortified Wager → Effect RES **+50%**; เมื่อเพื่อนคนนั้นถูกโจมตี → Aventurine ได้ Blind Bet **+1** (trigger อีกได้หลัง 2 เทิร์น)
- ขณะ Aventurine มี Fortified Wager → ต้าน CC
- Aventurine ถูกโจมตี → Blind Bet **+1**
- Blind Bet ครบ **7** → กิน 7, ยิง **7-hit follow-up** แต่ละ hit = **25% ของ DEF** Imaginary DMG ใส่ศัตรูสุ่ม
- Blind Bet cap **10**
- Energy +1 · Toughness 3

### Technique — The Red or the Black
- หลังใช้ Technique → ได้ 1 ใน: DEF +24% (chance) / +36% (high chance) / +60% (small chance)
- ใช้ซ้ำ → เก็บค่าสูงสุด
- เริ่มการต่อสู้ถัดไป → เพื่อนทุกคน DEF +ค่านั้น นาน 3 เทิร์น

---

### Major Traces
- **A2 — Leverage**: ทุก 100 DEF ที่เกิน **1600** → Aventurine CRIT Rate **+2%** สูงสุด **+48%**
- **A4 — Hot Hand**: ต้นการต่อสู้ → มอบ Fortified Wager ให้เพื่อนทุกคน = **100% ของ shield จาก Skill** นาน 3 เทิร์น
- **A6 — Bingo!**: หลังเพื่อนที่มี Fortified Wager ยิง follow-up → Aventurine Blind Bet **+1** (สูงสุด 3 ครั้ง, reset ต้นเทิร์นของ Aventurine). หลัง Aventurine ยิง Talent FUA → มอบ Fortified Wager ให้เพื่อนทุกคน = **7.2% ของ DEF + 96** + ให้เพื่อนที่ shield น้อยสุดอีก 1 อัน (7.2% DEF + 96) นาน 3 เทิร์น

### Minor Traces (รวมทั้งหมด)
DEF +35% · Imaginary DMG +14.4% · Effect RES +10%

### Eidolons
- **E1**: เพื่อนที่มี Fortified Wager → CRIT DMG **+20%**. หลังใช้ Ult → มอบ Fortified Wager ให้เพื่อนทุกคน = **100% ของ shield จาก Skill** นาน 3 เทิร์น
- **E2**: ใช้ Basic ATK → ลด All-Type RES เป้าหมาย **12%** นาน 3 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: เมื่อ trigger Talent FUA → Aventurine DEF **+40%** นาน 2 เทิร์น + Hits Per Action ของ Talent FUA **+3** (รวม 10)
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: ต่อเพื่อนที่มี Shield → Aventurine +DMG **+50%** สูงสุด **+150%**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ DEF** (BA 100%, Ult 270%, Talent FUA 25%/hit)
- **Fortified Wager shield**: 24% DEF + 320 (Skill), stack cap 200% Skill; A4/E1 = 100% Skill ให้ฟรี; A6 = 7.2% DEF + 96
- **Blind Bet** (0–10): Ult (1–7 สุ่ม), ถูกโจมตี (+1), เพื่อน shield ถูกตี (+1), A6 (+1×3); ครบ 7 → 7-hit FUA (E4 10-hit)
- **A2**: CRIT Rate จาก DEF เกิน 1600 (cap 48%)
- **Unnerved (Ult)**: เพื่อนตี → CRIT DMG +15%
- **E6**: DMG amp จากจำนวนเพื่อนที่มี shield (cap 150%)
- โค้ด: `Aventurine.h` — ตรวจ shield model + `Start_game_List` (A4)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/aventurine — kit tab (review/calc patch 4.0, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 50,
  "name": "Aventurine",
  "slug": "aventurine",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Preservation",
  "default_role": "Shielder",
  "affiliation": "Interastral Peace Corporation",
  "release_date": "April 17th, 2024",
  "is_released": true,
  "ultimate_energy_cost": "110",
  "base_stats": {
    "hp_base": 163.68,
    "def_base": 89.1,
    "atk_base": 60.72,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "DEF",
      "value": 35
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
    "en": "Camden Sutkowski",
    "kr": "박준원 (Park Jun-won)",
    "jpn": "河西健吾 (Kawanishi Kengo)",
    "cn": "杨超然 (Yang Chaoran)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/aventurine",
  "source_record_updated_at": "February 12th, 2026"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `130401` | Straight Bet | Basic ATK | Single Target |
| `skill` | `130402` | Cornerstone Deluxe | Skill | Defense |
| `ult` | `130403` | Roulette Shark | Ultimate | Single Target |
| `talent` | `130404` | Shot Loaded Right | Talent | Bounce |
| `technique` | `130407` | The Red or the Black | Technique | Defense |

## Ability records

### Straight Bet

```json
{
  "ability_id": "130401",
  "slot": "basic",
  "name": "Straight Bet",
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
    "def",
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
  "description_sha256": "6f5a05665ec6cdb50dda9094361aee632b1e8b41be58ad7cd991021c45df5c8c",
  "icon_path": "icon/skill/1304_basic_atk.png"
}
```

### Cornerstone Deluxe

```json
{
  "ability_id": "130402",
  "slot": "skill",
  "name": "Cornerstone Deluxe",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Defence",
  "targeting_label": "Defense",
  "element": "Imaginary",
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
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "def",
    "dmg",
    "shield"
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
          "value": 80,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 128,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
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
          "value": 164,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 200,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 224,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 248,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 266,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 284,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 302,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 320,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 338,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
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
          "value": 356,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 26.4,
          "unit": "percent"
        },
        "p2": {
          "value": 374,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 27.2,
          "unit": "percent"
        },
        "p2": {
          "value": 392,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 410,
          "unit": "scalar"
        },
        "p3": {
          "value": 3,
          "unit": "scalar"
        },
        "p4": {
          "value": 200,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "08c9c24fe2042605d182ad5f79b8dd7eb2c5e29d892e68597eba3406fd607952",
  "icon_path": "icon/skill/1304_skill.png"
}
```

### Roulette Shark

```json
{
  "ability_id": "130403",
  "slot": "ult",
  "name": "Roulette Shark",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "110",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
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
    "def",
    "crit_dmg",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 162,
          "unit": "percent"
        },
        "p3": {
          "value": 9,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 172.8,
          "unit": "percent"
        },
        "p3": {
          "value": 9.6,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 183.6,
          "unit": "percent"
        },
        "p3": {
          "value": 10.2,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 194.4,
          "unit": "percent"
        },
        "p3": {
          "value": 10.8,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 205.2,
          "unit": "percent"
        },
        "p3": {
          "value": 11.4,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 216,
          "unit": "percent"
        },
        "p3": {
          "value": 12,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 229.5,
          "unit": "percent"
        },
        "p3": {
          "value": 12.75,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 243,
          "unit": "percent"
        },
        "p3": {
          "value": 13.5,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 256.5,
          "unit": "percent"
        },
        "p3": {
          "value": 14.25,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 270,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 280.8,
          "unit": "percent"
        },
        "p3": {
          "value": 15.6,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 291.6,
          "unit": "percent"
        },
        "p3": {
          "value": 16.2,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 302.4,
          "unit": "percent"
        },
        "p3": {
          "value": 16.8,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 313.2,
          "unit": "percent"
        },
        "p3": {
          "value": 17.4,
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
          "value": 7,
          "unit": "scalar"
        },
        "p2": {
          "value": 324,
          "unit": "percent"
        },
        "p3": {
          "value": 18,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "487050e1290c169a2a0ecad7c4657835183dfc8247685d55d2059722125e8566",
  "icon_path": "icon/skill/1304_ultimate.png"
}
```

### Shot Loaded Right

```json
{
  "ability_id": "130404",
  "slot": "talent",
  "name": "Shot Loaded Right",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Bounce",
  "targeting_label": "Bounce",
  "element": "Imaginary",
  "energy_gain": "1",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "10",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "scalar",
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
    "def",
    "effect_res",
    "res",
    "dmg",
    "follow_up",
    "debuff",
    "buff"
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
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 12.5,
          "unit": "percent"
        },
        "p4": {
          "value": 25,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 13.75,
          "unit": "percent"
        },
        "p4": {
          "value": 27.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 16.25,
          "unit": "percent"
        },
        "p4": {
          "value": 32.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 17.5,
          "unit": "percent"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 18.75,
          "unit": "percent"
        },
        "p4": {
          "value": 37.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 20.31,
          "unit": "percent"
        },
        "p4": {
          "value": 40.62,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 21.88,
          "unit": "percent"
        },
        "p4": {
          "value": 43.75,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 23.44,
          "unit": "percent"
        },
        "p4": {
          "value": 46.88,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 25,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 26.25,
          "unit": "percent"
        },
        "p4": {
          "value": 52.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 27.5,
          "unit": "percent"
        },
        "p4": {
          "value": 55,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 28.75,
          "unit": "percent"
        },
        "p4": {
          "value": 57.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 60,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 1,
          "unit": "scalar"
        },
        "p2": {
          "value": 7,
          "unit": "scalar"
        },
        "p3": {
          "value": 31.25,
          "unit": "percent"
        },
        "p4": {
          "value": 62.5,
          "unit": "percent"
        },
        "p5": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "55cd3343dc285cea3541096664f45e1fea32ffa073e662b3462c76554fce2883",
  "icon_path": "icon/skill/1304_talent.png"
}
```

### The Red or the Black

```json
{
  "ability_id": "130407",
  "slot": "technique",
  "name": "The Red or the Black",
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
      "unit": "percent",
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
    "def",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 24,
          "unit": "percent"
        },
        "p2": {
          "value": 36,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        },
        "p4": {
          "value": 3,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "45a460b8be614529c54a8df5d28046dfe4caca1c3f9c7c4a215fb415ce0fd92f",
  "icon_path": "icon/skill/1304_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Leverage",
    "mechanic_tags": [
      "def",
      "crit_rate"
    ],
    "numeric_tokens": [
      "100",
      "1600",
      "2%",
      "48%"
    ],
    "description_sha256": "5fd9a5ab118caffc01e44b87528f5684220d0b318235952b4c22e788ed3a4123"
  },
  {
    "requirement": "A4",
    "name": "Hot Hand",
    "mechanic_tags": [
      "shield"
    ],
    "numeric_tokens": [
      "100%",
      "3"
    ],
    "description_sha256": "fc08f5d515c88fae753182f6a574ec41c9c205488b193ed3c7b2b934f7264ff4"
  },
  {
    "requirement": "A6",
    "name": "Bingo!",
    "mechanic_tags": [
      "def",
      "dmg",
      "shield",
      "follow_up"
    ],
    "numeric_tokens": [
      "1",
      "3",
      "7.2%",
      "96",
      "7.2%",
      "96",
      "3"
    ],
    "description_sha256": "7fc6dd06f3a416f13a28698075e18704d6df8b036783285996810818a3d06d13"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Prisoner's Dilemma",
    "mechanic_tags": [
      "crit_dmg",
      "dmg",
      "shield"
    ],
    "numeric_tokens": [
      "20%",
      "100%",
      "3"
    ],
    "description_sha256": "7aab496f47c023a074846f7fd4bc60bec52a40fd66f175ed8523be326e02eb55"
  },
  {
    "eidolon": 2,
    "name": "Bounded Rationality",
    "mechanic_tags": [
      "atk",
      "res"
    ],
    "numeric_tokens": [
      "12%",
      "3"
    ],
    "description_sha256": "898988bb808d14a57b9a0ef460d9b985268bf7990314c9fbb8287d82022aa32b"
  },
  {
    "eidolon": 3,
    "name": "Droprate Maxing",
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
    "name": "Unexpected Hanging Paradox",
    "mechanic_tags": [
      "def",
      "follow_up"
    ],
    "numeric_tokens": [
      "40%",
      "2",
      "3"
    ],
    "description_sha256": "233911dacfb96333a7f306e7605a76e8e2e6db66a20755acca130b9fcdc4a06d"
  },
  {
    "eidolon": 5,
    "name": "Ambiguity Aversion",
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
    "name": "Stag Hunt Game",
    "mechanic_tags": [
      "dmg",
      "shield"
    ],
    "numeric_tokens": [
      "50%",
      "150%"
    ],
    "description_sha256": "f48e5f3c7e844855e9424f73a6532365f4d804aaeb322bcf76595d62e74caff4"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
