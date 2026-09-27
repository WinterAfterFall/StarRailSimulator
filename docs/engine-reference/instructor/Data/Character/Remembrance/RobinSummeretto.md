# `src/Defination/Data/Character/Remembrance/RobinSummeretto.h`

kit อ้างอิง: [`docs/kit-reference/Character/Remembrance/robin-summeretto.md`](../../../../../kit-reference/Character/Remembrance/robin-summeretto.md) (รูปแบบย่อ nanoka 4.5.54 — user อัปเดต 2026-09-28 เทียบแล้วตรงกับโค้ดทุกข้อ ยกเว้นโล่ / CC ที่ตัดไว้) · ชื่อ unit `"Robin Summeretto"` · memosprite `"Summer Songbirds"` · เลือกใน `SettingFunction.h` ด้วยชื่อ `RobinSummeretto` · prefix บัฟ `RobinSM`

> สถานะ: เขียนใหม่ 2026-09-28 · `g++ -fsyntax-only` ผ่าน · **ยังไม่ได้รัน sim**
> ระดับ: Basic Lv.6 · Skill/Ult/Talent Lv.10 · Memosprite Skill/Talent Lv.6 (max 10 เหมือน Basic)

## ภาพรวมแบบสั้น

Robin • Summeretto เป็นซัพพอร์ตสาย Remembrance (Wind) สเกล **Max HP**

1. **Skill** เรียกนก "Summer Songbirds" ตัวแรก (Bessie) ลงสนาม — นอก Fever นกอยู่ในสนามแต่**ไม่ได้เทิร์น**
2. **Vibes** — เพื่อนตีทีหนึ่ง / ฮีลครั้งแรกในเทิร์น → Robin ได้ Vibes +1 · ครบ 6 → นกตัวที่ 2 (Drummie) · ครบ 12 → ตัวที่ 3 (Paddie)
3. **ครบ 3 ตัว → Fever**: นกได้เทิร์น (ตี AoE 150% HP ของนก) · มี countdown SPD 140 คอยหัก Vibes ครึ่งหนึ่ง (อย่างน้อย 12) · Robin **ไม่ได้เทิร์น**จนกว่า Fever จบ · ทีมเจาะ DEF (15% + 0.5% × Vibes) · Robin กับนก DMG +(60% + 2% × Vibes)
4. Vibes หมด → นกหายไป Fever จบ → Robin ดันแอคชัน 50% แล้วต้อง Skill เรียกนกใหม่

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ทำอะไรในเกม | โค้ดทำยังไง | บรรทัด |
|---|---|---|---|
| ค่าพื้นฐาน | SPD 95, Wind, Remembrance · HP/ATK/DEF 1203/602/485 · Energy 140 | `setCharBasicStats(95,140,140,...)` | 14-15 |
| นก Summer Songbirds | HP 70% ของ Robin · SPD 180% ของ Robin | `setMemoStats(ptr,0,70,0,180,...)` · นกเป็น memosprite ตัวเดียว นับจำนวนสมาชิกใน `buffNote["RobinSM Members"]` | 20 |
| countdown ของ Fever | SPD 140 | `setCountdownStats(ptr,140,"RobinSM Fever")` | 21 |
| build | Body HP% / SPD / HP% / ERR ตาม nanoka | `setRelicMainStats(...)` | 30 |
| **Basic ATK** | 50% Max HP เดี่ยว · toughness 10 · SP +1 · Energy 20 | lambda `ba` · `DmgSrcType::HP` | 160-172 |
| **Skill** | ไม่มีนก → เรียก Bessie (+20 Energy จาก Near the Sea's Heartbeat) · มีนก → ฮีลนก 100% HP ของนก + Vibes 6 · SP −1 · Energy 30 | `memo->summon(100)` แล้วตั้ง `ATV_FREEZE` (ไม่มีเทิร์น) · มีนก → `restoreHP(memo, TOTAL_HP 100)` + `gainVibes(ptr,6)` | 175-196 |
| AI เลือกท่า | — | ไม่มีนก หรือ `sp > spSafety` → Skill ไม่งั้น BA | 224-227 |
| **Ultimate** | เพื่อน 1 คน (ไม่ใช่ Robin) ดันแอคชัน 100% + Energy fixed 20% ของ Max Energy เขา · Special Guest 2 เทิร์น | เป้า = `chooseAllyBuff(ptr)` (ถ้าเป็น Robin เองจะไม่ทำอะไร) · `increaseEnergy(target,20,0)` = % ของ Max Energy ไม่คูณ ERR · จำเป้าด้วย `setBuffSubUnitTarget` | 251-275 |
| Special Guest ลดเวลา | ลด 1 ตอน**เริ่มเทิร์นของ Robin** | `beforeTurnList` ตอนเทิร์น Robin → ลด `"RobinSM Special Guest Turns"` ถึง 0 → ถอด | 288-296 |
| **Talent: Vibes จากการตี** | เพื่อนใช้การโจมตี → +1 · ถ้าเป็น Special Guest หรือ summon ของเขา → +2 เพิ่ม | `whenAttackList` (ยิงทุก action รวม Elation Skill ใน Aha) · นับเฉพาะผู้โจมตีคนแรก (โจมตีร่วม = 1) | 299-305 |
| **Talent: Vibes จากการฮีล** | เพื่อนฮีลครั้งแรกในเทิร์นของใครก็ตาม → +1 | `healingList` · กันซ้ำด้วย key "ผู้ฮีล + ยูนิตที่ถือเทิร์น + turnCnt" | 308-315 |
| `gainVibes` | เพดาน 50 (E2 70) | รวม A4 / E2 / A2 แล้วเรียก `checkMembers` + `updateFeverBuffs` | 139-154 |
| **Talent: สมาชิก + เข้า Fever** | มี Bessie อยู่: Vibes ≥ 6 → 2 ตัว · ≥ 12 → 3 ตัว · ครบ 3 → Fever + Zone | `checkMembers` (จำนวนสมาชิกไม่ลดจนกว่านกหาย) → `enterFever` | 102-111, 62-81 |
| **Fever** | Robin ไม่ได้เทิร์น · นกได้เทิร์น · countdown โผล่ | `ptr->status = ATV_FREEZE` · นก `ALIVE` + `resetATV` · `fever->summon()` | 62-81 |
| **Zone + DMG ใน Fever** | ทีมเจาะ DEF (15% + 0.5% × Vibes) · Robin + นก DMG +(60% + 2% × Vibes) | `updateFeverBuffs` ใส่ส่วนต่างเทียบ `buffNote` ทุกครั้งที่ Vibes เปลี่ยน · นอก Fever = 0 | 51-60 |
| **ศัตรูรับดาเมจตามจำนวนนก** | 8% / 12% / 16% | `updateMemberVul` ใส่ส่วนต่าง VUL ให้ศัตรูทุกตัว | 43-48 |
| **Memosprite Skill** | 150% HP ของนก ทุกตัว · toughness 10 · Robin +20 Energy | `memoSkill` · `AType::SKILL` + `SUMMON` · E6 ×2 = 300% | 199-220 |
| **countdown ของ Fever** | หัก Vibes 50% (อย่างน้อย 12) · Vibes 0 → นกหาย Fever จบ | `fever->turnFunc` · ยังไม่จบ → `resetTurn(fever)` เอง (countdown ไม่รีเซ็ตให้อัตโนมัติ) | 234-244 |
| **ออกจาก Fever** | นกหาย · Robin ได้เทิร์นอีก + ดันแอคชัน 50% (Astride Summer's Nightwind) | `exitFever` ล้าง Zone / DMG / VUL / E4 · `memo->death()` · `ptr->status = ALIVE` · `actionForward(...,50)` | 83-99 |
| **Technique** | เริ่มต่อสู้: ดันแอคชัน 20% · Vibes +6 · ทีม DMG +30% 2 เทิร์น | `startGameList` | 325-330 |
| **Minor traces** | HP +18% · SPD +14 · CR +6.7% | `resetList` | 349-351 |
| **A2** | เพื่อนที่ทำให้ได้ Vibes: ATK สูงกว่า Robin → ATK +(16% + 0.4% × Vibes) ของ HP Robin · ไม่งั้น CD +(40% + 1.5% × Vibes) · 2 เทิร์น | `a2(source)` คำนวณใหม่ทุกครั้งที่ได้ Vibes · ใส่ทั้ง `TEMP` และ `NONE` (บัฟจากคนอื่น) · จดค่าไว้บนตัวผู้รับ · ถอนใน `afterTurnList` | 114-130, 336-345 |
| **A4** | เพื่อนฮีล Robin / นก → Groove 12 · ได้ Vibes ครั้งแรกในเทิร์นใดก็ตาม ถ้ามี Groove → ใช้ 1 → Energy fixed 3 | `healingList` ตั้ง Groove · `gainVibes` ใช้ Groove ครั้งแรกต่อเทิร์น | 310, 141-145 |
| **A6** | CR +50% Robin และนก | ใส่ Robin ใน `resetList` · นกได้ตามเพราะ `memospriteReset` ก๊อป stat ของ Robin ทั้งก้อน | 353 |
| **E1** | นกนับดาเมจที่ไม่ใช่ True DMG ของทีม 100% · Memosprite Skill ตี True DMG (11% + 0.1% × Vibes) ของยอดนับ แล้วลดยอดนับครึ่งหนึ่ง | `afterDealingDamageList` สะสม `"RobinSM E1 Tally"` · `calDamageNote` ใส่เป้าหลัก | 318-322, 205-209 |
| **E2** | ทีม RES PEN +18% · เพดาน Vibes +20 · ability ของเพื่อนที่ทำให้ได้ Vibes ครั้งแรกในเทิร์น → +2 | `whenOnFieldList` · `vibesCap` · ใน `gainVibes` | 358, 38-40, 146-149 |
| **E4** | เข้า Fever → Vibes +12 · นก SPD +(20% + 0.5% × Vibes) | ใน `enterFever` · ถอน SPD ตอนออก | 68-73 |
| **E6** | Memosprite Skill ×2 · ใน Fever เก็บ Ult ได้ 2 ครั้ง · เข้า Fever ครั้งแรก และทุกเทิร์น countdown → Energy fixed 140 | `mtpr` 300 · Energy ที่ล้นหลอดระหว่าง Fever เก็บเข้า `buffNote["RobinSM E6 Bank"]` (สูงสุด 140 = Ult อีก 1 ครั้ง) · ใช้ Ult แล้วเติม Energy คืนจากคลัง · Max Energy คงที่ 140 · `increaseEnergy(ptr,0,140)` | 212, 74-79, 235, 279-285, 252-257 |

## จุดที่ตีความเอง / ตัดทิ้ง

- **นก 3 ตัว = memosprite ตัวเดียว** — engine มี memosprite ได้ตัวเดียวต่อตัวละคร จึงนับจำนวนสมาชิกแทน (มีผลกับ VUL ศัตรู และเงื่อนไขเข้า Fever) · Memosprite Skill ตีครั้งเดียวต่อเทิร์นนก
- **นอก Fever นกไม่มีเทิร์น** — ใช้สถานะ `ATV_FREEZE` (อยู่ในสนาม เป็นเป้าได้ แต่ไม่ได้เทิร์น) แบบเดียวกับที่ Phainon ใช้
- **Robin ไม่ได้เทิร์นใน Fever** — `ATV_FREEZE` เหมือนกัน · ยังกด Ult ได้ (`ultUseCheck` เช็คแค่ `isExisted`)
- **Vibes จาก Shield ไม่ได้ทำ** — engine ไม่มี event การให้โล่
- **"ครั้งแรกในเทิร์นของใครก็ตาม"** ใช้ key = ชื่อยูนิตที่ถือเทิร์น + `turnCnt` ของมัน
- **E6 เก็บ Ult 2 ครั้ง** (user 2026-09-28) — Max Energy คงที่ 140 · ระหว่าง Fever ส่วนที่ล้นหลอดเก็บแยกใน `buffNote["RobinSM E6 Bank"]` (สูงสุด 140) · ทุกครั้งที่ใช้ Ult (หลัง `ultUseCheck` หัก Energy แล้ว) เติม Energy คืนจากคลังเท่าที่หลอดรับได้ → ครบ 140 อีกรอบก็กด Ult ต่อได้ · คลังที่เก็บไว้ไม่หายตอนจบ Fever
- **ตัดทิ้ง**: CC (ล้าง / กัน), Special Guest "ห้ามให้เพื่อนคนอื่นได้ action advance"

## จุดที่ควรระวัง

- **ผู้ได้ A2 อาจเป็นนก** — นกตีแล้ว Robin ได้ Vibes → A2 ลงที่นก (เทียบ ATK ของนกกับ Robin)
- **Special Guest ลดเวลาตอนเริ่มเทิร์น Robin** แต่ใน Fever Robin ไม่มีเทิร์น → Special Guest จะค้างยาวตลอด Fever (ตรงตาม kit)
- **`updateFeverBuffs` ใส่ DEF shred ให้ทุกคนใน `allyList`** รวม memosprite ของตัวอื่น
- **ยังไม่ได้รัน sim** — ควรดู Vibes, จำนวนนก, สถานะ Fever และ DEF shred / DMG ที่ ATV 1000–5000 ว่ากลับเป็น 0 ทุกครั้งที่ Fever จบ
