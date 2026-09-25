# `src/Defination/Data/Character/Nihility/Black SwanV1.h`

**เวอร์ชันเก่าของ Black Swan — ไม่ใช่ตัวที่ใช้งานจริง** · ตัวจริงคือ `Black Swan.h` (ดู `Black Swan.md`)

`docs/kit-reference/Character/README.md` ระบุไว้ว่า "ข้าม V1 dupes — ดูไฟล์ตัวจริงแทน" และ `kit-reference/Character/Black Swan.md` ก็เขียนว่า "(เวอร์ชันเก่า `Black SwanV1.h` — ข้าม)"

> **แต่ยัง `#include` อยู่**: `All_Nihility_char.h:11` → `#include"Black SwanV1.h"` · ยังคอมไพล์เข้าไปในโปรแกรม (namespace ต่างกันจึงไม่ชน)

## ความต่างหลักจากเวอร์ชันปัจจุบัน

| ประเด็น | V1 (ไฟล์นี้) | ปัจจุบัน (`Black Swan.h`) |
|---|---|---|
| **ชนิด DoT ของ Arcana** | `{DotType::WindShear}` ชนิดเดียว | `{WindShear, Bleed, Burn, Shock}` ครบ 4 ชนิดตาม kit |
| **cap ของ stack** | ส่งเป็นพารามิเตอร์ `50` ให้ `dotSingleStack` ทุกครั้ง | ส่ง `1e9` (ไม่ cap ที่ระดับ helper) แล้ว clamp เองด้วย `maxArcana` หลังยิงดาเมจ |
| **จำนวน stack ที่ยัดต่อครั้ง** | `1` ต่อครั้ง เรียกซ้ำหลายรอบ | `5` ต่อครั้ง (ตรงกับ A2 ของ kit) |
| **การลด stack หลัง tick** | `setStack("Arcana", 1)` ตรง ๆ | `arcanaStacksAfterTick()` = หารครึ่งแบบคงขั้นต่ำ 1 |
| **เงื่อนไขลาม adjacent** | ต้องมี stack ≥ 3 และเป็น `DotBeforeTurn` | เป็น `DotBeforeTurn` อย่างเดียว |
| **เงื่อนไขพิเศษที่ stack ≥ 7** | มีหลายจุด (173, 197) | ไม่มี |
| **`AType` ของ action DoT** | `AType::WindShear` | `AType::Shock` |

**หลักที่เหมือนกัน**: ทั้งสองเวอร์ชันคงขั้นต่ำ 1 stack หลัง tick (V1 ตั้งเป็น 1 ตรง ๆ, ปัจจุบันหารครึ่งแต่ไม่ต่ำกว่า 1) — บันทึกไว้แล้วใน `Black Swan.md`

## ควรทำยังไงต่อ

ไฟล์นี้เป็น **โค้ดตาย** ที่ยังถูกคอมไพล์ · ถ้าไม่ได้ใช้เทียบผลอีกแล้วควรลบไฟล์และลบบรรทัด `#include` ออก เพื่อไม่ให้มีสองแหล่งความจริงของตัวละครเดียวกัน — แต่**ยังไม่ได้ถาม user** จึงยังไม่แตะ
