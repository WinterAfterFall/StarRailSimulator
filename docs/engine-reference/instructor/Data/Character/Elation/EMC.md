# `src/Defination/Data/Character/Elation/EMC.h`

kit อ้างอิง: [`docs/kit-reference/Character/Elation/trailblazer-elation.md`](../../../../../kit-reference/Character/Elation/trailblazer-elation.md) (ข้อมูลเกม 4.5.54 จาก nanoka) · ตัวจริงในเกม **Trailblazer • Elation** · ชื่อ unit `"EMC"` · เลือกใน `SettingFunction.h` ด้วยชื่อ `EMC`
คำศัพท์ของ path Elation อยู่ใน [Hibana.md](Hibana.md) — อ่านก่อน

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**
> Participant ID ของ Elation Skill = **120** (ไม่อยู่ในไฟล์ kit ดูจาก nanoka) — ใช้เป็น priority ของ `elationSkillList`
> ระดับ ability ใช้แบบ 5★ (Lv.6 / Lv.10) และ eidolon ตามค่าที่ส่งเข้า `setup` เหมือน Harmony MC / RMC

## ภาพรวมแบบสั้น

EMC เป็นซัพพอร์ตสาย Elation (Lightning)

- **Skill** ตีทุกตัวเบา ๆ แล้วให้ Certified Banger (CB) ตัวเอง 20 → ทำให้ Talent เปิด (Skill ตีเพิ่มเป็น Elation DMG)
- **Ult** บัฟเพื่อน 1 คน: CD +50% · ถ้าเพื่อนมี Elation Skill → ให้ CB +10 แล้วสั่งให้เพื่อนใช้ Elation Skill ทันที (นับ Punchline ตายตัว 20) · ถ้าไม่มี → ดันแอคชัน 50%
- **Talent** ทุกครั้งที่ตี: Energy +10 (fixed) และ Punchline +3

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 106, Lightning, Elation · HP/ATK/DEF 1087/466/631 · Energy 160 | `setCharBasicStats(106,160,160,...)` | 19-20 |
| build | Body CD / SPD / ATK% / ERR ตาม nanoka | `setRelicMainStats(...)` | 23-26 |
| นับเข้า Elation ในทีม | — | `elationCount++` | 28 |
| **Basic ATK** | 100% ATK เดี่ยว · toughness 10 · SP +1 · Energy 20 | lambda `ba` | 57-70 |
| **Skill** | 60% ATK ทุกตัว · toughness 20 · SP −1 · Energy 30 · ตัวเองได้ CB 20 | lambda `skill` · `grantCB(ptr, 20)` | 73-111 |
| **Talent: หลังตี** | Energy +10 (fixed) · Punchline +3 | `talent()` เรียกท้าย BA / Skill / Elation Skill · `increaseEnergy(ptr,0,10)` = flat ไม่คูณ ERR | 48-51 |
| **Talent: Skill + CB** | ถือ CB → Skill ตีเพิ่ม 30% Elation ทุกตัว โดยคิด CB ด้วย **ค่าสูงสุดในทีม** | action `ELATION_DMG` แยกก้อน · หา CB สูงสุดจาก `charList` แล้วยกส่วนต่างใส่ใต้ `AType::ELATION_DMG` ชั่วคราว (แบบ Ult ของ Evanescia) แล้วคืนค่า | 85-102 |
| **Ultimate** | Punchline +5 · เพื่อน 1 คน CD +50% 3 เทิร์น · มี Elation Skill → CB +10 + ใช้ Elation Skill ทันทีด้วย PL 20 · ไม่มี → ดันแอคชัน 50% | เป้า = `chooseAllyBuff(ptr)` · บัฟชื่อ `"EMC Ult"` · เช็คว่ามี Elation Skill จาก `elationSkillList` · `elationSkillTrigger(20,{ชื่อเป้า})` (ยิงเฉพาะ Elation Skill ของเป้า ไม่ให้ CB เพิ่ม) · ไม่มี → `actionForward(...,50)` | 126-151 |
| เงื่อนไขกด Ult | Energy ครบ 160 | ไม่มีเงื่อนไขเพิ่ม | 120-122 |
| AI เลือกท่า | — | `sp > spSafety` → Skill ไม่งั้น BA | 115-118 |
| **Elation Skill** | 8 × 20% Elation สุ่มเป้า แล้ว 60% Elation หารทุกตัว · toughness 20 · Energy 5 | `elationSkillList` priority 120 · `addEnemyBounce(...,8)` + AoE `60/จำนวนศัตรู` (toughness อยู่ที่ก้อน AoE) · `addToAhaInstant()` | 154-172 |
| **Technique** | สุ่มได้ Elation +20% (โอกาสสูง) หรือ +30% (โอกาสต่ำ) ให้ทั้งทีม 3 เทิร์น | เลือก +20% เสมอ (ผลที่มีโอกาสสูง ตามหลัก determinism) · `buffAllAlly(...,"EMC Technique",3)` | 195-198 |
| **Minor traces** | ATK +28% · CR +12% · CD +13.3% | `resetList` | 220-222 |
| **A2** | ATK ที่เกิน 1000 ทุก 200 → Elation +10% (สูงสุด 60%) | `statsAdjustList` เมื่อ ATK เปลี่ยน ใส่ส่วนต่างเทียบ `buffNote["EMC A2"]` · ปลุกครั้งแรกใน `whenOnFieldList` | 232-239, 227-229 |
| **A4** | CR +15% · หลัง Ult ทีมได้ SP +1 | `resetList` · `genSkillPoint(ptr,1)` ใน Ult | 224, 135 |
| **A6** | เพื่อนคนไหนใช้ Elation Skill → Skill ครั้งถัดไปของ EMC ได้ CB เพิ่ม 2 · **ซ้อนได้** (user 2026-09-28) | นับ stack ใน `buffNote["EMC A6"]` ไม่มีเพดาน · Skill ให้ `20 + 2×stack` แล้วรีเซ็ต · วิธีนับดูหัวข้อ "A6 นับยังไง" | 178-192, 81-82 |
| **E1** | หลังใช้ Skill → Ult ครั้งถัดไปให้ CB เพื่อนเพิ่ม 2 (ซ้อนได้ 3) | นับใน `buffNote["EMC E1"]` สูงสุด 3 · Ult ให้ `10 + 2×stack` แล้วรีเซ็ต | 83, 142, 146 |
| **E2** | Ult ให้เป้า Elation +12% 2 เทิร์น | บัฟชื่อ `"EMC E2"` | 134 |
| **E4** | ใช้ Elation Skill → ศัตรูรับดาเมจ +10% 2 เทิร์น | `debuffAllEnemyApply(...,"EMC E4",2)` · ถอนตอนเทิร์นศัตรู | 159, 203-205 |
| **E6** | ใช้ Elation Skill → CD ตัวเอง +100% 3 เทิร์น | บัฟชื่อ `"EMC E6"` | 160 |
| ถอนบัฟทั้งหมด | — | `afterTurnList` ตอนเทิร์นของผู้ถือ `isBuffEnd` → ใส่ค่าลบ | 200-216 |

## CB ที่ EMC แจก

engine มีระบบนับเวลาเฉพาะ CB ที่มาจาก Aha Instant (`cbCheck`) ส่วน CB ที่ EMC แจก (Skill ให้ตัวเอง, Ult ให้เป้า) ไฟล์นี้ดูแลเอง

- `grantCB(holder, value)` (บรรทัด 39-45) สร้างบัฟชื่อ `"EMC CB <n>"` อายุ `cbDuration` (เท่ากับ CB จาก Aha) แล้วจด {ผู้ถือ, ชื่อ, ค่า} ไว้ใน `grantedCB`
- ถึงเทิร์นของผู้ถือและบัฟหมด → ถอนค่าออก (บรรทัด 211-215)

## A6 นับยังไง

ทุก Elation Skill ที่เพื่อน (รวม EMC เอง) ใช้ = +1 stack · มีสองทางที่ Elation Skill เกิดขึ้น

| ทาง | นับตรงไหน | บรรทัด |
|---|---|---|
| **Aha Instant** — ทุกคนใน `elationSkillList` ใช้คนละ 1 ครั้ง | `afterAhaInstantList` → `+= elationSkillList.size()` (รวม Pro-Gamer Move ของ SW999 ที่ไม่สร้าง action ด้วย) | 182-184 |
| **นอก Aha** — `elationSkillTrigger` เช่น Ult ของ EMC, E1 ของ Evanescia | `afterAttackActionList` → action ที่เป็น `ELATION_SKILL` = +1 | 185-192 |

ใน Aha Instant `runAhaInstantBar()` ก็ยิง `afterAttackAction` ด้วย (ครั้งเดียวด้วยตัวแทน) → ถ้าไม่กันจะนับซ้ำ จึงตั้งธง `"EMC In Aha"` ใน `beforeAhaInstantList` (บรรทัด 178-180) และปิดใน `afterAhaInstantList` · ระหว่างธงเปิด ทาง `afterAttackAction` จะไม่นับ

ข้อจำกัด: Elation Skill ที่ไม่มีดาเมจ (Pro-Gamer Move ของ SW999) ถ้าถูกเรียกผ่าน `elationSkillTrigger` นอก Aha จะไม่ถูกนับ เพราะไม่มี attack event

## จุดที่ตีความเอง

- **Technique เลือก +20% เสมอ** — ผลที่โอกาสสูงกว่า (kit ไม่บอกเปอร์เซ็นต์)
- **toughness ของ Elation Skill (AoE 20)** ใส่ที่ก้อน AoE ท้ายท่า bounce 8 ครั้งไม่ลด toughness
- **Talent "หลังใช้การโจมตี"** เรียกตรงท้าย BA / Skill / Elation Skill ของ EMC เอง (ไม่ได้ใช้ `afterAttackActionList` เพราะใน Aha Instant event ระดับ action ยิงครั้งเดียวด้วยตัวแทน อาจไม่ใช่ของ EMC)
- **ตัดทิ้ง**: ล้าง Crowd Control ให้เป้า Ult (engine ไม่มีระบบ CC)

## จุดที่ควรระวัง

- **ไม่มี event "ได้ CB"** — CB ที่ EMC แจกให้ Evanescia จะไม่ไปกระตุ้น Talent ของ Evanescia (ได้ CB → ได้ Energy) ถ้าอยากให้สองตัวนี้คุยกันได้ ต้องเพิ่ม helper/event กลางใน engine
- **เป้า Ult มาจาก `chooseAllyBuff(ptr)`** (ค่า preset ไม่ใช่เลือกตามสถานการณ์) · ถ้าเป้าเปลี่ยนระหว่างรัน บัฟ `"EMC Ult"` บนตัวเก่ายังถอนตามเวลาปกติ ไม่ค้าง
- **ยังไม่ได้รัน sim** — ควรดู CD / Elation / CB ของเป้า Ult ที่ ATV 1000–5000 ว่าไม่ไหลลงหรือค้าง
