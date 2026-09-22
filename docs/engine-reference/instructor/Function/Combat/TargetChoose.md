# `src/Defination/Function/Combat/TargetChoose.h`

จากโค้ด:

- `canCastToAllyUnit()` / `canCastToEnemy()` (บน `ActionValueStats`) และ `canCastToSubUnit()` / `canCastToEnemy()` (บน `Unit`) — ทางลัด `dynamic_cast` คืน `nullptr` ถ้าชนิดไม่ตรง
- `chooseAllyBuff(ptr)` — คืนเป้าบัฟเดี่ยวที่ `ptr` เลือกไว้: `currentMemoNum == 0` → ตัวละคร `charUnit[currentCharNum]`, `1..N` → memosprite ลำดับที่ระบุ (`currentMemoNum - 1` เป็น index) ดูกติกาใน [CharUnit.md](../../Class/Unit/CharUnit.md)
- `chooseCharacterBuff(ptr)` — คืนตัวละคร `charUnit[currentCharNum]` เสมอ (ไม่เลือก memosprite)
- `chooseEnemyTarget(ptr)` — คืน `enemyUnit[Enemy_target_num]`

ฟังก์ชันเลือกเป้าหมายมี bounds guard แล้ว: `ptr` ว่างหรือ `currentCharNum` / `Enemy_target_num` อยู่นอกขอบเขตจะคืน `nullptr`; สำหรับ `chooseAllyBuff()` ถ้า `currentMemoNum` ไม่ใช่ 0 แต่ index memosprite ไม่ถูกต้อง จะคืนตัวละครเจ้าของแทน
