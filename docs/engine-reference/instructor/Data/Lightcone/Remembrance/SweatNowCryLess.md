# `src/Defination/Data/Lightcone/Remembrance/SweatNowCryLess.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"SweatNowCryLess"` · base stats `SetAllyBaseStats(1058, 529, 198)`

| ท่อน | โค้ด |
|---|---|
| CR `10 + 2S` | `Reset_List` |
| memosprite อยู่บนสนาม → ผู้สวมและ memosprite DMG `21 + 3S` | `Before_turn_List` ลง/ถอนตามสถานะ memosprite |
| memosprite ตาย → ถอนทันที | `AllyDeath_List` |

## รากฐาน: บัฟแบบ "ขณะที่ ... อยู่"

flag `buffCheck["SweatNowCryLess"]` บนผู้สวมบอกว่าบัฟลงอยู่หรือไม่ · `Before_turn_List` ของทุกเทิร์นเทียบกับสถานะ memosprite (มีและยังไม่ตาย) แล้วลงหรือถอนให้ตรง · `AllyDeath_List` ถอนทันทีเมื่อ memosprite ตาย ไม่ต้องรอเทิร์นถัดไป · อ่าน `ptr->memosprite.get()` แล้วเช็ค null ก่อน ผู้สวมที่ไม่ใช่ path Remembrance จึงไม่ crash

> **แก้ 2026-09-26 ตาม kit**: (1) DMG เดิม `20 + 4S` (24/28/32/36/40) → kit 24/27/30/33/36 = `21 + 3S` (2) เดิมลงครั้งเดียวแล้วค้างถาวรแม้ memosprite ตาย → ถอน/ลงตามสถานะ (3) เดิม `ptr->memosprite->isDeath()` ไม่เช็ค null → crash ถ้าผู้สวมไม่มี memosprite
