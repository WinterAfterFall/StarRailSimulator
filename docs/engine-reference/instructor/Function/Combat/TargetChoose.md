# `src/Defination/Function/Combat/TargetChoose.h`

จากโค้ด:

- `canCastToAllyUnit()` / `canCastToEnemy()` (บน `ActionValueStats`) และ `canCastToSubUnit()` / `canCastToEnemy()` (บน `Unit`) — ทางลัด `dynamic_cast` คืน `nullptr` ถ้าชนิดไม่ตรง
- `chooseAllyBuff(ptr)` — คืนเป้าบัฟเดี่ยวที่ `ptr` เลือกไว้: `currentMemoNum == 0` → ตัวละคร `charUnit[currentCharNum]`, `1..N` → memosprite ลำดับที่ N (index `-1`) ดูกติกาใน [CharUnit.md](../../Class/Unit/CharUnit.md)
- `chooseCharacterBuff(ptr)` — คืนตัวละคร `charUnit[currentCharNum]` เสมอ (ไม่เลือก memosprite)
- `chooseEnemyTarget(ptr)` — คืน `enemyUnit[Enemy_target_num]`

ฟังก์ชันเลือกเป้าหมายมี bounds guard แล้ว: index ที่อยู่นอกขอบเขตจะคืน `nullptr` และ memosprite index ที่ไม่ถูกต้องจะ fallback กลับไปยังตัวละครเจ้าของ แทนการเข้าถึง vector นอกขอบเขต
