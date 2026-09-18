# `src/Defination/Class/ActionData/ActionData.h`

## ชื่อแอ็กชัน

`ActionData` เก็บ `actionName` โดยมี `getActionName()` สำหรับอ่าน และ `setActionName(string)` สำหรับตั้งค่า

User ขอแก้ชื่อ setter จาก `getActionName(string)` เป็น `setActionName(string)` วันที่ 2026-09-17; commit และ push แล้วที่ `c216187` ตรวจไม่พบจุดเรียกที่ต้องแก้ และตรวจ syntax ผ่าน

## Helpers แปลงชนิดแอ็กชัน

User ยืนยัน 2026-09-17: ทำเป็นทางลัดเพื่อไม่ต้องเขียน `dynamic_cast` ซ้ำที่จุดเรียกใช้

- `ActionData::castToAllyActionData()` / `castToEnemyActionData()`
- `AllyActionData::castToAllyAttackAction()` / `castToAllyBuffAction()`

ทุกตัวใช้ `dynamic_cast` กับ `this` เพื่อเข้าถึง object เดิมผ่านชนิดที่เฉพาะขึ้น หากชนิดไม่ตรงคืน `nullptr` ไม่ได้สร้าง object ใหม่

## `PointerWithValue`

จากโค้ด: เก็บ `AllyUnit* ptr` คู่กับ `double value`; `Less_cmp` เปรียบเทียบด้วย `<` และ `Greater_cmp` ด้วย `>` การนำไปจัดลำดับเป้าหมายฮีลมีบันทึกแล้วใน [ChangeHP.md](../../Function/Combat/ChangeHP.md) ไม่ต้องเริ่มถามกลไกฮีลนี้ใหม่
