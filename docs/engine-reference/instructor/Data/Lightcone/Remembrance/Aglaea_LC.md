# `src/Defination/Data/Lightcone/Remembrance/Aglaea_LC.h`

`namespace Remembrance_Lightcone` · `Light_cone.Name` = `"Aglaea_LC"` · base stats `SetAllyBaseStats(1058, 635, 397)`

**signature ของ Aglaea** (ดู `../../Character/Remembrance/Aglaea.md`)

| ท่อน | โค้ด |
|---|---|
| **`baseSpeed += 10 + 2S`** | เขียนตรงใน lambda ตอน `Setup` |
| โจมตี → CD `7.5 + 1.5S` (cap 6 stack) | `When_attack_List` + `stack["Aglaea_LC_stack"]` |
| ครบ 6 stack → BA DMG `6 × (7.5 + 1.5S)` | เงื่อนไขในบล็อกเดียวกัน |

## จุดที่น่าสังเกต

**เป็น LC ใบที่สองที่แก้ `baseSpeed`** (อีกใบคือ `../Destruction/Phainon LC.md`) — ทำตอน setup ก่อนการต่อสู้เริ่ม จึงไม่ต้องเรียก `Update_Max_atv`

**นับ stack เองด้วย `ptr->stack[...]` แทน `buffStackSingle`** — เพราะต้องรู้ว่าถึง 6 พอดีเมื่อไหร่เพื่อให้บัฟก้อนใหญ่ · `buffStackSingle` ไม่บอกว่าเต็มแล้ว (ต้องใช้ `calStack` ที่คืน `pair`)

**ไม่มีการถอน** — CD และ BA DMG สะสมแล้วอยู่ถาวร

## จุดที่ควรระวัง

- **guard ด้วย `act->Attacker->Atv_stats->num == ptr->Atv_stats->num`** (เทียบเลขช่อง) → memosprite ที่ใช้เลขช่องเดียวกับเจ้าของก็นับด้วย ซึ่งน่าจะเป็นเจตนา แต่ไม่ชัดเจนจากโค้ด
