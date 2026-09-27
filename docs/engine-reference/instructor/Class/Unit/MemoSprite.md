# `src/Defination/Class/Unit/MemoSprite.h`

`class Memosprite : public AllyUnit` — เพิ่ม field จาก `AllyUnit` แค่ 4 ตัว ทั้งหมดเป็นสูตรสร้าง HP / SPD จากเจ้าของ (ตรวจโค้ด 2026-09-16)

| field | ตั้งที่ | ใช้ที่ |
|---|---|---|
| `unitHpRatio` | `setMemoStats` (`StatsSet.h:37`) | `baseHp = baseHp เจ้าของ × Unit_Hp_Ratio/100` (`StatsSet.h:43`) และคูณ `FLAT_HP` ทุก AType ตอนรีเซ็ต |
| `unitSpeedRatio` | `setMemoStats` (`StatsSet.h:38`) | `baseSpeed = fixSpeed + Unit_Speed_Ratio/100 × baseSpeed เจ้าของ` (`StatsSet.h:39`, คำนวณซ้ำที่ `Stats_Reset.h:255`) |
| `fixHP` | `setMemoStats` (`StatsSet.h:40`) | บวกเข้า `FLAT_HP[NONE]` ตอนรีเซ็ต |
| `fixSpeed` | `setMemoStats` (`StatsSet.h:41`) | ส่วนคงที่ของ `baseSpeed` |

สรุปคือ memosprite มี HP / SPD สองส่วน: **ส่วนคงที่** (`fix*`) + **ส่วนที่อิงเจ้าของ** (`*_Ratio`) · ตัวอย่าง Castorice ตั้ง `fixHP = 34000`, `hpRatio = 0`, `fixSpeed = 165`, `speedRatio = 0` คือ Netherwing ไม่อิงเจ้าของเลยทั้งสองค่า ส่วน Aglaea ตั้ง `fixHP = 720`, `hpRatio = 66`, `fixSpeed = 0`, `speedRatio = 35` คืออิงเจ้าของเป็นหลัก

ลำดับการคำนวณตอนรีเซ็ตต่อ run ดู [Stats_Reset.md](../../Function/Setup/Stats_Reset.md) · กฎลำดับการเรียก `setMemoStats` ดู [StatsSet.md](StatsSet.md)
