# `src/Defination/Data/Lightcone/Remembrance/SweatNowCryLess.h`

`namespace Remembrance_Lightcone` · `lightCone.name` = `"SweatNowCryLess"` · base stats `setAllyBaseStats(1058, 529, 198)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 529, 198)` | `SweatNowCryLess.h:5` |
| CR `10 + 2S` | บวกถาวร | `:9` |
| ขณะ memosprite อยู่สนาม → ผู้สวมและ memosprite DMG `21 + 3S` | ต้นทุกเทิร์นเช็คสถานะ memosprite · ลงด้วย `isHaveToAddBuff` / ถอนเมื่อไม่อยู่ ผ่าน flag `"SweatNowCryLess"` | `:13-22` |
| memosprite ตาย → ถอนทันที | `allyDeathList` | `:24-29` |

## รากฐาน: บัฟแบบ "ขณะที่ ... อยู่"

flag `buffCheck["SweatNowCryLess"]` บนผู้สวมบอกว่าบัฟลงอยู่หรือไม่ · `beforeTurnList` ของทุกเทิร์นเทียบกับสถานะ memosprite (มีและยังไม่ตาย) แล้วลงหรือถอนให้ตรง · `allyDeathList` ถอนทันทีเมื่อ memosprite ตาย ไม่ต้องรอเทิร์นถัดไป · อ่าน `ptr->memosprite.get()` แล้วเช็ค null ก่อน ผู้สวมที่ไม่ใช่ path Remembrance จึงไม่ crash

> **แก้ 2026-09-26 ตาม kit**: (1) DMG เดิม `20 + 4S` (24/28/32/36/40) → kit 24/27/30/33/36 = `21 + 3S` (2) เดิมลงครั้งเดียวแล้วค้างถาวรแม้ memosprite ตาย → ถอน/ลงตามสถานะ (3) เดิม `ptr->memosprite->isDeath()` ไม่เช็ค null → crash ถ้าผู้สวมไม่มี memosprite
