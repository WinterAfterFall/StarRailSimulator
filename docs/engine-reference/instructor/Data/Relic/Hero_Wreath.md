# `src/Defination/Data/Relic/Hero_Wreath.h`

เซ็ตจริง: **Hero of Triumphant Song** · `Relic.Name` = `"Hero_Wreath"` · **เซ็ตสำหรับสาย memosprite**

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — ATK +12% | `Reset_List` → `Stats_type[Stats::ATK_P][AType::None] += 12` | 8 |
| 4-pc — ขณะ memosprite อยู่สนาม: SPD +6% | `Before_turn_List` + flag `buffCheck["Hero_Wreath"]` | 11-21 |
| 4-pc — เมื่อ memosprite โจมตี: CD ทั้งคู่ +30% 2 เทิร์น | `BeforeAttackAction_List` → `buffSingleChar` | 23-27 |

## รากฐาน: memosprite

- `ptr->memospriteList` คือลิสต์ memosprite ของตัวละครนั้น · เช็ค "มีตัวที่ยังไม่ตายไหม" ด้วย `each->isDeath()` (14)
- **`buffSingleChar(ptr, {stat}, ชื่อ, เทิร์น)` = บัฟที่ลงให้ทั้งตัวละครและ memosprite ของเขา** ต่างจาก `buffSingle` ที่ลงเฉพาะ unit ที่ส่งไป · ตรงกับ kit ที่บอกว่า CD +30% ได้ "ทั้งคู่" · คู่เดียวกันนี้มีในฝั่ง extend ด้วย (`extendCharBuffTime`, `Function/Combat/Buff_Stats.h:42`)

## รากฐาน: บัฟถาวรที่ลงครั้งเดียวด้วย flag ของตัวเอง

SPD +6% ต้องลง **ครั้งเดียว** ตอน memosprite ปรากฏ แต่ `Before_turn_List` ยิงทุกเทิร์น → ใช้ `buffCheck["Hero_Wreath"] == 0` เป็นยาม แล้วตั้งเป็น 1 ทันทีที่ลง (15) · ไม่มีโค้ดถอนคืนเมื่อ memosprite ตาย — บัฟอยู่ยาวจนจบการต่อสู้

## จุดที่ควรระวัง

- **CD +30% ไม่ได้เช็คว่าผู้โจมตีคือ memosprite** — เงื่อนไขจริงคือ `act->Attacker->Atv_stats->side == Side::Ally && ptr->memospriteList.size() > 0` (24) แปลว่า **ใครในทีมโจมตีก็ได้** ขอแค่เจ้าของ relic มี memosprite อยู่ · kit ระบุว่าต้องเป็น memosprite เป็นผู้โจมตี → **ค่าที่ได้สูงกว่าจริง** และบัฟถูกต่ออายุแทบทุก action
- ยังไม่ได้เช็คด้วยว่า memosprite ตัวนั้นยังไม่ตาย (ต่างจากบล็อก SPD ที่เช็ค `isDeath()`)

## แก้เมื่อ 2026-09-25
- CD +30% เดิม trigger เมื่อใครฝ่ายเราตีก็ได้ → เปลี่ยนเป็นเฉพาะ memosprite ของเจ้าของ (`side == Side::Memosprite && Attacker->owner->isSameName(ptr)`)
- เดิมไม่มีโค้ดถอน `Hero_Wreath_buff` → CD ค้างถาวร · เพิ่ม `After_turn_List` ถอนทั้งเจ้าของและ memosprite แต่ละตัว (`isBuffEnd` เช็คตามเทิร์นของ unit นั้น)
