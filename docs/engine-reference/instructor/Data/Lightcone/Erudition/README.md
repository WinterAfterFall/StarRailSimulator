# `src/Defination/Data/Lightcone/Erudition/`

10 ใบ · `namespace Erudition_Lightcone` · อ่าน `../README.md` ก่อน

| ไฟล์ | ฟังก์ชัน | `Light_cone.Name` | สแตตติดตัว | เอฟเฟกต์ |
|---|---|---|---|---|
| `The_Herta_LC.h` | `The_Herta_LC` | `The_Herta_LC` | CR `10+2S` | ใช้ Ult → Skill/Ult DMG `50+10S` 3 เทิร์น · ถ้า `Ult_cost >= 140` คืน SP 1 |
| `Anaxa_LC.h` | `Anaxa_LC` | `Anaxa_LC` | DMG `50+10S` | ต้นเทิร์น energy 10 · โจมตี → เป้าติด DEF_SHRED `9+3S` |
| `Rappa_LC.h` | `Rappa_LC` | `Rappa_LC` | BE `50+10S` | ต้นเกม energy `27.5+2.5S` · หลัง ult ใช้ BA 2 ครั้ง → advance `40+5S` |
| `Before_Dawn.h` | `Before_Dawn` | `Before_Dawn` | CD `30+6S` · Skill/Ult DMG `15+3S` | ใช้ Skill/Ult → FuA ครั้งถัดไป DMG `40+8S` |
| `Himeko_LC.h` | `Himeko_LC` | `Himeko_LC` | ATK% `(7.5+1.5S) × Total_enemy` | มีการ break → DMG `25+5S` 1 เทิร์น |
| `Calculus.h` | `Calculus` | `Calculus` | ATK% `7+S` | ATK เพิ่มตามจำนวนเป้าของ action · ถึง 24 → SPD `6+2S` |
| `The_Day_The_Cosmos_Fell.h` | `Cosmos_Fell` | `Cosmos_Fell` | ATK% `14+2S` · CD `15+5S` | — |
| `GreatCosmic.h` | `GreatCosmic` | `GreatCosmic` | ATK% `6+2S` · DMG `(3+S)×7` | — |
| `BP_Erudition.h` | `BP_Erudition` | `BP_Erudition` | DMG ตาม `Max_energy` | — |
| `Passkey.h` | `Passkey` | `Passkey` | — | ใช้ Skill ครั้งแรกของเทิร์น → energy `7+S` |

## จุดเด่นของโฟลเดอร์นี้

**1. LC หลายใบคำนวณสแตตจากสถานะของเกม ไม่ใช่ค่าคงที่**
- `Himeko_LC.h` — ATK% คูณด้วย `Total_enemy` (คำนวณใน `WhenOnField_List` ครั้งเดียว)
- `BP_Erudition.h` — DMG ขึ้นกับ `Max_energy` ของผู้สวม (มี cap ที่ 160)
- `Calculus.h` — ATK% ขึ้นกับจำนวนเป้าของแต่ละ action (คำนวณใหม่ทุก action)

**2. `Calculus.h` ใช้สำนวน "ถอนของเก่า-ตั้งค่าใหม่-ใส่ของใหม่"** เหมือน `../../Relic/Grand_Duke.md`:
```cpp
ptr->Stats_type[ATK_P][None] -= buffNote["Calculus_Atk_buff"];
buffNote["Calculus_Atk_buff"] = act->targetList.size() * 3 + superimpose;
ptr->Stats_type[ATK_P][None] += buffNote["Calculus_Atk_buff"];
```

**3. `Before_Dawn.h` เขียน `Stats_type` ตรง ๆ แทน `buffSingle`** ทั้งตอนลงและถอน เพราะต้องครอบ action เดียวพอดี

## จุดที่ควรระวังร่วมกัน

- **`Anaxa_LC.h` `When_attack_List` ไม่ guard ผู้โจมตี** → ลง DEF_SHRED ทุกครั้งที่ใครโจมตี
- **`Calculus.h` `BeforeAttackAction_List` ไม่ guard ผู้โจมตี** → ATK ของผู้สวมเปลี่ยนตามจำนวนเป้าของ action ของ **ทุกคน**
- **`Himeko_LC.h` `Toughness_break_List` ไม่ guard ว่าใคร break**
- **`Himeko_LC.h` ถอน DMG ด้วยการเขียน `Stats_type` ตรง ๆ แต่ลงด้วย `buffSingle`** — คนละกลไก
- `GreatCosmic.h` มีโค้ดคอมเมนต์ทิ้ง 2 บรรทัด
