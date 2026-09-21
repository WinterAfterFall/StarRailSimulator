# `src/StdInclude.h`

รวม C++ standard headers, `conio.h`, alias ของ standard-library types/functions และ macro `PRIORITY_*` สำหรับลำดับ trigger นอกจากนี้กำหนด `endl` เป็นอักขระขึ้นบรรทัดใหม่ผ่าน macro จึงไม่ทำ flush แบบ `std::endl` ไฟล์นี้เป็น infrastructure header ไม่มี logic จำลองโดยตรง
