# `src/Defination/Function/Combat/Debuff_Stats.h`

ไฟล์นี้คือฐานของระบบดีบัฟทั้งหมด แบ่งเป็น 4 กลุ่ม: **กลุ่มสถานะ** (`debuffApply` `debuffMark` `debuffRemove` `isDebuffEnd`) · **กลุ่มอายุ** (`extendDebuff` + wrapper) · **กลุ่ม Weakness** (`weaknessApply` `weaknessApplyChoose`) · **กลุ่มบวกค่า** (`debuffSingle` + wrapper กระจายเป้าหมายอีกสิบกว่าตัว)

เส้นแบ่งที่สำคัญที่สุดคือ **"ชื่อสถานะ" กับ "ค่า stat" เป็นคนละเรื่องกัน** — ฟังก์ชันตระกูล `debuffSingle()` บวกค่าอย่างเดียวไม่สร้างชื่อ ส่วน `debuffApply()`/`debuffMark()` สร้างชื่ออย่างเดียวไม่บวกค่า ตัวที่ผู้ใช้เรียกจริง (`debuffSingleApply` ฯลฯ) คือการเอาสองอย่างมาต่อกัน

## `debuffApply()` กับ `debuffMark()`

ทั้งสองเมธอดคืน `true` เฉพาะเมื่อลงดีบัฟชื่อดังกล่าวเป็นครั้งแรก และเมื่อมี `extend` จะอัปเดต `debuffEnd` แม้ดีบัฟนั้นมีอยู่แล้ว ความต่างจากโค้ดคือ `debuffApply()` ปล่อย `BeforeApplyDebuff` และ `AfterApplyDebuff` ทุกครั้งที่พยายามลง ส่วน `debuffMark()` ปล่อย event สองจังหวะนี้เฉพาะครั้งที่สร้างสถานะใหม่

เมื่อลงใหม่ ทั้งคู่ตั้ง flag ใน `debuffCheck` และเพิ่ม `Total_debuff` หนึ่งครั้ง ฟังก์ชันตระกูล `debuffSingleApply` / `debuffSingleMark` จึงปรับ stat เฉพาะเมื่อ helper คืน `true` เพื่อไม่ให้ลงค่าซ้ำตอนต่ออายุ

`extendDebuff()` เก็บเทิร์นหมดอายุเป็น `enemy->turnCnt + Turn_extend`; `isDebuffEnd()` ตรวจทั้งเทิร์นและชื่อศัตรูที่กำลังเดิน แล้วเรียก `debuffRemove()` เพื่อล้าง flag และลด `Total_debuff`

ใน `debuffSingleMark()` ดีบัฟความเร็วต้องถูกนำไปใช้กับ `enemy` ซึ่งเป็นเป้าหมายเสมอ ไม่ใช่ `ptr` ผู้แจกดีบัฟ เช่นเดียวกับ `debuffSingleApply()` และฟังก์ชันดีบัฟรูปแบบอื่น

## กลุ่มอายุดีบัฟ — `extendDebuff` และ wrapper (บรรทัด 62–75)

| ฟังก์ชัน | ทำอะไร |
|---|---|
| `extendDebuff(Enemy*, name, turns)` | **เขียนทับ** `debuffEnd[name] = enemy->turnCnt + turns` |
| `extendDebuffAll(name, turns)` | วน `enemyList` เรียก `extendDebuff()` ทุกตัว |
| `extendDebuffTargets(vector<Enemy*>, name, turns)` | เรียกเฉพาะเป้าหมายที่ส่งมา |

⚠️ สองจุดที่ต่างจากสัญชาตญาณ:

- **เขียนทับ ไม่ใช่บวกเพิ่ม** — ต่ออายุซ้ำขณะเหลือ 3 เทิร์นด้วย `extend = 2` จะเหลือ **2** เทิร์น ไม่ใช่ 5 (ต่างจาก `weaknessApply()` ที่เลือกค่าสูงสุดระหว่างของเดิมกับของใหม่)
- **อิง `turnCnt` ของศัตรูเจ้าของดีบัฟ** ไม่ใช่ของผู้แจก — ศัตรูที่เร็วกว่าจึงกินอายุดีบัฟเร็วกว่า และ `isDebuffEnd()` ก็เช็คเฉพาะตอนถึงเทิร์นของศัตรูตัวนั้น
- ทั้งสอง wrapper **ไม่สนว่าศัตรูมีดีบัฟชื่อนั้นอยู่จริงไหม** — เขียน `debuffEnd` ให้ทุกตัวที่วนถึง ถ้าไม่เคยมีสถานะนั้นก็แค่มี entry ค้างไว้เฉย ๆ ไม่มีผลจนกว่าจะมีคนลงสถานะชื่อเดียวกัน

## wrapper สำหรับค่าสถานะและหลายเป้าหมาย

`debuffSingle()` เพิ่มค่าจาก `BuffClass` ลง `Stats_type` ของศัตรู (กรณี `FLAT_SPD`/`SPD_P` เรียก `enemy->speedBuff()`) หรือเพิ่มค่าจาก `BuffElementClass` ลง `Stats_each_element` โดยตรง ไม่สร้างชื่อสถานะและไม่ตั้งวันหมดอายุ `debuffAllEnemy()` และ `debuffEnemyTargets()` เพียงวนเรียกฟังก์ชันนี้กับ `enemyList` หรือรายการเป้าหมายที่ส่งมา

ชุด `debuffSingleApply()` / `debuffAllEnemyApply()` / `debuffEnemyTargetsApply()` เรียก `debuffApply()` ก่อน ส่วนชุด `debuffSingleMark()` / `debuffAllEnemyMark()` / `debuffEnemyTargetsyMark()` เรียก `debuffMark()` ก่อน ทั้งหมดเพิ่มค่า stat ผ่าน `debuffSingle()` หรือขั้นตอนเดียวกันเฉพาะเมื่อ helper คืน `true` จึงไม่บวกค่าซ้ำเมื่อชื่อดีบัฟมีอยู่แล้ว overload ที่มี `extend` ส่งอายุไปให้ helper เพื่อสร้างหรือต่ออายุสถานะ การลงซ้ำยังมีความต่างด้าน event ระหว่าง Apply กับ Mark ตามหัวข้อแรก

⚠️ **ลำดับพารามิเตอร์ไม่เหมือนกันระหว่างสองชุด** — ฝั่ง Apply ขึ้นต้นด้วย `AllyUnit *ptr` (`debuffAllEnemyApply(ptr, debuffSet, name)`) แต่ฝั่ง Mark เอา `debuffSet` ขึ้นก่อน (`debuffAllEnemyMark(debuffSet, ptr, name)`) เวลาเขียนตัวละครใหม่ต้องดูลายเซ็นทุกครั้ง

`debuffEnemyTargetsyMark()` คือชื่อที่สะกดอยู่ในโค้ดปัจจุบัน (มี `sy`) และยังไม่พบผู้เรียกใน `src/Defination` ไม่ได้เปลี่ยนชื่อระหว่างสำรวจ

`weaknessApplyChoose()` จะ clamp `amount` ให้อยู่ระหว่าง 0 และจำนวนธาตุที่เลือกได้จริง เพื่อไม่ให้ configuration ที่ขอมากเกินไปหรือเป็นค่าติดลบทำให้เข้าถึงข้อมูลนอกขอบเขต

`weaknessApply()` เพิ่มธาตุใน `Weakness_type` และเพิ่ม `currentWeaknessElementAmount` เฉพาะเมื่อธาตุนั้นยังไม่เป็น Weakness; อายุรายธาตุใช้ค่าสูงสุดระหว่างวันหมดอายุเดิมกับ `turnCnt + extend` เพื่อไม่ให้การลงซ้ำตัดอายุให้สั้นลง overload ที่รับชื่อดีบัฟเพิ่ม flag/`Total_debuff` เฉพาะเมื่อลงชื่อใหม่และตั้งวันหมดอายุของดีบัฟ ส่วน overload ไม่มีชื่อจัดการเฉพาะ Weakness และ event ที่เกี่ยวข้อง

`weaknessApplyChoose()` สร้างตัวเลือกจากธาตุของตัวละครที่ศัตรูยังไม่อ่อนแอ แล้วเรียง priority; หากไม่มีตัวเลือกใหม่ จะหันไปใช้ธาตุใน `Weakness_typeCountdown` โดยเรียงตามเทิร์นหมดอายุ ก่อนเรียก `weaknessApply()` กับจำนวนที่ถูก clamp

## priority ของการเลือกธาตุ

User แก้ 2026-09-21: ย้าย `int i = 1` ออกมาหน้าลูป `for (each : charList)` แล้ว ทำให้ตัวละคร Path ที่ไม่ใช่ Harmony/Nihility/Abundance/Preservation ได้ priority ตามลำดับที่ผ่านการตรวจใน `charList` แทนที่จะเป็น 1 เท่ากันทุกคน `i` เพิ่มเฉพาะรายการที่ธาตุนั้นยังไม่เป็น Weakness ของศัตรู ส่วนสี่ Path ดังกล่าวยังใช้ priority คงที่สูงกว่า

## ที่อธิบายไว้ไฟล์อื่น

- เส้นทาง stack ของดีบัฟ (`calDebuffStack` `debuffStackSingle` …) → [DebuffStack.md](DebuffStack.md)
- ตัวนับชนิด DoT ที่ซ้อนอยู่บนระบบนี้ → [Dot.md](Dot.md)
- `debuffCheck` `debuffEnd` `Total_debuff` `Weakness_type` ในฐานะ field → [Enemy.md](../../Class/Unit/Enemy.md)
- ⚠️ `isDebuffEnd()` **ไม่มีผู้เรียกในชั้น engine เลย** — ผู้เรียกทั้งหมดอยู่ใน `src/Defination/Data/Character/…` (Gallagher, FireFly, Mydei, Black Swan ฯลฯ) แปลว่าดีบัฟไม่ได้หมดอายุเองโดยอัตโนมัติ ตัวละครที่แจกต้องเช็คเอง · ส่วนการหมดอายุอัตโนมัติที่ engine ทำให้มีเฉพาะ Break DoT / Entanglement / Imprisonment / Weakness ชั่วคราว → [Event.md](../Event/Event.md)
