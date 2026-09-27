# `src/Defination/Data/Character/Elation/AventurineWaveflair.h`

kit อ้างอิง: [`docs/kit-reference/Character/Elation/aventurine-waveflair.md`](../../../../../kit-reference/Character/Elation/aventurine-waveflair.md) (ข้อมูลเกม 4.5.54 จาก nanoka) · ชื่อ unit `"Aventurine Waveflair"` (คนละตัวกับ `"Aventurine"` สาย Preservation) · เลือกใน `SettingFunction.h` ด้วยชื่อ `AventurineWaveflair` · prefix บัฟ `AvWF`
คำศัพท์ของ path Elation อยู่ใน [Hibana.md](Hibana.md) — อ่านก่อน

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**
> Participant ID ของ Elation Skill = **156** (ไม่อยู่ในไฟล์ kit ดูจาก nanoka)

## ภาพรวมแบบสั้น

Aventurine • Waveflair เป็น DPS สาย Quantum ที่เก็บแต้มส่วนตัวชื่อ **Fervor**

- ได้ Fervor จาก Skill (+4), Ult (+8), **เพื่อนตีทุกครั้ง (+1)**, A6 (+2), Technique (+2)
- Fervor ถึง 10 → ใช้ Elation Skill **Cheers!** ฟรีทันที (Punchline ตายตัว 20) แล้ว Elation Skill ครั้งถัดไป **ใน Aha Instant** กลายเป็น **All In!** ที่ใช้ Fervor ทั้งหมดเป็น bounce เพิ่ม
- ยิ่งทีมตีบ่อย Fervor ยิ่งขึ้นเร็ว

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 107, Quantum, Elation · HP/ATK/DEF 1164/485/606 · Energy 130 | `setCharBasicStats(107,130,130,...)` | 13-14 |
| build | CR / SPD / Quantum DMG / ERR ตาม nanoka · เป้า SPD 140 (เปิด A2) | `setSpeedRequire(140)` · `setRelicMainStats(...)` | 17-21 |
| นับเข้า Elation ในทีม | — | `elationCount++` | 23 |
| **Basic ATK** | 100% ATK เดี่ยว · toughness 10 · SP +1 · Energy 20 | lambda `ba` | 92-104 |
| **Skill** | 240% ATK ทุกตัว · toughness 10 · SP −1 · Energy 30 · Punchline +4 · Fervor +4 | lambda `skill` | 107-135 |
| ↳ ถือ CB | Skill ตีเพิ่ม 40% Elation ทุกตัว | action `ELATION_DMG` แยกก้อน | 117-126 |
| **Ultimate** | 400% ATK ทุกตัว · toughness 20 · Punchline +6 · Fervor +8 · SPD +30% 4 เทิร์น | `ultimateList` · บัฟ `"AvWF Ult"` | 149-176 |
| ↳ ถือ CB | Ult ตีเพิ่ม 72% Elation ทุกตัว | action `ELATION_DMG` แยกก้อน | 157-166 |
| AI เลือกท่า | — | `sp > spSafety` → Skill ไม่งั้น BA | 139-142 |
| **Talent: Fervor** | เพดาน 30 (E2 50) · ถึง 10 (E1 10/20/30, E2 +40/50) → Cheers! ฟรีด้วย PL 20 แล้ว Elation Skill ครั้งถัดไปใน Aha เป็น All In! | `addFervor(n)` จำกัดเพดาน · ข้ามเกณฑ์ตัวไหน (`ก่อน < เกณฑ์ ≤ หลัง`) → `freeCheers()`: ตั้งธง `"AvWF Free Cast"` → `elationSkillTrigger(20,{ชื่อเขา})` → ตั้งธง `"AvWF All In Ready"` · ถ้าคิว Aha ยังรันอยู่ → **พักไว้** (ดูหัวข้อ "Cheers! ที่ถูกพัก") | 73-86, 54-70 |
| **Talent: เพื่อนตี** | เพื่อนใช้การโจมตี → Fervor +1, Punchline +1 | **`whenAttackList`** (user 2026-09-28) — ยิงครั้งละ 1 ต่อ attack action รวมถึง **Elation Skill แต่ละตัวใน Aha Instant** · นับเฉพาะผู้โจมตีคนแรกของ action (โจมตีร่วม = 1) · ข้ามถ้าเป็นของเขาเอง | 236-248 |
| **Talent: CB อยู่นานขึ้น** | CB ของเขาอยู่นานขึ้น 1 เทิร์น | CB จาก Aha: `extendBuffTime(..., cbDuration + 1)` ใน `afterAhaInstantList` · CB ที่เขาได้เอง: `gainCB` สร้างก้อน `"AvWF CB <n>"` อายุ `cbDuration + 1` แล้วถอนเองตอนหมด | 224, 36-42, 296-300 |
| **Elation Skill: Cheers!** | 60% Elation ทุกตัว (toughness 10) + 10 × 18% สุ่มเป้า · Energy 5 | `elationSkillList` priority 156 · bounce toughness 1/3 ต่อครั้ง | 182-214 |
| **Elation Skill: All In!** | เหมือน Cheers! (toughness AoE 20 / bounce 1/3 ต่อครั้ง) แล้วใช้ Fervor ทั้งหมด → bounce 21% เพิ่ม 1 ครั้งต่อ Fervor | ตัดสินตอนสร้าง action: เป็น All In! ถ้า (อยู่ใน Aha และมีธง `All In Ready`) หรือ (E6 และใช้ Elation Skill ไปแล้ว ≥ 2 ครั้ง) · อ่าน Fervor เป็นจำนวน bounce แล้วตั้งเป็น 0 | 183-193, 211 |
| อยู่ใน Aha ไหม | — | ธง `"AvWF In Aha"` เปิดใน `beforeAhaInstantList` ปิดใน `afterAhaInstantList` · Cheers! ฟรีถือว่า**ไม่อยู่ใน Aha** เสมอ (ธง `Free Cast`) | 216-218, 221, 183-184 |
| **Technique** | เข้าต่อสู้: 100% ATK ทุกตัว (toughness 20) · Fervor +2 · CB +20 | `startGameList` · `turnReset = 0` | 270-287 |
| **Minor traces** | CR +18.7 · Elation +10 · SPD +9 | `resetList` | 305-307 |
| **A2** | SPD ≥ 140 → Elation +30% แล้ว +1% ต่อ SPD ที่เกิน (นับเกินได้ 200) | `statsAdjustList` ใส่ส่วนต่างเทียบ `buffNote["AvWF A2"]` · ปลุกครั้งแรกใน `whenOnFieldList` | 324-331, 320 |
| **A4 (มี Elation ตัวอื่น)** | ทั้งทีม Elation +20% · ตัวเขา +80% เพิ่ม ตลอดที่อยู่ในสนาม | `whenOnFieldList` ใส่ถาวร | 315-319 |
| **A4 (Elation ตัวเดียว)** | Elation Skill นับเป็น Follow-Up ATK · เพื่อนตี → CB +2, Punchline +1, SPD ของ Aha +25 จนจบ Aha Instant | `addAttackType(AType::FUA)` · ใน `whenAttackList` (ตัวเดียวกับ Talent) · SPD ของ Aha ผ่าน global ใหม่ `ahaExtraFlatSpeed` (ดูหัวข้อล่าง) ล้างเป็น 0 ใน `afterAhaInstantList` | 212, 240-245, 226-230 |
| **A6** | CD +48% · เพื่อนใช้ BA / Skill / FuA / Ult → ทั้งทีม CD +48% 3 เทิร์น + Fervor +2 · สูงสุด 6 ครั้ง นับใหม่เมื่อเขาใช้ Skill | CD ใน `resetList` · `afterAllyActionList` (ครอบ action บัฟด้วย เช่น Skill ของ Yao Guang) · บัฟ `"AvWF A6"` · รีเซ็ตนับใน Skill | 309, 256-267, 114 |
| **E1** | RES PEN +24% · เกณฑ์ Cheers! ฟรี 10/20/30 | `resetList` · `addFervor` | 310, 80 |
| **E2** | เพดาน Fervor 50 · เกณฑ์ +40/50 · หลังใช้ Elation Skill Fervor +4 | `addFervor` · ท้าย Elation Skill | 74, 81, 201 |
| **E4** | ใช้ Skill → ทั้งทีมเจาะ DEF 18% 3 เทิร์น | `buffAllAlly(...,"AvWF E4",3)` | 115 |
| **E6** | Elation merrymake +25% · ใช้ Elation Skill ครบ 2 ครั้งแล้ว ครั้งต่อ ๆ ไปเป็น All In! · All In! นอก Aha ไม่ใช้ Fervor | `resetList` · เงื่อนไข `allIn` · ไม่ตั้ง Fervor = 0 ถ้า E6 และไม่อยู่ใน Aha | 311, 185, 193 |
| ถอนบัฟ | — | `afterTurnList` ตอนเทิร์นผู้ถือ `isBuffEnd` → ใส่ค่าลบ | 289-301 |

## `ahaExtraFlatSpeed` — engine เพิ่มใหม่

`ahaSpeedAdjust()` ([Action_value.h](../../../Function/Combat/Action_value.md)) คำนวณ SPD ของ Aha **ใหม่ทั้งก้อน** จาก SPD ของสาย Elation ทุกครั้งที่มีใครสาย Elation ได้บัฟ SPD ถ้าบวก SPD ให้ Aha ตรง ๆ ค่าจะหายตอนคำนวณใหม่รอบถัดไป

จึงเพิ่ม global `double ahaExtraFlatSpeed` ใน `src/Setting.h` · `ahaSpeedAdjust` บวกค่านี้เข้าไปทุกครั้ง · `reset()` ใน `SetCombat.h` ตั้งเป็น 0 ทุกรอบรัน

A4 (solo) ใช้แบบนี้: เพื่อนตี → `ahaExtraFlatSpeed += 25` → `ahaSpeedAdjust` · Aha Instant จบ → ตั้งเป็น 0 → `ahaSpeedAdjust`

## Cheers! ที่ถูกพัก

`whenAttackList` ของ Elation Skill ยิง**ระหว่าง**ที่ `runAhaInstantBar()` ยังวนคิว `ahaInstantBar` อยู่ (ตัวที่กำลังทำงานยังค้างหน้าคิว) ถ้า Fervor ข้ามเกณฑ์ตรงนั้นแล้วยิง `elationSkillTrigger` ทันที มันจะรัน `runAhaInstantBar()` ซ้อนบนคิวเดียวกัน → วนกินคิวของ Aha ตัวนอกจนหมด แล้วตัวนอก `pop()` คิวว่าง = พัง

จึงให้ `freeCheers()` (บรรทัด 54-63) เช็คก่อน: ถ้า `ahaInstantBar` ไม่ว่าง → บวก `buffNote["AvWF Pending Cheers"]` แล้วออก · `flushCheers()` (65-70) ยิงที่พักไว้ตอนคิวว่างแล้ว เรียกจาก 2 จุด:

- `afterAhaInstantList` (บรรทัด 222) — หลัง Aha Instant จบ
- `afterAttackActionList` (บรรทัด 251-253) — หลัง `runAhaInstantBar` ของ `elationSkillTrigger` (นอก Aha) วนจบ ซึ่งคิวว่างแล้ว

## จุดที่ตีความเอง

- **เกณฑ์ Fervor ยิงครั้งเดียวต่อรอบ** — ต้องข้ามเกณฑ์ขาขึ้น (`ก่อน < เกณฑ์ ≤ หลัง`) · All In! ตั้ง Fervor เป็น 0 → เกณฑ์กลับมายิงได้อีก · ได้หลายเกณฑ์ในครั้งเดียว (เช่น +8 จาก 5 ไป 13 ที่ E1) = ยิงตามจำนวนเกณฑ์ที่ข้าม
- **"เพื่อนตี" นับจาก `whenAttackList`** — เดิมใช้ `afterAttackActionList` ซึ่งใน Aha ยิงครั้งเดียวด้วยตัวแทน และตัวแทนคือท่าของเขาเอง (Participant ID 156 สูงสุด อยู่หน้าคิว) ทำให้ Elation Skill ของเพื่อนไม่ให้ Fervor เลย · `whenAttackList` ยิงแยกทุก Elation Skill · กล่อง Top Loot Box ที่ SW999 เปิดใน EBA (เรียกตรง ไม่ผ่าน action) ไม่นับ · กล่องจาก Zone (ผ่าน action bar) นับ
- **toughness ของ Elation Skill (user กำหนด 2026-09-28)** — ค่าดิบของเกม (raw) หาร 3 เป็นหน่วย sim: Cheers! AoE raw 30 → 10 · All In! AoE raw 60 → 20 · **ทุก bounce raw 1 → 1/3** (รวม bounce จาก Fervor) · ตัวเลข ST ใน kit (3.33) จึงเป็น**ยอดรวม** ของ 10 bounce (10 × 1 raw = 10 raw = 3.33) — ตรงกับวิธีอ่านของ SW999
- **A6 นับทั้ง action บัฟ** (ใช้ `afterAllyActionList` ไม่ใช่เฉพาะ attack) เพราะ kit บอก "ใช้ Skill / Ult" ไม่ได้บอกว่าต้องเป็นการโจมตี
- **ตัดทิ้ง**: Technique ที่กันการโจมตีในแมพ (ไม่เกี่ยวกับการต่อสู้)

## จุดที่ควรระวัง

- **Cheers! ฟรีถูกยิงจากข้างใน event ของ action อื่น** (`afterAttackActionList` / `afterAllyActionList`) → `elationSkillTrigger` รัน Elation Skill ทันทีกลาง event นั้น แบบเดียวกับที่ Hibana E2 ทำใน `afterAhaInstantList`
- **ถ้า `ahaExtraFlatSpeed` ไม่ถูกล้าง** SPD ของ Aha จะค้าง · ตอนนี้ล้างใน `afterAhaInstantList` เฉพาะตอน solo
- **ยังไม่ได้รัน sim** — ควรดู Fervor (`buffNote["AvWF Fervor"]`), CD จาก A6 และ SPD ของ Aha ที่ ATV 1000–5000
