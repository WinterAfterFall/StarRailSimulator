# Hyacine (Hyacinthia) — ไฮอาซีน

| | |
|---|---|
| ไฟล์โค้ด | `src/Defination/Data/Character/Remembrance/Hyacine.h` |
| ธาตุ | **Wind** |
| Path | **Remembrance** |
| ระดับ | 5★ |
| Energy Ultimate | 140 |
| อ้างอิง | prydwen.gg (review patch 3.2 / calc patch 3.4) |

## Base Stats (Lv.80, ascended)
HP 1087 · ATK 388 · DEF 630 · SPD 110

> Remembrance healer สาย SPD scaling + memosprite **Little Ica** + healing-tally DMG

---

## Basic ATK — When Breeze Kisses Cirrus (โจมตีเดี่ยว, Lv.6)
- Wind DMG = **50% Max HP** ใส่ศัตรู 1 ตัว
- Energy +20 · Toughness 10

## Skill — Love Over the Rainbow (Restore, Lv.10)
- เรียก **Little Ica**
- ฮีลเพื่อนทุกคน (ยกเว้น Little Ica) = **8% Max HP + 160**
- ฮีล Little Ica = **10% Max HP + 200**
- Energy +30

## Ultimate — We Who Fly Into Twilight (Support, 140 energy, Lv.10)
- เรียก Little Ica
- ฮีลเพื่อนทุกคน (ยกเว้น Little Ica) = **10% Max HP + 200**; ฮีล Little Ica = **12% Max HP + 240**
- Hyacine เข้าสถานะ **"After Rain"** นาน 3 เทิร์น (ลด 1 ตอนเริ่มเทิร์นของ Hyacine)
- ขณะ After Rain: เพื่อนทุกคน Max HP **+30% + 600**
- Energy +5

## Talent — First Light Heals the World (Lv.10)
- Little Ica: initial Max HP = **50% ของ Max HP ของ Hyacine**
- เมื่อ Hyacine หรือ Little Ica ฮีล → Little Ica +DMG **80%** นาน 2 เทิร์น stack 3 ครั้ง

## Technique — Day So Right, Life So Fine!
- ต้นการต่อสู้ถัดไป → ฮีลเพื่อนทุกคน **30% Max HP + 600** + Max HP **+20%** นาน 2 เทิร์น

## Memosprite: Little Ica
### Memosprite Skill — Rainclouds, Time to Go! (AoE, Lv.6)
- Wind DMG AoE = **20% ของ tally การฮีลทั้งหมดของ Hyacine + Little Ica ในการต่อสู้นี้** + ล้าง tally **50%** (E6 → 12%)
- Energy +5 · Toughness 10

### Memosprite Talent
- **Take Sky in Hand**: Little Ica SPD คงที่ 0, ต้าน debuff, ไม่อยู่ใน Action Order. เมื่อเพื่อน (ยกเว้น Little Ica) เสีย HP → Little Ica กิน HP ตัวเอง **4% Max HP** และฮีลเพื่อนคนนั้น = **2% Max HP ของ Hyacine + 20** (ต้นเทิร์นใด ๆ / หลัง action ใด ๆ)
  - ขณะ After Rain: Little Ica ได้เทิร์นพิเศษทันที + auto "Rainclouds, Time to Go!" หลัง Hyacine ใช้ ability; เมื่อ Little Ica trigger heal → ฮีลเพื่อนทุกคนเพิ่ม **2% Max HP ของ Hyacine + 20**; หลัง Little Ica ใช้ ability → Continuous Effect ทั้งหมด duration −1
- **Soar, Unto the Sunlight**: เรียก Little Ica → คืน Energy **15** ให้ Hyacine (ครั้งแรก **30**)
- **Roar Rumbles the Realm**: Little Ica หาย → advance action Hyacine **30%**

---

## Major Traces
- **A2 — Gloomy Grin**: Hyacine + Little Ica CRIT Rate **+100%**. ฮีลเพื่อนที่ HP ≤ 50% Max HP → Hyacine + Little Ica Outgoing Healing **+25%**
- **A4 — Stormy Caress**: Hyacine Effect RES **+50%**. ใช้ Skill/Ult → ลบ debuff 1 อันจากเพื่อนทุกคน
- **A6 — Tempestuous Halt**: SPD > 200 → Hyacine + Little Ica Max HP **+20%**; ทุก 1 SPD ส่วนเกิน → Outgoing Healing **+1%** (นับสูงสุด 200 SPD ส่วนเกิน)

## Minor Traces (รวมทั้งหมด)
HP +10% · SPD +14 · Effect RES +18%

## Eidolons
- **E1**: ขณะ After Rain → เพื่อนทุกคน Max HP **+50%** เพิ่ม + หลัง Hyacine โจมตี → ฮีลตัวเอง **8% Max HP**
- **E2**: เมื่อเพื่อนเสีย HP → SPD **+30%** นาน 2 เทิร์น
- **E3**: Ultimate Lv. +2 · Basic ATK Lv. +1 · Memosprite Skill Lv. +1
- **E4**: A6 enhanced — ทุก 1 SPD ส่วนเกิน → Hyacine + Little Ica CRIT DMG **+2%** เพิ่ม
- **E5**: Skill Lv. +2 · Talent Lv. +2 · Memosprite Talent Lv. +1
- **E6**: Little Ica "Rainclouds" ล้าง tally เหลือ **12%**. ขณะ Little Ica อยู่ในสนาม → เพื่อนทุกคน All-Type RES PEN **+20%**

---

## กลไกสำคัญ (จุดที่ต้องเทียบกับโค้ด)
- **Healing tally** = ผลรวมการฮีลของ Hyacine + Little Ica ทั้งการต่อสู้ → Little Ica Skill DMG = 20% ของ tally, ล้าง 50% (E6 12%)
- **Little Ica (memosprite)**: SPD 0, ไม่อยู่ใน action order, HP = 50% Hyacine HP; reactive heal เมื่อเพื่อนเสีย HP (กิน 4% HP ตัวเอง → ฮีล 2% Hyacine HP + 20)
- **ดาเมจ BA สเกลกับ Max HP** (50%); healing สเกลกับ Max HP ของ Hyacine
- **After Rain (Ult)**: Max HP +30%+600 ทีม (E1 +50%) + Little Ica extra turn loop
- **SPD scaling** (A6 > 200 → HP + heal%; E4 → CD) — Hyacine เป็น SPD-stacking healer
- **A2 CRIT Rate +100%** ให้ Hyacine + Little Ica
- โค้ด: `Start_game_List` (`Hyacine.h:97`, `Hycptr`, `Icaptr`) — Ica = Little Ica

## แหล่งอ้างอิง
- https://www.prydwen.gg/star-rail/characters/hyacine — kit tab (review patch 3.2, calc patch 3.4, profile 01/Jun/2026)
