# `src/Defination/Data/Planar/Arcadia.h`

`Planar.Name` = `"Arcadia"` · **เซ็ตเดียวในโฟลเดอร์ที่ค่าเปลี่ยนได้ระหว่างเกม**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| DMG ตามส่วนต่างจำนวนเพื่อนจาก 4 คน (kit: ขาด ×12% · เกิน ×9%) | `BeforeAttackAction_List` | 6-20 |

```cpp
int cnt = 0;
for(auto &each : allyList) if(each->isExisted()) cnt++;
double buff = 0;
if(cnt<4)      buff = (4 - cnt) * 12;
else if(cnt>4) buff = (cnt - 4) * 9;
buffSingleChar(ptr,{{Stats::DMG,AType::None, buff - ptr->getBuffNote("Arcadia")}});
ptr->setBuffNote("Arcadia", buff);
```

## รากฐาน

**1. คำนวณใหม่ทุก action ด้วย `BeforeAttackAction_List`** — จำนวนเพื่อนที่ยังอยู่เปลี่ยนได้ตลอด (ตาย / ถูกลบออกจากสนามแบบอัลติ Phainon) จึงต้อง re-eval ก่อนทุกการโจมตี ไม่ใช่ตั้งครั้งเดียวตอนเข้าสนาม

**2. ใช้สำนวน delta + `buffNote`** เหมือน A2 ของ `../Character/Abundance/Gallagher.md` และ `../Relic/Ever-Glorious Magical Girl.md` — ลงเฉพาะส่วนต่างจากค่าที่เคยลงไว้ เพราะ `buffSingleChar` บวกค่าดิบ ไม่มี "ตั้งค่าเป็น"

**3. `each->isExisted()`** เป็นตัวเช็คว่า unit ยังอยู่ในสนามจริง ๆ — ต่างจาก `isTargetable()` และ `isDeath()` ที่ใช้คนละความหมาย (เทียบ `UnitStatus` ใน `Enum/Enum.h:28`: `Alive` / `Death` / `AtvFreeze` / `Retire`)

## จุดที่ควรรู้

- **kit แยกค่าตามทิศ**: เพื่อนน้อยกว่า 4 → +12% ต่อคนที่ขาด (สูงสุด 3 สแต็ก) · มากกว่า 4 → **+9%** ต่อคนที่เกิน (สูงสุด 4 สแต็ก) · ตั้งใจให้ทั้งสองปลายได้เท่ากันที่ 36% (1 คน = 3×12, 8 คน = 4×9)
- สาขา `cnt>4` เคยใช้ `* 12` (8 คนได้ 48%) แก้เป็น `* 9` แล้ว (2026-09-26)
- `cnt > 4` เกิดได้จริงเพราะ `allyList` รวม memosprite ด้วย (`Class/Unit/StatsSet.h:35`) ซึ่งตรงกับ kit ที่นับ memosprite เป็นเพื่อนในสนาม
