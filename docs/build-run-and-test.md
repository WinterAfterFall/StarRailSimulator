# Build, run และตรวจผล

รันคำสั่งจากรากโปรเจกต์บน Windows PowerShell โดยใช้ `g++` ที่รองรับ C++17 (เครื่องที่ใช้พัฒนาเดิมใช้ MinGW UCRT64) โปรแกรมมีทางเข้าสองไฟล์ที่มี `main()` คนละตัว: `Application.cpp` รับตัวเลือกในคอนโซล ส่วน `ManualBuilder.cpp` กำหนดทีมและศัตรูใน source ก่อนคอมไพล์ ดูเส้นทางทำงานใน [คู่มือ engine](engine-reference/instructor/README.md)

## คอมไพล์

ตัวอย่างนี้เขียน executable และ log ลงโฟลเดอร์ชั่วคราว เพื่อไม่ทับไฟล์ `.exe` ในโปรเจกต์:

```powershell
$buildDir = Join-Path $env:TEMP 'StarRailSimulator-build'
New-Item -ItemType Directory -Force -Path $buildDir | Out-Null
g++ -std=c++17 -O0 Application.cpp -o (Join-Path $buildDir 'Application.exe')
g++ -std=c++17 -O0 ManualBuilder.cpp -o (Join-Path $buildDir 'ManualBuilder.exe')
```

ถ้าต้องการตรวจ syntax อย่างเดียว ใช้ `g++ -std=c++17 -fsyntax-only Application.cpp` และคำสั่งเดียวกันกับ `ManualBuilder.cpp`; การผ่านขั้นนี้ยังไม่ยืนยันผลคำนวณขณะรัน

## รันและอ่านผล

`Application.exe` ถามจำนวนตัวละคร แล้วถามชื่อ, Eidolon, Light Cone, Relic และ Planar ทีละตัวก่อนสร้างศัตรู `SetCharacterPtr()` อ้าง `charUnit[1..4]` โดยตรง จึงต้องสร้างตัวละครให้ครบสี่ช่องเมื่อใช้ทางเข้านี้ `EnemySelector()` ถามจำนวนศัตรูแต่ยังไม่ใช้ค่านั้น; ที่คำถามตั้งค่าสถานะศัตรูเอง ต้องตอบ `yes` จึงจะสร้างศัตรูค่าคงที่สองตัว การตอบ `no` หรือกด Enter จะไม่สร้างศัตรู เพราะสาขานั้นยังไม่ implement

`ManualBuilder.exe` ใช้ทีม FireFly, Ruan Mei, Fugue และ Gallagher ตามบรรทัด `Setup()` ที่เปิดใช้อยู่ใน source ณ วันที่เขียนคู่มือ สามารถเปลี่ยนทีมได้ใน `ManualBuilder.cpp` แล้วคอมไพล์ใหม่ คำสั่งนี้ส่ง Enter ให้บรรทัดรอก่อนปิดโปรแกรมและเก็บ output ไว้อ่าน:

```powershell
$logFile = Join-Path $buildDir 'ManualBuilder-output.txt'
'' | & (Join-Path $buildDir 'ManualBuilder.exe') | Out-File -FilePath $logFile -Encoding utf8
Get-Content -LiteralPath $logFile -Tail 40
```

ทางเข้าทั้งสองเปิด `Print_Atv` ใน `SetValue()` จึงมี trace ของเทิร์นจำนวนมาก ผล `printRoundResult()` แสดง run ปัจจุบัน ส่วน `printSummaryResult()` แสดงชุด substats ที่ให้ค่าดีที่สุดและผลแยกตามศัตรู ความหมายของตัวเลขและสมุดดาเมจสองแบบอยู่ใน [Print.md](engine-reference/instructor/Function/Print/Print.md) และ [CalDamageNote.md](engine-reference/instructor/Function/Calculate/CalDamageNote.md) ก่อนเทียบผลหลังแก้สูตร ให้เก็บ output ของทีมและค่า setting เดิมไว้เป็น baseline แล้วเทียบยอดดาเมจและจำนวนเทิร์นหลังแก้

## ทดสอบ regression ที่มีอยู่ในเครื่อง

โฟลเดอร์ `test/` ถูก `.gitignore` ทั้งโฟลเดอร์ ไฟล์ทดสอบในเครื่องหนึ่งอาจไม่มีในอีกเครื่องหนึ่ง ตรวจชื่อไฟล์ก่อนรัน คำสั่งตัวอย่างสำหรับไฟล์ที่ตรวจพบใน workspace นี้:

```powershell
g++ -std=c++17 -O0 test/debuff_zero_stack_regression.cpp -o (Join-Path $buildDir 'debuff_zero_stack_regression.exe')
& (Join-Path $buildDir 'debuff_zero_stack_regression.exe')
g++ -std=c++17 -fsyntax-only test/set_enemy_declaration_regression.cpp
```

ไฟล์ regression แบบรันได้ที่พบเพิ่มเติมคือ `dot_zero_stack_regression.cpp`, `break_dot_expiry_regression.cpp` และ `arcana_min_stack_regression.cpp` ส่วน `set_enemy_declaration_regression.cpp` ตรวจ signature ระหว่างคอมไพล์เท่านั้น หากไฟล์ทดสอบที่เอกสารเก่าอ้างไม่มีอยู่ ให้รายงานว่าไม่สามารถรันเคสนั้นจาก workspace ปัจจุบันได้; อย่านับคำบันทึกว่าเคยทดสอบในอดีตเป็นผลทดสอบปัจจุบัน
