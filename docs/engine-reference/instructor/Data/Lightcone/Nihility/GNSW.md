# `src/Defination/Data/Lightcone/Nihility/GNSW.h`

`namespace Nihility_Lightcone` · `Light_cone.Name` = `"GNSW"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| DMG `(9 + 3S) × 3` | `Reset_List` |

**ไฟล์สั้นที่สุดในโฟลเดอร์** — มีบรรทัดเดียวที่ทำอะไร

## จุดที่ควรสังเกต

```cpp
ptr->Stats_type[Stats::DMG][AType::None] += (9 + (3 * superimpose)) * 3;
```
**คูณ 3 ไว้ในสูตร** — น่าจะเป็นการสมมติว่าเงื่อนไขของ kit (ที่ให้บัฟ stack ได้ 3 ชั้น) เข้าเงื่อนไขเต็มเสมอ แล้วใส่ค่าเต็มตรง ๆ · เป็นแนวเดียวกับที่ relic/planar ตัดเงื่อนไขทิ้ง (ดู `../../Relic/README.md`)

**ไม่มีคอมเมนต์อธิบาย** ว่าทำไมคูณ 3 — ถ้าจะทำเงื่อนไขจริงต้องกลับไปดู kit
