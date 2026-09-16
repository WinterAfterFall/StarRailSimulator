# `src/Defination/Class/ActionData/EnemyActionData.h`

## taunt / การเลือกเป้าของ enemy

> **Concept ของ enemy basic (single-target) attack** — ไม่ได้จำลอง "1 การโจมตี = โดน 1 ตัว" ให้ตรงเกมจริง · เป้าหมายคือ (ก) จำลอง **energy** ที่ ally ได้จากการโดนตี (ข) จำลอง **การเสีย HP** เพื่อจุดชนวน mechanic ที่ผูกกับการโดนโจมตี (Blade / Clara / Mydei / Fu Xuan redistribution / Preservation counter / Meshing Cogs …) · สิ่งที่ต้องถูกคือ **จำนวนครั้งที่แต่ละตัวโดนตีต่อ N เทิร์น ≈ `N · taunt_i / Σtaunt`** — ไม่สนว่าการโจมตีเดียวจะโดน 0/1/หลายตัว

**field** (ระบบ taunt: `baseTaunt` + `tauntIncrease` → `taunt` → `Σ taunt ของ pool`)
| field | ที่อยู่ | ค่า |
|---|---|---|
| `baseTaunt` | AllyUnit | `tauntValueEachPath[path]` — Preservation 150 · Destruction 125 · Abundance/Harmony/Nihility/Remembrance/Elation 100 · Hunt/Erudition 75 (`Setting.h:50`) · เซ็ตที่ `StatsSet.h:27,52` |
| `tauntIncrease` | AllyUnit | **% เพิ่ม** (0 = ไม่มี) · `Stats_Reset` reset `= 0` ต่อ run · เพิ่มผ่าน `tauntIncreaseChange(+X)` เท่านั้น |
| `taunt` | AllyUnit | ค่า aggro จริง = `baseTaunt · (1 + tauntIncrease/100)` · `Stats_Reset` ตั้ง `= baseTaunt` ตรง ๆ (เท่ากับตอน `tauntIncrease=0`) · `tauntIncreaseChange` recompute |
| `tauntList` | **Enemy** | `vector<AllyUnit*>` — forced taunt (ดึง aggro บังคับ) |
| `AttackCoolDown` | **Enemy** | `map<string,double>` — ตัวสะสม weighted round-robin ต่อชื่อ ally |

**`calHitChance(vector<AllyUnit*> pool)`** (`AllyUnit.h:71`) = `taunt / Σtaunt(pool) * 100` — คำนวณ `Σtaunt` จาก pool สด ๆ ทุกครั้ง · **ตัวเดียวในระบบ** (no-arg version + `totalTaunt` global ลบทิ้งแล้ว 2026-09-04)

**การเลือกเป้าของ enemy basic attack** (`EnemyActionData::setBaAttack`)
1. สร้าง `pool`:
   - `tauntList` ไม่ว่าง → `pool` = สมาชิก `tauntList` ที่ `isTargetable()` และไม่ใช่ `Backup`
   - ไม่งั้น → `pool` = ทุกตัวใน `allyList` ที่ `isTargetable()` และไม่ใช่ `Backup` (รวม memosprite)
2. วน `pool`: `AttackCoolDown[name] += each->calHitChance(pool)` → ถ้า `>= 100` : `-= 100` + unit นั้นโดนเลือกในเทิร์นนี้ (ได้ energy + [ควร] โดนดาเมจ) · ถ้า `< 100` : `continue`
   → **deterministic weighted round-robin** (error-diffusion แบบ Bresenham) ไม่ใช่สุ่ม · แต่ละตัวสะสมที่อัตรา `calHitChance_i` ต่อโจมตี → โดนเลือกทุก ๆ `100/calHitChance_i` โจมตี → ต่อ N โจมตี โดน `N · taunt_i/Σtaunt` ครั้ง
   - **หลายตัวข้าม 100 พร้อมกันในโจมตีเดียว = ปกติตามดีไซน์** (ทีมสมมาตร taunt เท่ากัน → ทุก ๆ 4 โจมตีโดนพร้อมกัน 4 ตัว, 3 โจมตีระหว่างนั้นไม่โดนใคร — aggregate ต่อ N ยังถูก) · ไม่ใช่บั๊ก
   - **ไม่มี `break`** — ทุกตัวที่ข้าม 100 ในโจมตีนั้นถูกเลือกหมด
3. `Stats_Reset.h:145` วน `AttackCoolDown` reset เป็น 0 (**ต่อ run** — ไม่ reset ระหว่าง wave, เศษ aggro ค้างข้าม wave = ตั้งใจ ให้ error-diffusion ต่อเนื่อง)

**enemy AoE** (`setAoeAttack`) — วน `allyList` ทุกตัว (targetable, non-Backup) **โดนหมด ไม่สน taunt** · ให้ energy + ดาเมจทุกตัว

**cadence single vs AoE** (`SetEnemy.h:48`) — enemy ทำ `action` sub-action/เทิร์น · แต่ละครั้ง `++AoeCharge` · เป็น AoE เมื่อ `AoeCoolDown != 0 && AOEratio != 0 && AoeCharge % AoeCoolDown == AoeStart` ไม่งั้น single · ถ้าเทิร์นก่อนโดน break (`Toughness_status == 0`) → เทิร์นนี้ฟื้น toughness ก่อน (บันทึก broken time)

**`addTaunt`/`removeTaunt`** (`EnemyCombat.h:13`) — `addTaunt` มี **dedup** (เช็คชื่อก่อน push) · `removeTaunt(AllyUnit*)` erase ตัวแรกที่ชื่อตรง · _(`removeTaunt(string)` ลบทิ้งแล้ว 2026-09-04 — ไม่มี caller)_

**Mydei_Taunt lifecycle** (ตัวอย่าง forced-taunt ที่มีวันหมด, แยกอิสระต่อ enemy) — `Mydei.h`:
- ult (Blast) : ต่อ enemy ในเป้า → `debuffApply(ptr,e,"Mydei_Taunt",2)` (2 เทิร์น) + `e->addTaunt(Mydei)`
- technique (`Start_game_List`, AoE) : ต่อ enemy ทุกตัว → `debuffApply(ptr,e,"Mydei_Taunt",1)` (1 เทิร์น) + `e->addTaunt(Mydei)`
- `debuffApply` 4-arg refresh countdown เสมอ · `addTaunt` มี dedup ในตัว
- `After_turn_List` : เทิร์น enemy → `isDebuffEnd(e,"Mydei_Taunt")` จริง → `e->removeTaunt(Mydei)` — **ถอด Mydei ออกจาก tauntList ของ e ตัวนั้นตัวเดียว**
- แต่ละ enemy อิสระเต็มที่: A ครบเทิร์น → A เลิกบังคับตี Mydei ทันที แม้ B ยังบังคับอยู่
- enemy ในเกมนี้ **ไม่มี HP ไม่ตาย** → ไม่ต้องกันเคส "enemy ตายทั้งที่ยังติด taunt"

**taunt increase% (feature ที่ต่อสายไว้ให้)** — `tauntIncreaseChange(double value)` (`AllyUnit.h:62`):
```cpp
void tauntIncreaseChange(double value){ tauntIncrease += value; taunt = baseTaunt * (1 + tauntIncrease/100.0); }
```
trace "taunt +X%" → เรียก `ptr->tauntIncreaseChange(X)` (`value` = X ตรง ๆ) → `taunt = baseTaunt · (1 + X/100)` · **ยังไม่มี caller** — พร้อมใช้
> ⚠️ ถ้าเพิ่ม taunt ให้ **memosprite** ต้องเรียกใน `WhenOnField_List` (หลัง `Memosprite_reset`) ไม่ใช่ `Reset_List` — ไม่งั้น `Memosprite_reset` reset `tauntIncrease=0` / `taunt=baseTaunt` ทับ (ดู [Stats_Reset.md](../../Function/Setup/Stats_Reset.md))

- ✅ `UnitGotHit` populate แล้ว (2026-09-02, `EnemyActionData.h:47,72`) — enemy single-target สร้างความเสียหายจริง → ดู [🐞 #11](../../BUGS.md)
