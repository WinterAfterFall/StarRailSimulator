# `src/Defination/Function/Combat/EnemyCombat.h`

`Enemy::aoeAttack()` และ `baAttack()` สร้าง `EnemyActionData`, ตั้งรายละเอียดโจมตีด้วย `setAoeAttack()` / `setBaAttack()` แล้วส่งเข้า `actionBar` จึงยังไม่ประมวลผลการโจมตีตรงจุดเรียกนี้

`addTaunt()` เพิ่ม ally เข้า `tauntList` หากยังไม่มีชื่อเดียวกัน; `removeTaunt()` ลบตัวแรกที่ชื่อเดียวกันแล้วหยุด พฤติกรรมเลือกเป้าของ basic attack เมื่อมี `tauntList` อธิบายใน [EnemyActionData.md](../../Class/ActionData/EnemyActionData.md)

ท้ายไฟล์มี `EnemyHit` / `DamageFormEnemy` รุ่นเก่าที่ถูก comment ไว้ ไม่ใช่เส้นทางที่รันปัจจุบัน
