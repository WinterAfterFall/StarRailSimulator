# `src/Defination/Function/AdjustFunction/MainStatsRelic.h`

`setRelicMainStats()` กำหนด callback main stat ของ Body/Boot/Orb/Rope พร้อมกัน ส่วน `setBody`, `setBoot`, `setOrb`, `setRope` กำหนดแยกชิ้น ทั้งหมดสร้าง callback ผ่าน `RelicMainStatsSet()` และนำไปใช้ภายหลังระหว่าง reset

ค่าที่รองรับ: SPD 25, ATK/HP/EHR 43.2%, DEF 54%, CR 32.4%, CD/BE 64.8%, Healing 34.57%, DMG ธาตุประจำตัว 38.88% และ Energy Recharge 19.4%; ชนิดอื่นได้ callback ว่าง
