# Debuff Stats

## `debuffApply()` กับ `debuffMark()`

ทั้งสองเมธอดคืน `true` เฉพาะเมื่อลงดีบัฟชื่อดังกล่าวเป็นครั้งแรก และเมื่อมี `extend` จะอัปเดต `debuffEnd` แม้ดีบัฟนั้นมีอยู่แล้ว ความต่างจากโค้ดคือ `debuffApply()` ปล่อย `BeforeApplyDebuff` และ `AfterApplyDebuff` ทุกครั้งที่พยายามลง ส่วน `debuffMark()` ปล่อย event สองจังหวะนี้เฉพาะครั้งที่สร้างสถานะใหม่

เมื่อลงใหม่ ทั้งคู่ตั้ง flag ใน `debuffCheck` และเพิ่ม `Total_debuff` หนึ่งครั้ง ฟังก์ชันตระกูล `debuffSingleApply` / `debuffSingleMark` จึงปรับ stat เฉพาะเมื่อ helper คืน `true` เพื่อไม่ให้ลงค่าซ้ำตอนต่ออายุ

`extendDebuff()` เก็บเทิร์นหมดอายุเป็น `enemy->turnCnt + Turn_extend`; `isDebuffEnd()` ตรวจทั้งเทิร์นและชื่อศัตรูที่กำลังเดิน แล้วเรียก `debuffRemove()` เพื่อล้าง flag และลด `Total_debuff`

ใน `debuffSingleMark()` ดีบัฟความเร็วต้องถูกนำไปใช้กับ `enemy` ซึ่งเป็นเป้าหมายเสมอ ไม่ใช่ `ptr` ผู้แจกดีบัฟ เช่นเดียวกับ `debuffSingleApply()` และฟังก์ชันดีบัฟรูปแบบอื่น

## wrapper สำหรับค่าสถานะและหลายเป้าหมาย

`debuffSingle()` เพิ่มค่าจาก `BuffClass` ลง `Stats_type` ของศัตรู (กรณี `FLAT_SPD`/`SPD_P` เรียก `enemy->speedBuff()`) หรือเพิ่มค่าจาก `BuffElementClass` ลง `Stats_each_element` โดยตรง ไม่สร้างชื่อสถานะและไม่ตั้งวันหมดอายุ `debuffAllEnemy()` และ `debuffEnemyTargets()` เพียงวนเรียกฟังก์ชันนี้กับ `enemyList` หรือรายการเป้าหมายที่ส่งมา

ชุด `debuffSingleApply()` / `debuffAllEnemyApply()` / `debuffEnemyTargetsApply()` เรียก `debuffApply()` ก่อน ส่วนชุด `debuffSingleMark()` / `debuffAllEnemyMark()` / `debuffEnemyTargetsyMark()` เรียก `debuffMark()` ก่อน ทั้งหมดเพิ่มค่า stat ผ่าน `debuffSingle()` หรือขั้นตอนเดียวกันเฉพาะเมื่อ helper คืน `true` จึงไม่บวกค่าซ้ำเมื่อชื่อดีบัฟมีอยู่แล้ว overload ที่มี `extend` ส่งอายุไปให้ helper เพื่อสร้างหรือต่ออายุสถานะ การลงซ้ำยังมีความต่างด้าน event ระหว่าง Apply กับ Mark ตามหัวข้อแรก

`debuffEnemyTargetsyMark()` คือชื่อที่สะกดอยู่ในโค้ดปัจจุบัน (มี `sy`) และยังไม่พบผู้เรียกใน `src/Defination` ไม่ได้เปลี่ยนชื่อระหว่างสำรวจ

`weaknessApplyChoose()` จะ clamp `amount` ให้อยู่ระหว่าง 0 และจำนวนธาตุที่เลือกได้จริง เพื่อไม่ให้ configuration ที่ขอมากเกินไปหรือเป็นค่าติดลบทำให้เข้าถึงข้อมูลนอกขอบเขต

`weaknessApply()` เพิ่มธาตุใน `Weakness_type` และเพิ่ม `currentWeaknessElementAmount` เฉพาะเมื่อธาตุนั้นยังไม่เป็น Weakness; อายุรายธาตุใช้ค่าสูงสุดระหว่างวันหมดอายุเดิมกับ `turnCnt + extend` เพื่อไม่ให้การลงซ้ำตัดอายุให้สั้นลง overload ที่รับชื่อดีบัฟเพิ่ม flag/`Total_debuff` เฉพาะเมื่อลงชื่อใหม่และตั้งวันหมดอายุของดีบัฟ ส่วน overload ไม่มีชื่อจัดการเฉพาะ Weakness และ event ที่เกี่ยวข้อง

`weaknessApplyChoose()` สร้างตัวเลือกจากธาตุของตัวละครที่ศัตรูยังไม่อ่อนแอ แล้วเรียง priority; หากไม่มีตัวเลือกใหม่ จะหันไปใช้ธาตุใน `Weakness_typeCountdown` โดยเรียงตามเทิร์นหมดอายุ ก่อนเรียก `weaknessApply()` กับจำนวนที่ถูก clamp

## priority ของการเลือกธาตุ

User แก้ 2026-09-21: ย้าย `int i = 1` ออกมาหน้าลูป `for (each : charList)` แล้ว ทำให้ตัวละคร Path ที่ไม่ใช่ Harmony/Nihility/Abundance/Preservation ได้ priority ตามลำดับที่ผ่านการตรวจใน `charList` แทนที่จะเป็น 1 เท่ากันทุกคน `i` เพิ่มเฉพาะรายการที่ธาตุนั้นยังไม่เป็น Weakness ของศัตรู ส่วนสี่ Path ดังกล่าวยังใช้ priority คงที่สูงกว่า
