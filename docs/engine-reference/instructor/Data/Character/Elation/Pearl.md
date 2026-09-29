# `src/Defination/Data/Character/Elation/Pearl.h`

kit อ้างอิง: [`docs/kit-reference/Character/Elation/pearl.md`](../../../../../kit-reference/Character/Elation/pearl.md) (ข้อมูลเกม 4.5.54 จาก nanoka) · ชื่อ unit `"Pearl"` · เลือกใน `SettingFunction.h` ด้วยชื่อ `Pearl`
คำศัพท์ของ path Elation อยู่ใน [Hibana.md](Hibana.md) — อ่านก่อน

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**
> Participant ID ของ Elation Skill = **104** (ไม่อยู่ในไฟล์ kit ดูจาก nanoka) · สเกลกับ **DEF**

## ภาพรวมแบบสั้น

Pearl เป็นซัพพอร์ต/ฮีลเลอร์สาย Elation (Ice)

- **Certified Banger (CB) ของเธอไม่หมดอายุ** เพดาน 50 — ได้จาก Skill, Ult, A4 (ทุกต้นเทิร์นเพื่อน) และ Aha
- **Ult** ใส่ "Deep Learning" ให้เพื่อน 1 คน (= Aesthetic Archetype) → ดันแอคชันเขาตามจำนวนตัว Elation ในทีม · ทีม Elation 4 ตัวขึ้นไป → เขาได้ extra turn
- ระหว่าง Deep Learning Basic ของ Pearl กลายเป็น AoE + ฮีล แล้วตามด้วย Elation DMG 60% **ที่คิดจาก stat ของ Archetype** (3 ครั้ง)
- **Elation Skill** ทำให้การตีครั้งถัดไปของทุกคนมี Elation DMG เพิ่ม

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 99, Ice, Elation · HP/ATK/DEF 1203/466/728 · Energy 180 | `setCharBasicStats(99,180,180,...)` | 17-18 |
| build | Body Outgoing Healing / SPD / DEF% / ERR · substat DEF% | `setRelicMainStats(...)` | 21-23 |
| นับเข้า Elation ในทีม | — | `elationCount++` | 25 |
| **Talent: CB ของ Pearl** | ไม่หมดอายุ · เพดาน 50 | กองเดียว `buffNote["Pearl CB"]` · `gainCB(x)` บวกไม่เกิน 50 | 35-41 |
| ↳ CB จาก Aha | CB จาก Aha ก็เป็นของเธอ = ไม่หมดอายุ | `afterAhaInstantList`: ถอด CB ก้อนที่ engine ใส่ (ชื่อใน `cbCheck.back()`) ออกจากระบบหมดอายุ — หักค่าออก, ล้าง check/end, ลดตัวนับของ entry นั้น 1 — แล้ว `gainCB(PL)` เข้ากอง | 307-318 |
| ↳ CB ตั้งต้น 20 | — | `startGameList` ย้าย `"CB Buff"` 20 ตอนเริ่ม (engine ใส่ให้ทุกตัว Elation) เข้ากองถาวร | 334-339 |
| **Basic ATK** | 90% DEF เดี่ยว · toughness 10 · SP +1 · Energy 20 | lambda `ba` · `DmgSrcType::DEF` | 101-113 |
| **Enhanced Basic** (Deep Learning) | 100% DEF ทุกตัว · toughness 10 (user) · SP +1 · Energy 30 · ฮีลทุกคน 8% DEF + 160 และคน HP% ต่ำสุดอีกเท่าเดิม | lambda `eba` · `teamHeal(8,160)` | 118-163 |
| ↳ Starry Night | Archetype เป็นสาย Elation + Pearl ถือ CB → Elation 15% ทุกตัว (ของ Pearl) | action `ELATION_DMG` แยก | 128-137 |
| ↳ Elation จาก Archetype | 60% Ice Elation ทุกตัว คิดด้วย stat ของ Archetype | action ที่ **attacker = Archetype** + `damageElement = ICE` (ดาเมจลงบัญชี Archetype) | 138-153 |
| ↳ Charge | 3 Charge · Enhanced Basic ใช้ 1 · หมด → Deep Learning จบ | `buffNote["Pearl DL Charges"]` → `endDeepLearning()` | 154-155, 88-95 |
| **Skill** | CB +15 · ฮีลทุกคน 12% DEF + 240 และคน HP% ต่ำสุดอีกเท่าเดิม · SP −1 · Energy 30 | lambda `skill` | 166-177 |
| ฮีลทีม | — | `teamHeal`: หาคน HP% ต่ำสุดใน `allyList` → `restoreHP(lowest, ×2, ×1)` | 60-72 |
| AI เลือกท่า | — | Deep Learning ยังมี Charge → Enhanced Basic · ไม่งั้น `sp > spSafety` → Skill · ไม่งั้น BA | 181-185 |
| **Ultimate** | CB +20 · Deep Learning ให้เพื่อน 1 คน (ไม่ใช่ Pearl) · ดันแอคชัน 10 / 15 / 30% ตามจำนวน Elation 1 / 2 / 3+ | เป้า = `chooseCharacterBuff(ptr)` · `startDeepLearning(target,3)` · `actionForward` | 197-251 |
| ↳ extra turn (Elation 4+) | Archetype ได้ extra turn · ต้นเทิร์นได้ CB 30 + Punchline 60 ถอนออกตอนจบ | ให้ CB/PL → เรียก `target->turnFunc()` ทันที → action ที่เพิ่งเข้าคิวตั้ง `turnReset = false` (ตามหลัก extra turn ไม่แตะ ATV / turnCnt) · จำ action สุดท้ายไว้ใน `extraLast` · `afterAllyActionList` เจอ action นั้น → ถอน CB/PL | 216-246, 254-260 |
| **Talent: ลดดาเมจ** | เพื่อน HP ≤ 50% รับดาเมจ −30% | `updateLowHp` เช็คทุกครั้งที่ HP เพื่อนเปลี่ยน (`hpDecreaseList` / `healingList`) → ใส่/ถอด `Stats::DMG_REDUCE` +30 บนตัวเพื่อน (stat ใหม่ที่สูตรรับดาเมจอ่าน — ดู [CalDmgReceive.md](../../../Function/Calculate/CalDmgReceive.md)) | 263-276 |
| **Talent: Repellency** | CB 1 = Repellency 200 · เพื่อนโดนตี → ใช้ Repellency กันดาเมจ 60% | engine ใหม่: กองกลาง `repellency` (`Setting.h`) + `Stats::BLOCK` · `gainCB` เติมกอง `CB × 200` · ทุกคนได้ `BLOCK` 60 (`whenOnFieldList`) · `decreaseBlock()` ใน engine หักดาเมจก่อนโล่ · `syncRepellency` (เรียกใน `hpDecreaseList`) ลด CB ของ Pearl ให้เท่า `repellency / 200` | 35-41, 47-53, 362, 270-273 |
| **Elation Skill** | ทุกคนตีครั้งถัดไป → Elation DMG ธาตุตัวเอง 10 / 15 / 20 / 40% (ตาม Elation 1 / 2 / 3 / 4+) · Energy 5 | ตั้งธง `"Pearl Elation Bonus"` ให้ทุกคนใน `allyList` · `whenAttackList` เจอธง → ยิง Elation ใส่**เป้าหลัก** (`mainEnemyNum`, user) แล้วล้างธง · priority 104 | 288-292, 294-304 |
| **Technique** | เริ่มต่อสู้: CB +20 · Deep Learning 2 Charge ให้ Archetype | `startGameList` | 340-343 |
| **Minor traces** | DEF +22.5% · SPD +9 · Elation +10% (Effect RES +10% ไม่ได้ใช้) | `resetList` | 348-350 |
| **A2** | DEF ≥ 2400 → Elation +32% แล้ว +3% ทุก 100 DEF ที่เกิน (นับเกินได้ 3600) · Outgoing Healing + 20% ของ Elation | `statsAdjustList` — DEF เปลี่ยน → คิด Elation · Elation เปลี่ยน → คิด Healing · ปลุกครั้งแรกใน `whenOnFieldList` | 367-380, 363 |
| **A4** | ต้นเทิร์นเพื่อนทุกคน → CB +5 (ได้รวมไม่เกิน 50 ต่อรอบ รีเซ็ตตอนต้นเทิร์น Pearl) | `beforeTurnList` · ตัวนับ `"Pearl A4 Gained"` · (Effect RES +50% / ล้างดีบัฟ ไม่ได้ทำ) | 321-329 |
| **A6** | หลัง Ult ถ้า Archetype เป็นสาย Elation → Ult ครั้งถัดไปของเขาให้ Pearl Energy fixed 90 (ไม่ซ้อน) | ธง `"Pearl A6"` · `whenUseUltList` | 206, 279-285 |
| **E1** | Elation 2 / 3 / 4+ ตัว → ทั้งทีม Elation +10 / 20 / 60% · (กันตาย ไม่ได้ทำ) | `whenOnFieldList` | 356-359 |
| **E2** | ทั้งทีม Elation DMG merrymake +15% · Ult ดันแอคชันตัว Elation อื่นด้วย · extra turn ได้ CB / PL ×2 | `whenOnFieldList` · ใน Ult | 360, 210-215, 219-220 |
| **E4** | Elation Skill ×2 | `ratio *= 2` | 299 |
| **E6** | ระหว่าง Deep Learning ทั้งทีม RES PEN +20% · Enhanced Basic Elation เพิ่ม 240% (stat ของ Archetype) | `startDeepLearning` / `endDeepLearning` · ก้อน 240 ใน action ของ Archetype | 84, 93, 146-150 |

## จุดที่ตีความเอง / ตัดทิ้ง

- **ส่วนเอาตัวรอดที่ไม่ได้ทำ** — Effect RES, ล้างดีบัฟ, กันตาย (E1) · ลดดาเมจตอน HP ต่ำ (`DMG_REDUCE`) และ Repellency (`BLOCK` + `repellency`) **ทำแล้ว** · CB ของ Pearl จึงลดลงเมื่อเพื่อนโดนตี · sim คิดดาเมจฝั่งเราเป็นหลัก · 
- **Elation DMG ของ Deep Learning ลงบัญชี Archetype** — ใช้ Archetype เป็น attacker เพื่อให้ stat ถูก (Elation, CB, คริ) ดาเมจรวมทีมเท่าเดิม แต่ยอดรายตัวย้ายไปอยู่กับ Archetype
- **Elation Skill ตีเป้าหลัก** (user 2026-09-28) — ท่า AoE ได้แค่เป้าเดียว
- **extra turn ของ Archetype** เรียก `turnFunc()` ของเขาแล้วปิด `turnReset` ของทุก action ที่เพิ่งเข้าคิว · ถ้า `turnFunc` ไม่ได้ใส่อะไรเข้าคิว → ถอน CB/PL ทันที
- **เป้า Ult/Technique = `chooseCharacterBuff(ptr)`** (ตัวละคร ไม่ใช่ memosprite) · ถ้าเป้าเป็น Pearl เอง → ได้แค่ CB ไม่มี Deep Learning

## จุดที่ควรระวัง

- **CB ที่ตัวละครอื่นให้ Pearl** (เพิ่ม 2026-09-29 user สั่ง): Pearl ตั้ง `ptr->receiveCB = gainCB` (บรรทัด 43-44) → CB จาก Ult ของ EMC เข้ากองถาวรเพดาน 50 + นับเป็น Repellency เหมือน CB ของเธอเอง ไม่เป็นบัฟมีอายุ · ตัวละครที่ให้ CB คนอื่นในอนาคตต้องเช็ค `receiveCB` แบบ `EMC.h:41-45`

- **Pearl ยุ่งกับ `cbCheck` ของ engine** — ลดตัวนับของ entry ล่าสุดเอง ถ้า engine เปลี่ยนรูปแบบ `cbCheck` (tuple ชื่อ / จำนวนตัว / ค่า) ต้องแก้ตาม
- **พบบั๊ก engine ระหว่างทำ**: CB ตั้งต้น 20 (`"CB Buff"` ใน `SetCombat.h` `reset()`) ไม่มีใครถอด → ทุกตัว Elation ได้ CB +20 ถาวร · Pearl ย้ายของตัวเองเข้ากองถาวรอยู่แล้วจึงไม่กระทบ · แยกเป็นงานต่างหาก
- **ยังไม่ได้รัน sim** — ควรดู CB ของ Pearl (ไม่เกิน 50), RES PEN ทีมตอน Deep Learning จบ (กลับ 0) และ CB / Punchline หลัง extra turn
