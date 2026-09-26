# `src/Defination/Data/Lightcone/Elation/Mushy Shroomy's Adventures.h`

`namespace Elation_Lightcone` · `Light_cone.Name` = `"Mushy Shroomy's Adventures"` · base stats `SetAllyBaseStats(847, 476, 397)`

ฟังก์ชันชื่อ `MushyShroomy`

| ท่อน | โค้ด |
|---|---|
| Elation `10 + 2S` | `Reset_List` |
| ใช้ Elation Skill → ศัตรูทุกตัวติด VUL[ElationDMG] `5 + S` 2 เทิร์น | `BeforeAllyActionList` → `debuffAllEnemyApply(..., debuffName, 2)` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " MushyShroomy Debuff"`)

## จุดที่ควรระวัง

> **แก้ 2026-09-26**: เดิม `debuffAllEnemyApply` ไม่ได้ส่ง duration → `debuffEnd` ไม่ถูกตั้ง `isDebuffEnd` แทบไม่เคยจริง → **VUL ค้างถาวร** (ไม่ซ้อน เพราะ `debuffApply` คืน false ถ้าศัตรูมีชื่อนี้อยู่แล้ว — คู่มือเดิมเขียนว่าซ้อนทับ ซึ่งผิด) · ตอนนี้ส่ง `2` ตาม kit "for 2 turn(s)" ใช้ Elation Skill ซ้ำจะต่ออายุโดยไม่บวกค่าซ้ำ

ถอนใน `After_turn_List` ตอนจบเทิร์นของศัตรูตัวนั้นผ่าน `isDebuffEnd` · ชื่อ debuff มี prefix เจ้าของ → ผู้สวมหลายคนซ้อนกันได้ (kit ไม่ได้ห้าม)
