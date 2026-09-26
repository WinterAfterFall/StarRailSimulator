---
schema_version: "1.0.0"
unit_id: 78
name: "Phainon"
slug: "phainon"
rarity: 5
element: "Physical"
path: "Destruction"
role: "Main DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/phainon"
source_record_updated_at: "July 10th, 2025"
dataset_snapshot: "2026-05-30"
---

# Phainon

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Phainon.h` |
| ธาตุ | **Physical** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 12 (ใช้ Coreflame เป็นทรัพยากรหลัก) |
| อ้างอิง | prydwen.gg (review/calc patch 3.4) |

### Base Stats (Lv.80, ascended)
HP 1433 · ATK 582 · DEF 703 · SPD 94

> **หมายเหตุ:** kit ซับซ้อนมาก ข้อความบน prydwen มีสลับชื่อ state ("Soulscorch" / "Soulrending Blaze" / "Scourge") — ตรวจกับ fandom เพิ่มก่อน implement

---

### โหมด Phainon (ปกติ)

#### Basic ATK — Stride to Deliverance (โจมตีเดี่ยว, Lv.6)
- Physical DMG = **100% ATK** · Energy +0 · Toughness 10

#### Skill — Let There Be Light (Blast, Lv.10)
- ได้ **Coreflame +2**
- Physical DMG หลัก = **300% ATK**, ข้างเคียง = **120% ATK**
- Energy +0 · Toughness 20 (+10)

#### Talent (Phainon) — Pyric Corpus
- **Coreflame** ครบ **12** → ใช้ Ultimate ได้ เก็บ overflow ได้อีก 3 แต้ม (คืนหลังจบร่าง)
- เมื่อ Phainon เป็นเป้าของ ability ใด ๆ → Coreflame **+1**; ถ้าผู้ใช้เป็นเพื่อน → Phainon CRIT DMG **+30%** นาน 3 เทิร์น

#### Technique — Beginning of the End
- อยู่ในทีม → Max Technique Points **+3**
- ใช้ Technique: กิน 2 TP, โจมตี AoE; เข้าฉาก → คืน Energy **25** ให้ทีม + ได้ Scourge **2** + Skill Point **1**
- ต้นแต่ละ wave: Physical DMG = **200% ATK** AoE

---

### โหมด Khaslana (หลังแปลงร่าง / Ultimate)

#### Ultimate — He Who Bears the World Must Burn (AoE, 12 energy, Lv.10)
- แปลงเป็น **Khaslana**, กาง Territory: เพื่อนคนอื่นกลายเป็น **Departed** (ทำอะไรไม่ได้), ศัตรูทุกตัวติด Physical Weakness
- Khaslana ไม่มีเทิร์นของตัวเอง แต่มี **Khaslana's extra turn 8 ครั้ง** SPD คงที่ = **60% ของ base SPD** ของ Khaslana
- ต้นของ extra turn สุดท้าย → **Final Hit**: Physical Ultimate DMG = **960% ATK** กระจายเท่า ๆ กันทุกศัตรู
- Energy +0 · Toughness 20

#### Talent (Khaslana) — Fate: Divine Vessel
- ตอนแปลงร่าง: ได้ Scourge **4**; ถ้าเป็นเทิร์นเพื่อน → ยืด buff เพื่อนคนนั้น 1 เทิร์น + จบเทิร์นปัจจุบัน
- Khaslana ภูมิคุ้มกัน CC, มี Enhanced BA 1 + Enhanced Skill 2, ใช้ Ult ไม่ได้
- ขณะแปลงร่าง: **ATK +80%, Max HP +270%**; หลังโจมตี → ฮีล **20% Max HP**
- โดน killing blow → ไม่ล้ม, ฮีล **25% Max HP**, ยิง Final Hit ทันที
- ทุก extra turn ที่เหลือ → Final Hit multiplier ลด **12.5%** ของ multiplier เดิม
- จบการแปลงร่าง → เพื่อนทุกคน SPD **+15%** นาน 1 เทิร์น

#### Enhanced Basic ATK — Creation: Bloodthorn Ferry (Blast, Lv.6)
- ได้ **Scourge +2**
- Physical DMG หลัก = **250% ATK**, ข้างเคียง = **75% ATK**
- Toughness 30 (+20)

#### Enhanced Skill 1 — Calamity: Soulscorch Edict (Enhance, Lv.10)
- ได้ Scourge = จำนวนศัตรู + **Soulscorch 1 stack**, บังคับศัตรูทุกตัว action ทันที
- ขณะ Soulscorch: Khaslana รับดาเมจ **-75%**; หลังศัตรู attack/action → Soulscorch +1 stack
- หลังศัตรู action → ยิง Counter: Physical DMG = **40% ATK** AoE + เพิ่ม **4 instance × 30% ATK**
- แต่ละ stack เพิ่ม multiplier ของ Counter **+20%** ของ multiplier เดิม
- ดาเมจนับเป็น Skill DMG; ถ้า state ยัง active ตอนต้น extra turn → ยิง Counter ทันที
- Toughness 10 (+5)

#### Enhanced Skill 2 — Foundation: Stardeath Verdict (Enhance, Lv.10)
- ล้าง debuff ตัวเอง
- Physical DMG สูงสุด = **1170% ATK**
- ต่อ Scourge ที่กิน: 4 instance × **45% ATK** ใส่ศัตรูสุ่ม
- กิน Scourge ครบ 4 → เพิ่ม Physical DMG **450% ATK** กระจายเท่ากันทุกศัตรู
- Toughness 3 (+20)

---

### Major Traces
- **A2 — March to Oblivion**: ต้นการต่อสู้ → Coreflame +1; จบการแปลงร่าง → Coreflame +3
- **A4 — Bide in Flames**: รับ heal/Shield จากเพื่อน → +DMG dealt **45%** นาน 4 เทิร์น (ไม่ซ้ำในเทิร์นเดียว). รับ Energy regen จากเพื่อน → Coreflame +1
- **A6 — Shine with Valor**: เข้าฉาก หรือจบการแปลงร่าง → ATK **+50%** stack ได้ 2 ครั้ง

### Minor Traces (รวมทั้งหมด)
CRIT Rate +12% · CRIT DMG +37.3% · SPD +5

### Eidolons
- **E1**: SPD inheritance ratio ของ extra turn เพิ่มเป็น **66%** +1.5% ต่อศัตรูที่ฆ่า สูงสุด 84%. ใช้ Ult → CRIT DMG **+50%** นาน 3 เทิร์น
- **E2**: Physical RES PEN **+20%**. กิน Scourge 4 ใช้ "Foundation" → ได้เทิร์นพิเศษ
- **E3**: Ultimate Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ใช้ "Calamity: Soulscorch Edict" → ได้ Soulscorch เพิ่ม **4 stacks**
- **E5**: Skill Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: Coreflame overflow ไม่มี cap. ต้นการต่อสู้ → Coreflame +6. หลัง "Foundation" attack → True DMG = **36% ของดาเมจรวมในการโจมตีนั้น** ใส่ศัตรู HP สูงสุด

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **2 โหมด**: Phainon (Coreflame gen) → transform → Khaslana (8 extra turns, ไม่มีเทิร์นปกติ, teammates Departed)
- **Coreflame** เกน: Skill +2, ถูก target โดย ability +1, A2 (+1 start, +3 end), A4 (energy regen +1), E6 (+6 start). ครบ 12 → Ult
- **Khaslana extra turn** SPD = 60% base (E1 เป็น 66%→84%)
- **Final Hit** multiplier 960% base, ลด 12.5% ต่อ extra turn ที่เหลือ (ยิงเร็ว = แรงกว่า)
- **Scourge** (0–4): ใช้กับ "Foundation" — 4 instance × 45% ต่อ stack + bonus 450% ถ้าครบ 4
- **Khaslana transform buff**: ATK +80%, Max HP +270%, heal 20% หลัง attack
- โค้ด: `Start_game_List` (E→genSkillPoint, Scourge(2), energy 25 ทีม, CoreFlame(3), E6 CoreFlame(6)) + `Start_wave_List` (Technique 200% AoE, self-flush)
- `CoreFlame`, `Scourge` เป็น callback ที่รับ int — sim ต้อง track resource เอง

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/phainon — kit tab (review/calc patch 3.4, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 78,
  "name": "Phainon",
  "slug": "phainon",
  "rarity": "5",
  "element": "Physical",
  "path": "Destruction",
  "default_role": "Main DPS",
  "affiliation": null,
  "release_date": "July 2nd, 2025",
  "is_released": true,
  "ultimate_energy_cost": "12",
  "base_stats": {
    "hp_base": 195,
    "def_base": 95.7,
    "atk_base": 79.2,
    "speed_base": 94
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "CRIT Rate",
      "value": 12
    },
    "traceStat2": {
      "stat": "CRIT DMG",
      "value": 37.3
    },
    "traceStat3": {
      "stat": "Speed",
      "value": 5
    }
  },
  "voice_actors": {
    "en": "Joshua Waters",
    "kr": "윤용식 (Yoon Yong-sik)",
    "jpn": "日野 聡 (Hino Satoshi)",
    "cn": "秦且歌 (Qin Qiege)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/phainon",
  "source_record_updated_at": "July 10th, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140801` | Stride to Deliverance | Basic ATK | Single Target |
| `basic_enh` | `140808` | Creation: Bloodthorn Ferry | Basic ATK | Blast |
| `skill` | `140802` | Let There Be Light | Skill | Blast |
| `skill_enh` | `140809` | Calamity: Soulscorch Edict | Enhanced Skill | Enhance |
| `ult` | `140803` | He Who Bears the World Must Burn | Ultimate | AoE |
| `talent` | `140804` | Pyric Corpus | Talent | Enhance |
| `technique` | `140807` | Beginning of the End | Technique | Enhance |
| `supplementary` | `140810` | Foundation: Stardeath Verdict | Enhanced Skill | Enhance |

## Ability records

### Stride to Deliverance

```json
{
  "ability_id": "140801",
  "slot": "basic",
  "name": "Stride to Deliverance",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Physical",
  "energy_gain": null,
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
  "description_sha256": "b96854af601c05b73de2a29e2189df910ba3cff5c5ebf9069e68931c20774a6c",
  "icon_path": null
}
```

### Creation: Bloodthorn Ferry

```json
{
  "ability_id": "140808",
  "slot": "basic_enh",
  "name": "Creation: Bloodthorn Ferry",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": "60",
  "source_max_level": 10,
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
          "value": 125,
          "unit": "percent"
        },
        "p2": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 52.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
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
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        },
        "p2": {
          "value": 67.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 250,
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
          "value": 275,
          "unit": "percent"
        },
        "p2": {
          "value": 82.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 90,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 325,
          "unit": "percent"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 350,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "1c1853031c376a7b3fdc3ad15a867890986b58a6cd2217950e9738a7673f1c5e",
  "icon_path": null
}
```

### Let There Be Light

```json
{
  "ability_id": "140802",
  "slot": "skill",
  "name": "Let There Be Light",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Physical",
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        },
        "p2": {
          "value": 66,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 72,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 195,
          "unit": "percent"
        },
        "p2": {
          "value": 78,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 84,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 225,
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
          "value": 243.75,
          "unit": "percent"
        },
        "p2": {
          "value": 97.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 262.5,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 281.25,
          "unit": "percent"
        },
        "p2": {
          "value": 112.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 300,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        },
        "p2": {
          "value": 126,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 330,
          "unit": "percent"
        },
        "p2": {
          "value": 132,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "2491fe55a1c6606a1a154d3c71624cc4f0dd29bc6236c8e4012557af2c1bc3f2",
  "icon_path": null
}
```

### Calamity: Soulscorch Edict

```json
{
  "ability_id": "140809",
  "slot": "skill_enh",
  "name": "Calamity: Soulscorch Edict",
  "type_code": "Normal",
  "type_label": "Enhanced Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "30",
  "toughness_break_secondary_source": "15",
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
    "dmg",
    "follow_up"
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
          "value": 15,
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
          "value": 16.5,
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
          "value": 18,
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
          "value": 19.5,
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
          "value": 21,
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
          "value": 22.5,
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
          "value": 24.375,
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
          "value": 26.25,
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
          "value": 28.125,
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
          "value": 31.5,
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
          "value": 33,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "5022af9ff58b5f3b0edffe0a04ea830786fd7d6e0225f9237b46f0c8f8450017",
  "icon_path": null
}
```

### He Who Bears the World Must Burn

```json
{
  "ability_id": "140803",
  "slot": "ult",
  "name": "He Who Bears the World Must Burn",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "AoE",
  "targeting_label": "AoE",
  "element": "Physical",
  "energy_gain": "0",
  "ultimate_energy_cost": "12",
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
    "spd",
    "dmg",
    "weakness"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 480,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 528,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 576,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 624,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 672,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 720,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 780,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 840,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 900,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 960,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 1008,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 1056,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "489666967f1ce02cfbdfeee6c6aac49888a70545bf3089004d71b1c718379d8e",
  "icon_path": null
}
```

### Pyric Corpus

```json
{
  "ability_id": "140804",
  "slot": "talent",
  "name": "Pyric Corpus",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
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
    "max_hp",
    "atk",
    "spd",
    "crit_dmg",
    "dmg",
    "healing",
    "debuff",
    "buff"
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
          "value": 40,
          "unit": "percent"
        },
        "p3": {
          "value": 135,
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
          "value": 44,
          "unit": "percent"
        },
        "p3": {
          "value": 148.5,
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
          "value": 48,
          "unit": "percent"
        },
        "p3": {
          "value": 162,
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
          "value": 52,
          "unit": "percent"
        },
        "p3": {
          "value": 175.5,
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
          "value": 56,
          "unit": "percent"
        },
        "p3": {
          "value": 189,
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
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 202.5,
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
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 219.375,
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
          "value": 70,
          "unit": "percent"
        },
        "p3": {
          "value": 236.25,
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
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 253.125,
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
          "value": 80,
          "unit": "percent"
        },
        "p3": {
          "value": 270,
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
          "value": 84,
          "unit": "percent"
        },
        "p3": {
          "value": 283.5,
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
          "value": 88,
          "unit": "percent"
        },
        "p3": {
          "value": 297,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "72b8ccf6b48735b37b243d72f4434b93ef25c0f58f19c729887e66144d5f8772",
  "icon_path": null
}
```

### Beginning of the End

```json
{
  "ability_id": "140807",
  "slot": "technique",
  "name": "Beginning of the End",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 1,
  "parameter_placeholders": {},
  "mechanic_tags": [
    "atk",
    "energy",
    "dmg",
    "skill_points"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 15,
          "unit": "scalar"
        },
        "p2": {
          "value": 2,
          "unit": "scalar"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 50,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "9a8780a467a933f56bd5a0c99fdae465bf196cccb0f0787e57245685fb9cd0f9",
  "icon_path": "icon/skill/1408_technique.png"
}
```

### Foundation: Stardeath Verdict

```json
{
  "ability_id": "140810",
  "slot": "supplementary",
  "name": "Foundation: Stardeath Verdict",
  "type_code": "Normal",
  "type_label": "Enhanced Skill",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Physical",
  "energy_gain": null,
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": null,
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
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
    "atk",
    "dmg",
    "debuff",
    "buff"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 225,
          "unit": "percent"
        },
        "p2": {
          "value": 22.5,
          "unit": "percent"
        },
        "p3": {
          "value": 585,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 247.5,
          "unit": "percent"
        },
        "p2": {
          "value": 24.75,
          "unit": "percent"
        },
        "p3": {
          "value": 643.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 270,
          "unit": "percent"
        },
        "p2": {
          "value": 27,
          "unit": "percent"
        },
        "p3": {
          "value": 702,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 292.5,
          "unit": "percent"
        },
        "p2": {
          "value": 29.25,
          "unit": "percent"
        },
        "p3": {
          "value": 760.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 315,
          "unit": "percent"
        },
        "p2": {
          "value": 31.5,
          "unit": "percent"
        },
        "p3": {
          "value": 819,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 337.5,
          "unit": "percent"
        },
        "p2": {
          "value": 33.75,
          "unit": "percent"
        },
        "p3": {
          "value": 877.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 365.625,
          "unit": "percent"
        },
        "p2": {
          "value": 36.56,
          "unit": "percent"
        },
        "p3": {
          "value": 950.62,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 393.75,
          "unit": "percent"
        },
        "p2": {
          "value": 39.37,
          "unit": "percent"
        },
        "p3": {
          "value": 1023.75,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 421.875,
          "unit": "percent"
        },
        "p2": {
          "value": 42.18,
          "unit": "percent"
        },
        "p3": {
          "value": 1096.87,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 450,
          "unit": "percent"
        },
        "p2": {
          "value": 45,
          "unit": "percent"
        },
        "p3": {
          "value": 1170,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 472.5,
          "unit": "percent"
        },
        "p2": {
          "value": 47.25,
          "unit": "percent"
        },
        "p3": {
          "value": 1228.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 495,
          "unit": "percent"
        },
        "p2": {
          "value": 49.5,
          "unit": "percent"
        },
        "p3": {
          "value": 1287,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "ce84383d19211959a832d5f7d1bd6cb98048be2e44225864091927a8ba1c50f6",
  "icon_path": null
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "March to Oblivion",
    "mechanic_tags": [],
    "numeric_tokens": [
      "1",
      "3"
    ],
    "description_sha256": "f2336296512061ae9d80fa67b611c1bea90ae9d9f37eb728530360ec01aa0112"
  },
  {
    "requirement": "A4",
    "name": "Bide in Flames",
    "mechanic_tags": [
      "energy",
      "energy_regen_rate",
      "dmg",
      "healing",
      "shield"
    ],
    "numeric_tokens": [
      "45%",
      "4",
      "1"
    ],
    "description_sha256": "04746cf45dc4d19338a8331e7e1b25a3580ba17fa468aafc81f163429d2cefa0"
  },
  {
    "requirement": "A6",
    "name": "Shine with Valor",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "50%",
      "2"
    ],
    "description_sha256": "e9b82a614f6dca7d9e8f8fe1befaad83b3783f1819467d88852fd887ce17133c"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Flame and Light Bind Virtue and Vice",
    "mechanic_tags": [
      "spd",
      "crit_dmg",
      "dmg"
    ],
    "numeric_tokens": [
      "66%",
      "1.5%",
      "84%",
      "50%",
      "3"
    ],
    "description_sha256": "55a5464edd3fa6dad24139b74530ab0c64dbe20274bc47b4d9231356105602a4"
  },
  {
    "eidolon": 2,
    "name": "Eidolon 2",
    "mechanic_tags": [
      "res_pen",
      "res"
    ],
    "numeric_tokens": [
      "20%",
      "4",
      "1"
    ],
    "description_sha256": "9ecf8b58dba46ea9941302d21b844c38172028c5d89ff4c4ce2b1a6260aae0ac"
  },
  {
    "eidolon": 3,
    "name": "Eidolon 3",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "77fd630f7f186cf220b64378e5f59e3870c6dbc1845af8b52c4cc734a64e864a"
  },
  {
    "eidolon": 4,
    "name": "Eidolon 4",
    "mechanic_tags": [],
    "numeric_tokens": [
      "4"
    ],
    "description_sha256": "7e274952c77ca601333d72d15458ad8add2f3bada27f0e434a6138874f602dd4"
  },
  {
    "eidolon": 5,
    "name": "Eidolon 5",
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
    "name": "Eidolon 6",
    "mechanic_tags": [
      "max_hp",
      "dmg"
    ],
    "numeric_tokens": [
      "6",
      "36%"
    ],
    "description_sha256": "881e5850a50ab0e69730b73266303cb4ffb985166f7fbbd25265e957dd542db7"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
