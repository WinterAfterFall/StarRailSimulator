# `src/Defination/Function/Calculate/CalDmgReceive.h`

ไฟล์นี้คำนวณดาเมจจาก `Enemy` ที่โจมตี `AllyUnit` โดยใช้สายสูตรสั้นแยกเป็นค่า ATK ศัตรู, ตัวคูณดาเมจศัตรู, ตัวคูณ DEF ของเป้าหมาย และตัวคูณลดดาเมจที่เป้าหมายได้รับ

> 2026-09-28 (user สั่ง): ฟิลด์ `Enemy::atkPercent` / `dmgPercent` ถูกลบ ย้ายไปเป็น stat `Stats::ATK_REDUCE` / `Stats::DMG_REDUCE` ช่อง `AType::NONE` · **ค่าบวก = ลด** · ใส่/ถอนด้วย `statsType[...][AType::NONE] += / -=` หรือ `debuffSingle` · `basicReset` ล้างให้เองพร้อม stat อื่นของศัตรู

## `calculateDmgReceive(Enemy*, AllyUnit*, ratio)`

`ratio` คือเปอร์เซ็นต์สเกลของสกิลศัตรู เช่น `100` หมายถึง 100% ของ ATK ศัตรู

ลำดับการคำนวณคือ

```text
ratio / 100
× calEnemyATK(Attacker)
× calDmgReduceMultiplier(Attacker, target)
× calAllyDefMultiplier(target)
```

หลังได้ดาเมจแล้ว `EnemyActionData` หัก **Repellency** (`decreaseBlock`) → โล่ (`decreaseSheild`) → HP ตามลำดับ ดู [ChangeHP.md](../Combat/ChangeHP.md)

ผลลัพธ์ติดลบถูกเปลี่ยนเป็น `0` ก่อนคืนค่า ฟังก์ชันนี้คำนวณดาเมจก่อนหักโล่และ HP; การหักโล่, การลด HP จริง และ event หลัง HP ลดอยู่ใน `ChangeHP.h`

## `calEnemyATK(Enemy*)`

เริ่มจาก `enemy->atk` แล้วหักเปอร์เซ็นต์จาก `ATK_REDUCE` ของศัตรู:

```text
ATK × (1 − statsType[ATK_REDUCE][NONE] / 100)
```

ถ้าค่าหลังคำนวณติดลบจะคืน `0` ศัตรูจึงไม่สามารถส่งค่า ATK ติดลบเข้าสูตรดาเมจได้

## `calDmgReduceMultiplier(Enemy*, AllyUnit*)` (เดิม `calEnemyDMG`)

**รวม** `DMG_REDUCE` ของศัตรู (ดาเมจที่ศัตรูสร้างลดลง) กับ `DMG_REDUCE` ของตัวที่รับ (ดาเมจที่รับลดลง) เป็นตัวคูณเดียว (user 2026-09-28):

```text
(100 − DMG_REDUCE ศัตรู − DMG_REDUCE ผู้รับ) / 100
```

ตัวนี้แยกจาก `ATK_REDUCE`: ค่าแรกเปลี่ยน ATK ที่ใช้เป็นฐาน ส่วน `DMG_REDUCE` เปลี่ยนดาเมจหลังได้ ATK แล้ว หากตัวคูณติดลบจะถูก clamp เป็น `0`

## `calAllyDefMultiplier(AllyUnit*)`

ใช้ `totalDEF` ของเป้าหมาย ซึ่งเป็นค่า DEF สุดท้ายหลังรวมการปรับ stat ที่เกี่ยวข้องแล้ว โดยค่าติดลบถูกมองเป็นศูนย์ แล้วคำนวณตัวคูณลดดาเมจ:

```text
1 - DEF / (DEF + 1000)
```

ค่า `1000` เป็นค่าคงที่ของสมการ DEF multiplier สำหรับตัวละครตอนรับดาเมจ ไม่ใช่ค่าเลเวลหรือค่าที่คำนวณแยกตามศัตรู

ดังนั้น DEF ที่มากขึ้นทำให้ตัวคูณเล็กลงตามสูตร แต่ฟังก์ชันนี้ไม่ได้รวม RES, โล่ หรือเอฟเฟกต์ลดดาเมจชนิดอื่น ซึ่งถูกจัดการในกลไกส่วนอื่นของ combat

แหล่งลดดาเมจทั้งหมด (ทั้งฝั่งศัตรูและฝั่งเรา) **บวกกัน** ไม่ได้คูณแยกทีละแหล่งแบบในเกม · ผู้ใช้ฝั่งเราตอนนี้: Talent ของ Pearl (HP ≤ 50% → −30%)
