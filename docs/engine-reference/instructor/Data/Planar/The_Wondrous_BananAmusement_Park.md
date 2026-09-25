# `src/Defination/Data/Planar/The_Wondrous_BananAmusement_Park.h`

`Planar.Name` = `"The_Wondrous_BananAmusement_Park"` · เซ็ตสาย summon / memosprite

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| CD +16% | `Reset_List` | 7 |
| CD +32% เพิ่ม ถ้ามี summon หรือ memosprite | `WhenOnField_List` — **เช็คเงื่อนไขจริง** | 10-14 |

```cpp
if (ptr->summonList.size() != 0 || ptr->memospriteList.size() > 0) {
    ptr->Stats_type[Stats::CD][AType::None] += 32;
}
```

## จุดที่ควรรู้

- **`summonList` กับ `memospriteList` เป็นคนละระบบ** — summon เป็นของเก่าที่กำลังจะถูก refactor เป็น `ActionValueStats` ล้วน (ดู `future-improvements.md` ข้อ 4) ส่วน memosprite เป็นระบบปัจจุบันของ path Remembrance · เซ็ตนี้รับทั้งสองแบบ
- **เช็คแค่ตอนเข้าสนามครั้งเดียว** — ถ้า memosprite ถูกเรียกออกมาภายหลัง (ซึ่งเป็นเรื่องปกติ) เงื่อนไขนี้จะเป็นเท็จตอนเช็คแล้วไม่ได้บัฟเลย · ต่างจาก `../Relic/Hero_Wreath.md` ที่เช็คทุกต้นเทิร์นใน `Before_turn_List` เพื่อรอจนกว่า memosprite จะมา — **น่าจะเป็นบั๊กของไฟล์นี้**
- ลงด้วยการเขียน `Stats_type` ตรง ๆ ไม่ผ่าน `buffSingle` → ไม่ยิง `StatsAdjust` และไม่ถึง memosprite (ต่างจาก `buffSingleChar` ที่ `Bone_Collection.h` ใช้)
