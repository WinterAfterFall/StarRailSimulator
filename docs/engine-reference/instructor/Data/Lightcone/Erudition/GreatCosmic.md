# `src/Defination/Data/Lightcone/Erudition/GreatCosmic.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"GreatCosmic"` · base stats `setAllyBaseStats(953, 476, 331)`

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(953, 476, 331)` | `GreatCosmic.h:5` |
| ATK% `6 + 2S` | บวกถาวร | `:9` |
| DMG `(3 + S) × 7` | kit: DMG ตามจำนวน debuff บนเป้า · โค้ดใส่เต็มเพดาน 7 ชั้นถาวร | `:10` |

## จุดที่ควรสังเกต

**`(3 + superimpose) * 7` คูณ 7 ไว้ในสูตร** — น่าจะเป็นการสมมติว่าเงื่อนไขของ kit (ที่ให้ stack ได้ 7 ชั้น) เข้าเต็มเสมอ แล้วใส่ค่าเต็มตรง ๆ · สำนวนเดียวกับ `../Nihility/GNSW.md` ที่คูณ 3

**มีโค้ดคอมเมนต์ทิ้ง 2 บรรทัด** (`After_attack_List` ที่รับ `shared_ptr<AllyActionData>`) — เป็นร่องรอยของการพยายามทำเงื่อนไขจริงแล้วเลิก
