# `src/Defination/Data/Lightcone/Erudition/Anaxa_LC.h`

`namespace Erudition_Lightcone` · `Light_cone.Name` = `"Anaxa_LC"` · base stats `SetAllyBaseStats(953, 582, 529)`

**signature ของ Anaxa** (ดู `../../Character/Erudition/Anaxa.md`)

| ท่อน | โค้ด |
|---|---|
| DMG `50 + 10S` | `Reset_List` |
| ต้นเทิร์น → energy 10 | `Before_turn_List` |
| โจมตี → เป้าติด DEF_SHRED `9 + 3S` 2 เทิร์น | `When_attack_List` |
| ถอน | `After_turn_List` → `isDebuffEnd` |

## จุดที่ควรระวัง

- **`Before_turn_List` ไม่ guard ว่าเป็นเทิร์นของใคร** → ได้ energy 10 **ทุกต้นเทิร์นของทุก unit รวมศัตรู** · ถ้า kit ระบุเฉพาะเทิร์นตัวเอง ควรเช็ค `turn->isSameName(ptr->Atv_stats->Name)`
- **`When_attack_List` ไม่ guard ผู้โจมตี** → ลง DEF_SHRED ทุกครั้งที่ใครในทีมโจมตี
- **ชื่อ debuff ไม่ prefix ด้วยชื่อเจ้าของ**
