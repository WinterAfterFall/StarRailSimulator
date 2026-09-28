# `src/Defination/Function/Combat/AhaCombat.h`

ทุกอย่างของ Aha Instant แยกออกมาจาก `Combat.h` เมื่อ 2026-09-28 (`358b933`) · ประกาศอยู่ใน `src/Declaration/Function/Combat/AhaCombat.h`

## `aha` — pseudo-unit ของทีม Elation

`aha` (`Setting.h:79`) = `unique_ptr<ActionValueStats>` ชื่อ `"Aha"` speed 80 — สร้างจาก `ActionValueStats` ตรง ๆ **ไม่มี object `Unit`** อยู่เบื้องหลัง → `charptr` เป็น `nullptr` ตลอด

- **วิ่งอยู่บนลู่ atv แย่งเทิร์นกับตัวละครจริง** — ถูก push เข้า `atvList` ที่ `SetCombat.h:62` **เฉพาะเมื่อมีสมาชิก Elation ในทีม**
- **ไม่มีตัวตนในสนาม** — ไม่มี HP / ไม่โดนตี / ไม่โดนบัฟ
- `takeAction` (`Combat.h:5`) จับเทิร์นของ Aha ด้วย `turn == aha.get()` (ไม่ใช่เช็ค `charptr` ว่าง เพราะ `TimerATV` ของ summon/countdown ก็มี `charptr` ว่าง) แล้วแตกไป `ahaTurn()`
- speed ของ `aha` ปรับด้วย `ahaSpeedAdjust(path)` (`Action_value.h`) — `flatSpeed = spd₁/5 + spd₂/10 + spd₃/15 + …` จาก speed สมาชิก Elation เรียงมากไปน้อย แล้วบวก `ahaExtraFlatSpeed` (บัฟ SPD ของ Aha จากตัวละคร — ไม่งั้นจะหายตอนคำนวณใหม่)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| **1 Aha Instant = 1 action** | `runAhaInstantBar()` ยิง event ระดับ action **ครั้งเดียว** ครอบ Elation Skill ทุกตัวในคิว | `AhaCombat.h:12-45` |
| เลือกตัวแทน action | ไล่สำเนาของ `ahaInstantBar` หา **attack action ตัวแรก** (`attackRep`) และ **buff action ตัวแรก** (`buffRep`) · ถ้ามีทั้งคู่ event ทั่วไปใช้ `attackRep` | `:15-26` |
| event ก่อนลูป | `BeforeAction` → `BeforeAllyAction` → `BeforeAttackAction` (ถ้ามี `attackRep`) | `:30-32` |
| รัน Elation Skill ทีละตัว | `elationSkillAction()` — เหมือน `allyAction()` แต่ **ไม่ยิง** Before/AfterAttackAction และ `buffList` | ลูป `:34-38` · ตัวฟังก์ชัน `Combat.h:81` |
| event หลังลูป | `AfterAttackAction` (ถ้ามี `attackRep`) → `buffList` (ถ้ามี `buffRep`) → `AfterAllyAction` → `AfterAction` | `:40-43` |
| **เทิร์นปกติของ Aha** | `ahaTurn()` — `++turnCnt` → `beforeAhaInstant()` → เรียก `elationSkillList` ทุกตัว (แต่ละตัว `addToAhaInstant()`) → `runAhaInstantBar()` → แจก Certified Banger → ล้าง Punchline แล้วเติม `elationCount` → `afterAhaInstant()` → `resetTurn(aha)` | `:46-68` |
| Certified Banger | Elation ทุกตัวได้ `CERTIFIED_BANGER` = Punchline ตอนนั้น ชื่อ `"CB Buff <turnCnt>"` อายุ `cbDuration` (ค่าเริ่ม 2 · Yao Guang A6 +1 ใน `YaoGuang.h` Setup) + บันทึกลง `cbCheck` | `:57-60` · `Setting.h:82` |
| ล้าง/เติม Punchline | `genPunchLine(nullptr, -punchline)` แล้ว `genPunchLine(nullptr, elationCount)` | `:62-63` |
| hook ก่อน/หลัง Aha Instant | `beforeAhaInstant()` / `afterAhaInstant()` วน `beforeAhaInstantList` / `afterAhaInstantList` · ผู้ใช้ตอนนี้: Hibana E1/E2 (`afterAhaInstantList`) · ยิงทั้งใน `ahaTurn` และ `ahaInstant(PL)` (ไม่ยิงใน `elationSkillTrigger`) | เรียก `:49`, `:65` (AhaTurn) · `:74`, `:90` (AhaInstant) · ตัวฟังก์ชัน `Event.h:252-261` |
| **Aha Instant จาก Ult ของ Yao Guang** | `ahaInstant(PL)` — ใช้ Punchline คงที่ `PL` ชั่วคราวแล้วคืนค่าเดิม (ไม่กิน Punchline จริง) · เรียก Elation Skill ทุกตัว · แจก CB · `++turnCnt` · เรียก `beforeAhaInstant()` หลังตั้ง PL และ `afterAhaInstant()` **หลังคืน Punchline เดิม** (Punchline ที่ hook ให้ เช่น Hibana E1 จึงไม่หาย) · **ไม่** `resetTurn(aha)` | `:69-91` · ผู้เรียก `YaoGuang.h:97-98` (PL 20 / E1 40) |
| **เรียก Elation Skill เฉพาะบางคน** | `elationSkillTrigger(PL, names)` — เหมือน `ahaInstant(PL)` แต่เรียกเฉพาะ trigger ที่ `owner->getName()` อยู่ใน `names` · **ไม่แจก CB · ไม่ `++turnCnt`** · log `trigger ELATION skill : ชื่อ1, ชื่อ2` | `:93-107` · ผู้เรียก: EMC Ult (`EMC.h:143`), Aventurine • Waveflair Cheers! ฟรี (`AventurineWaveflair.h:60`), Evanescia E1 (`Evanescia.h:116`) |
| **event "ตัวละครใช้ Elation Skill"** (เพิ่ม 2026-09-28) | `callElationSkill(e)` — เรียก Elation Skill ของเจ้าของ แล้วยิง `allEventWhenUseElationSkill(owner)` → วน `whenUseElationSkillList` (`TriggerByAllyFunc`, ส่งเจ้าของ · ดู `../Event/Event.md`) · ทั้ง 3 จุดที่เรียก `elationSkillList` (`ahaTurn` / `ahaInstant` / `elationSkillTrigger`) ใช้ตัวนี้ · ยิง **แยกทุกตัวละคร** ต่างจาก event ระดับ action ที่ยิงครั้งเดียว · ผู้ใช้: `Pearl_LC.h`, `Evanescia_LC.h`, `AventurineWaveflair_LC.h`, `Today's Good Luck.h`, `Mushy Shroomy's Adventures.h` | `AhaCombat.h:5-8` · event `Event.h:246-250` · list `Setting.h:109` · sort `SetCombat.h:18` |
| คิว Aha Instant | `ahaInstantBar` เป็น `queue<shared_ptr<AllyActionData>>` — ใส่ได้แค่ action ฝ่ายเรา · เข้าคิวผ่าน `AllyAttackAction::addToAhaInstant()` (ข้ามถ้าผู้โจมตีไม่อยู่ในสนาม) | `Setting.h:63` |

## ผลของการใช้ตัวแทนตัวแรก

trigger ระดับ action เห็นแค่ **action ของผู้แสดงคนแรก** ตามลำดับ priority ใน `elationSkillList` (sort มากไปน้อยที่ `SetCombat.h:14`) ทั้ง `attacker`, `attackSetList`, `targetList`

- LC / relic ที่เช็ค "ผู้สวมใช้ Elation Skill" ใน list ระดับ action จะติดเฉพาะเมื่อผู้สวมเป็นผู้แสดงคนแรก → ให้ใช้ `whenUseElationSkillList` แทน (Mushy Shroomy, Today's Good Luck ย้ายไปแล้ว 2026-09-28)
- `When_attack` ยังยิงรายผู้โจมตีภายใน `elationSkillAction()` ของแต่ละคน
- event ระดับการโจมตีใน `attack()` (`BeforeAttack` / `AfterAttack` / per-hit) ยังยิงรายคนตามปกติ
- ก่อนหน้านี้ (ระหว่างวันเดียวกัน) เคยลองสร้าง action ตัวแทนใหม่ที่รวม `attackSetList` / `targetList` ของทุกคน แต่ user เปลี่ยนเป็นหยิบตัวแรก (user สั่ง 2026-09-28)

## จุดที่ควรระวัง

- **ไม่มีการตรวจ Ultimate หลังแต่ละ action ในคิวนี้** — user ยืนยันว่าถูกต้อง (ต่างจาก `actionBar` ใน `dealDamage`)
- `cbDuration` บวกใน Setup และไม่ถูกรีเซ็ต → ถ้า Setup ทีมหลายรอบในการรันเดียวค่าจะสะสม (แบบเดียวกับ `elationCount`)
- `SetCombat.h:113` ยังแจก `"CB Buff"` ตอนเริ่มเกมด้วยอายุ 2 ตายตัว ไม่ได้ใช้ `cbDuration`
