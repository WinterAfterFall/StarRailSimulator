# `src/Defination/Function/Setup/SetRelic.h`

`transString()` แปลงชื่อ pair-set แบบไม่สนตัวพิมพ์ใหญ่เล็กเป็น `PairSetType` รองรับชื่อเต็มบางค่าและตัวย่อ เช่น `speed`/`spd`, `crit rate`/`cr`, `crit dam`/`cd`; ค่าไม่รู้จักคืน `ERROR`

`CharUnit::RelicPairSet()` คืน callback ที่เพิ่มค่าสองชิ้นตามชนิด: SPD 6%, ATK/HP 12%, DEF 15%, CR 8%, CD/BE 16%, Healing 10%, FuA DMG 20% หรือ DMG ธาตุประจำตัว 10% ค่า `ERROR` ได้ callback ว่าง
