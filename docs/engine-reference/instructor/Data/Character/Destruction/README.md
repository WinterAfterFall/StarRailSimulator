# `src/Defination/Data/Character/Destruction/`

DPS ที่มีทรัพยากรหนักและสถานะพิเศษ · 4 ไฟล์

| ไฟล์ | บทบาท | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `Mydei.h` | HP เป็นทรัพยากร | **taunt** (`addTaunt`/`removeTaunt`) · `HPDecrease_List` · `Enemy_hit_List` |
| `Phainon.h` | สถานะอัลติที่ลบทีมออกจากสนาม | `UnitStatus::Retire` / `AtvFreeze` · countdown เป็นตัวเดินเทิร์น · `Setup_List` |
| `Saber.h` | energy พิเศษ (360) | lambda คู่ สะสม/ใช้ทรัพยากร · การจัดจังหวะ ult ที่ซับซ้อนที่สุด |
| `FireFly.h` | Super Break | `Superbreak_trigger` · `weaknessApply` · ดาเมจที่ประกอบใน callback ทั้งก้อน |

> **แก้ 2026-09-27**: FireFly ปรับตาม kit (rework patch 4.2) — ดู `FireFly.md` · Mydei energy Skill 48 → 30 (ผ่าน ER) + Vendetta advance + Charge cap — ดู `Mydei.md`

## แบบแผนร่วมของกลุ่มนี้

**1. ทุกตัวมีสถานะพิเศษที่กินหลายเทิร์น** และใช้กลไกต่างกันหมด:
- `Mydei` — `buffCheck["Mydei_Vendetta"]` ไม่มีวันจบ
- `Phainon` — countdown unit ที่เล่นแทนเจ้าของ 8 เทิร์น
- `Saber` — `Mana Flow` + เงื่อนไข energy
- `FireFly` — countdown unit เป็นนาฬิกาจับเวลาอย่างเดียว

**2. 2 ใน 4 ตัวมี energy ult ไม่ปกติ** — `Phainon` = 0 (ใช้ทรัพยากรแทน), `Saber` = 360 · `Tingyun.h` มี escape hatch สำหรับ Saber โดยเฉพาะ

**3. การหารจำนวนเต็มโดยไม่ตั้งใจพบ 2 จุด** — `Saber.h:83` และ `Phainon.h:109` · เวลาเขียนตัวเลขทศนิยมต้องมี `.0`
