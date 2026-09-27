# `src/Defination/Function/Combat/Combat.h`

## Punchline

`punchline` เป็นทรัพยากร global ที่มี clamp ขั้นต่ำเป็น 0 แต่ไม่มีเพดานสูงสุด ตั้งใจให้สะสมเกินค่าเริ่มต้นได้ไม่จำกัดตามกลไกของทีม Elation

## `dealDamage()` กับ `actionBarUse`

User ยืนยัน 2026-09-17: `actionBarUse` ใช้กันการประมวลผลคิวซ้อน เพื่อให้แอ็กชันปัจจุบันจบก่อนทำรายการถัดไป

จากโค้ด: หาก `actionBarUse` เป็น `true` จะกลับทันที มิฉะนั้นตั้งเป็น `true` แล้ววนประมวลผล `actionBar` จากหัวคิวจนว่าง แอ็กชันที่เพิ่มเข้าคิวระหว่างนี้รอให้ลูปเดิมทำต่อ เมื่อจบจึงคืน `actionBarUse` เป็น `false` และคืน `phaseStatus` เป็นค่าก่อนเข้าฟังก์ชัน

## จังหวะตรวจ Ultimate

User อธิบาย 2026-09-17 ว่าเจตนาคือตรวจ 2 จังหวะ: หลังจบแอ็กชันใด ๆ และหลังจบ before-turn event ของตัวละครในเทิร์น AllyUnit

จุดเรียกที่ตรวจพบในโค้ดปัจจุบัน:

- `dealDamage()`: หลัง `allEventAfterAction(temp)` เรียก `allUltimateCheck()` เมื่อ `turn` ไม่เป็น null ก่อนนำแอ็กชันออกจากคิว
- `takeAction()`: เรียกหลังบล็อก `allEventBeforeTurn()` ก่อน `turnFunc()` เฉพาะเมื่อ `turn->canCastToAllyUnit()` คืน pointer ที่ไม่เป็น null; ยังเรียกเมื่อ `extraTurn` ทำให้ข้าม before-turn event
- User ยืนยันว่าการไม่ตรวจหลังแต่ละแอ็กชันใน `ahaInstantBar` ถูกต้องแล้ว กฎหลังจบแอ็กชันข้างต้นใช้กับคิว `actionBar`
- User แก้โค้ด 2026-09-17: เพิ่มเงื่อนไข `canCastToAllyUnit` และลบจุดเรียกก่อน `allEventAfterTurn()` แล้ว จึงเหลือสองตำแหน่งข้างต้นใน `Combat.h`

## Aha Instant

ย้ายไป `AhaCombat.h` แล้ว (2026-09-28) — `aha`, `ahaTurn()`, `ahaInstant(PL)`, `elationSkillTrigger()`, `runAhaInstantBar()` ดู [AhaCombat.md](AhaCombat.md) · ในไฟล์นี้เหลือแค่ `takeAction` ที่แยกเทิร์นของ Aha ด้วย `turn == aha.get()` (`Combat.h:5`) และ `AllyActionData::elationSkillAction()` (`Combat.h:81`) ที่ Aha ใช้รัน Elation Skill

## `turnSkip` (global bool, `Setting.h:72`)

บังคับข้ามเทิร์น (CC เช่น Freeze) — `takeAction()`: `if(turnSkip==0){ turnFunc(); dealDamage(); }`
- ตั้ง = 1: `Event.h:19` (enemy โดน Freeze กินเทิร์น) · `Ruan_Mei.h:104`
- reset = 0: ทุกรอบ loop (`Main.h:46` / `ManualBuilder.cpp:155`)
- before/after-turn events **ยังยิงปกติ** — ข้ามแค่ action; จุดตรวจ Ultimate ก่อน action ยังเรียกเมื่อ `turn->canCastToAllyUnit` เป็นจริง

**enemy ที่โดน freeze ทำไมไม่โดน `findTurn` เลือกซ้ำทันที** (atv มันยัง ~0 อยู่) — คำตอบอยู่ที่ `Event.h:13-22` ใน `allEventBeforeTurn` (`side == Enemy`): ถ้าเจอ entry ใน `breakFrzList`
1. `calFreezeDamage` — คิดดาเมจ freeze
2. **`actionForward(enemy->atvStats.get(), -50)`** — `fwd` ติดลบ → เข้า else branch ของ `actionForward` → `atv = atv - maxAtv*(-50)/100` = **`atv += 0.5 * maxAtv`** (ดัน atv ถอยหลังครึ่งบาร์)
3. `turnSkip = 1`
4. `breakFrzList.erase(itr)` + `break`

ขั้นที่ 2 คือกลไกที่ทำให้ enemy เลื่อนออกจากตำแหน่ง "ตัวถัดไป" — ไม่งั้น loop วนเลือกมันซ้ำไม่จบ. รอบหน้า freeze ถูกลบไปแล้ว → เล่นเทิร์นปกติ

## `attack()` (`Combat.h:111`) — ผู้โจมตีหลัง `switchAttacker`

จากโค้ด: ระหว่างวน `damageSplit` สลับ `attacker` / `source` / type ตาม `switchAttacker` และไม่คืนค่ากลับก่อน `allEventAfterAttack(act)` จึงเห็นผู้โจมตีตัวสุดท้ายที่สลับไป; การคืนเป็น `attackSetList[0]` เกิดทีหลังใน `allyAction()` ก่อน `allEventAfterAttackAction`

User ยืนยัน 2026-09-20: พฤติกรรมนี้ใช้ได้ ไม่มีปัญหา

## `superbreakTrigger()` — เงื่อนไขปริมาณ toughness ที่นับ

User ยืนยัน 2026-09-20:

- `currentToughness + toughnessReduce <= 0` (หรือมี Dahlia) → เป้า Break อยู่ก่อนแล้ว นับ `toughnessReduce` เต็มจำนวน
- `else` → การโจมตีครั้งนี้เพิ่งทำให้ Break พอดี จึงนับเฉพาะส่วนที่เกินเกราะ = `-currentToughness` ซึ่งตอนนั้นติดลบ เพราะ `calToughnessReduction` หักจนต่ำกว่า 0 ได้ (`CalDamage.h:188-196`)
- เรื่องสมุดเฉลี่ย/คิดสดของ Dahlia ดู [CalDamageNote.md](../Calculate/CalDamageNote.md)

## `dotTrigger(dotRatio, target, dotType)` — detonate DoT

User ยืนยัน 2026-09-20:

- `dotRatio` = เปอร์เซ็นต์ของดาเมจ DoT ปกติที่ทำให้เกิดทันที (detonate) เช่น Kafka 75 = DoT ทั้งหมดบนเป้าทำดาเมจทันที 75%
- `DotType::GENERAL` = ทุกประเภท; ระบุ `BURN` / `BLEED` / `SHOCK` / `WIND_SHEAR` = เฉพาะประเภทนั้น (Guinaifen = Burn, Luka = Bleed)

จากโค้ด: (1) วน `breakDotList` คำนวณ break DoT แต่ละประเภท (Wind Shear คูณ `stack`) ผ่าน `calDotToughnessBreakDamage` (2) เรียก `dotList` ให้ DoT จากสกิลตัวละครทำงานตาม `dotRatio` / `dotType`

## `toughnessBreak()` — `forceBreak` (`Setting.h:21`, ค่าเริ่มต้น `1`)

จากโค้ด: ถ้า `forceBreak != 0` ผู้ทำ Break ถูกบังคับเป็น `charUnit[forceBreak]` → ธาตุ Break, สถานะ Break ที่ติด และ Break DMG เป็นของตัวละครช่องนั้นเสมอ ไม่ว่าใครตีแตก; `0` = ใช้ `act->attacker` จริง

User ยืนยัน 2026-09-20 (เหตุผล): บางทีมมี Break DMG เป็นดาเมจสำคัญ ถ้าคนทำ Break ไม่ใช่คนเดิมเสมอ เวลาเทียบผลระหว่าง 2 ทีมอาจได้ผลที่ไม่ถูกต้อง จึงล็อคผู้ทำ Break ให้คงที่ (สอดคล้องหลัก determinism)

## `superBreakMode` (`Setting.h:8`, ค่าเริ่มต้น `0`)

จากโค้ด: ถ้าเป็น `1` ทุกครั้งที่ Break จะตั้ง ATV ศัตรูเป็น `maxAtv * 0.5` ก่อนใส่ action delay ตามธาตุ

User ยืนยัน 2026-09-20 (เหตุผล): SPB ทำดาเมจได้เฉพาะช่วงที่ศัตรูล้ม ซึ่งกินเวลาถึงเทิร์นถัดไปของศัตรู ถ้าเบรคเร็วเกินไปจนแตกในจังหวะที่ศัตรูใกล้ได้เทิร์นพอดี ช่วงทำดาเมจจะสั้นผิดปกติ โหมดนี้จึงสมมติว่าแตกกลางเทิร์นเสมอ เพื่อให้ผลของทีม Super Break คงที่

## ทรัพยากรทีม — `genSkillPoint()` · `genPunchLine()` (`Combat.h:169-184`)

สองฟังก์ชันนี้คือ **ทางเดียว**ที่ควรใช้แก้ค่า Skill Point และ Punchline เพราะมันห่อ event ไว้ให้

```cpp
void genSkillPoint(AllyUnit *ptr, int p){
    allEventSkillPoint(ptr, p);     // ← ยิง event ก่อน แล้วค่อยเปลี่ยนค่า
    sp += p;
    if (sp > maxSp) sp = maxSp;   // เพดานเท่านั้น ไม่มีพื้น
}
void genPunchLine(AllyUnit *ptr, int p){
    allEventPunchLine(ptr, p);
    punchline += p;
    punchline = max(punchline, 0);  // พื้นเท่านั้น ไม่มีเพดาน
}
```

| | `genSkillPoint` | `genPunchLine` |
|---|---|---|
| global ที่แก้ | `sp` | `punchline` |
| clamp | เพดาน `maxSp` · **ไม่มีพื้น** | พื้น `0` · **ไม่มีเพดาน** |
| event | `allEventSkillPoint` | `allEventPunchLine` |
| ใช้ `p` ติดลบ | ใช่ — การ "กิน" SP คือส่งค่าลบ | ใช่ — `AhaCombat.h:55` ส่ง `-punchline` เพื่อล้างทั้งกอง |

สามเรื่องที่ต้องระวัง:

1. **event ยิงก่อนค่าเปลี่ยน** — trigger ที่อ่าน `sp` / `punchline` ระหว่าง event จะเห็น**ค่าเก่า** ส่วนค่าที่กำลังจะเปลี่ยนรับมาทาง argument `p`
2. **event ยิงด้วย `p` ที่ร้องขอ ไม่ใช่ที่เปลี่ยนจริง** — ขอ SP ตอนเต็มหลอดอยู่แล้วก็ยังยิง event ด้วยเลขเต็ม แม้ `sp` จะไม่ขยับ
3. **`sp` ไม่มีพื้น** — ส่งค่าลบเกินที่มีจะได้ SP ติดลบ ผู้เรียกต้องเช็คเองว่ามี SP พอ

`genPunchLine(nullptr, …)` ที่ `AhaCombat.h:55-56` คือกรณี "ไม่มีเจ้าของ" — ใช้ตอน Aha Instant ล้างและแจก Punchline ใหม่ ดูหัวข้อ [Punchline](#punchline) ด้านบน

## `EnemyActionData::enemyAction()` (`Combat.h:107`)

ตัวมันเองมีแค่ 2 บรรทัด — เรียก `actionFunction()` ที่ศัตรูตัวนั้นตั้งไว้ แล้ว `resetTurn(turn)` · เนื้อหาว่าศัตรูเลือกท่า/เลือกเป้าอย่างไรอยู่ใน [EnemyCombat.md](EnemyCombat.md) และ [EnemyActionData.md](../../Class/ActionData/EnemyActionData.md)
