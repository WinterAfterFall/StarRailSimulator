# `src/Defination/Data/Relic/Wavestrider Captain.h`

เซ็ตจริง: **Wavestrider Captain** · `Relic.Name` = `"Captain"` (ชื่อย่อ)

| โบนัส | โค้ด | บรรทัด |
|---|---|---|
| 2-pc — CD +16% | `Reset_List` → `Stats_type[Stats::CD][AType::None] += 16` | 8 |
| 4-pc — นับจำนวนครั้งที่ถูกบัฟ (สูงสุด 2) | `Buff_List` → `calStack(each, 1, 2, help)` | 20-26 |
| 4-pc — กดอัลติตอนครบ 2 → ATK +48% 1 เทิร์น แล้วล้าง stack | `WhenUseUlt_List` | 11-18 |
| — ถอนเมื่อหมดอายุ / เมื่อตาย | `After_turn_List` + `AllyDeath_List` | 28-39 |

## รากฐาน: ถอนบัฟให้ครบ **ทุกทาง** ที่บัฟหายได้

เซ็ตนี้เป็นตัวอย่างที่ทำครบ 2 ทาง:

```cpp
After_turn_List: if (isBuffEnd(ptr, help))              buffSingle(ptr, {{ATK_P, -48}});
AllyDeath_List : if (isBuffGoneByDeath(target, help))   buffSingle(ptr, {{ATK_P, -48}});
```

`isBuffEnd` ไม่ยิงให้ unit ที่ไม่มีเทิร์น (เช่นคนที่ตายไปแล้ว) จึงต้องมี `AllyDeath_List` คู่เสมอ — หลักเดียวกับ `../Character/Harmony/Tingyun.md`

## รากฐาน: `calStack` — ตัวนับล้วนที่ไม่ผูกกับ stat

`calStack(เป้า, เพิ่ม, cap, ชื่อ)` เพิ่มตัวนับพร้อม clamp โดย**ไม่แตะ stat ใด ๆ** ต่างจาก `buffStackSingle` ที่ทั้งนับและลงค่า · ใช้เมื่อ stack เป็นเพียงเงื่อนไขปลดผล ไม่ใช่ตัวคูณของผลนั้น

## จุดที่ควรรู้

- ชื่อ stack/บัฟ ผูกกับเจ้าของ: `string help = ptr->getName() + " help";` (5) — เหตุผลเดียวกับ `Sacerdos_Relived_Ordeal.md`
- `Buff_List` ข้าม action ที่ผู้สวมเป็นคนทำเอง (`act->isSameName(ptr)`) แล้วนับเมื่อ **เป้าหมาย** เป็นผู้สวม — ตรงกับ kit "target of **another** ally's ability"
- **stack ถูกล้างเฉพาะตอนได้ใช้งาน** (`setStack(help, 0)` บรรทัด 14) ถ้ากดอัลติตอน stack ยังไม่ถึง 2 จะไม่เกิดอะไรและ stack คงอยู่ต่อ

## แก้เมื่อ 2026-09-26
- `Buff_List` เดิมไม่กรองผู้กระทำ → ผู้สวมบัฟตัวเองก็ได้ "Help" · เพิ่ม `if(act->isSameName(ptr))return;`
