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

## ตารางเต็มของ `canCheckDmgformulaXxx()`

ทุกตัวเป็น `bool` อ่านอย่างเดียว รวม flag ระดับ "ทั้งหมด → กลุ่ม → เดี่ยว" ให้ในฟังก์ชันเดียว ฝั่งโค้ดคำนวณจึงไม่ต้องรู้ว่ามี flag กี่ชั้น

| ฟังก์ชัน | คืน true เมื่อเปิด | ผู้เรียกหลัก |
|---|---|---|
| `canCheckDmgformula()` | `checkDmgFormula` (สวิตช์แม่) | เกตรวมใน `CalDamage.h` + `Combat.h:166,212` |
| `canCheckDmgformulaMtpr()` | `All` · `Src` · `HP` · `ATK` · `DEF` · `Const` | union ของกลุ่มที่มาของ Base DMG |
| `canCheckDmgformulaHP()` / `canCheckDmgformulaATK()` / `canCheckDmgformulaDEF()` / `canCheckDmgformulaConst()` | `All` · `Src` · ตัวเอง | `CalStats.h` ฝั่งคำนวณ Base DMG |
| `canCheckDmgformulaCritRate()` / `canCheckDmgformulaCritDam()` | `All` · `Crit` · ตัวเอง | `Cal_Crit_rate_multiplier` / `Cal_Crit_dam_multiplier` |
| `canCheckDmgformulaDmg()` `canCheckDmgformulaDefShred()` `canCheckDmgformulaRespen()` `canCheckDmgformulaVul()` `canCheckDmgformulaMtgt()` `canCheckDmgformulaMtprInc()` `canCheckDmgformulaBE()` `canCheckDmgformulaSpbInc()` `canCheckDmgformulaPL()` `canCheckDmgformulaMM()` `canCheckDmgformulaElation()` | `All` · ตัวเอง | ตัวคูณเชิงเส้นตัวใครตัวมันใน [CalStats.md](../Calculate/CalStats.md) |

⚠️ ไม่มีฟังก์ชัน `canCheck…` สำหรับฝั่ง heal/HP change — โค้ดฝั่งนั้นอ่าน field ตรง ๆ (ดูหัวข้อถัดไป)

## สวิตช์ฝั่งฮีลและ HP change

นอกจากสายดาเมจ `CharUnit` ยังมี flag อีก 7 ตัว (`CharUnit.h:67, 90-95`) เปิดผ่านฟังก์ชันตัวละ 1 บรรทัดใน `FormulaCheck.h:3, 30-47` ซึ่ง **ไม่มีระบบ mode/กลุ่มเหมือนฝั่งดาเมจ** — เปิดตัวไหนก็เปิดตรง ๆ ตัวนั้น

| ฟังก์ชันเปิด | flag | ใครอ่าน | พิมพ์อะไร |
|---|---|---|---|
| `enableCheckDamage()` | `checkDamage` | `CalDamage.h` (9 จุด) · `CalDamageNote.h:80` · `Combat.h:166,212` | เปิดหัวข้อ Damage Check + บรรทัดสรุปดาเมจรายท่า — **เป็นตัวเดียวที่ทำงานคู่กับ `canCheckDmgformula()` แบบ OR** |
| `enableCheckHeal()` | `checkHeal` | `ChangeHP.h` (8 จุด) · `CalHeal.h:7,55` | กรอบ `Heal Count : N` และบรรทัด `Total Heal` |
| `enableCheckHealFormula()` | `checkHealFormula` | `ChangeHP.h` (8 จุด) · `CalHeal.h:6,13` | กางสูตรฮีลทั้งชุด (ATK/HP/DEF ratio, lost-HP, total-HP, const, heal bonus) |
| `enableCheckHealReceive()` | `checkHealReceive` | `CalHeal.h:7,55` | — (ดูกติกา AND ข้างล่าง) |
| `enableCheckHealReceiveFormula()` | `checkHealReceiveFormula` | `CalHeal.h:6,13` | — |
| `enableCheckHpChange()` | `checkHpChange` | **ไม่มีใครอ่าน** | — |
| `enableCheckHpChangeFormula()` | `checkHpChangeFormula` | **ไม่มีใครอ่าน** | — |

### กติกา AND ของฝั่งฮีล — ต้องเปิดสองฝั่ง

`calculateHeal()` (`CalHeal.h:6-7`) ไม่ได้เช็คแค่ผู้ฮีล แต่เช็ค **ผู้ฮีล AND ผู้รับ** พร้อมกัน:

```cpp
if( (Healer->owner->checkHealFormula && target->owner->checkHealReceiveFormula)
 || (Healer->owner->checkHeal        && target->owner->checkHealReceive) ) { … }
```

แปลว่าเปิด `enableCheckHeal()` ให้ Huohuo คนเดียวจะ **ไม่เห็นอะไรเลย** ต้องไปเปิด `enableCheckHealReceive()` ให้ตัวที่อยากดูว่าได้รับฮีลเท่าไรด้วย เจตนาคือให้กรองได้ว่า "อยากดูเฉพาะคู่ผู้ฮีล→ผู้รับคู่นี้"

ข้อยกเว้น: กรอบหัวข้อ `Heal Count` ใน `ChangeHP.h` เช็คแค่ฝั่งผู้ฮีล (`checkHeal || checkHealFormula`) จึงเป็นไปได้ที่จะเห็นกรอบเปล่าโดยไม่มีบรรทัดฮีลข้างใน ถ้าลืมเปิดฝั่งผู้รับ

> ⚠️ **ยังใช้งานไม่ได้ รอแก้ภายหลัง (user ยืนยัน 2026-09-22)** — `checkHpChange` กับ `checkHpChangeFormula` มีครบทั้ง field และฟังก์ชันเปิด แต่ **ไม่มีจุดใดในโค้ดอ่านค่านี้เลย** (ตรวจทั้ง `src/` 2026-09-22) เส้นทางลด HP (`DecreaseHP` / `DecreaseCurrentHP` ใน [ChangeHP.md](../Combat/ChangeHP.md)) จึงยังไม่มี debug print ของตัวเอง เรียก `enableCheckHpChange()` ตอนนี้จะไม่เกิดอะไรขึ้น — ตั้งใจจะต่อสายทีหลัง ไม่ใช่โค้ดตกค้างที่ต้องถอด
