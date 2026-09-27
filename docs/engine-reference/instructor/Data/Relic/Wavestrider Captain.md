# `src/Defination/Data/Relic/Wavestrider Captain.h`

เซ็ตจริง: **Wavestrider Captain** · `Relic.name` = `"Captain"` (ชื่อย่อ)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| 2-pc — CD +16% | บวก CD ถาวร | `Wavestrider Captain.h:8` |
| 4-pc — ถูกเพื่อนบัฟ → ได้ "Help" 1 ชั้น (สูงสุด 2) | `buffList` ข้าม action ของผู้สวมเอง · ถ้าผู้สวมอยู่ใน `buffTargetList` นับ `calStack(…, 1, 2, help)` | `:20-27` |
| 4-pc — กด Ult ตอนมี Help 2 ชั้น → ATK +48% 1 เทิร์น แล้วล้าง Help | `whenUseUltList` เฉพาะผู้สวม · stack ≥ 2 → ตั้ง 0 และ `buffSingle` ATK 48 ชื่อ `help` อายุ 1 | `:11-18` |
| — ถอน ATK เมื่อหมดอายุ | ท้ายเทิร์นผู้สวม `isBuffEnd` | `:29-33` |
| — ถอน ATK เมื่อตาย | `allyDeathList` + `isBuffGoneByDeath` | `:36-40` |

## รากฐาน: ถอนบัฟให้ครบ **ทุกทาง** ที่บัฟหายได้

เซ็ตนี้เป็นตัวอย่างที่ทำครบ 2 ทาง:

```cpp
afterTurnList: if (isBuffEnd(ptr, help))              buffSingle(ptr, {{ATK_P, -48}});
allyDeathList : if (isBuffGoneByDeath(target, help))   buffSingle(ptr, {{ATK_P, -48}});
```

`isBuffEnd` ไม่ยิงให้ unit ที่ไม่มีเทิร์น (เช่นคนที่ตายไปแล้ว) จึงต้องมี `allyDeathList` คู่เสมอ — หลักเดียวกับ `../Character/Harmony/Tingyun.md`

## รากฐาน: `calStack` — ตัวนับล้วนที่ไม่ผูกกับ stat

`calStack(เป้า, เพิ่ม, cap, ชื่อ)` เพิ่มตัวนับพร้อม clamp โดย**ไม่แตะ stat ใด ๆ** ต่างจาก `buffStackSingle` ที่ทั้งนับและลงค่า · ใช้เมื่อ stack เป็นเพียงเงื่อนไขปลดผล ไม่ใช่ตัวคูณของผลนั้น

## จุดที่ควรรู้

- ชื่อ stack/บัฟ ผูกกับเจ้าของ: `string help = ptr->getName() + " help";` (`:5`) — เหตุผลเดียวกับ `Sacerdos_Relived_Ordeal.md`
- `buffList` ข้าม action ที่ผู้สวมเป็นคนทำเอง (`act->isSameName(ptr)`) แล้วนับเมื่อ **เป้าหมาย** เป็นผู้สวม — ตรงกับ kit "target of **another** ally's ability"
- **stack ถูกล้างเฉพาะตอนได้ใช้งาน** (`setStack(help, 0)` `:14`) ถ้ากดอัลติตอน stack ยังไม่ถึง 2 จะไม่เกิดอะไรและ stack คงอยู่ต่อ

## แก้เมื่อ 2026-09-26
- `buffList` เดิมไม่กรองผู้กระทำ → ผู้สวมบัฟตัวเองก็ได้ "Help" · เพิ่ม `if(act->isSameName(ptr))return;`
