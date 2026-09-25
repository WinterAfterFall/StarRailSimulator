# คิวงาน implement ตัวละครใหม่ (สั่งเมื่อ 2026-09-23)

> บันทึกไว้กันลืม — ยังไม่ได้ลงมือ ดูสถานะท้ายไฟล์

## ตัวละครที่สั่งให้ implement

| # | ชื่อ | ไฟล์โค้ดมีแล้วไหม | kit reference มีแล้วไหม | หมายเหตุ |
|---|---|---|---|---|
| 1 | **Rappa** | มี (`Erudition/Rappa.h`) | มี | มีอยู่แล้ว — ดู `Character/Erudition/Rappa.md` ว่ามีบั๊กอะไรค้าง |
| 2 | **Fugue** | มี (`Nihility/Fugue.h`) | มี | มีอยู่แล้ว ยังไม่ได้สำรวจ |
| 3 | **FireFly** | มี (`Destruction/FireFly.h`) | มี | มีอยู่แล้ว — ดู `Character/Destruction/FireFly.md` |
| 4 | **Huohuo** | มี (`Abundance/Huohuo.h`) | มี | มีอยู่แล้ว ยังไม่ได้สำรวจ |
| 5 | **Welt** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน |
| 6 | **Lingsha** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน |
| 7 | **Acheron** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน |
| 8 | **Seele** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน |
| 9 | **Jiaoqiu** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน |
| 10 | **Dan Heng Terrae** | **ไม่มี** | **ไม่มี** | ต้อง research ก่อน (ชื่อเต็มในเกมต้องเช็ค) |
| 11 | **Evernight** | **ไม่มี** | **ไม่มี** | ตัวใหม่ ต้อง research |
| 12 | **Ashveil** | **ไม่มี** | **ไม่มี** | ตัวใหม่ ต้อง research |
| 13 | **Robin (Summer)** | **ไม่มี** | **ไม่มี** | เวอร์ชัน alt ของ Robin ต้อง research |
| 14 | **Rin Tohsaka** | **ไม่มี** | **ไม่มี** | collab (ชุดเดียวกับ Saber) ต้อง research |
| 15 | **Gilgamesh** | **ไม่มี** | **ไม่มี** | collab ต้อง research |
| 16 | **Blade** | **ไม่มี** | **ไม่มี** | ต้อง research |
| 17 | **Mortenax Blade** | **ไม่มี** | **ไม่มี** | เวอร์ชัน rework/alt ของ Blade ต้อง research |
| 18 | **Feixiao** | **ไม่มี** | **ไม่มี** | ต้อง research |
| 19 | **Fu Xuan** | **ไม่มี** | **ไม่มี** | Preservation ต้อง research |
| 20 | **Jingliu** | **ไม่มี** | **ไม่มี** | Destruction ต้อง research |
| 21 | **Asta** | **ไม่มี** | **ไม่มี** | Harmony ต้อง research |
| 22 | **Hanya** | **ไม่มี** | **ไม่มี** | Harmony ต้อง research |
| 23 | **Sampo** | **ไม่มี** | **ไม่มี** | Nihility ต้อง research |

## งานเพิ่มเติมที่สั่งไว้

- **หาว่าเกม HSR rework ตัวไหนไปบ้าง แล้ว implement ให้หมด** — ต้อง research ว่ามีตัวไหนถูกปรับ kit แล้วเทียบกับไฟล์ที่มีอยู่ในโปรเจกต์
- **ทำ Relic / Planar / Light Cone ให้ครบทุกอันในเกม**
  - Relic (Cavern) ในเกมมี ~28 เซ็ต · ในโปรเจกต์มี **15** → ขาดอีก ~13
  - Planar ในเกมมี ~24 เซ็ต · ในโปรเจกต์มี **15** → ขาดอีก ~9
  - Light Cone ในเกมมีหลายร้อยใบ · ในโปรเจกต์มี **73 ไฟล์** → ขาดอีกจำนวนมาก
  - ตารางเซ็ตที่มีอยู่แล้วในโปรเจกต์: ดู `Relic/README.md` และ `Planar/README.md`
  - `docs/hsr-system-reference.md` 5.2 / 5.3 มีสรุปเซ็ตสำคัญไว้บางส่วน ใช้เป็นจุดเริ่มได้

> **ขนาดงานรวมของคิวนี้ใหญ่มาก** (ตัวละคร ~23 ตัว + relic/planar ~22 เซ็ต + light cone อีกหลายร้อยใบ)
> ทุกอย่างต้อง research ตัวเลขจากแหล่งข้างล่างก่อน เพราะโปรเจกต์ไม่มีข้อมูลดิบเก็บไว้
> แนะนำให้แบ่งเป็นรอบ ๆ และ build เทียบทุกรอบ ไม่ควรทำรวดเดียวแล้ว push

## แหล่งข้อมูลที่ user ระบุ

- https://www.prydwen.gg/star-rail/characters/&lt;name&gt; — แท็บ kit
- https://hsr.nanoka.cc/

## ขั้นตอนที่ต้องทำต่อตัว

1. research kit จากแหล่งข้างบน → เขียนไฟล์ `docs/character-kit-reference/<ชื่อ>.md` ตามรูปแบบเดิม (ดู `docs/character-kit-reference/README.md`)
2. เขียน `src/Defination/Data/Character/<Path>/<ชื่อ>.h` ตามแบบแผนใน `README.md` ของโฟลเดอร์นี้
3. เพิ่ม `#include` ใน `All_<Path>_char.h`
4. เขียนไฟล์ mapping `docs/engine-reference/instructor/Data/Character/<Path>/<ชื่อ>.md`
5. build + รันเทียบ

## หมายเหตุ

รายการนี้ยาวขึ้นเรื่อย ๆ ระหว่างที่ user สั่งเพิ่ม — ถ้ามีตัวไหนตกหล่นให้เทียบกับ transcript ของ session 2026-09-23

## สถานะ

**ยังไม่ได้เริ่ม** — งานสำรวจเอกสาร (`Data/` ทั้งโฟลเดอร์) ยังไม่จบ ซึ่ง user สั่งไว้ก่อน
ตัวที่ 1-4 มีโค้ดอยู่แล้ว ต้องดูก่อนว่า "implement" หมายถึงทำเพิ่มส่วนที่ขาด หรือรื้อทำใหม่
