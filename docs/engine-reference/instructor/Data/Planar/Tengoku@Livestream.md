# `src/Defination/Data/Planar/Tengoku@Livestream.h`

`Planar.name` = `"Tengoku@Livestream"` · ฟังก์ชัน `TengokuLivestream` (ไม่มี `@`) · **เซ็ตที่ผูกกับการใช้ skill point**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| CD +16% | บวก CD ถาวร | `Tengoku@Livestream.h:7` |
| ใช้ SP ครบ 3 แต้มในเทิร์นเดียว → CD +32% นาน 3 เทิร์น | `skillPointList` นับ SP ที่ถูกใช้ (ค่าติดลบ) ของทั้งทีมใน stack `"Tengoku sp count"` · ถึง 3 → `buffSingle` ชื่อ `"Tengoku Buff"` (กันซ้อนในตัว) — **เช็คเงื่อนไขจริง** | `:19-24` |
| — รีเซ็ตตัวนับ | ต้นทุกเทิร์น (ของทุก unit) ตั้ง stack เป็น 0 | `:10-12` |
| — ถอนเมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` → CD −32 | `:14-17` |

## รากฐาน: `skillPointList` — trigger จากการได้/ใช้ skill point

```cpp
skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY,
    [ptr](AllyUnit *spMaker, int SP) {
        if (SP < 0) ptr->addStack("Tengoku sp count", -1 * SP);   // SP ติดลบ = ใช้ไป
        if (ptr->getStack("Tengoku sp count") >= 3)
            buffSingle(ptr,{{Stats::CD,AType::NONE,32}},"Tengoku Buff",3);
    }));
```

- callback รับ **ใครเป็นคนทำ** และ **จำนวน SP ที่เปลี่ยน** · ค่าบวก = ได้เพิ่ม (`genSkillPoint(ptr, 1)`) ค่าลบ = ใช้ไป (`genSkillPoint(ptr, -1)`)
- **นับ SP ที่ทั้งทีมใช้ ไม่ใช่เฉพาะตัวเอง** — ไม่มี guard ว่า `spMaker` เป็นใคร ซึ่งตรงกับ kit
- เป็น list เดียวกับตระกูล `punchLineList` (`TriggerSkillPointFunc` เหมือนกัน) ที่ `../Relic/Ever-Glorious Magical Girl.md` ใช้

## รากฐาน: ตัวนับที่รีเซ็ตทุกเทิร์น

`beforeTurnList` เคลียร์ `"Tengoku sp count"` เป็น 0 ทุกต้นเทิร์น → เงื่อนไข "3 แต้มในเทิร์นเดียว" จึงเป็นการนับในหน้าต่างเทิร์นเดียว ไม่ใช่สะสมข้ามเทิร์น

> **ไม่ต้องกลัวบัฟซ้อน** — `buffSingle(ptr,{...},ชื่อ,เทิร์น)` เรียก `isHaveToAddBuff` ข้างใน (`Function/Combat/Buff_Stats.h:95`) จึงบวกค่าครั้งเดียวและต่ออายุให้ ถ้าใช้ SP แต้มที่ 4, 5 ในเทิร์นเดียวกันบัฟจะไม่ทบ

## จุดที่ควรรู้

- `beforeTurnList` ของเซ็ตนี้ **ไม่ได้ guard ว่าเป็นเทิร์นของใคร** → ตัวนับถูกล้างทุกต้นเทิร์นของทุก unit รวมถึงเทิร์นศัตรู · ผลคือหน้าต่างการนับสั้นกว่า "เทิร์นของตัวเอง" จริง ๆ ซึ่งน่าจะเข้มกว่าที่ kit ตั้งใจ
