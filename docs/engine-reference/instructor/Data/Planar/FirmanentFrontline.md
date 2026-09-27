# `src/Defination/Data/Planar/FirmanentFrontline.h`

`Planar.Name` = `"FirmanentFrontline"` · เซ็ตจริง: **Firmament Frontline: Glamoth** (ชื่อในโค้ดสะกดตก `e`) · **factory รับ `bool`**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| ATK +12% | บวก ATK% ถาวร (มีทั้งสองสาขา) | `FirmanentFrontline.h:8` (`true`) · `:16` (`false`) |
| DMG +12% (SPD ≥ 135) / +18% (SPD ≥ 160) | ผู้ประกอบทีมเลือกชั้นผ่าน `trigger` · `true` = 18, `false` = 12 · ไม่มีกรณี 0% | `:9` · `:17` |

factory `FirmanentFrontline(bool trigger)` (`:3`) คืน lambda คนละก้อน

kit: DMG +12% เมื่อ SPD ≥ 135 และ **+18%** เมื่อ SPD ≥ 160 → `trigger` คือ "SPD ถึงชั้นบนหรือยัง" ที่ผู้ประกอบทีมตัดสินเอง

## จุดที่ควรรู้

- **โค้ดไม่รองรับกรณี SPD < 135** ซึ่ง kit ให้ DMG +0% — สาขา `false` ให้ +12% เสมอ จึงสมมติว่าผ่านชั้นแรกไปแล้วทุกกรณี
- **สองสาขา copy ทั้งก้อน** ต่างกันแค่ 18 vs 12 (ดู `GiantTree.md`)
- `Stats::DMG` ที่ `AType::None` = เข้าทุกประเภทดาเมจ
