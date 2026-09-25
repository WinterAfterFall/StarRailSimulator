# `src/Defination/Data/Planar/Tengoku@Livestream.h`

`Planar.Name` = `"Tengoku@Livestream"` · ฟังก์ชัน `TengokuLivestream` (ไม่มี `@`) · **เซ็ตที่ผูกกับการใช้ skill point**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| CD +16% | `Reset_List` | 7 |
| ใช้ SP ครบ 3 แต้มในเทิร์นเดียว → CD +32% นาน 3 เทิร์น | `Skill_point_List` | 19-24 |
| รีเซ็ตตัวนับต้นเทิร์น | `Before_turn_List` → `setStack("Tengoku sp count", 0)` | 10-12 |
| ถอนบัฟเมื่อหมดอายุ | `After_turn_List` + `isBuffEnd` | 14-17 |

## รากฐาน: `Skill_point_List` — trigger จากการได้/ใช้ skill point

```cpp
Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *SP_maker, int SP) {
        if (SP < 0) ptr->addStack("Tengoku sp count", -1 * SP);   // SP ติดลบ = ใช้ไป
        if (ptr->getStack("Tengoku sp count") >= 3)
            buffSingle(ptr,{{Stats::CD,AType::None,32}},"Tengoku Buff",3);
    }));
```

- callback รับ **ใครเป็นคนทำ** และ **จำนวน SP ที่เปลี่ยน** · ค่าบวก = ได้เพิ่ม (`genSkillPoint(ptr, 1)`) ค่าลบ = ใช้ไป (`genSkillPoint(ptr, -1)`)
- **นับ SP ที่ทั้งทีมใช้ ไม่ใช่เฉพาะตัวเอง** — ไม่มี guard ว่า `SP_maker` เป็นใคร ซึ่งตรงกับ kit
- เป็น list เดียวกับตระกูล `PunchLine_List` (`TriggerSkill_point_func` เหมือนกัน) ที่ `../Relic/Ever-Glorious Magical Girl.md` ใช้

## รากฐาน: ตัวนับที่รีเซ็ตทุกเทิร์น

`Before_turn_List` เคลียร์ `"Tengoku sp count"` เป็น 0 ทุกต้นเทิร์น → เงื่อนไข "3 แต้มในเทิร์นเดียว" จึงเป็นการนับในหน้าต่างเทิร์นเดียว ไม่ใช่สะสมข้ามเทิร์น

> **ไม่ต้องกลัวบัฟซ้อน** — `buffSingle(ptr,{...},ชื่อ,เทิร์น)` เรียก `isHaveToAddBuff` ข้างใน (`Function/Combat/Buff_Stats.h:95`) จึงบวกค่าครั้งเดียวและต่ออายุให้ ถ้าใช้ SP แต้มที่ 4, 5 ในเทิร์นเดียวกันบัฟจะไม่ทบ

## จุดที่ควรรู้

- `Before_turn_List` ของเซ็ตนี้ **ไม่ได้ guard ว่าเป็นเทิร์นของใคร** → ตัวนับถูกล้างทุกต้นเทิร์นของทุก unit รวมถึงเทิร์นศัตรู · ผลคือหน้าต่างการนับสั้นกว่า "เทิร์นของตัวเอง" จริง ๆ ซึ่งน่าจะเข้มกว่าที่ kit ตั้งใจ
