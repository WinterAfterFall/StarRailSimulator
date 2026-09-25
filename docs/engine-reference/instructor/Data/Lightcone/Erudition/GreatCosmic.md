# `src/Defination/Data/Lightcone/Erudition/GreatCosmic.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"GreatCosmic"` · base stats `SetAllyBaseStats(953, 476, 331)`

| ท่อน | โค้ด |
|---|---|
| ATK% `6 + 2S` | `Reset_List` |
| DMG `(3 + S) × 7` | `Reset_List` |

## จุดที่ควรสังเกต

**`(3 + superimpose) * 7` คูณ 7 ไว้ในสูตร** — น่าจะเป็นการสมมติว่าเงื่อนไขของ kit (ที่ให้ stack ได้ 7 ชั้น) เข้าเต็มเสมอ แล้วใส่ค่าเต็มตรง ๆ · สำนวนเดียวกับ `../Nihility/GNSW.md` ที่คูณ 3

**มีโค้ดคอมเมนต์ทิ้ง 2 บรรทัด** (`After_attack_List` ที่รับ `shared_ptr<AllyActionData>`) — เป็นร่องรอยของการพยายามทำเงื่อนไขจริงแล้วเลิก
