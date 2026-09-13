# `src/Defination/Data/`

## LC / Relic / Planar ต่อเข้าตัวละครยังไง

`Setup` ของตัวละครรับ 3 อย่างนี้เป็น **ฟังก์ชัน** แล้วเรียกทันที (`Tingyun.h:20,32-34`):
```cpp
void Setup(int E, function<void(CharUnit *ptr)> LC, function<void(CharUnit *ptr)> Relic, function<void(CharUnit *ptr)> Planar){
    CharUnit *ptr = SetCharBasicStats(...);
    ...
    LC(ptr);
    Relic(ptr);
    Planar(ptr);
```
ฟังก์ชันพวกนั้นทำ 2 อย่าง: **เขียนชื่อลงช่องของตัวเอง** (เช่น `ptr->Light_cone.Name = "DDD"`) และ **ลงทะเบียน trigger / บัฟ** (`Reset_List`, `WhenUseUlt_List`, `addUltCondition` ...) — ตัวฟังก์ชันไม่ได้ถูกเก็บในช่อง ช่องเก็บแค่ชื่อ
- LC เป็น factory รับ superimpose แล้วคืน lambda (`Harmony_Lightcone::DDD(int superimpose)` → `[=](CharUnit *ptr){...}`)
- Relic / Planar ส่วนใหญ่เป็นฟังก์ชันตรง ๆ (`Relic::Eagle_Beaked_Helmet`) ยกเว้นตัวที่ต้องรับค่า เช่น `Planar::GiantTree(0)`

## เงื่อนไขกดอัลติที่ผูกกับของที่ใส่

relic / LC บางตัวให้ผลตอนใช้อัลติ (advance) → ถ้ากดตอนที่ตัวนั้นใกล้ได้เล่นอยู่แล้ว advance จะเสียเปล่า
- **Eagle of Twilight Line** (`Eagle_Beaked_Helmet.h` — ชื่อไฟล์เป็นชื่อชิ้นหัว): ใช้อัลติแล้ว advance ตัวเอง 25% → ไฟล์ relic **ใส่ `addUltCondition` ไว้เอง**: `atv <= Max_atv*0.25` → ยังไม่กด
- **Dance! Dance! Dance!** (`DDD.h`): ใช้อัลติแล้ว advance ทั้งทีม `14 + 2*S`% → **ไม่มีเงื่อนไขในตัว**

## แก้เมื่อ 2026-09-13 (user สั่ง)

- **Tribbie** — ลบ `addUltCondition` ทั้งก้อน เหลือแต่ `return true` แล้ว:
  - 2 บรรทัดเช็ค DDD (เป้าที่บัฟ หรือ driver มี atv ≤ 0 → ไม่กด)
  - บรรทัด `Light_cone.Name == "Eagle_Beaked_Helmet"` ที่ **ไม่มีวันจริง** เพราะ Eagle เป็น relic ชื่ออยู่ใน `Relic.Name` — และซ้ำกับเงื่อนไขที่ relic ใส่เองอยู่แล้ว
- **Hanabi / HanabiV1** — เดิม `LC != "DDD" && ต้นเทิร์นของเป้าที่บัฟ` → **ใส่ DDD แล้วเงื่อนไขเป็นเท็จเสมอ = ไม่มีวันกดอัลติ** · ลบส่วน `LC != "DDD"` ออก → กดอัลติตอนต้นเทิร์นของเป้าที่บัฟเสมอ ไม่ว่าใส่ LC อะไร
- **ชื่อ planar** — `Rutilant.h` เดิม `"    "` → `"Rutilant"` · `Inert.h` เดิม `"SpaceSealing"` (copy มา) → `"Inert"`

> ความต่างที่ทำให้ย้ายเงื่อนไข DDD เข้า `DDD.h` แบบ Eagle ไม่ได้ตรง ๆ: เงื่อนไขของ Tribbie คือ **กันไม่ให้ advance เสียเปล่า** แต่ของ Hanabi คือ **จับจังหวะให้บัฟอัลติเริ่มพอดีตอนเป้าได้เล่น** — คนละจุดประสงค์ · user ตัดสินใจเอา DDD ออกจากทั้ง 2 ตัวแทน
