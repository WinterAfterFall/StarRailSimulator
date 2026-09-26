# `src/Defination/Data/Lightcone/Nihility/Hysilens_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Hysilens_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Hysilens** (ดู `../../Character/Nihility/Hysilens.md`) · บังคับ `newApplyBaseChanceRequire(80)` แทนโอกาส 80% ของ Enthrallment

| ท่อน | โค้ด |
|---|---|
| EHR `35 + 5S` | `Reset_List` |
| ผู้สวมลง debuff ใส่เป้าที่ยังไม่ติด → เป้าเข้า `Hys LC Enthrallment` 3 เทิร์น | `AfterApplyDebuff` (ตั้ง flag เอง ไม่ยิง event ซ้ำ) |
| ผู้สวมลง debuff ใส่เป้าที่ติด Enthrallment → VUL[Dot] stack `3.75 + 1.25S` ตามจำนวน debuff ที่เพิ่ม (cap 6) | `BeforeApplyDebuff` + `AfterApplyDebuff` |
| เพื่อนคนไหนตีเป้าติด Enthrallment → ผู้ตี SPD `7.5 + 2.5S` 3 เทิร์น | `BeforeAttackAction_List` → `buffSingle(act->Attacker, ..., "Hys LC SPD", 3)` |
| Enthrallment หมด → ถอด VUL stack ทั้งหมด | `After_turn_List` → `isDebuffEnd` + `debuffStackRemove` + ลด `Total_debuff` ของ stack |
| ถอน SPD | `After_turn_List` → `isBuffEnd(ally, "Hys LC SPD")` |

ชื่อ `Hys LC Enthrallment` / `Hys LC` / `Hys LC SPD` ไม่มี prefix โดยตั้งใจ — kit ระบุ "Effects of the same type cannot stack" (ดูแบบแผนข้อ 4 ใน `README.md`)

## รากฐาน: วัด "จำนวน debuff ที่เพิ่มขึ้นจริง" ด้วยคู่ Before/After

```cpp
BeforeApplyDebuff: note = target->Total_debuff;
AfterApplyDebuff:  applied = target->Total_debuff - note;   // debuff ที่ลงติดจริง
```
`debuffNote` บนศัตรูใช้เป็นที่จดค่าชั่วคราว

## รากฐาน: กัน recursion

- **ลง VUL stack** ผ่าน `debuffStackSingle` ซึ่งยิง `Before/AfterApplyDebuff` อีกรอบ → ใช้ `buffCheck["Hys LC Stacking"]` บนผู้สวมเป็นตัวกัน ไม่ให้ stack นับตัวเอง
- **เข้า Enthrallment** ตั้ง `setDebuff` + `addTotalDebuff(1)` + `extendDebuff(3)` ตรง ๆ ไม่ผ่าน `debuffApply` เพื่อไม่ให้ยิง event ซ้ำ → debuff ตัวที่ทำให้เข้า Enthrallment **ไม่นับ** เป็น stack (kit: นับเฉพาะ debuff ที่ลง "ขณะ" ติด Enthrallment)
- **stack `Hys LC` นับใน `Total_debuff` 1 ครั้ง** (ตอน 0 → บวก ใน `calDebuffStack`) แต่ `debuffStackRemove` ไม่ลดคืน จึงลดเองก่อนถอด

## ยังไม่ได้ทำ

- ผู้สวมถูกล้ม → ล้าง Enthrallment ทั้งหมด (sim ไม่มีกรณีฝ่ายเราถูกล้มที่ใช้กับใบนี้)

> **แก้ 2026-09-26**: (1) เดิมให้ SPD ทั้งทีมถาวร → เฉพาะผู้ตีเป้าติด Enthrallment 3 เทิร์น (2) เดิมไม่มี Enthrallment ใช้ stack `"Hys LC"` > 0 แทน และ VUL stack ไม่เคยถูกถอด (ค้างถาวรที่ 6) → ทำ Enthrallment 3 เทิร์นจริง และถอด stack เมื่อหมด (3) ลบโค้ด debug ที่คอมเมนต์ทิ้งกับ `setBuffCheck("LC Hys using")` ที่ไม่มีใครอ่าน
