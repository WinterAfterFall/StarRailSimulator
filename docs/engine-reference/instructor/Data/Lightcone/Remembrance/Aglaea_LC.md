# `src/Defination/Data/Lightcone/Remembrance/Aglaea_LC.h`

`namespace Remembrance_Lightcone` · `lightCone.name` = `"Aglaea_LC"` · base stats `setAllyBaseStats(1058, 635, 397)`

**signature ของ Aglaea** (ดู `../../Character/Remembrance/Aglaea.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 635, 397)` | `Aglaea_LC.h:5` |
| SPD `10 + 2S` (ค่าคงที่) | บวก `baseSpeed` ตรง ๆ ตอน setup | `:7` |
| ผู้สวมหรือ memosprite โจมตี → CD `7.5 + 1.5S` ต่อชั้น (สูงสุด 6) ให้ทั้งคู่ | `whenAttackList` guard `isSameOwnerName` · นับ `stack["Aglaea_LC_stack"]` · `buffSingleChar` · ไม่มีอายุ | `:8-18` (CD `:11`) |
| ครบ 6 ชั้น → Basic ATK DMG `6 × (7.5 + 1.5S)` | ลงครั้งเดียวตอนถึง 6 | `:13-15` |

## จุดที่น่าสังเกต

**เป็น LC ใบที่สองที่แก้ `baseSpeed`** (อีกใบคือ `../Destruction/Phainon LC.md`) — ทำตอน setup ก่อนการต่อสู้เริ่ม จึงไม่ต้องเรียก `updateMaxAtv`

**นับ stack เองด้วย `ptr->stack[...]` แทน `buffStackSingle`** — เพราะต้องรู้ว่าถึง 6 พอดีเมื่อไหร่เพื่อให้บัฟก้อนใหญ่ · `buffStackSingle` ไม่บอกว่าเต็มแล้ว (ต้องใช้ `calStack` ที่คืน `pair`)

**ไม่มีการถอน** — CD และ BA DMG สะสมแล้วอยู่ถาวร ถูกต้องตาม kit

## จุดที่ควรระวัง

- **guard ด้วย `act->isSameOwnerName(ptr)`** → นับทั้งผู้สวมและ memosprite ของผู้สวม ตาม kit "After the wearer **and the wearer's memosprite** attacks" · **แก้ 2026-09-26** (user สั่ง): เดิมเทียบเลขช่อง `act->attacker->atvStats->num == ptr->atvStats->num` ซึ่งได้ผลเดียวกันเพราะ memosprite ใช้เลขช่องของเจ้าของ (`Class/Unit/StatsSet.h:45`) แต่ countdown ก็ใช้เลขช่องเดียวกันด้วย จึงเปลี่ยนมาเช็คเจ้าของตรง ๆ
- ค่าทุกตัวตรง kit (`baseSpeed` 12–20, CD 9–15 ต่อ stack, BA DMG ต่อ stack เมื่อครบ 6) และ stack ถาวรตาม kit (ไม่มี duration)
