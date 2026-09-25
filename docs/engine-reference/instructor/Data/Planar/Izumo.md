# `src/Defination/Data/Planar/Izumo.h`

`Planar.Name` = `"Izumo"` · เซ็ตจริง: **Izumo Gensei and Takama Divine Realm**

| ท่อน | โค้ด | บรรทัด |
|---|---|---|
| ATK +12% | `Reset_List` | 7 |
| CR +12% ถ้ามีเพื่อนอย่างน้อย 1 คน path เดียวกัน | `WhenOnField_List` — **เช็คเงื่อนไขจริง** | 10-22 |

## รากฐาน: เงื่อนไข "มีเพื่อน path เดียวกัน"

```cpp
for (int i = 1; i <= Total_ally; i++) {
    if (ptr->Atv_stats->Name == charUnit[i]->Atv_stats->Name) continue;   // ข้ามตัวเอง
    for (auto e1 : charUnit[i]->path)
        for (auto e2 : ptr->path)
            if (e2 == e1) { ptr->Stats_type[Stats::CR][AType::None] += 12; return; }
}
```

- **`path` เป็น `vector` ไม่ใช่ค่าเดียว** — ตัวละครมีได้หลาย path (เช่น memosprite ที่นับสอง path) จึงต้องวนซ้อนสองชั้น · `The_Herta.h` ก็ใช้วิธีเดียวกันตอนนับ Erudition ในทีม
- `return` ทันทีที่เจอคู่แรก — กันการบวกซ้ำถ้ามีเพื่อน path เดียวกันหลายคน
- ข้ามตัวเองด้วยการ**เทียบชื่อ** ไม่ใช่เทียบ pointer

เป็น 1 ใน 4 เซ็ตของโฟลเดอร์นี้ที่ยังเช็คเงื่อนไขจริง
