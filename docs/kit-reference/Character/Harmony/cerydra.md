---
schema_version: "1.0.0"
unit_id: 79
name: "Cerydra"
slug: "cerydra"
rarity: 5
element: "Wind"
path: "Harmony"
role: "Support"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/cerydra"
source_record_updated_at: "September 22nd, 2025"
dataset_snapshot: "2026-05-30"
---

# Cerydra

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Harmony/Cerydra.h` |
| ธาตุ | **Wind** |
| Path | **Harmony** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review patch 3.5 / calc patch 4.0) |

### Base Stats (Lv.80, ascended)
HP 1358 · ATK 620 · DEF 485 · SPD 99

---

### Basic ATK — King's Castling (โจมตีเดี่ยว, Lv.6)
- สร้าง Wind DMG = **100% ATK** ให้ศัตรูเป้าหมาย 1 ตัว
- Energy +20 · Toughness 10

### Skill — Pawn's Promotion (Support, Lv.10)
- มอบ **"Military Merit"** ให้ตัวละครฝ่ายเดียวกัน 1 ตัว และ Cerydra ได้ **Charge +1** (cap 8)
- เมื่อ Charge ถึง **6** → อัปเกรด "Military Merit" ของตัวนั้นเป็น **"Peerage"** อัตโนมัติ + ล้าง debuff Crowd Control ของตัวนั้น
  - ตัวที่มี "Peerage" ถือว่ามี "Military Merit" ไปพร้อมกัน
- ตัวที่มี **"Peerage"**:
  - +72% CRIT DMG เฉพาะดาเมจ Skill ของตัวเอง
  - +10% All-Type RES PEN
  - trigger **Coup de Main** เมื่อใช้ Skill ใส่ศัตรู หลัง Coup de Main จบ → กิน Charge 6 แต้ม, คืน "Peerage" กลับเป็น "Military Merit"
- Energy +30 · ไม่มี Toughness

### Ultimate — Scholar's Mate (AoE, 130 energy, Lv.10)
- ได้ **Charge +2**
- สร้าง Wind DMG = **240% ATK** ให้ศัตรูทุกตัว
- ถ้าในสนามไม่มีใครมี "Military Merit" → มอบให้ตัวละครลำดับแรกของทีมปัจจุบัน
- Energy +5 · Toughness 20

### Talent — Ave Imperator (Support, Lv.10)
- ตัวที่มี "Military Merit": **+ATK เท่ากับ 24% ของ ATK ของ Cerydra**
- เมื่อตัวนั้นใช้ Basic ATK หรือ Skill → Cerydra ได้ **Charge +1** (ยกเว้นช่วง Coup de Main จะไม่ได้ Charge)
- หลังตัวที่มี "Military Merit" โจมตี → Cerydra สร้าง Wind **Additional DMG = 60% ATK** เพิ่ม 1 instance
  - trigger ได้สูงสุด **20 ครั้ง** ตัวนับรีเซ็ตทุกครั้งที่ Cerydra ใช้ Ultimate
- "Military Merit" มีผลกับ **เป้าหมายล่าสุดตัวเดียว** เมื่อเปลี่ยนตัวที่ถือ → **Charge ของ Cerydra รีเซ็ตเป็น 0**

### Technique — First-Move Advantage
- หลังใช้ Technique → ได้ "Military Merit"
- เมื่อสลับตัวละคร active → "Military Merit" ย้ายตามตัว active ปัจจุบัน
- เริ่มการต่อสู้ถัดไป → ใช้ Skill อัตโนมัติ 1 ครั้งใส่ตัวที่ถือ "Military Merit" โดย**ไม่กิน Skill Point**

---

### Major Traces
- **A2 — Veni**: ทุก ๆ 100 ATK ของ Cerydra ที่เกิน 2000 → +18% CRIT DMG สูงสุด **+360%**
- **A4 — Vidi**: +100% CRIT Rate ให้ Cerydra. ขณะ Charge ยังไม่เต็ม ถ้าตัวที่มี "Military Merit" ใช้ Ultimate → Cerydra ได้ Charge +1 (ครั้งเดียว/การต่อสู้)
- **A6 — Vici**: เมื่อใช้ Skill → +20 SPD ให้ Cerydra และเพื่อนที่มี "Military Merit" นาน 3 เทิร์น. เมื่อตัวที่มี "Military Merit" ใช้ Basic ATK/Skill → คืน Energy 5 ให้ Cerydra

### Minor Traces (รวมทั้งหมด)
ATK +18% · Wind DMG +22.4% · HP +10%

### Eidolons
- **E1 — Seize the Crowns of All**: ตัวที่มี "Military Merit" **เพิกเฉย DEF 16%**. ถ้าอัปเป็น "Peerage" → เพิกเฉย DEF เพิ่มอีก **20%** เฉพาะดาเมจ Skill. เมื่อ Cerydra ใช้ Skill → คืน Energy 2 ให้ตัวเป้าหมาย
- **E2 — Forge the Dreams of Many**: ตัวที่มี "Military Merit" **+40% DMG**. ขณะมีเพื่อนถือ "Military Merit" ในสนาม → Cerydra **+160% DMG**
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4 — Remake the Realms of Men**: Ultimate multiplier **+240%**
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6 — A Journey Set Starward**: ตัวที่มี "Military Merit" **+20% All-Type RES PEN** และ multiplier ของ Additional DMG จาก Talent **+300%**. ขณะมีเพื่อนถือ "Military Merit" → Cerydra **+20% All-Type RES PEN**

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Charge**: cap 8, ได้จาก Skill(+1) / Ult(+2) / Talent เมื่อ target ทำ BA·Skill(+1) / A4(+1) เงื่อนไข. Coup de Main ระงับการได้ Charge จาก Talent
- **Threshold 6** = อัป Peerage อัตโนมัติ; Coup de Main จบ = กิน 6 Charge คืนเป็น Military Merit
- **เปลี่ยนตัวถือ Military Merit ⇒ Charge = 0** (สำคัญมากสำหรับ single-target buff logic)
- Talent ATK buff เป็น % ของ ATK **ของ Cerydra** (snapshot ต้องอัปเดตเมื่อ ATK Cerydra เปลี่ยน — โค้ดใช้ `calculateAtkForBuff` + `buffNote`)
- Additional DMG counter รีเซ็ตที่ Ultimate ไม่ใช่ต่อเทิร์น
- A2 CRIT DMG scaling ผูกกับ ATK จริง → ต้อง re-evaluate ผ่าน `Stats_Adjust_List`

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/cerydra — kit tab (review patch 3.5, calc patch 4.0, profile 04/Jun/2026)

## Character record

```json
{
  "unit_id": 79,
  "name": "Cerydra",
  "slug": "cerydra",
  "rarity": "5",
  "element": "Wind",
  "path": "Harmony",
  "default_role": "Support",
  "affiliation": null,
  "release_date": "September 2nd, 2025",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 184.8,
    "def_base": 66,
    "atk_base": 84.48,
    "speed_base": 99
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "atk",
      "value": 18
    },
    "traceStat2": {
      "stat": "Wind DMG",
      "value": 22.4
    },
    "traceStat3": {
      "stat": "hp",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "",
    "kr": "김윤채 (Kim Yun-chae)",
    "jpn": "高尾 奏音 (Takao Kanon)",
    "cn": "时欣蕾 (Shi Xinlei)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/cerydra",
  "source_record_updated_at": "September 22nd, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `141201` | King's Castling | Basic ATK | Single Target |
| `skill` | `141202` | Pawn's Promotion | Skill | Support |
| `ult` | `141203` | Scholar's Mate | Ultimate | AoE |
| `talent` | `141204` | Ave Imperator | Talent | Support |
| `technique` | `141207` | First-Move Advantage | Technique | Support |

## Ability records

### King's Castling

```json
{
  "ability_id": "141201",
  "slot": "basic",
  "name": "King's Castling",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Wind",
  "energy_gain": "20",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": null,
  "source_max_level": 10,
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
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ed62b71d1c0c3f8d27fc6b7eb434a97f123319b133b7535ef3eee856d2091c3c",
  "icon_path": "icon/skill/1412_basic_atk.png"
}
```

### Pawn's Promotion

```json
{
  "ability_id": "141202",
  "slot": "skill",
  "name": "Pawn's Promotion",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p4": {
      "unit": "scalar",
      "occurrences": 2
    },
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    }
  },
  "mechanic_tags": [
    "crit_dmg",
    "res_pen",
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
          "value": 36,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 39.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 8.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 43.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 8.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 46.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 8.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 50.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 8.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 54,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 9,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 58.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 9.25,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 63,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 9.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 67.5,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 9.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 10,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 75.6,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.2,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 79.2,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.4,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 82.8,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.6,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 86.4,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 10.8,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 1,
          "unit": "scalar"
        },
        "p3": {
          "value": 8,
          "unit": "scalar"
        },
        "p4": {
          "value": 6,
          "unit": "scalar"
        },
        "p5": {
          "value": 11,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "79d214b4c755a35cd5487078c34c5a549b8c0dc43f781ef0633c28d482634724",
  "icon_path": "icon/skill/1412_skill.png"
}
```

### Scholar's Mate

```json
{
  "ability_id": "141203",
  "slot": "ult",
  "name": "Scholar's Mate",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoEAttack",
  "targeting_label": "AoE",
  "element": "Wind",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
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
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 153.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 163.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 172.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 182.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 192,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 204,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 216,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 228,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 249.6,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 259.2,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 268.8,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 278.4,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 288,
          "unit": "percent"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "1e54f9214e1ba657fab7fe5bb89833a25410c7bb4c616bf9df16bccfcfd55028",
  "icon_path": "icon/skill/1412_ultimate.png"
}
```

### Ave Imperator

```json
{
  "ability_id": "141204",
  "slot": "talent",
  "name": "Ave Imperator",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Support",
  "targeting_label": "Support",
  "element": "Wind",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p2": {
      "unit": "percent",
      "occurrences": 1
    },
    "p1": {
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
    "atk",
    "dmg"
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
          "value": 18,
          "unit": "percent"
        },
        "p3": {
          "value": 30,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 18.6,
          "unit": "percent"
        },
        "p3": {
          "value": 33,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 19.2,
          "unit": "percent"
        },
        "p3": {
          "value": 36,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 19.8,
          "unit": "percent"
        },
        "p3": {
          "value": 39,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 20.4,
          "unit": "percent"
        },
        "p3": {
          "value": 42,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 21,
          "unit": "percent"
        },
        "p3": {
          "value": 45,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 21.75,
          "unit": "percent"
        },
        "p3": {
          "value": 48.75,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 52.5,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 23.25,
          "unit": "percent"
        },
        "p3": {
          "value": 56.25,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 24,
          "unit": "percent"
        },
        "p3": {
          "value": 60,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 24.6,
          "unit": "percent"
        },
        "p3": {
          "value": 63,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 25.2,
          "unit": "percent"
        },
        "p3": {
          "value": 66,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 25.8,
          "unit": "percent"
        },
        "p3": {
          "value": 69,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 26.4,
          "unit": "percent"
        },
        "p3": {
          "value": 72,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
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
          "value": 27,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "f7c999135d00ef7ce609c3c5d375ffa1dc747cf655cc896c994a8d945dcba747",
  "icon_path": "icon/skill/1412_talent.png"
}
```

### First-Move Advantage

```json
{
  "ability_id": "141207",
  "slot": "technique",
  "name": "First-Move Advantage",
  "type_code": "Maze",
  "type_label": "Technique",
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
    "skill_points"
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
  "description_sha256": "6977e43038565b98dfd0d2e30abb7b06bec9ea4451477544eee9bcf8ca89674e",
  "icon_path": "icon/skill/1412_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Veni",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "100",
      "2000",
      "18%",
      "360%"
    ],
    "description_sha256": "c8e5ae140fdd451f5a228af89941035b393b95b5aa2e1484931babab56119ddd"
  },
  {
    "requirement": "A4",
    "name": "Vidi",
    "mechanic_tags": [
      "crit_rate"
    ],
    "numeric_tokens": [
      "100%",
      "1"
    ],
    "description_sha256": "55bb635eaf8cadd3143f285f0fba6c08968946c6bd32ecd0ae511078cf829d04"
  },
  {
    "requirement": "A6",
    "name": "Vici",
    "mechanic_tags": [
      "atk",
      "spd",
      "energy"
    ],
    "numeric_tokens": [
      "20",
      "3",
      "5"
    ],
    "description_sha256": "4270b8f1306650e3dd09da946a324060011ebc6a0ce7ec47be07a004a206676c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Seize the Crowns of Al",
    "mechanic_tags": [
      "def",
      "energy",
      "dmg"
    ],
    "numeric_tokens": [
      "16%",
      "20%",
      "2"
    ],
    "description_sha256": "ed0ec6c2da5d7f49171409a21963a36c86f901a17f13c6673661c1fee25645b6"
  },
  {
    "eidolon": 2,
    "name": "Forge the Dreams of Many",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "40%",
      "160%"
    ],
    "description_sha256": "aeee9a42e2018de9a699ea28949a0d09e9b73b8ae3fcbeadbd4847faeb8be252"
  },
  {
    "eidolon": 3,
    "name": "Torch the Laws of Old",
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
    "name": "Remake the Realms of Men",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "240%"
    ],
    "description_sha256": "636424fa1b84c613cb655999f58bec9756035b6758be079d5ab07defd09ede47"
  },
  {
    "eidolon": 5,
    "name": "Help and Hurt Repaid in Full",
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
    "name": "A Journey Set Starward",
    "mechanic_tags": [
      "res_pen",
      "res",
      "dmg"
    ],
    "numeric_tokens": [
      "20%",
      "300%",
      "20%"
    ],
    "description_sha256": "aa42686e865390edb5385e27bd1d567154627cf6d0109dbf55c985ca232627fe"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
