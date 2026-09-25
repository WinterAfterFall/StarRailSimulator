# `src/Defination/Data/Planar/FirmanentFrontline.h`

`Planar.Name` = `"FirmanentFrontline"` · เซ็ตจริง: **Firmament Frontline: Glamoth** (ชื่อในโค้ดสะกดตก `e`) · **factory รับ `bool`**

```cpp
function<void(CharUnit *ptr)> FirmanentFrontline(bool trigger)
```

| `trigger` | ATK | DMG |
|---|---|---|
| `true` | +12% | +18% |
| `false` | +12% | +12% |

kit: DMG +12% เมื่อ SPD ≥ 135 และ **+18%** เมื่อ SPD ≥ 160 → `trigger` คือ "SPD ถึงชั้นบนหรือยัง" ที่ผู้ประกอบทีมตัดสินเอง

## จุดที่ควรรู้

- **โค้ดไม่รองรับกรณี SPD < 135** ซึ่ง kit ให้ DMG +0% — สาขา `false` ให้ +12% เสมอ จึงสมมติว่าผ่านชั้นแรกไปแล้วทุกกรณี
- **สองสาขา copy ทั้งก้อน** ต่างกันแค่ 18 vs 12 (ดู `GiantTree.md`)
- `Stats::DMG` ที่ `AType::None` = เข้าทุกประเภทดาเมจ
