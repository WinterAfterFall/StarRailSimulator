# `src/Defination/Data/Lightcone/Erudition/BP_Erudition.h`

`namespace Erudition_Lightcone` · `lightCone.name` = `"BP_Erudition"` · base stats `setAllyBaseStats(847, 529, 331)`

**มาจาก Battle Pass** · เซ็ตจริง: **Today Is Another Peaceful Day** (0.2/0.25/0.3/0.35/0.4% ต่อ energy สูงสุด 160 — ตรงกับโค้ด)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(847, 529, 331)` | `BP_Erudition.h:5` |
| DMG ตาม Max Energy ของผู้สวม (`0.15 + 0.05S`% ต่อ energy, นับสูงสุด 160) | `resetList` · Max Energy > 160 → ค่าเพดาน `24 + 8S` · ไม่งั้นคูณตรง | `:7-13` (เพดาน `:9` · คูณ `:11`) |

```cpp
if (ptr->maxEnergy > 160) ptr->statsType[DMG][NONE] += 24 + superimpose * 8;
else                       ptr->statsType[DMG][NONE] += ptr->maxEnergy * (0.15 + 0.05 * superimpose);
```

## รากฐาน: สแตตที่คำนวณจากคุณสมบัติของผู้สวม

**LC ใบเดียวในโปรเจกต์ที่อ่าน `maxEnergy` ของตัวละครมาคำนวณสแตต** — `0.15 + 0.05S` ต่อ 1 energy โดยมีเพดานที่ 160 energy (`24 + 8S`)

คำนวณครั้งเดียวใน `resetList` ซึ่งถูกต้องเพราะ `maxEnergy` ไม่เปลี่ยนระหว่างเกม

> เทียบกับ `../Destruction/Saber_LC.md` (`maxEnergy >= 300`) และ `The_Herta_LC.md` (`ultCost >= 140`) ที่ใช้ค่าเดียวกันเป็นเงื่อนไขเปิด/ปิด — ใบนี้ใช้เป็นตัวแปรในสูตรจริง ๆ
