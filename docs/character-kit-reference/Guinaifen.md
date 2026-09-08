# Guinaifen — กุ้ยไหน่เฟิน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Nihility/Guinaifen.h` |
| ธาตุ | **Fire** |
| Path | **Nihility** |
| ระดับ | 4★ |
| Energy Ultimate | 120 |
| อ้างอิง | prydwen.gg (review patch 3.0 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 882 · ATK 582 · DEF 441 · SPD 106

> Nihility DoT/support สาย Burn + "Firekiss" (vulnerability)

---

## Basic ATK — Standing Ovation (โจมตีเดี่ยว, Lv.6)
- Fire DMG = **100% ATK** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Blazing Welcome (Blast, Lv.10)
- Fire DMG หลัก = **120% ATK**, ข้างเคียง = **40% ATK**
- 100% base chance ติด **Burn** เป้าหมาย + ข้างเคียง
- Burn: Fire DoT = **218.2% ATK** ต้นทุกเทิร์น นาน 2 เทิร์น
- Energy +30 · Toughness 20 (+10)

## Ultimate — Watch This Showstopper (AoE, 120 energy, Lv.10)
- Fire DMG = **120% ATK** AoE
- ถ้าเป้าหมายติด Burn → Burn ลงดาเมจทันที = **92% ของดาเมจ Burn เดิม**
- Energy +5 · Toughness 20

## Talent — PatrAeon Benefits (Lv.10)
- ขณะ Guinaifen อยู่ในสนาม → 100% base chance ติด **Firekiss** ให้ศัตรูหลังจาก Burn ลงดาเมจ
- Firekiss: ศัตรูรับดาเมจเพิ่ม **+7%** นาน 3 เทิร์น stack 3 ครั้ง
- Energy +5

## Technique — Skill Showcase
- เข้าฉากโจมตี: **4 instance × 50% ATK** Fire DMG ใส่ศัตรูสุ่ม + 100% base chance ติด Firekiss
- Toughness 20

---

## Major Traces
- **A2 — High Poles**: Basic ATK 80% base chance ติด Burn (แบบเดียวกับ Skill)
- **A4 — Bladed Hoop**: ต้นการต่อสู้ → Guinaifen action advance **25%**
- **A6 — Walking on Knives**: สร้างดาเมจกับศัตรู Burned **+20%**

## Minor Traces (รวมทั้งหมด)
Fire DMG +22.4% · Effect HIT Rate +10% · Break Effect +24%

## Eidolons
- **E1**: ใช้ Skill → 100% base chance ลด Effect RES ศัตรูที่โดน **10%** นาน 2 เทิร์น
- **E2**: ศัตรูติด Burn → Basic ATK/Skill ของ Guinaifen เพิ่ม multiplier ของ Burn **+40%**
- **E3**: Skill Lv. +2 · Basic ATK Lv. +1
- **E4**: ทุกครั้ง Burn ของ Guinaifen ลงดาเมจ → คืน Energy **2**
- **E5**: Ultimate Lv. +2 · Talent Lv. +2
- **E6**: Firekiss stack cap **+1** (รวม 4)

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Burn** DoT: 218.2% ATK/2t (E2 +40% multiplier ถ้าตีด้วย BA/Skill ตอน burned)
- **Firekiss** = vulnerability debuff: +7%/stack, cap 3 (E6 4) — trigger หลัง Burn ลงดาเมจ (Talent) + Technique
- **Ult**: บังคับ Burn ลงดาเมจทันที 92%
- **A6**: DMG amp vs Burned +20% (self)
- **E4 energy**: +2 ต่อ Burn tick
- โค้ด: `Start_game_List` (`Guinaifen.h:100`, `gui`) — A4 advance + technique

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/guinaifen — kit tab (review patch 3.0, calc patch 3.4, profile 01/Jun/2026)
