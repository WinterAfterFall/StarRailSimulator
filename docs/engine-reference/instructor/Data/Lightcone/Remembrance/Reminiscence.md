# `src/Defination/Data/Lightcone/Remembrance/Reminiscence.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Reminiscence"` · base stats `SetAllyBaseStats(635, 423, 265)`

**base stats ต่ำสุดในโฟลเดอร์** (3★)

| ท่อน | โค้ด |
|---|---|
| memosprite ของผู้สวมตาย → ล้าง stack ทั้งหมด | `Before_turn_List` → `buffCharResetStack` |
| ต้นเทิร์นของ memosprite → DMG stack `7 + S` (cap 4) | `buffStackChar(..., 1, 4, "Reminiscence")` |

**ไม่มีสแตตติดตัว**

## จุดที่น่าสังเกต

เช็คสถานะ memosprite ก่อนแล้ว `return` ทันที → ลำดับนี้ทำให้ "ตายแล้วล้าง" ชนะ "ต้นเทิร์นแล้วสะสม" เสมอ

**ใช้ `buffStackChar` / `buffCharResetStack` คู่กันถูกต้อง** — ทั้งคู่เป็นตระกูล `...Char` · ต่างจาก `../Destruction/Danheng_LC.md` ที่ใช้คนละตระกูล

## จุดที่ควรระวัง

- ลูปเช็ค `e->Atv_stats->side == Side::Memosprite` ทั้งที่อ่านจาก `memosprite` อยู่แล้ว — เงื่อนไขซ้ำซ้อน
- ถ้าผู้สวมไม่ใช่ path Remembrance `memosprite` เป็น `nullptr` → `if` ข้ามไป ปลอดภัย
