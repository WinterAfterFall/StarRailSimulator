# `src/Defination/Function/Setup/SetEnemy.h`

## `createNewEnemy()`

สร้าง `Enemy` ใหม่ เพิ่ม `Total_enemy` แล้วผูก object เดียวกันเข้า `enemyUnit`, `enemyList` และ `atvList`; จากนั้นกำหนด SPD, toughness สูงสุด, `EnemyType`, index, ชื่อ `Enemy-N`, ฝั่ง `Enemy` และ back-reference `charptr`

ตำแหน่งเพื่อนบ้านถูกต่อเป็นลำดับ `5 ↔ 3 ↔ 1 ↔ 2 ↔ 4` เมื่อสร้างถึงห้าตัว โดย enemy 1 อยู่กลาง แล้ว 2/3 เป็นข้างเคียงชั้นแรกและ 4/5 เป็นชั้นถัดไป

## `SetupEnemy()`

พารามิเตอร์คู่ใช้สมาชิก `first` / `second` สำหรับ single-target / AoE ตามลำดับ:

- `energy`: energy ที่เป้าหมายได้รับเมื่อโดนโจมตี
- `skillRatio`: ตัวคูณดาเมจของศัตรู
- `attackCooldown`: `AoeStart` / `AoeCoolDown`

`action` คือจำนวน sub-action ต่อหนึ่งเทิร์นของศัตรู แต่ละ sub-action เพิ่ม `AoeCharge`; เลือก AoE เมื่อ cooldown และ ratio ของ AoE ไม่เป็นศูนย์ และ `AoeCharge % AoeCoolDown == AoeStart` นอกนั้นใช้ basic attack

ถ้าศัตรูเริ่มเทิร์นขณะ toughness แตก ฟังก์ชันจะคืนสถานะและ toughness เต็ม พร้อมสะสมช่วงเวลาที่แตกลง `Total_toughness_broken_time` ก่อนทำ sub-action

ตอน setup จะคัดลอก `Enemy_weak` ลงทั้ง weakness ปัจจุบันและค่า default, นับจำนวน weakness ที่เปิดไว้ และคัดลอก `Enemy_res` ลงค่า RES เริ่มต้น

## Declaration mismatch

แก้ 2026-09-21: declaration เดิมรับ `string type` แต่ definition และทุก caller ใช้ `EnemyType` ทำให้ผู้ที่ include declaration ได้ signature คนละตัวกับ implementation แก้ declaration ของทั้ง `createNewEnemy()` และ `SetupEnemy()` เป็น `EnemyType` และเพิ่ม compile regression test `test/set_enemy_declaration_regression.cpp`
