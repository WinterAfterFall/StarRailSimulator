# `src/Defination/Function/AdjustFunction/FormulaCheck.h`

## CalCheck — สวิตช์ debug สูตรดาเมจ (~35 bool)

field `check*` ทั้งกองอยู่ที่ `CharUnit.h:65-98` · นิยาม method ทั้งหมดอยู่ที่ `FormulaCheck.h` · enum `DmgFormulaMode` อยู่ที่ `Enum/CheckMode.h`

### โครงสร้าง 3 ชั้น

เปิดด้วย `enableCheckDamageFormula(DmgFormulaMode mode)` ซึ่งทำ 2 อย่าง — เปิด `checkDmgFormula` (**สวิตช์แม่**, ใช้เป็นเกตรวมใน `CalDamage.h`) แล้วเปิด flag ย่อยตาม `mode` อีก 1 ตัว

ฝั่งโค้ดคำนวณไม่ได้อ่าน field ตรง ๆ แต่เรียก `canCheckDmgformulaXxx()` ซึ่งรวม flag ให้:

| ระดับ | flag | คลุมอะไร |
|---|---|---|
| ทั้งหมด | `checkDmgFormulaAll` | ทุกอย่าง |
| กลุ่ม | `checkDmgFormulaSrc` | ที่มาของ Base DMG → HP + ATK + DEF + Const · (`canCheckDmgformulaMtpr()` = union ของกลุ่มนี้) |
| กลุ่ม | `checkDmgFormulaCrit` | CritRate + CritDam |
| เดี่ยว | `Dmg` `DefShred` `Respen` `Vul` `Mtgt` `MtprInc` `BE` `SpbInc` `PL` `MM` `Elation` | ตัวใครตัวมัน |

### ถอดตัวย่อ

| ย่อ | เต็ม | stat bucket |
|---|---|---|
| `Mtgt` | **Mitigation** (DMG Mitigation Mult, สูตร §10.1) | `Stats::Mitigration` ⚠️ สะกดผิดในโค้ด |
| `MtprInc` | **Multiplier Increase** | `Stats::MtprInc` |
| `SpbInc` | Super Break DMG increase | `Stats::SPB_inc` |
| `MM` | Merrymake | `Stats::Merrymake` |
| `PL` / `CB` | Punchline / Certified Banger | `punchline` (global) / `Stats::CertifiedBanger` |

> ⚠️ `DmgFormulaMode::CB` ไปเปิด flag ชื่อ `checkDmgFormulaPL` — **ไม่ใช่บั๊ก** เพราะ `calPunchLineMultiplier` (`CalStats.h:368`) คุมทั้งสองเรื่องในฟังก์ชันเดียว: ถ้าเป็น `ElationSkill` ใช้ตัวนับ `punchline` **สด** · ถ้าไม่ใช่ ใช้ `Stats::CertifiedBanger` ที่ **snapshot** ไว้ — ตรงกับ[คู่มือเกม](../../../../hsr-system-reference.md) §11.1 (Punchline = ทรัพยากรสดของทีม) และ §11.3 (Certified Banger = สถานะที่ snapshot Punchline ที่ใช้ไป อยู่ 2 เทิร์น)

> `CertifiedBanger` ถูกเขียนให้ ally เท่านั้น — `Combat.h:57,104` (ท้าย Aha Instant) และ `SetCombat.h:117` (ต้นรบ 20) · ลดคืนที่ `Event.h:89`
