# `src/Defination/Data/Lightcone/Destruction/Danheng_LC.h`

`namespace Destruction_Lightcone` · `lightCone.name` = `"Danheng_LC"` · base stats `setAllyBaseStats(1058, 635, 397)`

**signature ของ Dan Heng** (ตัวละครยังไม่มีในโปรเจกต์ — อยู่ในคิว `../../IMPLEMENT-QUEUE.md`)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| base stats | `setAllyBaseStats(1058, 635, 397)` | `Danheng_LC.h:5` |
| CR `15 + 3S` | บวกถาวร | `:8` |
| ใช้ Basic ATK → ATK `15 + 3S` และ ER `5 + S` ต่อ stack (สูงสุด 2) นาน 2 เทิร์น | `beforeAttackActionList` เฉพาะ BA ของผู้สวม · `calStack(…, 1, 2)` คืนจำนวนที่เพิ่มได้จริง แล้วคูณเข้ากับบัฟ ATK และ ER · ต่ออายุ 2 เทิร์น | `:11-19` |
| หมดอายุ → ถอนทั้งกอง | ท้ายเทิร์นผู้สวม `isBuffEnd` → ลบ ER ตาม stack และ `buffCharResetStack` ถอน ATK | `:21-26` |

## รากฐาน: ใช้ค่าคืนของ `calStack` เป็นตัวคูณ

```cpp
double value = calStack(ptr, 1, 2, "Danheng LC").first;   // จำนวนที่เพิ่มได้จริงหลัง clamp
buffSingle(ptr, {{ATK_P, value * (15 + 3*S)}});
ptr->energyRecharge += (5 + superimpose) * value;
extendBuffTime(ptr, "Danheng LC", 2);
```
`calStack` คืน `pair<int,int>` — `.first` คือจำนวนที่เพิ่มได้จริง (0 ถ้าเต็ม cap) → บัฟจะไม่บวกซ้ำเมื่อ stack เต็ม · **เป็นการใช้ `calStack` ที่ถูกต้องที่สุดในโปรเจกต์** (เทียบ `../../Relic/Wavestrider Captain.md` ที่ทิ้งค่าคืน)

## จุดที่ควรระวัง

**ถอน ATK ด้วย `buffCharResetStack` แต่ลงด้วย `buffSingle`** — คนละกลไก · `buffSingle` บวกค่าดิบโดย engine ไม่ได้นับ stack ให้ ส่วน `buffCharResetStack` ถอนตาม stack ที่ engine นับ → **ถ้า engine ไม่ได้นับ stack ของชื่อนี้ การถอนจะไม่ตรง** · ที่ถูกควรใช้ `buffStackSingle` ตอนลง หรือถอนด้วย `buffSingle` ติดลบคูณ stack เอง (แบบที่ทำกับ ER ใน `:23`)
