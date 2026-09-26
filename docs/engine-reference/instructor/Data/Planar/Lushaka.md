# `src/Defination/Data/Planar/Lushaka.h`

`Planar.Name` = `"Lushaka"` · เซ็ตจริง: **Lushaka, the Sunken Seas** · เซ็ตซัพพอร์ต

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| Energy Recharge +5% | `Reset_List` → `ptr->Energy_recharge += 5` | 8 |
| ถ้าผู้สวมใส่**ไม่ใช่เพื่อนช่องแรก** → เพื่อนช่องแรก ATK +12% | `WhenOnField_List` — **เช็คเงื่อนไขจริง** | 11-15 |

## จุดที่ควรรู้

- **ER เขียนที่ฟิลด์ `Energy_recharge` โดยตรง** ไม่ใช่ `Stats_type[Stats::ER]` — เป็นช่องคนละช่อง ต้องระวังเวลา grep หาว่าอะไรเพิ่ม ER ให้ตัวละคร
- **ผลตกที่ `charUnit[1]` เสมอ** (เพื่อนช่องแรกตามลำดับที่ประกอบทีม) เช็คด้วย `ptr->Atv_stats->num != 1` · เป็นเซ็ตเดียวในโฟลเดอร์ที่ผลขึ้นกับ **ตำแหน่งในทีม** → การสลับลำดับตัวละครตอนประกอบทีมเปลี่ยนผลลัพธ์
- บัฟลงด้วยการเขียน `Stats_type` ตรง ๆ ไม่ผ่าน `buffSingle` → **ไม่ยิง `StatsAdjust`** ถ้าเพื่อนช่องแรกมี trace ที่คำนวณจาก ATK แบบ live (ดู `../Character/Abundance/Gallagher.md`) ค่าจะไม่ตามไปด้วย
