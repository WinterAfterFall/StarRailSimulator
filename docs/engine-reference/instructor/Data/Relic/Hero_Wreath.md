# `src/Defination/Data/Relic/Hero_Wreath.h`

เซ็ตจริง: **Hero of Triumphant Song** · `Relic.name` = `"Hero_Wreath"` · **เซ็ตสำหรับสาย memosprite**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — ATK +12% | บวก ATK% ถาวร | `Hero_Wreath.h:8` |
| 4-pc — ขณะ memosprite อยู่สนาม: SPD +6% | ต้นทุกเทิร์นของผู้สวมเช็ค `memosprite->isExisted()` · ลง/ถอน 6% ตามสถานะ โดยใช้ flag `buffCheck["Hero_Wreath"]` กันลงซ้ำ | `:11-20` |
| 4-pc — memosprite โจมตี → ผู้สวมและ memosprite CD +30% นาน 2 เทิร์น | `beforeAttackActionList` กรอง `side == Memosprite` และเป็นของผู้สวม แล้ว `buffSingleChar` | `:22-26` |
| — ถอน CD เมื่อหมดอายุ | ท้ายเทิร์นของแต่ละตัว (ผู้สวม / memosprite) เช็ค `isBuffEnd` แยกกัน | `:28-33` |

## รากฐาน: memosprite

- `ptr->memosprite` คือ memosprite ของตัวละครนั้น (`nullptr` ถ้าไม่มี) · เช็คว่าอยู่ในสนามด้วย `isExisted()` (memosprite มีตั้งแต่ setup แต่เป็น `DEATH` จนกว่าจะ summon)
- **`buffSingleChar(ptr, {stat}, ชื่อ, เทิร์น)` = บัฟที่ลงให้ทั้งตัวละครและ memosprite ของเขา** ต่างจาก `buffSingle` ที่ลงเฉพาะ unit ที่ส่งไป · ตรงกับ kit ที่บอกว่า CD +30% ได้ "ทั้งคู่" · คู่เดียวกันนี้มีในฝั่ง extend ด้วย (`extendCharBuffTime`, `Function/Combat/Buff_Stats.h:42`)

## รากฐาน: บัฟถาวรที่ลงครั้งเดียวด้วย flag ของตัวเอง

SPD +6% ต้องลง **ครั้งเดียว** ตอน memosprite ปรากฏ แต่ `beforeTurnList` ยิงทุกเทิร์น → ใช้ `buffCheck["Hero_Wreath"] == 0` เป็นยาม แล้วตั้งเป็น 1 ทันทีที่ลง (`:14-15`) · ถ้า memosprite ออกจากสนาม จะถอน −6% และตั้ง flag กลับเป็น 0 (เปิด/ปิดตามสถานะจริง)

## แก้เมื่อ 2026-09-25
- CD +30% เดิม trigger เมื่อใครฝ่ายเราตีก็ได้ → เปลี่ยนเป็นเฉพาะ memosprite ของเจ้าของ (`side == Side::MEMOSPRITE && attacker->owner->isSameName(ptr)`)
- เดิมไม่มีโค้ดถอน `Hero_Wreath_buff` → CD ค้างถาวร · เพิ่ม `afterTurnList` ถอนทั้งเจ้าของและ memosprite แต่ละตัว (`isBuffEnd` เช็คตามเทิร์นของ unit นั้น)

## แก้เมื่อ 2026-09-26
- SPD +6% เดิมลงครั้งเดียวไม่ถอน แม้ memosprite ตาย · kit ระบุ "While the wearer's memosprite is on the field" → เช็ค `isExisted()` ทุกต้นเทิร์น ลง/ถอนตามสถานะ
