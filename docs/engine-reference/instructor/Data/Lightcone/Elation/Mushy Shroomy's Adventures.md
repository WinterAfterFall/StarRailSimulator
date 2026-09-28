# `src/Defination/Data/Lightcone/Elation/Mushy Shroomy's Adventures.h`

`namespace Elation_Lightcone` · `lightCone.name` = `"Mushy Shroomy's Adventures"` · base stats `setAllyBaseStats(847, 476, 397)`

ฟังก์ชันชื่อ `MushyShroomy`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(847, 476, 397)` | `Mushy Shroomy's Adventures.h:5` |
| Elation `10 + 2S` | บวกถาวร | `:10` |
| ผู้สวมใช้ Elation Skill → ศัตรูทุกตัวรับ Elation DMG +`5 + S`% นาน 2 เทิร์น | `whenUseElationSkillList` (เฉพาะ `ally == ptr`) → `debuffAllEnemyApply` ชื่อ debuff ขึ้นต้นด้วยชื่อผู้สวม (`:7`) | `:14-18` |
| ถอนเมื่อหมดอายุ | ท้ายเทิร์นศัตรู `isDebuffEnd` | `:20-26` |

ชื่อ debuff prefix ด้วยชื่อเจ้าของ (`ptr->getName() + " MushyShroomy Debuff"`)

## จุดที่ควรระวัง

> **แก้ 2026-09-28** (user สั่ง): เดิมใช้ `beforeAllyActionList` + `isSameAction(ptr, ELATION_SKILL)` → ใน Aha Instant event นี้ยิงครั้งเดียวด้วย action ตัวแรกเป็นตัวแทน จึงติดเฉพาะเมื่อผู้สวมอยู่หัวคิว · ตอนนี้ใช้ `whenUseElationSkillList` ที่ยิงแยกทุกตัวละคร (ดู `../../../Function/Event/Event.md`)

> **แก้ 2026-09-26**: เดิม `debuffAllEnemyApply` ไม่ได้ส่ง duration → `debuffEnd` ไม่ถูกตั้ง `isDebuffEnd` แทบไม่เคยจริง → **VUL ค้างถาวร** (ไม่ซ้อน เพราะ `debuffApply` คืน false ถ้าศัตรูมีชื่อนี้อยู่แล้ว — คู่มือเดิมเขียนว่าซ้อนทับ ซึ่งผิด) · ตอนนี้ส่ง `2` ตาม kit "for 2 turn(s)" ใช้ Elation Skill ซ้ำจะต่ออายุโดยไม่บวกค่าซ้ำ

ถอนใน `afterTurnList` ตอนจบเทิร์นของศัตรูตัวนั้นผ่าน `isDebuffEnd` · ชื่อ debuff มี prefix เจ้าของ → ผู้สวมหลายคนซ้อนกันได้ (kit ไม่ได้ห้าม)
