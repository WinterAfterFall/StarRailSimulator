# Mydei (Mydeimos) — ไมได

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Destruction/Mydei.h` |
| ธาตุ | **Imaginary** |
| Path | **Destruction** |
| ระดับ | 5★ |
| Energy Ultimate | 160 |
| อ้างอิง | prydwen.gg (review/calc patch 3.1) |

## Base Stats (Lv.80, ascended)
HP 1552 · ATK 426 · DEF 194 · SPD 95

---

## Basic ATK — Vow of Voyage (โจมตีเดี่ยว, Lv.6)
- Imaginary DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Deaths are Legion, Regrets are None (Blast, Lv.10)
- กิน HP = **50% ของ HP ปัจจุบัน** (ไม่พอ → HP = 1)
- Imaginary DMG เป้าหมายหลัก = **90% Max HP**, ข้างเคียง = **50% Max HP**
- Energy +30 · Toughness 20 (+10 ข้างเคียง)

## Skill (Enhanced) — Kingslayer Be King (Blast, Lv.10) — ใช้อัตโนมัติ
- กิน HP = **35% ของ HP ปัจจุบัน** (ไม่พอ → HP = 1)
- Imaginary DMG หลัก = **110% Max HP**, ข้างเคียง = **66% Max HP**
- Energy +30 · Toughness 20 (+10)

## Skill (Enhanced) — Godslayer Be God (Blast, Lv.10) — ใช้อัตโนมัติ
- กิน **Charge 150 แต้ม**
- Imaginary DMG หลัก = **280% Max HP**, ข้างเคียง = **168% Max HP**
- ขณะใช้ท่านี้ Charge สะสมไม่ได้
- Energy +10 · Toughness 30 (+20)

## Ultimate — Throne of Bones (Blast, 160 energy, Lv.10)
- ฮีลตัวเอง **20% Max HP** + สะสม Charge **20 แต้ม**
- Imaginary DMG หลัก = **160% Max HP**, ข้างเคียง = **100% Max HP**
- Taunt เป้าหมาย + ข้างเคียง นาน 2 เทิร์น
- "Godslayer Be God" ครั้งถัดไปพุ่งใส่เป้าหมายที่กำหนดก่อน (มีผลกับ target ล่าสุดเท่านั้น)
- Energy +5 · Toughness 20 (+20)

## Talent — Blood for Blood (Lv.10)
- ทุก 1% HP ที่เสียไป → Charge **+1** (สูงสุด 200)
- Charge ถึง **100** → กิน 100, เข้าสถานะ **"Vendetta"**, ฮีล **25% Max HP**, advance action **100%**
- ขณะ Vendetta: **Max HP +50% ของ Max HP ปัจจุบัน**, DEF = 0; เริ่มเทิร์น → ใช้ "Kingslayer Be King" อัตโนมัติ
- ขณะ Vendetta Charge ถึง **150** → ได้เทิร์นพิเศษทันที + ใช้ "Godslayer Be God" อัตโนมัติ
- โดน killing blow ขณะ Vendetta → ไม่ล้ม แต่ล้าง Charge, ออกจาก Vendetta, ฮีล 50% Max HP

## Technique — Cage of Broken Lance
- ดึงศัตรู + Daze 10 วิ
- โจมตีศัตรู Dazed → เข้าฉาก: Imaginary DMG = **80% Max HP** AoE + Taunt 1 เทิร์น + สะสม Charge **50 แต้ม**

---

## Major Traces
- **A2 — Earth and Water**: ขณะ Vendetta โดน killing blow → ไม่ออกจาก Vendetta (trigger 3 ครั้ง/การต่อสู้)
- **A4 — Thirty Tyrants**: ขณะ Vendetta → ภูมิคุ้มกัน Crowd Control
- **A6 — Bloodied Chiton**: ต้นการต่อสู้ ถ้า Max HP > 4000 → ทุก 100 HP ส่วนเกิน: CRIT Rate **+1.2%**, อัตรา Charge จากดาเมจที่รับ **+2.5%**, Incoming Healing **+0.75%** (นับส่วนเกินสูงสุด 4000)

## Minor Traces (รวมทั้งหมด)
CRIT DMG +37.3% · SPD +5 · HP +18%

## Eidolons
- **E1**: "Godslayer Be God" multiplier เป้าหมายหลัก **+30%** และเปลี่ยนเป็นตีศัตรูทุกตัวด้วย multiplier เท่าเป้าหมายหลัก
- **E2**: ขณะ Vendetta ดาเมจเพิกเฉย DEF **15%**. หลังรับการฮีล → แปลง **40% ของ heal** เป็น Charge (cap 40, รีเซ็ตหลังหน่วยใด action)
- **E3**: Skill Lv. +2 (สูงสุด 15) · Basic ATK Lv. +1 (สูงสุด 10)
- **E4**: ขณะ Vendetta → CRIT DMG **+30%** + ฮีล **10% Max HP** หลังถูกศัตรูโจมตี
- **E5**: Ultimate Lv. +2 (สูงสุด 15) · Talent Lv. +2 (สูงสุด 15)
- **E6**: เข้าฉาก → เข้า Vendetta ทันที + ลด Charge ที่ต้องใช้ของ "Godslayer Be God" เหลือ **100**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **ดาเมจทุกท่าสเกลกับ Max HP** (BA 50%, Skill 90/50, Vendetta-Skill 110/66, Godslayer 280/168, Ult 160/100)
- **Charge** สองแหล่ง: HP loss (1:1% cap 200) + A6 ratio จากดาเมจที่รับ + E2 จาก heal
- **Vendetta enter (Charge 100)**: ฮีล 25%, advance 100%, Max HP ×1.5, DEF→0, auto Kingslayer ทุกเทิร์น
- **Vendetta Charge 150** → extra turn + auto Godslayer (E6 ลด threshold เป็น 100)
- **โค้ด `Start_game_List`**: คำนวณ A6 (`Buff_note["Mydei_A6"]`), ปรับ CR/Healing; E6 → set `Buff_check["Mydei_Vendetta"]`, `Action_forward 100`, ฮีล, `FLAT_DEF -= 10000`
- Godslayer ใช้อัตโนมัติเมื่อเงื่อนไข Charge — sim ต้อง handle auto-action ใน turn loop
- Ult redirect "Godslayer" ใส่ target ล่าสุด

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/mydei — kit tab (review/calc patch 3.1, profile 01/Jun/2026)
