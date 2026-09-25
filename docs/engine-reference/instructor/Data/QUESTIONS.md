# คำถามจากการสำรวจ `src/Defination/Data/` (2026-09-23)

แยกตามหมวดตามที่ user สั่ง · แต่ละข้อระบุไฟล์+บรรทัด และบอกว่าทำไมถึงตอบเองไม่ได้

**วิธีใช้**: ตอบเป็นข้อ ๆ ได้เลย ผมจะเอาไปแก้โค้ดและอัปเดตไฟล์ md ที่เกี่ยวข้อง
ข้อที่ขึ้นต้นด้วย 🔴 คือของที่**กระทบตัวเลขผลลัพธ์แน่นอน** ควรตอบก่อน

---

# 1. Relic

### ✅ R1. `Hero_Wreath.h:24` — CD +30% trigger ผิดเงื่อนไข
> **แก้แล้ว 2026-09-25**: เช็ค `side == Memosprite` + เจ้าของตรงกัน · เพิ่ม `After_turn_List` ถอน CD (เดิมไม่มีโค้ดถอน → ค้างถาวร)

```cpp
if (act->Attacker->Atv_stats->side == Side::Ally && ptr->memospriteList.size() > 0)
```
kit บอก "เมื่อ **memosprite** โจมตี" แต่โค้ดเช็คแค่ว่าผู้โจมตีอยู่ฝ่ายเรา → **ใครในทีมตีก็ติด** รวม DoT/additional · บัฟถูกต่ออายุแทบทุก action

**ถาม**: แก้ให้ตรง kit (เช็คว่าผู้โจมตีเป็น memosprite ของเจ้าของ) หรือปล่อยแบบนี้เพราะทีมที่ใส่เซ็ตนี้มี memosprite ตีบ่อยอยู่แล้ว?

### ✅ R2. `Diviner of Distant Reach.h:12-16` — Elation ลงผิดคน
> **แก้แล้ว 2026-09-25**: แบบ (ก) — `buffSingle(each, ...)` แจกทุกคนคนละ 10 · `"DoD Buff"` กันซ้อนเมื่อมีหลายคนใส่

```cpp
for(auto &each : allyList){
    if(isHaveToAddBuff(each,"DoD Buff"))
    buffSingle(ptr,{{Stats::Elation,AType::None,10}});   // <- ptr ไม่ใช่ each
}
```
เจ้าของได้ Elation **+10 × จำนวนเพื่อน** (ทีม 4 คน = +40)

**ถาม**: เจตนาคือ (ก) แจกเพื่อนคนละ 10 → แก้เป็น `buffSingle(each, ...)` หรือ (ข) เจ้าของได้ 10 ครั้งเดียว → เอาลูปออก?

### ✅ R3. `Goddess of Sun and Thunder.h` — บัฟ CD ทีมค้างถ้าเจ้าของตาย
> **แก้แล้ว 2026-09-25**: เพิ่ม `AllyDeath_List` ถอน SPD เจ้าของ + CD ทั้งทีมเมื่อเจ้าของตาย

บัฟ CD +15% ลงทั้งทีมด้วย `buffAllAlly` แต่ถอนด้วย `isBuffEnd(ptr, ...)` ที่ผูกกับเทิร์นของ**เจ้าของ relic** และไม่มี `AllyDeath_List`

**ถาม**: เพิ่ม `AllyDeath_List` แบบ `Wavestrider Captain.h` ไหม หรือถือว่าเคสเจ้าของตายไม่เกิดในซิมนี้?

### ✅ R4. `Diviner of Distant Reach.h` — สองสาขา copy ทั้งก้อน
> **2026-09-25**: ยังไม่แก้ — บันทึกเป็นหัวข้อรวมใน `future-improvements.md` ข้อ 10 (เงื่อนไข SPD แบบ realtime) พร้อม GiantTree / FirmanentFrontline

ต่างกันแค่ CR 18 vs 10 · ยุบเป็น `double cr = trigger ? 18 : 10;` แล้วเหลือ lambda เดียวได้

**ถาม**: ให้รีแฟกเตอร์เลยไหม? (มีแบบเดียวกันที่ `Planar/GiantTree.h` และ `Planar/FirmanentFrontline.h`)

### ✅ R5. `PairSet.h` — `Relic.Name` เป็น `"PairSet"` เสมอ
> **2026-09-25 ไม่ต้องแก้**: PairSet คือ relic ยำ 2+2 — แต่ละ `PairSetType` ให้ค่า 2 ชิ้นแบบคงที่ (CD, DMG, ATK, HP, DEF ฯลฯ) ผ่าน `RelicPairSet` · ไม่มีโค้ดไหนเช็คชื่อ `"PairSet"`

ไม่บอกว่าใส่คู่ไหน → ตัวละคร/relic ที่เช็คชื่อแยกไม่ออก

**ถาม**: ต้องการให้ชื่อบอกคู่ที่ใส่ไหม (เช่น `"PairSet:ATK+CritDam"`) หรือไม่มีใครเช็คชื่อ PairSet อยู่แล้ว?

### ✅ R6. `Sacerdos_Relived_Ordeal.h:21-22` — guard ด้วย `currentCharNum` + `dynamic_cast`
> **แก้แล้ว 2026-09-25**: ลบ `if (turn->num != ptr->currentCharNum) return;` — เหลือ `dynamic_cast` กันเทิร์นที่ไม่ใช่ ally และ `isBuffEnd` เช็คเทิร์นเจ้าของบัฟเอง

`currentCharNum` เปลี่ยนได้ระหว่างเกมเมื่อมี memosprite

**ถาม**: เปลี่ยนเป็นเทียบชื่อ + `canCastToAllyUnit()` ไหม?

### ✅ R7. `Ever-Glorious Magical Girl.h` — `buffNote` ต่อเจ้าของ แต่ `buffAllAlly` ทั้งทีม
> **แก้แล้ว 2026-09-25**: เปลี่ยนเป็น `buffSingleChar(ptr, ...)` — ลงเฉพาะผู้สวม + memosprite ตรงกับ `buffNote` ที่เก็บต่อเจ้าของ

ถ้ามีสองคนใส่เซ็ตนี้ ค่าจะซ้อน

**ถาม**: เป็นเคสที่เกิดจริงไหม ถ้าไม่ก็ปล่อยได้

### R8. `Knight_of_Purity_Palace.h:8` — `Stats::SHEILD += 20` ยังไม่มีผล
ระบบโล่ยังไม่มี (`future-improvements.md` ข้อ 2)

**ถาม**: เก็บไว้รอระบบ (ตามที่บันทึกไว้) ใช่ไหม?

---

# 2. Planar

### 🔴 P1. `The_Wondrous_BananAmusement_Park.h:10-14` — เช็ค memosprite ผิดจังหวะ
```cpp
WhenOnField_List: if (ptr->summonList.size() != 0 || ptr->memospriteList.size() > 0) CD += 32;
```
เช็คครั้งเดียวตอนเข้าสนาม · **memosprite ส่วนใหญ่ถูกเรียกออกมาภายหลัง** (ผ่าน Skill) → เงื่อนไขเป็นเท็จตอนเช็คแล้วไม่ได้บัฟเลย

**ถาม**: ย้ายไป `Before_turn_List` แบบ `Relic/Hero_Wreath.h` ไหม?
> หมายเหตุ: `memospriteList` ถูกสร้างตอน `SetMemoStats` ใน `Setup` (ไม่ใช่ตอน summon) ดังนั้น `.size() > 0` อาจเป็นจริงอยู่แล้วแม้ memosprite ยังไม่ออกมา — **ต้องยืนยันว่า `.size()` หมายถึงอะไรกันแน่**

### P2. `Tengoku@Livestream.h:10-12` — รีเซ็ตตัวนับทุกต้นเทิร์นของทุก unit
```cpp
Before_turn_List: ptr->setStack("Tengoku sp count", 0);   // ไม่ guard ว่าเป็นเทิร์นใคร
```
หน้าต่างการนับ "ใช้ SP 3 แต้มในเทิร์นเดียว" จึงสั้นกว่าที่ kit ตั้งใจ (รวมเทิร์นศัตรูด้วย)

**ถาม**: ควร guard `turn->isSameName(...)` แบบ `Lightcone/Erudition/Passkey.h` ไหม?

### P3. `Arcadia.h:8-16` — `allyList` รวม memosprite หรือไม่
```cpp
for(auto &each : allyList) if(each->isExisted()) cnt++;
if(cnt > 4) buff = (cnt - 4) * 12;
```
ถ้า `allyList` รวม memosprite ทีม 4 คนที่มี memosprite 1 ตัวจะได้ `buff = 12` ซึ่งอาจไม่ใช่เจตนา

**ถาม**: `allyList` รวม memosprite ไหม? ถ้ารวม ต้องกรองออกหรือเปล่า?

### P4. เงื่อนไขที่ถูกตัดทิ้ง — ยืนยันว่าตั้งใจ
`Talia` (ไม่เช็ค SPD), `Kalpagni_Lantern` (ไม่เช็ค Fire weakness), `Rutilant`/`Inert` (ไม่เช็ค CR), `Broken_Keel` (ไม่เช็ค Effect RES), `SpaceSealing` (รวมเป็น 24)

**ถาม**: ยืนยันว่าเป็นแบบแผนเดียวกับ Pela A2 (ใส่ค่าเต็มเพราะ build เข้าเงื่อนไขอยู่แล้ว) ใช่ไหม · **`Kalpagni_Lantern` ต่างจากตัวอื่นตรงที่เงื่อนไขอยู่ที่ตัวศัตรู ไม่ใช่ build ของเรา** — อันนี้ยังโอเคไหม?

### P5. `Lushaka.h:12-13` — บัฟ `charUnit[1]` เขียน `Stats_type` ตรง ๆ
ไม่ผ่าน `buffSingle` → ไม่ยิง `StatsAdjust` · ถ้าเพื่อนช่องแรกมี trace ที่คำนวณจาก ATK แบบ live (เช่น Cerydra A2) ค่าจะไม่ตามไปด้วย

**ถาม**: เปลี่ยนเป็น `buffSingle` ไหม?

---

# 3. Light Cone

## 3.1 Harmony

### 🔴 LH1. `For_Tomorrow_Journey.h:20` — ถอนบัฟด้วยชื่อผิด
```cpp
ลง:  buffSingle(ptr, {...}, "For_Tomorrow_Journey_Buff", 1);
ถอน: if (isBuffEnd(ptr, "Himeko_LC_buff")) { ... }     // <- ชื่อของ LC อีกใบ
```
**DMG `15+3S` ค้างถาวรและซ้อนทับทุกครั้งที่กด ult** — บั๊กชนิดเดียวกับ Kafka E1 และ Luocha Field ที่แก้ไปแล้ว

**ถาม**: แก้เป็น `"For_Tomorrow_Journey_Buff"` เลยใช่ไหม? (คิดว่าใช่ แต่ขอยืนยันเพราะกระทบตัวเลข)

### LH2. `Robin_LC.h:8` — `When_attack_List` ไม่ guard ผู้โจมตี
ได้ Cantillation stack จากการโจมตีของ **ทุกคน** รวม DoT/additional

**ถาม**: kit ระบุเฉพาะเจ้าของหรือทั้งทีม?

### LH3. `Sunday_LC.h:17-19` — `AllyDeath_List` ไม่เช็ค `isBuffGoneByDeath`
ถอน stack กับทุกคนที่ตายแม้ไม่เคยมีบัฟ

**ถาม**: ใส่ guard ไหม? (อาการเดียวกับ `Character/Harmony/Sunday.h` E6)

## 3.2 Nihility

### 🔴 LN1. `Cipher_LC.h:7-10` — `BeforeAttackAction_List` ไม่ guard ผู้โจมตี
```cpp
BeforeAttackAction_List: debuffAllEnemyApply(ptr, {...}, "Bamboozle", 2);   // ไม่เช็คว่าใครตี
```
DEF_SHRED ถูกลง/ต่ออายุ **ทุกครั้งที่ใครก็ตามโจมตี** รวม DoT

**ถาม**: kit ของใบนี้ระบุเฉพาะผู้สวมหรือทั้งทีม?

### 🔴 LN2. `Hysilens_LC.h` — VUL stack ไม่มีโค้ดถอน
`debuffStackSingle` ลงโดยไม่มี duration และไม่มี `isDebuffEnd` รองรับ → ค้างถาวรจนจบการต่อสู้

**ถาม**: ตั้งใจให้ถาวรไหม หรือลืมใส่ duration?

### LN3. `Hysilens_LC.h` — โค้ด debug ค้าง
`ptr->setBuffCheck("LC Hys using",1)` ที่ไม่มีใครอ่าน + คอมเมนต์ทิ้ง 5 บรรทัด (บรรทัด guard ที่จะใช้มัน)

**ถาม**: เคยเจอปัญหา recursion ตรงนี้ไหม ถ้าไม่ ลบทิ้งได้เลยหรือเปล่า?

### LN4. `Kafka_LC.h` — ถอน Shock ด้วย `changeShock(-1)` แทน `dotRemove`
ลงด้วย `dotSingleApply` (ซึ่งเรียก `changeDotType` ข้างใน) แต่ถอนด้วย `changeShock` ตรง ๆ

**ถาม**: เปลี่ยนเป็น `dotRemove(enemy, {DotType::Shock})` ให้ตรงแบบแผนไหม?

### LN5. `ShowTime.h` / `HertaShop.h` — เช็ค `isBuffEnd(ally, ...)` แต่ถอนจาก `ptr`
ถ้า ally คนอื่นมีบัฟชื่อเดียวกันจะถอนผิดจังหวะ

**ถาม**: แก้เป็นเช็คและถอนที่ `ptr` ตรง ๆ ไหม?

### LN6. `Resolution.h` — จัดการ debuff ด้วยมือทั้งหมด
เขียน `Stats_type` / `debuffEnd` / `debuffCheck` / `Total_debuff` เอง แทน `debuffSingleApply` + `isDebuffEnd`

**ถาม**: ให้รีแฟกเตอร์ไหม? (โค้ดเก่าแบบเดียวกับ `Pela.h` ที่บันทึกไว้แล้ว)

### LN7. `GNSW.h` — `(9 + 3S) * 3` คูณ 3 ไว้ในสูตร
ไม่มีคอมเมนต์ว่าทำไม

**ถาม**: คือค่าเต็ม 3 stack ของ kit ใช่ไหม?

## 3.3 Destruction

### 🔴 LD1. `FireFly_LC.h:11` — guard ผู้โจมตีเขียนกลับด้าน
```cpp
if (act->Attacker->Atv_stats->num != ptr->Atv_stats->num && act->Attacker->Atv_stats->side != Side::Ally) return;
```
`side != Side::Ally` เป็นเท็จสำหรับ ally ทุกคน → **เงื่อนไขไม่มีวันเป็นจริงสำหรับ ally** → debuff ลงทุกครั้งที่ใครในทีมโจมตี

**ถาม**: เจตนาคือเฉพาะผู้สวม (`isSameOwnerName(ptr)`) หรือทั้งทีม?

### 🔴 LD2. `Jingliu_LC.h:11-13` — `Enemy_hit_List` ไม่เช็คว่าใครโดน
```cpp
for(AllyUnit* e : target){ buffStackSingle(ptr, {...}, 1, 3, "Jingliu_LC"); }   // e ไม่ได้ถูกใช้
```
ศัตรูตีโดน 3 คน = ผู้สวมได้ 3 stack ในครั้งเดียว แม้ไม่ได้โดนเอง · `HPDecrease_List` ก็ไม่ guard เช่นกัน

**ถาม**: แก้ให้เช็ค `e->isSameName(ptr)` แบบ `Blade_LC.h` ใช่ไหม?

### LD3. `Danheng_LC.h` — ลงด้วย `buffSingle` แต่ถอนด้วย `buffCharResetStack`
คนละกลไก — `buffSingle` engine ไม่ได้นับ stack ให้ แต่ `buffCharResetStack` ถอนตาม stack ที่ engine นับ

**ถาม**: เปลี่ยนตอนลงเป็น `buffStackSingle` หรือเปลี่ยนตอนถอนเป็น `buffSingle` ติดลบคูณ stack?

### LD4. `Mydei_LC.h:16` — เทียบ `currentHP >= 50000.0 / (5.5 + 0.5S)`
ตัวเลข 50000 ไม่ได้อิง Max HP จริงและไม่มีคอมเมนต์อธิบายที่มา

**ถาม**: kit ระบุเป็นเปอร์เซ็นต์ของ Max HP หรือค่าคงที่?

### LD5. `Secret_Vow.h` / `Secret_Vow_Nobuff.h` — `Light_cone.Name` เหมือนกัน
ทั้งสองไฟล์ตั้งเป็น `"Secret_Vow"` → ตัวละครที่เช็คชื่อแยกไม่ออกว่าใช้เวอร์ชันไหน

**ถาม**: ต้องการให้แยกชื่อไหม หรือไม่มีใครเช็คอยู่แล้ว?

### LD6. `HertaShop.h` — ATK stack ไม่มีวันถอน
`buffStackSingle` ไม่มี duration และไม่มี `After_turn_List` รองรับ

**ถาม**: kit ให้เป็นบัฟถาวรที่สะสมจนเต็มใช่ไหม?

## 3.4 Erudition

### 🔴 LE1. `Calculus.h:14-18` — `BeforeAttackAction_List` ไม่ guard ผู้โจมตี
ATK ของผู้สวมถูกเขียนทับตามจำนวนเป้าของ action ของ **ทุกคนในทีม** รวม DoT/additional

**ถาม**: แก้ให้ guard `isSameOwnerName(ptr)` ใช่ไหม?

### LE2. `Anaxa_LC.h:10-12` — `Before_turn_List` ไม่ guard เทิร์น
ได้ energy 10 **ทุกต้นเทิร์นของทุก unit รวมศัตรู**

**ถาม**: kit ระบุเฉพาะเทิร์นตัวเองใช่ไหม?

### LE3. `Anaxa_LC.h` — `When_attack_List` ไม่ guard ผู้โจมตี
ลง DEF_SHRED ทุกครั้งที่ใครโจมตี

**ถาม**: เฉพาะผู้สวมหรือทั้งทีม?

### LE4. `Himeko_LC.h` — `Toughness_break_List` ไม่ guard ว่าใคร break + ATK คำนวณครั้งเดียว
ATK% คูณ `Total_enemy` ตอนเข้าสนาม ถ้าจำนวนศัตรูเปลี่ยนค่าไม่ตาม

**ถาม**: จำนวนศัตรูเปลี่ยนระหว่างการต่อสู้ได้ไหมในซิมนี้?

### LE5. `GreatCosmic.h` — `(3+S)*7` คูณ 7 + มีโค้ดคอมเมนต์ทิ้ง
**ถาม**: คือค่าเต็ม 7 stack ใช่ไหม · โค้ดที่คอมเมนต์ไว้ตั้งใจจะทำอะไร?

## 3.5 Elation

### 🔴 LEL1. `Mushy Shroomy's Adventures.h` — `debuffAllEnemyApply` ไม่ส่ง duration
`After_turn_List` เรียก `isDebuffEnd` ที่เทียบ `debuffEnd` ซึ่งไม่เคยถูกตั้ง (default 0) → **VUL ค้างถาวรและซ้อนทับทุกครั้งที่ใช้ Elation Skill**

**ถาม**: ใส่ duration เท่าไร? (kit น่าจะระบุไว้)

### LEL2. `Hibana_LC.h` — บัฟ `"Stream Promo"` ไม่มีอายุ + DEF_SHRED stack ไม่มี duration
**ถาม**: ตั้งใจให้ถาวรใช่ไหม?

### LEL3. `Today's Good Luck.h` — Elation stack ไม่มีอายุ
**ถาม**: เหมือนกัน — ถาวรใช่ไหม?

### LEL4. `Max_sp` ถูกแก้โดย 3 ที่
`Character/Harmony/Hanabi.h`, `Character/The Hunt/Archer.h`, `Lightcone/Elation/Hibana_LC.h`

**ถาม**: ถ้าอยู่ในทีมเดียวกันจะบวกสะสม — ถูกต้องตาม kit ไหม?

## 3.6 Remembrance

### 🔴 LR1. `Hyacnine_LC.h` — ใส่ดาเมจผิด action
```cpp
shared_ptr<AllyAttackAction> addtionaldmg = make_shared<...>(AType::Addtional, ...);
act->addDamageIns(...);        // <- ใส่เข้า act ที่ยิงจบไปแล้ว
Attack(addtionaldmg);          // <- ยิง action ที่ไม่มีก้อนดาเมจ
```
**Additional DMG ของ LC ใบนี้ไม่ออกดาเมจเลย**

**ถาม**: แก้เป็น `addtionaldmg->addDamageIns(...)` ใช่ไหม?

### 🔴 LR2. `Geniuses_Greetings.h` — ลงด้วย `buffSingleChar` ถอนด้วย `buffSingle`
**บัฟบน memosprite ไม่ถูกถอน ค้างถาวร**

**ถาม**: แก้ตอนถอนเป็น `buffSingleChar` ใช่ไหม?

### LR3. `SweatNowCryLess.h:10` — `memospriteList[0]` ไม่เช็คขนาด
**crash ได้ถ้าผู้สวมไม่ใช่ path Remembrance**

**ถาม**: ใส่ guard ไหม หรือถือว่าใบนี้ใส่ได้เฉพาะ Remembrance อยู่แล้ว?

### LR4. `Hyacnine_LC.h` — `DecreaseHP(ptr, 0, 0, ...)` ส่ง `0` เป็น arg ที่ 2
arg นั้นควรเป็น `Unit*`

**ถาม**: overload นี้รับแบบนี้ได้จริงไหม?

### LR5. `Victory_In_Blink.h` — ถอนบัฟด้วยการเขียน `Stats_type` ตรง ๆ
**ถาม**: เปลี่ยนเป็น `buffSingle` ค่าติดลบไหม?

## 3.7 Abundance / Preservation / The_Hunt

### LA1. `Multiplication.h` — `Action_forward(turn, ...)` ส่ง `turn` ไม่ใช่ unit
advance ตกที่ unit ที่กำลังเล่นอยู่ ซึ่งปกติคือผู้สวม แต่ถ้ามี action ซ้อนจะไปถูกคนผิด

**ถาม**: เปลี่ยนเป็น `ptr->Atv_stats.get()` ไหม?

### LP1. `DayOne_of_MyNewLife.h` — คอมเมนต์ทิ้งทั้งไฟล์
สแตตเดียวที่ให้คือ DEF% ซึ่ง**ไม่ต้องรอระบบโล่**

**ถาม**: เขียนใหม่ตามรูปทรงปัจจุบันเลยไหม?

### LT1. `The_Hunt/` ไม่มี Light Cone เลย
**ถาม**: อยู่ในคิว implement อยู่แล้ว — มีใบไหนที่อยากได้ก่อนเป็นพิเศษไหม?

---

# 4. ตัวละคร (แยกตาม Path)

## 4.1 Harmony

### 🔴 CH1. `Robin.h:44-65` — `addUltCondition` ก้อน 2 กับ 3 ขัดกันเอง
ก้อน 2 (สาขา `AlwaysPull`): `if (driver->getATV() > dps->getATV()) return false;`
ก้อน 3 (สาขา `AlwaysPull`): `if (driver->getATV() < dps->getATV()) return false;`
→ **ถ้า atv ต่างกัน จะมีก้อนหนึ่งเป็นเท็จเสมอ → กด ult ไม่ได้เลยในโหมด `AlwaysPull`**

**ถาม**: ก้อนไหนถูก? หรือเจตนาคืออะไรกันแน่?

### 🔴 CH2. `Bronya.h:62` — `Stats_type[CR][AType::BA] = 100` ใช้ `=` ไม่ใช่ `+=`
เขียนทับค่าที่ relic/LC อาจใส่ไว้ในช่องเดียวกัน

**ถาม**: ตั้งใจเขียนทับ (เพราะ kit บอกว่า BA คริเสมอ) หรือควรเป็น `+=`?

### CH3. `Cerydra.h:183-217` — `chooseAllyBuff(crd)` สด 6 ครั้งทั้งตอนลงและถอน Peerage
ถ้าเป้าหมายเปลี่ยนระหว่างนั้น บัฟถูกถอนผิดคน

**ถาม**: ให้แก้เป็น `buffAllyTarget` แบบ `Sunday.h` หรือ `buffSubUnitTarget` แบบ `Tingyun.h` ไหม?

### CH4. `Cerydra.h:245` — สูตร A4 ใน `Stats_Adjust_List` ใช้ตัวแปรคนละตัวกับใน `Start_game_List`
`Start_game_List` ใช้ `calculateAtkForBuff(crd,100)` (ATK เต็ม) แต่ `Stats_Adjust_List` ใช้ `temp` (24% ของ ATK) → **A4 เพี้ยนทันทีที่ ATK เปลี่ยนระหว่างเกม**

**ถาม**: อันไหนถูก?

### CH5. `Cerydra.h` — copy action ทั้งก้อนเพื่อยิงซ้ำ (Coup de Main)
`make_shared<AllyAttackAction>(*act)` คัดลอก callback มาด้วย → **ผลข้างเคียงทั้งหมดของ Skill (energy, debuff, SP) เกิดซ้ำ**

**ถาม**: kit ให้ซ้ำเฉพาะดาเมจหรือทั้ง action?

### CH6. `Hanabi.h:261` — `getBuffNote("Hanabi turn note" + ...)` อ่านแต่ไม่เคยเขียน
เงื่อนไขเป็นจริงเสมอ → `Hnb sp record` ถูกล้างทุกครั้งที่ใช้ SP → **Skill ฟรีปลดได้เฉพาะเมื่อใช้ SP 3 แต้มในครั้งเดียว** ไม่ใช่สะสมในเทิร์น

**ถาม**: เจตนาคือสะสมภายในเทิร์นใช่ไหม?

### CH7. `Hanabi.h:247-249` — เพิ่ม `Total_debuff` ของศัตรูตรง ๆ ไม่ผ่าน `debuffApply`
ตัวนับนี้จะไม่มีวันถูกลด

**ถาม**: ตั้งใจให้ Cipher นับเป็น debuff ถาวรใช่ไหม?

### CH8. `Sunday.h:156-162` vs `273-278` — E1 ลง DEF_SHRED สองแบบพร้อมกันแต่ถอนแบบเดียว
ลง: `buffSingle` (16 + summon 24) **และ** `buffSingleChar` (40) · ถอน: เลือกสาขาตาม `turn->side` → **มีโอกาสถอนไม่ครบ**

**ถาม**: kit ให้ค่าไหนกับใคร?

### CH9. `Tribbie.h:103` — `DMG[AType::Fua] += 729` (E6)
ตัวเลขแปลกและไม่มีคอมเมนต์

**ถาม**: มาจากไหน?

### CH10. `Tribbie.h` — flag `Tribbie_ult_launch` ล้างเฉพาะตอน Tribbie กด ult
ถ้า Tribbie ไม่กด ult เพื่อนแต่ละคน trigger FuA ได้ครั้งเดียวตลอดเกม

**ถาม**: ตรงกับ kit ไหม?

### CH11. `Ruan_Mei.h:115-116` — `After_turn_List` push lambda ว่างเปล่า
**ถาม**: ลบทิ้งได้ไหม?

### CH12. `Harmony_MC.h:76-82` — ถอนบัฟด้วยเลขเทิร์นตายตัว (`turnCnt == 2` / `== 3`)
ไม่ได้ใช้ระบบ `isBuffEnd` · ถ้าลำดับเทิร์นเปลี่ยน (advance/delay) จะถอนผิดจังหวะ

**ถาม**: เปลี่ยนไปใช้ `isBuffEnd` ไหม?

### CH13. `Harmony_MC.h:125` — ชื่อ action ของ Skill เป็น `"RMC Skill"`
copy จาก RMC แล้วลืมเปลี่ยน → ชนกับ Skill ของ RMC ถ้ามี trigger จับชื่อ

**ถาม**: แก้เป็น `"HMC Skill"` ใช่ไหม?

### CH14. `Driver_num` ถูกเขียนโดย 3 ตัว (Bronya / Sunday / Hanabi)
ตัวที่ `Setup` ทีหลังชนะ

**ถาม**: ถ้ามีสองตัวในทีมเดียวกัน อยากให้ใครเป็น driver?

## 4.2 Nihility

### 🔴 CN1. `Hysilens.h:243` — ถอน Ult state ด้วย `atkPercent -= 15` (ควรเป็น `+=`)
ตอนลงใช้ `-= 15` ตอนถอนก็ `-= 15` อีก → **ATK ศัตรูถูกลดสะสมทุกครั้งที่ Ult state หมดอายุ**

**ถาม**: แก้เป็น `+= 15` ใช่ไหม? (คิดว่าใช่แน่ แต่ขอยืนยัน)

### 🔴 CN2. `Hysilens.h:255-274` — `Attack(Newact)` ในลูปทำให้ดาเมจทบต้น
`Newact` สะสม `addDamageIns` ไปเรื่อย ๆ แล้ว `Attack` ทุกรอบ — อาการเดียวกับ Serval Talent ที่แก้ไปแล้ว

**ถาม**: แก้แบบเดียวกับ Serval ไหม (สะสมให้ครบแล้ว `Attack` ครั้งเดียว)?

### 🔴 CN3. `Dahlia.h:128` — `isBuffEnd(ally, ...)` โดยไม่เช็ค null
`turn->canCastToAllyUnit()` คืน `nullptr` ได้ → **เสี่ยง null dereference**

**ถาม**: ใส่ `if (!ally) return;` ใช่ไหม?

### CN4. `Dahlia.h:170-172` — flag `Dahlia E1` ไม่เคยถูกล้าง
E1 ให้ toughness reduce กับศัตรูแต่ละตัวได้ครั้งเดียวตลอดเกม (ต่างจาก `Dahlia A6` ที่ล้างท้ายลูป)

**ถาม**: ตั้งใจหรือลืม?

### CN5. `Dahlia.h:179-183` — `AfterAction_List` วน `allyList` แต่ตั้ง flag ของ `ptr` เสมอ
ตัวแปรลูปไม่ได้ถูกใช้ · ตั้งค่าเดิมซ้ำ N ครั้ง

**ถาม**: เจตนาคือล้าง flag ของทุกคนใช่ไหม?

### CN6. `AType` ผิดประเภท — 3 ไฟล์ที่ยังไม่แก้
- `Guinaifen.h:46,73` — Skill และ **Ult** เป็น `AType::BA` (Ult ยังชื่อ `"Gui Skill"` ซ้ำกับ Skill)
- `Fugue.h:54` — Skill เป็น `AType::BA`
- `Dahlia.h:93` — Ult เป็น `AType::SKILL`

**ถาม**: แก้ทั้ง 3 ไฟล์เลยไหม? (แบบเดียวกับที่แก้ `Black Swan.h` / `Luka.h` ไปแล้ว — **กระทบตัวเลขเพราะบัฟที่ผูกกับ `AType` จะเข้า/ไม่เข้าต่างจากเดิม**)

### CN7. `Fugue.h:142-146` — `AllyDeath_List` ใช้ `isBuffEnd` แทน `isBuffGoneByDeath`
`isBuffEnd` เช็คว่าเป็นเทิร์นของ unit นั้นด้วย ซึ่งคนที่เพิ่งตายไม่ได้อยู่ในเทิร์นตัวเอง → **บล็อกนี้แทบไม่มีวันทำงาน**

**ถาม**: แก้เป็น `isBuffGoneByDeath` ใช่ไหม?

### CN8. `Fugue.h:160` — `Superbreak_trigger` ทุก action ของทุกคนโดยไม่มีเงื่อนไข
ต่างจาก `Harmony_MC.h` (ต้องมีบัฟ ult) และ `FireFly.h` (ต้องมี BE ถึงเกณฑ์)

**ถาม**: kit ของ Fugue ให้ Super Break ตลอดเวลาใช่ไหม?

### CN9. `Cipher.h:207` — เขียน `act->Attacker` ทับกลางลูปแล้วไม่คืนค่า
`act` เป็น action ที่เพิ่งยิงจบ ถ้ามี trigger อื่นอ่าน `Attacker` ต่อจะได้คนผิด

**ถาม**: ให้ copy action หรือเก็บค่าเดิมไว้คืนไหม?

### CN10. `Cipher.h:132-145` — Technique ไม่เช็ค `ptr->Technique`
ยิง AoE ต้นเกมเสมอ ทุกตัวละครอื่นเช็ค

**ถาม**: ใส่ `if (ptr->Technique)` ใช่ไหม?

### CN11. `Cipher.h:31` — `Adjust["Cipher Use Only BA"] = 1` ตายตัว
Cipher ไม่เคยใช้ Skill เลย → `Patron` ติดได้เฉพาะจาก Ult

**ถาม**: ตั้งใจให้เป็นค่าเริ่มต้นแล้วแก้จากข้างนอกใช่ไหม?

### CN12. `Cipher.h:98-100` — 3 บรรทัดค่า trace ถูกคอมเมนต์ทิ้ง
มีค่า trace สองชุดในไฟล์ ไม่ชัดว่าชุดไหนถูก

**ถาม**: ชุดไหนคือของจริง?

### CN13. `Guinaifen.h:129-137` — Firekiss ไม่มีโค้ดถอน
`debuffStackEnemyTargets` ลงโดยไม่มี duration → VUL +7.6/ชั้น ค้างถาวร

**ถาม**: ตั้งใจหรือลืมใส่ duration?

### CN14. `Silver Wolf.h:146` — ถอน RESPEN ธาตุด้วย `buffNote` ค่าเดียวสำหรับศัตรูทุกตัว
ถ้าแปะธาตุต่างกันให้ศัตรูคนละตัว ตอนถอนจะใช้ธาตุของตัวหลังสุดกับทุกตัว

**ถาม**: เคสศัตรูหลายตัวที่มี weakness ต่างกันเกิดจริงไหม?

### CN15. `Pela.h:74-87` — ถอน debuff ด้วยมือ + turn counter ไม่ตรงกัน 2 บล็อก
`Zone_Suppression` ใช้ `Atv_stats->turnCnt` ส่วน `Pela_Technique` ใช้ `turn->turnCnt`

**ถาม**: ให้รีแฟกเตอร์ไปใช้ `isDebuffEnd` + `canCastToEnemy` ไหม?

## 4.3 Erudition

### 🔴 CE1. `Anaxa.h:169-180` — Talent เรียก Skill ซ้ำ เสี่ยง recursion ไม่จบ
`Skill(ptr)` ข้างในสร้าง action ชื่อ `"Anaxa Skill"` ซึ่งเมื่อจบก็เข้า `AfterAttackActionList` ตัวเดิมอีก · ตัวหยุดมีทางเดียวคือธาตุครบ 5 · **ถ้าแปะธาตุไม่ถึง 5 จะวนไม่จบ**

**ถาม**: ใส่ตัวนับรอบสูงสุดแบบ `Archer.h` ไหม?

### CE2. `Anaxa.h:245-253` — `while(1)` ใน Skill ถ้า `targetList` ว่างจะวนไม่จบ
**ถาม**: ใส่ guard ไหม?

### ~~CE3. `Anaxa.h:97` — A4 เช็ค `path[0]` ช่องแรกช่องเดียว~~
✅ **ปิด** (2026-09-25): `path` เปลี่ยนจาก `vector<Path>` เป็น `Path` ค่าเดียวแล้ว — ปัญหาหายไป

### CE4. `Anaxa.h:42-47` — `addUltCondition` ถูกคอมเมนต์ทิ้งทั้งก้อน
**ถาม**: ตั้งใจเอาออกหรือลืมเปิดคืน?

### 🔴 CE5. `Jade.h:163` — `while (stack > 8)` ใช้ `>` ไม่ใช่ `>=`
ต้องมี **9** แต้มถึงยิง FuA ครั้งแรก และเหลือค้าง 1 แต้มทุกครั้ง

**ถาม**: kit บอก "ครบ 8" → แก้เป็น `>= 8` ใช่ไหม?

### CE6. `Jade.h:96` — ถอน SPD ด้วย `chooseAllyBuff(ptr)` สด → ถอนผิดคนถ้าเป้าเปลี่ยน
**ถาม**: แก้เป็น `buffSubUnitTarget` แบบ Tingyun ไหม?

### CE7. `Jade.h:176,212` — `Fua` และ `Fua_Enchance` ชื่อ action เหมือนกัน (`"Jade Fua"`)
**ถาม**: แยกชื่อไหม?

### CE8. `Jingyuan.h:207-212` — `Temp_Turn_Condition` / `Temp_ult_Condition` คืนค่าคงที่ ไม่มีใครเรียก
**ถาม**: ลบทิ้งได้ไหม?

### CE9. `Jingyuan.h` — ไม่มี `addUltCondition` ทั้งที่จังหวะ ult สัมพันธ์กับ stack ของ LL
**ถาม**: อยากให้มีเงื่อนไขไหม?

### CE10. `Serval.h:89-91` — E6 ไม่ผูกเงื่อนไข Shocked
**user ยืนยันแล้วว่าจงใจ** — บันทึกไว้เพื่อความครบถ้วน

### CE11. `Serval.h` — A2 และ Technique ยังไม่มี
A2 หายได้เพราะระบบความน่าจะเป็นถูกตัดทิ้ง แต่ **Technique เป็นดาเมจ + Shock ต้นเกมที่หายจริง**

**ถาม**: ทำ Technique เพิ่มไหม?

### CE12. `The_Herta.h:140-145` — `AfterAttackActionList` ไม่ guard ผู้โจมตี
รวม additional/DoT ทุกก้อน → stack และ energy น่าจะสูงกว่าจริง

**ถาม**: ควรกรองเฉพาะ BA/Skill/Ult/FuA ไหม?

### 🔴 CE13. `Rappa.h:173` — บรรทัดที่ไม่ทำอะไรเลย
```cpp
target->debuffNote["Withered_Leaf"] = target->debuffNote["Withered_Leaf"];
```
น่าจะตั้งใจเขียน `= temp;` → **`debuffNote` ค้างที่ 0 ตลอด → Withered Leaf สะสมไม่มีวันถูกถอน**

**ถาม**: แก้เป็น `= temp;` ใช่ไหม?

### CE14. `Rappa.h:128-132` — `data_2` ถูกสร้างแล้วไม่ได้ใช้
`Cal_Break_damage(act, ...)` ส่ง `act` ไม่ใช่ `data_2`

**ถาม**: ตั้งใจใช้ `act` ใช่ไหม?

## 4.4 Destruction

### 🔴 CD1. `Saber.h:83` — `370/150*100` หารจำนวนเต็ม ได้ `200` ไม่ใช่ `246.67`
→ **ศัตรู 1 ตัวกับ 2 ตัวได้ multiplier เท่ากันพอดี**

**ถาม**: แก้เป็น `370.0/150*100` ใช่ไหม?

### 🔴 CD2. `Phainon.h:109` — `10/3` หารจำนวนเต็ม ได้ `3` ไม่ใช่ `3.33`
**ถาม**: แก้เป็น `10.0/3` ใช่ไหม?

### CD3. `Saber.h:241-244` — `WhenUseUlt_List` ไม่ guard ว่าใครกด ult
Saber ได้ DMG +60% และ Core Resonance +3 ทุกครั้งที่ใครกด ult รวมตัวเอง

**ถาม**: kit ระบุเฉพาะเพื่อนหรือรวมตัวเอง?

### CD4. `Saber.h` — E4 บวก Wind RESPEN สองทาง (`Reset_List` +8 ถาวร + `buffStackSingle` +4×3 ตอน ult)
**ถาม**: ซ้อนกันถูกไหม?

### CD5. `Mydei.h:202-209` — `Basic_Atk` ยังไม่ implement (`//none complete`)
`Turn_func` ไม่เคยเรียกจึงยังไม่เห็นอาการ

**ถาม**: ต้องทำไหม?

### CD6. `Mydei.h` — `FLAT_DEF -= 10000` ไม่มีโค้ดคืน
**ถาม**: ยืนยันว่าไม่มีทางออกจาก Vendetta ใช่ไหม?

### CD7. `Phainon.h:460-465` — `if(ty)` capture `rm` แทน `ty` (copy-paste)
ไม่พังเพราะตัวแปรไม่ได้ถูกใช้

**ถาม**: แก้ให้ถูกไหม?

### CD8. `Phainon.h:371-375` — Talent เช็คชื่อ action ของตัวละครอื่น (`"TY Ult"`, `"SD Ult"`, `"Crd Skill"`)
**`Luka.h` เพิ่งเปลี่ยนชื่อ ult เป็น `"Luka Ult"` ซึ่งเป็นความเสี่ยงประเภทเดียวกัน**

**ถาม**: มีวิธีที่ไม่ผูกกับชื่อ action ไหม?

### CD9. `Phainon.h:392-396` — A4 ไม่เช็คว่าใครฮีล + ฮีล 20% Max HP ทุก action ในสถานะอัลติโดยไม่มี cap
**ถาม**: ตรงกับ kit ไหม?

### 🔴 CD10. `FireFly.h:70` — Module Y ไม่มีวันทำงาน
```cpp
if (ptr->buffNote["FireFly_ModuleY"] <= 0) temp = 0;   // เช็คค่าเดิม ไม่ใช่ temp
```
ครั้งแรก `buffNote` = 0 → `temp` ถูกบังคับเป็น 0 → `buffNote` ยังเป็น 0 ตลอดไป

**ถาม**: แก้เป็น `if (temp <= 0) temp = 0;` ใช่ไหม?

### 🔴 CD11. `FireFly.h:51-62` — Ult ไม่ผ่าน action bar
ไม่มี `addToActionBar()` / `Deal_damage()` → **ไม่ยิง `WhenUseUlt_List` ของใครเลย** กระทบ `Relic/Scholar.h`, `Relic/Eagle_Beaked_Helmet.h`, Talent ของ `Saber.h` และ LC หลายใบ

**ถาม**: ตั้งใจเพราะ ult ไม่มีดาเมจ หรือควรสร้าง `AllyBuffAction`?

### CD12. `FireFly.h:114-117` — E2 ไม่ guard ผู้โจมตี
ได้ advance 100% ทุกครั้งที่ใครโจมตี ตราบใดที่ stack เหลือ

**ถาม**: เฉพาะ FireFly ใช่ไหม?

## 4.5 Remembrance

### CR1. `RMC.h:133-135` — `Before_turn_List` ตั้ง `RMC_E2` = 1 ทุกต้นเทิร์นของทุก unit
โควตา E2 รีเซ็ตถี่กว่าที่ kit ตั้งใจ

**ถาม**: guard `turn->isSameName("RMC")` ไหม?

### CR2. `RMC.h:181-190` — charge ที่ควรสะสมระหว่าง Mem ตายหายไปทั้งหมด
**ถาม**: ตรงกับ kit ไหม (charge หยุดสะสมตอน Mem ตาย)?

### CR3. `RMC.h:185` — charge ล้นถูกตัดทิ้ง (ครบ 100 ตั้งเป็น 0 ตรง ๆ)
**ถาม**: kit เก็บส่วนเกินไหม?

### CR4. `Aglaea.h:29` — `setSpeedRequire` ถูกคอมเมนต์ทิ้ง ทั้งที่ A2 และ Talent สเกลกับ SPD
**ถาม**: ควรตั้งเท่าไร?

### CR5. `Aglaea.h:124` — Additional DMG guard ด้วย `Atv_stats->num`
ถ้า memosprite ใช้เลขช่องเดียวกับเจ้าของ จะยิงตอน Garmentmaker โจมตีด้วย

**ถาม**: ตรงกับ kit ไหม?

### CR6. `Castorice.h:181` — เขียน global `turn` โดยตรงใน `Start_game_List`
เป็นการแตะตัวแปรลำดับเทิร์นของ engine จากไฟล์ตัวละคร

**ถาม**: จำเป็นจริงไหม?

### CR7. `Castorice.h:52` — `while (currentHP > 8500)` ไม่มีตัวกันวนไม่จบ
**ถาม**: ใส่ตัวนับรอบสูงสุดกันไว้ไหม?

### CR8. `Castorice.h:388` — เทียบ `currentHP == 34000` ด้วย `==` กับ `double`
**ถาม**: เปลี่ยนเป็น `>=` ไหม?

### CR9. 🔴 `Hyacine.h:216` — เงื่อนไขที่เป็นเท็จเสมอ
```
if(StatsType!=Stats::SPD_P||StatsType!=Stats::FLAT_SPD)return;
```
ใช้ `||` แทน `&&` → `return` เสมอ → **A6 ไม่เคยถูกคำนวณใหม่เมื่อ SPD เปลี่ยนระหว่างเกม**

**ถาม**: แก้เป็น `&&` ใช่ไหม?

### CR10. `Hyacine.h:90` — `Reset_List` ใส่ `CR += 100` (ไม่อยู่ใน minor traces) · มีแบบเดียวกันที่ `Cerydra.h:102`
**ถาม**: ตั้งใจบังคับให้คริเสมอใช่ไหม?

### CR11. `Hyacine.h:254-256` — E2 ไม่ guard ว่าใครเสีย HP (ลงให้ Little Ica เองด้วย)
**ถาม**: ตรงกับ kit ไหม?

### CR12. `Hyacine.h:321` — `resetATV(-1)` ค่าพิเศษ
**ถาม**: `-1` หมายถึงอะไร?

## 4.6 Abundance

### CA1. `Luocha.h` — ที่เหลือจากการแก้รอบนี้
A2 (ลบ debuff), A6 (+70% CC res) ยังไม่มี · E4 รอระบบ (`future-improvements.md` ข้อ 9) · E2 สาขา shield รอระบบโล่ (ข้อ 2)

**ถาม**: A2/A6 ทำเพิ่มไหม?

### CA2. 🔴 `Gallagher.h:183-185` — `debuffApply` ไม่เช็คค่าคืน → `atkPercent` รั่ว
ถ้า Nectar Blitz ลงซ้ำขณะ debuff เดิมยังไม่หมด ATK ศัตรูถูกลบหลายรอบแต่คืนครั้งเดียว

**ถาม**: แก้เป็น `if (debuffApply(...)) { atkPercent -= 16; }` ใช่ไหม?

### CA3. `Gallagher.h:30` — `Turn_func` กด Skill ทุก 8 เทิร์นตายตัว
**ถาม**: เลข 8 มาจากการจูนแล้ว หรืออยากให้อิง `sp`/`Sp_Safety`?

### CA4. `Gallagher.h:200` — lambda รับ action by-value (ทุกไฟล์อื่นใช้ `&`)
**ถาม**: แก้ไหม?

### CA5. `Huohuo.h:95-101` — return ถ้า `ally` null ก่อนเช็ค Divine Provision
→ **ถ้าเป็นเทิร์นศัตรู Divine Provision จะไม่ถูกตรวจหมดอายุ**

**ถาม**: ย้าย `isBuffEnd` ขึ้นก่อน `return` ใช่ไหม?

### CA6. `Huohuo.h` — โค้ด Divine Provision copy 2 ที่
**ถาม**: แยกเป็น lambda กลางไหม?

## 4.7 Elation

### CEL1. `Hibana.h:129` / `YaoGuang.h:111` — `ElationSkill_List` ใช้ตัวเลข priority ดิบ (`144` / `114`)
**ถาม**: ควรตั้งเป็นค่าคงที่ `PRIORITY_*` ใหม่ไหม?

### CEL2. 🔴 `YaoGuang.h:222` — `act->source = ptr` ใส่ผิดตัว
ตั้งให้ `act` (action ของเพื่อน) แทน `newAct` (ดาเมจแถม) → **ดาเมจของเพื่อนถูกคำนวณด้วย stat ของ Yao Guang** — กลับด้านกับเจตนา

**ถาม**: แก้เป็น `newAct->source = ptr;` ใช่ไหม?

### CEL3. `YaoGuang.h:235` — A2 ลงเฉพาะ `AType::None` ไม่มีคู่ `TEMP`
Skill ของ Yao Guang เองอ่าน `calculateElationForBuff(ptr, 20)` → **A2 ป้อนกลับเข้า Skill ได้**

**ถาม**: ใส่คู่ `TEMP` แบบ `RMC.h` ใช่ไหม?

### CEL4. `Hibana.h:155` — `Reset_List` บวก `Stats::Elation` สองครั้ง (28 + 80)
**ถาม**: ก้อน 80 มาจาก trace ไหน?

### CEL5. `Hibana.h:44-60` — `while(sp)` ไม่มีตัวกันวนไม่จบ
**ถาม**: ใส่ตัวนับรอบสูงสุดไหม?

### CEL6. `Hibana.h:92` — `printUltStart` เรียกนอก callback (ต่างจากทุกตัว)
**ถาม**: ย้ายเข้า callback ไหม?

## 4.8 The Hunt

### CT1. `Archer.h:179-184` — A6 ไม่เช็คว่าใครทำให้ SP เปลี่ยน
ลงบัฟ CD +120 ทุกครั้งที่ `sp >= 4` · บัฟถูกต่ออายุตลอดเวลาที่ SP ยังสูง

**ถาม**: ตรงกับ kit ไหม?

### CT2. `Archer.h:89` — เกณฑ์ `sp >= 6` สูงกว่าเพดาน SP มาตรฐาน (5)
Archer กด Skill ได้เฉพาะตอน SP เกือบเต็ม

**ถาม**: `Adjust["Archer Minimum"] = 3` ตั้งใจให้เป็นค่านี้ใช่ไหม?

## 4.9 Preservation

### CP1. `Aventurine.h` — คอมเมนต์ทิ้งทั้งไฟล์ (257 บรรทัด, API รุ่นเก่า)
**ถาม**: ยืนยันว่ารอระบบโล่ก่อนใช่ไหม? และเมื่อทำแล้วจะ**เขียนใหม่** (ไม่ใช่แก้โค้ดเก่าทีละบรรทัด) ใช่ไหม?

---

# 5. คำถามข้ามหมวด

### X1. 🔴 `Enemy_Death_List` — นิยาม "ศัตรูตาย"
`allEventWhenEnemyDeath()` มีแต่ไม่มีผู้เรียก และ **ศัตรูไม่มี HP เลย** (ดู `README.md`)

ติดค้าง 6 ความสามารถ: Tingyun E2, Pela E1, Kafka A4, Serval A6, The Herta (stack ย้าย), Jade Talent

**ถาม**: อยากนิยามการตายยังไง? (เพิ่ม HP ให้ศัตรู / ใช้เกณฑ์ดาเมจสะสม / อย่างอื่น)

### X2. ไฟล์ V1 ที่ยังคอมไพล์อยู่
`Black SwanV1.h` และ `HanabiV1.h` ยังถูก `#include` — เป็นแหล่งความจริงที่สอง (เคยต้องแก้ซ้ำสองที่ตอน 2026-09-13)

**ถาม**: ลบทิ้งได้ไหม?

### X3. `Reset_List` ที่มีค่าลอย ๆ ไม่มีคอมเมนต์
`Saber.h` (CR +20), `Hibana.h` (Elation +80), `Silver Wolf.h` (ATK +50), `Anaxa.h` (DMG +30), `Guinaifen.h` (DMG +20), `Tribbie.h` (Fua DMG +729), `Hyacine.h` (CR +100), `Cerydra.h` (CR +100), `Huohuo.h` (Healing Out +40), `Fugue.h` (BE 24+30)

**ถาม**: มาจาก relic/substats ที่สมมติไว้ หรือจาก trace ที่ยังไม่ได้แยก? ควรย้ายไปที่เดียวกันทั้งโปรเจกต์ไหม?

### X4. guard ผู้กระทำใน trigger — มาตรฐานที่ควรใช้
มี 4 สำนวน: เทียบชื่อ / เทียบเลขช่อง / `isSameName` / `isSameOwnerName`

**ถาม**: อยากให้ใช้ตัวไหนเป็นมาตรฐาน? (ผมเดาว่า `isSameOwnerName` เพราะครอบ memosprite)

### X5. `dynamic_cast<AllyUnit*>(turn->charptr)` vs `turn->canCastToAllyUnit()`
มีทั้งสองแบบ · แบบแรกเป็นโค้ดเก่า

**ถาม**: ให้รีแฟกเตอร์ทั้งหมดไปใช้ helper ไหม?

### X6. บัฟที่ลงถึง memosprite แต่ถอนไม่ถึง
`Lightcone/Remembrance/Geniuses_Greetings.h` (ลง `buffSingleChar` ถอน `buffSingle`) และ `Lightcone/Destruction/Danheng_LC.h` (ลง `buffSingle` ถอน `buffCharResetStack`)

**ถาม**: มีกฎง่าย ๆ ไหมว่าอะไรควรใช้ตระกูล `...Char`?

---

*สร้างจากการสำรวจ 159 ไฟล์ใน `src/Defination/Data/` เมื่อ 2026-09-23 · รายละเอียดของแต่ละข้ออยู่ในไฟล์ md ของตัวนั้น ๆ หัวข้อ "จุดที่ควรระวัง"*
