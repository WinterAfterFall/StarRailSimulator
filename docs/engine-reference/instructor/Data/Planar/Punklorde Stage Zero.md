# `src/Defination/Data/Planar/Punklorde Stage Zero.h`

`Planar.name` = `"Punklorde Stage Zero"` · ฟังก์ชัน `Planar::PunklordeStageZero` · **เซ็ตสาย Elation** · kit: `docs/kit-reference/Planar.md` (nanoka 4.5.54 set 325)

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| Elation +8% | บวกถาวรใน `resetList` | `Punklorde Stage Zero.h:19` |
| Elation ถึง 40% / 80% ครั้งแรกในการต่อสู้ → CD +20% / +32% | ฟังก์ชัน `check` อ่าน `calculateElationOnStats` → ขั้นที่ควรได้ (0 / 20 / 32) · ลงเฉพาะส่วนต่างจากที่เคยได้ (`buffNote "Punklorde CD"`) · ขั้นลดลงไม่ได้ | `:9-16` |
| จุดที่เรียก `check` | ตอนเข้าสนาม (`PRIORITY_LAST` ให้บัฟอื่นลงก่อน) · ต้นเกม · ทุกครั้งที่ Elation ของผู้สวมเปลี่ยน (`statsAdjustList`) | `:24-34` |

## จุดที่ควรระวัง

- **ขั้น 80% ได้ CD รวม 32% ไม่ใช่ 20 + 32** — ตีความว่า "20%/32%" เป็นขั้นที่แทนกัน ถ้าจริง ๆ ต้องบวกกัน แก้บรรทัด 11 เป็น `32 + 20`
- ได้แล้วไม่หาย แม้ Elation จะลดต่ำกว่าเกณฑ์ภายหลัง (kit: "for the first time in combat")
- ค่า Elation ที่ใช้เทียบคือ Elation รวมบนตัว (`statsType[ELATION][NONE]`) ซึ่งรวมบัฟชั่วคราวด้วย → ถ้าบัฟชั่วคราวดันให้ถึงเกณฑ์ ก็ได้ CD ถาวร (ตรงตามข้อความ "reaches ... for the first time")
- ค่าที่บวกตรง ๆ ใน `resetList` ของไฟล์อื่นไม่ยิง `statsAdjust` จึงต้องเช็คซ้ำตอนเข้าสนามและต้นเกม
