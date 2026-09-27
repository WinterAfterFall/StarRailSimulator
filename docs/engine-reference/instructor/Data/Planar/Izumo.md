# `src/Defination/Data/Planar/Izumo.h`

`Planar.Name` = `"Izumo"` · เซ็ตจริง: **Izumo Gensei and Takama Divine Realm**

## ความสามารถหลัก → โค้ดที่ทำงาน

| ความสามารถ | ทำงานยังไง | ไฟล์:บรรทัด |
|---|---|---|
| ATK +12% | บวก ATK% ถาวร | `Izumo.h:7` |
| CR +12% ถ้ามีเพื่อน path เดียวกันอย่างน้อย 1 คน | ตอนเข้าสนามวน `charUnit[1..Total_ally]` ข้ามตัวเอง (เทียบชื่อ) เจอ path ตรงคนแรกก็บวกแล้ว `return` — **เช็คเงื่อนไขจริง** | `:10-18` |

## รากฐาน: เงื่อนไข "มีเพื่อน path เดียวกัน"

```cpp
for (int i = 1; i <= Total_ally; i++) {
    if (ptr->Atv_stats->Name == charUnit[i]->Atv_stats->Name) continue;   // ข้ามตัวเอง
    if (charUnit[i]->path == ptr->path) { ptr->Stats_type[Stats::CR][AType::None] += 12; return; }
}
```

- `path` เป็นค่าเดียว (`Path`) — เทียบ `==` ตรง ๆ
- `return` ทันทีที่เจอคู่แรก — กันการบวกซ้ำถ้ามีเพื่อน path เดียวกันหลายคน
- ข้ามตัวเองด้วยการ**เทียบชื่อ** ไม่ใช่เทียบ pointer

เป็น 1 ใน 4 เซ็ตของโฟลเดอร์นี้ที่ยังเช็คเงื่อนไขจริง
