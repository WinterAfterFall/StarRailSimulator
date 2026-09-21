# DoT

ฟังก์ชัน `dotEnemyTargetsStack(..., extend)` ต้องส่งค่า `extend` ต่อให้ `dotSingleStack()` ของทุกเป้าหมาย เพื่อให้ DoT แบบเพิ่ม stack พร้อมต่ออายุทำงานเหมือนกับการใช้กับศัตรูทั้งหมด

เส้นทาง stack ของ DoT ใช้ `calDebuffStack()` เช่นเดียวกับดีบัฟทั่วไป จึงจำกัด stack อยู่ระหว่าง `0` และ `StackLimit` และใช้จำนวน stack ที่เปลี่ยนจริงเมื่อรับค่าเพิ่มหรือลด

## การเพิ่มและลบสถานะ

`dotSingleApply()` กับ `dotSingleMark()` เรียก `debuffApply()` / `debuffMark()` ก่อน แล้วเพิ่มตัวนับชนิด DoT ผ่าน `changeDotType(type, +1)` เฉพาะเมื่อเป็นสถานะใหม่; การแปะซ้ำจึงไม่เพิ่มตัวนับอีก overload ที่รับ `extend` ต่ออายุผ่านฝั่ง debuff ก่อนตรวจว่าเป็นสถานะใหม่

`dotSingleStack()` เทียบ stack เดิมกับค่าใหม่หลัง clamp: เพิ่มตัวนับชนิด DoT เมื่อเปลี่ยนจาก 0 เป็นบวก และลดเมื่อเปลี่ยนจากบวกเป็น 0; กรณี 0 → 0 ไม่เปลี่ยน `DotCount` หรือตัวนับรายชนิด (user ยืนยัน 2026-09-21) จากนั้นเรียก `calDebuffStack()` เพื่ออัปเดต stack และ `Total_debuff` โดยยังอัปเดตตัวนับชนิดก่อน `AfterApplyDebuff` เพื่อรักษาจังหวะที่ Light Cone ของ Black Swan ใช้ตรวจ `ShockCount` overload ที่รับ `extend` เรียก `extendDebuff()` หลังคำนวณ stack

`dotRemove()` ลดตัวนับชนิด DoT ตามรายการชนิดที่ส่งมา ส่วน `dotStackRemove()` ตั้ง stack ของสถานะชื่อที่ระบุเป็นศูนย์ผ่าน `debuffRemoveStack()` แล้วลดตัวนับชนิด DoT และคืนจำนวน stack ก่อนลบ ทั้งสองเมธอดไม่ลบ debuff flag หรือลด `Total_debuff` ด้วยตนเอง; ผู้เรียกจัดการอายุ debuff แยกต่างหาก

ฟังก์ชัน `dotAllEnemy*()` วน `enemyList`; `dotEnemyTargets*()` วนเฉพาะ vector เป้าหมายที่ส่งมา โดยส่งต่อไปยังเมธอด `dotSingle*()` ที่สอดคล้องกัน
