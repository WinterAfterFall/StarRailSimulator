# `src/Defination/Class/ActionData/ActionDataDefine.h`

ไฟล์นี้นิยาม helper สำหรับถามว่า `AllyActionData` ที่กำลังตรวจอยู่เกี่ยวข้องกับผู้โจมตี, เจ้าของ, action type หรือ damage type ที่ระบุหรือไม่ โดยคืน `true` ทันทีเมื่อพบรายการที่ตรง

## หลักการตรวจ attack กับ action อื่น

`AllyAttackAction` อาจมีผู้โจมตีหลายคนใน action เดียว (`AttackSetList`) เช่น joint attack จึงวนตรวจทุก `Attacking` ใน list นั้น ส่วน `AllyBuffAction` และ action ฝั่ง ally ชนิดอื่นตรวจ `Attacker` และ `actionTypeList` ของ action โดยตรง

ดังนั้น helper ที่ใช้กับ attack หมายถึง “มีผู้โจมตีอย่างน้อยหนึ่งคนใน action นี้ตรงเงื่อนไข” ไม่ได้หมายถึง `Attacker` ตัวหลักเท่านั้น

## การตรวจชื่อและเจ้าของ

- `isSameName(AllyUnit*)` / `isSameName(string)` ตรวจผู้โจมตีโดยตรงด้วย `AllyUnit::isSameName`
- `isSameOwnerName(CharUnit*)` ตรวจว่าผู้โจมตีเป็นตัวละครนั้นเองหรือเป็น memosprite ของตัวละครนั้น ผ่าน `CharUnit::isSameOwner`

ความหมายของ owner identity และเหตุที่ใช้ชื่ออธิบายไว้แล้วใน [CharUnit.md](../Unit/CharUnit.md#issameowner)

## การตรวจประเภท action

- `isSameAction(AType)` ตรวจว่ามี action type ที่ระบุหรือไม่
- `isSameAction(AllyUnit*, AType)` และ `isSameAction(string, AType)` ต้องตรงทั้งผู้โจมตีและ action type
- `isSameOwnerAction(CharUnit*, AType)` ต้องตรงทั้งเจ้าของ (รวม memosprite) และ action type

รายการที่ตรวจคือ `actionTypeList` ของผู้โจมตีแต่ละคนใน `AttackSetList` สำหรับ attack หรือ `actionTypeList` ของ action โดยตรงสำหรับ non-attack. เนื่องจากหนึ่ง action มีได้หลาย type การตรวจจึงเป็นการค้นหาสมาชิกใน list ไม่ได้ยึด type ตัวแรกเป็น type หลัก

## การตรวจประเภทดาเมจ (เฉพาะ attack)

`AllyAttackAction` มีชุด helper คู่ขนานกับ action type:

- `isSameDamageType(AType)`
- `isSameDamageType(AllyUnit*, AType)` / `isSameDamageType(string, AType)`
- `isSameOwnerDamageType(CharUnit*, AType)`

helper กลุ่มนี้ตรวจ `damageTypeList` ของแต่ละ `Attacking` แทน `actionTypeList` จึงเหมาะเมื่อ trigger สนใจชนิดของดาเมจที่ถูกคำนวณจริง ไม่ใช่เพียงชนิดของ action ที่ทำให้เกิดมัน
