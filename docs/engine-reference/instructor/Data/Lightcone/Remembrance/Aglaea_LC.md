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

**ไม่มีการถอน** — CD และ BA DMG สะสมแล้วอยู่ถาวร ถูกต้องตาม kit

## จุดที่ควรระวัง

- **guard ด้วย `act->isSameOwnerName(ptr)`** → นับทั้งผู้สวมและ memosprite ของผู้สวม ตาม kit "After the wearer **and the wearer's memosprite** attacks" · **แก้ 2026-09-26** (user สั่ง): เดิมเทียบเลขช่อง `act->Attacker->Atv_stats->num == ptr->Atv_stats->num` ซึ่งได้ผลเดียวกันเพราะ memosprite ใช้เลขช่องของเจ้าของ (`Class/Unit/StatsSet.h:45`) แต่ countdown ก็ใช้เลขช่องเดียวกันด้วย จึงเปลี่ยนมาเช็คเจ้าของตรง ๆ
- ค่าทุกตัวตรง kit (`baseSpeed` 12–20, CD 9–15 ต่อ stack, BA DMG ต่อ stack เมื่อครบ 6) และ stack ถาวรตาม kit (ไม่มี duration)
