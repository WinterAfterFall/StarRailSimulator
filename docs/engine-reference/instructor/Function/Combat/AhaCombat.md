# `src/Defination/Function/Combat/AhaCombat.h`

ทุกอย่างของ Aha Instant แยกออกมาจาก `Combat.h` เมื่อ 2026-09-28 (`358b933`) · ประกาศอยู่ใน `src/Declaration/Function/Combat/AhaCombat.h`

## `aha` — pseudo-unit ของทีม Elation

`aha` (`Setting.h:79`) = `unique_ptr<ActionValueStats>` ชื่อ `"Aha"` speed 80 — สร้างจาก `ActionValueStats` ตรง ๆ **ไม่มี object `Unit`** อยู่เบื้องหลัง → `charptr` เป็น `nullptr` ตลอด

- **วิ่งอยู่บนลู่ atv แย่งเทิร์นกับตัวละครจริง** — ถูก push เข้า `atvList` ที่ `SetCombat.h:62` **เฉพาะเมื่อมีสมาชิก Elation ในทีม**
- **ไม่มีตัวตนในสนาม** — ไม่มี HP / ไม่โดนตี / ไม่โดนบัฟ
- `Take_action` (`Combat.h:5`) จับเทิร์นของ Aha ด้วย `turn == aha.get()` (ไม่ใช่เช็ค `charptr` ว่าง เพราะ `TimerATV` ของ summon/countdown ก็มี `charptr` ว่าง) แล้วแตกไป `AhaTurn()`
- speed ของ `aha` ปรับด้วย `ahaSpeedAdjust(path)` (`Action_value.h`) — `flatSpeed = spd₁/5 + spd₂/10 + spd₃/15 + …` จาก speed สมาชิก Elation เรียงมากไปน้อย

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| **1 Aha Instant = 1 action** | `runAhaInstantBar()` ยิง event ระดับ action **ครั้งเดียว** ครอบ Elation Skill ทุกตัวในคิว | `AhaCombat.h:5-38` |
| เลือกตัวแทน action | ไล่สำเนาของ `AhaInstantBar` หา **attack action ตัวแรก** (`attackRep`) และ **buff action ตัวแรก** (`buffRep`) · ถ้ามีทั้งคู่ event ทั่วไปใช้ `attackRep` | `:8-19` |
| event ก่อนลูป | `BeforeAction` → `BeforeAllyAction` → `BeforeAttackAction` (ถ้ามี `attackRep`) | `:23-25` |
| รัน Elation Skill ทีละตัว | `ElationSkillAction()` — เหมือน `AllyAction()` แต่ **ไม่ยิง** Before/AfterAttackAction และ `Buff_List` | ลูป `:27-31` · ตัวฟังก์ชัน `Combat.h:81` |
| event หลังลูป | `AfterAttackAction` (ถ้ามี `attackRep`) → `Buff_List` (ถ้ามี `buffRep`) → `AfterAllyAction` → `AfterAction` | `:33-36` |
| **เทิร์นปกติของ Aha** | `AhaTurn()` — `++turnCnt` → `BeforeAhaInstant()` → เรียก `ElationSkill_List` ทุกตัว (แต่ละตัว `addToAhaInstant()`) → `runAhaInstantBar()` → แจก Certified Banger → ล้าง Punchline แล้วเติม `elationCount` → `AfterAhaInstant()` → `resetTurn(aha)` | `:39-61` |
| Certified Banger | Elation ทุกตัวได้ `CertifiedBanger` = Punchline ตอนนั้น ชื่อ `"CB Buff <turnCnt>"` อายุ `CB_duration` (ค่าเริ่ม 2 · Yao Guang A6 +1 ใน `YaoGuang.h` Setup) + บันทึกลง `CBcheck` | `:50-53` · `Setting.h:82` |
| ล้าง/เติม Punchline | `genPunchLine(nullptr, -punchline)` แล้ว `genPunchLine(nullptr, elationCount)` | `:55-56` |
| hook ก่อน/หลัง Aha Instant | `BeforeAhaInstant()` / `AfterAhaInstant()` วน `BeforeAhaInstant_List` / `AfterAhaInstant_List` · ผู้ใช้ตอนนี้: Hibana E1/E2 (`AfterAhaInstant_List`) | เรียก `:42`, `:58` · ตัวฟังก์ชัน `Event.h:245-254` |
| **Aha Instant จาก Ult ของ Yao Guang** | `AhaInstant(PL)` — ใช้ Punchline คงที่ `PL` ชั่วคราวแล้วคืนค่าเดิม (ไม่กิน Punchline จริง) · เรียก Elation Skill ทุกตัว · แจก CB · `++turnCnt` แต่ **ไม่** `resetTurn(aha)` และ **ไม่** เรียก Before/AfterAhaInstant | `:62-78` · ผู้เรียก `YaoGuang.h:97-98` (PL 20 / E1 40) |
| **เรียก Elation Skill เฉพาะบางคน** | `ElationSkillTrigger(PL, names)` — เหมือน `AhaInstant(PL)` แต่เรียกเฉพาะ trigger ที่ `owner->getName()` อยู่ใน `names` · **ไม่แจก CB · ไม่ `++turnCnt`** · log `trigger Elation Skill : ชื่อ1, ชื่อ2` | `:80-94` · ยังไม่มีผู้เรียก |
| คิว Aha Instant | `AhaInstantBar` เป็น `queue<shared_ptr<AllyActionData>>` — ใส่ได้แค่ action ฝ่ายเรา · เข้าคิวผ่าน `AllyAttackAction::addToAhaInstant()` (ข้ามถ้าผู้โจมตีไม่อยู่ในสนาม) | `Setting.h:63` |

## ผลของการใช้ตัวแทนตัวแรก

trigger ระดับ action เห็นแค่ **action ของผู้แสดงคนแรก** ตามลำดับ priority ใน `ElationSkill_List` (sort มากไปน้อยที่ `SetCombat.h:14`) ทั้ง `Attacker`, `AttackSetList`, `targetList`

- LC / relic ที่เช็ค "ผู้สวมใช้ Elation Skill" ใน list ระดับ action (เช่น Mushy Shroomy, Today's Good Luck ใน `BeforeAllyActionList`) จะติดเฉพาะเมื่อผู้สวมเป็นผู้แสดงคนแรก
- `When_attack` ยังยิงรายผู้โจมตีภายใน `ElationSkillAction()` ของแต่ละคน
- event ระดับการโจมตีใน `Attack()` (`BeforeAttack` / `AfterAttack` / per-hit) ยังยิงรายคนตามปกติ
- ก่อนหน้านี้ (ระหว่างวันเดียวกัน) เคยลองสร้าง action ตัวแทนใหม่ที่รวม `AttackSetList` / `targetList` ของทุกคน แต่ user เปลี่ยนเป็นหยิบตัวแรก (user สั่ง 2026-09-28)

## จุดที่ควรระวัง

- **ไม่มีการตรวจ Ultimate หลังแต่ละ action ในคิวนี้** — user ยืนยันว่าถูกต้อง (ต่างจาก `Action_bar` ใน `Deal_damage`)
- `AhaInstant(PL)` ไม่เรียก `AfterAhaInstant()` → Hibana E1/E2 ไม่ทำงานใน Aha Instant ที่มาจาก Ult ของ Yao Guang
- `CB_duration` บวกใน Setup และไม่ถูกรีเซ็ต → ถ้า Setup ทีมหลายรอบในการรันเดียวค่าจะสะสม (แบบเดียวกับ `elationCount`)
- `SetCombat.h:113` ยังแจก `"CB Buff"` ตอนเริ่มเกมด้วยอายุ 2 ตายตัว ไม่ได้ใช้ `CB_duration`
