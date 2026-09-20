# `src/Defination/Function/Calculate/CalDmgReceive.h`

ไฟล์นี้คำนวณดาเมจจาก `Enemy` ที่โจมตี `AllyUnit` โดยใช้สายสูตรสั้นแยกเป็นค่า ATK ศัตรู, ตัวคูณดาเมจศัตรู และตัวคูณ DEF ของเป้าหมาย

## `calculateDmgReceive(Enemy*, AllyUnit*, ratio)`

`ratio` คือเปอร์เซ็นต์สเกลของสกิลศัตรู เช่น `100` หมายถึง 100% ของ ATK ศัตรู

ลำดับการคำนวณคือ

```text
ratio / 100
× calEnemyATK(Attacker)
× calEnemyDMG(Attacker)
× calAllyDefMultiplier(target)
```

ผลลัพธ์ติดลบถูกเปลี่ยนเป็น `0` ก่อนคืนค่า ฟังก์ชันนี้คำนวณดาเมจก่อนหักโล่และ HP; การหักโล่, การลด HP จริง และ event หลัง HP ลดอยู่ใน `ChangeHP.h`

## `calEnemyATK(Enemy*)`

เริ่มจาก `enemy->ATK` แล้วบวกเปอร์เซ็นต์จาก `enemy->atkPercent`:

```text
ATK × (1 + atkPercent / 100)
```

ถ้าค่าหลังคำนวณติดลบจะคืน `0` ศัตรูจึงไม่สามารถส่งค่า ATK ติดลบเข้าสูตรดาเมจได้

## `calEnemyDMG(Enemy*)`

แปลง `enemy->dmgPercent` เป็นตัวคูณโดยใช้ฐาน 100:

```text
(100 + dmgPercent) / 100
```

ตัวนี้แยกจาก `atkPercent`: ค่าแรกเปลี่ยน ATK ที่ใช้เป็นฐาน ส่วน `dmgPercent` เปลี่ยนดาเมจหลังได้ ATK แล้ว หากตัวคูณติดลบจะถูก clamp เป็น `0`

## `calAllyDefMultiplier(AllyUnit*)`

ใช้ `totalDEF` ของเป้าหมาย ซึ่งเป็นค่า DEF สุดท้ายหลังรวมการปรับ stat ที่เกี่ยวข้องแล้ว โดยค่าติดลบถูกมองเป็นศูนย์ แล้วคำนวณตัวคูณลดดาเมจ:

```text
1 - DEF / (DEF + 1000)
```

ค่า `1000` เป็นค่าคงที่ของสมการ DEF multiplier สำหรับตัวละครตอนรับดาเมจ ไม่ใช่ค่าเลเวลหรือค่าที่คำนวณแยกตามศัตรู

ดังนั้น DEF ที่มากขึ้นทำให้ตัวคูณเล็กลงตามสูตร แต่ฟังก์ชันนี้ไม่ได้รวม RES, โล่ หรือเอฟเฟกต์ลดดาเมจชนิดอื่น ซึ่งถูกจัดการในกลไกส่วนอื่นของ combat
