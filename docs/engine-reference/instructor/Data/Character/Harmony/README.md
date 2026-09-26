# `src/Defination/Data/Character/Harmony/`

ซัพพอร์ตทั้งหมด · 10 ไฟล์ (รวม `HanabiV1.h` ที่เป็นเวอร์ชันเก่า)

| ไฟล์ | บทบาท | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `Tingyun.h` | บัฟ ATK เป้าเดียว | **โครงพื้นฐานของทุกตัวละคร** · การจำผู้ถือบัฟด้วย `buffSubUnitTarget` |
| `Bronya.h` | advance + DMG | `Driver_num` · บัฟทีมที่ค่าต่างกันรายคน (`buffNote` ที่เป้าหมาย) |
| `Robin.h` | ATK ทีม + Concerto | `addUltCondition` หลายก้อนแยกตาม `driverType` · แก้ `baseSpeed` เพื่อหยุดเทิร์น · `All_Action_forward` |
| `Sunday.h` | CD เป้าเดียว + summon | `buffAllyTarget` — จำผู้ถือบัฟข้ามเวลา · บัฟที่ต้องลงถึง memosprite ทุกจุด |
| `Ruan_Mei.h` | Break support | `Turn_Skip` — ทำให้ศัตรูข้ามเทิร์น · `buffAllAllyExcludingBuffer` |
| `Hanabi.h` | SP economy | `Max_sp` · `Skill_point_List` เป็นแกนของ Talent |
| `Harmony_MC.h` | Super Break | Super Break ให้ทั้งทีม · `AType::TEMP` กันลูปสูตร BE→BE |
| `Cerydra.h` | บัฟ Skill ของเป้า | `AllyActionList` · copy action ทั้งก้อนเพื่อยิงซ้ำ |
| `Tribbie.h` | Zone + True DMG | `Cal_DamageNote` · `Char.Print_Func` |
| `HanabiV1.h` | (เวอร์ชันเก่า) | ดู `HanabiV1.md` |

## แบบแผนร่วมของกลุ่มนี้

**1. ซัพพอร์ตเกือบทุกตัวใช้ `AllyBuffAction` ไม่ใช่ `AllyAttackAction`** สำหรับ Skill/Ult ที่ไม่มีดาเมจ — ประกอบด้วย `addBuffSingleTarget()` / `addBuffAllAllies()` / `addBuffChar()` แล้ว `addToActionBar()`

**2. ปัญหาร่วม: บัฟลงกับถอนใช้คนละกลไก** — ลงด้วย `chooseAllyBuff(ptr)` สด แต่ถอนใน `After_turn_List` ด้วย `turn->canCastToAllyUnit()` (คนที่เพิ่งจบเทิร์น) · ถ้าเป้าหมายเปลี่ยนระหว่างนั้นจะไม่ตรงกัน · **ตัวที่แก้ถูกแล้ว**: `Tingyun.h` (`buffSubUnitTarget`), `Sunday.h` (`buffAllyTarget`) · **ตัวที่ยังเสี่ยง**: `Cerydra.h`, `Bronya.h`

**3. `Driver_num` ถูกเขียนโดย 3 ตัว** — `Bronya.h:20`, `Sunday.h:17`, `Hanabi.h:21` · ถ้ามีหลายตัวในทีมเดียวกัน ตัวที่ `Setup` ทีหลังชนะ

**4. บัฟ ult ที่ลงตอน `BeforeTurn` ของเพื่อนจะนับเทิร์นเกิน** — `Tingyun.h` แก้ด้วยการลด duration, `Bronya.h` แก้ด้วยการ `extendBuffTime` เพิ่ม · **สองวิธีกับปัญหาเดียวกัน**
