---
schema_version: "1.0.0"
unit_id: 74
name: "Cipher"
slug: "cipher"
rarity: 5
element: "Quantum"
path: "Nihility"
role: "Sub DPS"
affiliation: null
released: true
source_url: "https://www.prydwen.gg/star-rail/characters/cipher"
source_record_updated_at: "July 1st, 2025"
dataset_snapshot: "2026-05-30"
---

# Cipher

## สรุป kit ภาษาไทย + จุดเทียบโค้ด (รวมจากไฟล์ kit-reference เดิม)


| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Cipher.h` |
| ธาตุ | **Quantum** |
| Path | **Nihility** |
| ระดับ | 5★ |
| Energy Ultimate | 130 |
| อ้างอิง | prydwen.gg (review/calc patch 3.3) |

### Base Stats (Lv.80, ascended)
HP 931 · ATK 640 · DEF 509 · SPD 106

> Nihility sub-DPS/amplifier สาย "Patron" + DMG tally → True DMG burst

---

### Basic ATK — Oops, a Missed Catch (โจมตีเดี่ยว, Lv.6)
- Quantum DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

### Skill — Hey, Jackpot for the Taking (Blast, Lv.10)
- 120% base chance ติด Weaken เป้าหมาย + ข้างเคียง (−10% DMG dealt) + Cipher ATK **+30%** นาน 2 เทิร์น
- Quantum DMG หลัก = **200% ATK**, ข้างเคียง = **100% ATK**
- Energy +30 · Toughness 20 (+10)

### Ultimate — Yours Truly, Kitty Phantom Thief! (Blast, 130 energy, Lv.10)
- Quantum DMG = **120% ATK** ใส่เป้าหมายหลัก
- True DMG = **25% ของ tally ปัจจุบันจาก Talent** ใส่เป้าหมายหลัก
- Quantum DMG = **40% ATK** + True DMG = **75% ของ tally** ใส่เป้าหมายหลัก + ข้างเคียง (True DMG นี้กระจายเท่ากันทุกเป้าของท่านี้)
- หลังใช้ → ล้าง tally
- Energy +5 · Toughness 30 (+20)

### Talent — The Hospitable Dolosian (Lv.10)
- ถ้าไม่มีศัตรูสถานะ "Patron" → Cipher ทำให้ศัตรู Max HP สูงสุดเป็น "Patron" ทันที
- ใช้ Skill/Ult → เป้าหมายหลักเป็น "Patron" (มีผลกับ target ล่าสุด)
- หลัง "Patron" ถูกเพื่อนคนอื่นโจมตี → Cipher ยิง Follow-up ATK ใส่ "Patron": Quantum DMG = **150% ATK** (1 ครั้ง/เทิร์น, reset ต้นเทิร์นของ Cipher)
- Cipher **tally 12% ของ non-True DMG** ที่เพื่อนทำกับ "Patron" (overflow ไม่นับ); ล้าง tally หลังใช้ Ult
- Energy +5 · Toughness 20

### Technique — Puss in Boots
- ได้ "Zagreus's Blessing" 15 วิ
- เข้าฉากพร้อม Blessing → Quantum DMG = **100% ATK** AoE + เพิ่ม recorded DMG จาก instance นี้ **+200%**

---

### Major Traces
- **A2 — Empyrean Strides**: SPD ≥ 140/170 → CRIT Rate **+25%/+50%** + tally ที่ได้ **+50%/+100%**
- **A4 — 300 Rogues**: Cipher tally **8% ของ non-True DMG** ที่เพื่อนทำกับศัตรูตัวอื่นที่ไม่ใช่ "Patron"
- **A6 — Sleight of Sky**: Talent Follow-up ATK CRIT DMG **+100%**. ขณะ Cipher อยู่ในสนาม → ศัตรูทุกตัวรับดาเมจเพิ่ม **+40%**

### Minor Traces (รวมทั้งหมด)
Quantum DMG +14.4% · SPD +14 · Effect HIT Rate +10%

### Eidolons
- **E1**: recorded DMG = **150%** ของเดิม. ใช้ Talent Follow-up ATK → Cipher ATK **+80%** นาน 2 เทิร์น
- **E2**: Cipher ตีโดนศัตรู → 120% base chance ศัตรูรับดาเมจเพิ่ม **+30%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1
- **E4**: หลัง "Patron" ถูกเพื่อนโจมตี → Cipher สร้าง Quantum Additional DMG = **50% ATK**
- **E5**: Skill Lv. +2 · Talent Lv. +2
- **E6**: Talent Follow-up ATK DMG **+350%**. record เพิ่มอีก **16%** ของ non-overflow DMG ของ FUA. หลังล้าง record ตอน Ult → คืน **20%** ของ record ที่ล้าง

---

### กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **DMG tally**: 12% ของ non-True DMG ที่เพื่อนทำกับ Patron (+A4 8% non-Patron, A2 ×1.5/×2, E6 +16% FUA) — overflow (kill) ไม่นับ
- **Ult burst**: True DMG 25% (single) + 75% (blast, กระจาย) ของ tally → ล้าง tally (E6 คืน 20%)
- **Patron**: auto-assign HP สูงสุด, หรือ Skill/Ult target; FUA 150% ATK เมื่อเพื่อนตี Patron (1/เทิร์น)
- **A6**: enemy DMG-taken +40% ทีม (huge global amp)
- โค้ด: `Start_game_List` priority `PRIORITY_Last` (`Cipher.h:132`, `cph`) มี addToActionBar + `Deal_damage()` (technique attack self-flush) — **หมายเหตุ**: ตัวนี้เป็น `PRIORITY_Last` จงใจให้รันหลัง technique อื่น
- `BeforeAttackAction_List` มี "Cipher Fua" trigger (E2 vuln, Patron debuff)

### แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/cipher — kit tab (review/calc patch 3.3, profile 01/Jun/2026)

## Character record

```json
{
  "unit_id": 74,
  "name": "Cipher",
  "slug": "cipher",
  "rarity": "5",
  "element": "Quantum",
  "path": "Nihility",
  "default_role": "Sub DPS",
  "affiliation": null,
  "release_date": "June 11th, 2025",
  "is_released": true,
  "ultimate_energy_cost": "130",
  "base_stats": {
    "hp_base": 126.72,
    "def_base": 69.3,
    "atk_base": 87.12,
    "speed_base": 106
  },
  "minor_trace_totals": {
    "traceStat1": {
      "stat": "Quantum DMG",
      "value": 14.4
    },
    "traceStat2": {
      "stat": "speed",
      "value": 14
    },
    "traceStat3": {
      "stat": "Effect Hit Rate",
      "value": 10
    }
  },
  "voice_actors": {
    "en": "Shea Fairaday",
    "kr": "Mi So (미소)",
    "jpn": "Ito Ayasa (伊藤 彩沙)",
    "cn": "Wang Yaxin (王雅欣)"
  },
  "source_url": "https://www.prydwen.gg/star-rail/characters/cipher",
  "source_record_updated_at": "July 1st, 2025"
}
```

## Ability index

| Slot | ID | Name | Type | Target/effect |
|---|---:|---|---|---|
| `basic` | `140601` | Oops, a Missed Catch | Basic ATK | Single Target |
| `skill` | `140602` | Hey, Jackpot for the Taking | Skill | Blast |
| `ult` | `140603` | Yours Truly, Kitty Phantom Thief! | Ultimate | Blast |
| `talent` | `140604` | The Hospitable Dolosian | Talent | Single Target |
| `technique` | `140607` | Puss in Boots | Technique | Enhance |

## Ability records

### Oops, a Missed Catch

```json
{
  "ability_id": "140601",
  "slot": "basic",
  "name": "Oops, a Missed Catch",
  "type_code": "Normal",
  "type_label": "Basic ATK",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
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
  "description_sha256": "831c39e5ad9c1b2da5e0ea47b9be81abf859b034b8c556e9490a22b5215983b1",
  "icon_path": "icon/skill/1406_basic_atk.png"
}
```

### Hey, Jackpot for the Taking

```json
{
  "ability_id": "140602",
  "slot": "skill",
  "name": "Hey, Jackpot for the Taking",
  "type_code": "BPSkill",
  "type_label": "Skill",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
  "energy_gain": "30",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": "30",
  "source_max_level": 15,
  "parameter_placeholders": {
    "p6": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "percent",
      "occurrences": 1
    },
    "p5": {
      "unit": "percent",
      "occurrences": 1
    },
    "p4": {
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
    "atk",
    "dmg"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 100,
          "unit": "percent"
        },
        "p2": {
          "value": 50,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 110,
          "unit": "percent"
        },
        "p2": {
          "value": 55,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 60,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 130,
          "unit": "percent"
        },
        "p2": {
          "value": 65,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 140,
          "unit": "percent"
        },
        "p2": {
          "value": 70,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 75,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 162.5,
          "unit": "percent"
        },
        "p2": {
          "value": 81.25,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 175,
          "unit": "percent"
        },
        "p2": {
          "value": 87.5,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 93.75,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 200,
          "unit": "percent"
        },
        "p2": {
          "value": 100,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 210,
          "unit": "percent"
        },
        "p2": {
          "value": 105,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 220,
          "unit": "percent"
        },
        "p2": {
          "value": 110,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 230,
          "unit": "percent"
        },
        "p2": {
          "value": 115,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 240,
          "unit": "percent"
        },
        "p2": {
          "value": 120,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 250,
          "unit": "percent"
        },
        "p2": {
          "value": 125,
          "unit": "percent"
        },
        "p3": {
          "value": 10,
          "unit": "percent"
        },
        "p4": {
          "value": 2,
          "unit": "scalar"
        },
        "p5": {
          "value": 30,
          "unit": "percent"
        },
        "p6": {
          "value": 120,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "809665974c4a6b591e0c365e0b10be85cf0843843a513f2fa6e149da37ea1b51",
  "icon_path": "icon/skill/1406_skill.png"
}
```

### Yours Truly, Kitty Phantom Thief!

```json
{
  "ability_id": "140603",
  "slot": "ult",
  "name": "Yours Truly, Kitty Phantom Thief!",
  "type_code": "Ultra",
  "type_label": "Ultimate",
  "effect_code": "Blast",
  "targeting_label": "Blast",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": "130",
  "toughness_break_primary_source": "90",
  "toughness_break_secondary_source": "60",
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
    "p4": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
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
          "value": 60,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 20,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 66,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 22,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 72,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 24,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 78,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 26,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 84,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 28,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 30,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 32.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 35,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 37.5,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 120,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 40,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 126,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 42,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 132,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 44,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 138,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 46,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 144,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 48,
          "unit": "percent"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 25,
          "unit": "percent"
        },
        "p3": {
          "value": 75,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "percent"
        }
      }
    }
  ],
  "description_sha256": "e21b7c598ad0b685a7d435fd2ffcd9a2db9f05ac42c64e9ef21e017c137cd529",
  "icon_path": "icon/skill/1406_ultimate.png"
}
```

### The Hospitable Dolosian

```json
{
  "ability_id": "140604",
  "slot": "talent",
  "name": "The Hospitable Dolosian",
  "type_code": "Talent",
  "type_label": "Talent",
  "effect_code": "SingleAttack",
  "targeting_label": "Single Target",
  "element": "Quantum",
  "energy_gain": "5",
  "ultimate_energy_cost": null,
  "toughness_break_primary_source": "60",
  "toughness_break_secondary_source": null,
  "source_max_level": 15,
  "parameter_placeholders": {
    "p1": {
      "unit": "percent",
      "occurrences": 1
    },
    "p3": {
      "unit": "scalar",
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
    "dmg",
    "follow_up"
  ],
  "level_scaling": [
    {
      "source_row": 1,
      "parameters": {
        "p1": {
          "value": 75,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 2,
      "parameters": {
        "p1": {
          "value": 82.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 3,
      "parameters": {
        "p1": {
          "value": 90,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 4,
      "parameters": {
        "p1": {
          "value": 97.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 5,
      "parameters": {
        "p1": {
          "value": 105,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 6,
      "parameters": {
        "p1": {
          "value": 112.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 7,
      "parameters": {
        "p1": {
          "value": 121.88,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 8,
      "parameters": {
        "p1": {
          "value": 131.25,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 9,
      "parameters": {
        "p1": {
          "value": 140.62,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 10,
      "parameters": {
        "p1": {
          "value": 150,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 11,
      "parameters": {
        "p1": {
          "value": 157.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 12,
      "parameters": {
        "p1": {
          "value": 165,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 13,
      "parameters": {
        "p1": {
          "value": 172.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 14,
      "parameters": {
        "p1": {
          "value": 180,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    },
    {
      "source_row": 15,
      "parameters": {
        "p1": {
          "value": 187.5,
          "unit": "percent"
        },
        "p2": {
          "value": 12,
          "unit": "percent"
        },
        "p3": {
          "value": 1,
          "unit": "scalar"
        },
        "p4": {
          "value": 5,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "11c8e8c0d434019073dd19c3c46154e2bbf151fd115a24c31a0afd4e2a5558b6",
  "icon_path": "icon/skill/1406_talent.png"
}
```

### Puss in Boots

```json
{
  "ability_id": "140607",
  "slot": "technique",
  "name": "Puss in Boots",
  "type_code": "Maze",
  "type_label": "Technique",
  "effect_code": "Enhance",
  "targeting_label": "Enhance",
  "element": "Quantum",
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
    "p4": {
      "unit": "scalar",
      "occurrences": 1
    },
    "p3": {
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
    "spd",
    "dmg"
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
          "value": 200,
          "unit": "percent"
        },
        "p3": {
          "value": 100,
          "unit": "percent"
        },
        "p4": {
          "value": 50,
          "unit": "scalar"
        }
      }
    }
  ],
  "description_sha256": "64968023975c286a96e58bfaf25345baf9787084d9e90623bac28c2794041811",
  "icon_path": "icon/skill/1406_technique.png"
}
```

## Major traces

```json
[
  {
    "requirement": "A2",
    "name": "Empyrean Strides",
    "mechanic_tags": [
      "spd",
      "crit_rate"
    ],
    "numeric_tokens": [
      "140",
      "170",
      "25%",
      "50%",
      "50%",
      "100%"
    ],
    "description_sha256": "1bdb9d684e657808883d408e3b8719ba97c0e99e26c4b201c8662f84eedb15ac"
  },
  {
    "requirement": "A4",
    "name": "300 Rogues",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "8%"
    ],
    "description_sha256": "eee631bb1b0a0d9aca1ed431f0672ed09d976852686bf3fba50ce2b38f625802"
  },
  {
    "requirement": "A6",
    "name": "Sleight of Sky",
    "mechanic_tags": [
      "atk",
      "crit_dmg",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "100%",
      "40%"
    ],
    "description_sha256": "f7bb4571888d674f4599ac1233a8c182df2d9df85cc04a7b4eb0462f2a73b69f"
  }
]
```

## Eidolons

```json
[
  {
    "eidolon": 1,
    "name": "Read the Room, Seek the Glee",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "150%",
      "80%",
      "2"
    ],
    "description_sha256": "ad33ddd743d17dc9d815a09f3f03439a3d746d266d027cfeddec0da3d318ede6"
  },
  {
    "eidolon": 2,
    "name": "In the Fray, Nab On a Spree",
    "mechanic_tags": [
      "dmg"
    ],
    "numeric_tokens": [
      "120%",
      "30%",
      "2"
    ],
    "description_sha256": "83c6835dc22570e3c0f6d0341941f583537a90ed09b0e650f7f3ecd328e6bdad"
  },
  {
    "eidolon": 3,
    "name": "From Thin Air, Hard to Foresee",
    "mechanic_tags": [
      "atk"
    ],
    "numeric_tokens": [
      "+2",
      "15",
      "+1",
      "10"
    ],
    "description_sha256": "a7feeb7d754cfe954c7d1d3f1cd8dac81e25e12ef4d2da9be8cd9c1585c4e488"
  },
  {
    "eidolon": 4,
    "name": "The Jig Is Up, Quick to Flee",
    "mechanic_tags": [
      "atk",
      "dmg"
    ],
    "numeric_tokens": [
      "50%"
    ],
    "description_sha256": "c7b87a170aa008c76849f1320a5ee9e954bbd783cccc10d2fa36b29220c45e88"
  },
  {
    "eidolon": 5,
    "name": "Safe in Numbers, Light as a Bee",
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
    "name": "The Thief's Game, Unsung and Free",
    "mechanic_tags": [
      "atk",
      "dmg",
      "follow_up"
    ],
    "numeric_tokens": [
      "350%",
      "16%",
      "20%"
    ],
    "description_sha256": "bbd5317134d9e248dcae0a8e80a9a52adb6d125383b4e5d5a3ea6c8d32ca373e"
  }
]
```

## Data notes

- `level_scaling` preserves every numeric row in the source bundle. Percentage placeholders are converted from decimals to percentage points.
- `source_row` is the source-array index, not a guaranteed in-game reachable level; use character upgrade rules when mapping normal and Eidolon caps.
- Long copyrighted prose is not reproduced. `mechanic_tags`, numeric tokens, IDs, hashes, and the source URL support programmatic use and change detection.
- Toughness fields retain the source-page values as strings because the site display may normalize them differently.
