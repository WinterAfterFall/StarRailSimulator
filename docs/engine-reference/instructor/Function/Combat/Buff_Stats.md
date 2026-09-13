# `src/Defination/Function/Combat/Buff_Stats.h`

## `BuffClass` / `BuffElementClass` — payload มาตรฐานของการ `+stat`

```cpp
class BuffClass        { Stats statsType; AType actionType;                double value; };
class BuffElementClass  { Stats statsType; ElementType element; AType actionType; double value; };
```

คือ **รูปแบบมาตรฐาน** ของ "คำสั่งเพิ่ม/ลด stat" ทั้งเกม ส่งเป็น `vector<...>` เข้าฟังก์ชันตระกูล `buff*`
(`buffSingle` `buffSingleChar` `buffAllAlly` `buffAllMemosprite` `buffTargets` `buff*ExcludingBuffer` …ใน `Buff_Stats.h`)

**"delta" = `value`** — ปริมาณ stat ดิบ (เช่น `55` = ATK +55%). ปลาย ๆ ทาง:
- speed (`FLAT_SPD`/`SPD_P`) → เรียก `ptr->speedBuff(buff)` + `ahaSpeedAdjust`
- นอกนั้น → `ptr->Stats_type[statsType][actionType] += value`
- element version → `ptr->Stats_each_element[statsType][element][actionType] += value`
- ถ้า `actionType == None` → เรียก `StatsAdjust(ptr, statsType)` ต่อ (re-trigger `Stats_Adjust_List`)

**apply / remove ใช้ค่าคงที่ตัวเดียวกัน กันเลื่อน** (แพตเทิร์น Tingyun):
```cpp
constexpr double BENEDICTION_ATK = 55;
buffSingle(target, {{Stats::ATK_P, AType::None,  BENEDICTION_ATK}}, "Tingyun Benediction", 3); // ลง
buffSingle(target, {{Stats::ATK_P, AType::None, -BENEDICTION_ATK}});                           // ถอน
```

**2 โหมดของ `buffSingle`:**
| รูปแบบ | พฤติกรรม |
|---|---|
| `buffSingle(u, {…})` ไม่มีชื่อ | บวก stat **ทันที ถาวร ไม่ track** — ใช้ตอน "ถอนบัฟ" (ใส่ค่าลบ) |
| `buffSingle(u, {…}, "Name", extend)` | ผ่าน `isHaveToAddBuff`: `extendBuffTime` (refresh timer ทุกครั้ง) → ถ้า `Buff_check["Name"]` เป็น 1 อยู่แล้ว **ไม่บวกซ้ำ** (re-cast = ต่อเวลา ไม่ stack) |
