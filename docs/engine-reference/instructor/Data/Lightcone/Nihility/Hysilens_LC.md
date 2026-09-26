# `src/Defination/Data/Lightcone/Nihility/Hysilens_LC.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"Hysilens_LC"` · base stats `SetAllyBaseStats(953, 635, 463)`

**signature ของ Hysilens** (ดู `../../Character/Nihility/Hysilens.md`)

| ท่อน | โค้ด |
|---|---|
| EHR `35 + 5S` | `Reset_List` |
| เพื่อนตีเป้าที่ติด Enthrallment (มี stack `"Hys LC"`) → ผู้ตี SPD `7.5 + 2.5S` 3 เทิร์น | `BeforeAttackAction_List` → `buffSingle(act->Attacker, ..., "Hys LC SPD", 3)` · ถอนใน `After_turn_List` |
| ลง debuff → VUL[Dot] stack `3.75 + 1.25S` ตามจำนวน debuff ที่เพิ่มขึ้น (cap 6) | `BeforeApplyDebuff` + `AfterApplyDebuff` |

## รากฐาน: วัด "จำนวน debuff ที่เพิ่มขึ้นจริง" ด้วยคู่ Before/After

```cpp
BeforeApplyDebuff: if (Trigger->isSameName(ptr)) target->setDebuffNote("Hys LC TotalDebuff", target->Total_debuff);
AfterApplyDebuff:  if (Trigger->isSameName(ptr)) {
                       if (target->Total_debuff - target->getDebuffNote("Hys LC TotalDebuff") == 0) return;
                       debuffStackSingle(ptr, target, {{VUL, AType::Dot, ...}},
                                         target->Total_debuff - target->getDebuffNote(...), 6, "Hys LC");
                   }
```
**จดค่าก่อน แล้วลบกับค่าหลัง** = จำนวน debuff ที่ลงติดจริง (ไม่ใช่จำนวนครั้งที่พยายามลง) · `debuffNote` บนศัตรูใช้เป็นที่จดค่าชั่วคราว

`debuffStackSingle(ผู้ลง, เป้า, {stat}, จำนวนที่เพิ่ม, cap, ชื่อ)` — เวอร์ชัน stack ของ `debuffSingleApply` ที่รับจำนวนเพิ่มเป็นตัวแปร

## จุดที่ควรระวัง

- **มีโค้ด debug คอมเมนต์ทิ้ง 5 บรรทัด** และ `ptr->setBuffCheck("LC Hys using", 1)` ที่ตั้งแล้วไม่มีใครอ่าน (บรรทัด guard ที่จะใช้มันถูกคอมเมนต์ไว้) → น่าจะเป็นร่องรอยการดีบัก recursion
- **VUL stack ไม่มีโค้ดถอน** — `debuffStackSingle` ลงโดยไม่มี duration และไม่มี `isDebuffEnd` รองรับ → ค้างถาวร
- **แก้ 2026-09-26**: เดิมให้ SPD ทั้งทีมถาวรตอนเข้าสนาม (`buffAllAlly`) · ตอนนี้ให้เฉพาะผู้ที่ตีเป้าติด Enthrallment 3 เทิร์นตาม kit · ใช้ stack `"Hys LC"` > 0 แทนสถานะ Enthrallment (ยังไม่ได้ทำโอกาส 80% และอายุ 3 เทิร์นของ Enthrallment)
