# `src/Defination/Data/Lightcone/Erudition/BP_Erudition.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"BP_Erudition"` · base stats `SetAllyBaseStats(847, 529, 331)`

**มาจาก Battle Pass** · เซ็ตจริง: **Today Is Another Peaceful Day** (0.2/0.25/0.3/0.35/0.4% ต่อ energy สูงสุด 160 — ตรงกับโค้ด)

| ท่อน | โค้ด |
|---|---|
| DMG ขึ้นกับ `Max_energy` ของผู้สวม | `Reset_List` |

```cpp
if (ptr->Max_energy > 160) ptr->Stats_type[DMG][None] += 24 + superimpose * 8;
else                       ptr->Stats_type[DMG][None] += ptr->Max_energy * (0.15 + 0.05 * superimpose);
```

## รากฐาน: สแตตที่คำนวณจากคุณสมบัติของผู้สวม

**LC ใบเดียวในโปรเจกต์ที่อ่าน `Max_energy` ของตัวละครมาคำนวณสแตต** — `0.15 + 0.05S` ต่อ 1 energy โดยมีเพดานที่ 160 energy (`24 + 8S`)

คำนวณครั้งเดียวใน `Reset_List` ซึ่งถูกต้องเพราะ `Max_energy` ไม่เปลี่ยนระหว่างเกม

> เทียบกับ `../Destruction/Saber_LC.md` (`Max_energy >= 300`) และ `The_Herta_LC.md` (`Ult_cost >= 140`) ที่ใช้ค่าเดียวกันเป็นเงื่อนไขเปิด/ปิด — ใบนี้ใช้เป็นตัวแปรในสูตรจริง ๆ
