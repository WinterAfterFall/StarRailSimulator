# `src/Defination/Data/Lightcone/Destruction/`

13 ใบ · `namespace Destruction_Lightcone` · อ่าน `../README.md` ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `Phainon LC.h` | `Phainon_LC` | `Phainon_LC` | DEF_SHRED `13.5+4.5S` · **`baseSpeed += 10+2S`** | กด ult → DMG `42+18S` 1 เทิร์น |
| `Mydei_LC.h` | `Mydei_LC` | `Mydei_LC` | HP% `15+3S` · Incoming Healing `15+5S` | Skill/Ult → จ่าย HP + DMG `25+5S` (×2 ถ้า HP ที่จ่าย > 500) เฉพาะ action นั้น |
| `Saber_LC.h` | `Saber_LC` | `Saber_LC` | CD `27+9S` | กด ult → ATK `30+10S` 2 เทิร์น (×2 + energy ถ้า `Max_energy >= 300`) |
| `FireFly_LC.h` | `FireFly_LC` | `FireFly_LC` | BE `50+10S` | ผู้สวมโจมตี → เป้าติด Break VUL `20+4S` + SPD −20 |
| `Jingliu_LC.h` | `Jingliu_LC` | `Jingliu_LC` | CD `17+3S` | ถูกตี/เสีย HP → DMG stack (cap 3) · ครบ 3 → DEF_SHRED · ล้างเมื่อโจมตี |
| `Blade_LC.h` | `Blade_LC` | `Blade LC` | CR `15+3S` · HP% `15+3S` | ถูกตี/เสีย HP → DMG `20+4S` ครั้งเดียว ล้างเมื่อโจมตี |
| `Clara_LC.h` | `Clara_LC` | `Clara_LC` | ATK% `20+4S` | ถูกตี → ฮีลตัวเอง `7+S`% + DMG `20+4S` 1 เทิร์น (ครั้งเดียว/เทิร์น) |
| `Danheng_LC.h` | `Danheng_LC` | `Danheng_LC` | CR `15+3S` | ใช้ BA → ATK + ER stack (cap 2) 2 เทิร์น |
| `HertaShop.h` | `Hertashop` | `Fall of an Aeon` | — | โจมตี → ATK stack (cap 4) · ผู้สวม break → DMG `9+3S` 2 เทิร์น |
| `Ninja_Record.h` | `Ninja_Record` | `Ninja Record` | HP% `9+3S` | ถูกฮีล/เสีย HP → CD `13.5+4.5S` 2 เทิร์น |
| `BP2.h` | `BP2` | `A Trail of Bygone Blood` | CR `10+2S` · Skill/Ult DMG `20+4S` | — |
| `Secret_Vow.h` | `Secret_Vow` | `Secret_Vow` | DMG `30+10S` | — |
| `Secret_Vow_Nobuff.h` | `Secret_Vow_NoBuff` | `Secret_Vow` | DMG `15+5S` | — |
| `The Moles.h` | `The_Moles` | `The Moles` | — | ใช้ BA/Skill/Ult ครั้งแรกของแต่ละชนิด → ATK `9+3S` (สะสมได้ 3 ก้อน) |

## แบบแผนของโฟลเดอร์นี้

**1. LC สาย Destruction ผูกกับ "การถูกตี" และ "การเสีย HP" มากที่สุด** — `Blade_LC`, `Jingliu_LC`, `Clara_LC`, `Ninja_Record` ใช้ `Enemy_hit_List` และ/หรือ `HPDecrease_List` · เป็นโฟลเดอร์ที่ใช้ trigger สองตัวนี้หนาแน่นที่สุด

**2. `Secret_Vow.h` กับ `Secret_Vow_Nobuff.h` เป็นใบเดียวกันสองเวอร์ชัน** — `Light_cone.Name` เหมือนกัน (`"Secret_Vow"`) ต่างแค่ค่า (30+10S vs 15+5S) · เป็นวิธีจำลอง "เงื่อนไขของ kit เข้า/ไม่เข้า" ด้วยการทำสองไฟล์ แทนที่จะรับ `bool` แบบ `../../Relic/Diviner of Distant Reach.md` และ `Jiaoqiu_LC.h`

**3. บัฟชั่วคราวที่ล้างเมื่อผู้สวมโจมตี** — `Blade_LC`, `Jingliu_LC`, `Mydei_LC` ใช้ `AfterAttackActionList` เป็นจุดล้าง · เป็นสำนวนของ kit กลุ่มนี้ที่ "สะสมระหว่างรอ แล้วปล่อยตอนตี"

## จุดที่ควรระวังร่วมกัน

- **`Jingliu_LC.h` `Enemy_hit_List` วน `target` แล้ว `buffStackSingle` ทุกรอบโดยไม่เช็คว่าเป็นตัวเอง** → ถ้าศัตรูตีโดน 3 คน ผู้สวมได้ 3 stack แม้ไม่ได้โดนเอง
- ~~`FireFly_LC.h` guard ผู้โจมตีกลับด้าน~~ · ~~`Mydei_LC.h` เงื่อนไข HP / HEALING_OUT~~ · ~~`HertaShop.h` ไม่ guard ผู้ break~~ · ~~`Clara_LC.h` ค่าฮีล / ครั้งเดียวต่อเทิร์น~~ — แก้ตาม kit แล้ว 2026-09-26
