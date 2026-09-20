# Event

เมื่อหมดอายุ Break DoT ระบบต้องอ่าน `BreakSEType` ก่อนลบรายการออกจาก `breakDotList` เพราะ iterator หลัง `erase()` จะชี้ไปยังรายการถัดไปหรือ `end()` แล้ว การลด counter ของ Burn/Shock/WindShear/Bleed จึงอ้างอิงชนิดของรายการที่ถูกลบจริง
