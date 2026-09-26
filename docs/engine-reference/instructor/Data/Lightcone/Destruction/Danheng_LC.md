# `src/Defination/Data/Lightcone/Destruction/Danheng_LC.h`

`namespace Destruction_Lightcone` · `Light_cone.Name` = `"Danheng_LC"` · base stats `SetAllyBaseStats(1058, 635, 397)`

**signature ของ Dan Heng** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

| ท่อน | โค้ด |
|---|---|
| CR `15 + 3S` | `Reset_List` |
| ใช้ BA → ATK `15+3S` + ER `5+S` ต่อ stack (cap 2) นาน 2 เทิร์น | `BeforeAttackAction_List` |
| ถอน | `After_turn_List` |

## รากฐาน: ใช้ค่าคืนของ `calStack` เป็นตัวคูณ

```cpp
double value = calStack(ptr, 1, 2, "Danheng LC").first;   // จำนวนที่เพิ่มได้จริงหลัง clamp
buffSingle(ptr, {{ATK_P, value * (15 + 3*S)}});
ptr->Energy_recharge += (5 + superimpose) * value;
extendBuffTime(ptr, "Danheng LC", 2);
```
`calStack` คืน `pair<int,int>` — `.first` คือจำนวนที่เพิ่มได้จริง (0 ถ้าเต็ม cap) → บัฟจะไม่บวกซ้ำเมื่อ stack เต็ม · **เป็นการใช้ `calStack` ที่ถูกต้องที่สุดในโปรเจกต์** (เทียบ `../../Relic/Wavestrider Captain.md` ที่ทิ้งค่าคืน)

## จุดที่ควรระวัง

**ถอน ATK ด้วย `buffCharResetStack` แต่ลงด้วย `buffSingle`** — คนละกลไก · `buffSingle` บวกค่าดิบโดย engine ไม่ได้นับ stack ให้ ส่วน `buffCharResetStack` ถอนตาม stack ที่ engine นับ → **ถ้า engine ไม่ได้นับ stack ของชื่อนี้ การถอนจะไม่ตรง** · ที่ถูกควรใช้ `buffStackSingle` ตอนลง หรือถอนด้วย `buffSingle` ติดลบคูณ stack เอง (แบบที่ทำกับ ER ในบรรทัดก่อนหน้า)
