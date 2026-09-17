# LOG — บันทึกการไล่โค้ด

## สรุป session ล่าสุด — 2026-09-17

### สรุปรอบล่าสุดและจุดพัก

- สำรวจ `AllyActionData`, `AllyAttackAction`, `AllyBuffAction` และโครงสร้าง `Damage` / `DmgSrc` แล้วตามรายละเอียดในไฟล์คู่มือแต่ละคลาส ยังไม่เหมารวมว่าครบทุก method
- ข้อชี้แจงสำคัญ: `addDamageIns` เพิ่มรอบโจมตี ส่วน `addDamageHit` เพิ่ม hit ในรอบล่าสุด โค้ดเดิมถูกต้องแล้ว
- รวมเมธอดตรวจ attack/buff ไว้ใน `AllyActionData`; attack ตรวจทุกคนใน `AttackSetList`, buff ตรวจ `Attacker` โดยตรง ใช้ชื่อ `isSameOwnerName`, `isSameOwnerAction` และ `isSameOwnerDamageType`
- การตรวจ owner ด้วยชื่อ `string` เป็นเพียงแนวคิดที่อาจ implement ภายหลัง ดู [future-improvements.md](../future-improvements.md) ไม่ใช่งานที่อนุมัติให้ทำตอนนี้
- Commit และ push ขึ้น `main` แล้ว: `7bb5dea` ตั้งชื่อ owner ฝั่ง buff (ก่อนรวม), `2ca1abd` รวมเมธอดตรวจ, `5165273` เอกสารการสำรวจและงานค้าง ตรวจ `g++ -std=c++17 -fsyntax-only Application.cpp` และ `git diff --check` ผ่าน ยังไม่ได้รัน simulation เต็ม
- หลัง push working tree สะอาด; การอัปเดตบันทึกครั้งนี้เกิดหลัง `5165273`
- อ่านเอกสารก่อนถาม และถามเฉพาะเรื่องที่ยังไม่อธิบาย ห้ามถามซ้ำเพียงเพราะเปลี่ยนชื่อเมธอด

### จุดที่สำรวจถึง

- วิธีทำงาน: ถาม user ทีละหัวข้อ เทียบกับโค้ดเมื่อจำเป็น แล้วบันทึกใน `.md` ที่ตรงกับไฟล์นั้น
- `CharUnit.h`: ได้คำอธิบาย field ที่ค้างแล้ว ได้แก่ summon/memosprite/countdown lists, relic main stats, requirement stats, `Technique`, `Print`, `Adjust`, `path`, `Eidolon` ดู [CharUnit.md](Class/Unit/CharUnit.md) แต่ยังไม่ถือว่าไล่ทุก method และสูตรครบ
- `Enemy.h`: อธิบาย field ทั้ง 4 ของ `BreakSideEffect` แล้ว และตรวจเส้นทาง Damage Record จริงแล้ว: เก็บตัวอย่างดาเมจสะสมต่อ ATV ฝั่ง CharUnit แล้วรวมผลฝั่ง Enemy ตอนพิมพ์สรุป
- กลุ่ม debuff ของ Enemy: user อธิบาย `debuffCheck`, `debuffNote`, `stack` แล้ว ส่วน `debuffEnd` ตรวจโค้ดแล้วว่าเก็บเลขเทิร์นหมดอายุ ดู [Enemy.md](Class/Unit/Enemy.md)
- `Total_debuff`: user ยืนยันว่านับจำนวนสถานะ รวมสถานะจาก Break ไม่ใช่จำนวนสแต็ก เช่น ลด DEF + Wind Shear 3 สแต็ก นับเป็น 2 สถานะ
- กลุ่มพลังโจมตีศัตรู: user ยืนยัน `ATK` เป็นค่าตั้งต้น (`718`), `atkPercent` เป็นเปอร์เซ็นต์เพิ่ม/ลด ATK และ `dmgPercent` เป็นเปอร์เซ็นต์เพิ่ม/ลดดาเมจแยกจาก ATK; เปอร์เซ็นต์ทั้งสองเริ่มที่ `0`

- กลุ่ม toughness: user ยืนยัน `Max_toughness` เป็นความทนทานสูงสุด, `Current_toughness` เป็นค่าที่เหลือ และ `Toughness_status` ใช้ `1` = ยังไม่ Break / `0` = อยู่ในสถานะ Weakness Break

- `toughnessAvgMultiplier`: user ยืนยันว่าเป็นตัวคูณดาเมจเฉลี่ยถ่วงตามเวลา ATV ระหว่างยังไม่ Break (`0.9`) กับอยู่ในสถานะ Break (`1.0`) สำหรับสมุด non-real-time

- `Target_type`: user ยืนยันว่าแบ่งศัตรูตามตำแหน่งเทียบกับเป้าหมายหลัก: `Main` / `Adjacent` / `Other`

- `AttackCoolDown`: user ยืนยันว่าใช้สะสมโอกาสโดนโจมตีแยกตามชื่อยูนิตแทนการสุ่มเป้าหมาย; สะสมถึง `100` จึงโดนโจมตีแล้วหัก `100` เก็บเศษไว้

- `AoeCharge`: user ยืนยันว่าเพิ่มทุกแอ็กชันโจมตี ใช้ modulo กับ `AoeCoolDown` เทียบ `AoeStart` เพื่อกำหนดรอบ AoE; หนึ่งเทิร์นที่มีหลายแอ็กชันเพิ่มหลายครั้ง

- `tauntList`: user ยืนยันว่าเก็บยูนิตที่ยั่วยุศัตรูตัวนี้; การโจมตีปกติเลือกจากกลุ่มนี้โดยใช้ `calHitChance` / `AttackCoolDown` ส่วน AoE ยังโจมตีทุกยูนิตที่เป็นเป้าหมายได้

- `toughnessReduceNote`: user ยืนยันว่าเป็นที่พักค่าลดความทนทานรวมต่อเป้าหมายสำหรับคำนวณ Super Break โดยสะสมจาก `damageSplit` แล้วปรับผ่าน `Cal_Total_Toughness_Reduce`

- แก้ข้อสรุป `Enemy::hitCount`: user ยืนยันว่ามีการใช้งาน ไม่ใช่ dead code; ตรวจพบการรีเซ็ตและเพิ่มตัวนับใน `Attack()` แล้ว ยังไม่ได้ไล่รายละเอียดการอ่านค่าฝั่ง Enemy ครบ
- `nextToLeft` / `nextToRight`: user ยืนยันว่าชี้ศัตรูซ้าย/ขวา สำหรับตัวละครที่มีสกิลต้องรู้เป้าหมายข้างเคียง

- รายการสถานะ Break: user ยืนยัน `breakDotList` สำหรับ Bleed/Burn/Shock/Wind Shear, `breakImsList` สำหรับ Imprisonment, `breakEngList` สำหรับ Entanglement และ `breakFrzList` สำหรับ Freeze

- ตัวนับ DoT: user ยืนยันนับจำนวนสถานะจากทั้งสกิลและ Break ไม่ใช่จำนวนสแต็ก; สถานะแบบสะสมสแต็กหนึ่งอันนับ 1 DoT แม้มี 50 สแต็ก

- Methods ตัวนับ DoT: user ยืนยัน `changeShock` / `changeWindSheer` / `changeBleed` / `changeBurn` ปรับตัวนับประเภทนั้นและ `DotCount` พร้อมกัน; `changeDotType` เลือก method ตามประเภทที่ส่งมา

- `addBreakSEList`: user ยืนยันว่าคนเดิมทำ Break ซ้ำให้อัปเดตสถานะเดิม ส่วนคนละคนเก็บแยกกัน; ตรวจชื่อผ่าน `isSameName`, อัปเดต `countdown` และกลุ่ม DoT บวกสแต็กเพิ่ม

- **`Enemy.h` จบแล้ว (2026-09-16)** — ปิดของค้างจากโค้ดโดยไม่ต้องถาม: ค่าที่ `addBreakSEList` ส่งกลับ (ผู้ใช้จริงคือ Imprisonment ลด SPD เฉพาะตอนเพิ่มใหม่ `Combat.h:372`), `debuffCheck` เป็น flag `0`/`1` เท่านั้น, กลุ่ม Weakness (`Default_Weakness_type` / `Weakness_type` / `Weakness_typeCountdown` / `DefaultElementRes` / จำนวนธาตุอ่อนแอ) และคู่เวลา Break (`when_toughness_broken` / `Total_toughness_broken_time`) ดู [Enemy.md](Class/Unit/Enemy.md) · ที่เหลือใน `Enemy.h` เป็น constructor, getter/setter และ method ที่ประกาศไว้ (ตัวจริงอยู่ `EnemyCombat.h` ไล่แล้วตอนทัวร์ taunt)
- **`StatsSet.h` จบแล้ว (2026-09-16)** — `SetAllyBaseStats` ใช้ `+=` เพราะตัวละครกับ LC เรียกคนละครั้ง · กฎ `SetMemoStats` ต้องเรียกหลัง base + LC + Relic + Planar เพราะถ่ายค่าฐานของเจ้าของครั้งเดียว · ตาราง factory 4 ตัว (ลิสต์ที่ใส่, `side`, `num` ร่วมกับเจ้าของ, `owner`) ดู [StatsSet.md](Class/Unit/StatsSet.md)
- **`MemoSprite.h` จบแล้ว (2026-09-16)** — 4 field = HP/SPD ส่วนคงที่ (`fixHP` / `fixSpeed`) + ส่วนอิงเจ้าของ (`Unit_Hp_Ratio` / `Unit_Speed_Ratio`) ดู [MemoSprite.md](Class/Unit/MemoSprite.md) · **โฟลเดอร์ `Class/Unit` ครบทุกไฟล์แล้ว** (รายละเอียดสูตร/method บางส่วนของ CharUnit ยังค้างตามที่ระบุใน CharUnit.md)
- **เริ่ม `Class/ActionData` (2026-09-16)** — อ่าน `ActionData.h` / `AllyActionData.h` แล้ว; user ยืนยัน `Attacker` / `source`, `Turn_reset`, `traceType` และการตรวจชื่อผู้โจมตีแล้ว (ดูหัวข้อเริ่มครั้งหน้า)

### งานที่ทำและสถานะ Git

- 2026-09-16: แก้ `Enemy::addBreakSEList` ตามคำขอ user ให้เพิ่มรายการและตัวนับ DoT เฉพาะแขนง DoT; Freeze / Imprisonment / Entanglement ไม่ไหลไปเพิ่ม DoT อีก **commit แล้ว: `26a7da1` — `fix: exclude non-DoT break effects from DoT counters`** (commit นี้มีเฉพาะ `Enemy.h`)
- ระหว่างตรวจการแก้ สร้าง regression test ที่ `test/break_status_regression.cpp`; ไม่ได้รวมไฟล์ทดสอบใน commit ข้างต้น
- ผลตรวจการแก้ครั้งนี้: regression test ล้มก่อนแก้ด้วย non-DoT ถูกนับเป็น DoT และผ่านหลังแก้ครบ 7 ประเภท รวมต่ออายุ แยกผู้ทำ Break และ 50 สแต็กนับเป็น 1 DoT; `g++ -std=c++17 -fsyntax-only Application.cpp` ผ่าน ยังไม่ได้รัน simulation เต็ม

- `6c5c0e5` — commit เอกสารเปลี่ยนชื่อ field และบันทึกการสำรวจ
- `88768ad` — commit เปลี่ยนชื่อ field ในโค้ด 51 ไฟล์; ตรวจ snapshot ที่ commit ด้วย `g++ -std=c++17 -fsyntax-only Application.cpp` ผ่าน
- user ลบ `Wait_Other_Buff` จาก CharUnit และ declaration ของ `Set_Other_buff`; จากนั้นลบตัวฟังก์ชันและคอมเมนต์เก่าที่เหลือใน `CharCmd.h` ตามคำขอแล้ว
- หลังลบ ตรวจไม่พบ `Wait_Other_Buff` / `Set_Other_buff` ใน `src` และตรวจ syntax ของ `Application.cpp` ผ่าน (ไม่ได้รัน simulation ใน session นี้)
- การลบดังกล่าวในไฟล์โค้ดทั้ง 3 ไฟล์ commit แล้วที่ `000a3ef`
- 2026-09-16 (รอบสอง): push แล้ว `678923f..a417361` — `55713b9` แก้ลำดับ setup ของ Castorice ([🐞 #19](BUGS.md)) · `a417361` เอกสาร Enemy.h ช่วงท้าย + แก้บันทึก Dahlia ให้ตรงโค้ด · `g++ -std=c++17 -fsyntax-only Application.cpp` ผ่าน ยังไม่ได้รัน sim
- เอกสารค้าง `StatsSet.md`, `MemoSprite.md`, `BUGS.md` (#19) รวม commit และ push แล้วใน `5165273` (2026-09-17)
- 2026-09-16: **commit และ push ของค้างทั้งหมดแล้ว** (`e45232a..678923f`) working tree สะอาด แยกเป็น 4 commit: `000a3ef` ลบ `Set_Other_buff` · `e65743d` Dahlia SPB → สมุดเฉลี่ย · `ca7fde7` เปลี่ยนคำว่า "ลงดาเมจ" เป็น "สร้างความเสียหาย" ทั่วเอกสาร · `678923f` บันทึกทัวร์ `Enemy.h` · `test/break_status_regression.cpp` ไม่เข้า git เพราะ `test/` อยู่ใน `.gitignore`

### Dahlia — ปัญหา วิธีแก้ และสถานะล่าสุด

- ประเด็นที่ต้องการปรับ: Super Break ตั้งต้นใช้สมุดคิดสด แต่ Dahlia ทำ Super Break บนศัตรูที่ยังไม่ Break ได้ จึงปรับให้ใช้ตัวคูณ toughness เฉลี่ยตามเวลา นี่เป็นการเลือกวิธีคำนวณของ simulator ไม่ใช่ข้อสรุปว่าการคิดสดผิดเสมอ
- วิธีแก้ที่ลงจริง: ใน `Superbreak_trigger()` ตั้ง `toughnessAvgCalculate` ก่อนเรียกคำนวณ Super Break โดยดูจาก `DahliaCheck` — มี Dahlia ในทีมใช้สมุดเฉลี่ย ไม่มีใช้สมุดคิดสด (ไม่ได้แยกตามสถานะ Break ของเป้าแต่ละตัว ดูข้อเตือนด้านล่าง)
- ไฟล์โค้ดที่แก้มี **2 ไฟล์** ไม่ใช่ไฟล์เดียว:
    - `src/Defination/Function/Combat/Combat.h:254-256` เพิ่มคอมเมนต์ 2 บรรทัดและ `data_2->toughnessAvgCalculate = DahliaCheck ? 1 : 0;`
    - `src/Defination/Data/Character/Nihility/Dahlia.h:193` ลบการตั้ง `DahliaCheck = 0` / `DahliaCheck = 1` ที่คร่อม `Superbreak_trigger(act,200,"Dahlia")` ของ FuA ออก
- ⚠️ **เงื่อนไขคือ `DahliaCheck` ไม่ใช่ `Toughness_status` ของเป้า** — `DahliaCheck` เป็น global (`Setting.h:22`) ที่ตั้ง `1` ครั้งเดียวตอน build ตัว Dahlia (`Dahlia.h:20`) และไม่เคยเคลียร์ จึงแปลว่า "ทีมนี้มี Dahlia" ผลคือทีมที่มี Dahlia จะส่ง SPB **ทั้งหมด** เข้าสมุดเฉลี่ย รวมเป้าที่ broken ไปแล้ว ถ้าอยากแยกรายเป้าจริง ๆ ต้องอ่าน `enemyUnit[i]->Toughness_status` เพิ่ม
- user ขอ revert แล้วเปลี่ยนคำขอให้คืนโค้ดกลับก่อน revert; ทำตามคำขอล่าสุดแล้ว
- ตรวจ `g++ -std=c++17 -fsyntax-only Application.cpp` ผ่าน; **ยังไม่ได้รัน simulation เต็ม** หรือยืนยันผลเชิงตัวเลขของการเลือกสมุดเฉลี่ยสำหรับ Dahlia
- รายละเอียดกลไกดู [CalDamageNote.md](Function/Calculate/CalDamageNote.md)

### เริ่มครั้งหน้าตรงนี้

1. **`Attacker` กับ `source` ยืนยันแล้ว (2026-09-16)** — `Attacker` คือผู้ทำแอ็กชัน ส่วน `source` เป็นเจ้าของค่าพลังฐานสเกล ATK/HP/DEF; CR/CD, DMG%, การลด DEF และ RES PEN ยังอิง `Attacker` ตัวอย่าง Netherwing ใช้ HP ของ Castorice แต่ใช้ค่าคริติคอลและ stats อื่นของตัวเอง ดู [AllyActionData.md](Class/ActionData/AllyActionData.md) · `Turn_reset` ยืนยันแล้ว: บ่งบอกว่าหลังจบแอ็กชันจะรีเซ็ตเทิร์นหรือไม่ · `traceType` ยืนยันแล้ว: รูปแบบเป้าหมาย Single / Blast / Aoe / Bounce · `isSameName` / `isSameOwnerName` ยืนยันแล้ว: ตรวจยูนิตโดยตรง / รวมยูนิตของตัวละครนั้น · `isSameAction` / `isSameOwnerAction` ถามแล้ว ห้ามถามซ้ำ · `getChar()` ยืนยันแล้ว: คืนตัวละครเจ้าของเมื่อผู้โจมตีเป็น memosprite หรือคืนตัวละครผู้โจมตีเอง · `AttackSetList` / `switchAttacker` ยืนยันแล้ว 2026-09-17: ผู้ร่วมโจมตีและจังหวะสลับภายในแอ็กชันเดียว ดู [AllyAttackAction.md](Class/ActionData/AllyAttackAction.md) · `damageSplit` ยืนยันแล้ว 2026-09-17: ชั้นนอกแบ่งจังหวะโจมตี ชั้นในเก็บดาเมจต่อเป้าหมายในจังหวะนั้น · `Damage` ยืนยันแล้ว 2026-09-17: จับคู่เป้าหมายกับสเกลดาเมจ ค่าคงที่ และค่าลด toughness · หน่วย `DmgSrc` ยืนยันแล้ว 2026-09-17: สเกลเป็นเปอร์เซ็นต์, constDmg เป็นค่าคงที่, toughnessReduce เป็นหน่วย toughness · `critAble` / `critGarantee` ยืนยันแล้ว 2026-09-17: เปิด/ปิดการติดคริ และตัวบังคับคริที่ยังไม่ได้ใช้งาน · `targetList` ยืนยันแล้ว 2026-09-17: รายชื่อเป้าหมายไม่ซ้ำของแอ็กชัน · `Damage_element` ยืนยันแล้ว 2026-09-17: ธาตุดาเมจเริ่มจากผู้โจมตีและเปลี่ยนได้ · `actionFunction` อธิบายแล้ว 2026-09-17: รายละเอียดแอ็กชันมีมาก จึงใช้ callback เพื่อ custom ได้ง่าย · `addDamage` ยืนยันแล้ว 2026-09-17: เพิ่มค่าที่ระบุให้ทุกรายการใน damageSplit · `addDamageIns` / `addDamageHit` ยืนยันแล้ว 2026-09-17: เพิ่มรอบโจมตี / เพิ่ม hit ในรอบนั้น โค้ดถูกต้องแล้ว ไม่ต้องแก้ · `multiplyDmg` ยืนยันแล้ว: คูณ ATK/HP/DEF/constDmg ด้วย value/100 ไม่เปลี่ยน toughnessReduce/Elation · ท่า Bounce ยืนยันแล้ว: วนเป้าหมายแทนการสุ่ม, bestBounce เลือกเป้าหลัก, FairBounce กระจายทั่วกลุ่ม · `setJoint()` ยืนยันแล้ว: เตรียมโจมตีร่วมกับ memosprite และติดประเภท Summon · `addDamageInsByDebuff` ยืนยันแล้ว: เลือกศัตรูที่ยังไม่มีดีบัฟเพื่อกระจายให้ครบก่อน แล้วกลับไปเป้าหลัก · `AllyBuffAction` ยืนยันแล้ว: buffTargetList เก็บเป้าหมายฝ่ายเรา, actionFunction กำหนดผลต่อเป้าหมาย · `addBuffChar` / `addBuffAllAllies` ยืนยันแล้ว: รวม memosprite และเว้น OutofBounds · `addBuffSingleTarget(ptr)` ยืนยันแล้ว: ผู้เรียกตรวจความเหมาะสมเอง ไม่กรอง OutofBounds · รวมเมธอดตรวจ buff ให้ใช้ AllyActionData แล้ว; เมธอด owner ใช้ isSameOwnerAction / isSameOwnerDamageType
2. ครั้งหน้า: ตรวจส่วนที่ยังไม่ได้บันทึกของ `Class/ActionData` เทียบคู่มือเดิมก่อน โดยเฉพาะ constructors, helpers และการเข้าคิว; เรื่อง toughnessAvgCalculate, damageNote, Dont_care_weakness และ Aha มีข้อมูลในคู่มือ Function/Unit อยู่แล้ว ให้อ้างอิงก่อนถาม · กฎ actionTypeList / damageTypeList ยืนยันแล้ว 6 ข้อ ห้ามถามซ้ำ
3. จากนั้นไล่ส่วนที่เหลือของ `Class/CombatData`: `Damage` / `DmgSrc` และหน่วยอธิบายแล้ว ไม่ต้องเริ่มใหม่; ต่อ `HealData.h` แล้ว `Class/Trigger`
4. เก็บงานค้าง: เปลี่ยน `path` / `Element_type` เป็นค่าเดี่ยว (ยังไม่ทำ), รายละเอียดสูตร CharUnit ที่ยังไม่ได้ไล่, Dahlia SPB บนเป้าที่ broken แล้วยังลงสมุดเฉลี่ย (user: ช่างมัน), ยังไม่ได้รัน sim ยืนยันผล Dahlia / Castorice

## ประวัติการสำรวจ

> บันทึกก่อน **2026-09-13 (ต่อ 6)** เขียนตอนเอกสารยังเป็นไฟล์เดียว `docs/engine-reference/unit.md` — การอ้างถึงหัวข้อในบันทึกเก่าถูกเปลี่ยนเป็นลิงก์ไปไฟล์ใหม่แล้ว

**2026-09-02** — ทัวร์โค้ดรอบแรก: แก้ description `extraTurn` / `Type` / `priority` · เพิ่ม [Combat.md](Function/Combat/Combat.md) (aha) · กลไก freeze ใน [Combat.md](Function/Combat/Combat.md) · [Stats_Reset.md](Function/Setup/Stats_Reset.md) (Memosprite) · แก้โค้ด `HpAdjust` + rename `Turn_priority` → `nextForwardPriority`

**2026-09-04** — โฟกัสระบบ **taunt + การรับดาเมจ** · push 4 commit:
| commit | ทำอะไร |
|---|---|
| `8690113` | `UnitGotHit` populate (enemy single-target สร้างความเสียหาย 0 → แก้) · `DecreaseHP` ทั้งทีม `return`→`continue` · `addTaunt` dedup · Mydei_Taunt lifecycle (ult 2t / tech 1t / per-enemy removal) · `currentMemoNum` self-assign fix |
| `ce329ef` | ลบ dead code taunt: `totalTaunt` · no-arg `calHitChance()` · `removeTaunt(string)` · + `nextForwardPriority` reset, Enum comment |
| `4d2aa35` | `tauntMtpr` (100=×1) → `tauntIncrease` (0=ไม่มี) · `taunt = baseTaunt·(1+tauntIncrease/100)` · `tauntIncreaseChange(double)` |
| `babcc2f` | เอกสารชุดนี้เข้า git |

**2026-09-09** — เริ่มทัวร์ `CharUnit.h` · จบ **[CharUnit.md](Class/Unit/CharUnit.md)**: คลาสผู้ช่วย 4 ตัว (`Func_class` `DamageSrc` `DamageRecord` `DamageAvgRecord`) + **โมเดล True DMG** (ทำไม `DamageSrc` ต้องมี `src` **และ** `recv`, engine implement เป็น note ล้วนผ่าน `Cal_DamageNote` ไม่ใช่ AType) · ค้นยืนยันกับ wiki/Game8 · เจอ [🐞 #16](BUGS.md) (non-real-time True DMG คูณ toughnessAvgMultiplier ของ `recv` แทน `src`)

**2026-09-13** — ทัวร์ `CharUnit.h` ต่อ · เพิ่ม **[CalDamageNote.md](Function/Calculate/CalDamageNote.md)** (สมุดดาเมจ 2 เล่ม real-time vs non-real-time + `toughnessAvgCalculate` + ข้อยกเว้น Dahlia) และ **[Energy.md](Function/Combat/Energy.md)** (energy: convention 2-arg/3-arg ของ `Increase_energy`, `Ult_cost` vs `Max_energy`, `Max_energy == 0`) · **แก้คำอธิบายที่กลับข้างใน [CharUnit.md](Class/Unit/CharUnit.md) + [🐞 #16](BUGS.md)** — เดิมเขียนว่า Break/SPB/DoT ตกสมุดเฉลี่ย ที่ถูกคือ Break/SPB ตกสมุด**คิดสด** ส่วน DoT + การโจมตีปกติตกสมุด**เฉลี่ย** → ทำให้ [🐞 #16](BUGS.md) เป็นเคสหลักไม่ใช่เคสหายาก

**2026-09-13 (ต่อ)** — เพิ่ม **[FormulaCheck.md](Function/AdjustFunction/FormulaCheck.md)** (CalCheck: โครง 3 ชั้น `All`/กลุ่ม `Src`+`Crit`/เดี่ยว + ถอดตัวย่อ `Mtgt` `MtprInc` `SpbInc` `MM` `PL`/`CB`) · **แก้ [🐞 #18](BUGS.md)** — `calPunchLineMultiplier` อ่าน `Merrymake` แทน `CertifiedBanger` ฝั่งเป้าหมาย 4 จุด (copy-paste จาก `calMerryMakeMultiplier`) คอมไพล์ผ่าน

**2026-09-13 (ต่อ 2)** — เพิ่ม **[Substats_Reset.md](Function/Setup/Substats_Reset.md)** (substats reroll) · **refactor ระบบ reroll ให้โครงเดียวกับ WuwaSimulator**: ตั้งชื่อตัวแปรใหม่ (`spiltPoint` → `rerollTargetIndex` ฯลฯ) · เขียน `StandardReroll` ใหม่ + แยก `trySwapSubstat` / `restoreBestSubstats` · ลบ `SeparateRatio` · ลบ `Damage_data` / `*_Compare` + `Print_All_Substats` (user สั่งทิ้ง E3/E4) · comment `AllCombination` / `AllPossible` ทั้งหมด · เทียบผลเก่า/ใหม่ด้วย Python 6000 เคส ผลตรงกันทุกเคส · เพิ่มหมายเหตุใน [🐞 #16](BUGS.md) (`Cal_DamageSummary` ใช้ `src` ถูกแล้ว ที่ผิดคือ `Cal_AverageDamage`)

**2026-09-13 (ต่อ 3)** — user ตอบ E2: จำนวน roll รวมกำหนดเอง ปกติ **25** · ลบ `currentTotalSubstats` (ไม่มีใครอ่าน) · ปิด [🐞 #8](BUGS.md) (summon/countdown ไม่ได้ใช้ `owner`) · dead code ปล่อยไว้ · [🐞 #16](BUGS.md) ระบุบรรทัดแล้ว (ต้องแก้ 2 จุด) · **ต่อจากนี้ทำทีละหัวข้อ**

**2026-09-13 (ต่อ 4)** — แก้ตามที่ user สั่ง: `Total_substats` ค่าเริ่มต้น 20 → 25 · [🐞 #1](BUGS.md) ลบ include ซ้ำ · [🐞 #2](BUGS.md) summon ใช้ชื่อที่ส่งมา (`LL`) · [🐞 #4](BUGS.md) rename `isExsited` → `isExisted` (9 จุด) · [🐞 #16](BUGS.md) `Cal_AverageDamage` อัปเดตตัวคูณเฉลี่ยให้ศัตรูทุกตัว แล้วใช้ของ `src` · คอมไพล์ผ่าน

**2026-09-13 (ต่อ 5)** — เพิ่ม **[CharUnit.md](Class/Unit/CharUnit.md)** (Build: `Func_class` 4 ช่อง) · ลบเงื่อนไขอัลติของ Tribbie ทั้งก้อน (DDD 2 บรรทัด + เช็ค Eagle ผิดช่องที่ไม่มีวันจริง) · ลบเช็ค DDD ของ Hanabi / HanabiV1 (ใส่ DDD แล้วไม่มีวันกดอัลติ) · แก้ชื่อ planar `Rutilant` / `Inert` · user: เก็บช่อง `Name` / `Print_Func` ไว้ก่อน

**2026-09-13 (ต่อ 6)** — ย้าย `docs/engine-reference/unit.md` ทั้งไฟล์มาเป็น `instructor/` ที่ mirror โครง `src/Defination/` (README ทุกโฟลเดอร์ + `.md` ทุกไฟล์โค้ด · ไฟล์ที่ยังไม่มีข้อมูลปล่อยว่าง) · บั๊กย้ายไป [BUGS.md](BUGS.md) · บันทึกนี้ย้ายมาเป็น LOG.md · ปรับสถานะ [🐞 #7](BUGS.md) เป็น ✅ (โค้ดแก้ไปตั้งแต่ `8690113` แต่รายการเดิมลืมอัปเดต)

**2026-09-16** — ปิด `Enemy.h` · `StatsSet.h` · `MemoSprite.h` (โฟลเดอร์ `Class/Unit` ครบ) · แก้ `addBreakSEList` นับ DoT ผิด (`26a7da1`) · ลบ `Set_Other_buff` (`000a3ef`) · commit งาน Dahlia (`e65743d`) และแก้เอกสารให้ตรงโค้ดจริง (`DahliaCheck` ไม่ใช่ `Toughness_status`) · sweep คำว่า "สร้างความเสียหาย" (`ca7fde7`) · [🐞 #19](BUGS.md) Castorice สร้าง Netherwing ก่อนค่าฐาน (`55713b9`) · เริ่ม `Class/ActionData` · **user ย้ำ: อ่าน md ที่มีก่อนถาม อย่าถามซ้ำสิ่งที่บันทึกไว้แล้ว**

**บันทึกย่อยวันที่ 2026-09-15 (จุดต่อปัจจุบันให้ดูสรุป session ด้านบน):**
- **2026-09-15 (ต่อ 20)** — ตรวจชื่อ field ใหม่ใน `Enemy.h` / `AllyUnit.h` และปรับเอกสารอ้างอิง: `DebuffNote` → `debuffNote`, `Debuff_time_count` → `debuffEnd`, `Stack` → `stack`, `Buff_note` → `buffNote`, `Buff_countdown` → `buffEnd`, `Buff_check` → `buffCheck` · `debuffCheck`, `buffSubUnitTarget`, `buffAllyTarget` ตรงกับโค้ดแล้ว · ชื่อ accessor เดิมยังคงอยู่ · เก็บชื่อเก่าในบันทึกย้อนหลังไว้ตามเหตุการณ์ · ตรวจกลไก `debuffEnd` จาก `Debuff_Stats.h` แล้ว
- **2026-09-15 (ต่อ 19)** — user ยืนยันว่า `Enemy::Stack` เก็บจำนวนสแต็กตามชื่อ · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `Debuff_time_count`
- **2026-09-15 (ต่อ 18)** — user อธิบาย `DebuffNote` ว่าเก็บปริมาณเอฟเฟกต์เดิมของ debuff เพื่อคำนวณส่วนต่างเมื่ออัปเดต เช่น ลด DEF ตาม ATK ผู้ร่าย · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `Stack`
- **2026-09-15 (ต่อ 17)** — user เปลี่ยน `Enemy::Debuff` เป็น `debuffCheck` และอธิบายว่าใช้เช็กว่า debuff นั้นยังอยู่หรือไม่ · ตรวจชื่อใหม่ใน `Enemy.h` แล้ว · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `DebuffNote`
- **2026-09-15 (ต่อ 16)** — ตรวจเส้นทาง Damage Record ตามคำขอ user: ระหว่างต่อสู้เก็บฝั่ง `CharUnit`, ค่าเฉลี่ยเก็บตัวอย่างดาเมจสะสม / ATV ตั้งแต่ ATV 300 โดยเพิ่มตัวอย่างเมื่อห่างอย่างน้อย 20 ATV; field ของ `Enemy` รวมตอน `printSummaryResult()` · บันทึกใน [Enemy.md](Class/Unit/Enemy.md)
- **2026-09-15 (ต่อ 15)** — user ยืนยันว่า `BreakSideEffect::type` ระบุชนิดสถานะจาก Break · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · อธิบาย field ทั้ง 4 ตัวแล้ว ถัดไปกลุ่ม Damage Record ของ `Enemy`
- **2026-09-15 (ต่อ 14)** — user ยืนยันว่า `BreakSideEffect::stack` เก็บจำนวนชั้นของสถานะจาก Break เช่น Wind Shear และ Entanglement · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `type`
- **2026-09-15 (ต่อ 13)** — user ยืนยันว่า `BreakSideEffect::countdown` เก็บเลขเทิร์นของศัตรูที่สถานะจะหมดอายุ เช่น `turnCnt + 2` · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `stack`
- **2026-09-15 (ต่อ 12)** — เริ่ม `Enemy.h`: user ยืนยันว่า `BreakSideEffect::ptr` คือยูนิตที่เป็นคนทำ Break · บันทึกใน [Enemy.md](Class/Unit/Enemy.md) · ถัดไป `countdown`
- **2026-09-15 (ต่อ 11)** — user ยืนยันว่า `Eidolon` เก็บระดับ E0–E6 เพื่อเปิดความสามารถตามระดับตัวละคร · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ได้คำอธิบายเจตนาของ field ที่ค้างแล้ว แต่รายละเอียดสูตรและการทำงานที่ระบุว่ายังไม่ได้ไล่ยังคงค้าง · เริ่มหัวข้อถัดไป `Enemy.h`
- **2026-09-15 (ต่อ 10)** — user อธิบายว่า `vector<Path> path` เดิมเผื่อหลาย Path ในอนาคต ตอนนี้รอเปลี่ยนกลับเป็น Path เดียว · บันทึกเจตนาใน [CharUnit.md](Class/Unit/CharUnit.md) ยังไม่ได้แก้โค้ด · `Eidolon` ยังไม่ได้อธิบาย
- **2026-09-15 (ต่อ 9)** — user อธิบาย `Adjust` เป็นค่าปรับเฉพาะตัวละคร เช่น จำนวนเป้าหมาย True DMG ของอัลติ Cipher ซึ่งกำหนดเองเพราะศัตรูใน sim ไม่ตาย · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `path`
- **2026-09-15 (ต่อ 8)** — user อธิบายว่า `Print` ใช้เปิด/ปิดการแสดงผลตอนเริ่มและจบอัลติ · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `Adjust`
- **2026-09-15 (ต่อ 7)** — user ลบ `Wait_Other_Buff` แล้ว; ตรวจ `CharUnit.h` ไม่พบ field นี้ · อัปเดตสารบัญ field ใน [CharUnit.md](Class/Unit/CharUnit.md) ให้ตรงกับหัวข้อที่อธิบายแล้ว · ถัดไป `Print`
- **2026-09-15 (ต่อ 6)** — user อธิบายว่า `Technique` บางตัวละครใช้เปิด/ปิด บางตัวใช้กำหนดจำนวนครั้ง · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md)
- **2026-09-15 (ต่อ 5)** — user ยืนยันว่าส่วน EHR (`ApplyBaseChance` / `EhrRequire` / `ExtraEhr`) ใช้งานจริงแล้ว · อัปเดต [CharUnit.md](Class/Unit/CharUnit.md)
- **2026-09-15 (ต่อ 4)** — user อธิบายว่า `ApplyBaseChance` ใช้หา EHR ที่ต้องการใน `EhrRequire` ส่วน `ExtraEhr` ใช้หลักเดิมคือเก็บส่วนที่ยังขาดสำหรับ reroll ถัดไป · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ยืนยันสถานะการใช้งานของส่วน EHR
- **2026-09-15 (ต่อ 3)** — user ยืนยันว่าคู่ requirement ของ ATK / HP / DEF ใช้หลักเดียวกับ SPD แต่ยังเป็น dead code · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป `ApplyBaseChance` / `EhrRequire` / `ExtraEhr`
- **2026-09-15 (ต่อ 2)** — user อธิบาย `SpeedRequire` เป็นเป้าหมาย SPD รวม และ `ExtraSpeed` เก็บ SPD ที่ยังขาดหลังคำนึงถึง base SPD, SPD ที่มี และบัฟ เพื่อใช้ในรอบ reroll ถัดไป · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ยืนยันคู่ requirement stats อื่น
- **2026-09-15 (ต่อ)** — user ยืนยันว่า `Body` / `Boot` / `Orb` / `Rope` กำหนด main stat แต่ละช่องและคงไว้ระหว่าง reroll substats · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ถัดไป requirement stats
- **2026-09-15** — ทัวร์ `CharUnit.h` ต่อ: user อธิบาย `summonList` (โดนตีไม่ได้ ใช้ stats เจ้าของคำนวณดาเมจ), `countdownList` (กำหนดเวลาเริ่ม/จบบัฟ) และ `memospriteList` (เอกสิทธิ์ของ Remembrance ที่อัญเชิญ memosprite ได้ เป็นยูนิตแยก โดนตีได้ มี stats ของตัวเอง) · บันทึกใน [CharUnit.md](Class/Unit/CharUnit.md) · ยังไม่ได้ไล่รายละเอียดการทำงานของแต่ละ list ครบ
- ~~รัน sim จริง~~ ✅ user รันผ่านแล้ว (2026-09-13) · push แล้ว `31c9a49..e8de52b` · ~~**Dahlia (`Combat.h`) ยังไม่ commit**~~ ✅ commit แล้ว 2026-09-16 (`e65743d`) แต่ยังไม่ได้รัน sim ยืนยันผล
- ~~E2~~ ✅ ตอบแล้ว (2026-09-13): จำนวน roll รวม user กำหนดเอง ปกติ **25** — ตัวละครทุกตัวเรียก `setTotalSubstats(25)` (ค่าเริ่มต้นใน `CharUnit.h` แก้จาก 20 เป็น 25 แล้ว) · `currentTotalSubstats` ไม่มีใครอ่าน → **ลบแล้ว**
- หัวข้อ field ที่ค้างของ `CharUnit.h` อธิบายแล้ววันที่ 2026-09-15; รายละเอียดบางส่วนยังค้างตามที่ระบุในไฟล์
- กำลังสำรวจ `Enemy.h` → จากนั้น `StatsSet.h`
- 🐞 ~~#1 · #2 · #4 · #16~~ ✅ แก้แล้ว 2026-09-13 (push แล้ว) · ~~#8~~ ปิด — user: summon/countdown ไม่ได้ใช้ `owner`
- dead code (โซนอื่น): `DecreaseHP(Unit*, vector, ...)` overload — **ปล่อยไว้** (user 2026-09-13); ข้อสรุปเดิมที่รวม `Enemy::hitCount` ถูกแก้ไขวันที่ 2026-09-16: user ยืนยันว่ามีการใช้งาน ไม่ใช่ dead code
- `future-improvements.md`: ระบบสร้างโล่ · per-unit `priority` reset · buff auto-removal helper · AllyUnit cosmetic
- ~~`docs/character-kit-reference/*.md` (~40 ไฟล์) ยัง untracked~~ ✅ เข้า git แล้ว (`f6af8b7`)
