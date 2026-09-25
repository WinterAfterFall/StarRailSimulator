# `src/Defination/Data/Relic/Knight_of_Purity_Palace.h`

เซ็ตจริง: **Knight of Purity Palace** · `Relic.Name` = `"Knight"` (ชื่อย่อ)

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — DEF +15% | `Stats_type[Stats::DEF_P][AType::None] += 15` | 7 |
| 4-pc — Shield effectiveness +20% | `Stats_type[Stats::SHEILD][AType::None] += 20` | 8 |

ไฟล์สั้นที่สุดในกลุ่ม ไม่มี trigger ใด ๆ ทั้ง 2 อย่างอยู่ใน `Reset_List` ก้อนเดียว

## จุดที่ควรรู้

- **`Stats::SHEILD` ยังไม่มีผลจริง** — engine ยังไม่มีโค้ดที่ **เพิ่ม** โล่ให้ใคร (`decreaseSheild()` มีแล้วแต่ไม่มีตัวสร้าง) ดู `future-improvements.md` ข้อ 2 · ค่านี้จึงถูกเก็บไว้รอระบบ ไม่ได้ทำอะไรตอนนี้
- สะกด `SHEILD` (ไม่ใช่ `SHIELD`) ทั้ง enum และการใช้งาน — เวลา grep ต้องใช้ตัวสะกดนี้
