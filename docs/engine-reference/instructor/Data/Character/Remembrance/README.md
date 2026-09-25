# `src/Defination/Data/Character/Remembrance/`

memosprite ทั้งหมด · 4 ไฟล์ · **อ่าน `RMC.md` ก่อนเสมอ**

| ไฟล์ | memosprite | สิ่งที่ไฟล์นี้สอนเป็นไฟล์แรก |
|---|---|---|
| `RMC.h` | Mem | **ระบบ memosprite ทั้งหมด** · `When_Energy_Increase_List` · `AfterDealingDamage_List` · `AType::TEMP` กันลูป |
| `Aglaea.h` | Garmentmaker | countdown unit · joint attack (`setJoint` / `switchAttacker`) · `buffStackChar` |
| `Castorice.h` | Netherwing | HP เป็นทรัพยากรสองทาง · ลูปโจมตีจนทรัพยากรหมด · ตั้งเงื่อนไข ult ให้ตัวละครอื่น |
| `Hyacine.h` | Little Ica | ฮีล + memosprite · `BeforeAction_List`/`AfterAction_List` · `healCount` |

## สิ่งที่ต้องรู้ก่อนแตะไฟล์ในโฟลเดอร์นี้

**1. memosprite เป็น unit เต็มตัวที่มี `Turn_func` ของตัวเอง**

**2. `Side::Memosprite` แยกจาก `Side::Ally`** — trigger ที่กรองด้วย `side` ต้องระวัง

**3. ตระกูล `...Char` ลงถึง memosprite ด้วย** — `buffSingleChar`, `buffStackChar`, `buffCharResetStack`, `extendCharBuffTime` · ส่วน `buffSingle` ลงเฉพาะ unit ที่ส่งไป

**4. `chooseAllyBuff` / `chooseCharacterBuff`** — ตัวแรกคืนตัวที่ควรได้บัฟตอนนี้ (อาจเป็น memosprite) ตัวหลังคืนตัวละครเจ้าของเสมอ

**5. สูตรที่อ้างอิง stat ของตัวเองต้องลงคู่ `AType::TEMP` + `AType::None`** เพราะ `calculateXForBuff` หักช่อง `TEMP` ออกก่อนคำนวณ → เป็นกลไกกันลูป (ดู `RMC.md`)

**6. ทั้ง 4 ตัวมีระบบเรียกออกมา/ตาย ที่ต้องเช็ค `isDeath()` ก่อนเสมอ** — `summon(HP%)` + `resetATV(SPD)`
