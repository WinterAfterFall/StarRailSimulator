# `src/Defination/Data/Character/Harmony/Hanabi.h`

kit อ้างอิง: `docs/kit-reference/Character/Harmony/sparkle.md` · **ตัวเดียวที่แก้ `maxSp` ของทีม** และใช้ `skillPointList` เป็นแกนของ Talent · `HanabiV1.h` เป็นเวอร์ชันเก่า (ข้าม)

## ตาราง: ความสามารถ → โค้ด

| ส่วนของ kit | ลงที่ไหนในโค้ด | บรรทัด |
|---|---|---|
| ธาตุ / path / energy ult | `setCharBasicStats(101, 110, 110, E, QUANTUM, HARMONY, "Hanabi", STANDARD)` | 5 |
| **เพิ่มเพดาน SP ของทีม** | `maxSp += 3;` (E4 → +1 อีก) | 14-15 |
| **ตั้งตัวเองเป็น driver** | `driverNum = ptr->atvStats->num;` | 21 |
| **Basic ATK** | lambda `BA` — single 100%/10 (energy 30) | 25-35 |
| **Skill** — CD ตาม CD ของ Hanabi + RESPEN | lambda `skill` + `calculateCritdamForBuff(ptr, 24) + 45` + advance เป้า 50% | 37-71 |
| Skill ฟรีเมื่อทีมใช้ SP ครบ 3 | flag `Hnb Free skill` → `genSkillPoint(ptr, 0)` | 38-40, 265 |
| **Ultimate** — Cipher + คืน SP ก้อนใหญ่ | `ultimateList` — `genSkillPoint(ptr, 6)` (E4 → 7) + `buffAllAlly(..., "Hnb Cipher", 3)` | 88-128 |
| **Talent** — ทีมใช้ SP → ศัตรูรับดาเมจเพิ่ม | `skillPointList` → `calStack(ptr, -SP, 3, "Hnb Cipher")` + `buffAllAlly(VUL)` | 241-266 |
| **A-trace** — ทีม ATK +45% | `whenOnFieldList` | 136-139 |
| **Technique** | `startGameList` → `genSkillPoint(ptr, 3)` | 140-142 |
| **Minor traces** | `resetList` | 130-134 |
| **E1** — Cipher ให้ ATK +40% · Hanabi SPD +15% | `ultimateList` · `whenOnFieldList` | 104-108, 138 |
| **E2** — ศัตรู DEF_SHRED ตาม stack | `skillPointList` → `debuffAllEnemy` | 255 |
| **E4** — `maxSp` +1 · Ult คืน SP 7 | บรรทัด 15, 96 | |
| **E6** — บัฟ Skill กระจายให้ทุกคนที่มี Cipher | บล็อก `if (ptr->eidolon >= 6)` ใน Skill / Ult / การถอน | 55-66, 110-121, 157-169 |
| AI: เทิร์นนี้กดอะไร | `turnFunc` → `skill()` เสมอ | 74-76 |
| AI: กดอัลติเมื่อไหร่ | `addUltCondition` — เฉพาะ `BEFORE_TURN` ของเป้าที่บัฟ | 83-86 |

## รากฐาน: `skillPointList` เป็นแกนของตัวละคร

```cpp
skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *spMaker, int SP) { ... }));
```
Hanabi ใช้ list นี้ทำ **5 อย่างพร้อมกัน** (241-266):
1. บันทึก SP ที่ล้นเพดานระหว่างที่ ult ทำงาน (`Hnb sp record`)
2. ครั้งแรกที่มี Talent → เพิ่ม `totalDebuff` ให้ศัตรูทุกตัว (นับ Cipher เป็น debuff)
3. `calStack(ptr, -SP, 3, "Hnb Cipher")` → แจก `Stats::VUL` ให้ทีมตามจำนวน stack ที่เพิ่มจริง
4. คืน energy ให้ Hanabi ถ้าคนใช้ SP มีบัฟ Skill อยู่
5. นับ SP ที่ใช้ในเทิร์นนั้นเพื่อปลด Skill ฟรี

> **`calStack` คืน `pair<int,int>`** (252) — ตัวแรกคือจำนวนที่เพิ่มได้จริงหลัง clamp · ต่างจากที่ `../../Relic/Wavestrider Captain.md` ใช้แบบไม่สนค่าคืน

## รากฐาน: `maxSp` — เพดาน skill point ของทีม

`maxSp += 3;` ตอน `setup` (14) — เป็นตัวแปร global ที่ `sp` ถูก clamp ไว้ · **มีที่เดียวในโปรเจกต์ที่แก้ค่านี้** · การที่ Hanabi ขยายเพดานทำให้ `skillPointList` ของตัวเองต้องคอยเก็บ SP ที่ล้น (`max(0, sp + SP - maxSp)` บรรทัด 243) เพื่อคืนทีหลัง

## รากฐาน: การถอนบัฟที่ลงหลายชั้นพร้อมกัน

บัฟของ Hanabi ซ้อนกัน 3 ชั้น (`Hnb skill`, `Hnb Cipher`, `Hnb E6 Link`) และแต่ละชั้นถอนคนละที่ → **บล็อกถอนถูก copy 2 ที่เต็ม ๆ**: `afterTurnList` (144-196) และ `allyDeathList` (197-240) เนื้อหาเหมือนกันเกือบทุกบรรทัด ต่างแค่ `isBuffEnd` vs `isBuffGoneByDeath`

เป็นตัวอย่างที่ชัดว่า **ยิ่งบัฟซับซ้อน การถอนยิ่งซ้ำซ้อน** — โปรเจกต์ยังไม่มี helper รวมสองทางนี้ (มีในรายการ `future-improvements.md` ข้อ 1)

## จุดที่ควรระวัง

- **`ultimateList` ตั้ง `buffCheck["Hnb Ult"]` แต่ถอนใน `afterTurnList` ของ ally คนไหนก็ได้** (189-193) — ไม่ได้ guard ว่าเป็นเทิร์นของ Hanabi → SP ที่บันทึกไว้อาจถูกคืนเร็วกว่าที่ควร
- **`getBuffNote("Hanabi turn note" + turn->getUnitName())` ถูกอ่านแต่ไม่เคยถูกเขียน** (261) → เงื่อนไขนั้นเป็นจริงเสมอ (`0 != turnCnt` เมื่อ `turnCnt > 0`) → `Hnb sp record` ถูกล้างทุกครั้งที่มีการใช้ SP · **Skill ฟรีจึงปลดได้เฉพาะเมื่อใช้ SP 3 แต้มในครั้งเดียว** ไม่ใช่สะสมภายในเทิร์น
- **`skillPointList` เพิ่ม `totalDebuff` ของศัตรูโดยตรง** (247-249) โดยไม่ผ่าน `debuffApply` → ตัวนับนี้จะไม่มีวันถูกลด
- **บัฟ `Hnb skill` ลง `CD` แบบ delta (`buffNote`) แต่ลง `RESPEN` แบบค่าคงที่ 10** (52) — ตอนถอนก็ถอน `-10` ตรง ๆ (153) · ถ้าลง Skill ซ้ำคนเดิมก่อนบัฟหมด `isHaveToAddBuff` ใน `buffSingle` กันให้แล้ว แต่ E6 ที่กระจายให้คนอื่นใช้ `isHaveToAddBuff(each,"Hnb E6 Link")` แยก ซึ่งไม่มีอายุ (63) → อาจค้าง
- **`addUltCondition` ทางเลือกถูกคอมเมนต์ทิ้ง** (78-81)
- **E6 วน `allyList` แล้วถอน `CD` ของทุกคนเมื่อบัฟของ ally คนเดียวหมด** (157-169) → ถ้าคนอื่นยังมีบัฟอยู่ก็ถูกถอนไปด้วย
