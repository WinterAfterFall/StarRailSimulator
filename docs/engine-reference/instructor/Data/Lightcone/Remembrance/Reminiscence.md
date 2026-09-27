# `src/Defination/Data/Lightcone/Remembrance/Reminiscence.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Reminiscence"` · base stats `SetAllyBaseStats(635, 423, 265)`

**base stats ต่ำสุดในโฟลเดอร์** (3★)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `SetAllyBaseStats(635, 423, 265)` | `Reminiscence.h:5` |
| ต้นเทิร์นของ memosprite → ผู้สวมและ memosprite DMG `7 + S` ต่อชั้น (สูงสุด 4) | `Before_turn_List` เจ้าของเทิร์นเป็น memosprite ของผู้สวม → `buffStackChar(…, 1, 4, "Reminiscence")` | `:16-18` |
| memosprite หายไป → ล้างทั้งกอง | ต้นเทิร์นถ้า memosprite ตาย → `buffCharResetStack` · และทันทีที่ตายผ่าน `AllyDeath_List` | `:9-14` · `:22-25` |

**ไม่มีสแตตติดตัว**

## จุดที่น่าสังเกต

เช็คสถานะ memosprite ก่อนแล้ว `return` ทันที → ลำดับนี้ทำให้ "ตายแล้วล้าง" ชนะ "ต้นเทิร์นแล้วสะสม" เสมอ

**ใช้ `buffStackChar` / `buffCharResetStack` คู่กันถูกต้อง** — ทั้งคู่เป็นตระกูล `...Char` · ต่างจาก `../Destruction/Danheng_LC.md` ที่ใช้คนละตระกูล

## จุดที่ควรระวัง

- ลูปเช็ค `e->Atv_stats->side == Side::Memosprite` ทั้งที่อ่านจาก `memosprite` อยู่แล้ว — เงื่อนไขซ้ำซ้อน
- ถ้าผู้สวมไม่ใช่ path Remembrance `memosprite` เป็น `nullptr` → `if` ข้ามไป ปลอดภัย

> **แก้ 2026-09-26 ตาม kit** ("removed ... when the memosprite disappears"): เดิมล้างเฉพาะตอน `Before_turn` → ช่วงระหว่าง memosprite ตายจนถึงเทิร์นถัดไปยังได้บัฟ · เพิ่ม `AllyDeath_List` ล้างทันที
