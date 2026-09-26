# `src/Defination/Data/Planar/GiantTree.h`

`Planar.Name` = `"GiantTree"` · เซ็ตจริง: **Sprightly Vonwacq** ไม่ใช่ — เซ็ตนี้คือ **Giant Tree of Rapt Brooding** · **factory รับ `bool`**

```cpp
function<void(CharUnit *ptr)> GiantTree(bool trigger)
```

| `trigger` | SPD | Outgoing Healing |
|---|---|---|
| `true` | +6% | +20% |
| `false` | +6% | +12% |

kit: SPD +6% · Outgoing Healing **+12% เมื่อ SPD ≥ 135** และ **+20% เมื่อ SPD ≥ 180** → `trigger` คือ "SPD ถึงชั้นบน (180) หรือยัง" ที่ผู้ประกอบทีมตัดสินเอง ไม่ใช่โค้ดเช็คให้

## จุดที่ควรรู้

- **โค้ดไม่รองรับกรณี SPD < 135** ซึ่ง kit ให้ Healing +0% — สาขา `false` ให้ +12% เสมอ จึงสมมติว่าผ่านชั้นแรกไปแล้วทุกกรณี (เหมือน `FirmanentFrontline.md`)
- เรียกใช้จากฝั่งตัวละครเป็น `Planar::GiantTree(true)` แล้วส่งผลลัพธ์เข้า `Setup` (ดู `../README.md`) — `Luocha.h` และ `Gallagher.h` เป็นลูกค้าหลักของเซ็ตนี้
- **สองสาขาถูก copy ทั้งก้อน ต่างกันแค่ตัวเลขเดียว** (20 vs 12) เหมือน `FirmanentFrontline.h` และ `../Relic/Diviner of Distant Reach.md` · ยุบเป็น `double heal = trigger ? 20 : 12;` แล้วเหลือ lambda เดียวได้
- SPD เขียนที่ `Atv_stats->speedPercent` ไม่ใช่ `Stats_type[Stats::SPD_P]`
