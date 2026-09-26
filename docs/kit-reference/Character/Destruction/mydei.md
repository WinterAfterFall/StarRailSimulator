---
schema_version: "1.0.0"
unit_id: 71
name: "Mydei"
slug: "mydei"
rarity: 5
element: "Imaginary"
path: "Destruction"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/mydei"
source_record_updated_at: "March 26th, 2025"
dataset_snapshot: "2026-05-30"
---

# Mydei

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Mydei.h` |
| ธาตุ | **Imaginary** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review/calc patch 3.1) |

### Base Stats (Lv.80, ascended)
HP 1552 · ATK 426 · DEF 194 · SPD 95

---

### Basic ATK — Vow of Voyage (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Deaths are Legion, Regrets are None (Blast, Lv.10)
- กิน HP = **50% ของ HP ปัจจุบัน** (ไม่พอ → HP = 1)
- Imaginary DMG เป้าหมายหลัก = **90% Max HP**, ข้างเคียง = **50% Max HP**
- Energy +30 · Toughness 20 (+10 ข้างเคียง)

### Skill (Enhanced) — Kingslayer Be King (Blast, Lv.10) — ใช้อัตโนมัติ
- กิน HP = **35% ของ HP ปัจจุบัน** (ไม่พอ → HP = 1)
- Imaginary DMG หลัก = **110% Max HP**, ข้างเคียง = **66% Max HP**
- Energy +30 · Toughness 20 (+10)

### Skill (Enhanced) — Godslayer Be God (Blast, Lv.10) — ใช้อัตโนมัติ
- กิน **Charge 150 แต้ม**
- Imaginary DMG หลัก = **280% Max HP**, ข้างเคียง = **168% Max HP**
- ขณะใช้ท่านี้ Charge สะสมไม่ได้
- Energy +10 · Toughness 30 (+20)

### Ultimate — Throne of Bones (Blast, 160 energy, Lv.10)
- ฮีลตัวเอง **20% Max HP** + สะสม Charge **20 แต้ม**
- Imaginary DMG หลัก = **160% Max HP**, ข้างเคียง = **100% Max HP**
- Taunt เป้าหมาย + ข้างเคียง นาน 2 เทิร์น
- "Godslayer Be God" ครั้งถัดไปพุ่งใส่เป้าหมายที่กำหนดก่อน (มีผลกับ target ล่าสุดเท่านั้น)
- Energy +5 · Toughness 20 (+20)

### Talent — Blood for Blood (Lv.10)
- ทุก 1% HP ที่เสียไป → Charge **+1** (สูงสุด 200)
- Charge ถึง **100** → กิน 100, เข้าสถานะ **"Vendetta"**, ฮีล **25% Max HP**, advance action **100%**
- ขณะ Vendetta: **Max HP +50% ของ Max HP ปัจจุบัน**, DEF = 0; เริ่มเทิร์น → ใช้ "Kingslayer Be King" อัตโนมัติ
- ขณะ Vendetta Charge ถึง **150** → ได้เทิร์นพิเศษทันที + ใช้ "Godslayer Be God" อัตโนมัติ
- โดน killing blow ขณะ Vendetta → ไม่ล้ม แต่ล้าง Charge, ออกจาก Vendetta, ฮีล 50% Max HP

### Technique — Cage of Broken Lance
- ดึงศัตรู + Daze 10 วิ
- โจมตีศัตรู Dazed → เข้าฉาก: Imaginary DMG = **80% Max HP** AoE + Taunt 1 เทิร์น + สะสม Charge **50 แต้ม**

---

### Major Traces
- **A2 — Earth and Water**: ขณะ Vendetta โดน killing blow → ไม่ออกจาก Vendetta (trigger 3 ครั้ง/การต่อสู้)
- **A4 — Thirty Tyrants**: ขณะ Vendetta → ภูมิคุ้มกัน Crowd Control
- **A6 — Bloodied Chiton**: ต้นการต่อสู้ ถ้า Max HP > 4000 → ทุก 100 HP ส่วนเกิน: CRIT Rate **+1.2%**, อัตรา Charge จากดาเมจที่รับ **+2.5%**, Incoming Healing **+0.75%** (นับส่วนเกินสูงสุด 4000)

### Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · SPD +5 · HP +18%

### Eidolons
- **E1**: "Godslayer Be God" multiplier เป้าหมายหลัก **+30%** และเปลี่ยนเป็นตีศัตรูทุกตัวด้วย multiplier เท่าเป้าหมายหลัก
- **E2**: ขณะ Vendetta ดาเมจเพิกเฉย DEF **15%**. หลังรับการฮีล → แปลง **40% ของ heal** เป็น Charge (cap 40, รีเซ็ตหลังหน่วยใด action)
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ขณะ Vendetta → CRIT DMG **+30%** + ฮีล **10% Max HP** หลังถูกศัตรูโจมตี
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: เข้าฉาก → เข้า Vendetta ทันที + ลด Charge ที่ต้องใช้ของ "Godslayer Be God" เหลือ **100**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ Max HP** (BA 50%, Skill 90/50, Vendetta-Skill 110/66, Godslayer 280/168, Ult 160/100)
- **Charge** สองแหล่ง: HP loss (1:1% cap 200) + A6 ratio จากดาเมจที่รับ + E2 จาก heal
- **Vendetta enter (Charge 100)**: ฮีล 25%, advance 100%, Max HP ×1.5, DEF→0, auto Kingslayer ทุกเทิร์น
- **Vendetta Charge 150** → extra turn + auto Godslayer (E6 ลด threshold เป็น 100)
- **โค้ด `Start_game_List`**: คำนวณ A6 (`buffNote["Mydei_A6"]`), ปรับ CR/Healing; E6 → set `buffCheck["Mydei_Vendetta"]`, `Action_forward 100`, ฮีล, `FLAT_DEF -= 10000`
- Godslayer ใช้อัตโนมัติเมื่อเงื่อนไข Charge — sim ต้อง handle auto-action ใน turn loop
- Ult redirect "Godslayer" ใส่ target ล่าสุด

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/mydei — kit tab (review/calc patch 3.1, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 71,
  "name": "Mydei",
  "slug": "mydei",
  "rarity": "5",
  "element": "Imaginary",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "March 19th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "160",
  "base_stats": {
    "hp_base": 211.2,
    "def_base": 26.4,
    "atk_base": 58.08,
    "speed_base": 95
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT DMG",
      "value": 37.3
    },
    "traceStat2": {
      "stat": "speed",
      "value": 5
    },
    "traceStat3": {
      "stat": "hp",
      "value": 18
    }
  },
  "voice_actors": {
    "en": "-",
    "kr": "Ahn Hyo-min (안효민)",
    "jpn": "Yōhei Azakami (阿座上洋平)",
    "cn": "Zhao Chengchen (赵成晨)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/mydei",
  "source_record_updated_at": "March 26th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140401` | Vow of Voyage | Basic ATK | Single Target |
| `skill` | `140402` | Deaths are Legion, Regrets are None | Skill | Blast |
| `skill_enh` | `140409` | Kingslayer Be King | Skill | Blast |
| `ult` | `140403` | Throne of Bones | Ultimate | Blast |
| `talent` | `140404` | Blood for Blood | Talent | Enhance |
| `technique` | `140407` | Cage of Broken Lance | Technique | Impair |
| `supplementary` | `140411` | Godslayer Be God | Skill | Blast |

## Ability records

### Vow of Voyage

```json
{
  "ability_id": "140401",
  "slot": "basic",
  "name": "Vow of Voyage",
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
  "description_sha256": "f33c34ed09049f338c10242e32abf10eb4446e01326cb7a111fceb3fb643f6e9",
  "icon_path": "icon/skill/1404_basic_atk.png"
}
```

### Deaths are Legion, Regrets are None

```json
{
  "ability_id": "140402",
  "slot": "skill",
  "name": "Deaths are Legion, Regrets are None",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
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
          "value": 45,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 49.5,
          "unit": "percent"
        },
        "p2": {
          "value": 27.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 30,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        },
        "p2": {
          "value": 32.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        },
        "p2": {
          "value": 35,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 73.12,
          "unit": "percent"
        },
        "p2": {
          "value": 40.62,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 78.75,
          "unit": "percent"
        },
        "p2": {
          "value": 43.75,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 84.38,
          "unit": "percent"
        },
        "p2": {
          "value": 46.88,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 94.5,
          "unit": "percent"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 99,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 103.5,
          "unit": "percent"
        },
        "p2": {
          "value": 57.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 108,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 62.5,
          "unit": "percent"
        },
        "p3": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5db60559a2f961476604dcf864f95198e6f638e64c330c0595b03164f9579a7a",
  "icon_path": "icon/skill/1404_skill.png"
}
```

### Kingslayer Be King

```json
{
  "ability_id": "140409",
  "slot": "skill_enh",
  "name": "Kingslayer Be King",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
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
          "value": 55,
          "unit": "percent"
        },
        "p2": {
          "value": 33,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 60.5,
          "unit": "percent"
        },
        "p2": {
          "value": 36.3,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 39.6,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 71.5,
          "unit": "percent"
        },
        "p2": {
          "value": 42.9,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 77,
          "unit": "percent"
        },
        "p2": {
          "value": 46.2,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        },
        "p2": {
          "value": 49.5,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 89.38,
          "unit": "percent"
        },
        "p2": {
          "value": 53.63,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 96.25,
          "unit": "percent"
        },
        "p2": {
          "value": 57.75,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 103.12,
          "unit": "percent"
        },
        "p2": {
          "value": 61.88,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 115.5,
          "unit": "percent"
        },
        "p2": {
          "value": 69.3,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 121,
          "unit": "percent"
        },
        "p2": {
          "value": 72.6,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 126.5,
          "unit": "percent"
        },
        "p2": {
          "value": 75.9,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        },
        "p2": {
          "value": 79.2,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 137.5,
          "unit": "percent"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        },
        "p3": {
          "value": 35,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "7e45d2071a23dcc39d513cc55a9a63e1028a6b018efcccc2589da54f08772238",
  "icon_path": "icon/skill/1404_skill.png"
}
```

### Throne of Bones

```json
{
  "ability_id": "140403",
  "slot": "ult",
  "name": "Throne of Bones",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": "5",
  "ultimate_energy_cost": "160",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "60",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p2": {
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
    "dmg",
    "healing"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 96,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 15,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 102.4,
          "unit": "percent"
        },
        "p2": {
          "value": 64,
          "unit": "percent"
        },
        "p3": {
          "value": 15.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 108.8,
          "unit": "percent"
        },
        "p2": {
          "value": 68,
          "unit": "percent"
        },
        "p3": {
          "value": 16,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 115.2,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        },
        "p3": {
          "value": 16.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 121.6,
          "unit": "percent"
        },
        "p2": {
          "value": 76,
          "unit": "percent"
        },
        "p3": {
          "value": 17,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 128,
          "unit": "percent"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 17.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 136,
          "unit": "percent"
        },
        "p2": {
          "value": 85,
          "unit": "percent"
        },
        "p3": {
          "value": 18.12,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        },
        "p3": {
          "value": 18.75,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 152,
          "unit": "percent"
        },
        "p2": {
          "value": 95,
          "unit": "percent"
        },
        "p3": {
          "value": 19.38,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 160,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 20,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 166.4,
          "unit": "percent"
        },
        "p2": {
          "value": 104,
          "unit": "percent"
        },
        "p3": {
          "value": 20.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        },
        "p2": {
          "value": 108,
          "unit": "percent"
        },
        "p3": {
          "value": 21,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 179.2,
          "unit": "percent"
        },
        "p2": {
          "value": 112,
          "unit": "percent"
        },
        "p3": {
          "value": 21.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 185.6,
          "unit": "percent"
        },
        "p2": {
          "value": 116,
          "unit": "percent"
        },
        "p3": {
          "value": 22,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 22.5,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "86dacca85394cd8cc47cd21c50dfb8e65b2ba2ffa09d2c7985c6012846aace03",
  "icon_path": "icon/skill/1404_ultimate.png"
}
```

### Blood for Blood

```json
{
  "ability_id": "140404",
  "slot": "talent",
  "name": "Blood for Blood",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Imaginary",
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
    "p5": {
      "unit": "percent",
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
    "max_hp",
    "def",
    "action_advance",
    "healing"
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
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
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
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
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
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 18,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 19,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
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
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 21.25,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 22.5,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 23.75,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
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
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 26,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 27,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 28,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 29,
          "unit": "percent"
        },
        "p2": {
          "value": 0,
          "unit": "scalar"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
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
          "value": 150,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        },
        "p5": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "29d6aa8f84a4e8670b02ea7e8193d8408f4b901913cd348018059839653b3d8b",
  "icon_path": "icon/skill/1404_talent.png"
}
```

### Cage of Broken Lance

```json
{
  "ability_id": "140407",
  "slot": "technique",
  "name": "Cage of Broken Lance",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Impair",
  "targeting_label": "Impair",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {
    "p1": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p5": {
      "unit": "scalar",
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
          "unit": "scalar"
        },
        "p2": {
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 1,
          "unit": "scalar"
        },
        "p5": {
          "value": 50,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "b60910f035f4a80fd34b3b91e964c207c2b40b111d8bd245357a8a497c3e74b5",
  "icon_path": "icon/skill/1404_technique.png"
}
```

### Godslayer Be God

```json
{
  "ability_id": "140411",
  "slot": "supplementary",
  "name": "Godslayer Be God",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Imaginary",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
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
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 154,
          "unit": "percent"
        },
        "p2": {
          "value": 92.4,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 168,
          "unit": "percent"
        },
        "p2": {
          "value": 100.8,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 182,
          "unit": "percent"
        },
        "p2": {
          "value": 109.2,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 196,
          "unit": "percent"
        },
        "p2": {
          "value": 117.6,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 227.5,
          "unit": "percent"
        },
        "p2": {
          "value": 136.5,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 245,
          "unit": "percent"
        },
        "p2": {
          "value": 147,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 262.5,
          "unit": "percent"
        },
        "p2": {
          "value": 157.5,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 280,
          "unit": "percent"
        },
        "p2": {
          "value": 168,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 294,
          "unit": "percent"
        },
        "p2": {
          "value": 176.4,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 308,
          "unit": "percent"
        },
        "p2": {
          "value": 184.8,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 322,
          "unit": "percent"
        },
        "p2": {
          "value": 193.2,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 336,
          "unit": "percent"
        },
        "p2": {
          "value": 201.6,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 350,
          "unit": "percent"
        },
        "p2": {
          "value": 210,
          "unit": "percent"
        },
        "p3": {
          "value": 150,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9f0c97015d57787a7baddbaaff765319ae4328182bf39efec4589af5927169fa",
  "icon_path": "icon/skill/1404_skill.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Earth and Water",
    "mechanic_tags": [],
    "numeric_tokens": [
      "3"
    ],
    "description_sha256": "7bbf9a3a8d3c1f6f9d25faaca5b5def49b6fdde46ff6c0a0d8dbed27f2674f34"
  },
  {
    "requirement": "A4",
    "name": "Thirty Tyrants",
    "mechanic_tags": [
      "debuff",
      "buff"
    ],
    "numeric_tokens": [],
    "description_sha256": "a42eb3a367a70f8a6bbd0ff9bd2e88d8c7b0a970b67c5b9cb7b947d0ab88c463"
  },
  {
    "requirement": "A6",
    "name": "Bloodied Chiton",
    "mechanic_tags": [
      "max_hp",
      "crit_rate",
      "dmg",
      "healing"
    ],
    "numeric_tokens": [
      "4000",
      "100",
      "1.2%",
      "2.5%",
      "0.75%",
      "4000"
    ],
    "description_sha256": "c7046a41865d5667370dcef499eacebcad06d68f240ab140dcfe0580f87fe83c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Frost Hones Spine of Steel",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "30%"
    ],
    "description_sha256": "cfe3ea897e0764a225edbc8109d622c67fb8c32977c6d9ce433a75e7bbbbb7fb"
  },
  {
    "eidolon": 2,
    "name": "Strife Beholds Cry of Dead",
    "mechanic_tags": [
      "def",
      "dmg",
      "healing"
    ],
    "numeric_tokens": [
      "15%",
      "40%",
      "40"
    ],
    "description_sha256": "584cf1f0747e94e74863b6c563ddbfe619adac05318d9e015b8bd719db0981d4"
  },
  {
    "eidolon": 3,
    "name": "Honor Exalts Feast of Faith",
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
    "name": "Siren Jolts the Laconic Lion",
    "mechanic_tags": [
      "max_hp",
      "crit_dmg",
      "dmg",
      "healing"
    ],
    "numeric_tokens": [
      "30%",
      "10%"
    ],
    "description_sha256": "f9c1b9e30c7918bcdf8a5d7cd4742e3d27f1fa92999748f21c82af518aecbf6e"
  },
  {
    "eidolon": 5,
    "name": "War Chisels Flesh of Flame",
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
    "name": "Legacy Scales Mound of Blood",
    "mechanic_tags": [],
    "numeric_tokens": [
      "100"
    ],
    "description_sha256": "2b344906e1bc5d263e8a5909836495e36d4b0efc102d3a188c75319a5d994b2e"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
