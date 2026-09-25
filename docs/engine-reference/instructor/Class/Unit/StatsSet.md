# `src/Defination/Class/Unit/StatsSet.h`

## `SetAllyBaseStats` — ใช้ `+=` ไม่ใช่ `=`

`CharUnit::SetAllyBaseStats` (`StatsSet.h:5-9`) บวกค่า `baseHp` / `baseAtk` / `baseDef` สะสม เพราะถูกเรียก 2 ครั้งต่อตัวละคร:

1. ไฟล์ตัวละครใส่ค่าพื้นฐานของตัวละคร เช่น `Phainon.h:6`
2. Light Cone ใส่ค่าพื้นฐานของ LC เช่น `Data/Lightcone/All_Lighcone.h:13`

ผลรวมจึงเป็นค่าพื้นฐานตัวละคร + LC

## ⚠️ ลำดับการเรียก: `SetMemoStats` ต้องมาหลัง base + LC

`SetMemoStats` (`StatsSet.h:42-44`) **ถ่ายค่า** `baseAtk` / `baseDef` / `baseHp` ของเจ้าของมาเก็บ ณ ตอนที่เรียก และการรีเซ็ตต่อ run (`Function/Setup/Stats_Reset.h`) ไม่ได้คำนวณสามค่านี้ใหม่ (คำนวณใหม่แค่ `baseSpeed`) จึงต้องเรียกตามลำดับนี้:

```cpp
CharUnit *ptr = SetCharBasicStats(...);
ptr->SetAllyBaseStats(...);   // ค่าตัวละคร
LC(ptr);                      // ค่า LC บวกเพิ่ม
Relic(ptr);
Planar(ptr);
SetMemoStats(ptr, ...);       // ถ่ายค่าที่รวมครบแล้ว
```

ถ้าเรียก `SetMemoStats` ก่อน memosprite จะได้ค่าพื้นฐานเป็น `0` หรือขาดส่วนของ LC

LC / Relic / Planar ที่อ้าง `memospriteList` (`Reminiscence.h`, `SweatNowCryLess.h`, `Hero_Wreath.h`, `The_Wondrous_BananAmusement_Park.h`) อ่านข้างใน lambda ของ trigger ทั้งหมด ไม่ได้อ่านตอน setup จึงเรียก `SetMemoStats` หลังจากสามตัวนี้ได้ปลอดภัย

### ประวัติ

- 2026-09-16: Castorice เคยเรียก `SetMemoStats` ก่อน `LC` และ `SetAllyBaseStats` ทำให้ Netherwing ได้ `baseAtk = 0`, `baseDef = 0` · user ยืนยันว่าเป็นความบังเอิญ ไม่ได้ตั้งใจ · แก้ลำดับให้ตรงกับ Aglaea / Hyacine / RMC แล้ว · ผลต่อตัวเลขน่าจะไม่มี เพราะเลือด Netherwing ตั้งคงที่ `fixHP = 34000`, `Hp_ratio = 0` และชุดสกิลคิดจาก Max HP ของ Castorice แต่ยังไม่ได้รัน simulation ยืนยัน

## Factory 4 ตัว — ใครถูกใส่ลงลิสต์ไหน

ตรวจโค้ด 2026-09-16 · ความหมายของ summon / countdown / memosprite อยู่ใน [CharUnit.md](CharUnit.md) แล้ว หัวข้อนี้บันทึกแค่สิ่งที่ factory ทำ

| factory | ชนิด object | `charUnit` / `charList` | `allyList` | `atvList` | `side` | `num` | `owner` |
|---|---|---|---|---|---|---|---|
| `SetCharBasicStats` (`:10`) | `CharUnit` | ✅ | ✅ | ✅ | `Ally` | `Total_ally` ใหม่ | — |
| `SetMemoStats` (`:30`) | `Memosprite` | — | ✅ | ✅ | `Memosprite` | ของเจ้าของ | เจ้าของ |
| `SetCountdownStats` (`:55`) | `AllyUnit` ดิบ | — | — | ✅ | `Countdown` | ของเจ้าของ | `nullptr` ([🐞 #8](../../BUGS.md)) |
| `SetSummonStats` (`:66`) | `AllyUnit` ดิบ | — | — | ✅ | `Summon` | ของเจ้าของ | `nullptr` ([🐞 #8](../../BUGS.md)) |

สิ่งที่อ่านได้จากตาราง:

- **อยู่ใน `allyList` = เป็นเป้าของศัตรูและรับบัฟแบบวนทีมได้** — มีแค่ตัวละครกับ memosprite · summon / countdown อยู่แค่ `atvList` จึงมีเทิร์นของตัวเองแต่ไม่โดนตีและไม่รับบัฟ
- **`num` ใช้ร่วมกับเจ้าของ** — memosprite / summon / countdown ได้ `num` เดียวกับตัวละครเจ้าของ แยกกันด้วย `side` (เช่น Jingyuan เช็กเทิร์นด้วย `num` + `side` ที่ `Jingyuan.h:66`)
- **`charptr` ชี้ตัวเอง** ทั้ง memosprite, summon และ countdown (`:50,64,76`)
- `Name` ของ summon / countdown ใช้ชื่อที่ส่งมา (แก้ใน [🐞 #2](../../BUGS.md))
- `baseTaunt` ของ memosprite ใช้ Path ของเจ้าของ (`:52`) เพราะ memosprite ไม่มี `path` ของตัวเอง

### `SetCharBasicStats`

ตั้ง `baseSpeed`, `Max_energy`, `Ult_cost`, `Eidolon`, `Element_type`, `path`, `Name`, `side`, `Type` และ `baseTaunt` · รายละเอียด energy ดู [Energy.md](../../Function/Combat/Energy.md) · `Type` ดู [ActionValueStats.md](ActionValueStats.md) · `Element_type` / `path` เป็นค่าเดียว ดู [AllyUnit.md](AllyUnit.md) และ [CharUnit.md](CharUnit.md)

### `SetMemoStats`

- `baseSpeed = fixSpeed + Speed_ratio/100 × baseSpeed ของเจ้าของ` (`:39`) และคำนวณซ้ำตอนรีเซ็ต (`Stats_Reset.h:255`)
- `baseHp = baseHp เจ้าของ × Hp_ratio/100` · `baseAtk` / `baseDef` = ของเจ้าของดิบ ๆ — ถ่ายค่าครั้งเดียว ดูหัวข้อลำดับการเรียกด้านบน
- `fixHP` เก็บไว้เฉย ๆ ตรงนี้ ไปถูกใช้จริงตอนรีเซ็ต ดู [Stats_Reset.md](../../Function/Setup/Stats_Reset.md)
